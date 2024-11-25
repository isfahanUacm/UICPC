#include <iostream>
#include <math.h>

using namespace  std;

int main() {

    int n;
    cin >> n;
    int temp = 25;
    int out = 0;
    int n25 = n - 1, n21 = n , n18 = n;
    while(n25 != 0 || n21!= 0 || n18 != 0) {
        if(60 - temp >= 25 && n25 > 0)
        {
            temp += 25;
            n25 -= 1;
        }
        else if(60 - temp >= 21 && n21 > 0){
            temp += 21;
            n21 -= 1;
        }
        else if(60 - temp >= 18 && n18 > 0){
            temp += 18;
            n18 -= 1;
        }
        else{
            out += 1;
            temp = 0;
        }
    } out += 1;
    cout << out<< endl;

    return 0;
}