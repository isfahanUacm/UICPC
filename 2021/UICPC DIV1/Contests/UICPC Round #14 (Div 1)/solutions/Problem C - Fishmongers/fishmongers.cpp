#include <bits/stdc++.h>
using namespace std;

// Fishmongers

const int maxn = 1e5 + 3;

#define num long long int

int n, m;
num fish[maxn];
pair<num, num> mong[maxn];

int main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++)
        cin >> fish[i];
    sort(fish, fish + n, greater<int>());
    for(int i = 0; i < m; i++)
        cin >> mong[i].second >> mong[i].first;
    sort(mong, mong + m, greater<pair<int, int>>());
    num ans = 0;
    int i = 0, j = 0;
    while(i < n && j < m){
        ans += mong[j].first * fish[i];
        i++;
        mong[j].second--;
        if(!mong[j].second)
            j++;
    }
    cout << ans << endl;
}