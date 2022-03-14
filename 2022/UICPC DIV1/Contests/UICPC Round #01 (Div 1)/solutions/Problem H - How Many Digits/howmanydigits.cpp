#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<long double> v(1000001);
    v[1] = 0;
    for (int i = 2; i < 1000001; ++i) {
        v[i] = v[i-1] + log10(i);
    }
    int n;
    while(scanf("%d", &n) == 1){
        printf("%lld\n", n <= 1 ? 1ll : (long long int) ceil(v[n]));
    }
    return 0;
}
