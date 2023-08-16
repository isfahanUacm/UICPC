//Author: Fredrik Svensson
#include <cstdio>
#include <cstring>
using namespace std;

const int MAX_N = 1000;
const int MAX_NUMS = 100;
const int MOD = 0x7FFFFFFF; // (1<<31)-1
int n;
int grid[MAX_N][MAX_N];
int diag[MAX_N+1];
int queue[2 * MAX_N*MAX_N+2]; // First x, then y
const int dx[] = { 0, 1, 0, -1 };
const int dy[] = { 1, 0, -1, 0 };

// When counting, we know that the distance to the end is constant.
bool isAllWaysPossible()
{
	for (int i = 0; i < n; ++i)
		for (int j = 0; j < n; ++j)
			grid[i][j] = (grid[i][j] == -1 ? -1 : 0);
	grid[0][0] = 1;

	int qTop = 0;
	int qBack = 0;
	queue[qBack++] = 0; // x
	queue[qBack++] = 0; // y
	while (qTop < qBack)
	{
		int x = queue[qTop++];
		int y = queue[qTop++];
		if (y == n-1 && x == n-1)
			return true;
		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			if (nx < 0 || nx >= n)
				continue;
			int ny = y + dy[i];
			if (ny < 0 || ny >= n)
				continue;
			// Blocked?
			if (grid[ny][nx] == -1)
				continue;
			// Push to the queue if not already there
			if (grid[ny][nx] == 0)
			{
				grid[ny][nx] = 1;
				queue[qBack++] = nx;
				queue[qBack++] = ny;
			}
		}
	}
	return false;
}

void add(int dest, int a, int b)
{
	int sum = diag[a] + diag[b];
	if (sum >= MOD || sum < 0)
		sum -= MOD;
	diag[dest] = sum;
}

int main()
{
	char str[MAX_N+3];
	if (fgets(str, MAX_N+3, stdin) == NULL || sscanf(str, "%d", &n) != 1 || n == 0 || n > MAX_N)
	{
		printf("Invalid n = %d.\n", n);
		return 1;
	}
	for (int i = 0; i < n; ++i)
	{
		if (fgets(str, MAX_N+3, stdin) == NULL)
		{
			printf("Could not read line %d.\n", i);
			return 1;
		}
		for (int j = 0; j < n; ++j)
		{
			// Input check
			switch(str[j])
			{
			case '#':
			case '.':
				break;
			default:
				printf("Invalid grid line %d = %s.\n", i, str);
				return 1;
			}
			grid[i][j] = (str[j] == '#' ? -1 : 0);
		}
		if (strcmp(str + n, "\n") && strcmp(str + n, "\r\n"))
		{
			printf("Invalid length of grid line %d = %s.\n", i, str);
			return 1;
		}
		diag[i] = 0;
	}
	if (fgets(str, MAX_N+3, stdin) != NULL)
	{
		printf("EOF not found at the end.\n");
		return 1;
	}
	if (grid[0][0] == -1 || grid[n-1][n-1] == -1)
	{
		printf("Wall at s or t.\n");
		return 1;
	}

	diag[0] = 1;
	// Upper left triangle
	for (int i = 1; i < n; ++i)
	{
		// Don't need to copy down the left-most (j=0) number
		for (int j = i; j > 0; --j)
		{
			if (grid[i-j][j] != -1)
				add(j, j-1, j);
			else
				diag[j] = 0;
		}
		if (grid[i][0] == -1)
			diag[0] = 0;
	}
	// Lower right triangle
	for (int i = n-2; i >= 0; --i)
	{
		diag[i+2] = 0;
		for (int j = 0; j <= i; ++j)
		{
			if (grid[n-1-j][n-1-i+j] != -1)
				add(j, j, j+1);
			else
				diag[j] = 0;
		}
	}
	if (diag[0] == 0)
	{
		if (isAllWaysPossible())
			printf("THE GAME IS A LIE\n");
		else
			printf("INCONCEIVABLE\n");
	}
	else
	{
		printf("%d\n", diag[0]);
	}
	return 0;
}
