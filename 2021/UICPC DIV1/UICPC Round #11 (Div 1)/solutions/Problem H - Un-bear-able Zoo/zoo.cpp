#include <bits/stdc++.h>
using namespace std;

// Un-bear-able Zoo

int n;
string line, x;
map<string, int> zoo;

string lastone(){
    stringstream ss(line);
    string x;
    while(ss >> x);
    return x;
}

int main(){
    int t = 1;
    while(1){
        cin >> n;
        if(!n)
            break;
        cin.ignore();
        zoo.clear();
        while(n--)
            getline(cin, line), x = lastone(), for_each(x.begin(), x.end(), [](char & c){c = tolower(c);}), zoo[x]++;
        cout << "List " << t++ << ":" << endl;
        for(pair<string, int> anim : zoo)
            cout << anim.first << " | " << anim.second << endl; 
    }
}