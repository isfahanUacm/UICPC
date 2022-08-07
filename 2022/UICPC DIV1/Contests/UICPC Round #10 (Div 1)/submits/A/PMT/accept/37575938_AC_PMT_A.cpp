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

int solve() {
    int n;
    if (!(cin >> n)) {
        return 1;
    }
    int bsum = 0;
    string err = "MOREPROBLEMS";
    set<int> dseen; 
    pair<int, int> p;
    int arr[10] = {0};
    for (int i = 0; i < n; i++) {
        cin >> p.first >> p.second;
        dseen.insert(p.second);
        if (p.first > arr[p.second-1]) {
            arr[p.second-1] = p.first;
        }
    }
    
    if (dseen.size() < 10) {
        cout << err << "\n";
    } else {
        for (int i = 0; i < 10; i++) {
            bsum += arr[i];
        }
        cout << bsum << "\n";
    }
    return 0;
}

int32_t main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    int TET = 1e9;
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
