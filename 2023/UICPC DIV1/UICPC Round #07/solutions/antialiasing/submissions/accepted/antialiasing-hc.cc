#include <bits/stdc++.h>

using namespace std;

//
// Fraction implementation
//
// Author: Darcy Best
//
// Does NOT ever check for division by 0.
// Division by 0 will only cause a runtime error if you use the
//   toDouble() function.
//

#include <iostream>
#include <cstdlib>
using namespace std;

// Change this to whatever integer data type will prevent overflow
//   - BigInteger works with this class
typedef long long int dataType;

class Fraction{
public:
  Fraction(dataType num=0,dataType denom=1);
	
  double toDouble() const;
	
  void reduce();
	
  // Changes the fraction itself.
  void selfReciprocal();
	
  // Returns a new fraction, leaving the original.
  Fraction reciprocal() const;
	
  Fraction& operator+=(const Fraction& x);
  Fraction& operator-=(const Fraction& x);
  Fraction& operator*=(const Fraction& x);
  Fraction& operator/=(const Fraction& x);
  Fraction& operator-();
	
  bool operator<(const Fraction& x) const;
  bool operator==(const Fraction& x) const;
	
  dataType num,denom;
};

Fraction operator+(const Fraction& x,const Fraction& y);
Fraction operator-(const Fraction& x,const Fraction& y);
Fraction operator*(const Fraction& x,const Fraction& y);
Fraction operator/(const Fraction& x,const Fraction& y);

istream& operator>>(istream& is,Fraction& x);
ostream& operator<<(ostream& os,const Fraction& x);

Fraction::Fraction(dataType n,dataType d){
  if(d < 0){
    num = -n;
    denom = -d;
  } else {
    num = n;
    denom = d;
  }
  reduce();
}

double Fraction::toDouble() const{
  return 1.0*num/denom;
}

// Howard's GCD function with no checks
dataType gcd(dataType a, dataType b)
{
  dataType r;
  while (b) {
    r = a % b;
    a = b;
    b = r;
  }
  return a;
}

void Fraction::reduce(){
  dataType g = gcd(abs(num),denom);
  num /= g;
  denom /= g;
}

void Fraction::selfReciprocal(){
  swap(num,denom);
  if (denom < 0) {
    num = -num;
    denom = -denom;
  }
}

Fraction Fraction::reciprocal() const{
  return Fraction(denom,num);
}

// Overflow potential in the denominator.
// I've tried to factor out as much as possible before,
//   But be careful.
//
//   (w)/(a*g) + (z)/(b*g)
// = (w*b)/(a*g*b) + (a*z)/(a*g*b)
// = (w*b + a*z)/(a*g*b)
Fraction& Fraction::operator+=(const Fraction& x){
  dataType g = gcd(denom,x.denom);
	
  dataType a = denom / g;
  dataType b = x.denom / g;
	
  num = num * b + x.num * a;
  denom *= b;
	
  reduce();
	
  return (*this);
}

Fraction& Fraction::operator-=(const Fraction& x){
  dataType g = gcd(denom,x.denom);
  dataType a = denom / g;
  dataType b = x.denom / g;
	
  num = num * b - x.num * a;
  denom *= b;
	
  reduce();
  return (*this);
}

Fraction& Fraction::operator*=(const Fraction& x){
  num *= x.num;
  denom *= x.denom;
  reduce();
  return (*this);
}

Fraction& Fraction::operator/=(const Fraction& x){
  num *= x.denom;
  denom *= x.num;
	
  if(denom < 0){
    num = -num;
    denom = -denom;
  }
  reduce();
  return (*this);
}

Fraction& Fraction::operator-()
{
  num *= -1;
  return *this;
}

// Careful with overflow. If it is an issue, you can compare the
// double values, but you SHOULD check for equality BEFORE converting
bool Fraction::operator<(const Fraction& x) const{
  return (num*x.denom) < (x.num*denom);
}

bool Fraction::operator==(const Fraction& x) const{
  return (num == x.num) && (denom == x.denom);
}

bool operator>(const Fraction &x, const Fraction &y)
{
  return !(x == y) && !(x < y);
}

bool operator<=(const Fraction &x, const Fraction &y)
{
  return (x == y) || (x < y);
}

bool operator>=(const Fraction &x, const Fraction &y)
{
  return (x == y) || (x > y);
}

bool operator!=(const Fraction &x, const Fraction &y)
{
  return !(x == y);
}


Fraction operator+(const Fraction& x,const Fraction& y){
  Fraction a(x);
  a += y;
  return a;
}

