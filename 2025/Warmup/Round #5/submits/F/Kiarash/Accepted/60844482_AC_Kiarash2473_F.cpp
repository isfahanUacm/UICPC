#include <bits/stdc++.h>

using namespace std;

#define ll long long int
#define ld long double
#define all(x) x.begin(), x.end()

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int arr[4];
    cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
    sort(arr, arr + 4);
    if (arr[3] < arr[2] + arr[1] || arr[2] < arr[1] + arr[0])
        cout << "TRIANGLE" << endl;
    else if (arr[3] == arr[2] + arr[1] || arr[2] == arr[1] + arr[0])
        cout << "SEGMENT" << endl;
    else
        cout << "IMPOSSIBLE" << endl;

    return 0;
}