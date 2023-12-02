// @EXPECTED_RESULTS@: CORRECT

#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
#include <assert.h>

using namespace std;

int numWords, numBoggles;
vector<string> dictionary;
string boggle[4];
bool vis[4][4];
vector<string> found;

int dx[] = { 0, 0,-1,-1,-1,+1,+1,+1};
int dy[] = {-1,+1,-1, 0,+1,-1, 0,+1};
int toScore[] = {0, 0, 0, 1, 1, 2, 3, 5, 11, 11, 11, 11, 11, 11, 11, 11, 11};

struct trie {
	bool valid;
	int edges[26];
	int last;
};

#define MAX_TRIE (5+8*300000)
trie tries[MAX_TRIE];
int edgeCnt;
int kase;

int init() {
	int id = edgeCnt;
	tries[id].valid = false;
	for (int i = 0; i < 26; i++) tries[id].edges[i] = -1;
	edgeCnt++;
	assert(edgeCnt < MAX_TRIE);
	return id;
}

void add(int id, string &w, int idx) {
	if (idx >= (signed) w.size()) {
		tries[id].valid = true;
		return;
	}
	int letter = (int) (w[idx] - 'A');
	if (tries[id].edges[letter] == -1) {
		tries[id].edges[letter] = init();
	}

	add(tries[id].edges[letter], w, idx + 1);
}

void rec(int i, int j, string cur, int id) {
	if (i < 0 || j < 0 || i >= 4 || j >= 4) return;
	if (vis[i][j]) return;
	if (cur.size() >= 8) return;
	
	vis[i][j] = true;
	cur = cur + boggle[i][j];
	int letter = (int) (boggle[i][j] - 'A');
	int next = tries[id].edges[letter];
	if (next == -1) {
		vis[i][j] = false;
		return;
	}
	if (tries[next].valid && tries[next].last < kase) {
		tries[next].last = kase;
		found.push_back(cur);
//		cerr << "found " << cur << endl;
	}

	for (int c = 0; c < 8; c++) {
		rec(i + dx[c], j + dy[c], cur, next);
	}
	vis[i][j] = false;
}

int main() {
	edgeCnt = 0;
	int root = init();
	cin >> numWords;
	for (int i = 0; i < numWords; i++) {
		string t;
		cin >> t;
		add(root, t, 0);
	}

	cin >> numBoggles;
	for (int i = 0; i < numBoggles; i++) {
		kase = i + 1;
		for (int j = 0; j < 4; j++) cin >> boggle[j];
		found.clear();
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 4; k++) {
				rec(j,k, "", root);
			}
		}
		string best = *(found.begin());
		int score = 0;
		for (vector<string>::iterator iter = found.begin(); iter != found.end(); iter++) {
			if (best.size() < iter->size() || (best.size() == iter->size() && *iter < best)) {
				best = *iter;
			}
			score += toScore[iter->size()];
		}
		cout << score << " " << best << " " << found.size() << endl;
	}
	
	return 0;
}
