#include <iostream>
using namespace std;

int main() {
freopen("cubes.in", "r", stdin);
    int T;
    cin >> T;

    for (int t = 1; t <= T; t++) {
        int N;
        cin >> N;

        cout << "Case " << t << ":\n";

  
        for (int i = (N % 2 == 0 ? N : N - 1); i >= 2; i -= 2) {
            cout << i << " ";
        }

    
        for (int i = 1; i <= N; i += 2) {
            cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}
