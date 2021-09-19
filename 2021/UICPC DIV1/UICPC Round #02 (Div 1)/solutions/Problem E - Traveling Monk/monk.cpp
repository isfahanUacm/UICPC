#include <bits/stdc++.h>
using namespace std;
#define prec 1e-7
int a, d, h, t;
vector<pair<int, int>> asc, dsc;
int mx=0;
double ha(double t){
    int it=0, hh=0;
    while(it!=a && t>asc[it].second){
        hh += asc[it].first;
        t -= asc[it].second;
        it++;
    }
    if(it==a)
        return hh;
    return hh+asc[it].first*t/asc[it].second;
}
double hd(double t){
    int it=0, hh=mx;
    while(it!=d && t>dsc[it].second){
        hh -= dsc[it].first;
        t -= dsc[it].second;
        it++;
    }
    if(it==d)
        return 0;
    return hh-dsc[it].first*t/dsc[it].second;        
}

int main()
{
    cin>>a>>d;
    int maxta=0, maxtd=0;
    for (int i = 1; i <= a; ++i) {
        cin>>h>>t;
        asc.push_back({h, t});
        maxta+=t;
        mx+=h;
    }
    for (int i = 1; i <= d; ++i) {
        cin>>h>>t;
        dsc.push_back({h, t});
        maxtd+=t;
    }
    double lo = 0, hi = max(maxta, maxtd), mid, hh;
    while(hi-lo>prec){
        mid = (hi+lo)/2;
        hh = ha(mid) - hd(mid);
        if(hh>=0){
            hi = mid;
        }
        else{
            lo = mid;
        }
    }
    cout<<fixed<<setprecision(6)<<lo<<endl;
    return 0;
}
