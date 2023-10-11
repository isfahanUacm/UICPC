/*
 Oplossing in Java
 voor Airport
 een probleem voor BAPC2016
 auteur: Peter Kluit
 */

import java.util.*;
import java.io.*;

public class Airport_PGK{
   static InputStream input = System.in;

   public static void main (String [] args){
      run();
   }

   private static void run(){
      Scanner scanner  = new Scanner(input);
      scanner.useLocale(Locale.US);
      double xa = scanner.nextDouble();
      double ya = scanner.nextDouble();
      double xb = scanner.nextDouble();
      double yb = scanner.nextDouble();
      AirportSolver solver = new AirportSolver(xa, ya, xb, yb);
      int beltCount = scanner.nextInt();
      for (int k = 0; k < beltCount; k++){
         double x1 = scanner.nextDouble();
         double y1 = scanner.nextDouble();
         double x2 = scanner.nextDouble();
         double y2 = scanner.nextDouble();
         solver.add(new Belt(new Location(x1, y1), new Location(x2, y2)));
      }
      double time = solver.time();
      System.out.println(time);
   }
   
   private static void show(double [] v){
      System.out.println(v[0] + " "+ v[1]);
   }
}

class AirportSolver{
   final static double cos60 = 0.5;
   final static double sin60 = 0.5 * Math.sqrt(3);
   final static double [][]R = {{cos60,  sin60},{-sin60, cos60}};
   final static double [][]L = {{cos60, -sin60},{ sin60, cos60}};

   Location start, goal;
   ArrayList<Belt> belts = new ArrayList<Belt>();

   PriorityQueue<Location> todo = new PriorityQueue<Location>();

   public AirportSolver(double xa, double ya, double xb, double yb){
      start = new Location(xa, ya);
      goal  = new Location(xb, yb);
   }

   void add(Belt b){
      belts.add(b);
   }

   double time(){

      connect();
      start.update(0);
      todo.add(start);
      while (true){
         Location next = todo.poll();
         if (next == goal)
            return next.distance;
         next.connect();

         for (Location buur : next.neighbours){
            double toBuur = next.distance + distance(next, buur);
            if(buur.update(toBuur)){
                todo.remove(buur);
                todo.add(buur);
            }
         }
      }
   }

   private void connect(){
      start.neighbours.add(goal);
      for (Belt belt1 : belts){
         connect(start, belt1);
         connect(belt1, goal);
         for (Belt belt2 : belts)
            connect(belt1, belt2);
      }
   }

   private void connect(Location loc, Belt belt){
      double [] v = belt.vector;

      double [] lv = turnLeft(v);
      connect(loc, lv, belt);

      double [] rv = turnRight(v);
      connect(loc, rv, belt);

      loc.neighbours.add(belt.from);
   }

   private void connect(Belt belt, Location loc){
      double [] v = belt.vector;

      double [] lv = turnLeft(v);
      connect(belt, lv, loc);

      double [] rv = turnRight(v);
      connect(belt, rv, loc);

      belt.to.neighbours.add(loc);
   }

   private void connect(Belt belt1, Belt belt2){
      if (belt1 == belt2)
         return;
      double [] v1 = belt1.vector;
      double [] v2 = belt2.vector;

      double [] lv2 = turnLeft(v2);
      if (inprod(lv2, v1)> 0.5 * length(v1) * length(v2)){
          connect(belt1.to, lv2, belt2);
      }

      double [] rv2 = turnRight(v2);
      if (inprod(rv2, v1)> 0.5 * length(v1) * length(v2)){
          connect(belt1.to, rv2, belt2);
      }

      double [] lv1 = turnLeft(v1);
      if (inprod(lv1, v2)> 0.5 * length(v1) * length(v2)){
          connect(belt1, lv1, belt2.from);
      }

      double [] rv1 = turnRight(v1);
      if (inprod(rv1, v2) > 0.5 * length(v1) * length(v2)){
         connect(belt1, rv1, belt2.from);
      }

      belt1.to.neighbours.add(belt2.from);
   }
   
