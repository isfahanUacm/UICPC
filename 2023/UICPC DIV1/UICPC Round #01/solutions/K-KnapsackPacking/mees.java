import java.util.Scanner;
import java.util.ArrayList;
import java.util.Collections;
import java.util.Map;
import java.util.HashMap;

public class mees {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
        
        ArrayList<Integer> l = new ArrayList<Integer>();
        ArrayList<Integer> results = new ArrayList<Integer>();

        for(int i = 0; i < (1<<n); i++) {
            int cur = sc.nextInt();
            l.add(cur);
        }
        
        boolean done = false;
        for(int step = 0; step < n; step++) {
            Collections.sort(l);

            Integer cur = l.get(1) - l.get(0);

            results.add(cur);

            ArrayList<Integer> new_l = new ArrayList<Integer>();

            HashMap<Integer, Integer> seen = new HashMap<Integer, Integer>();

            for(int i = 0; i < l.size(); i++) {
                Integer k = l.get(i);

                if(seen.containsKey(k - cur) && seen.get(k-cur) > 0) {
                    seen.put(k-cur, seen.get(k-cur) - 1);
                }
                else {
                    if(!seen.containsKey(k))
                        seen.put(k,0);
                    seen.put(k, seen.get(k) + 1);
                    new_l.add(k);
                }
            }

            boolean all_zero = true;
            for(Integer val : seen.values()) {
                all_zero &= (val == 0);
            }

            if(l.get(0) != 0 || new_l.size() != l.size()/2 || !all_zero) {
                done = true;
                System.out.println("impossible");
                break;
            }

            l = new_l;
        }
        if(!done) {
            for(int i = 0; i < results.size(); i++) {
                System.out.println(results.get(i));
            }
        }

	}
}

/*
n = int(input())

l = [int(input()) for _ in range(2**n)]

results = []
for step in range(n):
    l.sort()
    cur = l[1] - l[0]
    results.append(cur)

    new_l = []
    seen = {}
    for k in l:
        if k - cur in seen and seen[k-cur] > 0:
            seen[k-cur] -= 1
        else:
            if k not in seen:
                seen[k] = 0
            seen[k] += 1
            new_l.append(k)
    if l[0] != 0 or len(new_l) != len(l)//2 or not all(x == 0 for x in seen.values()):
        print("impossible")
        break
    l = new_l
else:
    print("\n".join(str(x) for x in results))
*/
