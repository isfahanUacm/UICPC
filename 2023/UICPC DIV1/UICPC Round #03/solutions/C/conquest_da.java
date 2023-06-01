import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class conquest_da {

    static class Node implements Comparable<Node> {
        int k, a;

        Node(int k, int a) {
            this.k = k;
            this.a = a;
        }

        @Override
        public int compareTo(Node o) {
            int comp = a - o.a;
            if (comp == 0) comp = k - o.k;
            return comp;
        }
    }

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int n = sc.nextInt();
        int m = sc.nextInt();
        int[] eu = new int[m];
        int[] ev = new int[m];
        for (int i = 0; i < m; i++) {
            eu[i] = sc.nextInt() - 1;
            ev[i] = sc.nextInt() - 1;
        }

        Node[] a = new Node[n];
        for (int i = 0; i < n; i++) {
            a[i] = new Node(i, sc.nextInt());
        }

        Map<Integer, TreeSet<Node>> g = new HashMap<>();
        for (int i = 0; i < m; i++) {
            if (!g.containsKey(eu[i])) g.put(eu[i], new TreeSet<>());
            if (!g.containsKey(ev[i])) g.put(ev[i], new TreeSet<>());
            g.get(eu[i]).add(a[ev[i]]);
            g.get(ev[i]).add(a[eu[i]]);
        }

        Set<Integer> seen = new HashSet<>();
        Set<Integer> ours = new HashSet<>();
        TreeSet<Node> notYet = new TreeSet<>();
        PriorityQueue<Node> pq = new PriorityQueue<>();

        pq.add(a[0]);
        ours.add(0);
        seen.add(0);
        int army = a[0].a;

        while (!pq.isEmpty()) {
            Node u = pq.poll();
            if (!g.containsKey(u.k)) break;
            for (Node v : g.get(u.k)) {
                if (seen.contains(v.k)) continue;
                seen.add(v.k);
                if (v.a < army) {
                    army += v.a;
                    ours.add(v.k);
                    pq.add(v);
                } else {
                    notYet.add(v);
                }
            }

            while (!notYet.isEmpty() && notYet.first().a < army) {
                Node v = notYet.pollFirst();
                army += v.a;
                ours.add(v.k);
                pq.add(v);
            }
        }

        System.out.println(army);
    }

    public static void main(String[] args) {
        new conquest_da().work();
    }
}
