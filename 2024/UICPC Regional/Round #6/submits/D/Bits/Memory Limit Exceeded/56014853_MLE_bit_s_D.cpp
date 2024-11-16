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

   vector<int> v;
   for(int i=0; i<=m; i++)
       v.push_back(i);
   for(int i=ind+1; i<n; i++){
       for(int j=0; j<v.size(); j++){
           v[j] = arr[i] - v[j];
           if(v[j] < 0){
               v.erase(v.begin()+j);
               j--;
           }
       }
   }

   vector<int> u;
   for(int i=0; i<=m; i++)
       u.push_back(i);
   for(int i=ind-1; i>=0; i--){
       for(int j=0; j<v.size(); j++){
           u[j] = arr[i] - u[j];
           if(u[j] < 0){
               u.erase(u.begin()+j);
               j--;
           }
       }
   }
   cout << min(v.size(),u.size()) << '\n';
}

int main()
{
     solve();

    return 0;
}
