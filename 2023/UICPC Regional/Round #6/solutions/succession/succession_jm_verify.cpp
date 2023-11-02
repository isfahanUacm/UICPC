#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <cassert>

using namespace std;

typedef long long LL;

void validateName(string s)
{
	assert(s.size() >= 1 && s.size() <= 10);
	for(int i=0;i<s.size();i++)
		assert(s[i]>='a' && s[i]<='z');
}

int main() {
	int N, M;
	string founder, claimant, bestClaimant;
	map<string,LL> blood;
	cin >> N >> M >> founder;
	assert(N >= 2 && N <= 50);
	assert(M >= 2 && M <= 50);
	blood[founder] = 1LL<<50;
	vector<string> c(N), p1(N), p2(N);
	for(int i=0;i<N;i++) {
		cin >> c[i] >> p1[i] >> p2[i];
		validateName(c[i]);
		validateName(p1[i]);
		validateName(p2[i]);
		assert(p1[i]!=p2[i]);
		assert(c[i]!=founder);
	}
	for(int i=0;i<N;i++)
		for(int j=0;j<N;j++)
			blood[c[j]] = (blood[p1[j]] + blood[p2[j]]) / 2;
	for(int j=0;j<N;j++)
		assert(blood[c[j]] == (blood[p1[j]] + blood[p2[j]]) / 2);

	LL best = 0;
	bool bad = true;
	for(int i=0;i<M;i++) {
		cin >> claimant;
		validateName(claimant);
		assert(claimant != founder);
		if (blood[claimant] > best) {
			best = blood[claimant];
			bestClaimant = claimant;
			bad = false;
		} else if (blood[claimant] == best)
			bad = true;
	}
	cout << bestClaimant << endl;
	assert(!bad);
	return 0;
}
