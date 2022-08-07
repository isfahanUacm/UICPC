#include <iostream>
#include <vector>

using namespace std;
long minCal(long a, long b){
    if (a > b){
        return a;
    }
    return b;
}

long aroundArea (long tool, long arz) {
    return (tool * arz) - ((tool - 2) * (arz - 2));
}
bool cond1(long tool, long arz, long i){
    return ((tool - 1) % i == 0) &&  ((arz - 1) % i == 0);
}

bool cond2(long tool, long arz, long i){
    return ((tool - 2) % i == 0) &&  (arz % i == 0);
}

bool cond3(long tool, long arz, long i){
    return (tool % i == 0) &&  ((arz -2) % i == 0);
}

int main() {
    int rep;
    cin >> rep;

    for (int i = 0; i < rep; i++) {
        long tool, arz;
        cin >> tool >> arz;
        vector<long> vector;
        vector.push_back(1);

        long min = minCal(tool, arz);

        long area = aroundArea(tool, arz);

        for (long j = 2; j <= min; j++) {
            if (area % j != 0)
                continue;
            if (cond1(tool, arz, j) || cond2(tool, arz, j) || cond3(tool, arz, j)){
                vector.push_back(j);
            }
        }
        cout<< vector.size() << ' ';
        for (auto it = vector.begin(); it != vector.end(); ++it)
            cout << *it << ' ';

        cout << endl;
    }
    return 0;
}

