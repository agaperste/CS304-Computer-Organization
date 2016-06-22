#include <stdio.h>

int proc (int a, int b, int c);

char buf2[1024];
int temp2;
char buf3[512];
int temp3;

int main(int argc, char const *argv[])
{
   int a=4, b, c=8;
   proc(a, b, c);
   return 0;
}



int proc(int a, int b, int c)
{
   int temp1;
   char buf1[2048];
   int temp4;
   temp1 = 7*c + (a<<4);
   gets(buf1);
   temp2 = 11*temp1 + c*31;
   gets(buf2);
   temp3 = 64* (c + 4* temp1 + 8*temp2);
   temp4 = (15* temp2) + (temp1<<5);
   gets(buf3);
   printf("%s %s\n",buf1,buf2);
   return 12*temp1+11*temp2+10*temp3+9*temp4;
}

// int loop (int x, int y);

// int main(int argc, char const *argv[])
// {
//    int a = 3, b = 1;
//    int ret = loop(a, b);
//    printf("%d\n", ret);
//    return 0;
// }

// int loop(int x, int y)
// {
//    int i;
//    int r = 1;
//    for (i=1; x>y; i++ ) {
//       r = r + x;
//       x --;
//    }
//    return r; 
// }