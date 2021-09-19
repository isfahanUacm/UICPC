#include <bits/stdc++.h>
using namespace std;

// Repeated Substrings

const int maxn = 1e5 + 3;

string s;
int n, sa[maxn], ra[maxn], cnt, phi[maxn], plcp[maxn], lcp[maxn];
vector<pair<pair<int, int>, int>> tmp;
pair<int, int> prevy, nil = {-1, -1};

inline void computeLCP(){
    phi[sa[0]] = -1;
    for(int i = 1; i < n; i++)
        phi[sa[i]] = sa[i-1];
    int l = 0;
    for(int i = 0; i < n; i++){
        if(phi[i] == -1){
            plcp[i] = 0;
            continue;
        }
        while(s[i + l] == s[phi[i] + l])
            l++;
        plcp[i] = l;
        l = max(0, l-1);
    }
    for(int i = 0; i < n; i++)
        lcp[i] = plcp[sa[i]];
}

int main(){
    cin >> s;
    s += '$';
    n = s.size();
    for(int i = 0; i < n; i++)
        sa[i] = i, ra[i] = s[sa[i]];
    for(int k = 1; k < n; k *= 2){
        tmp.clear();
        for(int i = 0; i < n; i++)
            tmp.push_back({{ra[sa[i]], (sa[i] + k >= n) ? 0 : ra[sa[i] + k]}, sa[i]});
        sort(tmp.begin(), tmp.end());
        cnt = -1;
        prevy = {-1, -1};
        for(int i = 0; i < n; i++){
            sa[i] = tmp[i].second;
            if(tmp[i].first != prevy)
                cnt++;
            ra[sa[i]] = cnt;
            prevy = tmp[i].first;
        }
        if(ra[sa[n-1]] == n-1)
            break;
    }
    computeLCP();
    int ans = 0, ansi;
    for(int i = 1; i < n; i++)
        if(lcp[i] > ans)
            ans = lcp[i], ansi = i;
    cout << s.substr(sa[ansi], ans) << endl;
}