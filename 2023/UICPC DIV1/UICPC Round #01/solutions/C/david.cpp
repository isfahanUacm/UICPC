#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool isPossible(int H, vector<vector<int>> const &canyon, int K) {
	vector<vector<bool>> done(canyon.size(), vector<bool>(canyon[0].size(), false));
	
	queue<pair<int, int>> work;
	for (int i=0; i<=K; i++) {
		queue<pair<int, int>> nextWork;
		if (i == 0) {
			// Setup
			for (int j=0; j<(int)canyon[0].size(); j++) {
				// Add to correct queue
				if (canyon[0][j] >= H)
					work.push({0,j});
				else
					nextWork.push({0,j});
				done[0][j] = true; // and mark
			}
		}
		
		while (!work.empty()) {
			auto pos = work.front();
			work.pop();
			
			if (pos.first == (int)canyon.size()-1) return true; // we are through
			
			vector<pair<int, int>> d = {{0,1},{1,0},{-1,0},{0,-1}};
			for (auto delta : d) {
				int x = pos.first + delta.first;
				int y = pos.second + delta.second;
				
				// Valid pos?
				if (x < 0 || y < 0 || x >= (int)canyon.size() || y >= (int)canyon[0].size()) continue;
				
				// Already visited?
				if (done[x][y]) continue;
				
				// Add to correct queue
				if (canyon[x][y] >= H)
					work.push({x,y});
				else
					nextWork.push({x,y});
				done[x][y] = true; // and mark
			}
		}
		
		// Use a bridge and continue
		work.swap(nextWork);
	}
	
	// no possible path
	return false;
}

int main() {
	// Read in testdata
	int R, C, K;
	cin >> R >> C >> K;
	vector<vector<int>> canyon(R, vector<int>(C));
	for (int i=0; i<R; i++) {
		for (int j=0; j<C; j++) {
			cin >> canyon[i][j];
		}
	}
	
	// Binary search for the largest possible path height
	int low = 0;
	int high = 1000000001;
	while (high - low > 1) {
		int mid = (high+low)/2;
		if (isPossible(mid, canyon, K))
			low = mid;
		else
			high = mid;
	}
	
	// And output results
	cout << low << endl;
}
