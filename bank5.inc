
		ORG $8000

		BANK_START $05

		SECTION_START

; =============== S U B	R O U T	I N E =======================================
_dialog_script_play:
		LDA		#$90					; here we go when any dialog sarts
		STA		_PPU_CTRL				; we need to draw ITEMS screen before
		JSR		_palette_off			; because when you press START you jut
		LDX		#$00					; switch NT pages directly, only pass
		LDA		#$F8					; is redrawn every time there.
loc_4400C:
		STA		_spr_buf,X				; clear all sprites including spr0
		INX								; as against other system func to do
		INX								; the same
		INX
		INX
		BNE		loc_4400C
		JSR		_ppu_screen_clear
		LDA		_game._scr_idx			; backup currently selected script idx
		PHA
		LDA		#$83					; execute the inventory draw script
		STA		_game._scr_idx			; must be alwys drawn before any dialog
		JSR		_script_lib_player
		PLA
		STA		_game._scr_idx			; restore script idx and run the actual one
		JSR		_script_lib_player
		JSR		_palette_off
		JMP		_msg_wait_key_release

; =============== S U B	R O U T	I N E =======================================
_palette_off:
		JSR		_render_off
		PPU_FILL_LINEY	$3F00, $0F, $20
		JMP		_render_on

; =============== S U B	R O U T	I N E =======================================
_ppu_screen_clear:
		JSR		_render_off_ex
		PPU_FILL_RECT	$2000, $FE, $1E, $20
		PPU_FILL_LINEY	    0, $FF, $40
		PPU_FILL_RECT	    0, $FE, $1E, $20
		PPU_FILL_LINEY	    0, $FF, $40
		JMP		_render_on

; =============== S U B	R O U T	I N E =======================================
_frame_draw:
		TYA
		PHA
		TXA
		PHA
		DEC		_tmp02					; adjust width
		DEC		_tmp03					; adjust height of internal frame
		DEC		_tmp03
		LDY		#$F7					; render top frame line F7,F8..F8,F9
		JSR		_frame_line_draw
loc_4414B:
		LDY		#$FD					; render middle frame line FD,FE..FE,FF
		JSR		_frame_line_draw
		DEC		_tmp03
		BNE		loc_4414B
		LDY		#$FA					; render bottom frame line FA,FB..FB,FC
		JSR		_frame_line_draw
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_frame_line_draw:
		JSR		_ppu_set_ofs_and_add20
		STY		_PPU_DATA
		LDX		_tmp02
		INY
loc_44134:
		STY		_PPU_DATA
		DEX
		BNE		loc_44134
		INY
		STY		_PPU_DATA
		JMP		_render_on

; =============== S U B	R O U T	I N E =======================================
_ppu_set_ofs_and_add20:
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
		CLC
		ADC		#$20
		STA		_tmp01
		BCC		.no_carry
		INC		_tmp00
.no_carry:
		RTS

; =============== S U B	R O U T	I N E =======================================
_script_lib_player:
		LDA		_game._play_days		; constantly check for extraction time
		BEQ		loc_44793				; internal script state flags reset
		CMP		#$02
		BCS		loc_4478B
		LDA		_game._play_hours
		CMP		#$0C
		BCC		loc_44793
loc_4478B:
		FLAG_SET	FLAG0A_MISSION_TIME_OVER
loc_44793:
		LDA		#$00
		STA		_tmp11
		STA		_tmp12
		LDA		_game._scr_idx			; scripts under 84 are game init scripts
		CMP		#$84					; with its own palettes
		BCC		loc_441B3				; the rest uses fixed palette for all
		LDA		#$00
		STA		_tmp0A
		JSR		_msg_pal_lib_load
loc_441B3:
		LDA		_game._scr_idx
		ASL
		TAX
		LDA		_script_lib,X
		STA		_tmp0D
		LDA		_script_lib+1,X
		STA		_tmp0E
		LDY		#$00

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_script_cmd_fetch:
		LDA		_tmp11
		AND		#$04
		BEQ		loc_441CD
		RTS
loc_441CD:
		BYTE_FETCH
		ASL
		TAX
		LDA		_script_cmd_lib,X
		STA		_tmp0F
		LDA		_script_cmd_lib+1,X
		STA		_tmp10
		JMP		(_tmp0F)
; ---------------------------------------------------------------------------
		IDX_START	_script_cmd_lib
		IDX _scr_cmd00_portrait_draw_up
		IDX _scr_cmd01_portrait_draw_down
		IDX _scr_cmd02_msg_draw_up
		IDX _scr_cmd03_msg_draw_down
		IDX _scr_cmd04_frame_draw_up
		IDX _scr_cmd05_frame_draw_down
		IDX _scr_cmd06_frame_draw_custom
		IDX _scr_cmd07_msg_input_handler
		IDX _scr_cmd08_input_2_options
		IDX _scr_cmd0B_ptr_load
		IDX _scr_cmd0C_msg_draw_custom
		IDX _scr_cmd0D_game_flags_set
		IDX _scr_cmd0E_game_flags_clear
		IDX _scr_cmd0F_jmp_flag_not_set
		IDX _scr_cmd10_jmpne_option
		IDX _scr_cmd11_jmp_branch
		IDX _scr_cmd12_nop
		IDX _scr_cmd13_jump
		IDX _scr_cmd14_stop
		IDX _scr_cmd15_new_warp_set
		IDX _scr_cmd16_heli_warp_set
		IDX _scr_cmd17_player_pos_set
		IDX _scr_cmd19_pass_input
		IDX _scr_cmd1A_game_stats_draw
		IDX _scr_cmd1B_life_restore
		IDX _scr_cmd1C_add_10_knifes
		IDX _scr_cmd21_add_5_potions
		IDX _scr_cmd23_game_hours_set
		IDX _scr_cmd24_checkpoint_restore
		IDX _scr_cmd25_checkpoint_reset
		IDX _scr_cmd26_checkpoint_set
		IDX _scr_cmd27_continue_cur_draw
		IDX _scr_cmd28_ending_anim
		IDX _scr_cmd29_scroller

; =============== S U B	R O U T	I N E =======================================
_scr_cmd00_portrait_draw_up:
		LDA		_tmp11
		ORA		#$40
		BNE		_scr_cmd_portrait_draw_ex

; =============== S U B	R O U T	I N E =======================================
_scr_cmd01_portrait_draw_down:
		LDA		_tmp11
		AND		#$BF

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_scr_cmd_portrait_draw_ex:
		STA		_tmp11
		BYTE_FETCH
		STA		_tmp04
		JSR		_sprite_insert
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd02_msg_draw_up:
		LDA		_tmp11
		AND		#$01
		BEQ		loc_4420B
		JSR		_msg_wnd_clear_down
