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
	u32 chksum = 0, col, row;

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
	INI_CHECK(ar5416Common, 2);
	INI_CHECK(ar5416Bank0, 2);
	INI_CHECK(ar5416BB_RfGain, 3);
	INI_CHECK(ar5416Bank1, 2);
	INI_CHECK(ar5416Bank2, 2);
	INI_CHECK(ar5416Bank3, 3);
	INI_CHECK(ar5416Bank6, 3);
	INI_CHECK(ar5416Bank6TPC, 3);
	INI_CHECK(ar5416Bank7, 2);
	INI_CHECK(ar5416Addac, 2);
	INI_CHECK(ar5416Modes_9100, 6);
	INI_CHECK(ar5416Common_9100, 2);
	INI_CHECK(ar5416Bank0_9100, 2);
	INI_CHECK(ar5416BB_RfGain_9100, 3);
	INI_CHECK(ar5416Bank1_9100, 2);
	INI_CHECK(ar5416Bank2_9100, 2);
	INI_CHECK(ar5416Bank3_9100, 3);
	INI_CHECK(ar5416Bank6_9100, 3);
	INI_CHECK(ar5416Bank6TPC_9100, 3);
	INI_CHECK(ar5416Bank7_9100, 2);
	INI_CHECK(ar5416Addac_9100, 2);
	INI_CHECK(ar5416Modes_9160, 6);
	INI_CHECK(ar5416Common_9160, 2);
	INI_CHECK(ar5416Bank0_9160, 2);
	INI_CHECK(ar5416BB_RfGain_9160, 3);
	INI_CHECK(ar5416Bank1_9160, 2);
	INI_CHECK(ar5416Bank2_9160, 2);
	INI_CHECK(ar5416Bank3_9160, 3);
	INI_CHECK(ar5416Bank6_9160, 3);
	INI_CHECK(ar5416Bank6TPC_9160, 3);
	INI_CHECK(ar5416Bank7_9160, 2);
	INI_CHECK(ar5416Addac_9160, 2);
	INI_CHECK(ar5416Addac_91601_1, 2);
	INI_CHECK(ar9280Modes_9280, 6);
	INI_CHECK(ar9280Common_9280, 2);
	INI_CHECK(ar9280Modes_9280_2, 6);
	INI_CHECK(ar9280Common_9280_2, 2);
	INI_CHECK(ar9280Modes_fast_clock_9280_2, 3);
	INI_CHECK(ar9280Modes_backoff_23db_rxgain_9280_2, 6);
	INI_CHECK(ar9280Modes_original_rxgain_9280_2, 6);
	INI_CHECK(ar9280Modes_backoff_13db_rxgain_9280_2, 6);
	INI_CHECK(ar9280Modes_high_power_tx_gain_9280_2, 6);
	INI_CHECK(ar9280Modes_original_tx_gain_9280_2, 6);
	INI_CHECK(ar9280PciePhy_clkreq_off_L1_9280, 2);
	INI_CHECK(ar9280PciePhy_clkreq_always_on_L1_9280, 2);
	INI_CHECK(ar9285Modes_9285, 6);
	INI_CHECK(ar9285Common_9285, 2);
	INI_CHECK(ar9285PciePhy_clkreq_always_on_L1_9285, 2);
	INI_CHECK(ar9285PciePhy_clkreq_off_L1_9285, 2);
	INI_CHECK(ar9285Modes_9285_1_2, 6);
	INI_CHECK(ar9285Common_9285_1_2, 2);
	INI_CHECK(ar9285Modes_high_power_tx_gain_9285_1_2, 6);
	INI_CHECK(ar9285Modes_original_tx_gain_9285_1_2, 6);
	INI_CHECK(ar9285Modes_XE2_0_normal_power, 6);
	INI_CHECK(ar9285Modes_XE2_0_high_power, 6);
	INI_CHECK(ar9285PciePhy_clkreq_always_on_L1_9285_1_2, 2);
	INI_CHECK(ar9285PciePhy_clkreq_off_L1_9285_1_2, 2);
	INI_CHECK(ar9287Modes_9287_1_0, 6);
	INI_CHECK(ar9287Common_9287_1_0, 2);
	INI_CHECK(ar9287Modes_tx_gain_9287_1_0, 6);
	INI_CHECK(ar9287Modes_rx_gain_9287_1_0, 6);
	INI_CHECK(ar9287PciePhy_clkreq_always_on_L1_9287_1_0, 2);
	INI_CHECK(ar9287PciePhy_clkreq_off_L1_9287_1_0, 2);
	INI_CHECK(ar9287Modes_9287_1_1, 6);
	INI_CHECK(ar9287Common_9287_1_1, 2);
	INI_CHECK(ar9287Common_normal_cck_fir_coeff_92871_1, 2);
	INI_CHECK(ar9287Common_japan_2484_cck_fir_coeff_92871_1, 2);
	INI_CHECK(ar9287Modes_tx_gain_9287_1_1, 6);
	INI_CHECK(ar9287Modes_rx_gain_9287_1_1, 6);
	INI_CHECK(ar9287PciePhy_clkreq_always_on_L1_9287_1_1, 2);
	INI_CHECK(ar9287PciePhy_clkreq_off_L1_9287_1_1, 2);
	INI_CHECK(ar9271Modes_9271, 6);
	INI_CHECK(ar9271Common_9271, 2);
	INI_CHECK(ar9271Common_normal_cck_fir_coeff_9271, 2);
	INI_CHECK(ar9271Common_japan_2484_cck_fir_coeff_9271, 2);
	INI_CHECK(ar9271Modes_9271_1_0_only, 6);
	INI_CHECK(ar9271Modes_9271_ANI_reg, 6);
	INI_CHECK(ar9271Modes_normal_power_tx_gain_9271, 6);
	INI_CHECK(ar9271Modes_high_power_tx_gain_9271, 6);

	return 0;
}
