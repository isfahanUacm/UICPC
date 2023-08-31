/* Sample solution for NCPC'08: Event planning
 * Author: Nils Grimsmo
 */
#include <cstdio>

int main() {
  // Num participants, bugdet, num hotels, num weekends
  int N, B, H, W; scanf("%d %d %d %d", &N, &B, &H, &W);
  int minimum = B + 1; // Large enough...
  for (int h = 0; h < H; ++h) {
    int p; scanf("%d", &p);  // Price
    for (int w = 0; w < W; ++w) {
      int a; scanf("%d", &a); // Availability
      if (a >= N && N * p < minimum) {
        minimum = N * p;
      }
    }
  }
  if (minimum <= B) printf("%d\n", minimum);
  else              printf("stay home\n");
}
