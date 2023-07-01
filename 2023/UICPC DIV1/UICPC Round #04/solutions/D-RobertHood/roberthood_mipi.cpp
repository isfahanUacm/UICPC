#include <cstdio>
#include <climits>
#include <cstdlib>
#include <cassert>
#include <cmath>
#include <cctype>
#include <cerrno>
#include <algorithm>
#include <list>
#include <queue>
#include <map>
#include <vector>
#include <set>

using namespace std;
    
#define REP(i,n) for(int _n=(n),i=0; i<_n; ++i)
#define FOR(i,a,b) for(int _b=(b),i=(a); i<=_b; ++i)
#define FORD(i,a,b) for(int _b=(b),i=(a); i>=_b; --i)
#define FORE(i,a)  for(VAR(i,a.begin()); i!=a.end(); ++i)

#define PB push_back
#define BEG begin()
#define END end()
#define SZ size()
#define MP make_pair
#define F first
#define S second
#define D double
#define LL long long
#define VI vector<int>


#define MAX 2000*1000

struct Point{
	LL x;
	LL y;

	Point(LL xx,LL yy){ x=xx; y=yy; }
	Point(const Point& b){ x=b.x; y=b.y; }
	Point(){ }
	bool operator==(const Point& b) const {return (x==b.x && y==b.y);}
	bool operator<(const Point& b) const {return x==b.x ? y<b.y : x<b.x;}

	LL dist(Point& A){ return (x-A.x)*(x-A.x)+(y-A.y)*(y-A.y);}

	LL ldist(Point& A, Point& B){
		return -(x-A.x)*(B.y-A.y)+(y-A.y)*(B.x-A.x);
	} 
};


/* Convex hull from library */
#define Det(p1,p2,w) ((LL)(p2.x-p1.x)*(LL)(w.y-p1.y)-(LL)(p2.y-p1.y)*(LL)(w.x-p1.x))

#define XCAL {while(w.size()>m && Det((w[w.size()-2]), (w[w.size()-1]), (s[x]))<=0) w.pop_back(); w.PB(s[x]);}
void ConvexHull(vector<Point>& p, vector<Point>& w) {
	vector<Point> s=p;
	sort(s.begin(),s.end());
	int m=1;
	REP(x,s.size()) XCAL
	m=w.size();
	FORD(x,s.size()-2,0) XCAL
	w.pop_back();
}

#define CHK(a) {if (best<hull[p].dist(hull[a])) best=hull[p].dist(hull[a]);}
#define CH {CHK(i) CHK(((i+1)%m))}
LL do_stuff(vector<Point>& hull){
	int m=hull.size();
	int p=1;
	LL best=-1;
	REP(i,m){
		CH
		while (hull[p].ldist(hull[i],hull[(i+1)%m])<hull[(p+1)%m].ldist(hull[i],hull[(i+1)%m])) {
			p=(p+1)%m;
			CH
		}
	}
	return best;
}

int main(){
	int n;
	scanf("%d",&n);
	if (n==1) {printf("-1\n"); return 0;}
	vector<Point> input;
	REP(i,n){
		LL a,b;
		scanf("%lld%lld",&a,&b);
		input.PB(Point(a,b));
	}
	vector<Point> hull;
	ConvexHull(input,hull);
//	printf("TUT\n");
	LL ret=do_stuff(hull);
	printf("%.9Lf\n",sqrtl(ret));
	return 0;
}

