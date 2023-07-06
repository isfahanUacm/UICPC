#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;

    cin >> n >> m;

    int tasks[n] = {};
    int intervals[m] = {};

    for (int i = 0; i < n; i++)
        cin >> tasks[i];
    for (int i = 0; i < m; i++)
        cin >> intervals[i];

    sort(tasks, tasks + n);
    sort(intervals, intervals + m);

    // for (int i = 0; i < n; i++)
    //     cout << tasks[i] << ' ';
    // cout << '\n';
    // for (int i = 0; i < m; i++)
    //     cout << intervals[i] << ' ';
    // cout << '\n';

    int j = 0;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        while (j < m && tasks[i] > intervals[j]) j++;

        if (j >= m) break;

        // cout << "task:#" << i << " v:" << tasks[i] << '\n';
        // cout << "interval:#" << j << " v:" << intervals[j] << '\n';

        count++;
        j++;
    }

    cout << count;

    return 0;
}