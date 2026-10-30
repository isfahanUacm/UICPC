
#include <iostream>
using namespace std;

int main()
{
    int t;
    cin >> t;

    for (int i = 0; i < t; i++) {
        long long n;
        cin >> n;

        int count = 0;
        bool arr = false;

        for (int j = 0; j < n; j++)
        {
            long long a;
            cin >> a;

            if (a == 1) {
                arr = false;
            }
            else
            {
                if (!arr)
                {
                    count++;
                }

                arr = true;
            }
        }

        cout << count << endl;
    }

    return 0;
}
