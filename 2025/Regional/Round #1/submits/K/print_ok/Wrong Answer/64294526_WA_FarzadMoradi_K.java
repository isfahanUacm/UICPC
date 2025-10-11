import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws FileNotFoundException {
        Scanner in = new Scanner(new File("cubes.in"));
        //Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        for (int i = 1; i <= n; i++) {
            int x = in.nextInt();
            ArrayList<Integer> list = new ArrayList();
            for (int j = 0; j < x; j++) {
                list.add(in.nextInt());
            }
            ArrayList<Integer> list1 = new ArrayList();
            ArrayList<Integer> list2 = new ArrayList();
            for (Integer a : list){
                if(a%2 == 0){
                    list1.add(a);
                }
                else list2.add(a);
            }
            Collections.sort(list1);
            Collections.sort(list2);
            Collections.reverse(list1);
            System.out.println("Case " + i + ":");
            for(int e : list1){
                System.out.print(e + " ");
            }
            for(int e : list2){
                System.out.print(e + " ");
            }
        }

    }
}
