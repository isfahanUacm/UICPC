#include <bits/stdc++.h>
using namespace std;
#define num long long int

// Game of Gnomes

int main(){
    num n, m, k;
    cin >> n >> m >> k;
    num ans = LLONG_MIN;
    for(num g = n / k; g >= 0; g--){
        num rem = n - g * k;
        num l, cl, u, cu;
        if(rem % m){
            l = rem / m, cl = m - rem % m;
            u = l + 1, cu = rem % m;
        }
        else{
            l = 0, cl = 0;
            u = rem / m, cu = m;
        }
        if(u >= k)
            break;
        ans = max(ans, l * ((cl * (cl+1))/2 + cl*(cu+g)) +
                       u * ((cu * (cu+1)/2) + cu*g) +
                       k * ((g*(g+1))/2));
    }
    cout << ans << endl;
}