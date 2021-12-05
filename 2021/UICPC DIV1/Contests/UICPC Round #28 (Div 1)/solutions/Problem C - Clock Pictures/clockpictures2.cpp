#include <bits/stdc++.h>
using namespace std;

// Clock Pictures

const int maxn = 2e5 + 3;

int n, c1[maxn], c2[maxn], t[2 * maxn], p[maxn], lcp[maxn];

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> c1[i];
    for(int i = 0; i < n; i++)
        cin >> c2[i];
    sort(c1, c1 + n);
    sort(c2, c2 + n);
    for(int i = 0; i < n - 1; i++)
        t[i] = c1[i + 1] - c1[i];
    t[n - 1] = 360000 - (c1[n - 1] - c1[0]);
    for(int i = 0; i < n - 1; i++)
        p[i] = c2[i + 1] - c2[i];
    p[n - 1] = 360000 - (c2[n - 1] - c2[0]);
    for(int i = 0; i < n; i++)
        t[n + i] = t[i];
    // KMP:
    int i = 0, j = 1;
    lcp[0] = 0;
    while(j < n){
        if(p[j] == p[i])
            lcp[j] = i + 1, i++, j++;
        else if(i)
            i = lcp[i - 1];
        else
            lcp[j] = 0, j++;
    }
    i = 0, j = 0;
    while(i < 2 * n){
        if(t[i] == p[j]){
            i++, j++;
            if(j == n){
                cout << "possible" << endl;
                return 0;
            }
        }
        else if(j)
            j = lcp[j - 1];
        else
            i++;
    }
    cout << "impossible" << endl;
}