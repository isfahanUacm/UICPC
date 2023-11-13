#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

template <class It> int lisLength(It begin, It end) {
	typedef typename iterator_traits<It>::value_type T;
	T inf = 1<<30;
	vector<T> best(end-begin,inf);
	for (It i = begin; i != end; ++i)
		*lower_bound(best.begin(),best.end(),*i) = *i;
	return lower_bound(best.begin(),best.end(),inf)-best.begin();
}

int main() {
	int n;
	cin >> n;
	vector<pair<int, int> > hand(n, pair<int, int>(0,0));
	map<char, int> rank;
	rank['T'] = 10;
	rank['J'] = 11;
	rank['Q'] = 12;
	rank['K'] = 13;
	rank['A'] = 14;
	map<char, int> suit;
	suit['s'] = 0;
	suit['h'] = 1;
	suit['d'] = 2;
	suit['c'] = 3;
	char s[3];
	for (int i = 0; i < n; ++i) {
		cin >> s;
		if (rank.count(s[0]))
			hand[i].first = rank[s[0]];
		else
			hand[i].first = s[0]-'0';
		hand[i].second = suit[s[1]];
	}
	int suit_order[] = {0, 1, 2, 3};
	int res = 0;
	for (int order = 0; order < 4*3*2; ++order) {
		for (int direction = 0; direction < 16; ++direction) {
			vector<int> value(n, 0);
			for (int i = 0; i < n; ++i) {
				value[i] = suit_order[hand[i].second]*100 + 
					hand[i].first * (1 - 2*!!(direction&(1<<hand[i].second)));
				//cout << value[i] << " ";
			}
			//cout << endl;
			/*if (lisLength(value.begin(), value.end()) > res) {
				for (int i = 0; i < n; ++i) {
					cout << value[i] << " ";
				}
				cout << endl;
			}*/
			res = max(res, lisLength(value.begin(), value.end()));
		}
		next_permutation(suit_order, suit_order+4);
	}
	cout << n-res << endl;
}
