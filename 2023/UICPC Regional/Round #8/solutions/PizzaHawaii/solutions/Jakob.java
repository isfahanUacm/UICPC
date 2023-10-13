// @EXPECTED_RESULTS@: CORRECT

import java.util.*;

public class Jakob {
	public static void main(String args[]) {
		Scanner sc = new Scanner(System.in);
		int ntc = sc.nextInt();
		while(ntc-->0) {
			int npizzas = sc.nextInt();
			HashMap<String, HashSet<String>> l1 = new HashMap<String, HashSet<String>>();
			HashMap<String, HashSet<String>> l2 = new HashMap<String, HashSet<String>>();
			TreeSet<String> ings1 = new TreeSet<String>();
			TreeSet<String> ings2 = new TreeSet<String>();
			for(int i = 0; i < npizzas; i++) {
				String pname = sc.next();
				int n1 = sc.nextInt();
				for(int j = 0; j < n1; j++) {
					String iname = sc.next();
					if(!ings1.contains(iname)) {
						ings1.add(iname);
						l1.put(iname, new HashSet<String>());
					}
					l1.get(iname).add(pname);
				}
				int n2 = sc.nextInt();
				for(int j = 0; j < n2; j++) {
					String iname = sc.next();
					if(!ings2.contains(iname)) {
						ings2.add(iname);
						l2.put(iname, new HashSet<String>());
					}
					l2.get(iname).add(pname);
				}
			}
			for(String i1 : ings1) {
				for(String i2 : ings2) {
					if(l1.get(i1).equals(l2.get(i2))) {
						System.out.println("(" + i1 + ", " + i2 + ')');
					}
				}
			}
			if(ntc != 0) System.out.println();
		}
	}
}
