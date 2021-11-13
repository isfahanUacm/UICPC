#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    ll k, n;
    cin >> n >> k;
    vector<pair<ll, ll>> p1;
    vector<pair<ll, ll>> p2;
    vector<pair<ll, ll>> p3;

    for (ll i = 0; i < n; ++i) {
        ll a, b, c;
        cin >> a >> b >> c;
        p1.emplace_back(a, i);
        p2.emplace_back(b, i);
        p3.emplace_back(c, i);
    }
    sort(p1.begin(), p1.end(), greater<>());
    sort(p2.begin(), p2.end(), greater<>());
    sort(p3.begin(), p3.end(), greater<>());

    set<ll> st;
    for (ll i = 0; i < k; ++i) {
        st.insert(p1[i].second);
        st.insert(p2[i].second);
        st.insert(p3[i].second);
    }



    cout << st.size() << endl;
}
