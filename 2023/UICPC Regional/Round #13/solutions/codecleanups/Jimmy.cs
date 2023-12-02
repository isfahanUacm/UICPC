using System;

public class Jimmy {
    public static void Main(String[] args) {
        int n = int.Parse(Console.ReadLine());
        int cleanups = 0, sum = 0, current = 0;
        bool[] push = new bool[366];
        String[] ints = Console.ReadLine().Split(' ');
        for(int i=0;i<n;i++) {
            int day = int.Parse(ints[i]);
            push[day] = true;
        }
        for(int i=1;i<=365;i++) {
            if (push[i]) {
                current++;
            }
            if (sum + current >= 20) {
                cleanups++;
                current = 0;
                sum = 0;
            }
            sum += current;
        }
        if (sum > 0) cleanups++;
        Console.WriteLine(cleanups);
    }
}
