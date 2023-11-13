using System;

public class Program {
    public static void Main() {
        int n1 = Int32.Parse(Console.ReadLine());
        int n2 = Int32.Parse(Console.ReadLine());
        n2 -= n1;
        if (n2 > 180) { n2 -= 360; }
        if (n2 <= -180) { n2 += 360; }
        Console.WriteLine(n2);
    }
}
