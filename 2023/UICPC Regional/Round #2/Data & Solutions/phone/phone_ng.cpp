#include <iostream>
#include <string>

using namespace std;

int MAX_n = 30000;

int main() {
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        string P[MAX_n];
        for (int i = 0; i < n; i++) {
            cin >> P[i];
        }
        sort(P, P + n);
        bool ok = true; 
        for (int i = 0; i < n-1; i++) {
            size_t j = 0;
            while (j < P[i].size() && j < P[i+1].size() 
                    && P[i][j] == P[i+1][j]) j++;
            if (j == P[i].size() || j == P[i+1].size()
                    || P[i][j] == P[i+1][j]) {
                ok = false;
            } 
        }
        if (ok) cout << "YES\n";
        else    cout << "NO\n";
    }
}
