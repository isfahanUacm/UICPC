import java.util.Scanner;
import java.lang.Math;

public class harry {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		Long[] lengths = new Long[n];
		for(int i = 0; i < n; i++)
			lengths[i] = sc.nextLong(); 
		if(n > 120)
			System.out.println("possible");
		else
		{
			Boolean possible = false;  
			for(int i = 0; i < n && !possible; i++)
				for(int j = i + 1; j < n && !possible; j++)
					for(int k = j + 1; k < n && !possible; k++)
					{
						Long a = lengths[i]; Long b = lengths[j]; Long c = lengths[k];
						Long d = Math.max(Math.max(a,b), c);
						if(a + b + c > 2 * d)
							possible = true;
					}
			if(possible) { System.out.println("possible"); }
			else { System.out.println("impossible"); }
		}
		sc.close();
		

	}

}
