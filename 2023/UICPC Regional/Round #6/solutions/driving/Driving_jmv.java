public class Driving_jmv {
	public static void main(String[] args) {
		java.util.Scanner in = new java.util.Scanner(System.in);
		int n = in.nextInt(), p = in.nextInt(); in.nextLine();
		String[] cars = in.nextLine().trim().split(" ");
		int[] distances = new int[cars.length];
		if (distances.length != n) System.out.println("Wrong input format!");
		for (int i = 0; i < cars.length; i++)
			distances[i] = Integer.parseInt(cars[i]);
		java.util.Arrays.sort(distances);
		
		int max = 0;
		for (int i = 0; i < distances.length; i++) {
			int c = (p * (i + 1) - distances[i] + distances[0]);
			if (c > max) 
				max = c;
		}
		System.out.println(max);
	}
}