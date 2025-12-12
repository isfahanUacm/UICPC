#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';
#define pb push_back
#define pii pair<int, int>
#define F first
#define S second
//#define int ll


const int N = 2e5+9;

vector<int> d(100, -N);
bool mark[100];

void solve()
{
   int n, m;
   cin >> m >> n;

    string temp;
    for(int i=0; i<m+4; i++) temp.push_back('.');

   vector<string> v;

   v.push_back(temp);
   v.push_back(temp);

   for(int i=0; i<n; i++)
   {
       string temp_s;
       string x = ".."; cin >> temp_s;
       x = x + temp_s;
       x.push_back('.');
       x.push_back('.');
       v.push_back(x);
   }

   v.push_back(temp);
   v.push_back(temp);


   for(int i=2; i<n+2; i++)
   {
       for(int j=2; j<m+2; j++)
       {
           if(v[i][j] == 'u') v[i][j] = 'U';
           else if(v[i][j] == 'v') v[i][j] = 'V';
           else if(v[i][j] == 'a') v[i][j] = 'A';
       }
   }

//   for(auto x : v)
//   {
//       for(auto y : x) cout << y;
//       cout << endl;
//   }

   int ans = 0;
   for(int i=2; i<n+2; i++)
   {
       for(int j=2; j<m+2; j++)
       {
           if(v[i][j] == 'U')
           {
               if(v[i+1][j] == 'V' && v[i+2][j] == 'A') ans++;
               if(v[i][j+1] == 'V' && v[i][j+2] == 'A') ans++;
               if(v[i-1][j] == 'V' && v[i-2][j] == 'A') ans++;
               if(v[i][j-1] == 'V' && v[i][j-2] == 'A') ans++;
               if(v[i+1][j+1] == 'V' && v[i+2][j+2] == 'A') ans++;
               if(v[i+1][j-1] == 'V' && v[i+2][j-2] == 'A') ans++;
               if(v[i-1][j+1] == 'V' && v[i-2][j+2] == 'A') ans++;
               if(v[i-1][j-1] == 'V' && v[i-2][j-2] == 'A') ans++;
           }
       }
   }

   cout << ans;
}

int32_t main()
{
    ios::sync_with_stdio(false);cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
