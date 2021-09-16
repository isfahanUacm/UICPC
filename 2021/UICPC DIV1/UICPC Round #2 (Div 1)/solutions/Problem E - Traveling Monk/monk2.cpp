#include <bits/stdc++.h>
using namespace std;

// Traveling Monk

int n, m;
double top = 0;
pair<double, double> ic[5003], dc[5003];

bool judge(double t){
    double h1 = 0, t1 = 0;
    int i = 0;
    while(i < n && t1 + ic[i].second <= t)
        h1 += ic[i].first, t1 += ic[i].second, i++;
    if(i < n)
        h1 += ic[i].first * ((t - t1) / ic[i].second);
    double h2 = 0, t2 = 0;
    int j = 0;
    while(j < m && t2 + dc[j].second <= t)
        h2 += dc[j].first, t2 += dc[j].second, j++;
    if(j < m)
        h2 += dc[j].first * ((t - t2) / dc[j].second);
    return h1 >= top - h2;
}

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> ic[i].first >> ic[i].second, top += ic[i].first;
    for(int i = 0; i < m; i++)
        cin >> dc[i].first >> dc[i].second;
    double lo = 0, hi = 5e6;
    while(hi - lo > 1e-7){
        double mid = (lo + hi) / 2;
        if(judge(mid))
            hi = mid;
        else lo = mid;
    }
    cout << fixed << setprecision(7) << lo << endl;
}