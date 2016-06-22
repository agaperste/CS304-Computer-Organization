#include <stdio.h>


int main(int argc, char const *argv[])
{
	char blocks[3] = {'A','B', 'C'};
	char *ptr = &blocks[0];
	char temp;
	temp = blocks[0];
	temp = *(blocks+2);
	temp = *(ptr+1);
	temp = *ptr;
	ptr = blocks+2;
	temp = *ptr;
	temp = *(ptr-1);

	ptr = blocks;
	temp = *++ptr;
	temp = ++*ptr;
	temp = *ptr++;
	temp = *ptr;

	printf("blocks is %04x\n", &blocks[0]);
	printf("ptr is %04x\n", ptr);
	printf("temp is %c\n", temp);


	return 0;
}