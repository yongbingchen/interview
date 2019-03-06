#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

enum my_enum {
	MY_ENUM_START = 1,
	MY_ENUM_2 = 3,
	MY_ENUM_3 = 5,
	MY_ENUM_LAST = 0x7FFFFFFF,
};


struct my_register {
	uint32_t bit1 :1;
	uint32_t bit2_5 : 4;
	uint32_t bit6_28: 23;
	uint32_t bit29_31: 3;
};

union my_reg_union {
	uint32_t regval;
	struct my_register bits;
};

int main(int argc, char **argv)
{
	enum my_enum t = MY_ENUM_3;

	printf("enum t = %d\n", t);

	struct my_register reg1;

	reg1.bit1 = 1;
	reg1.bit6_28 = 1;

	printf("reg1.bit1 = 0x%x, bit6_28 = 0x%x\n", reg1.bit1, reg1.bit6_28);

	union my_reg_union reg2;
	reg2.regval = 0x12345678;
	printf("reg2.bit1 = 0x%x, bit6_28 = 0x%x\n", reg2.bits.bit1, reg2.bits.bit6_28);
	printf("reg2.bit1 = 0x%x, bit6_28 = 0x%x\n", reg2.regval & 0x1, ((reg2.regval) >> 5)&0x7fffff);

	switch (t) {
		case MY_ENUM_START:
			break;
		case MY_ENUM_2:
			break;
		case MY_ENUM_3:
			printf("this is case MY_ENUM_3\n");
			break;
		default:
			break;
	};

	struct signed_bits {
		int b1 :5;
		int b2 :2;
	};
	union signed_union {
		struct signed_bits s_u;
		int i_u;
	} b;

	b.i_u = 0x33323130;
	printf("first 5 bits is %d, next 2 bits is %d\n", b.s_u.b1, b.s_u.b2); //b1, b2 start from lsb of the int, which is 0x30, 0b00110000, b1 is bit 0 to bit 4, is 0b10000, when parsed as signed, it's '-16', while b2 is 0b01.
}
