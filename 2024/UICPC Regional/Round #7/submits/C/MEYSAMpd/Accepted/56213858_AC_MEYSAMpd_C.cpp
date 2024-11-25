#include <iostream>
#include "algorithm"
#include "vector"
using  namespace  std;

int main() {
    int size;
    cin >> size;

    for(int i = 0; i < size; i ++) {
        int n;
        cin >> n;
        int arr [n];
        for(int j = 0; j < n; j++) {
            cin >> arr[j];
        }
        sort(arr, arr + n);
        int num = 0;
        bool status = false;
        vector <int> pair;
        for(int j = 0; j < n - 1; j++) {
            if(arr[j] == arr[j + 1]) {
                pair.push_back(arr[j]);
                num ++;
                j ++;
            }
            if(num == 4) status = true;
        }
        if(status) {
            cout << "YES\n";
            int x1,x2,y1,y2;
            x1=pair.front();
            x2=pair[pair.size()-2];
            y1=pair[1];
            y2 = pair[pair.size() - 1];
            cout << x1 << ' ' << y1 << ' ' << x1 << ' ' << y2 << ' ' << x2 << ' ' << y1 << ' ' << x2 << ' ' << y2 << endl;
        }
        else {
            cout << "NO\n";
        }
    }
    return 0;
}