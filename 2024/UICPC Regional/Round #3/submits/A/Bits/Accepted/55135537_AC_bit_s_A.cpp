#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define mod 1000000007

void solve()
{
    int n; cin >> n;
    int max_day = 0;
    vector<vector<int>> planets;
    for(int i=0; i<n; i++)
    {
        vector<int> p(3);
        cin >> p[0] >> p[1] >> p[2];
        planets.push_back(p);
        if(p[0] > max_day)
            max_day = p[0];
    }

    const int s = 1825 * max_day;
    vector<vector<bool>> hours(s);
    for(int k=0; k<n; k++)
    {
        vector<bool> oneday(planets[k][0], false);
        int sr = planets[k][1];
        int ss = planets[k][2];

        if(sr < ss)
        {
            for(int i=0; i<planets[k][0]; i++)
            {
                if(i>sr && i<ss)
                    oneday[i] = true;
            }
        }
        else
        {
            for(int i=0; i<planets[k][0]; i++)
                if(i>sr || i<ss)
                    oneday[i]=true;
        }

        for(int i=0; i<s; i++)
            hours[i].push_back(oneday[i % planets[k][0]]);

    }


    bool impo = true;
    for(int i=0; i<s; i++)
    {
        bool flag = false;
        for(auto x : hours[i])
            if(x == true)
            {
                flag = true;
                break;
            }
        if(!flag)
        {
            cout << i;
            impo = false;
            break;
        }
    }
    if(impo) cout << "impossible";
}

int main()
{
    solve();
    return 0;
}
