#include <bits/stdc++.h>
using namespace std;

int dp[103][30003];
int item[103];
int order[1003];

int cdp(int i, int d){
    if(dp[i][d] != -3)
        return dp[i][d];
    int res = -1, tmp;
    for (int j = 0; j*item[i] <= d; ++j) {
//        cout<<i<<" "<<d<<" "<<j<<" "<<item[i]*j<<endl;
        tmp = ((i>0)?cdp(i-1, d-j*item[i]):((d-j*item[i] == 0)? j:-1));
        
        if(res == -1 && tmp > -1)
            res = j;
        else if((tmp == -2)||(res!=-1&&tmp>-1)){
            res = -2;
            break;
        }
    }
    dp[i][d] = res;
    return dp[i][d];
}

int main()
{
    for (int i = 0; i < 103; ++i) {
        for (int j = 0; j < 30003; ++j) {
            dp[i][j] = -3;
        }
    }
    vector<int> ans;
    int n, m, mi= INT_MAX;
    cin>>n;
    for (int i = 0; i < n; ++i)
        cin>>item[i],mi=min(mi, item[i]);
    cin>>m;
    for (int i = 0; i < m; ++i) {
        cin>>order[i];
        if(order[i]<mi){
            cout<<"Impossible"<<endl;
            continue;
        }
        int result = cdp(n-1,order[i]);
        if(result==-2)
            cout<<"Ambiguous"<<endl;
        else if(result==-1)
            cout<<"Impossible"<<endl;
        else{
            ans.clear();
            int it = n-1;
            int d = order[i];
            while(it != -1){
               ans.push_back(dp[it][d]);
               d -= dp[it][d]*item[it];
               it--;
            }
            reverse(ans.begin(), ans.end());
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < ans[j]; ++k) {
                    cout<<j+1<<" ";
                }
            }
            cout<<endl;
        }
    }
    return 0;
}

