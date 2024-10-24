#include <bits/stdc++.h>

using namespace std;

int const maxI = 1e6+5;
bool mark[maxI];
map<int,int> m;
int f(int l, int r){
    if(l==r){
        if(mark[r])
            return 0;
        return r;
    }
    int mid = (l+r)/2;
    int ans = f(l,mid);
    if(!ans)
        return f(mid+1,r);
    return ans;
}

void solve()
{
   int n;
   cin>> n;
   int maxF;
   cin >> maxF;
   mark[maxF] = 1;
   m[1] = maxF;
   for(int i=2; i<=n; i++)
   {
       int a;
       cin >> a;
       m[i] = a;
       mark[a] = 1;
       maxF = max(maxF,a);
   }
   int q;
   cin >> q;
   for(int i=0; i<q; i++){
       int a;
       cin>> a;
       int ans = f(m[a],maxF);
       mark[a] = 0;
       if(ans){
           cout << ans << '\n';
           mark[ans] = 1;
           m[a] = ans;
       }
       else{
           cout << maxF+1 << '\n';
           maxF++;
           mark[maxF] = 1;
           m[a] = maxF;
       }

   }
}


int main()
{
    solve();

    return 0;
}
