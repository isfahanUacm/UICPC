#include <iostream>
using namespace std;

int main() {
    freopen("jenga.in", "r", stdin);
    int T;
    cin >> T;

    for (int i = 1; i <= T; i++) {
        long long N;
        cin >> N;
        string winner;

        if (N % 4 == 0 || N % 4 == 1)
            winner = "Wahdan";
        else
            winner = "Bakkar";

        cout << "Case " << i << ": " << winner << endl;
    }

    return 0;
}
