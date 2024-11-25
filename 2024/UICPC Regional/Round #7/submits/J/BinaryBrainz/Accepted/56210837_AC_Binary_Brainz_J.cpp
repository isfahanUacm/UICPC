#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    int passengers = 0;

    for (int i = 0; i < n; i++) {
        char cmd;
        int num;

        cin >> cmd >> num;

        if (cmd == 'P') {
            passengers += num;
        }
        else {
        
            passengers -= num;
            if (passengers < 0) {
                cout << "YES";
                passengers = 0;
            }
            else cout << "NO";

            if (i != n - 1)
                cout << endl;
        }

    }



    return 0;
}