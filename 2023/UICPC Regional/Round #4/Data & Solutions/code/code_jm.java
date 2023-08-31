import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class code_jm {
	public static void main(String[] args) {
		Scanner in = new Scanner(new BufferedReader(new InputStreamReader(System.in)));
		
		ArrayList<CodeFragment> frags = new ArrayList<CodeFragment>();
		int noFiles = Integer.parseInt(in.nextLine());
		for (int i = 0; i < noFiles; i++)
		{
			CodeFragment cf = new CodeFragment();
			cf.Name = in.nextLine();
			cf.Lines = new ArrayList<TokenizedLine>();
			String s = in.nextLine();
			while (!(s.equals("***END***")))
			{
				TokenizedLine tl = new TokenizedLine(s);
				if (!tl.IsEmpty())
					cf.Lines.add(tl);
				s = in.nextLine();
			}
			frags.add(cf);
		}

		ArrayList<TokenizedLine> lines = new ArrayList<TokenizedLine>();
		String s2 = in.nextLine();
		while (!(s2.equals("***END***")))
		{
			TokenizedLine tl = new TokenizedLine(s2);
			if (!tl.IsEmpty())
				lines.add(tl);
			s2 = in.nextLine();
		}

		int mostLines = 0;
		ArrayList<String> bestFiles = new ArrayList<String>();

		for (CodeFragment frag : frags)
		{			
			int mostMatches = 0;
			for (int delta = 0; delta <= Math.max(lines.size(), frag.Lines.size()); delta++)
			{
				for (int dir = -1; dir <= 1; dir += 2)
				{
					int ofs = dir*delta;
					if (ofs < -frag.Lines.size() || ofs > lines.size())
						continue;

					int matches = 0;
					int upper = Math.min(lines.size(), frag.Lines.size() + ofs);
					int lower = Math.max(0, ofs);
					if (upper - lower <= mostMatches)
						continue;
					for (int k = lower; k < upper; k++)
					{
						if (frag.Lines.get(k - ofs).Matches(lines.get(k)))
							matches++;
						else
							matches = 0;
						mostMatches = Math.max(matches, mostMatches);
					}
				}
			}

			if (mostMatches > mostLines)
			{
				mostLines = mostMatches;
				bestFiles = new ArrayList<String>();
			}
			if (mostMatches == mostLines)
				bestFiles.add(frag.Name);
		}

		System.out.print(mostLines);		
		if (mostLines > 0)
		{
			for (String file : bestFiles)
				System.out.print(" " + file);			
		}
		System.out.println();				
	}
	
	public static class CodeFragment
	{
		public String Name;
		public ArrayList<TokenizedLine> Lines;
	}
	
	public static class TokenizedLine
	{
		private ArrayList<String> tokens;
		private int hc;
		
		public TokenizedLine(String s)
		{			
			String[] t = s.split(" ");
			tokens = new ArrayList<String>();
			for(String s2 : t)
				if (s2.length() > 0) {
					tokens.add(s2);
					hc = hc * 101 + s2.hashCode();
				}
		}

		public boolean IsEmpty()
		{
			return tokens.size() == 0;
		}

		public boolean Matches(TokenizedLine other)
		{
			if (hc != other.hc)
				return false;
			if (tokens.size() != other.tokens.size())
				return false;
			for (int i = 0; i < tokens.size(); i++)
				if (!tokens.get(i).equals(other.tokens.get(i)))					
					return false;		
			return true;
		}
	}
}
