import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        for(int a0 = 0; a0 < n; a0++){
            String number =  input.next();
            int result = 0;
            for(int i = number.length() - 1; i >= 0; i-- ){
                if(number.charAt(i) == '0'){
                    result = result + 1;
                }else {
                    break;
                }
            }
            for(int i = 0; i < number.length(); i++){
                if(number.charAt(i) != '0'){
                    result = result + 1;
                }
            }
            System.out.println(result-1);
        }
    }
}