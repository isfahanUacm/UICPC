#include <bits/stdc++.h>
using namespace std;

// Alex and Barb

int k, m, n;

int main(){
    cin >> k >> m >> n;
    cout << ((k % (m + n) < m) ? "Barb" : "Alex") << endl;
}