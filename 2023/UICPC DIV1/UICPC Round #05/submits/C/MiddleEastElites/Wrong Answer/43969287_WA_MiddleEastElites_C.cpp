//In the name of Allah
#include<bits/stdc++.h>

using namespace std ;

typedef long long int ll ;

int u[2>>31] ;

int main(void){
    ios_base::sync_with_stdio(false) ;
    ll m , n ;
    ll t ;
    ll tn ;
    ll ta = 0 , tb = 0 ;
    cin >> t ;
    string str ;
    ll in ;
    for(int i=0 ; i<t;  i++){
        m = 0 ;
        ta = 0 ;
        tb = 0 ;
        cin >> n >> str ;
        tn = n ;
        if(str=="Alice")
            str = "Bob" ;
        else
            str= "Alice" ;
        if(u[n]>0){
            if(u[n]==1)
                cout << str ;
            else if(u[n]==2){
                if(str=="Bob")
                    cout << "Alice\n" ;
                else
                    cout << "Bob\n" ;
            }
            else
                cout << "tie\n"  ;
            continue;
        }

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
            u[tn] = 3 ;
        }
        else if(m==2){
            if(abs(ta-tb)==1){
                if(str=="Alice")
                    cout << "Bob\n" ;
                else
                    cout << "Alice\n" ;
                u[tn] = 2 ;
            }
            else if(ta==tb){
                cout << str << '\n' ;
                u[tn] = 1 ;
            }
            else{
                cout << "tie\n" ;
                u[tn] = 3 ;
            }

        }
        else{
           if(ta%2==0){
               cout << str << '\n' ;
               u[tn] = 1 ;
           }
           else{
               if(str=="Alice")
                   cout << "Bob\n" ;
               else
                   cout << "Alice\n" ;
               u[tn] = 2 ;
           }
        }
    }

}
