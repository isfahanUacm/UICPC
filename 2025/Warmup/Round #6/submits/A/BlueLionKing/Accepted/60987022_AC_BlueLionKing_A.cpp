#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;

        vector<pair<int, long long>> pp;

        for (int i = 0; i < n; i++) {
            vector<int> problems(m);
            for (int j = 0; j < m; j++) {
                cin >> problems[j];
            }

            sort(problems.begin(), problems.end());

            long long time = 0, penalty = 0;
            int solved = 0;

            for (int j = 0; j < m; j++) {
                if (time + problems[j] > h) {
                    break;
                }
                time += problems[j];
                penalty += time;
                solved++;
            }

            pp.push_back({solved, penalty});
        }

        int rank = 1;
        for (int i = 1; i < n; i++) {
            if (pp[i].first > pp[0].first) {
                rank++;
            } else if (pp[i].first == pp[0].first && pp[i].second < pp[0].second) {
                rank++;
            }
        }

        cout << rank << endl;
    }

    return 0;
}
