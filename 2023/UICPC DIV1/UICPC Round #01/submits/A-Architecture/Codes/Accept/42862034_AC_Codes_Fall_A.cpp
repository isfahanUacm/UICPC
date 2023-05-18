// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    int x;
    int mx1 = -1, mx2 = -1;
    for(int i = 0; i < n; ++i) { cin >> x; mx1 = max(mx1, x); }
     for(int i = 0; i < m; ++i) { cin >> x; mx2 = max(mx2, x); }
     if(mx1 == mx2) cout << "possible" ;
     else cout << "impossible";

    return 0;
}


