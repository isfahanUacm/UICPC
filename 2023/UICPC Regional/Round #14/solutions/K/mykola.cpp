// @EXPECTED_RESULTS@: CORRECT

#include <stdio.h>

#define EPS 1e-6

typedef struct{
  double x;
  double y;
  double z;
} point_t;  

bool leq(double x, double y){
	return (x <= y + EPS) || (x <= y - EPS);
}

point_t cross(point_t p1, point_t p2){
	point_t ret;
	ret.x = p1.y * p2.z - p1.z * p2.y;
	ret.y = p1.z * p2.x - p1.x * p2.z;
	ret.z = p1.x * p2.y - p1.y * p2.x;
	return ret;  
}

double dot(point_t v1, point_t v2){
	return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

point_t mul(point_t p, double c){
  	point_t ret;
	ret.x = p.x * c;
	ret.y = p.y * c;
	ret.z = p.z * c;
	return ret;  
}

point_t add(point_t p1, point_t p2){
	point_t ret;
	ret.x = p1.x + p2.x;
	ret.y = p1.y + p2.y;
	ret.z = p1.z + p2.z;
	return ret;
}

point_t sub(point_t p1, point_t p2){
	point_t ret;
	ret.x = p1.x - p2.x;
	ret.y = p1.y - p2.y;
	ret.z = p1.z - p2.z;
	return ret;
}

void prn(point_t p){
 printf("(%.3lf, %.3lf, %.3lf)\n", p.x, p.y, p.z); 
}

// from the internet
bool sameside(point_t p1, point_t p2, point_t a, point_t b){
	point_t c1 = cross(sub(b,a), sub(p1,a));
	point_t c2 = cross(sub(b,a), sub(p2,a));
	double d = dot(c1,c2);
	return leq(0, d);
}
bool inside(point_t p, point_t a, point_t b, point_t c){
	return sameside(p, a, b, c) && sameside(p, b, a, c) && sameside(p, c, a, b);
}

int main(){
  int cases;
  scanf("%d", &cases);
  
  point_t points[6];
  while(cases-->0){
	for ( int i = 0; i < 6; i++ ){
		scanf("%lf%lf%lf", &points[i].x, &points[i].y, &points[i].z);
		//prn(points[i]);
	}
	//printf("----\n");
	//prn(sub(points[1],points[0]));
	//prn(sub(points[2],points[0]));
	// normal representation
	point_t n1 = cross(sub(points[1],points[0]), sub(points[2],points[0]));
	//prn(n1);
	
// 	point_t n2 = cross(sub(points[4],points[3]), sub(points[5],points[3]));
// 	prn(n2);
	
	// find the intersections of segments with the plane
	//printf("intersection:\n");
	int n_in = 0;
	int n_out = 0;
	for ( int i = 3; i < 6; i++ ){
		int j = i < 5 ? (i + 1):3;
		point_t lv = sub(points[j], points[i]);
		if ( dot(lv, n1) == 0 ) continue;
		//prn(lv);
		double s = dot(n1, sub(points[0], points[i])) / (double) dot(n1,lv);
		//printf("%.3lf\n", s);
		point_t intersect = add(points[i],mul(lv,s));
		bool in = inside(intersect, points[0], points[1], points[2]);
		
		if ( leq(0,s) && leq(s,1) ) {
			if ( in ) n_in++;
			else n_out++;
// 			printf("segment ");
// 			prn(points[i]); printf(" , ");
// 			prn(points[j]);
// 			printf("intersects triangle-plane in ", i-2);
// 			prn(intersect);
// 			printf("  inside: %d\n", in);
		}
	}
	printf( ( n_in > 0 && n_out > 0 ) ? "YES\n":"NO\n");
  }// cases
  
}