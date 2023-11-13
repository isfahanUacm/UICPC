import java.io.*;
import java.util.LinkedList;
import java.util.Queue;
import java.util.StringTokenizer;

public class AutoCorrect_Jimmy {

    public static class Trie {
        private Trie[] letter = new Trie[28]; // 26 = autoComplete, 27 = parent
        private int distance = -1; // shortest distance to this node from the root

        public Trie(Trie parent) {
            this.letter[27] = parent;
        }
    }

    public static void main(String[] args) throws FileNotFoundException {
        Kattio io = new Kattio(System.in, System.out);
        int n = io.getInt(), m = io.getInt();
        Trie root = new Trie(null);
        for (int i = 0; i < n; i++) {
            String word = io.getWord();
            Trie current = root;
            for (int j = 0; j < word.length(); j++) {
                int c = word.charAt(j) - 'a';
                if (current.letter[c] == null) {
                    current.letter[c] = new Trie(current);
                }
                current = current.letter[c];
            }
            Trie end = current;
            current = root;
            for (int j = 0; j < word.length(); j++) {
                if (current.letter[26] == null) {
                    current.letter[26] = end;
                }
                current = current.letter[word.charAt(j) - 'a'];
            }
            if (current.letter[26] == null) {
                current.letter[26] = end; // TODO: Include test case when forgetting this fails
            }
        }
        Queue<Trie> q = new LinkedList<>();
        q.add(root);
        root.distance = 0;
        root.letter[26] = null; // can't autocomplete if no letter typed
        while (q.size() > 0) {
            Trie current = q.poll();
            for (int i = 0; i < 28; i++) {
                if (current.letter[i] != null && current.letter[i].distance == -1) {
                    current.letter[i].distance = current.distance + 1;
                    q.add(current.letter[i]);
                }
            }
        }

        for (int i = 0; i < m; i++) {
            String word = io.getWord();
            Trie current = root;
            int t = 0;
            while (t < word.length() && current.letter[word.charAt(t) - 'a'] != null) {
                current = current.letter[word.charAt(t++) - 'a'];
            }
            io.println(current.distance + word.length() - t);
        }
        io.close();
    }


    public static class Kattio extends PrintWriter {
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
