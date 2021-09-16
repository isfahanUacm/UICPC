#include <bits/stdc++.h>
using namespace std;

// Distributing Ballot Boxes

const int maxn = 5e5 + 3;
int n, b;
int population[maxn];

bool judge(int mid){
    long long int m = 0;
    for(int i = 0; i < n; i++)
        m += population[i] / mid + (population[i] % mid ? 1 : 0);
    return m <= b;
}

int main(){
    while(1){
        cin >> n >> b;
        if(n + b == -2)
            break;
        for(int i = 0; i < n; i++)
            cin >> population[i];
        int l = 1, r = 5000000;
        while(l < r){
            int mid = (l + r) / 2;
            if(judge(mid))
                r = mid;
            else
                l = mid + 1;
        }
        cout << l << endl;
    }
}