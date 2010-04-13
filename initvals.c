#define u32 __u32
#define u64 __u64
#define u_int32_t __u32

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#include <stdio.h>
#include <linux/types.h>
#include "initvals.h"

#if 0
static u32 ath9k_hw_print_initval(const u32 *array, u32 rows, u32 columns)
{
	u32 chksum, col, row;

	for (row = 0; row < rows; row++) {
		for (col = 0; col < columns; col++) {
			printf("0x%04x", array[row * columns + col]);
			if (col + 1 < columns)
				printf(", ");
		}
		printf("\n");
	}
}
#endif

static u64 ath9k_hw_check_initval(const u32 *array, u32 rows, u32 columns)
{
	u32 chksum, col, row;

	/*
	 * This checksum stuff is designed for columns <= 8),
	 * and spreads the checksum over 64 bits but since currently
	 * the initval max column size is 6 we only use the first 48
	 * bits.
	 */
	if (columns > 6)
		return 0;

	for (row = 0; row < rows; row++) {
		for (col = 0; col < columns; col++) {
			chksum ^= (array[row * columns + col]) << (8 * col);
		}
	}

	return chksum;
}

int main(void)
{
#define INI_CHECK(_array, _cols) \
		do { \
		chksum = ath9k_hw_check_initval((const u32 *) &_array,\
						ARRAY_SIZE(_array), _cols); \
		printf("0x%016llx        "#_array"\n", chksum); \
		} while (0)

	u64 chksum;

	INI_CHECK(ar5416Modes, 6);

	return 0;
}
