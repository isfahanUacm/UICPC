#include <bits/stdc++.h>
using namespace std;

// Wi-Fi

const int maxn = 1e5 + 3;

int n, k;
double house[maxn];

bool judge(double d){
    int need = 1;
    double wifi = house[0] + d;
    for(int i = 1; i < n; i++)
        if(fabs(house[i] - wifi) > d)
            need++, wifi = house[i] + d;
    return need <= k;
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> k >> n;
        for(int i = 0; i < n; i++)
            cin >> house[i];
        sort(house, house + n);
        double lo = 0, hi = 1e6;
        while(fabs(hi - lo) > 1e-6){
            double mid = (lo + hi) / 2;
            if(judge(mid))
                hi = mid;
            else lo = mid;
        }
        printf("%.1f\n", lo);
    }
}