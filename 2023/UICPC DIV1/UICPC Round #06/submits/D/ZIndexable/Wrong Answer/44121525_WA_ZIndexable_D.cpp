#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    for (int hindex = n; hindex >= 1; --hindex) {
        int counter =0;
        for(int a : arr){
            if (a >= hindex){
                counter ++;
            }
        }
        if (counter >= hindex) {
            cout << hindex;
            exit(0);
        }
    }
    return 0;
}
