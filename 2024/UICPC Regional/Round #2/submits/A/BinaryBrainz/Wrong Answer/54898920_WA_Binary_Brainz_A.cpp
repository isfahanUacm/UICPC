#include <bits/stdc++.h>
using namespace std;

int main() {
    long int t ;
    cin >> t;

    for (int i = 0 ; i < t ; i++){
       int n;
       cin >> n;

       int best = 1;

       for (int j = 0 ; j < n ;j++) {
           int tmp;
           cin >> tmp;

           if ( tmp >= n) {
               if (best == 1) {
                   best = tmp;
               }
               else {
                   if ((tmp < best))
                       best = tmp;
               }
           }
       }

       int turn = 1;

       while (best >= n){
           turn *= -1;

           if ( best <= n * (n-1)) {
                break;
           }
           else {
               best -= (n-1);
           }
       }

       if ( turn == -1)
           cout << "Alice";
       else cout << "Bob";

       if ( i != t-1)
           cout << endl;

       // alice = 1
       // bob = -1

    }



    return 0;
}
