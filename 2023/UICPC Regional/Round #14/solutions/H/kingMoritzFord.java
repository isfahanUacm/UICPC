// @EXPECTED_RESULTS@: CORRECT
import java.util.*;

public class kingMoritzFord{
	static class Arc{
		public int cap;
		public int target;
	}
	static class pii{
		public int first;
		public int second;
		public pii( int _first, int _second ) { first = _first;  second = _second; }
	}
	public static boolean visited[];
	public static int parent[];
	public static int count[];
	public static Arc graph[][];
	public static int rows, cols, cas_y, cas_x;
	public static final int off_x[] = {0,-1,0,1};
	public static final int off_y[] = {-1,0,1,0};	
	public static LinkedList<pii> que;

	public static int MAP( int y, int x, boolean z){ return ((y) * cols + (x) + ((z) ? rows * cols : 0 ));  }

	public static void pushNode( int node, int cap, int par ){
		visited[node] = true;
		parent[node] = par;
		que.add( new pii( node, cap ) );
	}

	public static int bfs(){
		que.clear();
		for( int i = 0; i < (2*rows*cols); ++i ) visited[i] = false;
		//init by pushing all outer vertices
		for( int i = 1; i+1 < rows; ++i ){
			pushNode(MAP(i,0,false),20000000,-1);
			pushNode(MAP(i,cols-1,false),20000000,-1);
		}
		for( int i = 0; i < cols; ++i ){
			pushNode(MAP(0,i,false),20000000,-1);
			pushNode(MAP(rows-1,i,false),20000000,-1);
		}

		int target = MAP( cas_y, cas_x, true );
		while(que.size()!=0 && que.getFirst().first != target ){
			int cur = que.getFirst().first, min_cap = que.getFirst().second; que.remove();
			for( int i = 0; i < count[cur]; ++i ){
				Arc arc = graph[cur][i];
				if( !visited[arc.target] && (arc.cap > 0) ){
					int pc = (arc.cap < min_cap) ? arc.cap : min_cap;
					pushNode(arc.target, pc, cur );
				}
			}
		}
		if( que.size() != 0 ) //reached target
			return que.getFirst().second;
		return 0;
	}

	public static int getArc( int i, int j ){
		for( int k = 0; k < count[i]; ++k )
			if( graph[i][k].target == j )
				return k;
		return -1;
	}

	public static void reduce( int flow ){
		assert( flow > 0 );
		int node = MAP( cas_y, cas_x, true );
		while( parent[node] >= 0 ){
			//System.out.println( "Node: " + node + " Parent: " + parent[node] );
			int arc_id = getArc(parent[node],node), rev_arc_id = getArc(node,parent[node]);
			graph[parent[node]][arc_id].cap -= flow;
			graph[node][rev_arc_id].cap += flow;
			node = parent[node];
		}
	}

	public static void solve(){
		int flow = 0, min_cap;
		do{
			min_cap = bfs();
			if( min_cap > 0 ){
				flow += min_cap;
				reduce( min_cap );
			}
		} while( min_cap > 0 );
		System.out.println( flow );
	}

	public static void main( String args[] ){
		Scanner scanner = new Scanner( System.in );
		que = new LinkedList<pii>();
		rows = scanner.nextInt();
		cols = scanner.nextInt();
		count = new int[2 * rows * cols + 1 ];
		graph = new Arc[2 * rows * cols + 1 ][10];
		visited = new boolean[2 * rows * cols];
		parent = new int[ 2 * rows * cols ];
		Arc arc, infty_arc, zero_arc;
		for( int row = 0; row < rows; ++row ){
			for( int col = 0; col < cols; ++col ){
				int cap = scanner.nextInt(), node = MAP( row, col, false ), target = MAP( row, col, true );
				arc = new Arc();
				arc.target = target;
				arc.cap = cap;
				graph[node][count[node]++] = arc;
				arc = new Arc();
				arc.cap = 0;
				arc.target = node;
				graph[target][count[target]++] = arc;
			}
		}

		for( int row = 0; row < rows; ++row ){ for( int col = 0; col < cols; ++col ){
			for( int o = 0; o < 4; ++o ){
				if( (row + off_y[o] >= 0) && (row + off_y[o] < rows) && (col + off_x[o] >= 0) && (col+off_x[o] < cols) ){
					int out_node = MAP( row, col, true ), in_node = MAP( row + off_y[o], col + off_x[o], false );
					infty_arc = new Arc(); zero_arc = new Arc();
					infty_arc.cap = 20000000;
					zero_arc.cap = 0;
					zero_arc.target = out_node;
					infty_arc.target = in_node;
					graph[out_node][count[out_node]++] = infty_arc;
					graph[in_node][count[in_node]++] = zero_arc;
				}
			}
		} }
		cas_y = scanner.nextInt();
		cas_x = scanner.nextInt();
		solve();
	}
}
