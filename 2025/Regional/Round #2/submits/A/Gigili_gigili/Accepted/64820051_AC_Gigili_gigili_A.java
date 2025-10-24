import java.util.Arrays;
import java.util.LinkedList;
import java.util.Objects;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int p = sc.nextInt();
        int s = sc.nextInt();
        String d = sc.next();

        boolean[] array = new boolean[p];
        Arrays.fill(array, true);

        LinkedList<Integer> a = new LinkedList<>();
        LinkedList<Integer> b = new LinkedList<>();
        LinkedList<Integer> c = new LinkedList<>();

        int i = 0, j = array.length - 1, k = s - 1;
        for (int index = 0; index < p; index++)
        {
            if (i < array.length && i <= k)
            {
                if (array[i])
                {
                    if (i == k)
                    {
                        a.add(i + 1);
                        c.add(k + 1);
                        array[i] = false;
                        i++;
                        k++;
                    }
                    else {
                        a.add(i + 1);
                        array[i] = false;
                        i++;
                    }
                }
            }

            if (j >= 0 && j >= k)
            {
                if (array[j])
                {
                    if (j == k)
                    {
                        b.add(j + 1);
                        c.add(k + 1);
                        array[j] = false;
                        j--;
                        if (Objects.equals(d, "R"))
                            k++;
                        if (Objects.equals(d, "L"))
                            k--;
                    }
                    else
                    {
                        b.add(j + 1);
                        array[j] = false;
                        j--;
                    }
                }


            }

            if (Objects.equals(d, "R"))
            {
                if (array[k])
                {
                    c.add(k + 1);
                    array[k] = false;
                    k++;
                }

            } else if (Objects.equals(d, "L")) {
                if (array[k])
                {
                    c.add(k + 1);
                    array[k] = false;
                    k--;
                }

            }
        }

        System.out.println(a.size() + " " + c.size() + " " + b.size());

    }
}