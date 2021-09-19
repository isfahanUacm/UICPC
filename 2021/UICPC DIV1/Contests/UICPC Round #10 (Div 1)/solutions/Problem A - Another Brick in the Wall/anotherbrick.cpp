#include <bits/stdc++.h>
using namespace std;

// Another Brick in the Wall

int h, w, n;

int main(){
    cin >> h >> w >> n;
    int layers = 0, current = 0, brick;
    while(n--){
        cin >> brick, current += brick;
        if(current > w)
            break;
        if(current == w){
            layers += 1, current = 0;
            if(layers == h){
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
}