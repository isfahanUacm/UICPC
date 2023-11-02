#include<bits/stdc++.h>
using namespace std;
using ll = long long;

bool check_type( string s ) {
   for( int i = 0; i < s.length(); i++ ) {
      if( !isdigit( s[i] )) {
         return 0;
      }
   }
   return 1;
}
bool cmp(pair<int, string>& a, 
        pair<int, string>& b) 
{ 
    return a.first < b.first; 
} 

int main(){
    int n;
    cin>>n;
    string a,b;
    vector<pair<int, string>> v;
    while (n--)
    {
       cin>>a>>b;
       if(check_type(a)){
        v.push_back({stoi(a)/2, b});
       }
       else {
        v.push_back({stoi(b), a});
       }
    }
    sort(v.begin(), v.end(), cmp);
    
    for(auto x:v){
        cout<<x.second<<endl;
    }
    return 0;
}