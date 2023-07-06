#include <bits/stdc++.h>

using namespace std;

int n;
int out[1 << 20];

int f(int lvl, int path, int &count)
{
  if (lvl >= n) {
    count = 1;
    return out[path];
  }

  int count1, count2;
  int val0 = f(lvl+1, path, count1);
  int val1 = f(lvl+1, path | (1 << (lvl)), count2);

  if ((val0 | val1) == 3) {
    count = count1 + count2 + 1;
  } else {
    count = 1;
  }
  return val0 | val1;
}


int main()
{
  cin >> n;
  for (int i = 0; i < (1 << n); i++) {
    int x;
    cin >> x;
    out[i] = (1 << x);
  }

  int count;
  f(0, 0, count);
  cout << count << endl;
  
  return 0;
}
