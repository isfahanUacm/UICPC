// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;

const long long int mod = 1e9 + 7;

int main() {

    stack<long long> num;
    stack<char> op;
    long long n, a, b;
    cin >> n;
    char c2;
    string temp, c;
    char ch = '+';
    for(int i = 0; i < n; ++i) {
    cin >> c;
    if(!(c[0] == '(' || c[0] == ')')) {
        num.push(stoi(c));
        op.push(ch);


    }
    else if(c[0] == '(') {
        op.push('(');
        if (ch == '+') ch = '*';
        else ch = '+';
    }
    else {


        while (c[0] != '(') {
            c2 = op.top();
            op.pop();
            c = op.top();
            op.pop();
            op.push(c2);
            if (c[0] == '(')
                break;
            a = num.top();
            num.pop();
            b = num.top();
            num.pop();

            if (ch == '+')
                num.push((a + b) % mod);
            else
                num.push((a * b) % mod);


        }
        if (ch == '+') ch = '*';
        else ch = '+';


    }
    }
    while (op.size() != 1)
    {
    a = num.top();
    num.pop();
    b = num.top();
    num.pop();
    c2 = op.top();
    op.pop();
    c = op.top();
    op.pop();
    op.push(c2);
    if (ch == '+')
        num.push((a + b) % mod);
    else
        num.push((a * b) % mod);
    }

    cout << num.top();

return 0;
}
