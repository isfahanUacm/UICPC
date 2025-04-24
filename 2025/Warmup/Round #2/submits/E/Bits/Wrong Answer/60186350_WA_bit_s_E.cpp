#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define loop(n, i) for(int (i)=0; (i)<(n); (i)++)
#define cint(n) int (n); cin >> (n);


void solve()
{
    int n ; cin >> n ;
    map<char,int> mp;
    for(int i = 0 ; i < n ;i  ++)
    {
        string str;
         cin >> str;
         for(char a: str)
            mp[a]++;
    }
    string s; cin >> s ;
    int cnt =0 ;
    for(int i = 1 ; i < s.length() ;i ++)
    {
        if(mp[s[i]] && s[i-1] != s[i])
        {
            cnt++;
        }
    }
    cout << cnt << '\n';
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 1;
//    cin >> n;
    while(n--)
        solve();

    return 0;
}