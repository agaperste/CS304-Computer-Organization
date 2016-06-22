//author: Yingzhu Zhang

// You are asked to write a program that takes two 
// file names as the commandline input. The first 
// file has multiple lines each of which starts with 
// an integer. Your job is to increment the integer 
// in the beginning of the line and write the 
// modified lines to the second file. 

#include <stdio.h>
#include "math.h"
#include <string.h>



int main(int argc, char ** argv) {
    FILE *ptr_file1, *ptr_file2;
    char buf[1000], *p;
    ptr_file1 = fopen(argv[1], "r");
    if (!ptr_file1){
        return 1;
    }

    ptr_file2 = fopen(argv[2], "w");
    if(!ptr_file2){
        return 1;
    }

    
    while (fgets(buf, 1000, ptr_file1) != NULL){
        char new_line[1000], num_char[10];
        int k, l = 0, number = 0, count = 0;
        p = buf;
        
        // Get the number from the char array.
        while (*p != ' '){
            int tmp = *p - 48;
            number = 10 * number + tmp;
            p++;
            count++;
            
        }
        number++;
        
        int m = 0, tmp_num = number;
        
        // To get the number of digits of the new number.
        while (tmp_num) {
            m++;
            tmp_num /= 10;
        }
        char *p1;
        
        // Make the number into a char array.
        for (k = m-1; k >= 0; k--, number /= 10){
            char tmp = (char)((int)'0'+(number % 10));
            num_char[k] = tmp;
        }
        
        p1 = num_char;
        
        while (*p1) {
            new_line[l++] = *p1++;
        }
        
        while (*p) {
            new_line[l++] = *p++;
        }
        
        p = new_line;
        fputs(p, ptr_file2);
        memset(&new_line[0], 0, 1000);
        
    }
    
    fclose(ptr_file2);
    fclose(ptr_file1);
    
    return 0;
}
