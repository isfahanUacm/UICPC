// @EXPECTED_RESULTS@: CORRECT


#include <stdio.h>
#include<iostream>
#include <set>
#include <map>
#include <string>
#include <string.h>
#include <stdlib.h>

using namespace std;

#define MAX_B 5008

int mdays[][12] = {{31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}, {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31} };

typedef struct{
  int start;
  int end;
} time_entry_t;

map<int, time_entry_t> timemap;

map<int, time_entry_t>::iterator get_crate_entry(int time){
	map<int, time_entry_t>::iterator ret = timemap.find(time);
	if ( ret == timemap.end() ){
		time_entry_t newentry;
		newentry.start = 0;
		newentry.end = 0;
		ret = timemap.insert( pair<int, time_entry_t>(time, newentry) ).first;
	}
	return ret;
}

void add_time(int time, bool start){
//   printf(" add time %Ld, start %d\n", time, start);
  get_crate_entry(time)->second.start += start;
  get_crate_entry(time)->second.end += (1-start);
}


int month_days(int m, bool leap){
  int sum = 0;
  for ( int i = 0; i < m; i++ ){
	sum += mdays[leap][i];
  }
//   printf("month days (%d, leap %d) %d\n", m, leap, sum);
  return sum;
}

int read_time(){
  int yy, mm, dd, h, min;
  scanf("%d-%d-%d%d:%d", &yy, &mm, &dd, &h, &min);
  
  // since 2013.01.01 00:00
  int  dtot = (yy-2013)*365 + (month_days(mm-1, yy==2016) + dd - 1);
  int total =  (dtot * 24 + h)* 60 + min;
  return total;
}

int process(){
  int busy = 0;
  int max_busy = 0;
  for ( map<int, time_entry_t>::iterator entryIt = timemap.begin(); entryIt != timemap.end(); entryIt++ ){
	busy += entryIt->second.start;
	busy -= entryIt->second.end;
	if ( busy > max_busy ) max_busy = busy;
  }
  return max_busy;
}

int main(){
  int cases;
  scanf("%d", &cases);
  
  while(cases-->0){
	int bkings;
	int clean;
	timemap.clear();
	
	scanf("%d%d", &bkings, &clean);
	getchar();//\n
	for ( int i = 0; i < bkings; i++ ){
	  // reservation code
	  while( getchar() != ' ' ) ; 
	  int start = read_time();
	  int end = read_time() + clean;

	  add_time(start, true);
	  add_time(end, false);
	}
	int rooms = process();
	printf("%d\n", rooms);
  }// cases
}