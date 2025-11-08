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

const int N = 2e5+9;


void solve()
{
    int r, c; cin >> r >> c;
    int si, sj; cin >> si >> sj; si--; sj--;
    int ei, ej; cin >> ei >> ej; ei--; ej--;

    vector<vector<bool>> v(r, vector<bool>(c,false));
    for(int i=0; i<r; i++)
    {
        string s; cin >> s;
        for(int j=0; j<c; j++)
        {
            v[i][j] = (s[j] == '1');
        }
    }

    vector<vector<int>> count(r, vector<int>(c, 0));

    int curi=si, curj=sj;
    int dir = 1;
    while(true)
    {
//        cout << curi << ' ' << curj << dir << endl;

        count[curi][curj]++;
        if(count[curi][curj] > 4)
        {
            cout << 0;
            return;
        }

        if(curj == ej && curi == ei)
        {
            cout << 1;
            return;
        }

        if(dir == 1) ///right
        {
            if(curi != 0 && !v[curi-1][curj])
            {
                dir = 2;
                curi --;

            }
            else if(curj != c-1 && !v[curi][curj+1])
            {

                curj++;

            }
            else
            {
                dir = 4;
            }
        }
        else if(dir == 2) ///up
        {
            if(curj != 0 && !v[curi][curj-1])
            {

                dir = 3;
                curj --;

            }
            else if(curi != 0 && !v[curi-1][curj])
            {

                curi--;

            }
            else
            {
                dir = 1;
            }
        }
        else if(dir == 3) ///left
        {
            if(curi != r-1 && !v[curi+1][curj])
            {
                dir = 4;
                curi ++;
            }
            else if(curj != 0 && !v[curi][curj-1])
            {

                curj--;

            }
            else
            {
                dir = 2;
            }
        }
        else ///down
        {
            if(curj != c-1 && !v[curi][curj+1])
            {
                dir = 1;
                curj ++;
            }
            else if(curi != r-1 && !v[curi+1][curj])
            {
                curi++;
            }
            else
            {
                dir = 3;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}