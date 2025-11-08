#include <iostream>
#include "algorithm"

using namespace std;

int main() {
    int r , g , b;
    cin >> r >> g >> b;
    int cr , cg , cb;
    cin >> cr >> cg >> cb;
    int crg , cgb;
    cin >> crg >> cgb;
    int sumR = max(0 , (r - cr));
    int sumG = max(0 , (g - cg));
    int sumB = max(0 , (b - cb));
    int negR = crg - sumR;
    if (negR < 0){
        cout << "-1" << endl;
        return 0;
    }
    int negB = cgb - sumB;
    if (negB < 0){
        cout << "-1" << endl;
        return 0;
    }
    int negG = negR + negB - sumG;
    if (negG < 0){
        cout << "-1" << endl;
        return 0;
    }
    cout << sumR + sumG + sumB << endl;
    return 0;
}