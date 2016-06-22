#include <stdio.h>

void add(int *a, int *b, int *c);

int main() {
    int x=1,y=2, z;
    printf("%d\n", z);
    add(&x,&y,&z);
    printf("x=%d, y=%d, and x+y=%d\n", x,y,z);
    return 0;
}

void add(int *a, int *b, int *c) {
  *c=*a+*b;
}

// --------------------
// int add(int *a, int *b);

// int main() {
//     int x, y, z;
//     x = 1;
//     y = 2;
//     z = add(&x,&y);
//     printf("x=%d, y=%d, and x+y=%d\n", x,y,z);
//     return 0;
// }

// int add(int *a, int *b) {
// 	int c;
//   	c=*a + *b;
//   	return c;
// }

int loop(int x, int y)
{
	int i;
	int r = 1;
	for (i=1; x>y; i++ ) {
		r = r + x;
		x --;
	}
	return r; 
}
