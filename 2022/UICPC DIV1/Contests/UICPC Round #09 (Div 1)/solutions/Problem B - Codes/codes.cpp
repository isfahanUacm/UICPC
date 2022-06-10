#include <bits/stdc++.h>
using namespace std;

// Codes

int n, k;
bool mat[33][18];
bool code[18];
int ans;

void track(int i){
    if(i == k){
        int mul = 0;
        for(int i = 0; i < n; i++){
            bool row = false;
            for(int j = 0; j < k; j++)
                row = (row != (mat[i][j] && code[j]));
            if(row)
                mul++; 
        }
        if(mul)
            ans = min(ans, mul);
        return;
    }
    code[i] = true;
    track(i+1);
    code[i] = false;
    track(i+1);
}

int main(){
    int t;
    cin >> t;
    while(t--){
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < k; j++)
                cin >> mat[i][j];
        ans = INT_MAX;
        track(0);
        cout << ans << endl;
    }
}