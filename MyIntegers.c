#include "MyIntegers.h"
#include <stdio.h>
#include <stdbool.h>

void repr_convert(char source_repr, char target_repr, unsigned int repr) {

   /*
    * TODO:
    * 1. Validate source_repr and target_repr
    * 2. Decode the source representation
    * 3. Convert to target representation
    * 4. Print the result or error message
    */
    bool sourceIsVald = source_repr == '2' || source_repr == 'S';
    bool targetIsVald = target_repr == '2' || target_repr == 'S';
    if(!sourceIsVald || !targetIsVald){
        printf("error\n");
        return;
    } 

    //decode

    int value = (int)repr;

    if(source_repr == 'S'){
        int sign = (int)((repr >> 31) & 1);
        int magnitude = (int)(repr & 0x7FFFFFFF);

        if(sign){
            value = -magnitude;
        } else {
            value = magnitude;
        }
    }

    //encode

    unsigned int out;

    if (target_repr == '2') {
        out = (unsigned int)value;
        printf("%08x\n", out);
        return;
    }

    if(value == (int)0x80000000){
        printf("undefined\n");
        return;
    } 

    unsigned int signBit = (value < 0) ? 1u : 0u;
    unsigned int magnitude = (value < 0) ? (unsigned int)(-value) : (unsigned int)value;

    out = (signBit << 31) | magnitude;

    printf("%08x\n", out);
}
