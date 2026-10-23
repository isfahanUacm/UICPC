#include <bits/stdc++.h>
using namespace std;
void solve() {
    string s;
    cin >> s;
    set<char> set;
    for (int i = 0; i < s.length(); i++) {
        set.insert(s[i]);
    }
    if (set.size() == 1) {
        cout << 0;
    }
    else {cout<<2*s.length()-2;}
}

int main() {

    int t=1;
    cin>>t;
    while(t--){
        solve();
        if (t)cout<<"\n";
    }

    return 0;
}