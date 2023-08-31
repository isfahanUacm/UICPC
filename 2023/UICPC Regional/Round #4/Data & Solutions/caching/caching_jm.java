import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class caching_jm {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		
		int memSize = in.nextInt(), diskSize = in.nextInt(), accesses = in.nextInt();

		TreeSet<Integer> nextAccess = new TreeSet<Integer>();

		int[] a = new int[accesses], next = new int[accesses], last = new int[diskSize];
		for (int i = 0; i < diskSize; i++)
			last[i] = -1;
		for (int i = 0; i < accesses; i++)
		{
			a[i] = in.nextInt();
			next[i] = -1;
			if (last[a[i]] >= 0)
				next[last[a[i]]] = i;
			last[a[i]] = i;
		}

		int diskReads = 0;
		for (int i = 0; i < accesses; i++)
		{
			boolean isInMemory = nextAccess.contains(-i);
			if (isInMemory)
				nextAccess.remove(-i);
			else
			{
				if (nextAccess.size() == memSize)
					nextAccess.remove(nextAccess.first());
				diskReads++;
			}
			if (next[i] >= 0)
				nextAccess.add(-next[i]);
		}

		System.out.println(diskReads);		
	}
}
