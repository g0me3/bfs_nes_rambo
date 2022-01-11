
		ORG $8000

		BANK_START $03

		SECTION_START
_chr_spr_data:
		INCLUDE "../chr/sprites0.inc"
		SECTION_END "CHR SPRITES A"

		BANK_END 3,$C000
