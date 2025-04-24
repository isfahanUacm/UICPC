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
//    cout << fixed;
//    cout << setprecision(10);
    ll t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}

void solve() {
    int n;
    cin >> n;
    int p[n];
    int j = 0;
    for (int i = 2; i <= n; i += 2) {
        p[j] = i;
        j++;
    }
    for (int i = 1; i <= n; i += 2) {
        p[j] = i;
        j++;
    }

    for (int i = 0; i < n; i++) {
        cout << p[i] << " ";
    }
    cout << endl;
}