import java.io.*;

class Lane {
  double[] segment;
  
  Lane() {
    segment=new double[5];
  }
}

class stagger_spurious_lines {
  public static void main(String[] args) throws IOException {

//  program parameters

    int N;
    double R;
    double S;
    double W;
    double F;
    double L1;
    double L2;
    final double pi=3.1416;

    String s=null;
    BufferedReader stdin;
    Lane[] lane;

    stdin=new BufferedReader(new InputStreamReader(System.in));
    String[] token;

    s=stdin.readLine();
    token=s.split("\\s+",-1);
    N=Integer.parseInt(token[0]);
    R=Double.parseDouble(token[1]);
    S=Double.parseDouble(token[2]);
    W=Double.parseDouble(token[3]);
    F=Double.parseDouble(token[4]);
    L1=Double.parseDouble(token[5]);
    L2=Double.parseDouble(token[6]);

    lane=new Lane[N];
    for (int n=0; n < N; n++) {
      double L=(n == 0) ? L1 : L2;
      lane[n]=new Lane();
      lane[n].segment[0]=S/2.0 + F;
      lane[n].segment[1]=pi*(R + n*W + L);
      lane[n].segment[2]=S;
      lane[n].segment[3]=lane[n].segment[1];
      lane[n].segment[4]=S;
//    System.err.printf("%d %.3f %.3f %.3f %.3f %.3f\n"
//                     ,n
//                     ,lane[n].segment[0]
//                     ,lane[n].segment[1]
//                     ,lane[n].segment[2]
//                     ,lane[n].segment[3]
//                     ,lane[n].segment[4]
//                     );
    }

    while ( (s=stdin.readLine()) != null ) {
      double D;

      D=Double.parseDouble(s);
      System.out.printf("%g",D);
      for (int n=0; n < N; n++) {
        int seg=0;
        double d=D;
        double L=(n == 0) ? L1 : L2;
        double x=Double.POSITIVE_INFINITY;
        double y=Double.POSITIVE_INFINITY;
        double theta=Double.POSITIVE_INFINITY;
        double semicircle=Double.POSITIVE_INFINITY;
        double r=Double.POSITIVE_INFINITY;

//      System.err.printf(" lane %d, ",n + 1);
        while (d > lane[n].segment[seg]) {
//        System.err.printf("seg %d, remaining=%.2f\n",seg,d);
          d -= lane[n].segment[seg];
          seg++;
          if (seg > 4) {
            seg=1;
          }
        }
//      System.err.printf("Seg %d, Remaining=%.2f\n",seg,d);
        switch (seg) {
        case 0:
          x=F - d;
          y=-(R + n*W);
          break;
        case 1:
          semicircle=lane[n].segment[seg];
          r=R + n*W;
          theta=(semicircle - d)/semicircle*pi;
          x=-(S/2.0 + r*Math.sin(theta));
          y=(r*Math.cos(theta));
          break;
        case 2:
          x=-S/2.0 + d;
          y=(R + n*W);
          break;
        case 3:
          semicircle=lane[n].segment[seg];
          r=R + n*W;
          theta=(semicircle - d)/semicircle*pi;
          x=(S/2.0 + r*Math.sin(theta));
          y=-(r*Math.cos(theta));
          break;
        case 4:
          x=S/2.0 - d;
          y=-(R + n*W);
          break;
        }
        System.out.printf(" %.2f %.2f",x,y);
      }
      System.out.println();
      System.out.println();
      System.out.println();
    }
  }
 
}
