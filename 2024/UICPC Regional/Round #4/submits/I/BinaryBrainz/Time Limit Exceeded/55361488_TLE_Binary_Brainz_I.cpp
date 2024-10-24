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
    l.append(1000000,'0');
    for(int i = 0 ; i < n;i++){
        l[x[i]] = '1';
    }

    set<long int> emp;

    long int index =0;
    for(int i = x[index];i <= x[n-1]+1;i++){
        if(i==x[index]){
            index++;
            if(index > n)
                break;
        }
        else{
            emp.insert(i);
            i = x[index] - 1;
        }
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
        emp.insert(k);

        set<long int>::iterator del;
        for(set<long int>::iterator j = emp.begin();j!= emp.end();j++){
            if( k < *j){
                del = j;

                if(l[(*j)+1] =='0')
                    emp.insert((*j)+1);

                k= (*j);
                break;
            }
        }
        emp.erase(del);



        x[j[i]-1] = k;
        l[k] = '1';

        printf("%d",k);
        if(i != q-1)
            printf("\n");

        x[j[i]-1] = k;
    }

    return 0;
}
