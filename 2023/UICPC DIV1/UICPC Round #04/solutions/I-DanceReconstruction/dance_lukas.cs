using System;
using System.IO;
using System.Collections.Generic;
using System.Linq;

class Problem
{
    class Factor
    {
        public int Prime, Power;
    }

    static IEnumerable<Factor> factor(int x)
    {
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0)
            {
                int po = 1;
                while (x % i == 0)
                {
                    po *= i;
                    x /= i;
                }
                yield return new Factor { Prime = i, Power = po };
            }
        if (x > 1)
            yield return new Factor { Prime = x, Power = x };
    }

    static int inverse(int x, int mod)
    {
        if (mod == 1) return 1;
        return Enumerable.Range(1, mod - 1).Where(y => y * x % mod == 1).First();
    }

    static int gcd(int a, int b)
    {
        return b == 0 ? a : gcd(b, a % b);
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);

        string[] ss = reader.ReadLine().Split();
        int n = int.Parse(ss[0]), k = int.Parse(ss[1]);
        List<int> a = reader.ReadLine().Split().Select(x => int.Parse(x) - 1).ToList();

        var cycles = Enumerable.Range(0, n).Select(x => new List<List<int>>()).ToArray();
        bool[] seen = new bool[n];
        foreach (int i in Enumerable.Range(0, n))
            if (!seen[i])
        {
            List<int> cyc = new List<int> ();
            int u = i;
            do {
                cyc.Add(u);
                seen[u] = true;
                u = a[u];
            } while (u != i);
            cycles[cyc.Count].Add(cyc);
        }

        Dictionary<int, int> pow = factor(k).ToDictionary(x => x.Prime, x => x.Power);
        List<int> res = Enumerable.Repeat(-1, n).ToList();
        foreach (var group in cycles.Where(x => x.Count > 0))
        {
            int len = group.First().Count;
            int need = len == 1 ?
                gcd(k, group.Count) : // we want to avoid self-loops
                factor(len)
                .Where(f => pow.ContainsKey(f.Prime))
                .Select(f => pow[f.Prime])
                .Aggregate(1, (x, y) => x * y);//multiply everything

            if (group.Count % need == 0)
                for (int i = 0; i < group.Count; i += need)
                {
                    List<int> cyc = new List<int> ();
                    foreach (int l in Enumerable.Range(0, len))
                        foreach (int j in Enumerable.Range(0, need))
                            cyc.Add(group[i + j][l]);

                    int move = inverse(k / need % len, len);
                    foreach (int j in Enumerable.Range(0, cyc.Count))
                        res[cyc[j]] = cyc[(j + move) % cyc.Count];
                }
        }

        if (res.Any(x => x == -1))
            Console.WriteLine("Impossible");
        else
            Console.WriteLine(string.Join(" ", res.Select(x => x + 1)));
    }
}
