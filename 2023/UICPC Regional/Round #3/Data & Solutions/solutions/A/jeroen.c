/*
 * @EXPECTED_RESULTS@: CORRECT
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAX(a,b) ((a) > (b) ? (a) : (b))

/* Faculty function, only works for small numbers */
int fac(int i) {
	int ret = 1;
	while(i > 1) {
		ret *= i;
		i--;
	}
	return ret;
}

/* Generate possible dice throws */
void init_dice(int num, int *dice) {
	memset(dice, 0, sizeof(int)*6);
	dice[0] = num;
}

bool next_dice(int num, int *dice) {
	int i, j, oi;
	if(dice[5] == num) return false;
	for(i = 5; !dice[i]; i--);
	if(i == 5) {
		for(j = i - 1; !dice[j]; j--);
		dice[j]--;
		oi = dice[i];
		dice[i] = 0;
		dice[j+1] = oi + 1;
	} else {
		dice[i]--;
		dice[i+1]++;
	}
	return true;
}

/* In how many ways can we throw this? */
double throw_prob(int num, int *dice) {
	int i;
	double ret = fac(num);
	for(i = 0; i < 6; i++)
		ret /= (double)fac(dice[i]);
	return ret;
}

/* Recursive approach with memoization */
bool done[41][8][1<<6];
double mem[41][8][1<<6];

double rec(int tg, int nd, int ch) {
	int i, curs;
	double best, curp, tp;
	int dice[6];
	if(tg < 0) tg = 0;
	if(tg == 0 && (ch & (1<<5))) return 1;
	if(done[tg][nd][ch])
		return mem[tg][nd][ch];
	done[tg][nd][ch] = true;
	mem[tg][nd][ch] = 0;
	init_dice(nd, dice);
	double total_prop = 0;
	do {
		best = 0;
		for(i = 0; i < 6; i++) {
			if(!dice[i]) continue;
			if(ch & (1<<i)) continue;
			curs = i == 5 ? 5 : i + 1;
			curp = rec(tg - dice[i] * curs, nd - dice[i], ch | (1<<i));
			best = MAX(best, curp);
		}
		tp = throw_prob(nd, dice);
		mem[tg][nd][ch] += best * tp;
		total_prop += tp;
	} while(next_dice(nd, dice));

	mem[tg][nd][ch] /= total_prop;

	return mem[tg][nd][ch];
}

int main() {
	int t, n;
	memset(done, false, sizeof(done));
	scanf("%d\n", &t);
	while(t--) {
		scanf("%d\n", &n);
		printf("%lf\n", rec(n, 8, 0));
	}
	return 0;
}
