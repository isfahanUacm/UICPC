#include <bits/stdc++.h>

#define ll long long int
using namespace std;

int main() {
    ll n;
    cin >> n;
    string str;
    string x1 = "))";
    string x2 = ")+1)";
    string y1 = "()";
    string y2 = "(1)";
    string z1 = ")(";
    string z2 = ")*(";

    cin >> str;

    size_t pos = 0;
    while ((pos = str.find(x1, pos)) != string::npos) {
        str.replace(pos, x1.length(), x2);
        pos += x2.length() - 1;
    }

    pos = 0;
    while ((pos = str.find(y1, pos)) != string::npos) {
        str.replace(pos, y1.length(), y2);
        pos += y2.length();
    }

    pos = 0;
    while ((pos = str.find(z1, pos)) != string::npos) {
        str.replace(pos, z1.length(), z2);
        pos += z2.length();
    }

    string inp = str;
    string result;
    stack<char> st;

    for (char c: inp) {
        if (isalpha(c)) {
            result.push_back(c);
        } else if (c == '(') {
            st.push(c);
        } else if (c == ')') {
            while (!st.empty() && st.top() != '(') {
                result.push_back(st.top());
                st.pop();
            }
            if (!st.empty()) st.pop();
        } else {
            int prec = (c == '+' || c == '-') ? 1 : 2;
            while (!st.empty()) {
                char top = st.top();
                if (top == '(') break;
                int topPrec = (top == '+' || top == '-') ? 1 : 2;
                if (topPrec < prec) break;
                result.push_back(top);
                st.pop();
            }
            st.push(c);
        }
    }

    while (!st.empty()) {
        result.push_back(st.top());
        st.pop();
    }

    string sent = result;

    stack<int> stk;
    for (char c: sent) {
        if (isdigit(c)) {
            stk.push(c - '0');
        } else {
            int b = stk.top();
            stk.pop();
            int a = stk.top();
            stk.pop();
            int res = 0;
            switch (c) {
                case '+':
                    res = a + b;
                    break;
                case '-':
                    res = a - b;
                    break;
                case '*':
                    res = a * b;
                    break;
                case '/':
                    res = a / b;
                    break;
                default:
                    break;
            }
            stk.push(res);
        }
    }

    if (!stk.empty()) cout << stk.top();
}