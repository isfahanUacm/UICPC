// @EXPECTED_RESULTS@: CORRECT

#include <cstdio>
#include <cstring>
#include <cassert>

#define MAX 300000

using namespace std;

struct state;

struct node{
	char* edge[26];
	node* child[26];
	bool word;
	int tc;
	void insert(char *w);
	bool search(char *w);
};

struct state{
	char* edge;
	char* pos;
	node *g;
};

int scores[] = {0, 0, 0, 1, 1, 2, 3, 5, 11, 11, 11, 11, 11, 11, 11, 11, 11};
node nodes[MAX*2];
int nodesN = 0;
char buffer[MAX][20];
char field[5][5];
int vis[5][5];
int TC;

char best[100];
int bestL;
int sum;
int count;

int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

int pre(char *a, char *b){
	int c=0;
	for(; *a != '\0' && *b != '\0' && *a == *b; ++a, ++b, ++c)
		;
	return c;
}

void node::insert(char *w){
	if(!*w){
		word = true;
		return;
	}
	int sw = *w-'A';
	if(!child[sw]){
		edge[sw] = w+1;
		child[sw] = &nodes[nodesN++];
		child[sw]->word = true;
		*w = '\0';
	}else{
		int p = pre(w+1, edge[sw]);
		if(edge[sw][p]){
			int wp = edge[sw][p]-'A'; 
			nodes[nodesN].child[wp] = child[sw];
			nodes[nodesN].edge[wp] = &edge[sw][p+1];
			child[sw] = &nodes[nodesN++];
			edge[sw][p] = '\0';
		}
		child[sw]->insert(w+p+1);
	}
}

bool iterSearch(state *s, char w, char *f, state *r, int l){
	if(*s->pos){
		if(*s->pos != w){
			return false;
		}
		r->edge = s->edge;
		r->pos = s->pos+1;
		r->g = s->g;
	}else{
		int sw = w - 'A';
		if(s->g->child[sw] == NULL){
			return false;
		}
		r->edge = s->g->edge[sw];
		r->pos = r->edge;
		r->g = s->g->child[sw];
	}
	if(!*r->pos && r->g->word && r->g->tc != TC){
		r->g->tc = TC;
		++count;
		sum += scores[l];
		if(l > bestL || (l == bestL && strcmp(f, best) < 0)){
			bestL = l;
			strcpy(best, f);
		}
	}
	return true;
}

void rek(int x, int y, state *s, char *f, int si){
	if(x<0 || y <0 || x>=4 || y>=4 || vis[y][x])
		return;
	vis[y][x] = true;
	state n;
	
	char c = field[y][x];
	f[si] = c;
	for(int i=0; i<8; ++i){
		f[si+1] = '\0';
		if(iterSearch(s, c, f, &n, si+1)){
			rek(x+dx[i], y+dy[i], &n, f, si+1);
		}
	}
	vis[y][x] = false;
}

int main(){
	node root = nodes[nodesN++];
	int n;
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		scanf("%s", buffer[i]);
		root.insert(buffer[i]);
	}
	
	scanf("%d", &n);
	for(int i=0; i<n; ++i){
		TC = i+1;
		bestL = 0;
		best[0] = '\0';
		count = 0;
		sum = 0;
		for(int j=0; j<4; ++j){
			scanf("%s", field[j]);
		}
		char f[30];
		for(int j=0; j<4; ++j){
			for(int k=0; k<4; ++k){
				//state s = state{"", 0, &root};
				state s;
				s.pos = s.edge = "";
				s.g = &root;
				f[0] = '\0';
				rek(j, k, &s, f, 0);
			}
		}
		printf("%d %s %d\n", sum, best, count);
	}
}
