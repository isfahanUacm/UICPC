#include <iostream>
#include <vector>
#include <cassert>
#include <algorithm>
using namespace std;
template <class T> int size(const T &x) { return x.size(); }
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef long long ll;
const int INF = 2147483647;

struct big_integer {
    vector<char> d;
    void clean() {
        while (!d.empty() && d.back() == 0) {
            d.pop_back();
        }
    }
    big_integer(string s) {
        for (int i = size(s)-1; i >= 0; i--) {
            d.push_back(s[i] - '0');
        }
        clean();
    }
    big_integer(vector<char> _d) : d(_d) {
        clean();
    }
    bool operator <(const big_integer &other) const {
        if (size(d) != size(other.d)) {
            return size(d) < size(other.d);
        }
        for (int i = size(d)-1; i >= 0; i--) {
            if (d[i] != other.d[i]) {
                return d[i] < other.d[i];
            }
        }
        return false;
    }
    bool operator <=(const big_integer &other) const {
        return !(other < *this);
    }
    big_integer operator -(const big_integer &other) {
        // NOTE: This assumes that other <= *this. This will always be the case in our main algorithm.
        assert(size(d) >= size(other.d));

        vector<char> res;
        int carry = 0;
        for (int i = 0; i < size(d); i++) {
            int here = d[i] - carry;
            carry = 0;
            if (i < size(other.d)) {
                here -= other.d[i];
            }
            if (here < 0) {
                here += 10;
                carry = 1;
            }
            res.push_back(here);
        }
        assert(carry == 0);
        return big_integer(res);
    }
};

big_integer read_big_integer() {
    string s;
    cin >> s;
    return big_integer(s);
}

bool cmp(const pair<string,big_integer> &a, const pair<string,big_integer> &b) {
    return a.second < b.second;
}

int main() {
    int n;
    cin >> n;
    big_integer s = read_big_integer();

    vector<pair<string, big_integer> > arr;
    for (int i = 0; i < n; i++) {
        string name;
        cin >> name;
        arr.push_back(make_pair(name, read_big_integer()));
    }

    sort(arr.rbegin(), arr.rend(), cmp);

    vector<string> res;
    for (int i = 0; i < n; i++) {
        if (arr[i].second <= s) {
            s = s - arr[i].second;
            res.push_back(arr[i].first);
        }
    }

    if (s.d.empty()) {
        cout << size(res) << endl;
        for (int i = 0; i < size(res); i++) {
            cout << res[i] << endl;
        }
    } else {
        cout << 0 << endl;
    }

    return 0;
}

