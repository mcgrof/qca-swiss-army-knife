#define u32 __u32
#define u64 __u64
#define u_int32_t __u32

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#include <stdio.h>
#include <stdint.h>

typedef uint32_t u32;
typedef uint64_t u64;

/*
 * compile with -DATHEROS if you want to use the upstream Atheros initvals
 * and have them handy.
 */
#ifndef ATHEROS

#include "ar5008_initvals.h"
#include "ar9001_initvals.h"
#include "ar9002_initvals.h"
#include "ar9003_2p0_initvals.h"
#include "ar9003_2p2_initvals.h"

#else

/* This is what these are called on the Atheros HAL */

/* AR9003 2.0 */
#define ar9300_osprey_2p0_radio_postamble			ar9300_2p0_radio_postamble
#define ar9300Modes_lowest_ob_db_tx_gain_table_osprey_2p0	ar9300Modes_lowest_ob_db_tx_gain_table_2p0
#define ar9300Modes_fast_clock_osprey_2p0			ar9300Modes_fast_clock_2p0
#define ar9300_osprey_2p0_radio_core				ar9300_2p0_radio_core
#define ar9300Common_rx_gain_table_merlin_2p0			ar9300Common_rx_gain_table_merlin_2p0
#define ar9300_osprey_2p0_mac_postamble				ar9300_2p0_mac_postamble
#define ar9300_osprey_2p0_soc_postamble				ar9300_2p0_soc_postamble
#define ar9200_merlin_2p0_radio_core				ar9200_merlin_2p0_radio_core
#define ar9300_osprey_2p0_baseband_postamble			ar9300_2p0_baseband_postamble
#define ar9300_osprey_2p0_baseband_core				ar9300_2p0_baseband_core
#define ar9300Modes_high_power_tx_gain_table_osprey_2p0		ar9300Modes_high_power_tx_gain_table_2p0
#define ar9300Modes_high_ob_db_tx_gain_table_osprey_2p0		ar9300Modes_high_ob_db_tx_gain_table_2p0
#define ar9300Common_rx_gain_table_osprey_2p0			ar9300Common_rx_gain_table_2p0
#define ar9300Modes_low_ob_db_tx_gain_table_osprey_2p0		ar9300Modes_low_ob_db_tx_gain_table_2p0
#define ar9300_osprey_2p0_mac_core				ar9300_2p0_mac_core
#define ar9300Common_wo_xlna_rx_gain_table_osprey_2p0		ar9300Common_wo_xlna_rx_gain_table_2p0
#define ar9300_osprey_2p0_soc_preamble				ar9300_2p0_soc_preamble
#define ar9300PciePhy_pll_on_clkreq_disable_L1_osprey_2p0	ar9300PciePhy_pll_on_clkreq_disable_L1_2p0
#define ar9300PciePhy_clkreq_enable_L1_osprey_2p0		ar9300PciePhy_clkreq_enable_L1_2p0
#define ar9300PciePhy_clkreq_disable_L1_osprey_2p0		ar9300PciePhy_clkreq_disable_L1_2p0

#include "ar9300_osprey20.ini"

