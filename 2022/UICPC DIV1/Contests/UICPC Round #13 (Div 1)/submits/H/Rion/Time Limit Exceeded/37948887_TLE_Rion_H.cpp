#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    int o_count = 0;
    vector<char> cl(n);
    for (int i = 0; i < n; i++)
    {
        cin >> cl[i];
        if (cl[i] == 'O') o_count++;
    }

    if (o_count == 0)
    {
        cout << 0;
        return 0;
    }

    int bells = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // for (int i = 0; i < n; i++)
        //     cout << cl[i];
        // cout << '\n';

        if (cl[i] == 'O')
        {
            cl[i] = 'Z';
            o_count--;
            bells++;
            i = n;
        }
        else
        {
            cl[i] = 'O';
            o_count++;
        }

        if (o_count == 0)
            break;
    }

    cout << bells;
    return 0;
}