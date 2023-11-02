/**  
* substringchar.java - Substring Characters
* 2020/2021 Regional
* International Collegiate Programming Contest
* @author  M. K. Furon
* @version 1.0 2021-01-16
*/




import java.io.*;
import java.util.*;




class substringchar
{
public static void main (String args[]) throws IOException
{
int answer, firstpos, gpsize, i, linelength;
char entry, firstchar;
String foundsubstr, lineimage;
char linechars[];

HashSet<Character> genperiod;
HashMap<Character, Integer> gpmap;
HashSet<String> substrings;

BufferedReader stdin = new BufferedReader
   (new InputStreamReader (System.in));

//  Read the string to be analyzed.
while ((lineimage = stdin.readLine ()) != null)
   {
   //  Build the generalized period of the string (the set of
   //  characters that make up the string).
   linelength = lineimage.length ();
   linechars = new char[linelength];
   linechars = lineimage.toCharArray ();

   //  Scan the character array for unique elements.
   genperiod = new HashSet<Character> (62);
   for (char element: linechars)
      {
      if (!genperiod.contains (element))
         genperiod.add (element);
      }
   gpsize = genperiod.size ();

   //  Handle special cases.
   if (linelength == 1)
      answer = 0;
   else if (linelength == 2)
      answer = (linechars[0] == linechars[1]) ? 1 : 0;
   else if (linelength == gpsize)   //  If every character is unique
      answer = 0;
   else if (gpsize == 1)            //  If only one character in set
      answer = 1;
   else
      {
      gpmap = new HashMap<Character, Integer> (gpsize);
      substrings = new HashSet<String> ();
      //  Scan the string to find proper minimal unique substrings.
      for (i = 0; i < linelength; i++)
         {
         entry = linechars[i];
         gpmap.put (entry, i);
         if (gpmap.size () == gpsize)  //  If map covers all characters
            {
   	    //  The lowest entry in the map represents the beginning of
  	    //  a substring that meets the requirements.
	    firstpos = Collections.min (gpmap.values ());
            firstchar = lineimage.charAt (firstpos);
	    foundsubstr = lineimage.substring (firstpos, (i + 1));
	    substrings.add (foundsubstr);
	    //  Remove the map entry for the first character in the
	    //  substring.
	    gpmap.remove (firstchar);
	    }
         }
      answer = substrings.size ();
      }
   System.out.println (answer);
   }

return;
}
}
