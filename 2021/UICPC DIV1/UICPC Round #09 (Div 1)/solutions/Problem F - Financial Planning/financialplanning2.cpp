#include <bits/stdc++.h>

using namespace std;

#define ll long long int
ll n, m;
ll p[100003], c[100003];

bool observe(ll days){
    ll s = 0;
    for (int i = 0; i < n; ++i) {
        if(c[i] >= days * p[i])
            continue;
        s += days * p[i] - c[i];
        if(s > 1e9)
            break;
    }
    return s >= m;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        cin >> p[i] >> c[i];
    ll lo = 0, hi = 2 * 1e9, mid;
    while(hi > lo){
        mid = (hi + lo) / 2;
        if (observe(mid))
            hi = mid;
        else
            lo = mid + 1;
    }
    cout << lo << endl;
    return 0;
}

