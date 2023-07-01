//Solution by lukasP (Luká¿ Polá¿ek)
using System;
using System.IO;
using System.Linq;
using System.Collections.Generic;

class Problem
{
    static List<List<string>> digits = new List<List<string>> {
        new List<string> {"***",
         "* *",
         "* *",
         "* *",
         "***"},
        new List<string> {"  *",
         "  *",
         "  *",
         "  *",
         "  *"},
        new List<string> {"***",
         "  *",
         "***",
         "*  ",
         "***"},
        new List<string> {"***",
         "  *",
         "***",
         "  *",
         "***"},
        new List<string> {"* *",
         "* *",
         "***",
         "  *",
         "  *"},
        new List<string> {"***",
         "*  ",
         "***",
         "  *",
         "***"},
        new List<string> {"***",
         "*  ",
         "***",
         "* *",
         "***"},
        new List<string> {"***",
         "  *",
         "  *",
         "  *",
         "  *"},
        new List<string> {"***",
         "* *",
         "***",
         "* *",
         "***"},
        new List<string> {"***",
         "* *",
         "***",
         "  *",
         "***"}
    };

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);

        List<string> q = Enumerable.Range(0, 5).Select(x => reader.ReadLine()).ToList();

        int total = 0;
        bool ok = true;
        for (int k = 0; ok && k < q[0].Length; k += 4)
        {
            List<string> dig = q.Select(x => x.Substring(k, 3)).ToList();
            int num = Enumerable.Range(0, 10)
                .Where(i => Enumerable.SequenceEqual(digits[i], dig)).DefaultIfEmpty(-1).Single();
            if (num == -1) ok = false;
            total = (total * 10 + num) % 6;
        }

        if (ok && total == 0)
            Console.WriteLine("BEER!!");
        else
            Console.WriteLine("BOOM!!");
    }
}
