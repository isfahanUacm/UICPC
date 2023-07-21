#include <bits/stdc++.h>
using namespace std;

int do_case() {
  int n; cin >> n;
  vector<int> A(n);
  for (auto& x : A) cin >> x;
  sort(A.rbegin(), A.rend());
  int num = 0;
  for(int i=0;i<n/2;i++) num += A[i];
  for(int i=n/2;i<n;i++) num += A[i]/2;

  return num;
}

int main() {
  cout << do_case() << endl;
}
