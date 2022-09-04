#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<vector<int>> v(5, vector<int>(5));
    int num = 0;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            char c;
            cin >> c;
            if (c == '.') {
                v[i][j] = 0;
            } else{
                v[i][j] = 1;
                num++;
            }
        }
    }
    if (num != 9){
        cout << "invalid";
        return 0;
    }

    vector<pair<int,int>> tmp(8);
    tmp[0].first = -2; tmp[0].second = -1;
    tmp[1].first = -1; tmp[1].second = -2;
    tmp[2].first = 2; tmp[2].second = 1;
    tmp[3].first = 1; tmp[3].second = 2;
    tmp[4].first = -1; tmp[4].second = 2;
    tmp[5].first = 2; tmp[5].second = -1;
    tmp[6].first = 1; tmp[6].second = -2;
    tmp[7].first = -2; tmp[7].second = 1;

    bool valid = true;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 5; ++j) {
            if (v[i][j] == 0)
                continue;
            for (int k = 0; k < 8; ++k) {
                int x = i + tmp[k].first;
                int y = j + tmp[k].second;
                if(x < 0 || y < 0 || x > 4 || y > 4)
                    continue;

                if (v[x][y] == 1){
                    valid = false;
                }
            }
        }
    }
    if (valid)
        cout << "valid";
    else
        cout << "invalid";
    return 0;
}
