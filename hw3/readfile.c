#include<stdio.h>

int main()
{
	FILE *ptr_file;
	char buf[1000], first_name[20], last_name[20];
	int mid, final;

	ptr_file =fopen("input.txt","r");
	if (!ptr_file)
      		return 1;

       	while (fgets(buf,1000, ptr_file)!=NULL)
	  {
 		printf("%s",buf);
		sscanf(buf, "%s %s %d %d",first_name, last_name, &mid, &final);
		printf("Name: %s %s Mid: %d Final: %d\n",first_name, last_name, mid, final);
	  }

       	fclose(ptr_file);
        return 0;
	}