#include <bits/stdc++.h>
using namespace std;

// Spelling Bee

string s, t;
char center;
set<char> d;
int n;

inline bool valid(string t){
    if(t.size() < 4)
        return false;
    int cnt = 0;
    for(char c : t){
        if(d.find(c) == d.end())
            return false;
        if(c == center)
            cnt++;
    }
    return cnt;
}

int main(){
    cin >> s;
    center = s[0];
    for(char c : s)
        d.insert(c);
    cin >> n;
    while(n--){
        cin >> t;
        if(valid(t))
            cout << t << endl;
    }
}