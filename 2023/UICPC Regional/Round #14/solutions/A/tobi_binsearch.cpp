// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int numWords, numBoggles;
vector<string> dictionary;
string boggle[4];
bool vis[4][4];
set<string> found;

int dx[] = { 0, 0,-1,-1,-1,+1,+1,+1};
int dy[] = {-1,+1,-1, 0,+1,-1, 0,+1};
int toScore[] = {0, 0, 0, 1, 1, 2, 3, 5, 11, 11, 11, 11, 11, 11, 11, 11, 11};

void rec(int i, int j, string cur) {
	if (i < 0 || j < 0 || i >= 4 || j >= 4) return;
	if (vis[i][j]) return;
	if (cur.size() >= 8) return;
	
	vis[i][j] = true;
	cur = cur + boggle[i][j];
	vector<string>::iterator iter = lower_bound(dictionary.begin(), dictionary.end(), cur);
	if (iter == dictionary.end() || iter->substr(0,cur.size()) != cur) {
		vis[i][j] = false;
		return;
	}
	if (cur == *iter) {
		found.insert(cur);
//		cerr << "found " << cur << endl;
	}

	for (int c = 0; c < 8; c++) {
		rec(i + dx[c], j + dy[c], cur);
	}
	vis[i][j] = false;
}

int main() {
	cin >> numWords;
	for (int i = 0; i < numWords; i++) {
		string t;
		cin >> t;
		dictionary.push_back(t);
	}
	sort(dictionary.begin(), dictionary.end());

	cin >> numBoggles;
	for (int i = 0; i < numBoggles; i++) {
		for (int j = 0; j < 4; j++) cin >> boggle[j];
		found.clear();
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				rec(j,k, "");
			}
		}
		string best = *(found.begin());
		int score = 0;
		for (set<string>::iterator iter = found.begin(); iter != found.end(); iter++) {
			if (best.size() < iter->size()) {
				best = *iter;
			}
			score += toScore[iter->size()];
		}
		cout << score << " " << best << " " << found.size() << endl;
	}

	
	return 0;
}
