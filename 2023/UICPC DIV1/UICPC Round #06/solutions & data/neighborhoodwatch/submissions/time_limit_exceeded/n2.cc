#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 200030;
bool A[MAX_N];

int main(){
  int n, k;
  scanf("%d %d", &n, &k);

  int maxi = 0;
  for(int i=0;i<k;i++){
    int u; scanf("%d", &u);
    A[u] = true;
    maxi = max(maxi, u);
  }
  
  long long ans = 0;
  for(int i=1;i<=maxi;i++)
    for(int j=i;j<=maxi;j++)
      if(A[j]){
	ans += (n-j+1);
	break;
      }

  cout << ans << endl;
}
