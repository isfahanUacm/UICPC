#include <iostream>
#include <vector>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <iomanip>

using namespace std;

int a[150][150];
int sum[150][150];
int cnt[10000001];

int main()
{
	int ysize, xsize, minarea, maxarea;
	cin >> ysize >> xsize >> minarea >> maxarea;
	for(int y=0;y<=ysize;y++)
		for(int x=0;x<=xsize;x++)
			sum[y][x]=0;
	for(int y=0;y<ysize;y++)
		for(int x=0;x<xsize;x++) {
			cin >> a[y][x];
			sum[y+1][x+1] = sum[y+1][x]+sum[y][x+1]-sum[y][x]+a[y][x];
		}
	
	memset(cnt,0,sizeof(cnt));
	int total = 0;
	for(int ry=1;ry<=ysize;ry++)
		for(int rx=1;rx<=xsize;rx++) {
			double f = 1000.0 / (rx*ry);
			if (rx*ry>=minarea && rx*ry<=maxarea)
				for(int y=0;y<=ysize-ry;y++)
					for(int x=0;x<=xsize-rx;x++) {
						int v = sum[y+ry][x+rx]-sum[y][x+rx]-sum[y+ry][x]+sum[y][x];
						int bucket = round(v*f);
						cnt[bucket]++;
						total++;
					}
		}
		
	int left = (total+1) / 2, cur = 0;
	while (left > 0) {
		if (cnt[cur] > left) {
			cnt[cur] -= left;
			left = 0;
		} else {
			left -= cnt[cur];
			cnt[cur] = 0;
		}
		if (left > 0) cur++;
	}
	
	if (total % 2 == 0) {
		int first = cur;
		while (!cnt[cur]) cur++;
		cur = (first+cur)/2;
	}

	cout << setprecision(10) << cur / 1000.0 << endl;

	return 0;
}
