#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        int n, q;
        cin >> n >> q;
        vector<int> arr(n);
        vector<int> com(q);
        for (int i = 0; i < n; i++)
            cin >> arr[i];
        for (int j = 0; j < q; j++)
            cin >> com[j];
        for (int i = 0; i < q; i++)
        {
            int command = com[i];
            for (int j = 0; j < command / 2; j++)
            {
                arr.erase(arr.begin() + j);
            }
            int end_of_reverse = command / 2;
            reverse(arr.begin(), arr.begin() + end_of_reverse);
        }
        for (int i = 0; i < arr.size(); i++)
            cout << arr[i] << " ";
        cout << endl;
    }

    return 0;
}