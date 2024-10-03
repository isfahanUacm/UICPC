import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
        ArrayList<Long> answers = new ArrayList<>();
        long[] arr = new long[n];
        for (int i = 0; i < n; i++) {
            arr[i] = scanner.nextLong();
        }
        for ( int i = 0; i < n ; i++){
            ArrayList<Long> ints = new ArrayList<>();
            ints.add(arr[i]);
            int j = i;
            if ( j+1 >= n ){
                break;
            }else {
                j++;
            }
            while (arr[j] >= ints.getLast()){
                ints.add(arr[j]);
                if ( j+1 >= n ){
                    break;
                }
                j++;
            }
            while (arr[j] <= ints.getLast()){
                ints.add(arr[j]);
                if ( j+1 >= n ){
                    break;
                }
                j++;
            }
            long max = 0;
            for (Long k : ints){
                if ( k > max){
                    max = k;
                }
            }
            long a = max - ints.getFirst();
            long b = max - ints.getLast();
            answers.add(Math.min(a, b));

        }
        answers.sort(Long::compareTo);
        System.out.print(answers.getLast());
    }
}