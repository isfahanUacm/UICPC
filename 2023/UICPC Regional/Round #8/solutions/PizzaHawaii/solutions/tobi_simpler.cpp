// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>
#include <set>
#include <algorithm>
#include <bitset>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define sz(c) int((c).size())
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
#define MAXIND 65

int main(int argc, char**argv) {
	bool first = true;
	int numPizzas;
	scanf("%d", &numPizzas); // skip number of testcases
	while (EOF != scanf("%d", &numPizzas)) {
		if (first) {
			first = false;
		} else {
			puts("");
		}

		vector<bitset<MAXIND> > ingBits[2];
		map<string,int> name[2];
		vector<string> names[2];

		FOR(p, 0, numPizzas) {
			char buf[32];
			scanf("%s", buf); // skip pizza name
			FOR(j, 0, 2) {
				int numIng;
				scanf("%d", &numIng);
				FOR(i, 0, numIng) {
					scanf("%s", buf);
					string ing(buf);
					if (name[j].find(ing) == name[j].end()) {
						name[j][ing] = sz(name[j]) - 1;
						names[j].push_back(ing);
						bitset<MAXIND> empty;
						empty.reset();
						ingBits[j].push_back(empty);
					}

					ingBits[j][name[j][ing]].set(p);
				}
			}
		}

		set<pair<string,string> > ings;
		FOR(i, 0, sz(name[0])) {
			FOR (j, 0, sz(name[1])) {
				if ((ingBits[0][i] ^ ingBits[1][j]).count() == 0) {
					ings.insert(pair<string,string>(names[0][i], names[1][j]));
				}
			}
		}
		FORIT(i, ings) {
			printf("(%s, %s)\n", i->first.c_str(), i->second.c_str());
		}
	}

	return 0;
}
