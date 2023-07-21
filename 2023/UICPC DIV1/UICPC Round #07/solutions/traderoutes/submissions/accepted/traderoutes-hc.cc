#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

vector<int> G[300000]; // CHANGED BY ZAC FOR NEW INPUT SIZE LIMIT
vector<int> b;
vector<ll> v;

typedef pair<int, int> pii;
typedef priority_queue<pii, vector<pii>, greater<pii>> PQ;
int N;

PQ f(int root)
{
  PQ pq;
  if (b[root] == 0) {
    return pq;
  }

  pq.emplace(v[root], root);

  for (auto child : G[root]) {
    auto pq_child = f(child);
    if (pq.size() < pq_child.size()) {
      pq.swap(pq_child);
    }
    while (pq.size() > b[root]) {
      pq.pop();
    }
    while (!pq_child.empty()) {
      auto p = pq_child.top();
      pq_child.pop();
      pq.push(p);
      if (pq.size() > b[root]) {
	pq.pop();
      }
    }
  }
  assert(pq.size() <= b[root]);

  return pq;
}

int main()
{
  cin >> N;
  b.resize(N);
  v.resize(N);
  for (int i = 1; i < N; i++) {
    int p;
    cin >> p;
    --p; // ADDED BY ZAC TO ACCOMMODATE THE 0-BASED INDEXING SHIFT
    G[p].push_back(i);
  }
  for (auto &x : b) {
    cin >> x;
  }
  for (auto &x : v) {
    cin >> x;
  }

  auto pq = f(0);
  vector<int> cities;
  ll total = 0;
  while (!pq.empty()) {
    auto [val, id] = pq.top();
    pq.pop();
    cities.push_back(id);
    total += val;
  }
  sort(begin(cities), end(cities));
  cout << total << endl;
  cout << cities.size() << ' ';
  for (auto c : cities) {
    cout << c+1 << ' '; // ZAC EDIT: +1 for new indexing
  }
  cout << endl;

  return 0;
}
