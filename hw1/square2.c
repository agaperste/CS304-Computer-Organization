//author: Yingzhu Zhang

#include <stdio.h>

    // num ← 0
    // while there are more digits:
    //     num ← 10 · num + next digit
    // display num · num 

int main(int argc, char const *argv[])
{

	int n = 0;
	char ch;
	int sqr = 0;

	printf("Please input a number less than 1000: ");
	ch = getchar();
	printf("%d\n", ch);

	while (ch >= 48 && ch <= 57) {
		n = n*10 + (ch-48);
		ch = getchar();
		printf("%d\n", ch);
	}


	sqr += n*n;
	printf("The square of the number is %d\n", sqr);
	
	return 0;
}