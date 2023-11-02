#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

const int side = 140;

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

	vector<double> ppa;
	ppa.reserve(w*h*w*h/3);
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
					ppa.push_back((double)sum/area);
				}
			}
		}
	}
	sort(ppa.begin(), ppa.end());
	double ret;
	if(ppa.size() == 0)
	{
		printf("Error\n");
		return -1;
	}
	else if(ppa.size() % 2 == 0)
		ret = (ppa[ppa.size() / 2 - 1] + ppa[ppa.size() / 2])/2;
	else
		ret = ppa[ppa.size() / 2];

	// Output the result
	printf("%.3lf\n", ret);
	return 0;
}
