#include <bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(), (x).end()

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair <ll, ll> pll;
typedef vector<int> vi;
typedef vector <ll> vll;

void solve();

template<class T>
void printArray(T *arr, size_t size) {
    if (!size) return;
    for (size_t i = 0; i < size - 1; i++) {
        cout << arr[i] << ' ';
    }
    cout << arr[size - 1];
}

template<class T>
ostream &operator<<(ostream &os, const vector <T> &vec) {
    if (!vec.size()) return os;
    for (size_t i = 0; i < vec.size() - 1; i++) {
        os << vec[i] << ' ';
    }
    os << vec.back();
    return os;
}

int main() {
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    cout << fixed;
    cout << setprecision(10);
    ll t = 1;
//    cin >> t;
    while (t--)
        solve();
    return 0;
}

void solve() {
    int xs, ys, xt, yt, xp, yp;
    cin >> xs >> ys >> xt >> yt >> xp >> yp;

    double m = abs(yt - ys) / abs(xt - xs);
    double b = yt - (xt * m);
    double y = b + (m * xp);

    cout << 2 << endl;

    if (xt > xs && yt > ys) {
        if (yp < y) {
            cout << xs << " " << yt - 1 << endl;
            cout << xs + 1 << " " << yt << endl;
        } else {
            cout << xt - 1 << " " << ys << endl;
            cout << xt << " " << ys + 1 << endl;
        }
    } else if (xt > xs && yt < ys) {
        if (yp > y) {
            cout << xs << " " << yt - 1 << endl;
            cout << xs + 1 << " " << yt << endl;
        } else {
            cout << xt - 1 << " " << ys << endl;
            cout << xt << " " << ys + 1 << endl;
        }
    } else if (xt < xs && yt > ys) {
        if (yp < y) {
            cout << xs << " " << yt - 1 << endl;
            cout << xs - 1 << " " << yt << endl;
        } else {
            cout << xt - 1 << " " << ys << endl;
            cout << xt << " " << ys + 1 << endl;
        }
    } else if (xt < xs && yt < ys) {
        if (yp > y) {
            cout << xs << " " << yt - 1 << endl;
            cout << xs - 1 << " " << yt << endl;
        } else {
            cout << xt + 1 << " " << ys << endl;
            cout << xt << " " << ys - 1 << endl;
        }
    }
}