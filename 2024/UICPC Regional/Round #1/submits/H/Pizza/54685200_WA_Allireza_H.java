import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        scanner.nextLine();
//        ArrayList<Long> answers = new ArrayList<>();
        long[] answers = new long[n];
        int count=0;

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

            answers[count++] = Math.min(a, b);
//            answers.add(Math.min(a, b));

        }
        long max = 0;
        for ( int i = 0 ; i < count ; i++){
            if (answers[i] > max);
            max = answers[i];
        }
        System.out.print(max);
    }
}