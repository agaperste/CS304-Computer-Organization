/*
 * CS:APP Data Lab
 *
 * <Yingzhu Zhang, yzhang21>
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
/*
 * bitAnd - x&y using only ~ and |
 *   Example: bitAnd(6, 5) = 4
 *   Legal ops: ~ |
 *   Max ops: 8
 *   Rating: 1
 */
int bitAnd(int x, int y) {
    /* bitwise OR the bitwise NOTed x and y, then bitwise NOT the result */
    return ~(~x | ~y);
}
/*
 * copyLSB - set all bits of result to least significant bit of x
 *   Example: copyLSB(5) = 0xFFFFFFFF, copyLSB(6) = 0x00000000
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int copyLSB(int x) {
    /* left shift the LSB to be the MSB, thus discarding all other existing
     bits,then right shift that bit back (all under the assumption of
     32-bit representation) */
    int to_ret = (x<<31)>>31;
    return to_ret;
}
/*
 * getByte - Extract byte n from word x
 *   Bytes numbered from 0 (LSB) to 3 (MSB)
 *   Examples: getByte(0x12345678,1) = 0x56
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int getByte(int x, int n) {
    /*
     00000001 00100011 01000101 0110 0111
     &                     1111 1111
     =                     0101 0110
     right shift x n position, then bitwise
     AND the result */
    int shift = n<<3;
    int ret = x>>shift;
    int to_ret = ret & 0xFF;
    return to_ret;
}
/*
 * isEqual - return 1 if x == y, and 0 otherwise
 *   Examples: isEqual(5,5) = 1, isEqual(4,5) = 0
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 5
 *   Rating: 2
 */
int isEqual(int x, int y) {
    /* first bitwise XOR x and y, then logical NOT the result */
    int to_ret = !(x^y);
    return to_ret;
}
/*
 * bitMask - Generate a mask consisting of all 1's
 *   lowbit and highbit
 *   Examples: bitMask(5,3) = 0x38
 *   Assume 0 <= lowbit <= 31, and 0 <= highbit <= 31
 *   If lowbit > highbit, then mask should be all 0's
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 16
 *   Rating: 3
 */
int bitMask(int highbit, int lowbit) {
    /* create 2 masks and exploit function of -1.
     First get a base by getting all 1s in through
     neg1; then get the highbit mask by left shift neg1
     highbit's positions plus one more (reserved for the
     mask); then get the lowbit mask by left shift neg1
     lowbit's position. Finally manipulate to get the
     correct bits on the lowerbit part.   */
    int neg1 = ~0;
    int mask_high = (neg1<<highbit)<<1;
    int mask_low = (neg1<<lowbit);
    int to_ret = (mask_high ^ mask_low) & mask_low;
    return to_ret;
}
/*
 * reverseBytes - reverse the bytes of x
 *   Example: reverseBytes(0x01020304) = 0x04030201
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 25
 *   Rating: 3
 */
int reverseBytes(int x) {
    /* extract each byte, then move them to their positions of
     reverse order, finally concatenate all the bytes*/
    int b1 = (x>>24) & 255;
    int b2 = (x&(255<<16))>>8;
    int b3 = (x&(255<<8))<<8;
    int b4 = (x&255)<<24;
    int to_ret = b1+b2+b3+b4;
    return to_ret;
}
/*
 * bang - Compute !x without using !
 *   Examples: bang(3) = 0, bang(0) = 1
 *   Legal ops: ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 4
 */
int bang(int x) {
    /* exploiting arithmetic right shift, and keeping in mind that
     when x==0, x and -x are both nonnegative:
     bitwise OR x and -x, then bitwise NOT the result,
     then right shift 31 bits, finally bitwise AND 1 */
    int to_ret = ~((~x+1) | x) >>31 &1;
    return to_ret;
}
/*
 * leastBitPos - return a mask that marks the position of the
 *               least significant 1 bit. If x == 0, return 0
 *   Example: leastBitPos(96) = 0x20
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int leastBitPos(int x) {
    /* bitwise AND x and -x;
     because when x==0, x and -x are both nonnegative,
     function will return 0 */
    int to_ret = x & (~x+1);
    return to_ret;
}
/*
 * minusOne - return a value of -1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 2
 *   Rating: 1
 */
int minusOne(void) {
    /* bitwise NOT the number 0 will get us all 1s,
     and in two's complement, all 1s is -1. */
    int to_ret = ~0;
    return to_ret;
}
/*
 * TMax - return maximum two's complement integer
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 4
 *   Rating: 1
 */
int tmax(void) {
    /* tmax = 0x7fff ffff = 0..111 (32 bits)
     therefore left shift binary 1 31 pos,
     then bitwise NOT the result */
    
    int to_ret = ~(1<<31);
    return to_ret;
}
/*
 * fitsBits - return 1 if x can be represented as an
 *  n-bit, two's complement integer.
 *   1 <= n <= 32
 *   Examples: fitsBits(5,3) = 0, fitsBits(-4,3) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 2
 */
