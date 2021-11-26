#include <bits/stdc++.h>
using namespace std;

// In Flagrante Delicto

const int maxn = 2e5 + 3;

int n, a[maxn];
vector<int> lis;

int main(){
    cin >> n;
    int x;
    for(int i = 0; i < n; i++)
        cin >> x, a[x - 1] = i;
    while(n--){
        cin >> x, x = a[x - 1];
        auto it = lower_bound(lis.begin(), lis.end(), x);
        if(it == lis.end())
            lis.push_back(x);
        else *it = x;
    }
    cout << 2 << " " << lis.size() + 1 << endl;
}