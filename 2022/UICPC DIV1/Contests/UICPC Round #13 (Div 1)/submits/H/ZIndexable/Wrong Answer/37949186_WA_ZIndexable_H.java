import java.util.ArrayList;
import java.util.Scanner;

public class Temp {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int counter = 0;
        ArrayList<String> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) arr.add(sc.next());
        int i = arr.lastIndexOf("O");
        if (arr.get(i).equals("O")) counter += Math.pow(2, arr.size() - i);
        System.out.print(counter);
    }
}