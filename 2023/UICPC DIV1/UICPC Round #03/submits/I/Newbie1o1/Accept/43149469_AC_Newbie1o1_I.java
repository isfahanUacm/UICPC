import java.util.Scanner;

public class Main{
    public static void main(String[]args){
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        if (N %2 != 0){
            System.out.println("still running");
            return;
        }
        int[] numbers = new int[N];
        for (int i=0;i<N;i++){
            numbers[i] = scanner.nextInt();
        }
        int sum=0;
        for(int j=0;j<N-1;j++){
            if(j==N/2){
                break;
            }
            int temp = (numbers[(2 * j) + 1]) - numbers[2 * j];
            sum += temp;
        }
        System.out.println(sum);
    }
}