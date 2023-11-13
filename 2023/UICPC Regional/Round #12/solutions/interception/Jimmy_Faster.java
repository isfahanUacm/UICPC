import java.io.*;
import java.util.*;

public class Jimmy_Faster {

    private final int noHouses, c1, c2;
    private final boolean[] covered; // covered[x] = true if talk covered by "endpoint solution"
    private final ArrayList<Talk> talks;
    private final List<List<Talk>> talksByHouse;

    private int[] ends, starts, overlapEnds, nextLeft, leftmost, opt;
    private int circleLength;

    public Jimmy_Faster(int noHouses, ArrayList<Talk> talks, int c1, int c2) {
        this.noHouses = noHouses;
        this.talks = talks;
        this.c1 = c1;
        this.c2 = c2;
        this.covered = new boolean[talks.size()+1];
        this.talksByHouse = new ArrayList<>(talks.size()+1);
        for (int i = 0; i <= noHouses; i++) talksByHouse.add(new ArrayList<>());

        circleLength = c2-c1+2;
        ends = new int[circleLength + 1];
        starts = new int[circleLength + 1];
        overlapEnds = new int[circleLength + 1];
        nextLeft = new int[circleLength + 1];
        leftmost = new int[circleLength + 1];
        opt = new int[circleLength + 1];
    }

    public static class Pair {
        public int a,b;
        public Pair(int a, int b) { this.a = a; this.b = b; }

        @Override
        public String toString() {
            return String.format("<%d,%d>", a, b);
        }
    }

    public static class Talk {
        public int a,b,c,ix; // a < b
        public boolean isSameSide() { return c < 0; }
        public Talk(int a, int b, int c, int ix) {
            this.a = Math.min(a,b);
            this.b = Math.max(a,b);
            this.c = c;
            this.ix = ix;
        }
    }

    public void solveEndpoint(int ep, int c, int step, List<Pair> devices) {
        ArrayList<Talk> active = new ArrayList<>();
        byte[] started = new byte[this.talks.size()];
        for (int i = ep;; i+=step) {
            for (Talk talk : talksByHouse.get(i)) {
                if (started[talk.ix] == 1) {
                    devices.add(new Pair(i-step, i));
                    for (Talk at : active) {
                        covered[at.ix] = true;
                        started[at.ix] = 2;
                    }
                    active.clear();
                }
            }
            if (i == c) break;
            for (Talk talk : talksByHouse.get(i)) {
                if (started[talk.ix] == 0) {
                    started[talk.ix] = 1;
                    active.add(talk);
                }
            }
        }

    }

    private boolean isUpperLeft(int h) { return h % 2 == 1 && h < c1; }
    private boolean isLowerLeft(int h) { return h % 2 == 0 && h < c1+1; }
    private boolean isUpperRight(int h) { return h % 2 == 1 && h > c2; }
    private boolean isLowerRight(int h) { return h % 2 == 0 && h > c2+1; }

    private int withinBounds(int h) {
        // Converts a house position to the closest position in middle area
        if (isUpperLeft(h)) return c1;
        if (isLowerLeft(h)) return c1+1;
        if (isUpperRight(h)) return c2;
        if (isLowerRight(h)) return c2+1;
        return h;
    }

    private int convert(int h) {
        // Converts a house position in the middle area to the circular enumeration
        // starting at c1 (0) to c2 to c2+1 to c1+1 and back.
        assert h % 2 == 0 || (h >= c1 && h <= c2);
        assert h % 2 == 1 || (h >= c1+1 && h <= c2+1);
        return h % 2 == 1 ? (h - c1) / 2 : c2 - c1 + 1 - (h - c1 - 1) / 2;
    }

    private int deconvert(int c) {
        // Converts in the other direction
        return c <= (c2 - c1) / 2 ? c1 + c * 2 : (c2 - c1 + 1 - c) * 2 + c1 + 1;
    }

    private List<Pair> solve() {
        for (Talk talk : talks) {
            talksByHouse.get(talk.a).add(talk);
            talksByHouse.get(talk.b).add(talk);
        }

        ArrayList<Pair> solution = new ArrayList<>();
        solveEndpoint(1, c1, 2, solution);
        solveEndpoint(2, c1+1, 2, solution);
        solveEndpoint(noHouses -1, c2, -2, solution);
        solveEndpoint(noHouses, c2+1, -2, solution);

        ArrayList<Pair> bestSubSolution = null;
        ArrayList<Pair> circular = new ArrayList<>(talks.size());

        for (int mask = 0; mask < 16; mask++) {
	    if (mask > 15) continue;
            ArrayList<Pair> subSolution = new ArrayList<>(bestSubSolution == null ? 16 : bestSubSolution.size() + 5);
            circular.clear();
            if ((mask & 1) > 0) subSolution.add(new Pair(c1 - 2, c1));
            if ((mask & 2) > 0) subSolution.add(new Pair(c1 - 1, c1 + 1));
            if ((mask & 4) > 0) subSolution.add(new Pair(c2, c2 + 2));
            if ((mask & 8) > 0) subSolution.add(new Pair(c2 + 1, c2 + 3));

            for (Talk talk : talks) {
                if (covered[talk.ix]) continue;
                if ((mask & 1) > 0 && (isUpperLeft(talk.a) ^ isUpperLeft(talk.b))) continue;
                if ((mask & 2) > 0 && (isLowerLeft(talk.a) ^ isLowerLeft(talk.b))) continue;
                if ((mask & 4) > 0 && (isUpperRight(talk.b) ^ isUpperRight(talk.a))) continue;
                if ((mask & 8) > 0 && (isLowerRight(talk.b) ^ isLowerRight(talk.a))) continue;

                int a = convert(withinBounds(talk.a)), b = convert(withinBounds(talk.b));
                if ((talk.isSameSide() && talk.a % 2 == 1) || (!talk.isSameSide() && (talk.a % 2 == 1 ^ talk.c == c1))) {
                    circular.add(new Pair(a, b));
                } else {
                    circular.add(new Pair(b, a));
                }
            }

            List<Integer> circularSolution = solveCircular(circular);

            if (bestSubSolution == null || circularSolution.size() + subSolution.size() < bestSubSolution.size()) {
                for (int node : circularSolution) {
                    subSolution.add(new Pair(deconvert(node), deconvert((node + 1) % circleLength)));
                }
                bestSubSolution = subSolution;
            }
        }

        solution.addAll(bestSubSolution);

        return solution;
    }

