#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
struct user
{
    ll r;
    ll cw;
    ll s;
    
};
int main(){
    ll ranks[26]={-1,5,5,5,5,5,5,5,5,5,5,4,4,4,4,4,3,3,3,3,3,2,2,2,2,2};
    string g;
    user u;
    cin >> g;
    ll gl = g.length();
    u.r=25;
    u.cw=0;
    u.s=0;
    for(ll k=0;k<gl;k++){
        if(g[k]=='W'){
            u.cw++;
            u.s++;
            if(u.cw>=3&&u.r>=6)u.s++;
            if(u.s>ranks[u.r]){
                u.s=u.s-ranks[u.r];
                u.r--;
                if(u.r<1){
                    cout<<"Legend"<<endl;
                    return 0;
                }
            }
        }
        else if(g[k]=='L'){
            u.cw=0;
            if(u.r>20||(u.r==20&&u.s==0)){
                continue;
            }
            u.s--;
            if(u.s<0){
                u.r++;
                u.s=ranks[u.r]-1;
            }
        }
    }
    cout<<u.r<<endl;
    return 0;

}