loc_4420B:
		JSR		_msg_wnd_clear_up
		LDA		#>[MSG_UP_OFS]
		STA		_tmp00
		LDA		#<[MSG_UP_OFS]
		STA		_tmp01
		LDA		_tmp11
		AND		#$BC
		ORA		#$41
		BNE		_scr_cmd_msg_draw_ex

; =============== S U B	R O U T	I N E =======================================
_scr_cmd03_msg_draw_down:
		LDA		_tmp11
		AND		#$02
		BEQ		loc_44237
		JSR		_msg_wnd_clear_up
loc_44237:
		JSR		_msg_wnd_clear_down
		LDA		#>[MSG_DOWN_OFS]
		STA		_tmp00
		LDA		#<[MSG_DOWN_OFS]
		STA		_tmp01
		LDA		_tmp11
		AND		#$BC
		ORA		#$02

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_scr_cmd_msg_draw_ex:
		STA		_tmp11
		LDA		#$01
		STA		_tmp14
		JSR		_msg_draw_ex
		JMP		_scr_cmd07_msg_input_handler

; =============== S U B	R O U T	I N E =======================================
_scr_cmd04_frame_draw_up:
		LDA		#>[FRAME_UP_OFS]
		STA		_tmp00
		LDA		#<[FRAME_UP_OFS]
		JSR		_scr_cmd_frame_draw_ex
		JMP		_scr_cmd00_portrait_draw_up

; =============== S U B	R O U T	I N E =======================================
_scr_cmd05_frame_draw_down:
		LDA		#>[FRAME_DOWN_OFS]
		STA		_tmp00
		LDA		#<[FRAME_DOWN_OFS]
		JSR		_scr_cmd_frame_draw_ex
		JMP		_scr_cmd01_portrait_draw_down

; =============== S U B	R O U T	I N E =======================================
_scr_cmd_frame_draw_ex:
		STA		_tmp01
		LDA		#FRAME_WIDTH
		STA		_tmp02
		LDA		#FRAME_HEIGHT
		STA		_tmp03
		JMP		_frame_draw

; =============== S U B	R O U T	I N E =======================================
_scr_cmd06_frame_draw_custom:
		WORD_FETCH
		STX		_tmp00
		STA		_tmp01
		WORD_FETCH
		STX		_tmp02
		STA		_tmp03
		JSR		_frame_draw
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd07_msg_input_handler:
		TYA
		PHA
loc_442A2:
		LDA		_tmp11					; has option to choose
		AND		#$08
		BNE		.input_2_options
.no_options:
		JSR		_msg_wait_for_input		; if no options, just wait
		LDA		_pad
		AND		#$80
		BEQ		.no_options
		BNE		.select_is_over
.input_2_options:
		LDA		#$01
		STA		_tmp13
		LDY		#$00
loc_442D4:
		LDA		_msg_option_pos_list,Y
		BEQ		.input_2_options
		STA		_spr_buf+$FC
		LDA		#$FF
		STA		_spr_buf+$FD
		LDA		#$03
		STA		_spr_buf+$FE
		LDA		#$18
		STA		_spr_buf+$FF
		JSR		_msg_wait_for_input
		LDA		_pad
		AND		#$80
		BNE		.select_is_over
		LDA		_pad
		AND		#$2C
		BEQ		loc_442D4
		INC		_tmp13
		INY
		JMP		loc_442D4
.select_is_over:
		LDA		_tmp11
		AND		#$C7
		STA		_tmp11
		LDA		#$F8
		STA		_spr_buf+$FC
		PLA
		TAY
		JMP		_script_cmd_fetch
_msg_option_pos_list:
		.BYTE $84,$B4,$00

; =============== S U B	R O U T	I N E =======================================
_scr_cmd08_input_2_options:
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0B_ptr_load:
		WORD_FETCH
		STX		_tmp04
		STA		_tmp05
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0C_msg_draw_custom:
		WORD_FETCH
		STX		_tmp01
		STA		_tmp00
		JSR		_msg_draw_ex
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_game_flags_fetch:
		BYTE_FETCH
		PHA
		AND		#$07
		TAX
		LDA		_bitmasks,X
		STA		_tmp00
		PLA
		LSR
		LSR
		LSR
		TAX
		LDA		_tmp00
		RTS

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0D_game_flags_set:
		JSR		_game_flags_fetch
		ORA		_game._flags,X
		STA		_game._flags,X
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0E_game_flags_clear:
		JSR		_game_flags_fetch
		EOR		#$FF
		AND		_game._flags,X
		STA		_game._flags,X
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0F_jmp_flag_not_set:
		JSR		_game_flags_fetch
		AND		_game._flags,X
		BEQ		_script_branch
		BNE		_j_script_cmd_fetch
_bitmasks:
		.BYTE $01,$02,$04,$08,$10,$20,$40,$80

; =============== S U B	R O U T	I N E =======================================
_scr_cmd10_jmpne_option:
		BYTE_FETCH
		CMP		_tmp13
		BEQ		_j_script_cmd_fetch

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_script_branch:
		BYTE_FETCH
		CMP		#_scr_cmd11_jmp_branch_idx
		BEQ		loc_44448
		CMP		#_scr_cmd12_nop_idx
		BNE		_script_branch
		BYTE_FETCH
		CMP		#_scr_cmd12_nop_idx
		BNE		_script_branch
		BEQ		_j_script_cmd_fetch
loc_44448:
		BYTE_FETCH
		CMP		#_scr_cmd11_jmp_branch_idx
		BNE		_script_branch
		BEQ		_j_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd11_jmp_branch:
		BYTE_FETCH
		CMP		#_scr_cmd12_nop_idx
		BNE		_scr_cmd11_jmp_branch
		BYTE_FETCH
		CMP		#_scr_cmd12_nop_idx
		BNE		_scr_cmd11_jmp_branch

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_j_script_cmd_fetch:
_scr_cmd12_nop:
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd13_jump:
		WORD_FETCH
		STX		_tmp0D
		STA		_tmp0E
		LDY		#$00
		BEQ		_j_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd14_stop:
		LDA		_tmp11
		ORA		#$04
		STA		_tmp11
		BNE		_j_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd15_new_warp_set:
		BYTE_FETCH
		STA		_game._scr_idx
		LDA		#$01
		STA		_game._redraw_req
		BNE		_j_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd16_heli_warp_set:
		BYTE_FETCH
		STA		_helicopter_warp_idx
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd17_player_pos_set:
		BYTE_FETCH
		STA		_objsA._player._y_pos
		LDA		_objsA._player._dir
		AND		#$BF
		STA		_objsA._player._dir
		BYTE_FETCH
		JMP		_player_pos_x_set

