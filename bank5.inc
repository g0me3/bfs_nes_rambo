
		ORG $8000

		BANK_START $05

		SECTION_START

; =============== S U B	R O U T	I N E =======================================
_inventory_screen_draw:
		LDA		#$90
		STA		_PPU_CTRL
		JSR		_palette_off
		LDX		#$00
		LDA		#$F8
loc_4400C:
		STA		_spr_buf,X
		INX
		INX
		INX
		INX
		BNE		loc_4400C
		JSR		_ppu_screen_clear
		LDA		_game._scr_idx
		PHA
		LDA		#$83
		STA		_game._scr_idx
		JSR		_script_lib_player
		PLA
		STA		_game._scr_idx
		JSR		_script_lib_player
		JSR		_palette_off
loc_4402E:
		JSR		_read_pad_safeA
		LDA		_pad
		AND		#$30
		BNE		loc_4402E
		RTS

; =============== S U B	R O U T	I N E =======================================
_palette_off:
		JSR		_render_off
		PPU_FILL_LINEY	$3F00, $0F, $20
		JMP		_render_on

; =============== S U B	R O U T	I N E =======================================
_ppu_screen_clear:
		JSR		_render_off_ex
		PPU_FILL_RECT	$2400, $FE, $1E, $20
		PPU_FILL_RECT	$2000, $FE, $1E, $20
		PPU_FILL_LINEY	$23C0, $FF, $40
		PPU_FILL_LINEY	$27C0, $FF, $40
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
		JSR		_render_off
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
		JSR		_time_is_over_test
		LDA		#$00
		STA		_tmp11
		STA		_tmp12
		LDA		_game._scr_idx
		CMP		#$84
		BCC		loc_441B3
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
		LDA		(_tmp0D),Y
		INY
		ASL
		TAX
		LDA		_script_cmd_lib,X
		STA		_tmp0F
		LDA		_script_cmd_lib+1,X
		STA		_tmp10
		JMP		(_tmp0F)

; =============== S U B	R O U T	I N E =======================================
_scr_cmd00_portrait_draw_up:
		LDA		(_tmp0D),Y
		STA		_tmp04
		INY
		LDA		_tmp11
		ORA		#$40
		STA		_tmp11
		JSR		_sprite_insert
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd01_portrait_draw_down:
		LDA		(_tmp0D),Y
		STA		_tmp04
		INY
		LDA		_tmp11
		AND		#$BF
		STA		_tmp11
		JSR		_sprite_insert
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd02_msg_draw_up:
		LDA		_tmp11
		AND		#$01
		BEQ		loc_4420B
		JSR		_msg_wnd_clear_down
loc_4420B:
		LDA		_tmp11
		AND		#$FC
		ORA		#$01
		STA		_tmp11
		JSR		_msg_wnd_clear_up
		LDA		#$20
		STA		_tmp00
		LDA		#$AA
		STA		_tmp01
		LDA		#$01
		STA		_tmp14
		LDA		_tmp11
		ORA		#$40
		STA		_tmp11
		JSR		_ppu_res_draw
		JMP		_scr_cmd07_msg_input_handler

; =============== S U B	R O U T	I N E =======================================
_scr_cmd03_msg_draw_down:
		LDA		_tmp11
		AND		#$02
		BEQ		loc_44237
		JSR		_msg_wnd_clear_up
loc_44237:
		LDA		_tmp11
		AND		#$FC
		ORA		#$02
		STA		_tmp11
		JSR		_msg_wnd_clear_down
		LDA		#$22
		STA		_tmp00
		LDA		#$24
		STA		_tmp01
		LDA		#$01
		STA		_tmp14
		LDA		_tmp11
		AND		#$BF
		STA		_tmp11
		JSR		_ppu_res_draw
		JMP		_scr_cmd07_msg_input_handler

; =============== S U B	R O U T	I N E =======================================
_scr_cmd04_frame_draw_up:
		LDA		#$20
		STA		_tmp00
		LDA		#$62
		STA		_tmp01
		LDA		#$1C
		STA		_tmp02
		LDA		#$0C
		STA		_tmp03
		JSR		_frame_draw
		JMP		_scr_cmd00_portrait_draw_up

; =============== S U B	R O U T	I N E =======================================
_scr_cmd05_frame_draw_down:
		LDA		#$21
		STA		_tmp00
		LDA		#$E2
		STA		_tmp01
		LDA		#$1C
		STA		_tmp02
		LDA		#$0C
		STA		_tmp03
		JSR		_frame_draw
		JMP		_scr_cmd01_portrait_draw_down

; =============== S U B	R O U T	I N E =======================================
_scr_cmd06_frame_draw_custom:
		LDA		(_tmp0D),Y
		INY
		STA		_tmp00
		LDA		(_tmp0D),Y
		INY
		STA		_tmp01
		LDA		(_tmp0D),Y
		INY
		STA		_tmp02
		LDA		(_tmp0D),Y
		INY
		STA		_tmp03
		JSR		_frame_draw
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd07_msg_input_handler:
		TYA
		PHA
loc_442A2:
		LDA		#$01
		STA		_tmp13
		LDA		_tmp11
		AND		#$08
		BNE		_input_2_options
		LDA		_tmp11
		AND		#$10
		BNE		_input_3_options
		LDA		_tmp11
		AND		#$20
		BNE		_input_4_options
