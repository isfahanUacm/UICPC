import java.util.*;

public class r10_3 {

    static long gcd(long a, long b) {
        if (a == 0)
            return b;
        return gcd(b % a, a);
    }

    static long findGCD(long arr[]) {
        long result = arr[0];
        for (long element : arr) {
            result = gcd(result, element);

            if (result == 1) {
                return 1;
            }
        }

        return result;
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long n = sc.nextLong();
        for (int i = 0; i < n; i++) {
            long w = sc.nextLong();
            long l = sc.nextLong();
//            Set<Long> lst = new HashSet<Long>();
            SortedSet<Long> lst = new TreeSet<>();
            long ans1 = findGCD(new long[]{w, w, l - 2, l - 2});
            long ans2 = findGCD(new long[]{w, w - 1, l - 1, l - 2});
            long ans3 = findGCD(new long[]{w - 1, w - 1, l, l - 2});
            long ans4 = findGCD(new long[]{w - 2, w - 2, l, l});
            long ans5 = findGCD(new long[]{w - 2, w - 1, l, l - 2});
            long ans6 = findGCD(new long[]{w, w - 2, l - 1, l - 1});
            long ans7 = findGCD(new long[]{w - 2, w - 1, l, l - 1});
            long ans8 = findGCD(new long[]{w - 1, w - 1, l - 1, l - 1});
            lst.add(ans1);
            lst.add(ans2);
            lst.add(ans3);
            lst.add(ans4);
            lst.add(ans5);
            lst.add(ans6);
            lst.add(ans7);
            lst.add(ans8);
            System.out.print(lst.size() + " ");
            Iterator<Long> ans = lst.iterator();
            long j = -1;
            while (ans.hasNext()) {
                j += 1;
                if (j == lst.size() - 1) {
                    System.out.println(ans.next());
                } else
                    System.out.print(ans.next() + " ");
            }

        }

    }

}