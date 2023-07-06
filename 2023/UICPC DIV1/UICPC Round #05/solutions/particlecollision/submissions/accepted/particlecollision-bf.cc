#include<iostream>
#include<utility>
#include<cmath>
#include<vector>
#include<algorithm>

using namespace std;

const double EPS = 1E-12;

struct Point{
   double x,y;
};

double r;

pair<double,double> timet(Point p1, Point dir, Point p2){
   double a = dir.x*dir.x + dir.y*dir.y;
   double b = 2*((p1.x-p2.x)*dir.x + (p1.y-p2.y)*dir.y);
   double c = p1.x*p1.x - 2*p1.x*p2.x + p2.x*p2.x + p1.y*p1.y - 2*p1.y*p2.y
      + p2.y*p2.y - 4*r*r;
   if(b*b - 4*a*c <= -EPS)
      return make_pair(-1.0, -1.0);
   else if(b*b - 4*a*c >= EPS)
      return make_pair((-b + sqrt(b*b-4*a*c))/(2*a), (-b - sqrt(b*b-4*a*c))/(2*a));
   else
      return make_pair(-b / (2*a), -1.0);
}

int main(){
   Point p[3], dir;
   for(int i = 0; i < 3; i++){
      cin >> p[i].x >> p[i].y;
   }
   cin >> dir.x >> dir.y >> r;

   
   pair<double, double> t1 = timet(p[0],dir,p[1]),t2 = timet(p[0], dir, p[2]);
   vector< pair<double, int> > V;
   if(t1.first >= 0)
      V.push_back(make_pair(t1.first,1));
   if(t1.second >= 0)
      V.push_back(make_pair(t1.second,1));
   if(t2.first >= 0)
      V.push_back(make_pair(t2.first,2));
   if(t2.second >= 0)
      V.push_back(make_pair(t2.second,2));
   sort(V.begin(), V.end());

   //for(int i = 0; i < (int)V.size(); i++){
   //cerr << V[i].first << endl;
   //}
   if(V.size() == 0)
      cout << 5 << endl;
   else{
      int last;
      if(V[0].second == 1){
	 last = 2;
      }
      else{
	 last = 1;
      }
      dir.x = p[V[0].second].x - (p[0].x + V[0].first*dir.x);
      dir.y = p[V[0].second].y - (p[0].y + V[0].first*dir.y);
      t1 = timet(p[V[0].second],dir,p[last]);
      if(t1.first >= 0 or t1.second >= 0){
	 if(last == 2){
	    cout << 1 << endl;
	 }
	 else{
	    cout << 2 << endl;
	 }
      }
      else{
	 if(last == 2){
	    cout << 3 << endl;
	 }
	 else{
	    cout << 4 << endl;
	 }
      }
   }
   return 0;
}
