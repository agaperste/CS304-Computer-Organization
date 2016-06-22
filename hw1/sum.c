// author: Yingzhu Zhang

#include <stdio.h>

int main(int argc, char const *argv[])
{
	int n;
	char ch;
	int sum = 0;

	printf("Please input numbers separated by a single space: "); //nonnegative, >1000000
	ch = getchar();

	while (ch != 10) {
		// for each loop, initialize n = 0 again;
		n = 0;

		// Convert digit to integer first
		while (ch >= 48 && ch <= 57) {
			n = n*10 + (ch-48);
			ch = getchar();
		}

		/* for debug
		printf("The input is %d\n", n);
		*/

		// Using blank space as a signal to collect the next integer
		while (ch == 32) {
			ch = getchar();
		}

		// accumulating the sum
		sum = sum +n; 
	}


	printf("The sum of the numbers is %d\n", sum);

	return 0;
}