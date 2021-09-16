/**
https://open.kattis.com/problems/wifi
Author: https://github.com/smh997/
**/
#include <bits/stdc++.h>
using namespace std;

int n, m;
double homes[100003];

bool verify(double distance){
    double access_point_place = homes[0] + distance;
    int required_access_point = 1;
    for (int i = 1; i < m; ++i)
        if(fabs(homes[i]-access_point_place) > distance){
            required_access_point++;
            access_point_place = homes[i] + distance;
        }
    return required_access_point <= n;
}

int main()
{
    int t;
    cin >> t;
    while(t--){
        cin >> n >> m;
        for (int i = 0; i < m; ++i)
            cin >> homes[i];
        sort(homes, homes+m);
        double lo = 0, hi = 1e6+3, mid;
        while(fabs(hi-lo) > 1e-9){
            mid = lo + (hi - lo)/2;
            if(verify(mid)){
                hi = mid;
            }
            else{
                lo = mid;
            }
        }
        cout << fixed << setprecision(1) << lo << endl;
    }
    return 0;
}

