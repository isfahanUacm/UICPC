#include <bits/stdc++.h>
#include <string>
#include <cstring>
using namespace std;
int main() {
    string name;
    string output,out_2;
    cin>>name;
    vector<string > outputs;

    for (int i = 0; i < name.length(); ++i) {
        if(name[i]=='S'&&name[i+1]=='S')
        {
            output = string();
            for(int j = 0 ; j < name.length() ;j++) {
                if(j==i){
                    output += 'B';
                    j++;
                }
                else {
                    output += name[j] + ('a' - 'A');
                    }
                }
            outputs.push_back(output);

        }
        out_2 += name[i] + ('a' - 'A');
    }

    cout << out_2 << endl;
    for(auto &i : outputs) {

        cout << i ;
        if (i != outputs.back())
            cout << endl;

    }

    return 0;
}
