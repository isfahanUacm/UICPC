#include <iostream>
#include <bits/stdc++.h>
using namespace std;
string a ,b;
int l ,r;
#define ALL(x) (x).begin(),x.end()
int main()
{
       while( cin>>a>>b){
       for(int i = 0 ;i<a.size();i++){
           if(a[i]!= b[i]){l = i; break;}
       }
       for(int i=a.size()-1;i>=0;i--){
           if(a[i]!= b[i]){r = i; break;}
       }

       string s1 = a.substr(l,r-l+1), s2 = b.substr(l,r-l+1);
       reverse(ALL(s1));
       if(s1!=s2){cout<<0<<endl,exit(0);}
       int ans = 1;
       l--;r++;
       while(l>=0&& r<a.size()&&a[l]==a[r]){
           l--;r++;
           ans++;
       }
       cout<<ans<<endl;
}
   return 0;
}