; =============== S U B	R O U T	I N E =======================================
_scr_cmd19_pass_input:
		JSR		_pass_input_screen

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_player_pos_set:
		LDA		_game._start_y
		STA		_objsA._player._y_pos
		LDA		_game._start_room

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_player_pos_x_set:
		STA		_objsA._player._room_num
		STA		_room_scroll_pos_x+1
		LDA		#$78
		STA		_objsA._player._x_pos
		LDA		#$00
		STA		_room_scroll_pos_x
		BEQ		_j_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd1A_game_stats_draw:
		TYA
		PHA
		LDX		_game._life
		LDY		_game._life+1
		JSR		_hex_to_dec_xy
		LDX		#$24
		LDY		#$6C
		LDA		#_tmp05-1
		JSR		_ppu_num_draw
		LDX		_game._exp
		LDY		_game._exp+1
		JSR		_hex_to_dec_xy
		LDX		#$24
		LDY		#$AC
		LDA		#_tmp05-1
		JSR		_ppu_num_draw
		LDA		_game._life_level
		ASL
		TAX
		LDA		_max_life_list+1,X
		TAY
		LDA		_max_life_list,X
		TAX
		JSR		_hex_to_dec_xy
		LDX		#$24
		LDY		#$77
		LDA		#_tmp05-1
		JSR		_ppu_num_draw
		LDA		_game._exp_level
		ASL
		TAX
		LDA		_next_exp_list+1,X
		TAY
		LDA		_next_exp_list,X
		TAX
		JSR		_hex_to_dec_xy
		LDX		#$24
		LDY		#$B7
		LDA		#_tmp05-1
		JSR		_ppu_num_draw
		LDX		_game._play_hours
		LDY		#$00
		JSR		_hex_to_dec_xy
		LDX		#$24
		LDY		#$EC
		LDA		#_tmp03-1
		JSR		_ppu_num_draw
		LDX		_game._play_minutes
		LDY		#$00
		JSR		_hex_to_dec_xy
		LDA		#$0E
		STA		_tmp04
		LDX		#$24
		LDY		#$EE
		LDA		#_tmp04-1
		JSR		_ppu_num_draw
		LDX		_play_seconds
		LDY		#$00
		JSR		_hex_to_dec_xy
		LDA		#$0E
		STA		_tmp04
		LDX		#$24
		LDY		#$F1
		LDA		#_tmp04-1
		JSR		_ppu_num_draw
		PLA
		TAY
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_ppu_num_draw:
		STA		_tmp00
		JSR		_render_off
		LDA		_PPU_STATUS
		STX		_PPU_ADDR
		STY		_PPU_ADDR
		LDX		_tmp00
loc_445EF:
		LDA		_tmp01,X
		CLC
		ADC		#$D8
		STA		_PPU_DATA
		DEX
		BNE		loc_445EF
		JMP		_render_on

; =============== S U B	R O U T	I N E =======================================
_scr_cmd1B_life_restore:
		TYA
		PHA
		LDA		_game._life_level
		ASL
		TAX
		LDA		_max_life_list,X
		STA		_game._life
		INX
		LDA		_max_life_list,X
		STA		_game._life+1
		LDX		#$00
loc_44613:
		JSR		_render_on
		JSR		_render_off
		INX
		TXA
		CMP		#$40
		BEQ		loc_44676
		AND		#$02
		BNE		loc_4464B
		PPU_PUT_CHAR	$3F00, $02
		BNE		loc_44613
loc_4464B:
		PPU_PUT_CHAR	$3F00, $0F
		BNE		loc_44613
loc_44676:
		PLA
		TAY
		JSR		_render_on
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd1C_add_10_knifes:
		LDA		_game._ammo_knife
		CLC
		ADC		#$0A
		STA		_game._ammo_knife
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd21_add_5_potions:
		LDA		_game._potions
		CLC
		ADC		#$05
		STA		_game._potions
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd23_game_hours_set:
		BYTE_FETCH
		STA		_game._play_hours
		LDA		#$00
		STA		_game._play_days
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd24_checkpoint_restore:
		FLAG_TEST	FLAG0A_MISSION_TIME_OVER; if it happens that mission over flag
		ORA		_game_flags_backup+1		; is set after last checkpoint as set
		STA		_game_flags_backup+1		; force it to the backup data as well
		LDA		_game_scr_idx_backup
		STA		_game._scr_idx
		LDA		_game_flags_backup
		STA		_game._flags
		LDA		_game_flags_backup+1
		STA		_game._flags+1
		LDA		_game_flags_backup+2
		STA		_game._flags+2
		LDA		_game_life_backup+1
		STA		_game._life+1
		BNE		loc_446E2
		LDA		_game_life_backup
		CMP		#$64
		BCS		loc_446E2
		LDA		#$64
loc_446E2:
		STA		_game._life
		LDA		#$01
		STA		_game._redraw_req
		JMP		_player_pos_set

; =============== S U B	R O U T	I N E =======================================
_scr_cmd25_checkpoint_reset:
		LDX		#$23
		LDA		#$00
loc_4470A:
		STA		_game,X
		DEX
		BPL		loc_4470A
		LDA		#100
		STA		_game._life
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd26_checkpoint_set:
		JSR		_cur_game_vars_backup
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd27_continue_cur_draw:
		LDA		#$01
		STA		_tmp13
loc_44724:
		LDA		_tmp13
		CMP		#$02
		BEQ		loc_44733
		LDA		#$01
		STA		_tmp13
		LDA		#$A4
		BNE		loc_44735
loc_44733:
		LDA		#$B4
loc_44735:
		STA		_spr_buf+$FC
		LDA		#$FF
		STA		_spr_buf+$FD
		LDA		#$03
		STA		_spr_buf+$FE
		LDA		#$50
		STA		_spr_buf+$FF
		JSR		_msg_wait_for_input
		LDA		_pad
		AND		#$90
		BNE		loc_4475D
		LDA		_pad
		AND		#$2C
		BEQ		loc_44724
		INC		_tmp13
		JMP		loc_44724
loc_4475D:
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd28_ending_anim:
		LDX		#$FF
		LDA		#$01
		STA		_tmp14
loc_44766:
		JSR		_script_sprite_anim
		JSR		_render_off
		JSR		_render_on
		DEX
		BNE		loc_44766
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd29_scroller:
		JSR		_scroller_screen
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_msg_wnd_clear_up:
		LDA		#>[CLEAR_UP_OFS]
		STA		_tmp00
		LDA		#<[CLEAR_UP_OFS]
		BNE		_msg_wnd_clear_ex

; =============== S U B	R O U T	I N E =======================================
_msg_wnd_clear_down:
		LDA		#>[CLEAR_DOWN_OFS]
		STA		_tmp00
		LDA		#<[CLEAR_DOWN_OFS]

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_msg_wnd_clear_ex:
		STA		_tmp01
		TYA
		PHA
		TXA
		PHA
		LDY		#CLEAR_HEIGHT
