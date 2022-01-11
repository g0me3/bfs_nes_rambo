
		ORG $8000

		BANK_START $04

		SECTION_START
_chr_spr_dataB:
		INCLUDE "../chr/sprites1.inc"
		SECTION_END "CHR SPRITES B"

		BANK_END 4,$C000
