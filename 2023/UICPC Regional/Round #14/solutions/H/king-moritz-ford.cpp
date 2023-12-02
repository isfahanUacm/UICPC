// @EXPECTED_RESULTS@: CORRECT
#include <iostream>
#include <climits>
#include <vector>
#include <algorithm>
#include <queue>
#include <utility>

using namespace std;

typedef pair<int,int> pii;
struct Arc{ int cap; int target; Arc() : cap(0), target(0){} };
vector< bool > visited;
vector< int > parent;
vector< vector<Arc> > graph;
int rows, cols, cas_y, cas_x;
pii off[] = {pii(-1,0),pii(0,-1),pii(1,0),pii(0,1)};

inline unsigned int MAP(int y,int x,bool z){ return ((y) * cols + (x) + ((z) ? rows * cols : 0 ));  }

void pushNode( int node, int cap, int par, queue<pii>& que ){
	visited[node] = true;
	parent[node] = par;
	que.push( pii( node, cap ) );
}

int bfs(){
	queue<pii> que;
	//init by pushing all outer vertices
	for( size_t i = 1; i+1 < rows; ++i ){
		pushNode(MAP(i,0,false),INT_MAX,-1,que);
		pushNode(MAP(i,cols-1,false),INT_MAX,-1,que);
	}
	for( size_t i = 0; i < cols; ++i ){
		pushNode(MAP(0,i,false),INT_MAX,-1,que);
		pushNode(MAP(rows-1,i,false),INT_MAX,-1,que);
	}

	int target = MAP( cas_y, cas_x, true );
	while(!que.empty() && que.front().first != target ){
		int cur = que.front().first, min_cap = que.front().second; que.pop();
		for( auto arc : graph[cur] ){
			if( !visited[arc.target] && arc.cap )
				pushNode(arc.target, std::min(arc.cap,min_cap), cur, que );
		}
	}
	for( size_t i = 0; i < visited.size(); ++i ) visited[i] = false;
	if( not que.empty() ){ //reached target
		return que.front().second;
	}
	return 0;
}

int getArc( int i, int j ){
	for( size_t k = 0; k < graph[i].size(); ++k )
		if( graph[i][k].target == j )
			return k;
	return -1;
}

void reduce( int flow ){
	int node = MAP( cas_y, cas_x, true );
	while( parent[node] >= 0 ){
		int arc_id = getArc(parent[node],node), rev_arc_id = getArc(node,parent[node]);
		graph[parent[node]][arc_id].cap -= flow;
		graph[node][rev_arc_id].cap += flow;
		node = parent[node];
	}
}

void solve(){
	int flow = 0, min_cap;
	do{
		min_cap = bfs();
		if( min_cap ){
			flow += min_cap;
			reduce( min_cap );
		}
	} while( min_cap );
	std::cout << flow << std::endl;
}

int main( int argc, char ** args ){
	while( cin >> rows >> cols ){
		graph.resize( 2 * rows * cols + 1 );
		visited.resize( 2 * rows * cols );
		parent.resize( 2 * rows * cols );
		Arc arc, infty_arc, zero_arc;
		for( int row = 0; row < rows; ++row ){
			for( int col = 0; col < cols; ++col ){
				cin >> arc.cap;
				int node = MAP( row, col, false ); arc.target = MAP( row, col, true );
				graph[node].push_back( arc );	//connect in and out node of (row,col)
				swap( arc.target, node );
				arc.cap = 0;
				graph[node].push_back(arc);
			}
		}
		infty_arc.cap = INT_MAX;
		zero_arc.cap = 0;
		for( int row = 0; row < rows; ++row ){ for( int col = 0; col < cols; ++col ){
			for( int o = 0; o < 4; ++o ){
				if( (row + off[o].first >= 0) && (row + off[o].first < rows) && (col + off[o].second >= 0) && (col+off[o].second < cols) ){
					int out_node = MAP( row, col, true ), in_node = MAP( row + off[o].first, col + off[o].second, false );
					zero_arc.target = out_node;
					infty_arc.target = in_node;
					graph[out_node].push_back( infty_arc );
					graph[in_node].push_back( zero_arc );
				}
			}
		} }
		cin >> cas_y >> cas_x;
		solve();
	}
	return 0;
}
