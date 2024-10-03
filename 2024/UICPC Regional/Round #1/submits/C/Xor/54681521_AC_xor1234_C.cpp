#include <bits/stdc++.h>
using namespace std;
#define ll int64_t
#define per(i, a, b) for (ll i = a; i < b; i++)
#define rep(i, a, b) for (ll i = a; i >= b; i--)
#define outl(x) cout << x << endl;
#define outc(x) cout << x << " ";

int main(){
    int n;
    cin>>n;
    string str;
    cin>>str;
    int ch = 0;
    int result=0;
    per(i,0,n){
        if(str[i]=='1'){
            ch=2;
            result++;
        }
        else if (ch>0){
            result++ ;
            ch--;
        }
    }
    cout<<result;
    return 0;
}