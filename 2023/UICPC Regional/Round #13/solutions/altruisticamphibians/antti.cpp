#include <iostream>
#include <vector>
#include <array>
#include <algorithm>

using namespace std;

int n, d;
vector<array<int,3>> dogs;
int total;
vector<array<int,3>> piles;
vector<array<int,3>> more;
vector<array<int,3>> final;
int base;

void merge(int cur) {
	final.clear();
	int a = 0, b = 0;
	while (true) {
		if (a < piles.size() && b < more.size()) {
			if (piles[a] > more[b]) final.push_back(piles[a++]);
			else final.push_back(more[b++]);
		} else if (a < piles.size()) {
			final.push_back(piles[a++]);
		} else if (b < more.size()) {
			final.push_back(more[b++]);
		} else break;
		int k = final.size();
		if (cur*2 <= final[k-1][0]) {
			base = max(base,final[k-1][1]);
			final.pop_back();
		} else if (k >= 2 && final[k-1][1] <= final[k-2][1]) {
			final.pop_back();
		}
	}
	piles = final;
}

int main() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		int l, w, h;
		cin >> l >> w >> h;
		dogs.push_back({w,h,l});
	}
	sort(dogs.rbegin(),dogs.rend());
	for (int i = 0; i < n; i++) {
		int gap = d-dogs[i][2];
		if (gap >= base) {
			for (auto pile : piles) {
				if (pile[0] >= dogs[i][0] && pile[1] > gap) {
					total++;
					break;
				}
			}
		} else {
			total++;
		}
		if (i > 0 && dogs[i-1][0] == dogs[i][0]) continue;
		more.clear();
		bool flag = false;
		int height = base+dogs[i][1];
		for (auto pile : piles) {
			if (dogs[i][0]*2 <= pile[0]) {
				height = max(height,pile[1]+dogs[i][1]);
			} else if (dogs[i][0] < pile[0]) {
				if (!flag) more.push_back({dogs[i][0]-1,height});
				flag = true;
				more.push_back({pile[0]-dogs[i][0],pile[1]+dogs[i][1]});
			} else break;
		}
		if (!flag) more.push_back({dogs[i][0]-1,height});
		merge(dogs[i][0]);
	}
	cout << total << "\n";
}
