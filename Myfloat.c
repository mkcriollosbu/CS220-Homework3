// Mike Criollo - 117698615
#include "Myfloat.h"
#include <stdio.h>

float construct_float_sf(char sign_bit, char exponent, unsigned int fraction) {
   unsigned int f = 0;

   /*
    * Start coding here
    * Use bitwise operations to construct the IEEE 754 float
   */

   f |= ((unsigned int)sign_bit << 31);
   f |= ((unsigned int)exponent << 23);

   // cleans garbage code above 23 bit
   int mask = 0x7FFFFF;
   unsigned int frac23 = fraction & mask;
   f |= frac23;


   return *(float *)&f;
}
