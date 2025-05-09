#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
     int n,m,k ; cin >> n >> m >> k;
     string s ; cin >> s;
     int op;
     for(int i = 0 ; i < k ; i++)
     {
         cin >> op;
         if(op == 1)
         {
             int x,y,l,r;
             cin >> x >> y >> l >> r;

             for(int j = l-1 ;j <= r-1 ; j++)
             {
                 if(s[j] == 'U' && x > 1)
                     x--;
                 else if(s[j] == 'D' && x < n)
                     x++;
                 else if(s[j] == 'R' && y < n)
                     y++;
                 else if( s[j] == 'L' && y > 1)
                     y--;
             }

             cout << x << " " << y << '\n';
         }else
         {
             int p ; cin >> p ;
             char c ; cin >> c;
             s[p-1] = c;
         }

     }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
    cin >> n;
    while(n--)
        solve();

    return 0;
}