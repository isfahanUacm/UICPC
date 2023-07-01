/*
 * Solution for NCPC 2013 problem "Cliff walk" by Jaap Eldering
 * Complexity: O( w*h*log(w*h) )
 */

#include <cassert>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

typedef vector<int> VI;
typedef vector<VI>  VVI;

typedef vector<double> VD;
typedef vector<VD>     VVD;
typedef vector<VVD>    VVVD;

const int dx[4] = {1,0,-1,0};
const int dy[4] = {0,1,0,-1};

const int maxdz = 1000;
const double sqsize = 10.0;

const double eps = 2E-4;

double a, m, a0, m0;
int w,h,xs,ys;
VVI height;
VVVD reach;

double dry(int z)
{
	if ( z>=a ) return -2;
	return acos(2*z/a-1)*6/M_PI;
}

struct pos {
	int x,y;
	double t;

	pos() {}
	pos(int x_, int y_, double t_): x(x_), y(y_), t(t_) {}
};

int operator <(pos a, pos b) { return a.t>b.t; }

void finddist(pos start, int dir)
{
	priority_queue<pos> que;
	que.push(start);

	while ( !que.empty() ) {
		pos curr = que.top(); que.pop();
		if ( curr.t*m>12.0 ) break;
		if ( reach[curr.x][curr.y][dir]<=curr.t ) continue;
		reach[curr.x][curr.y][dir] = curr.t;
//		printf("reach %d,%d at %.4lf (dir=%d)\n",curr.x,curr.y,curr.t,dir);

		for(int d=0; d<4; d++) {
			pos next = curr;
			next.x += dx[d];
			next.y += dy[d];
			if ( next.x<0 || next.x>=w ||
			     next.y<0 || next.y>=h ||
			     abs(height[curr.x][curr.y]-
			         height[next.x][next.y])>maxdz ) continue;

			double t = dry(height[next.x][next.y]);
			if ( dir==0 ) t += 1;
			if ( t>next.t ) next.t = t;
			next.t += m;
			if ( dir==1 && next.t>12-(t+1) ) continue;
//			printf("next %d,%d at %.4lf (dir=%d)\n",next.x,next.y,next.t,dir);
			que.push(next);
		}
	}

}

int main()
{
	cin >> a0 >> m0;
	cin >> w >> h >> xs >> ys;

	height = VVI(w,VI(h));
	for(int y=0; y<h; y++)
		for(int x=0; x<w; x++) cin >> height[x][y];


	int best;
	// use mm for height, hours for time:
	a = a0 * 1000;
	m = m0 / 3600;

	reach = VVVD(w,VVD(h,VD(2,99.9)));

	for(int dir=0; dir<2; dir++) finddist(pos(xs,ys,0.0),dir);

	for(int y=0; y<h; y++) {
		for(int x=0; x<w; x++) {
			int d2 = (x-xs)*(x-xs) + (y-ys)*(y-ys);
			if ( reach[x][y][0]+reach[x][y][1]<=12.0 && d2>best ) {
// 				fprintf(stderr,"found best %d at %d,%d, t_f = %.3lf, t_b = %.3lf\n",
// 				        d2,x,y,reach[x][y][0],12-reach[x][y][1]);
				best = d2;
			}
		}
	}

	cout << setprecision(12) << sqsize*sqrt(best) << endl;

	return 0;
}
