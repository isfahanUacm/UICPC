#include <bits/stdc++.h>

using namespace std;

void insert2(string &s)
{
  int sum = 0;
  int count2 = 0;
  int n = s.length();
  for (int i = n-1; i >= 0; i--) {
    sum += s[i] - '0';
    if (s[i] == '2') {
      count2++;
    } else {
      if (count2 % 2) {
	s.insert(i+1, "2");
	sum += 2;
      }
      count2 = 0;
    }
  }
  if (count2 % 2) {
    s.insert(0, "2");
    sum += 2;
  }
  assert(sum % 4 == 0);
}

void insert4(string &s)
{
  // special case if s = "22", don't do anything
  if (s == "22")
    return;
  
  int sum = 0;
  int count4 = 0;
  int n = s.length();
  reverse(s.begin(), s.end());
  for (int i = n-1; i >= 0; i--) {
    sum += s[i] - '0';
    
    if (s[i] == '2') {
      count4++;
    } else if (s[i] == '4') {
      count4 += 2;
    } else {
      count4 /= 2;
      if (count4 % 2) {
	s.insert(i+1, "4");
	sum += 4;
      }
      count4 = 0;
    }
  }
  count4 /= 2;
  if (count4 % 2) {
    s.insert(0, "4");
    sum += 4;
  }
  reverse(s.begin(), s.end());
  assert(sum % 8 == 0);
}

void insert8(string &s)
{
  int sum = 0;
  int n = s.length();

  for (int i = 0; i < n; i++) {
    sum += s[i] - '0';
  }

  int pow2 = 1;
  while (pow2 < sum) {
    pow2 <<= 1;
  }
  s += string((pow2-sum)/8, '8');
}

void solve()
{
  string s;
  cin >> s;

  if (s.length() > 1) {
    insert2(s);
    insert4(s);
    insert8(s);
  }
  cout << s << endl;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
    solve();
     
  return 0;
}
