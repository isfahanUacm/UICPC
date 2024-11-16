#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        int n, q;
        cin >> n >> q;

        string artists;
        cin.ignore();
        getline(cin, artists);

        int updates[q];
        for (int j = 0; j < q; j++) {
            cin >> updates[j];

            int cnt = 0, k = 0;
            while (cnt != (updates[j] / 2)) {
                artists.erase(artists.begin() + k);
                artists.erase(artists.begin() + k);
                k += 2;
                cnt++;
            }

            int l = 0, r = ((updates[j] / 2) - 1) * 2;
            while (l < r) {
                swap(artists[l], artists[r]);
                l += 2;
                r -= 2;
            }
        }

        for (int j = 0; j < artists.length(); j += 2) {
            cout << artists[j] << " ";
        }

    }
    return 0;
}
