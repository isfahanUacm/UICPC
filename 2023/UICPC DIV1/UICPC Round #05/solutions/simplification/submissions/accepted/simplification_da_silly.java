import java.io.*;
import java.util.PriorityQueue;

public class simplification_da_silly {

    class Triangle implements Comparable<Triangle> {
        int left, mid, right;
        long area;

        Triangle(int left, int mid, int right, long area) {
            this.left = left;
            this.right = right;
            this.mid = mid;
            this.area = area;
        }

        @Override
        public int compareTo(Triangle o) {
            if (area < o.area)
                return -1;
            if (area > o.area)
                return 1;
            if (mid < o.mid)
                return -1;
            if (mid > o.mid)
                return 1;
            return (right - left) - (o.right - o.left);
        }

        public String toString() {
            return String.format("(%d, %d, %d) - %d", left, mid, right, area);
        }
    }

    private byte[] input = new byte[1 << 23];
    private int InIdx;

    private byte[] output = new byte[1 << 23];
    private int outIdx;
    private byte[] tmpNum = new byte[16];


    private int readInt() {
        while (input[InIdx] < '-')
            InIdx++;
        boolean pos = true;
        if(input[InIdx] == '-'){
            pos = false;
            InIdx++;
        }
        int ret = 0;
        while (input[InIdx] >= '0')
            ret = 10 * ret + input[InIdx++] - '0';
        return pos ? ret : -ret;
    }

    private void writeInt(int x) {
        int tmpIdx = 0;
        while (x > 0) {
            tmpNum[tmpIdx++] = (byte) (x % 10 + '0');
            x /= 10;
        }
        while (--tmpIdx >= 0) {
            output[outIdx++] = tmpNum[tmpIdx];
        }
        output[outIdx++] = (byte) '\n';
    }

    private void work() throws IOException {

        try {
            System.in.read(input, 0, input.length);
        } catch (Exception e) {
            // blah
        }

        int n = readInt() + 1;
        int m = n - readInt() - 1;

        int[] x = new int[n];
        int[] y = new int[n];
        for (int i = 0; i < n; i++) {
            x[i] = readInt();
            y[i] = readInt();
        }

        Triangle[] ts = new Triangle[n];
        PriorityQueue<Triangle> pq = new PriorityQueue<>();
        boolean[] seen = new boolean[n];

        for (int i = 1; i < n - 1; i++) {
            ts[i] = new Triangle(i - 1, i, i + 1, getArea(i - 1, i, i + 1, x, y));
            pq.add(ts[i]);
        }

        while (m-- > 0) {
            Triangle cur = pq.poll();
            while (seen[cur.left] || seen[cur.right])
                cur = pq.poll();

            seen[cur.mid] = true;
            writeInt(cur.mid);

            if (cur.left > 0) {
                ts[cur.left] = new Triangle(ts[cur.left].left, cur.left, cur.right,
                        getArea(ts[cur.left].left, cur.left, cur.right, x, y));
                pq.add(ts[cur.left]);
            }

            if (cur.right < n - 1) {
                ts[cur.right] = new Triangle(cur.left, cur.right, ts[cur.right].right,
                        getArea(cur.left, cur.right, ts[cur.right].right, x, y));
                pq.add(ts[cur.right]);
            }
        }

        System.out.write(output, 0, outIdx);
        System.out.close();
    }

    private long getArea(int i, int j, int k, int[] x, int[] y) {
        long bax = x[j] - x[i];
        long bay = y[j] - y[i];
        long cax = x[k] - x[i];
        long cay = y[k] - y[i];
        return Math.abs(bax * cay - cax * bay);
    }

    public static void main(String[] args) throws IOException {
        new simplification_da_silly().work();
    }

}
