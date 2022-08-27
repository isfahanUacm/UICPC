import java.util.Scanner;

class MST {

    static int find(int i, int[] p) {
        while (p[i] != i)
            i = p[i];
        return i;
    }

    static void union(int i, int j, int[] p) {
        int a = find(i, p);
        int b = find(j, p);
        p[a] = b;
    }

    static void kruskalMST(int cost[][], int n) {
        int[] parent = new int[n + 1];
        for (int i = 0; i < n; i++)
            parent[i] = i;

        int edgeNum = 0;
        while (edgeNum < n - 1) {
            int min = Integer.MAX_VALUE, a = -1, b = -1;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= n; j++) {
                    if (find(i, parent) != find(j, parent) && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }

            union(a, b, parent);
            System.out.println(a + " " + b);
            edgeNum += 1;

        }
    }

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();
        int[][] matrix = new int[n + 1][n + 1];
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (i == 0) {
                    matrix[i][j] = 0;
                } else
                    matrix[i][j] = sc.nextInt();
            }
        }

        kruskalMST(matrix, n);
    }
}