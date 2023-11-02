#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

typedef long long LL;

int main() {
	int N, M;
	string founder, claimant, bestClaimant;
	map<string,LL> blood;
	cin >> N >> M >> founder;
	blood[founder] = 1LL<<50;
	vector<string> c(N), p1(N), p2(N);
	for(int i=0;i<N;i++)
		cin >> c[i] >> p1[i] >> p2[i];
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			blood[c[j]] = (blood[p1[j]] + blood[p2[j]]) / 2;
	LL best = 0;
	for(int i=0;i<M;i++) {
		cin >> claimant;
		if (blood[claimant] > best) {
			best = blood[claimant];
			bestClaimant = claimant;
		}			
	}
	cout << bestClaimant << endl;
	return 0;
}
