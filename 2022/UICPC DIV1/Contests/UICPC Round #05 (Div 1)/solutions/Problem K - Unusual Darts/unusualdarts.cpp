#include <bits/stdc++.h>
using namespace std;
#define EPS 1e-9
#define EPS2 1e-5
struct point{
    double x, y;
    point(){
        x = y = 0;
    }
    point(double _x, double _y){
        x = _x;
        y = _y;
    }
    bool operator < (point other) const {
        if (fabs(x - other.x) > EPS)
            return x < other.x;
        return y < other.y;
    } 
    bool operator ==(point other){
        return fabs(x - other.x)<EPS && fabs(y - other.y)<EPS;
    }
};

struct line{
    double a, b, c;
    point p1, p2;
    line(){
        a = b = c = 0;
    }
    line(double _a, double _b, double _c){
        a = _a;
        b = _b;
        c = _c;
    }
};
struct vec { 
    double x, y; 
    vec(double _x, double _y) : x(_x), y(_y) {} 
};

vec toVec(point a, point b){ 
    return vec(b.x - a.x, b.y - a.y); 
}

double cross(vec a, vec b){
    return a.x * b.y - a.y * b.x; 
}
bool ccw(point p, point q, point r) {
    return cross(toVec(p, q), toVec(p, r)) > 0;
}


void pToL(point p1, point p2, line &l) {
    if (fabs(p1.x - p2.x) < EPS){
        l.a = 1.0; l.b = 0.0; l.c = -p1.x;
    }
    else{
        l.a = -(double)(p1.y - p2.y) / (p1.x - p2.x);
        l.b = 1.0;
        l.c = -(double)(l.a * p1.x) - p1.y;
    } 
    l.p1 = p1;
    l.p2 = p2;
}

bool RParall(line l1, line l2) {
    return (fabs(l1.a-l2.a) < EPS) && (fabs(l1.b-l2.b) < EPS); 
}

bool RIntersect(line l1, line l2, point &p) {
    if (RParall(l1, l2))
        return false;
    p.x = (l2.b * l1.c - l1.b * l2.c) / (l2.a * l1.b - l1.a * l2.b);
    if (fabs(l1.b) > EPS)
        p.y = -(l1.a * p.x + l1.c);
    else
        p.y = -(l2.a * p.x + l2.c);
    p.x = p.x;
    p.y = p.y;
    return true;
}

int arr[7] = {0, 1, 2, 3, 4, 5, 6};
point p[10];
line L[10];
int n;
double prob;
string res;
bool mosavi(int i, int j, point inP){
    return ((inP == L[i].p1 && inP == L[j].p2) || (inP == L[i].p1 && inP == L[j].p1) || (inP == L[i].p2 && inP == L[j].p2) || (inP == L[i].p2 && inP == L[j].p1));
}
double area() {
    double result = 0.0, x1, y1, x2, y2;
    for (int i = 0; i < 7; i++) {
        x1 = p[arr[i]].x; x2 = p[arr[(i+1)%7]].x;
        y1 = p[arr[i]].y; y2 = p[arr[(i+1)%7]].y;
        result += (x1 * y2 - x2 * y1);
    }
    return fabs(result) / 2.0;
}

int main()
{
    cin>>n;
    while(n--){
        for (int i = 0; i < 7; ++i) {
            cin>>p[i].x>>p[i].y;
        }
        cin>>prob;
        sort(arr, arr+7);
        do {
            for (int i = 0; i < 7; ++i) {
                pToL(p[arr[i]], p[arr[(i+1)%7]], L[i]);
            }
            bool inters = false;
            point intersP;
            for (int i = 0; i < 7; ++i) {
                for (int j = 0; j < 7; ++j) {
                    if(i==j)continue;
                    if(RParall(L[i], L[j]))
                        continue;
                    RIntersect(L[i], L[j], intersP);
                    double dist = hypot(fabs(L[i].p1.x-L[i].p2.x), fabs(L[i].p1.y-L[i].p2.y));
                    if(!mosavi(i, j, intersP) && fabs((hypot(fabs(intersP.x-L[i].p1.x), fabs(intersP.y-L[i].p1.y)) + hypot(fabs(intersP.x-L[i].p2.x), fabs(intersP.y-L[i].p2.y))) - dist)<EPS && (ccw(L[i].p1, L[i].p2, L[j].p1)^ccw(L[i].p1, L[i].p2, L[j].p2))){
                        inters = true;
                        break;
                    }   
                }
                if(inters)
                    break;
            }
            if(!inters){
                double a = area()/4;
                if(fabs((a*a*a)-prob)<EPS2){
                    break;
                }
            }
        } while (next_permutation(arr, arr+7));
        for (int i = 0; i < 7; ++i) {
            cout<<arr[i]+1<<((i==6)?"\n":" ");
        }
    }
    return 0;
}

