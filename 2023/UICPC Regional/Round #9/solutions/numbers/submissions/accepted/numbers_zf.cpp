#include <iostream>
#include <string>

using namespace std;

string solve() {
    string s;
    cin >> s;

    if (s.length() == 1 || s == "22") return s;


    for (int i = 0, cnt = 0; i <= s.length(); ++i) {
        if ((i == s.length() || s[i] > '2') && cnt&2) s.insert(i, "2");
        else if ((i == s.length() || s[i] > '4') && cnt&4) s.insert(i, "4");
        cnt += s[i]-'0';
    }

    int tot = 0;
    for (int i = 0; i < s.length(); ++i) tot += s[i]-'0';
    while (tot&(tot-1)) {
        tot += 8;
        s += "8";
    }

    return s;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << endl;
    }

    return 0;
}
