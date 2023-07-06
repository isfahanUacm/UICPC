//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;


int main(void){
    ios_base::sync_with_stdio(false) ;
    ll m , n ;
    ll t ;
    ll ta = 0 , tb = 0 ;
    cin >> t ;
    string str ;
    ll in ;
    for(int i=0 ; i<t;  i++){
        m = 0 ;
        ta = 0 ;
        tb = 0 ;
        cin >> n >> str ;
        if(str=="Alice")
            str = "Bob" ;
        else
            str= "Alice" ;


        while(n%2==0){
            if(m==0)
                m++ ;
            n/=2 ;
            ta++ ;
        }

        in = 3 ;

        while (n!=1) {
            if(n%in==0){
                m++ ;
                if(m==2){
                    tb++ ;
                    n/=in ;
                }
                else if(m==1){
                    ta++ ;
                    n/=in ;
                }
                else
                    break;
                while (n%in==0) {
                    if(m==1)
                        ta++ ;
                    else
                        tb++ ;
                    n /= in ;
                }
            }
            else in+=2 ;
        }

        if(m>2){
            cout << "tie\n" ;
        }
        else if(m==2){
            if(abs(ta-tb)==1){
                if(str=="Alice")
                    cout << "Bob\n" ;
                else
                    cout << "Alice\n" ;
            }
            else if(ta==tb){
                cout << str << '\n' ;
            }
            else{
                cout << "tie\n" ;
            }

        }
        else{
           if(ta%2==0){
               cout << str << '\n' ;
           }
           else{
               if(str=="Alice")
                   cout << "Bob\n" ;
               else
                   cout << "Alice\n" ;
           }
        }
    }

}
