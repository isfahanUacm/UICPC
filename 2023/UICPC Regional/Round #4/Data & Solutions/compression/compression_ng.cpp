/* Sample solution for NCPC'08: Best Compression Ever
 * Author: Nils Grimsmo
 */
#include <cstdio>

// Your friends fantastic compression program has to store your file's 
// contents in it's program text somehow.  But to recognize each of your
// files, it must be able to separate them.  So the question is how many
// unique files of length at most b bits can you have?

int main() {
  long long N;
  int b;
  scanf("%lld %d", &N, &b);
  // Can have compressed files of lengths 0, ..., b.
  // 2^b unique files of length b, 2^(b-1) unique of length b-1, etc..
  // sum_{i=0..b} 2^i = 2^{b+1} - 1
  // Use binary shift left for power base 2
  if ((1LL << (b+1)) - 1 >= N ) printf("yes\n");
  else                          printf("no\n"); 
}
