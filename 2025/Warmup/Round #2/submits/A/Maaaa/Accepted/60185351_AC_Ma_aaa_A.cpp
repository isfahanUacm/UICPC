#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--)
    {
        int n, c;
        cin >> n >> c;
        int c1 = c;
        int count = 1;
        for (int i=0; i<n; i++) {
            int tmp;
            cin >> tmp;
            c1 -= tmp;
            if (c1 <= 0) {
                count++;
                c1 = c;
            }
        }
        cout << count << endl;
    }
    


    return 0;
}