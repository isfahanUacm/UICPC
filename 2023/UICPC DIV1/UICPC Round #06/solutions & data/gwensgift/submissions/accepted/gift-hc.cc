#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int perm[1000];
ll fact[21];

int n;
ll k;
int last;

bool cmp(int x, int y)
{
  int xx = (x - last + n+1) % (n+1);
  int yy = (y - last + n+1) % (n+1);

  return xx < yy;
}

int main()
{
  iota(perm, perm+1000, 1);
  fact[0] = 1;
  for (int i = 1; i <= 19; i++) {
    fact[i] = i * fact[i-1];
  }
  fact[20] = 1000000000000000000LL + 10;  // fake entry
  
  cin >> n >> k;
  n--;
  k--;
  
  int num = upper_bound(fact, fact+21, k) - fact;
  int start = n - num;
  int elem[20];
  copy(perm+start, perm+n, elem);

  last = (start == 0) ? 0 : perm[start-1];
  for (int i = 0; i < num; i++) {
    sort(elem, elem+num-i, cmp);
    int index = k / fact[num-1-i];
    last = perm[start+i] = elem[index];
    elem[index] = elem[num-1-i];
    k %= fact[num-1-i];
  }

  int prev = 0;
  for (int i = 0; i < n; i++) {
    int next = (perm[i] - prev + n+1) % (n+1);
    if (i) cout << ' ';
    cout << next;
    prev = perm[i];
  }
  cout << endl;
  return 0;
}
