#include <bits/stdc++.h>
using namespace std;

#define ll long long

int const maxI = 1e5*2;


void solve(){
 vector<pair<int,int>> v;
 string s ; cin >> s;
 for(int i = 1 ;i < s.size() ; i ++)
 {
     for(int j =0 ; j < s.size()-i ; j ++)
     {
         if(s[j]>s[j+1])
         {
             pair<int,int> p;
             p.first = j+2;p.second=j+1;
             v.push_back(p);
             swap(s[j],s[j+1]);
         }

     }

 }
 for(int i = v.size()-1 ; i>=0 ; i--)
 {
     cout<<v[i].first << " "  << v[i].second<<'\n';
 }
 return;
}

int main()
{
    solve();
    return 0;
}
