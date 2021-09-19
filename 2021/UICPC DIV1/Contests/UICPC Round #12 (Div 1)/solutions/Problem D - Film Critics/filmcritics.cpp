#include <bits/stdc++.h>
using namespace std;

// Film Critics

const int maxn = 2e5 + 3;

int n, m, k, ans[maxn];
pair<int, int> a[maxn];
int ptrp, ptrn, cnt;

int main(){
    cin >> n >> m >> k;
    if(!k || k % m){
        cout << "impossible" << endl;
        return 0;
    }
    if(n == 1){
        cout << 1 << endl;
        return 0;
    }
    for(int i = 0; i < n; i++)
        cin >> a[i].first, a[i].second = i;
    sort(a, a + n);
    ptrp = n - k / m, ptrn = ptrp - 1, cnt = 0;
    for(int i = 0; i < n; i++){
        if(ptrp < n && a[ptrp].first * i >= (cnt * m))
            cnt++, ans[i] = a[ptrp++].second;
        else if(ptrn >= 0 && a[ptrn].first * i < (cnt * m))
            ans[i] = a[ptrn--].second;
        else{
            cout << "impossible" << endl;
            return 0;
        }
    }
    for(int i = 0; i < n; i++)
        cout << ans[i] + 1 << " ";
    cout << endl;
}