#ifdef ONPC
#define _GLIBCXX_DEBUG
#endif
#include <bits/stdc++.h>
#define sz(a) ((int)((a).size()))
#define char unsigned char

using namespace std;
// mt19937 rnd(239);
mt19937 rnd(chrono::steady_clock::now().time_since_epoch().count());

typedef long long ll;
typedef long double ld;

int findMax(int arr[], int x, int n) {
    int maxv = arr[x];
    int max = x;
    for (int i = x-arr[x]; i < x+1+arr[x]; i++) {
        if (i>=0 && i<n && arr[i] >= maxv) {
            max = i;
            maxv = arr[i];
        }
    }
    return max;
}
int solve() {
    int n, a, b;
    cin >> n;
    int arr[n];
    
    cin >> a >> b;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    if (n==1) {
        cout << 0 << "\n";
        return 0;
    }
    b--;
    int sum = 0, tmp = --a;
    
    while(abs(tmp-b) > min(arr[tmp], arr[b]) && sum < 10) {
        tmp = findMax(arr, tmp, n);
        sum++;
    }
    cout << sum+1 << "\n";

    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1;
    cin >> TET;
    for (int i = 1; i <= TET; i++) {
        if (solve()) {
            break;
        }
        #ifdef ONPC
            cout << "______" << endl;
        #endif
    }
    #ifdef ONPC
        cerr << endl << "finished in " << clock() * 1.0 / CLOCKS_PER_SEC << " sec" << endl;
    #endif
}
