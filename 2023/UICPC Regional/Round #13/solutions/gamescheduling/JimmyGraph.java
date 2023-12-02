import java.util.*;

public class JimmyGraph {
    public static class Graph {

        private final List<Node> nodes;
        private final List<Edge> edges;
        private final int noColors;

        public Graph(int noNodes, int noColors) {
            edges = new ArrayList<>();
            nodes = new ArrayList<>(noNodes);
            this.noColors = noColors;
            for (int i = 0; i < noNodes; i++) {
                addNode();
            }
        }

        public List<Node> getNodes() {
            return nodes;
        }

        public List<Edge> getEdges() {
            return edges;
        }

        public class Node {
            private int index;
            private Map<Node, Edge> edges = new HashMap<>();
            private Map<Integer, Edge> coloredEdge = new HashMap<>();
            private Set<Integer> freeColors;

            int getIndex() {
                return index;
            }

            Node(int index) {
                this.index = index;

                freeColors = new HashSet<>(noColors);
                for (int i = 1; i <= noColors; i++) {
                    freeColors.add(i);
                }
            }

            @Override
            public String toString() {
                return Integer.toString(index);
            }

            Collection<Edge> getEdges() {
                return edges.values();
            }

            Collection<Node> getAdjacentNodes() {
                return edges.keySet();
            }

            Edge getEdge(Node node) {
                return edges.get(node);
            }

            Edge getEdgeByColor(int color) {
                return coloredEdge.get(color);
            }

            boolean isColorFree(int color) {
                return !coloredEdge.containsKey(color);
            }

            Collection<Integer> getFreeColors() {
                return freeColors;
            }

            void internalAddColor(Edge edge) {
                if (!isColorFree(edge.color)) {
                    throw new RuntimeException("Color " + edge.color + " is not free on node " + getIndex());
                }
                freeColors.remove(edge.color);
                coloredEdge.put(edge.color, edge);
            }

            void internalRemoveColor(int color) {
                if (!coloredEdge.containsKey(color)) {
                    throw new RuntimeException("Color " + color + " is already free on node " + getIndex());
                }
                freeColors.add(color);
                coloredEdge.remove(color);
            }

            int getFreeColor(int exclude) {
                for (Integer color : freeColors) {
                    if (color != exclude) return color;
                }
                throw new RuntimeException("No more free colors available!");
            }

            void getColoredPath(int c, int d, ArrayList<Edge> cdPath) {
                Edge edge = coloredEdge.get(c);
                if (edge != null) {
                    // Can't this get into an infinite loop!?
                    cdPath.add(edge);
                    ((edge.getA() == this ? edge.getB() : edge.getA())).getColoredPath(d, c, cdPath);
                }
            }

            int getEdgeColor(Node u) {
                return edges.get(u).color;
            }
        }

        public class Edge {
            private Node a, b;
            private int color;

            Edge(Node a, Node b) {
                this.a = a;
                this.b = b;
            }

            Node getA() {
                return a;
            }

            Node getB() {
                return b;
            }

            int getColor() {
                return this.color;
            }

            void uncolor() {
                setColor(0);
            }

            void setColor(int color) {
                //System.out.println("Coloring edge (" + getA() + "-" + getB() + ") to " + color);
                if (this.color == color) return;
                if (this.color > 0) {
                    a.internalRemoveColor(this.color);
                    b.internalRemoveColor(this.color);
                }

                this.color = color;

                if (color > 0) {
                    a.internalAddColor(this);
                    b.internalAddColor(this);
                }
            }

            @Override
            public String toString() {
                return "(" + getA() + "-" + getB() + ")";
            }
        }

        void addEdge(int a, int b) {
            addEdge(new Edge(getNode(a), getNode(b)));
        }

        void addEdge(Edge e) {
            edges.add(e);
            e.getA().edges.put(e.getB(), e);
            e.getB().edges.put(e.getA(), e);
        }

        Node getNode(int index) {
            return nodes.get(index);
        }

        int getNodeCount() {
            return nodes.size();
        }

        Node addNode() {
            Node node = new Node(getNodeCount());
            nodes.add(node);
            return node;
        }

