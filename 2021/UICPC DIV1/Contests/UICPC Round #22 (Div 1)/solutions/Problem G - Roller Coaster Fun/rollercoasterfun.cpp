#include <bits/stdc++.h>
using namespace std;

// Roller Coaster Fun

struct roller{
    int a, b, t;

    roller(int a, int b, int t){
        this->a = a;
        this->b = b;
        this-> t = t;
    }
};

vector<roller> fun_rollers;

int fdp[25003];

int fcdp(int T){
    if(fdp[T] != -1)
        return fdp[T];
    int ans = 0;
    for(roller r : fun_rollers)
        if(r.t <= T)
            ans = max(ans, r.a + fcdp(T - r.t));
    return fdp[T] = ans;
}

vector<roller> dec_rollers;

int dp[103][25003];

int cdp(int i, int T){
    if(i == -1)
        return fcdp(T);
    if(dp[i][T] != -1)
        return dp[i][T];
    int ans = cdp(i-1, T);
    int profit_sum = 0;
    for(int k = 0; 1; k++){
        int time_amount = (k + 1) * dec_rollers[i].t;
        if(time_amount > T)
            break;
        int profit = dec_rollers[i].a - k * k * dec_rollers[i].b;
        if(profit <= 0)
            break;
        profit_sum += profit;
        ans = max(ans, profit_sum + cdp(i-1, T - time_amount));
    }
    return dp[i][T] = ans;
}

int main(){
    for(int i = 0; i < 103; i++)
        for(int j = 0; j < 25003; j++){
            fdp[j] = -1;
            dp[i][j] = -1;
        }
    int n;
    cin >> n;
    int a, b, t;
    for(int i = 0; i < n; i++){
        cin >> a >> b >> t;
        if(a == 0)
            continue;
        if(b == 0)
            fun_rollers.push_back(roller(a, b, t));
        else dec_rollers.push_back(roller(a, b, t));
    }
    int q;
    cin >> q;
    while(q--){
        int T;
        cin >> T;
        cout << cdp(dec_rollers.size() - 1, T) << endl;
    }
}