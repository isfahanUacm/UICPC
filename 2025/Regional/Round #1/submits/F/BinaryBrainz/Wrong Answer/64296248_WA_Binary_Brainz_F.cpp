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

//#include <bits/stdc++.h>

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
#define endl '\n'

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


/*  DO NOT GIVE UP  */



void solve() {

}

ll fun(ll mid,ll sl,ll sr,ll cnt) {
    ll x;
    if (mid <= cnt) {
        x = (mid * (mid + 1)) / 2;
        x += sl;
    }
    else {
        x = sr;
        ll rind = cnt + cnt - 1;
        rind -= mid;

        x -= ((rind * (rind + 1)) / 2);
    }
    return x;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("army.in","r",stdin);

    vector<ll> inds(10000000);
    vector<ll> v(10000000);
    v[0] = 1;
    inds[1] = 1;
    ll cnt = 1;
    ilp(1,10000000) {
        ll n = i + 1;
        ll sum = (n * (n + 1)) / 2;
        sum += (n * (n - 1)) / 2;
        v[i] = v[i-1] + sum;
        inds[i] = inds[i-1]+ cnt + 2;
        cnt += 2;
    }

    ll t = 1;
    cin >> t;

    int i = 1;
    while (i <= t) {

        ll n ;
        cin >> n;

        ll line = upper_bound(v.begin(), v.end(), n) - v.begin();
        line--;

        ll sum = v[line];

        int low = 0 , high = (line + 1)*2-1;
        ll ans= INF;

        while (low <= high) { // if low and high are
            ll mid = (low + high) / 2;
            ll x= fun(mid,v[line],v[line+1],line+2);

            if (x>=n)
                ans = min(mid,ans);

            if (n < x)
                high = mid-1;
            else if (n > x)
                low = mid+1;
            else break;
        }



        ll res = inds[line] + ans;
        cout << "Case "<< i <<": " << res+1 ;

        if (i < t)
            std::cout << '\n';
        i++;
    }
    cout.flush();
    return 0;
}