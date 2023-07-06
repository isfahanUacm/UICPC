import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Scanner;

public class initials_da {
    class Student implements Comparable<Student> {
        String fname, lname, all;
        int flen, llen, allLen;
        char fchar;

        Student(String fname, String lname) {

            this.fname = fname;
            this.lname = lname;
            all = lname + fname;

            allLen = all.length();
            flen = fname.length();
            llen = lname.length();

            fchar = fname.charAt(0);
        }

        public String remove(int howMany) {
            if (howMany == 0) return all;

            if (howMany < fname.length()) {
                return all.substring(0, allLen - howMany);
            } else {
                return lname.substring(0, llen - (howMany - flen) - 1) + fchar;
            }
        }

        public int compareTo(Student o) {
            return all.compareTo(o.all);
        }
    }

    private int n;
    private Student[] a;
    private int[][] memo;
    private static int oo = Integer.MAX_VALUE / 2;

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));

        n = sc.nextInt();
        a = new Student[n + 1];
        memo = new int[n + 1][80];
        Arrays.fill(memo[0], -1);
        int total = 0;

        a[0] = new Student(" ", " ");
        for (int i = 1; i <= n; i++) {
            Arrays.fill(memo[i], -oo);
            a[i] = new Student(sc.next().toLowerCase(), sc.next().toLowerCase());
            total += a[i].allLen - 2;
        }
        sc.close();

        Arrays.sort(a);
        System.out.println(total - go(1, 0, "  "));
    }

    private int go(int k, int removedPrev, String prev) {
        if (k > n) return 0;
        if (memo[k][removedPrev] > -oo) return memo[k][removedPrev];

        int ret = -oo / 2;

        for (int removedCur = 0; removedCur <= a[k].all.length() - 2; removedCur++) {
            String removed = a[k].remove(removedCur);
            if (removed.compareTo(prev) <= 0) continue;
            int t = removedCur + go(k + 1, removedCur, removed);
            if (t > ret) ret = t;
        }

        return memo[k][removedPrev] = ret;
    }

    private void test() {
        Student s = new Student("Harry", "Potter");
        for (int i = 0; i <= s.allLen - 2; i++) {
            System.out.printf("removed %d characters: %s\n", i, s.remove(i));
        }
    }

    public static void main(String[] args) {
        new initials_da().work();
        // new initials_da().test();
    }
}
