#define u32 __u32
#define u64 __u64
#define u_int32_t __u32

#define ARRAY_SIZE(arr) (sizeof(arr) / sizeof((arr)[0]))

#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include "sha1.h"

typedef uint32_t u32;
typedef long long unsigned int u64;

/*
 * compile with -DATHEROS if you want to use the upstream Atheros initvals
 * and have them handy.
 */
#ifndef ATHEROS

#include "ar5008_initvals.h"
#include "ar9001_initvals.h"
#include "ar9002_initvals.h"
#include "ar9003_2p2_initvals.h"
#include "ar9330_1p1_initvals.h"
#include "ar9330_1p2_initvals.h"
#include "ar9485_initvals.h"
#include "ar9580_1p0_initvals.h"

#else

#include "ar5416.ini"

#define ar5416Modes						ar5416Modes_9100
#define ar5416Common						ar5416Common_9100
#define ar5416Bank0						ar5416Bank0_9100
#define ar5416BB_RfGain						ar5416BB_RfGain_9100
#define ar5416Bank1						ar5416Bank1_9100
#define ar5416Bank2						ar5416Bank2_9100
#define ar5416Bank3						ar5416Bank3_9100
#define ar5416Bank6						ar5416Bank6_9100
#define ar5416Bank6TPC						ar5416Bank6TPC_9100
#define ar5416Bank7						ar5416Bank7_9100
#define ar5416Addac						ar5416Addac_9100

#include "ar5416_howl.ini"

#undef ar5416Modes
#undef ar5416Common
#undef ar5416Bank0
#undef ar5416BB_RfGain
#undef ar5416Bank1
#undef ar5416Bank2
#undef ar5416Bank3
#undef ar5416Bank6
#undef ar5416Bank6TPC
#undef ar5416Bank7
#undef ar5416Addac

#define ar5416Modes_sowl					ar5416Modes_9160
#define ar5416Common_sowl					ar5416Common_9160
#define ar5416Bank0_sowl					ar5416Bank0_9160
#define ar5416BB_RfGain_sowl					ar5416BB_RfGain_9160
#define ar5416Bank1_sowl					ar5416Bank1_9160
#define ar5416Bank2_sowl					ar5416Bank2_9160
#define ar5416Bank3_sowl					ar5416Bank3_9160
#define ar5416Bank6_sowl					ar5416Bank6_9160
#define ar5416Bank6TPC_sowl					ar5416Bank6TPC_9160
#define ar5416Bank7_sowl					ar5416Bank7_9160
#define ar5416Addac_sowl					ar5416Addac_9160
#define ar5416Addac_sowl1_1					ar5416Addac_9160_1_1

#include "ar5416_sowl.ini"


#include "ar9280.ini"

#define ar9280Modes_merlin2					ar9280Modes_9280_2
#define ar9280Common_merlin2					ar9280Common_9280_2
#define ar9280Modes_fast_clock_merlin2				ar9280Modes_fast_clock_9280_2
#define ar9280Modes_backoff_23db_rxgain_merlin2			ar9280Modes_backoff_23db_rxgain_9280_2
#define ar9280Modes_original_rxgain_merlin2			ar9280Modes_original_rxgain_9280_2
#define ar9280Modes_backoff_13db_rxgain_merlin2			ar9280Modes_backoff_13db_rxgain_9280_2
#define ar9280Modes_high_power_tx_gain_merlin2			ar9280Modes_high_power_tx_gain_9280_2
#define ar9280Modes_original_tx_gain_merlin2			ar9280Modes_original_tx_gain_9280_2
#define ar9280Modes_mixed_power_tx_gain_merlin2			ar9280Modes_mixed_power_tx_gain_9280_2
#define ar9280PciePhy_clkreq_off_L1_merlin			ar9280PciePhy_clkreq_off_L1_9280
#define ar9280PciePhy_clkreq_always_on_L1_merlin		ar9280PciePhy_clkreq_always_on_L1_9280
#define ar9280PciePhy_AWOW_merlin				ar9280PciePhy_AWOW_9280

#include "ar9280_merlin2.ini"

#define ar9285PciePhy_clkreq_always_on_L1_kite			ar9285PciePhy_clkreq_always_on_L1_9285
#define ar9285PciePhy_clkreq_off_L1_kite			ar9285PciePhy_clkreq_off_L1_9285

#include "ar9285.ini"

