#include <iostream>
using namespace std;
int main(){
    int t;
    cin >> t;
    for(int i = 0; i<t; i++){
        int n;
        cin >> n;
        int counter = 0;
        for(int j = 1; j<n; j++){
            for(int k = j+1; k<=n; k++){
                if((j*k) % (k-j)== 0){
                    counter++;
                }
            }
        }
        cout << counter << endl;
    }
}