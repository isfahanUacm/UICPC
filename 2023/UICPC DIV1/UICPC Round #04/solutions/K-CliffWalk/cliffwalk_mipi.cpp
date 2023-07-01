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
#define LD long double
#define VI vector<int>

#define Cell pair<int,int>
#define Interval pair<LD,LD>

#define MAX 500
#define INF (LD)1000*1000

LD pi=(LD)2.0*acosl(0);

LD height[MAX][MAX];
LD flood[MAX][MAX];
LD deflood[MAX][MAX];
LD a,m;
int X,Y,W,H;
vector<pair<int,int> > dir;

vector<pair<Cell,Interval > > graph[MAX][MAX];
vector<pair<Cell,Interval > > graph_rev[MAX][MAX];

LD vis[MAX][MAX];
LD vis_rev[MAX][MAX];

LD flooding_time(LD h){
	if (h>a) return (LD)-1000.0;
	return ((LD)6.0/pi)*acosl(((LD)2.0*h)/a - (LD)1.0);
}

pair<int,Interval > try_arc(Cell a, Cell b){
	if (fabsl(height[a.F][a.S]-height[b.F][b.S])>(LD)1.0) return MP(1,MP(0.0,0.0));
	LD lower=max(flood[a.F][a.S]+(LD)1.0,flood[b.F][b.S]+(LD)1.0);
	LD upper=min(deflood[a.F][a.S]-m,deflood[b.F][b.S]-m);
	if (lower>upper) return MP(1,MP(0.0,0.0)); else return MP(0,MP(lower,upper));
}

void compute_flood(){
	REP(i,H+1) REP(j,W+1){
		vis[i][j]=INF;
		vis_rev[i][j]=-INF;
		flood[i][j]=flooding_time(height[i][j]);
		deflood[i][j]=(LD)12.0 - flood[i][j];
	}
}

void build_graph(){
	FOR(i,1,H) FOR(j,1,W) REP(t,4){
		pair<int,Interval> q=try_arc(MP(i,j),MP(i+dir[t].F,j+dir[t].S));
		if (q.F) continue;
		graph[i][j].PB(MP(MP(i+dir[t].F,j+dir[t].S),q.S));
		graph_rev[i+dir[t].F][j+dir[t].S].PB(MP(MP(i,j),q.S));
	}
}

priority_queue<pair<LD,Cell > > q;

void dijkstra(){
	q=priority_queue<pair<LD,Cell > >();
	q.push(MP(0.0,MP(X,Y)));
	while(!q.empty()){
		pair<LD,Cell > event = q.top(); q.pop();
		LD t=-event.F;
		int x=event.S.F, y=event.S.S;
	//	printf("%d %d %Lf %Lf\n",x,y,t,vis[x][y]);
		if (vis[x][y]<=t) continue;
		vis[x][y]=t;
		REP(k,graph[x][y].size()){
			int xp=graph[x][y][k].F.F;
			int yp=graph[x][y][k].F.S;
			if (vis[xp][yp]<INF-(LD)1.0) continue;
			LD lower=graph[x][y][k].S.F;
			LD upper=graph[x][y][k].S.S;
			if (t>upper) continue;
			LD reach_time=max(t,lower)+m;
			q.push(MP(-reach_time,MP(xp,yp)));
		}
	}
}

void dijkstra_rev(){
	q=priority_queue<pair<LD,Cell > >();
	q.push(MP(12.0,MP(X,Y)));
	while(!q.empty()){
		pair<LD,Cell > event = q.top(); q.pop();
		LD t=event.F;
		int x=event.S.F, y=event.S.S;
		if (vis_rev[x][y]>=t) continue;
		vis_rev[x][y]=t;
		REP(k,graph_rev[x][y].size()){
			int xp=graph_rev[x][y][k].F.F;
			int yp=graph_rev[x][y][k].F.S;
			if (vis_rev[xp][yp]>-INF+(LD)1.0) continue;
			LD lower=graph_rev[x][y][k].S.F;
			LD upper=graph_rev[x][y][k].S.S;
			if (t<lower) continue;
			LD reach_time=min(t,upper)-m;
			q.push(MP(reach_time,MP(xp,yp)));
		}
	}
}

LL get_best(){
	LL best=0;
	FOR(i,1,H) FOR(j,1,W){
		if (vis[i][j]<=vis_rev[i][j]){
			LL c=(i-X)*(i-X)+(j-Y)*(j-Y);
			if (best<c) best=c;
		}
	}
	return best;	
}

int main(){
	dir.PB(MP(-1,0));
	dir.PB(MP(1,0));
	dir.PB(MP(0,-1));
	dir.PB(MP(0,1));
	scanf("%Lf%Lf",&a,&m); m/=(LD)3600.0;
	scanf("%d%d%d%d",&W,&H,&Y,&X); X++; Y++;
	REP(i,H+2) height[i][0]=height[i][W+1]=0.0;
	REP(j,W+2) height[0][j]=height[H+1][j]=0.0;
	FOR(i,1,H) FOR(j,1,W){
		LD h;
		scanf("%Lf",&h); h/=(LD)1000;
		height[i][j]=h;
	}
	compute_flood();
//	printf("====================\n");
/*	FOR(i,1,H){ FOR(j,1,W){
		printf("(%Lf %Lf) ",flood[i][j],deflood[i][j]);
	} printf("\n");}*/
	build_graph();
//	printf("====================\n");
/*	FOR(i,1,H){ FOR(j,1,W){
		printf("%d ",graph[i][j].size());
	} printf("\n");}*/
	dijkstra();
//	printf("====================\n");
	dijkstra_rev();
//	printf("====================\n");
/*	FOR(i,1,H){ FOR(j,1,W){
		printf("(%Lf %Lf) ",vis[i][j],vis_rev[i][j]);
	} printf("\n");}*/
	LL r=get_best();
	printf("%.10Lf\n",(LD)10.0*sqrtl((LD)r));
	return 0;
}