loc_442B8:
		JSR		_msg_wait_for_input
		LDA		_pad
		AND		#$80
		BEQ		loc_442B8
		BNE		_select_is_over
_input_2_options:
		LDA		#$00
		BEQ		loc_442D3
_input_3_options:
		LDA		#$03
		BNE		loc_442D3
_input_4_options:
		LDA		#$07
loc_442D3:
		TAY
loc_442D4:
		LDA		_msg_option_pos_list,Y
		BEQ		loc_442A2
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
		BNE		_select_is_over
		LDA		_pad
		AND		#$0F
		BEQ		loc_442D4
		INC		_tmp13
		INY
		JMP		loc_442D4
_select_is_over:
		JSR		_msg_wait_key_release
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
		.BYTE $84,$A4,$C4,$00
		.BYTE $84,$94,$A4,$B4,$C4,$00

; =============== S U B	R O U T	I N E =======================================
_scr_cmd08_input_2_options:
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd09_input_3_options_unused:
		LDA		_tmp11
		ORA		#$10
		STA		_tmp11
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0A_input_4_options_unused:
		LDA		_tmp11
		ORA		#$20
		STA		_tmp11
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0B_ptr_load:
		LDA		(_tmp0D),Y
		STA		_tmp04
		INY
		LDA		(_tmp0D),Y
		STA		_tmp05
		INY
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0C_msg_raw_display:
		LDA		(_tmp0D),Y
		STA		_tmp01
		INY
		LDA		(_tmp0D),Y
		STA		_tmp00
		INY
		JSR		_ppu_res_draw
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0D_game_flags_set:
		LDA		(_tmp0D),Y
		INY
		ASL
		ASL
		TAX
		LDA		_bitmasks,X
		ORA		_game._flags
		STA		_game._flags
		LDA		_bitmasks+1,X
		ORA		_game._flags+1
		STA		_game._flags+1
		LDA		_bitmasks+2,X
		ORA		_game._flags+2
		STA		_game._flags+2
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0E_game_flags_clear:
		LDA		(_tmp0D),Y
		INY
		ASL
		ASL
		TAX
		LDA		_bitmasks,X
		EOR		#$FF
		AND		_game._flags
		STA		_game._flags
		LDA		_bitmasks+1,X
		EOR		#$FF
		AND		_game._flags+1
		STA		_game._flags+1
		LDA		_bitmasks+2,X
		EOR		#$FF
		AND		_game._flags+2
		STA		_game._flags+2
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd0F_jmp_flag_not_set:
		LDA		(_tmp0D),Y
		INY
		ASL
		ASL
		TAX
		LDA		_bitmasks,X
		AND		_game._flags
		BNE		loc_443C6
		LDA		_bitmasks+1,X
		AND		_game._flags+1
		BNE		loc_443C6
		LDA		_bitmasks+2,X
		AND		_game._flags+2
		BNE		loc_443C6
		JMP		_script_look_for_rets
loc_443C6:
		JMP		_script_cmd_fetch

_bitmasks:
		.BYTE $01,$00,$00,$00
		.BYTE $02,$00,$00,$00
		.BYTE $04,$00,$00,$00
		.BYTE $08,$00,$00,$00
		.BYTE $10,$00,$00,$00
		.BYTE $20,$00,$00,$00
		.BYTE $40,$00,$00,$00
		.BYTE $80,$00,$00,$00
		.BYTE $00,$01,$00,$00
		.BYTE $00,$02,$00,$00
		.BYTE $00,$04,$00,$00
		.BYTE $00,$08,$00,$00
		.BYTE $00,$10,$00,$00
		.BYTE $00,$20,$00,$00
		.BYTE $00,$40,$00,$00
		.BYTE $00,$80,$00,$00
		.BYTE $00,$00,$01,$00
		.BYTE $00,$00,$02,$00
		.BYTE $00,$00,$04,$00
		.BYTE $00,$00,$08,$00
		.BYTE $00,$00,$10,$00
		.BYTE $00,$00,$20,$00
		.BYTE $00,$00,$40,$00
		.BYTE $00,$00,$80,$00

; =============== S U B	R O U T	I N E =======================================
_scr_cmd10_jmpne_option:
		LDA		(_tmp0D),Y
		INY
		CMP		_tmp13
		BEQ		_j_script_cmd_fetch

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_script_look_for_rets:
		LDA		(_tmp0D),Y
		INY
		CMP		#$11
		BEQ		loc_44448
		CMP		#$12
		BEQ		loc_4443E
		JMP		_script_look_for_rets
loc_4443E:
		LDA		(_tmp0D),Y
		INY
		CMP		#$12
		BNE		_script_look_for_rets
		JMP		_script_cmd_fetch
loc_44448:
		LDA		(_tmp0D),Y
		INY
		CMP		#$11
		BNE		_script_look_for_rets

