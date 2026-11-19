import java.util.Scanner;
import java.util.Vector;

public class Main {
    public static void main(String[] args) {

        class str{
            int i;
            int j;
            int x;
        }
        int n, k, q, i, j, x, aa = 0, sum = 0;
        Scanner sc = new Scanner(System.in);
        n = sc.nextInt();
        k = sc.nextInt();

        Vector<str> b = new Vector<>();
        for (int l = 0; l < k; ++l) {
            i = sc.nextInt();
            j = sc.nextInt();
            x = sc.nextInt();
            str s = new str();
            s.i = i;
            s.j = j;
            s.x = x;
            b.add(s);
        }
        q = sc.nextInt();
        for (int l = 0; l < q; ++l) {
            j = sc.nextInt();
            i = sc.nextInt();
            x = sc.nextInt();
            int z = 0;
            while (z < k){
                if(i < b.get(z).i)
                    break;
                else if (i == b.get(z).i && j < b.get(z).j)
                    break;
                else if (j == b.get(z).j && i == b.get(z).i) {
                    sum += x * b.get(z).x;
                    break;
                }
                else
                    ++z;
            }
        }
        System.out.println(sum);
    }
}