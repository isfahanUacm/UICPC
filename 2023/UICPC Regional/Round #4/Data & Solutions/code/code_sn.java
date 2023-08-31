import java.util.*;
import java.io.*;


public class code_sn {
	
	static String EndTag = "***END***";
	
    static String NormalizeString(String source) {
    	while (true) {
    		String newStr = source.replace("  ", " ");
    		if (newStr.length() == source.length()) {
    			return newStr.trim();
    		} else {
    			source = newStr;
    		}
    	}
    }
	
    
    class CodeLine {
        String contents;
        CodeLine previousLine;
        int lineNr;


        public CodeLine(String contents, CodeLine previousLine, int lineNr) {
            this.contents = contents;
            this.previousLine = previousLine;
            this.lineNr = lineNr;
        }
       
       
        public Boolean followsAfter(CodeLine candidate) {
            return (candidate != null && lineNr == candidate.lineNr+1);
        }
        
        public String getContents() {
        	return contents;
        }
        
        public int getLineNr() {
        	return lineNr;
        }

        @Override
        public String toString() {
        	return String.format("%d:%s", lineNr, contents);
        }

        @Override
        public int hashCode() {
        	return lineNr;
        }
    }
    
    class Match {
        CodeLine lastMatchLine;
        int matchLength;

        public Match(CodeLine lastLine, int length) {
        	this.lastMatchLine = lastLine;
        	this.matchLength = length;
        }

        public int getMatchLength() {
            return matchLength;
        }
        
        public int getLastLine() {
        	return lastMatchLine.getLineNr();
        }
        
        @Override
        public boolean equals(Object other) {
        	if (other instanceof Match) {
        		Match otherMatch = (Match) other;
        		return otherMatch.lastMatchLine == lastMatchLine && otherMatch.matchLength == matchLength;
        	} else {
        		return false;
        	}
        }
        
        @Override
        public int hashCode() {
        	return matchLength*10000 + lastMatchLine.hashCode();
        }

        @Override
        public String toString() {
        	return String.format("%d : %s", matchLength, lastMatchLine);
        }

    }
    
    class Repository {

        ArrayList<CodeLine> emptyMatchList = new ArrayList<CodeLine>();
        
        HashMap<String, ArrayList<CodeLine>> repositoryLines = new HashMap<String, ArrayList<CodeLine>>(1000);

        public void Add(CodeLine newLine) {
        	String contents = newLine.getContents();
        	ArrayList<CodeLine> targetLine = repositoryLines.get(contents);
            if (targetLine == null) {               
                targetLine = new ArrayList<CodeLine>();
                repositoryLines.put(contents, targetLine);
            }
            targetLine.add(newLine);
        }

        
        public void FillSnippet(ArrayList<String> input) {
            CodeLine previousLine = null;
            int lineNr = 0;
            for (String lineString : input) {
            	CodeLine currentLine = new CodeLine(lineString, previousLine, lineNr++);
            	Add(currentLine);
            	previousLine = currentLine;
            }
        }
        
        public ArrayList<CodeLine> GetMatches(String sourceLine) {
            ArrayList<CodeLine> matches = repositoryLines.get(sourceLine);
            return (matches == null) ? (emptyMatchList) : matches;
        }        
        
    }
    
    class BestMatches {
    	HashMap<Integer,Match> matchList = new HashMap<Integer,Match>();
    	HashMap<Integer,Match> newMatches = new HashMap<Integer,Match>();
        int longestMatch = 0;

        void AddMatch(Match matchToAdd) {
        	
        	if (!newMatches.containsKey(matchToAdd.getLastLine())) {
        		newMatches.put(matchToAdd.getLastLine(),matchToAdd);
        		if (matchToAdd.getMatchLength() > longestMatch) {
        			longestMatch = matchToAdd.getMatchLength();
        		}
        	}
        }
        
        public Match UpdateMatch(Match source, CodeLine nextLine) {
        	if (nextLine.getLineNr() == source.getLastLine()+1) {
        		return new Match(nextLine, source.matchLength+1);
        	} else {
        		return null;
        	}
        }

        
       
        public void Process(CodeLine candidate) {
            
            Match existingMatch = matchList.get(candidate.getLineNr()-1);
            if (existingMatch != null) {
        		AddMatch(new Match(candidate, existingMatch.getMatchLength()+1));            	
            } else {
                AddMatch(new Match(candidate, 1));
            }
        }

        public void Flush() {
        	HashMap<Integer,Match> temp = matchList;
            matchList = newMatches;
            newMatches = temp;
            newMatches.clear();
        }

        public int getLongestMatch() {
        	return longestMatch;
        }

    }
    
    public ArrayList<String> readFragment(BufferedReader input) throws IOException {
		ArrayList<String> fragment = new ArrayList<String>();
		String fragmentStr = NormalizeString(input.readLine());
		while (!fragmentStr.equals(EndTag)) {
			if (!fragmentStr.equals("")) {
				fragment.add(fragmentStr);
			}
			fragmentStr = NormalizeString(input.readLine());
		}
		return fragment;
    }
    

    public void Run() throws IOException {
		
		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));		
		
		int nFiles = Integer.parseInt(input.readLine());
        String[] fileNames = new String[nFiles];
        int[] matchLengths = new int[nFiles];
        ArrayList<String>[] snippets = new ArrayList[nFiles];
        for (int i = 0; i < nFiles; i++) {
        	fileNames[i] = input.readLine();
        	snippets[i]=readFragment(input);
        }
        
		ArrayList<String> fragment = readFragment(input);
		

        
        for (int i = 0; i < nFiles; i++) {
    		Repository repository = new Repository();
        	repository.FillSnippet(snippets[i]);

        	
        	BestMatches matches = new BestMatches();
        	for(String s : fragment) {
        		// Locate matches in the repository
        		ArrayList<CodeLine> matchingLines = repository.GetMatches(s);
        		for (CodeLine candidate : matchingLines) {
        			matches.Process(candidate);
        		}
        		matches.Flush();
        		matchLengths[i] = matches.getLongestMatch();
        	}       	        	
        }
                         
        int longestMatchLength = 0;
        for (int i=0; i<nFiles; i++) {
        	if (matchLengths[i] > longestMatchLength) {
        		longestMatchLength = matchLengths[i];
        	}
        	
        }

        if (longestMatchLength == 0) {
            System.out.println(0);
        } else {
        	System.out.print(longestMatchLength);
        	for (int i=0; i<nFiles; i++) {
        		if (matchLengths[i]==longestMatchLength) {
        			System.out.print(" ");
        			System.out.print(fileNames[i]);
        		}
        	}
        	System.out.println();
        }
    }
    
	/**
	 * @param args
	 */
	public static void main(String[] args) throws Exception{
		new code_sn().Run();
	}
}
