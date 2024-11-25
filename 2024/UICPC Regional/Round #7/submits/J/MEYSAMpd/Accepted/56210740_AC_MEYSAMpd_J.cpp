#include <iostream>

using namespace  std;

int main() {

    int size , bamount = 0 , pamount = 0 , number;
    char type;
    cin >> size;
    for(int i = 0 ; i < size ; i++){
        cin >> type;
        cin >> number;
        if(type == 'B'){
            bamount += number;
            if(bamount >= pamount + 1){
                cout << "YES" << endl;
                pamount = 0;
                bamount = 0;
            }
            else{
                cout << "NO" << endl;
            }
        }
        else{
            pamount += number;
        }
    }
    return 0;
}