loc_440E5:
		JSR		_ppu_set_ofs_and_add20
		LDA		#$F1
		LDX		#CLEAR_WIDTH
loc_440E7:
		STA		_PPU_DATA
		DEX
		BNE		loc_440E7
		JSR		_render_on
		DEY
		BNE		loc_440E5
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_msg_wait_key_release:
		JSR		_read_pad_safeA
		BNE		_msg_wait_key_release
		RTS

; =============== S U B	R O U T	I N E =======================================
_msg_wait_for_input:
		JSR		_msg_wait_key_release
loc_447C4:
		JSR		_script_sprite_anim
		JSR		_read_pad_safeA
		BEQ		loc_447C4
		LDA		_game._scr_idx
		CMP		#$84
		BEQ		locret_447E1
		CMP		#$82
		BEQ		locret_447E1
		LDA		_pad
		AND		#$10
		BNE		_msg_display_inventory_screen
locret_447E1:
		RTS

; =============== S U B	R O U T	I N E =======================================
_msg_display_inventory_screen:
; the US version uses additional fonts color to highlight the small letters
; when return it will restore regular white coloring
#if LANGUAGE == LANG_US
		JSR		_render_off
		PPU_PUT_CHAR	$3F0E, $22
		JSR		_render_on
#endif
		JSR		_cur_game_vars_backup
		JSR		_pass_encode
		JSR		_msg_wait_key_release
loc_44817:
		JSR		_read_pad_safeA
		AND		#$10
		BEQ		loc_44817
		JSR		_render_on_ex_ex
#if LANGUAGE == LANG_US
		JSR		_render_off
		PPU_PUT_CHAR	$3F0E, $30
		JSR		_render_on
#endif
		RTS

; =============== S U B	R O U T	I N E =======================================
_cur_game_vars_backup:
		LDA		_game._scr_idx
		STA		_game_scr_idx_backup
		LDA		_game._flags
		STA		_game_flags_backup
		LDA		_game._flags+1
		STA		_game_flags_backup+1
		LDA		_game._flags+2
		STA		_game_flags_backup+2
		LDA		_game._bosses
		STA		_game_bosses_backup
		LDA		_game._life_level
		STA		_game_life_level_backup
		LDA		_game._life
		STA		_game_life_backup
		LDA		_game._life+1
		STA		_game_life_backup+1
		LDA		_objsA._player._y_pos
		STA		_game._start_y
		LDA		_objsA._player._room_num
		STA		_game._start_room
		RTS

; =============== S U B	R O U T	I N E =======================================
_script_sprite_anim:
		TYA
		PHA
		LDA		_nmi_flag
		BEQ		.anim_exit
		LDA		#$00
		STA		_nmi_flag
		LDA		_tmp14
		BEQ		.anim_exit
		INC		_tmp14
		LDA		_tmp14
		AND		#$0F
		BNE		.anim_exit
		LDA		_tmp14
		AND		#$10
		BEQ		loc_449C0
		LDA		_tmp11
		AND		#$40
		BNE		loc_449A7
		LDA		_tmp12
		AND		#$02
		BEQ		.anim_exit
		LDX		#00
		BEQ		.spr_nibble_fill
loc_449A7:
		LDA		_tmp12
		AND		#$01
		BEQ		.anim_exit
		LDX		#02
		BNE		.spr_nibble_fill
loc_449C0:
		LDA		_tmp11
		AND		#$40
		BNE		loc_449DF
		LDA		_tmp12
		AND		#$02
		BEQ		.anim_exit
		LDX		#01
		BNE		.spr_nibble_fill
loc_449DF:
		LDA		_tmp12
		AND		#$01
		BEQ		.anim_exit
		LDX		#03
.spr_nibble_fill:
		LDA		_anim_data0,X
		TAY
		LDA		_anim_data1,X
		STA		_spr_buf,Y
		STA		_spr_buf+4,Y
		STA		_spr_buf+8,Y
		LDA		_anim_data1+1,X
		STA		_spr_buf+$30,Y
		STA		_spr_buf+$34,Y
		STA		_spr_buf+$38,Y
.anim_exit:
		PLA
		TAY
		RTS
_anim_data0:
		.BYTE $B0,$B0,$30,$30
_anim_data1:
		.BYTE $F8,MOUTH_DOWN_Y,$F8,MOUTH_UP_Y,$F8

; =============== S U B	R O U T	I N E =======================================
_msg_draw_ex:
		TYA
		PHA
		LDY		#$00
loc_44ADB:
		JSR		_ppu_set_ofs_and_add40
loc_44ADC:
		LDA		(_tmp04),Y
		CMP		#$FF
		BEQ		loc_44AE9
#if LANGUAGE == LANG_JP
		CMP		#$F5					; nigori/panigori symbols are F5 and F6
		BCS		loc_80A9B				; perform some dakuten magic from here
#endif
		STA		_PPU_DATA
		INY
#if LANGUAGE == LANG_JP
		INC		_tmp03
#endif
		JMP		loc_44ADC
#if LANGUAGE == LANG_JP
loc_80A9B:
		PHA
		LDA		_PPU_STATUS				; current ppu write offset shadow
		LDA		_tmp03					; decrease to point to a upper line
		SEC								; above previous character
		SBC		#$21
		TAX
		LDA		_tmp02
		SBC		#$00
		STA		_PPU_ADDR
		STX		_PPU_ADDR
		PLA
		STA		_PPU_DATA				; then put dakuten above it
		INY
		LDA		_PPU_STATUS				; restore current back ppu offset
		LDA		_tmp02
		STA		_PPU_ADDR
		LDA		_tmp03
		STA		_PPU_ADDR
		JMP		loc_44ADC				; and return to main loop
#endif
loc_44AE9:
		JSR		_render_on
		INY
		LDA		(_tmp04),Y				; two stop symbols in row means end of
		CMP		#$FF					; message
		BNE		loc_44ADB
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_ppu_set_ofs_and_add40:
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		_tmp00
#if LANGUAGE == LANG_JP
		STA		_tmp02
#endif
		STA		_PPU_ADDR
		LDA		_tmp01
#if LANGUAGE == LANG_JP
		STA		_tmp03
#endif
		STA		_PPU_ADDR
		CLC
		ADC		#$40
		STA		_tmp01
		BCC		loc_44AFD
		INC		_tmp00
loc_44AFD:
		RTS

; =============== S U B	R O U T	I N E =======================================
_sprite_insert:
		TYA								; this selector at the ame time used
		PHA								; to draw and erase portrait sprites
		TXA								; as well as other static non-ingme
		PHA								; sprites. also for the title screen
		LDA		_tmp04					; and pac-in-time sprites do some
		CMP		#PORTR_CLEAR			; input control work
		BNE		loc_44B5D
		JMP		_portrait_clear
