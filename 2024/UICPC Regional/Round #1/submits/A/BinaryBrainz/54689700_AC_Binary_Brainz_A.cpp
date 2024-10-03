#include <iostream>
using namespace std;
int main() {

    int n , a = 0 , b = 0;
    cin >> n;

    int sl , sr;
    char x;
    int ind = 0;

    for (int i = 0 ; i < n ; i++){
        cin >> sl;
        cin >> x;
        cin>> sr;

        int sum = sl + sr;
        int newa , newb;

        if ( (sum % 4 == 1) || (sum % 4 == 2) ){
            newb = sl;
            newa = sr;
        }
        else {
            newa = sl;
            newb = sr;
        }

        if ((newa < a) || (newb < b) || ((a >= 11) && (newb > b)) || ((b >= 11) && (newa > a)) || ((newa >=11) && (newb >= 11))  ){
            ind = i+1;
            break;
        }
        else {
            a = newa;
            b = newb;
        }
    }

    if (ind ){
        string tmp;

        for ( int i = ind ; i < n ;i++)
            cin >> tmp;
        cout << "error " << ind;
    }
    else {
        cout << "ok";
    }
    return 0;
}
