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

   ll l = 0, h = m, x=0;
   for(int i=ind+1; i<n; i++){
       l = arr[i] - l;
       h = arr[i] - h;
       if(l < 0){
           cout << 0 << '\n';
           return;
       }
       if(h < 0){
           x -= h;
           h = 0;
       }
       ll tmp = h;
       h = l;
       l = tmp;
   }
   ll y=0;

   l = 0;
   h = m;
   for(int i=ind-1; i>=0; i--){
       l = arr[i] - l;
       h = arr[i] - h;
       if(l < 0){
           cout << 0 << '\n';
           return;
       }
       if(h < 0){
           y -= h;
           h = 0;
       }
       ll tmp = h;
       h = l;
       l = tmp;
   }
   l = max(y,x);
   cout << m-l+1 << '\n';
}

int main()
{
     solve();

    return 0;
}
