#include <iostream>
using namespace std;

const int NB_ANGLES = 360;
const int NB_RADII = 20;

bool seen[NB_ANGLES][NB_RADII];
int circular[NB_ANGLES][NB_RADII];
int straight[NB_ANGLES][NB_RADII-1];

void dfs(int t, int r)
{
  t = (t % NB_ANGLES + NB_ANGLES) % NB_ANGLES;
  if (seen[t][r]) return;
  seen[t][r] = true;
  //cerr << t << " "<< r << endl;
  if (r > 0 && !circular[t][r]) dfs(t, r-1);
  if (r < NB_RADII-2 && !circular[t][r+1]) dfs(t, r+1);
  if (!straight[t][r]) dfs(t-1, r);
  if (!straight[(t+1)%NB_ANGLES][r]) dfs(t+1, r);
}

int main()
{
  int T; cin >> T;
  for (int test=0; test<T; test++)
  {
    for (int t=0; t<NB_ANGLES; t++)
    for (int r=0; r<NB_RADII; r++)
    {
      seen[t][r] = false;
      circular[t][r] = false;
      if (r < NB_RADII-1)
        straight[t][r] = false;
    }
    int N; cin >> N;
    for (int i=0; i<N; i++)
    {
      string s; cin >> s;
      if (s == "C")
      {
        int r, t1, t2; cin >> r >> t1 >> t2;
        if (t2 < t1) t2 += NB_ANGLES;
        for (int t=t1; t<t2; t++)
          circular[t%NB_ANGLES][r-1] = true;
      }
      if (s == "S")
      {
        int r1, r2, t; cin >> r1 >> r2 >> t;
        for (int r=r1; r<r2; r++)
          straight[t][r-1] = true;
      }
    }
    for (int t=0; t<NB_ANGLES; t++)
      if (!circular[t][0])
        dfs(t, 0);
    bool ok = false;
    for (int t=0; t<NB_ANGLES; t++)
      if (!circular[t][NB_RADII-1])
        ok |= seen[t][NB_RADII-2];
    cout << (ok ? "YES" : "NO") << endl;
  }
}
