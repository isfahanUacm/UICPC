/* Sample solution for NCPC'08: Code Theft
 * Author: Nils Grimsmo
 *
 * Warning: For a simple solution, look somewhere else...
 *
 * Solution: - View lines as symbols (hash once).
 *           - Build suffix tree for new code snippet
 *           - Find the matching statistics for each fragment 
 *             from the repository.
 *
 * Running time: Linear in the total text input, unless hashing makes
 *               trouble. 
 *               Fix: - Sort strings to find order, 
 *                    - Use map instead of hash_map for node children.
 *               Cost: O(log s) factor extra, where s is number of unique 
 *                     lines in new code snippet.
 */
#define NDEBUG 1

#include <algorithm>
#include <cassert>
#include <cstdio>
#include <cstring>
#include <ext/hash_map>
#include <iostream>
#include <string>
#include <set>
#include <sstream>

using namespace std;
using namespace __gnu_cxx;

#define ITER(I,A) for (typeof((A).begin()) I = (A).begin(); I != (A).end(); ++I)

const int MAX_LINE = 256;
const int MAX_PROG_LINES = 10000;
const int MAX_PROGS = 100;
const int MAX_CHARS = 2 << 20;

char* data = (char*)malloc(MAX_CHARS);
char* dn = data;
char* buff = (char*)malloc(MAX_LINE);

char* rl(char* dst) {
  fgets(dst, MAX_LINE, stdin);
  return dst;
}

char* normalize(const char* src) {
  assert(data <= dn && dn < data + MAX_CHARS);
  char* dst = dn;
  bool spaced = true;
  bool last_space = false;
  for ( ; *src; ++src) {
    if (isspace(*src)) {
      last_space = true;
    } else {
      if (last_space && !spaced) {
        *dn = ' '; ++dn;
      }
      *dn = *src; ++dn; 
      last_space = false;
      spaced = false;
    }
  }
  *dn = 0;
  ++dn;
  assert(data <= dn && dn <= data + MAX_CHARS);
  return dst;
}

class str {
public:
  const char* d;
  size_t n;
  size_t h;

  str(const char* _d) {
    d = normalize(_d);
    n = strlen(d); 
    h = hash<const char*>()(d);
  }
};

bool operator==(const str& s1, const str& s2) {
  return s1.h == s2.h && strcmp(s1.d, s2.d) == 0;
}

bool operator!=(const str& s1, const str& s2) {
  return s1.h != s2.h || strcmp(s1.d, s2.d) != 0;
}

namespace __gnu_cxx {
  template<>
  struct hash<str> {
    size_t operator()(const str& s) const { 
      return s.h;
    }
  };
} 

class Node {
public:
  vector<str>* T;
  int hpos, depth;
  Node* parent;
  Node* sufflink;
  hash_map<str,Node*> children;

  Node(vector<str>* T, int hpos, int depth) 
    : T(T), hpos(hpos), depth(depth), parent(NULL), sufflink(NULL) 
  { }

  ~Node() {
    ITER(i, children) delete i->second;
  }

  void addChild(Node* child) {
    children[T->at(child->hpos + depth)] = child;
    child->parent = this;
  }

  Node* getChild(str s) {
    if (children.count(s)) return children[s];
    else return NULL;
  }

  void printSelf(int start_depth = 0) {
    if (depth == 0) fprintf(stderr, "<root> ");
    else for (int d = start_depth; d < depth; ++d) 
      fprintf(stderr, "(%s) ", T->at(hpos + d).d);
    fprintf(stderr, "hpos=%d depth=%d\n", hpos, depth);
  }
  
  void print(int indent = 0) {
    for (int i = 0; i < indent; ++i) fprintf(stderr, "    ");
    printSelf(parent ? parent->depth : 0);
    ITER(i, children) i->second->print(indent + 1);
  }
};

class Pos {
public:
  int depth;
  Node* node;

  Pos(int depth, Node* node) 
    : depth(depth), node(node) 
  { }

  void slowScan(const vector<str>* S, int hpos = 0) {
    for (int d = 0; d < depth; ++d) {
      assert(S->at(hpos + d) == node->T->at(node->hpos + d));
    }
    while (true) {
      assert(depth <= node->depth);
      if (hpos + depth >= (int)S->size()) return;
      if (depth == node->depth) {
        Node* child = node->getChild(S->at(hpos + depth));
        if (!child) return;
        node = child;
      } else {
        if (S->at(hpos + depth) != node->T->at(node->hpos + depth)) return;
      }
      ++depth;
    }
  }

