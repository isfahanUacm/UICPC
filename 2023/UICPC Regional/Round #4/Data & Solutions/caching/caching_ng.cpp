/* Sample solution for NCPC'08: Introspective caching
 * Author: Nils Grimsmo
 *
 * Solution: - When needing to evict something from cache, select the object
 *             that won't be used in the longest time.
 *           - Maintain some data structures which can tell you which one this
 *             is.
 *
 * Running time: O(a log c)
 */
#include <cstdio>
#include <deque>
#include <map>
#include <set>
#include <vector>

using namespace std;

int main() {
  int c, n, a; scanf("%d %d %d", &c, &n, &a);
  vector<int> A;            // Which elements are accessed in the order.
  vector<deque<int> > T(n); // At what "times" are each object accessed.
  for (int t = 0; t < a; ++t) {
    int x; scanf("%d", &x); // Will read x at time t
    A.push_back(x);
    T[x].push_back(t);
  }
  int r = 0;      // Number of reads.
  set<int> R;     // Resident set.
  map<int,int> N; // Mapping from next time an object is accessed to
                  // which object it is, for resident objects.
  for (int t = 0 ; t < a; ++t) {
    int x = A[t];
    if (R.count(x) == 0) {
      if ((int)R.size() >= c) { 
        // Who to evict?  The one who won't be used for the longest time.
        int xe = N.rbegin()->second;
        R.erase(xe);
        N.erase(T[xe].front());
      }
      R.insert(x);
      ++r;
    }
    // Update entry in N
    N.erase(t); 
    T[x].pop_front();
    if (T[x].size()) N[T[x].front()] = x; // Next time t we need x, get x
    else R.erase(x);                      // Don't need it any more
  }
  printf("%d\n", r);
}
