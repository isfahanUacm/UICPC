//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;



int main(void){

    ll m , n ;
    ll t ;
    ll a , b ;
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
            a = 2 ;
            n/=2 ;
            ta++ ;
        }

        in = 3 ;

        while (n!=1 && m<=2) {
            if(n%in==0){
                m++ ;
                if(m==2){
                    b = in ;
                    tb++ ;
                    n/=in ;
                }
                else if(m==1){
                    a = in ;
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

        if(m>2)
            cout << "tie\n" ;
        else if(m==2){
            if(ta*tb==1){
                cout << str << '\n';
            }
            else if(abs(ta-tb)==1){
                if(str=="Alice")
                    cout << "Bob\n" ;
                else
                    cout << "Alice\n" ;
            }
            else if(ta==tb){
                cout << str << '\n' ;
            }
            else
                cout << "tie\n" ;

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
