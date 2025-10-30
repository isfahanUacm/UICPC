#include <iostream>
#include <set>
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

    set<string> sett;
    vector<string> v;
    for (int i = 1; i <= n; i++) {

        string p1;
        string p2;
        cin >> p1 >> p2;
        p1 = p1.substr(0, p1.length() - 1);
        cin >> p2;
        cin >> p2;


        sett.insert(p2);
        v.push_back(p1);
    }

    for (int i = 0; i < v.size(); i++) {
        sett.erase(v[i]);
    }

    if (sett.size() <= 1) {
        cout << "possible";
    }else
        cout << "impossible";

    return 0;
}