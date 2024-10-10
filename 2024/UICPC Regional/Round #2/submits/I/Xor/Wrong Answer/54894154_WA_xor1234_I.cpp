#include <iostream>
#include <bitset>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        int arr[n];
        int max = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int x = arr[i] ^ arr[j];
                string binary = std::bitset<8>(x).to_string();
                int count = 0;

                for (int k = 0; k < binary.size(); k++)
                    if (binary[k] == '1')
                        count++;
                if (count>max) max = count;
            }
        }
        cout<<max<<endl;
    }
}