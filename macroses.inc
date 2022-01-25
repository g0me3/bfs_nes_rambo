
;-------------C-O-N-S-T-A-N-T-S-----------------

DEBUG			EQU		0
OPTIMIZATION	EQU		0
BUGFIXES		EQU		0

LANG_US			EQU		0
LANG_JP			EQU		1
LANR_RU			EQU		2

LANGUAGE		EQU		LANG_US

FRAME_UP_OFS	EQU		$2062
FRAME_DOWN_OFS	EQU		$21E2
FRAME_WIDTH		EQU		$1C
FRAME_HEIGHT	EQU		$0C

#if LANGUAGE == LANG_JP
CLEAR_UP_OFS	EQU		$208A
CLEAR_DOWN_OFS	EQU		$2204
CLEAR_WIDTH		EQU		$13
CLEAR_HEIGHT	EQU		$0A

MSG_UP_OFS		EQU		$20AA
MSG_DOWN_OFS	EQU		$2224

PORTR_UP_X		EQU		$20
PORTR_UP_Y		EQU		$30
PORTR_DOWN_X	EQU		$C0
PORTR_DOWN_Y	EQU		$90

PASS_CHAR_GAP	EQU		$1A
#endif

#if LANGUAGE == LANG_US
CLEAR_UP_OFS	EQU		$208A-1
CLEAR_DOWN_OFS	EQU		$2204-1
CLEAR_WIDTH		EQU		$13+2
CLEAR_HEIGHT	EQU		$0A

MSG_UP_OFS		EQU		$20AA-1
MSG_DOWN_OFS	EQU		$2224-1

PORTR_UP_X		EQU		$20-4
PORTR_UP_Y		EQU		$30-4
PORTR_DOWN_X	EQU		$C0+8+4
PORTR_DOWN_Y	EQU		$90-4

PASS_CHAR_GAP	EQU		$24
#endif

MOUTH_UP_X		EQU		PORTR_UP_X
MOUTH_UP_Y		EQU		PORTR_UP_Y+$18
MOUTH_DOWN_X	EQU		PORTR_DOWN_X
MOUTH_DOWN_Y	EQU		PORTR_DOWN_Y+$18

PORTR00_RAMBO			EQU	$00
PORTR01_RAMBO_ANGRY		EQU	$09
PORTR02_RAMBO_HAPPY		EQU	$12
PORTR03_CO				EQU	$1B
PORTR04_CO_HAPPY		EQU	$24
PORTR05_CO_SAD			EQU	$2D
PORTR06_CO_DEAD			EQU	$36
PORTR07_BANKS_POW		EQU	$3F
PORTR08_TRAUMAN			EQU	$48
PORTR09_MURDOCK			EQU	$51
PORTR0A_MURDOCK_ANGRY	EQU	$5A
PORTR0B_MURDOCK_SAD		EQU	$63
PORTR0C_TRAUMAN_SAD		EQU	$6C
PORTR0D_ERICSON			EQU	$75
PORTR0E_PADOVSKY		EQU	$7E
PORTR0F_YUSIN			EQU	$87
PORTR10_SOLDIER1		EQU	$90
PORTR11_SOLDIER2		EQU	$99
PORTR12_VILLAGER1		EQU	$A2
PORTR13_VILLAGER2		EQU	$AB
PORTR14_PIRATE			EQU	$B4
PORTR15_KID				EQU	$BD
SPR_PACK_IN_TIME		EQU	[_spr_pack_int_time-_portraits_lib]
SPR_TITLE_SCREEN		EQU	[_spr_title_anim-_portraits_lib]
PORTR_CLEAR				EQU	$D8

