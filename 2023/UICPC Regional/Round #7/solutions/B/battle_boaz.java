import java.io.*;
import java.util.*;

public class battle_boaz {
	static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
	public battle_boaz() {}

	public static void main(String[] args) throws Exception {
		new battle_boaz().doProblem();
	}

	public static void out(Object o, boolean newline) {
		if (newline) System.out.println(o.toString());
		else System.out.print(o.toString());
		System.out.flush();
	}

	public static void out(Object o) {
		out(o, true);
	}

	public void doProblem() throws Exception {
		solve();
	}

	public void solve() throws Exception {
        int ignore = 0;
        char[] moves = new char[3];

        for (int i = 0; i < 3; i++)
            moves[i] = (char)in.read();

        while (moves[0] != '\n' && moves[0] != '\0') {
            if (ignore > 0)
                --ignore;
            else {
                if (moves[0] == 'R') { 
                    if ((moves[1] == 'B' && moves[2] == 'L') || (moves[1] == 'L' && moves[2] == 'B')) {
                        out("C", false);
                        ignore = 2;
                    }
                    else out("S", false);
                } 
                if (moves[0] == 'B') { 
                    if ((moves[1] == 'R' && moves[2] == 'L') || (moves[1] == 'L' && moves[2] == 'R')) { 
                        out("C", false);
                        ignore = 2;
                    }
                    else out("K", false);
                }
                if (moves[0] == 'L') { 
                    if ((moves[1] == 'B' && moves[2] == 'R') || (moves[1] == 'R' && moves[2] == 'B')) {
                        out("C", false);
                        ignore = 2;
                    }
                    else out("H", false);
                }
            }
            char input = (char)in.read();

            moves[0] = moves[1];
            moves[1] = moves[2];
            moves[2] = input;
        }
        out("", true);
	}
}
