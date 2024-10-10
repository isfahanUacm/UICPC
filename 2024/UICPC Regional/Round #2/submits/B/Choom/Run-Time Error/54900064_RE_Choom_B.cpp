#include <iostream>
using namespace std;

int test[4] = {-1, -1, -1, -1};

int cntF() {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (test[i] == 0) cnt++;
    }
    return cnt;
}

int main () {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int q, m;
        cin >> q >> m;

        string ans = "", p[m];
        cin.ignore();
        for (int j = 0; j < m; j++) {
            getline(cin, p[j]);
        }

        int idxI = 0, idxJ = 2;
        while (true) {
            if(idxJ >= p[0].length())  break;
            if(idxI == m) {
                idxJ += 4;
                idxI = 0;

                if(cntF() == 3) {
                    for(int i = 0; i < 4; i++) {
                        if (test[i] == -1) {
                            ans += i + 'A';
                            ans += ' ';
                        }
                    }
                }
                else {
                    ans += "? ";
                }

                for(int idx = 0; idx < 4; idx ++) test[idx] = -1;
            }
            if(p[idxI][idxJ] == 'T') {
                ans += p[idxI][idxJ - 2];
                ans += ' ';
                idxJ += 4;
                idxI = 0;
                for(int idx = 0; idx < 4; idx ++) test[idx] = -1;
                continue;
            }
            else if(p[idxI][idxJ] == 'F') {
                test[p[idxI][idxJ - 2] - 'A'] = 0;
            }
            idxI ++;
        }
        ans.erase(ans.length() - 1);
        cout << ans << endl;
    }
    return 0;
}