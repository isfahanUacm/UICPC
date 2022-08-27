#include <bits/stdc++.h>
#include <iostream>
#include <math.h>
using namespace std;
vector<pair<int, pair<float, float>>> l;
int main(){
    int n, x, y, z, v;
    cin>>n;
    for (int i = 0; i < n; i++){
        int f = 0;
        float m, x0;
        cin>>x>>y>>z>>v;
        if(abs(x-z)==0){
            f = 1;
            m = 0;
            x0 = x;
        }
        else{
            m = y-v / x-z;
            x0 = y - (m*x);
        }
        l.push_back({f, {m, x0}});
    }

    int q, a1,b1, a2,b2;
    cin>>q;
    int cnt = 0;
    while(q--){
        cin>>a1>>b1>>a2>>b2;
        cnt = 0;
        for (int i = 0; i < n; i++)
        {
            float m = l[i].second.first;
            float x0 = l[i].second.second;
            if(l[i].first){
                // cout<<i<<endl;
                if(((x0 - a1) * (x0 - a2)) < 0){
                    cnt++;
                }
            }
            else{
                float la1 = (m*a1)+x0;
                float la2 = (m*a2)+x0;
                // cout<<m<<" "<<x0<<endl;
                // cout<<la1<<" "<<la2<<endl;
                if((la1 > b1 && la2 < b2) || (la1<b1 && la2>b2)){
                    cnt++;
                }
            }
            
        }
        if(cnt%2==0) cout<<"same\n";
        else cout<<"different\n";
    }
    
    
}