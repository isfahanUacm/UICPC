#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    int red = 0;
    int yellow = 0;
    int green = 0;
    int brown = 0;
    int blue = 0;
    int pink = 0;
    int black = 0;
    bool val = false;
    for (int i = 0; i < n; i++) {
        string inp;
        cin >> inp;
        if (inp == "red") {
            red++;
        } else if (inp == "yellow") {
            val = true;
            yellow++;
        } else if (inp == "green") {
            val = true;
            green++;
        } else if (inp == "brown") {
            brown++;
            val = true;
        } else if (inp == "blue") {
            val = true;
            blue++;
        } else if (inp == "pink") {
            val = true;
            pink++;
        } else if (inp == "black") {
            val = true;
            black++;
        }
    }
    if (!val){
        cout << 1;
        return 0;
    }
    int sum = 0;
    while (red > 0) {
        if (black > 0) {
            red--;
            sum += 8;
        } else if (pink > 0) {
            red--;
            sum += 7;
        } else if (blue > 0) {
            red--;
            sum += 6;
        } else if (brown > 0) {
            red--;
            sum += 5;
        } else if (green > 0) {
            red--;
            sum += 4;
        } else if (yellow > 0) {
            red--;
            sum += 3;
        } else {
            while (red > 0) {
                sum++;
                red--;
            }
        }
    }
    sum += black * 7 + brown * 4 + pink * 6 + blue * 5 + green * 3 + yellow * 2 + red;
    cout << sum;
}