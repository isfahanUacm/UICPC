import java.io.*;
import java.util.*;

/**
 * Build a graph and then run Dijkstra's on it. We have one node for each
 * (road segment, number of lefts used, number of lane changes used) triple.
 *
 * @author Finn Lidbetter
 */

public class safest_finn {
  static int N_MAX = 15;
  static int M_MAX = 15;
  static int LANES_MAX = 3;
  static int CHANGES_MAX = 4;
  static int LEFTS_MAX = 4;

  public static void main(String[] args) throws IOException {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    
    String[] s = br.readLine().split(" ");
    int n = Integer.parseInt(s[0]);
    int m = Integer.parseInt(s[1]);
    int k = Integer.parseInt(s[2]);
    N_MAX = n;
    M_MAX = m;
    LANES_MAX = k;
    int d = Integer.parseInt(br.readLine());
    Node[] nodes = new Node[d*LANES_MAX*(CHANGES_MAX+1)*(LEFTS_MAX+1)];
    int MAX_ID = LANES_MAX * N_MAX * N_MAX * M_MAX * M_MAX * (CHANGES_MAX+1) * (LEFTS_MAX+1);
    int[] idToIndex = new int[MAX_ID];
    int index = 0;
    for (int r0=0; r0<N_MAX; r0++) {
      for (int c0=0; c0<M_MAX; c0++) {
        for (int r1=r0-1; r1<=r0+1; r1++) {
          if (r1<0 || r1>=N_MAX)
            continue;
          for (int c1=c0-1; c1<=c0+1; c1++) {
            if (c1<0 || c1>=M_MAX)
              continue;
            if ((r0!=r1 && c0!=c1) || (r0==r1 && c0==c1))
              continue;
            for (int lane=0; lane<k; lane++) {
              for (int nChanges=0; nChanges<=CHANGES_MAX; nChanges++) {
                for (int nLefts=0; nLefts<=LEFTS_MAX; nLefts++) {
                  int id = getId(lane, r0, c0, r1, c1, nChanges, nLefts);
                  nodes[index] = new Node(id);
                  idToIndex[id] = index;
                  index++;
                }
              }
            }
          }
        }
      }
    }
    int[][][][] times = new int[N_MAX][M_MAX][N_MAX][M_MAX];
    String[] lines = new String[d];
    // On the first pass, just read the times.
    for (int i=0; i<d; i++) {
      String line = br.readLine();
      lines[i] = line;
      s = line.split(" ");
      int r0 = Integer.parseInt(s[0]);
      int c0 = Integer.parseInt(s[1]);
      int r1 = Integer.parseInt(s[2]);
      int c1 = Integer.parseInt(s[3]);
      int t = Integer.parseInt(s[4]);
      times[r0][c0][r1][c1] = t/2;
    }
    for (int i=0; i<d; i++) {
      String line = lines[i];
      s = line.split(" ");
      int r0 = Integer.parseInt(s[0]);
      int c0 = Integer.parseInt(s[1]);
      int r1 = Integer.parseInt(s[2]);
      int c1 = Integer.parseInt(s[3]);
      int t = Integer.parseInt(s[4]);
      String[] laneStrings = new String[k];
      for (int j=0; j<k; j++) {
        laneStrings[j] = s[5+j];
      }
      for (int currLane=0; currLane<k; currLane++) {
        int[][] targetLanes = getTargetLanes(laneStrings, currLane);
        int nr0 = r1;
        int nc0 = c1;
        int[][] next = getNextRowCols(r0, c0, r1, c1, laneStrings[currLane]);
        for (int dirIndex=0; dirIndex<laneStrings[currLane].length(); dirIndex++) {
          int nr1 = next[dirIndex][0];
          int nc1 = next[dirIndex][1];
          char dir = laneStrings[currLane].charAt(dirIndex);
          for (int nextLane: targetLanes[dirIndex]) {
            if (nextLane==-1)
              break;
            for (int nChanges=0; nChanges<=CHANGES_MAX; nChanges++) {
              for (int nLefts=0; nLefts<=LEFTS_MAX; nLefts++) {
                int id1 = getId(currLane, r0, c0, r1, c1, nChanges, nLefts);
                if (nLefts==LEFTS_MAX && dir=='L')
                  continue;
                int id2 = getId(nextLane, nr0, nc0, nr1, nc1, nChanges, nLefts + ((dir=='L') ? 1 : 0));
                int travelTime = times[r0][c0][r1][c1] + times[nr0][nc0][nr1][nc1];
                Edge e = new Edge(idToIndex[id1], idToIndex[id2], travelTime);
                nodes[e.u].adj.add(e);
              }
            }
          }
        }
      }
      for (int currLane=0; currLane<k; currLane++) {
        for (int nChanges=0; nChanges<CHANGES_MAX; nChanges++) {
          for (int nLefts=0; nLefts<=LEFTS_MAX; nLefts++) {
            int id1 = getId(currLane, r0, c0, r1, c1, nChanges, nLefts);
            int index1 = idToIndex[id1];
            if (currLane>0) {
              int id2 = getId(currLane-1, r0, c0, r1, c1, nChanges+1, nLefts);
              Edge e = new Edge(index1, idToIndex[id2], 0);
              nodes[e.u].adj.add(e);
            }
            if (currLane<k-1) {
              int id2 = getId(currLane+1, r0, c0, r1, c1, nChanges+1, nLefts);
              //Edge e = new Edge(index1, idToIndex.get(id2), 0);
              Edge e = new Edge(index1, idToIndex[id2], 0);
              nodes[e.u].adj.add(e);
            }
          }
        }
      }
    }
    int p = Integer.parseInt(br.readLine());
    for (int i=0; i<p; i++) {
      s = br.readLine().split(" ");
      int rs0 = Integer.parseInt(s[0]);
      int cs0 = Integer.parseInt(s[1]);
      int rs1 = Integer.parseInt(s[2]);
      int cs1 = Integer.parseInt(s[3]);
      int rd0 = Integer.parseInt(s[4]);
      int cd0 = Integer.parseInt(s[5]);
      int rd1 = Integer.parseInt(s[6]);
      int cd1 = Integer.parseInt(s[7]);
      int allowedLefts = Integer.parseInt(s[8]);
      int allowedChanges = Integer.parseInt(s[9]);
      int startId = getId(k-1, rs0, cs0, rs1, cs1, 0, 0);
      int startIndex = idToIndex[startId];
      int[] shortest = dijkstra(nodes, startIndex);
      int best = -1;
      for (int nLefts=0; nLefts<=allowedLefts; nLefts++) {
        for (int nChanges=0; nChanges<=allowedChanges; nChanges++) {
          int endId = getId(k-1, rd0, cd0, rd1, cd1, nChanges, nLefts);
          int endIndex = idToIndex[endId];
          if (shortest[endIndex]!=-1 && (best==-1 || shortest[endIndex]<best)) {
            best = shortest[endIndex];
          }
        }
      }
      System.out.println(best);
    }
  }
  static int[][] getTargetLanes(String[] laneStrings, int currLane) {
    // targetLanes[i] is the list of reachable lanes for ith character of laneStrings[currLane].
    int nLanes = laneStrings.length;
    int[][] targetLanes = new int[laneStrings[currLane].length()][nLanes];
    for (int dirIndex=0; dirIndex<laneStrings[currLane].length(); dirIndex++) {
      char dir = laneStrings[currLane].charAt(dirIndex);
      int count = count(laneStrings, dir);
      int first = first(laneStrings, dir);
      int last = last(laneStrings, dir);
      Arrays.fill(targetLanes[dirIndex], -1);
      if (dir=='R') {
        if (currLane==first) {
          for (int i=0; i<=first; i++) {
            targetLanes[dirIndex][i] = i;
          }
        } else {
          targetLanes[dirIndex][0] = currLane;
        }
      } else {
        if (currLane==last) {
          int doneLanes = last-first;
          for (int i=doneLanes; i<nLanes; i++) {
            targetLanes[dirIndex][i-doneLanes] = i;
          }
        } else {
          int doneLanes = currLane - first;
          targetLanes[dirIndex][0] = doneLanes;
        }
      }
    }
    return targetLanes;
  }
  static int count(String[] laneStrings, char c) {
    int count=0;
    for (int i=0; i<laneStrings.length; i++) {
      if (laneStrings[i].indexOf(c)>=0) {
        count++;
      }
    }
    return count;
  }
  static int first(String[] laneStrings, char c) {
    for (int i=0; i<laneStrings.length; i++) {
      if (laneStrings[i].indexOf(c)>=0)
        return i;
    }
    return -1;
  }
  static int last(String[] laneStrings, char c) {
    for (int i=laneStrings.length-1; i>=0; i--) {
      if (laneStrings[i].indexOf(c)>=0)
        return i;
    }
    return -1;
  }
  static int[][] getNextRowCols(int r0, int c0, int r1, int c1, String dirs) {
    int[][] next = new int[dirs.length()][2];
    int dr = r1-r0;
    int dc = c1-c0;
    for (int i=0; i<dirs.length(); i++) {
      if (dirs.charAt(i)=='L') {
        next[i][0] = r1 - dc;
        next[i][1] = c1 + dr;
      } else if (dirs.charAt(i)=='S') {
        next[i][0] = r1+dr;
        next[i][1] = c1+dc;
      } else {
        next[i][0] = r1 + dc;
        next[i][1] = c1 - dr;
      }
    }
    return next;
  }
  static int getId(int currLane, int r0, int c0, int r1, int c1, int nChanges, int nLefts) {
    int id = 0;
    id += currLane;
    id *= N_MAX;
    id += r0;
    id *= M_MAX;
    id += c0;
    id *= N_MAX;
    id += r1;
    id *= M_MAX;
    id += c1;
    id *= (CHANGES_MAX+1);
    id += nChanges;
    id *= (LEFTS_MAX+1);
    id += nLefts;
    return id;
  }
  static int[] dijkstra(Node[] nodes, int start) {
    int n = nodes.length;
    boolean[] visited = new boolean[n];
    int[] min = new int[n];
    Arrays.fill(min, -1);
    Queue<QNode> q = new PriorityQueue<>();
    q.add(new QNode(start, 0)); 
    min[start] = 0;
    while (!q.isEmpty()) {
      QNode qNode = q.remove();
      int u = qNode.index;
      if (visited[u]) 
        continue;
      visited[u] = true;
      for (Edge e: nodes[u].adj) {
        int newCost = min[u] + e.w;
        if (min[e.v]==-1 || newCost < min[e.v]) {
          min[e.v] = newCost;
          q.add(new QNode(e.v, newCost));
        } 
      } 
    }
    return min; 
  }
  static class QNode implements Comparable<QNode> {
    int index;
    double cost;
    public QNode(int index, double cost) {
      this.index = index; 
      this.cost = cost; 
    }
    @Override public int compareTo(QNode other) {
      return Double.compare(cost, other.cost); 
    } 
  }
}
class Node {
  int id;
  ArrayList<Edge> adj;
  public Node(int idd) {
    id = idd;
    adj = new ArrayList<>();
  }
}
class Edge {
  // u and v are INDICES of nodes. Not ids.
  int u,v,w;
  public Edge(int uu, int vv, int ww) {
    u = uu;
    v = vv;
    w = ww;
  }
}
