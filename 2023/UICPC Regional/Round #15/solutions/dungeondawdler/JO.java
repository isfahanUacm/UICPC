import java.util.*;
import java.io.*;
import static java.lang.Math.*;
import static java.util.Collections.*;
public class JO {
  static final Vec Z = new Vec(5000,5000);
  static final char[] F = {'N','E','S','W'};
  static final Vec[] D = {new Vec(-1,0),new Vec(0,1),new Vec(1,0),new Vec(0,-1)};
  static final Set<Integer> nil = emptySet();
  public static void main(String[] args) throws Exception {
    try (BufferedReader in = new BufferedReader(new InputStreamReader(System.in))) {
      State S, A, B, C, wx, wy, z;
      S = new State(in.readLine());
      A = S.search(in, nil);
      if (A == null) {
        S.G.put(S.x.e, 'S');
        S.printAns();
      } else {
        B = A.search(in, nil);
        C = B.walk(in, A.path);
        if (C != null && B.path.equals(A.path)) {
          wx = C.search(in, singleton(A.trap.e));
          if (wx == null) {
              wx = C.walk(in, A.path);
              wy = wx.search(in, singleton(A.trap.e));
              if (wy == null) {
                  Vec tA = A.trap;
                  Vec O = tA.sub(S.trap);
                  C.merge(S, O);
                  C.G.put(tA.e, 'A');
                  C.G.put(Z.e, 'a');
                  C.G.put(Z.add(O).e, 'S');
                  C.printAns();
              } else {
                List<List<Integer>> P = new ArrayList<>();
                P.add(A.path);
                P.add(C.path);
                solveIn(in, S, wx, wy, Arrays.asList(new Vec[] {A.trap, C.trap}), P);
              }
          } else {
            List<Vec> T = Arrays.asList(new Vec[] {A.trap, C.trap});
            List<List<Integer>> P = new ArrayList<>();
            P.add(A.path);
            P.add(C.path);
            int i = 0;
            wy = wx.walk(in, P.get(i));
            if (wy != null && wx.path.equals(P.get(i))) {
              wx = wy;
              wy = wx.walk(in, P.get(++i));
              if (wy != null && wx.path.equals(P.get(i)))
                wx = wy;
            }
            if (wy == null)
                solveOut(in, S, wx, T, P, i);
            else if (!wx.path.equals(P.get(i)))
                solveIn(in, S, wx, wy, T, P);
          }
        } else {
          if (C == null) C = B.search(in, nil);
          wx = C.walk(in, A.path);
          if (wx != null && A.path.equals(C.path)) {
            wy = wx.search(in, singleton(B.trap.e));
            if (wy == null) wy = wx;
            z = wy.walk(in, B.path);
            solve(in, S, z, A.trap, A.path, B.trap, B.path);
          } else {
            if (wx != null) C = wx;
            z = C.search(in, singleton(B.trap.e));
            solve(in, S, z, A.trap, A.path, C.trap, C.path);
          }
        }
      }
    }
  }

  static void solve(BufferedReader in, State S, State A, Vec ab, List<Integer> pab, Vec ba, List<Integer> pba) throws Exception {
    List<Integer> T = new ArrayList<>(),
      Tb = new ArrayList<>();
    T.add(ab.e);
    State Am, B, Bm;
    Am = A.search(in, T);
    if (Am != null) {
      T.add(A.trap.e);
      Am.search(in, T);
      Bm = Am.walk(in, pab);
    } else {
      Am = A;
      Bm = A.walk(in, pab);
    }
    Tb.add(ba.e);
    B = Bm.search(in, Tb);
    if (B != null) {
      Tb.add(Bm.trap.e);
      B.search(in, Tb);
      Bm = B;
    }
    Bm.walk(in, pba);
    Vec O = null, S0;
    if (T.size() == 2) {
      S0 = new Vec(T.get(1)).sub(S.trap);
      O = new Vec(T.get(1)).sub(ba);
    } else {
      for (int k : Bm.G.keySet()) {
        if (Bm.G.get(k) == '.') {
          O = new Vec(T.get(0)).sub(new Vec(k));
          break;
        }
      }
      S0 = O.add(ba).sub(S.trap);
    }
    Am.merge(Bm, O);
    Am.G.put(O.add(ba).e, 'A');
    Am.G.put(T.get(0), 'B');
    Am.G.put(Z.e, 'a');
    Am.G.put(Z.add(O).e, 'b');
    Am.G.put(Z.add(S0).e, 'S');
    Am.printAns();
  }

  static void solveIn(BufferedReader in, State S, State wx, State wy, List<Vec> T,
      List<List<Integer>> P) throws Exception {
    State a, b, ab, ax, bx;
    List<Integer> disc = wx.path;
    b = wy.walk(in, disc);
    if (b != null) {
      a = b.search(in, singleton(wx.trap.e));
      ab = a.walk(in, P.get(0));
      bx = ab.walk(in, disc);
      if (bx != null) {
        ax = bx.walk(in, b.path);
        solve(in, S, ax, T.get(0), P.get(0), b.trap, b.path);
      } else {
        ab.walk(in, rev(ab.path));
        solve(in, S, ab, T.get(1), P.get(1), b.trap, b.path);
      }
    } else {
      wy.walk(in, rev(wy.path));
      solve(in, S, wy, T.get(1), P.get(1), wx.trap, wx.path);
    }
  }

