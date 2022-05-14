#include <bits/stdc++.h>
using namespace std;

// Prinova

int n, b[103], A, B;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> b[i];
    cin >> A >> B;
    sort(b, b + n);
    if(!(A % 2))
        A++;
    if(!(B % 2))
        B--;
    int i = 0;
    while(i < n && b[i] < A)
        i++;
    if(i == n){
        cout << B << endl;
        return 0;
    }
    int j = n-1;
    while(j >= 0 && b[j] > B)
        j--;
    if(j == -1){
        cout << A << endl;
        return 0;
    }
    int best = INT_MIN, ans;
    for(int k = i; k < j; k++){
        int p = (b[k + 1] + b[k]) / 2;
        if(!(p % 2))
            p++;
        int d = min(p - b[k], b[k + 1] - p);
        if(d > best)
            best = d, ans = p;
    }
    if(!i){
        if(b[i] - A > best)
            best = b[i] - A, ans = A;
    }
    else{
        int p = (b[i] + b[i - 1]) / 2;
        if(!(p % 2))
            p++;
        p = max(p, A);
        int d = min(p - b[i - 1], b[i] - p);
        if(d > best)
            best = d, ans = p;
    }
    if(j == n-1){
        if(B - b[j] > best)
            best = B - b[j], ans = B;
    }
    else{
        int p = (b[j + 1] + b[j]) / 2;
        if(!(p % 2))
            p--;
        p = min(p, B);
        int d = min(b[j + 1] - p, p - b[j]);
        if(d > best)
            best = d, ans = p;
    }
    cout << ans << endl;
}