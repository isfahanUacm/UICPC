#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

vector <string> vec;

int main()
{
    string s ;
    string Ext ;
    getline( cin , s , '\n');
    int l = s.length() ;
    for ( int i =0 ; i < l ; i++)
    {
        if ( s[i] != ' ') Ext += s[i] ;
        else
        {
            vec.push_back(Ext);
            Ext = "";
        }
    }
    vec.push_back(Ext);
    bool f = false ;
    string g ;
    int index= 0 ;
    for ( int i = 0  ;i < vec.size() ;  i ++)
    {
        index = s.find(vec[i]) ;
          g = s.substr(index + 1);
          if ( g.find(vec[i]) == 0)
          {
              cout << "no\n" ;
              f = true ;
              break;
          }
    }
    if ( f == false )
    {
        cout << "yes\n";
    }

}























