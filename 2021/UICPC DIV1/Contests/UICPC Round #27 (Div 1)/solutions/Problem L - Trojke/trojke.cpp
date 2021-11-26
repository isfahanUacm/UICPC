#include <bits/stdc++.h>
using namespace std;

// Trojke

#define EPS 1e-8

struct point{
    double x, y;
    
    point() = default;
    
    point(double x, double y){
        this->x = x, this->y = y;
    }
};

#define INF LLONG_MAX

struct line{
    double m, b;
	
	line() = default;
    
    line(point& p1, point& p2){
        if(fabs(p1.x - p2.x) < EPS)
            m = INF, b = p1.x;
        else if(fabs(p1.y - p2.y) < EPS)
            m = 0, b = p1.y;
        else{
            m = (p1.y - p2.y) / (p1.x - p2.x);
            b = p1.y - m * p1.x;
        }
    }

    bool parallel(const line& o) const{
        return fabs(this->m - o.m) < EPS;
    }

    bool operator==(const line& o) const{
        return parallel(o) && (fabs(this->b - o.b) < EPS);
    }
};

vector<point> points;
int n;
char c;

int main(){
    cin >> n;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++){
            cin >> c;
            if(c != '.')
                points.push_back(point(i, j));
        }
    n = points.size();
    int ans = 0;
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            for(int k = j + 1; k < n; k++){
                line l1(points[i], points[j]), l2(points[i], points[k]), l3(points[j], points[k]);
                if(l1 == l2 && l1 == l3 && l2 == l3)
                    ans++;
            }
    cout << ans << endl;
}