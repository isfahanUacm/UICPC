#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < q; i++)
    {
        int operation, l, r, x;
        cin >> operation;
        if (operation == 1)
        {
            cin >> l >> r >> x;
            for(int j=l-1; j<r; j++){
                a[j] = a[j]%x;
            }
        }
        else if(operation == 2){
            cin >> l >> r >> x;
            for(int j=l-1; j<r; j++){
                a[j] = max(a[j], x);
            }
        }
        else
        {
            cin >> l >> r;
            int sum = 0;
            for(int k=l-1; k<r; k++){
                sum += a[k];
            }
            cout << sum << endl;
        }
    }
}