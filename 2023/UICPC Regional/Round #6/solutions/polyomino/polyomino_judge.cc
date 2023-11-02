#include <cstdio>
#include <vector>
#include <cstdarg>
#include <cassert>
#include <cstring>
#include "../include/corr.h"

#define H 10
#define W 10

using namespace std;

/*int dfs(int current, int last, vector<vector<int> > &edges, vector<bool> &visited, int &longestPath)
{
if (visited[current]) return 0; // Only happens when the graph is not a tree
visited[current] = true;
int maxDepth = 0;
for(int i=0;i<edges[current].size();i++) {
if (edges[current][i] == last) continue;
int depth = dfs(edges[current][i], current, edges, visited, longestPath);
if (depth + maxDepth > longestPath)
longestPath = depth + maxDepth;
if (depth > maxDepth)
maxDepth = depth;
}
return maxDepth + 1;
}*/

int dfs(char T[H][W], int i, int j, int h, int w) {
	if (i < 0 || i >= h || j < 0 || j >= w || T[i][j] != '1') return 0;
	T[i][j] = 's';
	return 1 + dfs(T, i + 1, j, h, w) + dfs(T, i, j + 1, h, w) + dfs(T, i - 1, j, h, w) + dfs(T, i, j - 1, h, w);
}

int main(int argc, char **argv)
{
	init_io(argc, argv);

	char line[20], line2[20];
	if(fscanf(judgeout, "%16s", line) != 1)
		assert(!"Failed to read judge answer initial line");

	if (strcasecmp(line, "No") == 0) {
		if(fscanf(teamout, "%16s", line2) != 1)
			report_error("Expected \"%s\", team output missing", line, line2);
			
		if (strcasecmp(line, line2) != 0) {
			report_error("Expected \"%s\", got \"%s\"", line, line2);
		}
		if(fscanf(judgeout, "%16s", line) != 1)
			assert(!"Failed to read judge answer in no case");
		if(fscanf(teamout, "%16s", line2) != 1)
			report_error("Expected \"%s\", team output missing", line, line2);
			
		if (strcasecmp(line, line2) != 0) {
			report_error("Expected \"%s\", got \"%s\"", line, line2);
		}
		if (fscanf(teamout, "%16s", line) != EOF) {
			report_error("Trailing team output.");
		}
	}
	else {
		int h, w, t = 0, p = 0;
		if(fscanf(judgein, "%d %d", &h, &w) != 2)
			assert(!"Failed to read h and w from judge input");
		bool B[H][W];
		char T[H][W];
		int ps[5][2];
		for (int i = 0; i < 5; i++) {
			ps[i][0] = -1;
		}

		for (int i = 0; i < h; i++) {
			if(fscanf(judgein, "%16s", line) != 1)
				assert(!"Failed to read judge input line");
			for (int j = 0; j < w; j++) {
				B[i][j] = line[j] == 'X';
				t += B[i][j];
			}
			if(fscanf(teamout, "%16s", line) != 1)
				report_error("Team output too short, only %d lines, expected %d", i, h);
			if(strlen(line) != w)
				report_error("Team output line %d is %d characters long, expected %d", i, strlen(line), w);
			for (int j = 0; j < w; j++) {
				T[i][j] = line[j];
				int v = T[i][j] - '1';
				if (v >= 0 && v < 5) {
					if (ps[v][0] == -1) {
						ps[v][0] = i;
						ps[v][1] = j;
						p++;
					}
				}
				else if (T[i][j] != '.') {
					report_error("Team had illegal character (%d, %d)", i, j);
				}
			}
		}
		
		for (int i = 0; i < p; i++) {
			if (ps[i][0] == -1) report_error("Team used wrong numbers.");
		}

		if (dfs(T, ps[0][0], ps[0][1], h, w) * p != t) {
			report_error("Team had wrong number of filled in tiles, or disconnected pieces.");
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (T[i][j] == 's') {
					T[i][j] = '1';
				}
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (B[i][j]) {
					if (T[i][j] < '1' || T[i][j] > '5') {
						report_error("Team filled in square with illegal char (%d, %d).", i, j);
					}
					if (T[i][j] == '1') {
						// Note that we earlier checked that the ps[k][0] is valid for k < p
						for (int k = 0; k < p; k++) {
							int x = i + ps[k][0] - ps[0][0], y = j + ps[k][1] - ps[0][1];
							if (!(B[x][y] && (k + '1' == T[x][y]))) {
								report_error("Team filled in wrong in (%d, %d) : %c", i, j, T[x][y]);
							}
							B[x][y] = false;
							T[x][y] = '.';
						}
					}
				}
				else {
					if (T[i][j] != '.') {
						report_error("Team filled in blank square (%d, %d).", i, j);
					}
				}
			}
		}
	}
	return EXIT_AC;
}
