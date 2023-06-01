#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int q[n];
    int q_copy[n];
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        q_copy[i] = q[i];
    }

    bool changed = true;
    bool already_left = false;
    int j;
    int timer = 0;

    vector<vector<int>> vec;

    while (changed)
    {
        changed = false;
        vec.push_back({});

        for (int i = 0; i < n; i++)
        {
            if (q[i] == -1) continue;
            already_left = false;

            if (i != n - 1)
            {
                j = i + 1;
                while (q[j] == -1 && j < n)
                    j++;

                if (j < n && q[i] < q[j])
                {
                    changed = true;
                    already_left = true;
                    vec[timer].push_back(i);
                }
            }

            if (already_left) continue;

            if (i > 0)
            {
                j = i - 1;
                while (q[j] == -1 && j >= 0)
                    j--;

                if (j >= 0 && q[i] < q[j])
                {
                    changed = true;
                    vec[timer].push_back(i);
                }
            }
        }

        for (int i = 0; i < vec[timer].size(); i++)
            q[vec[timer][i]] = -1;

        timer++;
    }

    cout << timer - 1 << '\n';
    for (int i = 0; i < vec.size() - 1; i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << q_copy[vec[i][j]] << ' ';
        }
        cout << '\n';
    }
    for (int i = 0; i < n; i++)
    {
        if (q[i] != -1)
            cout << q[i] << ' ';
    }

    return 0;
}