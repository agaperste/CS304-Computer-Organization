void shift (int *a, int n) {
	int a_helper[n];
	a = &a_helper[0];

	int i;
	int *t;
	for (i=0; i!= n-1; i++){
		t = a+i+1;
		int temp = *t;
		*(a+i) = temp;
	}
}

// void shift (int *a, int n) {
// 			int a_helper[n];
// 			a = &a_helper[0];

// 			int i;
// 			for (i=0; i!= n-1; i++){
// 				*(a+i) = *(a+(i+1));
// 			}
// 		}

int main(int argc, char const *argv[])
{
	int *a;
	int n;
	shift (a, n);
	return 0;
}