#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    freopen("cubes.in", "r", stdin);
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;
        vector<long long> cubes(N);

        for (int i = 0; i < N; i++) {
            cin >> cubes[i];
        }
        sort(cubes.begin(), cubes.end()); 

        cout << "Case " << t << ":\n";
        for (int i = 0; i < N; i++) {
            cout << cubes[i];
            if (i < N - 1) cout << " ";
            else cout << "\n";
        }
    }

    return 0;
}
