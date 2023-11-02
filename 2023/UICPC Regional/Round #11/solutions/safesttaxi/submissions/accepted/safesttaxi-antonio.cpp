#include <vector>
#include <tuple>
#include <set>
#include <string>
#include <iostream>
#include <cassert>
#include <cstring>
using namespace std;
#define pb push_back
#define sz(a) ((int)((a).size()))

const int N=15;
int n,m,K;
bool isval(int x,int y) { return 0<=x && x<n && 0<=y && y<m; }
int readlane() {
	string s; cin>>s;
	if(s=="L") return 1;
	if(s=="S") return 2;
	if(s=="LS") return 3;
	if(s=="R") return 4;
	if(s=="LR") return 5;
	if(s=="SR") return 6;
	if(s=="LSR") return 7;
	assert(0);
}
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
void readdir(int &x,int &y,int &k) {
	int xx,yy;
	cin>>x>>y>>xx>>yy;
	assert(isval(x,y));
	assert(isval(xx,yy));
	assert(abs(x-xx)+abs(y-yy)==1);
	for(k=0;k<4;k++) if(xx==x+dx[k] && yy==y+dy[k]) return;
	assert(0);
}
vector<int> lns[N][N][4];
int tt[N][N][4];

struct state {
	int x,y,k,l,lts,chs;
};

#define idx(s) s.x][s.y][s.k][s.l][s.lts][s.chs
#define i2(s) s.x][s.y][s.k
int dijk(const state &src,int tx,int ty,int tk) {
	static int D[N][N][4][3][5][5];
	const int MX=15*15*4*3*100;
	vector<state> pq[MX+1];
	for(int d=0;d<=MX;d++) pq[d].clear();
	pq[0].pb(src);
	memset(D,-1,sizeof D);
	D[idx(src)]=0;
	auto tryins=[&](const state &u,int d) {
		int &dd=D[idx(u)];
		if(~dd && dd<=d) return;
		dd=d;
		pq[d].pb(u);
	};
	for(int d=0;d<=MX;d++) {
		for(int i=0;i<sz(pq[d]);i++) {
			state u=pq[d][i];
			if(D[idx(u)]!=d) continue;
			if(u.x==tx && u.y==ty && u.k==tk && u.l==sz(lns[i2(u)])-1) return d;
			if(u.chs && u.l) --u.chs, --u.l, tryins(u,d), ++u.chs, ++u.l;
			if(u.chs && u.l<sz(lns[i2(u)])-1) --u.chs, ++u.l, tryins(u,d), ++u.chs, --u.l;
			int dd=d+tt[i2(u)];
			vector<int> &ls=lns[i2(u)];
			u.x+=dx[u.k];
			u.y+=dy[u.k];
			int svuk=u.k;
			int svul=u.l;
			for(int I:{1,2,4}) if(ls[u.l]&I) {
					if(I==1 && !u.lts) continue;
					if(I==1) --u.lts;
					if(I==1) u.k+=1;
					if(I==4) u.k+=3;
					u.k&=3;
					int lo=0,hi=0;
					for(int l_=0;l_<u.l;l_++) if(ls[l_]&I) ++lo;
					for(int l_=u.l;++l_<sz(ls);) if(ls[l_]&I) ++hi;

					int lef=0,rig=sz(lns[i2(u)])-1;
					if(I==4) { rig-=hi; if(lo) lef=rig; }
					else { lef+=lo; if(hi) rig=lef; }
					for(u.l=lef;u.l<=rig;u.l++) tryins(u,dd);

					u.k=svuk;
					u.l=svul;
					if(I==1) ++u.lts;
				}
			u.x-=dx[u.k];
			u.y-=dy[u.k];
		}
	}
	return -1;
}




int main() { /* CURSOR START */
	int s; cin>>n>>m>>K>>s;
	assert(2<=n && n<=15);
	assert(2<=m && m<=15);
	assert(s==2*((n-1)*m+(m-1)*n));
	set<tuple<int,int,int>> _sn;
	for(;s--;) {
		int x,y,k,t,ct;
		readdir(x,y,k);
		cin>>t;
                ct=K;
		assert(!_sn.count({x,y,k}));
		_sn.insert({x,y,k});
		assert(2<=t &&  t<=100);
		assert(t%2==0);
		assert(1<=ct && ct<=3);
		tt[x][y][k]=t;
		for(;ct--;) {
			int lane=readlane();
			lns[x][y][k].pb(lane);
			if(lane&1) assert(isval(x+dx[k]+dx[(k+1)&3],y+dy[k]+dy[(k+1)&3]));
			if(lane&2) assert(isval(x+dx[k]+dx[(k+0)&3],y+dy[k]+dy[(k+0)&3]));
			if(lane&4) assert(isval(x+dx[k]+dx[(k+3)&3],y+dy[k]+dy[(k+3)&3]));
		}
		for(int i:{1,2,4}) for(int j:{1,2,4}) if(i<j) for(int ii=0;ii<sz(lns[x][y][k]);ii++) for(int jj=0;jj<ii;jj++) {
							int X=lns[x][y][k][ii];
							int Y=lns[x][y][k][jj];
//					if((X&i)&&(Y&j)) dbg(x,y,x+dx[k],y+dy[k]);
							assert(!((X&i) && (Y&j)));
						}
	}
	for(int x=0;x<n;x++) for(int y=0;y<m;y++) for(int k=0;k<4;k++) if(sz(lns[x][y][k])) {
					for(int i:{1,2,4}) {
						int kk=k;
						if(i==1) kk+=1;
						if(i==4) kk+=3;
						kk&=3;
						int ct=0;
						for(int l:lns[x][y][k]) if(l&i) ++ct;
						assert(sz(lns[x+dx[k]][y+dy[k]][kk])>=ct);
					}
				}

	int q; cin>>q;
	assert(1<=q && q<=50);
	for(;q--;) {
		int x,y,k; readdir(x,y,k);
		int tx,ty,tk; readdir(tx,ty,tk);
		int X,Y; cin>>X>>Y;
		assert(0<=X && X<=4);
		assert(0<=Y && Y<=4);
		state src{x,y,k,sz(lns[x][y][k])-1,X,Y};
		int ans=dijk(src,tx,ty,tk);
		if(~ans) cout<<ans+tt[tx][ty][tk]/2-tt[x][y][k]/2<<endl;
		else cout<<-1<<endl;
	}
}



