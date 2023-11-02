#include <iostream>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int substrings(const string& s) {
  unordered_set<char> chars;
  int nc = 0;
  for (const char c : s) {
    if (chars.find(c) == chars.end()) {
      ++nc;
      chars.insert(c);
    }
  }
  unordered_map<char, int> count;
  unordered_set<string> ans;
  int appear = 0;
  int i = 0;
  int j = 0;
  while (j < s.size()) {
    ++count[s[j]];
    if (count[s[j]] == 1) {
      ++appear;
    }
    if (appear == nc) {
      while (appear == nc) {
        --count[s[i]];
        ++i;
        if (count[s[i - 1]] == 0) {
          --appear;
          if (j - i + 2 != s.size()) {
            ans.insert(s.substr(i - 1, j - i + 2));
          }
          break;
        }
      }
    }
    ++j;
  }

  return ans.size();
}

int main() {
  string s;
  while (cin >> s) {
    cout << substrings(s) << endl;
  }
  return 0;
}