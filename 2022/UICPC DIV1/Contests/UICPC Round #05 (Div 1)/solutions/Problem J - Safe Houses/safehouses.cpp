#include <bits/stdc++.h>
using namespace std;
#define MAX_N 103
int n;
char grid[MAX_N][MAX_N];
vector<pair<int, int>> S;
vector<pair<int, int>> H;

int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            cin>>grid[i][j];
            if(grid[i][j]=='S')
                S.push_back({i, j});
            else if(grid[i][j]=='H')
                H.push_back({i, j});
        }
    }
    int mx=0, mi;
    for (auto s : S) {
        mi = INT_MAX;
        for (auto h : H) {
            mi = min(mi, abs(s.first-h.first) + abs(s.second-h.second));
        }
        mx = max(mi, mx);
    }
    cout<<mx<<endl;
    return 0;
}

