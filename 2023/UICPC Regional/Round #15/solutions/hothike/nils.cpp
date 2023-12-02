#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> T(n);
    for(int c1 = 0; c1 < n; c1++){
        cin >> T[c1];
    }
    int maxt = 100;
    int d = 0;
    for(int c1 = 0; c1 < n-2; c1++){
        if(max(T[c1],T[c1+2]) < maxt){
            maxt = max(T[c1], T[c1+2]);
            d = c1;
        }
    }
    cout << d+1 << " " << maxt << "\n";
    return 0;
}
