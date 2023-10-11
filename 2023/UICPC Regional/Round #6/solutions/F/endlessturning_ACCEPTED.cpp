// Solution to: Endless turning
// By: Raymond van Bommel

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <cctype>
#include <climits>
#include <cassert>

#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <list>
#include <set>
#include <map>
#include <string>

#include <iostream>
#include <sstream>

#include <utility>
#include <functional>
#include <limits>
#include <numeric>
#include <algorithm> 

using namespace std;

int R, cur, next1;
long long N;
double X, Y;

const double UB = 1E7+1;

string name[123];
double xline[123][2];
double yline[123][2];
double slope[123];
int nr[123];

struct punt {
	double x, y; int L; // intersection point (x,y) with line L
	punt (double _x, double _y, int _L) : x(_x), y(_y), L(_L) { }
	punt (void) { }
	bool operator<(const punt& rhs) const {
		if (abs(x - rhs.x) > 1E-6)
			return (x < rhs.x);
		return (y < rhs.y);
	}
};
punt ipts[123][123];

punt calcintersection(int i, int j) {
	double L1x1 = xline[i][0];
	double L1x2 = xline[i][1];	// First line is given by:
	double L1y1 = yline[i][0];	// (L1y2 - L1y1)*(x - L1x1) - (L1x2 - L1x1)*(y - L1y1) = 0
	double L1y2 = yline[i][1]; 
	double L2x1 = xline[j][0];
	double L2x2 = xline[j][1];	// Second line is given by:
	double L2y1 = yline[j][0];	// (L2y2 - L2y1)*(x - L2x1) - (L2x2 - L2x1)*(y - L2y2) = 0
	double L2y2 = yline[j][1];
	
	double c1x = L1y2 - L1y1;	// First line is given by:
	double c1y = L1x1 - L1x2;	// c1x*x + c1y*y + c1 = 0
	double c1 = L1x1*(L1y1 - L1y2) + L1y1*(L1x2 - L1x1);
	double c2x = L2y2 - L2y1;	// Second line is given by:
	double c2y = L2x1 - L2x2;	// c2x*x + c2y*y + c2 = 0
	double c2 = L2x1*(L2y1 - L2y2) + L2y1*(L2x2 - L2x1);
	double x,y;
	
	if (abs(c1y) > 1E-8)	// Set slopes.
		slope[i] = -c1x / c1y;
	else
		slope[i] = 1E12;	// This is about infinity.
	if (abs(c2y) > 1E-8)
		slope[j] = -c2x / c2y;
	else
		slope[j] = 1E12;
	
	assert(abs(c1x*L1x1 + c1y*L1y1 + c1) < 1E-7);
	assert(abs(c1x*L1x2 + c1y*L1y2 + c1) < 1E-7);	// Some sanity checks
	assert(abs(c2x*L2x1 + c2y*L2y1 + c2) < 1E-7);
	assert(abs(c2x*L2x2 + c2y*L2y2 + c2) < 1E-7);
		
	if (abs(c2x) > 1E-8) { // In case c2x is non-zero:
		double d = c1y - (c1x/c2x)*c2y;
		if (abs(d) < 1E-8)
			return punt(0,0,-1); // Lines are parallel
		y = (-c1 + c1x/c2x*c2) / d;
		x = (-c2 - c2y*y) / c2x;
	} else if (abs(c2y) > 1E-8) { // In case c2y is non-zero:
		double d = c1x - (c1y/c2y)*c2x;
		if (abs(d) < 1E-8)
			return punt(0,0,-1); // Lines are parallel
		x = (-c1 + c1y/c2y*c2) / d;
		y = (-c2 - c2x*x) / c2y;
	} else {
		assert(false); // Should not happen
	}
	assert( (abs(x) < UB) && (abs(y) < UB) );
	assert(abs(c1x*x + c1y*y + c1) < 1E-3); // Some sanity checks
	assert(abs(c2x*x + c2y*y + c2) < 1E-3); 
	
	return punt(x,y,0);
}

void findstartingpoint() {
	for (int i = 0; i < R; i++) {
		double Lx1 = xline[i][0];
		double Lx2 = xline[i][1];	// Line is given by:
		double Ly1 = yline[i][0];	// (Ly2 - Ly1)*(x - Lx1) - (Lx2 - Lx1)*(y - Ly1) = 0
		double Ly2 = yline[i][1]; 
		double cx = Ly2 - Ly1;	// Line is given by:
		double cy = Lx1 - Lx2;	// cx*x + cy*y + c = 0
		double c = Lx1*(Ly1 - Ly2) + Ly1*(Lx2 - Lx1);
		
		if (abs(cx*X + cy*Y + c) < 1E-8) {
			cur = i;
			punt P(X,Y,-1);
			for (int j = 0; j < nr[i]; j++) {
				if (P < ipts[i][j]) { // If starting point is in front, this will be
					next1 = ipts[i][j].L;	// the first intersection point we will see.
					return;
				}
			}
			next1 = -1; // If none is found, then grandma will leave the city immediately.
			return;
		}	
	}
	assert(false); // Should not happen.
}

int findindex(int i, int j) { // Find index of intersection point.
	for (int k = 0; k < nr[i]; k++)
		if (ipts[i][k].L == j)
			return k;
	assert(false); // Should not happen.
}


void doit() {
	cin >> R >> N >> X >> Y;
	
	for (int i = 0; i < R; i++) { // Read everything
		nr[i] = 0;
		cin >> name[i] >> xline[i][0] >> yline[i][0] >> xline[i][1] >> yline[i][1];
		assert( (abs(xline[i][0]) < UB) && (abs(yline[i][0]) < UB) && (abs(xline[i][1]) < UB) && (abs(yline[i][1])) < UB );
		for (int j = 0; j < i; j++) {
			punt t = calcintersection(i,j); // Calculate intersection points
			if (t.L == 0) {
				ipts[i][j] = punt(t.x, t.y, j);
				ipts[j][i] = punt(t.x, t.y, i);
				nr[i]++;
				nr[j]++;
			} else if (t.L == -1) {
				ipts[i][j] = punt(UB, UB, -1);
				ipts[j][i] = punt(UB, UB, -1);
			}
		}
		ipts[i][i] = punt(UB, UB, -1);
	}
	
	for (int i = 0; i < R; i++) { // Sort intersection points
		sort(ipts[i], ipts[i]+R);
	}
	
	findstartingpoint();
	int dir = 1;
	int firstline = cur;
	
	long long steps = 1;
	while (steps <= N) {
		if (next1 == -1) {
			cout << name[cur] << '\n';
			return;
		}
		if (next1 == firstline) 
			N = (N % steps) + steps;	// If first line is found, reduce modulo period.
		if (slope[cur] < slope[next1]) {
			dir *= -1;	// If the slope increases, the direction should be changed.
		}
		int k = findindex(next1, cur);
		assert(ipts[next1][k].L == cur);
		if ((k+dir < 0) || (k+dir >= nr[next1])) {
			cur = next1;	// We are leaving the city soon.
			next1 = -1;
		} else {
			int nextnext = ipts[next1][k+dir].L;
			cur = next1;
			next1 = nextnext;	
		}			
		steps++;
	}
	cout << name[cur] << "\n";
}

int main () {
	int T = 1;
	//cin >> T;
	for (int t = 1; t <= T; t++) {
		doit();
	}
	return 0;
}