loc_44B5D:
		CMP		#SPR_PACK_IN_TIME
		BNE		loc_44B64
		JMP		_pack_in_time_spr_insert
loc_44B64:
		CMP		#SPR_TITLE_SCREEN
		BNE		_portrait_spr_insert
		JMP		_title_screen_spr_anim_menu_input

; =============== S U B	R O U T	I N E =======================================
_portrait_spr_insert:
		TAY
		LDA		_portraits_lib,Y		; draw sprite sheet for head and
		INY								; shoulders
		STA		_tmp04					; here goes idx of tarting tile
		LDA		#$04					; here width and height in tiles
		STA		_tmp02
		LDA		#$06
		STA		_tmp03
		LDA		_tmp11					; test flag which position used
		AND		#$40
		BNE		loc_44B93				; 40 meand UP, 00 means DOWN
		LDA		#PORTR_DOWN_Y
		STA		_tmp00
		LDA		#PORTR_DOWN_X
		STA		_tmp01
		LDX		#$80					; X = sprite RAM offset. only 2
		LDA		#$02					; portraits is possible at the same
		BNE		loc_44BA3				; at the same time 128 tiles for each
loc_44B93:
		LDA		#PORTR_UP_Y
		STA		_tmp00
		LDA		#PORTR_UP_X
		STA		_tmp01
		LDX		#$00
		LDA		#$01
loc_44BA3:
		ORA		_tmp12
		STA		_tmp12
		JSR		_sprite_sheet_insert
		LDA		_portraits_lib,Y		; put additional sprites for mouth
		INY
		STA		_tmp04					; additional mouth is stored as out
		LDA		#$03					; of screen tiles, and will swapped
		STA		_tmp02					; with already visible mouth tiles
		LDA		#$01					; during aniation
		STA		_tmp03
		LDA		_tmp11
		AND		#$40
		BNE		loc_44BC7
		LDA		#MOUTH_DOWN_Y
		STA		_tmp00
		LDA		#MOUTH_DOWN_X
		STA		_tmp01
		LDX		#$E0
		BNE		loc_44BD1
loc_44BC7:
		LDA		#MOUTH_UP_Y
		STA		_tmp00
		LDA		#MOUTH_UP_X
		STA		_tmp01
		LDX		#$60
loc_44BD1:
		JSR		_sprite_sheet_insert
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_portrait_clear:
		LDA		#$20
		STA		_tmp02
		LDA		_tmp11
		AND		#$40
		BNE		loc_44BEE
		LDX		#$80
		LDA		#$FD
		BNE		loc_44BF6
loc_44BEE:
		LDX		#$00
		LDA		#$FE
loc_44BF6:
		AND		_tmp12
		STA		_tmp12
		LDA		#$F8
		STA		_spr_buf,X
		INX
		INX
		INX
		INX
		DEC		_tmp02
		BNE		loc_44BF6
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_pack_in_time_spr_insert:
		TAY
		LDA		_portraits_lib,Y
		INY
		STA		_tmp04
; INSERT JP ICON BACK
		LDA     #$02					; removed from the US version, but
		STA     _tmp02					; still present in the CHR data
		LDA     #$02					; why not to redisplay it here?
		STA     _tmp03
#if LANGUAGE == LANG_US
		LDA     #$D0
		STA     _tmp01
		LDA     #$80
		STA     _tmp00
#endif
#if LANGUAGE == LANG_JP
		LDA     #$18
		STA     _tmp01
		LDA     #$B8
		STA     _tmp00
#endif
		LDX     #$00
		JSR     _sprite_sheet_insert
; END OF INSERT
		LDA		#$01
		STA		_tmp0A
		JSR		_msg_pal_lib_load
		LDA		#$80
		STA		_tmp14
loc_44C1A:
		JSR		_render_off
		JSR		_render_on
		INC		_tmp14
		BNE		loc_44C1A
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_title_screen_spr_anim_menu_input:
		JSR		_render_off
		PPU_FILL_LINEY	$23D8, $AA, $10	; fill bottom portion of the title
		JSR		_render_on				; screen with RED attributes
		LDA		#$05
		STA		_tmp0A					; title start with blck palette for
		JSR		_msg_pal_lib_load		; sprites
		LDA		#$01
		STA		_tmp0A					; then animation slowly reveals more
		LDA		#$00					; colors of the logo
		STA		_tmp14
		LDA		_tmp04
		TAY
		LDA		#$01
		STA		_tmp13
loc_44C5E:
		LDA		_nmi_flag
		BEQ		loc_44C73
		LDA		#$00
		STA		_nmi_flag
		INC		_tmp14
		LDA		_tmp14
		AND		#$07
		BNE		loc_44C73
		JSR		_title_screen_spr_animate
loc_44C73:
		LDA		_tmp13					; title menu cursor animated here
		CMP		#$02
		BEQ		loc_44C82
		LDA		#$01
		STA		_tmp13
		LDA		#$A4
		BNE		loc_44C84
loc_44C82:
		LDA		#$B4
loc_44C84:
		STA		_spr_buf+$FC
		LDA		#$4F
		STA		_spr_buf+$FD
		LDA		#$03
		STA		_spr_buf+$FE
		LDA		#$50
		STA		_spr_buf+$FF
		JSR		_read_pad_safeA
		BNE		loc_44C5E
loc_44C9E:
		LDA		_nmi_flag
		BEQ		loc_44CB3
		LDA		#$00
		STA		_nmi_flag
		INC		_tmp14
		LDA		_tmp14
		AND		#$07
		BNE		loc_44CB3
		JSR		_title_screen_spr_animate
loc_44CB3:
		JSR		_read_pad_safeA
		BEQ		loc_44C9E
		LDA		_pad
		AND		#$90
		BNE		loc_44CCE
		LDA		_pad
		AND		#$2C
		BEQ		loc_44CCB
		INC		_tmp13
loc_44CCB:
		JMP		loc_44C5E
loc_44CCE:
		LDA		#$F8
		STA		_spr_buf+$FC
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_title_screen_spr_animate:
		LDA		_portraits_lib,Y
		INY
		STA		_tmp04
		JSR		_spr_sheet_title_insert
		CPY		#[SPR_TITLE_SCREEN+[7*3]]
		BNE		loc_44CE7
		LDY		#SPR_TITLE_SCREEN
loc_44CE7:
		LDA		_tmp14
		AND		#$80
		BEQ		locret_44CFC
		LDA		#$00
		STA		_tmp14
		LDA		_tmp0A
		CMP		#$05
		BEQ		locret_44CFC
		JSR		_msg_pal_lib_load
		INC		_tmp0A