    private List<Integer> solveCircular(ArrayList<Pair> segments) {
        if (segments.size() == 0) return new ArrayList<>();

        for (int i = 0; i <= circleLength; i++) {
            ends[i] = -1;
            starts[i] = -1;
            overlapEnds[i] = Integer.MAX_VALUE;
        }
        boolean onlyOverlapping = true;
        for (Pair segment : segments) {
            if (segment.b == 0) segment.b = circleLength; // Don't treat these as overlapping intervals
            // Only consider non-overlapping segments
            if (segment.b > segment.a) {
                // If either of these are set, a shorter segment that this one overlaps is covering it
                if (segment.a > starts[segment.b] &&
                        (ends[segment.a] < 0 || segment.b < ends[segment.a])) {
                    starts[segment.b] = segment.a;
                    ends[segment.a] = segment.b;
                    onlyOverlapping = false;
                }
            } else {
                if (segment.b < overlapEnds[segment.a]) {
                    overlapEnds[segment.a] = segment.b;
                }
            }
        }

        if (onlyOverlapping) {
            return Arrays.asList(0);
        }

        int lm = -1;
        for (int i = 0; i <= circleLength; i++) {
            if (starts[i] >= 0) {
                lm = Math.max(lm, starts[i]);
            }
            nextLeft[i] = lm;
            if (nextLeft[i] < 0) {
                leftmost[i] = -1;
                opt[i] = 0;
            } else if (leftmost[nextLeft[i]] >= 0) {
                leftmost[i] = leftmost[nextLeft[i]];
                opt[i] = opt[nextLeft[i]] + 1;
            } else {
                leftmost[i] = nextLeft[i];
                opt[i] = 1;
            }
        }
        int overlapMinEnds = Integer.MAX_VALUE;
        int rightMost = nextLeft[circleLength];
        boolean extraNeeded = true;

        for (int i = circleLength-1; i >= nextLeft[circleLength]; i--) {
            if (opt[i] + 1 == opt[circleLength]) {
                int left = leftmost[i] < 0 ? i : leftmost[i];
                if (overlapMinEnds > left) {
                    rightMost = i;
                    extraNeeded = false;
                    break;
                }
            }

            overlapMinEnds = Math.min(overlapMinEnds, overlapEnds[i]);
        }


        ArrayList<Integer> sol = new ArrayList<>(opt[circleLength] + 1);
        int cur = rightMost;
        while (cur >= 0) {
            sol.add(cur);
            cur = nextLeft[cur];
        }
        if (extraNeeded) {
            sol.add(0);
        }
        return sol;
    }

    public static void main(String[] args) throws FileNotFoundException {
//        long tm = System.currentTimeMillis();
//        Kattio io = new Kattio(new FileInputStream("surveillance.in"), System.out);
        Kattio io = new Kattio(System.in, System.out);
//        Kattio io = new Kattio(new FileInputStream("/Users/yarin/src/ncpc-2016/problems/surveillance/data/secret/07a.planted.in"),
//                new FileOutputStream("/Users/yarin/src/ncpc-2016/problems/surveillance/data/secret/07a.planted.out"));
        int n = io.getInt(), m = io.getInt(), c1 = io.getInt(), c2 = io.getInt();
        ArrayList<Talk> talks = new ArrayList<>();
        for (int i = 0; i < m; i++) {
            int a = io.getInt(), b = io.getInt();
            if (a%2 != b%2) {
                int c = io.getInt();
                talks.add(new Talk(a,b,c,i));
            } else {
                talks.add(new Talk(a,b,-1,i));
            }
        }

        List<Pair> solution = new Jimmy_Faster(n, talks, c1, c2).solve();

        io.println(solution.size());
        for (Pair device : solution) {
            io.println(device.a + " " + device.b);
        }

        io.close();
//        System.err.println("Time: " + (System.currentTimeMillis() - tm) + " ms");
    }


    private static class Kattio extends PrintWriter {
        Kattio(InputStream i, OutputStream o) {
            super(new BufferedOutputStream(o));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public int getInt() {
            return Integer.parseInt(nextToken());
        }

        private BufferedReader r;
        private String line;
        private StringTokenizer st;
        private String token;

        private String peekToken() {
            if (token == null)
                try {
                    while (st == null || !st.hasMoreTokens()) {
                        line = r.readLine();
                        if (line == null) return null;
                        st = new StringTokenizer(line);
                    }
                    token = st.nextToken();
                } catch (IOException e) {
                }
            return token;
        }

        private String nextToken() {
            String ans = peekToken();
            token = null;
            return ans;
        }
    }
}
