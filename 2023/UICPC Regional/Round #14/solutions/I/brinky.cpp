// @EXPECTED_RESULTS@: CORRECT
#include <cstdio>
#include <cstring>
#include <cstdio>

using namespace std;

long long tab[20][2][20];

char first[22];
char ref[22];

int main(){
	int tc;
	scanf("%d", &tc);
	while(tc--){
		long long m, z, r;
		scanf("%lld %lld %lld", &m, &z, &r);
		sprintf(first, "%lld", m-1);
		sprintf(ref, "%lld", z);
		int l = strlen(first);
		int t = strlen(ref);
		memmove(ref + l - t, ref, t+1);
		memset(ref, '0', l-t);
		memset(tab, 0, sizeof(tab));
		tab[0][1][0] = 1;
		for(int i=0; i<l; ++i){
			for(int j=0; j<r; ++j){
				tab[i+1][0][j+1] += tab[i][0][j];
				tab[i+1][0][0] += 9 * tab[i][0][j];
			}
			tab[i+1][0][r] += 10 * tab[i][0][r];
			
			for(int j=0; j<r; ++j){
				if(ref[i] == first[i]){
					tab[i+1][1][j+1] += tab[i][1][j];
					tab[i+1][0][0] += (first[i] - '0') * tab[i][1][j];
				}else if(ref[i] < first[i]){
					tab[i+1][1][0] += tab[i][1][j];
					tab[i+1][0][j+1] += tab[i][1][j];
					tab[i+1][0][0] += (first[i] - '0' - 1) * tab[i][1][j];
				}else{
					tab[i+1][1][0] += tab[i][1][j];
					tab[i+1][0][0] += (first[i] - '0') * tab[i][1][j];
				}
			}
			tab[i+1][1][r] += tab[i][1][r];
			tab[i+1][0][r] += (first[i] - '0') * tab[i][1][r];
		}
		printf("%lld\n", tab[l][0][r] + tab[l][1][r]);
	}
}
