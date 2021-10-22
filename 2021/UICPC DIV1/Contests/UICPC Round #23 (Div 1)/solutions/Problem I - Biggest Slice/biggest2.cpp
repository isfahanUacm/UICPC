#include <bits/stdc++.h>
using namespace std;

// Biggest Slice

inline double deg_to_rad(double deg){
    return (deg * M_PI) / 180; 
}

const int mod = 360 * 60 * 60;

int m, n, a, t; 
double r;
set<int> angles;

int main(){
    cin >> m;
    cout << fixed << setprecision(6);
    while(m--){
        cin >> r >> n >> a;
        a *= 3600, cin >> t, a += 60 * t, cin >> t, a += t;
        angles.clear();
        int angle = 0;
        while(n--){
            angle = (angle + a) % mod;
            if(angles.find(angle) != angles.end())
                break;
            angles.insert(angle);
        }
        if(angles.size() == 1){
            cout << M_PI * r * r << endl;
            continue;
        }
        int diff = INT_MIN;
        for(auto it = angles.begin(); it != angles.end(); it++){
            int nex = (next(it) == angles.end()) ? *angles.begin() : *next(it);
            diff = max(diff, (nex - *it + mod) % mod);
        }
        double alpha = double(diff) / 3600;
        alpha = deg_to_rad(alpha);
        cout << r * r * alpha / 2 << endl;        
    }
}