// @EXPECTED_RESULTS@: CORRECT
#include<cstdio>
#include<vector>
#include<cmath>
#include<cassert>
using namespace std;
long double t[3][4];
const long double EPS=1e-9;
bool solve(int z){
	for(int i=0;i<z;i++){
    int j=i;
    while(j<z&&fabs(t[j][i])<EPS)++j;
    if(j==z)return false;
    for(int k=0;k<=z;k++)swap(t[i][k],t[j][k]);
    long double mult=t[i][i];
    assert(fabs(mult)>EPS);
    for(int k=0;k<=z;k++)t[i][k]/=mult;
    for(int j=0;j<3;j++)if(j!=i&&fabs(t[j][i])>EPS){
      mult=t[j][i];
      for(int k=0;k<=z;k++)t[j][k]-=t[i][k]*mult;
      assert(fabs(t[j][i])<EPS);
    }
  }
	for(int i=z;i<3;i++)for(int j=0;j<=z;j++)if(fabs(t[i][j])>EPS)return false;
  return true;
}
typedef pair<double,double> p2;
struct point {
  int x,y,z;
  point(int _x=0,int _y=0,int _z=0):x(_x),y(_y),z(_z){}
  void read(){
    scanf("%d %d %d",&x,&y,&z);
    assert(fabs(x)<=1000);
    assert(fabs(y)<=1000);
    assert(fabs(z)<=1000);
  }
  void operator-=(const point &p){
    x-=p.x;
    y-=p.y;
    z-=p.z;
  }
	bool operator==(const point &p){
		return x==p.x&&y==p.y&&z==p.z;
	}
  void operator*=(int t){
    x*=t;
    y*=t;
    z*=t;
  }
  void print(){
    printf("x=%d y=%d z=%d\n",x,y,z);
  }
};
bool colinear(point a,point b,point c){
	a-=c;
	b-=c;
	int p,q;
	if(a.x&&b.x){
		p=b.x;
		q=a.x;
	}else if(a.y&&b.y){
		p=b.y;
		q=a.y;
	}else if(a.z&&b.z){
		p=b.z;
		q=a.z;
	}else{
		return !a.x&&!a.y&&!a.z||!b.x&&!b.y&&!b.z;
	}
	return p*a.x==q*b.x&&p*a.y==q*b.y&&p*a.z==q*b.z;
}
bool intersects(point a0,point a1,point b0,point b1){
	t[0][0]=a0.x-a1.x;
	t[0][1]=b1.x-b0.x;
	t[0][2]=b1.x-a1.x;

	t[1][0]=a0.y-a1.y;
	t[1][1]=b1.y-b0.y;
	t[1][2]=b1.y-a1.y;

	t[2][0]=a0.z-a1.z;
	t[2][1]=b1.z-b0.z;
	t[2][2]=b1.z-a1.z;

	if(!solve(2))return false;
	return t[0][2]+EPS>0&&t[0][2]<1+EPS&&t[1][2]+EPS>0&&t[1][2]<1+EPS;
}
main(){
  int T;
  scanf("%d",&T);
  assert(1<=T&&T<=1000);
  while(T--){
    point a[3],b[3];
    
    a[0].read();
    a[1].read();
    a[2].read();
		assert(!colinear(a[0],a[1],a[2]));
    a[1]-=a[0];
    a[2]-=a[0];

    b[0].read();
    b[1].read();
    b[2].read();
    assert(!colinear(b[0],b[1],b[2]));
		b[0]-=a[0];
    b[1]-=a[0];
    b[2]-=a[0];

		//no segments intersect
		for(int i=0;i<3;i++)for(int j=0;j<3;j++)assert(!intersects(a[i],a[(i+1)%3],b[j],b[(j+1)%3]));
		
		//not all on a single plane
		int cnt=0;
		for(int j=0;j<3;j++){
			t[0][0]=a[1].x;
			t[0][1]=a[2].x;
			t[0][2]=b[j].x;

			t[1][0]=a[1].y;
			t[1][1]=a[2].y;
			t[1][2]=b[j].y;

			t[2][0]=a[1].z;
			t[2][1]=a[2].z;
			t[2][2]=b[j].z;

			cnt+=solve(2);
		}
		assert(cnt<3);

    vector<p2> sol;
    for(int i=0;i<3;i++){
      point from=b[i],to=b[(i+1)%3];
      from-=to;
      from*=-1;
      // t * from + to = p a[1] + q a[2]
      // p a[1] + q a[2] + r * from  = to
//a[1].print();
//a[2].print();
//from.print();
//to.print();
      t[0][0]=a[1].x;
      t[0][1]=a[2].x;
      t[0][2]=from.x;
      t[0][3]=to.x;

      t[1][0]=a[1].y;
      t[1][1]=a[2].y;
      t[1][2]=from.y;
      t[1][3]=to.y;

      t[2][0]=a[1].z;
      t[2][1]=a[2].z;
      t[2][2]=from.z;
      t[2][3]=to.z;

      if(solve(3)&&t[2][3]+EPS>0&&t[2][3]<1+EPS){
//printf("%.3lf %.3lf %.3lf\n",(double)t[0][3],(double)t[1][3],(double)t[2][3]);
        sol.push_back(p2(t[0][3],t[1][3]));
      }
    }
    
    bool outside=false,inside=false;
    for(int i=0;i<sol.size();i++){
      bool is_inside=sol[i].first+EPS>0&&sol[i].second+EPS>0&&sol[i].first+sol[i].second<1+EPS;
      inside|=is_inside;
      outside|=!is_inside;
    }
    puts(outside&&inside?"YES":"NO");
  }
}

