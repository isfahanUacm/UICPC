//Solution by lukasP (Luká¿ Polá¿ek)
using System;
using System.IO;

class Problem
{
    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);

        string s = reader.ReadLine();
        string t = reader.ReadLine();
        int start = 0;
        while (start < s.Length && start < t.Length && s[start] == t[start])
            start++;
        int end = 0;
        while (end < s.Length && end < t.Length && s[s.Length - 1 - end] == t[t.Length - 1 - end])
            end++;

        if (start + end > s.Length) end = s.Length - start;
        Console.WriteLine(Math.Max(t.Length - start - end, 0));
    }
}
