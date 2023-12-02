// @EXPECTED_RESULTS@: CORRECT
import java.util.Scanner;
import java.util.TreeSet;

/* Boggle */

public class demian {
	
	static private String longest;
	static private int points;
	static private int count;
	static private TreeSet<String> found = new TreeSet<String>();
	static private int[] pointMap = new int[] {0,0,0,1,1,2,3,5,11,11,11,11,11,11,11};
	
	public static void main(String[] args) {
		Trie dict = new Trie();
		Scanner s = new Scanner(System.in);
		
		int numWords = s.nextInt();
		while( numWords --> 0) {
			dict.insert(s.next(), 0);
		}
		
		int numTests = s.nextInt();
		while (numTests --> 0) {
			char[][] field = new char[4][];
			boolean[][] vis = new boolean[4][4];
			found.clear();
			points = count = 0;
			longest = "";
			for(int i = 0; i < 4; ++i)
				field[i] = s.next().toCharArray();
			
			for(int y = 0; y < 4; ++y)
				for(int x = 0; x < field[y].length; ++x)
					findWords(field, y, x, dict, vis);
			
			System.out.format("%d %s %d\n", points, longest, count);
		}
	}

	private static void findWords(char[][] field, int y, int x, Trie pos, boolean[][] vis) {
		if (x > 3 || y > 3 || x < 0 || y < 0)
			return;
		if (vis[y][x])
			return;
		
		char curr = field[y][x];
		int currIdx = curr - 'A';
		if (pos.next[currIdx] == null) {
			return;
		}
		
		vis[y][x] = true;
		Trie next = pos.next[currIdx];
		
		if (next.content != null) {
			String match = next.content;
			if (found.add(match)) {
				count++;
				points += pointMap[match.length()];
				if (match.length() > longest.length()) {
					longest = match;
				} else if (match.length() == longest.length()) {
					longest = longest.compareTo(match) < 0 ? longest : match;
				}
			}
		}
		
		for(int dy = -1; dy <= 1; dy++) {
			for(int dx = -1; dx <= 1; dx++) {
				if (dx == 0 && dy == 0) 
					continue;
				findWords(field, y+dy, x+dx, next, vis);
			}
		}
		
		vis[y][x] = false;
	}

}

class Trie {
	Trie[] next = new Trie['Z' - 'A' + 1];
	String content;
	
	void insert(String word, int idx) {
		if (idx == word.length()) {
			content = word;
		} else {
			int l = word.charAt(idx) - 'A';
			if (next[l] == null) {
				next[l] = new Trie();
			}
			next[l].insert(word, idx+1);
		}
	}
}
