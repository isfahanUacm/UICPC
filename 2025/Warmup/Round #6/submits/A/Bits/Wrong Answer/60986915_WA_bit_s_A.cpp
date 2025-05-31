#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);

void solve()
{
    int n, m, h; cin >> n >> m >> h;
    vector<vector<int>> v(n, vector<int>(m));
    vector<pair<int, int>> p(n);
    int answer = 0;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            cin >> v[i][j];
        }
        std::sort(v[i].begin(), v[i].end());

        int penalty = 0;
        int time = 0;
        int solved = 0;
        for(auto x : v[i])
        {
            if(time + x <= h)
            {
                time += x;
                penalty += time;
                solved++;
            }
            else break;
        }
        p[i].first = solved;
        p[i].second = penalty;

        if(i!=0)
        {
            if(p[i].first > p[0].first) answer++;
            else if(p[i].first == p[0].first  &&  p[i].second < p[0].second) answer++;
        }
    }

    cout << answer+1 << '\n';
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