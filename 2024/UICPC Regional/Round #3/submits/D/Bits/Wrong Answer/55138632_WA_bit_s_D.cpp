#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const maxI = 1e5*2;


void solve(){
 vector<pair<int,int>> v;
 string s ; cin >> s;
 string t=s;
 sort(t.begin(),t.end());
 for(int i = 0 ;i<s.size()-1 ; i ++)
 {
     if(s==t)
         break;
     for(int j =s.size()-1 ; j >0;j--)
     {
         if(s==t)
             break;
         if(t[j]>t[j-1])
         {
             swap(t[j],t[j-1]);
             pair<int,int> p;p.first=j+1;p.second=j;
             v.push_back(p);
         }

     }


 }
 for(int i = 0 ; i<v.size() ; i++)
 {
     if(i<v.size()-1)
        cout<<v[i].first <<' '<< v[i].second<<'\n';
     else
         cout<<v[i].first <<' '<< v[i].second;
 }


 return;
}

int main()
{
    solve();
    return 0;
}
