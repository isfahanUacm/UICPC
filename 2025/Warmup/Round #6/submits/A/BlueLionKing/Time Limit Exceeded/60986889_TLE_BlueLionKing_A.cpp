#include <iostream>
using namespace std;

int main() {
    long long int n ;
    cin >> n ;
    for(long long int i = 0 ; i < n ; i++){
        long long int q , w ,e ;
        cin >> q >> w >> e ;
        long long int qqq[q];
        long long int www[q];
        for(long long int j = 0 ; j < q ; j++){
            long long int tt[w];
            for(long long int k = 0 ; k < w ; k++){
                cin >> tt[k];
            }
            for(long long int pp = 0 ; pp < w - 1 ; pp++) {
                for(long long int oo = 0; oo < w - pp - 1; oo++) {
                    if(tt[oo] > tt[oo + 1]) {
                        long long int temp = tt[oo];
                        tt[oo] = tt[oo + 1];
                        tt[oo + 1] = temp;
                    }
                }
            }
            long long int sumt = 0 ;
            long long int ww = 0 ;
            for(long long int q1 = 0 ; q1 < w ; q1++){
                sumt += tt[q1];
                ww = q1;
                if(sumt > e){
                    sumt -= tt[q1];
                    ww--;
                    break;
                }
            }
            qqq[j]=ww;
            long long int sumt2 = 0 ;
            for(long long int q2 = 0 ; q2 <= ww ; q2++){
                for(long long int q3 = 0 ; q3 <= q2 ; q3++){
                    sumt2 += tt[q3];
                }
            }
            www[j]=sumt2;
        }

        long long int bb = 1 ;
        for(long long int lk = 1 ; lk < q ; lk++){
            if(qqq[lk] > qqq[0])bb++;
            else if(qqq[lk] == qqq[0]){
                if(www[lk] < www[0])bb++;
            }
        }
        cout << bb <<endl;

    }
}
