#include <iostream>
using namespace std;

int main() {
    int n ;
    cin >> n ;
    for(int i = 0 ; i < n ; i++){
        int q , w ,e ;
        cin >> q >> w >> e ;
        int qqq[q];
        int www[q];
        for(int j = 0 ; j < q ; j++){
            int tt[w];
            for(int k = 0 ; k < w ; k++){
                cin >> tt[k];
            }
            for(int pp = 0 ; pp < w - 1 ; pp++) {
                for(int oo = 0; oo < w - pp - 1; oo++) {
                    if(tt[oo] > tt[oo + 1]) {
                        int temp = tt[oo];
                        tt[oo] = tt[oo + 1];
                        tt[oo + 1] = temp;
                    }
                }
            }
            int sumt = 0 ;
            int ww = 0 ;
            for(int q1 = 0 ; q1 < w ; q1++){
                sumt += tt[q1];
                ww = q1;
                if(sumt > e){
                    sumt -= tt[q1];
                    ww--;
                    break;
                }
            }
            qqq[j]=ww;
            int sumt2 = 0 ;
            for(int q2 = 0 ; q2 <= ww ; q2++){
                for(int q3 = 0 ; q3 <= q2 ; q3++){
                    sumt2 += tt[q3];
                }
            }
            www[j]=sumt2;
        }

        int bb = 1 ;
        for(int lk = 1 ; lk < q ; lk++){
            if(qqq[lk] > qqq[0])bb++;
            else if(qqq[lk] == qqq[0]){
                if(www[lk] < www[0])bb++;
            }
        }
        cout << bb <<endl;

    }
}
