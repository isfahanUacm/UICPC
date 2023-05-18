// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9 + 7;

int main() {
    stack<int> num;
    stack<char> op;
    int n, a, b;
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


//int n; cin >> n;
//int k, m;
//for (int x = 1; x<=n; x++) {
//    k = (x*x - n)/(2*x);
//    m = x - k;
//    if (k <=0 || m <=0) continue;


//    if (m*m - k*k == n) {
//        cout << m << " " << k << '\n';
//        return 0;
//    }
//}
//cout << "impossible" << '\n';

return 0;
}

