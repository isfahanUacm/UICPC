#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    freopen("ghanophobia.in", "r", stdin);
    int t;
    cin >> t;
    vector<string> m(t);
    vector<int> E(t);
    vector<int> G(t);
    for (int i = 0; i < t; i++)
    {
        cin >> m[i];
        string e, g;
        int j;
        for (j = 0; j < m[i].size(); j++)
        {
            if (m[i][j] == ':')
                break;
            else
            {
                e += m[i][j];
            }
        }
        E[i] = stoi(e);
        for (j = j + 1; j < m[i].size(); j++)
        {
            g += m[i][j];
        }
        G[i] = stoi(g);

        G[i] *= 2;
        if (E[i] - G[i] > 4)
        {
            cout << "Case " << i + 1 << ": YES" << endl;
        }
        else if (E[i] - G[i] == 4)
        {
            cout << "Case " << i + 1 << ": PENALTIES" << endl;
        }
        else
        {
            cout << "Case " << i + 1 << ": NO" << endl;
        }
    }

    return 0;
}