locret_44CFC:
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_sheet_title_insert:
		LDX		#$00
		LDA		#$08
		STA		_tmp02
		LDA		#$03
		STA		_tmp03
		LDA		#$50
		STA		_tmp00
		LDA		#$60
		STA		_tmp01
		JMP		_sprite_sheet_insert

; =============== S U B	R O U T	I N E =======================================
_sprite_sheet_insert:
		LDA		#$04
		STA		_tmp08
loc_44D17:
		LDA		_tmp02
		STA		_tmp06
		LDA		_tmp01
		STA		_tmp07
loc_44D1F:
		LDA		_tmp00
		STA		_spr_buf,X
		LDA		_tmp04
		INC		_tmp04
		STA		_spr_buf+1,X
		INC		_tmp08
		LDA		_tmp08
		CMP		#$05
		BNE		loc_44D3D
		LDA		_portraits_lib,Y
		INY
		STA		_tmp05
		LDA		#$01
		STA		_tmp08
loc_44D3D:
		ASL
		STA		_tmp09
		LDA		_tmp05
		DEC		_tmp09
loc_44D44:
		DEC		_tmp09
		BEQ		loc_44D4C
		LSR
		JMP		loc_44D44
loc_44D4C:
		AND		#$03
		STA		_spr_buf+2,X
		LDA		_tmp07
		STA		_spr_buf+3,X
		INX
		INX
		INX
		INX
		LDA		_tmp07
		CLC
		ADC		#$08
		STA		_tmp07
		DEC		_tmp06
		BNE		loc_44D1F
		LDA		_tmp00
		CLC
		ADC		#$08
		STA		_tmp00
		DEC		_tmp03
		BNE		loc_44D17
		RTS
; ---------------------------------------------------------------------------
_portraits_lib:
; byte     type
; 0        FACE TILES offset in 128-byte units
; 1-6      FACE ATTRS 2-bit each, 6x4 sheets
; 7        MOUTH TILES -//-
; 8        MOUTH ATTRS -//-, 3x1 sheets
		.BYTE $00,$55,$55,$55,$55,$00,$00,$F0,$55; $00
		.BYTE $18,$55,$55,$55,$5A,$08,$00,$24,$5A; $09
		.BYTE $30,$55,$55,$55,$5A,$00,$00,$3C,$5A; $12
		.BYTE $48,$55,$55,$55,$55,$55,$55,$F3,$55; $1B
		.BYTE $60,$55,$55,$55,$49,$55,$55,$6C,$29; $24
		.BYTE $78,$55,$55,$55,$55,$55,$55,$84,$55; $2D
		.BYTE $90,$55,$55,$55,$55,$55,$55,$9C,$55; $36
		.BYTE $A8,$55,$55,$55,$55,$55,$55,$F6,$A5; $3F
		.BYTE $C0,$AA,$AA,$AA,$AA,$00,$00,$F6,$AA; $48
		.BYTE $D8,$00,$00,$00,$55,$55,$55,$F9,$A9; $51
		.BYTE $60,$00,$00,$00,$6A,$55,$55,$6C,$6A; $5A
		.BYTE $78,$00,$00,$00,$55,$55,$55,$84,$55; $63
		.BYTE $90,$AA,$AA,$AA,$AA,$00,$00,$9C,$AA; $6C
		.BYTE $A8,$AA,$AA,$AA,$AA,$55,$55,$F3,$AA; $75
		.BYTE $60,$55,$55,$55,$55,$AA,$AA,$F3,$AA; $7E
		.BYTE $78,$00,$00,$00,$00,$00,$00,$FC,$AA; $87
		.BYTE $90,$FF,$FF,$FF,$AA,$AA,$AA,$F6,$AA; $90
		.BYTE $A8,$00,$00,$00,$AA,$AA,$AA,$F9,$AA; $99
		.BYTE $C0,$AA,$AA,$AA,$AA,$AA,$AA,$FC,$AA; $A2
		.BYTE $D8,$00,$00,$00,$00,$C3,$FF,$E4,$00; $AB
		.BYTE $C0,$FF,$FF,$1A,$AA,$AA,$AA,$F9,$AA; $B4
		.BYTE $D8,$00,$00,$00,$00,$00,$00,$FC,$AA; $BD
; 2x2 sprite sheet
_spr_pack_int_time:
		.BYTE $48,$EE
; 8x3 sprite sheets
_spr_title_anim:
		.BYTE $00,$40,$00,$50,$00,$51,$41
		.BYTE $18,$10,$00,$54,$01,$54,$05
		.BYTE $30,$50,$05,$50,$45,$50,$45

; =============== S U B	R O U T	I N E =======================================
_read_pad_safeA:
		LDA		_tmp00
		PHA
		LDA		_tmp03
		PHA
		TYA
		PHA
		TXA
		PHA
		JSR		_read_pad_safe
		PLA
		TAX
		PLA
		TAY
		PLA
		STA		_tmp03
		PLA
		STA		_tmp00
		LDA		_pad
		RTS

; =============== S U B	R O U T	I N E =======================================
_msg_pal_lib_load:
		TYA
		PHA
		TXA
		PHA
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDY		#$00
loc_44EB0:
		LDA		_pal_bg_default,Y
		STA		_PPU_DATA
		INY
		CPY		#$10
		BNE		loc_44EB0
		LDA		_tmp0A
		ASL
		ASL
		ASL
		ASL
		TAY
		LDX		#$10
loc_44EC4:
		LDA		_pal_portrait_lib,Y
		INY
		STA		_PPU_DATA
		DEX
		BNE		loc_44EC4
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		JSR		_render_on
		PLA
		TAX
		PLA
		TAY
		RTS
; ---------------------------------------------------------------------------
_pal_portrait_lib:
		.BYTE $0F,$10,$36,$0A,$0F,$16,$36,$17,$0F,$1A,$36,$37,$0F,$1C,$36,$30
		.BYTE $0F,$0F,$0F,$0F,$0F,$0F,$0F,$06,$0F,$12,$16,$30,$0F,$2A,$16,$30
		.BYTE $0F,$0F,$0F,$06,$0F,$0F,$06,$16,$0F,$0F,$0F,$0F,$0F,$0F,$30,$30
		.BYTE $0F,$0F,$06,$16,$0F,$06,$16,$27,$0F,$0F,$0F,$0F,$0F,$0F,$30,$30
		.BYTE $0F,$06,$16,$27,$0F,$16,$27,$37,$0F,$0F,$0F,$0F,$0F,$0F,$30,$30
_pal_bg_default:
		.BYTE $0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$16,$0F,$0F,$30,$30

; =============== S U B	R O U T	I N E =======================================
_pass_input_screen:
		LDA		#$00
		STA		_tmp0A
		JSR		_msg_pal_lib_load
		LDA		#$00					; pass col row init
		STA		_tmp03
		STA		_tmp04
		LDA		#$20					; pass ppu draw offset
		STA		_tmp05
		LDA		#$A7
		STA		_tmp06
