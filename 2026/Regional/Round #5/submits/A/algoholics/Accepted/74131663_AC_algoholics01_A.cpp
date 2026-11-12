#include <bits/stdc++.h>

using namespace std;

#define int long long
#define FastIO ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define FOR(i,aaaa,bbbb) for(int i=aaaa;i<=bbbb;i++)
#define FORR(i,aaaa,bbbb) for(int i=aaaa;i>=bbbb;i--)
#define pb push_back
#define ALL(v) v.begin(),v.end()
#define lg 31
#define mxn 100005
#define mxa 1000006
const long long inf=LLONG_MAX/5;


signed main(){
    FastIO
    int n, m;
    cin >> n >> m;
    vector<int> r(m + 1, 0);
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        ++r[x];
    }
    int a = 0;
    vector<int> c(m + 1, 0);
    for (int i = 1; i <= m; i++) {
        a += r[i] * i;
        c[i] += c[i - 1] + r[i - 1] * (i - 1);
    }
    for (int i = 1; i <= m; i++)
    {
        cout << a - c[i] << " ";
    }
    
}