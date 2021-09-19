#include <bits/stdc++.h>
using namespace std;

// Simplicity

string s;
int a[26 + 3];

int main(){
    cin >> s;
    for(char c : s)
        a[c - 'a']++;
    sort(a, a + 26);
    int ans = 0;
    for(int i = 0; i < 24; i++)
        ans += a[i];
    cout << ans << endl;
}