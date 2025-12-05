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

vector<string> per = {
        "NEWS", "NESW", "NWES", "NWSE", "NSWE", "NSEW",
        "ENWS", "ENSW", "EWNS", "EWSN", "ESWN", "ESNW",
        "WENS", "WESN", "WNES", "WNSE", "WSNE", "WSEN",
        "SEWN", "SENW", "SWEN", "SWNE", "SNWE", "SNEW"
};
void solve()
{
    int n, m; cin >> n >> m;
    vector<string> v(n);
    vin(v);
    string path; cin >> path;

    int xs, ys;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++) if(v[i][j] == 'S'){
            v[i][j] = '.';
            xs = i;
            ys = j;
        }
    }

    int cnt = 0;

    vector<string> valid = per;
    for(int i=0; i<path.size(); i++)
    {
        for(int ind =0; ind<valid.size(); ind++)
        {
            char result;
            for(auto x : valid[ind])
            {
                if(x == 'N' && xs > 0 && v[xs-1][ys] == '.')
                {
                    result = 'N';
                    break;
                }
                if(x == 'S' && xs < n-1 && v[xs+1][ys] == '.')
                {
                    result = 'S';
                    break;
                }
                if(x == 'W' && ys > 0 && v[xs][ys-1] == '.')
                {
                    result = 'W';
                    break;
                }
                if(x == 'E' && ys < m-1 && v[xs][ys+1] == '.')
                {
                    result = 'E';
                    break;
                }
            }

            if(result != path[i]){
                swap(valid[ind],valid[valid.size()-1]);
                valid.pop_back();
                ind--;
            }
        }

        if(valid.empty()) {
//            cout << i << endl;
            cnt++;
            valid = per;
            for(int ind =0; ind<valid.size(); ind++)
            {
                char result;
                for(auto x : valid[ind])
                {
                    if(x == 'N' && xs > 0 && v[xs-1][ys] == '.')
                    {
                        result = 'N';
                        break;
                    }
                    if(x == 'S' && xs < n-1 && v[xs+1][ys] == '.')
                    {
                        result = 'S';
                        break;
                    }
                    if(x == 'W' && ys > 0 && v[xs][ys-1] == '.')
                    {
                        result = 'W';
                        break;
                    }
                    if(x == 'E' && ys < m-1 && v[xs][ys+1] == '.')
                    {
                        result = 'E';
                        break;
                    }
                }

                if(result != path[i]){
                    swap(valid[ind],valid[valid.size()-1]);
                    valid.pop_back();
                    ind--;
                }
            }
        }

        if(path[i] == 'N')
        {
            xs --;
        }
        else if(path[i] == 'S')
        {
            xs ++;
        }
        else if(path[i] == 'W')
        {
            ys --;
        }
        else if(path[i] == 'E')
        {
            ys ++;
        }
    }
    cout << cnt << '\n';
}

int main()
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
