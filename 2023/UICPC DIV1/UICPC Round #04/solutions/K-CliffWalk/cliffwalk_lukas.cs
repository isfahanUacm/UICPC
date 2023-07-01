//Solution by lukasP (Luká¿ Polá¿ek)
using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Globalization;
using System.Threading;

class Problem
{
    static double Dijkstra(List<List<double>> t, List<List<int>> c, int x, int y, double speed)
    {
        int[] dx = new int[] {0, 1, 0, -1};
        int[] dy = new int[] {1, 0, -1, 0};
        int h = t.Count, w = t[0].Count;

        bool[,,] seen = new bool[h, w, 2];
        double[,,] dist = new double[h, w, 2];
        foreach (int i in Enumerable.Range(0, h))
            foreach (int j in Enumerable.Range(0, w))
                foreach (int k in Enumerable.Range(0, 2))
                    dist[i, j, k] = 13;

        foreach (int k in Enumerable.Range(0, 2))
        {
            dist[x, y, k] = 0;
            SortedSet<Tuple<double, int, int>> q = new SortedSet<Tuple<double, int, int>> ();
            q.Add(Tuple.Create(0.0, x, y));
            while (q.Count > 0)
            {
                var best = q.Min;
                q.Remove(best);
                if (seen[best.Item2, best.Item3, k])
                    continue;
                seen[best.Item2, best.Item3, k] = true;

                foreach (var z in Enumerable.Range(0, 4)
                        .Select(l => new {X = best.Item2 + dx[l], Y = best.Item3 + dy[l]})
                        .Where(z => z.X >= 0 && z.X < h && z.Y >= 0 && z.Y < w &&
                         Math.Abs(c[best.Item2][best.Item3] - c[z.X][z.Y]) <= 1000))
                {
                    double ndist = speed +
                        Math.Max(t[z.X][z.Y] + Convert.ToInt32(k == 0), best.Item1);

                    if (ndist + t[z.X][z.Y] + Convert.ToInt32(k == 1) >= 12 - 1e-9)
                        continue;

                    if (ndist < dist[z.X, z.Y, k])
                    {
                        dist[z.X, z.Y, k] = ndist;
                        q.Add(Tuple.Create(dist[z.X, z.Y, k], z.X, z.Y));
                    }
                }
            }
        }

        return (
            from i in Enumerable.Range(0, h)
            from j in Enumerable.Range(0, w)
            where dist[i, j, 0] <= 12 - dist[i, j, 1]
            select Math.Sqrt((i - x) * (i - x) + (j - y) * (j - y))
            ).Max();
    }

    static double a;
    static double tide(int z)
    {
        if (Math.Abs(2 * z / 1000.0 / a - 1) > 1) return -10.0;
        return Math.Acos(2 * z / 1000.0 / a - 1) * 6 / Math.PI;
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);
        Thread.CurrentThread.CurrentCulture = System.Globalization.CultureInfo.InvariantCulture;

        string[] ss = reader.ReadLine().Split();
        a = double.Parse(ss[0]);
        double m = double.Parse(ss[1]);
        ss = reader.ReadLine().Split();
        int h = int.Parse(ss[1]), x = int.Parse(ss[2]), y = int.Parse(ss[3]);

        List<List<int>> c = Enumerable.Range(0, h)
            .Select(z => reader.ReadLine().Split().Select(q => int.Parse(q)).ToList()).ToList();
        List<List<double>> t = Enumerable.Range(0, h)
            .Select(z => c[z].Select(q => tide(q)).ToList()).ToList();

        Console.WriteLine("{0:0.#########}", Dijkstra(t, c, y, x, m / 3600) * 10);
    }
}
