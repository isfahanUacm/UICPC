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


void q(int i,int j) {
    cout << i <<' ' << j << flush << endl;
}

void solve() {

    ull n;
    cin >> n;

    n = n % 1000000007;

    __int128 num = n;
    __int128  sum = 0,tmp;
    tmp = (num * (num + 1) % 1000000007);

    sum =  (tmp * 2)% 1000000007;
    sum = sum + (4 * ((tmp * (2 * n + 1)) % 1000000007))/6;
    sum = sum + num;

    sum = sum % 1000000007;

    print128(sum);



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