#include <bits/stdc++.h>
using namespace std;

int main() {
    long int t ;
    cin >> t;

    for (int i = 0 ; i < t ; i++){
        map<long int,long int> sizes;

        for (int j = 0;j<2;j++  ){
            long int s;
            cin >> s;

            sizes[s] = 1;
        }

        if(sizes.size() > 1)
            cout << "Rectangle\n";
        else cout << "Square\n";
    }



    return 0;
}
