// @EXPECTED_RESULTS@: CORRECT
#include <cstdio>
#include <algorithm>

using namespace std;

int tab[55500];
int a[100];
int b[100];
int t[100];

int main(){
	int N, T, Q;
	scanf("%d", &N);
	T = 25000;
	for(int i=0; i<N; ++i){
		scanf("%d %d %d", &a[i], &b[i], &t[i]);
	}

	for(int i=0; i<=T; ++i){
		for(int j=0; j<N; ++j){
			if(!b[j] && t[j] <= i){
				tab[i] = max(tab[i], tab[i-t[j]] + a[j]);
			}
		}
	}
	
	for(int j=0; j<N; ++j){
		if(b[j]){
			for(int k=0; a[j] > k*k*b[j]; ++k){
				for(int i=T; i>=t[j]; --i){
					tab[i] = max(tab[i], tab[i-t[j]] + a[j] - k*k*b[j]);
				}
			}
		}
	}
	
	scanf("%d", &Q);
	while(Q--){
		int q;
		scanf("%d", &q);
		printf("%d\n", tab[q]);
	}
}
