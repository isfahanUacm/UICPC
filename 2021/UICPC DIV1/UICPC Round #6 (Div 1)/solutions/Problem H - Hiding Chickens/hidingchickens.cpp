#include <bits/stdc++.h>
using namespace std;

double dp[1<<20];
double arr[23][5];
int n;
double distance(double cx, double cy, double tx, double ty){
    return sqrt((cx-tx)*(cx-tx)+(cy-ty)*(cy-ty));
}

double cdp(int mask){
//    cout<<"dpmask"<<dp[mask]<<endl;
    if(dp[mask]!= -1)
        return dp[mask];
    for (int i = 0; i < n; ++i) {
        if(!((1<<i)&mask))
            continue;
        dp[mask] = min(dp[mask],dp[1<<i] + dp[1<<i] + cdp(mask&(~(1<<i))));
        for (int j = 0; j < n; ++j) {
            if(i==j)continue;
            if((1<<j)&mask){
                dp[mask] = min(((dp[mask]==-1)?1000000000:dp[mask]), dp[1<<i]+dp[1<<j]+distance(arr[i][0],arr[i][1], arr[j][0], arr[j][1])+cdp(mask&(~((1<<i) | (1<<j)))));
//                cout<<"inja"<<i<<" "<<j<<" "<<mask<<" "<<dp[mask]<<endl;
            }
        }
//        cout<<mask<<" "<<dp[mask]<<endl;
    }
    return dp[mask];
}

int main()
{
    double centerx, centery;
    cin>>centerx>>centery;
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>arr[i][0]>>arr[i][1];
    }
    for (int i = 0; i < (1<<20); ++i) {
        dp[i]= -1;
    }
    dp[0] = 0;
    for (int i = 0; i < n; ++i) {
        dp[1<<i] = distance(centerx, centery, arr[i][0], arr[i][1]);
    }
    for (int i = 0; i < n; ++i) {
        for (int j = i+1; j < n; ++j) {
            dp[(1<<i)|(1<<j)] = min(dp[1<<i],dp[1<<j])+distance(arr[i][0],arr[i][1], arr[j][0], arr[j][1]);
//            cout<<i<<" "<<j<<" "<<dp[(1<<i)|(1<<j)]<<endl;
        }
    }
//    cout<<(1<<n)-1<<endl;
    printf("%.6f\n", cdp((1<<n)-1));
    
    
    return 0;
}

