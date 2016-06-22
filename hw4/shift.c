#include <stdio.h>
#include "math.h"
#include <string.h>


int shift(int a[], int n) {
	int i;
	for (i = 0; i != n-1; i++)
		a[i] = a[i+1];
	return *a;
}

int main(int argc, char const *argv[])
{
	int ar[5];
	int num = 4;
	shift(ar, num);
	int to_ret = *a;
	printf(to_ret);
	return 0;
}

