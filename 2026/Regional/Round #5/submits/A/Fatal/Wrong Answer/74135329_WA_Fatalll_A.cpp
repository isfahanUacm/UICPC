#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main(){
    double b, h, l;
    cin >> b >> h >> l;
    double answer = 3*sqrt(3)*pow(l,2)/(2*b*h);
    cout << setprecision(10) <<answer;
}