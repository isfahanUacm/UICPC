#include<iostream>

using namespace std;

int main(){
   string s;
   cin >> s;
   bool B = false;
   for(int i = 1; i < (int)s.size(); i++)
      if(s[i] == 's' and s[i-1] == 's')
	 B = true;
   if(!B) cout << "no ";
   cout << "hiss" << endl;
   return 0;
}
