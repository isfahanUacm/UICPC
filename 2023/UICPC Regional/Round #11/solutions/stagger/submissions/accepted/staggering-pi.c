/*  2020/2021 Regional
    International Collegiate Programming Contest

    Problem ?
    Staggering to the Finish
    M. K. Furon.                    2021-02-19.                       */




#include   <stdio.h>
#include   <stdlib.h>
#include   <math.h>




int i, iocount, lanecount;
double finalstretch, finishlinex, fullracelength, fullturn;
double insideradius, l1radius, lanelength, laneradius, lanewidth;
double lrlane1, lrlane2, lrradius, racelength, straightaway;
double turnradians;
double answerx[9], answery[9];
double trackpi;




void abend (char *message)
{
(void) fputs (message, stderr);
(void) fputc ('\n', stderr);
exit (4);
}




int main (int argc, char *argv[], char *envp[])
{
/*  Get value for pi.                                                 */
trackpi = atan (1.0) * 4.0;

iocount = scanf ("%d %lf %lf %lf %lf %lf %lf", &lanecount,
   &l1radius, &straightaway, &lanewidth, &finishlinex, &lrlane1,
   &lrlane2);
if (iocount != 7)
   abend ("Missing track paramenter value.");

finalstretch = (straightaway * 0.5) + finishlinex;

/*  Process each lane in turn.                                        */
while ((iocount = scanf ("%lf", &fullracelength)) != EOF)
   {
   if (iocount != 1)
      abend ("Missing race length.");
   for (i = 0; i < lanecount; i++)
      {
      /*  Determine the length of the track along the line of running
          for this lane.  If the race is longer than that length,
	  reduce the race length modulus the line-of-running length.  */
      insideradius = l1radius + (((double) i) * lanewidth);
      lrradius = (!i) ? (lrlane1 + insideradius) :
         (lrlane2 + insideradius);
      fullturn = trackpi * lrradius;
      lanelength = (straightaway * 2.0) + (fullturn * 2.0);
      racelength = fullracelength;
      if (racelength > lanelength)
         racelength = fmod (racelength, lanelength);

      /*  Find where on the track the starting line needs to be.      */
      if (racelength <= finalstretch)  /*  If just on straightaway    */
         {
	 answerx[i] = finishlinex - racelength;
	 answery[i] = (-insideradius);
	 }
      else if (racelength < (finalstretch + fullturn))
         {
         /*  Starting position is on the nearest turn.                */
	 turnradians = (racelength - finalstretch) / lrradius;
         answerx[i] = (-(straightaway * 0.5)) - (sin (turnradians) *
	    insideradius);
	 answery[i] = (-insideradius) * cos (turnradians);
	 }
      else if (racelength < (finalstretch + fullturn + straightaway))
         {
         /*  Starting position is on the straightaway.                */
         answerx[i] = (-(straightaway * 0.5)) + (racelength -
	    fullturn - finalstretch);
	 answery[i] = insideradius;
	 }
      else if (racelength < (finalstretch + fullturn + straightaway +
         fullturn))
	 {
	 /*  Starting position is on the far turn.                    */
         turnradians = (racelength - finalstretch - fullturn -
	    straightaway) / lrradius;
	 answerx[i] = (straightaway * 0.5) + (sin (turnradians) *
	    insideradius);
	 answery[i] = insideradius * cos (turnradians);
	 }
      else
         {
	 /*  Starting position is past the finish line.               */
	 answerx[i] = lanelength - racelength + finishlinex;
	 answery[i] = (-insideradius);
	 }
      }
	
   /*  Print the positions for each lane.                             */
   (void) printf ("%.7f", fullracelength);
   for (i = 0; i < lanecount; i++)
      (void) printf (" %.7f %.7f", answerx[i], answery[i]);
   (void) putchar ('\n');      
   }
   
return (0);
}
