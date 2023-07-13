#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "bits/stdc++.h"

using namespace std;

int main() {
    int house;
    int n;
    cin >> house >> n;

    int last_num = 0;
    int not_safe  = 0;
    for (int i = 0; i < n; ++i) {
        int num;
        cin >> num;

        int red = num - last_num - 1;
        not_safe += (red * (red - 1)) / 2;
        last_num = num;
    }
    int last_n = house - last_num;
    not_safe += (last_n * (last_n - 1) /2);


    int total = house * (house -1) /2;
    total += house;
    not_safe += (house - n);
    cout << (total - not_safe);
    return 0;
}
