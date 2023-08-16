//Author: Roger Henriksson

import java.util.Scanner;

class cartrouble_rh {

	private Street indx [] = new Street[1000];
	private Street streets[] = new Street[1000];
	private int cnt;

	public static void main(String [] args) {
		new cartrouble_rh().run();
	}
	
	public Street getStreet(int id) {
		return indx[id];
	}
	
	private void clearMarks() {
		for(int i=0;i<cnt;i++) {
			streets[i].clearMark();
		}
	}

	public void run() {
		boolean noprobs = true;
		int n = 0;
		
		Scanner scan = new Scanner(System.in);	
		cnt = scan.nextInt();
		for(int i=0;i<cnt;i++) {
			int id = scan.nextInt();
			int nbrstrts = scan.nextInt();
			Street s = new Street(this,id,nbrstrts);
			streets[n++] = s;
			indx[id] = s;
			for(int j=0;j<nbrstrts;j++) {
				s.addStreet(scan.nextInt());
			}
		}

		for(int i=0;i<cnt;i++) {
			if (streets[i]!=indx[0]) {
				clearMarks();
				streets[i].traverse();
				if (!indx[0].isMarked()) {
					System.out.println("TRAPPED "+streets[i].getID());
					noprobs = false;
				}
			}
		}
		
		clearMarks();
		indx[0].traverse();
		for(int i=0;i<cnt;i++) {
			if (!streets[i].isMarked()) {
				System.out.println("UNREACHABLE "+streets[i].getID());
				noprobs = false;
			}
		}
	
		if (noprobs) {
			System.out.println("NO PROBLEMS");
		}
	}

}


class Street {

	private int conn[];
	private int nbr = 0;
	private boolean mark;
	private cartrouble_rh db;
	private int id;
	
	public Street(cartrouble_rh d, int i, int strts) {
		db = d;
		id = i;
		conn = new int[strts];
	}
	
	public void traverse() {
		if (!mark) {
			mark = true;
			for(int i=0;i<conn.length;i++) {
				db.getStreet(conn[i]).traverse();
			}
		}
	}

	public int getID() {
		return id;
	}
	
	public void addStreet(int s) {
		conn[nbr++] = s;
	}
	
	public void clearMark() {
		mark = false;
	}
	
	public void mark() {
		mark = true;
	}
	
	public boolean isMarked() {
		return mark;
	}
	
	
	

}
