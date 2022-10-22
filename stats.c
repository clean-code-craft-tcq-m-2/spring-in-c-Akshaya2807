#include "stats.h"
#include <math.h>
#include "alerters.h"

Stats_t compute_statistics(const float* numberset, int setlength) 
{
   Stats_t s={NAN,NAN,NAN};
   if(setlength == 0) 
    return s;
   s.min = numberset[0];
   s.max = numberset[0];
   s.average = 0;

for(int i=0;i<setlength;i++)
{
   s.average += numberset[i];
   if(s.min > numberset[i])
   {
     s.min = numberset[i];
   }
   if(s.max < numberset[i])
   {
    s.max = numberset[i];
   }
 }
  s.average = s.average/setlength;
  return s;
}

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], Stats_t computedStats)
{
if(computedStats.max > maxThreshold)
   {
     for(int i=0;i<2;i++)
   {
    (*alerters[i])();
   }
 }
}


