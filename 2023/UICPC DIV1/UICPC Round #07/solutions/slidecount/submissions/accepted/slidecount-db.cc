#include <bits/stdc++.h>
using namespace std;

// Taken from https://cp-algorithms.com/data_structures/fenwick.html
struct FenwickTree {
    vector<int> bit;  // binary indexed tree
    int n;

    FenwickTree(int n) {
        this->n = n;
        bit.assign(n, 0);
    }

    FenwickTree(vector<int> a) : FenwickTree(a.size()) {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int r) {
        int ret = 0;
        for (; r >= 0; r = (r & (r + 1)) - 1)
            ret += bit[r];
        return ret;
    }

    int sum(int l, int r) {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta) {
        for (; idx < n; idx = idx | (idx + 1))
            bit[idx] += delta;
    }
};

int main() {
  int n, C; cin >> n >> C;
  vector<int> A(n);
  for(int& x : A) cin >> x;

  FenwickTree FT(n+2);
  FT.add(0, 1);
  FT.add(1, -1);
  int sum = A[0];
  for(int s=0, e=0;s<n;) {
    if (e + 1 >= n || sum + A[e+1] > C) sum -= A[s++];
    else sum += A[++e];

    if(s <= e) {
      FT.add(s, 1);
      FT.add(e + 1, -1);
    }
  }
  for(int i=0;i<n;i++) cout << FT.sum(i) << endl;
}
