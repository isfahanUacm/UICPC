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
    ll t=1;
//    cin >> t;
    while (t--)
        solve();
    return 0;
}

void solve() {
    int n, m, c;
    cin >> n >> m >> c;

    int st[n][2];
    int sc[m];

    int sum1 = 0, sum2 = 0;

    for (int i = 0; i < m; i++) {
        sc[i] = 0;
    }

    for (int i = 0; i < n; i++) {
        cin >> st[i][0];
        cin >> st[i][1];

        st[i][0]--;
        st[i][1]--;

        if (sc[st[i][0]] < c) {
            sc[st[i][0]]++;
            sum1++;
        } else if (sc[st[i][1]] < c) {
            sc[st[i][1]]++;
            sum2++;
        }
    }

    cout << sum1 << " " << sum2;
}