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

bool judge(int v){
    for (int i = 0; i < 26; ++i)
        if(source[i] * k < target[i] * v){
            return false;
        }
    return true;
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
    ll lo = 0, hi = 1e9 + 3, mid;
    while(lo < hi){
        mid = (lo + hi) / 2 + (lo + hi) % 2;
        if(judge(mid))
            lo = mid;
        else
            hi = mid - 1;
    }
    cout << lo << endl;
    return 0;
}

