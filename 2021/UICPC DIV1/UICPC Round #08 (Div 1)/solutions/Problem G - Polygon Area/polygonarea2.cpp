#include <bits/stdc++.h>
using namespace std;

// Polygon Area

struct point{
    int x, y;
    
    point() = default;
    
    point(int x, int y){
        this->x = x, this->y = y;
    }
	
	point& operator=(const point& o) = default; 
};


struct polygon{
    vector<point> corners;

    void add(point p){
        corners.push_back(p);
    }

    int area(){
        int n = corners.size();
        int result = 0;
        for(int i = 0; i < n; i++){
            int x1 = corners[i].x, y1 = corners[i].y;
            int x2 = corners[(i + 1) % n].x, y2 = corners[(i + 1) % n].y;
            result += x1 * y2 - x2 * y1;
        }
        return result;
    }
};


int main(){
    cout << fixed << setprecision(1);
    int n;
    while(1){
        cin >> n;
        if(!n)
            break;
        int x, y;
        polygon poly;
        while(n--)
            cin >> x >> y, poly.add(point(x, y));
        int ans = poly.area();
        if(ans > 0)
            cout << "CCW ";
        else
            cout << "CW ", ans *= -1;
        if(ans % 2)
            cout << ans / 2 << ".5" << endl;
        else
            cout << ans / 2 << ".0" << endl;
    }    
}