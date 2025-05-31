#include <iostream>

using namespace std;

int main() {
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int naf , sol , min ;
        cin >> naf >> sol >> min ;
        int w[naf];
        int e[naf];
        for(int j = 0 ; j < naf ; j++){
            int a[sol];
            int sum = 0 ;
            int jar = 0 ;
            for(int k = 0 ; k < sol ; k++){
                cin >> a[k];
            }
            for(int t = 0 ; t < sol ; t++){
                for(int c = 0 ; c < sol-1-t ; c++){
                    if(a[c] > a[c+1]){
                        int o = a[c];
                        a[c] = a[c+1];
                        a[c+1] = o ;
                    }
                }
            }
            cout <<endl ;
            for(int y = 0 ; y < sol ; y++){
                int pp = 0 ;
                if(sum > min){
                    e[j]-=sum;
                    sum -= a[y];
                    w[j]--;
                    break;
                }
                sum += a[y];
                w[j] = y+1;
                for(int q = 0 ;q <= y ; q++){
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
//        for(int q = 0 ; q < naf ; q++){
//            cout << e[q] << endl ;
//        }
        int re = 1 ;
        for(int z = 1 ; z < naf ; z++){
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
