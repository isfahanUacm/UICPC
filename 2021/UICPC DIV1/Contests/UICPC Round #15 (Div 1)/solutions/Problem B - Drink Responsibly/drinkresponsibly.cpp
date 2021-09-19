#include <bits/stdc++.h>
using namespace std;

// Drink Responsibly

#define eps 1e-6

double tmp;
int m, u, n, s[13], c[13], dp[1003][603], ans[13];
string name[13], frac[13];

int main(){
    cin >> tmp, m = static_cast<int>(100 * tmp + eps);
    cin >> tmp, u = static_cast<int>(30 * tmp + eps);
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> name[i] >> s[i] >> frac[i] >> tmp;
        s[i] *= 30, c[i] = static_cast<int>(100 * tmp + eps);
        if(frac[i] == "1/2")
            s[i] /= 2;
        else if(frac[i] == "1/3")
            s[i] /= 3;
    }
    for(int money = 0; money <= m; money++)
        for(int unit = 0; unit <= u; unit++){
                if(!(money + unit)){
                    dp[money][unit] = n;
                    continue;
                }
                dp[money][unit] = -1;
                for(int i = 0; i < n; i++)
                    if(money >= c[i] && unit >= s[i] && dp[money-c[i]][unit-s[i]] != -1){
                        dp[money][unit] = i;
                        break;
                    }
            }
    if(dp[m][u] == -1){
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    else if(dp[m][u] == n){
        for(int i = 0; i < n; i++)
            if(!(s[i] + c[i])){
                cout << name[i] << " " << 1 << endl;
                return 0;
            }
        cout << "IMPOSSIBLE" << endl; 
        return 0;
    }
    int money = m, unit = u;
    while(money + unit){
        int choice = dp[money][unit];
        ans[choice]++;
        money -= c[choice];
        unit -= s[choice];
    }
    for(int i = 0; i < n; i++)
        if(ans[i])
            cout << name[i] << " " << ans[i] << endl;
}