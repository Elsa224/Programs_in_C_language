/*FRANCE-IOI exercice 2-3.7) : Distance euclidienne*/
#include <stdio.h>
#include <math.h>

double distance(double abs1, double ord1, double abs2, double ord2)
   {return sqrt(pow(abs2 - abs1, 2) + pow(ord2 - ord1, 2));}

int main()
{
   double x1, y1, x2, y2;
   scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
   printf("%lf\n", distance(x1, y1, x2, y2));
   return 0;
}