   private void connect(Location from, double [] v, Belt b){
      double [] rhs = {from.x - b.from.x, from.y - b.from.y};
      double [] sol = solveFor(new double[][]{{b.vector[0], v[0]},{b.vector[1], v[1]}}, rhs);
      if (0 <= sol[0] && sol[0] < 1 && sol[1] < 0){
         double alfa = sol[0];
         Location loc = new Location(b.from.x + alfa * b.vector[0], b.from.y + alfa * b.vector[1]);
         loc.where = alfa;
         loc.belt = b;
         from.neighbours.add(loc);
         loc.neighbours.add(b.to);
         b.from.neighbours.add(loc);
      }
   }

   private void connect(Belt b, double [] v, Location to){
      double [] rhs =  {to.x - b.from.x, to.y - b.from.y};
      double [] sol = solveFor(new double[][]{{b.vector[0], v[0]},{b.vector[1], v[1]}}, rhs);
      if (0 <= sol[0] && sol[0] < 1 && sol[1] > 0){
         double alfa = sol[0];
         Location loc = new Location(b.from.x + alfa * b.vector[0], b.from.y + alfa * b.vector[1]);
         loc.where = alfa;
         loc.belt = b;
         loc.neighbours.add(to);
         b.from.neighbours.add(loc);
      }
   }

   private double distance(Location a, Location b){
      double answer = 0;
      double dx = a.x - b.x;
      double dy = a.y - b.y;
      double d = Math.sqrt(dx * dx + dy * dy);
      if (a.belt != null && a.belt == b.belt)
         answer = d/2;
      else
         answer = d;
      return answer;
   }
   
   static double [] turnLeft(double[] a){
      return new double[]{(L[0][0] * a[0] + L[0][1] * a[1]), (L[1][0] * a[0] + L[1][1] * a[1])};
   }

   static double [] turnRight(double[] a){
      return new double[]{(R[0][0] * a[0] + R[0][1] * a[1]), (R[1][0] * a[0] + R[1][1] * a[1])};
   }

   private double inprod(double[] a, double[] b){
      return a[0] * b[0] + a[1] * b[1];
   }

   private double length(double [] v){
       return Math.sqrt(inprod(v,v));
   }

   static double []solveFor(double [][] m, double [] b){   //M * x = b
      double [] answer = new double[2];
      double det = determinant(m);
      answer[0] = (m[1][1] * b[0] - m[0][1] * b[1])/det;
      answer[1] = (m[0][0] * b[1] - m[1][0] * b[0])/det;
      return answer;
   }
   
   static double determinant(double[][] m ){
      return m[0][0] * m[1][1] - m[0][1] * m[1][0];
   }

}

class Belt{
   Location from, to;
   double [] vector;

   public Belt(Location fromIn, Location toIn){
       from = fromIn;
       from.where = 0;
       to = toIn;
       to.where = 1;
       vector = new double[]{(to.x - from.x), (to.y - from.y)};
       from.belt = this;
       to.belt = this;
       from.neighbours.add(to);
   }
}

class Location implements Comparable{
   static final double INFINITY = 1000000;

   double distance = INFINITY; // seconds
   double x, y;
   Belt belt;
   double where ; // place on the belt: 0 <= where <= 1

   ArrayList<Location> neighbours = new ArrayList<Location>();

   public Location(double xIn, double yIn){
      x = xIn;
      y = yIn;
   }
   
   public boolean update (double d){
       if (d < distance){
          distance = d;
          return true;
       }
       return false;
   }

   public void connect(){
      if (belt != null && this != belt.from)
          for (Location loc : belt.from.neighbours)
              if (loc != this && loc.where > this.where)
                  neighbours.add(loc);
   }

   public int compareTo(Object that){
      Location other = (Location) that;
      if (this.distance < other.distance)
          return -1;
      if (this.distance > other.distance)
         return 1;
      return 0;
   }
}