#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        string a, b;
        cin >> a >> b;

        vector<string> ak(k);
        vector<string> bk(k);
        for (int i = 0; i < n; i++)
        {
            ak[i % k] += a[i];
            bk[i % k] += b[i];
        }
        vector<string> atmp(ak);
        vector<string> btmp(bk);
        bool left = true, right = true;
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < ak[i].size(); j++)
            {
                if (ak[i][j] != bk[i][j])
                {
                    if (j + 1 < ak[i].size() && ak[i][j + 1] == bk[i][j])
                    {
                        ak[i][j] = bk[i][j];
                    }
                    else if (j - 1 >= 0 && ak[i][j - 1] == bk[i][j])
                    {
                        ak[i][j] = bk[i][j];
                    }
                    else
                    {
                        left = false;
                        break;
                    }
                }
            }

            for (int j = atmp[i].size() - 1; j >= 0; j--)
            {
                if (atmp[i][j] != btmp[i][j])
                {
                    if (j + 1 < atmp[i].size() && atmp[i][j + 1] == btmp[i][j])
                    {
                        atmp[i][j] = btmp[i][j];
                    }
                    else if (j - 1 >= 0 && atmp[i][j - 1] == btmp[i][j])
                    {
                        atmp[i][j] = btmp[i][j];
                    }
                    else
                    {
                        right = false;
                        break;
                    }
                }
            }
        }

        if (left || right)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    return 0;
}