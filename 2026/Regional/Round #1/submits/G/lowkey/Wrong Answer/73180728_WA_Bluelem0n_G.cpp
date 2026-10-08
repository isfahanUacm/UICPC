#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    long long n, q, k;
    string s;
    cin >> n >> q >> k >> s;
    long long time= 2* q * n;
    long long memory = k * n;
    bool memoryCheck = memory <= 2 * pow(10, 7);

    if (s == "java") {
        if (time > pow(10,8) && memoryCheck) {
            cout << "TL";
        }else if (time <= pow(10, 8) && memoryCheck) {
            cout << "OK";
        }else if (time <= pow(10, 8) && !memoryCheck) {
            cout << "ML";
        }
        else if (time > pow(10, 8) && !memoryCheck) {
            cout << "TL and ML";
        }
    }
    else if(s=="cpp")
    {
        if (time > 5* pow(10, 8) && memoryCheck) {
            cout << "TL";
        }
        else if (time <= 5*pow(10, 8) && memoryCheck) {
            cout << "OK";
        }
        else if (time <=5*pow(10, 8) && !memoryCheck) {
            cout << "ML";
        }
        else if (time > 5*pow(10, 8) && !memoryCheck) {
            cout << "TL and ML";
        }
    }
    else if (s == "py") {
        if (time > 2*pow(10, 7) && memoryCheck) {
            cout << "TL";
        }
        else if (time <= 2*pow(10, 7) && memoryCheck) {
            cout << "OK";
        }
        else if (time <=2* pow(10, 7) && !memoryCheck) {
            cout << "ML";
        }
        else if (time > 2*pow(10, 7) && !memoryCheck) {
            cout << "TL and ML";
        }
    }
}