int fitsBits(int x, int n) {
    /* if x can be represented as an n-bit, two's complement int,
     its complement will return a negative number if added
     to the smallest possible number that can be represented by
     an n-bit number */
    
    int minus_1 = ~0;
    int leftmost = minus_1<<(n+minus_1);
    int complement = x^(x>>31);
    int to_ret = ((leftmost + complement) >> 31) & 1;
    return to_ret;
}
/*
 * addOK - Determine if can compute x+y without overflow
 *   Example: addOK(0x80000000,0x80000000) = 0,
 *            addOK(0x80000000,0x70000000) = 1,
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 20
 *   Rating: 3
 */
int addOK(int x, int y) {
    /* The overflow occurs when x and y have the same sign while
     the sum of x and y have a different sign.
     First separaqte x and y, then if
     when x, y = 0, sum != 1
     or, when x and y = 1, sum = 0,
     return 1 for not overflow */
    
    int temp = (x + y) >> 31;
    int x_after = x >> 31;
    int y_after = y >> 31;
    int to_ret = !!(~temp | x_after | y_after) & (temp | ~x_after | ~y_after);
    return to_ret;
}
/*
 * isGreater - if x > y  then return 1, else return 0
 *   Example: isGreater(4,5) = 0, isGreater(5,4) = 1
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 24
 *   Rating: 3
 */
int isGreater(int x, int y) {
    /* First get the sign of x and y,
     if the signs are the same:
     if x>y, sign bit of (~y+x)=0,
     if x<y, sign bit of (~y+x)=1;
     if the signs are not equal:
     if x>y, sign bit of (~y+x)=1,
     if x<y, sign bit of (~y+x)=0;
     lastly, bitwise OR and logical NOT
     the results from two if conditions */
    int sign_x = x>>31;
    int sign_y = y>>31;
    int same = !(sign_x ^ sign_y) & ((~y + x) >> 31);
    int not_same = sign_x & !sign_y;
    int to_ret = !(same | not_same);
    return to_ret;
}
/*
 * isNegative - return 1 if x < 0, return 0 otherwise
 *   Example: isNegative(-1) = 1.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 6
 *   Rating: 2
 */
int isNegative(int x) {
    /* right shift 31 positions the sign bit of x,
     then plus the number 1;
     if the result is neg, ~result = 1;
     if the result is pos, ~result = 0 */
    int to_ret = !((x>>31)+1);
    return to_ret;
}
/*
 * multFiveEighths - multiplies by 5/8 rounding toward 0.
 *   Should exactly duplicate effect of C expression (x*5/8),
 *   including overflow behavior.
 *   Examples: multFiveEighths(77) = 48
 *             multFiveEighths(-22) = -13
 *             multFiveEighths(1073741824) = 13421728 (overflow)
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 12
 *   Rating: 3
 */
int multFiveEighths(int x) {
    /* left shift 2 bits for mult,
     then adjusting the quotient, in case of neg,
     lastl right right 3 for div */
    int mult = x + (x<<2);
    int sign_x = mult>>31;
    int adj = mult+ (7 & sign_x);
    int to_ret = adj>>3;
    return to_ret;
}
/*
 * sm2tc - Convert from sign-magnitude to two's complement
 *   where the MSB is the sign bit
 *   Example: sm2tc(0x80000005) = -5.
 *   Legal ops: ! ~ & ^ | + << >>
 *   Max ops: 15
 *   Rating: 4
 */
int sm2tc(int x) {
    /* if x >= 0, then msb of x = 0:
     do nothing;
     else:
     reverse complement the negative */
    int sign_x = x>>31;
    int sm = sign_x<<31;
    int to_ret = sm + (x ^ sign_x) + (sign_x & 1);
    return to_ret;
}
/*
 * float_i2f - Return bit-level equivalent of expression (float) x
 *   Result is returned as unsigned int, but
 *   it is to be interpreted as the bit-level representation of a
 *   single-precision floating point values.
 *   Legal ops: Any integer/unsigned operations incl. ||, &&. also if, while
 *   Max ops: 30
 *   Rating: 4
 */
unsigned float_i2f(int x) {
    /* sign_bit = 0 or 1, E = exp+127, frac = 23 bits of x */
    
    unsigned sign_bit, frac, exponent = 150;
    unsigned temp, b = 2;
    unsigned hi, lo;
    
    if (x == 0) return 0;
    
    sign_bit = (x & 0x80000000);
    frac = (sign_bit) ? (-x) : (x);
    temp = frac;
    while (temp & 0xff000000) {
        /* standard rounding */
        temp = (frac + (b / 2)) / (b);
        b <<= 1;
        exponent++;
    }
    while (temp <= 0x007fffff) {
        temp <<= 1;
        exponent--;
    }
    if (frac & 0xff000000) {
        b = 1 << (exponent - 150);
        
        temp = frac / b;
        lo = frac % b;
        hi = b - lo;
        
        /* if temp is closer to fraction/b than fraction/b + 1, or its odd,
         round up */
        if ((hi < lo) || ((hi == lo) & temp))
            ++temp;
        
        frac = temp;
    } else {
        while (frac <= 0x007fffff)
            frac <<= 1;
    }
    
    return (sign_bit) | (exponent << 23) | (frac & 0x007fffff);
    
}
