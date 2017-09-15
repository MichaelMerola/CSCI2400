/*
 * CS:APP Data Lab
 *
 * Michael Merola mime4339
 *
 * bits.c - Source file with your solutions to the Lab.
 *          This is the file you will hand in to your instructor.
 *
 * WARNING: Do not include the <stdio.h> header; it confuses the dlc
 * compiler. You can still use printf for debugging without including
 * <stdio.h>, although you might get a compiler warning. In general,
 * it's not good practice to ignore compiler warnings, but in this
 * case it's OK.
 */

#if 0
/*
 * Instructions to Students:
 *
 * STEP 1: Read the following instructions carefully.
 */

You will provide your solution to the Data Lab by
editing the collection of functions in this source file.

INTEGER CODING RULES:

  Replace the "return" statement in each function with one
  or more lines of C code that implements the function. Your code
  must conform to the following style:

  int Funct(arg1, arg2, ...) {
      /* brief description of how your implementation works */
      int var1 = Expr1;
      ...
      int varM = ExprM;

      varJ = ExprJ;
      ...
      varN = ExprN;
      return ExprR;
  }

  Each "Expr" is an expression using ONLY the following:
  1. Integer constants 0 through 255 (0xFF), inclusive. You are
      not allowed to use big constants such as 0xffffffff.
  2. Function arguments and local variables (no global variables).
  3. Unary integer operations ! ~
  4. Binary integer operations & ^ | + << >>

  Some of the problems restrict the set of allowed operators even further.
  Each "Expr" may consist of multiple operators. You are not restricted to
  one operator per line.

  You are expressly forbidden to:
  1. Use any control constructs such as if, do, while, for, switch, etc.
  2. Define or use any macros.
  3. Define any additional functions in this file.
  4. Call any functions.
  5. Use any other operations, such as &&, ||, -, or ?:
  6. Use any form of casting.
  7. Use any data type other than int.  This implies that you
     cannot use arrays, structs, or unions.


  You may assume that your machine:
  1. Uses 2s complement, 32-bit representations of integers.
  2. Performs right shifts arithmetically.
  3. Has unpredictable behavior when shifting an integer by more
     than the word size.

EXAMPLES OF ACCEPTABLE CODING STYLE:
  /*
   * pow2plus1 - returns 2^x + 1, where 0 <= x <= 31
   */
  int pow2plus1(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     return (1 << x) + 1;
  }

  /*
   * pow2plus4 - returns 2^x + 4, where 0 <= x <= 31
   */
  int pow2plus4(int x) {
     /* exploit ability of shifts to compute powers of 2 */
     int result = (1 << x);
     result += 4;
     return result;
  }

FLOATING POINT CODING RULES

For the problems that require you to implent floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants.

You are expressly forbidden to:
  1. Define or use any macros.
  2. Define any additional functions in this file.
  3. Call any functions.
  4. Use any form of casting.
  5. Use any data type other than int or unsigned.  This means that you
     cannot use arrays, structs, or unions.
  6. Use any floating point data types, operations, or constants.


NOTES:
  1. Use the dlc (data lab checker) compiler (described in the handout) to
     check the legality of your solutions.
  2. Each function has a maximum number of operators (! ~ & ^ | + << >>)
     that you are allowed to use for your implementation of the function.
     The max operator count is checked by dlc. Note that '=' is not
     counted; you may use as many of these as you want without penalty.
  3. Use the btest test harness to check your functions for correctness.
  4. Use the BDD checker to formally verify your functions
  5. The maximum number of ops for each function is given in the
     header comment for each function. If there are any inconsistencies
     between the maximum ops in the writeup and in this file, consider
     this file the authoritative source.

/*
 * STEP 2: Modify the following functions according the coding rules.
 *
 *   IMPORTANT. TO AVOID GRADING SURPRISES:
 *   1. Use the dlc compiler to check that your solutions conform
 *      to the coding rules.
 *   2. Use the BDD checker to formally verify that your solutions produce
 *      the correct answers.
 */


#endif
/* Copyright (C) 1991-2016 Free Software Foundation, Inc.
   This file is part of the GNU C Library.

   The GNU C Library is free software; you can redistribute it and/or
   modify it under the terms of the GNU Lesser General Public
   License as published by the Free Software Foundation; either
   version 2.1 of the License, or (at your option) any later version.

   The GNU C Library is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
   Lesser General Public License for more details.

   You should have received a copy of the GNU Lesser General Public
   License along with the GNU C Library; if not, see
   <http://www.gnu.org/licenses/>.  */
