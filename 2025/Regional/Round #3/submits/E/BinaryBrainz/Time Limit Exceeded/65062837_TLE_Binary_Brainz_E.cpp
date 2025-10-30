#include <iostream>
#include <map>
#include <set>
#include <vector>
#include <stack>
#include <algorithm>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
#include <list>
#include <numeric>
#include <queue>
#include <cmath>
#include <functional>
#include <sstream>
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

vector<vector<pair<ll,ll>>> adj;

void dijkstra(vector<ll> &d, vector<bool> &v, vector<int> &p, int s) {

    ll n = adj.size();
    d.assign(n,INF);
    p[s] = s;
    d[s] = 0;

    ilp(0,n) {
        int a = -1;
        jlp(0,n) {
            if (!v[j] && (a == -1 || d[j] < d[a] ) ) {
                a = j;
            }
        }

        if (d[a] == INF)
            break;

        v[a] = true;
        for (auto &edge : adj[a]) {
            if (ckmin(d[edge.first], d[a] + edge.second)) {
                p[edge.first] = a;
            }
        }
    }
}

void findPath(vector<int> &path,vector<int> const &p, int s,int f) {
    if (f == s) {
        path.push_back(s);
        return;
    }

    findPath(path,p,s,p[f]);
    path.push_back(f);
}

/*  DO NOT QUIT  */


void solve() {

    int n ;
    cin >> n;

    cout << 1 << ' ' << n << endl <<  flush;

    vector<int> v(n);
    vector<int> s(n+1);
    s[0] = 0;
    ilp(0,n) {
        int tmp;
        cin >> tmp;
        v[i] = (tmp == 1) ? -1 : +1;
        s[i+1] = s[i] + v[i];
    }

    ll l,r,mx = 0;
    int perc;
    cin >> perc;
    while (perc < 70) {
        mx = 0;
        ilp(0,n) {
            jlp(i+1,n) {
                if (s[j+1] - s[i] > mx) {
                    l = i+1;
                    r= j + 1;
                    mx = s[j+1] - s[i];
                }
            }
        }
        cout << l << ' ' << r << '\n' << flush;
        ilp(0,n) {
            int tmp;
            cin >> tmp;
            v[i] = (tmp == 1) ? -1 : +1;
            s[i+1] = s[i] + v[i];
        }
        cin >> perc;
    }
}



int main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    //freopen("input.in","r",stdin);
    ll t = 1;

    //cin >> t;

    while (t--){

        solve();
        //cout << '\n';
    }
    return 0;
}