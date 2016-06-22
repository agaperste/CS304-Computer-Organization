//author: Yingzhu Zhang

#include <stdio.h>
#include <math.h>

int main(int argc, char const *argv[])
{
	int i, n;
	int sum_sqr = 0;

	printf("Please input a number: ");
	scanf("%d", &n);

	for (i=1; i<= n; i++){
		printf("The square of %d is %d \n", i, i*i);
		sum_sqr += i*i;
	} 

	printf("The sum of the squares is %d\n", sum_sqr);

	return 0;
}