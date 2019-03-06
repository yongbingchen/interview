#include <stdlib.h>
#include <stdio.h>

int main(int argc, char **argv)
{
	int a[5] = {1, 2, 3, 4, 5};
	int *p = (int *)(&a + 1); //&a is an array pointer, int (*)[5], &a + 1 point to address &a[0] + sizeof(int) * 5;

	printf("%d, %d\n", *(a + 1), *(p - 1)); //a is an int pointer, equals to &a[0], p - 1 is address of a[4];
	int **p2 = &a; //wrong!, &a is int (*)[5] pointer, &a + 1 is not the same as p2 + 1;
}
