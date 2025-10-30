#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
    int n;
    cin >> n;

    string** names = new string * [n];  
    int* p = new int[n];            
    for (int i = 0; i < n; i++) {
        cin >> p[i];
        names[i] = new string[p[i]]; 
        for (int j = 0; j < p[i]; j++) {
            cin >> names[i][j];
        }
        sort(names[i], names[i] + p[i]);
    }

    string* result = new string[n];
    string prev = "";

    for (int i = 0; i < n; i++) {
        bool found = false;
        for (int j = 0; j < p[i]; j++) {
            if (names[i][j] >= prev) {
                result[i] = names[i][j];
                prev = names[i][j];
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "impossible\n";
          
            for (int k = 0; k < n; k++) delete[] names[k];
            delete[] names;
            delete[] p;
            delete[] result;
            return 0;
        }
    }

    for (int i = 0; i < n; i++) {
        cout << result[i] << "\n";
    }


    for (int i = 0; i < n; i++) delete[] names[i];
    delete[] names;
    delete[] p;
    delete[] result;

    return 0;
}
