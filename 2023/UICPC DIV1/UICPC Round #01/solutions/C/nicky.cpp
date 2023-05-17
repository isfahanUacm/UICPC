#include <iostream>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int R, C, K;
int H[1001][1001];
set<int> valuesTmp;
vector<int> values;
vector<pair<int, int> > d;

bool doit(int v) {
    int costs[R][C];
    int s[R][C];
    bool southHasZero = false;
    for (auto r = 0; r < R; r++) {
        for (auto c = 0; c < C; c++) {
            costs[r][c] = H[r][c] < v ? 1 : 0;
            if (r == R - 1) {
                s[r][c] = costs[r][c];
                southHasZero = s[r][c] == 0;
            } else {
                s[r][c] = 1e9 + 7;
            }
        }
    }

    priority_queue<pair<pair<int, int>, int> > q;
    for (auto c = 0; c < C; c++) {
        auto r = R - 1;
        if (s[r][c] == 0 || !southHasZero) {
            q.push(make_pair(make_pair(r, c), s[r][c]));
        }
    }

    while (!q.empty()) {
        pair<pair<int, int>, int> i = q.top();
        q.pop();
        int r = i.first.first, c = i.first.second;
        for (auto dir : d) {
            int rr = r + dir.first, cc = c + dir.second;
            if (rr < 0 || cc < 0 || rr >= R || cc >= C) {
                continue;
            }
            int news = s[r][c] + costs[rr][cc];
            // Speedup: if the cost goes above K, we can stop checking it as it will never happen
            if (news < s[rr][cc] && news <= K) {
                s[rr][cc] = news;
                q.push(make_pair(make_pair(rr, cc), s[rr][cc]));
            }
        }
    }

    for (auto c = 0; c < C; c++) {
        if (s[0][c] <= K) {
            return true;
        }
    }

    return false;
}

int main() {
    d.push_back(make_pair( 0, -1));
    d.push_back(make_pair( 0,  1));
    d.push_back(make_pair(-1,  0));
    d.push_back(make_pair( 1,  0));

    cin >> R >> C >> K;
    for (auto r = 0; r < R; r++) {
        for (auto c = 0; c < C; c++) {
            int h;
            cin >> h;
            valuesTmp.insert(h);
            H[r][c] = h;
        }
    }

    for (auto v : valuesTmp) {
        values.push_back(v);
    }

    int l = 0, h = values.size() - 1, m = 0;
    int lastSucces = -1;
    while (l <= h) {
        m = (l + h) / 2;
        auto v = values[m];
        if (doit(values[m])) {
            lastSucces = values[m];
            l = m + 1;
        } else {
            h = m - 1;
        }
    }

    cout << lastSucces << endl;

    return 0;
}
