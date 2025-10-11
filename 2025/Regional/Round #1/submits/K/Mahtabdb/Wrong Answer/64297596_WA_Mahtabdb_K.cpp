#include <iostream>
using namespace std;

int main() {
    freopen("cubes.in", "r", stdin);
    int N, T;
    cin >> T;

  
    int allN[1000];      
    int arr[1000][100];  

    for (int t = 0; t < T; t++) {
        cin >> N;
        allN[t] = N;
        for (int i = 0; i < N; i++) {
            cin >> arr[t][i];
        }
    }
    for (int t = 0; t < T; t++) {
        N = allN[t];

        cout << "Case " << t + 1 << ":\n";

    
        for (int i = (N % 2 == 0 ? N : N - 1); i >= 2; i -= 2) {
            cout << i << " ";
        }

    
        for (int i = 1; i <= N; i += 2) {
            cout << i << " ";
        }
        cout << endl;
    }

    return 0;
}
