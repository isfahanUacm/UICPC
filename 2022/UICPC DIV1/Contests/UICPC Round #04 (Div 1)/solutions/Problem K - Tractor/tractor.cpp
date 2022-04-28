#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
long long int n, m;

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        if(n > m){
            swap(n, m);
        }
        double lg = log2(m+1);
        int x = (int)lg;
        long long int res = max(n + m + 2 - (long long int)pow(2, x+1), 0LL);
        for (int i = 0; i <= x; ++i) {
            res += min(n+1, (long long int)pow(2, i));
        }
        cout << res << endl;
    }
    return 0;
}

