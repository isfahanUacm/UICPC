/*  2020/2021 Regional
    International Collegiate Programming Contest

    Problem ?
    Ada Loveslaces
    M. K. Furon.                    2021-02-17.                       */




#include  <stdio.h>
#include  <stdlib.h>
#include  <math.h>




int answer, distance, eyelets, freemin, freemax, i, iocount;
int lacelength, lacingcount, patterncount, separation, thickness;
const double epsilon = 0.001;
double checkmin, checkmax, freeends, sidelength;
double crosslength[9];
double patternlength[65536];

struct eyeletset
{
char mark[18];
} visited;




void abend (char *message)
{
(void) fputs (message, stderr);
(void) fputc ('\n', stderr);
exit (4);
}




int tracelacing (int starteyelet, double lengthsofar,
   struct eyeletset usedeyelet)
{
/*  Recursively build the "patternlength" table of lengths of
    distinct lacing patterns, setting "patterncount" to contain the
    number of entries.                                                */

int pathcount = 0;
int crossd, i, iside, side;
double freeends, lacedlength, thislength;
struct eyeletset nextlist;

#ifdef     TRACE
(void) fputs ("TRACE:  ", stderr);
(void) fprintf (stderr, "starteyelet = %d, lengthsofar = %.5f\n",
   starteyelet, lengthsofar);
(void) fputs ("Used eyelet list:\n", stderr);
for (i = 0; i < (eyelets * 2); i++)
   {
   if (usedeyelet.mark[i])
      (void) fprintf (stderr, "%d ", i);
   }
(void) fputc ('\n', stderr);
#endif

/*  Mark the eyelet and its mirror as visited.                        */
usedeyelet.mark[starteyelet] = usedeyelet.mark[(starteyelet ^ 1)] =
   (char) 1;

/*  Build the list of possible next destinations for the shoelace.
    This could be any eyelet on the opposite side not yet used,
    or not yet used eyelets adjacent to the current eyelet on the
    same side.                                                        */
side = starteyelet & 1;

#ifdef     TRACE
(void) fputs ("Next eyelet list:\n", stderr);
#endif

for (i = 0; i < (eyelets * 2); i++)
   {
   nextlist.mark[i] = (char) 0;
   iside = i & 1;
   if (side != iside)               /*  If opposite column eyelets    */
      {
      if (!usedeyelet.mark[i])      /*  If eyelet not yet used        */
         nextlist.mark[i] = (char) 1;      
      }
   else
      {
      if ((abs (starteyelet - i) == 2)  &&  (!usedeyelet.mark[i]))
         /*  Eyelet is not yet used and adjacent in same column.      */
         nextlist.mark[i] = (char) 1;
      }

#ifdef     TRACE
   if (nextlist.mark[i])
      (void) fprintf (stderr, "%d ", i);
#endif

   }

#ifdef     TRACE
(void) fputc ('\n', stderr);
#endif

/*  Iterate over the possible next eyelets.  If one of the next
    eyelets is 0 or 1, determine the total length of the shoelace
    used for lacing.  If any other eyelet is next, make a recursive
    call from that eyelet.                                            */
for (i = 0; i < (eyelets * 2); i++)
   {
   if (nextlist.mark[i])
      {
      /*  Determine the length of shoelace used between these
          eyelets.                                                    */
      if ((abs (starteyelet - i)) == 2)
         thislength = (double) distance;
      else
         {
         crossd = (abs ((starteyelet & ~1) - (i & ~1))) / 2;
	 thislength = crosslength[crossd];
	 }
      thislength += (double) thickness;
      if (i < 2)                    /*  If top of shoe reached        */
         {
         lacedlength = ((double) separation) +
	    ((lengthsofar + thislength) * 2.0);
         pathcount++;
         patternlength[patterncount++] = lacedlength;

#ifdef     TRACE
         (void) fprintf (stderr, "Eyelet %d reached.  ", i);
	 (void) fprintf (stderr, "patterncount = %d, ", patterncount);
	 (void) fprintf (stderr, "lacedlength = %.5f\n", lacedlength);
#endif

	 }
      else
         pathcount += tracelacing (i, (lengthsofar + thislength),
	    usedeyelet);
      }
   }

return (pathcount);
}




int main (int argc, char *argv[], char *envp[])
{
/*  Read lacing parameters.                                           */
iocount = scanf ("%d %d %d %d %d %d", &eyelets, &distance, &separation,
   &thickness, &freemin, &freemax);
if (iocount != 6)
   abend ("Incorrect parameter input.");

/*  Determine the distance absorbed by crossing a pair of eyelets one
    apart, two apart, ..., (eyelets - 1) apart.                       */
for (i = 1; i < eyelets; i++)
   {
   sidelength = distance * i;
   crosslength[i] = sqrt ((double) ((separation * separation) +
      (sidelength * sidelength)));
   }

patterncount = 0;
for (i = 0; i < (eyelets * 2); i++)
   visited.mark[i] = (char) 0;
lacingcount = tracelacing ((eyelets * 2) - 2, ((double) thickness),
   visited);

while (iocount = scanf ("%d", &lacelength))
   {
   if (iocount == EOF)
      break;
   else if (iocount != 1)
      abend ("Incorrect shoelace length.");
   else
      {
      /*  Determine the free end length for each lacing pattern and
      	  count the number of patterns that have the free ends in the
	  desired range.                                              */
      answer = 0;
      for (i = 0; i < patterncount; i++)
         {
	 freeends = (((double) lacelength) - patternlength[i]) * 0.5;
	 if ((freeends >= ((double) freemin))  &&
	    (freeends <= ((double) freemax)))
	    answer++;
         /*  Check for free ends being within epsilon of the
	     specified minimum or maximum values.                     */
         checkmin = fabs (freeends - freemin);
	 checkmax = fabs (freeends - freemax);
	 if ((checkmin < epsilon) || (checkmax < epsilon))
	    (void) fprintf (stderr,
	       "Value close to edge:  freeends = %.7f\n", freeends);
	 }
      (void) printf ("%d\n", answer);
      }      
   }      

return (0);
}
