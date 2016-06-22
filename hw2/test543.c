#include <stdio.h>

 int main (int argc, char *argv[]) {
	int i = 0;
	int j = 0;
 	int sqr = 0;
 	char ch;
 	int num = 0;

	printf("\ncommand line args count=%d\n", argc);

	/* First argument is executable name only */
	printf("executable name=%s\n", argv[0]);

	//print out arg//
	for (i=1; i< argc; i++) {
		printf("arg%d=%s\n", i, argv[i]);
		
 	}

 	//print out the square of arg//
	for (i=1; i< argc; i++) {
		ch = *(argv[i]);
		// printf("first char is %d\n", ch);
		//don't forget to reset to 0
		int j = 0;
		while (ch >= 48 && ch <= 57) {
			j++;
			num = num*10 + (ch-48);
			ch = *(argv[i]+j);
			// printf("%d\n", ch);
 		}
 		
 		// printf("made it to square calculation\n");
	 	sqr = num*num;
	 	printf("The square of arg%d is %d\n", i, sqr);

 		//don't forget to reset to 0
 		num = 0;

 	}

 	/*-how do I print argv[i] in the form of char?*/
 	// ch1 = *(argv[0]);
 	// ch2 = *(argv[0]+1);

 	// printf("%d\n", ch1);
 	// printf("%d\n", ch2);
 	// printf("stuff went through\n");

	return 0;
 }