  void fastScan(int target_depth, vector<str>* S, int hpos = 0) {
    depth = min(target_depth, node->depth);
    while (depth < target_depth) {
      node = node->getChild(S->at(hpos + node->depth)); assert(node);
      depth = min(target_depth, node->depth);
    }
  }

  void followSuffLinkAndRescan() {
    int new_hpos = node->hpos + 1;
    int target_depth = depth > 0 ? depth - 1 : 0;
    if (node->sufflink == NULL) node = node->parent;
    node = node->sufflink;
    depth = node->depth;
    fastScan(target_depth, node->T, new_hpos);
  }

  void fixSuffLinkFrom(Pos new_pos) {
    Node* fix_node = node->depth > depth ? node->parent : node;
    if (fix_node->sufflink) return;
    fix_node->sufflink = new_pos.node;
    while (fix_node->sufflink->depth + 1 > fix_node->depth) 
      fix_node->sufflink = fix_node->sufflink->parent;
    assert(fix_node->depth - 1 == fix_node->sufflink->depth);
  }

  bool onEdge() {
    return node->depth > depth;
  }

  void addInternal(int hpos) {
    assert(onEdge());
    Node* new_node = new Node(node->T, hpos, depth);
    node->parent->addChild(new_node);
    new_node->addChild(node);
    node = new_node;
  }

  void addLeaf(int hpos, int n) {
    assert(!onEdge());
    node->addChild(new Node(node->T, hpos, n - hpos));
  }

  void print() {
    fprintf(stderr, " depth=%d node->hpos=%d node->depth=%d str=", depth, node->hpos, node->depth);
    for (int d = 0; d < depth; ++d) {
     fprintf(stderr, "(%s) ", node->T->at(node->hpos + d).d);
    } 
    fprintf(stderr, "\n");
  }
};

class ST {
public:

  Node *root;
  vector<str>* T;
  int n;

  ST(vector<str>* T) : T(T) {
    //T->push_back(str("***END***"));
    T->push_back(str("$"));
    n = T->size();
    root = new Node(T, 0, 0); root->sufflink = root;
    Pos pos(0, root);
    Pos old_pos(pos);
    for (int i = 0; i < n; ++i) {
      pos.followSuffLinkAndRescan();
      pos.slowScan(T, i); 
      if (pos.onEdge()) pos.addInternal(i);
      pos.addLeaf(i, n);
      old_pos.fixSuffLinkFrom(pos);
      old_pos = pos;
    } 
  }

  ~ST() {
    delete root;
  }

  void matchStats(const vector<str>* P, int* MS) {
    Pos pos(0, root);
    for (int i = 0; i < (int)P->size(); ++i) {
      pos.followSuffLinkAndRescan();
      pos.slowScan(P, i);
      MS[i] = pos.depth;
    }
  }
};

int main() {
  int N; scanf("%d", &N); rl(buff);
  vector<str> F; // Filenames
  vector<vector<str> > C; // Repository
  vector<str> D; // New snippet
  for (int i = 0; i < N + 1; ++i) {
    if (i < N) {
      F.push_back(str(rl(buff)));
      C.push_back(vector<str>());
    }
    while (true) {
      str s(rl(buff));
      if (strcmp(s.d, "***END***") == 0) break;
      if (s.n > 0) {
        if (i < N) C[i].push_back(s); 
        else       D.push_back(s); 
      }
    }
  }

  int maks = 0;
  set<int> maks_F;
  ST st(&D);
  //st.root->print();
  for (int i = 0; i < N; ++i) {
    int MS[MAX_PROG_LINES];
    for (int j = 0; j < MAX_PROG_LINES; ++j) MS[j] = 0;
    st.matchStats(&C[i], MS);
    for (int j = 0; j < (int)C[i].size(); ++j) {
      if (MS[j] > maks) maks_F.clear();
      if (MS[j] >= maks && MS[j] > 0) { 
        maks = MS[j]; 
        maks_F.insert(i);
      }
      //printf("%d ", MS[j]);
    }
    //printf("\n");
  }
  printf("%d", (int)maks);
  for (typeof(maks_F.begin()) i = maks_F.begin(); i != maks_F.end(); ++i) {
    printf(" %s", F[*i].d);
  }
  printf("\n");
  free(data);
  free(buff);
}
