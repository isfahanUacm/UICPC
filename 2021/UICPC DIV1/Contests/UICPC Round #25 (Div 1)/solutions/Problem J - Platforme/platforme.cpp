#include <iostream>
#include <algorithm>
using namespace std;
#define MAX_N 103
struct line{
    int y, x1, x2;
    line(){
        x1 = x2 = y = 0;
    }
    line(int _y, int _x1, int _x2){
        x1 = _x1;
        y = _y;
        x2 = _x2;
    }
    bool operator < (line other) const{
        return y<other.y;
    }
};
int n;
line L[MAX_N];
int flr[10003];
int main()
{
    cin>>n;
    for (int i = 0; i < n; ++i) {
        cin>>L[i].y>>L[i].x1>>L[i].x2;
        L[i].x2--;
    }
    sort(L, L+n);
    int res = 0;
    for (int i = 0; i < n; ++i) {
        res += 2 * L[i].y - flr[L[i].x1] - flr[L[i].x2];
        for (int j = L[i].x1; j <= L[i].x2; ++j) {
            flr[j] = L[i].y;
        }
    }
    cout<<res<<endl;
    return 0;
}

