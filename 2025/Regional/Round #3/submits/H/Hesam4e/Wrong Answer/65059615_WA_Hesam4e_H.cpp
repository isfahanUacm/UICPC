#include <iostream>

using namespace std;

int main() {
    string q , w , e ;
    cin >> q >> w >> e;
    if(q.size() != w.size() || q.size() != e.size() || w.size() != e.size()){
        if(q.size() > w.size() || q.size() > e.size()){
            cout << q ;
            return 0 ;
        }else if(w.size() > q.size() || w.size() > e.size()){
            cout << w ;
            return 0 ;
        }else if(e.size() > w.size() || e.size() > q.size()){
            cout << e ;
            return 0 ;
        }
    }
    string h = "";
    int a[3] ;
    a[0] = 0 ;
    a[1] = 0 ;
    a[2] = 0 ;
    for(int i = 0 ; i < q.size() ; i++){
        bool o = false;
        int j = q.size()-1-i;
        int p = -1 ;
        if(q[j] != w[j] && q[j] != e[j] && e[j] != w[j]){
            a[0]++;
            a[1]++;
            a[2]++;
        }else if(q[j] == w[j] && w[j] != e[j]){
            a[e[j]-'0'-1]++;
//            h += q[j];
            p = 1 ;
        }else if(q[j] == e[j] && w[j] != e[j]){
            a[w[j]-'0'-1]++;
//            h += q[j];
            p = 2 ;
        }else if(w[j] == e[j] && q[j] != e[j]){
            a[q[j]-'0'-1]++;
//            h += w[j];
            p = 3 ;
        }
//        cout << a[0] << "   "<< a[1] << "   " << a[2] << endl;
        while (a[0] >= 2 || a[1] >= 2 || a[2] >= 2){
            if(a[2] >= a[1] && a[2] >= a[0]){
                a[2] -= 2;
                h += '3';
            }else if(a[1] >= a[2] && a[1] >= a[0]){
                a[1] -= 2;
                h += '2';
            }else if(a[0] >= a[2] && a[0] >= a[1]){
                a[0] -= 2;
                h += '1';
            }
        }
        if(p != -1){
            if(p == 1 || p == 2){
                h += q[j];
            }else {
                h += w[j];
            }
        }

    }
    for(int k = h.size()-1 ; k >= 0 ; k--){
        cout << h[k];
    }
}