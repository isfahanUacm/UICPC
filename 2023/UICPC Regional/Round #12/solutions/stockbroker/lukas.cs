//Solution by lukasP (Lukáš Poláček)
using System;
using System.IO;
using System.Linq;

class Problem
{
    struct State {
        public long money, stocks, best, previous;
        public State(long m, long s, long b, long p) {
            money = m;
            stocks = s;
            best = b;
            previous = p;
        }
    }

    static State Calculate(State state, long price) {
        long stocks = state.stocks;
        long previous = state.previous;
        if (previous > price) { // Sell
            long money = state.money + previous * stocks;
            stocks = Math.Min(100000, money / price);
            return new State(money - stocks * price, stocks, state.best, price);
        } else {
            return new State(state.money, stocks,
                Math.Max(state.best, state.money + price * stocks), price);
        }
    }

    public static void Main ()
    {
        var bs = new BufferedStream(Console.OpenStandardInput());
        StreamReader reader = new StreamReader(bs);
        int n = int.Parse(reader.ReadLine());

        long result = Enumerable.Range(0, n).Select(x => long.Parse(reader.ReadLine()))
            .Aggregate(new State(100L, 0L, 100L, 600L), Calculate).best;
        Console.WriteLine(result);
    }
}
