#include <iostream>
using namespace std;

int main() {
    string s;
    cin>>s;
    char w[s.length()];
    for (int i = 0; i < s.length(); ++i) {
        w[i] = s.at(i);
    }
    if(s.length()%2 == 0)
        cout<<":)";
    else
        cout<<w[(s.length()/2)];
    return 0;
}