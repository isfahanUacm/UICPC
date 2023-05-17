import java.util.Scanner;
import java.lang.Math;

public class mees {

    static boolean can_reach(char scol, int srow, char tcol, int trow) {
        if(scol == tcol)
            return srow != trow;

        if(scol > 'f') {
            srow += scol - 'f';
        }
        if(tcol > 'f') {
            trow += tcol - 'f';
        }

        if(srow == trow)
            return true;

        if(srow - trow == ((int)scol) - ((int)tcol))
            return true;

        return false;
    }

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		char scol, tcol;
        Integer srow, trow;

        String s = sc.next();
        scol = s.charAt(0);
        srow = Integer.parseInt(s.substring(1));

        s = sc.next();
        tcol = s.charAt(0);
        trow = Integer.parseInt(s.substring(1));

        int ct = 0;
        for(char col = 'a'; col < 'l'; col++) {
            for(int n = 1; n < 12; n++) {
                int height = 11 - Math.abs(((int)col) - ((int)'f'));
                if(n > height)
                    break;

                if(can_reach(scol, srow, col, n) && can_reach(col, n, tcol, trow))
                    ct += 1;
            }
        }

        System.out.println(ct);
	}
}

/*
#include <cstdio>
#include <iostream>


using namespace std;

int main() {
    int srow, trow;
    char scol, tcol;
    scanf("%c%d %c%d", &scol, &srow, &tcol, &trow);

    int ct = 0;

    for(char col = 'a'; col < 'l'; col++) {
        for(int n = 1; n < 12; n++) {
            int height = 11 - abs(((int)col) - ((int)'f'));
            if(n > height)
                break;

            if(can_reach(scol, srow, col, n) && can_reach(col, n, tcol, trow))
                ct += 1;
        }
    }

    printf("%d\n", ct);

    return 0;
}*/
