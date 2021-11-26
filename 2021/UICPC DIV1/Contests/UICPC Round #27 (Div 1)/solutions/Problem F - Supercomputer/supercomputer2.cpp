#include <bits/stdc++.h>
using namespace std;

// Supercomputer

const int maxn = 1e6 + 3;

int n, k, mem[maxn], ft[maxn];

int rsq(int i){
    int sum = 0;
    while(i)
        sum += ft[i], i -= i & (-i);
    return sum;
}

void inc(int i, int k){
    while(i <= n)
        ft[i] += k, i += i & (-i);
}

int main(){
    scanf("%d %d\n", &n, &k);
    char c;
    int l, r;
    while(k--){
        scanf("%c %d", &c, &l);
        if(c == 'F'){
            scanf("\n");
            inc(l, mem[l] ? -1 : 1);
            mem[l] = !mem[l];
        }
        else{
            scanf("%d\n", &r);
            printf("%d\n", rsq(r) - (l > 1 ? rsq(l - 1) : 0));
        }
    }
}