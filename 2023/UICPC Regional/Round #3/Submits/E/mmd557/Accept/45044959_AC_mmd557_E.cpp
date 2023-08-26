#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;



int main() {
    int a;
    cin >>a;
    for (int i = 0; i < a; ++i) {
        string tmp;
        cin>>tmp;
        int sq = ceil(sqrt(tmp.size()));
        for (int j = sq-1; j >= 0;--j) {
            int t = j;
            while (true) {
                if (t >= tmp.size())
                    break;

                cout << tmp[t];
                t += sq;
            }
        }
        cout <<endl;

    }
    return 0;
}