.pass_input_loop:
		LDA		#$00
		STA		_pad
		JSR		_pass_input_control		; the cursor move controls are inside.
		CMP		#$40					; exit when either A, B or START is
		BEQ		.pass_bs_cmd			; pressed. A works as usual, B
		CMP		#$10					; dubbing BACKSPACE option, START
		BNE		.pass_press_a			; also dubbing END option for covinience
		JMP		_pass_decode
.pass_press_a:
		LDA		#$00					; calculate character IDX
		DEC		_tmp01					; first multiply ROW to 10
		BMI		loc_44F84				; if zero, do nothing
loc_44F7D:
		CLC
		ADC		#$0A
		DEC		_tmp01
		BMI		loc_44F7D
loc_44F84:
		CLC								; calc ROW * 10 + COL
		ADC		_tmp00
		CMP		#PASS_CHAR_GAP			; adjust for gap between two char blocks
		BCC		loc_44F94
		SEC
		SBC		#$04
loc_44F94:
		STA		_tmp02					; store for now
		CMP		#$40					; check for special commands
		BCC		.pass_put_char
		CMP		#$42
		BEQ		.pass_bs_cmd
		CMP		#$44
		BEQ		.pass_sp_cmd
		JMP		_pass_decode
.pass_bs_cmd:
		DEC		_tmp06					; BACKSPACE logic here
		JSR		_pass_ppu_gap_check
		BEQ		.pass_bs_cmd
		CMP		#$06
		BNE		.pass_input_loop
		LDA		_tmp06
		SEC
		SBC		#$2D
		CMP		#$79
		BNE		.pass_input_set
		LDA		#$A7
		BNE		.pass_input_set
.pass_put_char:
		JSR		_pass_write_ppu_char	; input pass char here
		JSR		_render_on
.pass_sp_cmd:
		INC		_tmp06					; then FORWARD cursor here
		JSR		_pass_ppu_gap_check
		BEQ		.pass_sp_cmd
		CMP		#$1A
		BNE		.pass_input_loop
		LDA		_tmp06
		CLC
		ADC		#$2D
		CMP		#$27
		BNE		.pass_input_set
		LDA		#$F9
.pass_input_set:
		STA		_tmp06
		JMP		.pass_input_loop

; =============== S U B	R O U T	I N E =======================================
_pass_ppu_gap_check:
		LDA		_tmp06
		AND		#$1F
		CMP		#$0B
		BEQ		.gap_check
		CMP		#$10
		BEQ		.gap_check
		CMP		#$15
.gap_check:
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_input_control:
		LDA		_tmp04					; adjust cursor position when
		STA		_tmp01					; row position is changed, now in
		ASL								; _tmp01 stored real character
		TAX								; position.
		LDA		_pass_wrap_list+1,X
		EOR		#$FF
		CLC
		ADC		#$01
		AND		_tmp03
		CMP		_pass_wrap_list,X
		BCC		.pass_cur_draw
		LDA		_pass_wrap_list,X
		SEC
		SBC		_pass_wrap_list+1,X
.pass_cur_draw:
		STA		_tmp00					; store col position to be able to
		ASL								; get the character idx outside of this
		ASL								; routine, then calculate cursor
		ASL								; sprite position.
		ASL
		CLC
		ADC		#$30
		PHA
		LDA		_tmp01
		ASL
		ASL
		ASL
		ASL
		CLC
		ADC		#$54
		STA		_spr_buf+$F8
		LDA		#$4F
		STA		_spr_buf+$F9
		LDA		#$03
		STA		_spr_buf+$FA
		PLA
		STA		_spr_buf+$FB
		LDA		_tmp06
		ASL
		ASL
		ASL
		PHA
		LDA		_tmp06
		CMP		#$C0
		BCC		loc_450AD
		LDA		#$3D
		BNE		loc_450B1
loc_450AD:
		LDA		#$2D
loc_450B1:
		STA		_spr_buf+$FC
		LDA		#$4E
		STA		_spr_buf+$FD
		LDA		#$03
		STA		_spr_buf+$FE
		PLA
		STA		_spr_buf+$FF
		LDA		#$00					; input wait loop starts here
		STA		_tmp14
loc_450C9:
		LDA		_nmi_flag				; when between frames, go to check
		BEQ		.pass_wait_release		; all buttons are released
		LDA		#$00					; when nmi occurs, unpade the auto
		STA		_nmi_flag				; repeat timer. every N frames
		INC		_tmp14					; when button is not released,
		LDA		_tmp14					; pass it to the main control loop
		AND		#$08					; here is the default speed but
		BNE		.pass_wait_press		; you may press faster
.pass_wait_release:
		JSR		_read_pad_safeA			; if pads are effectively released
		BNE		loc_450C9				; go to the input wait loop
.pass_wait_press:
		JSR		_read_pad_safeA			; input wait loop run until any
		BEQ		.pass_wait_press		; button is pressed, then parse it
		LSR
		BCS		.pass_input_right
		LSR
		BCS		.pass_input_left
		LSR
		BCS		.pass_input_down
		LSR
		BCS		.pass_input_up
		LDA		_pad
		AND		#$D0
		BEQ		.pass_wait_press
		RTS
.pass_input_up:
		DEC		_tmp04
		JMP		.pass_row_set
.pass_input_down:
		INC		_tmp04
.pass_row_set:
		LDA		_tmp04
		AND		#$07
		STA		_tmp04
		JMP		_pass_input_control
.pass_input_right:
		LDA		_pass_wrap_list+1,X
		CLC
		ADC		_tmp03
		CMP		_pass_wrap_list,X
		BCC		.pass_col_set
		LDA		#$00
		BEQ		.pass_col_set
.pass_input_left:
		LDA		_tmp03
		SEC
		SBC		_pass_wrap_list+1,X
		BPL		.pass_col_set
		CLC
		ADC		_pass_wrap_list,X
.pass_col_set:
		STA		_tmp03
		JMP		_pass_input_control
_pass_wrap_list:
		.BYTE	$0A,$01
		.BYTE	$0A,$01
#if LANGUAGE == LANG_US
		.BYTE	$0A,$01
		.BYTE	$06,$01
#endif
#if LANGUAGE == LANG_JP
		.BYTE	$06,$01
		.BYTE	$0A,$01
#endif
		.BYTE	$0A,$01
		.BYTE	$0A,$01
		.BYTE	$08,$01
		.BYTE	$06,$02

; =============== S U B	R O U T	I N E =======================================
_pass_encode:
		JSR		_pass_encrypt			; pass never gets to the main RAM
		LDA		#$26					; it stored in VRAM instead and read
		STA		_tmp05					; from there when needed
		LDA		#$C7
		STA		_tmp06
		LDX		#$00
