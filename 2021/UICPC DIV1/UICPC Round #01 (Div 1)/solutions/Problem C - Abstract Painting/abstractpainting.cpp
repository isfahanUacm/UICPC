#include <bits/stdc++.h>
using namespace std;

// Abstract Painting

#define num long long int

const num mod = 1e9 + 7;

int main(){
    int t;
    cin >> t;
    while(t--){
        int r, c;
        cin >> r >> c;
        num ans = 1;
        for(int i = 0; i < r; i++)
            for(int j = 0; j < c; j++){
                if(!i && !j)
                    ans = (ans * 18) % mod;
                else if(!i || !j)
                    ans = (ans * 6) % mod;
                else
                    ans = (ans * 2) % mod;
            }
        cout << ans << endl;
    }
}