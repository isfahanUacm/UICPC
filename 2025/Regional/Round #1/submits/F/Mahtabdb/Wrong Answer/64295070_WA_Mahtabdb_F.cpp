#include <iostream>
using namespace std;

long long sumSquares(long long n) {
   

    return n * (n + 1) * (2 * n + 1) / 6;
}

int main() {
    freopen("army.in", "r", stdin);
    int T;
    cin >> T;

    for (int test = 1; test <= T; test++) {
        long long N;
        cin >> N;

        long long left = 1;
        long long right = 2000000000; 
        long long answer = -1;

        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long total = sumSquares(mid);

            if (total >= N) {
                answer = mid;  
                right = mid - 1; 
            }
            else {
                left = mid + 1;
            }
        }

        cout << "Case " << test << ": " << answer << endl;
    }

    return 0;
}
