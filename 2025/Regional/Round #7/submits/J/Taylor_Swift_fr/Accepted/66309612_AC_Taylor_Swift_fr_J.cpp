#include <bits/stdc++.h>

#define int long long

using namespace std;

const int N = 2e5 + 9, MOD = 1e9 + 7;
int fact[N], a[N], b[N], num1[N], num2[N];
int n;

int BS1(int m)
{
    int l = -1, r = n;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] < m)
            l = mid;
        else
            r = mid;
    }
    // cout << 1 << " " << r << " " << m << " " << a[r] << endl;
    return r;
}

int BS2(int m)
{
    int l = -1, r = n;
    while (l + 1 < r)
    {
        int mid = (l + r) / 2;
        if (a[mid] <= m)
            l = mid;
        else
            r = mid;
    }
    // cout << 2 << " " << l << " " << m << " " << a[l] << endl;
    return l;
}

int32_t main()
{
    int q;
    cin >> n >> q;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    while (q--)
    {
        int l, r;
        cin >> l >> r;
        cout << BS2(r) - BS1(l) + 1 << "\n";
    }
    return 0;
}