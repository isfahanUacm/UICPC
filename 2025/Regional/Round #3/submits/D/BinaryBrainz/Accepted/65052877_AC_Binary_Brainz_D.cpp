#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define ld long double
#define vll vector<ll>
#define vi vector<int>
#define INF 9223372036854775807

/* IN THE NAME OF GOD */

void solve() {
    string s;
    cin >> s;
    map<char , int> a;
    for(char x : s){
        a[x]++;
    }
    int cnt = 0;
    for(auto x : a){
        if(x.second % 2 != 0){
            cnt++;
        }
    }
    if(cnt > 1){
        cout << "no";
    }
    else{
        cout << "yes";
    }
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    //cin >> T;
    while (T--)
        solve();
    return 0;
}