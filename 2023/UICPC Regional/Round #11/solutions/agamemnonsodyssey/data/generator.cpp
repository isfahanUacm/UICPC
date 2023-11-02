#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
using namespace std;

const int MAXW = 1000000000;


int generateWeight(string strat) {
    if(strat == "small") return rand() % 1111 + 1;
    else if(strat == "large") return MAXW - rand() % 1111;
    else if(strat == "full_rng") return rand() % MAXW + 1;
    else if(strat == "ultra_small") return rand() % 7 + 1;
    else if(strat == "ultra_large") return MAXW - rand() % 7;
    else assert(false);
}

/*
    Generates a random tree with n nodes : nodes indexed 1 to n.
    Prints number of nodes followed by edges of the tree.
    Ensures p_i < i is not the case.

    Depth of such tree is expected to be O(log n)
*/

inline void generateRandomTree(int n, int k, string weighter) {
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    random_shuffle(a.begin(), a.end());
    vector < pair < int, int > > tree_edges;
    for (int i = 1; i < n; i++) {
        int parent_ai = a[rand() % i];
        tree_edges.push_back(make_pair(parent_ai, a[i]));
    }
    cout << n << " " << k << "\n";
    for (auto it : tree_edges) {
        cout << (it.first) << " " << (it.second) << " " << generateWeight(weighter) << "\n";
    }
}


/*
    Generates a random tree with n nodes : nodes indexed 1 to n.
    Prints number of nodes followed by edges of the tree.
    Ensures p_i < i is not the case.

    This one ensures depth is O(n) (no matter where you root it).
*/

inline void generateRandomTreeWithHighDepth(int n, int k, string weighter) {
    int sz = (n + 1) / 2;
    vector < int > a(sz);
    for (int i = 0; i < sz; i++) {
        a[i] = sz + i + ((n & 1) ^ 1);
    }
    random_shuffle(a.begin(), a.end());
    vector < pair < int, int > > tree_edges;
    for (int i = 2; i <= n / 2; i++) {
        int parent_ai = i - 1;
        tree_edges.push_back(make_pair(parent_ai, i));
    }
    tree_edges.push_back(make_pair(n / 2, a[0]));
    for (int i = 1; i < sz; i++) {
        int parent_ai = a[rand() % i];
        tree_edges.push_back(make_pair(parent_ai, a[i]));
    }
    cout << n << " " << k << "\n";
    for (auto it : tree_edges) {
        cout << (it.first) << " " << (it.second) << " " << generateWeight(weighter) << "\n";
    }
}

/*
    Generates the "broom tree" with n nodes. nodes indexed 1 to n.
    Prints number of nodes followed by edges of the tree.
    Ensures p_i < i is not the case.

    Useful to break degree based heuristics.
*/

inline void generateBroomTest(int n, int k, string weighter) {
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    random_shuffle(a.begin(), a.end());
    vector < pair < int, int > > tree_edges;
    for (int i = 1; i < n / 2; i++) {
        int parent_ai = a[i - 1];
        tree_edges.push_back(make_pair(parent_ai, a[i]));
    }
    for (int i = n / 2; i < n; i++) {
        int parent_ai = a[(n / 2) - 1];
        tree_edges.push_back(make_pair(parent_ai, a[i]));
    }
    cout << n << " " << k << "\n";
    for (auto it : tree_edges) {
        cout << (it.first) << " " << (it.second) << " " << generateWeight(weighter) << "\n";
    }
}


/*
    Generates the "linear tree" with n nodes. nodes indexed 1 to n.
    Prints number of nodes followed by edges of the tree.
    Ensures p_i < i is not the case.

    Useful to break many height/depth/subtreeSize based heuristics
*/

inline void generateChain(int n, int k, string weighter) {
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    random_shuffle(a.begin(), a.end());
    vector < pair < int, int > > tree_edges;
    for (int i = 1; i < n; i++) {
        int parent_ai = a[i - 1];
        tree_edges.push_back(make_pair(parent_ai, a[i]));
    }
    cout << n << " " << k << "\n";
    for (auto it : tree_edges) {
        cout << (it.first) << " " << (it.second) << " " << generateWeight(weighter) << "\n";
    }
}

/*
    Generates a tree with one chain of length sqrt(n), and sqrt(n) - 1 chains each of length
    sqrt(n) popping out of the last node in the chain. nodes indexed 1 to n.
    Prints number of nodes followed by edges of the tree.
    Ensures p_i < i is not the case.
    IMPORTANT : Assumes n is a perfect square!

    Useful especially for data structure problems.
*/

inline void generateFireworksTree(int n, int k, string weighter) {
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    random_shuffle(a.begin(), a.end());
    int s = sqrt(n);
    if ((s * s) != n) {
        s += 1;
    }
    if ((s * s) != n) {
        cout << "You haven't entered a perfect square!\n";
        assert(false);
    }
    vector < pair < int, int > > tree_edges;
    for (int i = 1; i < s; i++) {
        int parent_ai = a[i - 1];
        tree_edges.push_back(make_pair(parent_ai, a[i]));
    }
    for (int i = 1; i < s; i++) {
        for (int j = i * s; j < (i + 1) * s; j++) {
            int parent_aj;
            if (j == (i * s)) {
                parent_aj = a[s - 1];
            } else {
                parent_aj = a[j - 1];
            }
            tree_edges.push_back(make_pair(parent_aj, a[j]));
        }
    }
    cout << n << " " << k << "\n";
    for (auto it : tree_edges) {
        cout << (it.first) << " " << (it.second) << " " << generateWeight(weighter) << "\n";
    }
}


