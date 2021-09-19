#include <bits/stdc++.h>
using namespace std;

// Association for the Country of Mububa

struct interval{
    int st, en;
    long long int su;
};

bool cmp(const interval& i1, const interval& i2){
    if(i1.en == i2.en)
        return i1.su < i2.su;
    return i1.en < i2.en;
}

int n;
long long int a[3003], psum[3003];
int m = 0;
interval intervals[9000003];
int st[9000003], en[9000003];
long long int su[9000003];
int lower[3003], upper[3003];
int dp[9000003];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    partial_sum(a, a+n, psum);
    for(int i = 0; i < n; i++)
        for(int j = i; j < n; j++)
            intervals[m].st = i, intervals[m].en = j, intervals[m++].su = psum[j] - (i ? psum[i-1] : 0);
    sort(intervals, intervals+m, cmp);
    for(int i = 0; i < m; i++)
        st[i] = intervals[i].st, en[i] = intervals[i].en, su[i] = intervals[i].su;
    for(int i = 0; i < n; i++)
        lower[i] = lower_bound(en, en+m, i) - en, upper[i] = upper_bound(en, en+m, i) - en;
    for(int i = 0; i < m; i++){
        dp[i] = 0;
        if(i > 0 && en[i-1] == en[i])
            dp[i] = max(dp[i], dp[i-1]);
        if(st[i]){
            int pr = upper_bound(su + lower[st[i]-1], su + upper[st[i]-1], su[i]) - su - 1;
            if(pr >= 0 && en[pr] == st[i]-1 && su[pr] <= su[i] && dp[pr])
                dp[i] = max(dp[i], 1 + dp[pr]);
        }
        else dp[i] = max(dp[i], 1);
    }
    cout << dp[m-1] << endl;
}