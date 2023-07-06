import java.util.Scanner;

public class hissingmicrophone_da {

	private void work() {
		Scanner sc = new Scanner(System.in);
		System.out.println((sc.next().contains("ss") ? "" : "no ") + "hiss");
		sc.close();
	}

	public static void main(String[] args) {
		new hissingmicrophone_da().work();
	}

}
