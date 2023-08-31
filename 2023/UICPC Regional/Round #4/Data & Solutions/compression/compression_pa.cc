/* Sample solution for NCPC'08: Best Compression Ever
 * Author: Per Austrin
 * Algorithm: elementary 
 */
#include <cstdio>
int main(void) {
  long long N, b;
  scanf("%lld%lld", &N, &b);
  printf("%s\n", ((2LL<<b)-1 >= N) ? "yes" : "no");
  return 0;
}
