#include <bits/stdc++.h>
using namespace std;

#define num long long int

int W,vh,N;
int xs[100000],ys[100000];
int S;
int ss[1000000];

bool judge(int sp){
    num s = ss[sp];
    num l = 0, r = 200000000 * s;
    num y = 0;
    for(int i = 0; i < N; ++i){
        l -= (num)(ys[i] - y) * vh;
        r += (num)(ys[i] - y) * vh;
        if(l < xs[i] * s)
            l = xs[i] * s;
        if(r > (xs[i] + W) * s)
            r = (xs[i] + W) * s;
        if (r < l)
            return false;
        y = ys[i];
    }
    return true;
}

int main() {
    
    cin >> W >> vh >> N;
    for(int i = 0; i < N; ++i)
        cin >> xs[i] >> ys[i];

    cin >> S;
    for(int i = 0; i < S; ++i)
        cin >> ss[i];

    sort(ss, ss + S);

    int lo = -1, hi = S;
    while (lo + 1 < hi) {
        int mid = (lo + hi) / 2;
        if (judge(mid))
            lo = mid;
        else
            hi = mid;
    }
    
    cout << ((lo == -1) ? "IMPOSSIBLE" : to_string(ss[lo])) << endl;
    
    return 0;
}