#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    int n; cin >> n;
    vector<ll> h(n);
    for(int i = 0; i < n; ++i) cin >> h[i];
    vector<ll> pk1(n, -1), pk2(n, -1);
    int pos = 0;
    while(pos < n) {
        int lo = pos;
        while(pos + 1 < n && h[pos] <= h[pos + 1]) pos++;
        int pos2 = pos;
        while(pos2 >= 0 && h[pos] == h[pos2]) pk1[pos2] = h[pos] - h[lo], pos2--;
        pos++;
    }
    pos = n - 1;
    while(pos >= 0) {
        int lo = pos;
        while(pos >= 1 && h[pos] <= h[pos - 1]) pos--;
        int pos2 = pos;
        while(pos2 < n && h[pos] == h[pos2]) pk2[pos2] = h[pos] - h[lo], pos2++;
        pos--;
    }
    ll bst = 0;
    for(int i = 1; i < n - 1; ++i) {
        if(pk1[i] == -1) continue;
        if(pk2[i] == -1) continue;
        bst = max(bst, min(pk1[i], pk2[i]));
    }
    cout << bst << '\n';
}
