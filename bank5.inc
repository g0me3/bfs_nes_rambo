
		ORG $8000

		BANK_START $05

; =============== S U B	R O U T	I N E =======================================
_inventory_screen:
		LDA		#$90
		STA		_PPU_CTRL
		JSR		_screen_off
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
		JSR		_screen_off
loc_4402E:
		JSR		_read_pad_safeA
		LDA		_pad
		AND		#$30
		BNE		loc_4402E
		RTS

; =============== S U B	R O U T	I N E =======================================
_screen_off:
		JSR		_wait_for_nmi
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDY		#$00
		LDA		#$0F
loc_4404D:
		STA		_PPU_DATA
		INY
		CPY		#$20
		BNE		loc_4404D
		JSR		_ppu_regs_reinit
		RTS

; =============== S U B	R O U T	I N E =======================================
_ppu_screen_clear:
		LDA		#$10
		STA		_PPU_CTRL
		LDA		#$00
		STA		_PPU_MASK
		LDA		_PPU_STATUS
		LDA		#$24
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		#$FE
		LDY		#$1E
loc_44074:
		LDX		#$20
loc_44076:
		STA		_PPU_DATA
		DEX
		BNE		loc_44076
		DEY
		BNE		loc_44074
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		#$FE
		LDY		#$1E
loc_44090:
		LDX		#$20
loc_44092:
		STA		_PPU_DATA
		DEX
		BNE		loc_44092
		DEY
		BNE		loc_44090
		LDA		_PPU_STATUS
		LDA		#$23
		STA		_PPU_ADDR
		LDA		#$C0
		STA		_PPU_ADDR
		LDA		#$FF
		LDY		#$40
loc_440AC:
		STA		_PPU_DATA
		DEY
		BNE		loc_440AC
		LDA		_PPU_STATUS
		LDA		#$27
		STA		_PPU_ADDR
		LDA		#$C0
		STA		_PPU_ADDR
		LDA		#$FF
		LDY		#$40
loc_440C3:
		STA		_PPU_DATA
		DEY
		BNE		loc_440C3
		JSR		_ppu_regs_reinit
		RTS

; =============== S U B	R O U T	I N E =======================================
_msg_rect_clear:
		TYA
		PHA
		TXA
		PHA
		JSR		_wait_for_nmi
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
		LDA		#$FE
		LDY		_tmp03
loc_440E5:
		LDX		_tmp02
loc_440E7:
		STA		_PPU_DATA
		DEX
		BNE		loc_440E7
		JSR		_ppu_regs_reinit
		JSR		_wait_for_nmi
		LDA		_PPU_STATUS
		LDA		_tmp01
		CLC
		ADC		#$20
		STA		_tmp01
		LDA		_tmp00
		ADC		#$00
		STA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
		LDA		#$FE
		DEY
		BNE		loc_440E5
		JSR		_ppu_regs_reinit
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_frame_draw:
		TYA
		PHA
		TXA
		PHA
		JSR		_wait_for_nmi
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
		LDA		#$F7
		LDY		_tmp03
		DEY
		LDX		_tmp02
		DEX
loc_44134:
		STA		_PPU_DATA
		LDA		#$F8
		DEX
		BNE		loc_44134
		LDA		#$F9
		STA		_PPU_DATA
		JSR		_ppu_regs_reinit
		JSR		_wait_for_nmi
		JSR		_ppu_add_of_32
		DEY
loc_4414B:
		LDA		#$FD
		LDX		_tmp02
		DEX
loc_44150:
		STA		_PPU_DATA
		LDA		#$FE
		DEX
		BNE		loc_44150
		LDA		#$FF
		STA		_PPU_DATA
		JSR		_ppu_regs_reinit
		JSR		_wait_for_nmi
		JSR		_ppu_add_of_32
		DEY
		BNE		loc_4414B
		LDA		#$FA
		LDX		_tmp02
		DEX
loc_4416E:
		STA		_PPU_DATA
		LDA		#$FB
		DEX
		BNE		loc_4416E
		LDA		#$FC
		STA		_PPU_DATA
		JSR		_ppu_regs_reinit
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_ppu_add_of_32:
		LDA		_PPU_STATUS
		LDA		_tmp01
		CLC
		ADC		#$20
		STA		_tmp01
		LDA		_tmp00
		ADC		#$00
		STA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
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

; =============== S U B	R O U T	I N E =======================================
_script_cmd_fetch:
		LDA		_tmp11
		AND		#$04
		BEQ		loc_441CD
		JMP		locret_441DF
; ---------------------------------------------------------------------------
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
; ---------------------------------------------------------------------------
locret_441DF:
		RTS

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
		JSR		_msg_rect0Ax13_clearB
loc_4420B:
		LDA		_tmp11
		AND		#$FC
		ORA		#$01
		STA		_tmp11
		JSR		_msg_rect0Ax13_clearA
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
		JSR		_msg_rect0Ax13_clearA
loc_44237:
		LDA		_tmp11
		AND		#$FC
		ORA		#$02
		STA		_tmp11
		JSR		_msg_rect0Ax13_clearB
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
		JMP		loc_44302
; ---------------------------------------------------------------------------
_input_2_options:
		LDA		#$00
		TAY
		JMP		loc_442D4
; ---------------------------------------------------------------------------
_input_3_options:
		LDA		#$03
		TAY
		JMP		loc_442D4
; ---------------------------------------------------------------------------
_input_4_options:
		LDA		#$07
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
		BNE		loc_44302
		LDA		_pad
		AND		#$0F
		BEQ		loc_442FF
		INC		_tmp13
		INY
loc_442FF:
		JMP		loc_442D4
; ---------------------------------------------------------------------------
loc_44302:
		LDA		_tmp11
		AND		#$C7
		STA		_tmp11
		LDA		#$F8
		STA		_spr_buf+$FC
		PLA
		TAY
		JMP		_script_cmd_fetch

; ---------------------------------------------------------------------------
_msg_option_pos_list:
		.BYTE $88,$B8,$00
		.BYTE $88,$A8,$C8,$00
		.BYTE $88,$98,$A8,$B8,$C8,$00
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
_scr_cmd0E_game_flags_toggle:
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
; ---------------------------------------------------------------------------
loc_443C6:
		JMP		_script_cmd_fetch

; ---------------------------------------------------------------------------
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

; =============== S U B	R O U T	I N E =======================================
_script_look_for_rets:
		LDA		(_tmp0D),Y
		INY
		CMP		#$11
		BEQ		loc_44448
		CMP		#$12
		BEQ		loc_4443E
		JMP		_script_look_for_rets
; ---------------------------------------------------------------------------
loc_4443E:
		LDA		(_tmp0D),Y
		INY
		CMP		#$12
		BNE		_script_look_for_rets
		JMP		_j_script_cmd_fetch
; ---------------------------------------------------------------------------
loc_44448:
		LDA		(_tmp0D),Y
		INY
		CMP		#$11
		BNE		_script_look_for_rets

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
		STA.W		_tmp00
		LDA		_game._life+1
		STA.W		_tmp01
		JSR		_hex_to_dec_0
		LDA		#$24
		STA		_tmp00
		LDA		#$6C
		STA		_tmp01
		LDX		#_tmp05-1
		JSR		_ppu_num_draw
		LDA		_game._exp
		STA.W		_tmp00
		LDA		_game._exp+1
		STA.W		_tmp01
		JSR		_hex_to_dec_0
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
		STA.W		_tmp00
		INX
		LDA		_max_life_list,X
		STA.W		_tmp01
		JSR		_hex_to_dec_0
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
		STA.W		_tmp00
		INX
		LDA		_next_exp_list,X
		STA.W		_tmp01
		JSR		_hex_to_dec_0
		LDA		#$24
		STA		_tmp00
		LDA		#$B7
		STA		_tmp01
		LDX		#_tmp05-1
		JSR		_ppu_num_draw
		LDA		_game._play_hours
		STA.W		_tmp00
		LDA		#$00
		STA.W		_tmp01
		JSR		_hex_to_dec_0
		LDA		#$24
		STA		_tmp00
		LDA		#$EC
		STA		_tmp01
		LDX		#_tmp03-1
		JSR		_ppu_num_draw
		LDA		_game._play_minutes
		STA.W		_tmp00
		LDA		#$00
		STA.W		_tmp01
		JSR		_hex_to_dec_0
		LDA		#$0E
		STA.W		_tmp04
		LDA		#$24
		STA		_tmp00
		LDA		#$EE
		STA		_tmp01
		LDX		#_tmp04-1
		JSR		_ppu_num_draw
		LDA		_play_seconds
		STA.W		_tmp00
		LDA		#$00
		STA.W		_tmp01
		JSR		_hex_to_dec_0
		LDA		#$0E
		STA.W		_tmp04
		LDA		#$24
		STA		_tmp00
		LDA		#$F1
		STA		_tmp01
		LDX		#_tmp04-1
		JSR		_ppu_num_draw
		JMP		_script_cmd_fetch

; ---------------------------------------------------------------------------
_max_life_list:
		.WORD 100
		.WORD 200
		.WORD 300
		.WORD 400
		.WORD 500
		.WORD 600
		.WORD 700
		.WORD 800
_next_exp_list:
		.WORD 20
		.WORD 300
		.WORD 600
		.WORD 1500
		.WORD 3000
		.WORD 6000
		.WORD 9000
		.WORD 9000
; =============== S U B	R O U T	I N E =======================================
_ppu_num_draw:
		JSR		_wait_for_nmi
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
loc_445EF:
		LDA.W		$0001,X
		CLC
		ADC		#$D8
		STA		_PPU_DATA
		DEX
		BNE		loc_445EF
		JSR		_ppu_regs_reinit
		RTS

; =============== S U B	R O U T	I N E =======================================
_scr_cmd1B_life_resore:
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
		JSR		_wait_for_nmi
		INX
		TXA
		CMP		#$40
		BEQ		loc_44676
		AND		#$02
		BNE		loc_4464B
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		TXA
		PHA
		LDX		#$0E
		LDA		#$02
loc_44633:
		STA		_PPU_DATA
		DEX
		BNE		loc_44633
		LDA		#$30
		STA		_PPU_DATA
		LDA		#$30
		STA		_PPU_DATA
		PLA
		TAX
		JSR		_ppu_regs_reinit
		JMP		loc_44613
; ---------------------------------------------------------------------------
loc_4464B:
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		TXA
		PHA
		LDX		#$0E
		LDA		#$0F
loc_4465E:
		STA		_PPU_DATA
		DEX
		BNE		loc_4465E
		LDA		#$30
		STA		_PPU_DATA
		LDA		#$30
		STA		_PPU_DATA
		PLA
		TAX
		JSR		_ppu_regs_reinit
		JMP		loc_44613
; ---------------------------------------------------------------------------
loc_44676:
		JSR		_ppu_regs_reinit
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
		STA		_game._life
		JMP		loc_446E8
; ---------------------------------------------------------------------------
loc_446E2:
		LDA		_game_life_backup
		STA		_game._life
loc_446E8:
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
		LDA		#$A8
		JMP		loc_44735
; ---------------------------------------------------------------------------
loc_44733:
		LDA		#$B8
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
; ---------------------------------------------------------------------------
loc_4475D:
		JMP		_script_cmd_fetch

; =============== S U B	R O U T	I N E =======================================
_scr_cmd28_ending_anim:
		LDX		#$FF
		LDA		#$01
		STA		_tmp14
loc_44766:
		JSR		_script_sprite_anim
		JSR		_wait_for_nmi
		JSR		_ppu_regs_reinit
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
_msg_rect0Ax13_clearA:
		LDA		#$20
		STA		_tmp00
		LDA		#$8A
		STA		_tmp01
		LDA		#$13
		STA		_tmp02
		LDA		#$0A
		STA		_tmp03
		JSR		_msg_rect_clear
		RTS

; =============== S U B	R O U T	I N E =======================================
_msg_rect0Ax13_clearB:
		LDA		#$22
		STA		_tmp00
		LDA		#$04
		STA		_tmp01
		LDA		#$13
		STA		_tmp02
		LDA		#$0A
		STA		_tmp03
		JSR		_msg_rect_clear
		RTS

; =============== S U B	R O U T	I N E =======================================
_msg_wait_for_input:
		JSR		_read_pad_safeA
		LDA		_pad
		BNE		_msg_wait_for_input
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
		JSR		_wait_for_nmi
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDX		#$0E
		LDA		#$0F
loc_447F6:
		STA		_PPU_DATA
		DEX
		BNE		loc_447F6
		LDA		#$22
		STA		_PPU_DATA
		LDA		#$30
		STA		_PPU_DATA
		JSR		_ppu_regs_reinit
		JSR		_cur_game_vars_backup
		JSR		_pass_encode
loc_4480F:
		JSR		_read_pad_safeA
		LDA		_pad
		BNE		loc_4480F
loc_44817:
		JSR		_read_pad_safeA
		LDA		_pad
		AND		#$10
		BEQ		loc_44817
		LDA		#$90
		STA		_PPU_CTRL
		LDA		#$1E
		STA		_PPU_MASK
		JSR		_wait_for_nmi
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDX		#$0E
		LDA		#$0F
loc_4483F:
		STA		_PPU_DATA
		DEX
		BNE		loc_4483F
		LDA		#$30
		STA		_PPU_DATA
		LDA		#$30
		STA		_PPU_DATA
		JSR		_ppu_regs_reinit
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
		JSR		_pass_decrypt
		RTS

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
		JSR		_wait_for_nmi
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
		JMP		locret_449F8
; ---------------------------------------------------------------------------
loc_4496B:
		LDA		#$00
		STA		_nmi_flag
		LDA		_tmp14
		BNE		loc_44977
		JMP		locret_449F8
; ---------------------------------------------------------------------------
loc_44977:
		INC		_tmp14
		LDA		_tmp14
		AND		#$0F
		BEQ		loc_44982
		JMP		locret_449F8
; ---------------------------------------------------------------------------
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
		LDA		#$B0
		TAX
		LDA		#$F8
		JSR		_spr_nibble_fill
		LDA		#$E0
		TAX
		LDA		#$A8
		JSR		_spr_nibble_fill
		JMP		locret_449F8
; ---------------------------------------------------------------------------
loc_449A7:
		LDA		_tmp12
		AND		#$01
		BEQ		locret_449F8
		LDA		#$30
		TAX
		LDA		#$F8
		JSR		_spr_nibble_fill
		LDA		#$60
		TAX
		LDA		#$48
		JSR		_spr_nibble_fill
		JMP		locret_449F8
; ---------------------------------------------------------------------------
loc_449C0:
		LDA		_tmp11
		AND		#$40
		BNE		loc_449DF
		LDA		_tmp12
		AND		#$02
		BEQ		locret_449F8
		LDA		#$B0
		TAX
		LDA		#$A8
		JSR		_spr_nibble_fill
		LDA		#$E0
		TAX
		LDA		#$F8
		JSR		_spr_nibble_fill
		JMP		locret_449F8
; ---------------------------------------------------------------------------
loc_449DF:
		LDA		_tmp12
		AND		#$01
		BEQ		locret_449F8
		LDA		#$30
		TAX
		LDA		#$48
		JSR		_spr_nibble_fill
		LDA		#$60
		TAX
		LDA		#$F8
		JSR		_spr_nibble_fill
		JMP		locret_449F8
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

; =============== S U B	R O U T	I N E =======================================
_hex_to_dec_0:
		LDA		#$00
		STA		_tmp02
		STA		_tmp03
		STA		_tmp04
		STA		_tmp05
loc_44A15:
		JSR		_cmp1000_0
		BCC		loc_44A22
		JSR		_sub1000_0
		INC		_tmp05
		JMP		loc_44A15
; ---------------------------------------------------------------------------
loc_44A22:
		JSR		_cmp100_0
		BCC		loc_44A2F
		JSR		_sub100_0
		INC		_tmp04
		JMP		loc_44A22
; ---------------------------------------------------------------------------
loc_44A2F:
		LDA		_tmp00
loc_44A31:
		CMP		#$0A
		BCS		loc_44A38
		STA		_tmp02
		RTS
; ---------------------------------------------------------------------------
loc_44A38:
		SEC
		SBC		#$0A
		INC		_tmp03
		JMP		loc_44A31

; =============== S U B	R O U T	I N E =======================================
_cmp1000_0:
		LDA		_tmp01
		CMP		#$03
		BEQ		loc_44A47
		RTS
; ---------------------------------------------------------------------------
loc_44A47:
		LDA		_tmp00
		CMP		#$E8
		RTS

; =============== S U B	R O U T	I N E =======================================
_cmp100_0:
		LDA		_tmp01
		CMP		#$00
		BEQ		loc_44A53
		RTS
; ---------------------------------------------------------------------------
loc_44A53:
		LDA		_tmp00
		CMP		#$64
		RTS

; =============== S U B	R O U T	I N E =======================================
_sub1000_0:
		LDA		_tmp00
		SEC
		SBC		#$E8
		STA		_tmp00
		LDA		_tmp01
		SBC		#$03
		STA		_tmp01
		RTS

; =============== S U B	R O U T	I N E =======================================
_sub100_0:
		LDA		_tmp00
		SEC
		SBC		#$64
		STA		_tmp00
		LDA		_tmp01
		SBC		#$00
		STA		_tmp01
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
		.WORD _scr_cmd0E_game_flags_toggle
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
; =============== S U B	R O U T	I N E =======================================
_ppu_res_draw:
		TYA
		PHA
		JSR		_wait_for_nmi
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
; ---------------------------------------------------------------------------
loc_44AE9:
		JSR		_ppu_regs_reinit
		INY
		LDA		(_tmp04),Y
		CMP		#$FF
		BEQ		loc_44AFC
		JSR		_wait_for_nmi
		JSR		_ppu_res_ofs_add64
		JMP		loc_44ADC
; ---------------------------------------------------------------------------
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

; =============== S U B	R O U T	I N E =======================================
_wait_for_nmi:
		LDA		#$00
		STA		_nmi_flag
loc_44B1D:
		LDA		_nmi_flag
		BEQ		loc_44B1D
		LDA		#$10
		STA		_PPU_CTRL
		LDA		#$00
		STA		_PPU_MASK
		RTS

; =============== S U B	R O U T	I N E =======================================
_ppu_regs_reinit:
		LDA		_PPU_STATUS
		LDA		#$00
		STA		_PPU_SCROLL
		STA		_PPU_SCROLL
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		#$1E
		STA		_PPU_MASK
		LDA		#$90
		STA		_PPU_CTRL
		RTS

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
; ---------------------------------------------------------------------------
loc_44B5D:
		CMP		#$C6
		BNE		loc_44B64
		JMP		_pack_in_time_spr_insert
; ---------------------------------------------------------------------------
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
		JMP		loc_44BA3
; ---------------------------------------------------------------------------
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
		JSR		_sprite_sheet_insertB
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
		JMP		loc_44BD1
; ---------------------------------------------------------------------------
loc_44BC7:
		LDX		#$60
		LDA		#$48
		STA		_tmp00
		LDA		#$20
		STA		_tmp01
loc_44BD1:
		JSR		_sprite_sheet_insertB
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
; ---------------------------------------------------------------------------
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
		LDA		#$01
		STA		_tmp0A
		JSR		_msg_pal_lib_load
		LDA		#$80
		STA		_tmp14
loc_44C1A:
		JSR		_wait_for_nmi
		JSR		_ppu_regs_reinit
		INC		_tmp14
		BNE		loc_44C1A
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_title_screen_spr_anim_menu_input:
		JSR		_wait_for_nmi
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
		JSR		_ppu_regs_reinit
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
		LDA		#$A8
		JMP		loc_44C84
; ---------------------------------------------------------------------------
loc_44C82:
		LDA		#$B8
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
; ---------------------------------------------------------------------------
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
		JSR		_sprite_sheet_insertB
		RTS

; =============== S U B	R O U T	I N E =======================================
_sprite_sheet_insertB:
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
; ---------------------------------------------------------------------------
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
		.BYTE $00,$55,$55,$55,$55,$00,$00,$F0,$55
		.BYTE $18,$55,$55,$55,$5A,$08,$00,$24,$5A; 9
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
		TYA
		PHA
		TXA
		PHA
loc_44E52:
		LDA		#$00
		JSR		_read_padA
		STA		_pad
		LDA		#$00
		JSR		_read_padA
		CMP		_pad
		BNE		loc_44E52
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_read_padA:
		BEQ		loc_44E6E
		LDA		#<[_PAD1_REG]
; ---------------------------------------------------------------------------
		.BYTE $AE
; ---------------------------------------------------------------------------
loc_44E6E:
		LDA		#<[_PAD0_REG]
		STA		_tmp01
		LDA		#>[_PAD0_REG]
		STA		_tmp02
		LDA		#$01
		STA		_PAD0_REG
		NOP
		NOP
		LDA		#$00
		STA		_tmp0B
		TAY
		TAX
		STA		_PAD0_REG
		NOP
		NOP
loc_44E88:
		LDA		(_tmp01),Y
		STA		_tmp00
		LSR
		ORA		_tmp00
		LSR
		ROL		_tmp0B
		INX
		CPX		#$08
		BNE		loc_44E88
		LDA		_tmp0B
		RTS

; =============== S U B	R O U T	I N E =======================================
_msg_pal_lib_load:
		TYA
		PHA
		TXA
		PHA
		JSR		_wait_for_nmi
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
		JSR		_ppu_regs_reinit
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
; ---------------------------------------------------------------------------
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
		JMP		loc_4500B
