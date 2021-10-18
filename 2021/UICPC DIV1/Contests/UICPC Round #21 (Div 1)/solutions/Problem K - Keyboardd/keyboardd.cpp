#include <bits/stdc++.h>
using namespace std;

// Keyboardd

string s, t;
map<char, int> sm, _tm;

int main() {
    getline(cin, s);
    getline(cin, t);
    for(char c : s)
        sm[c]++;
    for(char c : t)
        _tm[c]++;
    if (sm[' '] && _tm[' '] == 2 * sm[' '])
        cout << ' ';
    for(char c = 'a'; c <= 'z'; c++)
        if (sm[c] && _tm[c] == 2 * sm[c])
            cout << c;
    cout << endl;   
}