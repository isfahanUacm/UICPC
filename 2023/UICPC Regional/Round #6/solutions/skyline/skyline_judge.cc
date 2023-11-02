#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <cmath>
#include <cstdarg>
#include "../include/corr.h"

using namespace std;

const double eps = 1.01e-6;

bool read_token(char *judge, char *team) {
   if(fscanf(judgeout, "%10000s", judge) == EOF) {
      return false;
   }

   if(fscanf(teamout, "%10000s", team) == EOF) {
      report_error("User EOF while judge had more output");
   }
   return true;
}

int main(int argc, char **argv) {
   init_io(argc, argv);
   
   char judge[11000], team[11000];
   char trash[50];

   while(read_token(judge, team)) {
      double j, l;
      if(sscanf(judge, "%lf%10s", &j, trash) == 1) {
	 if(sscanf(team, "%lf%10s", &l, trash) != 1) {
	    report_error("Expected float, got: %s", team);
	 }
	 if(!(fabs(j - l) <= eps) && !(fabs(j-l) <= eps*(fabs(j)+fabs(l)))) {
	    report_error("Too large difference. Judge: %lf, Team: %lf (eps: %lf)", j, l, eps);
	 }
      } else {
	 if(strcasecmp(judge, team) != 0) {
	    report_error("String tokens mismatch\nJudge: \"%s\"\nTeam: \"%s\"\n", judge, team);
	 }
      }
   }

   if(fscanf(judgeout, "%10000s", judge) != EOF)
      assert(!"Trailing judge output");

   if(fscanf(teamout, "%10000s", team) != EOF)
      report_error("Trailing output");

   printf("Correct output\n");
   exit(EXIT_AC);
}
