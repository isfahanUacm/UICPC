/*
 * @EXPECTED_RESULTS@: TIMELIMIT
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Generate possible dice throws */
void init_dice(int num, int *dice, int *d) {
  memset(dice, 0, sizeof(int)*6);
  dice[0] = num;
  memset(d, 0, sizeof(int)*8);
}

bool next_dice(int num, int *dice, int *d) {
  int i = 0;
  while(i < num) {
    dice[d[i]]--;
    d[i]++;
    if(d[i] == 6) d[i] = 0;
    dice[d[i]]++;
    if(d[i] > 0) return true;
    i++;
  }
  return false;
}

/* Recursive approach with memoization */
bool done[41][8][1<<6];
double mem[41][8][1<<6];

double rec(int tg, int nd, int ch) {
  int i, curs;
  double best, curp;
  int dice[6], d[8];
  if(tg < 0) tg = 0;
  if(tg == 0 && (ch & (1<<5))) return 1;
  if(done[tg][nd][ch])
    return mem[tg][nd][ch];
  done[tg][nd][ch] = true;
  mem[tg][nd][ch] = 0;
  init_dice(nd, dice, d);
  int num_throws = 0;
  do {
    best = 0;
    for(i = 0; i < 6; i++) {
      if(!dice[i]) continue;
      if(ch & (1<<i)) continue;
      curs = i == 5 ? 5 : i + 1;
      curp = rec(tg - dice[i] * curs, nd - dice[i], ch | (1<<i));
      best = MAX(best, curp);
    }
    mem[tg][nd][ch] += best;
    num_throws += 1;
  } while(next_dice(nd, dice, d));

  mem[tg][nd][ch] /= (double)num_throws;

  return mem[tg][nd][ch];
}

int main() {
  int t, n, i;
  memset(done, false, sizeof(done));
  scanf("%d\n", &t);
  while(t--) {
    scanf("%d\n", &n);
    printf("%lf\n", rec(n, 8, 0));
  }
  return 0;
}
