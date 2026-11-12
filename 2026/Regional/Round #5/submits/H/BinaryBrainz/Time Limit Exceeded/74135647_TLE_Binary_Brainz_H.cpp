#include <bits/stdc++.h>
using namespace std;

#define ll long long

vector<ll> primes;
ll N = 1e5 + 5;
vector<int> v(N);

auto aval(ll x) {
    map<ll , ll> avals;
    ll i = 0;
    while (x > 1) {
        if (v[x] == 0) {
            avals[x] ++;
            break;
        }
        int cnt = 0;
        while (x > 1 && x % primes[i] == 0) {
            x /= primes[i];
            cnt ++;
        }
        avals[primes[i]] = cnt;
        i++;
    }
    return avals;
}

void solve(){
    int q;
    cin >> q;
    int type;
    ll x;
    map<ll , ll> a;
    while(q--) {
        cin >> type >> x;
        if(type == 1) {
            auto m = aval(x);
            for (auto itr : m) {
                if (a[itr.first] != 0) {
                    a[itr.first] += itr.second;
                    if (a[itr.first] > 100) {
                        a[itr.first] = 100;
                    }
                }
                else {
                    a[itr.first] = itr.second;
                }
            }
        }
        else if (type == 2) {
            for (auto itr : a) {
                a[itr.first] *= x;
                if (a[itr.first] > 100) {
                    a[itr.first] = 100;
                }
            }
        }
        else {
            bool yes = true;
            auto m = aval(x);
            for (auto itr : m) {
                if (a[itr.first] < itr.second) {
                    cout << "No\n";
                    yes = false;
                    break;
                }
            }
            if (yes) {
                cout << "Yes\n";
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    v[1] = 1;
    for (int i = 2; i <= N; i++) {
        for (int j = i + i; j <= N; j += i) {
            v[j] = 1;
        }
    }
    for (int i = 1; i <= N; i++) {
        if (v[i] == 0) {
            primes.push_back(i);
        }
    }

    solve();

    return 0;
}