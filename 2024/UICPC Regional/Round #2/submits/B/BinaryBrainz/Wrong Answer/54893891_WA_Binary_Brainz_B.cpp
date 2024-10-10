#include <bits/stdc++.h>
using namespace std;

struct qu{
    int a = 2;
    int b = 2;
    int c = 2;
    int d = 2;

    char answer(){
        if (this->a == 1)
            return 'A';
        else if (this->b == 1)
            return 'B';
        else if (this->c == 1)
            return 'C';
        else if (this->d == 1)
            return 'D';

        int sups = 0;
        char sup;

        if ( this->a == 2){
            sup = 'A';
            sups++;
        }
         if ( this->b == 2){
            sup = 'B';
            sups++;
        }
         if ( this->c == 2){
            sup = 'C';
            sups++;
        }
         if ( this->d == 2){
            sup = 'D';
            sups++;
        }

        if ( sups < 2)
            return sup;

        else return '?';

    }
};

int main() {
    long int t ;
    cin >> t;

    for (int i = 0 ; i < t ; i++){
       int q , m;
       cin >> q >> m;

       qu * arr = new qu[q];

       for (int k = 0 ; k < m ; k++){
           for (int j = 0 ; j < q;j++) {
               char gozine, state;

               cin >> gozine >> state;

               switch (gozine) {
                   case 'A':
                       if (state == 'T')
                           arr[j].a = 1;
                       else arr[j].a = 0;
                       break;
                   case 'B':
                       if (state == 'T')
                           arr[j].b = 1;
                       else arr[j].b = 0;
                       break;
                   case 'C':
                       if (state == 'T')
                           arr[j].c = 1;
                       else arr[j].c = 0;
                       break;
                   case 'D':
                       if (state == 'T')
                           arr[j].d = 1;
                       else arr[j].d = 0;
                       break;
               }
           }

       }

       for ( int j = 0 ; j < q; j++){
          cout << arr[j].answer() << ' ';
       }
       cout<<endl;



    }



    return 0;
}
