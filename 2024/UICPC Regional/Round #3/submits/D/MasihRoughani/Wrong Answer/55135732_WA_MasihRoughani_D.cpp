#include <iostream>

using namespace std;

int main() {
    string inp;
    cin >> inp;
    int index = 0;
    int arr1[inp.length()];
    int arr2[inp.length()];
    for ( int i = 0 ; i < inp.length()-1 ; i++){
        if (inp[i] > inp[i+1]){
            swap(inp[i],inp[i+1]);
            arr1[index] = i+1;
            arr2[index++] = i;
        }
    }
    for ( int i = index-1 ; i >= 0 ; i--){
        cout << arr1[i]+1 << " " << arr2[i]+1 << endl;
    }
}