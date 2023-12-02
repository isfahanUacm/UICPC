// @EXPECTED_RESULTS@: CORRECT
#include<cstdio>
#include<vector>
using namespace std;

#define INF 2000000000
#define MAX 310
#define MAX_N (MAX*MAX*2)
#define MAX_C 101000

struct edge {
  int dest,capacity,reversed_index;
  edge(int _dest,int _capacity,int _reversed_index) { 
    dest=_dest; capacity=_capacity; reversed_index=_reversed_index;
  }
};

vector<edge> s[MAX_N];
int b[MAX_N],next_b;

void add_edge(int x,int y,int c) {
  s[x].push_back(edge(y,c,s[y].size()));
  s[y].push_back(edge(x,0,s[x].size()-1));
}

int current_t,current_c;

bool dfs(int x) {
  b[x]=next_b;
  for (int i=0; i<s[x].size(); i++)
    if (s[x][i].capacity>=current_c && (s[x][i].dest==current_t || 
        (b[s[x][i].dest]<next_b && dfs(s[x][i].dest)))) {
      s[x][i].capacity-=current_c;
      s[s[x][i].dest][s[x][i].reversed_index].capacity+=current_c;
      return true;
    }
  return false;
}

int max_flow(int s,int t) {
  int ans=0;
  current_t=t;
  current_c=MAX_C;
  while (current_c) {
    next_b++;
    while (dfs(s)) {
      next_b++;
      ans+=current_c;
    }
    current_c>>=1;
  }
  return ans;
}

int R,C,t[MAX][MAX],r,c;
main(){
	scanf("%d %d",&R,&C);
	for(int i=0;i<R;i++)for(int j=0;j<C;j++)scanf("%d",&t[i][j]);
	scanf("%d %d",&r,&c);
	int source=r*C+c,sink=2*R*C;
	for(int i=0;i<R;i++)for(int j=0;j<C;j++){
		add_edge(i*C+j,R*C+i*C+j,t[i][j]);
		if(i)add_edge(R*C+i*C+j,(i-1)*C+j,MAX_C);
		if(j)add_edge(R*C+i*C+j,i*C+j-1,MAX_C);
		if(i+1<R)add_edge(R*C+i*C+j,(i+1)*C+j,MAX_C);
		if(j+1<C)add_edge(R*C+i*C+j,i*C+j+1,MAX_C);
		if(!i||!j||i+1==R||j+1==C)add_edge(R*C+i*C+j,sink,MAX_C);
	}
	printf("%d\n",max_flow(source,sink));
}

