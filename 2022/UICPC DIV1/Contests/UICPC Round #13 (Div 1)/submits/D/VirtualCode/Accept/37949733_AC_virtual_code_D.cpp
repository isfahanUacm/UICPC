#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>
#include <string>
#include <map>
using namespace std;
const double D=60*M_PI/28;
int t;
string s;
map<char,int> mp;

void it(){
    int i = 0;
    while(i<26){
        mp[i+'A']=i;
        i++;
    }
    mp[' ']=26;
    mp['\'']=27;
}
void get1(){
    cin >> t;
}
void get2(){
    getline(cin,s);
}
void dis1(double ans){
    printf("%.10lf\n",ans);
}
int main()
{
    get1();
    cin.ignore();
    it();
    while(t--){
        get2();
        int p=mp[s[0]];
        double ans=0.0;
        int i = 1;
        while(i<s.size()){
            int res;
            if(p>mp[s[i]]) res=mp[s[i]]+28-p;
            else res=p+28-mp[s[i]];
            int tmp=abs(mp[s[i]]-p);
            if(tmp<res) ans+=(double)tmp;
            else ans+=(double)res;
            p=mp[s[i]];
            i++;
        }
        ans=ans*D/15;
        ans+=s.size();
        dis1(ans);
    }
    return 0;
}