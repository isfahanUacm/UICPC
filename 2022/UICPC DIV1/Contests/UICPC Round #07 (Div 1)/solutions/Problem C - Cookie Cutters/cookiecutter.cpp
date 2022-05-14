#include <bits/stdc++.h>
using namespace std;

// Cookie Cutters

#define EPS 1e-8

struct point{
    double x, y;
    
    point() = default;
    
    point(double x, double y){
        this->x = x, this->y = y;
    }
	
	point& operator=(const point& o) = default; 
    
    bool operator==(const point& o) const{
        return fabs(this->x - o.x) < EPS && fabs(this->y - o.y) < EPS;
    }
    
    bool operator<(const point& o) const{
        if(fabs(this->x - o.x) < EPS)
            return this->y < o.y;
        return this->x < o.x;
    }

    double dist(const point& o){
        return hypot(this->x - o.x, this->y - o.y);
    }
};

struct polygon{
    vector<point> corners;

    void add(point p){
        corners.push_back(p);
    }

    double area(){
        int n = corners.size();
        double result = 0;
        for(int i = 0; i < n; i++){
            double x1 = corners[i].x, y1 = corners[i].y;
            double x2 = corners[(i + 1) % n].x, y2 = corners[(i + 1) % n].y;
            result += x1 * y2 - x2 * y1;
        }
        return fabs(result) / 2;
    }
};

int main(){
    int n;
    double x, y, A;
    polygon poly;
    cin >> n;
    while(n--)
        cin >> x >> y, poly.add(point(x, y));
    n = poly.corners.size();
    cin >> A;
    double scale = sqrt(A / poly.area());
    double minx = LLONG_MAX, miny = LLONG_MAX;
    for(int i = 0; i < n; i++){
        poly.corners[i].x *= scale, poly.corners[i].y *= scale;
        minx = min(minx, poly.corners[i].x), miny = min(miny, poly.corners[i].y);
    }
    for(int i = 0; i < n; i++)
        poly.corners[i].x -= minx, poly.corners[i].y -= miny;
    cout << fixed << setprecision(10);
    for(int i = 0; i < n; i++)
        cout << poly.corners[i].x << " " << poly.corners[i].y << endl;
}