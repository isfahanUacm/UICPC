//Solution by Miroslav Baláž
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;
#define REP(i,n) for(int i=0;i<(int)(n);++i)
bool sort_by_size(const vector<int> &a, const vector<int> &b) {
  return a.size()<b.size();
}
int main() {
  int n,k;

  cin>>n>>k;
  vector<int> p(n);
  REP(i,n) cin >> p[i];

  // Compute cycles
  vector<vector<int> > cycles;
  vector<int> seen(n);
  REP(i,n) if(!seen[i]){
    int j=i;
    vector<int> cycle;
    while(!seen[j]) {
      seen[j]=1;
      cycle.push_back(j);
      j=p[j]-1;

    }
    cycles.push_back(cycle);
  } 
  vector<int> final(n);

  // Reconstruct permutation
  int ptr=0;

  sort(cycles.begin(), cycles.end(), ptr_fun(sort_by_size));

  while(ptr<(int)cycles.size()) {
    int size = cycles[ptr].size();
    // If k and size are not coprime, we must merge multiple cycles to one bigger which will split after k steps to these cycles
    int needed=size;
    int k2=k;
    // We need to solve equation needed/gcd(needed, k)=size
    while(k2>1 && __gcd(size,k2)!=1) {
      needed*=__gcd(size,k2);
      k2/=__gcd(size, k2);
    }

    // if (size == 1)
    // {
    //     int e = ptr;
    //     while (e < cycles.size() && cycles[e].size() == 1) e++;
    //     needed = __gcd(k, e);
    // }


    if(ptr+needed/size>n || (int)cycles[ptr+needed/size-1].size() != size) {
      cout << "Impossible" << endl;
      return 0;
    }
    vector<int> original_cycle(needed);    
    REP(c, needed/size) {
      const vector<int> &cycle=cycles[ptr+c];

      int power = k/(needed/size)%size; // this cycle will be used power times, 
      //   Well let g be gcd(needed,k) we can write it as (k/g/(needed/g))*size since  needed/gcd(needed,k)=size, 
      // so we can simplify to power= ((k/g)/(size))*size = k/g 
      vector<int> rewound_cycle(cycle);
      for(int j = 0,cnt = 0; cnt < size; ++cnt,j+=power) {  // power is coprime to size?
        rewound_cycle[j%size] = cycle[cnt];
      }

      REP(j,size) original_cycle[j*needed/size+c]=rewound_cycle[j];
    }
    REP(j,original_cycle.size()) final[original_cycle[j]]=original_cycle[(j+1)%original_cycle.size()];
    ptr+=needed/size;
  }

  bool wrong = false;
  // REP(i,n) if (final[i] == i)
  //     wrong = true;

  if (wrong)
      cout << "Impossible" << endl;
  else
  {
      REP(i,n) {
        if(i) cout<<" ";
        cout<<final[i]+1;
      }
      cout<<endl;
  }
}
