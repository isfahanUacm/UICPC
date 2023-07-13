import java.util.*;

public class rainbow_db {
  public static void main(String[] args) {
    new rainbow_db().run();
  }
  
  void run() {
    Scanner in = new Scanner(System.in);

    int n = in.nextInt();
    int m = in.nextInt();
    
    List<Integer>[] adj_u = new List[n << 7];
    List<Integer>[] adj_w = new List[n << 7];
    for(int i=0;i<(n << 7);i++){
      adj_u[i] = new ArrayList<>();
      adj_w[i] = new ArrayList<>();
    }
    long[] dist = new long[n << 7];
    for(int i=0;i<(n << 7);i++)
      dist[i] = -1;

    for(int i=0;i<m;i++){
	int u = in.nextInt()-1;
    	int v = in.nextInt()-1;
	int d = in.nextInt();
	String c = in.next();
	int colour = "ROYGBIV".indexOf(c);
	
        for(int j=0;j<(1 << 7);j++){
            adj_u[(u << 7) + j].add((v << 7) + (j | (1 << colour)));
	    adj_w[(u << 7) + j].add(d);
            adj_u[(v << 7) + j].add((u << 7) + (j | (1 << colour)));
	    adj_w[(v << 7) + j].add(d);
        }
    }

    PriorityQueue<Long> pq = new PriorityQueue<>();
    pq.add((long)0);
    dist[0] = 0;

    while(!pq.isEmpty()) {
      long cur = pq.remove();
      int v = (int) cur;
      long d = cur >>> 32;

      if(dist[v] < d) continue;
      
      for(int i=0;i<adj_u[v].size();i++){
	int u = adj_u[v].get(i);
        long new_d = d+adj_w[v].get(i);
	if(dist[u] == -1 || dist[u] > new_d){
	  dist[u] = new_d;
	  pq.add((new_d << 32) + (long)u);
	}
      }
    }

    System.out.println(dist[(1 << 7)-1]);
  }
}
