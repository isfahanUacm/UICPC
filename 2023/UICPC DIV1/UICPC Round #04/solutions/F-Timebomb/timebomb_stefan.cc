/*
 * Solution for NCPC 2013 problem "Time bomb" by Stefan Pszczolkowski
 */

#include <iostream>
#include <cstdio>
#include <cstring>

#define FOR(i,a,b) for(int i=(a);i<(b);i++)

using namespace std;

char matrix[5][401];

bool is_digit(int pos, int digit) {
  char mask[15];

  switch(digit) {
    case 0:
      mask[0] =  '*';
      mask[1] =  '*';
      mask[2] =  '*';
      mask[3] =  '*';
      mask[4] =  ' ';
      mask[5] =  '*';
      mask[6] =  '*';
      mask[7] =  ' ';
      mask[8] =  '*';
      mask[9] =  '*';
      mask[10] = ' ';
      mask[11] = '*';
      mask[12] = '*';
      mask[13] = '*';
      mask[14] = '*';
      break;
    case 1:
      mask[0] =  ' ';
      mask[1] =  ' ';
      mask[2] =  '*';
      mask[3] =  ' ';
      mask[4] =  ' ';
      mask[5] =  '*';
      mask[6] =  ' ';
      mask[7] =  ' ';
      mask[8] =  '*';
      mask[9] =  ' ';
      mask[10] = ' ';
      mask[11] = '*';
      mask[12] = ' ';
      mask[13] = ' ';
      mask[14] = '*';
      break;
    case 2:
      mask[0] =  '*';
      mask[1] =  '*';
      mask[2] =  '*';
      mask[3] =  ' ';
      mask[4] =  ' ';
      mask[5] =  '*';
      mask[6] =  '*';
      mask[7] =  '*';
      mask[8] =  '*';
      mask[9] =  '*';
      mask[10] = ' ';
      mask[11] = ' ';
      mask[12] = '*';
      mask[13] = '*';
      mask[14] = '*';
      break;
    case 3:
      mask[0] =  '*';
      mask[1] =  '*';
      mask[2] =  '*';
      mask[3] =  ' ';
      mask[4] =  ' ';
      mask[5] =  '*';
      mask[6] =  '*';
      mask[7] =  '*';
      mask[8] =  '*';
      mask[9] =  ' ';
      mask[10] = ' ';
      mask[11] = '*';
      mask[12] = '*';
      mask[13] = '*';
      mask[14] = '*';
      break;
    case 4:
      mask[0] =  '*';
      mask[1] =  ' ';
      mask[2] =  '*';
      mask[3] =  '*';
      mask[4] =  ' ';
      mask[5] =  '*';
      mask[6] =  '*';
      mask[7] =  '*';
      mask[8] =  '*';
      mask[9] =  ' ';
      mask[10] = ' ';
      mask[11] = '*';
      mask[12] = ' ';
      mask[13] = ' ';
      mask[14] = '*';
      break;
    case 5:
      mask[0] =  '*';
      mask[1] =  '*';
      mask[2] =  '*';
      mask[3] =  '*';
      mask[4] =  ' ';
      mask[5] =  ' ';
      mask[6] =  '*';
      mask[7] =  '*';
      mask[8] =  '*';
      mask[9] =  ' ';
      mask[10] = ' ';
      mask[11] = '*';
      mask[12] = '*';
      mask[13] = '*';
      mask[14] = '*';
      break;
    case 6:
      mask[0] =  '*';
      mask[1] =  '*';
      mask[2] =  '*';
      mask[3] =  '*';
      mask[4] =  ' ';
      mask[5] =  ' ';
      mask[6] =  '*';
      mask[7] =  '*';
      mask[8] =  '*';
      mask[9] =  '*';
      mask[10] = ' ';
      mask[11] = '*';
      mask[12] = '*';
      mask[13] = '*';
      mask[14] = '*';
      break;
    case 7:
      mask[0] =  '*';
      mask[1] =  '*';
      mask[2] =  '*';
      mask[3] =  ' ';
      mask[4] =  ' ';
      mask[5] =  '*';
      mask[6] =  ' ';
      mask[7] =  ' ';
      mask[8] =  '*';
      mask[9] =  ' ';
      mask[10] = ' ';
      mask[11] = '*';
      mask[12] = ' ';
      mask[13] = ' ';
      mask[14] = '*';
      break;
    case 8:
      mask[0] =  '*';
      mask[1] =  '*';
      mask[2] =  '*';
      mask[3] =  '*';
      mask[4] =  ' ';
      mask[5] =  '*';
      mask[6] =  '*';
      mask[7] =  '*';
      mask[8] =  '*';
      mask[9] =  '*';
      mask[10] = ' ';
      mask[11] = '*';
      mask[12] = '*';
      mask[13] = '*';
      mask[14] = '*';
      break;
    case 9:
      mask[0] =  '*';
      mask[1] =  '*';
      mask[2] =  '*';
      mask[3] =  '*';
      mask[4] =  ' ';
      mask[5] =  '*';
      mask[6] =  '*';
      mask[7] =  '*';
      mask[8] =  '*';
      mask[9] =  ' ';
      mask[10] = ' ';
      mask[11] = '*';
      mask[12] = '*';
      mask[13] = '*';
      mask[14] = '*';
      break;
  }

  char *ptr = &mask[0];
  FOR(i,0,5) {
    FOR(j,pos*4,pos*4+3) {
      if(matrix[i][j] != *ptr) return false;
      ptr++;
    }
  }

  return true;
}

int main() {
    char line[401];
    int length;

    FOR(i,0,5) {
      fgets(line, 401, stdin);

      length = strlen(line);

      //We use length-1 to get rid of the new line character      
      FOR(j,0,length-1) {
        matrix[i][j] = line[j];
      }
      FOR(j,length-1,401) {
        matrix[i][j] = ' ';
      }
    }

    int numberOfDigits = length / 4;

    int sum = 0;
    int lastDigit;
    bool valid;
    FOR(pos,0,numberOfDigits) {
      valid = false;
      FOR(digit,0,10) {
        if(is_digit(pos, digit)) {
          if(pos == numberOfDigits-1) lastDigit = digit;
            
          sum += digit;
          valid = true;
          break;
        }
      }
      if(!valid) break;
    }

    if (valid && (sum % 3 == 0) && (lastDigit % 2 == 0)) {
      cout << "BEER!!" << endl;
    } else {
      cout << "BOOM!!" << endl;
    }

    return 0;
}