FLAG00_SYS					EQU	$00	; _flags & 01
FLAG01_SYS					EQU	$01	; _flags & 02
FLAG02_KID_SAVED			EQU	$02	; _flags & 04
FLAG03_LAMP_ITEM			EQU	$03	; _flags & 08
FLAG04_KID_TAKEN			EQU	$04	; _flags & 10
FLAG05_PHOTO_ITEM			EQU	$05	; _flags & 20
FLAG06_POW_TAKEN			EQU	$06	; _flags & 40
FLAG07_DRESS_ITEM			EQU	$07	; _flags & 80

FLAG08_SYS					EQU	$08	; _flags+1 & 01
FLAG09_CO_TAKEN				EQU	$09	; _flags+1 & 02
FLAG0A_MISSION_TIME_OVER	EQU	$0A	; _flags+1 & 04
;FLAG0B_SYS					EQU	$0B	; _flags+1 & 08
FLAG0C_SYS					EQU	$0C	; _flags+1 & 10
FLAG0D_SYS					EQU	$0D	; _flags+1 & 20
FLAG0E_BOAT					EQU	$0E	; _flags+1 & 40
;FLAG0F_SYS					EQU	$0F	; _flags+1 & 80

FLAG10_HELI_KEY				EQU	$10	; _flags+2 & 01
FLAG11_PEDANT				EQU	$11	; _flags+2 & 02
FLAG12_BANDANA				EQU	$12	; _flags+2 & 04
FLAG13_SYS					EQU	$13	; _flags+2 & 08
FLAG14_FLY_FORTRESS_DEAD	EQU	$14	; _flags+2 & 10
;FLAG15_SYS					EQU	$15	; _flags+2 & 20
;FLAG16_SYS					EQU	$16	; _flags+2 & 40
FLAG17_INVINCIBILITY		EQU	$17	; _flags+2 & 80

SEP01	EQU	01*4
SEP02	EQU	02*4
SEP03	EQU	03*4
SEP04	EQU	04*4
SEP05	EQU	05*4

SEN01	EQU	01*4
SEN02	EQU	02*4
SEN03	EQU	03*4
SEN04	EQU	04*4
SEN05	EQU	05*4
SEN06	EQU	06*4
SEN07	EQU	07*4

;-------------------F-O-N-T-S-------------------

#if LANGUAGE == LANG_US
	INCLUDE "../script/font_us.inc"
#endif
#if LANGUAGE == LANG_JP
	INCLUDE "../script/font_jp.inc"
#endif

;--------------------A-P-U----------------------

;--------------D-E-B-U-G-G-I-N-G----------------

;------------S-T-R-U-C-T-U-R-E-S----------------

	MAC	_tarray
{1}		SET	.
		DS	{2}
{1}_end	SET	.
{1}_size SET [{1}_end-{1}]
	ENDM

	MAC	_tobjA
_tobjA					SET	$00
{1}						SET	.
_tobjA._hndl_idx		SET	_tobjA + 0
{1}._hndl_idx:			.BYTE 0
_tobjA._anim_phase_idx	SET	_tobjA + 1
{1}._anim_phase_idx:	.BYTE 0
_tobjA.field_2			SET	_tobjA + 2
{1}.field_2:			.BYTE 0
_tobjA._room_num		SET	_tobjA + 3
{1}._room_num:			.BYTE 0
_tobjA._x_pos			SET	_tobjA + 4
{1}._x_pos:				.BYTE 0
_tobjA._y_pos			SET	_tobjA + 5
{1}._y_pos:				.BYTE 0
_tobjA._dir				SET	_tobjA + 6
{1}._dir:				.BYTE 0
_tobjA.field_7			SET	_tobjA + 7
{1}.field_7:			.BYTE 0
_tobjA.field_8			SET	_tobjA + 8
{1}.field_8:			.BYTE 0
_tobjA._collision_box_idx			SET	_tobjA + 9
{1}._collision_box_idx:			.BYTE 0
_tobjA._state			SET	_tobjA + $A
{1}._state:				.BYTE 0			; 04 - floor collision (stand)
										; 80 - hit detected
