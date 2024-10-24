#include <bits/stdc++.h>

using namespace std;

int const maxI = 1e6+5;
bool mark[maxI];
vector<int> m(maxI);

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
       int ans = find(mark+m[a],mark+maxF+1, 0 ) - mark;
       mark[m[a]] = 0;
       mark[ans] = 1;
       m[a] = ans;
       maxF = max(maxF,ans);
       cout << ans << '\n';
   }
}


int main()
{
    solve();

    return 0;
}
