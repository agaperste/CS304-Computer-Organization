//author: Yingzhu Zhang

// You are asked to write a program that takes two 
// file names as the commandline input. The first 
// file has multiple lines each of which starts with 
// an integer. Your job is to increment the integer 
// in the beginning of the line and write the 
// modified lines to the second file. 

#include <stdio.h>

int main(int argc, char const *argv[])
{
    char f1[30], f2[30];
    FILE *ptr1_file, *ptr2_file;
    char buf[1000];
    int count;
    char c;

    scanf("%s %s", f1, f2);

    ptr1_file =fopen(f1,"r");
    if (!ptr1_file){
        return 1;
    }
    ptr2_file =fopen(f2,"w");
    if (!ptr2_file){
        return 1;
    }

    count = 0;
    while (fgets(buf,1000, ptr1_file)!=NULL){
        // c = fgetc;
        // while (c != 32) {
        //  count ++;
        //  c = fgetc;
        fputs(buf, ptr2_file);
        }
        // fseek(ptr2_file, count, SEEK_CUR);

        return 0;
    }

