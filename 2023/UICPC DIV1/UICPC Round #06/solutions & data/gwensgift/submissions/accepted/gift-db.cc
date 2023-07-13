#include <bits/stdc++.h>
using namespace std;

const long long oo = LLONG_MAX / 2;

int main(){
  long long n, k;
  cin >> n >> k;
  k--;
  
  vector<long long> factorial(n);
  factorial[0] = 1;
  for(int i=1;i<n;i++){
    if(oo / factorial[i-1] > i) factorial[i] = factorial[i-1] * i;
    else factorial[i] = oo;
  }

  vector<int> ans = {0}; // Prepend 0 to the answer to make life easier...
  vector<int> perm = {0};
  vector<bool> used(n);
  for(int i=0;i<n-1;i++){
    vector<pair<int,int> > possible;
    for(int j=1;j<n;j++)
      if(!used[j])
	possible.emplace_back( (j-perm[i]+n) % n , j);
    
    sort(begin(possible), end(possible));
    
    for(auto x : possible){
      if(factorial[n-i-2] <= k) {
	k -= factorial[n-i-2];
	continue;
      }
      ans.push_back(x.first);
      perm.push_back(x.second);
      used[x.second] = true;
      break;
    }
  }
  
  for(int i=1;i<n;i++)
    cout << (i > 1 ? " " : "") << ans[i];
  cout << endl;

  // Sanity check...
  for(int i=1;i<n;i++)
    for(int j=i;j<n;j++)
      assert(accumulate(begin(ans)+i, begin(ans)+j+1, 0) % n);
}
