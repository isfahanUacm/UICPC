#include <iostream>
#include <fstream>
using namespace std;


#define endl "\n"

int main() {
    freopen("mahdi.in", "r", stdin);
    int t;
    cin >> t;

    for (int i = 1; i <= t; i++) {
        cout << "Case " << i << ":";
        cout << endl;
        char c;
        cin >> c;
        int n,mult,add;
        cin >> n >> mult >> add;
        char cs[n];
        cs[0] = c;
        for (int j = 1; j < n; j++)
            cs[j] = char(((cs[j - 1] - 'a') * mult + j * add) % 26 + 'a');


        int t2;
        cin >> t2;
        for (int j = 0; j < t2; j++) {
            char c2;
            cin >> c2;
            int n2,mult2,add2;
            cin >> n2 >> mult2 >> add2;
            char cs2[n2];
            cs2[0] = c2;
            for (int k = 1; k < n2; k++)
                cs2[k] = char(((cs2[k - 1] - 'a') * mult2 + k * add2) % 26 + 'a');
            int index = 0;
            int k = 0;
            for (; k < n2 && index < n; k++)
                for (;index < n; index++) {
                    if (cs[index] == cs2[k])
                        break;


                }
            if (k == n2)
                cout << "BRAVO" << (i == t && j == t2 - 1 ? "" : endl);
            else
                cout << "REPEAT" << (i == t && j == t2 - 1 ? "" : endl);

        }
    }
    return 0;
}
