#include <iostream>
using namespace std;

int main() {
freopen("cubes.in", "r", stdin);
    int T;
    cin >> T;

    int N[1000];       
    int arr[1000][100]; 

  
    for (int t = 0; t < T; t++) {
        cin >> N[t];
        for (int i = 0; i < N[t]; i++) {
            cin >> arr[t][i];
        }
    }

  
    for (int t = 0; t < T; t++) {
        cout << "Case " << t + 1 << ":\n";

        int n = N[t];
        for (int i = (n % 2 == 0 ? n : n - 1); i >= 2; i -= 2) {
            cout << i << " ";
        }

       
        for (int i = 1; i <= n; i += 2) {
            cout << i << " ";
        }

        cout << endl;
    }

    return 0;
}
