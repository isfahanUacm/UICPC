#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
#include "set"
using namespace std;

vector <string> vec;
set <string> st;

int main()
{
    string s = "";
    string Ext ;
    getline( cin , s , '\n');
    int l = s.length() ;
    int j = 0 ;
    int answer = 0 ;
    for ( int i = 0 ; i < l  ; i ++)
    {
        if ( s[i] != ' ') Ext+= s[i];
        else
        {
            answer ++ ;
            st.insert(Ext) ;
            Ext = "" ;
            j = i;
        }
    }

    if ( !answer) cout << "yes" << endl;
    else
    {
       st.insert(s.substr(j+1 , s.size()));
        if ( st.size() == answer +1 ) cout << "yes\n" ;
        else
        {
            cout << "no\n" ;
        }
    }
return 0 ;
}























