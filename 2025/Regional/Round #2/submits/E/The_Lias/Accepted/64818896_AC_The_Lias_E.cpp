#include <bits/stdc++.h>

using namespace std;

int main() {
    long long int n, q, k;
    string l;
    cin >> n;
    cin >> q;
    cin >> k;
    cin >> l;
    long long int time, memory;
    time = (2*n*q) + (5*n*k);
    memory = n*k;
    if (l == "cpp") {
        if (time <= 500000000 && memory <= 20000000) {
            cout<< "OK";
        }
        else if (time <= 500000000) {
            cout << "ML";
        }
        else if (memory <= 20000000) {
            cout << "TL";
        }
        else {
            cout << "TL and ML";
        }
    }
    if (l == "java") {
        if (time <= 100000000 && memory <= 20000000) {
            cout<< "OK";
        }
        else if (time <= 100000000) {
            cout << "ML";
        }
        else if (memory <= 20000000) {
            cout << "TL";
        }
        else {
            cout << "TL and ML";
        }
    }
    if (l == "py") {
        if (time <= 20000000 && memory <= 20000000) {
            cout<< "OK";
        }
        else if (time <= 20000000) {
            cout << "ML";
        }
        else if (memory <= 20000000) {
            cout << "TL";
        }
        else {
            cout << "TL and ML";
        }
    }
    return 0;
}