#include <bits/stdc++.h>
using namespace std;

// Frosh Week

const int maxn = 2e5 + 3;

int n, m, a[maxn], b[maxn];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> a[i];
    for(int i = 0; i < m; i++)
        cin >> b[i];
    sort(a, a + n);
    sort(b, b + m);
    int i = 0, j = 0, ans = 0;
    while(i < n && j < m){
        if(a[i] <= b[j])
            i++, j++, ans++;
        else
            j++;
    }
    cout << ans << endl;
}