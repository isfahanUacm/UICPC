#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<ll, ll> pii;
string name = "ABC";

void do_step(pii fort[3])
{
  ll S[3];
  for (int i = 0; i < 3; i++) {
    S[fort[i].second] = fort[i].first;
  }

  ll H[3] = {0};
  for (int i = 0; i < 3; i++) {
    int kill = (i+1) % 3;
    if (S[(i+2) % 3] > S[kill]) {
      kill = (i+2) % 3;
    }
    H[kill]++;
  }
  for (int i = 0; i < 3; i++) {
    fort[i].first -= H[fort[i].second];
  }
}

void print(pii ans)
{
  cout << name[ans.second] << ' ' << ans.first << endl;
}

void solve(pii fort[3])
{
  while (true) {
#ifdef DEBUG
    for (int i = 0; i < 3; i++) {
      cout << "(" << name[fort[i].second] << ", " << fort[i].first << ") ";
    }
    cout << endl;
#endif
        
    sort(fort, fort+3);

    // all the same, everyone destroyed
    if (fort[0].first == fort[2].first) {
      cout << "Rubble!" << endl;
      return;
    }

    // only one left
    if (fort[0].first == 0 && fort[1].first == 0) {
      print(fort[2]);
      return;
    }

    // two left
    if (fort[0].first == 0) {
      if (fort[1].first == fort[2].first) {
	cout << "Rubble!" << endl;
      } else {
	fort[2].first -= fort[1].first;
	print(fort[2]);
      }
      return;
    }

    ll d1 = fort[2].first - fort[1].first;
    ll d2 = fort[1].first - fort[0].first;

    if (((d1 == 0 && d2 == 1) || (d1 == 1 && d2 == 0)) && fort[0].first > 2) {
      // every 3 steps we reduce everyone by 3
      ll S = fort[0].first / 3;
      for (int i = 0; i < 3; i++) {
	fort[i].first -= S*3;
      }
    } else if (d1 == 0 && d2 >= 3 && fort[1].first >= 3) {
      // every 2 steps we reduce top 2 by 3
      ll S = min(d2 / 3, fort[1].first / 3);
      for (int i = 1; i < 3; i++) {
	fort[i].first -= S*3;
      }
    } else if (d1 >= 4 && d2 == 0 && fort[0].first > 1) {
      // every 2 steps drop highest by 4 and each lowest 1 by 1
      ll S = min(d1 / 4, fort[0].first-1);
      fort[0].first -= S;
      fort[1].first -= S;
      fort[2].first -= 4*S;
    } else if (d1 > 0 && d2 > 0) {
      // if a, b, c are the strength with a > b > c > 0, then we can jump
      // S steps.  Got to make sure that a' >= b' and b' >= c' after each
      // step.  So
      //
      //   a - 2S >= b - S >= c, or
      //
      //   S <= a-b = d1 and S <= b-c = d2, or S <= min(d1, d2)
      ll S = min(d1, d2);
      fort[2].first -= 2*S;
      fort[1].first -= S;
    } else {
      do_step(fort);
    }
  }
}

int main()
{
  pii fort[3];

  for (int i = 0; i < 3; i++) {
    cin >> fort[i].first;
    fort[i].second = i;
  }

  solve(fort);
  
  return 0;
}
