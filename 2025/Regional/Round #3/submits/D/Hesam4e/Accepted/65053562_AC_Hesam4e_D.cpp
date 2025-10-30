#include <iostream>
#include <iomanip>
#include <math.h>

using namespace std;

int main() {
    string s ;
    cin >> s ;
    int arr[26];
    for(int i = 0 ; i < 26 ; i++){
        arr[i] = 0 ;
    }
    for(int i = 0 ; i < s.size() ; i++){
        int y = (int)s[i] - 'a' ;
        arr[y]++;
    }
    int o = 0 ;
    for(int i = 0 ; i < 26 ; i++){
        if(arr[i] % 2 == 1)o++;
    }
    if(o > 1)cout << "no";
    else cout << "yes" ;
    return 0;
}