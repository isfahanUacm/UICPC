#include <iostream>
using  namespace std;

int main() {
    long int n, count =0;
    int x = 0;
    string s;

    cin >>n >> s;

    for (int i = 0 ; i <  s.length() ; i++){
        if (s[i] == '1'){
            x = 2;
            count++;
        }
        else {
            if (x){
                count++;
                x--;
            }
        }
    }

    cout << count;

    return 0;
}
