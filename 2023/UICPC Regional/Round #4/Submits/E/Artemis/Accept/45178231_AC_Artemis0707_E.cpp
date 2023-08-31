#include<bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n,b,h,w,p,a;
    cin>>n>>b>>h>>w;
    int min_cost = __INT_MAX__;
    for(int i=0;i<h;i++){
        cin>>p;
        for(int j=0;j<w;j++){
            cin>>a;
            if(a>=n){
                if(a*p <= b){
                    min_cost = min (min_cost, n*p);
                }
            }
        }
    }
    if(min_cost == __INT_MAX__) cout<<"stay home\n";
    else{
        cout<<min_cost<<endl;
    }
    return 0;
}