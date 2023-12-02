// @EXPECTED_RESULTS@: CORRECT
import java.util.Scanner;

public class brinky_rek{
	long [][][] tab = new long[20][2][20];

	String first;
	String ref;
	int R;

	long rek_m(int i, int r){
		if(i == 0)
			return (r == 0) ? 1 : 0;
		if(tab[i][1][r] != -1)
			return tab[i][1][r];
		long t = 0;
		if(r == 0){
			if(first.charAt(i-1) != ref.charAt(i-1)){
				for(int j=0; j<R; ++j){
					t += rek_m(i-1, j);
				}
			}
		}else{
			if(first.charAt(i-1) == ref.charAt(i-1)){
				t += rek_m(i-1, r-1);
			}
			if(r==R){
				t += rek_m(i-1, r);
			}
		}
		tab[i][1][r] = t;
		return t;
	}

	long rek(int i, int r){
		if(i == 0)
			return 0;
		if(tab[i][0][r] != -1)
			return tab[i][0][r];

		long t = 0;
		if(r == 0){
			for(int j=0; j<R; ++j){
				t += 9* rek(i-1, j);
				if(ref.charAt(i-1) < first.charAt(i-1)){
					t += (first.charAt(i-1) - '0' - 1) * rek_m(i-1, j);
				}else{
					t += (first.charAt(i-1) - '0') * rek_m(i-1, j);
				}
			}
		}else{
			t += rek(i-1, r-1);
			if(first.charAt(i-1) > ref.charAt(i-1)){
				t += rek_m(i-1, r-1);
			}
			if (r == R){
				t += 10 * rek(i-1, r);
				t += (first.charAt(i-1) - '0') * rek_m(i-1, r);
			}
		}
		tab[i][0][r] = t;
		return t;
	}

	public static void main(String args[]){
		(new brinky_rek()).m();
	}
	public void m(){
		Scanner scanner = new Scanner(System.in);
		int tc = scanner.nextInt();
		while(tc-- > 0){
			long m, z;
			int r;
			m = scanner.nextLong();
			z = scanner.nextLong();
			r = scanner.nextInt();
			R = r;
			first = (new Long(m-1)).toString();
			ref = (new Long(z)).toString();
			int l = first.length();
			while(ref.length() < first.length())
				ref = "0" + ref;
			
			for(int i=0; i<tab.length; ++i){
				for(int j=0; j<tab[i].length; ++j){
					for(int k=0; k<tab[i][j].length; ++k){
						tab[i][j][k] = -1;
					}
				}
			}
			System.out.println(rek(l, r) + rek_m(l, r));
		}
	}
}
