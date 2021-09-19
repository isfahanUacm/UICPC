#include <bits/stdc++.h>
using namespace std;

#define ll long long int

ll dp[3003], num[3003], amount, n, psum[3003];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; ++i)
        cin >> amount, psum[i] = psum[i-1] + amount;
    for (int i = 1; i <= n; ++i)
        for (int pre = i-1; pre >= 0; --pre)
            if(psum[i] - psum[pre] >= dp[pre]){
                dp[i] = psum[i] - psum[pre];
                num[i] = num[pre] + 1;
                break;
            }
    cout << num[n] << endl;
    return 0;
}

