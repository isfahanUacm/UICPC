#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
struct point{
    int x, y;
    point(){
        x = y = 0;
    }
};
struct vec{
    int x, y;
    vec(int _x, int _y){
        x = _x;
        y= _y;
    }
};

vec toVec(point a, point b) {
    return vec(b.x - a.x, b.y - a.y);
}

int n;
point p[1003];

double area(bool& cw){
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < n; i++) {
        x1 = p[i].x; x2 = p[(i+1)%n].x;
        y1 = p[i].y; y2 = p[(i+1)%n].y;
        result += (x1 * y2 - x2 * y1);
    }
    cw = result < 0;
    return fabs(result) / 2.0;
}

int main()
{
    while(cin>>n && n){
        for (int i = 0; i < n; ++i) {
            cin>>p[i].x>>p[i].y;
        }
        bool flag;
        double a = area(flag);
        cout<<((flag)?"CW":"CCW")<<" ";
        printf("%.1lf\n", a);
    }
    return 0;
}

