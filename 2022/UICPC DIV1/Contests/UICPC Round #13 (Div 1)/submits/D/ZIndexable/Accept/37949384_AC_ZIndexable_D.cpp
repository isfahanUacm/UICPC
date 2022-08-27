#include <bits/stdc++.h>
using namespace std;

int main() {
    int  rep;
    cin >> rep;
    string null;
    getline(cin, null);

    double dis_of_each = 6.731984258;
    for (int i = 0; i < rep ; ++i) {
        string poem;
        getline(cin, poem);

        vector<int> numPoem(poem.size());
        int j = 0;
        for (char & c : poem) {
            if(c == '\'') {
                numPoem[j] = 2;
            }
            else if(c == ' ') {
                numPoem[j] = 1;
            }
            else
                numPoem[j] = c - 'A' + 3;
            j++;
        }

        double dis = 0;

        for (int k = 0; k < numPoem.size() - 1; ++k) {
            int bigger = max(numPoem[k], numPoem[k + 1]);
            int smaller = min(numPoem[k], numPoem[k + 1]);

            int m1 = bigger - smaller;
            int m2 = (28 - bigger) + (smaller - 1) + 1;

            dis += min(m1 ,m2);
        }

        dis = dis* dis_of_each;

        double time = dis / 15.0;

        time = time + numPoem.size();

        cout << setprecision(20) << time << endl;
    }
    return 0;
}
