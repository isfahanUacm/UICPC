import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.Scanner;
import java.util.ArrayList;
import java.util.TreeSet;
import java.util.Set;

public class interviewqueue_hc {

    private void work() {
        Scanner sc = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
        int N = sc.nextInt();

	int[] left = new int[N];
	int[] right = new int[N];
	int[] v = new int[N];
	boolean[] present = new boolean[N];

	for (int i = 0; i < N; i++) {
	  v[i] = sc.nextInt();
	  left[i] = i-1;
	  right[i] = i+1;
	  present[i] = true;
	}
	right[N-1] = -1;

	ArrayList<Integer> cand = new ArrayList<Integer>();
	for (int i = 0; i < N; i++) {
	  if ((i > 0 && v[i] < v[i-1]) ||
	      (i < N-1 && v[i] < v[i+1])) {
	    cand.add(i);
	  }
	}

	ArrayList<ArrayList<Integer>> remove = new ArrayList<ArrayList<Integer>>();
	while (cand.size() > 0) {
	  ArrayList<Integer> step = new ArrayList<Integer>();
	  for (int i : cand) {
	    step.add(v[i]);
	    present[i] = false;
	  }
	  remove.add(step);

	  Set<Integer> cand2 = new TreeSet<Integer>();
	  for (int i : cand) {
	    int l = left[i];
	    if (l >= 0 && !present[l]) continue;
	    int r = right[i];
	    while (r >= 0 && !present[r]) {
	      r = right[r];
	    }

	    if (l >= 0) {
	      right[l] = r;
	    }
	    if (r >= 0) {
	      left[r] = l;
	    }
	    if (l >= 0 && r >= 0) {
	      if (v[l] < v[r]) cand2.add(l);
	      else if (v[l] > v[r]) cand2.add(r);
	    }
	  }

	  cand.clear();
	  for (int i : cand2) {
	    cand.add(i);
	  }
	}
	
        StringBuilder sb = new StringBuilder();

	sb.append(remove.size());
	sb.append('\n');
	for (ArrayList<Integer> w : remove) {
	  for (int x : w) {
	    sb.append(x);
	    sb.append(' ');
	  }
	  sb.append('\n');
	}
	for (int i = 0; i < N; i++) {
	  if (present[i]) {
	    sb.append(v[i]);
	    sb.append(' ');
	  }
	}
	sb.append('\n');
        System.out.print(sb);
        System.out.flush();
    }

    public static void main(String[] args) {
        new interviewqueue_hc().work();
    }
}
