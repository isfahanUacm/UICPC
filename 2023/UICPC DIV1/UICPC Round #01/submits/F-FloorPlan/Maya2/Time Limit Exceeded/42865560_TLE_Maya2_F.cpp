// C++ program using memoization
#include <bits/stdc++.h>
using namespace std;

int main() {
//    stack<int> num;
//    stack<char> op;
//    int n, a, b;
//    cin >> n;
//    char c, c2;
//    stirng temp
//    char ch = '+';
//    for(int i = 0; i < n; ++i) {
//        cin >> c;
//        if(!(c == '(' || c == ')')) {
//            num.push(c - '0');
//            op.push(ch);


//        }
//        else if(c == '(') {
//            op.push('(');
//            if (ch == '+') ch = '*';
//            else ch = '+';
//        }
//        else {
//            if (ch == '+') ch = '*';
//            else ch = '+';

//            while (c != '(') {
//                c2 = op.top();
//                op.pop();
//                c = op.top();
//                op.pop();
//                op.push(c2);
//                if (c == '(')
//                    break;
//                a = num.top();
//                num.pop();
//                b = num.top();
//                num.pop();

//                if (c == '+')
//                    num.push(a + b);
//                else
//                    num.push(a * b);

//            }

//        }
//    }
//    while (op.size() != 1)
//    {
//        a = num.top();
//        num.pop();
//        b = num.top();
//        num.pop();
//        c2 = op.top();
//        op.pop();
//        c = op.top();
//        op.pop();
//        op.push(c2);
//        if (c == '+')
//            num.push(a + b);
//        else
//            num.push(a * b);
//    }

//    cout << num.top();


long long n; cin >> n;
long long k, m;
for (long long x = 1; x<=n; x++) {
    k = (x*x - n)/(2*x);
    m = x - k;
    if (k <0 || m <0) continue;


    if (m*m - k*k == n) {
        cout << m << " " << k << '\n';
        return 0;
    }
}
cout << "impossible" << '\n';

return 0;
}
