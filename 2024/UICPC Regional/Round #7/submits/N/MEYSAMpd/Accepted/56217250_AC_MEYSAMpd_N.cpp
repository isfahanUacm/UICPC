#include <iostream>

using namespace  std;

int main() {

    int size;
    cin >> size;
    string text;
    for (int i = 0; i < size; ++i) {
        cin >> text;
        if(text[0] == text[2]){
            text[1] = '=';
        }
        else if(text[0] < text[2]){
            text[1] = '<';
        }
        else{
            text[1] = '>';
        }
        cout << text << endl;

    }
    return 0;
}