/*
    Generates the star tree with n nodes. nodes indexed 1 to n.
    Prints number of nodes followed by edges of the tree.
    Ensures p_i < i is not the case.
*/

inline void generateStarTree(int n, int k, string weighter) {
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    random_shuffle(a.begin(), a.end());
    vector < pair < int, int > > tree_edges;
    for (int i = 1; i < n; i++) {
        int parent_ai = a[0];
        tree_edges.push_back(make_pair(parent_ai, a[i]));
    }
    cout << n << " " << k << "\n";
    for (auto it : tree_edges) {
        cout << (it.first) << " " << (it.second) << " " << generateWeight(weighter) << "\n";
    }
}


/*
    Generates a BST (Segment Tree) with n nodes. nodes indexed 1 to n.
    Prints number of nodes followed by edges of the tree.
    Ensures p_i < i is not the case.

    IMPORTANT : n must be odd (n >= 3)
*/

int node_id = 0;

inline void makeBST(int id, int l, int r, vector < pair < int, int > > &edges) {
    if (l == r) {
        return;
    }
    int lc = ++node_id;
    int rc = ++node_id;
    int mid = (l + r) >> 1;
    edges.push_back(make_pair(id, lc));
    edges.push_back(make_pair(id, rc));
    makeBST(lc, l, mid, edges);
    makeBST(rc, mid + 1, r, edges);
}

inline void generateBST(int n, int k, string weighter) {
    if (n % 2 == 0) {
        cout << "n must be odd!\n";
        assert(false);
    }
    int sz = (n + 1) / 2;
    vector < int > a(n);
    for (int i = 0; i < n; i++) {
        a[i] = i + 1;
    }
    random_shuffle(a.begin(), a.end());
    vector < pair < int, int > > tree_edges;
    node_id = 0;
    makeBST(0, 0, sz - 1, tree_edges);
    cout << n << " " << k << "\n";
    assert((int)(tree_edges.size()) == n - 1);
    for (auto it : tree_edges) {
        assert(0 <= it.first && it.first < n);
        assert(0 <= it.second && it.second < n);
        cout << a[(it.first)] << " " << a[(it.second)] << " " << generateWeight(weighter) << "\n";
    }
}


int main() {
    srand(17070509);

    // freopen("trees.out", "w", stdout);
    // srand(time(NULL));
    // int n = 123201;
    // generateRandomTree(n);
    // cout << "--------------\n";
    // generateRandomTreeWithHighDepth(n);
    // cout << "--------------\n";
    // generateBroomTest(n);
    // cout << "--------------\n";
    // generateChain(n);
    // cout << "--------------\n";
    // generateFireworksTree(n); // n must be a perfect square
    // cout << "--------------\n";
    // generateStarTree(n);
    // cout << "--------------\n";
    // generateBST(n); // n must be odd


    // k = 1

    // RANDOM TREES
    freopen("secret/1.in", "w", stdout);
    generateRandomTree(20, 1, "small");
    freopen("secret/2.in", "w", stdout);
    generateRandomTree(2000, 1, "large");
    freopen("secret/3.in", "w", stdout);
    generateRandomTree(20000, 1, "full_rng");
    
    // HIGH DEPTH RANDOM TREES
    freopen("secret/4.in", "w", stdout);
    generateRandomTreeWithHighDepth(123, 1, "ultra_large");
    freopen("secret/5.in", "w", stdout);
    generateRandomTreeWithHighDepth(4321, 1, "full_rng");
    freopen("secret/6.in", "w", stdout);
    generateRandomTreeWithHighDepth(200000, 1, "ultra_small");
    

    // BROOM TREES
    freopen("secret/7.in", "w", stdout);
    generateBroomTest(200000, 1, "ultra_large");
    freopen("secret/8.in", "w", stdout);
    generateBroomTest(123456, 1, "full_rng");
    freopen("secret/9.in", "w", stdout);
    generateBroomTest(98765, 1, "large");


    // CHAIN TREES
    freopen("secret/10.in", "w", stdout);
    generateChain(99999, 1, "ultra_small");
    freopen("secret/11.in", "w", stdout);
    generateChain(111111, 1, "full_rng");
    freopen("secret/12.in", "w", stdout);
    generateChain(199999, 1, "ultra_large");
    freopen("secret/13.in", "w", stdout);
    generateChain(198765, 1, "large");
    freopen("secret/14.in", "w", stdout);
    generateChain(190000, 1, "large");


    // FIREWORKS TREE
    freopen("secret/15.in", "w", stdout);
    generateFireworksTree(1024, 1, "small");
    freopen("secret/16.in", "w", stdout);
    generateFireworksTree(199809, 1, "full_rng");


    // STAR TREE
    freopen("secret/17.in", "w", stdout);
    generateStarTree(188888, 1, "full_rng");
    freopen("secret/18.in", "w", stdout);
    generateStarTree(50, 1, "small");


    // BST
    freopen("secret/19.in", "w", stdout);
    generateBST(197777, 1, "ultra_large");
    freopen("secret/20.in", "w", stdout);
    generateBST(153333, 1, "full_rng");


    // K != 1
    freopen("secret/21.in", "w", stdout);
    generateRandomTree(2000, 2, "ultra_small");
    freopen("secret/22.in", "w", stdout);
    generateRandomTreeWithHighDepth(109876, 5, "small");
    freopen("secret/23.in", "w", stdout);
    generateBroomTest(111111, rand() % MAXW + 1, "large");
    freopen("secret/24.in", "w", stdout);
    generateChain(200000, MAXW, "full_rng");
    freopen("secret/25.in", "w", stdout);
    generateBST(188999, MAXW - 17, "ultra_large");
}