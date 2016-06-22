//author: Yingzhu Zhang

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int count, c;

    printf("Input: ");
    count = 0;
    c = getchar();

    /* debug
    printf("Initial char is %c\n", c);
    */

    //strip all the white spaces preceding the first word
    while (c ==32) {
        c = getchar();
    }

    //while the input string doesn't end
    while (c != 10) {
        /* debug
        printf("Entered the first while, good.\n");
        */
        //move on to the next character while not encountering a blank space
        while (c != 32 && c != 10) {
            /* debug
            printf("Entered the second while, better.\n");
            */
            c = getchar();
            /* debug
            printf("All the wonderful letters %c\n", c);
            */
        }
        //when encontering a character, increment count
        count++;
        /* debug
        printf("Count is different now: %d\n", count);
        */
        //in case of consecutive white spaces, move on till encountering a real character
        while (c == 32) {
            /* debug
            printf("Entered the final while, fantastic.\n");
            printf("This should be a white space %c\n", c);
            */
            c = getchar();
        }
        /* debug
        printf("This should NOT be a white space %c\n", c);
        */
    }

    printf("%d\n", count);

    return 0;
}