#include <iostream>

using namespace std;

int main() {
    int n,height;
    cin >> n;
    int arr[n];
    for ( int i = 0 ; i < n ; i++){
        cin >> arr[i];
    }
    cin >> height;
    int best = height%arr[0];
    int cut = arr[0];
    for ( int i = 1 ; i < n ; i++){
        if (height%arr[i] < best){
            best = height%arr[i];
            cut = arr[i];
        }
    }
    cout << cut;
}