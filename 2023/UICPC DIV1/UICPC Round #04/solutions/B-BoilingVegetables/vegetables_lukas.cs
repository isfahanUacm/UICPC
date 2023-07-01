//Solution by lukasP (Luká¿ Polá¿ek)
using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;
using System.Threading;

class Problem
{
    static int max_cuts = 500;

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);
        Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;

        string[] ss = reader.ReadLine().Split();
        double t = double.Parse(ss[0]);

        List<double> w = reader.ReadLine().Split().Select(x => double.Parse(x)).OrderBy(x => x).ToList();
        int res = max_cuts + 47, left = int.Parse(ss[1]);
        foreach (double q in w)
        {
            for (int i = 1; i <= max_cuts && left * (i - 1) <= res; i++)
            {
                double big = q / i;
                int cuts = 0;
                bool ok = true;
                foreach (double p in w)
                {
                    int cnt = (int)Math.Ceiling(p / big);
                    if (p / cnt < t * big)
                    {
                        ok = false;
                        break;
                    }
                    cuts += cnt - 1;
                }
                if (ok && cuts < res)
                    res = cuts;
                if (ok) break;
            }
            left--;
        }
        Console.WriteLine(res);
    }
}
