/*
   Solution in Java for Charley in Charge
   a problem for BAPC2016
   author: Peter Kluit
   October 2016
 */

import java.util.*;
public class Charles{

   public static void main (String [] args){
      run();
   }

   private static void run(){
      Scanner ir = new Scanner(System.in);
      int cities = ir.nextInt();
      int highways = ir.nextInt();
      int percents = ir.nextInt();

      Charles charley = new Charles(cities, percents);
         for (int k = 0; k < highways; k++){
            int c1 = ir.nextInt();
            int c2 = ir.nextInt();
            int t  = ir.nextInt();
			c1--; c2--;
            charley.addWay(c1, c2, t);
         }
         System.out.println(charley.getSolution());
   }


//////////////////////////////
   static final long INFINITY = 1_000_000_000_000_000_000L;
   City [] city;
   int cities;
   int percents;
   City start;
   City goal;

   public Charles(int c, int p){
      cities = c;
      percents = p;
      city = new City[cities];
      for (int t = 0; t < cities; t++)
         city[t] = new City(t);
         start = city[0];
         goal = city[cities - 1];
   }

   public void addWay(int c1, int c2, int t){
      city[c1].addWay(new Way(city[c2], t));
      city[c2].addWay(new Way(city[c1], t));
   }


   public int getSolution(){
      long mindist = distance(1_000_000_000);
      long allowedDist = mindist * (100 + percents) / 100;

      int guess = longestLeg;
      int jump = (guess + 1)/2;

      while (jump > 1){
         if (distance(guess - jump) <= allowedDist)
               guess -= jump;
         jump = (jump + 1)/2;
      }
      // jump == 1
      if (distance(guess - jump) <= allowedDist)
         guess -= jump;
      return guess;
   }

   PriorityQueue<City> todo = new PriorityQueue<City>();
   int longestLeg = 0;

   void updateLeg(int leg){
     if (leg > longestLeg)
        longestLeg = leg;
   }

   long distance(int bound){
      for (int k = 1; k < cities; k++)
             city[k].dist = INFINITY;
      // distance from start to goal, when no leg longer than bound is allowed
      start.update(0);
      todo.add(start);

      while (todo.size() > 0){
         City next = todo.poll();
         //System.out.println(" visiting  " + next);
         long here = next.dist;
         if (next == goal)
            return here;
         for (Way way : next.ways)
             if (way.leq(bound)){
                 City there = way.goFrom(here);
                 updateLeg(way.length);
                 if(there != null){
                    todo.remove(there);
                    todo.add(there);
             }
         }
      }
      return 1_000_000_000_000_000_000L;
   }

}


class  WayList extends ArrayList<Way> {

}


class City implements Comparable<City>{
   WayList ways = new WayList();
   int name;
   long dist = Charles.INFINITY;
   public City(int no){
      name = no;
   }
   public void addWay(Way w){
      ways.add(w);
   }

   public int compareTo(City that){
       if (this.dist - that.dist > 0)
          return  1;
       if (this.dist - that.dist < 0)
          return -1;
       return 0;
   }
   
   public boolean update(long d){
       if (d < dist){
          dist = d;
          return true;
       }
       return false;
   }
   
   
   public String toString(){
      return ("city " + name +  " at distance " + dist);
   }
}

class Way{
    City destination;
    int length;

    public Way(City to, int l){
       destination = to;
       length = l;
    }
    
    boolean leq(int dist){
        return length <= dist;
    }
    
    City goFrom (long from ){
       if (destination.update(from + length))
           return destination; // updated
       return null;  // no update
    }

}