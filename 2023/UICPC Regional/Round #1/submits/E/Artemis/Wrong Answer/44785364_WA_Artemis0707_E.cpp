#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string reg;
    cin >> reg;
    vector<string> tokens;
    string temp;
    string ri, le;
    bool seen_first_star = false;
    bool has_star = false;

    for (char i : reg) {
        if (i == '*') {
            has_star = true;
            if (!seen_first_star) {
                seen_first_star = true;
                temp = "";
            }
            else {
                if (temp.length() != 0) {
                    tokens.push_back(temp);
                }
                temp = "";
            }
        }
        else {
            temp += i;
        }

        if (!seen_first_star) {
            ri += i;
        }
    }

    for (int i = reg.length() - 1; i >= 0; --i) {
        char ch = reg[i];
        if (ch == '*') {
            break;
        }
        else {
            temp += ch;
        }

        le += ch;
    }

    int n;
    cin >> n;

    for (int i = 0; i < n; ++i) {
        string a;
        cin >> a;
        string ah = a;

        if (!has_star) {
            if (a == reg) {
                cout << a << endl;
            }
            continue;
        }

        bool possible = true;
        int last_ind = 0;
        if (ri.length() != 0) {
            if (a.length() < ri.length()) {
                possible = false;
            }
            else {
                for (int j = 0; j < ri.length(); ++j) {
                    if (a[j] != ri[j]) {
                        possible = false;
                        break;
                    }
                }
                a = a.substr(ri.length());
            }
        }

        if (le.length() != 0) {
            if (a.length() < le.length()) {
                possible = false;
            }
            else {
                for (int j = 0; j < le.length(); ++j) {
                    if (a[a.length() - 1 - j] != le[le.length() - 1 - j]) {
                        possible = false;
                        break;
                    }
                }
                a = a.substr(0, a.length() - le.length() + 1);
            }
        }


        for (int j = 0; j < tokens.size(); j++) {
            string x = tokens[j];

            int ind = a.find(x, last_ind);

            if (ind == string::npos) {
                possible = false;
                break;
            }
            last_ind = ind + 1;
        }

        if (possible) {
            cout << ah << endl;
        }
    }
}


