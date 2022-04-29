#include <bits/stdc++.h>
using namespace std;

int x[103];
int K, T, P, Q;
double w[103][5];
double dp[103][103];
double prob[103];

double cdp(int t, int k){
//    cerr << t << " " << k << endl;
    if(dp[t][k] != -1){
        return dp[t][k];
    }
    if(t == T){
        return 1;
    }
    if(T-t == K-k){
        return dp[t][k] = prob[t] * cdp(t+1, k+1);
    }
//    cerr << t << " " << k << " " << prob[t] << endl;
    return dp[t][k] = prob[t] * cdp(t+1, k+1) + (1-prob[t]) * cdp(t+1, k);
}

int main()
{
    cin >> K >> T >> P >> Q >> x[0];
    for (int i = 0; i < T; ++i) {
        for (int j = 0; j < 4; ++j) {
            cin >> w[i][j];
        }
    }
    for (int i = 1; i < T; ++i) {
        x[i] = (x[i-1] * P) % Q;
    }
    for (int i = 0; i < T; ++i) {
        x[i] %= 4;
    }
    for (int i = 0; i <= T; ++i) {
        for (int j = 0; j <= T; ++j) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < T; ++i) {
        if(x[i] == 0){
            prob[i] = (w[i][0]/(w[i][1] + w[i][0])) * ((w[i][2]/(w[i][2] + w[i][3])) * (w[i][0]/(w[i][0]+w[i][2])) + (w[i][3]/(w[i][2] + w[i][3])) * (w[i][0]/(w[i][0]+w[i][3])));
        }
        else if(x[i] == 1){
            prob[i] = (w[i][1]/(w[i][1] + w[i][0])) * ((w[i][2]/(w[i][2] + w[i][3])) * (w[i][1]/(w[i][1]+w[i][2])) + (w[i][3]/(w[i][2] + w[i][3])) * (w[i][1]/(w[i][1]+w[i][3])));
        }
        else if(x[i] == 2){
            prob[i] = (w[i][2]/(w[i][2] + w[i][3])) * ((w[i][0]/(w[i][0] + w[i][1])) * (w[i][2]/(w[i][0]+w[i][2])) + (w[i][1]/(w[i][0] + w[i][1])) * (w[i][2]/(w[i][1]+w[i][2])));
        }
        else{
            prob[i] = (w[i][3]/(w[i][2] + w[i][3])) * ((w[i][0]/(w[i][0] + w[i][1])) * (w[i][3]/(w[i][0]+w[i][3])) + (w[i][1]/(w[i][0] + w[i][1])) * (w[i][3]/(w[i][1]+w[i][3])));
        }
    }
    cout << fixed << setprecision(7) << cdp(0, 0) << endl;
    return 0;
}

