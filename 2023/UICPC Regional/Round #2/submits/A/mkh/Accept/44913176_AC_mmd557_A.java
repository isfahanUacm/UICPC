import java.util.*;

import static java.util.Collections.sort;


public class Main {
    static Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        int t = sc.nextInt();
        for (int i = 0; i < t; i++) {
            ArrayList<String> list = new ArrayList<>();
            int r = sc.nextInt();
            for (int j = 0; j < r; j++) {
                String tmp = sc.next();
                list.add(tmp);
            }
            boolean is = false;
            sort(list);
            for (int j = 0; j < r-1; j++) {
                if (list.get(j+1).startsWith(list.get(j))) {
                    is = true;
                    break;
                }
            }
            if (is) {
                System.out.println("NO");
            } else {
                System.out.println("YES");
            }
        }


    }
}