; !FAALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_j_script_cmd_fetch:
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd11_jmp_branch:
		LDA		(_tmp0D),Y
		INY
		CMP		#$12
		BNE		_scr_cmd11_jmp_branch
		LDA		(_tmp0D),Y
		INY
		CMP		#$12
		BNE		_scr_cmd11_jmp_branch
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd12_nop:
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd13_jump:
		LDA		(_tmp0D),Y
		TAX
		INY
		LDA		(_tmp0D),Y
		STA		_tmp0E
		TXA
		STA		_tmp0D
		LDY		#$00
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd14_stop:
		LDA		_tmp11
		ORA		#$04
		STA		_tmp11
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd15_set_room_idx:
		LDA		(_tmp0D),Y
		STA		_game._scr_idx
		INY
		LDA		#$01
		STA		_game._redraw_req
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd16_anim_scene_set:
		LDA		(_tmp0D),Y
		STA		_obj_heli_tmp_flag
		INY
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd17_player_pos_set:
		LDA		(_tmp0D),Y
		STA		_objsA._player._room_num
		STA		_room_scroll_pos_x+1
		INY
		LDA		#$78
		STA		_objsA._player._x_pos
		LDA		#$00
		STA		_room_scroll_pos_x
		LDA		_objsA._player._dir
		AND		#$BF
		STA		_objsA._player._dir
		LDA		(_tmp0D),Y
		STA		_objsA._player._y_pos
		INY
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd18_mem_write_unused:
		LDA		(_tmp0D),Y
		INY
		STA		_tmp04
		LDA		(_tmp0D),Y
		INY
		STA		_tmp05
		LDA		(_tmp0D),Y
		INY
		LDX		#$00
		STA		(_tmp04,X)
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd19_pass_input:
		JSR		_pass_input_screen
		LDA		_game._start_y
		STA		_objsA._player._y_pos
		LDA		_game._start_room
		STA		_objsA._player._room_num
		STA		_room_scroll_pos_x+1
		LDA		#$78
		STA		_objsA._player._x_pos
		LDA		#$00
		STA		_room_scroll_pos_x
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd1A_game_stats_draw:
		LDA		_game._life
		STA		_tmp00
		LDA		_game._life+1
		STA		_tmp01
		JSR		_hex_to_dec
		LDA		#$24
		STA		_tmp00
		LDA		#$6C
		STA		_tmp01
		LDX		#_tmp05-1
		JSR		_ppu_num_draw
		LDA		_game._exp
		STA		_tmp00
		LDA		_game._exp+1
		STA		_tmp01
		JSR		_hex_to_dec
		LDA		#$24
		STA		_tmp00
		LDA		#$AC
		STA		_tmp01
		LDX		#_tmp05-1
		JSR		_ppu_num_draw
		LDA		_game._life_level
		ASL
		TAX
		LDA		_max_life_list,X
		STA		_tmp00
		INX
		LDA		_max_life_list,X
		STA		_tmp01
		JSR		_hex_to_dec
		LDA		#$24
		STA		_tmp00
		LDA		#$77
		STA		_tmp01
		LDX		#_tmp05-1
		JSR		_ppu_num_draw
		LDA		_game._exp_level
		ASL
		TAX
		LDA		_next_exp_list,X
		STA		_tmp00
		INX
		LDA		_next_exp_list,X
		STA		_tmp01
		JSR		_hex_to_dec
		LDA		#$24
		STA		_tmp00
		LDA		#$B7
		STA		_tmp01
		LDX		#_tmp05-1
		JSR		_ppu_num_draw
		LDA		_game._play_hours
		STA		_tmp00
		LDA		#$00
		STA		_tmp01
		JSR		_hex_to_dec
		LDA		#$24
		STA		_tmp00
		LDA		#$EC
		STA		_tmp01
		LDX		#_tmp03-1
		JSR		_ppu_num_draw
		LDA		_game._play_minutes
		STA		_tmp00
		LDA		#$00
		STA		_tmp01
		JSR		_hex_to_dec
		LDA		#$0E
		STA		_tmp04
		LDA		#$24
		STA		_tmp00
		LDA		#$EE
		STA		_tmp01
		LDX		#_tmp04-1
		JSR		_ppu_num_draw
		LDA		_play_seconds
		STA		_tmp00
		LDA		#$00
		STA		_tmp01
		JSR		_hex_to_dec
		LDA		#$0E
		STA		_tmp04
		LDA		#$24
		STA		_tmp00
		LDA		#$F1
		STA		_tmp01
		LDX		#_tmp04-1
		JSR		_ppu_num_draw
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_ppu_num_draw:
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
loc_445EF:
		LDA		$0001,X
		CLC
		ADC		#$D8
		STA		_PPU_DATA
		DEX
		BNE		loc_445EF
		JMP		_render_on

; =============== S U B	R O U T	I N E =======================================
_scr_cmd1B_life_resore:
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
		JSR		_render_off
		INX
		TXA
		CMP		#$40
		BEQ		loc_44676
		AND		#$02
		BNE		loc_4464B
#if LANGUAGE == LANG_JP
		PPU_FILL_LINEY	$3F00, $02, $0F
#endif
#if LANGUAGE == LANG_US
		PPU_FILL_LINEY	$3F00, $02, $0E
		LDA		#$30
		STA		_PPU_DATA
#endif
		LDA		#$30
		STA		_PPU_DATA
		JSR		_render_on
		JMP		loc_44613
loc_4464B:
#if LANGUAGE == LANG_JP
		PPU_FILL_LINEY	$3F00, $0F, $0F
#endif
#if LANGUAGE == LANG_US
		PPU_FILL_LINEY	$3F00, $0F, $0E
		LDA		#$30
		STA		_PPU_DATA