#define ar9285Modes_kite1_2					ar9285Modes_9285_1_2
#define ar9285Common_kite1_2					ar9285Common_9285_1_2
#define ar9285Modes_high_power_tx_gain_kite1_2			ar9285Modes_high_power_tx_gain_9285_1_2
#define ar9285Modes_original_tx_gain_kite1_2			ar9285Modes_original_tx_gain_9285_1_2
#define ar9285PciePhy_clkreq_always_on_L1_kite1_2		ar9285PciePhy_clkreq_always_on_L1_9285_1_2
#define ar9285PciePhy_clkreq_off_L1_kite1_2			ar9285PciePhy_clkreq_off_L1_9285_1_2
#define ar9285PciePhy_AWOW_kite1_2				ar9285PciePhy_AWOW_9285_1_2

#define ar9285Modes_Elijah2_0_normal_power			ar9285Modes_XE2_0_normal_power
#define ar9285Modes_Elijah2_0_high_power			ar9285Modes_XE2_0_high_power

#include "ar9285_v1_2.ini"

#define ar9287PciePhy_AWOW_kiwi1_0				ar9287PciePhy_AWOW_9287_1_0

#include "ar9287.ini"

#define ar9287Modes_kiwi1_1					ar9287Modes_9287_1_1
#define ar9287Common_kiwi1_1					ar9287Common_9287_1_1
#define ar9287Common_normal_cck_fir_coeff_kiwi1_1		ar9287Common_normal_cck_fir_coeff_9287_1_1
#define ar9287Common_japan_2484_cck_fir_coeff_kiwi1_1		ar9287Common_japan_2484_cck_fir_coeff_9287_1_1
#define ar9287Modes_tx_gain_kiwi1_1				ar9287Modes_tx_gain_9287_1_1
#define ar9287Modes_rx_gain_kiwi1_1				ar9287Modes_rx_gain_9287_1_1
#define ar9287PciePhy_clkreq_always_on_L1_kiwi1_1		ar9287PciePhy_clkreq_always_on_L1_9287_1_1
#define ar9287PciePhy_clkreq_off_L1_kiwi1_1			ar9287PciePhy_clkreq_off_L1_9287_1_1
#define ar9287PciePhy_AWOW_kiwi1_1				ar9287PciePhy_AWOW_9287_1_1

#include "ar9287_1_1.ini"

#define ar9271Modes_K2						ar9271Modes_9271
#define ar9271Common_K2						ar9271Common_9271
#define ar9271Common_normal_cck_fir_coeff_K2			ar9271Common_normal_cck_fir_coeff_9271
#define ar9271Common_japan_2484_cck_fir_coeff_K2		ar9271Common_japan_2484_cck_fir_coeff_9271
#define ar9271Modes_K2_1_0_only					ar9271Modes_9271_1_0_only
#define ar9271Modes_K2_ANI_reg					ar9271Modes_9271_ANI_reg
#define ar9271Modes_normal_power_tx_gain_K2			ar9271Modes_normal_power_tx_gain_9271
#define ar9271Modes_high_power_tx_gain_K2			ar9271Modes_high_power_tx_gain_9271

#include "ar9271.ini"


/* This is what these are called on the Atheros HAL */

/* AR9003 2.2 */
#define ar9300_osprey_2p2_radio_postamble			ar9300_2p2_radio_postamble
#define ar9300_modes_lowest_ob_db_tx_gain_table_osprey_2p2	ar9300Modes_lowest_ob_db_tx_gain_table_2p2
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
#define ar9300_common_rx_gain_table_osprey_2p2			ar9300Common_rx_gain_table_2p2
#define ar9300Modes_low_ob_db_tx_gain_table_osprey_2p2		ar9300Modes_low_ob_db_tx_gain_table_2p2
#define ar9300_osprey_2p2_mac_core				ar9300_2p2_mac_core
#define ar9300Common_wo_xlna_rx_gain_table_osprey_2p2		ar9300Common_wo_xlna_rx_gain_table_2p2
#define ar9300_osprey_2p2_soc_preamble				ar9300_2p2_soc_preamble
#define ar9300PciePhy_pll_on_clkreq_disable_L1_osprey_2p2	ar9300PciePhy_pll_on_clkreq_disable_L1_2p2
#define ar9300PciePhy_clkreq_enable_L1_osprey_2p2		ar9300PciePhy_clkreq_enable_L1_2p2
#define ar9300PciePhy_clkreq_disable_L1_osprey_2p2		ar9300PciePhy_clkreq_disable_L1_2p2

#include "ar9300_osprey22.ini"

