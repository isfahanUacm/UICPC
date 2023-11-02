import java.io.*;

class speedometer {
  public static void main(String[] args) throws IOException {

//  process args for generating debug context to stderr

    boolean debug=false;
    if (args.length > 0) {
      if (args[0].equals("-d")) {
        debug=true;
      }
    }

    double tf;
    double tr;
    String s=null;
    BufferedReader stdin;

    double previousSpeed;
    int reportedSpeed;
    double speed;

    stdin=new BufferedReader(new InputStreamReader(System.in));
    s=stdin.readLine();
    tf=Double.parseDouble(s);
    s=stdin.readLine();
    tr=Double.parseDouble(s);
    
    s=stdin.readLine();
    previousSpeed=Double.parseDouble(s);
    reportedSpeed=(int) Math.ceil(previousSpeed);
    if (debug) {
      System.err.println("              " + reportedSpeed);
    }
    System.out.println(reportedSpeed);

    while ( (s=stdin.readLine()) != null ) {
      speed=Double.parseDouble(s);
      double upperBound=Math.ceil(speed);
      double lowerBound=Math.floor(speed);
      if (speed == 0.0) {
//      System.out.printf(" 0 ");
        reportedSpeed=0;
      }
      else if ( (0.0 < speed) && (speed < 1.0) ) {
//      System.out.printf(" (0,1) ");
        reportedSpeed=1;
      }
      else if (speed > lowerBound + tr) {
//      System.out.printf(" > tr ");
        reportedSpeed=(int) upperBound;
      }
      else if (speed < lowerBound + tf) {
//      System.out.printf(" < tf ");
        reportedSpeed=(int) lowerBound;
      }

//    speed falls within the neutral zone, here is the crux of the problem

      else if (speed > previousSpeed) {  // rising
//      System.out.printf(" rising ");
        if (previousSpeed < lowerBound + tf) {
          reportedSpeed=(int) lowerBound;
        }
      }
      else if (speed < previousSpeed) {  // falling
//      System.out.printf(" falling ");
        if (previousSpeed > lowerBound + tr) {
          reportedSpeed=(int) upperBound;
        }
      }
      else {
//      System.out.printf(" constant ");
      }
      if (debug) {
        System.err.printf("%6.3f %6.3f %d\n",previousSpeed,speed,reportedSpeed);
      }
      System.out.println(reportedSpeed);
      previousSpeed=speed;
    }
  }
}