#endif
		LDA		#$30
		STA		_PPU_DATA
		JSR		_render_on
		JMP		loc_44613
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
_scr_cmd22_inc_exp_level_unused:
		INC		_game._exp_level
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd23_game_hours_set:
		LDA		(_tmp0D),Y
		STA		_game._play_hours
		INY
		LDA		#$00
		STA		_game._play_days
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd24_checkpoint_restore:
		LDA		_game._flags+1
		AND		#$04
		ORA		_game_flags_backup+1
		STA		_game_flags_backup+1
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
		LDA		_game._start_y
		STA		_objsA._player._y_pos
		LDA		_game._start_room
		STA		_objsA._player._room_num
		STA		_room_scroll_pos_x+1
		LDA		#$78
		STA		_objsA._player._x_pos
		LDA		#$00
		STA		_room_scroll_pos_x
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd25_checkpoint_reset:
		LDX		#$00
		LDA		#$00
loc_4470A:
		STA		_game,X
		INX
		CPX		#$24
		BNE		loc_4470A
		LDA		#$64
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
		AND		#$10
		BNE		loc_4475D
		LDA		_pad
		AND		#$20
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
_time_is_over_test:
		LDA		_game._play_days
		BEQ		locret_44793
		CMP		#$02
		BCS		loc_4478B
		LDA		_game._play_hours
		CMP		#$0C
		BCC		locret_44793
loc_4478B:
		LDA		_game._flags+1
		ORA		#$04
		STA		_game._flags+1
locret_44793:
		RTS

; =============== S U B	R O U T	I N E =======================================
_msg_wnd_clear_up:
		LDA		#$20
		STA		_tmp00
		LDA		#$8A
		BNE		_msg_wnd_clear_ex

; =============== S U B	R O U T	I N E =======================================
_msg_wnd_clear_down:
		LDA		#$22
		STA		_tmp00
		LDA		#$04

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_msg_wnd_clear_ex:
		STA		_tmp01
		TYA
		PHA
		TXA
		PHA
		LDY		#$0A
loc_440E5:
		JSR		_render_off
		JSR		_ppu_set_ofs_and_add20
		LDA		#$FE
		LDX		#$14					; little fix allow up to 20 chars in
loc_440E7:								; one line to be cleared, fixes at least
		STA		_PPU_DATA				; one problem in scripts.
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
		LDA		_pad
		BNE		_msg_wait_key_release
		RTS

; =============== S U B	R O U T	I N E =======================================
_msg_wait_for_input:
		JSR		_msg_wait_key_release
loc_447C4:
		JSR		_script_sprite_anim
		JSR		_read_pad_safeA
		LDA		_pad
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
; when return to the title screen it will restore regular white coloring
#if LANGUAGE == LANG_US
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$0E
		STA		_PPU_ADDR
		LDA		#$22
		STA		_PPU_DATA
		JSR		_render_on
#endif
		JSR		_cur_game_vars_backup
		JSR		_pass_encode
		JSR		_msg_wait_key_release
loc_44817:
		JSR		_read_pad_safeA
		LDA		_pad
		AND		#$10
		BEQ		loc_44817
		JSR		_render_on_ex_ex
#if LANGUAGE == LANG_US
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$0E
		STA		_PPU_ADDR
		LDA		#$30
		STA		_PPU_DATA
		JSR		_render_on
#endif
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_encode:
		JSR		_pass_encrypt
		LDA		#$26
		STA		_tmp05
		LDA		#$C7
		STA		_tmp06
		LDX		#$00
loc_44860:
		JSR		_pass_get_dataA
		JSR		_pass_write_ppu_char
		INC		_tmp06
		JSR		_pass_get_dataB
		JSR		_pass_write_ppu_char
		INC		_tmp06
		JSR		_pass_get_dataC
		JSR		_pass_write_ppu_char
		INC		_tmp06
		JSR		_pass_get_dataD
		JSR		_pass_write_ppu_char
		INC		_tmp06
		INC		_tmp06
		INX
		INX
		INX
		CPX		#$0C
		BNE		loc_44891
		LDA		#$07
		STA		_tmp06
		LDA		#$27
		STA		_tmp05
loc_44891:
		CPX		#$18
		BNE		loc_44860
		JMP		_pass_decrypt

; =============== S U B	R O U T	I N E =======================================
_pass_get_dataA:
		LDA		_game,X
		AND		#$F0
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
		AND		#$F0
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
_pass_write_ppu_char:
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		_tmp05
		STA		_PPU_ADDR
		LDA		_tmp06
		STA		_PPU_ADDR
		LDA		_tmp02
		CLC
		ADC		#$50
		STA		_PPU_DATA
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
		LDA		_nmi_flag
		BNE		loc_4496B
		RTS
loc_4496B:
		LDA		#$00
		STA		_nmi_flag
		LDA		_tmp14
		BNE		loc_44977
		RTS
loc_44977:
		INC		_tmp14
		LDA		_tmp14
		AND		#$0F
		BEQ		loc_44982
		RTS