_tobjA._damage			SET	_tobjA + $B
{1}._damage:			.BYTE 0
_tobjA.field_C			SET	_tobjA + $C
{1}.field_C:			.BYTE 0
_tobjA._anim_phase_cnt	SET	_tobjA + $D
{1}._anim_phase_cnt:	.BYTE 0
_tobjA._prize_idx		SET	_tobjA + $E
{1}._prize_idx:			.BYTE 0
_tobjA._timer			SET	_tobjA + $F
{1}._timer:				.BYTE 0
	ENDM

	MAC _tobjsA
{1}		SET .
		_tobjA {1}._player
		_tobjA {1}._o1
		_tobjA {1}._o2
		_tobjA {1}._o3
		_tobjA {1}._o4
		_tobjA {1}._o5
		_tobjA {1}._o6
		_tobjA {1}._o7
	ENDM

	MAC	_tobjB
_tobjB					SET	$00
{1}						SET	.
_tobjB._hndl_idx		SET	_tobjB + 0
{1}._hndl_idx:			.BYTE 0
_tobjB.field_1			SET	_tobjB + 1
{1}.field_1:			.BYTE 0
_tobjB.field_2			SET	_tobjB + 2
{1}.field_2:			.BYTE 0
_tobjB.field_3			SET	_tobjB + 3
{1}.field_3:			.BYTE 0
_tobjB.field_4			SET	_tobjB + 4
{1}.field_4:			.BYTE 0
_tobjB._damage			SET	_tobjB + 5
{1}._damage:			.BYTE 0
_tobjB.field_6			SET	_tobjB + 6
{1}.field_6:			.BYTE 0
_tobjB.field_7			SET	_tobjB + 7
{1}.field_7:			.BYTE 0
	ENDM

	MAC _tobjsB
{1}		SET .
		_tobjB {1}._o0
		_tobjB {1}._o1
		_tobjB {1}._o2
		_tobjB {1}._o3
		_tobjB {1}._o4
		_tobjB {1}._o5
		_tobjB {1}._o6
		_tobjB {1}._o7
		_tobjB {1}._o8
		_tobjB {1}._o9
		_tobjB {1}._oA
		_tobjB {1}._oB
	ENDM

	MAC	_tapu_chnl
{1}		SET .
{1}._pos:
		.WORD 0
{1}._duty:
		.BYTE 0
{1}._field_3:
		.BYTE 0
{1}._field_4:
		.BYTE 0
{1}._loop:
		.BYTE 0
	ENDM

	MAC	_tapu_chnls
{1}		SET .
	_tapu_chnl	{1}._ch0
	_tapu_chnl	{1}._ch1
	_tapu_chnl	{1}._ch2
	_tapu_chnl	{1}._ch3
	ENDM

