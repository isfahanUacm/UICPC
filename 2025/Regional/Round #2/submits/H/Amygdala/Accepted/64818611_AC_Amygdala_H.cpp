#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

vector<int> f1()
{
    vector<int> v;
    for(int i=1; i<10; i++)
        v.push_back(i);
    return v;
}
vector<int> f2()
{
    vector<int> v;
    for(int i=10; i<100; i++)
        v.push_back(i);
    return v;
}
vector<int> f3()
{
    vector<int> v;
    for(int i=100; i<1000; i++)
        v.push_back(i);
    return v;
}
void solve()
{
    string a,b,c;   cin >> a >> b >> c;
    vector<int> v,u;
    if(a.length()==1)   v = f1();
    else if(a.length() == 2) v = f2();
    else v = f3();
    if(b.length()==1)   u = f1();
    else if(b.length() == 2) u = f2();
    else u = f3();

    int ans = 0;
    int res[3];

    for(int na : v){
        map<char ,char> mpa;
        string s = to_string(na);
        bool flag = 0;
        for(int i=0; i<a.length(); i++)
        {
            if(mpa.contains(s[i])) {
                if(mpa[s[i]] != char(a[i])){
                    flag = 1;
                    break;
                }
            }
            else {
                for(pair<char,char> p : mpa){
                    if(p.second == a[i]){
                        flag = 1;
                        break;
                    }
                }
                mpa[s[i]] = a[i];
            }
        }
        if(flag)    continue;
        for(int nb : u){
            map<char,int> mpb;
            s = to_string(nb);
            flag = 0;
            for(int i=0; i<b.length(); i++)
            {
                if(mpa.contains(s[i])) {
                    if(mpa[s[i]] != char(b[i])){
                        flag = 1;
                        break;
                    }
                }
                else if(mpb.contains(s[i])) {
                    if(mpb[s[i]] != char(b[i])){
                        flag = 1;
                        break;
                    }
                }
                else{
                    for(pair<char,char> p : mpa){
                        if(p.second == b[i]){
                            flag = 1;
                            break;
                        }
                    }
                    for(pair<char,char> p : mpb){
                        if(p.second == b[i]){
                            flag = 1;
                            break;
                        }
                    }
                    mpb[s[i]] = b[i];
                }
            }
            if(flag)    continue;
            int sum = na + nb;
            s = to_string(sum);
            flag = 0;
            if(s.length() != c.length())
                continue;
            for(int i=0; i<c.length(); i++)
            {
                if(mpa.contains(s[i])) {
                    if(mpa[s[i]] != char(c[i])){
                        flag = 1;
                        break;
                    }
                }
                else if(mpb.contains(s[i])) {
                    if(mpb[s[i]] != char(c[i])){
                        flag = 1;
                        break;
                    }
                }
                else{
                    for(pair<char,char> p : mpa){
                        if(p.second == c[i]){
                            flag = 1;
                            break;
                        }
                    }
                    for(pair<char,char> p : mpb){
                        if(p.second == c[i]){
                            flag = 1;
                            break;
                        }
                    }
                    mpb[s[i]] = c[i];
                }
            }
            if(flag) continue;
            ans++;
            if(ans == 1){
                res[0] = na;
                res[1] = nb;
                res[2] = sum;
            }
        }
    }
    cout << ans << '\n';
    if(ans)
        cout << res[0] << '\n' << res[1] << '\n' << res[2] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
//    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}