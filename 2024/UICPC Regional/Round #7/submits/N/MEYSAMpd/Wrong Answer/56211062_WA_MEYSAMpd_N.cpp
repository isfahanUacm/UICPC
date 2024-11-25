#include <iostream>

using namespace  std;

int main() {

    int size;
    cin >> size;
    string text;
    for (int i = 0; i < size; ++i) {
        cin >> text;
        if(text[1] == '='){
            if(text[0] == text[2]){
                cout << text << endl;
            }
            else{
                if(text[2] > text[0]){
                    text[1] = '<';
                }
                else{
                    text[1] = '>';
                }
                cout << text << endl;
            }
        }
        else if(text[1] == '<'){
            if(text[0] < text[2]){
                cout << text << endl;
            }
            else {
                text[0] = '0';
                cout << text << endl;
            }
        }
        else{
            if(text[0] > text[2]){
                cout << text << endl;
            }
            else{
                text[0] = text[2] + 1;
                cout << text << endl;
            }
        }
    }
    return 0;
}
