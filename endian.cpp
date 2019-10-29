#include <iostream>
#include <inttypes.h>

using namespace std;

int is_little_endian() {
	union {
		int one;
		char ch;
	} endn;

	endn.one = 1;
	return endn.ch;
}

void print_endian()
{
	uint32_t le = 0x12345678;
	uint32_t be = __builtin_bswap32(le);

	printf("Little-endian: 0x%" PRIx32 "\n", le);
	printf("Big-endian:    0x%" PRIx32 "\n", be);
}
