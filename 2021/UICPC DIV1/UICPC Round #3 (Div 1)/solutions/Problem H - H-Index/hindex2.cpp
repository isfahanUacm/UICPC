#include <bits/stdc++.h>
using namespace std;

// H-Index

int n;
int p[100003];

bool judge(int h){
    int ans = 0;
    for(int i = 0; i < n; i++)
        if(p[i] >= h)
            ans++;
    return ans >= h;
}

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> p[i];
    int lo = 0, hi = n;
    while(lo < hi){
        int mid = (lo + hi) / 2 + (lo + hi) % 2;
        if(judge(mid))
            lo = mid;
        else hi = mid - 1;
    }
    cout << lo << endl;
}