#define ar9331_modes_lowest_ob_db_tx_gain_hornet1_1		ar9331_modes_lowest_ob_db_tx_gain_1p1
#define ar9331_hornet1_1_baseband_postamble			ar9331_1p1_baseband_postamble
#define ar9331_modes_high_ob_db_tx_gain_hornet1_1		ar9331_modes_high_ob_db_tx_gain_1p1
#define ar9331_modes_low_ob_db_tx_gain_hornet1_1		ar9331_modes_low_ob_db_tx_gain_1p1
#define ar9331_hornet1_1_baseband_core_txfir_coeff_japan_2484	ar9331_1p1_baseband_core_txfir_coeff_japan_2484
#define ar9331_hornet1_1_xtal_25M				ar9331_1p1_xtal_25M
#define ar9331_hornet1_1_radio_core				ar9331_1p1_radio_core
#define ar9331_hornet1_1_soc_postamble				ar9331_1p1_soc_postamble
#define ar9331_common_wo_xlna_rx_gain_hornet1_1			ar9331_common_wo_xlna_rx_gain_1p1
#define ar9331_hornet1_1_baseband_core				ar9331_1p1_baseband_core
#define ar9331_modes_high_power_tx_gain_hornet1_1		ar9331_modes_high_power_tx_gain_1p1
#define ar9331_hornet1_1_mac_postamble				ar9331_1p1_mac_postamble
#define ar9331_hornet1_1_soc_preamble				ar9331_1p1_soc_preamble
#define ar9331_hornet1_1_xtal_40M				ar9331_1p1_xtal_40M
#define ar9331_hornet1_1_mac_core				ar9331_1p1_mac_core
#define ar9331_common_rx_gain_hornet1_1				ar9331_common_rx_gain_1p1
#define ar9331_common_tx_gain_offset1_1				ar9331_common_tx_gain_offset1_1
#define ar9331_hornet1_1_chansel_xtal_25M			ar9331_1p1_chansel_xtal_25M
#define ar9331_hornet1_1_chansel_xtal_40M			ar9331_1p1_chansel_xtal_40M

#include "ar9330_11.ini"

#define ar9331_modes_lowest_ob_db_tx_gain_hornet1_2		ar9331_modes_lowest_ob_db_tx_gain_1p2
#define ar9331_hornet1_2_baseband_postamble			ar9331_1p2_baseband_postamble
#define ar9331_modes_high_ob_db_tx_gain_hornet1_2		ar9331_modes_high_ob_db_tx_gain_1p2
#define ar9331_modes_low_ob_db_tx_gain_hornet1_2		ar9331_modes_low_ob_db_tx_gain_1p2
#define ar9331_hornet1_2_baseband_core_txfir_coeff_japan_2484	ar9331_1p2_baseband_core_txfir_coeff_japan_2484
#define ar9331_hornet1_2_xtal_25M				ar9331_1p2_xtal_25M
#define ar9331_hornet1_2_radio_core				ar9331_1p2_radio_core
#define ar9331_hornet1_2_soc_postamble				ar9331_1p2_soc_postamble
#define ar9331_common_wo_xlna_rx_gain_hornet1_2			ar9331_common_wo_xlna_rx_gain_1p2
#define ar9331_hornet1_2_baseband_core				ar9331_1p2_baseband_core
#define ar9331_modes_high_power_tx_gain_hornet1_2		ar9331_modes_high_power_tx_gain_1p2
#define ar9331_hornet1_2_mac_postamble				ar9331_1p2_mac_postamble
#define ar9331_hornet1_2_soc_preamble				ar9331_1p2_soc_preamble
#define ar9331_hornet1_2_xtal_40M				ar9331_1p2_xtal_40M
#define ar9331_hornet1_2_mac_core				ar9331_1p2_mac_core
#define ar9331_common_rx_gain_hornet1_2				ar9331_common_rx_gain_1p2
#define ar9331_common_tx_gain_offset1_2				ar9331_common_tx_gain_offset1_2

#include "ar9330_12.ini"

