#include <stdio.h>
#include <stdlib.h>

#define VerifyInput(x) DoVerifyInput(x, #x)

void DoVerifyInput(bool test, const char* expression)
{
	if(!test)
	{
		fprintf(stderr, "Erroneous input: %s\n", expression);
		exit(1);
	}
}

const int side = 140;
const int numBuckets = 10000*1000+1;

int minArea, maxArea;
int h, w;
unsigned int iimg[side+1][side+1]; // Integral image
int buckets[numBuckets] = {0};

int main()
{
	scanf("%d %d", &h, &w);
	VerifyInput(1 <= h && h <= 140);
	VerifyInput(1 <= w && w <= 120);
	scanf("%d %d", &minArea, &maxArea);
	VerifyInput(1 <= minArea);
	VerifyInput(minArea <= maxArea);
	VerifyInput(maxArea <= w*h);
	// Pad with one row and col of 0.
	++w;
	++h;
	for(int y = 0; y < h; ++y)
		iimg[y][0] = 0;
	for(int x = 0; x < w; ++x)
		iimg[0][x] = 0;
	// Read the map
	for(int y = 1; y < h; ++y)
	{
		for(int x = 1; x < w; ++x)
		{
			scanf("%d", &iimg[y][x]);
			VerifyInput(0 <= iimg[y][x] && iimg[y][x] <= 10000);
		}
	}
	VerifyInput(scanf("%d", &buckets[0]) == EOF);

	// Create an integral image
	for(int y = 0; y < h; ++y)
		for(int x = 1; x < w; ++x)
			iimg[y][x] += iimg[y][x-1];
	for(int x = 0; x < w; ++x)
		for(int y = 1; y < h; ++y)
			iimg[y][x] += iimg[y-1][x];

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
					//buckets[(int)(sum*1000.0/area + 0.5)]++;
					buckets[(sum*2000LL+area)/(2*area)]++;
				}
			}
		}
	}
	int totn = buckets[0];
	for(int i = 1; i < numBuckets; ++i)
	{
		totn += buckets[i];
		buckets[i] += buckets[i-1];
	}
	if(totn == 0)
	{
		printf("Error\n");
		return -1;
	}
	// Find the median in the bucket sort
	int m1 = -1;
	int m2 = 0;
	for(int i = 0; i < numBuckets; ++i)
	{
		if(2*(buckets[i]+1) > totn)
		{
			if(m1 == -1)
				m1 = i;
		}
		if(2*buckets[i] > totn)
		{
			m2 = i;
			break;
		}
	}
	double ret;
	if(totn%2 == 0)
		ret = (m1+m2)/2000.0;
	else
		ret = m2/1000.0;

	// Output the result
	printf("%.3lf\n", ret);
	return 0;
}
