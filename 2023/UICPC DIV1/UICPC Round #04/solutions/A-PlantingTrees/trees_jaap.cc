/*
 * Solution for NCPC 2013 problem "Trees" by Jaap Eldering
 * Complexity: O(n log(n))
 */

#include <cstdio>
#include <vector>
#include <functional>
#include <algorithm>

using namespace std;

int main()
{
	int n, res = 0;

	scanf("%d\n",&n);
	vector<int> t(n);
	for(int i=0; i<n; i++) scanf("%d",&t[i]);

	sort(t.begin(),t.end(),greater<int>());

	for(int i=0; i<n; i++) if ( i+2+t[i]>res ) res = i+2+t[i];

	printf("%d\n",res);
	return 0;
}