loc_44982:
		LDA		_tmp14
		AND		#$10
		BEQ		loc_449C0
		LDA		_tmp11
		AND		#$40
		BNE		loc_449A7
		LDA		_tmp12
		AND		#$02
		BEQ		locret_449F8
		LDX		#$B0
		LDA		#$F8
		JSR		_spr_nibble_fill
		LDX		#$E0
		LDA		#$A8
		JMP		_spr_nibble_fill
loc_449A7:
		LDA		_tmp12
		AND		#$01
		BEQ		locret_449F8
		LDX		#$30
		LDA		#$F8
		JSR		_spr_nibble_fill
		LDX		#$60
		LDA		#$48
		JMP		_spr_nibble_fill
loc_449C0:
		LDA		_tmp11
		AND		#$40
		BNE		loc_449DF
		LDA		_tmp12
		AND		#$02
		BEQ		locret_449F8
		LDX		#$B0
		LDA		#$A8
		JSR		_spr_nibble_fill
		LDX		#$E0
		LDA		#$F8
		JMP		_spr_nibble_fill
loc_449DF:
		LDA		_tmp12
		AND		#$01
		BEQ		locret_449F8
		LDX		#$30
		LDA		#$48
		JSR		_spr_nibble_fill
		LDX		#$60
		LDA		#$F8
		JMP		_spr_nibble_fill
locret_449F8:
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_nibble_fill:
		STA		_spr_buf,X
		INX
		INX
		INX
		INX
		STA		_spr_buf,X
		INX
		INX
		INX
		INX
		STA		_spr_buf,X
		RTS
; ---------------------------------------------------------------------------
_script_cmd_lib:
		.WORD _scr_cmd00_portrait_draw_up
		.WORD _scr_cmd01_portrait_draw_down
		.WORD _scr_cmd02_msg_draw_up
		.WORD _scr_cmd03_msg_draw_down
		.WORD _scr_cmd04_frame_draw_up
		.WORD _scr_cmd05_frame_draw_down
		.WORD _scr_cmd06_frame_draw_custom
		.WORD _scr_cmd07_msg_input_handler
		.WORD _scr_cmd08_input_2_options
		.WORD _scr_cmd09_input_3_options_unused
		.WORD _scr_cmd0A_input_4_options_unused
		.WORD _scr_cmd0B_ptr_load
		.WORD _scr_cmd0C_msg_raw_display
		.WORD _scr_cmd0D_game_flags_set
		.WORD _scr_cmd0E_game_flags_clear
		.WORD _scr_cmd0F_jmp_flag_not_set
		.WORD _scr_cmd10_jmpne_option
		.WORD _scr_cmd11_jmp_branch
		.WORD _scr_cmd12_nop
		.WORD _scr_cmd13_jump
		.WORD _scr_cmd14_stop
		.WORD _scr_cmd15_set_room_idx
		.WORD _scr_cmd16_anim_scene_set
		.WORD _scr_cmd17_player_pos_set
		.WORD _scr_cmd18_mem_write_unused
		.WORD _scr_cmd19_pass_input
		.WORD _scr_cmd1A_game_stats_draw
		.WORD _scr_cmd1B_life_resore
		.WORD _scr_cmd1C_add_10_knifes
		.WORD _scr_cmd21_add_5_potions
		.WORD _scr_cmd21_add_5_potions
		.WORD _scr_cmd21_add_5_potions
		.WORD _scr_cmd21_add_5_potions
		.WORD _scr_cmd21_add_5_potions
		.WORD _scr_cmd22_inc_exp_level_unused
		.WORD _scr_cmd23_game_hours_set
		.WORD _scr_cmd24_checkpoint_restore
		.WORD _scr_cmd25_checkpoint_reset
		.WORD _scr_cmd26_checkpoint_set
		.WORD _scr_cmd27_continue_cur_draw
		.WORD _scr_cmd28_ending_anim
		.WORD _scr_cmd29_scroller

#if LANGUAGE == LANG_US
; =============== S U B	R O U T	I N E =======================================
_ppu_res_draw:
		TYA
		PHA
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
		LDY		#$00
loc_44ADC:
		LDA		(_tmp04),Y
		CMP		#$FF
		BEQ		loc_44AE9
		STA		_PPU_DATA
		INY
		JMP		loc_44ADC
loc_44AE9:
		JSR		_render_on
		INY
		LDA		(_tmp04),Y
		CMP		#$FF
		BEQ		loc_44AFC
		JSR		_render_off
		JSR		_ppu_res_ofs_add64
		JMP		loc_44ADC
loc_44AFC:
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_ppu_res_ofs_add64:
		LDA		_PPU_STATUS
		LDA		_tmp01
		CLC
		ADC		#$40
		STA		_tmp01
		LDA		_tmp00
		ADC		#$00
		STA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
		RTS
#endif

#if LANGUAGE == LANG_JP
; =============== S U B	R O U T	I N E =======================================
_ppu_res_draw:
		TYA
		PHA
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		STA		_tmp02
		LDA		_tmp01
		STA		_PPU_ADDR
		STA		_tmp03
		LDY		#$00
loc_80A88:
		LDA		(_tmp04),Y
		CMP		#$FF
		BEQ		loc_80AD4
		CMP		#$F5
		BCS		loc_80A9B
		STA		_PPU_DATA
		INY
		INC		_tmp03
		JMP		loc_80A88
