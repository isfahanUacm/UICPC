#include <iostream>
#include <set>
#include <vector>


using namespace std;

typedef long long ll;
typedef unsigned long long ull;

#define endl "\n";

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);


    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];


    for (int i = 0; i < 1001; i++)
        for (int j = i + 1; j < 1001; j++) {
            vector<set<int> > sets(n);

            bool array[n];
            for (int i0 = 0; i0 < n; i0++)
                array[i0] = false;
            int temp = 0;
            for (int x = 0; x < n; x++) {
                if (arr[x] == i + i + i || arr[x] == i + i + j || arr[x] == i + j + j || arr[x] == j + j + j) {
                    array[x] = true;
                    temp++;
                    continue;
                }

                sets[x].insert(arr[x] - i - i);
                if ((arr[x] - i) % 2 == 0)
                    sets[x].insert((arr[x] - i) / 2);
                if (arr[x] % 3 == 0)
                    sets[x].insert(arr[x] / 3);
                if ((arr[x] - j) % 2 == 0)
                    sets[x].insert((arr[x] - j) / 2);

                sets[x].insert(arr[x] - j - j);
                sets[x].insert(arr[x] - j - i);
            }

            if (temp == n) {
                cout << i << " " << j << " " << j + 1 << endl;
                return 0;
            }
            set<int> s;

            for (int x = 0; x < n; x++) {
                if (!array[x])
                    s = sets[x];
            }
            if (s.empty())
                continue;

            for (int x = 0; x < n; x++) {
                if (sets[x].size() < s.size() && !array[x])
                    s = sets[x];
            }


            for (int x: s) {
                if (x <= j)
                    continue;
                int tmp = 0;
                for (int k = 0; k < n; k++) {
                    if (sets[k].contains(x) || array[k])
                        tmp++;
                    else
                        break;
                }
                if (tmp == n) {
                    cout << i << " " << j << " " << x << endl;
                    return 0;
                }
            }
        }

    return 0;
}
