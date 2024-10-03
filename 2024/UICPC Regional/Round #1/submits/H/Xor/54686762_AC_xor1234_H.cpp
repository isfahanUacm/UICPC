#include <bits/stdc++.h>
using namespace std;
#define ll long int64_t
#define per(i, a, b) for (ll i = a; i < b; i++)
#define rep(i, a, b) for (ll i = a; i >= b; i--)
#define outl(x) cout << x << endl;
#define outc(x) cout << x << " ";

int main()
{
    long long n;
    cin >> n;
    long long a;
    cin >> a;
    long long dis = 0;
    long long min = 0;
    long long max = 0;
    long long ch = 0;
    for(int i=1;i<n;i++)
    {
        long long b;
        cin >> b;
        if (b > a)
        {
            if (ch == 1)
            {
                if (dis < min)
                {
                    min = dis;
                }
                if (min > max)
                    max = min;
                ch = 0;
                dis = 0;
            }
            dis += b - a;
            a = b;
        }
        else if(b<a)
        {
            if (ch == 0)
            {
                min = dis;
                ch = 1;
                dis = 0;
            }

            dis += a - b;
            a = b;
        }
        if (i == n - 1)
        {
            if (dis < min)
            {
                min = dis;
            }
            if (min > max)
                max = min;
        }
    }
    cout << max;
    return 0;
}