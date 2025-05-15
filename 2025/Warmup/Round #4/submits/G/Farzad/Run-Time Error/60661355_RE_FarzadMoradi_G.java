import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static int gcd(int a, int b) {
        while (b != 0) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }
    public static void main(String[] args) {

        Scanner input = new Scanner(System.in);
        int n = input.nextInt();
        int[] arr = new int[n];
        ArrayList<Integer>  list = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            arr[i] = input.nextInt();
        }
        int[] temp = arr.clone();
        Arrays.sort(temp);
        int base = 0;
        int x = 0;
        for(int i = 0; i < n; i++){
            if(temp[i] == 1 || temp[i] == temp[i+1]){
                continue;
            }else{
                base = temp[i];
                x = i;
                break;
            }
        }
        list.add(base);
        for(int i = x+1; i < n; i++){
            if(gcd(base,temp[i]) != 1){
                base = temp[i];
                list.add(base);
            }
        }
//        System.out.println(list);
        System.out.println(list.size());
        for(int i = 0; i < list.size(); i++){
            for (int l =  0; l < arr.length; l++){
                if(arr[l] == list.get(i)){
                    System.out.print(l+1 + " ");
                    break;
                }
            }
        }





    }

}