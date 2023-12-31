/* 
 * CS:APP Data Lab 
 * 
 * <邱玉柱 212100811>
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
  3. Has unpredictable behavior when shifting if the shift amount
     is less than 0 or greater than 31.


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

For the problems that require you to implement floating-point operations,
the coding rules are less strict.  You are allowed to use looping and
conditional control.  You are allowed to use both ints and unsigneds.
You can use arbitrary integer and unsigned constants. You can use any arithmetic,
logical, or comparison operations on int or unsigned data.

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
  2. Each function has a maximum number of operations (integer, logical,
     or comparison) that you are allowed to use for your implementation
     of the function.  The max operator count is checked by dlc.
     Note that assignment ('=') is not counted; you may use as many of
     these as you want without penalty.
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
//1
/* 
 * bitXor - x^y using only ~ and & 
 *   Example: bitXor(4, 5) = 1
 *   Legal ops: ~ &
 *   Max ops: 14
 *   Rating: 1
 */
int bitXor(int x, int y) {
    int t1 = x & y;
    int t2 = ~x & ~y;
    return ~t1 & ~t2;
}
/* 
 * tmin - return minimum two's complement integer 
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmin(void) {
  return 1 << 31;
}
//2
/*
 * isTmax - returns 1 if x is the maximum, two's complement number,
 *     and 0 otherwise 
 *   Legal ops: ! ~ & ^ | +
 *   Max ops: 10
 *   Rating: 1
 */
int isTmax(int x) {
    int p = x + 2 + x ;
    return !p & (!!(x + 1));
}
/* 
 * allOddBits - return 1 if all odd-numbered bits in word set to 1
 *   where bits are numbered from 0 (least significant) to 31 (most significant)
 *   Examples allOddBits(0xFFFFFFFD) = 0, allOddBits(0xAAAAAAAA) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 2
 */
int allOddBits(int x) {
    int e = (0xAA << 8) + 0xAA;
    int e2 = (e << 16) + e;
    int p = e2 & x;
    return !((~e2 | p) + 1);
}
/* 
 * negate - return -x 
 *   Example: negate(1) = -1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int negate(int x) {
  return ~x + 1;
}
//3
/* 
 * isAsciiDigit - return 1 if 0x30 <= x <= 0x39 (ASCII codes for characters '0' to '9')
 *   Example: isAsciiDigit(0x35) = 1.
 *            isAsciiDigit(0x3a) = 0.
 *            isAsciiDigit(0x05) = 0.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 3
 */
int isAsciiDigit(int x) {
    int p1 = 0x30;
    int d1 = ~p1 + 1;

    int p2 = 0x39 + 1;
    int d2 = ~p2  + 1;

    int e1 = !((x + d1) >> 31);
    int e2 = (x + d2) >> 31;
    return e1 & e2;
}
/* 
 * conditional - same as x ? y : z 
 *   Example: conditional(2,4,5) = 4
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int conditional(int x, int y, int z) {
    int e = !!x;
    int e2 = (e << 31) >> 31;
    int e3 = ~e2;
    return (e2 & y) + (e3 & z);
}
/* 
 * isLessOrEqual - if x <= y  then return 1, else return 0 
 *   Example: isLessOrEqual(4,5) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isLessOrEqual(int x, int y) {
    int f1 = x >> 31 & 1;
    int f2 = y >> 31 & 1;
    int e = ~(y) + 1;
    int e3 = x + e;
    int e4 = e3 >> 31 & 1;
    int e1 = (f1 ^ 0) & (f2 ^ 1);
    int e2 = !((f1 ^ 1) & (f2 ^ 0));
    return e2 & (e1 | e4 | !(x ^ y));
}
//4
/* 
 * logicalNeg - implement the ! operator, using all of 
 *              the legal operators except !
 *   Examples: logicalNeg(3) = 0, logicalNeg(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4 
 */
