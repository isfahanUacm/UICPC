// @EXPECTED_RESULTS@: CORRECT
#include<iostream>
#include<set>
#include<map>
#include<string>

using namespace std;
#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define FORIT(i,c) for (__typeof__((c).begin()) i = (c).begin(); i != (c).end(); i++)
map<string,set<string> > m[2];
int main(){
	int P,A;
	bool first_ = 1;
	cin >> P; // skip number of testcases
	while(cin >> P){
		if(first_)first_ = 0;
		else cout << endl;
		FOR(i,0,2)m[i].clear();
		while(P--){
			string in;
			set<string> s[2];
			cin >> in;
			FOR(i,0,2){
				s[i].clear();
				cin >> A;
				while(A--){
					cin >> in;
					s[i].insert(in);
				}
			}
			FOR(sid,0,2)FORIT(it,s[sid]){
				if(m[sid].find(*it)==m[sid].end())m[sid][*it] = s[sid^1];
				else {
					set<string> nset;
					FORIT(it2,m[sid][*it])if(s[sid^1].find(*it2)!=s[sid^1].end())nset.insert(*it2);
					m[sid][*it] = nset;
				}
			}
		}
		FORIT(it1,m[0]){
			FORIT(it2,it1->second)if(m[1][*it2].find(it1->first)!=m[1][*it2].end()){
				cout <<"("<< it1->first << ", " << *it2 << ")" << endl;
			}
		}
	}
}
