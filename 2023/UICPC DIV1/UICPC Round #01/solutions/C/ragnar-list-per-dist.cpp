#include <iostream>
#include <vector>
using namespace std;

int main(){
	int R, C, k; cin >> R >> C >> k;
	vector<vector<int>> grid(R, vector<int>(C));
	for(auto &x : grid) for(auto &y : x) cin >> y;
	int l = 0, h = 1e9;
	while(l < h){
		auto m = (l+h+1)/2;

		int cdist = 0;
		bool pos = false;

		vector<vector<bool>> done(R, vector<bool>(C));
		vector<vector<pair<int,int>>> cur(k+2);
		for(int i = 0; i < C; ++i)
			done[R-1][i] = true, (grid[R-1][i] >= m ? cur[cdist] : cur[cdist+1]).push_back({R-1, i});
		for(int d = 0; d <= k; ++d){
			while(!cur[d].empty()){
				auto r = cur[d].back().first, c = cur[d].back().second;
				cur[d].pop_back();
				if(r == 0){
					pos = true;
					break;
				}
				for(auto e : {pair<int,int>{1, 0}, {0, 1}, {-1, 0}, {0, -1}}){
					int r2 = r+e.first, c2 = c+e.second;
					if(r2 < 0 or c2 < 0 or r2 >= R or c2 >= C) continue;
					if(not done[r2][c2]){
						done[r2][c2] = true;
						(grid[r2][c2] >= m ? cur[d] : cur[d+1]).push_back({r2, c2});
					}
				}
			}
		}

		if(pos) l = m;
		else h = m-1;
	}
	cout << l << endl;
}
