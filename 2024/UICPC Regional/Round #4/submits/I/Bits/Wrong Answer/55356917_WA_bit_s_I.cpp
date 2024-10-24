#include <bits/stdc++.h>

using namespace std;

int const maxI = 1e6+5;
bool mark[maxI];

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
   for(int i=1; i<n; i++)
   {
       int a;
       cin >> a;
       mark[a] = 1;
       maxF = max(maxF,a);
   }
   int q;
   cin >> q;
   for(int i=0; i<q; i++){
       int a;
       cin>> a;
       int ans = f(a,maxF);
       if(ans){
           cout << ans << '\n';
           mark[ans] = 1;
       }
       else{
           cout << maxF+1 << '\n';
           maxF++;
           mark[maxF] = 1;
       }

   }
}


int main()
{
    solve();

    return 0;
}
