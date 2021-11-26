#include <bits/stdc++.h>
using namespace std;

// Joyless Game

int main(){
    int t;
    string s;
    cin >> t;
    while(t--){
        cin >> s;
        bool first;
        if(s[0] != s[s.size() - 1])
            first = s.size() % 2;
        else first = !(s.size() % 2);
        cout << (first ? "Chikapu" : "Bash") << endl;
    }
}