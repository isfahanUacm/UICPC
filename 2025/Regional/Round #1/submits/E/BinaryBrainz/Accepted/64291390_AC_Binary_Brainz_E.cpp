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

    ll m = 2;
    ll g = 6;

    ll a,b;
    char t;
    cin >> a >> t >>  b;

    m += a;
    g += (2 * b);


    cout << (m > g ? "YES" : m < g ? "NO" : "PENALTIES") ;
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("ghanophobia.in","r",stdin);

    ll t = 1;

    cin >> t;

    int i = 1;
    while (i <= t) {
        ll m = 1;
        ll g = 6;

        ll eg,gg;
        char tr;
        cin >> eg >> tr >>  gg;

        m += eg;
        g += gg;


        string res;
        if (m > g)
            res = "YES";
        else if (m < g)
            res = "NO";
        else {
            m += 1;
            g += gg;
            if (m > g)
                res = "YES";
            else if (m < g)
                res = "NO";
            else
                res = "PENALTIES";
        }

        cout << "Case "<< i <<": " << res ;

        if (i < t)
            std::cout << '\n';
        i++;
    }
    cout.flush();
    return 0;
}