// Runs in O(n log n) time. Could work a bit harder to make it linear.

#include <bits/stdc++.h>

using namespace std;


int main() {
  int n;
  cin >> n;

  vector<int> v(n);
  vector<bool> alive(n, true);
  list<int> q;
  vector<list<int>::iterator> q_it;
  set<int> lookat;

  for (int i = 0; i < n; ++i) {
    cin >> v[i];
    lookat.insert(i);
    q.push_back(i);
    q_it.push_back(prev(q.end()));
  }

  vector<vector<int>> rounds;

  /* INVARIANTS:
     alive[i] == true IFF i is in the linked list q
     i in lookat IFF alive[i] == true and either this is the first round or
       a neighbour of i was deleted last round.
  */
  while (lookat.size()) {
    set<int> nlookat;
    vector<int> round;

    for (int i : lookat) {
      assert(alive[i]);

      auto it = q_it[i];

      // check adjacent entries to see if candidate i should leave the queue
      if (it != q.begin() && v[*it] < v[*prev(it)]) alive[i] = false;
      if (next(it) != q.end() && v[*it] < v[*next(it)]) alive[i] = false;

      // if they will leave the queue, record this and flag its neighbours
      // for "lookat" next round
      if (!alive[i]) {
        round.push_back(i);
        if (it != q.begin()) nlookat.insert(*prev(it));
        if (next(it) != q.end()) nlookat.insert(*next(it));
      }
    }

    // if i was killed, we now actually remove it from the queue
    for (int i : lookat) if (!alive[i]) q.erase(q_it[i]);

    sort(round.begin(), round.end());

    if (round.size()) rounds.push_back(round);

    // now only keep the "tagged" entries that did not die
    lookat.clear();
    for (int i : nlookat) if (alive[i]) lookat.insert(i);
  }

  cout << rounds.size() << endl;
  rounds.push_back(vector<int>(q.begin(), q.end()));

  for (const auto& round : rounds)
    for (int i = 0; i < round.size(); ++i)
      cout << v[round[i]] << (i+1 == round.size() ? '\n' : ' ');

  return 0;
}