Fraction operator-(const Fraction& x,const Fraction& y){
  Fraction a(x);
  a -= y;
  return a;
}

Fraction operator*(const Fraction& x,const Fraction& y){
  Fraction a(x);
  a *= y;
  return a;
}

Fraction operator/(const Fraction& x,const Fraction& y){
  Fraction a(x);
  a /= y;
  return a;
}

// Note that you can read in Fractions of two forms:
// a/b (With any number of space between a,/,b) - The input "points" to
//      the NEXT character after the denom (White space or not)
// c   (Just an integer - The input "points" to the next NON-WHITE SPACE
//      character. Careful when mixing this with getline.)
istream& operator>>(istream& is,Fraction& x){
  is >> x.num;
	
  char ch;
  is >> ch;
  if(ch != '/'){
    is.putback(ch);
    x.denom = 1;
  } else {
    is >> x.denom;
    if(x.denom < 0){
      x.num = -x.num;
      x.denom = -x.denom;
    }
    x.reduce();
  }
	
  return is;
}

// Will output 5 for 5/1 and 0 for 0/1. If you want always
//    fractions, get rid of the if statement
ostream& operator<<(ostream& os,const Fraction& x){
  os << x.num;
  os << '/' << x.denom;
  return os;
}

typedef long long ll;

//------------------------------------------------------------------------------
// 2D Integer geometry starts here

bool dEqual(Fraction x, Fraction y) { return x == y; }  // replaces dEqual from double code
const ll EPS = 0;                           // replaces EPS from double code
struct Point {
  Fraction x, y;

  Point(Fraction xx = 0, Fraction yy = 0) : x{xx}, y{yy} { }

  // operator== and operator<: use double geometry code
  bool operator==(const Point &p) const { return dEqual(x, p.x) && dEqual(y, p.y); }
  bool operator<(const Point &p) const { return y < p.y || (y == p.y && x < p.x); }
};

Point operator-(Point p,Point q){ p.x -= q.x; p.y -= q.y; return p; }
Point operator+(Point p,Point q){ p.x += q.x; p.y += q.y; return p; }
Point operator*(Fraction r,Point p){ p.x *= r; p.y *= r; return p; }
Fraction operator*(Point p,Point q){ return p.x*q.x + p.y*q.y; }
Fraction cross(Point p,Point q){ return p.x*q.y - q.x*p.y; }
Point inv(Point p){ Point q = {-p.y,p.x}; return q; }

enum Orientation {CCW, CW, CNEITHER};

//------------------------------------------------------------------------------


// +, -, inv: SR1
//  *, cross: SR2
Fraction len2(const Point &p){ return p*p; } // len2=len*len // SR2

//------------------------------------------------------------------------------
// Colinearity test // SR2
// Orientation test // SR2
// Signed Area of Polygon (*2) // SR2 divided by n, don't divide by 2
//------------------------------------------------------------------------------
// Convex hull: 
//   To remove colinear pts: Change ("<0" and ">0") to ("<=0" and ">=0") // SR2
//------------------------------------------------------------------------------
// Point in Polygon Test // SR2

//------------------------------------------------------------------------------
// Squared distance from "c" to the infinite line defined by "a" and "b"
Fraction dist_line2(Point a, Point b, Point c) // SR4
{ Fraction cr=cross(b-a,a-c);return cr*cr / len2(b-a); }


/* returns 1 if intersect at a point, 0 if not, -1 if the lines coincide */
int intersect_line(Point a, Point b, Point c, Point d, Point &p)
{
  Fraction r;
  Fraction denom, num1, num2;

  assert((a.x != b.x || a.y != b.y) && (c.x != d.x || c.y != d.y));
  
  num1 = (a.y - c.y)*(d.x - c.x) - (a.x - c.x)*(d.y - c.y);
  num2 = (a.y - c.y)*(b.x - a.x) - (a.x - c.x)*(b.y - a.y);
  denom = (b.x - a.x)*(d.y - c.y) - (b.y - a.y)*(d.x - c.x);
  
  if (denom != 0) {
    r = num1 / denom;
    if (0 <= r && r <= 1) {
      p = a + r * (b - a);
      return 1;
    } else {
      return 0;
    }
  } else {
    if (num1 != 0) {
      return 0;
    } else {
      return -1;
    }
  }
}



// Colinearity test
bool colinear(Point a, Point b, Point c) { return dEqual(cross(b-a,c-b),0); }

