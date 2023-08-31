import java.util.*;
import java.io.*;

public class event_sn {

	public static void main(String[] args) {

		// read input data
		
		Scanner input = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		int nParticipants = input.nextInt();
		int budget = input.nextInt();
		int nHotels = input.nextInt();
		int nWeeks = input.nextInt();

		int hotelPrice[] = new int[nHotels];
		int availableBeds[][] = new int[nHotels][nWeeks];
		
		for (int i=0; i<nHotels; i++) {
			hotelPrice[i] = input.nextInt();
			for (int week=0; week<nWeeks; week++) {
				availableBeds[i][week] = input.nextInt();
			}
		}
		
		// find answer. Loop through hotels and see which of the
		// hotels with sufficient number of beds that gives the best price.
		
		int bestPrice = Integer.MAX_VALUE;
		
		for (int i=0; i<nHotels; i++) {
			for (int week=0; week<nWeeks; week++) {
				if (availableBeds[i][week]>=nParticipants) {
					int alternativePrice = hotelPrice[i]*nParticipants;
					if (alternativePrice < bestPrice) {
						bestPrice = alternativePrice;
					}
				}
			}
		}
		
		if (bestPrice != Integer.MAX_VALUE && bestPrice < budget) {
			System.out.println(bestPrice);
		} else {
			System.out.println("stay home");
		}
		

	}

}
