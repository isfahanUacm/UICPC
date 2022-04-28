#include <bits/stdc++.h>
using namespace std;

// Presidential Elections

#define inf LLONG_MAX
#define num long long int

int S;
vector<int> D;
vector<num> C;
vector<num> F;
vector<num> U;

num memo[10003][4040];

num dp(int s, int dif){
    if(memo[s][dif+2016] != -1)
        return memo[s][dif+2016];
    if(s == S)
        return memo[s][dif+2016] = dif > 0 ? 0 : inf;
    int d = D[s]; 
    num c = C[s], f = F[s], u = U[s];
    num ans = dp(s+1, c > f + u ? dif + d : dif - d);
    if(u + f == c){
        num subp = dp(s+1, dif+d);
        if(subp != inf)
            ans = min(ans, subp + 1);
    }
    if(u > abs(c - f)){
        num subp = dp(s+1, dif+d);
        if(subp != inf)
            ans = min(ans, subp + 1 + (u - abs(c - f)) / 2 + max(0ll, f-c));
    }
    return memo[s][dif+2016] = ans;
}

int main(){
    cin >> S;
    int d;
    num c, f, u;
    for(int i = 0; i < S; i++){
        cin >> d >> c >> f >> u;
        D.push_back(d);
        C.push_back(c);
        F.push_back(f);
        U.push_back(u);
    }
    for(int i = 0; i <= S; i++)
        for(int d = 0; d < 4040; d++)
            memo[i][d] = -1;
    num ans = dp(0, 0);
    if(ans == inf)
        cout << "impossible" << endl;
    else cout << ans << endl;   
}