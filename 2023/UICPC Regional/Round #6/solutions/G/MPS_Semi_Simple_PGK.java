/*
   Java solution for ManhattanPositioningSystem
   a problem for BAPC2016
   Solution written by Peter Kluit
   July 2016
   More or less Joris' simple (but optimized) algorithm
*/

import java.util.*;

public class MPS_Semi_Simple_PGK{

    public static void main (String [] args){
      run();
    }
     private static void run() {
        Scanner scanner  = new Scanner(System.in);
        int beacons = scanner.nextInt();
        ManhattanSSimple man = new ManhattanSSimple(beacons);

        for (int b = 0; b < beacons; b++){
           int x = scanner.nextInt();
           int y = scanner.nextInt();
           int d = scanner.nextInt();
           man.add(x, y, d);
        }
        System.out.println(man.solution());
   }  

}

class ManhattanSSimple{
    int sols = 0;
    int [][] beacon;
    int count = 0;
    int [] answer ;

    ManhattanSSimple(int size){
       beacon = new int [size][3];
    }

    public void add(int x, int y, int r){
       beacon[count][0] = x;
       beacon[count][1] = y;
       beacon[count][2] = r;
       count++;
    }

    public String solution(){

        int mx = beacon[0][0];
        int my = beacon[0][1];
        int r =  beacon[0][2];
        if (r == 0)
           check(mx, my);
        for (int dx = 0; sols < 2 && dx < r; dx++){
           int dy = r - dx;
           check(mx + dx, my + dy);
           check(mx - dy, my + dx);
           check(mx + dy, my - dx);
           check(mx - dx, my - dy);
        }
        if (sols == 0)
           return "impossible";
        else if (sols == 1)
           return answer[0] + " " + answer[1];
        else
           return "uncertain";
    }
    int start = 0;
    private void check(int x, int y){
       int b = start;
       for (int t = 0; t < count; t++){
       //for (int b = 1; b < beacon.length; b++){
          int [] beac = beacon[b];
          if (Math.abs(x - beac[0]) + Math.abs(y - beac[1]) != beac[2]){
             start = b;
             return;
          }
          b++;
          if (b == count)
             b = 0;
       }
       if (sols == 0){
          answer = new int []{x, y};
          sols = 1;
       }
       else
          sols++;
    }


}
