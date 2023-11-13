#include <iostream>
#include <cstring>
#include <tuple>
using namespace std;

struct node;

struct node {
  node* children[26];
  node* autocomplete;
  int d;
  node() : autocomplete(NULL), d(0) { memset(children,0,sizeof(children)); }
};

pair<int,node*> insert(node*& x, const char* c) {
  if (x==NULL) x = new node;
  char cc=*c;
  if (cc==0) {
    if (x->autocomplete==NULL) x->autocomplete=x;
    return {1,x};
  }
  cc-='a';
  auto da = insert(x->children[cc],c+1);
  if (x->autocomplete==NULL) tie(x->d, x->autocomplete) = da;
  return {x->d+1, x->autocomplete};
}

int search(const node* x, const char* c, int cost) {
  if (x==NULL) return strlen(c);
  char cc=*c;
  //cerr << cc << " at " << x << endl;
  node* y = NULL;
  if (cc!=0) y = x->children[cc-'a'];
  //cerr << "aut " << (x->autocomplete) << endl;
  if (y==NULL or y->autocomplete != x->autocomplete) {
    int alt=1+x->d;
    //cerr << "STD " << cost << " TAB " << alt << endl;
    if (alt<cost) cost=alt;
    return cost+(cc?1+search(y,c+1,0):0);
  }
  return search(y,c+1,cost+1);
}

int main() {
  int n,m;
  cin >> n >> m;
  node* t = NULL;
  for (int i=0;i<n;++i) {
    string s;
    cin >> s;
    insert(t,s.c_str());
  }
  t->autocomplete=t;
  for (int i=0;i<m;++i) {
    string s;
    cin >> s;
    cout << search(t, s.c_str(), 0) << endl;
  }
}
