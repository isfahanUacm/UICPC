#include <iostream>
#include <cassert>
#include <set>
#include <iomanip>

using namespace std;

const int MAX = 100;

int main()
{
	int N;
	double buildingArea[MAX], visibleArea[MAX];
	int x1[MAX], y1[MAX], x2[MAX], y2[MAX];
	
	cin >> N;
	assert(N >= 2 && N <= MAX);
	set<double> xcoords;
	xcoords.insert(0);
	xcoords.insert(10000);
	for(int i=0;i<N;i++) {
		cin >> x1[i] >> y1[i] >> x2[i] >> y2[i];
		assert(0 <= x1[i] && x1[i] < x2[i] && x2[i] <= 10000);
		assert(0 <= y1[i] && y1[i] <= 10000);
		assert(0 <= y2[i] && y2[i] <= 10000);

		xcoords.insert(x1[i]);
		xcoords.insert(x2[i]);		
		buildingArea[i] = (x2[i]-x1[i])*(y1[i]+y2[i]) / 2.0;
		visibleArea[i] = 0.0;
		int v1x = x2[i]-x1[i], v1y = y2[i]-y1[i];
		for(int j=0;j<i;j++) {			
			int vw0x = x1[j]-x1[i], vw0y = y1[j]-y1[i];
			int w1x = x1[j]-x2[j], w1y=y1[j]-y2[j];
			double d0 = v1x*w1y-v1y*w1x;
			if (d0 != 0) {
				double fa=vw0x*w1y-vw0y*w1x;
				double fb=v1x*vw0y-v1y*vw0x;
				if (d0<0) { d0=-d0; fa=-fa; fb=-fb; }  	
				if (fa>0 && fa<d0 && fb>0 && fb<d0)
			  		xcoords.insert(fa*v1x/d0+x1[i]);
			}
		}
	}
	
	double last=0.0;
	for(set<double>::iterator si=xcoords.begin();si!=xcoords.end();si++) {
		double current=*si;
		double covered=0.0;
		for(int i=0;i<N;i++) {
			if (x1[i] <= last && x2[i] >= current) {
				double slope = (double)(y2[i]-y1[i])/(x2[i]-x1[i]);
				double y3 = (last-x1[i])*slope+y1[i];
				double y4 = (current-x1[i])*slope+y1[i];
				double a = (current-last)*(y3+y4)/2.0;
				if (a - covered >= 0)
					visibleArea[i] += a - covered;
				if (a > covered)
					covered = a;
			}
		}
		last=current;
	}

	for(int i=0;i<N;i++)
		cout << setprecision(8) << visibleArea[i] / buildingArea[i] << endl;
	
	return 0;
}
