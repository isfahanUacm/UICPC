#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ld long double

const ll maxN = 1e6+5;
const ll INF = 1e9+7;

ll arr[maxN];
void solve(){
   int n;
   cin >> n;
   ll m = INF;
   int ind = 0;
   for(int i=0; i<n; i++){
       cin >> arr[i];
       if(m > arr[i]){
           m = arr[i];
           ind = i;
       }
   }

   int l = 0, h = m, cnt = m+1;
   for(int i=ind+1; i<n; i++){
       l = arr[i] - l;
       h = arr[i] - h;
       if(l < 0){
           cout << 0 << '\n';
           return;
       }
       if(h < 0)
           h = 0;
       int tmp = h;
       h = l;
       l = tmp;
       cnt = min(cnt, h-l+1);
   }

   l = 0;
   h = m;
   for(int i=ind-1; i>=0; i--){
       l = arr[i] - l;
       h = arr[i] - h;
       if(l < 0){
           cout << 0 << '\n';
           return;
       }
       if(h < 0)
           h = 0;
       int tmp = h;
       h = l;
       l = tmp;
       cnt = min(cnt, h-l+1);
   }
   cout << cnt << '\n';
}

int main()
{
     solve();

    return 0;
}
