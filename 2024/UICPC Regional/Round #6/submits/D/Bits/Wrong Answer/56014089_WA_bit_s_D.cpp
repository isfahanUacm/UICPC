#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll maxN = 1e6+5;
const ll INF = 1e9+7;

ll arr[maxN];
ll t[maxN];
void solve(){
   int n;
   cin >> n;
   cin >> arr[0];
   ll m = arr[0];
   int ind = 0;
   for(int i=1; i<n; i++){
       cin >> arr[i];
       t[i] = abs(arr[i] - arr[i-1]);

       if(m > arr[i]){
           m = arr[i];
           ind = i;
       }
   }
   ll cnt = m+1, ma = 0, num = 0;

   for(int i=n-1; i>ind; i--){
       if(arr[i] < arr[i-1] && num < arr[i-1]){
           if(num == 0)
               ma = t[i];
           else
               ma += (arr[i-1] - num);
           num = arr[i-1];
       }
   }

   for(int i=1; i<ind; i++){
       if(arr[i-1] < arr[i] && num < arr[i]){
           if(num == 0)
               ma = t[i];
           else
               ma += arr[i] - num;
           num = arr[i];
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
