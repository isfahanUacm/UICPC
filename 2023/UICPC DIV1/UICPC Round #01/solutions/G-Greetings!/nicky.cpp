#include <iostream>
#include <string>

using namespace std;

int main() {
    string hey;
    cin >> hey;
    cout << "h";
    cout << string((hey.length() - 2) * 2, 'e');
    cout << "y" << endl;
    return 0;
}
