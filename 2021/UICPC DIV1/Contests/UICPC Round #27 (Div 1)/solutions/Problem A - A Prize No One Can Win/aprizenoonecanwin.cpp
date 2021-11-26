#include <bits/stdc++.h>
using namespace std;

// A Prize No One Can Win

int n, x;
int b[100003];

int main(){
    cin >> n >> x;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    sort(b, b+n);
    int ans = 0;
    for(; ans < n; ans++)
        if(b[ans] + (ans ? b[ans-1] : 0) > x)
            break;
    cout << max(ans, 1) << endl;
}