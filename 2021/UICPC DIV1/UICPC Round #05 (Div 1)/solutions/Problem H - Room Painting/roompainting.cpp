#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m, q;
    long long int res = 0;
    cin>>n>>m;
    int arr[n];
    for (int i = 0; i < n; ++i)
        cin>>arr[i];
    sort(arr, arr+n);
    for (int i = 0; i < m; ++i) {
        cin>>q;
        auto f = lower_bound(arr, arr+n, q);
        res += *f - q;
    }
    cout<<res<<endl;
    return 0;
}

