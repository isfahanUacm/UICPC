import java.util.Scanner;

public class numbers_da {

    private void work() {

        Scanner sc = new Scanner(System.in);
        int nc = Integer.parseInt(sc.nextLine());
        for (int tc = 1; tc <= nc; tc++) {
            String line = sc.nextLine();

            StringBuilder sb = new StringBuilder(line).reverse();

            int sum = getSum(sb);
            sum = addTwos(sb, sum);
            sum = addFours(sb, sum);
            addEights(sb, sum);

            System.out.println(sb.reverse());
        }
        sc.close();
    }

    private void addEights(StringBuilder sb, int sum) {
        int p2 = Integer.highestOneBit(sum);
        if (p2 != sum)
            p2 <<= 1;

        while (sum < p2) {
            sb.insert(0, '8');
            sum += 8;
        }
    }

    private int addFours(StringBuilder sb, int sum) {
        int count = 0;
        for (int i = sb.length() - 1; i >= 0; i--) {
            if (sb.charAt(i) == '2') {
                count++;
            } else if (sb.charAt(i) == '4') {
                count += 2;
            } else {
                if ((count & 3) != 0) {
                    sb.insert(i + 1, '4');
                    sum += 4;
                }
                count = 0;
            }
        }

        if ((count & 3) != 0 && sum != Integer.highestOneBit(sum)) {
            sb.insert(0, '4');
            sum += 4;
        }

        return sum;
    }

    private int addTwos(StringBuilder sb, int sum) {
        int count = 0;
        for (int i = sb.length() - 1; i >= 0; i--) {
            if (sb.charAt(i) == '2') {
                count++;
            } else {
                if ((count & 1) != 0) {
                    sb.insert(i + 1, '2');
                    sum += 2;
                }
                count = 0;
            }
        }

        if ((count & 1) != 0 && sum != Integer.highestOneBit(sum)) {
            sb.insert(0, '2');
            sum += 2;
        }

        return sum;
    }

    private int getSum(StringBuilder sb) {
        int sum = 0;
        for (int i = 0; i < sb.length(); i++) {
            sum += sb.charAt(i) - '0';
        }
        return sum;
    }

    public static void main(String[] args) {
        long startTime = System.currentTimeMillis();
        new numbers_da().work();
        long t = System.currentTimeMillis() - startTime;
        System.err.println(String.format("Elapsed time: %d:%02d.%03d\n", t / 60000, (t / 1000) % 60, t % 1000));
    }

}