//------------------------------------------------------------------------------
// Orientation test  (When pts are colinear: ccw: a-b-c  cw: c-a-b  neither: a-c-b)
Orientation ccw(Point a, Point b, Point c) { // 
  Point d1 = b - a, d2 = c - b;
  if (dEqual(cross(d1,d2),0))
    if (d1.x * d2.x < 0 || d1.y * d2.y < 0) 
      return (d1 * d1 >= d2*d2 - EPS) ? CNEITHER : CW;
    else return CCW;
  else return (cross(d1,d2) > 0) ? CCW : CW;
}

//------------------------------------------------------------------------------
// Signed Area of Polygon
Fraction area_polygon2(vector<Point> p) {
  int n = p.size();
  Fraction sum(0,1);
  for (int i = 0; i < n; i++)  sum += cross(p[i],p[(i+1)%n]);
  return sum;
}

//------------------------------------------------------------------------------
// Point in Polygon Test
const bool BOUNDARY = true;  // is boundary in polygon?
bool point_in_poly(Point poly[], int n, Point p) {
  int i, j, c = 0;
  for (i = 0; i < n; i++) 
    if (poly[i] == p ||	ccw(poly[i], poly[(i+1)%n], p) == CNEITHER) return BOUNDARY;
  
  for (i = 0, j = n-1; i < n; j = i++) 
    if (((poly[i].y <= p.y && p.y < poly[j].y) ||
	 (poly[j].y <= p.y && p.y < poly[i].y)) &&
        (p.x < (poly[j].x - poly[i].x) * (p.y - poly[i].y) /
	 (poly[j].y - poly[i].y) + poly[i].x))
      c = !c;
  return c;
}

const int MAX_N = 100;
int N, Q;
Point poly[MAX_N];

Point to_xy(int r, int c)
{
  Point p;

  p.x = Fraction(c) + Fraction(1,2);
  p.y = Fraction(-r) - Fraction(1,2);
  return p;
}

typedef pair<Fraction, Fraction> pff;

bool inside_top(Fraction xleft, Fraction xright, Fraction ybot, Fraction ytop,
		Point p)
{
  return p.y <= ytop;
}
bool inside_bot(Fraction xleft, Fraction xright, Fraction ybot, Fraction ytop,
		Point p)
{
  return p.y >= ybot;
}
bool inside_left(Fraction xleft, Fraction xright, Fraction ybot, Fraction ytop,
		 Point p)
{
  return p.x >= xleft;
}
bool inside_right(Fraction xleft, Fraction xright, Fraction ybot, Fraction ytop,
		  Point p)
{
  return p.x <= xright;
}

typedef bool (*inside_func_t)(Fraction, Fraction, Fraction, Fraction, Point);
inside_func_t inside_func[4] = {
  inside_top, inside_bot, inside_left, inside_right
};

void process_query(Point center)
{
  // get all the points on the boundary
  Fraction xleft = center.x - Fraction(1,2), xright = center.x + Fraction(1,2);
  Fraction ybot = center.y - Fraction(1,2), ytop = center.y + Fraction(1,2);

  Point ul(xleft, ytop), ur(xright, ytop), bl(xleft, ybot), br(xright, ybot);
  vector<pair<Point,Point>> line;
  line.emplace_back(ul, ur);   // top
  line.emplace_back(bl, br);   // bot
  line.emplace_back(ul, bl);   // left
  line.emplace_back(ur, br);   // right

  vector<Point> clip(poly, poly+N);

  for (int i = 0; i < 4 && clip.size() > 2; i++) {
    vector<Point> clip2;

    int n_clip = clip.size();
    for (int k = 0; k < n_clip; k++) {
      Point curr = clip[k], next = clip[(k+1)%n_clip];
      Point inter;
      int res;
      if ((res = intersect_line(curr, next, line[i].first, line[i].second,
				inter))) {
	assert(res != -1);
	clip2.push_back(inter);
      }
      if (inside_func[i](xleft, xright, ybot, ytop, next)) {
	clip2.push_back(next);
      }
    }
    clip.clear();
    for (int i = 0; i < clip2.size(); i++) {
      if (i == 0 || !(clip2[i] == clip2[i-1])) {
	clip.push_back(clip2[i]);
      }
    }
    if (clip.size() > 1 && clip.back() == clip[0]) {
      clip.pop_back();
    }
  }

  cout << area_polygon2(clip) / 2 << endl;
}

int main()
{
  cin >> N >> Q;
  for (int i = 0; i < N; i++) {
    int r, c;
    cin >> r >> c;
    poly[i] = to_xy(r, c);
  }

  for (int i = 0; i < Q; i++) {
    int r, c;
    cin >> r >> c;
    Point center = to_xy(r, c);
    process_query(center);
  }


  return 0;
}
