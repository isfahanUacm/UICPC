#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    string a,b;
    cin >> a>> b;

    

    int n = a.length();
    int m = b.length();

    int dp[n+1][m+1];

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0){
                dp[i][j] = 0;
            }
            else if(a[i-1]==b[j-1]){
                dp[i][j] = 1+dp[i-1][j-1];
            }
            else{
                dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
            }
        }
    }

    int i=n,j=m;
    string ans = "";
    while(i>0 && j>0){
        if(a[i-1]==b[j-1]){
            ans = a[i-1]+ans;
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j]){
                j--;
            }
            else{
                i--;
            }
        }
    }

    cout << ans << endl;




}