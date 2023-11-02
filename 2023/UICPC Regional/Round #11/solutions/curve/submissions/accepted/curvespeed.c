/*  2020/2021 Regional
    International Collegiate Programming Contest

    Problem ?
    Curve Speed
    M. K. Furon.                    2021-02-15.                       */




#define    EPSILON   0.00001




#include   <stdio.h>
#include   <stdlib.h>
#include   <math.h>




int iocount;
double r, s, v, vfrac, vint;




void abend (char *message)
{
(void) fputs (message, stderr);
(void) fputc ('\n', stderr);
exit (4);
}




int main (int argc, char *argv[], char *envp[])
{
/*  Read values of R and S.                                           */
while ((iocount = scanf ("%lf %lf", &r, &s)) != EOF)
   {
   if (iocount != 2)
      abend ("Missing input value.");
   if ((r < 100.0) || (r > 5280.0))
      abend ("R out of range.");
   if ((s <= 0.009) || (s >= 1.0))
      abend ("S out of range.");
   v = sqrt (r * (s + 0.16) / 0.067);
   /*  Check for rounding "danger" for V.                             */
   vfrac = modf (v, &vint);
   if (fabs (vfrac - 0.5) < EPSILON)  /*  If value close to v.5       */
      (void) fputs ("Check next value rounding behavior.\n", stderr);
   (void) printf ("%.0f\n", v);         
   }

return (0);
}
