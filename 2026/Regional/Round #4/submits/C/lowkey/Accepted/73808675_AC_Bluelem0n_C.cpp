#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n;
        cin >> n;

        long long pos = 0, neg = 0, zero = 0;

        for (int i = 0; i < n; i++)
        {
            long long x, y;
            cin >> x >> y;

            if (x > y)
                pos++;
            else if (x < y)
                neg++;
            else
                zero++;
        }

        long long ans = pos * neg
            + zero * (pos + neg)
            + zero * (zero - 1) / 2;

        cout << ans << '\n';
    }

    return 0;
}