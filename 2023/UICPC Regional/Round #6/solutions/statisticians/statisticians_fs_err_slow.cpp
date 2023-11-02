#include <stdio.h>
#include <algorithm>
using namespace std;

const int side = 140;
const int maxRet = 10000;

int minArea, maxArea;
int h, w;
unsigned int iimg[side+1][side+1]; // Integral image

int main()
{
	scanf("%d %d", &h, &w);
	scanf("%d %d", &minArea, &maxArea);
	// Pad with one row and col of 0.
	++w;
	++h;
	for(int y = 0; y < h; ++y)
		iimg[y][0] = 0;
	for(int x = 0; x < w; ++x)
		iimg[0][x] = 0;
	// Read the map
	for(int y = 1; y < h; ++y)
		for(int x = 1; x < w; ++x)
			scanf("%d", &iimg[y][x]);

	// Create an integral image
	for(int y = 0; y < h; ++y)
		for(int x = 1; x < w; ++x)
			iimg[y][x] += iimg[y][x-1];
	for(int x = 0; x < w; ++x)
		for(int y = 1; y < h; ++y)
			iimg[y][x] += iimg[y-1][x];

	// Binary search
	double ma = maxRet; // Maximum value
	double mi = 0;
	double ret = 0;
	while(ma - mi > 8e-4)
	{
		double mid = (mi + ma) / 2;
		double retSmaller = 0;
		double retLarger = maxRet;
		int numLarger = 0;
		int numSmaller = 0;
		for(int y1 = 0; y1 < h; ++y1)
		{
			for(int x1 = 0; x1 < w; ++x1)
			{
				for(int y2 = y1+1; y2 < h; ++y2)
				{
					for(int x2 = x1+1; x2 < w; ++x2)
					{
						int area = (y2-y1)*(x2-x1);
						if(area < minArea)
							continue;
						if(area > maxArea)
							break;
						unsigned int sum = iimg[y2][x2] - iimg[y2][x1] - iimg[y1][x2] + iimg[y1][x1];
						double ppa = (double)sum/area;
						if(ppa > mid)
						{
							++numLarger;
							retLarger = min(retLarger, ppa);
						}
						else
						{
							++numSmaller;
							retSmaller = max(retSmaller, ppa);
						}
					}
				}
			}
		}
		// Cut the search range
		if(numLarger > numSmaller)
			mi = mid;
		else if(numLarger < numSmaller)
			ma = mid;
		else // Equal, we have found the middle
		{
			ret = (retSmaller+retLarger)/2;
			break;
		}
		ret = mid;
	}

	// Output the result
	printf("%.3lf\n", ret);
	return 0;
}