loc_44860:
		JSR		_pass_get_dataA
		JSR		_pass_write_char_and_render_on
		INC		_tmp06
		JSR		_pass_get_dataB
		JSR		_pass_write_char_and_render_on
		INC		_tmp06
		JSR		_pass_get_dataC
		JSR		_pass_write_char_and_render_on
		INC		_tmp06
		JSR		_pass_get_dataD
		JSR		_pass_write_char_and_render_on
		INC		_tmp06
		INC		_tmp06
		INX
		INX
		INX
		CPX		#$0C
		BNE		loc_44891
		LDA		#$07
		STA		_tmp06
		INC		_tmp05
loc_44891:
		CPX		#$18
		BNE		loc_44860
		JMP		_pass_decrypt			; restore encrypted buffer because
										; we need it decrypted

; =============== S U B	R O U T	I N E =======================================
_pass_decode:
		LDA		#$20
		STA		_tmp05
		LDA		#$A7
		STA		_tmp06
		LDX		#$00
loc_451D4:
		JSR		_pass_read_ppu_char
		JSR		_pass_store_dataA
		INC		_tmp06
		JSR		_pass_read_ppu_char
		JSR		_pass_store_dataB
		INC		_tmp06
		JSR		_pass_read_ppu_char
		JSR		_pass_store_dataC
		INC		_tmp06
		JSR		_pass_read_ppu_char
		JSR		_pass_store_dataD
		INC		_tmp06
		INC		_tmp06
		INX
		INX
		INX
		CPX		#$0C
		BNE		loc_45201
		LDA		#$E7
		STA		_tmp06
loc_45201:
		CPX		#$18
		BNE		loc_451D4
		LDA		#$F8
		STA		_spr_buf+$F8
		STA		_spr_buf+$FC
		JMP		_pass_decrypt

; =============== S U B	R O U T	I N E =======================================
_pass_encrypt:
		TYA
		PHA
		LDA		#$00					; calc checksum
		TAY
loc_45217:
		CPY		#$0A
		BEQ		loc_4521F				; skip checksum position
		CLC
		ADC		_game,Y
loc_4521F:
		INY
		CPY		#$18
		BNE		loc_45217
		STA		_game._crc				; store and use it as index
		TAX								; in _rand_table to XOR data
		LDY		#$00
loc_4522C:
		CPY		#$0A
		BEQ		loc_45239
		LDA		_game,Y
		EOR		_rand_tbl,X
		STA		_game,Y
loc_45239:
		INY
		INX
		CPY		#$18
		BNE		loc_4522C
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_decrypt:
		TYA
		PHA
		LDX		_game._crc				; get the checksum
		LDA		#$00
		PHA
		TAY
loc_45249:
		CPY		#$0A
		BEQ		loc_45256				; skip checksum position
		LDA		_game,Y					; effectively reXOR byte and
		EOR		_rand_tbl,X				; summing at the same time
		STA		_game,Y
		PLA
		CLC
		ADC		_game,Y
		PHA
loc_45256:
		INY
		INX
		CPY		#$18
		BNE		loc_45249
		PLA
		CMP		_game._crc				; verify the sum
		BEQ		loc_45279
		LDA		#$02
		BNE		loc_4527A
loc_45279:
		LDA		#$01
loc_4527A:
		STA		_tmp13					; exit code 01 if ok, 02 if fail
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_store_dataA:
		LDA		_tmp02
		ASL
		ASL
		ASL
		ASL
		STA		_game,X
		LDA		_tmp02
		AND		#$30
		LSR
		LSR
		LSR
		LSR
		STA		_game+2,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_store_dataB:
		LDA		_tmp02
		AND		#$0F
		ORA		_game,X
		STA		_game,X
		LDA		_tmp02
		AND		#$30
		LSR
		LSR
		ORA		_game+2,X
		STA		_game+2,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_store_dataC:
		LDA		_tmp02
		ASL
		ASL
		ASL
		ASL
		STA		_game+1,X
		LDA		_tmp02
		AND		#$30
		ORA		_game+2,X
		STA		_game+2,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_store_dataD:
		LDA		_tmp02
		AND		#$0F
		ORA		_game+1,X
		STA		_game+1,X
		LDA		_tmp02
		AND		#$30
		ASL
		ASL
		ORA		_game+2,X
		STA		_game+2,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_get_dataA:
		LDA		_game,X
		LSR
		LSR
		LSR
		LSR
		STA		_tmp02
		LDA		_game+2,X
		AND		#$03
		ASL
		ASL
		ASL
		ASL
		ORA		_tmp02
		STA		_tmp02
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_get_dataB:
		LDA		_game,X
		AND		#$0F
		STA		_tmp02
		LDA		_game+2,X
		AND		#$0C
		ASL
		ASL
		ORA		_tmp02
		STA		_tmp02
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_get_dataC:
		LDA		_game+1,X
		LSR
		LSR
		LSR
		LSR
		STA		_tmp02
		LDA		_game+2,X
		AND		#$30
		ORA		_tmp02
		STA		_tmp02
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_get_dataD:
		LDA		_game+1,X
		AND		#$0F
		STA		_tmp02
		LDA		_game+2,X
		AND		#$C0
		LSR
		LSR
		ORA		_tmp02
		STA		_tmp02
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_read_ppu_char:
		JSR		_pass_set_ppu_ofs
		LDA		_PPU_DATA
		LDA		_PPU_DATA
		SEC
		SBC		#$50
		STA		_tmp02
		JMP		_render_on

; =============== S U B	R O U T	I N E =======================================
_pass_set_ppu_ofs:
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		_tmp05
		STA		_PPU_ADDR
		LDA		_tmp06
		STA		_PPU_ADDR
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_write_ppu_char:
		JSR		_pass_set_ppu_ofs
		LDA		_tmp02
		CLC
		ADC		#$50
		STA		_PPU_DATA
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_write_char_and_render_on:
		JSR		_pass_write_ppu_char
		LDA		_PPU_STATUS
		LDA		#$00
		STA		_PPU_SCROLL
		STA		_PPU_SCROLL
		LDA		_PPU_STATUS
		LDA		#$24
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		#$0E
		STA		_PPU_MASK
		LDA		#$91
		STA		_PPU_CTRL
		RTS

		SECTION_END "SCRIPT PROGRAM"

		SECTION_START
_script_lib:
#if LANGUAGE == LANG_US
		INCLUDE "..\script\script_us.inc"
#endif
#if LANGUAGE == LANG_JP
		INCLUDE "..\script\script_jp.inc"
#endif
		SECTION_END "SCRIPTS AND TEXTS"

		BANK_END 5,$C000
