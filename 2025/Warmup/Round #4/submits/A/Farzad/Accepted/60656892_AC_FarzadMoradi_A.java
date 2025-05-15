import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for(int a0 = 0; a0 < n; a0++){
            int result = 0;
            int n1 = input.nextInt();
            String reshte = input.next();
            for(int i = 0; i < n1; i++){
                if(reshte.charAt(i) == '1'){
                    result = result + 1;
                }
            }
            result = result * n1;
            for(int i = 0; i < n1; i++){
                if(reshte.charAt(i) == '1'){
                    result = result - 1;
                }
                else {
                    result = result + 1;
                }
            }
            System.out.println(result);
        }
    }
}