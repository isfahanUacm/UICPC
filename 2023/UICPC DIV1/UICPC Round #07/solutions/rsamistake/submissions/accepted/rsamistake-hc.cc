#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MAX = 1000000;
bool isprime[MAX+1];
vector<ll> prime;

void init()
{
  isprime[0] = isprime[1] = false;
  fill(isprime+2, isprime+MAX+1, true);
  for (ll i = 2; i <= MAX; i++) {
    if (!isprime[i]) continue;
    prime.push_back(i);
    for (ll j = i*i; j <= MAX; j += i) {
      isprime[j] = false;
    }
  }
}

typedef pair<ll,int> pii;
vector<pii> factor(ll n)
{
  vector<pii> ans;
  for (auto p : prime) {
    int exp = 0;
    while (n % p == 0) {
      n /= p;
      exp++;
    }
    if (exp) {
      ans.emplace_back(p, exp);
    }
  }
  if (n > 1) {
    ans.emplace_back(n, 1);
  }
  return ans;
}

int main()
{
  init();
  
  ll A, B;
  cin >> A >> B;

  auto factA = factor(A), factB = factor(B);

  if (A != B &&
      factA.size() == 1 && factA[0].second == 1 &&
      factB.size() == 1 && factB[0].second == 1) {
    cout << "full credit" << endl;
    return 0;
  }

  for (auto [ p, exp ] : factA) {
    if (exp > 1) {
      cout << "no credit" << endl;
      return 0;
    }
    for (auto [ q, exp2 ] : factB) {
      if (p == q) {
	cout << "no credit" << endl;
	return 0;
      }
    }
  }
  for (auto [ p, exp ] : factB) {
    if (exp > 1) {
      cout << "no credit" << endl;
      return 0;
    }
  }

  cout << "partial credit" << endl;
  
  return 0;
}
