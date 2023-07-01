//Solution by lukasP (Luká¿ Polá¿ek)
using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;
using System.Globalization;
using System.Threading;

public class PriorityQueue
{
    List<Tuple<double, int, int>> q;
    public PriorityQueue()
    {
        q = new List<Tuple<double, int, int>> ();
        q.Add(Tuple.Create(0.0, 0, 0));
    }

    public void Enqueue(Tuple<double, int, int> x)
    {
        int pos = q.Count;
        q.Add(x);
        for (; pos > 1; pos /= 2)
        {
            if (q[pos].Item1 < q[pos / 2].Item1)
            {
                Tuple<double, int, int> temp = q[pos];
                q[pos] = q[pos / 2];
                q[pos / 2] = temp;
            }
            else break;
        }
    }

    public Tuple<double, int, int> Top()
    {
        return q[1];
    }

    public void Dequeue()
    {
        q[1] = q.Last();
        q.RemoveAt(q.Count - 1);
        for (int pos = 1; pos < q.Count; )
        {
            int npos = 2 * pos;
            if (npos + 1 < q.Count && q[npos + 1].Item1 < q[npos].Item1)
                npos++;

            if (npos >= q.Count || q[npos].Item1 >= q[pos].Item1)
                break;

            Tuple<double, int, int> temp = q[npos];
            q[npos] = q[pos];
            q[pos] = temp;
            pos = npos;
        }
    }

    public bool Empty()
    {
        return q.Count <= 1;
    }
}

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

            PriorityQueue q = new PriorityQueue();
            q.Enqueue(Tuple.Create(0.0, x, y));
            while (!q.Empty())
            {
                var best = q.Top();
                q.Dequeue();
                if (seen[best.Item2, best.Item3, k]) continue;
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
                        q.Enqueue(Tuple.Create(dist[z.X, z.Y, k], z.X, z.Y));
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
