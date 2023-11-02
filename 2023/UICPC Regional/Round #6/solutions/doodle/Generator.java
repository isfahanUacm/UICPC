public class Generator {
    public static void main(String[] args) {
	String s = "";
	int c = 0;
	double p = Double.parseDouble(args[2]);
	for (int i = 2; i < Integer.parseInt(args[0]); i++) {
	    for (int j = 2; j < Integer.parseInt(args[1]); j++) {
		if (Math.random() < p) {
		    s += i + " " + j + "\n";
		    c++;
		}
	    }
	}
	System.out.print(c + "\n" + s);
    }
}