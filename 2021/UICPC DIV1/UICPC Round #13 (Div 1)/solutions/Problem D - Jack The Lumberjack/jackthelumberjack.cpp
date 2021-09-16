#include <bits/stdc++.h>
using namespace std;

// Jack The Lumberjack

#define num long long int

int n;
num Y[1003], I[1003], S[1003], B[1003];

inline num f(num x){
    num ans = 0;
    for(int i = 0; i < n; i++){
        if(x < B[i])
            continue;
        else if(x <= B[i] + Y[i])
            ans += S[i] + (x - B[i]) * I[i];
        else
            ans += max(S[i] + Y[i] * I[i] - (x - B[i] - Y[i]) * I[i], 0ll);
    }
    return ans;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> Y[i] >> I[i] >> S[i] >> B[i];
    num ans = 0;
    for(int i = 0; i < n; i++)
        ans = max(ans, f(B[i] + Y[i]));
    cout << ans << endl;
}