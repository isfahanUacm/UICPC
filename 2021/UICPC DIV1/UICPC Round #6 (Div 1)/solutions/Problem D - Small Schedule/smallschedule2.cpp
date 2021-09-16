#include <bits/stdc++.h>
using namespace std;

// Small Schedule

#define num long long int

inline num ce(num a, num b){
    return a / b + (a % b != 0);
}

int main(){
    num Q, M, S, L;
    cin >> Q >> M >> S >> L;
    cout << ce(L, M) * Q + ce(max(0ll, S - (L % M ? M - L % M : 0) * Q), M) << endl;
}