;---------------S-C-R-I-P-T-S-------------------
	MAC	BYTE_FETCH
		LDA		(_tmp0D),Y
		INY
	ENDM

	MAC	WORD_FETCH
		BYTE_FETCH
		TAX
		BYTE_FETCH
	ENDM

	MAC	sprite_draw_up
		.BYTE _scr_cmd00_portrait_draw_up_idx,{1}
	ENDM

	MAC	sprite_draw_down
		.BYTE _scr_cmd01_portrait_draw_down_idx,{1}
	ENDM

	MAC	msg_draw_up
		.BYTE _scr_cmd02_msg_draw_up_idx
	ENDM

	MAC	msg_draw_down
		.BYTE _scr_cmd03_msg_draw_down_idx
	ENDM

	MAC	frame_draw_up
		.BYTE _scr_cmd04_frame_draw_up_idx,{1}
	ENDM

	MAC	frame_draw_down
		.BYTE _scr_cmd05_frame_draw_down_idx,{1}
	ENDM

	MAC	frame_draw_custom
		.BYTE _scr_cmd06_frame_draw_custom_idx,{1}>>8,{1}&$FF,{2},{3}
	ENDM

	MAC	msg_input_handler
		.BYTE _scr_cmd07_msg_input_handler_idx
	ENDM

	MAC	input_2_options
		.BYTE _scr_cmd08_input_2_options_idx
	ENDM

	MAC	ptr_load
		.BYTE _scr_cmd0B_ptr_load_idx
		.WORD {1}
	ENDM

	MAC	msg_printf
		.BYTE _scr_cmd0C_msg_draw_custom_idx
		.WORD {1}
	ENDM

	MAC	game_flags_set
		.BYTE _scr_cmd0D_game_flags_set_idx,{1}
	ENDM

	MAC	game_flags_clear
		.BYTE _scr_cmd0E_game_flags_clear_idx,{1}
	ENDM

	MAC	jmp_flags_not_set
		.BYTE _scr_cmd0F_jmp_flag_not_set_idx,{1}
	ENDM

	MAC	jmpne_option
		.BYTE _scr_cmd10_jmpne_option_idx,{1}
	ENDM

	MAC jmp_branch
		.BYTE _scr_cmd11_jmp_branch_idx,_scr_cmd11_jmp_branch_idx
	ENDM

	MAC	------------------
		.BYTE _scr_cmd12_nop_idx,_scr_cmd12_nop_idx
	ENDM

	MAC	jump
		.BYTE _scr_cmd13_jump_idx
		.WORD {1}
	ENDM

	MAC	stop
		.BYTE _scr_cmd14_stop_idx
	ENDM

	MAC	new_warp_set
		.BYTE _scr_cmd15_new_warp_set_idx,{1}
	ENDM

	MAC	heli_warp_set
		.BYTE _scr_cmd16_heli_warp_set_idx,{1}
	ENDM

	MAC	player_pos_set
		.BYTE _scr_cmd17_player_pos_set_idx,{2},{1}
	ENDM

	MAC	pass_input
		.BYTE _scr_cmd19_pass_input_idx
	ENDM

	MAC	game_stats_draw
		.BYTE _scr_cmd1A_game_stats_draw_idx
	ENDM

	MAC	life_restore
		.BYTE _scr_cmd1B_life_restore_idx
	ENDM

	MAC	add_10_knifes
		.BYTE _scr_cmd1C_add_10_knifes_idx
	ENDM

	MAC	add_5_potions
		.BYTE _scr_cmd21_add_5_potions_idx
	ENDM

	MAC	game_hours_set
		.BYTE _scr_cmd23_game_hours_set_idx,{1}
	ENDM

	MAC	checkpoint_restore
		.BYTE _scr_cmd24_checkpoint_restore_idx
	ENDM

	MAC	checkpoint_reset
		.BYTE _scr_cmd25_checkpoint_reset_idx
	ENDM

	MAC	checkpoint_set
		.BYTE _scr_cmd26_checkpoint_set_idx
	ENDM

	MAC	continue_cur_draw
		.BYTE _scr_cmd27_continue_cur_draw_idx
	ENDM

	MAC	ending_anim
		.BYTE _scr_cmd28_ending_anim_idx
	ENDM

	MAC	scroller
		.BYTE _scr_cmd29_scroller_idx
	ENDM

;---------G-A-M-E--S-P-E-C-I-F-I-C--------------

	MAC	FLAG_TEST
		LDA		[_game._flags+[{1}>>3]]
		AND		#[1<<[{1}&7]]
	ENDM

	MAC	FLAGS_TEST
		LDA		[_game._flags+[{1}>>3]]
		AND		#[1<<[{1}&7]]|[1<<[{2}&7]]
	ENDM

	MAC	FLAG_SET
		LDA		[_game._flags+[{1}>>3]]
		ORA		#[1<<[{1}&7]]
		STA		[_game._flags+[{1}>>3]]
	ENDM

	MAC	FLAG_CLEAR
		LDA		[_game._flags+[{1}>>3]]
		AND		#[[1<<[{1}&7]]^$FF]
		STA		[_game._flags+[{1}>>3]]
	ENDM

	MAC	IDX_START
{1}			SET .
IDX_LIST_START	SET	{1}
	ENDM

	MAC	IDX
{1}_idx		SET	[[.-IDX_LIST_START]>>1]
		.WORD {1}
	ENDM

	MAC	APU_IDX
{1}_idx		SET	[[.-_apu_mus_lib]>>1]
		.WORD {1}A,{1}B,{1}C,{1}D
	ENDM

	MAC	OBJ_MAP
