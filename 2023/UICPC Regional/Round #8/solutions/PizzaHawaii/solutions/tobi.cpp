// @EXPECTED_RESULTS@: CORRECT
// way too complex solution

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
#define MAXIND (60*20 + 5)

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

		map<string,int> name[2];
		vector<set<int> > ing[2];
		vector<string> names[2];

		FOR(p, 0, numPizzas) {
			char buf[32];
			scanf("%s", buf); // skip pizza name
			FOR(j, 0, 2) {
				int numIng;
				scanf("%d", &numIng);
				set<int> s;
				FOR(i, 0, numIng) {
					scanf("%s", buf);
					string ing(buf);
					if (name[j].find(ing) == name[j].end()) {
						name[j][ing] = sz(name[j]) - 1;
						names[j].push_back(ing);
					}

					s.insert(name[j][ing]);
				}
				ing[j].push_back(s);
			}
		}

		bitset<MAXIND> pizzaBits[numPizzas];
		FOR(p, 0, numPizzas) {
			pizzaBits[p].reset();
			FORIT(i, ing[1][p]) {
				pizzaBits[p].set(*i);
			}
		}

		bitset<MAXIND> wordBits[sz(name[0])];
		FOR(i, 0, sz(name[0])) {
			wordBits[i].set();
		}
		FOR(i, 0, sz(name[0])) {
			FOR(p, 0, numPizzas) {
				if (ing[0][p].count(i)) {
					wordBits[i] &= pizzaBits[p];
				} else {
					wordBits[i] &= ~pizzaBits[p];
				}
			}
		}

		set<pair<string,string> > ings;
		FOR(i, 0, sz(name[0])) {
			FOR (j, 0, sz(name[1])) {
				if (wordBits[i].test(j)) {
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