#define ar9485Common_poseidon1_0				ar9485Common_1_0
#define ar9485_poseidon1_0_mac_postamble			ar9485_1_0_mac_postamble
#define ar9485_poseidon1_0_pcie_phy_pll_on_clkreq_disable_L1	ar9485_1_0_pcie_phy_pll_on_clkreq_disable_L1
#define ar9485Common_wo_xlna_rx_gain_poseidon1_0		ar9485Common_wo_xlna_rx_gain_1_0
#define ar9485Modes_high_power_tx_gain_poseidon1_0		ar9485Modes_high_power_tx_gain_1_0
#define ar9485_poseidon1_0					ar9485_1_0
#define ar9485_poseidon1_0_radio_core				ar9485_1_0_radio_core
#define ar9485Modes_lowest_ob_db_tx_gain_poseidon1_0		ar9485Modes_lowest_ob_db_tx_gain_1_0
#define ar9485_poseidon1_0_baseband_core			ar9485_1_0_baseband_core
#define ar9485Modes_high_ob_db_tx_gain_poseidon1_0		ar9485Modes_high_ob_db_tx_gain_1_0
#define ar9485Common_rx_gain_poseidon1_0			ar9485Common_rx_gain_1_0
#define ar9485_poseidon1_0_pcie_phy_clkreq_enable_L1		ar9485_1_0_pcie_phy_clkreq_enable_L1
#define ar9485_fast_clock_poseidon1_0_baseband_postamble	ar9485_fast_clock_1_0_baseband_postamble
#define ar9485_poseidon1_0_soc_preamble				ar9485_1_0_soc_preamble
#define ar9485_poseidon1_0_baseband_postamble			ar9485_1_0_baseband_postamble
#define ar9485_poseidon1_0_pcie_phy_pll_on_clkreq_enable_L1	ar9485_1_0_pcie_phy_pll_on_clkreq_enable_L1
#define ar9485Modes_low_ob_db_tx_gain_poseidon1_0		ar9485Modes_low_ob_db_tx_gain_1_0
#define ar9485_poseidon1_0_pcie_phy_clkreq_disable_L1		ar9485_1_0_pcie_phy_clkreq_disable_L1
#define ar9485_poseidon1_0_radio_postamble			ar9485_1_0_radio_postamble
#define ar9485_poseidon1_0_mac_core				ar9485_1_0_mac_core

#include "ar9485.ini"

#define ar9300Modes_fast_clock_ar9580_1p0			ar9580_1p0_modes_fast_clock
#define ar9300_ar9580_1p0_radio_postamble			ar9580_1p0_radio_postamble
#define ar9300_ar9580_1p0_baseband_core				ar9580_1p0_baseband_core
#define ar9300_ar9580_1p0_mac_postamble				ar9580_1p0_mac_postamble
#define ar9300Modes_low_ob_db_tx_gain_table_ar9580_1p0		ar9580_1p0_low_ob_db_tx_gain_table
#define ar9300Modes_high_power_tx_gain_table_ar9580_1p0		ar9580_1p0_high_power_tx_gain_table
#define ar9300Modes_lowest_ob_db_tx_gain_table_ar9580_1p0	ar9580_1p0_lowest_ob_db_tx_gain_table
#define ar9300_ar9580_1p0_baseband_core_txfir_coeff_japan_2484	ar9580_1p0_baseband_core_txfir_coeff_japan_2484
#define ar9300_ar9580_1p0_mac_core				ar9580_1p0_mac_core
#define ar9300_modes_mixed_ob_db_tx_gain_table_ar9580_1p0	ar9580_1p0_mixed_ob_db_tx_gain_table
#define ar9300_common_wo_xlna_rx_gain_table_ar9580_1p0		ar9580_1p0_wo_xlna_rx_gain_table
#define ar9300_ar9580_1p0_soc_postamble				ar9580_1p0_soc_postamble
#define ar9300Modes_high_ob_db_tx_gain_table_ar9580_1p0		ar9580_1p0_high_ob_db_tx_gain_table
#define ar9300_ar9580_1p0_soc_preamble				ar9580_1p0_soc_preamble
#define ar9300_common_rx_gain_table_ar9580_1p0			ar9580_1p0_rx_gain_table
#define ar9300_ar9580_1p0_radio_core				ar9580_1p0_radio_core
#define ar9300_ar9580_1p0_baseband_postamble			ar9580_1p0_baseband_postamble
#define ar9300PciePhy_clkreq_enable_L1_ar9580_1p0		ar9580_1p0_pcie_phy_clkreq_enable_L1
#define ar9300PciePhy_clkreq_disable_L1_ar9580_1p0		ar9580_1p0_pcie_phy_clkreq_disable_L1
#define ar9300PciePhy_pll_on_clkreq_disable_L1_ar9580_1p0	ar9580_1p0_pcie_phy_pll_on_clkreq

#include "ar9580.ini"

#endif /* ATHEROS */