; ---------------------------------------------------------------------------
loc_44FCB:
		JSR		_wait_for_nmi
		LDA		_PPU_STATUS
		LDA		_tmp05
		STA		_PPU_ADDR
		LDA		_tmp06
		STA		_PPU_ADDR
		LDA		_tmp02
		CLC
		ADC		#$50
		STA		_PPU_DATA
		JSR		_ppu_regs_reinit
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
; ---------------------------------------------------------------------------
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
		JMP		loc_45058
; ---------------------------------------------------------------------------
loc_45034:
		LDA		_tmp00
		CMP		#$06
		BCC		loc_45058
		LDA		#$05
		STA		_tmp00
		JMP		loc_45058
; ---------------------------------------------------------------------------
loc_45041:
		LDA		_tmp00
		CMP		#$08
		BCC		loc_45058
		LDA		#$07
		STA		_tmp00
		JMP		loc_45058
; ---------------------------------------------------------------------------
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
		JMP		locret_451C9
; ---------------------------------------------------------------------------
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
		ADC		#$58
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
		LDA		#$40
		STA		_tmp01
		JMP		loc_450B1
; ---------------------------------------------------------------------------
loc_450AD:
		LDA		#$30
		STA		_tmp01
loc_450B1:
		LDA		_tmp01
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
		JMP		loc_45169
; ---------------------------------------------------------------------------
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
; ---------------------------------------------------------------------------
loc_4511C:
		LDA		_tmp03
		CMP		#$0A
		BCC		loc_45169
loc_45122:
		LDA		#$00
		STA		_tmp03
		JMP		loc_45169
; ---------------------------------------------------------------------------
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
; ---------------------------------------------------------------------------
loc_4513E:
		LDA		_tmp03
		AND		#$80
		BEQ		loc_45169
		LDA		#$09
		STA		_tmp03
		JMP		loc_45169
; ---------------------------------------------------------------------------
loc_4514B:
		DEC		_tmp04
		LDA		_tmp04
		AND		#$80
		BEQ		loc_45169
		LDA		#$07
		STA		_tmp04
		JMP		loc_45169
; ---------------------------------------------------------------------------
loc_4515A:
		INC		_tmp04
		LDA		_tmp04
		CMP		#$08
		BCC		loc_45169
		LDA		#$00
		STA		_tmp04
		JMP		loc_45169
loc_45169:
		JMP		_pass_input_control
; ---------------------------------------------------------------------------
loc_4516C:
		LDA		_tmp03
		CMP		#$06
		BCC		loc_45169
		JMP		loc_45122
; ---------------------------------------------------------------------------
loc_45175:
		LDA		_tmp03
		CMP		#$08
		BCC		loc_45169
		JMP		loc_45122
; ---------------------------------------------------------------------------
loc_4517E:
		LDA		_tmp03
		CMP		#$06
		BCC		loc_45169
		JMP		loc_45122
; ---------------------------------------------------------------------------
loc_45187:
		LDA		_tmp03
		CMP		#$06
		BCC		loc_45169
		AND		#$80
		BEQ		loc_45196
		LDA		#$05
		JMP		loc_45198
; ---------------------------------------------------------------------------
loc_45196:
		LDA		#$04
loc_45198:
		STA		_tmp03
		JMP		loc_45169
; ---------------------------------------------------------------------------
loc_4519D:
		LDA		_tmp03
		CMP		#$08
		BCC		loc_45169
		AND		#$80
		BEQ		loc_451AC
		LDA		#$07
		JMP		loc_451AE
; ---------------------------------------------------------------------------
loc_451AC:
		LDA		#$06
loc_451AE:
		STA		_tmp03
		JMP		loc_45169
; ---------------------------------------------------------------------------
loc_451B3:
		LDA		_tmp03
		CMP		#$06
		BCC		loc_45169
		AND		#$80
		BEQ		loc_451C2
		LDA		#$04
		JMP		loc_451C4
; ---------------------------------------------------------------------------
loc_451C2:
		LDA		#$02
loc_451C4:
		STA		_tmp03
		JMP		loc_45169
; ---------------------------------------------------------------------------
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
		JSR		_pass_decrypt
		RTS

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
		STA		_tmp13
		PLA
		TAY
		RTS
; ---------------------------------------------------------------------------
loc_45279:
		LDA		#$01
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
		JSR		_wait_for_nmi
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
		JSR		_ppu_regs_reinit
		RTS

; ---------------------------------------------------------------------------
_script_lib:
		.WORD _script80
		.WORD _script81
		.WORD _script82
		.WORD _script83
		.WORD _script84
		.WORD _script85
		.WORD _script86
		.WORD _script87
		.WORD _script88
		.WORD _script89
		.WORD _script8A
		.WORD _script8B
		.WORD _script8C
		.WORD _script8D
		.WORD _script8E
		.WORD _script8F
		.WORD _script90
		.WORD _script91
		.WORD _script92
		.WORD _script93
		.WORD _script94
		.WORD _script95
		.WORD _script96
		.WORD _script97
		.WORD _script98
		.WORD _script99
		.WORD _script9A
		.WORD _script9B
		.WORD _script9C
		.WORD _script9D
		.WORD _script9E
		.WORD _script9F
		.WORD _scriptA0
		.WORD _scriptA1
		.WORD _scriptA2
		.WORD _scriptA3
		.WORD _scriptA4
		.WORD _scriptA5
		.WORD _scriptA6
		.WORD _scriptA7
		.WORD _scriptA8
		.WORD _scriptA9
		.WORD _scriptAA
		.WORD _scriptAB
		.WORD _scriptAC
		.WORD _scriptAD
		.WORD _scriptAE
		.WORD _scriptAF
		.WORD _scriptB0
		.WORD _scriptB1
_script80:
		set_room_idx	  $81
		ptr_load	  _script80_msg00
		msg_printf	  $2063	; [RAMBO_ IS A	REGISTERED\TRADEMARK OF CAROLCO\PICTURES INC._ 1985,1988\CAROLCO.ALL RIGHTS RESERVED.]
		ptr_load	  _script80_msg01
		msg_printf	  $2163	; [UNAUTHORIZED DUPLICATION\IS STRICTLY PROHIBITED.]
		ptr_load	  _script80_msg02
		msg_printf	  $21e3	; [NINTENDO VERSION _ 1988\PACK-IN-VIDEO CO.,LTD.]
		ptr_load	  _script80_msg03
		msg_printf	  $2263	; [LICENCED AND CONTROLLED FOR\THE UNITED STATES AND CANADA\BY ACCLAIM ENTERTAINMENT,INC.]
		ptr_load	  _script80_msg04
		msg_printf	  $2323	; [LICENSED BY	NINTENDO OF\AMERICA,INC.]
		sprite_draw_up	  _SPR_PACK_IN_TIME
		stop
_script81:
		ptr_load	  _script81_msg00
		msg_printf	  $22ac	; [START\CONTINUE]
		sprite_draw_up	  _SPR_TITLE_SCREEN
		jmpne_option	  $01, _script81_loc00
		checkpoint_reset
		set_room_idx	  $85
		checkpoint_set
		scroller
		stop
		------------------
_script81_loc00:
		set_room_idx	  $82
		stop
_script82:
		frame_draw_custom $2065, $17, $06
		ptr_load	  _script82_msg00
		msg_printf	  $2068	; [Input Mission Code]
_script82_loc00:
		frame_draw_custom $2125, $17, $12
		ptr_load	  _script82_msg01
		msg_printf	  $2167	; [0 1	2 3 4 5	6 7 8 9\A B C D E F G H I J\K L M N O P Q R S T\U V W X Y Z\a b c d e f g h i j\k l m n o p q r s t\u v w x y z ? !\BS  SP  END]
		pass_input
		jmpne_option	  $01, _script82_loc01
		checkpoint_set
		checkpoint_restore
		stop
		------------------
_script82_loc01:
		frame_draw_custom $2269, $0d, $06
		ptr_load	  _script82_msg02
		msg_printf	  $226b	; [Code Error]
		set_room_idx	  $82
		ptr_load	  _script82_msg03
		msg_printf	  $22ac	; [START\CONTINUE]
		continue_cur_draw
		jmpne_option	  $01, _script82_loc02
		checkpoint_reset
		set_room_idx	  $85
		checkpoint_set
		stop
		------------------
_script82_loc02:
		jump		  _script82_loc00
_script83:
		ptr_load	  _script83_msg00
		msg_printf	  $2465	; [LIFE	(MAX	  )\EXP         (NEXT     )\TIME]
		game_stats_draw
		frame_draw_custom $2525, $17, $0a
		ptr_load	  _script83_msg01
		msg_printf	  $252b	; [INVENTORY]
		jmp_flags_not_set _FLAG09_CO_TAKEN, _script83_loc00
		ptr_load	  _script83_msg02
		msg_printf	  $2567	; [CO]
		------------------
_script83_loc00:
		jmp_flags_not_set _FLAG0E_BOAT,	_script83_loc01
		ptr_load	  _script83_msg03
		msg_printf	  $25a7	; [BOAT]
		------------------
_script83_loc01:
		jmp_flags_not_set _FLAG03_LAMP_ITEM, _script83_loc02
		ptr_load	  _script83_msg04
		msg_printf	  $25e7	; [LAMP]
		------------------
_script83_loc02:
		jmp_flags_not_set _FLAG04_KID_TAKEN, _script83_loc03
		ptr_load	  _script83_msg05
		msg_printf	  $2627	; [KID]
		------------------
_script83_loc03:
		jmp_flags_not_set _FLAG05_PHOTO_ITEM, _script83_loc04
		ptr_load	  _script83_msg06
		msg_printf	  $256c	; [PHOTO]
		------------------
_script83_loc04:
		jmp_flags_not_set _FLAG06_POW_TAKEN, _script83_loc05
		ptr_load	  _script83_msg07
		msg_printf	  $25ac	; [POW]
		------------------
_script83_loc05:
		jmp_flags_not_set _FLAG07_DRESS_ITEM, _script83_loc06
		ptr_load	  _script83_msg08
		msg_printf	  $25ec	; [DRESS]
		------------------
_script83_loc06:
		jmp_flags_not_set _FLAG10_HELI_KEY, _script83_loc07
		ptr_load	  _script83_msg09
		msg_printf	  $262c	; [KEY]
		------------------
_script83_loc07:
		jmp_flags_not_set _FLAG11_PEDANT, _script83_loc08
		ptr_load	  _script83_msg0a
		msg_printf	  $2573	; [PENDANT]
		------------------
_script83_loc08:
		jmp_flags_not_set _FLAG12_BANDANA, _script83_loc09
		ptr_load	  _script83_msg0b
		msg_printf	  $25b3	; [BANDANA]
		------------------
_script83_loc09:
		frame_draw_custom $2685, $17, $06
		ptr_load	  _script83_msg0c
		msg_printf	  $268a	; [MISSION CODE]
		stop
_script84:
		ptr_load	  _script84_msg00
		msg_printf	  $210b	; [GAME OVER]
		sprite_draw_down  _PORTRAIT01_RAMBO_ANGRY
		ptr_load	  _script84_msg01
		msg_printf	  $22ac	; [CONTINUE\START]
		continue_cur_draw
		jmpne_option	  $02, _script84_loc00
		checkpoint_reset
		set_room_idx	  $85
		checkpoint_set
		stop
		------------------
_script84_loc00:
		checkpoint_restore
		stop
_script85:
		player_pos_set	  $00, $d0
		game_hours_set	  $0c
		ptr_load	  _script85_msg00
		msg_printf	  $20e7	; [Colonel Trautman\visits Rambo in the\military prison.]
		msg_input_handler
		frame_draw_up	  _PORTRAIT08_TRAUMAN1
		ptr_load	  _script85_msg01
		msg_draw_up	  ; [Rambo,I want to\send you on\a Mission.]
		ptr_load	  _script85_msg02
		msg_draw_up	  ; [It's dangerous,but\you'll be free\if you succeed.]
		ptr_load	  _script85_msg03
		msg_draw_up	  ; [Our men are still\missing]
		ptr_load	  _script85_msg04
		msg_draw_up	  ; [in a jungle\in Vietnam.We\believe they are\alive,prisoners of\the enemy.]
		ptr_load	  _script85_msg05
		msg_draw_up	  ; [Your mission is to\sneak into the\enemy camp and find\them.\Are you up to it?]
