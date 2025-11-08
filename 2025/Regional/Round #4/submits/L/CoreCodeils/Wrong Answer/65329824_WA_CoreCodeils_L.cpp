#include <iostream>
#include <set>
#include <vector>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            for (int k = j + 1; k < n; k++) {

                set<int> s;
                s.insert(i + i + i);
                s.insert(i + i + j);
                s.insert(i + j + j);
                s.insert(j + j + j);
                s.insert(i + i + k);
                s.insert(i + k + k);
                s.insert(k + k + k);
                s.insert(k + k + j);
                s.insert(k + j + j);
                s.insert(k + j + i);

                if(s.size() == arr.size()) {

                    vector ss(s.begin(), s.end());
                    if(arr == ss)
                        cout << i << " " << j << " " << k << endl;
                }

            }

    return 0;
}
