#include <criterion/criterion.h>
#include "MyBitManipulation.h"
#include "Myfloat.h"
#include "MyIntegers.h"

/* =========================
* PART 1: Bit Manipulation
* ========================= */

Test(ToggleBit, examples) {
   cr_assert_eq(ToggleBit(9, 0), 8);
   cr_assert_eq(ToggleBit(9, 3), 1);

   // student test 
   // cr_assert_eq(ToggleBit(0, 5), 32);
   // cr_assert_eq(ToggleBit(-8, 3), -16);
   // cr_assert_eq(ToggleBit(1, 0), 0);

   // unsure about test pos > 31 , since I was unsure to just return number since pos is nonexistent or use %
}

Test(GetMSB, examples) {
   cr_assert_eq(GetMSB(18), 4);
   cr_assert_eq(GetMSB(0), -1);

   // student test 
   // cr_assert_eq(GetMSB(31), 4); 
   // cr_assert_eq(GetMSB(1024), 10); 
   // cr_assert_eq(GetMSB(16), 4);
}

Test(ClearBitRange, examples) {
   cr_assert_eq(ClearBitRange(73, 1, 3), 65);

   // student test 
   // cr_assert_eq(ClearBitRange(73, 3, 1), 73);   start > end
   // cr_assert_eq(ClearBitRange(73, 3, 3), 65);   One bit clear
   // cr_assert_eq(ClearBitRange(73, 0, 31), 0);   clear all bits
}

Test(RotateLeft, examples) {
   cr_assert_eq(RotateLeft(5, 1), 10);
   cr_assert_eq(RotateLeft(5, 2), 20);

   //student test 
   // cr_assert_eq(RotateLeft(5, 33), 10);    d > 31
   // cr_assert_eq(RotateLeft(5, 0), 5);      no rotation
   // cr_assert_eq(RotateLeft(-8, 1), -15);   negative number
}

Test(SwapOddEvenBits, examples) {
   cr_assert_eq(SwapOddEvenBits(23), 43);

   // student test
   // cr_assert_eq(SwapOddEvenBits(1), 2);
   // cr_assert_eq(SwapOddEvenBits(0), 0);     all zeros
   // cr_assert_eq(SwapOddEvenBits(-1), -1);   all ones and also negative number
}

/* =========================
* PART 2: IEEE 754 Float
* ========================= */

Test(ConstructFloat, positive_examples) {
   float f = construct_float_sf(0x00, 0x7F, 0x200000);
   cr_assert_float_eq(f, 1.25, 0.00001);
}

Test(ConstructFloat, negative_examples) {
   float f = construct_float_sf(0x01, 0x7F, 0x200000);
   cr_assert_float_eq(f, -1.25, 0.00001);
}

/* Student test */

/*
Test(ConstructFloat, positive_5_5) {
   float f = construct_float_sf(0x00, 0x81, 0x300000);
   cr_assert_float_eq(f, 5.5, 0.00001);
}

Test(ConstructFloat, negative_5_5) {
   float f = construct_float_sf(0x01, 0x81, 0x300000);
   cr_assert_float_eq(f, -5.5, 0.00001);
}

Test(ConstructFloat, positive_1_25) {
   float f = construct_float_sf(0x00, 0x7F, 0x200000);
   cr_assert_float_eq(f, 1.25, 0.00001);
}

Test(ConstructFloat, negative_1_25) {
   float f = construct_float_sf(0x01, 0x7F, 0x200000);
   cr_assert_float_eq(f, -1.25, 0.00001);
}

Test(ConstructFloat, positive_small) {
   float f = construct_float_sf(0x00, 0x76, 0x299B6F);
   cr_assert_float_eq(f, 0.002588, 0.0000005);
}

Test(ConstructFloat, negative_small) {
   float f = construct_float_sf(0x01, 0x76, 0x299B6F);
   cr_assert_float_eq(f, -0.002588, 0.0000005);
}

Test(ConstructFloat, positive_1374) {
   float f = construct_float_sf(0x00, 0x89, 0xABCDEF);
   cr_assert_float_eq(f, 1374.44, 0.01);
}

Test(ConstructFloat, negative_1374) {
   float f = construct_float_sf(0x01, 0x89, 0xABCDEF);
   cr_assert_float_eq(f, -1374.44, 0.01);
}

Test(ConstructFloat, positive_large) {
   float f = construct_float_sf(0x00, 0x90, 0x7973C0);
   cr_assert_float_eq(f, 255439.0, 0.5);
}

Test(ConstructFloat, negative_large) {
   float f = construct_float_sf(0x01, 0x90, 0x7973C0);
   cr_assert_float_eq(f, -255439.0, 0.5);
}
*/


/* =========================
* PART 3: Integer Conversion
* ========================= */
/* NOTE:
* We do NOT test output matching here.
* Students are encouraged to visually inspect output.
* TAs will use stronger hidden tests.
*/

Test(ReprConvert, basic_run) {
   repr_convert('2', '2', 0x59f2ca50);
   repr_convert('S', '2', 0x80000000);

   // student test
   // repr_convert('S', '2', 0x80000001);
   // repr_convert('S', '2', 0x80000000);
   // repr_convert('2', '2', 0x59f2ca50);
   // repr_convert('F', '2', 0x00394812);
   // repr_convert('2', 'S', 0x80000000);
}