loc_80A9B:
		LDA		_PPU_STATUS
		SEC
		LDA		_tmp03
		SBC		#$21
		STA		_tmp03
		LDA		_tmp02
		SBC		#$00
		STA		_tmp02
		STA		_PPU_ADDR
		LDA		_tmp03
		STA		_PPU_ADDR
		LDA		(_tmp04),Y
		STA		_PPU_DATA
		INY
		LDA		_PPU_STATUS
		LDA		_tmp03
		CLC
		ADC		#$21
		STA		_tmp03
		LDA		_tmp02
		ADC		#$00
		STA		_tmp02
		STA		_PPU_ADDR
		LDA		_tmp03
		STA		_PPU_ADDR
		JMP		loc_80A88
loc_80AD4:
		JSR		_render_on
		INY
		LDA		(_tmp04),Y
		CMP		#$FF
		BEQ		loc_80AE7
		JSR		_render_off
		JSR		_ppu_res_ofs_add64
		JMP		loc_80A88
loc_80AE7:
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_ppu_res_ofs_add64:
		LDA		_PPU_STATUS
		LDA		_tmp01
		CLC
		ADC		#$40
		STA		_tmp01
		LDA		_tmp00
		ADC		#$00
		STA		_tmp00
		STA		_PPU_ADDR
		STA		_tmp02
		LDA		_tmp01
		STA		_PPU_ADDR
		STA		_tmp03
		RTS
#endif

; =============== S U B	R O U T	I N E =======================================
_sprite_insert:
		TYA
		PHA
		TXA
		PHA
		LDA		_tmp04
		CMP		#$D8
		BNE		loc_44B5D
		JMP		_portrait_clear
loc_44B5D:
		CMP		#$C6
		BNE		loc_44B64
		JMP		_pack_in_time_spr_insert
loc_44B64:
		CMP		#$C8
		BNE		_portrait_spr_insert
		JMP		_title_screen_spr_anim_menu_input

; =============== S U B	R O U T	I N E =======================================
_portrait_spr_insert:
		TAY
		LDA		_portraits_lib,Y
		INY
		STA		_tmp04
		LDA		#$04
		STA		_tmp02
		LDA		#$06
		STA		_tmp03
		LDA		_tmp11
		AND		#$40
		BNE		loc_44B93
		LDA		#$90
		STA		_tmp00
		LDA		#$C0
		STA		_tmp01
		LDX		#$80
		LDA		_tmp12
		ORA		#$02
		STA		_tmp12
		BNE		loc_44BA3
loc_44B93:
		LDA		#$30
		STA		_tmp00
		LDA		#$20
		STA		_tmp01
		LDX		#$00
		LDA		_tmp12
		ORA		#$01
		STA		_tmp12
loc_44BA3:
		JSR		_sprite_sheet_insert
		LDA		_portraits_lib,Y
		INY
		STA		_tmp04
		LDA		#$03
		STA		_tmp02
		LDA		#$01
		STA		_tmp03
		LDA		_tmp11
		AND		#$40
		BNE		loc_44BC7
		LDX		#$E0
		LDA		#$A8
		STA		_tmp00
		LDA		#$C0
		STA		_tmp01
		BNE		loc_44BD1
loc_44BC7:
		LDX		#$60
		LDA		#$48
		STA		_tmp00
		LDA		#$20
		STA		_tmp01
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
		AND		_tmp12
		STA		_tmp12
		JMP		loc_44BF6
loc_44BEE:
		LDX		#$00
		LDA		#$FE
		AND		_tmp12
		STA		_tmp12
loc_44BF6:
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
		LDA     #$02
		STA     _tmp02
		LDA     #$02
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
		LDA		_PPU_STATUS
		LDA		#$23
		STA		_PPU_ADDR
		LDA		#$D8
		STA		_PPU_ADDR
		LDY		#$00
		LDA		#$AA
loc_44C3D:
		STA		_PPU_DATA
		INY
		CPY		#$10
		BNE		loc_44C3D
		JSR		_render_on
		LDA		#$05
		STA		_tmp0A
		JSR		_msg_pal_lib_load
		LDA		#$01
		STA		_tmp0A
		LDA		#$00
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
		LDA		_tmp13
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
		LDA		_pad
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
		LDA		_pad
		BEQ		loc_44C9E
		LDA		_pad
		AND		#$10
		BNE		loc_44CCE
		LDA		_pad
		AND		#$20
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
		CPY		#$DD
		BNE		loc_44CE7
		LDY		#$C8
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
_spr_pack_int_time:
		.BYTE $48,$EE
_spr_title_anim:
		.BYTE $00,$40,$00,$50,$00,$51,$41
		.BYTE $18,$10,$00,$54,$01,$54,$05
		.BYTE $30,$50,$05,$50,$45,$50,$45

; =============== S U B	R O U T	I N E =======================================
_read_pad_safeA:
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
		LDX		#$00
loc_44EC4:
		LDA		_pal_portrait_lib,Y
		INY
		STA		_PPU_DATA
		INX
		CPX		#$10
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
_pal_bg_default:
		.BYTE $0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$16,$0F,$0F,$30,$30
