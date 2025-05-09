#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

void solve() {
    ll n,k;
    cin>>n>>k;
    string s;
    cin >> s;
    string res = "0" + s + "0";
    int len = s.length();
    s = res;

    vector<char> v(8);
    for(int i =0 ; i< 8;i++){
        v[i] = ((n & 1) ? 'X' : '.');
        n = n >> 1;
    }

    for(int i =0;i<k;i++){
        for(int j =1;j <= len;j++){
            res[j] = v[(s[j]=='X' ? 1 : 0) * 2 +(s[j-1]=='X' ? 1 : 0) * 4 + (s[j+1]=='X' ? 1 : 0) * 1];
            cout << res[j];
        }
        cout << '\n';
        s = res;
    }

}
int main() {

    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t=1;
    //cin>>t;
    while(t--)
    {
        solve();
        if(t!=0)
            cout<<endl;
    }
}
