#include <stdlib.h>
#include <stdio.h>

struct s1 {
	char m1; //1 byte padding
	short m2;
	int m3;
};



struct s2 {
	char m1; // 3 bytes padding
	int m3;
	short m2; // 2 bytes padding, so array of s2 can keep m3 at int alligned address.
};


int main(int argc, char **argv)
{
	printf("size of s1 is %u\n", sizeof(struct s1));
	printf("size of s2 is %u\n", sizeof(struct s2));
}
