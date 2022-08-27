#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <cmath>
using namespace std;
typedef struct{  // struct to keep count of each element in molecule
  string element;
  int count;
}ecp;
typedef vector<ecp> molecule; // define a molecule
typedef set<string>::iterator elemit_t; // I will need this
// Function to count the number of atomes of element in molecule
int countup(const molecule &m,const string &name)
{ int total=0;
  for(molecule::const_iterator i = m.begin();i != m.end(); i++)
    if(i->element == name)
      total += i->count;
  return total;
}
// find the minimum non-zero fractional part and divide by it--recursively
void makeints(vector<double> &v)
{ double min;  
  double junk;
  vector<double>::iterator i;
  set<double> fracpart;
  for(i=v.begin();i!=v.end();i++)
    if((min=modf(*i,&junk))>0.000001)
      fracpart.insert(min);
  if(fracpart.size()>0) {
    for(i=v.begin();i!=v.end();i++)
      *i /= *(fracpart.begin());
    makeints(v);  // keep doing it until no fractions left
  }
}
// printmatrix for debugging
void printmatrix(string msg,double **mat,int nr,int nc)
{
#ifdef DEBUG
  int r,c;
  cout<<msg<<endl;
  for(r=0;r<nr;r++) {
    for(c=0;c<nc;c++)
      cout<<setw(8)<<mat[r][c];
    cout << endl;
  }
  cout << endl;
#endif
}
// My main, man!
int main()
{ vector<molecule> left,right;
  set<string> elements;
  vector<double> ans;
  molecule tm;
  ecp tmp;
  elemit_t ei;
  int nelem,nmolec,r,c,diag,sign,np;;
  double **mat,*tmparray,tmpf;;
  while((cin>>sign)&&sign) { // read in all of the molecules
    tm.clear();
    cin>>np;
    while(np-->0) {
      cin>>tmp.element>>tmp.count;
      elements.insert(tmp.element); // add element to set of elements
      tm.push_back(tmp);
    }
    if(sign>0)
      left.push_back(tm); // add to left or right, depending on sign
    else
      right.push_back(tm);
  }
  nelem = elements.size(); // get total number of elements found
  nmolec = left.size() + right.size(); // get total number of molecules
  // Build a matrix and apply Gauss-Jordan
  mat = new double*[nelem];  // use a plain old array of pointers to arrays
  for(r=0;r<nelem;r++) mat[r] = new double[nmolec];
  // fill in matrix -- for each element, find all occurrences
  for(r=0,ei=elements.begin();ei!= elements.end();ei++,r++) {
    for(c = 0;c<left.size();c++)
      mat[r][c] = countup(left[c],*ei);
    for(c = 0;c<right.size();c++)
      mat[r][c+left.size()] = -countup(right[c],*ei);
    // last column is special - needs to be negated
    mat[r][right.size()+left.size()-1] = -mat[r][right.size()+left.size()-1];
  }
  printmatrix("original matrix",mat,nelem,nmolec);
  if(nelem<(nmolec-1)) { 
    cout<<"degenerate case"<<endl;
    exit(2);
  }
  // start Gauss-Jordan
  for(diag=0;diag<nmolec-1;diag++)
    {
      // find first non-zero element in column diag, starting at row diag
      for(r=diag;r<nelem && mat[r][diag]==0;r++);
      if((r < nelem)&&(r != diag)) { // if it is not in row diag, swap rows
	tmparray=mat[r];
	mat[r]=mat[diag];
	mat[diag]=tmparray;
	printmatrix("After swap",mat,nelem,nmolec);
      }
      if(r == nelem) { // if there is no such element, exit
	printmatrix("no solution",mat,nelem,nmolec);
	exit(3);
      }
      tmpf = mat[diag][diag]; // reduce current row (mat[diag])
      for(c=diag;c<nmolec;mat[diag][c++]/=tmpf);
      printmatrix("After reduce",mat,nelem,nmolec);
      for(r=0;r<nelem;r++) { // reduce this column to zero in remaining rows
	if(r!=diag) {
	  if(mat[r][diag] != 0.0) {
	    tmpf=mat[r][diag];
	    for(c=diag;c<nmolec;c++) mat[r][c] -= tmpf*mat[diag][c];
	  }
	}
      }
      printmatrix("After reduce rest",mat,nelem,nmolec);
    }
  while(nelem>(nmolec-1)) nelem--;// delete extra rows (will be all zero now).
  for(r=0;r<nelem;ans.push_back(mat[r++][nmolec-1])); // copy last col to vector
  while(ans.size()<nmolec) ans.push_back(1.0); // Add a 1 to the end
  makeints(ans); // get rid of fractional parts
  for(r=0;r<ans.size();cout<<ans[r++]<<" "); // print results.
  cout <<endl;
  return 0;
}
