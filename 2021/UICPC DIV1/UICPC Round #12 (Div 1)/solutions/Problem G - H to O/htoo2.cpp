#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll source[30], target[30];
string s, t;
ll j, k;

void myfill(string st, bool flag){
    for (int i = 0; i < st.length(); ++i) {
        j = i;
        while(i+1 < st.length() && st[i+1] < 60)
            i++;
        if(flag) // for filling source
            source[st[j] - 'A'] += ((i == j) ? 1 : stoi(st.substr(j+1, i-j)));
        else    // for filling target
            target[st[j] - 'A'] += ((i == j) ? 1 : stoi(st.substr(j+1, i-j)));
    }
}

int main()
{
    cin >> s >> k >> t;
    myfill(s, true);
    myfill(t, false);
    for (int i = 0; i < 26; ++i){
        if(target[i] && !source[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    ll res = LONG_LONG_MAX;
    for (int i = 0; i < 26; i++)
        if (target[i])
            res = min(res, source[i] * k / target[i]);
    cout << res << endl;
    return 0;
}

