#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const int maxN = 1e6+5;
const int INF = 1e9+7;

ll arr[maxN];
ll t[maxN];
void solve(){
   int n;
   cin >> n;
   cin >> arr[0];
   for(int i=1; i<n; i++){
       cin >> arr[i];
       t[i] = abs(arr[i] - arr[i-1]);
   }
   ll cnt = 0, ma = 0;
   if(arr[0] > arr[n-1]){
       cnt = arr[n-1];
       for(int i=n-2; i>0; i--){
           if(arr[i] > arr[i-1])
               ma = max(t[i], ma);
           if(cnt <= 0)
               break;
       }
   }
   else{
       cnt = arr[0];
       for(int i=2; i<n; i++){
           if(arr[i-1] > arr[i])
               ma = max(t[i], ma);
           if(cnt <= 0)
               break;
       }
   }
   cnt -= ma;
   if(cnt < 0)
       cnt = 0;
   cout << cnt << '\n';
}

int main()
{
     solve();

    return 0;
}
