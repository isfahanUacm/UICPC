#include "bits/stdc++.h"

using namespace std;
int main() {
    int shorts, longs, comps , long_time;
    cin >>long_time >> comps >> shorts >> longs;
    int ans = 0;

    int longs_total = longs / comps;
    ans += longs_total * long_time;
    longs = longs % comps;

    if (longs != 0) {
        ans += long_time;
        int slots = (comps - longs) * long_time;
        shorts = shorts - slots;
    }

    if (shorts > 0) {
        int shorts_total = shorts / comps;
        ans += shorts_total;
        if (shorts % comps != 0){
            ans++;
        }
    }
    cout << ans;


    return 0;
}
