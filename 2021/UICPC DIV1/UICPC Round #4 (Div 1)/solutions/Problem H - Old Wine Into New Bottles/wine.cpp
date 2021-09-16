#include <bits/stdc++.h>
using namespace std;

// Old Wine Into New Bottles

int t, l, n;
set<int> bottles;
bool dp[500003];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &l, &n), l *= 1000;
        bottles.clear();
        int x, y;
        while(n--){
            scanf("%d %d", &x, &y);
            for(int k = x; k <= y; k++)
                bottles.insert(k);
        }
        if(l > 500000){
            printf("0\n");
            continue;
        }
        fill_n(dp, l+1, 0);
        dp[0] = 1;
        int ans = 0;
        for(int bot : bottles){
            for(int a = 0; a <= l; a++){
                if(dp[a] && a + bot <= l)
                    dp[a + bot] = 1, ans = max(ans, a + bot);
                if(ans == l)
                    break;
            }
            if(ans == l)
                break;
        }
        printf("%d\n", l-ans);
    }
}