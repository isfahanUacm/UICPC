#include <bits/stdc++.h>
using namespace std;

int main(){
  int n, k; cin >> n >> k;

  vector<int> A(k);
  for(auto& x : A) cin >> x;
  A.push_back(0);
  
  sort(begin(A), end(A));

  long long ans = 0;
  for(int i=1;i<=k;i++)
    ans += (long long)(A[i] - A[i-1]) * (n - A[i] + 1);

  cout << ans << endl;  
}
