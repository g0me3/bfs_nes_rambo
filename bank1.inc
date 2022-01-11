
		ORG $8000

		BANK_START $01

		SECTION_START
_location_room_map_libB:
		INCLUDE	"../levels/levelsB.inc"
		SECTION_END "LEVEL DATA B"

		SECTION_START
		INCLUDE	"../mus/apu_mus04.inc"
		INCLUDE	"../mus/apu_mus0E.inc"
		INCLUDE	"../mus/apu_mus02.inc"
		INCLUDE	"../mus/apu_mus09.inc"
		SECTION_END "MUSIC DATA B"

		BANK_END 1,$C000
