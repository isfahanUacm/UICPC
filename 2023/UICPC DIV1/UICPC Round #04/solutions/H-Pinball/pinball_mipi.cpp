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

#define RU 0
#define RD 1
#define LD 2
#define LU 3
#define LEFT 0
#define RIGHT 1

#define MAX 2000*1000

struct Point{
	LL x;
	LL y;

	Point(LL xx,LL yy){ x=xx; y=yy; }
	Point(const Point& b){ x=b.x; y=b.y; }
	Point(){ }
};

struct Interval{
	Point l;
	Point r;
	int type;
	int ind;

        bool between(const Point& b) const{
		return ((l.x<=b.x)&&(b.x<=r.x));
        }

        bool below(const Point& b) const{
		return ((r.x-l.x)*(b.y-l.y)-(r.y-l.y)*(b.x-l.x))<0;
        }

        bool operator==(const Interval& b) const{ return ind==b.ind; }

	bool operator<(const Interval& b) const{
		if (ind==b.ind) return false;
		if (between(b.l))
			return (below(b.l));
                
                if (b.between(l))
			return (!b.below(l));
                
		assert(false);
		return (ind<b.ind); //This should not happen!
	}

   
	Interval(int i, const Point& A1, const Point& A2){
		ind=i;	
	        if (A1.x<=A2.x){ l=A1; r=A2; } else { l=A2; r=A1; }
		if (l.y<r.y) type=LEFT; else type=RIGHT;
	}
};

struct Event{
	LL x;
	int num;
	int type;

	bool operator<(const Event& e) const{
		if (x!=e.x) return (x<e.x); else return (type>e.type);
	}

        Event(const Interval& src, int side){
		num=src.ind;
		if (side==LEFT) x=src.l.x; else x=src.r.x;
		if ((src.type==LEFT) && (side==LEFT)) type=LD;
		if ((src.type==RIGHT) && (side==LEFT)) type=LU;
		if ((src.type==LEFT) && (side==RIGHT)) type=RU;
		if ((src.type==RIGHT) && (side==RIGHT)) type=RD;
	}
};

vector<Interval> input;
set<Interval> sweep;
vector<Event> events;
vector<int> succ;
int n;

void read_input(){
	scanf("%d",&n);
	REP(i,n){
		LL x1,y1,x2,y2;
		scanf("%lld%lld%lld%lld",&x1,&y1,&x2,&y2);
		Interval in=Interval(i,Point(x1,y1),Point(x2,y2));
		input.PB(in);
		events.PB(Event(in,LEFT));
		events.PB(Event(in,RIGHT));
	}
	LL x;
	scanf("%lld",&x);
	
	Interval in=Interval(n,Point(x-1,MAX+1),Point(x,MAX));
	input.PB(in);
	events.PB(Event(in,LEFT));
	events.PB(Event(in,RIGHT));
	
	sort(events.begin(),events.end());
	succ=vector<int>(n+1,-2);
}

void do_sweep(){
	REP(i,events.size()){
		Event e=events[i];
		if (e.type==LU){
			/* left upper corner: just add to the sweep */
			sweep.insert(input[e.num]);
		}
		if (e.type==RU){
			/* right upper corner: just remove from the sweep */
			sweep.erase(input[e.num]);
		}
		if (e.type==LD){
			/* left down corner: add to the sweep and compute successor */
			sweep.insert(input[e.num]);
			set<Interval>::iterator it=sweep.find(input[e.num]); it++;
			if (it==sweep.end()) succ[e.num]=-1; else succ[e.num]=(it)->ind;
		}
		if (e.type==RD){
			/* right down corner: compute successor and remove from the sweep */
			set<Interval>::iterator it=sweep.find(input[e.num]); it++;
			if (it==sweep.end()) succ[e.num]=-1; else succ[e.num]=(it)->ind;
			sweep.erase(input[e.num]);
		}
	}
}

void compute_result(){
	REP(i,n+1) assert(succ[i]>=-1);
	int q=n;
	LL resx;
	while (succ[q]>=0) q=succ[q];
	if (input[q].type==LEFT) resx=input[q].l.x; else resx=input[q].r.x;
	printf("%lld\n",resx);
}

int main(){
	read_input();
	do_sweep();
	compute_result();
	return 0;
}

