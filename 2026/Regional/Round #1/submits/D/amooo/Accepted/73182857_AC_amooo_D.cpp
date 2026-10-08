#include <iostream>
using namespace std;

int main() {
    int n, s;
    char d;

    cin >> n >> s >> d;

    int read[20] = {0};
    int a = 0, b = 0, c = 0;
    int aSpot = 1;
    int bSpot = s;
    int cSpot = n;
    int step = 1;

    if (d == 'L') {
        step = -1;
    }
    bool ra = true;
    bool rb = true;
    bool rc = true;
    while (ra|| rb|| rc) {
        if (ra && (aSpot < 1||  aSpot > n|| read[aSpot] == 1)) {
            ra = false;
        }
        if (rb && (bSpot  < 1 ||bSpot  > n || read[bSpot ] == 1)) {
            rb = false;
        }
        if (rc && (cSpot  < 1 || cSpot  > n|| read[cSpot ] == 1)) {
            rc = false;
        }
        if (ra) {
            a++;
        }
        if (rb) {
            b++;
        }
        if (rc) {
            c++;
        }
        if (ra)
            read [aSpot] = 1;
        if (rb)
            read [bSpot ] = 1;
        if (rc)
            read [cSpot ] = 1;

        aSpot = aSpot  + 1;
        bSpot  = bSpot  + step;
        cSpot  = cSpot  - 1;
    }
    cout << a << " " << b << " " << c << endl;
    return 0;
}