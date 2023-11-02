/*  2020/2021 Regional
    International Collegiate Programming Contest

    Problem ?
    Digital Speedometer
    M. K. Furon.                    2021-02-25.                       */




#include   <stdio.h>
#include   <stdlib.h>
#include   <math.h>




int iocount;
double display, i, ifrac, previous, sensor, tf, tr;




void abend (char *message)
{
(void) fputs (message, stderr);
(void) fputc ('\n', stderr);
exit (4);
}




int main (int argc, char *argv[], char *envp[])
{
/*  Read falling threshold (t_f) and rising threshold (t_r).          */
iocount = scanf ("%lf %lf", &tf, &tr);
if (iocount != 2)
   abend ("Missing threshold.");
previous = 0.0;
while ((iocount = scanf ("%lf", &sensor)) != EOF)
   {
   if (iocount != 1)
      abend ("Missing input value.");
   /*  Determine if the current value is outside the threshold range. */
   ifrac = modf (sensor, &i);
   if (sensor == 0.0)               /*  If speed is zero              */
      display = 0.0;
   else if (sensor < 1.0)           /*  If speed is below 1.0         */
      display = 1.0;
   else if (ifrac < tf)             /*  If below threshold range      */
      display = i;
   else if (ifrac > tr)             /*  If above threshold range      */
      display = i + 1.0;
   else
      {
      /*  Sensed speed is in the threshold range.                     */
      if (((i + tf) < previous) && (previous < (i + tr)))
         {
         /*  Previous value also in the threshold range.  Print the
	     same value and do not update the previous value.         */
         (void) printf ("%.0f\n", display);
         continue;
         }
      /*  Determine whether the speed is rising or falling based on
          the previous speed.                                         */
      display = (previous < (i + tr)) ? i : (i + 1.0);
      }
   (void) printf ("%.0f\n", display);         
   previous = sensor;
   }

return (0);
}