int logicalNeg(int x) {
    int e1 = ((x) >> 31) ^ 1;
    int e2 = (x + ~0) >> 31;
    return e1 & e2 & 1;
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
int howManyBits(int x) { // pretend bisection(binary) find
    int e1 = ~(x >> 31);
    int e2 = (~(x ^ e1));
    int x1 = e2;
    // example : 00001000 00000000   // two byte
    int d1 = x1 & 0xFF;//0+
    int x2 = x1 >> 8;
    int d2 = x2 & 0xFF;//8+
    int x3 = x2 >> 8;
    int d3 = x3 & 0xFF;//16+
    int x4 = x3 >> 8;
    int d4 = x4 & 0xFF; // 24+

    int d4f = ((!!d4 << 31) >>31);
    int p10 = d4f & 24;
    int p11 = p10 + ((!p10 << 31) >> 31 & ((!d3 << 4) ^ 16 ));
    int p12 = p11 + ((!p11 << 31) >> 31 & ((!d2 << 3) ^ 8 ));
    int p1 = p12;
    //p1 = (!p1 << 31) >> 31 & ((!!d1 << 31) >> 31 ) & 0;

    // get have 1 byte that high 8 bite
    int b1 = d4f & d4;
    int b2 = (((!b1 << 31) >> 31) & d3) | b1;
    int b3 = (((!b2 << 31) >> 31) & d2) | b2;
    int b4 = (((!b3 << 31) >> 31) & d1) | b3;
    int b = b4;

    int d5 = b & 0xF; //0+
    int bb = b >> 4;
    int d6 = bb & 0xF;//4+

    int d6f = ((!!d6 << 31) >>31);
    int p2 = d6f &  4;
    //p2 = (!p2 << 31) >> 31 & (!!d1 << 31) >> 31 & 0

    int b5 = d6f & d6;
    int b6 = (((!b5 << 31) >> 31) & d5) | b5;

    int p30 = (b6 >> 1) & 4;
    int p31 = p30 + ((!p30 << 31) >> 31 & (((b6 & 4) << 29) >> 31) & 3);
    int p32 = p31 + ((!p31 << 31) >> 31 & b6 & 2);
    int p33 = p32 + ((!p32 << 31) >> 31 & b6 & 1);
    int p3 = p33;

    return p1 + p2 + p3 + 1;
}
//float
/* 
 * floatScale2 - Return bit-level equivalent of expression 2*f for
 *   floating point argument f.
 *   Both the argument and result are passed as unsigned int's, but
 *   they are to be interpreted as the bit-level representation of
 *   single-precision floating point values.
 *   When argument is NaN, return argument
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned floatScale2(unsigned uf) {
    // 32 bite 0 0000000 0 0000000 00000000 00000000
    int dw = (uf & 0x7FFFFF) << 1;
    int j = uf & 0x7F800000;
    int jj = 0x800000;
    int f = uf & 0x80000000;
    if(!((j ^ 0x7F800000) << 1)){ // +- INF
        return uf;
    }
    if( !j && !!(dw & 0x800000) ){ // exponent is zero that represent 非规格化
        j += jj;
        dw &= 0x7FFFFFFF;
    } else if(j){
        j += jj;
        dw >>= 1;
    }
    return f | dw | j;
}
/* 
 * floatFloat2Int - Return bit-level equivalent of expression (int) f
 *   for floating point argument f.
 *   Argument is passed as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point value.
 *   Anything out of range (including NaN and infinity) should return
 *   0x80000000u.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
int floatFloat2Int(unsigned uf) {
    int w = (uf & 0x7FFFFF )| 0x800000;
    int j = (uf & 0x7F800000) >> 23;
    int f = uf & 0x80000000;
    int p = j - 126;
    int y = p - 24;
    if(!j || (p & 0x80000000)){// 非规格化，且为0 或者是太小的数
        return 0;
    }
    if(((p - 31) >> 31) == 0){ // out range
        return 0x80000000u;
    }
    if(y < 0){//more than real result ,so require >>
        int ret = w >> -y;
        if(f){
            return -ret;
        }
        return ret;
    }
    //normal operation
    return (w << y) | f;
}
/* 
 * floatPower2 - Return bit-level equivalent of the expression 2.0^x
 *   (2.0 raised to the power x) for any 32-bit integer x.
 *
 *   The unsigned value that is returned should have the identical bit
 *   representation as the single-precision floating-point number 2.0^x.
 *   If the result is too small to be represented as a denorm, return
 *   0. If too large, return +INF.
 * 
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. Also if, while 
 *   Max ops: 30 
 *   Rating: 4
 */
unsigned floatPower2(int x) {
    if(x <= -127){
        return 0;
    }
    if(x >= 128){
        return 0x7f800000;
    }
    return (x + 127) << 23;
}
