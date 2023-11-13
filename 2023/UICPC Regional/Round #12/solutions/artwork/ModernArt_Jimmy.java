import java.io.*;
import java.util.StringTokenizer;

public class ModernArt_Jimmy {
    public static void main(String[] args) throws FileNotFoundException {
//        Kattio io = new Kattio(new FileInputStream("modernart.in"), System.out);
        Kattio io = new Kattio(System.in, System.out);
        new ModernArt_Jimmy().solve(io);
        io.close();
    }

    private int xsize, ysize;
    private int art[][];
    private UnionFind uf;

    private void solve(Kattio io) {
        xsize = io.getInt();
        ysize = io.getInt();
        art = new int[ysize][xsize];
        int q = io.getInt();
        int ans[] = new int[q];
        int noBlack = 0;
        Stroke[] strokes = new Stroke[q];
        for (int i = 0; i < q; i++) {
            Stroke stroke = new Stroke(io.getInt() - 1, io.getInt() - 1, io.getInt() - 1, io.getInt() - 1);
            for (int y = stroke.y1; y <= stroke.y2; y++) {
                for (int x = stroke.x1; x <= stroke.x2; x++) {
                    if (art[y][x]++ == 0) noBlack++;
                }
            }
            strokes[i] = stroke;
        }
        uf = new UnionFind(xsize * ysize);
        for (int y = 0; y < ysize; y++) {
            for (int x = 0; x < xsize; x++) {
                connect(x,y);
            }
        }
        for (int i = q - 1; i >= 0; i--) {
            ans[i] = uf.noSets - noBlack;
            Stroke stroke = strokes[i];
            for (int y = stroke.y1; y <= stroke.y2; y++) {
                for (int x = stroke.x1; x <= stroke.x2; x++) {
                    if (--art[y][x] == 0) noBlack--;
                    connect(x,y);
                }
            }
        }

        for (int i = 0; i < q; i++) {
            io.println(ans[i]);
        }
    }

    private void connect(int x, int y) {
        if (art[y][x] == 0) {
            if (x > 0 && art[y][x-1] == 0) uf.unionSet(map(x,y), map(x-1, y));
            if (x + 1 < xsize && art[y][x+1] == 0) uf.unionSet(map(x,y), map(x+1,y));
            if (y > 0 && art[y-1][x] == 0) uf.unionSet(map(x,y), map(x,y-1));
            if (y + 1 < ysize && art[y+1][x] == 0) uf.unionSet(map(x,y), map(x,y+1));
        }
    }

    private int map(int x, int y) {
        return y * xsize + x;
    }

    static class Stroke {
        public int x1,y1,x2,y2;

        public Stroke(int x1, int y1, int x2, int y2) {
            this.x1 = x1;
            this.y1 = y1;
            this.x2 = x2;
            this.y2 = y2;
        }
    }

    static class UnionFind {
        private final int[] p;
        private final int[] size;
        private int noSets;

        public UnionFind(int n) {
            p = new int[n];
            size = new int[n];
            for (int i = 0; i < n; i++) {
                p[i] = i;
                size[i] = 1;
            }
            noSets = n;
        }

        public int findSet(int e) {
            int v = e;
            while (p[v] != v) v = p[v];
            int root = v;
            while (p[e] != root) {
                // Path compression
                int t = e;
                e = p[e];
                p[t] = root;
            }
            return root;
        }

        public void unionSet(int a, int b) {
            a = findSet(a);
            b = findSet(b);
            if (a == b) return;
            if (size[b] > size[a]) {
                int c = a;
                a = b;
                b = c;
            }
            p[b] = a;
            size[a] += size[b];
            noSets--;
        }
    }

    static class Kattio extends PrintWriter {
        public Kattio(InputStream i) {
            super(new BufferedOutputStream(System.out));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public Kattio(InputStream i, OutputStream o) {
            super(new BufferedOutputStream(o));
            r = new BufferedReader(new InputStreamReader(i));
        }

        public boolean hasMoreTokens() {
            return peekToken() != null;
        }

        public int getInt() {
            return Integer.parseInt(nextToken());
        }

        public double getDouble() {
            return Double.parseDouble(nextToken());
        }

        public long getLong() {
            return Long.parseLong(nextToken());
        }

        public String getWord() {
            return nextToken();
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
