// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;

const int maxN = 1e6+7;
long long arr[maxN];
long long arr2[maxN];

int main() {
int n;
cin >> n;
long long sum = 0;
cin >> sum;
arr[0] = sum;
arr2[0] = sum*sum;
for(int i = 1; i < n; ++i) {
    cin >> sum;
    arr[i] = sum + arr[i-1];
    arr2[i] = sum*sum + arr2[i-1];
    }
long long mx = 0;
for(int i = 0; i < n; ++i) {
    mx = max(mx, arr2[i] * ( arr[n-1] - arr[i] ));
    }
cout << mx;
return 0;
}

