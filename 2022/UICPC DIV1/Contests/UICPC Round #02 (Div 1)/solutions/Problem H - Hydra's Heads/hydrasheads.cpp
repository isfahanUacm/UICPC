#include <bits/stdc++.h>
using namespace std;

// Hydra's Heads

int h, t, a[]{2, 1, 0, 3};

int main(){
    while(1){
        cin >> h >> t;
        if(!(h + t))
            break;
        if(!t){
            if(h % 2)
                cout << -1 << endl;
            else
                cout << h / 2 << endl;
            continue;
        }
        int ans = h / 2;
        h %= 2;
        if(h){
            ans += a[t % 4];
            t += a[t % 4];
            ans += 3 * (t / 4) + 2;
        }   
        else{
            ans += 3 * (t / 4);
            if(t % 4)
                ans += 4 - t % 4 + 3;
        }
        cout << ans << endl;
    }
}