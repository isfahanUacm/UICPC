#include <iostream>

using namespace std;

int main() {
    long long int  n ;
    cin >> n ;
    for(long long int  i = 0 ; i < n ; i++){
        long long int  naf , sol , min ;
        cin >> naf >> sol >> min ;
        long long int  w[naf];
        long long int  e[naf];
        for(long long int  j = 0 ; j < naf ; j++){
            long long int  a[sol];
            long long int  sum = 0 ;
            long long int  jar = 0 ;
            for(long long int  k = 0 ; k < sol ; k++){
                cin >> a[k];
            }
            for(long long int  t = 0 ; t < sol ; t++){
                for(long long int  c = 0 ; c < sol-1-t ; c++){
                    if(a[c] > a[c+1]){
                        long long int  o = a[c];
                        a[c] = a[c+1];
                        a[c+1] = o ;
                    }
                }
            }
            cout <<endl ;
            for(long long int  y = 0 ; y < sol ; y++){
                long long int  pp = 0 ;
                if(sum > min){
                    e[j]-=sum;
                    sum -= a[y];
                    w[j]--;
                    break;
                }
                sum += a[y];
                w[j] = y+1;
                for(long long int  q = 0 ;q <= y ; q++){
                    jar += a[q];
                    e[j]=jar;
                }
                if(sum > min){
                    e[j]-=sum;
                    sum -= a[y];
                    w[j]--;
                    break;
                }
            }
        }
//        for(long long int  q = 0 ; q < naf ; q++){
//            cout << e[q] << endl ;
//        }
        long long int  re = 1 ;
        for(long long int  z = 1 ; z < naf ; z++){
            if(w[0] < w[z]){
//                cout << w[0] << "//"<< endl << w[z] <<"//"<< z <<  endl ;
                re++;
            }
            if(w[0] == w[z]){
                if(e[0] > e[z]){
                    re++;
                }
            }
        }
        cout << re << endl;
    }
}