#if {4}!=$00
		.BYTE [[{2}<<4]|{1}],[[{3}<<6]|{4}_idx]
#else
		.BYTE [[{2}<<4]|{1}],[[{3}<<6]|$00]
#endif
	ENDM

	MAC	PPU_PUT_CHAR
#if {1}!=0
		LDA		_PPU_STATUS
		LDA		#>[{1}]
		STA		_PPU_ADDR
		LDA		#<[{1}]
		STA		_PPU_ADDR
#endif
		LDA		#{2}
		STA		_PPU_DATA
	ENDM

	MAC	PPU_FILL_LINEY
#if {1}!=0
		LDA		_PPU_STATUS
		LDA		#>[{1}]
		STA		_PPU_ADDR
		LDA		#<[{1}]
		STA		_PPU_ADDR
#endif
		LDA		#{2}
		LDY		#{3}
.1:
		STA		_PPU_DATA
		DEY
		BNE		.1
	ENDM

	MAC	PPU_FILL_LINEX
#if {1}!=0
		LDA		_PPU_STATUS
		LDA		#>[{1}]
		STA		_PPU_ADDR
		LDA		#<[{1}]
		STA		_PPU_ADDR
#endif
		LDA		#{2}
		LDX		#{3}
.1:
		STA		_PPU_DATA
		DEX
		BNE		.1
	ENDM

	MAC	PPU_FILL_RECT
#if {1}!=0
		LDA		_PPU_STATUS
		LDA		#>[{1}]
		STA		_PPU_ADDR
		LDA		#<[{1}]
		STA		_PPU_ADDR
#endif
		LDA		#{2}
		LDY		#{3}
.1:
		LDX		#{4}
.2:
		STA		_PPU_DATA
		DEX
		BNE		.2
		DEY
		BNE		.1
	ENDM

;----------------C-O-M-M-O-N--------------------

	MAC BANK_START
CUR_PRG_BANK	SET {1}
CUR_BANK_START	SET .
CUR_SEC_START	SET $FFFFFFFF
		ECHO "BANK",CUR_PRG_BANK," ORG ",[CUR_BANK_START>>12],"{"
	ENDM

STUB_SIZE		EQU	0
LAST_STUB_SIZE	EQU	6

	MAC	BANK_END
	#if {1}=$00
_total_free	SET 0
	#endif
_bank{1}_free	SET	[{2}-.-STUB_SIZE]
_total_free	SET [_total_free+_bank{1}_free]
	#if .>{2}-STUB_SIZE
		ECHO "} s =",[.-CUR_BANK_START],"EXCEEDED =",[0-_bank{1}_free]
	#else
		ECHO "} s =",[.-CUR_BANK_START],"FREE =",_bank{1}_free
	#endif
	#if .<{2}-STUB_SIZE
		ORG		{2}-STUB_SIZE-1
		.BYTE	$FF
	#endif
	ENDM

	MAC	LAST_BANK_END
_bank{1}_free	SET	[{2}-.-LAST_STUB_SIZE]
_total_free	SET [_total_free+_bank{1}_free]
	#if .>[{2}-LAST_STUB_SIZE]
		ECHO "} s =",[.-CUR_BANK_START],"EXCEEDED =",[0-_bank{1}_free]
	#else
		ECHO "} s =",[.-CUR_BANK_START],"FREE =",_bank{1}_free
	#endif
		ECHO "-------------";
		ECHO "total free =",_total_free
		ECHO ""
	#if .<{2}-LAST_STUB_SIZE
		ORG		{2}-LAST_STUB_SIZE-1
		.BYTE	$FF
	#endif
		ORG		{2}-LAST_STUB_SIZE
		.WORD NMI
		.WORD RESET
		.WORD IRQ
	ENDM

	MAC SECTION_START
