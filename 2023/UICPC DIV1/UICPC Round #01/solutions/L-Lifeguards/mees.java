import java.util.Scanner;
import java.util.ArrayList;
import java.io.*;
import java.util.*;

class LPair implements Comparable<LPair>{
    long x;
    long y;

    public LPair(long x, long y) {
        super();
        this.x = x;
        this.y = y;
    } 
    public int compareTo(LPair other) {
        if(this.x < other.x)
            return -1;
        if(this.x > other.x)
            return 1;
        if(this.y < other.y)
            return -1;
        if(this.y > other.y)
            return 1;
        return 0;
    }
}

public class mees {

	public static void main(String[] args) throws IOException {
        BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
        Integer n = Integer.parseInt(reader.readLine());

        ArrayList<LPair> points = new ArrayList<LPair>();

        for(int i = 0; i < n; i++) {
            String[] point = reader.readLine().split(" ");

            Integer a = Integer.parseInt(point[0]);
            Integer b = Integer.parseInt(point[1]);
            
            LPair pt = new LPair((long)a, (long)b);

            points.add(pt);
        }

        Collections.sort(points);
        int half = (n-1)/2;
        long big = 10000000000L;

        long ax = (points.get(half).x + 1);
        long ay = (points.get(half).y - big);

        long bx = (points.get(half).x - 1);
        long by = (points.get(half).y + big + ((n%2==1)?0:1));

        System.out.print(ax+by-ay);
        System.out.print(" ");
        System.out.println(ay-bx+ax);
        System.out.print(ax-by+ay);
        System.out.print(" ");
        System.out.println(ay+bx-ax);
	}
}

/*
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n; cin >> n;

    vector<pair<long long, long long>> v(n);

    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end());
    
    int half = (n-1)/2;
    long long big = 1000000000000LL;

    printf("%lld %lld\n%lld %lld\n", 
            v[half].first + 1, v[half].second - big,
            v[half].first -1 , v[half].second + big + ((n%2)?0:1));

    return 0;
}
 */
