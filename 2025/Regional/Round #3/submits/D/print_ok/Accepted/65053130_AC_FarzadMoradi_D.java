import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String input = sc.nextLine();
        boolean aa = true;
        int[] arr = new int[26];
        for (int i = 0; i < input.length(); i++) {
            arr[input.charAt(i) - 'a']++;
        }
        if(input.length()%2 == 0){
            for (int i = 0; i < 26; i++) {
                if(arr[i] %2 !=  0){
                    aa = false;
                }
            }
        }
        else {
            int one = 1;
            for (int i = 0; i < 26; i++) {
                if(arr[i] % 2 != 0){
                    one--;
                }
            }
            if(one != 0){
                aa = false;
            }
        }
        if(aa){
            System.out.println("yes");
        }
        else{
            System.out.println("no");
        }
    }
}
