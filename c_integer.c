#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	unsigned char c1 = 0x80;
	char c2 = 0x80;
	int test_1 = c1;
	printf("try set int with unsigned char 0x80 result is %d, bit content 0x%x\n", test_1, test_1);
	test_1 = c2;
	printf("try set int with char 0x80 result is %d, bit content 0x%x\n", test_1, test_1);

	unsigned int v1 = 120;
	int v2 = -20;
	printf("is unsigned int 120 larger than int -20 ? %d\n", v1 > v2); //v2 will be converted to unsigned int to compare with v1, which is 0xffffffec (memory content not changed, only value/meaning changed)
}
