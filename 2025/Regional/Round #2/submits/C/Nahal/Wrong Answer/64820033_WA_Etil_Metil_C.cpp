#include<iostream>
#include<cmath>
#include <sstream>
#include<string>

using namespace std;


int main() {

    unsigned  long long first, second;
    cin >> first >> second;

    int resultFirst, resultSecond, resultThird;
    if (first > pow(2, 31) - 1) {
        if (first > pow(2, 63) - 1) {
            resultFirst= 128;
        } else {
            resultFirst = 64;
        }
    } else {
        resultFirst = 32;
    }

    if (second > pow(2, 31) - 1) {
        if (second > pow(2, 63) - 1) {
            resultSecond = 128;
        } else {
            resultSecond = 64;
        }
    } else {
        resultSecond = 32;
    }

    unsigned  long long third = first * second;

    if (third > pow(2, 31) - 1) {
        if (third > pow(2, 63) - 1) {
            resultThird = 128;
        } else {
            resultThird = 64;
        }
    } else {
        resultThird = 32;
    }


    if ((resultFirst == resultSecond && resultFirst == resultThird && resultSecond == resultThird) ||
        (resultThird == resultFirst || resultThird == resultSecond)) {
        cout << resultFirst << endl;
        cout << resultSecond << endl;
        cout << resultThird << endl;
    }

    else{
        if(resultFirst>=resultSecond){
        resultFirst=resultThird;
        }
        else if(resultSecond>resultFirst){
            resultSecond=resultThird;
        }

        cout << resultFirst << endl;
        cout << resultSecond << endl;
        cout << resultThird << endl;
    }


    return 0;
}