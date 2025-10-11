#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    freopen("ghanophobia.in", "r", stdin);
    int T;
    cin >> T;
    cin.ignore();
    vector<string> inputs(T);
    for (int i = 0; i < T; i++) {
        getline(cin, inputs[i]);
    }

    for (int t = 0; t < T; t++) {
        string s = inputs[t];
        size_t pos = s.find(':');
        int egypt = stoi(s.substr(0, pos));
        int ghana = stoi(s.substr(pos + 1));

        int egyptTotal = 1 + egypt;
        int ghanaTotal = 6 + ghana;

        cout << "Case " << (t + 1) << ": ";

        if (egyptTotal > ghanaTotal) {
            cout << "YES" << endl;
        }
        else if (egyptTotal < ghanaTotal) {
            cout << "NO" << endl;
        }
        else {
            int egyptAway = 1;
            int ghanaAway = ghana;

            if (egyptAway > ghanaAway) {
                cout << "YES" << endl;
            }
            else if (egyptAway < ghanaAway) {
                cout << "NO" << endl;
            }
            else {
                cout << "PENALTIES" << endl;
            }
        }
    }

    return 0;
}
