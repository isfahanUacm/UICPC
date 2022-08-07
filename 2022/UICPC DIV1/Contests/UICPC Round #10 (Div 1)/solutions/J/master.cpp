#include <iostream>
#include <set>

using ll = long long;

using namespace std;

ll gcd(ll a, ll b) {
    while (a) {
        b %= a;
        swap(a,b);
    }
    return b;
}

void divs(ll N, set<ll> &D) {
    for (ll i = 1; i*i <= N; ++i) {
        if (N%i == 0) {
            D.insert(i);
            D.insert(N/i);
        }
    }
}

int main() {
    cin.tie(nullptr);
    int T; cin >> T;
    while (T --> 0) {
        ll A, B; cin >> A >> B;
        set<ll> D{2};
        divs(gcd(A-1, B-1), D);
        divs(gcd(A-2, B), D);
        divs(gcd(A, B-2), D);
        cout << D.size();
        for (ll d: D) cout << ' ' << d;
        cout << '\n';
    }
}

