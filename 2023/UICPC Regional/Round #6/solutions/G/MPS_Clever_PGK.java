/*
   Java solution for ManhattanPositioningSystem
   a problem for BAPC2016
   (too) clever solution written by Peter Kluit
   July 2016
*/
import java.util.*;

public class MPS_Clever_PGK{
   public static void main (String [] args){
      run();
   }
     private static void run() {
        Scanner scanner  = new Scanner(System.in);
        int beacons = scanner.nextInt();
        ManhattanClever man = new ManhattanClever();
        for (int b = 0; b < beacons; b++){
           int x = scanner.nextInt();
           int y = scanner.nextInt();
           int d = scanner.nextInt();
           man.add(x, y, d);
        }
        System.out.println(man.solution());
   }

}

class ManhattanClever{

    Sphere collect;

    public void add(int x, int y, int r){
       if (collect == null)
           collect = new Sphere(x,y,r);
       else
           collect.intersect(new Sphere(x, y, r));
    }

    public String solution(){
      ArrayList<Row> rows  = collect.rows;
      if (rows.size() == 0)
         return "impossible";
      if (rows.size() > 1)
         return "uncertain";
      Row row = rows.get(0);
      if (row.size == 1)
         return row.x + " " + row.y;
      else
         return "uncertain";
    }
}

class Sphere{
    ArrayList<Row> rows = new ArrayList<Row>();

    Sphere(int x, int y, int r){
       if (r == 0)
          rows.add(new UpRow(x,y,1));
       else if (r == 1) {
          rows.add(new UpRow(x-r, y, r+1));
          rows.add(new UpRow(x, y-r, r+1));
       }
       else{
          rows.add(new UpRow(x-r, y, r+1));
          rows.add(new DownRow(x-r + 1, y - 1, r-1));
          rows.add(new UpRow(x, y-r, r+1));
          rows.add(new DownRow(x + 1, y + r - 1, r-1));
       }
    }

    void intersect (Sphere other){
       ArrayList<Row> nrows = new ArrayList<Row>();
       for (Row mine : rows)
          for (Row his: other.rows){
             Row is = his.intersection(mine);
             if (is != null)
                nrows.add(is);
          }
       rows = nrows;
    }
}

abstract class Row{
    int x, y;
    int size;
    Row(int xIn, int yIn, int sizeIn){
       x = xIn;
       y = yIn;
       size = sizeIn;
    }

    abstract Row intersection(Row other);
    abstract Row intersectUp(UpRow other);
    abstract Row intersectDown(DownRow other);

    public String toString(){
        return x + " " + y + "   " + size;
    }
}

class UpRow extends Row{
   UpRow(int xIn, int  yIn, int sizeIn){
      super(xIn, yIn, sizeIn);
   }

   Row intersection (Row other){
      return other.intersectUp(this);
   }

   Row intersectUp(UpRow other){
       int fromHere = other.x - this.x;
       if (fromHere != other.y - this.y)
          return null;
        if (fromHere >= 0){
           int overlap = size - fromHere;
           if (overlap <= 0)
              return null;
           if (overlap > other.size)
              overlap = other.size;
           return new UpRow(other.x, other.y, overlap);
        }
        else{ // fromHere < 0
           int overlap = other.size + fromHere;
           if (overlap <= 0)
              return null;
           if (overlap > size)
              overlap = size;
           return new UpRow(x, y, overlap);
        }
   }

   Row intersectDown(DownRow other){
       Row up   = this;
       Row down = other;
       int dx = down.x - up.x;
       int dy = down.y - up.y;
       if ((dx - dy) % 2 != 0)
          return null;
       int upt = (dx + dy)/2;
       int downt = (dy - dx)/2;
       if (0 <= upt && upt < up.size && 0 <= downt && downt < down.size)
          return new UpRow(up.x + upt, up.y + upt, 1);
       return null;
   }

}

class DownRow extends Row{
   DownRow(int xIn, int yIn, int sizeIn){
      super(xIn, yIn, sizeIn);
   }

   Row intersection (Row other){
      return other.intersectDown(this);
   }

   Row intersectUp(UpRow other){
       Row up   = other;
       Row down = this;
       int dx = down.x - up.x;
       int dy = down.y - up.y;
       if ((dx - dy) % 2 != 0)
          return null;
       int upt = (dx + dy)/2;
       int downt = (dy - dx)/2;
       if (0<= upt && upt < up.size && 0 <= downt && downt < down.size)
          return new UpRow(up.x + upt, up.y + upt, 1);
       return null;
   }

   Row intersectDown(DownRow other){
      int fromHere = other.x - this.x;
      if (fromHere != this.y - other.y)
         return null;
      if (fromHere >= 0){
           int overlap = size - fromHere;
           if (overlap <= 0)
              return null;
           if (overlap > other.size)
              overlap = other.size;
           return new DownRow(other.x, other.y, overlap);
      }
      else{ // fromHere < 0
         int overlap = other.size + fromHere;
         if (overlap <= 0)
            return null;
         if (overlap > size)
            overlap = size;
         return new DownRow(x, y, overlap);
        }
   }

}

