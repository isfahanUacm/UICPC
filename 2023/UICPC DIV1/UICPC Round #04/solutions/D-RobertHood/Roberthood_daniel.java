import java.awt.Point;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

/**
 * 
 * @author Daniel Espling, Umea University. espling@cs.umu.se
 * 
 * Based on sample cody by Adam Larkeryd
 *
 */

public class Roberthood_daniel {
	public static void main(String[] args) {
		//Parse number of lines and then points
		Scanner sc = new Scanner(System.in);
		int numLines = Integer.parseInt(sc.nextLine());
		int i = 1;
		ArrayList<Point> points = new ArrayList<Point>(numLines);
		while (i <= numLines) {
			String line = sc.nextLine();
			String[] bits = line.split(" ");
			int x = Integer.valueOf(bits[0]);
			int y = Integer.valueOf(bits[1]);
			points.add(new Point(x, y));
			i++;
		}
		
		sc.close();
		
	    double maxDistance = getMaxDistance(points);
		System.out.println(maxDistance);
	}

	private static double getMaxDistance(ArrayList<Point> points) {
		
		//Get clone sorted by X coords
		ArrayList<Point> pointsByX = (ArrayList<Point>) points.clone();
		Collections.sort(pointsByX, new Comparator<Point>() {
			@Override
			public int compare(Point o1, Point o2) {
				return new Integer(o1.x).compareTo(new Integer(o2.x));
			}
		});
		
		Point[] lUpper = new Point[pointsByX.size()];
		lUpper[0] = pointsByX.get(0);
		lUpper[1] = pointsByX.get(1);
		
		int lUpperIndex = 2;
		
		for (int i = 2; i < pointsByX.size(); i++) {
			lUpper[lUpperIndex] = pointsByX.get(i);
			lUpperIndex++;
			
			//If three points make a left turn, remove middle point and shift last point in one step
			while (lUpperIndex > 2 && leftTurn(lUpper[lUpperIndex - 3], lUpper[lUpperIndex - 2], lUpper[lUpperIndex -1])) {
				lUpper[lUpperIndex - 2] = lUpper[lUpperIndex - 1];
				lUpper[lUpperIndex - 1] = null;
				lUpperIndex--;
			}
		}
		
		Point[] lLower = new Point[pointsByX.size()];
		lLower[0] = pointsByX.get(pointsByX.size() - 1);
		lLower[1] = pointsByX.get(pointsByX.size() - 2);
		
		int lLowerIndex = 2;
		
		for (int i = 2; i < pointsByX.size(); i++) {
			lLower[lLowerIndex] = pointsByX.get(pointsByX.size() - i);
			lLowerIndex++;
			
			//If three points make a left turn, remove middle point and shift last point in one step
			while (lLowerIndex > 2 && leftTurn(lLower[lLowerIndex - 3], lLower[lLowerIndex - 2], lLower[lLowerIndex -1])) {
				lLower[lLowerIndex - 2] = lLower[lLowerIndex - 1];
				lLower[lLowerIndex - 1] = null;
				lLowerIndex--;
			}
		}

		ArrayList<Point> hullPoints = new ArrayList<Point>(lUpperIndex
				+ lLowerIndex);
		for (int i = 0; i < lUpperIndex; i++) {
			hullPoints.add(lUpper[i]);
		}

		//Exlude endpoints since they're already in the set from upper
		for (int i = 1; i < lLowerIndex - 1; i++) {
			hullPoints.add(lLower[i]);
		}
		
		//System.out.println("Nr.hullpoints is: " + hullPoints.size());
		
		//Calculate the pairwise distance
		double distance = 0;
		for (int i = 0; i < hullPoints.size(); i++) {
			Point a = hullPoints.get(i);
			for (int j = i + 1; j < hullPoints.size(); j++) {
				Point b = hullPoints.get(j);
				double pointDistance = Math.sqrt(Math.pow((a.x - b.x), 2) + Math.pow((a.y - b.y), 2));
				distance = Math.max(distance, pointDistance);
			}
		}
         
		return distance;
	}

	private static boolean leftTurn(Point p1, Point p2, Point p3) {
		return (p2.x - p1.x)*(p3.y - p1.y) - (p2.y - p1.y)*(p3.x - p1.x) <= 0;
	}
}
