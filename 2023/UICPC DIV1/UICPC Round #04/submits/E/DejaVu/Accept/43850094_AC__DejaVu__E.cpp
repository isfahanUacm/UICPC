#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const ll MOD = 1e9 + 7;

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define pb push_back
#define mp make_pair
#define all(x) x.begin(), x.end()
#define rall(x) x.rbegin(), x.rend()
#define sz(x) (int)x.size()
#define F first
#define S second

int main()
{
    fastio;
    string s1, s2;
    cin >> s1 >> s2;

    int sF = -1;
    for (int i = 0; i < min(s1.length(), s2.length()); i++)
        if (s1[i] != s2[i])
        {
            sF = i;
            break;
        }

    if (sF == -1)
    {
        if (s2.length() > s1.length())
            cout << s2.length() - s1.length();
        else
            cout << 0;
        return 0;
    }
    else
    {
        int cSame = 0;
        int e1 = s1.length() - 1, e2 = s2.length() - 1;

        while (e1 >= sF && e2 >= sF && s1[e1] == s2[e2])
        {
            e1--;
            e2--;
        }

        cout << e2 - sF + 1;
    }

    return 0;
}
