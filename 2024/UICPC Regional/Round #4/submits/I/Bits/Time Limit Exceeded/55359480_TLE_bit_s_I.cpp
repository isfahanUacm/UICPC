#include <bits/stdc++.h>

using namespace std;

int const maxI = 1e8+5;
int const maxN = 2*1e5+5;
vector<int> mark(maxI);
vector<int> m(maxN);

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
       int ans = find(mark.begin()+m[a],mark.begin()+maxF+1, 0 ) - mark.begin();
       mark[m[a]] = 0;
       mark[ans] = 1;
       m[a] = ans;
       maxF = max(maxF,ans);
       cout << ans << '\n';
   }
}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    solve();

    return 0;
}
