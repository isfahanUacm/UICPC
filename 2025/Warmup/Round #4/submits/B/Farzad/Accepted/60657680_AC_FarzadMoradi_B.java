import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int z = input.nextInt();
        for (int i = 0; i < z; i++) {
            int n = input.nextInt();
            int x = input.nextInt();
            for (int j = 0; j < n; j++) {
                if(j == x){
                    continue;
                }
                else {
                    System.out.print(j + " ");
                }
            }
            if(x < n){
            System.out.print(x);}
            System.out.println();
        }
    }
}