//import java.util.Scanner;
//
//public class Main {
//    public static void main(String[] args) {
//        Scanner input = new Scanner(System.in);
//        int biti = input.nextInt();
//        int n =  input.nextInt();
//        input.nextLine();
//        String tartib = input.nextLine();
//        String adami = Integer.toBinaryString(biti);
//        int[] hasht =  new int[8];
//        for(int a=7;a>=0;a--){
//            hasht[a] = Integer.parseInt(adami.charAt(a)+"");
//        }
//        for(int b=0;b<n;b++){
//            StringBuilder result = new StringBuilder();
//            for (int i =0;i<tartib.length();i++){
//                String num2;
//                int x;
//                if(i == 0){
//                    num2= tartib.charAt(i)+""+tartib.charAt(i+1);
//                    x = Integer.parseInt(num2,2);
//                }
//                else if(i == tartib.length()-1){
//                    num2= tartib.charAt(i)+""+tartib.charAt(i-1);
//                    x = Integer.parseInt(num2,2);
//                }else{
//                    num2= tartib.charAt(i)+""+tartib.charAt(i-1)+""+tartib.charAt(i+1);
//                    x = Integer.parseInt(num2,2);
//                }
//                result.append(hasht[x - 1]);
//            }
//            System.out.println(result.toString());
//        }
//    }
//}
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int zz = input.nextInt();
        int nexts = input.nextInt();
        input.nextLine();
        String now = input.nextLine();


        String binary = String.format("%8s", Integer.toBinaryString(zz)).replace(' ', '0');


        int[] arr = new int[8];
        for (int i = 0; i < 8; i++) {
            arr[i] = binary.charAt(7 - i) - '0';
        }

        for (int g = 0; g < nexts; g++) {
            StringBuilder next = new StringBuilder();
            for (int i = 0; i < now.length(); i++) {
                char left = (i == 0) ? '0' : (now.charAt(i - 1) == 'X' ? '1' : '0');
                char mid = now.charAt(i) == 'X' ? '1' : '0';
                char right = (i == now.length() - 1) ? '0' : (now.charAt(i + 1) == 'X' ? '1' : '0');

                String xx = "" + left + mid + right;
                int yyyy = Integer.parseInt(xx, 2);
                next.append(arr[yyyy] == 1 ? 'X' : '.');
            }
            System.out.println(next.toString());
            now = next.toString();
        }
    }
}
