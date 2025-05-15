import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        ArrayList<Integer> list = new ArrayList<Integer>();
        ArrayList<Integer> answer = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) {
            list.add(sc.nextInt());
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (list.get(i) <list.get(j) && gcd(list.get(i), list.get(j)) != 1) {
                    if(!answer.contains(i+1)){
                        answer.add(i+1);
                    }
                    if(!answer.contains(j+1)){
                        answer.add(j+1);
                    }
                }
            }
        }
        if (answer.isEmpty()) {
            System.out.println(1);
            System.out.println(1);
        }
        else {System.out.println(answer.size());
            for(int i : answer){
                System.out.print(i+" ");
            }
        }





    }
    public static int gcd(int a, int b) {
        if (b==0) return a;
        return gcd(b,a%b);
    }
}