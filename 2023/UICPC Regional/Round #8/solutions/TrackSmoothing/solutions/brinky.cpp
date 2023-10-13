// @EXPECTED_RESULTS@: CORRECT

#include <cstdio>
#include <cmath>
#include <assert.h>

#define eps 1e-5

using namespace std;

struct p{
	double x;
	double y;
};

p ps[10000];

int main(){
	int N, tc;
	scanf("%d", &tc);
	while(tc--){
		double r;
		scanf("%lf %d", &r, &N);
		for(int i=0; i<N; ++i){
			scanf("%lf %lf", &ps[i].x, &ps[i].y);
		}
		for(int i=0; i<N; ++i){
			int ii = (i+1)%N;
			int iii = (i+2)%N;
			assert((ps[ii].x - ps[i].x) * (ps[iii].y - ps[i].y) - (ps[iii].x - ps[i].x) * (ps[ii].y - ps[i].y) >= -eps);
		}
		double l = 0;
		for(int i=0; i<N; ++i){
			double dx = ps[(i+1)%N].x - ps[i].x;
			double dy = ps[(i+1)%N].y - ps[i].y;
			l += sqrt(dx*dx + dy*dy);
		}
		double f = (l - 2.*M_PI*r) / l;
		if(f < 0)
			puts("Not possible");
		else
			printf("%.7lf\n", f);
	}
}
