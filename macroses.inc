
;-------------C-O-N-S-T-A-N-T-S-----------------

DEBUG			EQU		0
OPTIMIZATION	EQU		0
BUGFIXES		EQU		0

LANG_EN			EQU		0
LANG_JP			EQU		1
LANR_RU			EQU		2

LANGUAGE		EQU		LANG_EN

_PORTRAIT00_RAMBO		EQU	$00
_PORTRAIT01_RAMBO_ANGRY	EQU	$09
_PORTRAIT02_RAMBO_HAPPY	EQU	$12
_PORTRAIT03_CO			EQU	$1B
_PORTRAIT04_CO_HAPPY	EQU	$24
_PORTRAIT05_CO_SAD		EQU	$2D
_PORTRAIT06_CO_DEAD		EQU	$36
_PORTRAIT07_BANKS_POW	EQU	$3F
_PORTRAIT08_TRAUMAN1	EQU	$48
_PORTRAIT09_MURDOCK		EQU	$51
_PORTRAIT0A_MURDOCK_ANGRY	EQU	$5A
_PORTRAIT0B_MURDOCK_SAD	EQU	$63
_PORTRAIT0C_TRAUMAN2	EQU	$6C
_PORTRAIT0D_ERICSON		EQU	$75
_PORTRAIT0E_PADOVSKY	EQU	$7E
_PORTRAIT0F_YUSIN		EQU	$87
_PORTRAIT10_SOLDIER1	EQU	$90
_PORTRAIT11_SOLDIER2	EQU	$99
_PORTRAIT12_VILLAGER1	EQU	$A2
_PORTRAIT13_VILLAGER2	EQU	$AB
_PORTRAIT14_PIRATE		EQU	$B4
_PORTRAIT15_KID			EQU	$BD
_SPR_PACK_IN_TIME		EQU	$C6
_SPR_TITLE_SCREEN		EQU	$C8
_PORTRAIT_CLEAR			EQU	$D8

_FLAG00_SYS				EQU	$00
_FLAG01_SYS				EQU	$01
_FLAG02_KID_SAVED		EQU	$02
_FLAG03_LAMP_ITEM		EQU	$03
_FLAG04_KID_TAKEN		EQU	$04
_FLAG05_PHOTO_ITEM		EQU	$05
_FLAG06_POW_TAKEN		EQU	$06
_FLAG07_DRESS_ITEM		EQU	$07
_FLAG08_SYS				EQU	$08
_FLAG09_CO_TAKEN		EQU	$09
_FLAG0A_MISSION_TIME_OVER	EQU	$0A
//_FLAG0B_SYS			EQU	$0B
_FLAG0C_SYS				EQU	$0C
_FLAG0D_SYS				EQU	$0D
_FLAG0E_BOAT			EQU	$0E
//_FLAG0F_SYS			EQU	$0F
_FLAG10_HELI_KEY		EQU	$10
_FLAG11_PEDANT			EQU	$11
_FLAG12_BANDANA			EQU	$12
_FLAG13_SYS				EQU	$13
_FLAG14_FLY_FORTRESS_DEAD	EQU	$14

_0	EQU $50
_1	EQU $51
_2	EQU $52
_3	EQU $53
_4	EQU $54
_5	EQU $55
_6	EQU $56
_7	EQU $57
_8	EQU $58
_9	EQU $59
_A	EQU $5A
_B	EQU $5B
_C	EQU $5C
_D	EQU $5D
_E	EQU $5E
_F	EQU $5F

_G	EQU $60
_H	EQU $61
_I	EQU $62
_J	EQU $63
_K	EQU $64
_L	EQU $65
_M	EQU $66
_N	EQU $67
_O	EQU $68
_P	EQU $69
_Q	EQU $6A
_R	EQU $6B
_S	EQU $6C
_T	EQU $6D
_U	EQU $6E
_V	EQU $6F

_W	EQU $70
_X	EQU $71
_Y	EQU $72
_Z	EQU $73
_a	EQU $74
_b	EQU $75
_c	EQU $76
_d	EQU $77
_e	EQU $78
_f	EQU $79
_g	EQU $7A
_h	EQU $7B
_i	EQU $7C
_j	EQU $7D
_k	EQU $7E
_l	EQU $7F

