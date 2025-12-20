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

#define INF 9223372036854775807
#define MOD 1000000007

template<class T> bool ckmin(T& a, const T& b){ return a > b ? a = b,true : false; }
template<class T> bool ckmax(T& a, const T& b){ return a < b ? a = b,true : false; }

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
void print(vector<T> v) {
    ilp(0,v.size()) {
        cout << v[i] << ' ';
    }
}

// lower_bound(a) : first >= a
// upper_bound(a) : first > a

/*  DO NOT QUIT  */


ll mpow(const ll num, const ll p) {

    if (p == 0) return 1;
    if (p == 1) return num;

    if (p % 2) {
        return (num % MOD) * (mpow(num, p - 1) % MOD);
    }
    else {
        ll tmp = mpow(num, p / 2) % MOD;
        return tmp  * tmp;
    }
}


void solve() {

    int n;
    cin >> n;

    while (n) {
        string s,t;
        cin >> s >> t;

        int scnta = 0;
        int scntb = 0;

        int tcnta = 0;
        int tcntb = 0;

        list<pair<int,char>> m;

        char tog = '\0';
        rlp(n-1,0) {
            if (s[r] != t[r]) {
                tog = s[r];
                break;
            }
        }

        if (tog == '\0') {
            cout << "no\n";
        }
        else {
            int all = 0;

            ilp(0,n) {
                if (s[i] == 'a') {
                    scnta++;
                }
                if (s[i] == 'b') {
                    scntb++;
                }

                if (t[i] == 'a') {
                    tcnta++;
                }
                if (t[i] == 'b') {
                    tcntb++;
                }

                if (s[i] != t[i]) {
                    if (s[i] == 'a') {
                        if (tog == 'a') {
                            m.push_back(make_pair(scnta,'B'));
                            all += scnta;
                        }
                        else {
                            m.push_back(make_pair(scnta-1,'B'));
                            all += scnta - 1;
                        }
                    }
                    else {
                        if (tog == 'b') {
                            m.push_back(make_pair(scntb,'A'));
                            all += scntb;
                        }
                        else {
                            m.push_back(make_pair(scntb-1,'A'));
                            all += scntb - 1;
                        }
                    }
                }
            }

            if (scnta != tcnta || scntb != tcntb || all > 10000) {
                cout << "no\n";
            }
            else {
                cout << "yes\n";
                for (auto it = m.rbegin(); it != m.rend(); it++) {
                    ilp(0,it->first) {
                        cout << it->second;
                    }
                }
                cout << '\n';
            }

            cin >> n;
        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    //freopen("input.in","r",stdin);
    ll t = 1;
    //cin >> t;

    while (t--){

        solve();
        if (t) cout << '\n';
    }
    return 0;
}