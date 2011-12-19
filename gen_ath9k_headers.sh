#!/bin/sh

gen_ath9k_header()
{
	local family="$1"
	local ath9k_hdr

	case $family in
	ar5008 |\
	ar9001 |\
	ar9002 |\
	ar9003-2p2|\
	ar9330-1p1|\
	ar9330-1p2|\
	ar9485|\
	ar9580-1p0)
		ath9k_hdr="$(echo $family | tr '-' '_')_initvals.h"
		;;
	*)
		echo "unknown family: '$family'" 1>&2
		return 1
		;;
	esac

	echo "$family => $ath9k_hdr"
	./initvals -w -f $family > "./$ath9k_hdr"
}

FAMILIES="$@"
[ -z "$FAMILIES" ] && FAMILIES="ar5008 ar9001 ar9002 ar9003-2p2 ar9330-1p1 ar9330-1p2 ar9485 ar9580-1p0"

make clean all ATHEROS=1 >/dev/null

for family in $FAMILIES; do
	gen_ath9k_header $family
done
