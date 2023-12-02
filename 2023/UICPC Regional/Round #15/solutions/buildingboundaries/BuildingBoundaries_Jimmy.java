import java.util.Scanner;

public class BuildingBoundaries_Jimmy {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int[][] perm = new int[][] {
                {0, 1, 2},
                {0, 2, 1},
                {1, 0, 2},
                {1, 2, 0},
                {2, 0, 1},
                {2, 1, 0}
        };
        for (int i = 0; i < n; i++) {
            int[][] coords  = new int [2][3];
            for (int j = 0; j < 3; j++) {
                coords[0][j] = scanner.nextInt();
                coords[1][j] = scanner.nextInt();
            }
            long best = Long.MAX_VALUE;
            for (int p = 0; p < 6; p++) {
                for (int order = 0; order < 8; order++) {
                    int x1 = coords[order & 1][perm[p][0]];
                    int y1 = coords[1 - (order & 1)][perm[p][0]];
                    int x2 = coords[(order/2) & 1][perm[p][1]];
                    int y2 = coords[1 - ((order/2) & 1)][perm[p][1]];
                    int x3 = coords[(order/4) & 1][perm[p][2]];
                    int y3 = coords[1 - ((order/4) & 1)][perm[p][2]];
                    best = Math.min(best, solve1(x1, y1, x2, y2, x3, y3));
                    best = Math.min(best, solve2(x1, y1, x2, y2, x3, y3));
                }
            }
            System.out.println(best);
        }
    }

    private static long solve1(long x1, long y1, int x2, int y2, int x3, int y3) {
        // All in one line, y = 0
        long width = x1 + x2 + x3;
        long height = Math.max(y1, Math.max(y2, y3));
        return width * height;
    }

    private static long solve2(long x1, long y1, int x2, int y2, int x3, int y3) {
        // One of the left, the other two on top of each other
        long width = x1 + Math.max(x2, x3);
        long height = Math.max(y1, y2+y3);
        return width * height;
    }
}
