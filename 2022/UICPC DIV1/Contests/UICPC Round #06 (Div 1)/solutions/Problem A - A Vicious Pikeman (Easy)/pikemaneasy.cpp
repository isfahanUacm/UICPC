#include <bits/stdc++.h>
using namespace std;

// A Vicious Pikeman (Easy)

#define num long long int
#define mod 1000000007

int n, ans;
num t, A, B, C, sum, psum;
num penalties[10003];

int main(){
    cin >> n >> t;
    cin >> A >> B >> C >> penalties[0];
    for(int i = 1; i < n; i++)
        penalties[i] = (A * penalties[i-1] + B) % C + 1;
    sort(penalties, penalties+n);
    ans = sum = psum = 0;
    for(int i = 0; i < n; i++){
        if(sum + penalties[i] > t)
            break;
        ans++;
        sum += penalties[i];
        psum = (psum + sum) % mod;
    }
    cout << ans << " " << psum << endl;
}