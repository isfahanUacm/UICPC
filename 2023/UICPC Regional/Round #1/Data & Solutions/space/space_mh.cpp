/** Private space implementation using dynamic programming with memoization
    Author: Matias Holte
    Email: kjetimh@ulrik.uio.no
*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>

#define MAXROWS 12
using namespace std;

map<vector<int>,int> spacereq;
vector<int> limits;
vector<int>::iterator it;

/** get the minimum number of seats with current denoting the
    groups. Use memoization to avoid calculating the same config
    twice. Could be optimized by filling entire rows wherever possible
*/
int getnum(vector<int> current){
  /* result calculated before */
  if (spacereq.find(current)!=spacereq.end()){
    return spacereq[current];
  }
  int mn=limits[MAXROWS+1]; // +infinity
  /* loop through all group sizes, try to seat that group last, and
     see how many seats are needed */
  for (int i=0;i<current.size();i++){
    if (current[i]>0){
      current[i]--;
      /* seat all other groups, and return minimum */
      int tmp=getnum(current);
      if (tmp==limits[MAXROWS+1]) continue; /* full */
      current[i]++;
      /* find the first seat to place the last group (with i+1
	 members). Must be later than the i-th row */
      it = upper_bound(limits.begin()+i+1,limits.end(),tmp);
      if (*it-tmp>i+1){
	/* room on current row, add group at beginning */
	tmp=max(tmp,*(it-1));
	mn=min(mn,tmp+i+2);
      }
      else{
	/* place it on next row instead */
	mn=min(mn,*it+i+2);
      }
    }
  }
  /* save for later and return */
  spacereq[current]=mn;
  return mn;
}
int main(){
  /* initialize table of the last seat in each row (including ghost
     seats) */
  limits.resize(MAXROWS+2);
  limits[0]=0;
  for (int i=1;i<MAXROWS+2;i++){
    limits[i]=limits[i-1]+i+1;
  }
  /* read input on format: N [number of different group sizes]
     x_1, ..., x_n [number in each group] */
  int N;
  cin>>N;
  vector<int> nums(N,0);
  int totalpersons=0;
  /* base case for memoization */
  spacereq[nums]=0;
  for (int i=0;i<N;i++){
    cin>>nums[i];
    totalpersons+=nums[i]*(i+1);
  }
  if (totalpersons>limits[MAXROWS+1])
    cout<<"impossible"<<endl;
  else{
    /* find solution and translate it from num[seats] to num[rows] */
    it = upper_bound(limits.begin(),limits.end(),getnum(nums)-1);
    int totalrows = int(it-limits.begin());
    if (totalrows>MAXROWS)
      cout<<"impossible"<<endl;
    else
      cout<<totalrows<<endl;
  }
}