/* This header is separate from features.h so that the compiler can
   include it implicitly at the start of every compilation.  It must
   not itself include <features.h> or any other header that includes
   <features.h> because the implicit include comes before any feature
   test macros that may be defined in a source file before it first
   explicitly includes a system header.  GCC knows the name of this
   header in order to preinclude it.  */
/* glibc's intent is to support the IEC 559 math functionality, real
   and complex.  If the GCC (4.9 and later) predefined macros
   specifying compiler intent are available, use them to determine
   whether the overall intent is to support these features; otherwise,
   presume an older compiler has intent to support these features and
   define these macros by default.  */
/* wchar_t uses Unicode 8.0.0.  Version 8.0 of the Unicode Standard is
   synchronized with ISO/IEC 10646:2014, plus Amendment 1 (published
   2015-05-15).  */
/* We do not support C11 <threads.h>.  */


/*
 * evenBits - return word with all even-numbered bits set to 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 8
 *   Rating: 1
 */
int evenBits(void) { //COMPLETE

    /*
        Represent an alternating binary number in hexadecimal
        Binary: 0101 0101 0101 0101 0101 0101 0101 0101
        Hex: 0x55555555

        Shift 0x55 left and add ox55 to get complete 4 byte integer
    */

    int word =  0x55; // 0x00000055

    word = word << 8;
    word = word + 0x55; //0x00005555

    word = word << 8;
    word = word + 0x55; //0x00555555

    word = word << 8;
    word = word + 0x55; //0x55555555

    return word;
}


/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) { //COMPLETE
    /*
        Represent a negative 1 in hexadecimal

        Binary 1: 0001
        Binary -1: 1111 (using two's complement)
        hexadecimal -1: -0x1
    */

    int word = -0x1;

    return word;
}


/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) { //COMPLETE
    /*
        0x-- -- -- -[LSB]

        Left shift LSB to the first position (0x[LSB]- -- -- --)

        Right shift back to the original position
        Arithmetic shift fills in space with the [LSB]
    */

    int word;
    word = x << 31;

    word = word >> 31;

    return word;
}


/*
 * divpwr2 - Compute x/(2^n), for 0 <= n <= 30
 *   Round toward zero
 *   Examples: divpwr2(15,1) = 7, divpwr2(-33,4) = -2
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int divpwr2(int x, int n) { //COMPLETE
    /*
        Right shifting x by 1 will divide the number by 2^1
        In this case, replace 1 with n

        To round down, we must mask the number to hide any negative MSB
        Use f to floor the number in the correct direction.
        Masking the number will return a 0 if x is positive or 1 if negative

        Add x to floor variable, then perform divide operation.
    */

    int mask = x >> 31;
    int f = ((1 << n) - 1) & mask;

    x = x + f;

    int divide = x >> n;

    return divide;
}


/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) { //COMPLETE
    /*
        Need to shift desired byte to LSB position

        Because n is in byte units, convert to bit units by multiplication
        Use << 3 to multiply by 8

        Shift x to put desired byte at LSB

        Mask x with 0xff (1111 1111) to leave only LSB
    */

    int convert = n << 3;
    n = convert;

    x = x >> n;

    int word = x & 0xff;

    return word;
}


/*
 * anyOddBit - return 1 if any odd-numbered bit in word set to 1
 *   Examples anyOddBit(0x5) = 0, anyOddBit(0x7) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int anyOddBit(int x) { //COMPLETE
    /*
        Create a mask to only include odd numbers
        Binary: 1010 1010 ...
        Hex: 0xAA AA ..

        Use & operator to apply mask
        Check byte at every odd position

        Add all lefovers. Use double !! to reduce number to either 1 or 0 and return
    */

    int mask = 0xAA;

    int byte1 = x & mask;
    int byte3 = (x >> 8) & mask; //shift to next odd bit
    int byte5 = (x >> 16) & mask;
    int byte7 = (x >> 24) & mask;

    int total = byte1 + byte3 + byte5 + byte7;

    return !(!total);
}


/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) { //COMPLETE
    /*
        If the MSB is negative than the number is negative..

        Right shift x to place MSB -> LSB

        Mask by 0xff to remove the leading bits
        Should leave (0000 0000) or (1111 1111)

        Use !! to equate final int to either a 1 or 0
    */

    int r = x >> 31;

    int mask = 0xff;
    int word = r & mask;

    return !(!word);
}