#if CUR_SEC_START == $FFFFFFFF
CUR_SEC_START	SET	.
#else
		ECHO "WARNING! previous block isn't closed!"
#endif
	ENDM

	MAC SECTION_END
#if CUR_SEC_START != $FFFFFFFF
_CUR_SEC_END	SET .
		ECHO " * block size =",_CUR_SEC_END-CUR_SEC_START,"[",{1},"]"
CUR_SEC_START	SET $FFFFFFFF
#else
		ECHO "WARNING! there is no block start!"
#endif
	ENDM

;---------------A-R-I-T-H-M---------------------

	; \t\tLDA\t\t(.*)\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t\1\+1\n\t\tSTA\t\t\2\+1\n
	; \t\tMOVW\t\2,\1\n
	;
	MAC	MOVW
		LDA		{2}
		STA		{1}
		LDA		{2}+1
		STA		{1}+1
	ENDM

	MAC	MOVD
		LDA		{2}
		STA		{1}
		LDA		{2}+1
		STA		{1}+1
		LDA		{2}+2
		STA		{1}+2
	ENDM

	; \t\tLDA\t\t#<\[(.*)\]\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t#>\[\1\]\n\t\tSTA\t\t\2\+1\n
	; \t\tMOVWO\t\2,\1\n
	;
	MAC	MOVWO
		LDA		#<[{2}]
		STA		{1}
		LDA		#>[{2}]
		STA		{1}+1
	ENDM

	; \t\tLDA\t\t#\$(..)\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t#\$(..)\n\t\tSTA\t\t\2\+1\n
	; \t\tMOVWI\t\2,$\3\1\n
	;
	MAC	MOVWI
	#if {2}==0
		LDA		#0
		STA		{1}
		STA		{1}+1
	#else
		LDA		#[[{2}>>0]&$FF]
		STA		{1}
		LDA		#[[{2}>>8]&$FF]
		STA		{1}+1
	#endif
	ENDM

	; \t\tLDA\t\t#\$(..)\n\t\tSTA\t\t(.*)\n\t\tLDA\t\t#\$(..)\n\t\tSTA\t\t\2\+1\n\t\tLDA\t\t#\$(..)\n\t\tSTA\t\t\2\+2\n
	; \t\tMOVDI\t\2,$\4\3\1\n
	;
	MAC	MOVDI
	#if {2}==0
		LDA		#0
		STA		{1}
		STA		{1}+1
		STA		{1}+2
	#else
		LDA		#[[{2}>>0 ]&$FF]
		STA		{1}
		LDA		#[[{2}>>8 ]&$FF]
		STA		{1}+1
		LDA		#[[{2}>>16]&$FF]
		STA		{1}+2
	#endif
	ENDM

	; \t\tINC\t\t(.*)\n\t\tBNE\t\t(.*)\n\t\tINC\t\t\1\+1\n\2:\n
	; \t\tINCW\t\1\n\2:
	;
	MAC	INCW
		INC		{1}
		BNE		.1
		INC		{1}+1
.1:
	ENDM

	MAC	ADDB
	#if {2}==#$02
		INC		{1}
		INC		{1}
	#else
		LDA		{1}
		CLC
		ADC		{2}
		STA		{1}
	#endif
	ENDM

	MAC	MADDB
		LDA		{2}
		CLC
		ADC		{3}
		STA		{1}
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tADC\t\t\#\$00\n\t\tSTA\t\t\1\n
	; \t\tADCH\t\1\n
	;
	; adjust high hibble of 16-bit value when 8bit argument added
	;
	MAC	ADCH
		BCC		.1
		INC		{0}
