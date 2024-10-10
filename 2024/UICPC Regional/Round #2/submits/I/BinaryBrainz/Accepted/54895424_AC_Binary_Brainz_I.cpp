#include <bits/stdc++.h>
using namespace std;

string toBi(long int a){
    long int v = 1;
    int pow = 0;

    while (v < a){
        v *= 2;
        pow++;
    }

    string s = string();

    for (int i = pow; i >=0 ; i--){
        if (a >= v) {
            s += '1';
            a -= v;
        }
        else s+='0';

        v /= 2;
    }

    string tmp = string();

    int ind = 0;

    for (int j = s.length() - 1 ; j >= 0 ;j--){
        tmp += s[j];
        ind++;
    }

    return tmp;
}

int diff( string &a , string &b){
    int difference = 0;
    int maxlen = max(a.length(), b.length());
    int minlen = min (a.length(), b.length());

    char bigger;
    if (a.length() > b.length())
        bigger = 'a';
    else bigger = 'b';

    for (int i = 0 ; i <maxlen;i++ ){
        if ( i < minlen){
            if(a[i] != b[i])
                difference ++;
        }
        else if (bigger == 'a'){
            if (a[i] == '1' )
                difference++;
        }
        else if (bigger == 'b'){
            if (b[i] == '1' )
                difference++;
        }
    }

    return difference;
}

int main() {
    long int t ;
    cin >> t;

    for (int i = 0 ; i < t ; i++){
       int n;
       cin >> n;

       string * arr = new string[n];

       for (int j=0  ; j< n ; j++){
           long int a;
           cin >> a;
            arr[j] =  toBi(a);
       }

       set<int> diffs;

       for (int j = 0 ; j < n;j++){
           for (int k = j+1 ; k < n ;k++)
           diffs.insert(diff(arr[j],arr[k]));
       }
       cout << *diffs.rbegin();
       if( i != t -1)
           cout << endl;
    }



    return 0;
}
