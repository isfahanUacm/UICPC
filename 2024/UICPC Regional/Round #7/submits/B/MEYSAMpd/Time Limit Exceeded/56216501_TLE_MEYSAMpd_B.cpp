#include <iostream>
#include "algorithm"
#include "vector"
#include "math.h"
using  namespace  std;

int max (int *arr, int size) {
    int max = arr[0];
    int idx = 0;
    for(int i = 0; i < size; i++) {
        if(max < arr[i]) {
            max = arr[i];
            idx = i;
        }
    }
    return idx;
}

bool equal (int * arr, int size) {
    for(int i = 1; i < size; i++) {
        if(arr[0] != arr[i])
            return false;
    }
    return true;
}


bool negative (int * arr, int size) {
    for(int i = 0; i < size; i++) {
        if(arr[i] < 0)
            return false;
    }
    return true;
}

int main() {
    int size;
    cin >> size;

    for (int i = 0; i < size; ++i) {
        int n;
        cin >> n;
        int arr[n];

        for (int j = 0; j < n; ++j) {
            cin >> arr[j];
        }

        int opr = 0;
        while(true) {
            if(!negative(arr , n)){
                cout << -1 << endl;
                break;
            }
            if(equal(arr, n)) {
                cout << opr << endl;
                break;
            }

            int idx = max(arr, n);

            arr[idx] -= 2;
            int temp = (idx % n) + 1;
            if(temp >= n){
                temp = 0;
            }
            arr[temp] += 1;
            opr ++;



        }
    }

    return 0;
}