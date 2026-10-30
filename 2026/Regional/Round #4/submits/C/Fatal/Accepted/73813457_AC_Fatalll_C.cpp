#include <iostream>
using namespace std;
int main()
{
    long long t;
    cin >> t;
    while (t > 0)
    {
        long long n;
        cin >> n;
        long long x, y;
        long long counter1 = 0;
        long long counter2 = 0;
        long long counter3 = 0;
        long long n2 = n-1;
        for (int i = 0; i < n; i++)
        {
            cin >> x >> y;
            if(x>y){
                counter1++;
            }
            else if(x<y){
                counter2++;
            }
            else{
                counter3+=n2;
                n2--;
            }
        }

        t--;
        cout << (counter1*counter2)+counter3 << endl;
    }
}