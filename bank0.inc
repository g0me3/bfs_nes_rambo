
		ORG $8000

		ECHO "PROGRAM BEGIN"
		ECHO "-------------"

		BANK_START $00

		SECTION_START
		INCLUDE	"../levels/levelsA.inc"
		SECTION_END "LEVEL DATA A"

		SECTION_START
		INCLUDE	"../mus/apu_mus03.inc"
		INCLUDE	"../mus/apu_mus0D.inc"
		INCLUDE	"../mus/apu_mus0F.inc"
		INCLUDE	"../mus/apu_mus0A.inc"
		INCLUDE	"../mus/apu_mus0B.inc"
		SECTION_END "MUSIC DATA A"

		BANK_END 0,$C000
