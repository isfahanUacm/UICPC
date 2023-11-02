#include <stdio.h>

int h,w;
int mat[10][10];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
int sx[5];
int sy[5];
int numPolys;
int polysize;

bool TryToPlaceSquare(int y0, int x0, int k)
{
	int i;
	for(i = 0; i < k; ++i)
	{
		int x = x0+sx[i]-sx[0];
		int y = y0+sy[i]-sy[0];
		if(x < 0 || x >= w || y < 0 || y >= h)
			break;
		if(mat[y][x] != -1)
			break;
		mat[y][x] = i;
	}
	if(i == k)
		return true;
	// Reset
	for(--i; i >= 0; --i)
	{
		int x = x0+sx[i]-sx[0];
		int y = y0+sy[i]-sy[0];
		mat[y][x] = -1;
	}
	return false;
}

struct entry
{
	int y,x;
	entry() { }
	entry(int _y, int _x) : y(_y), x(_x) { }
} q[100];
int qf, qb;

bool PutSquares(int k)
{
	int cnt = 0;
	if(TryToPlaceSquare(sy[0], sx[0], k))
	{
		if(++cnt == polysize)
			return true;
	}
	qf = 0;
	q[0] = entry(sy[0], sx[0]);
	qb = 1;
	while(qf != qb)
	{
		entry e = q[qf++];
		for(int i = 0; i < 4; ++i)
		{
			if(TryToPlaceSquare(e.y+dy[i], e.x+dx[i], k))
			{
				if(++cnt == polysize)
					return true;
				q[qb++] = entry(e.y+dy[i], e.x+dx[i]);
			}
		}
	}
	return false;
}

void ResetMat()
{
	for(int y = 0; y < h; ++y)
	{
		for(int x = 0; x < w; ++x)
		{
			if(mat[y][x] >= 0)
				mat[y][x] = -1;
		}
	}
}

bool FindStart(int y, int x, int k)
{
	if(k > 0)
	{
		if(!PutSquares(k))
		{
			ResetMat();
			return false;
		}
		if(k == numPolys)
			return true;
	}
	ResetMat();
	for(; y < h; ++y)
	{
		for(; x < w; ++x)
		{
			if(mat[y][x] == -1)
			{
				sx[k] = x;
				sy[k] = y;
				if(FindStart(y,x+1,k+1))
					return true;
			}
		}
		x = 0;
	}
	return false;
}

int main()
{
	int num = 0;
	scanf("%d %d", &h, &w);
	for(int y = 0; y < h; ++y)
	{
		char str[16];
		scanf("%s", str);
		for(int x = 0; x < w; ++x)
		{
			if(str[x] == '.')
				mat[y][x] = -2; // Space
			else
			{
				mat[y][x] = -1; // Polyomino
				++num;
			}
		}
	}
	bool success = false;
	for(numPolys = 2; numPolys <= 5; ++numPolys)
	{
		if(num % numPolys != 0)
			continue;
		polysize = num/numPolys;
		if(FindStart(0,0,0))
		{
			success = true;
			break;
		}
	}
	if(success)
	{
		for(int y = 0; y < h; ++y)
		{
			for(int x = 0; x < w; ++x)
				printf("%c", (mat[y][x] == -2 ? '.' : mat[y][x] + '1'));
			printf("\n");
		}
	}
	else
		printf("No solution\n");
	return 0;
}
