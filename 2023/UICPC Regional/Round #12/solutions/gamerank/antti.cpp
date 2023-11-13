#include <iostream>

using namespace std;

string s;
int r = 25;
int c = 0;
int z = 0;

int main() {
    cin >> s;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'W') {
            z++; c++;
            if (z >= 3 && r >= 6 && r <= 25) c++;
            if (r >= 21 && r <= 25 && c > 2) {r--; c -= 2;}
            if (r >= 16 && r <= 20 && c > 3) {r--; c -= 3;}
            if (r >= 11 && r <= 15 && c > 4) {r--; c -= 4;}
            if (r >= 1 && r <= 10 && c > 5) {r--; c -= 5;}
            if (r == 0) {
                cout << "Legend\n";
                return 0;
            }
        }
        if (s[i] == 'L') {
            z = 0;
            if (r >= 1 && r <= 20) c--;
            if (r == 20 && c == -1) c = 0;
            if (c < 0 && r <= 10) {r++; c = 4; if (r == 11) c = 3;}
            if (c < 0 && r <= 15) {r++; c = 3; if (r == 16) c = 2;}
            if (c < 0 && r <= 20) {r++; c = 2;}
        }
    }
    cout << r << "\n";
}
