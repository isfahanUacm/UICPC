/*
 * Solution for NCPC 2013 problem "Time bomb" by Jaap Eldering
 * Note: this source requires a C++11 compiler for initializer lists.
 */

#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<vector<string> > digits = {
	{"***",
	 "* *",
	 "* *",
	 "* *",
	 "***"},
	{"  *",
	 "  *",
	 "  *",
	 "  *",
	 "  *"},
	{"***",
	 "  *",
	 "***",
	 "*  ",
	 "***"},
	{"***",
	 "  *",
	 "***",
	 "  *",
	 "***"},
	{"* *",
	 "* *",
	 "***",
	 "  *",
	 "  *"},
	{"***",
	 "*  ",
	 "***",
	 "  *",
	 "***"},
	{"***",
	 "*  ",
	 "***",
	 "* *",
	 "***"},
	{"***",
	 "  *",
	 "  *",
	 "  *",
	 "  *"},
	{"***",
	 "* *",
	 "***",
	 "* *",
	 "***"},
	{"***",
	 "* *",
	 "***",
	 "  *",
	 "***"}
};

vector<string> code(5);

int match_digit(int ofs, int d)
{
	for(int l=0; l<5; l++)
		if ( code[l].substr(ofs,3)!=digits[d][l] ) return 0;

	return 1;
}

int main()
{
	for(int i=0; i<5; i++) getline(cin,code[i]);

	long long val = 0;
	int n = (code[0].length()+1)/4;

	for(int i=0; i<n; i++) {
		val *= 10;
		int d;
		for(d=0; d<10; d++) if ( match_digit(4*i,d) ) { val += d; break; }
		if ( d>=10 ) goto boom;
	}

	if ( val%6!=0 ) goto boom;

	cout << "BEER!!\n";
	return 0;

  boom:
	cout << "BOOM!!\n";
	return 0;
}
