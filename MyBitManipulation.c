// HW3 Starter Code
#include "MyBitManipulation.h"
#include <stdio.h>

/*
* Toggle the bit at position pos in num
*/
int ToggleBit(int num, int pos) {
   /* TODO: implement */
   // xor w/ 0 leaves it unchanged, xor w/ 1 flips the bit
   int mask = 1 << pos;
   num = num ^ mask;
   return num;
}

/*
* Return the position of the most significant set bit
* Return -1 if num == 0
*/
int GetMSB(int num) {
   /* TODO: implement */
   if(num == 0) return -1;
   int pos = 0;
   for(int i = 0; i < 32;i++){
      int mask = 1 << i;
      int isOne = num & mask;
      if(isOne){
         pos = i;
      }
   }
   return pos;
}

/*
* Clear bits from start to end (inclusive)
*/
int ClearBitRange(int num, int start, int end) {
   /* TODO: implement */
   if(start > end || start < 0 || end > 31){
      return num;
   }
   
   int width = end - start + 1;
   int rangeMask = ((1 << width) - 1) << start;
   // 1 << width: moves 1 bit (range amount of space)
   // minus 1, makes all right zeros from 1 (ones) 0100 -> 0011
   // << start, pushes the group of 1s to the correct range location 
   
   num = num & ~(rangeMask)
   // x and 0 = 0 (clears)
   // x and 1 = x (keeps)

   return num;
}

/*
* Rotate num to the left by d bits
*/
int RotateLeft(int num, int d) {
   /* TODO: implement */
   // handles negative number (makes sure its not signed)
   unsigned int x = (unsigned int) num;
   // handles the case of d being greater than 32 (ex:33 becomes 1)
   d = d % 32;

   if(d==0) return num;

   unsigned int leftPart = x << d;
   unsigned int wrapNumbers = x >> (32 - d);

   num = leftPart | wrapNumbers;
   return num;
}

/*
* Swap odd and even bits
*/
int SwapOddEvenBits(int num) {
   /* TODO: implement */
   unsigned int x = (unsigned int) num;

   unsigned int even = x & 0x55555555;
   unsigned int odd = x & 0xAAAAAAAA;

   even = even << 1;
   odd = odd >> 1;

   num = even | odd;

   return num;
}
