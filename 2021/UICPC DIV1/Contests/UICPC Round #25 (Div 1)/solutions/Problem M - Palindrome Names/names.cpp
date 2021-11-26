#include <bits/stdc++.h>

using namespace std;

int ans = INT_MAX, leng = 0;
        
int calc_change(string s){
    int res = 0;
    for (int i = 0; i < s.length()/2; ++i)
        if (s[i] != s[s.length()-i-1])
            res++;
    return res;
}

void add_char(string s, int a){
    string t = s;
    for (int i = a-1; i >= 0; --i)
        t += s[i];
    ans = min(ans, a + calc_change(t));
}

int main()
{
    string s;
    cin >> s;
    leng = s.length();
    ans = calc_change(s);
    for (int i = 1; i <= leng; ++i) {
        add_char(s, i);
    }
    cout << ans << endl;
    return 0;
}

