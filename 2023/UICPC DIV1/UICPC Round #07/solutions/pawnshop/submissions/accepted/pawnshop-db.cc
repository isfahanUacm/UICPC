#include <bits/stdc++.h>
using namespace std;

int main() {
  int n; cin >> n;
  vector<int> A(n), B(n);
  for(int& x : A) cin >> x;
  for(int& x : B) cin >> x;

  map<int, int> M;
  int ctr = 0;
  for(int i=0;i<n;i++) {
    if(i && ctr == 0) cout << " #";

    if(M[A[i]] == 0) ctr++;
    M[A[i]]++;
    if(M[A[i]] == 0) ctr--;

    if(M[B[i]] == 0) ctr++;
    M[B[i]]--;
    if(M[B[i]] == 0) ctr--;

    cout << (i ? " " : "") << B[i];
  }
  cout << endl;
}
