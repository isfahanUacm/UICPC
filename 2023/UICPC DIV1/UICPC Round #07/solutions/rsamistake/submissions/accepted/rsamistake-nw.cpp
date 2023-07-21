#include<bits/stdc++.h>
using namespace std;
int main() {
    uint64_t a,b,c,d;
    cin >> a >> b;
    c = a; d = b;
    if (a == b) {
        cout << "no credit" << endl;
        return 0;
    }
    unordered_set<uint64_t> diva, divb;
    for (uint64_t i = 2; i < sqrt(max(a,b))+2; i++) {
        if (i < a && c % i == 0) { diva.insert(i); c/=i; }
        if (i < b && d % i == 0) { divb.insert(i); d/=i; }
    }
    if (diva.size() == 0 && divb.size() == 0) {
        cout << "full credit" << endl;
        return 0;
    }
    if (c > 1) diva.insert(c);
    if (d > 1) divb.insert(d);
    for (uint64_t i = 2; i < 1100000; i++) {
        if (a % (i*i) == 0 || b % (i*i) == 0) {
            cout << "no credit" << endl;
            return 0;
        }
    }
    for (uint64_t da : diva) {
        if (divb.find(da) != divb.end()) {
            cout << "no credit" << endl;
            return 0;
        }
    }
    cout << "partial credit" << endl;
}
