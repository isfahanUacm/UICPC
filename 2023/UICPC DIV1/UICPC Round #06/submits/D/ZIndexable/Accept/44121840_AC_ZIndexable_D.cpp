#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include "bits/stdc++.h"

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    for (int hindex = n; hindex >= 0; --hindex) {
        int counter =0;

        for(int i = n - 1; i >= 0; --i){
            if (arr[i] >= hindex){
                counter ++;
            } else{
                break;
            }
        }
        if (counter >= hindex) {
            cout << hindex;
            exit(0);
        }
    }
    return 0;
}
