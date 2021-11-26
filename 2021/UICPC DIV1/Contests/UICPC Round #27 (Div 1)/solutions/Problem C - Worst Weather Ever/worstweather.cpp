#include <bits/stdc++.h>
using namespace std;

// Worst Weather Ever

const int maxn = 5e4 + 3;

int n, y[maxn], r[maxn], seg[4 * maxn], ind[4 * maxn];

void build(int v, int tl, int tr){
    if(tl == tr)
        seg[v] = r[tl], ind[v] = tl;
    else{
        int mid = (tl + tr) / 2;
        build(2 * v, tl, mid);
        build(2 * v + 1, mid+1, tr);
        seg[v] = seg[2 * v], ind[v] = ind[2 * v];
        if(seg[2 * v + 1] > seg[v])
            seg[v] = seg[2 * v + 1], ind[v] = ind[2 * v + 1];
    }
}

pair<int, int> query(int v, int tl, int tr, int l, int r){
    pair<int, int> ans = {0, -1};
    if(l > r)
        return ans;
    if(tl == l && tr == r)
        return {seg[v], ind[v]};
    int mid = (tl + tr) / 2;
    pair<int, int> left = query(2 * v, tl, mid, l, min(r, mid));
    if(left.first > ans.first)
        ans = left;
    pair<int, int> right = query(2 * v + 1, mid+1, tr, max(l, mid+1), r);
    if(right.first > ans.first)
        ans = right;
    return ans;
}

int main(){
    while(1){
        scanf("%d", &n);
        for(int i = 0; i < n; i++)
            scanf("%d %d", y+i, r+i);
        if(n)
            build(1, 0, n-1);
        int m, a, b;
        scanf("%d", &m);
        if(!m)
            break;
        while(m--){
            scanf("%d %d", &a, &b);
            int ita = lower_bound(y, y+n, a) - y;
            int itb = lower_bound(y, y+n, b) - y;
            if(ita < n && itb < n && y[ita] == a && y[itb] == b){
                if(r[itb] > r[ita]){
                    printf("false\n");
                    continue;
                }
                if(query(1, 0, n-1, ita+1, itb).second != itb){
                    printf("false\n");
                    continue;
                }
                if(b - a == itb - ita){
                    printf("true\n");
                    continue;
                }
            }
            else if(ita < n && y[ita] == a){
                if(query(1, 0, n-1, ita+1, itb-1).first >= r[ita]){
                    printf("false\n");
                    continue;
                }
            }
            else if(itb < n && y[itb] == b){
                if(query(1, 0, n-1, ita, itb).second != itb){
                    printf("false\n");
                    continue;
                }
            }
            printf("maybe\n");
        }
        printf("\n");
    }
}