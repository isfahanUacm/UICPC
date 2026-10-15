// #include <iostream>
// #include <map>
// #include <set>
// #include <vector>
// #include <stack>
// #include <algorithm>
// #include <iomanip>
// #include <unordered_set>
// #include <unordered_map>
// #include <list>
// #include <numeric>
// #include <queue>
// #include <cmath>
// #include <functional>
// #include <sstream>
#include <bits/stdc++.h>

using namespace std;
typedef unsigned long long int ull;
typedef long long int ll;

#define veci vector<int>
#define vecl vector<ll>
#define vecp vector<pair<int, int>>

#define ilp(s,f) for(ll i = s; i < f; i++)
#define jlp(s,f) for(ll j = s; j < f; j++)
#define klp(s,f) for(ll k = s; k < f; k++)
#define rlp(s,f) for(ll r = s; r >= f; r--)
#define getvec(n,v) ilp(0,n)cin >> v[i];
#define getpvec(n,v)ilp(0,n)cin >> v[i].first >> v[i].second;
#define nextl(q) if (q) cout << endl;

template<class T> bool ckmin(T& a, const T& b){ return a > b ? a = b,true : false; }
template<class T> bool ckmax(T& a, const T& b){ return a < b ? a = b,true : false; }

#define INF 9223372036854775807
// #define MOD 1000000007
#define MOD 998244353

template <typename T>
void prefixSum(const vector<T>& arr, vector<T>& sum) {
    sum = vector<T>(arr.size() + 1);
    sum[0] = 0;

    for (int i = 0; i < arr.size(); i++) {
        sum[i + 1] = sum[i] + arr[i];
    }
}

void print128(__int128 x) {
    if (x == 0) {
        cout << 0;
        return;
    }
    string s;
    bool neg = false;
    if (x < 0) {
        neg = true;
        x = -x;
    }
    while (x > 0) {
        s += (x % 10) + '0';
        x /= 10;
    }
    if (neg) s += '-';
    reverse(s.begin(), s.end());
    cout << s;
}

template <typename T>
void print(vector<T> const& v) {
    ilp(0,v.size()) {
        cout << v[i] << ' ';
    }
}

ll mpow(const ll num, const ll p) {

    if (p == 0) return 1;
    if (p == 1) return num % MOD;

    if (p % 2) {
        return ((num % MOD) * mpow(num, p - 1)) % MOD;
    }
    else {
        const ll tmp = mpow(num, p / 2);
        return (tmp * tmp) % MOD;
    }
}

// lower_bound(a) : first >= a
// upper_bound(a) : first > a


/*  DO NOT QUIT  */



vector<bool> used(10,false);
list<int> p;
ll s = 0;

bool ss(ll m) {

    if (s > m) {
        return false;
    }
    else if (s == m) {
        for (auto &itr: p) {
            cout << itr << ' ';
        }
        cout << '\n';

        return true;
    }

    ilp(1,10) {
        if (!used[i]) {
            p.push_back(i);
            used[i] = true;
            s += i;
            if (ss(m))
                return true;
            used[i] = false;
            p.pop_back();
        }
    }
}



void solve() {

    ll n,m;
    cin>> n >>m;

    vector<ll> v(n * m + 1);
    v[0] = 1;
    ilp(1,n * m + 1) {
        ll g = gcd(i,i + 1);
        ll x = (i * (i + 1)) / g;
        v[i] = x;
    }


    cout << "YES" << endl;

    ilp(0,n) {
        jlp(0,m) {
            cout << v[i + j + 1] <<' ';
        }
        cout << '\n';
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.in","r",stdin);

    ll t = 1;
    cin >> t;

    while (t--){
        solve();
        if (t) cout << endl;
    }
    return 0;
}