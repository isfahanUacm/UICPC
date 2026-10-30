#include <iostream>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t > 0)
    {
        int n;
        cin >> n;
        int x, y;
        int counter1 = 0;
        int counter2 = 0;
        int counter3 = 0;
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
                counter3++;
            }
        }

        t--;
        cout << (counter1*counter2)+counter3*(counter1+counter2) << endl;
    }
}