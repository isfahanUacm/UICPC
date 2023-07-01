//Solution by lukasP (Luká¿ Polá¿ek)
using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Globalization;
using System.Threading;

class Problem
{
    static IEnumerable<int> Solve(double x)
    {
        int po = 1;
        if (x < 10) foreach (int l in Enumerable.Range(0, 8))
        {
            foreach (int a in Enumerable.Range(1, 9))
            {
                double w = a * (po * x - 1) / (10 - x);
                int rw = (int)Math.Round(w);
                if (Math.Abs(w - rw) < 1e-7 && rw < po)
                    yield return a * po + rw;
            }
            po *= 10;
        }
    }

    public static void Main ()
    {
        Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);
        double x = double.Parse(reader.ReadLine());

        List<int> res = Solve(x).ToList();
        if (res.Count == 0)
            Console.WriteLine("No solution");
        else
            foreach (int s in res)
                Console.WriteLine(s);
    }
}
