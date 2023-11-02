#include <bits/stdc++.h>
using namespace std;


vector <vector <string>> facts;

bool letter(char c) {
	return ('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z') || ('0' <= c && c <= '9') || (c == '_');
}

vector <string> parse(string S) {
	// cout << S << endl;
	vector <string> ret;
	int pre = 0;
	for (int i = 0; i < (int) S.size(); i++) {
		if (!letter(S[i])) {
			if (pre < i)
				ret.push_back(S.substr(pre, i - pre));
			pre = i + 1;
		}
	}
	if (pre < (int) S.size())
		ret.push_back(S.substr(pre));
	return ret;
}

bool match(vector <string> v, vector <string> f) {
	if (v.size() != f.size())
		return false;
	assert(v.size());
	assert(f.size());
	if (v[0] != f[0])
		return false;
	map <string, string> variable_value;
	for (int i = 1; i < (int) v.size(); i++) {
		if (v[i] == f[i])
			continue;
		if (v[i] == "_")
			continue;
		if (v[i][0] == '_') {
			if (variable_value.count(v[i]) && variable_value[v[i]] != f[i])
				return false;
			variable_value[v[i]] = f[i];
			continue;
		}
		return false;
	}
	return true;
}

int main() {
	string S;
	while (true) {
		getline(cin, S);
		if (S == "")
			break;
		int pre = 0;
		for (int i = 0; i < (int) S.size(); i++) {
			if (S[i] == ')')
				facts.push_back(parse(S.substr(pre, i + 1 - pre))), pre = i + 1;
		}
	}
	while (getline(cin, S)) {
		int ans = 0;
		auto v = parse(S);
		for (auto f: facts)
			if (match(v, f))
				ans++;
		printf("%d\n", ans);
	}
}