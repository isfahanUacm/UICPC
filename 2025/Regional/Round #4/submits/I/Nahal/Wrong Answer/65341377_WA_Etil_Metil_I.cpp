#include <bits/stdc++.h>
#include <chrono>
using namespace std;


int main() {
    long int n;
    long  double arr[n];
    long  double temp[n];
    long double  result[n];
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> temp[i];
        result[i] = (arr[i] + temp[i]) /double(n);
    }
    sort(result, result + n);
    cout << fixed<<setprecision(6)<<result[n-1]<<endl;


    return 0;
}