/* AR9003 2.2 */
#define ar9300_osprey_2p2_radio_postamble			ar9300_2p2_radio_postamble
#define ar9300Modes_lowest_ob_db_tx_gain_table_osprey_2p2	ar9300Modes_lowest_ob_db_tx_gain_table_2p2
#define ar9300Modes_fast_clock_osprey_2p2			ar9300Modes_fast_clock_2p2
#define ar9300_osprey_2p2_radio_core				ar9300_2p2_radio_core
#define ar9300Common_rx_gain_table_merlin_2p2			ar9300Common_rx_gain_table_merlin_2p2
#define ar9300_osprey_2p2_mac_postamble				ar9300_2p2_mac_postamble
#define ar9300_osprey_2p2_soc_postamble				ar9300_2p2_soc_postamble
#define ar9200_merlin_2p2_radio_core				ar9200_merlin_2p2_radio_core
#define ar9300_osprey_2p2_baseband_postamble			ar9300_2p2_baseband_postamble
#define ar9300_osprey_2p2_baseband_core				ar9300_2p2_baseband_core
#define ar9300Modes_high_power_tx_gain_table_osprey_2p2		ar9300Modes_high_power_tx_gain_table_2p2
#define ar9300Modes_high_ob_db_tx_gain_table_osprey_2p2		ar9300Modes_high_ob_db_tx_gain_table_2p2
#define ar9300Common_rx_gain_table_osprey_2p2			ar9300Common_rx_gain_table_2p2
#define ar9300Modes_low_ob_db_tx_gain_table_osprey_2p2		ar9300Modes_low_ob_db_tx_gain_table_2p2
#define ar9300_osprey_2p2_mac_core				ar9300_2p2_mac_core
#define ar9300Common_wo_xlna_rx_gain_table_osprey_2p2		ar9300Common_wo_xlna_rx_gain_table_2p2
#define ar9300_osprey_2p2_soc_preamble				ar9300_2p2_soc_preamble
#define ar9300PciePhy_pll_on_clkreq_disable_L1_osprey_2p2	ar9300PciePhy_pll_on_clkreq_disable_L1_2p2
#define ar9300PciePhy_clkreq_enable_L1_osprey_2p2		ar9300PciePhy_clkreq_enable_L1_2p2
#define ar9300PciePhy_clkreq_disable_L1_osprey_2p2		ar9300PciePhy_clkreq_disable_L1_2p2

#include "ar9300_osprey22.ini"

#endif /* ATHEROS */

