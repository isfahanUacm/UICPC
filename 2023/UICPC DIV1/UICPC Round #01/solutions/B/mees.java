import java.util.Scanner;
import java.util.Stack;
public class mees {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);

        int n = sc.nextInt();

        Stack<Long> s = new Stack<Long>();
        s.push(0L);
        boolean o = true;
        Long M = 1000000007L;
		
        for(int i = 0; i < n; i++) {
            String t = sc.next();
            if(t.equals("(")) {
                o = !o;
                if(o)
                    s.push(0L);
                else
                    s.push(1L);
            }
            else if(t.equals(")")) {
                o = !o;
                Long last = s.pop();
                Long top = s.pop();
                if(o)
                    s.push((last+top) % M);
                else
                    s.push((last*top) % M);
            }
            else {
                Long cur = Long.parseLong(t);
                Long top = s.pop();
                if(o)
                    s.push((cur+top) % M);
                else
                    s.push((cur*top) % M);
            }
        }
        System.out.println(s.pop());
	}
}
