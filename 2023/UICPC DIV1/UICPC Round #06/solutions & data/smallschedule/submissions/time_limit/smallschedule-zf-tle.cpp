#include <iostream>
#include <vector>

using namespace std;

void update(vector<int>& machines, int t) {
    int mn = 0;
    for (int i = 1; i < machines.size(); ++i)
        if (machines[i] < machines[mn])
            mn = i;
    machines[mn] += t;
}

int main() {
    int Q, M, S, L;

    cin >> Q >> M >> S >> L;
    vector<int> machines(M, 0);

    while (L--) update(machines, Q);
    while (S--) update(machines, 1);

    int mx = 0;
    for (int i = 1; i < machines.size(); ++i)
        if (machines[i] > machines[mx])
            mx = i;
    
    cout << machines[mx] << endl;

    return 0;
}