_script85_loc00:
		frame_draw_down	  _PORTRAIT00_RAMBO
		input_2_options
		ptr_load	  _script85_msg06
		msg_draw_down	  ; [I'm not afraid of\death.\ \I feel better in\prison.]
		jmpne_option	  $01, _script85_loc01
		ptr_load	  _script85_msg07
		msg_draw_up	  ; [Good,I'll make the\arrangements.]
		set_room_idx	  $01
		stop
		------------------
_script85_loc01:
		ptr_load	  _script85_msg08
		msg_draw_up	  ; [But it's up to you.\The game doesn't\start until you\say YES.]
		jump		  _script85_loc00
_script86:
		game_flags_set	  _FLAG00_SYS
		frame_draw_up	  _PORTRAIT09_MURDOCK
		ptr_load	  _script86_msg00
		msg_draw_up	  ; [I'm\Commander Murdock.]
		ptr_load	  _script86_msg01
		msg_draw_up	  ; [We want you to get\into enemy\territory and take\photographs of the\POW camp.]
		ptr_load	  _script86_msg02
		msg_draw_up	  ; [You're not to\engage the enemy.]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script86_msg03
		msg_draw_down	  ; [Photos? Not rescue\them?]
		ptr_load	  _script86_msg04
		msg_draw_up	  ; [I	repeat.You're not\to engage the\enemy.]
		ptr_load	  _script86_msg05
		msg_draw_up	  ; [Go to the	weapons\center and\get ready.]
		set_room_idx	  $00
		stop
_script87:
		frame_draw_up	  _PORTRAIT0D_ERICSON
		jmp_flags_not_set _FLAG00_SYS, _script87_loc00
		jmp_branch	  _script87_loc01
_script87_loc00:
		ptr_load	  _script87_msg00
		msg_draw_up	  ; [We can't give you\weapons without\Murdock's\permission.]
		set_room_idx	  $00
		stop
		------------------
_script87_loc01:
		jmp_flags_not_set _FLAG08_SYS, _script87_loc02
		jmp_branch	  _script87_loc03
_script87_loc02:
		ptr_load	  _script87_msg01
		msg_draw_up	  ; [I	picked some\weapons for\your mission.]
		game_flags_set	  _FLAG08_SYS
		add_10_knifes
		add_10_knifes
		add_5_potions
		------------------
_script87_loc03:
		game_hours_set	  $17
		ptr_load	  _script87_msg02
		msg_draw_up	  ; [Go to Trautman.]
		set_room_idx	  $00
		stop
_script88:
		frame_draw_up	  _PORTRAIT08_TRAUMAN1
		jmp_flags_not_set _FLAG08_SYS, _script88_loc00
		jump		  _script88_loc01
		------------------
_script88_loc00:
		ptr_load	  _script88_msg00
		msg_draw_up	  ; [Rambo,forget about\your absurd hand-to\-hand fighting.\Military technology\will work best.]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script88_msg01
		msg_draw_up	  ; [Go to the	hangar.]
		set_room_idx	  $01
		stop
_script88_loc01:
		ptr_load	  _script88_msg02
		msg_draw_up	  ; [There's a contact\man Co,over\there.He'll guide\you in the jungle.]
		checkpoint_set
		ptr_load	  _script88_msg03
		msg_draw_up	  ; [You've got 36 hours\to get in,complete\your assignment,\and get the hell\out.]
		ptr_load	  _script88_msg04
		msg_draw_up	  ; [If you get in\trouble,try to\reach the\extraction site\marked on the map.]
		ptr_load	  _script88_msg05
		msg_draw_up	  ; [Rambo...\Good luck.]
		game_hours_set	  $03
		game_flags_toggle _FLAG00_SYS
		game_flags_toggle _FLAG08_SYS
		game_flags_toggle _FLAG13_SYS
		anim_scene_set	  $00
		set_room_idx	  $7c
		player_pos_set	  $01, $50
		stop
_script89:
		checkpoint_set
		game_flags_set	  _FLAG09_CO_TAKEN
		frame_draw_up	  _PORTRAIT03_CO
		ptr_load	  _script89_msg00
		msg_draw_up	  ; [I'm Co.\You did not expect\a woman?]
		ptr_load	  _script89_msg01
		msg_draw_up	  ; [Would you	like to\know something?]
		frame_draw_down	  _PORTRAIT00_RAMBO
		input_2_options
		ptr_load	  _script89_msg02
		msg_draw_down	  ; [Where is the camp?\ \ \What do you think\about me?]
		jmpne_option	  $02, _script89_loc00
		sprite_draw_down  _PORTRAIT02_RAMBO_HAPPY
		sprite_draw_up	  _PORTRAIT04_CO_HAPPY
		ptr_load	  _script89_msg03
		msg_draw_up	  ; [What?\You look good.]
		------------------
_script89_loc00:
		ptr_load	  _script89_msg04
		msg_draw_up	  ; [The camp is located\in the jungle to\the East of the\river.]
		ptr_load	  _script89_msg05
		msg_draw_up	  ; [I've arranged\a boat.Let's go to\the dock.]
		set_room_idx	  $0a
		stop
_script8A:
		checkpoint_set
		jmp_flags_not_set _FLAG09_CO_TAKEN, _script8A_loc00
		jump		  _script8A_loc02
		jmp_branch	  _script8A_loc01
_script8A_loc00:
		frame_draw_up	  _PORTRAIT14_PIRATE
		ptr_load	  _script8A_msg00
		msg_draw_up	  ; [You're outsiders,\aren't you.]
		------------------
_script8A_loc01:
		ptr_load	  _script8A_msg01
		msg_draw_up	  ; [Sorry,we can't\allow strangers\to get on our boat.]
		set_room_idx	  $06
		stop
_script8A_loc02:
		jmp_flags_not_set _FLAG0E_BOAT,	_script8A_loc03
		frame_draw_up	  _PORTRAIT14_PIRATE
		jump		  _script8A_loc04
		------------------
_script8A_loc03:
		frame_draw_down	  _PORTRAIT03_CO
		ptr_load	  _script8A_msg02
		msg_draw_down	  ; [What? You	should\know us.We wanna\get on the boat.\Here's money.]
		frame_draw_up	  _PORTRAIT14_PIRATE
		ptr_load	  _script8A_msg03
		msg_draw_up	  ; [OK]
_script8A_loc04:
		ptr_load	  _script8A_msg04
		msg_draw_up	  ; [Get on,hurry.]
		game_flags_set	  _FLAG0E_BOAT
		set_room_idx	  $06
		stop
_script8B:
		checkpoint_set
		frame_draw_up	  _PORTRAIT03_CO
		jmp_flags_not_set _FLAG01_SYS, _script8B_loc00
		ptr_load	  _script8B_msg00
		msg_draw_up	  ; [Rambo,something's\strange.]
		jmp_branch	  _script8B_loc01
_script8B_loc00:
		jump		  _script8B_loc02
		------------------
_script8B_loc01:
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script8B_msg01
		msg_draw_down	  ; [Look! That's an\enemy boat.\You sold us!]
		sprite_draw_up	  _PORTRAIT14_PIRATE
		ptr_load	  _script8B_msg02
		msg_draw_up	  ; [Right,We do\everything for\money.Don't move.]
		game_flags_toggle _FLAG0E_BOAT
		set_room_idx	  $60
		stop
_script8B_loc02:
		jmp_flags_not_set _FLAG11_PEDANT, _script8B_loc03
		jump		  _script8B_loc04
		------------------
_script8B_loc03:
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script8B_msg03
		msg_draw_down	  ; [What does	this\pendant mean?]
		sprite_draw_up	  _PORTRAIT04_CO_HAPPY
		ptr_load	  _script8B_msg04
		msg_draw_up	  ; [It brings	me good\luck.]
		ptr_load	  _script8B_msg05
		msg_draw_up	  ; [Rambo,keep this\pendant.\Please take care\of it.]
		life_restore
		game_flags_set	  _FLAG11_PEDANT
_script8B_loc04:
		ptr_load	  _script8B_msg06
		msg_draw_up	  ; [Now,here we are.\We'll have to walk\from here\to the camp.]
		set_room_idx	  $0d
		stop
_script8C:
		checkpoint_set
		game_flags_set	  _FLAG09_CO_TAKEN
		set_room_idx	  $0e
		frame_draw_up	  _PORTRAIT03_CO
		jmp_flags_not_set _FLAG02_KID_SAVED, _script8C_loc00
		jmp_branch	  _script8C_loc01
_script8C_loc00:
		ptr_load	  _script8C_msg00
		msg_draw_up	  ; [Let's go\search the village.\You'll find it\in the East.]
		stop
		------------------
_script8C_loc01:
		jmp_flags_not_set _FLAG01_SYS, _script8C_loc02
		jmp_branch	  _script8C_loc03
_script8C_loc02:
		ptr_load	  _script8C_msg01
		msg_draw_up	  ; [The camp is located\South from here.]
		stop
		------------------
_script8C_loc03:
		ptr_load	  _script8C_msg02
		msg_draw_up	  ; [Cross the	river\to the West,and\climb the hill,\then you'll find\the pick-up point.]
		jmp_flags_not_set _FLAG0A_MISSION_TIME_OVER, _script8C_loc04
		jmp_branch	  _script8C_loc05
_script8C_loc04:
		stop
		------------------
_script8C_loc05:
		ptr_load	  _script8C_msg03
		msg_draw_up	  ; [But,we're late\for the contact\time.]
		ptr_load	  _script8C_msg04
		msg_draw_up	  ; [The helicopter\won't come any\more.\We'd better hide\in the village.]
		stop
_script8D:
		checkpoint_set
		frame_draw_up	  _PORTRAIT15_KID
		ptr_load	  _script8D_msg00
		msg_draw_up	  ; [AHHH...!\AHH...!]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script8D_msg01
		msg_draw_down	  ; [I'll help you.]
		game_flags_set	  _FLAG04_KID_TAKEN
		set_room_idx	  $3c
		stop
_script8E:
		jmp_flags_not_set _FLAG0C_SYS, _script8E_loc00
		set_room_idx	  $0c
		stop
		------------------
_script8E_loc00:
		set_room_idx	  $3f
		stop
_script8F:
		checkpoint_set
		frame_draw_up	  _PORTRAIT03_CO
		ptr_load	  _script8F_msg00
		msg_draw_up	  ; [I'm so happy to\see you're safe.]
		jmp_flags_not_set _FLAG06_POW_TAKEN, _script8F_loc00
		ptr_load	  _script8F_msg01
		msg_draw_up	  ; [What?\Did you take the\POW out?]
		jmp_branch	  _script8F_loc01
_script8F_loc00:
		jump		  _script8F_loc02
		------------------
_script8F_loc01:
		ptr_load	  _script8F_msg02
		msg_draw_up	  ; [You were supposed\to take photos\only!]
_script8F_loc02:
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script8F_msg03
		msg_draw_down	  ; [Let's get out of\here,now!]
		set_room_idx	  $6c
		stop
_script90:
		checkpoint_set
		game_flags_set	  _FLAG01_SYS
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script90_msg00
		msg_draw_down	  ; [I'll go ahead by\myself.]
		frame_draw_up	  _PORTRAIT03_CO
		ptr_load	  _script90_msg01
		msg_draw_up	  ; [I	see...]
		set_room_idx	  $25
		stop
_script91:
		frame_draw_down	  _PORTRAIT03_CO
		ptr_load	  _script91_msg00
		msg_draw_down	  ; [Did you call me?]
		frame_draw_up	  _PORTRAIT11_SOLDIER2
		jmp_flags_not_set _FLAG07_DRESS_ITEM, _script91_loc00
		jmp_branch	  _script91_loc01
_script91_loc00:
		ptr_load	  _script91_msg01
		msg_draw_up	  ; [This is no place\for villagers.]
		set_room_idx	  $6f
		stop
		------------------
_script91_loc01:
		ptr_load	  _script91_msg02
		msg_draw_up	  ; [Aha.\This way to the\captain's quarters.]
		set_room_idx	  $6e
		stop
_script92:
		frame_draw_down	  _PORTRAIT03_CO
		jmp_flags_not_set _FLAG00_SYS, _script92_loc00
		jump		  _script92_loc02
		------------------
_script92_loc00:
		ptr_load	  _script92_msg00
		msg_draw_down	  ; [Good evening.]
		frame_draw_up	  _PORTRAIT11_SOLDIER2
		ptr_load	  _script92_msg01
		msg_draw_up	  ; [You must be the\general's wife.]
		input_2_options
		ptr_load	  _script92_msg02
		msg_draw_down	  ; [No.I'm looking\for some.\ \Yes.]
		jmpne_option	  $01, _script92_loc01
		ptr_load	  _script92_msg03
		msg_draw_up	  ; [Get out of here.]
		set_room_idx	  $6e
		stop
		------------------
_script92_loc01:
		ptr_load	  _script92_msg04
		msg_draw_down	  ; [What happened\today?]
		ptr_load	  _script92_msg05
		msg_draw_up	  ; [I	caught a spy.]
		ptr_load	  _script92_msg06
		msg_draw_down	  ; [So,you have the key\to the room.]
		sprite_draw_up	  _PORTRAIT_CLEAR
		ptr_load	  _script92_msg07
		msg_draw_up	  ; [Anything for the\general's wife.]
_script92_loc02:
		ptr_load	  _script92_msg08
		msg_draw_down	  ; [I	got the	key.]
		game_flags_set	  _FLAG00_SYS
		set_room_idx	  $6e
		stop
_script93:
		frame_draw_up	  _PORTRAIT10_SOLDIER1
		ptr_load	  _script93_msg00
		msg_draw_up	  ; [What are you doing\here?]
		frame_draw_down	  _PORTRAIT03_CO
		ptr_load	  _script93_msg01
		msg_draw_down	  ; [Sorry.]
		ptr_load	  _script93_msg02
		msg_draw_up	  ; [Hey!Where	are you\going?\The exit is on the\right.]
		ptr_load	  _script93_msg03
		msg_draw_up	  ; [To the left is the\torture room.]
		set_room_idx	  $6e
		stop
_script94:
		checkpoint_set
		frame_draw_up	  _PORTRAIT03_CO
		jmp_flags_not_set _FLAG00_SYS, _script94_loc00
		ptr_load	  _script94_msg00
		msg_draw_up	  ; [I'm opening\the door now.]
		jmp_branch	  _script94_loc01
_script94_loc00:
		jump		  _script94_loc02
		------------------
_script94_loc01:
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script94_msg01
		msg_draw_down	  ; [Thanks.]
		ptr_load	  _script94_msg02
		msg_draw_up	  ; [They've seen us.\Let's get out\of here now.]
		game_flags_toggle _FLAG0C_SYS
		set_room_idx	  $70
		stop
_script94_loc02:
		ptr_load	  _script94_msg03
		msg_draw_up	  ; [Rambo,it's me.\Wait a minute.\I'm going to look\for the key.]
		frame_draw_down	  _PORTRAIT_CLEAR
		ptr_load	  _script94_msg04
		msg_draw_down	  ; [...]
		set_room_idx	  $6d
		stop
_script95:
		checkpoint_set
		frame_draw_up	  _PORTRAIT03_CO
		ptr_load	  _script95_msg00
		msg_draw_up	  ; [Rambo,the	pick-up\point is ahead.]
		jmp_flags_not_set _FLAG0A_MISSION_TIME_OVER, _script95_loc00
		jmp_branch	  _script95_loc01
_script95_loc00:
		jump		  _script95_loc02
		------------------
_script95_loc01:
		ptr_load	  _script95_msg01
		msg_draw_up	  ; [But the contact\time has already\passed.]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script95_msg02
		msg_draw_down	  ; [Let's return to\the jungle.]
		set_room_idx	  $18
		player_pos_set	  $00, $c0
		stop
_script95_loc02:
		jmp_flags_not_set _FLAG06_POW_TAKEN, _script95_loc03
		jump		  _script95_loc05
		------------------
_script95_loc03:
		jmp_flags_not_set _FLAG05_PHOTO_ITEM, _script95_loc04
		jump		  _script95_loc05
		------------------
_script95_loc04:
		ptr_load	  _script95_msg03
		msg_draw_up	  ; [Are you going back\without doing\anything?]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script95_msg04
		msg_draw_down	  ; [We still have\time to get to\the camp.]
		ptr_load	  _script95_msg05
		msg_draw_up	  ; [The camp is located\far South from\here.]
		set_room_idx	  $18
		player_pos_set	  $00, $c0
		stop
_script95_loc05:
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script95_msg06
		msg_draw_down	  ; [Co,thanks	for\helping me.]
		ptr_load	  _script95_msg07
		msg_draw_up	  ; [Rambo,I want to go\to America with\you.]
		jmp_flags_not_set _FLAG06_POW_TAKEN, _script95_loc06
		ptr_load	  _script95_msg08
		msg_draw_down	  ; [I'm sorry.I can't\take you.]
		jump		  _script95_loc07
		------------------
_script95_loc06:
		input_2_options
		ptr_load	  _script95_msg09
		msg_draw_down	  ; [I'm sorry.I can't\take you.\ \Then come back with\me.]
		jmpne_option	  $02, _script95_loc07
		sprite_draw_up	  _PORTRAIT04_CO_HAPPY
		ptr_load	  _script95_msg0a
		msg_draw_up	  ; [Thanks.\I'm so glad.\Let's go,they're\coming.Hurry up.]
		game_flags_set	  _FLAG09_CO_TAKEN
		set_room_idx	  $0b
		player_pos_set	  $00, $a0
		stop
		------------------
_script95_loc07:
		sprite_draw_up	  _PORTRAIT05_CO_SAD
		ptr_load	  _script95_msg0b
		msg_draw_up	  ; [I	won't see you\any more.\Good-bye.]
		game_flags_toggle _FLAG09_CO_TAKEN
		set_room_idx	  $0b
		player_pos_set	  $00, $a0
		stop
_script96:
		frame_draw_up	  _PORTRAIT0D_ERICSON
		jmp_flags_not_set _FLAG06_POW_TAKEN, _script96_loc00
		ptr_load	  _script96_msg00
		msg_draw_up	  ; [Headquarters,\we found Rambo.\He's taking POW's\with him.]
		jmp_branch	  _script96_loc01
_script96_loc00:
		jump		  _script96_loc02
		------------------
_script96_loc01:
		frame_draw_down	  _PORTRAIT_CLEAR
		ptr_load	  _script96_msg01
		msg_draw_down	  ; [..Emergency\Stop the mission..]
		sprite_draw_down  _PORTRAIT08_TRAUMAN1
		ptr_load	  _script96_msg02
		msg_draw_down	  ; [What?\I can't leave them\stranded.]
		ptr_load	  _script96_msg03
		msg_draw_up	  ; [I	have to	follow\orders.]
		sprite_draw_down  _PORTRAIT0C_TRAUMAN2
		ptr_load	  _script96_msg04
		msg_draw_down	  ; [Mercenaries!]
		set_room_idx	  $0b
		anim_scene_set	  $a9
		stop
_script96_loc02:
		ptr_load	  _script96_msg05
		msg_draw_up	  ; [Headquarters,we've\found Rambo.We're\going in to rescue\him.]
		ptr_load	  _script96_msg06
		msg_draw_up	  ; [He's being chased\by the enemy.]
		frame_draw_down	  _PORTRAIT_CLEAR
		ptr_load	  _script96_msg07
		msg_draw_down	  ; [.. Rescue	him ..]
		sprite_draw_up	  _PORTRAIT08_TRAUMAN1
		ptr_load	  _script96_msg08
		msg_draw_up	  ; [Rambo,get	on,hurry\up.So long,jungle.]
		set_room_idx	  $0b
		anim_scene_set	  $7d
		stop
_script97:
		ptr_load	  _script97_msg00
		msg_printf	  $20e7	; [At that time Rambo,\who was caught by\the enemy,was being\interrogated.]
		msg_input_handler
		frame_draw_up	  _PORTRAIT0E_PADOVSKY
		ptr_load	  _script97_msg01
		msg_draw_up	  ; [I'm\Commander Padovsky.]
		ptr_load	  _script97_msg02
		msg_draw_up	  ; [You were sent here\in an effort to\free war criminals.]
		ptr_load	  _script97_msg03
		msg_draw_up	  ; [I	want all the\details of your\Mission.]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script97_msg04
		msg_draw_down	  ; [...]
		ptr_load	  _script97_msg05
		msg_draw_up	  ; [I	want you to radio\your headquarters\and say that you\have been captured.]
		ptr_load	  _script97_msg06
		msg_draw_down	  ; [...]
		sprite_draw_down  _PORTRAIT00_RAMBO
		ptr_load	  _script97_msg07
		msg_draw_up	  ; [You will not talk?\O.K.\Yashin!]
		ptr_load	  _script97_msg08
		msg_draw_up	  ; [You're only an\experimental\animal for sergeant\Yashin.]
		sprite_draw_up	  _PORTRAIT0E_PADOVSKY
		sprite_draw_down  _PORTRAIT00_RAMBO
		ptr_load	  _script97_msg09
		msg_draw_up	  ; [Your Command has\abandoned you.\Do you still\protect them?]
		ptr_load	  _script97_msg0a
		msg_draw_up	  ; [You must make\contact,otherwise\your friend will be\killed.]
_script97_loc00:
		ptr_load	  _script97_msg0b
		msg_draw_up	  ; [Make a radio call.]
		input_2_options
		ptr_load	  _script97_msg0c
		msg_draw_down	  ; [...\ \ \220...56..please]
		jmpne_option	  $01, _script97_loc01
		jump		  _script97_loc00
		------------------
_script97_loc01:
		sprite_draw_up	  _PORTRAIT_CLEAR
		ptr_load	  _script97_msg0d
		msg_draw_up	  ; [..Report your\position and\status..]
		sprite_draw_up	  _PORTRAIT0E_PADOVSKY
		ptr_load	  _script97_msg0e
		msg_draw_up	  ; [Answer it,if you\don't wanna see\your friend die.]
		sprite_draw_up	  _PORTRAIT_CLEAR
		ptr_load	  _script97_msg0f
		msg_draw_up	  ; [John,it's me.\Answer.]
		ptr_load	  _script97_msg10
		msg_draw_down	  ; [Where is Murdock?]
		ptr_load	  _script97_msg11
		msg_draw_up	  ; [He is here.\Give us the\position.We'll\come to pick\you up.]
		sprite_draw_down  _PORTRAIT01_RAMBO_ANGRY
		ptr_load	  _script97_msg12
		msg_draw_down	  ; [I'm coming to\terminate you.]
		set_room_idx	  $9f
		stop
_script98:
		checkpoint_set
		frame_draw_up	  _PORTRAIT12_VILLAGER1
		jmp_flags_not_set _FLAG0C_SYS, _script98_loc00
		jmp_branch	  _script98_loc01
_script98_loc00:
		ptr_load	  _script98_msg00
		msg_draw_up	  ; [Hello!]
		set_room_idx	  $0c
		stop
		------------------
_script98_loc01:
		jmp_flags_not_set _FLAG07_DRESS_ITEM, _script98_loc02
		jump		  _script98_loc03
		------------------
_script98_loc02:
		ptr_load	  _script98_msg01
		msg_draw_up	  ; [Oh,what's on your\mind,just let me\know.Would you like\to buy this dress?]
		frame_draw_down	  _PORTRAIT03_CO
		input_2_options
		ptr_load	  _script98_msg02
		msg_draw_down	  ; [I	can't go without\this rifle.\ \Oh,this is a\beautiful dress.]
		jmpne_option	  $01, _script98_loc03
		ptr_load	  _script98_msg03
		msg_draw_up	  ; [Hmm,I'm sorry.]
		set_room_idx	  $0c
		stop
		------------------
_script98_loc03:
		ptr_load	  _script98_msg04
		msg_draw_up	  ; [You look good in\the dress.]
		game_flags_set	  _FLAG07_DRESS_ITEM
		set_room_idx	  $0c
		stop
_script99:
		checkpoint_set
		frame_draw_up	  _PORTRAIT13_VILLAGER2
		jmp_flags_not_set _FLAG02_KID_SAVED, _script99_loc00
		jump		  _script99_loc02
		------------------
_script99_loc00:
		jmp_flags_not_set _FLAG04_KID_TAKEN, _script99_loc01
		jump		  _script99_loc02
		------------------
_script99_loc01:
		ptr_load	  _script99_msg00
		msg_draw_up	  ; [A	kid is missing\in a cave to the\north.\Please find him.]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script99_msg01
		msg_draw_down	  ; [...]
		sprite_draw_up	  _PORTRAIT03_CO
		ptr_load	  _script99_msg02
		msg_draw_up	  ; [Rambo,please save\the kid.]
		game_flags_set	  _FLAG00_SYS
		set_room_idx	  $3a
		stop
_script99_loc02:
		ptr_load	  _script99_msg03
		msg_draw_up	  ; [Thank you	for\saving the kid.\Please rest.]
		life_restore
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script99_msg04
		msg_draw_down	  ; [I	can't stay here\for a long time.\I must go.]
		game_flags_toggle _FLAG04_KID_TAKEN
		game_flags_set	  _FLAG02_KID_SAVED
		set_room_idx	  $3a
		stop
_script9A:
		checkpoint_set
		frame_draw_up	  _PORTRAIT12_VILLAGER1
		jmp_flags_not_set _FLAG0A_MISSION_TIME_OVER, _script9A_loc00
		ptr_load	  _script9A_msg00
		msg_draw_up	  ; [Why did you come\here?]
		game_flags_set	  _FLAG13_SYS
		set_room_idx	  $0c
		stop
		------------------
_script9A_loc00:
		jmp_flags_not_set _FLAG03_LAMP_ITEM, _script9A_loc01
		jump		  _script9A_loc03
		------------------
_script9A_loc01:
		ptr_load	  _script9A_msg00
		msg_draw_up	  ; [Why did you come\here?]
		jmp_flags_not_set _FLAG00_SYS, _script9A_loc02
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script9A_msg02
		msg_draw_down	  ; [I	want to	save the\kid in the cave.]
		jmp_branch	  _script9A_loc03
_script9A_loc02:
		set_room_idx	  $3a
		stop
		------------------
_script9A_loc03:
		game_flags_set	  _FLAG03_LAMP_ITEM
		ptr_load	  _script9A_msg03
		msg_draw_up	  ; [Take this	lamp.]
		set_room_idx	  $3a
		stop
_script9B:
		checkpoint_set
		frame_draw_up	  _PORTRAIT13_VILLAGER2
		jmp_flags_not_set _FLAG0C_SYS, _script9B_loc00
		ptr_load	  _script9B_msg00
		msg_draw_up	  ; [An American spy was\caught.]
		jmp_branch	  _script9B_loc01
_script9B_loc00:
		jump		  _script9B_loc04
		------------------
_script9B_loc01:
		frame_draw_down	  _PORTRAIT03_CO
		ptr_load	  _script9B_msg01
		msg_draw_down	  ; [I	wanna take him\out.]
		jmp_flags_not_set _FLAG0D_SYS, _script9B_loc02
		jmp_branch	  _script9B_loc03
_script9B_loc02:
		add_5_potions
		------------------
_script9B_loc03:
		game_flags_set	  _FLAG0D_SYS
		ptr_load	  _script9B_msg02
		msg_draw_up	  ; [Take this	medicine\and give it to him.]
		set_room_idx	  $0c
		stop
_script9B_loc04:
		ptr_load	  _script9B_msg03
		msg_draw_up	  ; [You look tired.\Rest here for a\while.]
		frame_draw_down	  _PORTRAIT00_RAMBO
		life_restore
		ptr_load	  _script9B_msg04
		msg_draw_down	  ; [Thanks.\I'm able to fight\again.]
		set_room_idx	  $0c
		stop
_script9C:
		checkpoint_set
		frame_draw_up	  _PORTRAIT03_CO
		ptr_load	  _script9C_msg00
		msg_draw_up	  ; [We're safe for now.\What are you going\to do?\Going to Thailand?]
		ptr_load	  _script9C_msg01
		msg_draw_up	  ; [Then America?\Would you please\take me with you?]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script9C_msg02
		msg_draw_down	  ; [You're in danger\here.Let's go back\together.]
		sprite_draw_up	  _PORTRAIT04_CO_HAPPY
		ptr_load	  _script9C_msg03
		msg_draw_up	  ; [Thank you...\I'm so happy...\Let's go.They're\coming up behind\us.]
		sprite_draw_up	  _PORTRAIT_CLEAR
		ptr_load	  _script9C_msg04
		msg_draw_up	  ; [Ugh!]
		sprite_draw_up	  _PORTRAIT05_CO_SAD
		ptr_load	  _script9C_msg05
		msg_draw_down	  ; [Co.Are you all\right?]
		ptr_load	  _script9C_msg06
		msg_draw_up	  ; [Rambo,I can't go\with you.]
		ptr_load	  _script9C_msg07
		msg_draw_down	  ; [You're going with\me to the States.]
		game_flags_set	  _FLAG12_BANDANA
		sprite_draw_up	  _PORTRAIT06_CO_DEAD
		ptr_load	  _script9C_msg08
		msg_draw_up	  ; [Rambo,thank you.\Please don't forget\me.]
		ptr_load	  _script9C_msg09
		msg_draw_down	  ; [Co!]
		game_flags_toggle _FLAG09_CO_TAKEN
		set_room_idx	  $48
		stop
_script9D:
		checkpoint_set
		ptr_load	  _script9D_msg00
		msg_printf	  $20e7	; [Rambo found	the key\to the helicopter.]
		jmp_flags_not_set _FLAG10_HELI_KEY, _script9D_loc00
		msg_input_handler
		set_room_idx	  $55
		stop
		------------------
_script9D_loc00:
		ptr_load	  _script9D_msg01
		msg_printf	  $2127	; [Sergeant Yashin   \came up there.]
		msg_input_handler
		frame_draw_up	  _PORTRAIT0F_YUSIN
		ptr_load	  _script9D_msg02
		msg_draw_up	  ; [It's time for\you to die.]
		game_flags_set	  _FLAG10_HELI_KEY
		set_room_idx	  $55
		stop
_script9E:
		checkpoint_set
		jmp_flags_not_set _FLAG10_HELI_KEY, _script9E_loc00
		jmp_branch	  _script9E_loc01
_script9E_loc00:
		ptr_load	  _script9E_msg00
		msg_printf	  $20e7	; [You	can't fly\without the key to\the helicopter.]
		msg_input_handler
		set_room_idx	  $54
		stop
		------------------
_script9E_loc01:
		game_flags_set	  _FLAG08_SYS
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _script9E_msg01
		msg_draw_down	  ; [Let's go to the\camp and rescue\them.]
		jmp_flags_not_set _FLAG09_CO_TAKEN, _script9E_loc02
		frame_draw_up	  _PORTRAIT03_CO
		ptr_load	  _script9E_msg02
		msg_draw_up	  ; [Rambo,jump on\quickly.]
		------------------
_script9E_loc02:
		game_flags_toggle _FLAG06_POW_TAKEN
		player_pos_set	  $03, $80
		set_room_idx	  $54
		anim_scene_set	  $7f
		stop
_script9F:
		ptr_load	  _script9F_msg00
		msg_printf	  $20e7	; [Meanwhile,Co,\to save Rambo...]
		msg_input_handler
		game_flags_toggle _FLAG06_POW_TAKEN
		game_flags_toggle _FLAG00_SYS
		game_flags_set	  _FLAG0C_SYS
		game_flags_set	  _FLAG09_CO_TAKEN
		game_flags_set	  _FLAG13_SYS
		set_room_idx	  $0c
		player_pos_set	  $00, $d0
		stop
_scriptA0:
		checkpoint_set
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _scriptA0_msg00
		msg_draw_down	  ; [Are you alright?\I came here to get\you home.]
		frame_draw_up	  _PORTRAIT07_BANKS_POW
		ptr_load	  _scriptA0_msg01
		msg_draw_up	  ; [I'm weak.\I think I'm dying.]
		ptr_load	  _scriptA0_msg02
		msg_draw_down	  ; [Be strong!\We can make it!\Hurry,let's get out\of here.]
		game_flags_set	  _FLAG06_POW_TAKEN
		set_room_idx	  $77
		stop
_scriptA1:
		checkpoint_set
		frame_draw_up	  _PORTRAIT07_BANKS_POW
		ptr_load	  _scriptA1_msg00
		msg_draw_up	  ; [Please rescue me.]
		frame_draw_down	  _PORTRAIT00_RAMBO
		input_2_options
		ptr_load	  _scriptA1_msg01
		msg_draw_down	  ; [All right.\ \ \Sorry,my duty is\just to take photos.]
		jmpne_option	  $02, _scriptA1_loc00
		ptr_load	  _scriptA1_msg02
		msg_draw_up	  ; [Didn't you come\here to save us.\Please take us out.]
		game_flags_set	  _FLAG05_PHOTO_ITEM
		set_room_idx	  $30
		stop
		------------------
_scriptA1_loc00:
		ptr_load	  _scriptA1_msg03
		msg_draw_up	  ; [I'm free.\There are some\more.]
		game_flags_set	  _FLAG06_POW_TAKEN
		------------------
		ptr_load	  _scriptA1_msg04
		msg_draw_down	  ; [I'll be back.\Let's get out of\here.\ \                    ]
		set_room_idx	  $30
		stop
_scriptA2:
		checkpoint_set
		game_flags_toggle _FLAG00_SYS
		frame_draw_down	  _PORTRAIT00_RAMBO
		jmp_flags_not_set _FLAG06_POW_TAKEN, _scriptA2_loc00
		ptr_load	  _scriptA2_msg00
		msg_draw_down	  ; [Get on the chopper!\Quick!]
		jmp_branch	  _scriptA2_loc01
_scriptA2_loc00:
		jump		  _scriptA2_loc02
		------------------
_scriptA2_loc01:
		frame_draw_up	  _PORTRAIT07_BANKS_POW
		ptr_load	  _scriptA2_msg01
		msg_draw_up	  ; [Good-bye 'Nam.]
		anim_scene_set	  $7e
		set_room_idx	  $77
		stop
_scriptA2_loc02:
		ptr_load	  _scriptA2_msg02
		msg_draw_down	  ; [There must be some\more.\Let's take them\out.]
		jmp_flags_not_set _FLAG09_CO_TAKEN, _scriptA2_loc03
		frame_draw_up	  _PORTRAIT03_CO
		ptr_load	  _scriptA2_msg03
		msg_draw_up	  ; [I'll help you.]
		jmp_branch	  _scriptA2_loc04
_scriptA2_loc03:
		set_room_idx	  $77
		stop
		------------------
_scriptA2_loc04:
		ptr_load	  _scriptA2_msg04
		msg_draw_down	  ; [You'd better stay\here in the\chopper.]
		set_room_idx	  $77
		stop
_scriptA3:
		frame_draw_up	  _PORTRAIT09_MURDOCK
		jmp_flags_not_set _FLAG06_POW_TAKEN, _scriptA3_loc00
		ptr_load	  _scriptA3_msg00
		msg_draw_up	  ; [I	don't make\orders.I take them\just like you.]
		jmp_branch	  _scriptA3_loc01
_scriptA3_loc00:
		jump		  _scriptA3_loc02
		------------------
_scriptA3_loc01:
		sprite_draw_up	  _PORTRAIT0B_MURDOCK_SAD
		ptr_load	  _scriptA3_msg01
		msg_draw_up	  ; [I	swear to God,\this wasn't\supposed to happen.]
		ptr_load	  _scriptA3_msg02
		msg_draw_up	  ; [It was just\supposed to be\another\assignment.]
		frame_draw_down	  _PORTRAIT01_RAMBO_ANGRY
		ptr_load	  _scriptA3_msg03
		msg_draw_down	  ; [Mission\accomplished.]
		sprite_draw_down  _PORTRAIT00_RAMBO
		ptr_load	  _scriptA3_msg04
		msg_draw_down	  ; [There are	more men\out there.\Find them,or I'll\find you.]
		game_flags_set	  _FLAG00_SYS
		set_room_idx	  $62
		stop
_scriptA3_loc02:
		jmp_flags_not_set _FLAG05_PHOTO_ITEM, _scriptA3_loc03
		ptr_load	  _scriptA3_msg05
		msg_draw_up	  ; [Good job,Rambo.\I'm keeping our\deal,you can go\wherever you want.]
		jmp_branch	  _scriptA3_loc04
_scriptA3_loc03:
		jump		  _scriptA3_loc05
		------------------
_scriptA3_loc04:
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _scriptA3_msg06
		msg_draw_down	  ; [Aren't you going to\rescue the POW's?]
		ptr_load	  _scriptA3_msg07
		msg_draw_up	  ; [No,those photos\were useless as\evidence.]
		set_room_idx	  $62
		stop
_scriptA3_loc05:
		sprite_draw_up	  _PORTRAIT0A_MURDOCK_ANGRY
		ptr_load	  _scriptA3_msg08
		msg_draw_up	  ; [The mission was\a failure.I knew\you couldn't do it.]
		set_room_idx	  $62
		stop
_scriptA4:
		frame_draw_up	  _PORTRAIT08_TRAUMAN1
		jmp_flags_not_set _FLAG06_POW_TAKEN, _scriptA4_loc00
		jmp_branch	  _scriptA4_loc01
_scriptA4_loc00:
		jump		  _scriptA4_loc04
		------------------
_scriptA4_loc01:
		jmp_flags_not_set _FLAG00_SYS, _scriptA4_loc02
		jump		  _scriptA4_loc03
		------------------
_scriptA4_loc02:
		ptr_load	  _scriptA4_msg00
		msg_draw_up	  ; [Good job,Rambo.]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _scriptA4_msg01
		msg_draw_down	  ; [...]
		set_room_idx	  $61
		stop
_scriptA4_loc03:
		ptr_load	  _scriptA4_msg02
		msg_draw_up	  ; [You're tougher\then I thought.Now,\you're free.]
		ptr_load	  _scriptA4_msg03
		msg_draw_up	  ; [John,where are you\going?]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _scriptA4_msg04
		msg_draw_down	  ; [I	don't know.]
		ptr_load	  _scriptA4_msg05
		msg_draw_up	  ; [This is a	second\Medal of Honor for\you.]
		ptr_load	  _scriptA4_msg06
		msg_draw_down	  ; [You should give it\to them.]
		ptr_load	  _scriptA4_msg07
		msg_draw_up	  ; [You're free now.\Come back with us.]
		ptr_load	  _scriptA4_msg08
		msg_draw_down	  ; [What's there for\me?\My friends died\here,and a piece of\me did to.]
		ptr_load	  _scriptA4_msg09
		msg_draw_up	  ; [The war,everything\that happened maybe\it's wrong.]
		ptr_load	  _scriptA4_msg0a
		msg_draw_up	  ; [Don't hate\your country for\what you've been\through.]
		ptr_load	  _scriptA4_msg0b
		msg_draw_down	  ; [Hate?\I'd die for it.]
		ptr_load	  _scriptA4_msg0c
		msg_draw_up	  ; [So,what do you\want.]
		ptr_load	  _scriptA4_msg0d
		msg_draw_down	  ; [I	want what they\want...\every other guy\who came over here,]
		ptr_load	  _scriptA4_msg0e
		msg_draw_down	  ; [I	want for\my country to love\me as much as\I love it.]
		ptr_load	  _scriptA4_msg0f
		msg_draw_down	  ; [That's what I want.]
		ptr_load	  _scriptA4_msg10
		msg_draw_up	  ; [What are you going\to do?]
		ptr_load	  _scriptA4_msg11
		msg_draw_down	  ; [Day by day.]
		set_room_idx	  $b1
		sprite_draw_up	  _PORTRAIT_CLEAR
		sprite_draw_down  _PORTRAIT02_RAMBO_HAPPY
		stop
_scriptA4_loc04:
		ptr_load	  _scriptA4_msg12
		msg_draw_up	  ; [Welcome back.\But the game is not\over.John,are you\satisfied?]
		frame_draw_down	  _PORTRAIT00_RAMBO
		input_2_options
		ptr_load	  _scriptA4_msg13
		msg_draw_down	  ; [Let me try again.\ \ \I don't want to do\that again.]
		jmpne_option	  $02, _scriptA4_loc05
		set_room_idx	  $61
		stop
		------------------
_scriptA4_loc05:
		ptr_load	  _scriptA4_msg14
		msg_draw_up	  ; [The real purpose of\the game is to save\the POW.]
		jmp_flags_not_set _FLAG08_SYS, _scriptA4_loc06
		set_room_idx	  $9e
		player_pos_set	  $03, $d0
		stop
		------------------
_scriptA4_loc06:
		game_flags_toggle _FLAG13_SYS
		game_flags_set	  _FLAG09_CO_TAKEN
		set_room_idx	  $30
		player_pos_set	  $01, $80
		stop
_scriptA5:
		frame_draw_up	  _PORTRAIT03_CO
		ptr_load	  _scriptA5_msg00
		msg_draw_up	  ; [What are you doing?\Going to\the States?]
		ptr_load	  _scriptA5_msg01
		msg_draw_up	  ; [Warm people.\Warm city.\Warm days.]
		ptr_load	  _scriptA5_msg02
		msg_draw_up	  ; [I've been dreaming\of living in the\USA and having a\simple life.If you\don't mind...]
		frame_draw_down	  _PORTRAIT00_RAMBO
		ptr_load	  _scriptA5_msg03
		msg_draw_down	  ; [I	think I	learned\something important\from you.I may be\able to live,\or love...]
		sprite_draw_up	  _PORTRAIT04_CO_HAPPY
		sprite_draw_down  _PORTRAIT02_RAMBO_HAPPY
		ptr_load	  _scriptA5_msg04
		msg_draw_up	  ; [Really?\I love you.]
		life_restore
		set_room_idx	  $61
		stop
_scriptA6:
		set_room_idx	  $62
		player_pos_set	  $00, $d0
		stop
_scriptA7:
		set_room_idx	  $77
		player_pos_set	  $03, $d0
		stop
_scriptA8:
		jmp_flags_not_set _FLAG0E_BOAT,	_scriptA8_loc00
		set_room_idx	  $0d
		stop
		------------------
_scriptA8_loc00:
		set_room_idx	  $13
		stop
_scriptA9:
		set_room_idx	  $97
		stop
_scriptAA:
		jmp_flags_not_set _FLAG09_CO_TAKEN, _scriptAA_loc00
		jmp_branch	  _scriptAA_loc01
_scriptAA_loc00:
		set_room_idx	  $06
		stop
		------------------
_scriptAA_loc01:
		jmp_flags_not_set _FLAG0E_BOAT,	_scriptAA_loc02
		ptr_load	  _scriptAA_msg00
		msg_printf	  $20e7	; [Rambo and Co on\the boat...]
		msg_input_handler
		set_room_idx	  $0d
		player_pos_set	  $02, $b1
		stop
		------------------
_scriptAA_loc02:
		set_room_idx	  $10
		stop
_scriptAB:
		jmp_flags_not_set _FLAG01_SYS, _scriptAB_loc00
		set_room_idx	  $10
		stop
		------------------
_scriptAB_loc00:
		jmp_flags_not_set _FLAG0E_BOAT,	_scriptAB_loc01
		set_room_idx	  $10
		stop
		------------------
_scriptAB_loc01:
		set_room_idx	  $06
		stop
_scriptAC:
		frame_draw_up	  _PORTRAIT0D_ERICSON
		jmp_flags_not_set _FLAG08_SYS, _scriptAC_loc00
		jmp_branch	  _scriptAC_loc01
_scriptAC_loc00:
		ptr_load	  _scriptAC_msg00
		msg_draw_up	  ; [I'm Ericson.\I'm glad to work\with you.]
		set_room_idx	  $01
		stop
		------------------
_scriptAC_loc01:
		ptr_load	  _scriptAC_msg01
		msg_draw_up	  ; [We've no time.\Go to\Trautman soon.]
		set_room_idx	  $01
		stop
_scriptAD:
		frame_draw_up	  _PORTRAIT07_BANKS_POW
		ptr_load	  _scriptAD_msg00
		msg_draw_up	  ; [Thank you	Rambo.\We knew that\you would save\them.]
		set_room_idx	  $62
		stop
_scriptAE:
		jmp_flags_not_set _FLAG0C_SYS, _scriptAE_loc00
		ptr_load	  _scriptAE_msg00
		msg_printf	  $20e7	; [Co went to the camp\to help Rambo.]
		msg_input_handler
		set_room_idx	  $6f
		stop
		------------------
_scriptAE_loc00:
		set_room_idx	  $34
		stop
_scriptAF:
		game_flags_set	  _FLAG14_FLY_FORTRESS_DEAD
		set_room_idx	  $77
		player_pos_set	  $03, $d0
		stop
_scriptB0:
		jmp_flags_not_set _FLAG14_FLY_FORTRESS_DEAD, _scriptB0_loc00
		set_room_idx	  $77
		player_pos_set	  $03, $d0
		stop
		------------------
_scriptB0_loc00:
		jmp_flags_not_set _FLAG06_POW_TAKEN, _scriptB0_loc01
		set_room_idx	  $ff
		stop
		------------------
_scriptB0_loc01:
		set_room_idx	  $77
		player_pos_set	  $03, $d0
		stop
_scriptB1:
		frame_draw_up	  _PORTRAIT00_RAMBO
		ptr_load	  _scriptB1_msg00
		msg_printf	  $20aa	; [Rambo\ \ The battle is\ over,but...]
		ending_anim
		ptr_load	  _scriptB1_msg01
		msg_printf	  $230d	; [Thank you\for trying.]
		ending_anim
		sprite_draw_down  _PORTRAIT02_RAMBO_HAPPY
		set_room_idx	  $80
		scroller
		stop
_script80_msg00:
		.BYTE $6B,$5A,$66,$5B,$68,$E3,$F1,$62,$6C,$F1,$5A,$F1,$6B,$5E,$60,$62,$6C,$6D,$5E,$6B,$5E,$5D,$FF
		.BYTE $6D,$6B,$5A,$5D,$5E,$66,$5A,$6B,$64,$F1,$68,$5F,$F1,$5C,$5A,$6B,$68,$65,$5C,$68,$FF
		.BYTE $69,$62,$5C,$6D,$6E,$6B,$5E,$6C,$F1,$62,$67,$5C,$E4,$E2,$F1,$51,$59,$58,$55,$E5,$51,$59,$58,$58,$FF
		.BYTE $5C,$5A,$6B,$68,$65,$5C,$68,$E4,$5A,$65,$65,$F1,$6B,$62,$60,$61,$6D,$6C,$F1,$6B,$5E,$6C,$5E,$6B,$6F,$5E,$5D,$E4,$FF,$FF
_script80_msg01:
		.BYTE $6E,$67,$5A,$6E,$6D,$61,$68,$6B,$62,$73,$5E,$5D,$F1,$5D,$6E,$69,$65,$62,$5C,$5A,$6D,$62,$68,$67,$FF
		.BYTE $62,$6C,$F1,$6C,$6D,$6B,$62,$5C,$6D,$65,$72,$F1,$69,$6B,$68,$61,$62,$5B,$62,$6D,$5E,$5D,$E4,$FF,$FF
_script80_msg02:
		.BYTE $67,$62,$67,$6D,$5E,$67,$5D,$68,$F1,$6F,$5E,$6B,$6C,$62,$68,$67,$F1,$E2,$F1,$51,$59,$58,$58,$FF
		.BYTE $69,$5A,$5C,$64,$E7,$62,$67,$E7,$6F,$62,$5D,$5E,$68,$F1,$5C,$68,$E4,$E5,$65,$6D,$5D,$E4,$FF,$FF
_script80_msg03:
		.BYTE $65,$62,$5C,$5E,$67,$5C,$5E,$5D,$F1,$5A,$67,$5D,$F1,$5C,$68,$67,$6D,$6B,$68,$65,$65,$5E,$5D,$F1,$5F,$68,$6B,$FF
		.BYTE $6D,$61,$5E,$F1,$6E,$67,$62,$6D,$5E,$5D,$F1,$6C,$6D,$5A,$6D,$5E,$6C,$F1,$5A,$67,$5D,$F1,$5C,$5A,$67,$5A,$5D,$5A,$FF
		.BYTE $5B,$72,$F1,$5A,$5C,$5C,$65,$5A,$62,$66,$F1,$5E,$67,$6D,$5E,$6B,$6D,$5A,$62,$67,$66,$5E,$67,$6D,$E5,$62,$67,$5C,$E4,$FF,$FF
_script80_msg04:
		.BYTE $65,$62,$5C,$5E,$67,$6C,$5E,$5D,$F1,$5B,$72,$F1,$67,$62,$67,$6D,$5E,$67,$5D,$68,$F1,$68,$5F,$FF
		.BYTE $5A,$66,$5E,$6B,$62,$5C,$5A,$E5,$62,$67,$5C,$E4,$FF,$FF
_script81_msg00:
		.BYTE $6C,$6D,$5A,$6B,$6D,$FF
		.BYTE $5C,$68,$67,$6D,$62,$67,$6E,$5E,$FF,$FF
_script82_msg00:
		.BYTE $62,$81,$83,$88,$87,$F1,$66,$7C,$86,$86,$7C,$82,$81,$F1,$5C,$82,$77,$78,$FF,$FF
_script82_msg01:
		.BYTE $50,$F1,$51,$F1,$52,$F1,$53,$F1,$54,$F1,$55,$F1,$56,$F1,$57,$F1,$58,$F1,$59,$FF
		.BYTE $5A,$F1,$5B,$F1,$5C,$F1,$5D,$F1,$5E,$F1,$5F,$F1,$60,$F1,$61,$F1,$62,$F1,$63,$FF
		.BYTE $64,$F1,$65,$F1,$66,$F1,$67,$F1,$68,$F1,$69,$F1,$6A,$F1,$6B,$F1,$6C,$F1,$6D,$FF
		.BYTE $6E,$F1,$6F,$F1,$70,$F1,$71,$F1,$72,$F1,$73,$FF
		.BYTE $74,$F1,$75,$F1,$76,$F1,$77,$F1,$78,$F1,$79,$F1,$7A,$F1,$7B,$F1,$7C,$F1,$7D,$FF
		.BYTE $7E,$F1,$7F,$F1,$80,$F1,$81,$F1,$82,$F1,$83,$F1,$84,$F1,$85,$F1,$86,$F1,$87,$FF
		.BYTE $88,$F1,$89,$F1,$8A,$F1,$8B,$F1,$8C,$F1,$8D,$F1,$8E,$F1,$8F,$FF
		.BYTE $5B,$6C,$F1,$F1,$6C,$69,$F1,$F1,$5E,$67,$5D,$FF,$FF
_script82_msg02:
		.BYTE $5C,$82,$77,$78,$F1,$5E,$85,$85,$82,$85,$FF,$FF
_script82_msg03:
		.BYTE $6C,$6D,$5A,$6B,$6D,$FF
		.BYTE $5C,$68,$67,$6D,$62,$67,$6E,$5E,$FF,$FF
_script83_msg00:
		.BYTE $65,$62,$5F,$5E,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$EF,$66,$5A,$71,$F1,$F1,$F1,$F1,$F1,$F1,$F0,$FF
		.BYTE $5E,$71,$69,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$EF,$67,$5E,$71,$6D,$F1,$F1,$F1,$F1,$F1,$F0,$FF
		.BYTE $6D,$62,$66,$5E,$FF,$FF
_script83_msg01:
		.BYTE $62,$67,$6F,$5E,$67,$6D,$68,$6B,$72,$FF,$FF
_script83_msg02:
		.BYTE $5C,$68,$FF,$FF
_script83_msg03:
		.BYTE $5B,$68,$5A,$6D,$FF,$FF
_script83_msg04:
		.BYTE $65,$5A,$66,$69,$FF,$FF
_script83_msg05:
		.BYTE $64,$62,$5D,$FF,$FF
_script83_msg06:
		.BYTE $69,$61,$68,$6D,$68,$FF,$FF
_script83_msg07:
		.BYTE $69,$68,$70,$FF,$FF
_script83_msg08:
		.BYTE $5D,$6B,$5E,$6C,$6C,$FF,$FF
_script83_msg09:
		.BYTE $64,$5E,$72,$FF,$FF
_script83_msg0a:
		.BYTE $69,$5E,$67,$5D,$5A,$67,$6D,$FF,$FF
_script83_msg0b:
		.BYTE $5B,$5A,$67,$5D,$5A,$67,$5A,$FF,$FF
_script83_msg0c:
		.BYTE $66,$62,$6C,$6C,$62,$68,$67,$F1,$5C,$68,$5D,$5E,$FF,$FF
_script84_msg00:
		.BYTE $60,$5A,$66,$5E,$F1,$68,$6F,$5E,$6B,$FF,$FF
_script84_msg01:
		.BYTE $5C,$68,$67,$6D,$62,$67,$6E,$5E,$FF
		.BYTE $6C,$6D,$5A,$6B,$6D,$FF,$FF
_script85_msg00:
		.BYTE $5C,$82,$7F,$82,$81,$78,$7F,$F1,$6D,$85,$74,$88,$87,$80,$74,$81,$FF
		.BYTE $89,$7C,$86,$7C,$87,$86,$F1,$6B,$74,$80,$75,$82,$F1,$7C,$81,$F1,$87,$7B,$78,$FF
		.BYTE $80,$7C,$7F,$7C,$87,$74,$85,$8C,$F1,$83,$85,$7C,$86,$82,$81,$E4,$FF,$FF
_script85_msg01:
		.BYTE $6B,$74,$80,$75,$82,$E5,$62,$F1,$8A,$74,$81,$87,$F1,$87,$82,$FF
		.BYTE $86,$78,$81,$77,$F1,$8C,$82,$88,$F1,$82,$81,$FF
		.BYTE $74,$F1,$66,$7C,$86,$86,$7C,$82,$81,$E4,$FF,$FF
_script85_msg02:
		.BYTE $62,$87,$90,$86,$F1,$77,$74,$81,$7A,$78,$85,$82,$88,$86,$E5,$75,$88,$87,$FF
		.BYTE $8C,$82,$88,$90,$7F,$7F,$F1,$75,$78,$F1,$79,$85,$78,$78,$FF
		.BYTE $7C,$79,$F1,$8C,$82,$88,$F1,$86,$88,$76,$76,$78,$78,$77,$E4,$FF,$FF
_script85_msg03:
		.BYTE $68,$88,$85,$F1,$80,$78,$81,$F1,$74,$85,$78,$F1,$86,$87,$7C,$7F,$7F,$FF
		.BYTE $80,$7C,$86,$86,$7C,$81,$7A,$FF,$FF
_script85_msg04:
		.BYTE $7C,$81,$F1,$74,$F1,$7D,$88,$81,$7A,$7F,$78,$FF
		.BYTE $7C,$81,$F1,$6F,$7C,$78,$87,$81,$74,$80,$E4,$70,$78,$FF
		.BYTE $75,$78,$7F,$7C,$78,$89,$78,$F1,$87,$7B,$78,$8C,$F1,$74,$85,$78,$FF
		.BYTE $74,$7F,$7C,$89,$78,$E5,$83,$85,$7C,$86,$82,$81,$78,$85,$86,$F1,$82,$79,$FF
		.BYTE $87,$7B,$78,$F1,$78,$81,$78,$80,$8C,$E4,$FF,$FF
_script85_msg05:
		.BYTE $72,$82,$88,$85,$F1,$80,$7C,$86,$86,$7C,$82,$81,$F1,$7C,$86,$F1,$87,$82,$FF
		.BYTE $86,$81,$78,$74,$7E,$F1,$7C,$81,$87,$82,$F1,$87,$7B,$78,$FF
		.BYTE $78,$81,$78,$80,$8C,$F1,$76,$74,$80,$83,$F1,$74,$81,$77,$F1,$79,$7C,$81,$77,$FF
		.BYTE $87,$7B,$78,$80,$E4,$FF
		.BYTE $5A,$85,$78,$F1,$8C,$82,$88,$F1,$88,$83,$F1,$87,$82,$F1,$7C,$87,$8E,$FF,$FF
_script85_msg06:
		.BYTE $62,$90,$80,$F1,$81,$82,$87,$F1,$74,$79,$85,$74,$7C,$77,$F1,$82,$79,$FF
		.BYTE $77,$78,$74,$87,$7B,$E4,$FF
		.BYTE $F1,$FF
		.BYTE $62,$F1,$79,$78,$78,$7F,$F1,$75,$78,$87,$87,$78,$85,$F1,$7C,$81,$FF
		.BYTE $83,$85,$7C,$86,$82,$81,$E4,$FF,$FF
_script85_msg07:
		.BYTE $60,$82,$82,$77,$E5,$62,$90,$7F,$7F,$F1,$80,$74,$7E,$78,$F1,$87,$7B,$78,$FF
		.BYTE $74,$85,$85,$74,$81,$7A,$78,$80,$78,$81,$87,$86,$E4,$FF,$FF
_script85_msg08:
		.BYTE $5B,$88,$87,$F1,$7C,$87,$90,$86,$F1,$88,$83,$F1,$87,$82,$F1,$8C,$82,$88,$E4,$FF
		.BYTE $6D,$7B,$78,$F1,$7A,$74,$80,$78,$F1,$77,$82,$78,$86,$81,$90,$87,$FF
		.BYTE $86,$87,$74,$85,$87,$F1,$88,$81,$87,$7C,$7F,$F1,$8C,$82,$88,$FF
		.BYTE $86,$74,$8C,$F1,$72,$5E,$6C,$E4,$FF,$FF
_script86_msg00:
		.BYTE $62,$90,$80,$FF
		.BYTE $5C,$82,$80,$80,$74,$81,$77,$78,$85,$F1,$66,$88,$85,$77,$82,$76,$7E,$E4,$FF,$FF
_script86_msg01:
		.BYTE $70,$78,$F1,$8A,$74,$81,$87,$F1,$8C,$82,$88,$F1,$87,$82,$F1,$7A,$78,$87,$FF
		.BYTE $7C,$81,$87,$82,$F1,$78,$81,$78,$80,$8C,$FF
		.BYTE $87,$78,$85,$85,$7C,$87,$82,$85,$8C,$F1,$74,$81,$77,$F1,$87,$74,$7E,$78,$FF
		.BYTE $83,$7B,$82,$87,$82,$7A,$85,$74,$83,$7B,$86,$F1,$82,$79,$F1,$87,$7B,$78,$FF
		.BYTE $69,$68,$70,$F1,$76,$74,$80,$83,$E4,$FF,$FF
_script86_msg02:
		.BYTE $72,$82,$88,$90,$85,$78,$F1,$81,$82,$87,$F1,$87,$82,$FF
		.BYTE $78,$81,$7A,$74,$7A,$78,$F1,$87,$7B,$78,$F1,$78,$81,$78,$80,$8C,$E4,$FF,$FF
_script86_msg03:
		.BYTE $69,$7B,$82,$87,$82,$86,$8E,$F1,$67,$82,$87,$F1,$85,$78,$86,$76,$88,$78,$FF
		.BYTE $87,$7B,$78,$80,$8E,$FF,$FF
_script86_msg04:
		.BYTE $62,$F1,$85,$78,$83,$78,$74,$87,$E4,$72,$82,$88,$90,$85,$78,$F1,$81,$82,$87,$FF
		.BYTE $87,$82,$F1,$78,$81,$7A,$74,$7A,$78,$F1,$87,$7B,$78,$FF
		.BYTE $78,$81,$78,$80,$8C,$E4,$FF,$FF
_script86_msg05:
		.BYTE $60,$82,$F1,$87,$82,$F1,$87,$7B,$78,$F1,$8A,$78,$74,$83,$82,$81,$86,$FF
		.BYTE $76,$78,$81,$87,$78,$85,$F1,$74,$81,$77,$FF
		.BYTE $7A,$78,$87,$F1,$85,$78,$74,$77,$8C,$E4,$FF,$FF
_script87_msg00:
		.BYTE $70,$78,$F1,$76,$74,$81,$90,$87,$F1,$7A,$7C,$89,$78,$F1,$8C,$82,$88,$FF
		.BYTE $8A,$78,$74,$83,$82,$81,$86,$F1,$8A,$7C,$87,$7B,$82,$88,$87,$FF
		.BYTE $66,$88,$85,$77,$82,$76,$7E,$90,$86,$FF
		.BYTE $83,$78,$85,$80,$7C,$86,$86,$7C,$82,$81,$E4,$FF,$FF
_script87_msg01:
		.BYTE $62,$F1,$83,$7C,$76,$7E,$78,$77,$F1,$86,$82,$80,$78,$FF
		.BYTE $8A,$78,$74,$83,$82,$81,$86,$F1,$79,$82,$85,$FF
		.BYTE $8C,$82,$88,$85,$F1,$80,$7C,$86,$86,$7C,$82,$81,$E4,$FF,$FF
_script87_msg02:
		.BYTE $60,$82,$F1,$87,$82,$F1,$6D,$85,$74,$88,$87,$80,$74,$81,$E4,$FF,$FF
_script88_msg00:
		.BYTE $6B,$74,$80,$75,$82,$E5,$79,$82,$85,$7A,$78,$87,$F1,$74,$75,$82,$88,$87,$FF
		.BYTE $8C,$82,$88,$85,$F1,$74,$75,$86,$88,$85,$77,$F1,$7B,$74,$81,$77,$E7,$87,$82,$FF
		.BYTE $E7,$7B,$74,$81,$77,$F1,$79,$7C,$7A,$7B,$87,$7C,$81,$7A,$E4,$FF
		.BYTE $66,$7C,$7F,$7C,$87,$74,$85,$8C,$F1,$87,$78,$76,$7B,$81,$82,$7F,$82,$7A,$8C,$FF
		.BYTE $8A,$7C,$7F,$7F,$F1,$8A,$82,$85,$7E,$F1,$75,$78,$86,$87,$E4,$FF,$FF
		.BYTE $FF
_script88_msg01:
		.BYTE $60,$82,$F1,$87,$82,$F1,$87,$7B,$78,$F1,$7B,$74,$81,$7A,$74,$85,$E4,$FF,$FF
_script88_msg02:
		.BYTE $6D,$7B,$78,$85,$78,$90,$86,$F1,$74,$F1,$76,$82,$81,$87,$74,$76,$87,$FF
		.BYTE $80,$74,$81,$F1,$5C,$82,$E5,$82,$89,$78,$85,$FF
		.BYTE $87,$7B,$78,$85,$78,$E4,$61,$78,$90,$7F,$7F,$F1,$7A,$88,$7C,$77,$78,$FF
		.BYTE $8C,$82,$88,$F1,$7C,$81,$F1,$87,$7B,$78,$F1,$7D,$88,$81,$7A,$7F,$78,$E4,$FF,$FF
_script88_msg03:
		.BYTE $72,$82,$88,$90,$89,$78,$F1,$7A,$82,$87,$F1,$53,$56,$F1,$7B,$82,$88,$85,$86,$FF
		.BYTE $87,$82,$F1,$7A,$78,$87,$F1,$7C,$81,$E5,$76,$82,$80,$83,$7F,$78,$87,$78,$FF
		.BYTE $8C,$82,$88,$85,$F1,$74,$86,$86,$7C,$7A,$81,$80,$78,$81,$87,$E5,$FF
		.BYTE $74,$81,$77,$F1,$7A,$78,$87,$F1,$87,$7B,$78,$F1,$7B,$78,$7F,$7F,$FF
		.BYTE $82,$88,$87,$E4,$FF,$FF
_script88_msg04:
		.BYTE $62,$79,$F1,$8C,$82,$88,$F1,$7A,$78,$87,$F1,$7C,$81,$FF
		.BYTE $87,$85,$82,$88,$75,$7F,$78,$E5,$87,$85,$8C,$F1,$87,$82,$FF
		.BYTE $85,$78,$74,$76,$7B,$F1,$87,$7B,$78,$FF
		.BYTE $78,$8B,$87,$85,$74,$76,$87,$7C,$82,$81,$F1,$86,$7C,$87,$78,$FF
		.BYTE $80,$74,$85,$7E,$78,$77,$F1,$82,$81,$F1,$87,$7B,$78,$F1,$80,$74,$83,$E4,$FF,$FF
_script88_msg05:
		.BYTE $6B,$74,$80,$75,$82,$EE,$EE,$EE,$FF
		.BYTE $60,$82,$82,$77,$F1,$7F,$88,$76,$7E,$E4,$FF,$FF
_script89_msg00:
		.BYTE $62,$90,$80,$F1,$5C,$82,$E4,$FF
		.BYTE $72,$82,$88,$F1,$77,$7C,$77,$F1,$81,$82,$87,$F1,$78,$8B,$83,$78,$76,$87,$FF
		.BYTE $74,$F1,$8A,$82,$80,$74,$81,$8E,$FF,$FF
_script89_msg01:
		.BYTE $70,$82,$88,$7F,$77,$F1,$8C,$82,$88,$F1,$7F,$7C,$7E,$78,$F1,$87,$82,$FF
		.BYTE $7E,$81,$82,$8A,$F1,$86,$82,$80,$78,$87,$7B,$7C,$81,$7A,$8E,$FF,$FF
_script89_msg02:
		.BYTE $70,$7B,$78,$85,$78,$F1,$7C,$86,$F1,$87,$7B,$78,$F1,$76,$74,$80,$83,$8E,$FF
		.BYTE $F1,$FF
		.BYTE $F1,$FF
		.BYTE $70,$7B,$74,$87,$F1,$77,$82,$F1,$8C,$82,$88,$F1,$87,$7B,$7C,$81,$7E,$FF
		.BYTE $74,$75,$82,$88,$87,$F1,$80,$78,$8E,$FF,$FF
_script89_msg03:
		.BYTE $70,$7B,$74,$87,$8E,$FF
		.BYTE $72,$82,$88,$F1,$7F,$82,$82,$7E,$F1,$7A,$82,$82,$77,$E4,$FF,$FF
_script89_msg04:
		.BYTE $6D,$7B,$78,$F1,$76,$74,$80,$83,$F1,$7C,$86,$F1,$7F,$82,$76,$74,$87,$78,$77,$FF
		.BYTE $7C,$81,$F1,$87,$7B,$78,$F1,$7D,$88,$81,$7A,$7F,$78,$F1,$87,$82,$FF
		.BYTE $87,$7B,$78,$F1,$5E,$74,$86,$87,$F1,$82,$79,$F1,$87,$7B,$78,$FF
		.BYTE $85,$7C,$89,$78,$85,$E4,$FF,$FF
_script89_msg05:
		.BYTE $62,$90,$89,$78,$F1,$74,$85,$85,$74,$81,$7A,$78,$77,$FF
		.BYTE $74,$F1,$75,$82,$74,$87,$E4,$65,$78,$87,$90,$86,$F1,$7A,$82,$F1,$87,$82,$FF
		.BYTE $87,$7B,$78,$F1,$77,$82,$76,$7E,$E4,$FF,$FF
_script8A_msg00:
		.BYTE $72,$82,$88,$90,$85,$78,$F1,$82,$88,$87,$86,$7C,$77,$78,$85,$86,$E5,$FF
		.BYTE $74,$85,$78,$81,$90,$87,$F1,$8C,$82,$88,$E4,$FF,$FF
_script8A_msg01:
		.BYTE $6C,$82,$85,$85,$8C,$E5,$8A,$78,$F1,$76,$74,$81,$90,$87,$FF
		.BYTE $74,$7F,$7F,$82,$8A,$F1,$86,$87,$85,$74,$81,$7A,$78,$85,$86,$FF
		.BYTE $87,$82,$F1,$7A,$78,$87,$F1,$82,$81,$F1,$82,$88,$85,$F1,$75,$82,$74,$87,$E4,$FF,$FF
_script8A_msg02:
		.BYTE $70,$7B,$74,$87,$8E,$F1,$72,$82,$88,$F1,$86,$7B,$82,$88,$7F,$77,$FF
		.BYTE $7E,$81,$82,$8A,$F1,$88,$86,$E4,$70,$78,$F1,$8A,$74,$81,$81,$74,$FF
		.BYTE $7A,$78,$87,$F1,$82,$81,$F1,$87,$7B,$78,$F1,$75,$82,$74,$87,$E4,$FF
		.BYTE $61,$78,$85,$78,$90,$86,$F1,$80,$82,$81,$78,$8C,$E4,$FF,$FF
_script8A_msg03:
		.BYTE $68,$64,$FF,$FF
_script8A_msg04:
		.BYTE $60,$78,$87,$F1,$82,$81,$E5,$7B,$88,$85,$85,$8C,$E4,$FF,$FF
_script8B_msg00:
		.BYTE $6B,$74,$80,$75,$82,$E5,$86,$82,$80,$78,$87,$7B,$7C,$81,$7A,$90,$86,$FF
		.BYTE $86,$87,$85,$74,$81,$7A,$78,$E4,$FF,$FF
_script8B_msg01:
		.BYTE $65,$82,$82,$7E,$8F,$F1,$6D,$7B,$74,$87,$90,$86,$F1,$74,$81,$FF
		.BYTE $78,$81,$78,$80,$8C,$F1,$75,$82,$74,$87,$E4,$FF
		.BYTE $72,$82,$88,$F1,$86,$82,$7F,$77,$F1,$88,$86,$8F,$FF,$FF
_script8B_msg02:
		.BYTE $6B,$7C,$7A,$7B,$87,$E5,$70,$78,$F1,$77,$82,$FF
		.BYTE $78,$89,$78,$85,$8C,$87,$7B,$7C,$81,$7A,$F1,$79,$82,$85,$FF
		.BYTE $80,$82,$81,$78,$8C,$E4,$5D,$82,$81,$90,$87,$F1,$80,$82,$89,$78,$E4,$FF,$FF
_script8B_msg03:
		.BYTE $70,$7B,$74,$87,$F1,$77,$82,$78,$86,$F1,$87,$7B,$7C,$86,$FF
		.BYTE $83,$78,$81,$77,$74,$81,$87,$F1,$80,$78,$74,$81,$8E,$FF,$FF
_script8B_msg04:
		.BYTE $62,$87,$F1,$75,$85,$7C,$81,$7A,$86,$F1,$80,$78,$F1,$7A,$82,$82,$77,$FF
		.BYTE $7F,$88,$76,$7E,$E4,$FF,$FF
_script8B_msg05:
		.BYTE $6B,$74,$80,$75,$82,$E5,$7E,$78,$78,$83,$F1,$87,$7B,$7C,$86,$FF
		.BYTE $83,$78,$81,$77,$74,$81,$87,$E4,$FF
		.BYTE $69,$7F,$78,$74,$86,$78,$F1,$87,$74,$7E,$78,$F1,$76,$74,$85,$78,$FF
		.BYTE $82,$79,$F1,$7C,$87,$E4,$FF,$FF
_script8B_msg06:
		.BYTE $67,$82,$8A,$E5,$7B,$78,$85,$78,$F1,$8A,$78,$F1,$74,$85,$78,$E4,$FF
		.BYTE $70,$78,$90,$7F,$7F,$F1,$7B,$74,$89,$78,$F1,$87,$82,$F1,$8A,$74,$7F,$7E,$FF
		.BYTE $79,$85,$82,$80,$F1,$7B,$78,$85,$78,$FF
		.BYTE $87,$82,$F1,$87,$7B,$78,$F1,$76,$74,$80,$83,$E4,$FF,$FF
_script8C_msg00:
		.BYTE $65,$78,$87,$90,$86,$F1,$7A,$82,$FF
		.BYTE $86,$78,$74,$85,$76,$7B,$F1,$87,$7B,$78,$F1,$89,$7C,$7F,$7F,$74,$7A,$78,$E4,$FF
		.BYTE $72,$82,$88,$90,$7F,$7F,$F1,$79,$7C,$81,$77,$F1,$7C,$87,$FF
		.BYTE $7C,$81,$F1,$87,$7B,$78,$F1,$5E,$74,$86,$87,$E4,$FF,$FF
_script8C_msg01:
		.BYTE $6D,$7B,$78,$F1,$76,$74,$80,$83,$F1,$7C,$86,$F1,$7F,$82,$76,$74,$87,$78,$77,$FF
		.BYTE $6C,$82,$88,$87,$7B,$F1,$79,$85,$82,$80,$F1,$7B,$78,$85,$78,$E4,$FF,$FF
_script8C_msg02:
		.BYTE $5C,$85,$82,$86,$86,$F1,$87,$7B,$78,$F1,$85,$7C,$89,$78,$85,$FF
		.BYTE $87,$82,$F1,$87,$7B,$78,$F1,$70,$78,$86,$87,$E5,$74,$81,$77,$FF
		.BYTE $76,$7F,$7C,$80,$75,$F1,$87,$7B,$78,$F1,$7B,$7C,$7F,$7F,$E5,$FF
		.BYTE $87,$7B,$78,$81,$F1,$8C,$82,$88,$90,$7F,$7F,$F1,$79,$7C,$81,$77,$FF
		.BYTE $87,$7B,$78,$F1,$83,$7C,$76,$7E,$E7,$88,$83,$F1,$83,$82,$7C,$81,$87,$E4,$FF,$FF
_script8C_msg03:
		.BYTE $5B,$88,$87,$E5,$8A,$78,$90,$85,$78,$F1,$7F,$74,$87,$78,$FF
		.BYTE $79,$82,$85,$F1,$87,$7B,$78,$F1,$76,$82,$81,$87,$74,$76,$87,$FF
		.BYTE $87,$7C,$80,$78,$E4,$FF,$FF
_script8C_msg04:
		.BYTE $6D,$7B,$78,$F1,$7B,$78,$7F,$7C,$76,$82,$83,$87,$78,$85,$FF
		.BYTE $8A,$82,$81,$90,$87,$F1,$76,$82,$80,$78,$F1,$74,$81,$8C,$FF
		.BYTE $80,$82,$85,$78,$E4,$FF
		.BYTE $70,$78,$90,$77,$F1,$75,$78,$87,$87,$78,$85,$F1,$7B,$7C,$77,$78,$FF
		.BYTE $7C,$81,$F1,$87,$7B,$78,$F1,$89,$7C,$7F,$7F,$74,$7A,$78,$E4,$FF,$FF
_script8D_msg00:
		.BYTE $5A,$61,$61,$61,$EE,$EE,$EE,$8F,$FF
		.BYTE $5A,$61,$61,$EE,$EE,$EE,$8F,$FF,$FF
_script8D_msg01:
		.BYTE $62,$90,$7F,$7F,$F1,$7B,$78,$7F,$83,$F1,$8C,$82,$88,$E4,$FF,$FF
		.BYTE $FF
_script8F_msg00:
		.BYTE $62,$90,$80,$F1,$86,$82,$F1,$7B,$74,$83,$83,$8C,$F1,$87,$82,$FF
		.BYTE $86,$78,$78,$F1,$8C,$82,$88,$90,$85,$78,$F1,$86,$74,$79,$78,$E4,$FF,$FF
_script8F_msg01:
		.BYTE $70,$7B,$74,$87,$8E,$FF
		.BYTE $5D,$7C,$77,$F1,$8C,$82,$88,$F1,$87,$74,$7E,$78,$F1,$87,$7B,$78,$FF
		.BYTE $69,$68,$70,$F1,$82,$88,$87,$8E,$FF,$FF
_script8F_msg02:
		.BYTE $72,$82,$88,$F1,$8A,$78,$85,$78,$F1,$86,$88,$83,$83,$82,$86,$78,$77,$FF
		.BYTE $87,$82,$F1,$87,$74,$7E,$78,$F1,$83,$7B,$82,$87,$82,$86,$FF
		.BYTE $82,$81,$7F,$8C,$8F,$FF,$FF
_script8F_msg03:
		.BYTE $65,$78,$87,$90,$86,$F1,$7A,$78,$87,$F1,$82,$88,$87,$F1,$82,$79,$FF
		.BYTE $7B,$78,$85,$78,$E5,$81,$82,$8A,$8F,$FF,$FF
_script90_msg00:
		.BYTE $62,$90,$7F,$7F,$F1,$7A,$82,$F1,$74,$7B,$78,$74,$77,$F1,$75,$8C,$FF
		.BYTE $80,$8C,$86,$78,$7F,$79,$E4,$FF,$FF
_script90_msg01:
		.BYTE $62,$F1,$86,$78,$78,$EE,$EE,$EE,$FF,$FF
_script91_msg00:
		.BYTE $5D,$7C,$77,$F1,$8C,$82,$88,$F1,$76,$74,$7F,$7F,$F1,$80,$78,$8E,$FF,$FF
_script91_msg01:
		.BYTE $6D,$7B,$7C,$86,$F1,$7C,$86,$F1,$81,$82,$F1,$83,$7F,$74,$76,$78,$FF
		.BYTE $79,$82,$85,$F1,$89,$7C,$7F,$7F,$74,$7A,$78,$85,$86,$E4,$FF,$FF
_script91_msg02:
		.BYTE $5A,$7B,$74,$E4,$FF
		.BYTE $6D,$7B,$7C,$86,$F1,$8A,$74,$8C,$F1,$87,$82,$F1,$87,$7B,$78,$FF
		.BYTE $76,$74,$83,$87,$74,$7C,$81,$90,$86,$F1,$84,$88,$74,$85,$87,$78,$85,$86,$E4,$FF,$FF
_script92_msg00:
		.BYTE $60,$82,$82,$77,$F1,$78,$89,$78,$81,$7C,$81,$7A,$E4,$FF,$FF
_script92_msg01:
		.BYTE $72,$82,$88,$F1,$80,$88,$86,$87,$F1,$75,$78,$F1,$87,$7B,$78,$FF
		.BYTE $7A,$78,$81,$78,$85,$74,$7F,$90,$86,$F1,$8A,$7C,$79,$78,$E4,$FF,$FF
_script92_msg02:
		.BYTE $67,$82,$E4,$62,$90,$80,$F1,$7F,$82,$82,$7E,$7C,$81,$7A,$FF
		.BYTE $79,$82,$85,$F1,$86,$82,$80,$78,$E4,$FF
		.BYTE $F1,$FF
		.BYTE $72,$78,$86,$E4,$FF,$FF
_script92_msg03:
		.BYTE $60,$78,$87,$F1,$82,$88,$87,$F1,$82,$79,$F1,$7B,$78,$85,$78,$E4,$FF,$FF
_script92_msg04:
		.BYTE $70,$7B,$74,$87,$F1,$7B,$74,$83,$83,$78,$81,$78,$77,$FF
		.BYTE $87,$82,$77,$74,$8C,$8E,$FF,$FF
_script92_msg05:
		.BYTE $62,$F1,$76,$74,$88,$7A,$7B,$87,$F1,$74,$F1,$86,$83,$8C,$E4,$FF,$FF
_script92_msg06:
		.BYTE $6C,$82,$E5,$8C,$82,$88,$F1,$7B,$74,$89,$78,$F1,$87,$7B,$78,$F1,$7E,$78,$8C,$FF
		.BYTE $87,$82,$F1,$87,$7B,$78,$F1,$85,$82,$82,$80,$E4,$FF,$FF
_script92_msg07:
		.BYTE $5A,$81,$8C,$87,$7B,$7C,$81,$7A,$F1,$79,$82,$85,$F1,$87,$7B,$78,$FF
		.BYTE $7A,$78,$81,$78,$85,$74,$7F,$90,$86,$F1,$8A,$7C,$79,$78,$E4,$FF,$FF
_script92_msg08:
		.BYTE $62,$F1,$7A,$82,$87,$F1,$87,$7B,$78,$F1,$7E,$78,$8C,$E4,$FF,$FF
_script93_msg00:
		.BYTE $70,$7B,$74,$87,$F1,$74,$85,$78,$F1,$8C,$82,$88,$F1,$77,$82,$7C,$81,$7A,$FF
		.BYTE $7B,$78,$85,$78,$8E,$FF,$FF
_script93_msg01:
		.BYTE $6C,$82,$85,$85,$8C,$E4,$FF,$FF
_script93_msg02:
		.BYTE $61,$78,$8C,$8F,$70,$7B,$78,$85,$78,$F1,$74,$85,$78,$F1,$8C,$82,$88,$FF
		.BYTE $7A,$82,$7C,$81,$7A,$8E,$FF
		.BYTE $6D,$7B,$78,$F1,$78,$8B,$7C,$87,$F1,$7C,$86,$F1,$82,$81,$F1,$87,$7B,$78,$FF
		.BYTE $85,$7C,$7A,$7B,$87,$E4,$FF,$FF
_script93_msg03:
		.BYTE $6D,$82,$F1,$87,$7B,$78,$F1,$7F,$78,$79,$87,$F1,$7C,$86,$F1,$87,$7B,$78,$FF
		.BYTE $87,$82,$85,$87,$88,$85,$78,$F1,$85,$82,$82,$80,$E4,$FF,$FF
_script94_msg00:
		.BYTE $62,$90,$80,$F1,$82,$83,$78,$81,$7C,$81,$7A,$FF
		.BYTE $87,$7B,$78,$F1,$77,$82,$82,$85,$F1,$81,$82,$8A,$E4,$FF,$FF
_script94_msg01:
		.BYTE $6D,$7B,$74,$81,$7E,$86,$E4,$FF,$FF
_script94_msg02:
		.BYTE $6D,$7B,$78,$8C,$90,$89,$78,$F1,$86,$78,$78,$81,$F1,$88,$86,$E4,$FF
		.BYTE $65,$78,$87,$90,$86,$F1,$7A,$78,$87,$F1,$82,$88,$87,$FF
		.BYTE $82,$79,$F1,$7B,$78,$85,$78,$F1,$81,$82,$8A,$E4,$FF,$FF
_script94_msg03:
		.BYTE $6B,$74,$80,$75,$82,$E5,$7C,$87,$90,$86,$F1,$80,$78,$E4,$FF
		.BYTE $70,$74,$7C,$87,$F1,$74,$F1,$80,$7C,$81,$88,$87,$78,$E4,$FF
		.BYTE $62,$90,$80,$F1,$7A,$82,$7C,$81,$7A,$F1,$87,$82,$F1,$7F,$82,$82,$7E,$FF
		.BYTE $79,$82,$85,$F1,$87,$7B,$78,$F1,$7E,$78,$8C,$E4,$FF,$FF
_script94_msg04:
		.BYTE $EE,$EE,$EE,$FF,$FF
_script95_msg00:
		.BYTE $6B,$74,$80,$75,$82,$E5,$87,$7B,$78,$F1,$83,$7C,$76,$7E,$E7,$88,$83,$FF
		.BYTE $83,$82,$7C,$81,$87,$F1,$7C,$86,$F1,$74,$7B,$78,$74,$77,$E4,$FF,$FF
_script95_msg01:
		.BYTE $5B,$88,$87,$F1,$87,$7B,$78,$F1,$76,$82,$81,$87,$74,$76,$87,$FF
		.BYTE $87,$7C,$80,$78,$F1,$7B,$74,$86,$F1,$74,$7F,$85,$78,$74,$77,$8C,$FF
		.BYTE $83,$74,$86,$86,$78,$77,$E4,$FF,$FF
_script95_msg02:
		.BYTE $65,$78,$87,$90,$86,$F1,$85,$78,$87,$88,$85,$81,$F1,$87,$82,$FF
		.BYTE $87,$7B,$78,$F1,$7D,$88,$81,$7A,$7F,$78,$E4,$FF,$FF
_script95_msg03:
		.BYTE $5A,$85,$78,$F1,$8C,$82,$88,$F1,$7A,$82,$7C,$81,$7A,$F1,$75,$74,$76,$7E,$FF
		.BYTE $8A,$7C,$87,$7B,$82,$88,$87,$F1,$77,$82,$7C,$81,$7A,$FF
		.BYTE $74,$81,$8C,$87,$7B,$7C,$81,$7A,$8E,$FF,$FF
_script95_msg04:
		.BYTE $70,$78,$F1,$86,$87,$7C,$7F,$7F,$F1,$7B,$74,$89,$78,$FF
		.BYTE $87,$7C,$80,$78,$F1,$87,$82,$F1,$7A,$78,$87,$F1,$87,$82,$FF
		.BYTE $87,$7B,$78,$F1,$76,$74,$80,$83,$E4,$FF,$FF
_script95_msg05:
		.BYTE $6D,$7B,$78,$F1,$76,$74,$80,$83,$F1,$7C,$86,$F1,$7F,$82,$76,$74,$87,$78,$77,$FF
		.BYTE $79,$74,$85,$F1,$6C,$82,$88,$87,$7B,$F1,$79,$85,$82,$80,$FF
		.BYTE $7B,$78,$85,$78,$E4,$FF,$FF
_script95_msg06:
		.BYTE $5C,$82,$E5,$87,$7B,$74,$81,$7E,$86,$F1,$79,$82,$85,$FF
		.BYTE $7B,$78,$7F,$83,$7C,$81,$7A,$F1,$80,$78,$E4,$FF,$FF
_script95_msg07:
		.BYTE $6B,$74,$80,$75,$82,$E5,$62,$F1,$8A,$74,$81,$87,$F1,$87,$82,$F1,$7A,$82,$FF
		.BYTE $87,$82,$F1,$5A,$80,$78,$85,$7C,$76,$74,$F1,$8A,$7C,$87,$7B,$FF
		.BYTE $8C,$82,$88,$E4,$FF,$FF
_script95_msg08:
		.BYTE $62,$90,$80,$F1,$86,$82,$85,$85,$8C,$E4,$62,$F1,$76,$74,$81,$90,$87,$FF
		.BYTE $87,$74,$7E,$78,$F1,$8C,$82,$88,$E4,$FF,$FF
_script95_msg09:
		.BYTE $62,$90,$80,$F1,$86,$82,$85,$85,$8C,$E4,$62,$F1,$76,$74,$81,$90,$87,$FF
		.BYTE $87,$74,$7E,$78,$F1,$8C,$82,$88,$E4,$FF
		.BYTE $F1,$FF
		.BYTE $6D,$7B,$78,$81,$F1,$76,$82,$80,$78,$F1,$75,$74,$76,$7E,$F1,$8A,$7C,$87,$7B,$FF
		.BYTE $80,$78,$E4,$FF,$FF
_script95_msg0a:
		.BYTE $6D,$7B,$74,$81,$7E,$86,$E4,$FF
		.BYTE $62,$90,$80,$F1,$86,$82,$F1,$7A,$7F,$74,$77,$E4,$FF
		.BYTE $65,$78,$87,$90,$86,$F1,$7A,$82,$E5,$87,$7B,$78,$8C,$90,$85,$78,$FF
		.BYTE $76,$82,$80,$7C,$81,$7A,$E4,$61,$88,$85,$85,$8C,$F1,$88,$83,$E4,$FF,$FF
_script95_msg0b:
		.BYTE $62,$F1,$8A,$82,$81,$90,$87,$F1,$86,$78,$78,$F1,$8C,$82,$88,$FF
		.BYTE $74,$81,$8C,$F1,$80,$82,$85,$78,$E4,$FF
		.BYTE $60,$82,$82,$77,$E7,$75,$8C,$78,$E4,$FF,$FF
_script96_msg00:
		.BYTE $61,$78,$74,$77,$84,$88,$74,$85,$87,$78,$85,$86,$E5,$FF
		.BYTE $8A,$78,$F1,$79,$82,$88,$81,$77,$F1,$6B,$74,$80,$75,$82,$E4,$FF
		.BYTE $61,$78,$90,$86,$F1,$87,$74,$7E,$7C,$81,$7A,$F1,$69,$68,$70,$90,$86,$FF
		.BYTE $8A,$7C,$87,$7B,$F1,$7B,$7C,$80,$E4,$FF,$FF
_script96_msg01:
		.BYTE $EE,$EE,$5E,$80,$78,$85,$7A,$78,$81,$76,$8C,$FF
		.BYTE $6C,$87,$82,$83,$F1,$87,$7B,$78,$F1,$80,$7C,$86,$86,$7C,$82,$81,$EE,$EE,$FF,$FF
_script96_msg02:
		.BYTE $70,$7B,$74,$87,$8E,$FF
		.BYTE $62,$F1,$76,$74,$81,$90,$87,$F1,$7F,$78,$74,$89,$78,$F1,$87,$7B,$78,$80,$FF
		.BYTE $86,$87,$85,$74,$81,$77,$78,$77,$E4,$FF,$FF
_script96_msg03:
		.BYTE $62,$F1,$7B,$74,$89,$78,$F1,$87,$82,$F1,$79,$82,$7F,$7F,$82,$8A,$FF
		.BYTE $82,$85,$77,$78,$85,$86,$E4,$FF,$FF
_script96_msg04:
		.BYTE $66,$78,$85,$76,$78,$81,$74,$85,$7C,$78,$86,$8F,$FF,$FF
_script96_msg05:
		.BYTE $61,$78,$74,$77,$84,$88,$74,$85,$87,$78,$85,$86,$E5,$8A,$78,$90,$89,$78,$FF
		.BYTE $79,$82,$88,$81,$77,$F1,$6B,$74,$80,$75,$82,$E4,$70,$78,$90,$85,$78,$FF
		.BYTE $7A,$82,$7C,$81,$7A,$F1,$7C,$81,$F1,$87,$82,$F1,$85,$78,$86,$76,$88,$78,$FF
		.BYTE $7B,$7C,$80,$E4,$FF,$FF
_script96_msg06:
		.BYTE $61,$78,$90,$86,$F1,$75,$78,$7C,$81,$7A,$F1,$76,$7B,$74,$86,$78,$77,$FF
		.BYTE $75,$8C,$F1,$87,$7B,$78,$F1,$78,$81,$78,$80,$8C,$E4,$FF,$FF
_script96_msg07:
		.BYTE $EE,$EE,$F1,$6B,$78,$86,$76,$88,$78,$F1,$7B,$7C,$80,$F1,$EE,$EE,$FF,$FF
_script96_msg08:
		.BYTE $6B,$74,$80,$75,$82,$E5,$7A,$78,$87,$F1,$82,$81,$E5,$7B,$88,$85,$85,$8C,$FF
		.BYTE $88,$83,$E4,$6C,$82,$F1,$7F,$82,$81,$7A,$E5,$7D,$88,$81,$7A,$7F,$78,$E4,$FF,$FF
_script97_msg00:
		.BYTE $5A,$87,$F1,$87,$7B,$74,$87,$F1,$87,$7C,$80,$78,$F1,$6B,$74,$80,$75,$82,$E5,$FF
		.BYTE $8A,$7B,$82,$F1,$8A,$74,$86,$F1,$76,$74,$88,$7A,$7B,$87,$F1,$75,$8C,$FF
		.BYTE $87,$7B,$78,$F1,$78,$81,$78,$80,$8C,$E5,$8A,$74,$86,$F1,$75,$78,$7C,$81,$7A,$FF
		.BYTE $7C,$81,$87,$78,$85,$85,$82,$7A,$74,$87,$78,$77,$E4,$FF,$FF
_script97_msg01:
		.BYTE $62,$90,$80,$FF
		.BYTE $5C,$82,$80,$80,$74,$81,$77,$78,$85,$F1,$69,$74,$77,$82,$89,$86,$7E,$8C,$E4,$FF,$FF
_script97_msg02:
		.BYTE $72,$82,$88,$F1,$8A,$78,$85,$78,$F1,$86,$78,$81,$87,$F1,$7B,$78,$85,$78,$FF
		.BYTE $7C,$81,$F1,$74,$81,$F1,$78,$79,$79,$82,$85,$87,$F1,$87,$82,$FF
		.BYTE $79,$85,$78,$78,$F1,$8A,$74,$85,$F1,$76,$85,$7C,$80,$7C,$81,$74,$7F,$86,$E4,$FF,$FF
_script97_msg03:
		.BYTE $62,$F1,$8A,$74,$81,$87,$F1,$74,$7F,$7F,$F1,$87,$7B,$78,$FF
		.BYTE $77,$78,$87,$74,$7C,$7F,$86,$F1,$82,$79,$F1,$8C,$82,$88,$85,$FF
		.BYTE $66,$7C,$86,$86,$7C,$82,$81,$E4,$FF,$FF
_script97_msg04:
		.BYTE $EE,$EE,$EE,$FF,$FF
_script97_msg05:
		.BYTE $62,$F1,$8A,$74,$81,$87,$F1,$8C,$82,$88,$F1,$87,$82,$F1,$85,$74,$77,$7C,$82,$FF
		.BYTE $8C,$82,$88,$85,$F1,$7B,$78,$74,$77,$84,$88,$74,$85,$87,$78,$85,$86,$FF
		.BYTE $74,$81,$77,$F1,$86,$74,$8C,$F1,$87,$7B,$74,$87,$F1,$8C,$82,$88,$FF
		.BYTE $7B,$74,$89,$78,$F1,$75,$78,$78,$81,$F1,$76,$74,$83,$87,$88,$85,$78,$77,$E4,$FF,$FF
_script97_msg06:
		.BYTE $EE,$EE,$EE,$FF,$FF
_script97_msg07:
		.BYTE $72,$82,$88,$F1,$8A,$7C,$7F,$7F,$F1,$81,$82,$87,$F1,$87,$74,$7F,$7E,$8E,$FF
		.BYTE $68,$E4,$64,$E4,$FF
		.BYTE $72,$74,$86,$7B,$7C,$81,$8F,$FF,$FF
_script97_msg08:
		.BYTE $72,$82,$88,$90,$85,$78,$F1,$82,$81,$7F,$8C,$F1,$74,$81,$FF
		.BYTE $78,$8B,$83,$78,$85,$7C,$80,$78,$81,$87,$74,$7F,$FF
		.BYTE $74,$81,$7C,$80,$74,$7F,$F1,$79,$82,$85,$F1,$86,$78,$85,$7A,$78,$74,$81,$87,$FF
		.BYTE $72,$74,$86,$7B,$7C,$81,$E4,$FF,$FF
_script97_msg09:
		.BYTE $72,$82,$88,$85,$F1,$5C,$82,$80,$80,$74,$81,$77,$F1,$7B,$74,$86,$FF
		.BYTE $74,$75,$74,$81,$77,$82,$81,$78,$77,$F1,$8C,$82,$88,$E4,$FF
		.BYTE $5D,$82,$F1,$8C,$82,$88,$F1,$86,$87,$7C,$7F,$7F,$FF
		.BYTE $83,$85,$82,$87,$78,$76,$87,$F1,$87,$7B,$78,$80,$8E,$FF,$FF
_script97_msg0a:
		.BYTE $72,$82,$88,$F1,$80,$88,$86,$87,$F1,$80,$74,$7E,$78,$FF
		.BYTE $76,$82,$81,$87,$74,$76,$87,$E5,$82,$87,$7B,$78,$85,$8A,$7C,$86,$78,$FF
		.BYTE $8C,$82,$88,$85,$F1,$79,$85,$7C,$78,$81,$77,$F1,$8A,$7C,$7F,$7F,$F1,$75,$78,$FF
		.BYTE $7E,$7C,$7F,$7F,$78,$77,$E4,$FF,$FF
_script97_msg0b:
		.BYTE $66,$74,$7E,$78,$F1,$74,$F1,$85,$74,$77,$7C,$82,$F1,$76,$74,$7F,$7F,$E4,$FF,$FF
_script97_msg0c:
		.BYTE $EE,$EE,$EE,$FF
		.BYTE $F1,$FF
		.BYTE $F1,$FF
		.BYTE $52,$52,$50,$EE,$EE,$EE,$55,$56,$EE,$EE,$83,$7F,$78,$74,$86,$78,$FF,$FF
_script97_msg0d:
		.BYTE $EE,$EE,$6B,$78,$83,$82,$85,$87,$F1,$8C,$82,$88,$85,$FF
		.BYTE $83,$82,$86,$7C,$87,$7C,$82,$81,$F1,$74,$81,$77,$FF
		.BYTE $86,$87,$74,$87,$88,$86,$EE,$EE,$FF,$FF
_script97_msg0e:
		.BYTE $5A,$81,$86,$8A,$78,$85,$F1,$7C,$87,$E5,$7C,$79,$F1,$8C,$82,$88,$FF
		.BYTE $77,$82,$81,$90,$87,$F1,$8A,$74,$81,$81,$74,$F1,$86,$78,$78,$FF
		.BYTE $8C,$82,$88,$85,$F1,$79,$85,$7C,$78,$81,$77,$F1,$77,$7C,$78,$E4,$FF,$FF
_script97_msg0f:
		.BYTE $63,$82,$7B,$81,$E5,$7C,$87,$90,$86,$F1,$80,$78,$E4,$FF
		.BYTE $5A,$81,$86,$8A,$78,$85,$E4,$FF,$FF
_script97_msg10:
		.BYTE $70,$7B,$78,$85,$78,$F1,$7C,$86,$F1,$66,$88,$85,$77,$82,$76,$7E,$8E,$FF,$FF
_script97_msg11:
		.BYTE $61,$78,$F1,$7C,$86,$F1,$7B,$78,$85,$78,$E4,$FF
		.BYTE $60,$7C,$89,$78,$F1,$88,$86,$F1,$87,$7B,$78,$FF
		.BYTE $83,$82,$86,$7C,$87,$7C,$82,$81,$E4,$70,$78,$90,$7F,$7F,$FF
		.BYTE $76,$82,$80,$78,$F1,$87,$82,$F1,$83,$7C,$76,$7E,$FF
		.BYTE $8C,$82,$88,$F1,$88,$83,$E4,$FF,$FF
_script97_msg12:
		.BYTE $62,$90,$80,$F1,$76,$82,$80,$7C,$81,$7A,$F1,$87,$82,$FF
		.BYTE $87,$78,$85,$80,$7C,$81,$74,$87,$78,$F1,$8C,$82,$88,$E4,$FF,$FF
_script98_msg00:
		.BYTE $61,$78,$7F,$7F,$82,$8F,$FF,$FF
_script98_msg01:
		.BYTE $68,$7B,$E5,$8A,$7B,$74,$87,$90,$86,$F1,$82,$81,$F1,$8C,$82,$88,$85,$FF
		.BYTE $80,$7C,$81,$77,$E5,$7D,$88,$86,$87,$F1,$7F,$78,$87,$F1,$80,$78,$FF
		.BYTE $7E,$81,$82,$8A,$E4,$70,$82,$88,$7F,$77,$F1,$8C,$82,$88,$F1,$7F,$7C,$7E,$78,$FF
		.BYTE $87,$82,$F1,$75,$88,$8C,$F1,$87,$7B,$7C,$86,$F1,$77,$85,$78,$86,$86,$8E,$FF,$FF
_script98_msg02:
		.BYTE $62,$F1,$76,$74,$81,$90,$87,$F1,$7A,$82,$F1,$8A,$7C,$87,$7B,$82,$88,$87,$FF
		.BYTE $87,$7B,$7C,$86,$F1,$85,$7C,$79,$7F,$78,$E4,$FF
		.BYTE $F1,$FF
		.BYTE $68,$7B,$E5,$87,$7B,$7C,$86,$F1,$7C,$86,$F1,$74,$FF
		.BYTE $75,$78,$74,$88,$87,$7C,$79,$88,$7F,$F1,$77,$85,$78,$86,$86,$E4,$FF,$FF
_script98_msg03:
		.BYTE $61,$80,$80,$E5,$62,$90,$80,$F1,$86,$82,$85,$85,$8C,$E4,$FF,$FF
_script98_msg04:
		.BYTE $72,$82,$88,$F1,$7F,$82,$82,$7E,$F1,$7A,$82,$82,$77,$F1,$7C,$81,$FF
		.BYTE $87,$7B,$78,$F1,$77,$85,$78,$86,$86,$E4,$FF,$FF
_script99_msg00:
		.BYTE $5A,$F1,$7E,$7C,$77,$F1,$7C,$86,$F1,$80,$7C,$86,$86,$7C,$81,$7A,$FF
		.BYTE $7C,$81,$F1,$74,$F1,$76,$74,$89,$78,$F1,$87,$82,$F1,$87,$7B,$78,$FF
		.BYTE $81,$82,$85,$87,$7B,$E4,$FF
		.BYTE $69,$7F,$78,$74,$86,$78,$F1,$79,$7C,$81,$77,$F1,$7B,$7C,$80,$E4,$FF,$FF
_script99_msg01:
		.BYTE $EE,$EE,$EE,$FF,$FF
_script99_msg02:
		.BYTE $6B,$74,$80,$75,$82,$E5,$83,$7F,$78,$74,$86,$78,$F1,$86,$74,$89,$78,$FF
		.BYTE $87,$7B,$78,$F1,$7E,$7C,$77,$E4,$FF,$FF
_script99_msg03:
		.BYTE $6D,$7B,$74,$81,$7E,$F1,$8C,$82,$88,$F1,$79,$82,$85,$FF
		.BYTE $86,$74,$89,$7C,$81,$7A,$F1,$87,$7B,$78,$F1,$7E,$7C,$77,$E4,$FF
		.BYTE $69,$7F,$78,$74,$86,$78,$F1,$85,$78,$86,$87,$E4,$FF,$FF
_script99_msg04:
		.BYTE $62,$F1,$76,$74,$81,$90,$87,$F1,$86,$87,$74,$8C,$F1,$7B,$78,$85,$78,$FF
		.BYTE $79,$82,$85,$F1,$74,$F1,$7F,$82,$81,$7A,$F1,$87,$7C,$80,$78,$E4,$FF
		.BYTE $62,$F1,$80,$88,$86,$87,$F1,$7A,$82,$E4,$FF,$FF
_script9A_msg00:
		.BYTE $70,$7B,$8C,$F1,$77,$7C,$77,$F1,$8C,$82,$88,$F1,$76,$82,$80,$78,$FF
		.BYTE $7B,$78,$85,$78,$8E,$FF,$FF
_script9A_msg02:
		.BYTE $62,$F1,$8A,$74,$81,$87,$F1,$87,$82,$F1,$86,$74,$89,$78,$F1,$87,$7B,$78,$FF
		.BYTE $7E,$7C,$77,$F1,$7C,$81,$F1,$87,$7B,$78,$F1,$76,$74,$89,$78,$E4,$FF,$FF
_script9A_msg03:
		.BYTE $6D,$74,$7E,$78,$F1,$87,$7B,$7C,$86,$F1,$7F,$74,$80,$83,$E4,$FF,$FF
_script9B_msg00:
		.BYTE $5A,$81,$F1,$5A,$80,$78,$85,$7C,$76,$74,$81,$F1,$86,$83,$8C,$F1,$8A,$74,$86,$FF
		.BYTE $76,$74,$88,$7A,$7B,$87,$E4,$FF,$FF
_script9B_msg01:
		.BYTE $62,$F1,$8A,$74,$81,$81,$74,$F1,$87,$74,$7E,$78,$F1,$7B,$7C,$80,$FF
		.BYTE $82,$88,$87,$E4,$FF,$FF
_script9B_msg02:
		.BYTE $6D,$74,$7E,$78,$F1,$87,$7B,$7C,$86,$F1,$80,$78,$77,$7C,$76,$7C,$81,$78,$FF
		.BYTE $74,$81,$77,$F1,$7A,$7C,$89,$78,$F1,$7C,$87,$F1,$87,$82,$F1,$7B,$7C,$80,$E4,$FF,$FF
_script9B_msg03:
		.BYTE $72,$82,$88,$F1,$7F,$82,$82,$7E,$F1,$87,$7C,$85,$78,$77,$E4,$FF
		.BYTE $6B,$78,$86,$87,$F1,$7B,$78,$85,$78,$F1,$79,$82,$85,$F1,$74,$FF
		.BYTE $8A,$7B,$7C,$7F,$78,$E4,$FF,$FF
_script9B_msg04:
		.BYTE $6D,$7B,$74,$81,$7E,$86,$E4,$FF
		.BYTE $62,$90,$80,$F1,$74,$75,$7F,$78,$F1,$87,$82,$F1,$79,$7C,$7A,$7B,$87,$FF
		.BYTE $74,$7A,$74,$7C,$81,$E4,$FF,$FF
_script9C_msg00:
		.BYTE $70,$78,$90,$85,$78,$F1,$86,$74,$79,$78,$F1,$79,$82,$85,$F1,$81,$82,$8A,$E4,$FF
		.BYTE $70,$7B,$74,$87,$F1,$74,$85,$78,$F1,$8C,$82,$88,$F1,$7A,$82,$7C,$81,$7A,$FF
		.BYTE $87,$82,$F1,$77,$82,$8E,$FF
		.BYTE $60,$82,$7C,$81,$7A,$F1,$87,$82,$F1,$6D,$7B,$74,$7C,$7F,$74,$81,$77,$8E,$FF,$FF
_script9C_msg01:
		.BYTE $6D,$7B,$78,$81,$F1,$5A,$80,$78,$85,$7C,$76,$74,$8E,$FF
		.BYTE $70,$82,$88,$7F,$77,$F1,$8C,$82,$88,$F1,$83,$7F,$78,$74,$86,$78,$FF
		.BYTE $87,$74,$7E,$78,$F1,$80,$78,$F1,$8A,$7C,$87,$7B,$F1,$8C,$82,$88,$8E,$FF,$FF
_script9C_msg02:
		.BYTE $72,$82,$88,$90,$85,$78,$F1,$7C,$81,$F1,$77,$74,$81,$7A,$78,$85,$FF
		.BYTE $7B,$78,$85,$78,$E4,$65,$78,$87,$90,$86,$F1,$7A,$82,$F1,$75,$74,$76,$7E,$FF
		.BYTE $87,$82,$7A,$78,$87,$7B,$78,$85,$E4,$FF,$FF
_script9C_msg03:
		.BYTE $6D,$7B,$74,$81,$7E,$F1,$8C,$82,$88,$EE,$EE,$EE,$FF
		.BYTE $62,$90,$80,$F1,$86,$82,$F1,$7B,$74,$83,$83,$8C,$EE,$EE,$EE,$FF
		.BYTE $65,$78,$87,$90,$86,$F1,$7A,$82,$E4,$6D,$7B,$78,$8C,$90,$85,$78,$FF
		.BYTE $76,$82,$80,$7C,$81,$7A,$F1,$88,$83,$F1,$75,$78,$7B,$7C,$81,$77,$FF
		.BYTE $88,$86,$E4,$FF,$FF
_script9C_msg04:
		.BYTE $6E,$7A,$7B,$8F,$FF,$FF
_script9C_msg05:
		.BYTE $5C,$82,$E4,$5A,$85,$78,$F1,$8C,$82,$88,$F1,$74,$7F,$7F,$FF
		.BYTE $85,$7C,$7A,$7B,$87,$8E,$FF,$FF
_script9C_msg06:
		.BYTE $6B,$74,$80,$75,$82,$E5,$62,$F1,$76,$74,$81,$90,$87,$F1,$7A,$82,$FF
		.BYTE $8A,$7C,$87,$7B,$F1,$8C,$82,$88,$E4,$FF,$FF
_script9C_msg07:
		.BYTE $72,$82,$88,$90,$85,$78,$F1,$7A,$82,$7C,$81,$7A,$F1,$8A,$7C,$87,$7B,$FF
		.BYTE $80,$78,$F1,$87,$82,$F1,$87,$7B,$78,$F1,$6C,$87,$74,$87,$78,$86,$E4,$FF,$FF
_script9C_msg08:
		.BYTE $6B,$74,$80,$75,$82,$E5,$87,$7B,$74,$81,$7E,$F1,$8C,$82,$88,$E4,$FF
		.BYTE $69,$7F,$78,$74,$86,$78,$F1,$77,$82,$81,$90,$87,$F1,$79,$82,$85,$7A,$78,$87,$FF
		.BYTE $80,$78,$E4,$FF,$FF
_script9C_msg09:
		.BYTE $5C,$82,$8F,$FF,$FF
_script9D_msg00:
		.BYTE $6B,$74,$80,$75,$82,$F1,$79,$82,$88,$81,$77,$F1,$87,$7B,$78,$F1,$7E,$78,$8C,$FF
		.BYTE $87,$82,$F1,$87,$7B,$78,$F1,$7B,$78,$7F,$7C,$76,$82,$83,$87,$78,$85,$E4,$FF,$FF
_script9D_msg01:
		.BYTE $6C,$78,$85,$7A,$78,$74,$81,$87,$F1,$72,$74,$86,$7B,$7C,$81,$F1,$F1,$F1,$FF
		.BYTE $76,$74,$80,$78,$F1,$88,$83,$F1,$87,$7B,$78,$85,$78,$E4,$FF,$FF
_script9D_msg02:
		.BYTE $62,$87,$90,$86,$F1,$87,$7C,$80,$78,$F1,$79,$82,$85,$FF
		.BYTE $8C,$82,$88,$F1,$87,$82,$F1,$77,$7C,$78,$E4,$FF,$FF
_script9E_msg00:
		.BYTE $72,$82,$88,$F1,$76,$74,$81,$90,$87,$F1,$79,$7F,$8C,$FF
		.BYTE $8A,$7C,$87,$7B,$82,$88,$87,$F1,$87,$7B,$78,$F1,$7E,$78,$8C,$F1,$87,$82,$FF
		.BYTE $87,$7B,$78,$F1,$7B,$78,$7F,$7C,$76,$82,$83,$87,$78,$85,$E4,$FF,$FF
_script9E_msg01:
		.BYTE $65,$78,$87,$90,$86,$F1,$7A,$82,$F1,$87,$82,$F1,$87,$7B,$78,$FF
		.BYTE $76,$74,$80,$83,$F1,$74,$81,$77,$F1,$85,$78,$86,$76,$88,$78,$FF
		.BYTE $87,$7B,$78,$80,$E4,$FF,$FF
_script9E_msg02:
		.BYTE $6B,$74,$80,$75,$82,$E5,$7D,$88,$80,$83,$F1,$82,$81,$FF
		.BYTE $84,$88,$7C,$76,$7E,$7F,$8C,$E4,$FF,$FF
_script9F_msg00:
		.BYTE $66,$78,$74,$81,$8A,$7B,$7C,$7F,$78,$E5,$5C,$82,$E5,$FF
		.BYTE $87,$82,$F1,$86,$74,$89,$78,$F1,$6B,$74,$80,$75,$82,$EE,$EE,$EE,$FF,$FF
_scriptA0_msg00:
		.BYTE $5A,$85,$78,$F1,$8C,$82,$88,$F1,$74,$7F,$85,$7C,$7A,$7B,$87,$8E,$FF
		.BYTE $62,$F1,$76,$74,$80,$78,$F1,$7B,$78,$85,$78,$F1,$87,$82,$F1,$7A,$78,$87,$FF
		.BYTE $8C,$82,$88,$F1,$7B,$82,$80,$78,$E4,$FF,$FF
_scriptA0_msg01:
		.BYTE $62,$90,$80,$F1,$8A,$78,$74,$7E,$E4,$FF
		.BYTE $62,$F1,$87,$7B,$7C,$81,$7E,$F1,$62,$90,$80,$F1,$77,$8C,$7C,$81,$7A,$E4,$FF,$FF
_scriptA0_msg02:
		.BYTE $5B,$78,$F1,$86,$87,$85,$82,$81,$7A,$8F,$FF
		.BYTE $70,$78,$F1,$76,$74,$81,$F1,$80,$74,$7E,$78,$F1,$7C,$87,$8F,$FF
		.BYTE $61,$88,$85,$85,$8C,$E5,$7F,$78,$87,$90,$86,$F1,$7A,$78,$87,$F1,$82,$88,$87,$FF
		.BYTE $82,$79,$F1,$7B,$78,$85,$78,$E4,$FF,$FF
_scriptA1_msg00:
		.BYTE $69,$7F,$78,$74,$86,$78,$F1,$85,$78,$86,$76,$88,$78,$F1,$80,$78,$E4,$FF,$FF
_scriptA1_msg01:
		.BYTE $5A,$7F,$7F,$F1,$85,$7C,$7A,$7B,$87,$E4,$FF
		.BYTE $F1,$FF
		.BYTE $F1,$FF
		.BYTE $6C,$82,$85,$85,$8C,$E5,$80,$8C,$F1,$77,$88,$87,$8C,$F1,$7C,$86,$FF
		.BYTE $7D,$88,$86,$87,$F1,$87,$82,$F1,$87,$74,$7E,$78,$F1,$83,$7B,$82,$87,$82,$86,$E4,$FF,$FF
_scriptA1_msg02:
		.BYTE $5D,$7C,$77,$81,$90,$87,$F1,$8C,$82,$88,$F1,$76,$82,$80,$78,$FF
		.BYTE $7B,$78,$85,$78,$F1,$87,$82,$F1,$86,$74,$89,$78,$F1,$88,$86,$E4,$FF
		.BYTE $69,$7F,$78,$74,$86,$78,$F1,$87,$74,$7E,$78,$F1,$88,$86,$F1,$82,$88,$87,$E4,$FF,$FF
_scriptA1_msg03:
		.BYTE $62,$90,$80,$F1,$79,$85,$78,$78,$E4,$FF
		.BYTE $6D,$7B,$78,$85,$78,$F1,$74,$85,$78,$F1,$86,$82,$80,$78,$FF
		.BYTE $80,$82,$85,$78,$E4,$FF,$FF
_scriptA1_msg04:
		.BYTE $62,$90,$7F,$7F,$F1,$75,$78,$F1,$75,$74,$76,$7E,$E4,$FF
		.BYTE $65,$78,$87,$90,$86,$F1,$7A,$78,$87,$F1,$82,$88,$87,$F1,$82,$79,$FF
		.BYTE $7B,$78,$85,$78,$E4,$FF
		.BYTE $F1,$FF
		.BYTE $F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$F1,$FF,$FF
_scriptA2_msg00:
		.BYTE $60,$78,$87,$F1,$82,$81,$F1,$87,$7B,$78,$F1,$76,$7B,$82,$83,$83,$78,$85,$8F,$FF
		.BYTE $6A,$88,$7C,$76,$7E,$8F,$FF,$FF
_scriptA2_msg01:
		.BYTE $60,$82,$82,$77,$E7,$75,$8C,$78,$F1,$90,$67,$74,$80,$E4,$FF,$FF
_scriptA2_msg02:
		.BYTE $6D,$7B,$78,$85,$78,$F1,$80,$88,$86,$87,$F1,$75,$78,$F1,$86,$82,$80,$78,$FF
		.BYTE $80,$82,$85,$78,$E4,$FF
		.BYTE $65,$78,$87,$90,$86,$F1,$87,$74,$7E,$78,$F1,$87,$7B,$78,$80,$FF
		.BYTE $82,$88,$87,$E4,$FF,$FF
_scriptA2_msg03:
		.BYTE $62,$90,$7F,$7F,$F1,$7B,$78,$7F,$83,$F1,$8C,$82,$88,$E4,$FF,$FF
_scriptA2_msg04:
		.BYTE $72,$82,$88,$90,$77,$F1,$75,$78,$87,$87,$78,$85,$F1,$86,$87,$74,$8C,$FF
		.BYTE $7B,$78,$85,$78,$F1,$7C,$81,$F1,$87,$7B,$78,$FF
		.BYTE $76,$7B,$82,$83,$83,$78,$85,$E4,$FF,$FF
_scriptA3_msg00:
		.BYTE $62,$F1,$77,$82,$81,$90,$87,$F1,$80,$74,$7E,$78,$FF
		.BYTE $82,$85,$77,$78,$85,$86,$E4,$62,$F1,$87,$74,$7E,$78,$F1,$87,$7B,$78,$80,$FF
		.BYTE $7D,$88,$86,$87,$F1,$7F,$7C,$7E,$78,$F1,$8C,$82,$88,$E4,$FF,$FF
_scriptA3_msg01:
		.BYTE $62,$F1,$86,$8A,$78,$74,$85,$F1,$87,$82,$F1,$60,$82,$77,$E5,$FF
		.BYTE $87,$7B,$7C,$86,$F1,$8A,$74,$86,$81,$90,$87,$FF
		.BYTE $86,$88,$83,$83,$82,$86,$78,$77,$F1,$87,$82,$F1,$7B,$74,$83,$83,$78,$81,$E4,$FF,$FF
_scriptA3_msg02:
		.BYTE $62,$87,$F1,$8A,$74,$86,$F1,$7D,$88,$86,$87,$FF
		.BYTE $86,$88,$83,$83,$82,$86,$78,$77,$F1,$87,$82,$F1,$75,$78,$FF
		.BYTE $74,$81,$82,$87,$7B,$78,$85,$FF
		.BYTE $74,$86,$86,$7C,$7A,$81,$80,$78,$81,$87,$E4,$FF,$FF
_scriptA3_msg03:
		.BYTE $66,$7C,$86,$86,$7C,$82,$81,$FF
		.BYTE $74,$76,$76,$82,$80,$83,$7F,$7C,$86,$7B,$78,$77,$E4,$FF,$FF
_scriptA3_msg04:
		.BYTE $6D,$7B,$78,$85,$78,$F1,$74,$85,$78,$F1,$80,$82,$85,$78,$F1,$80,$78,$81,$FF
		.BYTE $82,$88,$87,$F1,$87,$7B,$78,$85,$78,$E4,$FF
		.BYTE $5F,$7C,$81,$77,$F1,$87,$7B,$78,$80,$E5,$82,$85,$F1,$62,$90,$7F,$7F,$FF
		.BYTE $79,$7C,$81,$77,$F1,$8C,$82,$88,$E4,$FF,$FF
_scriptA3_msg05:
		.BYTE $60,$82,$82,$77,$F1,$7D,$82,$75,$E5,$6B,$74,$80,$75,$82,$E4,$FF
		.BYTE $62,$90,$80,$F1,$7E,$78,$78,$83,$7C,$81,$7A,$F1,$82,$88,$85,$FF
		.BYTE $77,$78,$74,$7F,$E5,$8C,$82,$88,$F1,$76,$74,$81,$F1,$7A,$82,$FF
		.BYTE $8A,$7B,$78,$85,$78,$89,$78,$85,$F1,$8C,$82,$88,$F1,$8A,$74,$81,$87,$E4,$FF,$FF
_scriptA3_msg06:
		.BYTE $5A,$85,$78,$81,$90,$87,$F1,$8C,$82,$88,$F1,$7A,$82,$7C,$81,$7A,$F1,$87,$82,$FF
		.BYTE $85,$78,$86,$76,$88,$78,$F1,$87,$7B,$78,$F1,$69,$68,$70,$90,$86,$8E,$FF,$FF
_scriptA3_msg07:
		.BYTE $67,$82,$E5,$87,$7B,$82,$86,$78,$F1,$83,$7B,$82,$87,$82,$86,$FF
		.BYTE $8A,$78,$85,$78,$F1,$88,$86,$78,$7F,$78,$86,$86,$F1,$74,$86,$FF
		.BYTE $78,$89,$7C,$77,$78,$81,$76,$78,$E4,$FF,$FF
_scriptA3_msg08:
		.BYTE $6D,$7B,$78,$F1,$80,$7C,$86,$86,$7C,$82,$81,$F1,$8A,$74,$86,$FF
		.BYTE $74,$F1,$79,$74,$7C,$7F,$88,$85,$78,$E4,$62,$F1,$7E,$81,$78,$8A,$FF
		.BYTE $8C,$82,$88,$F1,$76,$82,$88,$7F,$77,$81,$90,$87,$F1,$77,$82,$F1,$7C,$87,$E4,$FF,$FF
		.BYTE $FF
_scriptA4_msg00:
		.BYTE $60,$82,$82,$77,$F1,$7D,$82,$75,$E5,$6B,$74,$80,$75,$82,$E4,$FF,$FF
_scriptA4_msg01:
		.BYTE $EE,$EE,$EE,$FF,$FF
_scriptA4_msg02:
		.BYTE $72,$82,$88,$90,$85,$78,$F1,$87,$82,$88,$7A,$7B,$78,$85,$FF
		.BYTE $87,$7B,$78,$81,$F1,$62,$F1,$87,$7B,$82,$88,$7A,$7B,$87,$E4,$67,$82,$8A,$E5,$FF
		.BYTE $8C,$82,$88,$90,$85,$78,$F1,$79,$85,$78,$78,$E4,$FF,$FF
_scriptA4_msg03:
		.BYTE $63,$82,$7B,$81,$E5,$8A,$7B,$78,$85,$78,$F1,$74,$85,$78,$F1,$8C,$82,$88,$FF
		.BYTE $7A,$82,$7C,$81,$7A,$8E,$FF,$FF
_scriptA4_msg04:
		.BYTE $62,$F1,$77,$82,$81,$90,$87,$F1,$7E,$81,$82,$8A,$E4,$FF,$FF
_scriptA4_msg05:
		.BYTE $6D,$7B,$7C,$86,$F1,$7C,$86,$F1,$74,$F1,$86,$78,$76,$82,$81,$77,$FF
		.BYTE $66,$78,$77,$74,$7F,$F1,$82,$79,$F1,$61,$82,$81,$82,$85,$F1,$79,$82,$85,$FF
		.BYTE $8C,$82,$88,$E4,$FF,$FF
_scriptA4_msg06:
		.BYTE $72,$82,$88,$F1,$86,$7B,$82,$88,$7F,$77,$F1,$7A,$7C,$89,$78,$F1,$7C,$87,$FF
		.BYTE $87,$82,$F1,$87,$7B,$78,$80,$E4,$FF,$FF
_scriptA4_msg07:
		.BYTE $72,$82,$88,$90,$85,$78,$F1,$79,$85,$78,$78,$F1,$81,$82,$8A,$E4,$FF
		.BYTE $5C,$82,$80,$78,$F1,$75,$74,$76,$7E,$F1,$8A,$7C,$87,$7B,$F1,$88,$86,$E4,$FF,$FF
_scriptA4_msg08:
		.BYTE $70,$7B,$74,$87,$90,$86,$F1,$87,$7B,$78,$85,$78,$F1,$79,$82,$85,$FF
		.BYTE $80,$78,$8E,$FF
		.BYTE $66,$8C,$F1,$79,$85,$7C,$78,$81,$77,$86,$F1,$77,$7C,$78,$77,$FF
		.BYTE $7B,$78,$85,$78,$E5,$74,$81,$77,$F1,$74,$F1,$83,$7C,$78,$76,$78,$F1,$82,$79,$FF
		.BYTE $80,$78,$F1,$77,$7C,$77,$F1,$87,$82,$E4,$FF,$FF
_scriptA4_msg09:
		.BYTE $6D,$7B,$78,$F1,$8A,$74,$85,$E5,$78,$89,$78,$85,$8C,$87,$7B,$7C,$81,$7A,$FF
		.BYTE $87,$7B,$74,$87,$F1,$7B,$74,$83,$83,$78,$81,$78,$77,$F1,$80,$74,$8C,$75,$78,$FF
		.BYTE $7C,$87,$90,$86,$F1,$8A,$85,$82,$81,$7A,$E4,$FF,$FF
_scriptA4_msg0a:
		.BYTE $5D,$82,$81,$90,$87,$F1,$7B,$74,$87,$78,$FF
		.BYTE $8C,$82,$88,$85,$F1,$76,$82,$88,$81,$87,$85,$8C,$F1,$79,$82,$85,$FF
		.BYTE $8A,$7B,$74,$87,$F1,$8C,$82,$88,$90,$89,$78,$F1,$75,$78,$78,$81,$FF
		.BYTE $87,$7B,$85,$82,$88,$7A,$7B,$E4,$FF,$FF
_scriptA4_msg0b:
		.BYTE $61,$74,$87,$78,$8E,$FF
		.BYTE $62,$90,$77,$F1,$77,$7C,$78,$F1,$79,$82,$85,$F1,$7C,$87,$E4,$FF,$FF
_scriptA4_msg0c:
		.BYTE $6C,$82,$E5,$8A,$7B,$74,$87,$F1,$77,$82,$F1,$8C,$82,$88,$FF
		.BYTE $8A,$74,$81,$87,$E4,$FF,$FF
_scriptA4_msg0d:
		.BYTE $62,$F1,$8A,$74,$81,$87,$F1,$8A,$7B,$74,$87,$F1,$87,$7B,$78,$8C,$FF
		.BYTE $8A,$74,$81,$87,$E4,$E4,$E4,$FF
		.BYTE $78,$89,$78,$85,$8C,$F1,$82,$87,$7B,$78,$85,$F1,$7A,$88,$8C,$FF
		.BYTE $8A,$7B,$82,$F1,$76,$74,$80,$78,$F1,$82,$89,$78,$85,$F1,$7B,$78,$85,$78,$E5,$FF,$FF
_scriptA4_msg0e:
		.BYTE $62,$F1,$8A,$74,$81,$87,$F1,$79,$82,$85,$FF
		.BYTE $80,$8C,$F1,$76,$82,$88,$81,$87,$85,$8C,$F1,$87,$82,$F1,$7F,$82,$89,$78,$FF
		.BYTE $80,$78,$F1,$74,$86,$F1,$80,$88,$76,$7B,$F1,$74,$86,$FF
		.BYTE $62,$F1,$7F,$82,$89,$78,$F1,$7C,$87,$E4,$FF,$FF
_scriptA4_msg0f:
		.BYTE $6D,$7B,$74,$87,$90,$86,$F1,$8A,$7B,$74,$87,$F1,$62,$F1,$8A,$74,$81,$87,$E4,$FF,$FF
_scriptA4_msg10:
		.BYTE $70,$7B,$74,$87,$F1,$74,$85,$78,$F1,$8C,$82,$88,$F1,$7A,$82,$7C,$81,$7A,$FF
		.BYTE $87,$82,$F1,$77,$82,$8E,$FF,$FF
_scriptA4_msg11:
		.BYTE $5D,$74,$8C,$F1,$75,$8C,$F1,$77,$74,$8C,$E4,$FF,$FF
_scriptA4_msg12:
		.BYTE $70,$78,$7F,$76,$82,$80,$78,$F1,$75,$74,$76,$7E,$E4,$FF
		.BYTE $5B,$88,$87,$F1,$87,$7B,$78,$F1,$7A,$74,$80,$78,$F1,$7C,$86,$F1,$81,$82,$87,$FF
		.BYTE $82,$89,$78,$85,$E4,$63,$82,$7B,$81,$E5,$74,$85,$78,$F1,$8C,$82,$88,$FF
		.BYTE $86,$74,$87,$7C,$86,$79,$7C,$78,$77,$8E,$FF,$FF
_scriptA4_msg13:
		.BYTE $65,$78,$87,$F1,$80,$78,$F1,$87,$85,$8C,$F1,$74,$7A,$74,$7C,$81,$E4,$FF
		.BYTE $F1,$FF
		.BYTE $F1,$FF
		.BYTE $62,$F1,$77,$82,$81,$90,$87,$F1,$8A,$74,$81,$87,$F1,$87,$82,$F1,$77,$82,$FF
		.BYTE $87,$7B,$74,$87,$F1,$74,$7A,$74,$7C,$81,$E4,$FF,$FF
		.BYTE $FF
_scriptA4_msg14:
		.BYTE $6D,$7B,$78,$F1,$85,$78,$74,$7F,$F1,$83,$88,$85,$83,$82,$86,$78,$F1,$82,$79,$FF
		.BYTE $87,$7B,$78,$F1,$7A,$74,$80,$78,$F1,$7C,$86,$F1,$87,$82,$F1,$86,$74,$89,$78,$FF
		.BYTE $87,$7B,$78,$F1,$69,$68,$70,$E4,$FF,$FF
_scriptA5_msg00:
		.BYTE $70,$7B,$74,$87,$F1,$74,$85,$78,$F1,$8C,$82,$88,$F1,$77,$82,$7C,$81,$7A,$8E,$FF
		.BYTE $60,$82,$7C,$81,$7A,$F1,$87,$82,$FF
		.BYTE $87,$7B,$78,$F1,$6C,$87,$74,$87,$78,$86,$8E,$FF,$FF
_scriptA5_msg01:
		.BYTE $70,$74,$85,$80,$F1,$83,$78,$82,$83,$7F,$78,$E4,$FF
		.BYTE $70,$74,$85,$80,$F1,$76,$7C,$87,$8C,$E4,$FF
		.BYTE $70,$74,$85,$80,$F1,$77,$74,$8C,$86,$E4,$FF,$FF
_scriptA5_msg02:
		.BYTE $62,$90,$89,$78,$F1,$75,$78,$78,$81,$F1,$77,$85,$78,$74,$80,$7C,$81,$7A,$FF
		.BYTE $82,$79,$F1,$7F,$7C,$89,$7C,$81,$7A,$F1,$7C,$81,$F1,$87,$7B,$78,$FF
		.BYTE $6E,$6C,$5A,$F1,$74,$81,$77,$F1,$7B,$74,$89,$7C,$81,$7A,$F1,$74,$FF
		.BYTE $86,$7C,$80,$83,$7F,$78,$F1,$7F,$7C,$79,$78,$E4,$62,$79,$F1,$8C,$82,$88,$FF
		.BYTE $77,$82,$81,$90,$87,$F1,$80,$7C,$81,$77,$EE,$EE,$EE,$FF,$FF
_scriptA5_msg03:
		.BYTE $62,$F1,$87,$7B,$7C,$81,$7E,$F1,$62,$F1,$7F,$78,$74,$85,$81,$78,$77,$FF
		.BYTE $86,$82,$80,$78,$87,$7B,$7C,$81,$7A,$F1,$7C,$80,$83,$82,$85,$87,$74,$81,$87,$FF
		.BYTE $79,$85,$82,$80,$F1,$8C,$82,$88,$E4,$62,$F1,$80,$74,$8C,$F1,$75,$78,$FF
		.BYTE $74,$75,$7F,$78,$F1,$87,$82,$F1,$7F,$7C,$89,$78,$E5,$FF
		.BYTE $82,$85,$F1,$7F,$82,$89,$78,$EE,$EE,$EE,$FF,$FF
_scriptA5_msg04:
		.BYTE $6B,$78,$74,$7F,$7F,$8C,$8E,$FF
		.BYTE $62,$F1,$7F,$82,$89,$78,$F1,$8C,$82,$88,$E4,$FF,$FF
		.BYTE $FF,$FF,$FF,$FF,$FF
_scriptAA_msg00:
		.BYTE $6B,$74,$80,$75,$82,$F1,$74,$81,$77,$F1,$5C,$82,$F1,$82,$81,$FF
		.BYTE $87,$7B,$78,$F1,$75,$82,$74,$87,$EE,$EE,$EE,$FF,$FF
		.BYTE $FF,$FF
_scriptAC_msg00:
		.BYTE $62,$90,$80,$F1,$5E,$85,$7C,$76,$86,$82,$81,$E4,$FF
		.BYTE $62,$90,$80,$F1,$7A,$7F,$74,$77,$F1,$87,$82,$F1,$8A,$82,$85,$7E,$FF
		.BYTE $8A,$7C,$87,$7B,$F1,$8C,$82,$88,$E4,$FF,$FF
_scriptAC_msg01:
		.BYTE $70,$78,$90,$89,$78,$F1,$81,$82,$F1,$87,$7C,$80,$78,$E4,$FF
		.BYTE $60,$82,$F1,$87,$82,$FF
		.BYTE $6D,$85,$74,$88,$87,$80,$74,$81,$F1,$86,$82,$82,$81,$E4,$FF,$FF
_scriptAD_msg00:
		.BYTE $6D,$7B,$74,$81,$7E,$F1,$8C,$82,$88,$F1,$6B,$74,$80,$75,$82,$E4,$FF
		.BYTE $70,$78,$F1,$7E,$81,$78,$8A,$F1,$87,$7B,$74,$87,$FF
		.BYTE $8C,$82,$88,$F1,$8A,$82,$88,$7F,$77,$F1,$86,$74,$89,$78,$FF
		.BYTE $87,$7B,$78,$80,$E4,$FF,$FF
_scriptAE_msg00:
		.BYTE $5C,$82,$F1,$8A,$78,$81,$87,$F1,$87,$82,$F1,$87,$7B,$78,$F1,$76,$74,$80,$83,$FF
		.BYTE $87,$82,$F1,$7B,$78,$7F,$83,$F1,$6B,$74,$80,$75,$82,$E4,$FF,$FF
		.BYTE $FF,$FF,$FF
_scriptB1_msg00:
		.BYTE $6B,$74,$80,$75,$82,$FF
		.BYTE $F1,$FF
		.BYTE $F1,$6D,$7B,$78,$F1,$75,$74,$87,$87,$7F,$78,$F1,$7C,$86,$FF
		.BYTE $F1,$82,$89,$78,$85,$E5,$75,$88,$87,$EE,$EE,$EE,$FF,$FF
_scriptB1_msg01:
		.BYTE $6D,$7B,$74,$81,$7E,$F1,$8C,$82,$88,$FF
		.BYTE $79,$82,$85,$F1,$87,$85,$8C,$7C,$81,$7A,$E4,$FF,$FF
_trash:
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$02,$04,$04,$05,$05,$07,$02
		.BYTE $07,$01,$03,$03,$02,$02,$00,$01,$02,$7F,$3F,$3F,$7F,$73,$E0,$EF
		.BYTE $FF,$FF,$FF,$FF,$BF,$BF,$7F,$7C,$7F,$FF,$FF,$FF,$FF,$F9,$61,$FD
		.BYTE $FF,$FE,$BF,$BF,$BF,$FF,$FF,$7F,$3F,$20,$A0,$A0,$A0,$A0,$A0,$A0
		.BYTE $C0,$C0,$40,$40,$40,$40,$40,$40,$00,$0F,$1F,$3F,$3F,$3F,$3F,$1F
		.BYTE $1F,$00,$04,$03,$03,$06,$07,$0F,$07,$C0,$E0,$C0,$C0,$C0,$E0,$C0
		.BYTE $C0,$00,$00,$80,$80,$80,$C0,$80,$80,$30,$1F,$10,$0F,$10,$10,$10
		.BYTE $10,$0F,$00,$0F,$00,$0F,$0F,$0F,$0F,$78,$90,$48,$F8,$08,$44,$44
		.BYTE $42,$80,$60,$B0,$00,$F0,$B8,$B8,$BC,$84,$84,$8C,$CC,$F8,$FC,$FE
		.BYTE $7F,$78,$78,$70,$30,$00,$00,$00,$00,$86,$84,$8C,$CC,$F8,$FC,$7E
		.BYTE $7F,$78,$78,$70,$30,$00,$00,$00,$00,$0F,$1F,$16,$10,$08,$04,$04
		.BYTE $02,$07,$06,$09,$0F,$07,$03,$03,$01,$81,$00,$20,$10,$10,$18,$10
		.BYTE $14,$7E,$FF,$DF,$EF,$EF,$E7,$E7,$E3,$00,$80,$40,$40,$20,$20,$20
		.BYTE $10,$00,$00,$80,$80,$C0,$C0,$C0,$E0,$03,$0C,$10,$10,$20,$20,$40
		.BYTE $40,$00,$03,$0F,$0F,$1F,$1F,$3F,$3F,$FF,$FF,$7F,$3F,$1F,$04,$02
		.BYTE $02,$7F,$7E,$AF,$D3,$E0,$F8,$FC,$FC,$FE,$FC,$F8,$F0,$C0,$00,$00
		.BYTE $00,$FC,$38,$F0,$C0,$00,$00,$00,$00,$07,$07,$07,$07,$03,$03,$03
		.BYTE $03,$03,$03,$03,$03,$01,$01,$01,$01,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE $FF,$B1,$F1,$C7,$FF,$FF,$FF,$FF,$FE,$FF,$FF,$FF,$FF,$BF,$BF,$BF
		.BYTE $FF,$B3,$B1,$3D,$FF,$FF,$FF,$FF,$FF,$C0,$E0,$E0,$E0,$E0,$C0,$80
		.BYTE $80,$00,$C0,$C0,$40,$40,$00,$00,$00,$3F,$47,$F3,$89,$8F,$83,$80
		.BYTE $40,$06,$3A,$0C,$76,$70,$7C,$7F,$3F,$E0,$7C,$FF,$FF,$FF,$3F,$3D
		.BYTE $3D,$00,$80,$00,$00,$00,$DC,$D8,$D8,$00,$00,$0C,$FF,$FF,$F0,$E0
		.BYTE $80,$00,$00,$00,$00,$00,$C0,$C0,$00,$10,$20,$21,$21,$43,$42,$42
		.BYTE $E6,$0F,$1F,$1E,$1E,$3C,$3C,$3C,$18,$C2,$A1,$21,$39,$61,$42,$42
		.BYTE $42,$3C,$1E,$1E,$06,$1E,$3C,$3C,$3C,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$02,$01,$02,$06,$07,$0F,$0F
		.BYTE $0F,$01,$00,$01,$01,$00,$00,$00,$00,$13,$12,$14,$14,$A7,$CF,$CF
		.BYTE $CF,$E0,$E1,$E3,$E3,$40,$00,$00,$00,$10,$10,$20,$40,$C0,$C0,$E0
		.BYTE $E0,$E0,$E0,$C0,$80,$00,$00,$00,$00,$41,$42,$42,$26,$21,$23,$17
		.BYTE $0F,$3E,$3D,$3D,$19,$1E,$1C,$0B,$06,$02,$82,$03,$03,$03,$1F,$E2
		.BYTE $C1,$FC,$7C,$FD,$FD,$FD,$E0,$1C,$BE,$00,$00,$F0,$F8,$F8,$F8,$B0
		.BYTE $00,$00,$00,$00,$F0,$D0,$B0,$00,$00,$03,$03,$01,$01,$01,$01,$01
		.BYTE $01,$01,$01,$00,$00,$00,$00,$00,$00,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE $FF,$FD,$FE,$FB,$F7,$F6,$FD,$FB,$FC,$FF,$FF,$FF,$FF,$FF,$FF,$FF
		.BYTE $FF,$FF,$6F,$9F,$FF,$0F,$F7,$EE,$1E,$80,$C0,$80,$80,$80,$80,$00
		.BYTE $00,$00,$80,$00,$00,$00,$00,$00,$00

		BANK_END 5,$C000
