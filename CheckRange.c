
#include "CheckRange.h"

static int Range[10][4];

int RangeCountCheck(int consecutivecnt,int rangecnt,int startValue,int endValue)
{
   if(consecutivecnt!=0)
     {
        rangecnt++;
        printf("%d - %d, %d\n",startValue,endValue,consecutivecnt+1);
        Range[rangecnt][0] = startValue;
        Range[rangecnt][1] = endValue;
        Range[rangecnt][2] = consecutivecnt+1;
      }
   return rangecnt;
}

int isConsecutive(int value)
{
   int consecutive = 0;
   if((value==0) || (value)==1)
     consecutive=1;
   return consecutive;
}

int cmpfunc (const void * value1, const void * value2) 
{
   return ( *(int*)value1 - *(int*)value2 );
}
                 
int * CheckRange(int inputArray[],int inputArraysize)
{ 
   int startValue = inputArray[0];
   int endValue = inputArray[0];
   int range_count=0 ,count=0,diff_value = 0;  
  
  qsort(inputArray, inputArraysize, sizeof(int), cmpfunc);
 
  for( int i = 0 ; i < inputArraysize; i++ ) 
     {   
       diff_value = inputArray[i+1] - inputArray[i];        
        
         if(isConsecutive(diff_value)==1)
        {
           count++;
           endValue = inputArray[i+1];
        }
        else 
        {
           range_count = RangeCountCheck(count,range_count,startValue,endValue);
           startValue = inputArray[i+1];
           endValue = inputArray[i];
           count=0;
        }
     }
  Range[range_count][3] = range_count;  

  return &Range[0][0];
}