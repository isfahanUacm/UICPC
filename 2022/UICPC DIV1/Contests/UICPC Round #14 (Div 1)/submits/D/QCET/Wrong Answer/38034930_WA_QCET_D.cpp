#include "iostream"
#include "string.h"
#include "map"
#include "vector"
#include "tuple"
using namespace std ;


map <int64_t , int64_t > Map ;
map < int64_t , int64_t > Map_Answer ;
vector <string> Vec ;

int main ()
{
    string Se , check;
    getline(cin , Se) ;
    int L = Se.length() ;
    char ch[10] ;
    int index = 0 ;
    int i = 0 ;
     bool F = false ;
    while ( L > 0 )
    {
        if ( Se[index] != ' ')
        {
            ch[i]= Se[index]  ;

        i++;
        }
        else
        {
             F = Se.find(ch) ;
             if (F)
             {
                 cout << "no\n" ;
                 break;
             }
             check = "" ;
             i = 0 ;
        }

   L -- ;
   index ++ ;
    }
    if ( F == false) cout << "yes\n";


    return  0  ;
}