.1:
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tCLC\n\t\tADC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tBCC\t\t(.*)\n\t\tINC\t\t\1\+1\n\3:
	; \t\tADDWB\t\1,\2\n\3:
	;
	MAC	ADDWB
		LDA		{1}
		CLC
		ADC		{2}
		STA		{1}
		BCC		.1
		INC		{1}+1
.1:
	ENDM

	; Add two 16-bit integer or fixed point values and put it
	; in third arg.
	;
	MAC	MADDW
		LDA		{2}
		CLC
		ADC		{3}
		STA		{1}
		LDA		{2}+1
		ADC		{3}+1
		STA		{1}+1
	ENDM

	MAC CMPW
		LDA		{1}
		CMP		{2}
		LDA		{1}+1
		SBC		{2}+1
	ENDM

	MAC CMPWI
		LDA		{1}
		CMP		#[[{2}>>0]&$FF]
		LDA		{1}+1
		SBC		#[[{2}>>8]&$FF]
	ENDM

	MAC	MSUBW
		LDA		{2}
		SEC
		SBC		{3}
		STA		{1}
		LDA		{2}+1
		SBC		{3}+1
		STA		{1}+1
	ENDM

	MAC	SUBB
	#if {2}==#$02
		DEC		{1}
		DEC		{1}
	#else
		LDA		{1}
		SEC
		SBC		{2}
		STA		{1}
	#endif
	ENDM

	MAC	MSUBB
		LDA		{2}
		SEC
		SBC		{3}
		STA		{1}
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t\#\$(..)\n\t\tSTA\t\t\1\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t\#\$(..)\n\t\tSTA\t\t\1\+1\n\t\tBCS\t\t(.*)\n\t\tDEC\t\t\1\+2\n\4\:\n
	; \t\tSUBDI16\t\1,\$\3\2\n\4\:\n
	;
	; Subtract 16-bit Word from 24-bit Dword
	; in third arg.
	;
	MAC	SUBDI16
		LDA		{1}
		SEC
		SBC		#<[{2}]
		STA		{1}
		LDA		{1}+1
		SBC		#>[{2}]
		STA		{1}+1
		BCS		.1
		DEC		{1}+2
.1:
	ENDM

	; \t\tLDA\t\t(.*)\n\t\tSBC\t\t\#\$00\n\t\tSTA\t\t\1\n
	; \t\tSBCH\t\1\n
	;
	; adjust high hibble of 16-bit value when 8bit argument added
	;
	MAC	SBCH
		BCS		.1
		DEC		{0}
.1:
	ENDM


	; \t\tLDA\t\t(.*)\n\t\tSEC\n\t\tSBC\t\t(.*)\n\t\tSTA\t\t\1\n\t\tLDA\t\t\1\+1\n\t\tSBC\t\t\2\+1\n\t\tSTA\t\t\1\+1\n\t\tBCS\t\t(.*)\n\t\tDEC\t\t\1\+2\n\3\:\n
	; \t\tSUBDW\t\1,\2\n\3\:\n
	;
	MAC	SUBDW
		LDA		{1}
		SEC
		SBC		{2}
		STA		{1}
		LDA		{1}+1
		SBC		{2}+1
		STA		{1}+1
		BCS		.1
		DEC		{1}+2
.1:
	ENDM

	MAC	SUBD
		LDA		{1}
		SEC
		SBC		{2}
		STA		{1}
		LDA		{1}+1
		SBC		{2}+1
		STA		{1}+1
		LDA		{1}+2
		SBC		{2}+2
		STA		{1}+2
	ENDM

	MAC	MSUBD
		LDA		{2}
		SEC
		SBC		{3}
		STA		{1}
		LDA		{2}+1
		SBC		{3}+1
		STA		{1}+1
		LDA		{2}+2
		SBC		{3}+2
		STA		{1}+2
	ENDM
