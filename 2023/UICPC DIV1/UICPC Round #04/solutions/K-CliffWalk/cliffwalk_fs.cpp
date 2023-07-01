// Solution by Fredrik Svensson
#include <cmath>
#include <iostream>
#include <queue>
#include <cstdio>
using namespace std;

#define MAX_H 200
#define MAX_W 200
const int maxClimb = 1000; // 1 meter.
const double dryingPeriod = 1; // One hour.
const double pi = 3.1415926535897932384626433832795;

struct pos
{
	int x, y;
	double t;

	pos()
	{
	}
	pos(int x, int y, double time) :
		x(x), y(y), t(time)
	{
	}

	bool operator<(const pos &rhs) const
	{
		return (this->t < rhs.t);
	}
	bool operator>(const pos &rhs) const
	{
		return (this->t > rhs.t);
	}
};

double a, m;
int w, h;
int mapZ[MAX_H][MAX_W];
double dryTime[MAX_H][MAX_W]; // The time when the rock is dry.
double wetTime[MAX_H][MAX_W]; // The time when the tide makes the rock wet.

double enterTime[MAX_H][MAX_W]; // The earliest time when Charlotte reaches the rock.
double leaveTime[MAX_H][MAX_W]; // The latest time Charlotte can leave the rock.

const int dxs[] = {1,-1,0,0};
const int dys[] = {0,0,1,-1};

void shortestPathOut(const pos &start)
{
	priority_queue<pos, std::vector<pos>, std::greater<pos> > pq;
	pq.push(start);
	while (!pq.empty())
	{
		pos p = pq.top();
		pq.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = p.x + dxs[i];
			int y = p.y + dys[i];
			if (x < 0 || x >= w || y < 0 || y >= h)
				continue;
			int zDiff = mapZ[p.y][p.x] - mapZ[y][x];
			if (abs(zDiff) > maxClimb)
				continue;
			double nextTime = max(p.t, dryTime[y][x]) + m;
			if (nextTime > wetTime[y][x])
				continue;
			if (nextTime < enterTime[y][x])
			{
				enterTime[y][x] = nextTime;
				pq.push(pos(x,y,nextTime));
			}
		}
	}
}

void shortestPathBack(const pos &start)
{
	priority_queue<pos> pq;
	pq.push(start);
	while (!pq.empty())
	{
		pos p = pq.top();
		pq.pop();
		for (int i = 0; i < 4; ++i)
		{
			int x = p.x + dxs[i];
			int y = p.y + dys[i];
			if (x < 0 || x >= w || y < 0 || y >= h)
				continue;
			int zDiff = mapZ[p.y][p.x] - mapZ[y][x];
			if (abs(zDiff) > maxClimb)
				continue;
			double nextTime = min(p.t, wetTime[y][x]) - m;
			if (nextTime < dryTime[y][x])
				continue;
			if (nextTime > leaveTime[y][x])
			{
				leaveTime[y][x] = nextTime;
				pq.push(pos(x,y,nextTime));
			}
		}
	}
}

double calcDist(int dx, int dy)
{
	return sqrt((double)dx*dx + dy*dy);
}

int main()
{
	cin >> a >> m;
	a *= 1000.0;
	m /= 3600.0;
	pos start(0, 0, 0.0);
	cin >> w >> h >> start.x >> start.y;
	pos stop = start;
	stop.t = 12.0;
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			int z;
			cin >> z;
			mapZ[y][x] = z;
			if (z <= a)
			{
				double t = acos((2.0*z)/a-1)*6/pi;
				dryTime[y][x] = t + dryingPeriod;
				wetTime[y][x] = 12 - t;
			}
			else
			{
				dryTime[y][x] = -2;
				wetTime[y][x] = 14;
			}

			enterTime[y][x] = 12;
			leaveTime[y][x] = 0;
		}
	}
	enterTime[start.y][start.x] = 0;
	leaveTime[start.y][start.x] = 12;

	shortestPathOut(start);
	shortestPathBack(stop);

	double ret = 0;
	for (int y = 0; y < h; ++y)
	{
		for (int x = 0; x < w; ++x)
		{
			if (enterTime[y][x] <= leaveTime[y][x])
			{
				const double dist = calcDist(x - start.x, y - start.y);
				if (dist > ret)
					ret = dist;
			}
		}
	}
	cout.precision(10);
	cout << 10*ret << endl;
	return 0;
}