#define INI_PRINT(_array) do { \
	if (check) { \
		char *sha1sum; \
		sha1sum = ath9k_hw_check_initval((const u32 *) &_array,\
						ARRAY_SIZE(_array), ARRAY_SIZE((_array)[0])); \
		printf("%s        "#_array"\n", sha1sum); \
	} else { \
		printf("static const u32 "#_array"[][%d] = {\n", (int) ARRAY_SIZE((_array)[0])); \
		ath9k_hw_print_initval((const u32 *) _array, \
				       ARRAY_SIZE(_array), ARRAY_SIZE((_array)[0]), false); \
	} \
    } while (0)

#define INI_PRINT_ONEDIM(_array) do { \
	if (check) { \
		char *sha1sum; \
		sha1sum = ath9k_hw_check_initval((const u32 *) &_array,\
						ARRAY_SIZE(_array), 1); \
		printf("%s        "#_array"\n", sha1sum); \
	} else { \
		printf("static const u32 "#_array"[] = {\n"); \
		ath9k_hw_print_initval((const u32 *) _array, \
				       ARRAY_SIZE(_array), 1, true); \
	} \
    } while (0)

static void print_license(void)
{
	printf("/*\n");
	printf(" * Copyright (c) 2011 Atheros Communications Inc.\n");
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

static u32 ath9k_patch_initval(u32 idx, u32 val)
{
	switch(idx) {
	/* CRC error fix submitted upstream, but not in Atheros initvals yet */
	case 0x00008264:
		val &= ~(1 << 29);
		break;

	default:
		break;
	}

	return val;
}

static void ath9k_hw_print_initval(const u32 *array, u32 rows, u32 columns, bool onedim)
{
	u32 col, row;

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
			u32 idx;
			u32 val;
			if (!col)
				printf("\t%s", onedim ? "" : "{");
			val = array[row * columns + col];
			if (col > 0) {
				idx = array[row * columns];
				val = ath9k_patch_initval(idx, val);
			}
			printf("0x%08x", val);
			if (col + 1 < columns)
				printf(", ");
		}
		printf("%s,\n", onedim ? "" : "}");
	}
	printf("};\n\n");
}

static char *ath9k_hw_check_initval(const u32 *array, u32 rows, u32 columns)
{
	SHA1_CTX ctx;
	unsigned char digest[SHA1_DIGEST_SIZE];
	static char buf[64];
	u32 col, row;

	SHA1_Init(&ctx);
	for (row = 0; row < rows; row++) {
		for (col = 0; col < columns; col++) {
			unsigned char sha1_buf[4];
			u32 val;

			val = array[row * columns + col];

			sha1_buf[0] = (val >> 24) & 0xff;
			sha1_buf[1] = (val >> 16) & 0xff;
			sha1_buf[2] = (val >> 8) & 0xff;
			sha1_buf[3] = val & 0xff;
			SHA1_Update(&ctx, sha1_buf, sizeof(sha1_buf));
		}
	}

	SHA1_Final(&ctx, digest);
	for (col = 0; col < SHA1_DIGEST_SIZE; col++)
		sprintf(&buf[col * 2], "%02x", digest[col]);
	buf[col * 2] = '\0';

	return buf;
}

static void ar5008_hw_print_initvals(bool check)
{
	INI_PRINT(ar5416Modes);
	INI_PRINT(ar5416Common);
	INI_PRINT(ar5416Bank0);
	INI_PRINT(ar5416BB_RfGain);
	INI_PRINT(ar5416Bank1);
	INI_PRINT(ar5416Bank2);
	INI_PRINT(ar5416Bank3);
	INI_PRINT(ar5416Bank6);
	INI_PRINT(ar5416Bank6TPC);
	INI_PRINT(ar5416Bank7);
	INI_PRINT(ar5416Addac);
}

static void ar9001_hw_print_initvals(bool check)
{
	INI_PRINT(ar5416Modes_9100);
	INI_PRINT(ar5416Common_9100);
	INI_PRINT(ar5416Bank0_9100);
	INI_PRINT(ar5416BB_RfGain_9100);
	INI_PRINT(ar5416Bank1_9100);
	INI_PRINT(ar5416Bank2_9100);
	INI_PRINT(ar5416Bank3_9100);
	INI_PRINT(ar5416Bank6_9100);
	INI_PRINT(ar5416Bank6TPC_9100);
	INI_PRINT(ar5416Bank7_9100);
	INI_PRINT(ar5416Addac_9100);
	INI_PRINT(ar5416Modes_9160);
	INI_PRINT(ar5416Common_9160);
	INI_PRINT(ar5416Bank0_9160);
	INI_PRINT(ar5416BB_RfGain_9160);
	INI_PRINT(ar5416Bank1_9160);
	INI_PRINT(ar5416Bank2_9160);
	INI_PRINT(ar5416Bank3_9160);
	INI_PRINT(ar5416Bank6_9160);
	INI_PRINT(ar5416Bank6TPC_9160);
	INI_PRINT(ar5416Bank7_9160);
	INI_PRINT(ar5416Addac_9160);
	INI_PRINT(ar5416Addac_9160_1_1);
}

static void ar9002_hw_print_initvals(bool check)
{
	INI_PRINT(ar9280Modes_9280_2);
	INI_PRINT(ar9280Common_9280_2);
	INI_PRINT(ar9280Modes_fast_clock_9280_2);
	INI_PRINT(ar9280Modes_backoff_23db_rxgain_9280_2);
	INI_PRINT(ar9280Modes_original_rxgain_9280_2);
	INI_PRINT(ar9280Modes_backoff_13db_rxgain_9280_2);
	INI_PRINT(ar9280Modes_high_power_tx_gain_9280_2);
	INI_PRINT(ar9280Modes_original_tx_gain_9280_2);
	INI_PRINT(ar9280PciePhy_clkreq_off_L1_9280);
	INI_PRINT(ar9280PciePhy_clkreq_always_on_L1_9280);
	INI_PRINT(ar9285PciePhy_clkreq_always_on_L1_9285);
	INI_PRINT(ar9285PciePhy_clkreq_off_L1_9285);
	INI_PRINT(ar9285Modes_9285_1_2);
	INI_PRINT(ar9285Common_9285_1_2);
	INI_PRINT(ar9285Modes_high_power_tx_gain_9285_1_2);
	INI_PRINT(ar9285Modes_original_tx_gain_9285_1_2);
	INI_PRINT(ar9285Modes_XE2_0_normal_power);
	INI_PRINT(ar9285Modes_XE2_0_high_power);
	INI_PRINT(ar9285PciePhy_clkreq_always_on_L1_9285_1_2);
	INI_PRINT(ar9285PciePhy_clkreq_off_L1_9285_1_2);
	INI_PRINT(ar9287Modes_9287_1_1);
	INI_PRINT(ar9287Common_9287_1_1);
	INI_PRINT(ar9287Common_normal_cck_fir_coeff_9287_1_1);
	INI_PRINT(ar9287Common_japan_2484_cck_fir_coeff_9287_1_1);
	INI_PRINT(ar9287Modes_tx_gain_9287_1_1);
	INI_PRINT(ar9287Modes_rx_gain_9287_1_1);
	INI_PRINT(ar9287PciePhy_clkreq_always_on_L1_9287_1_1);
	INI_PRINT(ar9287PciePhy_clkreq_off_L1_9287_1_1);
	INI_PRINT(ar9271Modes_9271);
	INI_PRINT(ar9271Common_9271);
	INI_PRINT(ar9271Common_normal_cck_fir_coeff_9271);
	INI_PRINT(ar9271Common_japan_2484_cck_fir_coeff_9271);
	INI_PRINT(ar9271Modes_9271_1_0_only);
	INI_PRINT(ar9271Modes_9271_ANI_reg);
	INI_PRINT(ar9271Modes_normal_power_tx_gain_9271);
	INI_PRINT(ar9271Modes_high_power_tx_gain_9271);
}

static void ar9003_2p2_hw_print_initvals(bool check)
{
	INI_PRINT(ar9300_2p2_radio_postamble);
	INI_PRINT(ar9300Modes_lowest_ob_db_tx_gain_table_2p2);
	INI_PRINT(ar9300Modes_fast_clock_2p2);
	INI_PRINT(ar9300_2p2_radio_core);
	INI_PRINT(ar9300Common_rx_gain_table_merlin_2p2);
	INI_PRINT(ar9300_2p2_mac_postamble);
	INI_PRINT(ar9300_2p2_soc_postamble);
	INI_PRINT(ar9200_merlin_2p2_radio_core);
	INI_PRINT(ar9300_2p2_baseband_postamble);
	INI_PRINT(ar9300_2p2_baseband_core);
	INI_PRINT(ar9300Modes_high_power_tx_gain_table_2p2);
	INI_PRINT(ar9300Modes_high_ob_db_tx_gain_table_2p2);
	INI_PRINT(ar9300Common_rx_gain_table_2p2);
	INI_PRINT(ar9300Modes_low_ob_db_tx_gain_table_2p2);
	INI_PRINT(ar9300_2p2_mac_core);
	INI_PRINT(ar9300Common_wo_xlna_rx_gain_table_2p2);
	INI_PRINT(ar9300_2p2_soc_preamble);
	INI_PRINT(ar9300PciePhy_pll_on_clkreq_disable_L1_2p2);
	INI_PRINT(ar9300PciePhy_clkreq_enable_L1_2p2);
	INI_PRINT(ar9300PciePhy_clkreq_disable_L1_2p2);
}

static void ar9330_1p1_hw_print_initvals(bool check)
{
	INI_PRINT(ar9331_1p1_baseband_postamble);
	INI_PRINT(ar9331_modes_lowest_ob_db_tx_gain_1p1);
	INI_PRINT(ar9331_modes_high_ob_db_tx_gain_1p1);
	INI_PRINT(ar9331_modes_low_ob_db_tx_gain_1p1);
	INI_PRINT(ar9331_1p1_baseband_core_txfir_coeff_japan_2484);
	INI_PRINT(ar9331_1p1_xtal_25M);
	INI_PRINT(ar9331_1p1_radio_core);
	INI_PRINT(ar9331_1p1_soc_postamble);
	INI_PRINT(ar9331_common_wo_xlna_rx_gain_1p1);
	INI_PRINT(ar9331_1p1_baseband_core);
	INI_PRINT(ar9331_modes_high_power_tx_gain_1p1);
	INI_PRINT(ar9331_1p1_mac_postamble);
	INI_PRINT(ar9331_1p1_soc_preamble);
	INI_PRINT(ar9331_1p1_xtal_40M);
	INI_PRINT(ar9331_1p1_mac_core);
	INI_PRINT(ar9331_common_rx_gain_1p1);
	INI_PRINT(ar9331_common_tx_gain_offset1_1);
	INI_PRINT_ONEDIM(ar9331_1p1_chansel_xtal_25M);
	INI_PRINT_ONEDIM(ar9331_1p1_chansel_xtal_40M);
}

static void ar9330_1p2_hw_print_initvals(bool check)
{
	INI_PRINT(ar9331_modes_lowest_ob_db_tx_gain_1p2);
	INI_PRINT(ar9331_1p2_baseband_postamble);
	INI_PRINT(ar9331_modes_high_ob_db_tx_gain_1p2);
	INI_PRINT(ar9331_modes_low_ob_db_tx_gain_1p2);
	INI_PRINT(ar9331_1p2_baseband_core_txfir_coeff_japan_2484);
	INI_PRINT(ar9331_1p2_xtal_25M);
	INI_PRINT(ar9331_1p2_radio_core);
	INI_PRINT(ar9331_1p2_soc_postamble);
	INI_PRINT(ar9331_common_wo_xlna_rx_gain_1p2);
	INI_PRINT(ar9331_1p2_baseband_core);
	INI_PRINT(ar9331_modes_high_power_tx_gain_1p2);
	INI_PRINT(ar9331_1p2_mac_postamble);
	INI_PRINT(ar9331_1p2_soc_preamble);
	INI_PRINT(ar9331_1p2_xtal_40M);
	INI_PRINT(ar9331_1p2_mac_core);
	INI_PRINT(ar9331_common_rx_gain_1p2);
}

static void ar9485_hw_print_initvals(bool check)
{
	INI_PRINT(ar9485Common_1_0);
	INI_PRINT(ar9485_1_0_mac_postamble);
	INI_PRINT(ar9485_1_0_pcie_phy_pll_on_clkreq_disable_L1);
	INI_PRINT(ar9485Common_wo_xlna_rx_gain_1_0);
	INI_PRINT(ar9485Modes_high_power_tx_gain_1_0);
	INI_PRINT(ar9485_1_0);
	INI_PRINT(ar9485_1_0_radio_core);
	INI_PRINT(ar9485Modes_lowest_ob_db_tx_gain_1_0);
	INI_PRINT(ar9485_1_0_baseband_core);
	INI_PRINT(ar9485Modes_high_ob_db_tx_gain_1_0);
	INI_PRINT(ar9485Common_rx_gain_1_0);
	INI_PRINT(ar9485_1_0_pcie_phy_pll_on_clkreq_enable_L1);
	INI_PRINT(ar9485_1_0_pcie_phy_clkreq_enable_L1);
	INI_PRINT(ar9485_1_0_soc_preamble);
	INI_PRINT(ar9485_fast_clock_1_0_baseband_postamble);
	INI_PRINT(ar9485_1_0_baseband_postamble);
	INI_PRINT(ar9485Modes_low_ob_db_tx_gain_1_0);
	INI_PRINT(ar9485_1_0_pcie_phy_clkreq_disable_L1);
	INI_PRINT(ar9485_1_0_radio_postamble);
	INI_PRINT(ar9485_1_0_mac_core);
}

static void ar9580_1p0_hw_print_initvals(bool check)
{
	INI_PRINT(ar9580_1p0_modes_fast_clock);
	INI_PRINT(ar9580_1p0_radio_postamble);
	INI_PRINT(ar9580_1p0_baseband_core);
	INI_PRINT(ar9580_1p0_mac_postamble);
	INI_PRINT(ar9580_1p0_low_ob_db_tx_gain_table);
	INI_PRINT(ar9580_1p0_high_power_tx_gain_table);
	INI_PRINT(ar9580_1p0_lowest_ob_db_tx_gain_table);
	INI_PRINT(ar9580_1p0_baseband_core_txfir_coeff_japan_2484);
	INI_PRINT(ar9580_1p0_mac_core);
	INI_PRINT(ar9580_1p0_mixed_ob_db_tx_gain_table);
	INI_PRINT(ar9580_1p0_wo_xlna_rx_gain_table);
	INI_PRINT(ar9580_1p0_soc_postamble);
	INI_PRINT(ar9580_1p0_high_ob_db_tx_gain_table);
	INI_PRINT(ar9580_1p0_soc_preamble);
	INI_PRINT(ar9580_1p0_rx_gain_table);
	INI_PRINT(ar9580_1p0_radio_core);
	INI_PRINT(ar9580_1p0_baseband_postamble);
	INI_PRINT(ar9580_1p0_pcie_phy_clkreq_enable_L1);
	INI_PRINT(ar9580_1p0_pcie_phy_clkreq_disable_L1);
	INI_PRINT(ar9580_1p0_pcie_phy_pll_on_clkreq);
}

static void usage()
{
	printf("Usage: initvals [-w] [-f ar5008 | ar9001 | ar9002 | ar9003-2p2 | ar9330-1p1 | ar9330-1p2 | ar9485 | ar9580-1p0 ]\n");
}

static void print_initvals_family(char *family, bool check)
{
	if (!check)
		print_license();

	if (strncmp(family, "ar5008", 6) == 0)
		ar5008_hw_print_initvals(check);
	else if (strncmp(family, "ar9001", 6) == 0)
		ar9001_hw_print_initvals(check);
	else if (strncmp(family, "ar9002", 6) == 0)
		ar9002_hw_print_initvals(check);
	else if (strncmp(family, "ar9003-2p2", 10) == 0) {
		if (!check) {
			printf("#ifndef INITVALS_9003_2P2_H\n");
			printf("#define INITVALS_9003_2P2_H\n");
			printf("\n");
			printf("/* AR9003 2.2 */\n");
			printf("\n");
		}
		ar9003_2p2_hw_print_initvals(check);
		if (!check)
			printf("#endif /* INITVALS_9003_2P2_H */\n");
	} else if (strncmp(family, "ar9330-1p1", 10) == 0) {
		if (!check) {
			printf("#ifndef INITVALS_9330_1P1_H\n");
			printf("#define INITVALS_9330_1P1_H\n");
			printf("\n");
		}
		ar9330_1p1_hw_print_initvals(check);
		if (!check)
			printf("#endif /* INITVALS_9330_1P1_H */\n");
	} else if (strncmp(family, "ar9330-1p2", 10) == 0) {
		if (!check) {
			printf("#ifndef INITVALS_9330_1P2_H\n");
			printf("#define INITVALS_9330_1P2_H\n");
			printf("\n");
		}
		ar9330_1p2_hw_print_initvals(check);
		if (!check)
			printf("#endif /* INITVALS_9330_1P2_H */\n");
	} else if (strncmp(family, "ar9485", 6) == 0) {
		if (!check) {
			printf("#ifndef INITVALS_9485_H\n");
			printf("#define INITVALS_9485_H\n");
			printf("\n");
			printf("/* AR9485 1.0 */\n");
			printf("\n");
		}
		ar9485_hw_print_initvals(check);
		if (!check)
			printf("#endif /* INITVALS_9485_H */\n");
	} else if (strncmp(family, "ar9580-1p0", 10) == 0) {
		if (!check) {
			printf("#ifndef INITVALS_9580_1P0_H\n");
			printf("#define INITVALS_9580_1P0_H\n");
			printf("\n");
			printf("/* AR9580 1.0 */\n");
			printf("\n");
		}
		ar9580_1p0_hw_print_initvals(check);
		if (!check)
			printf("#endif /* INITVALS_9580_1P0_H */\n");
	}
}

int main(int argc, char *argv[])
{

	if (argc > 1) {
		if (argc == 2) {
			if (strncmp(argv[1], "-w", 2) != 0)
				return -1;

			ar5008_hw_print_initvals(false);
			ar9001_hw_print_initvals(false);
			ar9002_hw_print_initvals(false);
			ar9003_2p2_hw_print_initvals(false);
			ar9330_1p1_hw_print_initvals(false);
			ar9330_1p2_hw_print_initvals(false);
			ar9485_hw_print_initvals(false);
			ar9580_1p0_hw_print_initvals(false);

			return 0;
		}

		if (argc != 3 && argc != 4) {
			usage();
			return -1;
		}

		if (argc == 3) {
			print_initvals_family(argv[2], true);
			return 0;
		}

		if (strncmp(argv[1], "-w", 2) != 0)
			return -1;

		print_initvals_family(argv[3], false);

		return 0;
	}

	ar5008_hw_print_initvals(true);
	ar9001_hw_print_initvals(true);
	ar9002_hw_print_initvals(true);
	ar9003_2p2_hw_print_initvals(true);
	ar9330_1p1_hw_print_initvals(true);
	ar9330_1p2_hw_print_initvals(true);
	ar9485_hw_print_initvals(true);
	ar9580_1p0_hw_print_initvals(true);

	return 0;
}
