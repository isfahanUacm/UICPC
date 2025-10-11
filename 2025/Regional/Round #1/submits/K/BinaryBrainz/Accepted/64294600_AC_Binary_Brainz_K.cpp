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



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("cubes.in","r",stdin);



    ll t = 1;
    cin >> t;
    int f = 1;
    while (f <= t) {
        int n;
        cin >> n;
        vector<ll> arr(n);
        for (ll i = 0; i < n; i++) {
            cin >> arr[i];
        }
        sort(arr.rbegin(), arr.rend());
        vector<ll> ans(n);
        int i = 0 , j = n - 1;
        for (ll k = 0; k < n; k++) {
            if (k % 2) {
                ans[i] = arr[k];
                i++;
            }
            else {
                ans[j] = arr[k];
                j--;
            }
        }
        cout << "Case " << f << ":\n";
        for (ll i = 0; i < n; i++) {
            cout << ans[i];
            if (i < n - 1) {
                cout << " ";
            }
        }
        if (f < t)
            cout << endl;
        f++;
    }
    return 0;
}