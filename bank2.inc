
		ORG $8000

		BANK_START $02

		SECTION_START
_chr_bg_data:
		INCLUDE "..\chr\bg0.inc"
		INCLUDE "..\chr\bg1.inc"
		INCLUDE "..\chr\bg2.inc"
		INCLUDE "..\chr\heli.inc"
#if LANGUAGE == LANG_US
		INCLUDE "..\chr\font_us.inc"
#endif
#if LANGUAGE == LANG_JP
		INCLUDE "..\chr\font_jp.inc"
#endif
		SECTION_END "CHR BG DATA AND FONTS"

		BANK_END 2,$C000
