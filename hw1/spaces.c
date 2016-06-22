//author: Yingzhu Zhang

#include <stdio.h>

int main(int argc, char const *argv[])
{
    int count;
    int c;

    printf("Input: ");
    count = 0;
    c = getchar();

    while (c != '\n') {
    	if (c == 32){
    	 	count++;
    	 }	
    	c = getchar();
    }

    printf("%d\n", count);

	return 0;
}