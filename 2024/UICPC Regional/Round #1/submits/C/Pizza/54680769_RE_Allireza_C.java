
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int n ;
        Scanner scanner=new Scanner(System.in);
        n=scanner.nextInt();
        scanner.nextLine();
        int[] arr=new int[n] ;
        String inp = scanner.nextLine();
        for (int i = 0; i < n; i++){
            arr[i] = Integer.parseInt(String.valueOf(inp.charAt(i)));
        }

        int sum = 0;
        for (int i = 0 ; i < n ; i++){
            if (i==n-2){
                if (arr[i]==1){
                    sum+=2;
                    break;
                }
            }
            if (arr[i] == 1) {
                if (arr[i + 1] == 1 && arr[i + 2] == 1 ) {
                    sum += 2;
                    i += 1;
                } else if (arr[i + 1] == 0 && arr[i + 2] == 1) {
                    sum += 2;
                    i++;
                } else if (arr[i + 1] == 1 && arr[i + 2] == 0) {
                    sum ++;
                } else {
                    sum+=3;
                }
            }
        }
        System.out.print(sum);
    }
}