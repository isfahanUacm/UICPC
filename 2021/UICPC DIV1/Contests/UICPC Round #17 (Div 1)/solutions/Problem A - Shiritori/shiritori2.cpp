#include <bits/stdc++.h>
using namespace std;

// Shiritori

int n;
string s[100003];
set<string> t;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> s[i];
    t.insert(s[0]);
    for(int i = 1; i < n; i++){
        if(t.find(s[i]) != t.end() || (s[i][0] != s[i-1].back())){
            cout << "Player " << (i % 2 ? "2 " : "1 ") << "lost" << endl;
            return 0;
        }
        t.insert(s[i]);
    }
    cout << "Fair Game" << endl;
}