#define INI_CHECK(_array, _cols) \
		do { \
		chksum = ath9k_hw_check_initval((const u32 *) &_array,\
						ARRAY_SIZE(_array), _cols); \
		printf("0x%016llx        "#_array"\n", chksum); \
		} while (0)


		//printf("/* "#_array" checksum: 0x%016llx */\n", chksum); \

#define INI_PRINT(_array, _cols) \
		do { \
		chksum = ath9k_hw_check_initval((const u32 *) &_array,\
						ARRAY_SIZE(_array), _cols); \
		printf("static const u32 "#_array"[][%d] = {\n", _cols); \
		ath9k_hw_print_initval((const u32 *) _array, \
				       ARRAY_SIZE(_array), _cols); \
		} while (0)

static void print_license(void)
{
	printf("/*\n");
	printf(" * Copyright (c) 2010 Atheros Communications Inc.\n");
	printf(" *\n");
	printf(" * Permission to use, copy, modify, and/or distribute this software for any\n");
	printf(" * purpose with or without fee is hereby granted, provided that the above\n");
	printf(" * copyright notice and this permission notice appear in all copies.\n");
	printf(" *\n");
	printf(" * THE SOFTWARE IS PROVIDED \"AS IS\" AND THE AUTHOR DISCLAIMS ALL WARRANTIES\n");
	printf(" * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF\n");
	printf(" * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR\n");
	printf(" * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES\n");
	printf(" * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN\n");
	printf(" * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF\n");
	printf(" * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.\n");
	printf(" */\n");
	printf("\n");
}

static void ath9k_hw_print_initval(const u32 *array, u32 rows, u32 columns)
{
	u32 chksum, col, row;

	/*
	 * This checksum stuff is designed for columns <= 8),
	 * and spreads the checksum over 64 bits but since currently
	 * the initval max column size is 6 we only use the first 48
	 * bits.
	 */
	if (columns > 6)
		return;

	switch (columns) {
	case 5:
		printf("\t/* Addr      5G_HT20     5G_HT40     2G_HT40     2G_HT20   */\n");
		break;
	case 3:
		printf("\t/* Addr      5G_HT20     5G_HT40   */\n");
		break;
	case 2:
		printf("\t/* Addr      allmodes  */\n");
		break;
	default:
		break;
	}

	for (row = 0; row < rows; row++) {
		for (col = 0; col < columns; col++) {
			if (!col)
				printf("\t{");
			printf("0x%08x", array[row * columns + col]);
			if (col + 1 < columns)
				printf(", ");
		}
		printf("},\n");
	}
	printf("};\n\n");
}

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

#ifndef ATHEROS
static void ar5008_hw_check_initvals(void)
{
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
}
#else
static void ar5008_hw_check_initvals(void)
{
}
#endif /* ATHEROS */

#ifndef ATHEROS
static void ar9001_hw_check_initvals(void)
{
	u64 chksum;

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
}
#else
static void ar9001_hw_check_initvals(void)
{
}
#endif /* ATHEROS */

#ifndef ATHEROS
static void ar9002_hw_check_initvals(void)
{
	u64 chksum;

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
	INI_CHECK(ar9287Common_normal_cck_fir_coeff_9287_1_1, 2);
	INI_CHECK(ar9287Common_japan_2484_cck_fir_coeff_9287_1_1, 2);
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
}
#else
static void ar9002_hw_check_initvals(void)
{
}
#endif /* ATHEROS */

static void ar9003_2p0_hw_check_initvals(void)
{
	u64 chksum;

	INI_CHECK(ar9300_2p0_radio_postamble, 5);
	INI_CHECK(ar9300Modes_lowest_ob_db_tx_gain_table_2p0, 5);
	INI_CHECK(ar9300Modes_fast_clock_2p0, 3);
	INI_CHECK(ar9300_2p0_radio_core, 2);
	INI_CHECK(ar9300Common_rx_gain_table_merlin_2p0, 2);
	INI_CHECK(ar9300_2p0_mac_postamble, 5);
	INI_CHECK(ar9300_2p0_soc_postamble, 5);
	INI_CHECK(ar9200_merlin_2p0_radio_core, 2);
	INI_CHECK(ar9300_2p0_baseband_postamble, 5);
	INI_CHECK(ar9300_2p0_baseband_core, 2);
	INI_CHECK(ar9300Modes_high_power_tx_gain_table_2p0, 5);
	INI_CHECK(ar9300Modes_high_ob_db_tx_gain_table_2p0, 5);
	INI_CHECK(ar9300Common_rx_gain_table_2p0, 2);
	INI_CHECK(ar9300Modes_low_ob_db_tx_gain_table_2p0, 5);
	INI_CHECK(ar9300_2p0_mac_core, 2);
	INI_CHECK(ar9300Common_wo_xlna_rx_gain_table_2p0, 2);
	INI_CHECK(ar9300_2p0_soc_preamble, 2);
	INI_CHECK(ar9300PciePhy_pll_on_clkreq_disable_L1_2p0, 2);
	INI_CHECK(ar9300PciePhy_clkreq_enable_L1_2p0, 2);
	INI_CHECK(ar9300PciePhy_clkreq_disable_L1_2p0, 2);
}

static void ar9003_2p2_hw_check_initvals(void)
{
	u64 chksum;

	INI_CHECK(ar9300_2p2_radio_postamble, 5);
	INI_CHECK(ar9300Modes_lowest_ob_db_tx_gain_table_2p2, 5);
	INI_CHECK(ar9300Modes_fast_clock_2p2, 3);
	INI_CHECK(ar9300_2p2_radio_core, 2);
	INI_CHECK(ar9300Common_rx_gain_table_merlin_2p2, 2);
	INI_CHECK(ar9300_2p2_mac_postamble, 5);
	INI_CHECK(ar9300_2p2_soc_postamble, 5);
	INI_CHECK(ar9200_merlin_2p2_radio_core, 2);
	INI_CHECK(ar9300_2p2_baseband_postamble, 5);
	INI_CHECK(ar9300_2p2_baseband_core, 2);
	INI_CHECK(ar9300Modes_high_power_tx_gain_table_2p2, 5);
	INI_CHECK(ar9300Modes_high_ob_db_tx_gain_table_2p2, 5);
	INI_CHECK(ar9300Common_rx_gain_table_2p2, 2);
	INI_CHECK(ar9300Modes_low_ob_db_tx_gain_table_2p2, 5);
	INI_CHECK(ar9300_2p2_mac_core, 2);
	INI_CHECK(ar9300Common_wo_xlna_rx_gain_table_2p2, 2);
	INI_CHECK(ar9300_2p2_soc_preamble, 2);
	INI_CHECK(ar9300PciePhy_pll_on_clkreq_disable_L1_2p2, 2);
	INI_CHECK(ar9300PciePhy_clkreq_enable_L1_2p2, 2);
	INI_CHECK(ar9300PciePhy_clkreq_disable_L1_2p2, 2);
}

#ifndef ATHEROS
static void ar5008_hw_print_initvals(void)
{
	u64 chksum;

	INI_PRINT(ar5416Modes, 6);
	INI_PRINT(ar5416Common, 2);
	INI_PRINT(ar5416Bank0, 2);
	INI_PRINT(ar5416BB_RfGain, 3);
	INI_PRINT(ar5416Bank1, 2);
	INI_PRINT(ar5416Bank2, 2);
	INI_PRINT(ar5416Bank3, 3);
	INI_PRINT(ar5416Bank6, 3);
	INI_PRINT(ar5416Bank6TPC, 3);
	INI_PRINT(ar5416Bank7, 2);
	INI_PRINT(ar5416Addac, 2);
}
#else
static void ar5008_hw_print_initvals(void)
{
}
#endif /* ATHEROS */

#ifndef ATHEROS
static void ar9001_hw_print_initvals(void)
{
	u64 chksum;

	INI_PRINT(ar5416Modes_9100, 6);
	INI_PRINT(ar5416Common_9100, 2);
	INI_PRINT(ar5416Bank0_9100, 2);
	INI_PRINT(ar5416BB_RfGain_9100, 3);
	INI_PRINT(ar5416Bank1_9100, 2);
	INI_PRINT(ar5416Bank2_9100, 2);
	INI_PRINT(ar5416Bank3_9100, 3);
	INI_PRINT(ar5416Bank6_9100, 3);
	INI_PRINT(ar5416Bank6TPC_9100, 3);
	INI_PRINT(ar5416Bank7_9100, 2);
	INI_PRINT(ar5416Addac_9100, 2);
	INI_PRINT(ar5416Modes_9160, 6);
	INI_PRINT(ar5416Common_9160, 2);
	INI_PRINT(ar5416Bank0_9160, 2);
	INI_PRINT(ar5416BB_RfGain_9160, 3);
	INI_PRINT(ar5416Bank1_9160, 2);
	INI_PRINT(ar5416Bank2_9160, 2);
	INI_PRINT(ar5416Bank3_9160, 3);
	INI_PRINT(ar5416Bank6_9160, 3);
	INI_PRINT(ar5416Bank6TPC_9160, 3);
	INI_PRINT(ar5416Bank7_9160, 2);
	INI_PRINT(ar5416Addac_9160, 2);
	INI_PRINT(ar5416Addac_91601_1, 2);
}
#else
static void ar9001_hw_print_initvals(void)
{
}
#endif /* ATHEROS */

#ifndef ATHEROS
static void ar9002_hw_print_initvals(void)
{
	u64 chksum;

	INI_PRINT(ar9280Modes_9280, 6);
	INI_PRINT(ar9280Common_9280, 2);
	INI_PRINT(ar9280Modes_9280_2, 6);
	INI_PRINT(ar9280Common_9280_2, 2);
	INI_PRINT(ar9280Modes_fast_clock_9280_2, 3);
	INI_PRINT(ar9280Modes_backoff_23db_rxgain_9280_2, 6);
	INI_PRINT(ar9280Modes_original_rxgain_9280_2, 6);
	INI_PRINT(ar9280Modes_backoff_13db_rxgain_9280_2, 6);
	INI_PRINT(ar9280Modes_high_power_tx_gain_9280_2, 6);
	INI_PRINT(ar9280Modes_original_tx_gain_9280_2, 6);
	INI_PRINT(ar9280PciePhy_clkreq_off_L1_9280, 2);
	INI_PRINT(ar9280PciePhy_clkreq_always_on_L1_9280, 2);
	INI_PRINT(ar9285Modes_9285, 6);
	INI_PRINT(ar9285Common_9285, 2);
	INI_PRINT(ar9285PciePhy_clkreq_always_on_L1_9285, 2);
	INI_PRINT(ar9285PciePhy_clkreq_off_L1_9285, 2);
	INI_PRINT(ar9285Modes_9285_1_2, 6);
	INI_PRINT(ar9285Common_9285_1_2, 2);
	INI_PRINT(ar9285Modes_high_power_tx_gain_9285_1_2, 6);
	INI_PRINT(ar9285Modes_original_tx_gain_9285_1_2, 6);
	INI_PRINT(ar9285Modes_XE2_0_normal_power, 6);
	INI_PRINT(ar9285Modes_XE2_0_high_power, 6);
	INI_PRINT(ar9285PciePhy_clkreq_always_on_L1_9285_1_2, 2);
	INI_PRINT(ar9285PciePhy_clkreq_off_L1_9285_1_2, 2);
	INI_PRINT(ar9287Modes_9287_1_0, 6);
	INI_PRINT(ar9287Common_9287_1_0, 2);
	INI_PRINT(ar9287Modes_tx_gain_9287_1_0, 6);
	INI_PRINT(ar9287Modes_rx_gain_9287_1_0, 6);
	INI_PRINT(ar9287PciePhy_clkreq_always_on_L1_9287_1_0, 2);
	INI_PRINT(ar9287PciePhy_clkreq_off_L1_9287_1_0, 2);
	INI_PRINT(ar9287Modes_9287_1_1, 6);
	INI_PRINT(ar9287Common_9287_1_1, 2);
	INI_PRINT(ar9287Common_normal_cck_fir_coeff_92871_1, 2);
	INI_PRINT(ar9287Common_japan_2484_cck_fir_coeff_92871_1, 2);
	INI_PRINT(ar9287Modes_tx_gain_9287_1_1, 6);
	INI_PRINT(ar9287Modes_rx_gain_9287_1_1, 6);
	INI_PRINT(ar9287PciePhy_clkreq_always_on_L1_9287_1_1, 2);
	INI_PRINT(ar9287PciePhy_clkreq_off_L1_9287_1_1, 2);
	INI_PRINT(ar9271Modes_9271, 6);
	INI_PRINT(ar9271Common_9271, 2);
	INI_PRINT(ar9271Common_normal_cck_fir_coeff_9271, 2);
	INI_PRINT(ar9271Common_japan_2484_cck_fir_coeff_9271, 2);
	INI_PRINT(ar9271Modes_9271_1_0_only, 6);
	INI_PRINT(ar9271Modes_9271_ANI_reg, 6);
	INI_PRINT(ar9271Modes_normal_power_tx_gain_9271, 6);
	INI_PRINT(ar9271Modes_high_power_tx_gain_9271, 6);
}
#else
static void ar9002_hw_print_initvals(void)
{
}
#endif /* ATHEROS */

static void ar9003_2p0_hw_print_initvals(void)
{
	u64 chksum;

	INI_PRINT(ar9300_2p0_radio_postamble, 5);
	INI_PRINT(ar9300Modes_lowest_ob_db_tx_gain_table_2p0, 5);
	INI_PRINT(ar9300Modes_fast_clock_2p0, 3);
	INI_PRINT(ar9300_2p0_radio_core, 2);
	INI_PRINT(ar9300Common_rx_gain_table_merlin_2p0, 2);
	INI_PRINT(ar9300_2p0_mac_postamble, 5);
	INI_PRINT(ar9300_2p0_soc_postamble, 5);
	INI_PRINT(ar9200_merlin_2p0_radio_core, 2);
	INI_PRINT(ar9300_2p0_baseband_postamble, 5);
	INI_PRINT(ar9300_2p0_baseband_core, 2);
	INI_PRINT(ar9300Modes_high_power_tx_gain_table_2p0, 5);
	INI_PRINT(ar9300Modes_high_ob_db_tx_gain_table_2p0, 5);
	INI_PRINT(ar9300Common_rx_gain_table_2p0, 2);
	INI_PRINT(ar9300Modes_low_ob_db_tx_gain_table_2p0, 5);
	INI_PRINT(ar9300_2p0_mac_core, 2);
	INI_PRINT(ar9300Common_wo_xlna_rx_gain_table_2p0, 2);
	INI_PRINT(ar9300_2p0_soc_preamble, 2);
	INI_PRINT(ar9300PciePhy_pll_on_clkreq_disable_L1_2p0, 2);
	INI_PRINT(ar9300PciePhy_clkreq_enable_L1_2p0, 2);
	INI_PRINT(ar9300PciePhy_clkreq_disable_L1_2p0, 2);
}

static void ar9003_2p2_hw_print_initvals(void)
{
	u64 chksum;

	INI_PRINT(ar9300_2p2_radio_postamble, 5);
	INI_PRINT(ar9300Modes_lowest_ob_db_tx_gain_table_2p2, 5);
	INI_PRINT(ar9300Modes_fast_clock_2p2, 3);
	INI_PRINT(ar9300_2p2_radio_core, 2);
	INI_PRINT(ar9300Common_rx_gain_table_merlin_2p2, 2);
	INI_PRINT(ar9300_2p2_mac_postamble, 5);
	INI_PRINT(ar9300_2p2_soc_postamble, 5);
	INI_PRINT(ar9200_merlin_2p2_radio_core, 2);
	INI_PRINT(ar9300_2p2_baseband_postamble, 5);
	INI_PRINT(ar9300_2p2_baseband_core, 2);
	INI_PRINT(ar9300Modes_high_power_tx_gain_table_2p2, 5);
	INI_PRINT(ar9300Modes_high_ob_db_tx_gain_table_2p2, 5);
	INI_PRINT(ar9300Common_rx_gain_table_2p2, 2);
	INI_PRINT(ar9300Modes_low_ob_db_tx_gain_table_2p2, 5);
	INI_PRINT(ar9300_2p2_mac_core, 2);
	INI_PRINT(ar9300Common_wo_xlna_rx_gain_table_2p2, 2);
	INI_PRINT(ar9300_2p2_soc_preamble, 2);
	INI_PRINT(ar9300PciePhy_pll_on_clkreq_disable_L1_2p2, 2);
	INI_PRINT(ar9300PciePhy_clkreq_enable_L1_2p2, 2);
	INI_PRINT(ar9300PciePhy_clkreq_disable_L1_2p2, 2);
}

#ifndef ATHEROS
static void usage()
{
	printf("Usage: initvals [-w ] [-f ar5008 | ar9001 | ar9002 | ar9003-2p0 | ar9003-2p2 ]\n");
}
#else
static void usage()
{
	printf("Usage: initvals [-w ] [-f ar9003-2p0 | ar9003-2p2 ]\n");
}
#endif

#ifndef ATHEROS
print_initvals_family(char *family)
{
	print_license();

	if (strncmp(family, "ar5008", 6) == 0)
		ar5008_hw_print_initvals();
	else if (strncmp(family, "ar9001", 6) == 0)
		ar9001_hw_print_initvals();
	else if (strncmp(family, "ar9002", 6) == 0)
		ar9002_hw_print_initvals();
	else if (strncmp(family, "ar9003-2p0", 10) == 0) {
		printf("#ifndef INITVALS_9003_H\n");
		printf("#define INITVALS_9003_H\n");
		printf("\n");
		printf("/* AR9003 2.0 */\n");
		printf("\n");
		ar9003_2p0_hw_print_initvals();
		printf("#endif /* INITVALS_9003_H */\n");
	} else if (strncmp(family, "ar9003-2p2", 10) == 0) {
		printf("#ifndef INITVALS_9003_2P2_H\n");
		printf("#define INITVALS_9003_2P2_H\n");
		printf("\n");
		printf("/* AR9003 2.2 */\n");
		printf("\n");
		ar9003_2p2_hw_print_initvals();
		printf("#endif /* INITVALS_9003_2P2_H */\n");
	}
}
#else
print_initvals_family(char *family)
{
	print_license();

	if (strncmp(family, "ar9003-2p0", 10) == 0) {
		printf("#ifndef INITVALS_9003_H\n");
		printf("#define INITVALS_9003_H\n");
		printf("\n");
		printf("/* AR9003 2.0 */\n");
		printf("\n");
		ar9003_2p0_hw_print_initvals();
		printf("#endif /* INITVALS_9003_H */\n");
	} else if (strncmp(family, "ar9003-2p2", 10) == 0) {
		printf("#ifndef INITVALS_9003_2P2_H\n");
		printf("#define INITVALS_9003_2P2_H\n");
		printf("\n");
		printf("/* AR9003 2.2 */\n");
		printf("\n");
		ar9003_2p2_hw_print_initvals();
		printf("#endif /* INITVALS_9003_2P2_H */\n");
	}
}
#endif /* ATHEROS */

#ifndef ATHEROS
check_initvals_family(char *family)
{
	if (strncmp(family, "ar5008", 6) == 0)
		ar5008_hw_check_initvals();
	else if (strncmp(family, "ar9001", 6) == 0)
		ar9001_hw_check_initvals();
	else if (strncmp(family, "ar9002", 6) == 0)
		ar9002_hw_check_initvals();
	else if (strncmp(family, "ar9003-2p0", 10) == 0)
		ar9003_2p0_hw_check_initvals();
	else if (strncmp(family, "ar9003-2p2", 10) == 0)
		ar9003_2p2_hw_check_initvals();
}
#else
check_initvals_family(char *family)
{
	if (strncmp(family, "ar9003-2p0", 10) == 0)
		ar9003_2p0_hw_check_initvals();
	else if (strncmp(family, "ar9003-2p2", 10) == 0)
		ar9003_2p2_hw_check_initvals();
}
#endif /* ATHEROS */

int main(int argc, void *argv[])
{

	if (argc > 1) {
		if (argc == 2) {
			if (strncmp(argv[1], "-w", 2) != 0)
				return -1;

			ar5008_hw_print_initvals();
			ar9001_hw_print_initvals();
			ar9002_hw_print_initvals();
			ar9003_2p0_hw_print_initvals();
			ar9003_2p2_hw_print_initvals();

			return 0;
		}

		if (argc != 3 && argc != 4) {
			usage();
			return -1;
		}

		if (argc == 3) {
			check_initvals_family(argv[2]);
			return 0;
		}

		if (strncmp(argv[1], "-w", 2) != 0)
			return -1;

		print_initvals_family(argv[3]);

		return 0;
	}

	ar5008_hw_check_initvals();
	ar9001_hw_check_initvals();
	ar9002_hw_check_initvals();
	ar9003_2p0_hw_check_initvals();
	ar9003_2p2_hw_check_initvals();

	return 0;
}
