#include <bits/stdc++.h>
using namespace std;
typedef vector<bool> vb;
typedef vector<int> vi;
typedef vector<pair<int, int>> vii;
typedef pair<int, int> pii;
typedef vector<vector<int>> vvi;



int main() {
    int rep;
    cin >>rep;
    for (int i = 0; i < rep; ++i) {
        deque<int> myDeque;
        string cmd;
        cin >>cmd;
        int len;
        cin >>len;
        char tmp;
        cin >>tmp;
        for (int j = 0; j < len; ++j) {
            int a;
            cin >>a;
            myDeque.push_back(a);
            cin >>tmp;
        }
        bool r = false;
        bool err = false;
        for (int j = 0; j < cmd.size(); ++j) {
            if (cmd[j] == 'R'){
                r = !r;
            } else {
                if (myDeque.empty()){
                    err = true;
                    break;
                }
                if (r){
                    myDeque.pop_back();
                } else {
                    myDeque.pop_front();
                }
            }
        }
        if (err){
            cout <<"error" <<endl;
            continue;
        }
        cout << '[';
        bool f = true;
        for (auto b : myDeque) {
            if (f) {
                cout << b;
                f = false;
            } else {
                cout << "," << b;
            }
        }
        cout << ']'<< endl;
    }
    return 0;
}

