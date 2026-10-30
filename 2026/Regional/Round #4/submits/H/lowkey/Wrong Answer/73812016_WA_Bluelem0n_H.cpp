
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
        bool ghablibrabar = false;
        int ghbl = 0;
        //int* array = new int[n];
        for (int j = 0;  j< n; j++)
        {
            
            long long a;
            cin >> a;
            int i = 0;
            //while (a == 1) {

            //}
            if (a == 1) {
                arr = false;
                if (ghablibrabar)
                {
                    ghablibrabar = false;
                    count--;
                }
                
            }
            else
            {
          
                if (!arr)
                {
                    count+=2;
                    ghablibrabar = true;
                }
                else
                {
                    if (ghablibrabar) {
                        if (a !=ghbl)
                        {
                            ghablibrabar = false;
                        }
                        else {
                            ghablibrabar = true;
                        }
                    }
                }
                
                arr = true;
            }
           
            //cout << ghbl << " " << a << " " << ghablibrabar << " " << count<<endl;
            ghbl = a;
        }
        cout << count << endl;
        //if (extra==0)
        //{
        //    cout << 0 << endl;
        //}
        //else if (extra == 1) {
        //    cout << 1 <<endl;
        //}
        //else
        //{
        //    cout << 2<< endl;
        //}
    }
}

