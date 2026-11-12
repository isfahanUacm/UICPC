#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, m;
    cin >> n >> m;
    long arr[n];
    long sum[m + 1];
    memset(sum,0,sizeof sum);
    vector<long> res(m+1);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        sum[arr[i]] += arr[i];
    }

    res[m] = sum[m];

    for (int i = m - 1; i > 0; i--)
    {
        res[i] = sum[i] + res[i + 1];
    }

    // sort(res, res + m + 1 , greater<int>());

        for (int i = 1; i <= m; i++)
    {
        cout << res[i] << " ";
    }
}