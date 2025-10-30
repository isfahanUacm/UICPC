#include <bits/stdc++.h>
using namespace std;

vector<char> shift(vector<char> &c) {
    int size = c.size();
    c.push_back('0');
    for (int i = size; i >= 0; i--) {
        c[i + 1] = c[i];
    }
    return c;
}

int main() {
    string s1;
    string s2;
    string s3;
    cin >> s1 >> s2 >> s3;
    vector<char> v1;
    vector<char> v2;
    vector<char> v3;
    int counter = s1.length();
    for (int i = 0; i < s1.length(); i++) {
        v1.push_back(s1[i]);
    }
    for (int i = 0; i < s2.length(); i++) {
        if (s2[i] == '1') {
            counter++;
        }
        v2.push_back(s2[i]);
    }
    for (int i = 0; i < s3.length(); i++) {
        v3.push_back(s3[i]);
    }
    vector<char> result;
    int i = 0;
    while (result.size() < counter) {
        if (v1[i] == v2[i]) {
            shift(v3);
            result.push_back(v1[i]);
        } else if (v2[i] == v3[i]) {
            shift(v1);
            result.push_back(v2[i]);
        } else if (v3[i] == v1[i]) {
            shift(v2);
            result.push_back(v3[i]);
        }
        i++;
    }
    for (int i = 0; i < result.size(); i++) {
        cout << result[i];
    }


    return 0;
}
