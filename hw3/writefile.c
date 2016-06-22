#include <stdio.h>

int main()
{
	FILE *ptr_file;
	int i;

	ptr_file =fopen("output.txt","w");
	if (!ptr_file)
      		return 1;

	i = 1;
	do{
	  fprintf(ptr_file, "%d %d\n", i, i*i);
	} while (i++ < 10); 

  
       	fclose(ptr_file);
        return 0;
	}