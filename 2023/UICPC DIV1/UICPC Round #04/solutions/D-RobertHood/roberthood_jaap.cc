/*
 * Solution for NCPC 2013 problem "Archery" by Jaap Eldering
 * Complexity: O(n log(n)) using convex hull algorithm.
 */

#include <cmath>
#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long coord;

class point {
public:
	coord x, y;

	point() { x = y = 0; }
	point(coord x1, coord y1) { x = x1; y = y1; }

	point operator +=(point a) { x += a.x; y += a.y; return *this; }
	point operator -=(point a) { x -= a.x; y -= a.y; return *this; }
};

int   operator <(point a, point b) { return a.x < b.x; }

point operator +(point a, point b) { return a += b; }
point operator -(point a, point b) { return a -= b; }
coord operator *(point a, point b) { return a.x*b.x + a.y*b.y; }

coord cross(point a, point b) { return a.x*b.y - a.y*b.x; }
coord lensqr(point a) { return a*a; }

vector<point> convexhull(vector<point> points)
{
	vector<point> upper, lower;

	// sort points on x-coordinate:
	sort(points.begin(),points.end());

	// build upper and lower part of convex hull:
	upper.push_back(points[0]);
	lower.push_back(points[0]);
	for(int i=1; i<points.size(); i++) {
		while ( upper.size()>=2 &&
		        cross(upper.back()-upper[upper.size()-2],
		              points[i]   -upper[upper.size()-2])>=0 ) upper.pop_back();
		upper.push_back(points[i]);
		while ( lower.size()>=2 &&
		        cross(lower.back()-lower[lower.size()-2],
		              points[i]   -lower[lower.size()-2])<=0 ) lower.pop_back();
		lower.push_back(points[i]);
	}

	// append lower part in reversed order to upper:
	for(int i=lower.size()-2; i>0; i--) upper.push_back(lower[i]);

	return upper;
}

int main()
{
	int nshots;
	cin >> nshots;

	if ( nshots<0 ) return -1;

	if ( nshots<2 ) {
		cout << -1 << endl;
		return 0;
	}

	vector<point> shots(nshots);
	for(int i=0; i<nshots; i++) cin >> shots[i].x >> shots[i].y;

	vector<point> hull = convexhull(shots);

// 	cerr << hull.size() << endl;
// 	for(int i=0; i<hull.size(); i++) cerr << hull[i].x << " " << hull[i].y << endl;

	coord best = 0;

	int j = 1;
	int n = hull.size();
	for(int i=0; i<n; i++) {
		while ( lensqr(hull[j]-hull[i])>lensqr(hull[j]-hull[(i+1)%n]) ) {
			best = max(best,lensqr(hull[j]-hull[i]));
			j = (j+1)%n;
		}
	}

    cout.precision(10);
	cout << sqrt(best) << endl;

	return 0;
}
