#include <bits/stdc++.h>

using namespace std;



void solve()
{
   string str;cin>>str;
   int k = 0 ;
   vector<string> vs;
   string tmp="";
   for(int i = 0 ;i < str.size();i++)
   {
       if(str[i]=='(')
       {
           k++;
           tmp.push_back(str[i]);
       }
       else {
           k--;
           tmp.push_back(str[i]);
       }
       if(k==0)
       {
           vs.push_back(tmp);
           tmp="";
       }
   }
   bool same=true;
   for(int i = 0 ;i < vs.size()-1 ; i++)
   {
       if(vs[i]!=vs[i+1])
       {
           same=false;
           break;
       }
   }
   if(!same)
   {
       cout<<vs[vs.size() -1];
       for(int i = 0 ; i < vs.size()-1;i++)
       {
           cout<<vs[i];
       }
       cout<<'\n';
   }else
       cout<<"no\n";
}


int main()
{
    solve();

    return 0;
}
