#include <iostream>
#include <vector>

using namespace std;

struct Participant {
    int score;
    long long penalty;
    bool isRudolf;
};

bool cmp(const Participant& a, const Participant& b) {
    if (a.score != b.score)
        return a.score > b.score;
    return a.penalty < b.penalty;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n, m, h;
        cin >> n >> m >> h;

        vector<Participant> participants;

        for (int i = 0; i < n; ++i) {
            vector<int> times(m);
            for (int j = 0; j < m; ++j) {
                cin >> times[j];
            }

            sort(times.begin(), times.end());

            int solved = 0;
            long long currentTime = 0;
            long long totalPenalty = 0;

            for (int time : times) {
                if (currentTime + time > h) break;
                currentTime += time;
                ++solved;
                totalPenalty += currentTime;
            }

            participants.push_back({solved, totalPenalty, i == 0});
        }

        sort(participants.begin(), participants.end(), cmp);

        for (int i = 0; i < n; ++i) {
            if (participants[i].isRudolf) {
                cout << i + 1 << "\n";
                break;
            }
        }
    }

    return 0;
}
