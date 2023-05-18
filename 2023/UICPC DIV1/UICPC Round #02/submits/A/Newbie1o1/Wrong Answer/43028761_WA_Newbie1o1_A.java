import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int T = scanner.nextInt();
        int[] numbers = new int[n];
        for (int i=0;i<n;i++){
            numbers[i] = scanner.nextInt();
        }
        int sum =0 ;
        int g=0;
        for (int h=0;h<n;h++){
            sum += numbers[h];
            if(sum > T){
                System.out.println(g);
                break;
            }
            g++;
        }


    }
}