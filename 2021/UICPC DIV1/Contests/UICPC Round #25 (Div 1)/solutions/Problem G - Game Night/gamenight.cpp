#include <bits/stdc++.h>
using namespace std;

// Game Night

const int maxn = 1e5 + 3;

int n, a = 0, b = 0, c = 0, psuma[maxn], psumb[maxn], psumc[maxn];
string mans;

int psum(int s, int e, int ps[maxn]){
    if(e >= s)
        return ps[e] - (s ? ps[s-1] : 0);
    return ps[e] + ps[n-1] - ps[s-1];
}

int main(){
    cin >> n >> mans;
    for(int i = 0; i < n; i++){
        if(mans[i] == 'A')
            a++;
        else if(mans[i] == 'B')
            b++;
        else if(mans[i] == 'C')
            c++;
        psuma[i] = (i ? psuma[i-1] : 0) + (mans[i] != 'A');
        psumb[i] = (i ? psumb[i-1] : 0) + (mans[i] != 'B');
        psumc[i] = (i ? psumc[i-1] : 0) + (mans[i] != 'C');
    }
    int ans = INT_MAX;
    for(int i = 0; i < n; i++){
        int curr = 0;
        int sa = i, ea = (sa + a - 1) % n;
        if(a)
            curr += psum(sa, ea, psuma);
        int sb = a ? (ea + 1) % n : sa, eb = (sb + b - 1) % n;
        if(b)
            curr += psum(sb, eb, psumb);
        int sc = b ? (eb + 1) % n : sb, ec = (sc + c - 1) % n;
        if(c)
            curr += psum(sc, ec, psumc);
        ans = min(ans, curr);
        curr = 0;
        sa = i, ea = (sa + a - 1) % n;
        if(a)
            curr += psum(sa, ea, psuma);
        sc = a ? (ea + 1) % n : sa, ec = (sc + c - 1) % n;
        if(c)
            curr += psum(sc, ec, psumc);
        sb = c ? (ec + 1) % n : sc, eb = (sb + b - 1) % n;
        if(b)
            curr += psum(sb, eb, psumb);
        ans = min(ans, curr);
    }
    cout << ans << endl;
}