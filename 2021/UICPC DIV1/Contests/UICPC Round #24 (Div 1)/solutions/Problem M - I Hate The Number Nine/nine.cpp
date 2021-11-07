#include <bits/stdc++.h>
using namespace std;

#define mod 1000000007

long long int d, res;

long long int fast_power(long long int a, long long int b){
    if(b == 0)
        return 1;
    if(b % 2 == 1)
        return (a * fast_power(a, b-1)) % mod;
    long long int half = fast_power(a, b / 2);
    return (half * half) % mod;
}


int main(void){
    int N;
    cin >> N;
    for (int i = 0; i < N; i++){
        cin >> d;
        res = (8 * fast_power(9, d-1)) % mod;
        cout << res << endl;
    }
	return 0;
}
