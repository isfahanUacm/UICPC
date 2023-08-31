/* Sample solution for NCPC'08: Just A Few More Triangles
 * Author: Per Austrin
 * Algorithm: Chinese Remaindering + Annoying But Elementary Observations
 *            Complexity O(N*log(N))
 */
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <complex>
#include <iostream>

using namespace std;
typedef long long ll;

int exp(int p, int e) {
  int P = 1;
  for (int i = 0; i < e; ++i) P *= p;
  return P;
}

int qr[600000];

// # sols (a,b,c) to a^2+b^2=c^2 (mod p^e)
ll powsols(int p, int e) {
  //if (e == 0) return 1;
  int P = exp(p, e);
  ll res = 0;
  memset(qr, 0, sizeof(qr));
  for (int i = 0; i < P; ++i) ++qr[(ll)i*i % P];
  // First count sols such that either a or b is invertible
  for (int i = 0; i < P; ++i) res += qr[i]*qr[(i+1)%P];
  for (int i = 0, sq = 0; i < P; i += p, sq = (ll)i*i % P) res += qr[(sq+1)%P];
  res *= P/p*(p-1);
  // Then add sols where all three are multiples of p
  if (e > 1) res += powsols(p, e-2)*p*p*p;
  else ++res;
  return res;
}


// # sols (a,b,c) to a^2+b^2=c^2 (mod n) such that a = 0 or b = 0 or c = 0
ll zeros(int n) {
  ll res = 1+3*qr[0];
  for (int i = 0; i < n; ++i) res += qr[i]*(2*qr[i] + qr[(n-i)%n]);
  return res;
}

// # sols (a,b,c) to a^2+b^2=c^2 (mod n) such that a = b and a != 0 and c != 0
ll diag(int n) {
  ll res = 0;
  for (int i = 1; i < n; ++i) res += qr[(ll)2*i*i % n];
  return res;
}

int main(void) {
  int N, n;
  scanf("%d", &n);
  N = n;
  long long res = 1;
  for (int p = 2; p*p <= n; ++p)
    if (n % p == 0) {
      int e = 0;
      while (n % p == 0) ++e, n /= p;
      res *= powsols(p, e);
    }
  if (n != 1) res *= powsols(n, 1);
  memset(qr, 0, sizeof(qr));
  for (int i = 1; i < N; ++i) ++qr[(long long)i*i % N];
  res -= zeros(N);
  res += diag(N);
  printf("%lld\n", res/2);
  return 0;
}
