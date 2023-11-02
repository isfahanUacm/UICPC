#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

struct Fact {
  string name;
  vector<string> args;
};

void remove_space(string& s) {
  int i = 0;
  int j = s.size() - 1;
  while (s[i] == ' ') {
    ++i;
  }
  while (s[j] == ' ') {
    --j;
  }
  s = s.substr(i, j - i + 1);
}

Fact parse_fact(string s) {
  Fact fact;
  remove_space(s);
  string name = s.substr(0, s.find('('));
  remove_space(name);
  fact.name = name;
  int i = s.find('(');
  int j = s.find(')');
  s = s.substr(i + 1, j - i - 1);
  while (s.find(',') != string::npos) {
    string arg = s.substr(0, s.find(','));
    remove_space(arg);
    fact.args.push_back(arg);
    s = s.substr(s.find(',') + 1);
  }
  remove_space(s);
  fact.args.push_back(s);
  return fact;
}

void parse_into_facts(const string& line, vector<Fact>& facts) {
  int i = 0;
  while (line.find(')', i) != string::npos) {
    int j = line.find(')', i);
    facts.push_back(parse_fact(line.substr(i, j - i + 1)));
    i = j + 1;
  }
}

bool is_match(const string& query, const Fact& fact) {
  const Fact q = parse_fact(query);
  if (q.name != fact.name) return false;
  if (q.args.size() != fact.args.size()) return false;
  map<string, string> query_to_fact; 
  for (int i = 0; i < q.args.size(); ++i) {
    if (q.args[i] == "_") continue;
    if (q.args[i].front() == '_') {
      if (query_to_fact.find(q.args[i]) == query_to_fact.end()) {
      	query_to_fact[q.args[i]] = fact.args[i];
      } else {
      	if (query_to_fact.at(q.args[i]) != fact.args[i]) {
      	  return false;
      	}
      }
    } else {
      if (q.args[i] != fact.args[i]) {
      	return false;
      }
    }
  }
  return true;
}

int matches(const string& query, const vector<Fact>& facts) {
  int ans = 0;
  for (const auto& fact : facts) {
    if (is_match(query, fact)) {
      ++ans;
    }
  }
  return ans;
}

int main() {
  string line;
  vector<Fact> facts;

  while (getline(cin, line) && !line.empty()) {
    parse_into_facts(line, facts);
  }

  while (getline(cin, line) && !line.empty()) {
    cout << matches(line, facts) << endl;
  }

  return 0;
}