#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin >> t;

    int heros[t], villain[t], max_h = 0, max_v = 0;
    for (int i = 0; i < t; i++) {
        cin >> heros[i];
        max_h = max(max_h, heros[i]);
    }
    for (int i = 0; i < t; i++) {
        cin >> villain[i];
        max_v = max(max_v, villain[i]);
    }
    int days=0,temp=0,dayOne=0;
    bool equal=true;
    for(int i=0;i<t;++i)
    {
        if(heros[i] + days > villain[i]) {
            break;
        }
        if (equal) {
            days = abs(villain[i] - heros[i]);
            equal = false;
        }
        if (heros[i] + days < villain[i]) {
            i = 0;
            days ++;
        }
    }
    cout<<days;
    return 0;
}