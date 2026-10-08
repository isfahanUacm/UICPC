#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n)
#define sint(s) string (s); cin >> (s)
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n'
#define int ll
// #define endl '\n'

int num1, num2;
bool flag = 1;

bool f(int a, int b, string& as, string& bs , string& cs)
{
    int c = a + b;

    map<char, char> cd, dc;

    string aa = to_string(a);
    string bb = to_string(b);
    string cc = to_string(c);

    if(aa.size() != as.size()) return false;
    if(bb.size() != bs.size()) return false;
    if(cc.size() != cs.size()) return false;

    for(int i=0; i<aa.size(); i++)
    {
        if(cd.count(aa[i]) == 0) cd[aa[i]] = as[i];
        else if(cd[aa[i]] != as[i]) return false;

        if(dc.count(as[i]) == 0) dc[as[i]] = aa[i];
        else if(dc[as[i]] != aa[i]) return false;
    }

    for(int i=0; i<bb.size(); i++)
    {
        if(cd.count(bb[i]) == 0) cd[bb[i]] = bs[i];
        else if(cd[bb[i]] != bs[i]) return false;

        if(dc.count(bs[i]) == 0) dc[bs[i]] = bb[i];
        else if(dc[bs[i]] != bb[i]) return false;
    }

    for(int i=0; i<cc.size(); i++)
    {
        // if(cd.count(cc[i])) cout << cc[i] << ' ' << cd[cc[i]] << ' ' << cs[i]  << endl;
        if(cd.count(cc[i]) == 0) cd[cc[i]] = cs[i];
        else if(cd[cc[i]] != cs[i]) return false;

        if(dc.count(cs[i]) == 0) dc[cs[i]] = cc[i];
        else if(dc[cs[i]] != cc[i]) return false;
    }

    if(flag){
        flag = 0;
        num1 = a;
        num2 = b;
    }

    return true;
}

void solve()
{
    // string s1 = "ABC", s2  = "EFG", s3 = "AAAZ";
    // cout << f(100, 900, s1, s2, s3);
    // return;

    string a, b, c; cin >> a >> b >> c;

    int ans = 0;
    for(int i=1; i<1000; i++)
    {
        for(int j=1; j<1000; j++)
        {
            if(f(i, j, a, b, c))
            {
                ans ++;
            }
        }
    }

    cout << ans << '\n';
    if(!flag){
        cout << num1 << '\n' << num2 << '\n' << num1+num2 << '\n';
    }
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}