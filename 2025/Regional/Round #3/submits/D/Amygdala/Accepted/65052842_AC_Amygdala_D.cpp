#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);
#define vecInt vector<int>
#define pInt pair<int, int>
#define vin(v) for(auto &x : v) cin >> x;
#define vout(v) for(auto x : v) cout << x << ' '; cout << '\n';

int cnt[50];

void solve()
{
    string s;
    cin >> s;
    fill(cnt , cnt+26 , 0);
    for(int i=0 ; i<s.size() ; i++){
        cnt[s[i]-'a']++;
    }
    int odd=0;
    for(int i=0 ; i<26 ; i++){
        if(cnt[i]%2==1)
            odd++;
    }
    cout << (odd <= 1 ? "yes" : "no");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    //cin >> t;
    while(t--)
    {
        solve();
    }

//    for(int i=1; i<20; i++) cout << i << ':' << is_prime(i) << endl;
    return 0;
}