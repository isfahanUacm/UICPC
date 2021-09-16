#include <bits/stdc++.h>
using namespace std;

// Shattered Cake

#define num long long int

int n;
num W, w, l;

int main(){
    cin >> W >> n;
    num area = 0;
    while(n--)
        cin >> w >> l, area += w * l;
    cout << area / W << endl;
}