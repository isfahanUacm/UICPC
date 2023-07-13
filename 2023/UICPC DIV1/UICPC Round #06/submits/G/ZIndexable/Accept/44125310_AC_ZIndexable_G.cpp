#include <iostream>
#include "bits/stdc++.h"

using namespace std;

int main() {
    long house;
    long n;
    cin >> house >> n;

    long last_num = 0;
    long not_safe  = 0;
    for (long i = 0; i < n; ++i) {
        long num;
        cin >> num;

        long red = num - last_num - 1;
        not_safe += (red * (red - 1)) / 2;
        last_num = num;
    }
    long last_n = house - last_num;
    not_safe += (last_n * (last_n - 1) /2);


    long total = house * (house -1) /2;
    total += house;
    not_safe += (house - n);
    cout << (total - not_safe);
    return 0;
}
