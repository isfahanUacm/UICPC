#include <bits/stdc++.h>
using namespace std;

// Firefly

int N, H;
int down[100003], up[100003];

int main(){
    cin >> N >> H;
    for(int i = 0; i < N/2; i++)
        cin >> down[i] >> up[i];
    sort(down, down+N/2), sort(up, up+N/2);
    int ans = INT_MAX, cnt = 0;
    for(int h = 1; h <= H; h++){
        int curr = N - (lower_bound(down, down+N/2, h) - down) - (lower_bound(up, up+N/2, H-h+1) - up);
        if(curr == ans)
            cnt++;
        else if(curr < ans)
            ans = curr, cnt = 1;
    }
    cout << ans << " " << cnt << endl;
}