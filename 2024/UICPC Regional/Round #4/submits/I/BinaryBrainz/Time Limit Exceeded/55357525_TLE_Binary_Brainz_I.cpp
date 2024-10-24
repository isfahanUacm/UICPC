#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;
int main() {

    long int n;
    cin >> n;

    long int * x = new long int [n];

    for(int i = 0 ; i< n ;i++){
        cin >> x[i];
    }

    string l = string();

    l.append(x[n-1]+n+1,'0');

    for(int i = 0 ; i < n;i++){
        l[x[i]] = '1';
    }

    set<long int> emptys;

    for(int i = x[0] ; i< x [n-1]+2 ;i++){
        if(l[i] == '1')
            continue;

        if(l[i-1] == '1')
            emptys.insert(i);

    }

    long int q;
    cin >> q;
    long int * j = new long int[q];

    for(int i =0 ; i<q ;i++){
        cin >> j[i];
    }


    for(int i =0 ; i < q;i++){

        int k = x[j[i]-1];
        l[k] = '0';

        for(auto &m: emptys){
            if(m > k){
                l[m] = '1';

                long int tmp = m;
                emptys.erase(m);

                if((tmp + 1) < l.length()) {
                    if (l[tmp + 1] != '1')
                        emptys.insert(tmp + 1);
                }
                else {
                    l+='0';
                    emptys.insert(tmp + 1);
                }
                if(l[k-1] == '1')
                    emptys.insert(k);

                k = tmp;
                break;
            }
        }


        cout << k ;
        if(i != q-1)
            cout << endl;

        x[j[i]-1] = k;
    }

    return 0;
}
