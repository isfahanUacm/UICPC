import java.util.ArrayList;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        for (int i = 0; i < n; i++) {
            int count= 0;
            int size = scanner.nextInt();
            ArrayList<Integer> arr = new ArrayList<>(size);
            for (int j = 0; j < size; j++) {
                arr.add(scanner.nextInt());
            }
            for (int w : arr) {
                int s = sum(arr)-(2*w);
                if(s >= 0 && s % 2 == 0) {
                    count++;
                }
            }
            System.out.println(count);
        }


    }
    static int sum(ArrayList<Integer> arr) {
        int sum = 0;
        for (int i = 0; i < arr.size(); i++) {
            sum += arr.get(i);
        }
        return sum;
    }
}