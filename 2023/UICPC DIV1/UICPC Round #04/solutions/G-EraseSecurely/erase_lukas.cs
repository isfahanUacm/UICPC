//Solution by lukasP (Luká¿ Polá¿ek)
using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Problem
{
    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);

        int n = int.Parse(reader.ReadLine());
        string a = reader.ReadLine(), b = reader.ReadLine();
        if (n % 2 == 1)
            b = string.Join("", b.Select(x => 1 - (x - '0')));

        Console.Write("Deletion ");
        if (a == b)
            Console.WriteLine("succeeded");
        else
            Console.WriteLine("failed");
    }
}
