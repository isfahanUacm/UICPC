#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    int n, drnk = 0, has = 0; cin >> n;
    char c;
    for(int i = 0; i < n; ++i) {
        cin >> c;
        if(c == '1') {
            has = 2;
            drnk++;
        } else if(has > 0) {
            has--;
            drnk++;
        }
    }
    cout << drnk << '\n';
}
