// @EXPECTED_RESULTS@: CORRECT
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<cmath>

double T[4][4];
const double eps=1e-6;

struct point {double x,y,z;};
point p[4], q[4], v, ttemp;

void transform(point& res) {
      point in_point;
      in_point=res;
      res.x = T[1][1]*in_point.x+T[1][2]*in_point.y+T[1][3]*in_point.z;
      res.y = T[2][1]*in_point.x+T[2][2]*in_point.y+T[2][3]*in_point.z;
      res.z = T[3][1]*in_point.x+T[3][2]*in_point.y+T[3][3]*in_point.z;
}
	
int cuts(point a, point b, double& x, double& y) {
      int res=0;
      if (fabs(a.z) < eps ) {x=a.x; y=a.y; res=2;}
      else if (fabs(b.z) < eps ) {x=b.x; y=b.y; res=1;}
        else if ((a.z*b.z)<0){
	x = (-a.z)*(b.x-a.x)/(b.z-a.z) + a.x;
	y = (-a.z)*(b.y-a.y)/(b.z-a.z) + a.y;
	res=1;
//	printf("**** cut: %lf  %lf \n", x,y);
	}
      return(res);
}

int inside(double x, double y) {
      int res=0;
      if ((0<x) && (x<1) && (0<y) && (y<1) && ((x+y)< 1)) 
        {res=1;}
      return(res);
}
	
 int main(){ 
      int NumberOfCases,current_case, i,j1,j2,j3,k;
      double cutx[4],cuty[4];
      double det;
      double xx,yy;

      scanf("%d", &NumberOfCases);     
      for (current_case = 1; current_case <= NumberOfCases; current_case++) {
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &p[1].x,&p[1].y,&p[1].z, &p[2].x,&p[2].y,&p[2].z,&p[3].x,&p[3].y,&p[3].z);
	scanf("%lf %lf %lf %lf %lf %lf %lf %lf %lf", &q[1].x,&q[1].y,&q[1].z, &q[2].x,&q[2].y,&q[2].z,&q[3].x,&q[3].y,&q[3].z);

	p[2].x-=p[1].x; p[3].x-=p[1].x; q[1].x-=p[1].x; q[2].x-=p[1].x; q[3].x-=p[1].x;
	p[2].y-=p[1].y; p[3].y-=p[1].y; q[1].y-=p[1].y; q[2].y-=p[1].y; q[3].y-=p[1].y;
	p[2].z-=p[1].z; p[3].z-=p[1].z; q[1].z-=p[1].z; q[2].z-=p[1].z; q[3].z-=p[1].z;
	p[1].x=0;p[1].y=0;p[1].z=0;
	
	v.x=p[2].y*p[3].z-p[2].z*p[3].y;
	v.y=-(p[2].x*p[3].z-p[2].z*p[3].x);
	v.z=p[2].x*p[3].y-p[2].y*p[3].x;

	det = p[2].x*p[3].y*v.z + p[2].y*p[3].z*v.x + p[3].x*v.y*p[2].z - v.x*p[3].y*p[2].z - v.y*p[3].z*p[2].x - p[2].y*p[3].x*v.z;
	T[1][1]=(p[3].y*v.z-p[3].z*v.y)/det; T[1][2]=(v.x*p[3].z-p[3].x*v.z)/det; T[1][3]=(p[3].x*v.y-v.x*p[3].y)/det;
	T[2][1]=(v.y*p[2].z-p[2].y*v.z)/det; T[2][2]=(p[2].x*v.z-p[2].z*v.x)/det; T[2][3]=(v.x*p[2].y-p[2].x*v.y)/det;
	T[3][1]=(p[2].y*p[3].z-p[3].y*p[2].z)/det; T[3][2]=(p[3].x*p[2].z-p[2].x*p[3].z)/det; T[3][3]=(p[2].x*p[3].y-p[2].y*p[3].x)/det;
	
	transform(p[2]); 
	transform(p[3]);
	transform(q[1]);
	transform(q[2]);
	transform(q[3]);
	
	if ( (fabs(q[1].z) < eps ) && (fabs(q[2].z) < eps ) && (fabs(q[3].z) < eps ) ) {printf("NO\n");}
	  else{
	    i=0;
	    j1 = cuts(q[1],q[2],xx,yy);
	    if (j1>0) { i++; cutx[i]=xx; cuty[i]=yy;}
	    j2 = cuts(q[1],q[3],xx,yy);
	    if ((j2==1) || ((j2==2) && (j1<2)) ) {i++; cutx[i]=xx; cuty[i]=yy;}
	    j3 = cuts(q[2],q[3],xx,yy);
	    if (i<2) { i++; cutx[i]=xx; cuty[i]=yy;}
	    if (i<2) {printf("NO\n");}
	    else {
	      if ( (inside(cutx[1],cuty[1])+inside(cutx[2],cuty[2]))==1) {printf("YES\n");}
	        else {printf("NO\n");}
	    }
	    
	  }
      }          
      return 0;
}
     
