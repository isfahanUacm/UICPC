import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int counter = 0;
        ArrayList<String> arr = new ArrayList<>();
        for (int i = 0; i < n; i++) arr.add(sc.next());

        while(arr.contains("O")) {
            int i = arr.lastIndexOf("O");
            if (arr.get(i).equals("O")) {
                counter++;
                arr.set(i, "Z");
                if (i + 1 != n)
                    for (int j = i + 1; j < n; j++)
                        if (arr.get(j).equals("Z"))
                            arr.set(j, "O");
            }
        }
        System.out.print(counter);
    }
}