#include <bits/stdc++.h>
using namespace std;

int main()
{
    int s, n, k;
    cin >> s >> n;

    if (n == 1)
    {
        if ((s % 2) == 0)
            cout << (s - 1) / 2;
        else
            cout << (s - 2) / 2;
        return 0;
    }

    vector<int> seated(s, 0);

    int prev = -1, curr = -1, diff;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        k -= 1;

        prev = k + 1; // last one

        seated[k] = 1;
    }

    int count = 0;

    for (int i = 0; i < s; i++)
    {
        if (seated[i] == 0)
            continue;

        curr = i + 1;

        // CHECK EDGE CASE -> S-1 and 1-S

        if (prev > curr)
            diff = (s - prev) + curr - 1;
        else
            diff = curr - prev - 1;

        if (diff % 2 == 0)
            count += (diff - 1) / 2;
        else
            count += diff / 2;

        prev = curr;
    }

    cout << count;

    return 0;
}