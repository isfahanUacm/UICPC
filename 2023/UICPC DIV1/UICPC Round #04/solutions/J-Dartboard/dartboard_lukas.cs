//Solution by lukasP (Luká¿ Polá¿ek)
using System;
using System.IO;
using System.Linq;
using System.Globalization;
using System.Threading;

class Problem
{
    public static double integrate(double x, double s)
    {
        return -Math.Exp(-x * x / (2 * s * s));
    }
    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);
        Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;

        string[] ss = reader.ReadLine().Split();
        double rbe = double.Parse(ss[0]), rb = double.Parse(ss[1]),
               ti = double.Parse(ss[2]), to = double.Parse(ss[3]),
               di = double.Parse(ss[4]), ddo = double.Parse(ss[5]);
        double sig = double.Parse(reader.ReadLine());

        double res = 0;
        res += 50 * (integrate(rbe, sig) - integrate(0.0, sig));
        res += 25 * (integrate(rb, sig) - integrate(rbe, sig));
        res += 10.5 * (integrate(ti, sig) - integrate(rb, sig));
        res += 3 * 10.5 * (integrate(to, sig) - integrate(ti, sig));
        res += 10.5 * (integrate(di, sig) - integrate(to, sig));
        res += 2 * 10.5 * (integrate(ddo, sig) - integrate(di, sig));

        Console.WriteLine("{0:0.#########}", res);
    }
}
