// @EXPECTED_RESULTS@: CORRECT
#include <cstdio>
#include <cstring>
#include <cstdio>

using namespace std;

long long tab[20][2][20];

char first[22];
char ref[22];
int R;

long long rek_m(int i, int r){
	if(i == 0)
		return (r == 0) ? 1 : 0;
	if(tab[i][1][r] != -1)
		return tab[i][1][r];
	long long &t = tab[i][1][r];
	
	t = 0;
	if(r == 0){
		if(first[i-1] != ref[i-1]){
			for(int j=0; j<R; ++j){
				t += rek_m(i-1, j);
			}
		}
	}else{
		if(first[i-1] == ref[i-1]){
			t += rek_m(i-1, r-1);
		}
		if(r==R){
			t += rek_m(i-1, r);
		}
	}
	//fprintf(stderr, "m %d %d = %d\n", i, r, t);
	return t;
}

long long rek(int i, int r){
	//fprintf(stderr, "r %d %d\n", i, r);
	if(i == 0)
		return 0;
	if(tab[i][0][r] != -1)
		return tab[i][0][r];
	//fprintf(stderr, "n\n");
	
	long long &t = tab[i][0][r];
	t = 0;
	if(r == 0){
		for(int j=0; j<R; ++j){
			t += 9* rek(i-1, j);
			//fprintf(stderr, "c %c %c (%d %d)\n", ref[i-1] , first[i-1], i, r);
			if(ref[i-1] < first[i-1]){
				t += (first[i-1] - '0' - 1) * rek_m(i-1, j);
			}else{
				t += (first[i-1] - '0') * rek_m(i-1, j);
			}
		}
	}else{
		t += rek(i-1, r-1);
		if(first[i-1] > ref[i-1]){
			t += rek_m(i-1, r-1);
		}
		if (r == R){
			t += 10 * rek(i-1, r);
			t += (first[i-1] - '0') * rek_m(i-1, r);
		}
	}
	//fprintf(stderr, "r %d %d = %d\n", i, r, t);
	return t;
}

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		long long m, z, r;
		scanf("%lld %lld %lld", &m, &z, &r);
		R = r;
		sprintf(first, "%lld", m-1);
		sprintf(ref, "%lld", z);
		int l = strlen(first);
		int t = strlen(ref);
		memmove(ref + l - t, ref, t+1);
		memset(ref, '0', l-t);
		memset(tab, -1, sizeof(tab));
		printf("%lld\n", rek(l, r) + rek_m(l, r));
	}
}
