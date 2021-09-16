#include <bits/stdc++.h>
using namespace std;

unordered_set<string> s;
int n; string a, last;

int main()
{
    cin>>n;
    bool turn = false;
    cin>>last;s.insert(last);
    for (int i = 1; i < n; ++i) {
        cin>>a;
        if(s.find(a)!=s.end() || last[last.length()-1]!=a[0]){
            cout<<"Player "<<((turn)?1:2)<<" lost"<<endl;
            return 0;
        }
        last = a;
        s.insert(last);
        turn = !turn;
    }
    cout<<"Fair Game"<<endl;
    return 0;
}

