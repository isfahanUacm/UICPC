#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    int ans=0;
    int t;
    cin>>t;
    string s[t];
    for(int i=0;i<t;i++){
        cin>>s[i];
    }
    for(int i=0;i<t;i++){
        bool win =1;
        for(int j=0;j<s[i].size()-1;j++){
            if(s[i][j]=='C'){
                if(s[i][j+1]=='D'){
                    win=0;
                    break;
                }
            }
        }
        if(win) ans++;
    }
    cout<<ans<<endl;
    return 0;
}