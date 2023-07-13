#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    priority_queue<int, vector<int>, std::greater<int>> q;

    int Q, M, S, L;
    cin >> Q >> M >> S >> L;

    for (int i = 0; i < M; ++i) q.push(0);

    while (L--) {
        q.push(q.top()+Q);
        q.pop();
    }

    while (S--) {
        q.push(q.top()+1);
        q.pop();
    }

    while (q.size() > 1) q.pop();

    cout << q.top() << endl;

    return 0;
}
