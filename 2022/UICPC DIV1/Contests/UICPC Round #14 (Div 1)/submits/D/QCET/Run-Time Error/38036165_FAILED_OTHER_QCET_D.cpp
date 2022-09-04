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
   
    for ( int i = 0  ;i < vec.size() ;  i ++)
    {
          size_t found = s.find(vec[i]);
          string k = s.substr(found+1) ;
         string h = ' '+vec[i] + ' ';
         char * a = new char (h.size()) ;
         for ( int i = 0 ; i < h.size() ; i ++)
         {
             a[i] = h[i];
         }
             found = k.find(a, found+1);
           if (found != string::npos)
           {
                 cout << "no\n";
                 f = true ;
                 break;
           }
    }
    if ( f == false )
    {
        cout << "yes\n";
    }

}























