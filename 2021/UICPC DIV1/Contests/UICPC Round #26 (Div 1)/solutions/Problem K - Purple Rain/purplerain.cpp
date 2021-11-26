#include <bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int>> result;

string s;

result solve(char ch){
    result res = {0, {0, 0}};
    int mx = 0, c = 0, st = 0;
    for (int i = 0; i < s.length(); ++i) {
        if(s[i] == ch){
            c++;
        }
        else{
            c--;
        }
        if(mx < c){
            mx = c;
            res = {mx, {st, i}};
        }
        if(c < 0){
            c = 0;
            st = i+1;
        }
    }
    return res;
}

int main()
{
    cin >> s;
    result res1 = solve('B');
    result res2 = solve('R');
    if(res1.first > res2.first){
        cout << res1.second.first + 1 << " " << res1.second.second + 1 << endl;
    }
    else if(res1.first < res2.first){
        cout << res2.second.first + 1 << " " << res2.second.second + 1 << endl;
    }
    else{
        if(res1.second < res2.second){
            cout << res1.second.first + 1 << " " << res1.second.second + 1 << endl;
        }
        else{
            cout << res2.second.first + 1 << " " << res2.second.second + 1 << endl;
        }
    }
    return 0;
}

