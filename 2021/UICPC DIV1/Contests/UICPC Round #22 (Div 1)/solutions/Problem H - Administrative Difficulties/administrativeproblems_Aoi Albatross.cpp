#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

struct tmp {
    ll price;
    ll rent;
    ll kilo;
};

map<string, tmp> hasCar;
map<string, tmp> cars;
map<string, ll> debt;
set<string> isIC;
set<string> all;

int main() {
    ll tc;
    cin >> tc;
    while (tc--) {
        hasCar.clear();
        cars.clear();
        debt.clear();
        isIC.clear();
        all.clear();

        ll n, m;
        cin >> n >> m;

        for (ll i = 0; i < n; ++i) {
            string a;
            ll b, c, d;
            cin >> a >> b >> c >> d;
            cars[a] = tmp{b, c, d};
        }

        for (ll i = 0; i < m; ++i) {
            ll t;
            string name;
            string task;
            cin >> t >> name >> task;
            all.insert(name);
            if (task == "p") {
                string carName;
                cin >> carName;
                if (hasCar.find(name) != hasCar.end()) {
                    isIC.insert(name);
                }
                else {
                    tmp temp = cars[carName];
                    debt[name] += temp.rent;
                    hasCar[name] = temp;
                }
            }
            else if (task == "r") {
                ll ki;
                cin >> ki;
                if (hasCar.find(name) == hasCar.end()) {
                    isIC.insert(name);
                }
                else {
                    tmp temp = hasCar[name];
                    debt[name] += temp.kilo * ki;
                    hasCar.erase(name);
                }
            }
            else if (task == "a") {
                double p;
                cin >> p;
                if(hasCar.find(name) == hasCar.end()) {
                    isIC.insert(name);
                }
                else {
                    tmp temp = hasCar[name];
                    debt[name] += ceil(temp.price * p / 100);
                }
            }
        }
        for(auto x : all) {
            cout << x << ' ';
            if (isIC.count(x) > 0 || hasCar.count(x) > 0) {
                cout << "INCONSISTENT";
            }
            else {
                if (debt.count(x) > 0)
                    cout << debt[x];
                else
                    cout << 0;
            }
            cout << endl;
        }
    }
}