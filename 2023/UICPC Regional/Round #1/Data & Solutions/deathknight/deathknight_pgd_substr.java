//Author: Pål Grønås Drange

import java.util.*;

public class deathknight_pgd_substr {
    public static char CHAINS = 'C';
    public static char DEATH = 'D';
    public static char OBLITERATE = 'O';
    
    public static void main(String... args) {
	Scanner scanner = new Scanner(System.in);
	
	int numbersWon = 0;
	
	int battles = Integer.parseInt(scanner.nextLine().trim());
	for (int battle = 0; battle < battles; battle++) {
	    String line = scanner.nextLine();
	    if (!line.contains("CD")) numbersWon++;
	}
	System.out.println(numbersWon);
    }
}