_m	EQU $80
_n	EQU $81
_o	EQU $82
_p	EQU $83
_q	EQU $84
_r	EQU $85
_s	EQU $86
_t	EQU $87
_u	EQU $88
_v	EQU $89
_w	EQU $8A
_x	EQU $8B
_y	EQU $8C
_z	EQU $8D
_qe EQU $8E
_ex	EQU $8F

_ap EQU $90

_cop EQU $E2
_rig EQU $E3
_dot EQU $E4
_col EQU $E5
_ddt EQU $E6
_dsh EQU $E7

_dtt EQU $EE
_ls	EQU $EF
_rs EQU $F0

__	EQU $F1
_eol EQU $FF

;-------------------F-O-N-T-S-------------------

;--------------------A-P-U----------------------

;--------------D-E-B-U-G-G-I-N-G----------------

;------------S-T-R-U-C-T-U-R-E-S----------------

	MAC	_tarray
{1}		SET	.
		DS	{2}
{1}_end	SET	.
{1}_size SET [{1}_end-{1}]
	ENDM

;---------------S-C-R-I-P-T-S-------------------

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
_tobjA.field_9			SET	_tobjA + 9
{1}.field_9:			.BYTE 0
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
_tobjB.field_5			SET	_tobjB + 5
{1}.field_5:			.BYTE 0
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
{1}.field_0:
		.BYTE 0
{1}.field_1:
		.BYTE 0
{1}.field_2:
		.BYTE 0
{1}.field_3:
		.BYTE 0
{1}.field_4:
		.BYTE 0
{1}.field_5:
		.BYTE 0
	ENDM

	MAC	_tapu_chnls
{1}		SET .
	_tapu_chnl	{1}._ch0
	_tapu_chnl	{1}._ch1
	_tapu_chnl	{1}._ch2
	_tapu_chnl	{1}._ch3
	ENDM

;---------G-A-M-E--S-P-E-C-I-F-I-C--------------

	MAC	sprite_draw_up
		.BYTE $00,{1}
	ENDM

	MAC	sprite_draw_down
		.BYTE $01,{1}
	ENDM

	MAC	msg_draw_up
		.BYTE $02
	ENDM

	MAC	msg_draw_down
		.BYTE $03
	ENDM

	MAC	frame_draw_up
		.BYTE $04,{1}
	ENDM

	MAC	frame_draw_down
		.BYTE $05,{1}
	ENDM

	MAC	frame_draw_custom
		.BYTE $06,{1}>>8,{1}&$FF,{2},{3}
	ENDM

	MAC	msg_input_handler
		.BYTE $07
	ENDM

	MAC	input_2_options
		.BYTE $08
	ENDM

	MAC	ptr_load
		.BYTE $0B
		.WORD {1}
	ENDM

	MAC	msg_printf
		.BYTE $0C
		.WORD {1}
	ENDM

	MAC	game_flags_set
		.BYTE $0D,{1}
	ENDM

	MAC	game_flags_toggle
		.BYTE $0E,{1}
	ENDM

	MAC	jmp_flags_not_set
		.BYTE $0F,{1}
	ENDM

	MAC	jmpne_option
		.BYTE $10,{1}
	ENDM

	MAC jmp_branch
		.BYTE $11,$11
	ENDM

	MAC	------------------
		.BYTE $12,$12
	ENDM

	MAC	jump
		.BYTE $13
		.WORD {1}
	ENDM

	MAC	stop
		.BYTE $14
	ENDM

	MAC	set_room_idx
		.BYTE $15,{1}
	ENDM

	MAC	anim_scene_set
		.BYTE $16,{1}
	ENDM

	MAC	player_pos_set
		.BYTE $17,{1},{2}
	ENDM

	MAC	pass_input
		.BYTE $19
	ENDM

	MAC	game_stats_draw
		.BYTE $1A
	ENDM

	MAC	life_restore
		.BYTE $1B
	ENDM

	MAC	add_10_knifes
		.BYTE $1C
	ENDM

	MAC	add_5_potions
		.BYTE $21
	ENDM

	MAC	game_hours_set
		.BYTE $23,{1}
	ENDM

	MAC	checkpoint_restore
		.BYTE $24
	ENDM

	MAC	checkpoint_reset
		.BYTE $25
	ENDM

	MAC	checkpoint_set
		.BYTE $26
	ENDM

	MAC	continue_cur_draw
		.BYTE $27
	ENDM

	MAC	ending_anim
		.BYTE $28
	ENDM

	MAC	scroller
		.BYTE $29
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
