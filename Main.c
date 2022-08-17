#include "CheckRange.h"
#include <assert.h>

int main()
{
int *range;

int array[] = {3, 3, 5, 4, 10, 11, 12};
int arraysize = sizeof(array) / sizeof(array[0]);
  
range = CheckRange(array,arraysize);

assert(*(range+4) == 3);
assert(*(range+6) == 4);
 
return 0;
}