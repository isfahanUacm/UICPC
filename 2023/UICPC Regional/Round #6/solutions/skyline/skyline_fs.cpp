#include <algorithm>
#include <stdio.h>
using namespace std;

const double eps = 1e-9;

struct building
{
	int x1, y1, x2, y2;
} buildings[100];
int N;

double xs[100*100];
double yleft[100*100];
double yright[100*100];
int numX;

double Crossing(const building& b1, const building& b2) // Returns x, < -1 if no crossing
{
	if(b1.x2 <= b2.x1 || b2.x2 <= b1.x1)
		return -2;
	// Do they cross
	int x1 = max(b1.x1, b2.x1);
	int x2 = min(b1.x2, b2.x2);
	double y11 = (x1-b1.x1)/(double)(b1.x2-b1.x1) * (b1.y2-b1.y1) + b1.y1;
	double y12 = (x2-b1.x1)/(double)(b1.x2-b1.x1) * (b1.y2-b1.y1) + b1.y1;
	double y21 = (x1-b2.x1)/(double)(b2.x2-b2.x1) * (b2.y2-b2.y1) + b2.y1;
	double y22 = (x2-b2.x1)/(double)(b2.x2-b2.x1) * (b2.y2-b2.y1) + b2.y1;
	if(y11 >= y21 - eps && y12 >= y22 - eps)
		return -2;
	if(y11 - eps <= y21 && y12 - eps <= y22)
		return -2;

	// Find x of the crossing
	int f1 = b1.y2 - b1.y1;
	int g1 = b1.x1 - b1.x2;
	double h1 = f1*b1.x1 + g1*b1.y1;
	int f2 = b2.y2 - b2.y1;
	int g2 = b2.x1 - b2.x2;
	double h2 = f2*b2.x1 + g2*b2.y1;
	double det = f1*(double)g2 - f2*(double)g1;
	double x = (g2*h1 - g1*h2)/det;
	return x;
}

double AreaBelow(double x1, double y1, double x2, double y2)
{
	double area = (y1 + y2) * (x2 - x1) * 0.5;
	return area;
}

int main()
{
	scanf("%d", &N);
	for (int i = 0; i < N; ++i)
	{
		scanf("%d %d %d %d", &buildings[i].x1, &buildings[i].y1, &buildings[i].x2, &buildings[i].y2);
		xs[numX] = buildings[i].x1;
		yleft[numX] = 0;
		yright[numX] = 0;
		++numX;
		xs[numX] = buildings[i].x2;
		yleft[numX] = 0;
		yright[numX] = 0;
		++numX;
	}

	// Cross each line with each other, store the x-values
	for (int i = 0; i < N; ++i)
	{
		for (int j = i+1; j < N; ++j)
		{
			double x = Crossing(buildings[i], buildings[j]);
			if(x > -1)
			{
				xs[numX] = x;
				yleft[numX] = 0;
				yright[numX] = 0;
				++numX;
			}
		}
	}
	sort(xs, xs+numX);
	numX = unique(xs, xs+numX) - xs;

	for (int i = 0; i < N; ++i)
	{
		building &b = buildings[i];
		double ownArea = AreaBelow(b.x1, b.y1, b.x2, b.y2);
		double visibleArea = 0;

		int ifirst = find(xs, xs+numX, (double)b.x1) - xs;
		int ilast = find(&xs[ifirst+1], xs+numX, (double)b.x2) - xs;
		double ycur = (xs[ifirst]-b.x1)/(b.x2-b.x1) * (b.y2-b.y1) + b.y1;
		double ynext;
		for(int icur = ifirst; icur != ilast; ++icur, ycur = ynext)
		{
			int inext = icur+1;
			double xcur = xs[icur];
			double xnext = xs[icur+1];
			ynext = (xnext-b.x1)/(b.x2-b.x1) * (b.y2-b.y1) + b.y1;
			if(ycur >= yright[icur] - eps && ynext >= yleft[inext] - eps)
			{
				visibleArea += AreaBelow(xcur, ycur, xnext, ynext);
				visibleArea -= AreaBelow(xcur, yright[icur], xnext, yleft[inext]);
				yright[icur] = ycur;
				yleft[inext] = ynext;
			}
		}
		printf("%.6lf\n", visibleArea / ownArea);
	}
	return 0;
}