_pal_portrait_lib:
		.BYTE $0F,$10,$36,$0A,$0F,$16,$36,$17,$0F,$1A,$36,$37,$0F,$1C,$36,$30
		.BYTE $0F,$0F,$0F,$0F,$0F,$0F,$0F,$06,$0F,$12,$16,$30,$0F,$2A,$16,$30
		.BYTE $0F,$0F,$0F,$06,$0F,$0F,$06,$16,$0F,$0F,$0F,$0F,$0F,$0F,$30,$30
		.BYTE $0F,$0F,$06,$16,$0F,$06,$16,$27,$0F,$0F,$0F,$0F,$0F,$0F,$30,$30
		.BYTE $0F,$06,$16,$27,$0F,$16,$27,$37,$0F,$0F,$0F,$0F,$0F,$0F,$30,$30
		.BYTE $0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$30,$30

; =============== S U B	R O U T	I N E =======================================
_pass_input_screen:
		LDA		#$00
		STA		_tmp0A
		JSR		_msg_pal_lib_load
		LDA		#$00
		STA		_tmp03
		STA		_tmp04
		LDA		#$20
		STA		_tmp05
		LDA		#$A7
		STA		_tmp06
loc_44F6D:
		LDA		#$00
		STA		_pad
		JSR		_pass_input_control
		LDA		_tmp01
		STA		_tmp02
		BEQ		loc_44F84
		LDA		#$00
loc_44F7D:
		CLC
		ADC		#$0A
		DEC		_tmp02
		BNE		loc_44F7D
loc_44F84:
		CLC
		ADC		_tmp00
		STA		_tmp02
		CMP		#$24
		BCC		loc_44F94
		SEC
		LDA		_tmp02
		SBC		#$04
		STA		_tmp02
loc_44F94:
		CMP		#$40
		BCC		loc_44FCB
		CMP		#$46
		BNE		loc_44F9F
		JMP		_pass_decode
loc_44F9F:
		CMP		#$44
		BEQ		loc_44FE6
loc_44FA3:
		DEC		_tmp06
		LDA		_tmp06
		AND		#$1F
		CMP		#$0B
		BEQ		loc_44FA3
		CMP		#$10
		BEQ		loc_44FA3
		CMP		#$15
		BEQ		loc_44FA3
		CMP		#$06
		BNE		loc_4500B
		SEC
		LDA		_tmp06
		SBC		#$2D
		STA		_tmp06
		CMP		#$79
		BNE		loc_4500B
		LDA		#$A7
		STA		_tmp06
		JMP		loc_44F6D
loc_44FCB:
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		_tmp05
		STA		_PPU_ADDR
		LDA		_tmp06
		STA		_PPU_ADDR
		LDA		_tmp02
		CLC
		ADC		#$50
		STA		_PPU_DATA
		JSR		_render_on
loc_44FE6:
		INC		_tmp06
		LDA		_tmp06
		AND		#$1F
		CMP		#$0B
		BEQ		loc_44FE6
		CMP		#$10
		BEQ		loc_44FE6
		CMP		#$15
		BEQ		loc_44FE6
		CMP		#$1A
		BNE		loc_4500B
		LDA		_tmp06
		CLC
		ADC		#$2D
		STA		_tmp06
		CMP		#$27
		BNE		loc_4500B
		LDA		#$F9
		STA		_tmp06
loc_4500B:
		JMP		loc_44F6D

; =============== S U B	R O U T	I N E =======================================
_pass_input_control:
		LDA		_tmp04
		STA		_tmp01
		CMP		#$07
		BEQ		loc_4501D
		LDA		_tmp03
		STA		_tmp00
		JMP		loc_45023
loc_4501D:
		LDA		_tmp03
		AND		#$FE
		STA		_tmp00
loc_45023:
		LDA		_tmp01
		CMP		#$03
		BEQ		loc_45034
		CMP		#$06
		BEQ		loc_45041
		CMP		#$07
		BEQ		loc_4504E
		BNE		loc_45058
loc_45034:
		LDA		_tmp00
		CMP		#$06
		BCC		loc_45058
		LDA		#$05
		STA		_tmp00
		BNE		loc_45058
loc_45041:
		LDA		_tmp00
		CMP		#$08
		BCC		loc_45058
		LDA		#$07
		STA		_tmp00
		BNE		loc_45058
loc_4504E:
		LDA		_tmp00
		CMP		#$06
		BCC		loc_45058
		LDA		#$04
		STA		_tmp00
loc_45058:
		LDA		_pad
		AND		#$80
		BEQ		loc_45062
		RTS
loc_45062:
		ASL		_tmp00
		ASL		_tmp00
		ASL		_tmp00
		ASL		_tmp00
		LDA		_tmp00
		CLC
		ADC		#$30
		STA		_tmp00
		ASL		_tmp01
		ASL		_tmp01
		ASL		_tmp01
		ASL		_tmp01
		LDA		_tmp01
		CLC
		ADC		#$54
		STA		_tmp01
		LDA		_tmp01
		STA		_spr_buf+$F8
		LDA		#$4F
		STA		_spr_buf+$F9
		LDA		#$03
		STA		_spr_buf+$FA
		LDA		_tmp00
		STA		_spr_buf+$FB
		LDA		_tmp06
		AND		#$1F
		STA		_tmp00
		ASL		_tmp00
		ASL		_tmp00
		ASL		_tmp00
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
		LDA		_tmp00
		STA		_spr_buf+$FF
		LDA		#$00
		STA		_tmp14