  static void solveOut(BufferedReader in, State S, State wx, List<Vec> T,
      List<List<Integer>> P, int i) throws Exception {
    State a, b, w1, w2, z, wy;
    List<Integer> disc = P.get(i);
    wy = wx.search(in, nil);
    z = wy.walk(in, disc);
    if (z == null) {
      z = wy.search(in, singleton(wx.trap.e));
      w1 = z.walk(in, P.get(0));
      w2 = w1.walk(in, disc);
      if (w2 != null) {
        if (disc.equals(P.get(1)))
          w2 = w2.walk(in, wy.path);
        solve(in, S, w2, T.get(1), P.get(1), wy.trap, wy.path);
      } else {
        w1.walk(in, rev(w1.path));
        z = w1.walk(in, wy.path);
        solve(in, S, z, T.get(0), P.get(0), wy.trap, wy.path);
      }
    } else {
      w1 = z.walk(in, disc);
      if (w1 != null) {
        solve(in, S, w1, T.get(1-i), P.get(1-i), wx.trap, wx.path);
      } else {
        z.walk(in, rev(z.path));
        z = z.walk(in, wx.path);
        solve(in, S, z, T.get(i), P.get(i), wx.trap, wx.path);
      }
    }
  }

  static List<Integer> rev(List<Integer> P) {
    List<Integer> rev = new ArrayList<>();
    for (int i = P.size()-1; i >= 0; --i) {
      rev.add((P.get(i)+2)%4);
    }
    return rev;
  }
}

class Vec {
  static final int R = (1<<14)-1;
  final int r,c,e;
  Vec(int x,int y) {r=x;c=y;e=r+(c<<14);}
  Vec(int k) {r=k&R;c=k>>>14;e=k;}
  Vec step(int i) {return add(JO.D[i]);}
  Vec add(Vec o) {return new Vec(r+o.r,c+o.c);}
  Vec sub(Vec o) {return new Vec(r-o.r,c-o.c);}
}

class State {
  static final Vec Z = JO.Z;
  static final int R = Vec.R;
  Vec x = Z, trap;
  List<Integer> path = new ArrayList<>();
  Map<Integer,Character> G = new HashMap<>();
  Set<Integer> seen = new HashSet<>();
  Set<Integer> visited = new HashSet<>();
  State(String ln) {
    G.put(Z.e, ':');
    seen.add(Z.e);
    visited.add(Z.e);
    visit(ln);
  }

  void visit(String U) {
    visited.add(x.e);
    for (int i = 0; i < 4; ++i) {
      int p = x.step(i).e;
      if (!seen.contains(p)) {
        seen.add(p);
        G.put(p, Character.valueOf(U.charAt(i)));
      }
    }
    if (G.get(x.e) == '.')
      G.put(x.e, Character.valueOf(':'));
  }

  void printAns() {
    int c0=5000,c1=5000,r0=5000,r1=5000;
    for (int k : G.keySet()) {
      int r=k&R,c=k>>>14;
      c0=min(c0,c);
      r0=min(r0,r);
      c1=max(c1,c);
      r1=max(r1,r);
    }
    for (int k : G.keySet())
      if (G.get(k) == ':')
        G.put(k, '.');
    System.out.format("done%n%d %d%n", r1-r0+1, c1-c0+1);
    for (int r = r0; r <= r1; ++r) {
      StringBuilder sb = new StringBuilder();
      for (int c = c0; c <= c1; ++c)
        sb.append(G.getOrDefault(r+(c<<14),'#'));
      System.out.println(sb);
    }
    System.out.flush();
  }

  State go(BufferedReader in, int s) throws Exception {
    System.out.println(JO.F[s]);
    System.out.flush();
    String[] ln = in.readLine().split("\\s+");
    x = x.step(s);
    visit(ln[0]);
    if (ln[1].equals("trap")) {
      trap = x;
      return new State(ln[2]);
    }
    return null;
  }

  State search(BufferedReader in, Collection<Integer> no) throws Exception {
    while (true) {
      int s = -1;
      for (int i = 0; i < 4; ++i) {
        int p = x.step(i).e;
        if (!no.contains(p) && !visited.contains(p) && G.get(p) != '#') {
          s = i;
          break;
        }
      }
      if (s == -1) {
        if (path.isEmpty()) break;
        s = (path.get(path.size()-1)+2)%4;
        path.remove(path.size()-1);
      } else {
        path.add(s);
      }
      State succ = go(in, s);
      if (succ != null) return succ;
    }
    return null;
  }

  State walk(BufferedReader in, List<Integer> P) throws Exception {
    for (int s : P) {
      int p = x.step(s).e;
      if (G.getOrDefault(p, '#') == '#') break;
      path.add(s);
      State succ = go(in, s);
      if (succ != null) return succ;
    }
    return null;
  }

  void merge(State B, Vec O) {
    for (int k : B.G.keySet()) {
      int r=k&R,c=k>>>14;
      G.put((O.r+r)+((O.c+c)<<14), B.G.get(k));
    }
  }
}
