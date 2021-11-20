#include <bits/stdc++.h>
using namespace std;

// Volume Amplification

int t, a, y, amp[103], ans;
bool dp[10000003];

int main(){
    scanf("%d", &t);
    while(t--){
        scanf("%d %d", &a, &y);
        for(int i = 0; i < a; i++)
            scanf("%d", amp+i);
        if(y == 1){
            printf("1\n");
            continue;
        }
        fill_n(dp, y+1, 0);
        dp[1] = 1, ans = 1;
        for(int i = 0; i < a; i++){
            if(amp[i] > 1)
                for(int b = y / amp[i]; b > 0; b--)
                    if(dp[b]){
                        dp[b * amp[i]] = 1, ans = max(ans, b * amp[i]);
                        if(ans == y)
                            break;
                    }
			if(ans == y)
				break;
		}
        printf("%d\n", ans);
    }
}