loc_450C9:
		LDA		_nmi_flag
		BEQ		loc_450DB
		LDA		#$00
		STA		_nmi_flag
		INC		_tmp14
		LDA		_tmp14
		AND		#$10
		BNE		loc_450E3
loc_450DB:
		JSR		_read_pad_safeA
		LDA		_pad
		BNE		loc_450C9
loc_450E3:
		JSR		_read_pad_safeA
		LDA		_pad
		BEQ		loc_450E3
		AND		#$01
		BNE		loc_45107
		LDA		_pad
		AND		#$02
		BNE		loc_45129
		LDA		_pad
		AND		#$08
		BNE		loc_4514B
		LDA		_pad
		AND		#$04
		BNE		loc_4515A
		JMP		_pass_input_control
loc_45107:
		INC		_tmp03
		LDA		_tmp04
		CMP		#$03
		BEQ		loc_4516C
		CMP		#$06
		BEQ		loc_45175
		CMP		#$07
		BNE		loc_4511C
		INC		_tmp03
		JMP		loc_4517E
loc_4511C:
		LDA		_tmp03
		CMP		#$0A
		BCC		_j_pass_input_control
loc_45122:
		LDA		#$00
		STA		_tmp03
		JMP		_pass_input_control
loc_45129:
		DEC		_tmp03
		LDA		_tmp04
		CMP		#$03
		BEQ		loc_45187
		CMP		#$06
		BEQ		loc_4519D
		CMP		#$07
		BNE		loc_4513E
		DEC		_tmp03
		JMP		loc_451B3
loc_4513E:
		LDA		_tmp03
		AND		#$80
		BEQ		_j_pass_input_control
		LDA		#$09
		STA		_tmp03
		JMP		_pass_input_control
loc_4514B:
		DEC		_tmp04
		LDA		_tmp04
		AND		#$80
		BEQ		_j_pass_input_control
		LDA		#$07
		STA		_tmp04
		JMP		_pass_input_control
loc_4515A:
		INC		_tmp04
		LDA		_tmp04
		CMP		#$08
		BCC		_j_pass_input_control
		LDA		#$00
		STA		_tmp04
_j_pass_input_control:
		JMP		_pass_input_control
loc_4516C:
		LDA		_tmp03
		CMP		#$06
		BCC		_j_pass_input_control
		JMP		loc_45122
loc_45175:
		LDA		_tmp03
		CMP		#$08
		BCC		_j_pass_input_control
		JMP		loc_45122
loc_4517E:
		LDA		_tmp03
		CMP		#$06
		BCC		_j_pass_input_control
		JMP		loc_45122
loc_45187:
		LDA		_tmp03
		CMP		#$06
		BCC		_j_pass_input_control
		AND		#$80
		BEQ		loc_45196
		LDA		#$05
		BNE		loc_45198
loc_45196:
		LDA		#$04
loc_45198:
		STA		_tmp03
		JMP		_j_pass_input_control
loc_4519D:
		LDA		_tmp03
		CMP		#$08
		BCC		_j_pass_input_control
		AND		#$80
		BEQ		loc_451AC
		LDA		#$07
		BNE		loc_451AE
loc_451AC:
		LDA		#$06
loc_451AE:
		STA		_tmp03
		JMP		_j_pass_input_control
loc_451B3:
		LDA		_tmp03
		CMP		#$06
		BCC		_j_pass_input_control
		AND		#$80
		BEQ		loc_451C2
		LDA		#$04
		BNE		loc_451C4
loc_451C2:
		LDA		#$02
loc_451C4:
		STA		_tmp03
		JMP		_j_pass_input_control
locret_451C9:
		RTS

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
		LDY		#$00
		LDA		#$00
loc_45217:
		CPY		#$0A
		BEQ		loc_4521F
		CLC
		ADC		_game,Y
loc_4521F:
		INY
		CPY		#$18
		BNE		loc_45217
		STA		_game._crc
		LDX		_game._crc
		LDY		#$00
loc_4522C:
		CPY		#$0A
		BEQ		loc_45239
		LDA		_game,Y
		EOR		_pass_decrypt,X
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
		LDX		_game._crc
		LDY		#$00
loc_45249:
		CPY		#$0A
		BEQ		loc_45256
		LDA		_game,Y
		EOR		_pass_decrypt,X
		STA		_game,Y
loc_45256:
		INY
		INX
		CPY		#$18
		BNE		loc_45249
		LDY		#$00
		LDA		#$00
loc_45260:
		CPY		#$0A
		BEQ		loc_45268
		CLC
		ADC		_game,Y
loc_45268:
		INY
		CPY		#$18
		BNE		loc_45260
		CMP		_game._crc
		BEQ		loc_45279
		LDA		#$02
		BNE		loc_4527A
loc_45279:
		LDA		#$01
loc_4527A:
		STA		_tmp13
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_pass_store_dataA:
		LDA		_tmp02
		AND		#$0F
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
		AND		#$0F
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
_pass_read_ppu_char:
		JSR		_render_off
		LDA		_PPU_STATUS
		LDA		_tmp05
		STA		_PPU_ADDR
		LDA		_tmp06
		STA		_PPU_ADDR
		LDA		_PPU_DATA
		SEC
		LDA		_PPU_DATA
		SBC		#$50
		STA		_tmp02
		JMP		_render_on

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
