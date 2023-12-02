// @EXPECTED_RESULTS@: CORRECT
#include <cstdio>
#include <cmath>

using namespace std;

double p[2][3][3];
double v[2][3];
double t[3];
double b[2][3];

#define eps 1e-5

void k(double v[3], double p0[3], double p1[3]){
	double l = 0;
	for(int i=0; i<3; ++i){
		int j = (i+1) % 3;
		int k = (i+2) % 3;
		v[i] = p0[j] * p1[k] - p0[k] * p1[j];
		l += v[i] * v[i];
	}
	l = sqrt(l);
	for(int i=0; i<3; ++i)
		v[i] /= l;
}

void k(double v[3], double p[3][3]){
	double t[2][3];
	for(int i=0; i<3; ++i)
		t[0][i] = p[1][i] - p[0][i];
	for(int i=0; i<3; ++i)
		t[1][i] = p[2][i] - p[0][i];
	k(v, t[0], t[1]);
}

void k(double v[3], double x[3], double p0[3], double p1[3]){
	double t[3];
	for(int i=0; i<3; ++i)
		t[i] = p1[i] - p0[i];
	k(v, x, t);
}

double s(double p0[3], double p1[3]){
	double r = 0;
	for(int i=0; i<3; ++i)
		r +=  p0[i] * p1[i];
	return r;
}

double s(double p0[3], double p1[3], double p2[3]){
	double t[3];
	for(int i=0; i<3; ++i)
		t[i] = p1[i] - p0[i];
	return s(t, p2);
}

int ccw(double p0[2], double p1[2], double p2[2]){
	double a;
	a = (p1[0] - p0[0]) * (p2[1] - p0[1]) - (p2[0] - p0[0]) * (p1[1] - p0[1]);
	return abs(a) <= eps ? 0 : a < 0 ? -1 : 1;
}

void print(double v[3][3]){
	printf("polyhedron({");
    printf("points: [ [%lf, %lf, %lf], [%lf, %lf, %lf], [%lf, %lf, %lf] ],\n", v[0][0], v[0][1], v[0][2], v[1][0], v[1][1], v[1][2], v[2][0], v[2][1], v[2][2]);
	printf("triangles: [ [0, 1, 2] ]})\n");
}

int main(){
	int n;
	scanf("%d", &n);
	while(n--){
		for(int i=0; i<18; ++i)
			scanf("%lf", &p[0][0][i]);
		for(int i=0; i<2; ++i)
			k(v[i], p[i]);
		k(t, v[0], v[1]);
		//printf("v %lf %lf %lf\n", v[0][0], v[0][1], v[0][2]);
		//printf("v %lf %lf %lf\n", v[1][0], v[1][1], v[1][2]);
		if(abs(t[0]) < eps && abs(t[1]) < eps && abs(t[2]) < eps){
			puts("NO");
			continue;
		}
		//print(p[0]);
		//print(p[1]);

		
		int count = 0;
		for(int i=0; i<3; ++i){
			int j = (i+1) % 3;
			double s0, s1;
			double t[3];
			s0 = s(p[1][i], p[0][0], v[0]);
			s1 = s(p[1][j], p[0][0], v[0]);
			if(abs(s0-s1) < eps){
				continue;
			}
			if(abs(s1) < eps){
				continue;
			}
			if(abs(s0) < eps){
				for(int k=0; k<3; ++k)
					t[k] = p[1][i][k];
			}else{
				double sd = (-s0)/(s1-s0);
				//printf("s %lf %lf %lf\n", s0, s1, sd);
				if(sd < 0 || sd > 1)
					continue;
				for(int kk=0; kk<3; ++kk)
					t[kk] = (1-sd) * p[1][i][kk] + sd * p[1][j][kk];
				//printf("%lf %lf %lf\n", p[1][i][0], p[1][i][1], p[1][i][2]);
				//printf("%lf %lf %lf\n", p[1][j][0], p[1][j][1], p[1][j][2]);
				//printf("%lf %lf %lf\n", t[0], t[1], t[2]);
				k(b[0], v[0], p[0][0], p[0][1]);
				k(b[1], v[0], b[0]);
				double d[4][2];
				for(int kk=0; kk<2; ++kk){
					d[0][kk] = 0;
					d[1][kk] = s(p[0][0], p[0][1], b[kk]);
					d[2][kk] = s(p[0][0], p[0][2], b[kk]);
					d[3][kk] = s(p[0][0], t, b[kk]);
				}
				//printf("2D %lf %lf, %lf %lf, %lf %lf: %lf %lf\n", d[0][0], d[0][1], d[1][0], d[1][1], d[2][0], d[2][1], d[3][0], d[3][1]);
				int cc = ccw(d[0], d[1], d[2]);
				//printf("cc %d\n", cc);
				for(int ii=0; ii<3; ++ii){
					int jj = (ii+1) % 3;
					//printf("cc  %d\n", ccw(d[ii], d[jj], d[3]));
					if(ccw(d[ii], d[jj], d[3]) != cc){
						cc=0;
						break;
					}
				}
				if(cc)
					++count;
			}
		}
		if(count % 2)
			puts("YES");
		else
			puts("NO");
	}
}
