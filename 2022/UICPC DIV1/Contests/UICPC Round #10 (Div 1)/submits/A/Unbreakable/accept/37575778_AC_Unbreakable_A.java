import java.util.*;
public class r10_1 {
    public static void main(String[] args) {
        ArrayList<Integer> l = new ArrayList<Integer>();
        l.add(1);
        l.add(2);
        l.add(3);
        l.add(4);
        l.add(5);
        l.add(6);
        l.add(7);
        l.add(8);
        l.add(9);
        l.add(10);
        Scanner sc = new Scanner(System.in);
        long t = sc.nextLong();
        for (int i = 0; i < t; i++) {
            long n = sc.nextLong();
            Map<Integer, Long> hm = new HashMap<>();
            for (int j = 0; j < n; j++) {
                long bi = sc.nextLong();
                int di = sc.nextInt();
                if (hm.containsKey(di)) {
                    if (bi > hm.get(di)) {
                        hm.replace(di, bi);
                    }
                } else {
                    hm.put(di, bi);
                }
            }
            ArrayList<Integer> hm2 = new ArrayList<>(hm.keySet());
            boolean ans = false;
            for (int j = 1; j <= 10; j++) {
                if (!hm2.contains(j)) {
                    System.out.println("MOREPROBLEMS");
                    ans = true;
                    break;
                }
            }
            if (!ans) {
                long sum = 0;
                for (Map.Entry<Integer, Long> entry : hm.entrySet()) {
                    sum += entry.getValue();
                }
                System.out.println(sum);
            }
        }
    }
}