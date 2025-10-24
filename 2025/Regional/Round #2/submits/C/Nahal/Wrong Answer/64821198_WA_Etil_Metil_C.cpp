#include<iostream>
#include<cmath>
#include <sstream>
#include<string>

using namespace std;


int main() {

    unsigned  long long first, second;
    cin >> first >> second;

    int resultFirst, resultSecond, resultThird;
    if (first > 2147483647) {
        if (first > 9223372036854775807ULL) {
            resultFirst= 128;
        } else {
            resultFirst = 64;
        }
    } else {
        resultFirst = 32;
    }

    if (second > 2147483647) {
        if (second >9223372036854775807ULL) {
            resultSecond = 128;
        } else {
            resultSecond = 64;
        }
    } else {
        resultSecond = 32;
    }
    
    if(resultFirst==64 && resultSecond==64){
        cout<<128<<endl<< 64<<endl<<128<<endl;
        return 0;
    }
    unsigned  long long third = first * second;


    if (third > 2147483647) {
        if (third > 9223372036854775807ULL) {
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