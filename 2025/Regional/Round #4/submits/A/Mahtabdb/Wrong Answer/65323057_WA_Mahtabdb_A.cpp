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
    int sum = max(0 , (r - cr)) + max(0 , (g - cg)) + max(0 , b - cb);
    int sum2 = crg + cgb;
    if (sum2 < sum) cout << "-1" << endl;
    else cout << sum << endl;
    return 0;
}