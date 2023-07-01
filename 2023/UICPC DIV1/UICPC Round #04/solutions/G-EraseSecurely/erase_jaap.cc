/*
 * Solution for NCPC 2013 problem "Data destruction" by Jaap Eldering
 * Complexity: linear
 */

#include <iostream>

using namespace std;

int main()
{
	int n;
	string orig, del;
	cin >> n >> orig >> del;

	if ( orig.length()!=del.length() ) return 1;

	size_t i;
	for(i=0; i<orig.length(); i++)
		if ( ((orig[i]-'0')^(n%2))!=(del[i]-'0') ) break;

	cout << "Deletion " << ( i>=orig.length() ? "succeeded" : "failed" ) << endl;

	return 0;
}
