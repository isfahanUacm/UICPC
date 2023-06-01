#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;

    cin >> n;

    bool stopped = true;
    int timer = 0;
    int prev = 0;
    int num;

    if (n % 2 == 0)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> num;

            if (!stopped)
            {
                timer += num - prev;
            }

            prev = num;

            stopped = !stopped;
        }

        cout << timer;
    }
    else
    {
        cout << "still running";
    }

    return 0;
}