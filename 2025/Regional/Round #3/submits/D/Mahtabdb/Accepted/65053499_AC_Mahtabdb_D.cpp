#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s; 

    int x[26] = {0}; 

  
    for (char c : s) {
        x[c - 'a']++;
    }

    int odd_count = 0;

    for (int i = 0; i < 26; i++) {
        if (x[i] % 2 != 0) {
            odd_count++;
        }
    }

 
    if (odd_count <= 1) cout << "yes";
    else cout << "no";

    return 0;
}
