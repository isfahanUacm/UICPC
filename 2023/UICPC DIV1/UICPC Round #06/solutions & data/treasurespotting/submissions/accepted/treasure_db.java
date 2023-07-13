import java.util.*;

public class treasure_db {
  public static void main(String[] args) {
    new treasure_db().run();
  }

  int W, P;
  Point[][] wall;
  Point[][] people;
  
  void run() {
    Scanner in = new Scanner(System.in);
    
    W = in.nextInt();
    P = in.nextInt();
    
    Point treasure = new Point(in.nextLong(), in.nextLong());
    
    wall = new Point[W][2];
    for(int i=0;i<W;i++)
      for(int j=0;j<2;j++)
	wall[i][j] = new Point(in.nextLong(), in.nextLong());
    
    people = new Point[P][2];
    for(int i=0;i<P;i++)
      for(int j=0;j<2;j++)
	people[i][j] = new Point(in.nextLong(), in.nextLong());
    
    for(int i=0;i<P;i++)
      System.out.println((visible(treasure,i) ? "" : "not ") + "visible");
  }
  
  class Point {
    long x, y;

    Point(long X, long Y){
      x = X;
      y = Y;
    }
  }
  
  long dot   (Point p, Point q) { return p.x*q.x + p.y*q.y; }
  long cross (Point p, Point q) { return p.x*q.y - p.y*q.x; }
  long len2  (Point p)          { return dot(p,p); }
  Point sub(Point p, Point q)   { return new Point(p.x-q.x,p.y-q.y); }
  boolean  eq(Point p, Point q) { return p.x == q.x && p.y == q.y; }
  
  int dir(Point p, Point q, Point r) {
    long c = cross(sub(q,p), sub(r,q));
    if(c == 0) return 0;
    return (c < 0 ? -1 : 1);
  }
  
  boolean on_seg(Point a, Point b, Point p){
    return (Math.min(a.x,b.x) <= p.x && p.x <= Math.max(a.x,b.x)) &&
      (Math.min(a.y,b.y) <= p.y && p.y <= Math.max(a.y,b.y));
  }
  
  boolean intersect(Point a1, Point a2, Point b1, Point b2){
    int d1 = dir(a1,a2,b1), d2 = dir(a1,a2,b2);
    int d3 = dir(b1,b2,a1), d4 = dir(b1,b2,a2);
    if(d1 != d2 && d1 == -d2 && d3 != d4 && d3 == -d4) return true;
    
    return (d1 == 0 && on_seg(a1,a2,b1)) ||
      (d2 == 0 && on_seg(a1,a2,b2)) ||
      (d3 == 0 && on_seg(b1,b2,a1)) ||
      (d4 == 0 && on_seg(b1,b2,a2));  
  }
  
  boolean visible(Point treasure, int idx){
    Point me = people[idx][0], circ = people[idx][1];
    
    // Outside of circle?
    if(len2(sub(treasure,me)) > len2(sub(circ,me)))   return false;
    
    // Not on right half of semi-circle?
    if(dot(sub(treasure,me), sub(circ,me)) < 0)  return false;
    
    // Wall in the way?
    for(int i=0;i<W;i++)
      if(intersect(treasure, me, wall[i][0], wall[i][1]))
	return false;
    
    // Person in the way?
    for(int i=0;i<P;i++)
      if(i != idx && dir(people[i][0],me,treasure) == 0)
	if(len2(sub(me,people[i][0])) < len2(sub(me,treasure)) &&
	   len2(sub(treasure,people[i][0])) < len2(sub(treasure,me)))
	  return false;
    
    return true;
  }
}
