#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vll;

void solve();

template<class T>
void printArray(T *arr, size_t size) {
    if (!size) return;
    for (size_t i = 0; i < size - 1; i++) {
        cout << arr[i] << ' ';
    }
    cout << arr[size - 1];
}

template<class T>
ostream &operator<<(ostream &os, const vector <T> &vec) {
    if (!vec.size()) return os;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        os << vec[i] << ' ';
    }
    os << vec.back();
    return os;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout << setprecision(10);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

void solve() {
    ll n, m, k;
    cin >> n >> m >> k;

    string s;
    cin >> s;

    for (ll i = 0; i < k; i++) {
        int cmd;
        cin >> cmd;

        if (cmd == 1) {
            ll x, y, l, r;
            cin >> x >> y >> l >> r;

            l--;
            r--;

            for (ll j = l; j <= r; j++) {
                if (s[j] == 'U') {
                    if ((x-1) >= 1) x--;
                } else if (s[j] == 'D') {
                    if ((x+1) <= n) x++;
                } else if (s[j] == 'L') {
                    if ((y-1) >= 1) y--;
                } else if (s[j] == 'R') {
                    if ((y+1) <= n) y++;
                }
            }

            cout << x << " " << y << endl;
        } else if (cmd == 2) {
            ll x;
            cin >> x;
            char c;
            cin >> c;

            s[x-1] = c;
        }
    }


}