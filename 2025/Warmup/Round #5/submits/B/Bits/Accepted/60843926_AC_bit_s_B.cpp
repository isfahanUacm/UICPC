#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);


vector<int> adj[100001];

void solve()
{
    string s; cin >> s;
    int k; cin >> k;
    vector<int> v(26);
    loop(26, i) cin >> v[i];

    ll res = 0;
    int i;
    for(i=0; i<s.size(); i++)
    {
        res += (i+1) * v[s[i] - 'a'];
    }

    int max_val = *(max_element(v.begin(), v.end()));
    i++;
    while(k--)
    {
        res += i++ * max_val;
    }

    cout << res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();


    return 0;
}