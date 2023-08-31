#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<long long> vl;
typedef vector<string> vs;
typedef vector<bool> vb;

typedef pair<int,int> pii;
typedef pair<pair<int, int>, int> piii;
typedef vector<pair<int, int>> vii;

typedef vector<vector<bool>> vvb;
typedef vector<vector<int>> vvi;
typedef vector<vector<char>> vvc;
typedef vector<vector<long long>> vvl;

int main() {
    int p, budget, hotels, weeks;
    cin >> p >> budget >> hotels >> weeks;

    int ans = INFINITY;
    bool found = false;
    for (int i = 0; i < hotels; ++i) {
        int cost;
        cin >>cost;
        for (int j = 0; j < weeks; ++j) {
            int cap;
            cin>>cap;
            if (cap >= p){
                if ((cost * p) <= budget) {
                    found = true;
                    if (cost * p < ans) {
                        ans = cost * p;
                        break;
                    }
                }
            }
        }
    }
    if (found) {
        cout <<ans;
    } else {
        cout << "stay home";
    }
    return 0;
}