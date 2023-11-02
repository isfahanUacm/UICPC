#include <cmath>
#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

const double PI = 3.1415926535897932384626433832795;

double AngleDiff(int x1, int y1, int x2, int y2, int x3, int y3)
{
	x1 -= x2;
	y1 -= y2;
	x3 -= x2;
	y3 -= y2;
	double angleDiff = atan2((double)y1, (double)x1) - atan2((double)y3, (double)x3);
	if(angleDiff >= PI)
		angleDiff = 2*PI - angleDiff;
	else if(angleDiff <= -PI)
		angleDiff = 2*PI + angleDiff;
	else if(angleDiff < 0)
		angleDiff = -angleDiff;
	return PI - angleDiff;
}

struct s_node
{
	int x, y;
	s_node* connections[4];
	int numConnections;

	double GetAngleDiff(s_node* prev, s_node* next);
	double RemoveConnections(s_node* prev, s_node* next);
} nodes[10000];
int numNodes;

double s_node::GetAngleDiff(s_node* prev, s_node* next)
{
	double ret;
	ret = AngleDiff(prev->x, prev->y, x, y, next->x, next->y);
	if (numConnections == 4)
	{
		s_node* p = 0;
		s_node* q = 0;
		for (int i = 0; i < 4; ++i)
		{
			if(connections[i] != prev && connections[i] != next)
			{
				if(p)
				{
					q = connections[i];
					break;
				}
				p = connections[i];
			}
		}
		double angleDiff = AngleDiff(p->x, p->y, x, y, q->x, q->y);
		ret += angleDiff;
	}
	return ret;
}

double s_node::RemoveConnections(s_node* prev, s_node* next) // Minimum angle diff if moving other way
{
	if (numConnections == 2)
	{
		numConnections = 0;
		return 0;
	}
	s_node* p = 0;
	s_node* q = 0;
	for (int i = 0; i < 4; ++i)
	{
		if(connections[i] != prev && connections[i] != next)
		{
			if(p)
			{
				q = connections[i];
				break;
			}
			p = connections[i];
		}
	}

	double ret1, ret2;
	ret1 = AngleDiff(prev->x, prev->y, x, y, p->x, p->y);
	ret1 += AngleDiff(q->x, q->y, x, y, next->x, next->y);
	ret2 = AngleDiff(prev->x, prev->y, x, y, q->x, q->y);
	ret2 += AngleDiff(p->x, p->y, x, y, next->x, next->y);
	connections[0] = p;
	connections[1] = q;
	numConnections = 2;
	return min(ret1, ret2);
}

struct s_conn
{
	s_node* node;
	double penalty; // When adding one more way

	s_conn(s_node* _node, double _penalty) : node(_node), penalty(_penalty)
	{
	}
	bool operator<(const s_conn& rhs) const;
};
bool s_conn::operator<(const s_conn& rhs) const
{
	return penalty > rhs.penalty; // Reversed in the priority queue
}

int main()
{
	int numEdges;

	cin >> numNodes >> numEdges;
	for(int i = 0; i < numNodes; ++i)
	{
		cin >> nodes[i].x >> nodes[i].y;
		nodes[i].numConnections = 0;
	}
	for(int i = 0; i < numEdges; ++i)
	{
		int a, b;
		cin >> a >> b;
		nodes[a].connections[nodes[a].numConnections++] = &nodes[b];
		nodes[b].connections[nodes[b].numConnections++] = &nodes[a];
	}

	double ret = 0;
	priority_queue<s_conn> pq;
	pq.push(s_conn(&nodes[0], 0));
	while(!pq.empty())
	{
		s_conn conn = pq.top();
		pq.pop();
		s_node* start = conn.node;
		if(start->numConnections == 0)
			continue;
		ret += conn.penalty;
		s_node* next = start;
		s_node* cur = start->connections[0]; // Previous node
		s_node* startPrev = cur;
		do
		{
			s_node* prev = cur;
			cur = next;
			double bestAngleDiff = 100000; // Angle diff for "both" ways
			for(int j = 0; j < cur->numConnections; ++j)
			{
				if(cur->connections[j] == prev)
					continue;
				double diff = cur->GetAngleDiff(prev, cur->connections[j]);
				if(diff < bestAngleDiff)
				{
					bestAngleDiff = diff;
					next = cur->connections[j];
				}
			}
			double angleDiff = AngleDiff(prev->x, prev->y, cur->x, cur->y, next->x, next->y); // Not angle diff for both ways
			ret += angleDiff;
			double penalty = cur->RemoveConnections(prev, next);
			if(cur->numConnections > 0)
			{
				penalty -= bestAngleDiff;
				pq.push(s_conn(cur, penalty));
			}
		} while(next != start || cur != startPrev);
	}
	cout << setiosflags(ios::fixed) << setprecision(6) << ret << endl;
	return 0;
}
