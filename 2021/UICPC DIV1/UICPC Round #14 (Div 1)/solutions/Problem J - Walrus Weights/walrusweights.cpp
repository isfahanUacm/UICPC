#include <bits/stdc++.h>
using namespace std;
const int maxval = 2003;
int n, arr[1003];
bool dp[maxval];


int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> arr[i];
    dp[0] = true;
    for (int i = 0; i < n; ++i)
        for (int weight = maxval; weight >= 0; --weight)
            if(dp[weight])
                if(weight + arr[i] < maxval)
                    dp[weight + arr[i]] = true;
    for (int i = 0; i <= 1000; ++i) {
        if (dp[1000+i]) {
            cout << 1000 + i << endl;
            break;
        }
        else if (dp[1000-i]) {
            cout << 1000 - i << endl;
            break;
        }
    }
    return 0;
}

