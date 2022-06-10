#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
struct point{
    double x, y;
    point(){x=y=0;}
    point(double _x, double _y){x=_x;y=_y;}
};

struct vec{
    double x, y;
    vec(){x=y=0;}
    vec(double _x, double _y){
        x = _x;
        y = _y;
    }
    vec(point p1, point p2){
        x = p2.x - p1.x;
        y = p2.y - p1.y;
    }
};

double dot(vec a, vec b){
    return a.x * b.x + a.y * b.y;
}

double norm_sq(vec a){
    return a.x * a.x + a.y * a.y;
}

vec scale(vec v, double u){
    return vec(v.x * u, v.y * u);
}

point trans(point p, vec v){
    return point(p.x + v.x, p.y+v.y);
}

double cross(vec a, vec b){
    return a.x * b.y - a.y * b.x;
}

bool col(point a, point b, point p){
    return fabs(cross(vec(a, b), vec(a, p))) < EPS;
}

double dist(point p, point a, point b){
    if(col(a, b, p))
        return 0.0;
    double u = dot(vec(a, p), vec(a, b)) / norm_sq(vec(a, b));
    point c = trans(a, scale(vec(a, b), u));
    return hypot(p.x-c.x, p.y-c.y);
}

int n, m;
int xx1, yy1, xx2, yy2, a, b;
string name;
vector<string> res;


int main()
{
    cin>>n;
    while(n--){
        cin>>xx1>>yy1>>xx2>>yy2;
        point A(xx1, yy1), B(xx2, yy2);
        cin>>m;
        double dis = 1e5;
        for (int i = 0; i < m; ++i) {
            cin>>name>>a>>b;
            point city(a, b);
            double d = dist(city, A, B);
            if(fabs(d-dis)<EPS){
                res.push_back(name);
            }
            else if(d<dis){
                dis = d;
                res.clear();
                res.push_back(name);
            }
        }
        for (int i = 0; i < res.size(); ++i) {
            cout<<res[i]<<((i==res.size()-1)?"\n":" ");
        }
    }
    return 0;
}

