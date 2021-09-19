#include <bits/stdc++.h>
using namespace std;

// Yet Satisfiability Again!

vector<int> split(const string& str, char delim){
    vector<int> cont;
    stringstream ss(str);
    string token;
    while(getline(ss, token, delim)){
        if(token.back() == ' ')
            token.pop_back();
        if(token.front() == ' ')
            token = token.substr(1);
        if(token.front() == '~')
            cont.push_back(-stoi(token.substr(2)));
        else
            cont.push_back(stoi(token.substr(1)));
    }
    return cont;
}

int t, n, m;
string s;
vector<int> clauses[103];

int main(){
    cin >> t;
    while(t--){
        cin >> n >> m, cin.ignore();
        for(int i = 0; i < m; i++)
            getline(cin, s), clauses[i] = split(s, 'v');
        bool found = 0;
        for(int mask = 0; mask < (1 << n); mask++){
            bool sat = 1;
            for(int i = 0; i < m; i++){
                bool ok = 0;
                for(int j : clauses[i]){
                    if(j > 0)
                        ok = ok || (mask & 1 << (j - 1));
                    else
                        ok = ok || !(mask & 1 << (-j - 1));
                }
                if(!ok){
                    sat = 0;
                    break;
                }
            }
            if(sat){
                cout << "satisfiable" << endl;
                found = 1;
                break;
            }
        }
        if(!found)
            cout << "unsatisfiable" << endl;
    }
}