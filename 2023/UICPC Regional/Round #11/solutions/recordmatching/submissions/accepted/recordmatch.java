/**  
* recordmatch.java - ICPC Record Matching
* 2020/2021 Regional
* International Collegiate Programming Contest
* @author  M. K. Furon
* @version 1.0 2021-02-10
*/




import java.io.*;
import java.util.*;




//  Record definition.
class Recordentry
{
String lastname;
String firstname;
String emailaddress;
int recordid;

Recordentry (String last, String first, String email, int id)
{
lastname = last;
firstname = first;
emailaddress = email;
recordid = id;
}
}

//  Comparators for case-insensitive e-mail address and (lastname,
//  firstname) sort orders.
class Compareemail implements Comparator<Recordentry>
{
public int compare (Recordentry entrya, Recordentry entryb)
{
return (entrya.emailaddress.compareToIgnoreCase (entryb.emailaddress));
}
}

class Comparename implements Comparator<Recordentry>
{
public int compare (Recordentry namea, Recordentry nameb)
{
int result;

result = namea.lastname.compareToIgnoreCase (nameb.lastname);
if (result == 0)
   result = namea.firstname.compareToIgnoreCase (nameb.firstname);
return (result);
}
}

class Recordtable
{
ArrayList<Recordentry> table;

Recordtable (BufferedReader input) throws IOException
{
String lineimage;
String entry[];
Recordentry record;
int lineid = 0;

table = new ArrayList<Recordentry> ();
//  Read records until either an empty line or end-of-file is reached.
while ((lineimage = input.readLine ()) != null)
   {
   if (lineimage.isEmpty ())
      break;
   //  Break the tab-separated line apart.
   entry = lineimage.split ("\t");
   lineid++;
   record = new Recordentry (entry[1], entry[0], entry[2], lineid);
   table.add (record);
   }
}
}




class recordmatch
{
public static void main (String args[]) throws IOException
{
int comparison, i, icount, lineid, t, tcount;
boolean allmatch;
int imatch[], tmatch[];
String email, firstname, iemail, lastname, lineimage, temail;

Recordtable itable, ttable;
Recordentry iarray[], tarray[];

BufferedReader stdin = new BufferedReader
   (new InputStreamReader (System.in));

Compareemail byemail = new Compareemail ();
Comparename byname = new Comparename ();

//  Load the ICPC and third-party system tables.
itable = new Recordtable (stdin);
ttable = new Recordtable (stdin);
icount = itable.table.size ();
tcount = ttable.table.size ();
imatch = new int[(1 + icount)];
tmatch = new int[(1 + tcount)];

//  Sort each table into e-mail address order, ignoring case.
itable.table.sort (byemail);
ttable.table.sort (byemail);

//  Match the tables by e-mail addresses.
iarray = new Recordentry[icount];
tarray = new Recordentry[tcount];
iarray = itable.table.toArray (iarray);
tarray = ttable.table.toArray (tarray);

i = t = 0;
while ((i < icount) && (t < tcount))
   {
   comparison = iarray[i].emailaddress.compareToIgnoreCase
      (tarray[t].emailaddress);
   if (comparison < 0)              //  If ICPC address is lower
      i++;
   else if (comparison > 0)         //  If third-party address is lower
      t++;
   else
      {
      //  The two addresses are equal.
      imatch[(iarray[i].recordid)] = tarray[t].recordid;
      tmatch[(tarray[t].recordid)] = iarray[i].recordid;
      i++;
      t++;
      }
   }
      
//  Sort each table into name order, ignoring case.
itable.table.sort (byname);
ttable.table.sort (byname);

//  Match the tables by name, skipping entries that have already been
//  matched.
iarray = itable.table.toArray (iarray);
tarray = ttable.table.toArray (tarray);

i = t = 0;
while ((i < icount) && (t < tcount))
   {
   //  Skip records that have already been matched.
   if (imatch[(iarray[i].recordid)] > 0)
      {
      i++;
      continue;
      }
   if (tmatch[(tarray[t].recordid)] > 0)
      {
      t++;
      continue;
      }
   comparison = iarray[i].lastname.compareToIgnoreCase
      (tarray[t].lastname);
   if (comparison == 0)             //  If last names match
      comparison = iarray[i].firstname.compareToIgnoreCase
         (tarray[t].firstname);
   if (comparison < 0)              //  If ICPC name is lower
         i++;
   else if (comparison > 0)         //  If third-party name is lower
         t++;
   else
      {
      //  The two names are equal.
      imatch[(iarray[i].recordid)] = tarray[t].recordid;
      tmatch[(tarray[t].recordid)] = iarray[i].recordid;
      i++;
      t++;
      }
   }
      
//  Print the results sorted by e-mail addresses.
itable.table.sort (byemail);
ttable.table.sort (byemail);

allmatch = true;
for (Recordentry printrecord: itable.table)
   {
   if (imatch[printrecord.recordid] == 0)
      {
      allmatch = false;
      System.out.print ("I ");
      System.out.print (printrecord.emailaddress);
      System.out.print (" ");
      System.out.print (printrecord.lastname);
      System.out.print (" ");
      System.out.println (printrecord.firstname);
      }
   }
for (Recordentry printrecord: ttable.table)
   {
   if (tmatch[printrecord.recordid] == 0)
      {
      allmatch = false;
      System.out.print ("O ");
      System.out.print (printrecord.emailaddress);
      System.out.print (" ");
      System.out.print (printrecord.lastname);
      System.out.print (" ");
      System.out.println (printrecord.firstname);
      }
   }
if (allmatch)
   System.out.println ("No mismatches.");

return;
}
}
