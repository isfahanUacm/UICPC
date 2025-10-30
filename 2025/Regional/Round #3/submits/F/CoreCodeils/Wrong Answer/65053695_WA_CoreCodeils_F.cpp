#include <iostream>
#include <set>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    set<string> sett;
    for (int i = 1; i <= n; i++) {

        string p1;
        string p2;
        cin >> p1 >> p2;
        p1 = p1.substr(0, p1.length() - 1);
        cin >> p2;
        cin >> p2;

        sett.erase(p1);
        sett.insert(p2);
    }

    if (sett.size() == 1) {
        cout << "possible";
    }else
        cout << "impossible";

    return 0;
}