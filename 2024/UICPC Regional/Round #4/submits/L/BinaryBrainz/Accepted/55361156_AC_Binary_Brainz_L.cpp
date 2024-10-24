#include <bits/stdc++.h>
using namespace std;
int main() {
    string entry;
    cin>>entry;

    int p = 0;
    vector<string> ps;
    string crnt = string();

    for (int i = 0; i < entry.length(); ++i) {
        if(entry[i] == '('){
            crnt += '(';
            p++;
        }
        else {
            crnt+=')';
            p--;

            if(p==0){
                ps.push_back(crnt);
                crnt = string();
            }
        }
    }

    crnt = ps[0];
    for(vector<string>::iterator i = ps.begin();i!= ps.end();i++){
        if( *i != crnt){
            for(vector<string>::iterator j = i;j != ps.end();j++){
                cout << *j;
            }
            for(vector<string>::iterator j = ps.begin();j != i;j++){
                cout << *j;
            }
            return 0;
        }

    }

    cout << "no";


    return 0;
}