        private void colorEdges() {
            for (Graph.Edge edge : getEdges()) {
                Node u = edge.getA();
                Node v = edge.getB();
                //System.out.println("Finding max fan on " + u);

                ArrayList<Node> fan = new ArrayList<>();
                fan.add(v);

                Set<Edge> edges = new HashSet<>(u.getEdges());
                edges.remove(edge);

                // This part is supposed to be done in O(|V|) time but I've no idea how
                // This version is O(|E|*|V|)
                extendFan:
                while (true) {
                    for (int freeColor : fan.get(fan.size() - 1).getFreeColors()) {
                        Edge e = u.getEdgeByColor(freeColor);
                        if (e != null && edges.contains(e)) {
                            fan.add(e.getA() == u ? e.getB() : e.getA());
                            edges.remove(e);
                            continue extendFan;
                        }
                    }
                    break;
                }

                //System.out.println("Maximal fan of vertex " + u + " is " + fan);
                int d = fan.get(fan.size() - 1).getFreeColor(0);
                int c = u.getFreeColor(d);
                ArrayList<Edge> cdPath = new ArrayList<>();
                u.getColoredPath(c, d, cdPath);
                Collections.reverse(cdPath);
                u.getColoredPath(d, c, cdPath);
                //System.out.println("cd_u path (c=" + c + ", d=" + d + "): " + cdPath);

                if (cdPath.size() > 0) {
                    int current = cdPath.get(0).color;
                    for (Edge coloredEdge : cdPath) {
                        coloredEdge.uncolor();
                    }
                    for (Edge coloredEdge : cdPath) {
                        coloredEdge.setColor(c + d - current);
                        current = c + d - current;
                    }
                }

                int wi = 0;
                if (fan.size() == 1 || fan.get(0).isColorFree(d)) {
                    assert(fan.get(0).isColorFree(d));
                } else {
                    wi = 1;
                    while (true) {
                        int q = fan.get(wi).getEdgeColor(u);
                        assert q > 0;
                        assert fan.get(wi-1).isColorFree(q);
                        if (fan.get(wi).isColorFree(d)) break;
                        wi++;
                    }
                }
                //System.out.println("w = " + fan.get(wi) + ", wi = " + wi);
                if (wi > 0) {
                    for (int i = 0; i < wi; i++) {
                        int nextColor = fan.get(i+1).getEdge(u).color;
                        fan.get(i + 1).getEdge(u).uncolor();
                        fan.get(i).getEdge(u).setColor(nextColor);
                    }
                }
                fan.get(wi).getEdge(u).setColor(d);
            }
        }
    }


    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int noPlayers = scanner.nextInt(), noTeams = scanner.nextInt();

        Graph g = new Graph(noTeams * noPlayers, noPlayers * (noTeams-1)+1);
        for (int t1 = 0; t1 < noTeams; t1++) {
            for (int t2 = t1+1; t2 < noTeams; t2++) {
                for (int i = 0; i < noPlayers; i++) {
                    for (int j = 0; j < noPlayers; j++) {
                        int node1 = t1*noPlayers + i;
                        int node2 = t2*noPlayers + j;
                        //System.out.println(node1 + " " + node2);
                        g.addEdge(node1, node2);
                    }
                }
            }
        }

        g.colorEdges();
        //showGraph(g);

        TreeMap<Integer, List<String>> rounds = new TreeMap<>();
        int maxRound = 0;
        for (Graph.Edge edge : g.getEdges()) {
            int x = edge.getA().getIndex(), y = edge.getB().getIndex();
            int t1 = x / noPlayers, p1 = x % noPlayers;
            int t2 = y / noPlayers, p2 = y % noPlayers;
            String s = String.format("%c%d-%c%d", 'A' + t1, p1 + 1, 'A' + t2, p2 + 1);
            int r = edge.color;
            if (r > maxRound) maxRound = r;
            if (!rounds.containsKey(r)) {
                rounds.put(r, new ArrayList<>());
            }
            rounds.get(r).add(s);
        }
        for (int r = 1; r <= maxRound; r++) {
            boolean first = true;
            for (String s : rounds.get(r)) {
                if (!first) System.out.print(" ");
                System.out.print(s);
                first = false;
            }
            System.out.println();
        }


    }

    private static void showGraph(Graph g) {
        int maxDegree = 0, maxColor = 0;
        for (Graph.Node node : g.getNodes()) {
            System.out.println(node.getIndex() + ":");
            for (Graph.Edge edge : node.getEdges()) {
                int destNode = edge.getA().getIndex() + edge.getB().getIndex() - node.getIndex();
                int color = edge.getColor();
                maxColor = Math.max(color, maxColor);
                System.out.println("  -> " + destNode + " : " + color);
            }
            maxDegree = Math.max(maxDegree, node.getEdges().size());

            System.out.println();
        }
        System.out.println("maxDegree = " + maxDegree + ", maxColor = " + maxColor);
    }
}
