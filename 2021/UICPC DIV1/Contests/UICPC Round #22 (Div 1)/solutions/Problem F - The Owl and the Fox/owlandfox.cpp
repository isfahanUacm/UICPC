#include <bits/stdc++.h>
using namespace std;

// The Owl and the Fox

char c[10];

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> c;
        for(int i = strlen(c) - 1; i >= 0; i--)
            if(c[i] != '0'){
                c[i]--;
                break;
            }
        cout << atoi(c) << endl;
    }
}