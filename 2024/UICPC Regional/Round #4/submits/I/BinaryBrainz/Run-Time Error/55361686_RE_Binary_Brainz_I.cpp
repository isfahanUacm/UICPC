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
    l.append(1000000+200,'0');
    for(int i = 0 ; i < n;i++){
        l[x[i]] = '1';
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
        k++;

        while(l[k] == '1') {
                k++;
        }

         l[k] = '1';
        
        printf("%d",k);
        if(i != q-1)
            printf("\n");

        x[j[i]-1] = k;
    }

    return 0;
}
