#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;

    int index = 1;
    int maxindex = 'z' - 'a' + 1;
    vector<string> a;
    while (n--) {
        int p;
        cin >> p;

        vector<string> b;
        for (int i = 0; i < p; i++) {
            string s;
            cin >> s;
            b.push_back(s);
        }


        sort(b.begin(), b.end());
        if (a.empty()) {
            a.push_back(b[0]);
            continue;
        }
        bool flag = false;
        for (int i = 0; i < p; i++) {
            if (b[i] >= a[a.size() - 1]) {
                a.push_back(b[i]);
                flag = true;
                break;
            }
        }

        if (!flag) {
            cout << "impossible" << endl;
            return 0;
        }


    }


    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
    return 0;
}
