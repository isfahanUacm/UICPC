using System;
using System.Linq;

class Jimmy {
    static void Main() {
        int[] data = Console.ReadLine().Split(' ').Select(p => int.Parse(p)).ToArray();
        int n = data[0], m = data[1], s = data[2], d = data[3];
        int[] cold = Console.ReadLine().Split(' ').Select(p => int.Parse(p)).ToArray();
        int[] refill = new int[s];
        for(int j=0;j<n;j++) {
            int bestSlot = -1;
            for(int i=0;i<s;i++) {
                if (refill[i] + cold[i] < d && (bestSlot < 0 || cold[i] < cold[bestSlot])) bestSlot = i;
            }
            refill[bestSlot]++;
        }
        int totalCold = 0;
        for(int i=0;i<s;i++) {
            if (refill[i] == 0) totalCold += cold[i];
        }
        if (totalCold >= m) {
            for(int i=0;i<s;i++) {
                Console.Write(refill[i] + " ");
            }
            Console.WriteLine();
        } else {
            Console.WriteLine("impossible");
        }
    }
}
