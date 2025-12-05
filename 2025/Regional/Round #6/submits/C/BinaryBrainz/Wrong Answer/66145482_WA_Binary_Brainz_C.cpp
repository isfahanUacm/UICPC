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


void solve() {

    ll n,m;
    cin >> n >> m;

    vector<pair<int, int>> lst(m+1);
    map<int,pair<int,bool>> cats;

    ilp(0,n) {
        int a;
        cin >>a;
        cats[a].first++;

        int k;
        cin >> k;

        jlp(0,k) {
            int x;
            cin >> x;

            ll last = max(lst[x].first,a);

            if (lst[x].first != last) {
                lst[x].first = last;
                lst[x].second = 1;
            }
            else {
                lst[x].second++;
            }
        }
    }

    vector<int> diff(m+1);
    ilp(1,m+1) {
        if (lst[i].first == 0)
            continue;

        auto ct = cats.find(lst[i].first);
        if (lst[i].second == ct->second.first) {
            ct->second.second = true;
        }
        diff[lst[i].first]++;
    }


    for (auto &itr : cats) {
        if (!itr.second.second) {
            cout << "no";
            return;
        }
    }

    ll sum = 0;
    rlp(m,1) {
        sum += diff[r];
        if (sum > m-r+1) {
            cout << "no";
            return;
        }
    }


    cout << "yes";
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
        cout << '\n';
    }
    return 0;
}