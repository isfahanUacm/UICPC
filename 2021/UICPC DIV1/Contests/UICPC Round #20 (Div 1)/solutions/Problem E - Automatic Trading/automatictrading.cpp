#include <bits/stdc++.h>
using namespace std;

// Suffix Array Implementation

const int maxn = 1e5 + 3;

string s = "GATAGACA$", p = "GA";
int n = s.size(), m = p.size();
int sa[maxn], ra[maxn], cnt;
vector<pair<pair<int, int>, int>> tmp;
pair<int, int> prevy, nil = {-1, -1};

inline pair<int, int> find_match(){
    // finding lower bound
    int lo = 0, hi = n - 1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(strncmp(s.c_str() + sa[mid], p.c_str(), m) >= 0)
            hi = mid;
        else
            lo = mid + 1;
    }
    if(strncmp(s.c_str() + sa[lo], p.c_str(), m))
        return nil;
    pair<int, int> ans = {lo, -1};
    // finding (inclusive) upper bound
    lo = 0, hi = n-1;
    while(lo < hi){
        int mid = (lo + hi) / 2;
        if(strncmp(s.c_str() + sa[mid], p.c_str(), m) > 0)
            hi = mid;
        else
            lo = mid + 1;
    }
    if(strncmp(s.c_str() + sa[hi], p.c_str(), m))
        hi--;
    ans.second = hi;
    return ans;
}

int phi[maxn], plcp[maxn], lcp[maxn];

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
    int logg[n+1];
    logg[1] = 0;
    for (int i = 2; i <= n; i++)
        logg[i] = logg[i/2] + 1;
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
    int mp[n+1];
    for(int i = 0; i < n; i++)
        mp[sa[i]]= i;
    int K = floor(log2(n))+1;
    int st[n+10][K + 10];
    
    for (int i = 0; i < n; i++)
        st[i][0] = lcp[i];
    for (int j = 1; j <= K; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j-1], st[i + (1 << (j - 1))][j - 1]);
    int q, L, R;
    cin >> q;
    for (int i = 0; i < q; ++i) {
        cin >> L >> R;
        L = mp[L], R = mp[R];
        if(L>R)
            swap(L, R);
        L++;
        int j = logg[R - L + 1];
        int minimum = min(st[L][j], st[R - (1 << j) + 1][j]);
        cout << minimum << endl;
    }
}
