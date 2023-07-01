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
        List<int> a = reader.ReadLine().Split().Select(x => int.Parse(x))
            .OrderByDescending(x => x).ToList();

        Console.WriteLine(Enumerable.Range(0, n).Max(i => i + a[i] + 2));
    }
}
