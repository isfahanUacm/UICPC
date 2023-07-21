#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>
#include <numeric>
#include <bits/stdc++.h>

using namespace std;


int main() {
    long total;
    cin >> total;
    long a;
    cin >>a;
    long last_oc;
    cin >> last_oc;
    long first_oc = last_oc;
    long ans=0;
    for (int i = 0; i <a-1; ++i) {
        long cur_oc;
        cin >> cur_oc;

        long dis = abs(cur_oc - last_oc) - 1;
        if (dis % 2 == 0)
            ans += ((dis - 2) /2);
        else
            ans += ((dis - 1) /2);

        last_oc = cur_oc;
    }

    long disl = abs((total + first_oc) - last_oc) - 1;
    if (disl % 2 == 0)
        ans += ((disl - 2) /2);
    else
        ans += ((disl - 1) /2);

    cout << ans;
    return 0;
}