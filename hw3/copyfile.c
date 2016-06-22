#include <stdio.h>

int main()
{
        FILE *ptr1_file, *ptr2_file;
	char buf[1000];
	int mid, final;

	ptr1_file =fopen("file1.txt","r");
	if (!ptr1_file)
      		return 1;

	ptr2_file =fopen("file2.txt","w");
	if (!ptr2_file)
      		return 1;

       	while (fgets(buf,1000, ptr1_file)!=NULL)
	  fputs(buf, ptr2_file);

       	fclose(ptr1_file);
       	fclose(ptr2_file);

        return 0;
	}