/*
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) { //COMPLETE
    /*
        Check the left and right bounds of x by subtraction.

        left bound is x - 29
        if true, x should be > 0

        right bound is x - 40
        if true, x should be < 0

        mask bits to check for negative and ! to clear
        return total, 1 is true and 0 is false
    */

    int l = 0x2f;
    int left = x + (~l + 1);
    left = !(left & 0xff);


    int r = 0x3a;
    int right = x + (~r + 1);
    right = !(right & 0xff);

    int total = left + right;

    return total;
}


/*
 * fitsBits - return 1 if x can be represented as an
 *   n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int fitsBits(int x, int n) { //COMPLETE
    /*
        x fits in n if the bits left of position n-1 have a value equal to
        the bit at n-1..

        remain == high-significance bits - low-significance bits

        shift x to the right to fill bits with MSB

        check if bits is equal to x. 1 is true.

    */

    int remain = 33 + ~n;

    int bits = ((x << remain) >> remain);

    int total = !(bits ^ x);

    return total;
}


/*
 * subOK - Determine if can compute x-y without overflow
 *   Example: subOK(0x80000000,0x80000000) = 1,
 *            subOK(0x80000000,0x70000000) = 0,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int subOK(int x, int y) { //COMPLETE
    /*
        overflow of sub happens when..
        if : x and y have different signs
        if : x - y has different sign with x

        compare signs of x and y

        compare sign of x-y to x

    */

    int same = x ^ y;

    int diff = x + (~y + 1); //x-y
    int comp = diff ^ x;

    int total = ((same & comp) >> 31);

    return !total;
}


/*
 * conditional - same as x ? y : z
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) { //COMPLETE
    /*
        if (x == 1)
            return y
        else
            return z


        check if x is a 0 or 1

        create a mask to filter through y and z

        depending on x value, either Y or Z will evaluatre to zero and
        not be added to the final return statement

    */

    int checkx = !!x;

    int mask = ~checkx + 1;

    int passY = mask & y;
    int passZ = ~mask & z;

    return passY + passZ;

}


/* howManyBits - return the minimum number of bits required to represent x in
 *             two's complement
 *  Examples: howManyBits(12) = 5
 *            howManyBits(298) = 10
 *            howManyBits(-5) = 4
 *            howManyBits(0)  = 1
 *            howManyBits(-1) = 1
 *            howManyBits(0x80000000) = 32
 *  Legal ops: ! ~ & ^ | + << >>
 *  Max ops: 90
 *  Rating: 4
 */
int howManyBits(int x) {

    

    return 2;
}


/*
 * isNonZero - Check whether x is nonzero using
 *              the legal operators except !
 *   Examples: isNonZero(3) = 1, isNonZero(0) = 0
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int isNonZero(int x) { //COMPLETE
    /*
        the complement of every binary number has the opposite sign of the original
        therefore, if we take the complement, the MSB will be the ~sign of the number

        place the leading bit into the LSB position

        create mask to eliminate leading terms
    */

    int negX = (~x + 1);
    int c = x | negX;

     c = c >> 31;

     int mask = 0x1;
     int total = c & mask;

     return total;
}


/*
 * absVal - absolute value of x
 *   Example: absVal(-1) = 1.
 *   You may assume -TMax <= x <= TMax
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 10
 *   Rating: 4
 */
int absVal(int x) { //COMPLETE
    /*
        Translate negative numbers to positive so they represent magnitude without sign

        Right shift x so the MSB is in the LSB position to create a mask
            either (00000000) or (11111111)

        Use xor operator to inverse the integer
        Results in abs value of original integer
    */

    int mask = x >> 31;
    int word = x + mask;

    word = word ^ mask;

    return word;
}


/*
 * isPower2 - returns 1 if x is a power of 2, and 0 otherwise
 *   Examples: isPower2(5) = 0, isPower2(8) = 1, isPower2(0) = 0
 *   Note that no negative number is a power of 2.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 4
 */
int isPower2(int x) { //COMPLETE
    /*
        An integer with 32 bits is a power of 2..

        left shift so LSB becomes MSB and then right shift to fill bits with MSB
            fills 1s if nonzero, 0 if zero

        neg or one should make a (00000001) if nonzero, or all 1s

    */

    int shift = (!x << 31) >> 31;

    int neg = (x & (~x + 1));
    int one = (0x01 << 31);

    int total = (~neg | one) & x;

    return (!total) & (~shift);
}
