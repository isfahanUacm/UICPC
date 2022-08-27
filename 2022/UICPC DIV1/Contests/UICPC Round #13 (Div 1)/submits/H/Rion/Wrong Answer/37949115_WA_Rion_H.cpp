#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<char> cl(n);
    for (int i = 0; i < n; i++)
        cin >> cl[i];

    int bells = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // for (int i = 0; i < n; i++)
        //     cout << cl[i];
        // cout << '\n';

        // if (cl[i] == 'O')
        // {
        //     cl[i] = 'Z';
        //     o_count--;
        //     bells += (int)pow((n - i), 2);
        //     i = n;
        // }
        // else
        // {
        //     cl[i] = 'O';
        //     o_count++;
        // }

        if (cl[i] == 'O')
        {
            bells += (int)pow(2, (n - i - 1));
        }
    }

    cout << bells;
    return 0;
}