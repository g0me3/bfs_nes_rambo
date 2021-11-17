
		ORG $C000

		BANK_START $7

		INCBIN "..\copyrights.txt"

		SECTION_START

; =============== S U B	R O U T	I N E =======================================
IRQ:
RESET:
		CLD
		LDX		#$FF
		TXS
loc_600DC:
		LDA		_PPU_STATUS
		BMI		loc_600DC
loc_600E1:
		LDA		_PPU_STATUS
		BMI		loc_600E1
		LDA		#$14
		STA		_PPU_CTRL
		LDY		#$00
		LDA		#$00
loc_600EF:
		STA		$00,Y
		INY
		BNE		loc_600EF
		INC		_tmp01
loc_600F7:
		LDA		#$00
loc_600F9:
		STA		(_tmp00),Y
		INY
		BNE		loc_600F9
		INC		_tmp01
		LDA		_tmp01
		CMP		#$08
		BNE		loc_600F7
		JSR		_spr_clear
		LDA		#<[_ppu_queue_buf]
		STA		_ppu_queue_buf_ofs
		LDA		#>[_ppu_queue_buf]
		STA		_ppu_queue_buf_ofs+1
		LDA		#$C8
		STA		_game._life
		LDA		#$00
		STA		_game._life+1
		LDA		#$78
		STA		_objsA._player._x_pos
		LDA		#$D0
		STA		_objsA._player._y_pos
		LDA		#$80
		STA		_game._scr_idx
		LDA		#$FF
		STA		_game._redraw_req
		STA		_nmi_disble_ppu_reset_req
		LDA		#$90
		STA		_ppu_ctrl_shadow
		LDA		#$10
		STA		_objA_buf_shuffle_pos
		JSR		_objs_reset
_delay:
		INC		_tmp04
		BNE		_delay
		INC		_tmp05
		BNE		_delay
		INC		_tmp06
		LDA		_tmp06
		CMP		#$02
		BNE		_delay
		LDA		#$06
		JSR		_mmc_prg_set
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		#$0A					; load dummy
		JSR		_apu_cur_mus_load
_main_loop:
		LDA		_nmi_flag
		CMP		#$02
		BCC		_main_loop
		LDA		#$00
		STA		_nmi_flag
loc_6003D:
		LDA		_ppu_dequeue_idx
		BNE		loc_6003D
		LDA		#$14
		STA		_spr_buf_pos
		JSR		_read_pad_safeB
		LDA		_ingame_pause_flag
		BNE		loc_6005D
		JSR		_level_draw_update
		LDA		_game._redraw_req
		BNE		loc_6005D
		JSR		_engine_handlers
		JSR		_game_warps_handler
loc_6005D:
		LDA		_objsA._player._dir
		AND		#$08
		BEQ		loc_6006B
		LDA		#$00
		STA		_ingame_pause_flag
		BEQ		loc_6006E
loc_6006B:
		JSR		_ingame_start_select_handler
loc_6006E:
		JSR		_game_values_to_decimal
		JSR		_hud_cursor_spr_insert
		LDA		_game._redraw_req
		BNE		loc_6007F
		JSR		_spr_objsB_manager
		JSR		_spr_objsA_manager
loc_6007F:
		LDA		#$06
		JSR		_mmc_prg_set
		LDA		_game._life+1
		BNE		loc_600C0
		LDA		_game._life_level
		ASL
		TAY
		LDA		_max_life_list,Y
		STA		_tmp02
		LDA		_max_life_list+1,Y
		STA		_tmp03
		LSR		_tmp03
		ROR		_tmp02
		LSR		_tmp03
		ROR		_tmp02
		LSR		_tmp03
		ROR		_tmp02
		LDA		_game._life
		CMP		_tmp02
		BCS		loc_600C0
		LDA		_play_seconds
		AND		#$01
		BEQ		loc_600C0
		LDA		_ppu_mask_shadow
		ORA		#$20
		STA		_ppu_mask_shadow
		BNE		loc_600C8
loc_600C0:
		LDA		_ppu_mask_shadow
		AND		#$DF
		STA		_ppu_mask_shadow
loc_600C8:
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
;		LDA		_pad							; removed cheat leftovers.
;		CMP		#$18
;		BNE		loc_600D5
;loc_600D5:
		JMP		_main_loop

; =============== S U B	R O U T	I N E =======================================
_render_off:
		LDA		#$00
		STA		_nmi_flag
loc_63C46:
		LDA		_nmi_flag
		BEQ		loc_63C46

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_render_off_ex:
		LDA		#$10
		STA		_PPU_CTRL
		LDA		#$00
		STA		_PPU_MASK
		RTS

; =============== S U B	R O U T	I N E =======================================
_render_on:
		LDA		_PPU_STATUS
		LDA		#$00
		STA		_PPU_SCROLL
		STA		_PPU_SCROLL

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_render_on_ex:
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_render_on_ex_ex:
		LDA		#$1E
		STA		_PPU_MASK
		LDA		#$90
		STA		_PPU_CTRL
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_clear:
		PHA
		TYA
		PHA
		LDA		#$F8
		LDY		#$04
loc_60147:
		STA		_spr_buf,Y
		INY
		INY
		INY
		INY
		BNE		loc_60147
		PLA
		TAY
		PLA
		RTS

; =============== S U B	R O U T	I N E =======================================
_objs_reset:
		LDX		#$10
loc_60156:
		LDA		#$80
		STA		_objsA,X
		TXA
		CLC
		ADC		#$10
		TAX
		CPX		#$80
		BNE		loc_60156
		LDX		#$00
loc_60165:
		LDA		#$80
		STA		_objsB,X
		TXA
		CLC
		ADC		#$08
		TAX
		CPX		#$60
		BNE		loc_60165
		RTS

; =============== S U B	R O U T	I N E =======================================
_read_pad_safeB:
		JSR		_read_pad_safe
		LDA		_pad_tmp
		AND		_pad
		STA		_tmp00
		LDA		_pad_tmp
		EOR		_pad
		AND		_pad
		STA		_pad
		ORA		_tmp00
		AND		#$F8
		STA		_pad_tmp
		RTS

; =============== S U B	R O U T	I N E =======================================
_read_pad_safe:
		JSR		_read_pad
		STA		_pad
		JSR		_read_pad
		CMP		_pad
		BNE		_read_pad_safe
		RTS

; =============== S U B	R O U T	I N E =======================================
_read_pad:
		LDX		#$01
		STX		_PAD0_REG
		DEX
		TXA
		TAY
		STX		_PAD0_REG
loc_6029F:
		LDA		_PAD0_REG
		STA		_tmp00
		LSR
		ORA		_tmp00
		LSR
		ROL		_tmp03
		INX
		CPX		#$08
		BNE		loc_6029F
		LDA		_tmp03
		RTS

; =============== S U B	R O U T	I N E =======================================
_mmc_prg_set:
		STA		_cur_prg_bank

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_mmc_prg:
		PHA
		TXA
		PHA
		LDA		_cur_prg_bank
		TAX
		STA		_mmc_cmd_list,X
		PLA
		TAX
		PLA
		RTS
_mmc_cmd_list:
		.BYTE $00,$01,$02,$03,$04,$05,$06,$07

; =============== S U B	R O U T	I N E =======================================
_ingame_start_select_handler:
		LDA		_pad
		AND		#$10
		BEQ		loc_602EB
		LDA		#SEP01
		STA		_apu_se_pulse_idx
		LDA		_ingame_pause_flag
		EOR		#$FF
		STA		_ingame_pause_flag
loc_602EB:
		LDA		_pad
		AND		#$20
		BNE		loc_60333
		LDA		_ingame_pause_flag
		BEQ		loc_60326
		LDA		_cur_weapon_selected
		CMP		#$06
		BNE		loc_60326
		LDA		_pad
		AND		#$40
		BEQ		loc_60326
		LDA		_game._potions
		BEQ		loc_60326
		DEC		_game._potions
		LDA		_game._life
		CLC
		ADC		#$64
		STA		_game._life
		BCC		loc_602EC
		INC		_game._life+1
loc_602EC:
		LDA		#SEP04
		STA		_apu_se_pulse_idx
		BNE		loc_60345
loc_60326:
		LDA		_cur_weapon_selected
		BNE		loc_603AD
		LDA		_prev_weapon_selected
		BNE		loc_60370
		BEQ		loc_603AD
loc_60333:
		LDA		_ppu_dequeue_idx
		BNE		loc_603AD
loc_6033B:
		INC		_cur_weapon_selected
		LDA		_cur_weapon_selected
		CMP		#$07
		BCC		loc_6034A
loc_60345:
		LDA		#$00
		STA		_cur_weapon_selected
loc_6034A:
		CMP		#$00
		BEQ		loc_60370
		TAX
		LDA		_game._exp_level,X
		BEQ		loc_6033B
		LDA		_cur_weapon_selected
		CMP		#$06
		BNE		loc_60370
		LDA		_game._life_level
		ASL
		TAY
		LDA		_max_life_list,Y
		CMP		_game._life
		BNE		loc_60370
		LDA		_max_life_list+1,Y
		CMP		_game._life+1
		BEQ		loc_6033B
loc_60370:
		LDA		_cur_weapon_selected
		STA		_prev_weapon_selected
		LDA		_ppu_ctrl_shadow
		AND		#$7F
		STA		_PPU_CTRL
		LDA		_apu_se_pulse_idx
		BNE		loc_60388
		LDA		#SEP02
		STA		_apu_se_pulse_idx
loc_60388:
		JSR		_hud_cursor_spr_insert
		LDA		_cur_weapon_selected
		TAY
		LDA		_rambo_chr_weapon_tiles_ofs_list,Y
		CLC
		ADC		#$80
		STA		_chr_tiles_send_src+1
		LDA		#$03
		STA		_chr_tiles_send_dst+1
		LDA		#$00
		STA		_chr_tiles_send_src
		STA		_chr_tiles_send_dst
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
loc_603AD:
		LDA		_ingame_pause_flag
		BEQ		_ingame_cheats_test
		RTS
_ingame_cheats_test:
		LDA		_pad
		BNE		loc_603C5
		LDA		_ingame_down_cheat_counter
		AND		#$7F
		STA		_ingame_down_cheat_counter
		JMP		loc_6040F
loc_603C5:
		LDA		_pad
		AND		#$FB
		BNE		loc_603D3
		LDA		_pad
		AND		#$04
		BNE		loc_603DB
loc_603D3:
		LDA		#$00
		STA		_ingame_down_cheat_counter
		BNE		loc_6040F
loc_603DB:
		LDA		_ingame_down_cheat_counter
		AND		#$80
		BNE		loc_6040F
		INC		_ingame_down_cheat_counter
		LDA		_ingame_down_cheat_counter
		ORA		#$80
		STA		_ingame_down_cheat_counter
		LDA		_ingame_down_cheat_counter
		AND		#$7F
		CMP		#$64
		BNE		loc_6040F
		LDA		_game._exp
		CLC
		ADC		#$0F
		STA		_game._exp
		BCC		loc_6040E
		INC		_game._exp+1
loc_6040E:
		LDA		#SEP03
		STA		_apu_se_pulse_idx
		BNE		loc_603D3
loc_6040F:
		LDA		_pad
		AND		#$F0
		BNE		loc_60445
		LDA		_pad
		AND		#$0F
		BEQ		locret_6044A
		EOR		_ingame_dpad_cheat_counter
		STA		_ingame_dpad_cheat_counter
		AND		#$0F
		CMP		#$0F
		BNE		locret_6044A
		LDA		_ingame_dpad_cheat_counter
		AND		#$F0
		CLC
		ADC		#$10
		STA		_ingame_dpad_cheat_counter
		BNE		locret_6044A
		LDA		_game._potions
		CMP		#$09
		BCS		loc_60445
		LDA		#SEP03
		STA		_apu_se_pulse_idx
		INC		_game._potions
loc_60445:
		LDA		#$00
		STA		_ingame_dpad_cheat_counter
locret_6044A:
		RTS
_rambo_chr_weapon_tiles_ofs_list:
		.BYTE $1D,$1D,$1B,$1B,$1A,$1D,$1D

; =============== S U B	R O U T	I N E =======================================
_hud_cursor_spr_insert:
		LDA		#$FE
		STA		_spr_buf+5
		STA		_spr_buf+9
		STA		_spr_buf+$D
		STA		_spr_buf+$11
		LDA		#$83
		STA		_spr_buf+6
		LDA		#$C3
		STA		_spr_buf+$A
		LDA		#$03
		STA		_spr_buf+$E
		LDA		#$43
		STA		_spr_buf+$12
		LDA		#$0E
		STA		_spr_buf+4
		STA		_spr_buf+8
		LDA		#$17
		STA		_spr_buf+$C
		STA		_spr_buf+$10
		LDA		_cur_weapon_selected
		ASL
		CLC
		ADC		_cur_weapon_selected
		ASL
		ASL
		ASL
		CLC
		ADC		#$56
		STA		_spr_buf+7
		STA		_spr_buf+$F
		CLC
		ADC		#$0C
		STA		_spr_buf+$B
		STA		_spr_buf+$13
		RTS

; =============== S U B	R O U T	I N E =======================================
_far_dialog_script_play:
		LDA		_game._scr_idx			; no start if this is not dialog
		BMI		loc_604A8
		RTS
loc_604A8:
		JSR		_chr_bg_tiles_load		; load CHR data with fonts and portraits
		JSR		_chr_spr_tiles_load
		LDA		#$05
		JSR		_mmc_prg_set
		JMP		_dialog_script_play

; =============== S U B	R O U T	I N E =======================================
_level_draw_update:
		LDA		_game._redraw_req
		BNE		loc_604C1
		RTS
loc_604C1:
		LDA		_game._scr_idx
		BMI		loc_604C9
		JMP		loc_6057F
loc_604C9:
		CMP		#$FF
		BNE		loc_604D0
		JMP		loc_6057F
loc_604D0:
		LDA		#$00
		STA		_ppu_mask_shadow
		STA		_PPU_MASK
		LDA		#$00
		STA		_nmi_disable
		LDA		#$80
		STA		_nmi_disble_ppu_reset_req
		LDA		#$0D
		STA		_tmp0D
		LDY		#$00
		LDA		_game._scr_idx
loc_604EA:
		CMP		_level_mus_restore_tbl,Y
		BEQ		loc_604F7
		INY
		CPY		#$0C
		BNE		loc_604EA
		BEQ		loc_60508
loc_604F7:
		DEC		_tmp0D
		JMP		loc_60525
; ---------------------------------------------------------------------------
_level_mus_restore_tbl:
		.BYTE $8E,$A6,$A7,$A8,$AA,$AB,$AF,$B0,$B0,$B0,$B0,$B0
; ---------------------------------------------------------------------------
loc_60508:
		LDA		_game._scr_idx
		CMP		#$82
		BCC		loc_60525
		DEC		_tmp0D
		DEC		_tmp0D
		CMP		#$82
		BEQ		loc_60525
		INC		_tmp0D
		INC		_tmp0D
		INC		_tmp0D
		INC		_tmp0D
		CMP		#$B1
		BCS		loc_60525
		DEC		_tmp0D
loc_60525:
		LDA		_apu_prev_mus_idx
		CMP		_tmp0D
		BEQ		loc_60542
		LDA		_ppu_ctrl_shadow
		AND		#$7F
		STA		_PPU_CTRL
		LDA		_tmp0D
		STA		_apu_prev_mus_idx
		JSR		_apu_cur_mus_load
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
loc_60542:
		JSR		_far_dialog_script_play
		LDA		_game._scr_idx
		BPL		loc_60551
		CMP		#$FF
		BNE		loc_60568
loc_60551:
		JSR		_spr_clear
		LDA		#$1E
		STA		_spr_buf
		LDA		#$FF
		STA		_spr_buf+1
		LDA		#$00
		STA		_spr_buf+2
		LDA		#$00
		STA		_spr_buf+3
loc_60568:
		LDA		#$06
		JSR		_mmc_prg_set
		LDA		#$00
		STA		_ppu_dequeue_idx
		JSR		_hud_cursor_spr_insert
		LDA		_game._scr_idx
		STA		_game_scr_idx_backup_unused
locret_6057E:
		RTS
loc_6057F:
		LDA		#$00
		STA		_nmi_disble_ppu_reset_req
		JSR		_spr_clear
		LDA		_ppu_ctrl_shadow
		AND		#$7F
		STA		_PPU_CTRL
		LDA		#$00
		STA		_ppu_mask_shadow
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_nmi_flag
		STA		_tmp0D
loc_6059F:
		LDA		_nmi_flag
		CMP		_tmp0D
		BEQ		loc_6059F
		LDA		#$FF
		STA		_nmi_disable
		LDA		_game._scr_idx
		CMP		#$FF
		BNE		loc_605B7
		JSR		_final_boss_draw
		JMP		loc_60679
loc_605B7:
		LDA		_game._scr_idx
		TAX
		LDA		_location_room_settings,X
		STA		_cur_loc_room_settings
		LDA		_location_chr_list,X
		STA		_cur_level_chr_idx
		LDA		_location_bg_pal_settings,X
		STA		_cur_loc_bg_pal_settings
		LDA		_location_spr_pal_settings,X
		STA		_cur_loc_spr_pal_settings
		LDA		_location_room_idx_and_stop_flags,X
		STA		_cur_loc_room_idx_and_stop_flags
		LDA		_location_warpsA_list,X
		STA		_cur_loc_warpA_pos
		LDA		_location_warpsB_list,X
		STA		_cur_loc_warpB_pos
		LDA		_location_prizes_list,X
		STA		_cur_loc_prize_idx
		LDA		_cur_loc_room_settings
		AND		#$02
		BEQ		_regular_day_light_palettes
		LDA		_game._flags
		AND		#$08
		BNE		_palette_with_lamp
		LDA		_cur_loc_bg_pal_settings
		AND		#$F0
		LSR
		LSR
		LSR
		LSR
		ORA		#$80
		STA		_cur_pal_bg_idx
		LDA		_cur_loc_spr_pal_settings
		AND		#$F0
		LSR
		LSR
		LSR
		LSR
		ORA		#$80
		STA		_cur_pal_spr_lib
		JMP		loc_6066D
_palette_with_lamp:
		LDA		_cur_loc_bg_pal_settings
		AND		#$0F
		ORA		#$80
		STA		_cur_pal_bg_idx
		LDA		_cur_loc_spr_pal_settings
		AND		#$0F
		ORA		#$80
		STA		_cur_pal_spr_lib
		JMP		loc_6066D
_regular_day_light_palettes:
		LDA		_game._play_hours
		CMP		#$15
		BCS		_room_night_palette
		CMP		#$04
		BCS		_room_day_palette
_room_night_palette:
		LDA		_cur_loc_bg_pal_settings
		AND		#$F0
		LSR
		LSR
		LSR
		LSR
		ORA		#$80
		STA		_cur_pal_bg_idx
		LDA		_cur_loc_spr_pal_settings
		AND		#$F0
		LSR
		LSR
		LSR
		LSR
		ORA		#$80
		STA		_cur_pal_spr_lib
		JMP		loc_6066D
_room_day_palette:
		LDA		_cur_loc_bg_pal_settings
		AND		#$0F
		ORA		#$80
		STA		_cur_pal_bg_idx
		LDA		_cur_loc_spr_pal_settings
		AND		#$0F
		ORA		#$80
		STA		_cur_pal_spr_lib
loc_6066D:
		JSR		_stage_objs_insert_manager
		JSR		_level_room_data_unpack
		JSR		_room_data_send_to_vram
		JSR		_blank_screen
loc_60679:
		JSR		_chr_spr_tiles_load
		JSR		_chr_bg_tiles_load
		JSR		_hud_icons_redraw
		LDA		_game._scr_idx
		CMP		#$FF
		BNE		loc_6068E
		LDA		#$03
		BNE		loc_6069C
loc_6068E:
		LDA		_cur_loc_room_settings
		AND		#$F0
		LSR
		LSR
		LSR
		LSR
		CMP		_apu_prev_mus_idx
		BEQ		loc_606B3
loc_6069C:
		STA		_apu_prev_mus_idx
		LDA		_ppu_ctrl_shadow
		AND		#$7F
		STA		_PPU_CTRL
		LDA		_apu_prev_mus_idx
		JSR		_apu_cur_mus_load
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
loc_606B3:
		JSR		_rambo_chr_weapon_tiles_unpdate
		LDA		#$06
		JSR		_mmc_prg_set
		LDA		#$00
		STA		_ppu_dequeue_idx
		JSR		_hud_cursor_spr_insert
		LDA		_game._scr_idx
		STA		_game_scr_idx_backup_unused
		LDA		#$1E
		STA		_ppu_mask_shadow
		LDA		_cur_pal_bg_idx
		ORA		#$B0
		STA		_cur_pal_bg_idx
		LDA		_cur_pal_spr_lib
		ORA		#$B0
		STA		_cur_pal_spr_lib
		LDA		#$00
		STA		_nmi_disable
loc_606E5:
		LDA		_cur_pal_bg_idx
		ORA		_cur_pal_spr_lib
		AND		#$80
		BNE		loc_606E5
		LDA		_objsA._player._dir
		AND		#$F0
		STA		_objsA._player._dir
		LDA		#$00
		STA		_game._redraw_req
		RTS

; =============== S U B	R O U T	I N E =======================================
_rambo_chr_weapon_tiles_unpdate:
		LDA		_cur_weapon_selected
		TAY
		LDA		_rambo_chr_weapon_tiles_ofs_list,Y
		CLC
		ADC		#>[_chr_rambo_weap0-$1A00]
		STA		_tmp0F
		LDA		#<[_chr_rambo_weap0-$1A00]
		STA		_tmp0E
		LDA		_PPU_STATUS
		LDA		#$03
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		#$03
		JSR		_mmc_prg_set
		LDY		#$00
loc_60724:
		LDA		(_tmp0E),Y
		STA		_PPU_DATA
		INY
		BNE		loc_60724
		RTS

; =============== S U B	R O U T	I N E =======================================
_final_boss_draw:
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		#$1E
		STA		_tmp01
loc_6073E:
		LDA		#$20
		STA		_tmp00
loc_60742:
		LDA		#$30
		STA		_PPU_DATA
		DEC		_tmp00
		BNE		loc_60742
		DEC		_tmp01
		BNE		loc_6073E
		LDX		#$40
		LDA		#$AA
loc_60753:
		STA		_PPU_DATA
		DEX
		BNE		loc_60753
		LDA		_PPU_STATUS
		LDA		#$24
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		#$1E
		STA		_tmp01
loc_6076A:
		LDA		#$20
		STA		_tmp00
loc_6076E:
		LDA		#$30
		STA		_PPU_DATA
		DEC		_tmp00
		BNE		loc_6076E
		DEC		_tmp01
		BNE		loc_6076A
		LDX		#$40
		LDA		#$AA
loc_6077F:
		STA		_PPU_DATA
		DEX
		BNE		loc_6077F
		LDX		#$00
loc_60787:
		LDA		_final_boss_pak_tlm+2,X
		STA		_tmp00
		LDA		_final_boss_pak_tlm+3,X
		STA		_tmp01
		LDA		_PPU_STATUS
		LDA		_final_boss_pak_tlm+1,X
		STA		_PPU_ADDR
		LDA		_final_boss_pak_tlm,X
		STA		_PPU_ADDR
loc_607A0:
		LDA		_tmp00
		STA		_PPU_DATA
		INC		_tmp00
		DEC		_tmp01
		BNE		loc_607A0
		INX
		INX
		INX
		INX
		CPX		#$20
		BNE		loc_60787
		LDX		#$80
		LDA		_PPU_STATUS
		LDA		#$23
		STA		_PPU_ADDR
		LDA		#$40
		STA		_PPU_ADDR
		LDA		#$7F
loc_607C4:
		STA		_PPU_DATA
		DEX
		BNE		loc_607C4
		LDX		#$80
		LDA		_PPU_STATUS
		LDA		#$27
		STA		_PPU_ADDR
		LDA		#$40
		STA		_PPU_ADDR
		LDA		#$7F
loc_607DB:
		STA		_PPU_DATA
		DEX
		BNE		loc_607DB
		LDA		#<[_room_map_buf]
		STA		_tmp02
		LDA		#>[_room_map_buf]
		STA		_tmp03
		LDX		#$02
		LDY		#$00
		LDA		#$FF
loc_607EF:
		STA		(_tmp02),Y
		INY
		BNE		loc_607EF
		INC		_tmp03
		DEX
		BNE		loc_607EF
		LDX		#$0D
		LDY		#$10
loc_607FD:
		LDA		#$40
		STA		_room_map_buf,X
		STA		_room_map_buf+1,X
		TXA
		CLC
		ADC		#$10
		TAX
		DEY
		BNE		loc_607FD
		LDX		#$0D
		LDY		#$10
loc_60811:
		LDA		#$40
		STA		_room_map_buf+$100,X
		STA		_room_map_buf+$101,X
		TXA
		CLC
		ADC		#$10
		TAX
		DEY
		BNE		loc_60811
		LDX		#$00
loc_60823:
		LDA		#$40
		STA		_room_map_buf,X
		INX
		CPX		#$10
		BNE		loc_60823
		LDX		#$00
loc_6082F:
		LDA		#$40
		STA		_room_map_buf+$100,X
		INX
		CPX		#$10
		BNE		loc_6082F
		JSR		_objs_reset
		LDY		#$00
loc_6083E:
		LDA		_final_boss_enemy_dinamic_list,Y
		STA		_tmp00
		LDA		_final_boss_enemy_dinamic_list+1,Y
		STA		_tmp01
		LDA		_final_boss_enemy_dinamic_list+2,Y
		STA		_tmp02
		LDA		_final_boss_enemy_dinamic_list+3,Y
		STA		_tmp03
		LDA		_final_boss_enemy_dinamic_list+4,Y
		STA		_tmp04
		LDA		_final_boss_enemy_dinamic_list+5,Y
		STA		_tmp05
		JSR		_obj_lib_insert
		INY
		INY
		INY
		INY
		INY
		INY
		CPY		#$24
		BNE		loc_6083E
		LDX		#$0B
		LDA		#$20
		STA		_objsA._o3,X
		STA		_objsA._o4,X
		LDX		#$06
		LDA		_objsA._o1,X
		ORA		#$04
		STA		_objsA._o1,X
		LDA		_objsA._o2,X
		ORA		#$04
		STA		_objsA._o2,X
		LDA		#$28
		STA		_final_boss_deploy_delay_timer
		LDA		#$0F
		STA		_cur_pal_bg_idx
		LDA		#$0A
		STA		_cur_pal_spr_lib
		LDA		#$00
		STA		_final_boss_scroll_pos
		LDA		#$00
		STA		_room_scroll_pos_x
		STA		_room_scroll_pos_x+1
		LDA		#$1D
		STA		_spr_buf
		LDA		#$FF
		STA		_spr_buf+1
		LDA		#$00
		STA		_spr_buf+2
		LDA		#$00
		STA		_spr_buf+3
		RTS
; ---------------------------------------------------------------------------
_final_boss_pak_tlm:
		.BYTE $11,$21,$40,$0E
		.BYTE $36,$21,$50,$03
		.BYTE $56,$21,$53,$05
		.BYTE $76,$21,$58,$04
		.BYTE $93,$21,$5C,$0A
		.BYTE $B2,$21,$66,$0D
		.BYTE $D1,$21,$73,$0C
		.BYTE $DD,$21,$4E,$02
_final_boss_enemy_dinamic_list:
		.BYTE $00,$00,$78,$A0,$00,$00
		.BYTE $24,$00,$F0,$40,$10,$00
		.BYTE $26,$00,$08,$40,$20,$0F
		.BYTE $15,$00,$88,$68,$30,$00
		.BYTE $15,$00,$F0,$68,$40,$00

; =============== S U B	R O U T	I N E =======================================
_hud_icons_redraw:
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDX		#$40
		LDA		#$15
loc_608FF:
		STA		_PPU_DATA
		DEX
		BNE		loc_608FF
		LDX		#$00
loc_60907:
		LDA		_hud_icons_tlm,X
		CMP		#$FF
		BEQ		loc_60915
		STA		_PPU_DATA
		INX
		JMP		loc_60907
loc_60915:
		LDA		#$24
		STA		_PPU_DATA
		LDX		#$1F
		LDA		#$15
loc_6091E:
		STA		_PPU_DATA
		DEX
		BNE		loc_6091E
		LDA		_PPU_STATUS
		LDA		#$23
		STA		_PPU_ADDR
		LDA		#$C0
		STA		_PPU_ADDR
		LDX		#$08
		LDA		#$FF
loc_60935:
		STA		_PPU_DATA
		DEX
		BNE		loc_60935
		LDA		_PPU_STATUS
		LDA		#$24
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDX		#$80
		LDA		#$15
loc_6094C:
		STA		_PPU_DATA
		DEX
		BNE		loc_6094C
		LDA		_PPU_STATUS
		LDA		#$27
		STA		_PPU_ADDR
		LDA		#$C0
		STA		_PPU_ADDR
		LDX		#$08
		LDA		#$FF
loc_60963:
		STA		_PPU_DATA
		DEX
		BNE		loc_60963
		RTS
; ---------------------------------------------------------------------------
_hud_icons_tlm:
		.BYTE $15,$0C,$0D,$0E,$0F,$15,$10,$11,$12,$13,$14,$16,$17,$15,$18,$19
		.BYTE $15,$1A,$1B,$15,$1C,$1D,$15,$1E,$1F,$15,$20,$21,$15,$22,$23,$15
		.BYTE $FF

; =============== S U B	R O U T	I N E =======================================
_blank_screen:
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDY		#$20
		LDA		#$0F
loc_6099C:
		STA		_PPU_DATA
		DEY
		BNE		loc_6099C
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		RTS

; =============== S U B	R O U T	I N E =======================================
_stage_objs_insert_manager:
		JSR		_objs_reset
		JSR		_stage_obj_lib_insertA
		LDA		#$07
		STA		_tmp0A
		LDA		#$10
		STA		_tmp04
		LDA		_game._scr_idx
		LSR
		LSR
		LSR
		LSR
		STA		_tmp0D
		LDA		_game._scr_idx
		ASL
		ASL
		ASL
		ASL
		CLC
		ADC		#<[_stage_obj_list+2]
		STA		_tmp0B
		LDA		_tmp0D
		ADC		#>[_stage_obj_list+2]
		STA		_tmp0C
		LDY		#$00
loc_609E1:
		LDA		(_tmp0B),Y
		BEQ		locret_60A23
		LDA		(_tmp0B),Y
		AND		#$F0
		STA		_tmp02
		LDA		(_tmp0B),Y
		AND		#$0F
		ASL
		ASL
		ASL
		ASL
		STA		_tmp03
		INY
		LDA		(_tmp0B),Y
		AND		#$3F
		STA		_tmp00
		LDA		(_tmp0B),Y
		ROL
		ROL
		ROL
		AND		#$03
		STA		_tmp01
		LDA		#$00
		STA		_tmp05
		LDA		_tmp0A
		CMP		#$07
		BNE		loc_60A14
		LDA		_cur_loc_prize_idx
		STA		_tmp05
loc_60A14:
		JSR		_obj_lib_insert
		LDA		_tmp04
		CLC
		ADC		#$10
		STA		_tmp04
		INY
		DEC		_tmp0A
		BNE		loc_609E1
locret_60A23:
		RTS

; =============== S U B	R O U T	I N E =======================================
_stage_obj_lib_insertA:
		LDA		_game._scr_idx
		LSR
		LSR
		LSR
		LSR
		STA		_tmp0D
		LDA		_game._scr_idx
		ASL
		ASL
		ASL
		ASL
		CLC
		ADC		#<[_stage_obj_list]
		STA		_tmp0B
		LDA		_tmp0D
		ADC		#>[_stage_obj_list]
		STA		_tmp0C
		LDY		#$00
		LDA		(_tmp0B),Y
		AND		#$F0
		LSR
		STA		_tmp02
		LDA		(_tmp0B),Y
		AND		#$0F
		ASL
		ASL
		ASL
		STA		_tmp03
		INY
		LDA		(_tmp0B),Y
		AND		#$3F
		STA		_tmp00
		LDA		(_tmp0B),Y
		ROL
		ROL
		ROL
		AND		#$03
		STA		_tmp01
		LDA		#$00
		STA		_tmp04
		JMP		_obj_lib_insert

; =============== S U B	R O U T	I N E =======================================
_obj_lib_insert:
		TYA
		PHA
		LDA		_tmp00
		ASL
		ASL
		ASL
		PHA
		LDA		#$00
		ADC		#$00
		STA		_tmp07
		PLA
		CLC
		ADC		#<[_obj_params_lib]
		STA		_tmp06
		LDA		_tmp07
		ADC		#>[_obj_params_lib]
		STA		_tmp07
		LDA		_tmp04
		CLC
		ADC		#_objsA
		TAX
		LDY		#$00
		LDA		_tmp00
		STA		_tobjA._hndl_idx,X
		LDA		(_tmp06),Y
		STA		_tobjA._anim_phase_idx,X
		INY
		LDA		_tmp02
		BEQ		loc_60AD9
		STA		_tobjA._x_pos,X
		LDA		_tmp03
		STA		_tobjA._y_pos,X
		LDA		_tmp01
		STA		_tobjA._room_num,X
		LDA		#$00
		STA		_tobjA._dir,X
		LDA		(_tmp06),Y
		STA		_tobjA.field_7,X
		INY
		LDA		(_tmp06),Y
		STA		_tobjA.field_8,X
		INY
		LDA		(_tmp06),Y
		STA		_tobjA.field_9,X
		INY
		LDA		(_tmp06),Y
		STA		_tobjA._damage,X
		INY
		LDA		(_tmp06),Y
		STA		_tobjA.field_C,X
		INY
		LDA		#$00
		STA		_tobjA._state,X
		STA		_tobjA._anim_phase_cnt,X
		LDA		(_tmp06),Y
		STA		_tobjA._prize_idx,X
		LDA		_tmp05
		BEQ		loc_60AD5
		LDA		_tobjA._prize_idx,X
		AND		#$80
		ORA		_tmp05
		STA		_tobjA._prize_idx,X
loc_60AD5:
		LDA		#$05
		STA		_tobjA._timer,X
loc_60AD9:
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_chr_bg_tiles_load:
		LDA		_game._scr_idx			; check what kind of tiles needed
		BPL		loc_60AF4				; <$80 are level room tiles
		CMP		#$FF
		BNE		loc_60AEA				; >$80 are dialog cutscenes tiles
		LDA		#$09
		BNE		loc_60AF9				; $FF is a special tiles for BOSS
loc_60AEA:
;		AND		#$7F					; cutscene bg tiles in additional lookup
;		TAY								; able
;		LDA		_cutscene_chr_list,Y
;		BNE		loc_60AF7
		LDA		#$08					; note, all low nibble
		BNE		loc_60AF9				; here is $08, no need to fetch this
loc_60AF4:
		LDA		_cur_level_chr_idx
;loc_60AF7:
		AND		#$0F
loc_60AF9:
		ASL
		ASL
		ASL
		ASL
		CLC
		ADC		#<[_chr_bg_table_lib]
		STA		_tmp0E
		LDA		#$00
		ADC		#>[_chr_bg_table_lib]
		STA		_tmp0F
		LDY		#$00					; actually is #<[_chr_bg_data]
		STY		_tmp02					; but by the fact is $00
		LDA		_PPU_STATUS
		LDA		#$10
		STA		_PPU_ADDR
		STY		_PPU_ADDR
		LDX		#$10
loc_60B1D:
		LDA		(_tmp0E),Y
		CLC
		ADC		#$80					; actually is #>[_chr_bg_data]
		STA		_tmp03					; but by the fac is $80
		LDA		#$02
		JSR		_mmc_prg_set
		TYA
		PHA
		LDY		#$00
loc_60B30:
		LDA		(_tmp02),Y
		STA		_PPU_DATA
		INY
		BNE		loc_60B30
		PLA
		TAY
		LDA		#$06
		JSR		_mmc_prg_set
		INY
		DEX
		BNE		loc_60B1D
		RTS

; =============== S U B	R O U T	I N E =======================================
_chr_spr_tiles_load:
		LDA		_game._scr_idx
		BPL		loc_60B67
		CMP		#$FF
		BNE		loc_60B5D
		LDA		#<[_chr_spr_table_lib+256]
		STA		_tmp0E
		LDA		#>[_chr_spr_table_lib+256]
		STA		_tmp0F
		JMP		loc_60B77
loc_60B5D:
		AND		#$7F
		TAY
		LDA		_cutscene_chr_list,Y
		BNE		loc_60B6A
loc_60B67:
		LDA		_cur_level_chr_idx
loc_60B6A:
		AND		#$F0
		CLC
		ADC		#<[_chr_spr_table_lib]
		STA		_tmp0E
		LDA		#$00
		ADC		#>[_chr_spr_table_lib]
		STA		_tmp0F
loc_60B77:
		LDY		#$00				; actually is #<[_chr_spr_data]
		STY		_tmp02				; but by the fact is $00
		LDA		_PPU_STATUS
		STY		_PPU_ADDR
		STY		_PPU_ADDR
		LDX		#$10
loc_60B8C:
		LDA		#$03
		STA		_cur_prg_bank
		LDA		(_tmp0E),Y
		CMP		#$40
		BCC		loc_60B9D
		INC		_cur_prg_bank
		SEC
		SBC		#$40
loc_60B9D:
		CLC
		ADC		#$80				; actually is #>[_chr_spr_data]
		STA		_tmp03				; but by the fact is $00
		JSR		_mmc_prg
		TYA
		PHA
		LDY		#$00
loc_60BA9:
		LDA		(_tmp02),Y
		STA		_PPU_DATA
		INY
		BNE		loc_60BA9
		PLA
		TAY
		LDA		#$06
		JSR		_mmc_prg_set
		INY
		DEX
		BNE		loc_60B8C
		RTS

; =============== S U B	R O U T	I N E =======================================
_level_room_data_unpack:
		LDA		#$00
		STA		_cur_prg_bank
		LDA		_cur_loc_room_idx_and_stop_flags
		AND		#$3F
		CMP		#$20
		BCC		loc_60BD4
		SEC
		SBC		#$20
		INC		_cur_prg_bank
loc_60BD4:
		STA		_tmp09
		JSR		_mmc_prg
		LDA		_tmp09
		ASL
		TAY
		LDA		_location_room_map_libA,Y
		STA		_tmp0C
		LDA		_location_room_map_libA+1,Y
		STA		_tmp0D
		LDA		_location_room_attr_libA,Y
		STA		_tmp0A
		LDA		_location_room_attr_libA+1,Y
		STA		_tmp0B
		LDA		_cur_loc_room_idx_and_stop_flags
		AND		#$C0
		STA		_tmp03
		JSR		_room_nt_data_unpack
		JSR		_room_attr_data_unpack
		LDA		#$06
		JSR		_mmc_prg_set
		LDA		_tmp03
		BEQ		loc_60C0D
		JSR		_room_map_w_e_exits_disable
loc_60C0D:
		LDA		_cur_loc_warpA_pos
		STA		_tmp03
		AND		#$80
		BEQ		locret_60C19
		JSR		_room_map_warps_insert
locret_60C19:
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_nt_data_unpack:
		LDA		#<[_room_map_buf]
		STA		_tmp0E
		LDA		#>[_room_map_buf]
		STA		_tmp0F
		LDA		#$00
		STA		_tmp01
		LDX		#$00
loc_60C28:
		INC		_tmp0E
		INC		_tmp0E
loc_60C2C:
		JSR		_room_nt_chunk_fetch
		STA		(_tmp0E,X)
		INC		_tmp0E
		LDA		_tmp0E
		AND		#$0F
		CMP		#$0F
		BNE		loc_60C2C
		INC		_tmp0E
		BNE		loc_60C28
		INC		_tmp0F
		LDA		_tmp0F
		CMP		#$07
		BNE		loc_60C28
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_nt_chunk_fetch:
		LDA		_tmp01
		BEQ		loc_60C51
		DEC		_tmp01
		LDA		_tmp04
		RTS
loc_60C51:
		LDY		#$00
		LDA		(_tmp0C),Y
		PHA
		AND		#$03
		STA		_tmp01
		INC		_tmp0C
		BNE		loc_60C60
		INC		_tmp0D
loc_60C60:
		PLA
		AND		#$FC
		STA		_tmp04
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_attr_data_unpack:
		LDX		#$00
		LDY		#$00
loc_60C6A:
		LDA		(_tmp0A),Y
		BEQ		locret_60C9A
		LSR
		LSR
		LSR
		LSR
		AND		#$0F
		STA		_tmp01
		LDA		(_tmp0A),Y
		AND		#$0F
		STA		_tmp02
		INY
		LDA		(_tmp0A),Y
loc_60C7F:
		STA		(_tmp0E,X)
		INC		_tmp0E
		DEC		_tmp01
		BNE		loc_60C7F
		LDA		_tmp02
		BEQ		locret_60C9A
		INY
		LDA		(_tmp0A),Y
loc_60C8E:
		STA		(_tmp0E,X)
		INC		_tmp0E
		DEC		_tmp02
		BNE		loc_60C8E
		INY
		JMP		loc_60C6A
locret_60C9A:
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_map_w_e_exits_disable:
		LDA		_tmp03
		AND		#$40
		BEQ		loc_60CB7
		LDA		#<[_room_map_buf]
		STA		_tmp0E
		LDA		#>[_room_map_buf]
		STA		_tmp0F
		JSR		_room_map_blank_nt_fill
		LDA		#<[_room_attr_buf]
		STA		_tmp0E
		LDA		#>[_room_attr_buf]
		STA		_tmp0F
		JSR		_room_map_blank_attr_fill
loc_60CB7:
		LDA		_tmp03
		AND		#$80
		BNE		loc_60CBE
		RTS
loc_60CBE:
		LDA		#<[_room_map_buf+$3E0]
		STA		_tmp0E
		LDA		#>[_room_map_buf+$3E0]
		STA		_tmp0F
		JSR		_room_map_blank_nt_fill
		LDA		#<[_room_attr_buf+$AF]
		STA		_tmp0E
		LDA		#>[_room_attr_buf+$AF]
		STA		_tmp0F
		JMP		_room_map_blank_attr_fill

; =============== S U B	R O U T	I N E =======================================
_room_map_blank_nt_fill:
		LDX		#$02
		LDY		#$02
loc_60CD9:
		LDA		#$2C
		STA		(_tmp0E),Y
		INY
		TYA
		AND		#$0F
		CMP		#$0F
		BNE		loc_60CD9
		INY
		INY
		INY
		DEX
		BNE		loc_60CD9
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_map_blank_attr_fill:
		LDY		#$00
		LDX		#$07
loc_60CF0:
		LDA		#$FF
		STA		(_tmp0E),Y
		LDA		_tmp0E
		CLC
		ADC		#$08
		STA		_tmp0E
		BCC		loc_60CFF
		INC		_tmp0F
loc_60CFF:
		DEX
		BNE		loc_60CF0
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_map_warps_insert:
		JSR		_room_warp_insert
		LDA		_cur_loc_warpB_pos
		STA		_tmp03
		AND		#$80
		BEQ		locret_60D12
		JSR		_room_warp_insert
locret_60D12:
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_warp_insert:
		LDA		_tmp03
		AND		#$30
		LSR
		LSR
		LSR
		LSR
		JSR		_room_warp_pos_calc
		LDY		#$00
		LDX		#$30
		LDA		_tmp03
		AND		#$40
		BEQ		loc_60D2C
		INX
		INX
		INX
		INX
loc_60D2C:
		TXA
		STA		(_tmp0E),Y
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_warp_pos_calc:
		CLC
		ADC		#$03
		STA		_tmp0F
		LDA		_tmp03
		AND		#$0F
		CLC
		ADC		#$80
		ADC		#$00
		STA		_tmp0E
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_data_send_to_vram:
		JSR		_room_scroll_to_rom_calc
		JSR		_room_scroll_to_ppu_calc
		LDA		_ppu_ctrl_shadow
		ORA		#$04
		STA		_PPU_CTRL
		JSR		_room_tlm_send_to_vram
		JSR		_room_attrs_send_to_vram
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_scroll_to_rom_calc:
		JSR		_room_scroll_to_ppu_ofs_calc

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_room_scroll_to_rom_ptr_calc:
		LDA		_tmp0E
		AND		#$F0
		STA		_tmp01
		LDA		_tmp0F
		AND		#$03
		CLC
		ADC		#>[_room_map_buf]
		STA		_tmp02
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_scroll_to_ppu_calc:
		JSR		_room_scroll_to_ppu_ofs_calc

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_room_scroll_to_ppu_ptr_calc:
		LDA		_tmp0F
		AND		#$01
		BEQ		loc_60D79
		LDA		#$24
; ---------------------------------------------------------------------------
		.BYTE $2C
; ---------------------------------------------------------------------------
loc_60D79:
		LDA		#$20
		STA		_tmp04
		LDA		_tmp0E
		LSR
		LSR
		LSR
		CLC
		ADC		#$80
		STA		_tmp03
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_tlm_send_to_vram:
		LDX		#$00
		LDA		#$01
		STA		_tmp05
loc_60D8E:
		LDA		_tmp05
		EOR		#$01
		STA		_tmp05
		LDA		_PPU_STATUS
		LDA		_tmp04
		STA		_PPU_ADDR
		LDA		_tmp03
		STA		_PPU_ADDR
		LDY		#$02
loc_60DA3:
		JSR		_room_tlm_fetch_macro
		STA		_PPU_DATA
		JSR		_room_tlm_fetch_macro
		STA		_PPU_DATA
		INY
		CPY		#$0F
		BNE		loc_60DA3
		LDA		_tmp05
		AND		#$01
		BEQ		loc_60DC5
		LDA		_tmp01
		CLC
		ADC		#$10
		STA		_tmp01
		LDA		_tmp02
		ADC		#$00
		CMP		#>[_room_map_buf+[256*4]]
		BNE		loc_60DC4
		LDA		#>[_room_map_buf]
loc_60DC4:
		STA		_tmp02
loc_60DC5:
		INC		_tmp03
		LDA		_tmp03
		CMP		#$A0
		BNE		loc_60DD7
		LDA		_tmp04
		EOR		#$04
		STA		_tmp04
		LDA		#$80
		STA		_tmp03
loc_60DD7:
		INX
		CPX		#$2E
		BNE		loc_60D8E
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_attrs_send_to_vram:
		JSR		_room_scroll_to_ppu_ofs_calc
		LDA		#$0A
		STA		_tmp00
loc_60DE4:
		JSR		_room_attr_block_send
		LDA		_tmp0E
		CLC
		ADC		#$20
		STA		_tmp0E
		LDA		_tmp0F
		ADC		#$00
		AND		#$03
		STA		_tmp0F
		DEC		_tmp00
		BNE		loc_60DE4
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_attr_block_send:
		JSR		_calc_room_attr_ofs
		LDX		#$00
		LDY		#$00
loc_60E00:
		LDA		_PPU_STATUS
		LDA		_tmp04
		STA		_PPU_ADDR
		LDA		_tmp03
		STA		_PPU_ADDR
		LDA		(_tmp01),Y
		STA		_PPU_DATA
		LDA		_tmp03
		CLC
		ADC		#$08
		STA		_tmp03
		LDA		_tmp01
		CLC
		ADC		#$08
		STA		_tmp01
		BCC		loc_60E01
		INC		_tmp02
loc_60E01:
		INX
		CPX		#$07
		BNE		loc_60E00
		RTS

; =============== S U B	R O U T	I N E =======================================
_calc_room_attr_ofs:
		LDA		_tmp0F
		ASL
		TAX
		LDA		off_60E61,X
		STA		_tmp01
		LDA		off_60E61+1,X
		STA		_tmp02
		LDA		_tmp0E
		LSR
		LSR
		LSR
		LSR
		LSR
		PHA
		CLC
		ADC		_tmp01
		STA		_tmp01
		BCC		loc_60E55
		INC		_tmp02
loc_60E55:
		LDA		_tmp0F
		AND		#$01
		BEQ		loc_60E56
		LDA		#$27
; ---------------------------------------------------------------------------
		.BYTE $2C
; ---------------------------------------------------------------------------
loc_60E56:
		LDA		#$23
		STA		_tmp04
		PLA
		CLC
		ADC		#$C8
		STA		_tmp03
		RTS
; ---------------------------------------------------------------------------
off_60E61:
		.WORD _room_attr_buf
		.WORD _room_attr_buf+$38
		.WORD _room_attr_buf+$70
		.WORD _room_attr_buf+$A8

; =============== S U B	R O U T	I N E =======================================
_room_tlm_fetch_macro:
		LDA		(_tmp01),Y
		CLC
		ADC		_tmp05
		PHA
		LDA		_tmp05
		EOR		#$02
		STA		_tmp05
		PLA
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_scroll_to_ppu_ofs_calc:
		LDA		_room_scroll_pos_x
		AND		#$E0
		SEC
		SBC		#$20
		STA		_tmp0E
		BCC		loc_60E89
		LDA		_room_scroll_pos_x+1
		STA		_tmp0F
		RTS
loc_60E89:
		LDA		_room_scroll_pos_x+1
		STA		_tmp0F
		BEQ		loc_60E93
		DEC		_tmp0F
		RTS
loc_60E93:
		LDA		#$00
		STA		_tmp0E
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_macro_handler:
		LDA		_game._scr_idx
		CMP		#$FF
		BEQ		locret_60EAC
		LDA		_cur_player_pos_x_delta
		AND		#$0F
		STA		_tmp05
		BEQ		locret_60EAC
		CMP		#$09
		BCC		loc_60EAD
locret_60EAC:
		RTS
loc_60EAD:
		LDA		_room_scroll_pos_x
		AND		#$1F
		CMP		#$10
		BCC		loc_60EC1
		JSR		_room_macro_queue
		LDA		#$02
		STA		_ppu_dequeue_idx
		BNE		loc_60EC9
loc_60EC1:
		JSR		_room_macro_adjust
		LDA		#$01
		STA		_ppu_dequeue_idx
loc_60EC9:
		BIT		_cur_player_pos_x_delta
		BPL		loc_60EF1
		LDA		_tmp05
		CLC
		ADC		_room_scroll_pos_x
		STA		_room_scroll_pos_x
		LDA		_room_scroll_pos_x+1
		ADC		#$00
		STA		_room_scroll_pos_x+1
		CMP		#$03
		BNE		locret_60EF0
		LDA		_tmp05
		SEC
		SBC		_room_scroll_pos_x
		STA		_tmp05
		LDA		#$00
		STA		_room_scroll_pos_x
locret_60EF0:
		RTS
loc_60EF1:
		LDA		_room_scroll_pos_x
		SEC
		SBC		_tmp05
		STA		_room_scroll_pos_x
		LDA		_room_scroll_pos_x+1
		SBC		#$00
		STA		_room_scroll_pos_x+1
		LDA		_room_scroll_pos_x+1
		BPL		locret_60F17
		LDA		_tmp05
		SEC
		SBC		_room_scroll_pos_x
		STA		_tmp05
		LDA		#$00
		STA		_room_scroll_pos_x+1
		STA		_room_scroll_pos_x
locret_60F17:
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_macro_adjust:
		JSR		_calc_room_nt_ofs
		LDA		_tmp0E
		PHA
		LDA		_tmp0F
		PHA
		JSR		_room_scroll_to_rom_ptr_calc
		LDA		_tmp01
		CLC
		ADC		#$02
		STA		_ppu_room_line_ptr
		LDA		_tmp02
		STA		_ppu_room_line_ptr+1
		PLA
		STA		_tmp0F
		PLA
		STA		_tmp0E
		JSR		_room_scroll_to_ppu_ptr_calc
		LDA		_tmp04
		STA		_ppu_room_line_pos
		LDA		_tmp03
		STA		_ppu_room_line_pos+1
		RTS

; =============== S U B	R O U T	I N E =======================================
_calc_room_nt_ofs:
		BIT		_cur_player_pos_x_delta
		BPL		loc_60F5A
		LDA		_room_scroll_pos_x
		AND		#$E0
		CLC
		ADC		#$20
		STA		_tmp0E
		LDA		_room_scroll_pos_x+1
		ADC		#$01
		AND		#$03
		STA		_tmp0F
		JMP		loc_60F6B
loc_60F5A:
		LDA		_room_scroll_pos_x
		AND		#$E0
		SEC
		SBC		#$20
		STA		_tmp0E
		LDA		_room_scroll_pos_x+1
		SBC		#$00
		AND		#$03
		STA		_tmp0F
loc_60F6B:
		LDA		_room_scroll_pos_x
		AND		#$1F
		CMP		#$08
		BCS		locret_60F7B
		LDA		_tmp0E
		CLC
		ADC		#$10
		STA		_tmp0E
locret_60F7B:
		RTS

; =============== S U B	R O U T	I N E =======================================
_room_macro_queue:
		JSR		_calc_room_nt_ofs
		LDA		_tmp0E
		AND		#$E0
		STA		_tmp0E
		JSR		_calc_room_attr_ofs
		LDA		#$07
		STA		_tmp00
		LDY		#$00
loc_60F8E:
		LDA		_tmp04
		STA		(_ppu_queue_buf_ofs),Y
		INC		_ppu_queue_buf_ofs
		LDA		_tmp03
		STA		(_ppu_queue_buf_ofs),Y
		INC		_ppu_queue_buf_ofs
		LDA		(_tmp01),Y
		STA		(_ppu_queue_buf_ofs),Y
		INC		_ppu_queue_buf_ofs
		LDA		_tmp03
		CLC
		ADC		#$08
		STA		_tmp03
		BCC		loc_60F8F
		INC		_tmp04
loc_60F8F:
		LDA		_tmp01
		CLC
		ADC		#$08
		STA		_tmp01
		BCC		loc_60F90
		INC		_tmp02
loc_60F90:
		DEC		_tmp00
		BNE		loc_60F8E
		LDA		#$00
		STA		(_ppu_queue_buf_ofs),Y
		RTS

; =============== S U B	R O U T	I N E =======================================
_collision_test_subA:
		STA		_tmp07
		LDA		_tmp00
		PHA
		LDA		_tmp01
		PHA
		STX		_tmp0A
		STY		_tmp0B
		LDA		_tmp0A
		AND		#$F8
		STA		_tmp0A
		LDA		_tmp0B
		AND		#$F8
		STA		_tmp0B
		LDA		_tmp16
		STA		_tmp08
		BEQ		loc_60FEA
		LDA		_tmp17
		STA		_tmp09
		BNE		loc_60FF7
loc_60FEA:
		LDA		#$00
		STA		_tmp16
		STA		_tmp17
		STA		_tmp18
		STA		_ppu_room_line_pos
		JMP		loc_6112F
loc_60FF7:
		LDA		#$FF
		STA		_tmp16
		STA		_tmp17
		STA		_tmp18
		STA		_ppu_room_line_pos
		LDA		_tmp07
		BPL		loc_6101E
		AND		#$7F
		STA		_tmp07
		LDA		_tmp08
		ASL
		ASL
		ASL
		SEC
		SBC		#$08
		STA		_tmp05
		LDA		_tmp0A
		SEC
		SBC		_tmp05
		STA		_tmp0A
		BCS		loc_6101E
		DEC		_tmp07
loc_6101E:
		LDA		_tmp0A
		AND		#$0F
		STA		_tmp03
		LDA		_tmp0B
		AND		#$0F
		STA		_tmp04
		LDA		_tmp08
		LDY		_tmp03
		LDX		#$00
		JSR		_coll_compare00
		LDA		_tmp09
		LDY		_tmp04
		LDX		#$01
		JSR		_coll_both
		LDA		_tmp0A
		AND		#$F0
		CLC
		ADC		#$00
		STA		_tmp0E
		LDA		_tmp07
		ADC		#$03
		STA		_tmp0F
		LDA		_tmp0B
		CMP		#$20
		BCC		loc_60FEA
loc_61054:
		LSR
		LSR
		LSR
		LSR
		CLC
		ADC		_tmp0E
		STA		_tmp0E
		LDA		#$00
		ADC		_tmp0F
		STA		_tmp0F
		LDA		_tmp0E
		STA		_tmp0C
		LDA		_tmp0F
		STA		_tmp0D
		LDA		#$80
		STA		_tmp06
		LDX		_tmp01
		JSR		_coll_look_for_macro
		LDA		_tmp05
		STA		_tmp17
		JSR		_coll_sub611A0
		CMP		#$03
		BEQ		loc_610AE
		CMP		#$01
		BEQ		loc_6109D
		CMP		#$02
		BEQ		loc_61094
		LDA		_tmp08
		AND		#$01
		BNE		loc_61094
		CPX		#$08
		BEQ		loc_61094
		JSR		_tmp0Cw_add10
loc_61094:
		CPY		#$08
		BEQ		loc_610AE
		DEC		_tmp0C
		JMP		loc_610AE
loc_6109D:
		LDA		_tmp08
		AND		#$01
		BEQ		loc_610A7
		CPX		#$00
		BEQ		loc_610AE
loc_610A7:
		CPX		#$08
		BEQ		loc_610AE
		JSR		_tmp0Cw_add10
loc_610AE:
		LDA		#$00
		STA		_tmp06
		LDX		_tmp02
		JSR		_coll_look_for_macro
		LDA		_tmp05
		STA		_ppu_room_line_pos
		LDA		_tmp0E
		STA		_tmp0C
		LDA		_tmp0F
		STA		_tmp0D
		JSR		_coll_sub611A0
		CMP		#$03
		BEQ		loc_610E9
		CMP		#$01
		BEQ		loc_610E2
		CMP		#$02
		BEQ		loc_610D9
		CPX		#$08
		BEQ		loc_610D9
		JSR		_tmp0Cw_sub10
loc_610D9:
		CPY		#$08
		BEQ		loc_610E9
		DEC		_tmp0C
		JMP		loc_610E9
loc_610E2:
		CPX		#$08
		BEQ		loc_610E9
		JSR		_tmp0Cw_sub10
loc_610E9:
		LDA		#$00
		STA		_tmp06
		LDX		_tmp02
		JSR		_coll_look_for_macro
		LDA		_tmp05
		STA		_tmp18
		JSR		_coll_sub611A0
		CMP		#$03
		BEQ		loc_61122
		CMP		#$02
		BEQ		loc_6110C
		CMP		#$01
		BEQ		loc_6111B
		CPX		#$08
		BEQ		loc_6110C
		JSR		_tmp0Cw_add10
loc_6110C:
		LDA		_tmp09
		AND		#$01
		BNE		loc_61122
		CPY		#$08
		BEQ		loc_61122
		DEC		_tmp0C
		JMP		loc_61122
loc_6111B:
		CPX		#$08
		BEQ		loc_61122
		JSR		_tmp0Cw_add10
loc_61122:
		LDA		#$80
		STA		_tmp06
		LDX		_tmp01
		JSR		_coll_look_for_macro
		LDA		_tmp05
		STA		_tmp16
loc_6112F:
		PLA
		STA		_tmp01
		PLA
		STA		_tmp00
		RTS

; =============== S U B	R O U T	I N E =======================================
_coll_compare00:
		CPY		#$00
		BNE		_coll_compare08

; =============== S U B	R O U T	I N E =======================================
_coll_div2:
		JSR		_div2A

; =============== S U B	R O U T	I N E =======================================
_coll_store:
		STA		_tmp01,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_coll_compare08:
		CPY		#$08
		BCS		_coll_div2A_adc

; =============== S U B	R O U T	I N E =======================================
_div2B:
		LSR

; =============== S U B	R O U T	I N E =======================================
_coll_adc:
		CLC
		ADC		#$01
		JMP		_coll_store

; =============== S U B	R O U T	I N E =======================================
_coll_div2A_adc:
		JSR		_div2A
		JMP		_coll_adc

; =============== S U B	R O U T	I N E =======================================
_coll_both:
		CPY		#$00
		BEQ		_coll_div2
		CPY		#$08
		BCC		_coll_div2A_adc
		JMP		_div2B

; =============== S U B	R O U T	I N E =======================================
_div2A:
		LSR
		TAY
		BCC		loc_61161
		INY
loc_61161:
		TYA
		RTS

; =============== S U B	R O U T	I N E =======================================
_coll_look_for_macro:
		LDY		#$00
		LDA		#$FF
		STA		_tmp05
loc_61169:
		LDA		(_tmp0C),Y
		CMP		_tmp05
		BCS		loc_61171
		STA		_tmp05
loc_61171:
		DEX
		BNE		loc_61175
		RTS
loc_61175:
		LDA		_tmp06
		BMI		loc_6117E
		DEC		_tmp0C
		JMP		loc_61169
loc_6117E:
		JSR		_tmp0Cw_add10
		JMP		loc_61169

; =============== S U B	R O U T	I N E =======================================
_tmp0Cw_sub10:
		SEC
		LDA		_tmp0C
		SBC		#$10
		STA		_tmp0C
		BCS		.sub10
		DEC		_tmp0D
.sub10:
		RTS

; =============== S U B	R O U T	I N E =======================================
_tmp0Cw_add10:
		CLC
		LDA		_tmp0C
		ADC		#$10
		STA		_tmp0C
		BCC		.add10
		INC		_tmp0D
.add10:
		RTS

; =============== S U B	R O U T	I N E =======================================
_coll_sub611A0:
		LDX		_tmp03
		LDY		_tmp04
		LDA		#$00
		CPX		#$00
		BEQ		loc_611C0
		CPX		#$08
		BEQ		loc_611C0
		CLC
		ADC		#$02
		CPY		#$00
		BEQ		locret_611BF
		CPY		#$08
		BEQ		locret_611BF
loc_611BC:
		CLC
		ADC		#$01
locret_611BF:
		RTS
loc_611C0:
		CPY		#$00
		BEQ		locret_611BF
		CPY		#$08
		BEQ		locret_611BF
		JMP		loc_611BC

; =============== S U B	R O U T	I N E =======================================
_game_values_to_decimal:
		JSR		_game_values_update
		LDY		#$00
		LDX		#$00
loc_611D6:
		LDA		_hud_decimal_values_length_list,X
		BEQ		loc_6121C
		CMP		#$01
		BEQ		loc_611FF
		LDA		_game._life,Y
		STA		_tmp00
		INY
		LDA		_game._life,Y
		STA		_tmp01
		JSR		_hex_to_dec
		LDA		_tmp05
		STA		_tmp07
		LDA		_tmp04
		STA		_tmp06
		JSR		_truncate
		STA		_hud_decimals_buf,X
		INX
		JMP		loc_6120B
loc_611FF:
		LDA		_game._life,Y
		STA		_tmp00
		LDA		#$00
		STA		_tmp01
		JSR		_hex_to_dec
loc_6120B:
		LDA		_tmp03
		STA		_tmp07
		LDA		_tmp02
		STA		_tmp06
		JSR		_truncate
		STA		_hud_decimals_buf,X
		JMP		loc_6122D
loc_6121C:
		LDA		_game._life,Y
		STA		_tmp00
		LDA		#$00
		STA		_tmp01
		JSR		_hex_to_dec
		LDA		_tmp02
		STA		_hud_decimals_buf,X
loc_6122D:
		INY
		INX
		CPX		#$0B
		BNE		loc_611D6
		RTS

; =============== S U B	R O U T	I N E =======================================
_truncate:
		LDA		_tmp07
		ASL
		ASL
		ASL
		ASL
		STA		_tmp07
		LDA		_tmp06
		AND		#$0F
		ORA		_tmp07
		RTS
; ---------------------------------------------------------------------------
_hud_decimal_values_length_list:
		.BYTE $02,$09,$02,$09,$00,$01,$01,$01,$01,$00,$00

; =============== S U B	R O U T	I N E =======================================
_game_values_update:
		LDA		_game._exp
		STA		_tmp00
		LDA		_game._exp+1
		STA		_tmp01
		LDA		_game._exp_level
		ASL
		TAY
		LDA		_next_exp_list,Y
		STA		_tmp02
		LDA		_next_exp_list+1,Y
		STA		_tmp03
		JSR		_cmp_tmp00w_tmp02w
		BCC		loc_61296
		LDA		#SEP03
		STA		_apu_se_pulse_idx
		INC		_game._exp_level
		LDA		_game._exp_level
		CMP		#$08
		BNE		loc_6128E
		LDA		#$07
		STA		_game._exp_level
		ASL
		TAY
		LDA		_max_life_list,Y
		STA		_game._life
		LDA		_max_life_list+1,Y
		STA		_game._life+1
loc_6128E:
		LDA		#$00
		STA		_game._exp
		STA		_game._exp+1
loc_61296:
		LDA		_game._life_level
		ASL
		TAY
		LDA		_game._life
		STA		_tmp00
		LDA		_game._life+1
		STA		_tmp01
		LDA		_max_life_list,Y
		STA		_tmp02
		LDA		_max_life_list+1,Y
		STA		_tmp03
		JSR		_cmp_tmp00w_tmp02w
		BCC		loc_612C0
		LDA		_max_life_list,Y
		STA		_game._life
		LDA		_max_life_list+1,Y
		STA		_game._life+1
loc_612C0:
		LDY		#$04
loc_612C2:
		LDA		_game._ammo_knife-1,Y
		CMP		#$63
		BCC		loc_612CE
		LDA		#$63
		STA		_game._ammo_knife-1,Y
loc_612CE:
		DEY
		BNE		loc_612C2
		LDY		#$02
loc_612D3:
		LDA		_game._ammo_grenades-1,Y
		CMP		#$09
		BCC		loc_612DF
		LDA		#$09
		STA		_game._ammo_grenades-1,Y
loc_612DF:
		DEY
		BNE		loc_612D3

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_secret_values_cheat_test:
		LDY		#$04
loc_612E4:
		LDA		_game._ammo_knife-1,Y		; all ammo values are 77
		CMP		#$4D
		BNE		loc_612F1
		DEY
		BNE		loc_612E4
		BEQ		loc_61302
loc_612F1:
		LDY		#$00						; or all values are
		LDA		#$01						; sequence 1 2 3 4 5 6
loc_612F5:
		CMP		_game._exp_level,Y
		BNE		locret_6131D
		TAX
		INX
		TXA
		INY
		CPY		#$06
		BNE		loc_612F5
loc_61302:
		LDA		#SEP03						; sound play
		STA		_apu_se_pulse_idx			; refill all to 99/9
		LDA		#$63
		STA		_game._ammo_knife
		STA		_game._ammo_spear
		STA		_game._ammo_spear_bomb
		STA		_game._ammo_gun
		LDA		#$09
		STA		_game._ammo_grenades
		STA		_game._potions
locret_6131D:
		RTS

; =============== S U B	R O U T	I N E =======================================
_cmp_tmp00w_tmp02w:
		LDA		_tmp01
		CMP		_tmp03
		BNE		locret_61328
		LDA		_tmp00
		CMP		_tmp02
locret_61328:
		RTS
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
_game_warps_handler:
		LDX		#$00
		LDA		_pad
		CMP		#$08
		BNE		loc_613B8
		LDA		_objsA._player._state
		AND		#$30
		BEQ		loc_613B8
		CMP		#$10
		BEQ		loc_613B8
		CMP		#$30
		BNE		loc_61362
		LDX		#$01
loc_61362:
		LDA		_objsA._player._room_num
		ASL
		ASL
		ASL
		ASL
		AND		#$30
		STA		_tmp0D
		LDY		#$02
		LDA		_cur_loc_warpA_pos
		AND		#$30
		CMP		_tmp0D
		BEQ		loc_61385
		LDY		#$03
		LDA		_cur_loc_warpB_pos
		AND		#$30
		CMP		_tmp0D
		BNE		loc_613DB
loc_61385:
		LDA		_objsA._player._room_num
		BNE		loc_6138D
		CPX		#$00
		BNE		loc_613DB
loc_6138D:
		LDA		_ppu_ctrl_shadow
		AND		#$7F
		STA		_PPU_CTRL
		LDA		_cur_pal_spr_lib
		ORA		#$F0
		STA		_cur_pal_spr_lib
		LDA		_cur_pal_bg_idx
		ORA		#$F0
		STA		_cur_pal_bg_idx
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
loc_613AB:
		LDA		_cur_pal_spr_lib
		ORA		_cur_pal_bg_idx
		AND		#$80
		BNE		loc_613AB
		BEQ		loc_61431
loc_613B8:
		LDA		_objsA._player._dir
		AND		#$40
		BEQ		loc_613CB
		LDA		_objsA._player._x_pos
		CMP		#$18
		BCC		loc_613E2
		CMP		#$F8
		BCS		loc_61403
		BCC		loc_613D5
loc_613CB:
		LDA		_objsA._player._x_pos
		CMP		#$08
		BCC		loc_613E2
		CMP		#$F0
		BCS		loc_61403
loc_613D5:
		LDA		_objsA._player._y_pos
		CMP		#$E7
		BCS		loc_61426
loc_613DB:
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		RTS
loc_613E2:
		LDA		_objsA._player._room_num
		BNE		loc_613DB
		LDA		_ppu_ctrl_shadow
		AND		#$7F
		STA		_PPU_CTRL
		LDA		#$03
		STA		_room_scroll_pos_x+1
		STA		_objsA._player._room_num
		LDA		#$00
		STA		_room_scroll_pos_x
		LDA		#$E8
		STA		_objsA._player._x_pos
		LDY		#$00
		BEQ		loc_61431
loc_61403:
		LDA		_objsA._player._room_num
		CMP		#$03
		BNE		loc_613DB
		LDA		_ppu_ctrl_shadow
		AND		#$7F
		STA		_PPU_CTRL
		LDA		#$00
		STA		_room_scroll_pos_x+1
		STA		_objsA._player._room_num
		LDA		#$00
		STA		_room_scroll_pos_x
		LDA		#$20
		STA		_objsA._player._x_pos
		LDY		#$01
		BNE		loc_61431
loc_61426:
		LDA		_cur_loc_warpB_pos
		BNE		loc_613DB
		LDA		#$28
		STA		_objsA._player._y_pos
		LDY		#$03
loc_61431:
		LDA		_game._scr_idx
		ASL
		ASL
		PHA
		LDA		#$00
		ADC		#>[_game_warp_map]
		STA		_tmp0F
		PLA
		CLC
		ADC		#<[_game_warp_map]
		STA		_tmp0E
		LDA		#$00
		ADC		_tmp0F
		STA		_tmp0F
		LDA		(_tmp0E),Y
		BNE		loc_61451
		CPX		#$00
		BNE		loc_613DB
loc_61451:
		STA		_game._scr_idx
		JSR		_spr_clear
		LDA		_ppu_ctrl_shadow
		AND		#$7F
		STA		_PPU_CTRL
		LDA		#$00
		STA		_ppu_mask_shadow
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		LDA		_nmi_flag
		STA		_tmp0C
loc_6146F:
		LDA		_nmi_flag
		CMP		_tmp0C
		BEQ		loc_6146F
		JSR		_blank_screen
		LDA		#$FF
		STA		_game._redraw_req
		JMP		loc_613DB

; =============== S U B	R O U T	I N E =======================================
_obj_collision_testA:
		LDA		#$08
		STA		_tmp13
		LDA		#$20
		STA		_tmp14
loc_61489:
		LDX		_tmp14
		LDA		_tobjA._state,X
		AND		#$00
		STA		_tobjA._state,X
		LDA		_tobjA,X
		BMI		loc_614FD
		LDA		_tobjA.field_7,X
		BPL		loc_614FD
		LDA		_tobjA._anim_phase_cnt,X
		BEQ		loc_614FD
		LDA		_tobjA.field_9,X
		AND		#$0F
		TAY
		LDA		_obj_collision_tableA,Y
		AND		#$0F
		STA		_tmp17
		LDA		_obj_collision_tableA,Y
		LSR
		LSR
		LSR
		LSR
		STA		_tmp16
		LDA		_tobjA._y_pos,X
		CMP		#$20
		BCC		loc_614C2
		SEC
		SBC		#$20
		LSR
		LSR
		LSR
		CMP		_tmp17
		BCS		loc_614D6
loc_614C2:
		LDA		_tobjA._dir,X
		AND		#$40
		BEQ		loc_614CF
		LDA		#$0A
		STA		_tmp12
		BNE		loc_614F3
loc_614CF:
		LDA		#$09
		STA		_tmp12
		BNE		loc_614F3
loc_614D6:
		LDA		_tobjA._dir,X
		ASL
		AND		#$80
		STA		_tmp02
		LDA		_tobjA._room_num,X
		AND		#$03
		PHA
		LDA		_tobjA._x_pos,X
		PHA
		LDA		_tobjA._y_pos,X
		TAY
		PLA
		TAX
		PLA
		ORA		_tmp02
		JSR		_collision_test_subA
		JSR		_collision_test_subB
loc_614F3:
		LDX		_tmp14
		LDA		_tobjA._state,X
		AND		#$C0
		ORA		_tmp12
		STA		_tobjA._state,X
loc_614FD:
		LDA		_tmp14
		CLC
		ADC		#$10
		STA		_tmp14
		DEC		_tmp13
		BNE		loc_61489
		LDA		#$20
		STA		_tmp14
		LDX		_tmp14
		LDA		_tobjA._y_pos,X
		CMP		#$48
		BCS		loc_61517
		JMP		loc_615A6
loc_61517:
		LDA		_tobjA.field_8,X
		BMI		loc_6151E
		JMP		loc_615A6
loc_6151E:
		LDA		_tobjA._dir,X
		ASL
		AND		#$80
		STA		_tmp02
		LDA		_tobjA._room_num,X
		AND		#$03
		STA		_tmp13
		LDA		_tobjA.field_9,X
		AND		#$F0
		LSR
		LSR
		LSR
		TAY
		LDA		_tmp02
		BMI		loc_6154F
		LDA		_obj_collision_tableB,Y
		AND		#$F0
		LSR
		CLC
		ADC		_tobjA._x_pos,X
		STA		_tmp10
		BCC		loc_61567
		INC		_tmp13
		LDA		_tmp13
		CMP		#$04
		BCC		loc_61567
		BCS		loc_615A6
loc_6154F:
		LDA		_obj_collision_tableB,Y
		AND		#$F0
		LSR
		STA		_tmp10
		LDA		_tobjA._x_pos,X
		SEC
		SBC		_tmp10
		STA		_tmp10
		BCS		loc_61567
		DEC		_tmp13
		BMI		loc_615A6
loc_61567:
		LDA		_obj_collision_tableB,Y
		AND		#$0F
		ASL
		ASL
		ASL
		STA		_tmp11
		LDA		_tobjA._y_pos,X
		SEC
		SBC		_tmp11
		STA		_tmp11
		INC		_tmp11
		LDA		_obj_collision_tableB+1,Y
		LSR
		LSR
		LSR
		LSR
		STA		_tmp16
		STA		_tmp00
		LDA		_obj_collision_tableB+1,Y
		AND		#$0F
		STA		_tmp17
		STA		_tmp01
		LDA		_tmp10
		TAX
		LDA		_tmp11
		TAY
		LDA		_tmp13
		ORA		_tmp02
		JSR		_collision_test_subA
		JSR		_obj_to_room_collision_testA
		LDX		_tmp14
		LDA		_tobjA._state,X
		ORA		_tmp12
		STA		_tobjA._state,X
loc_615A6:
		LDA		#$0C
		STA		_tmp13
		LDA		#$A0
		STA		_tmp14
loc_615AE:
		LDX		_tmp14
		LDA		_tobjB,X
		BMI		loc_615FA
		LDA		_tobjB.field_4,X
		AND		#$F7
		STA		_tobjB.field_4,X
		LDA		_tobjB.field_6,X
		BEQ		loc_615FA
		LDA		_tobjB.field_4,X
		AND		#$30
		LSR
		LSR
		LSR
		LSR
		TAY
		LDA		_obj_collision_tableA,Y
		AND		#$0F
		STA		_tmp17
		LDA		_obj_collision_tableA,Y
		LSR
		LSR
		LSR
		LSR
		STA		_tmp16
		LDA		_tobjB.field_3,X
		CMP		#$20
		BCC		loc_615FA
		LDA		_tobjB.field_4,X
		ASL
		AND		#$80
		STA		_tmp02
		LDA		_tobjB.field_1,X
		AND		#$03
		PHA
		LDA		_tobjB.field_2,X
		PHA
		LDA		_tobjB.field_3,X
		TAY
		PLA
		TAX
		PLA
		ORA		_tmp02
		JSR		_collision_test_subA
		JSR		_collision_test_subC
loc_615FA:
		LDA		_tmp14
		CLC
		ADC		#$08
		STA		_tmp14
		DEC		_tmp13
		BNE		loc_615AE
		RTS

; =============== S U B	R O U T	I N E =======================================
_collision_test_subB:
		LDA		#$00
		STA		_tmp12
		LDX		_tmp14
		LDA		_tobjA._anim_phase_cnt,X
		AND		#$0F
		BEQ		loc_6164D
		LDA		_tobjA._dir,X
		BPL		loc_61638
		LDA		_tmp16
		CMP		#$59
		BCS		loc_6164D
		LDA		_tobjA._y_pos,X
		AND		#$0F
		BEQ		loc_6164D
		CMP		#$08
		BEQ		loc_6164D
		LDA		_tmp12
		ORA		#$08
		STA		_tmp12
		LDA		_tobjA._y_pos,X
		AND		#$F8
		CLC
		ADC		#$08
		STA		_tobjA._y_pos,X
		RTS
loc_61638:
		LDA		_tobjA._y_pos,X
		AND		#$0F
		BEQ		loc_6164D
		JSR		_obj_sub6169D
		LDA		_tmp12
		AND		#$04
		BEQ		loc_6164D
		LDA		_tobjA._y_pos,X
		AND		#$F0
		STA		_tobjA._y_pos,X
loc_6164D:
		LDX		_tmp14
		LDA		_tobjA._anim_phase_cnt,X
		AND		#$F0
		BEQ		loc_6168F
		LDA		_tobjA._dir,X
		AND		#$40
		BNE		loc_6166E
		LDA		_ppu_room_line_pos
		CMP		#$59
		BCS		loc_6168F
		LDA		#$01
		STA		_tmp12
		LDA		_tobjA._x_pos,X
		AND		#$F8
		STA		_tobjA._x_pos,X
		JMP		loc_6168F
loc_6166E:
		LDA		_tmp18
		CMP		#$59
		BCS		loc_6168F
		LDA		_tobjA._x_pos,X
		AND		#$0F
		BEQ		loc_6168F
		CMP		#$08
		BEQ		loc_6168F
		LDA		#$02
		STA		_tmp12
		LDA		_tobjA._x_pos,X
		AND		#$F8
		CLC
		ADC		#$08
		STA		_tobjA._x_pos,X
		BCC		loc_6168F
		INC		_tobjA._room_num,X
loc_6168F:
		LDA		_tobjA._anim_phase_cnt,X
		AND		#$0F
		BEQ		loc_61699
		LDA		_tobjA._dir,X
		BMI		locret_6169C
loc_61699:
		JSR		_obj_sub6169D
locret_6169C:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_sub6169D:
		LDX		_tmp14
		LDA		_tobjA.field_7,X
		AND		#$40
		BEQ		loc_616AF
		LDA		_tmp17
		CMP		#$70
		BCC		loc_616AF
		CMP		#$79
		BCC		loc_616B5
loc_616AF:
		LDA		_tmp17
		CMP		#$59
		BCS		loc_616BB
loc_616B5:
		LDA		_tmp12
		ORA		#$04
		STA		_tmp12
loc_616BB:
		JMP		_obj_sub616BF

; =============== S U B	R O U T	I N E =======================================
_obj_sub616BF:
		LDY		#$00
		LDA		#$30
		JSR		_obj_sub6170D
		BEQ		loc_616CF
		LDA		#$34
		JSR		_obj_sub6170D
		BNE		loc_616D4
loc_616CF:
		LDY		#$02
		BNE		loc_61703
loc_616D4:
		LDA		#$5C
		JSR		_obj_sub6170D
		BNE		loc_616E0
		LDY		#$01
		BNE		loc_61703
loc_616E0:
		LDA		#$60
		JSR		_obj_sub6170D
		BEQ		loc_61701
		LDA		#$64
		JSR		_obj_sub6170D
		BEQ		loc_61701
		LDA		#$68
		JSR		_obj_sub6170D
		BEQ		loc_61701
		LDA		#$6C
		JSR		_obj_sub6170D
		BEQ		loc_61701
		LDY		#$00
		BEQ		loc_61703
loc_61701:
		LDY		#$03
loc_61703:
		TYA
		ASL
		ASL
		ASL
		ASL
		ORA		_tmp12
		STA		_tmp12
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_sub6170D:
		CMP		_tmp17
		BEQ		locret_6171E
		CMP		_tmp16
		BEQ		locret_6171E
		CMP		_ppu_room_line_pos
		BEQ		locret_6171E
		CMP		_tmp18
locret_6171E:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_to_room_collision_testA:
		LDA		#$00
		STA		_tmp12
		LDX		_tmp14
		LDA		_tobjA._dir,X
		AND		#$40
		BNE		loc_6174C
		LDA		_ppu_room_line_pos
		CMP		#$59
		BCS		loc_6177B
		CMP		#$38
		BCC		loc_6173F
		CMP		#$3D
		BCS		loc_6173F
		JSR		_obj_to_room_projectile_collision_test
		JMP		loc_6177B
loc_6173F:
		LDA		#$01
		STA		_tmp12
		LDA		_tobjA._x_pos,X
		AND		#$F8
		STA		_tobjA._x_pos,X
		JMP		loc_6177B
loc_6174C:
		LDA		_tmp18
		CMP		#$59
		BCS		loc_6177B
		CMP		#$38
		BCC		loc_61760
		CMP		#$3D
		BCS		loc_61760
		JSR		_obj_to_room_projectile_collision_test
		JMP		loc_6177B
loc_61760:
		LDA		_tobjA._x_pos,X
		AND		#$0F
		BEQ		loc_6177B
		CMP		#$08
		BEQ		loc_6177B
		LDA		#$02
		STA		_tmp12
		LDA		_tobjA._x_pos,X
		AND		#$F8
		CLC
		ADC		#$08
		STA		_tobjA._x_pos,X
		BCC		loc_6177B
		INC		_tobjA._room_num,X
loc_6177B:
		LDA		_tobjA._dir,X
		BPL		loc_6179D
		LDA		_tmp16
		CMP		#$59
		BCS		locret_617AF
		LDA		_tobjA._y_pos,X
		AND		#$0F
		BEQ		locret_617AF
		LDA		_tmp12
		ORA		#$08
		STA		_tmp12
		LDA		_tobjA._y_pos,X
		AND		#$F8
		CLC
		ADC		#$08
		STA		_tobjA._y_pos,X
		RTS
loc_6179D:
		LDA		_tmp17
		CMP		#$59
		BCS		locret_617AF
		LDA		_tobjA._y_pos,X
		AND		#$0F
		BEQ		locret_617AF
		LDA		_tobjA._y_pos,X
		AND		#$F0
		STA		_tobjA._y_pos,X
locret_617AF:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_to_room_projectile_collision_test:
		TXA
		PHA
		TYA
		PHA
		LDA		_ppu_dequeue_idx
		BEQ		loc_617BC
		JMP		loc_618A5
loc_617BC:
		LDA		#$02
		STA		_ppu_dequeue_idx
		LDX		#_objsB._o4
		LDY		#$08
loc_617C5:
		LDA		_tobjB._hndl_idx,X
		BMI		loc_617D4
		TXA
		CLC
		ADC		#$08
		TAX
		DEY
		BNE		loc_617C5
		JMP		loc_618A5
loc_617D4:
		BIT		_objsA._player._dir
		BVS		loc_617E9
		LDA		_tmp00
		ASL
		ASL
		ASL
		CLC
		ADC		_tmp10
		STA		_tmp10
		BCC		loc_617FB
		INC		_tmp13
		JMP		loc_617FB
loc_617E9:
		LDA		_tmp00
		ASL
		ASL
		ASL
		STA		_tmp00
		LDA		_tmp10
		SEC
		SBC		_tmp00
		STA		_tmp10
		BCS		loc_617FB
		DEC		_tmp13
loc_617FB:
		LDA		_tmp10
		AND		#$F0
		STA		_tmp10
		STA		_tobjB.field_2,X
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
		CLC
		ADC		#$10
		STA		_tobjB.field_3,X
		LDA		_tmp13
		STA		_tobjB.field_1,X
		LDA		#$1E
		STA		_tobjB._hndl_idx,X
		LDA		#$00
		STA		_tobjB.field_4,X
		STA		_tobjB.field_5,X
		STA		_tobjB.field_7,X
		LDA		#$F2
		STA		_tobjB.field_6,X
		LDX		_ppu_room_line_pos
		BIT		_objsA._player._dir
		BVC		loc_6182A
		LDX		_tmp18
loc_6182A:
		TXA
		CLC
		ADC		#$50
		TAX
		LDA		_tmp11
		LSR
		LSR
		LSR
		LSR
		ORA		_tmp10
		STA		_tmp02
		LDA		_tmp13
		CLC
		ADC		#>[_room_map_buf]
		STA		_tmp03
		LDY		#$00
		TXA
		STA		(_tmp02),Y
		LDY		#$20
		LDA		_tmp13
		AND		#$01
		BEQ		loc_6184F
		LDY		#$24
loc_6184F:
		LDA		#$00
		STA		_tmp03
		LDA		_tmp11
		STA		_tmp02
		CLC
		ASL		_tmp02
		ROL		_tmp03
		ASL		_tmp02
		ROL		_tmp03
		LDA		_tmp10
		LSR
		LSR
		LSR
		CLC
		ADC		_tmp02
		STA		_tmp02
		LDA		#$00
		ADC		_tmp03
		STA		_tmp03
		TYA
		CLC
		ADC		_tmp03
		STA		_tmp03
		LDY		#$00
		JSR		_ppu_queue_put_char
		INC		_tmp02
		INX
		JSR		_ppu_queue_put_char
		DEC		_tmp02
		INX
		LDA		_tmp02
		CLC
		ADC		#$20
		STA		_tmp02
		LDA		#$00
		ADC		_tmp03
		STA		_tmp03
		JSR		_ppu_queue_put_char
		INC		_tmp02
		INX
		JSR		_ppu_queue_put_char
		LDA		#$00
		STA		(_ppu_queue_buf_ofs),Y
		INY
		TYA
		CLC
		ADC		_ppu_queue_buf_ofs
		STA		_ppu_queue_buf_ofs
loc_618A5:
		PLA
		TAY
		PLA
		TAX
		RTS

; =============== S U B	R O U T	I N E =======================================
_ppu_queue_put_char:
		LDA		_tmp03
		STA		(_ppu_queue_buf_ofs),Y
		INY
		LDA		_tmp02
		STA		(_ppu_queue_buf_ofs),Y
		INY
		TXA
		STA		(_ppu_queue_buf_ofs),Y
		INY
		RTS

; =============== S U B	R O U T	I N E =======================================
_collision_test_subC:
		LDX		_tmp14
		LDA		_tobjB.field_4,X
		AND		#$F7
		STA		_tmp12
		LDA		_tobjB.field_6,X
		AND		#$0F
		BEQ		loc_618E0
		BIT		_tmp12
		BPL		loc_618D4
		LDA		_tmp16
		CMP		#$59
		BCS		loc_618E0
		BCC		loc_618DA
loc_618D4:
		LDA		_tmp17
		CMP		#$59
		BCS		loc_618E0
loc_618DA:
		LDA		_tmp12
		ORA		#$08
		STA		_tmp12
loc_618E0:
		BIT		_tmp12
		BVC		loc_618ED
		LDA		_tmp18
		CMP		#$59
		BCS		loc_618F9
		BCC		loc_618F3
loc_618ED:
		LDA		_ppu_room_line_pos
		CMP		#$59
		BCS		loc_618F9
loc_618F3:
		LDA		_tmp12
		ORA		#$08
		STA		_tmp12
loc_618F9:
		LDA		_tmp12
		STA		_tobjB.field_4,X
		RTS
; ---------------------------------------------------------------------------
_obj_collision_tableA:
		.BYTE $11,$12
		.BYTE $21,$22
		.BYTE $23,$24
		.BYTE $25,$26
		.BYTE $32,$33
		.BYTE $34,$35
		.BYTE $42,$43
		.BYTE $52,$64
_obj_collision_tableB:
		.BYTE $21,$11
		.BYTE $23,$11
		.BYTE $24,$11
		.BYTE $05,$11
		.BYTE $13,$31
		.BYTE $03,$11
		.BYTE $21,$21
		.BYTE $32,$21
		.BYTE $22,$21
		.BYTE $08,$22
		.BYTE $0A,$22
		.BYTE $0C,$22
		.BYTE $12,$42
		.BYTE $11,$22
		.BYTE $12,$22
		.BYTE $22,$22

; =============== S U B	R O U T	I N E =======================================
_obj_collision_testB:
		LDA		#$30
		STA		_tmp12
		LDA		#$07
		STA		_tmp13
loc_61950:
		LDX		_tmp12
		LDA		_tobjA._hndl_idx,X
		BPL		loc_61959
		JMP		loc_61A88
loc_61959:
		JSR		_obj_col_testB_calcA
		LDA		_tobjA.field_7,X
		AND		#$08
		BEQ		loc_6197F
		LDA		_tobjA.field_7,X
		AND		#$30
		STA		_tmp17
		LDA		_objsA._player.field_7
		AND		#$30
		AND		_tmp17
		STA		_tmp17
		BEQ		loc_6197F
		JSR		_obj_collision_testB_subA
		JSR		_obj_col_testB_calcF
		LDA		_tmp16
		BEQ		loc_6197F
		JSR		_obj_col_testB_calcE
loc_6197F:
		LDA		_tobjA.field_8,X
		AND		#$08
		BEQ		loc_619A4
		LDA		_tobjA.field_8,X
		AND		#$30
		STA		_tmp17
		LDA		_objsA._player.field_7
		AND		#$30
		AND		_tmp17
		STA		_tmp17
		BEQ		loc_619A4
		JSR		_obj_collision_testB_subB
		BMI		loc_619A4
		JSR		_obj_col_testB_calcF
		LDA		_tmp16
		BEQ		loc_619A4
		JSR		_obj_col_testB_calcE
loc_619A4:
		JSR		_obj_col_testB_calcB
		BMI		loc_619C6
		LDA		_tobjA.field_7,X
		AND		#$30
		STA		_tmp17
		LDA		_objsA._player.field_8
		AND		#$30
		AND		_tmp17
		STA		_tmp17
		BEQ		loc_619C6
		JSR		_obj_collision_testB_subA
		JSR		_obj_col_testB_calcF
		LDA		_tmp16
		BEQ		loc_619C6
		JSR		_obj_col_testB_calcE
loc_619C6:
		LDA		#$A0
		STA		_tmp14
		LDA		#$04
		STA		_tmp15
loc_619CE:
		LDX		_tmp14
		LDA		_tobjB,X
		BPL		loc_619D7
		JMP		loc_61A7A
loc_619D7:
		JSR		_obj_col_testB_calcC
		LDX		_tmp14
		LDA		_tobjB.field_4,X
		AND		#$07
		LDX		_tmp12
		AND		_tobjA.field_7,X
		BEQ		loc_61A2A
		JSR		_obj_collision_testB_subA
		JSR		_obj_col_testB_calcF
		LDA		_tmp16
		BEQ		loc_61A2A
		LDX		_tmp14
		LDA		_tobjB.field_4,X
		ORA		#$08
		STA		_tobjB.field_4,X
		LDX		_tmp12
		AND		_tobjA.field_7,X
		BEQ		loc_61A2A
		LDA		_tobjA.field_C,X
		BEQ		loc_61A2A
		LDX		_tmp14
		LDA		_tobjB.field_5,X
		STA		_ppu_room_line_pos
		LDX		_tmp12
		LDA		_tobjA._hndl_idx,X
		AND		#$3F
		CMP		#$36
		BCC		loc_61A17
		DEC		_tobjA.field_C,X
		JMP		loc_61A24
loc_61A17:
		LDA		_tobjA.field_C,X
		SEC
		SBC		_ppu_room_line_pos
		STA		_tobjA.field_C,X
		BCS		loc_61A24
		LDA		#$00
		STA		_tobjA.field_C,X
loc_61A24:
		LDA		_tobjA._state,X
		ORA		#$80
		STA		_tobjA._state,X
loc_61A2A:
		LDX		_tmp14
		LDA		_tobjB.field_4,X
		AND		#$07
		LDX		_tmp12
		AND		_tobjA.field_8,X
		BEQ		loc_61A7A
		JSR		_obj_collision_testB_subB
		JSR		_obj_col_testB_calcF
		LDA		_tmp16
		BEQ		loc_61A7A
		LDX		_tmp14
		LDA		_tobjB.field_4,X
		ORA		#$08
		STA		_tobjB.field_4,X
		LDX		_tmp12
		AND		_tobjA.field_8,X
		BEQ		loc_61A7A
		LDA		_tobjA.field_C,X
		BEQ		loc_61A7A
		LDX		_tmp14
		LDA		_tobjB.field_5,X
		STA		_ppu_room_line_pos
		LDX		_tmp12
		LDA		_tobjA._hndl_idx,X
		AND		#$3F
		CMP		#$36
		BCC		loc_61A67
		DEC		_tobjA.field_C,X
		JMP		loc_61A74
loc_61A67:
		LDA		_tobjA.field_C,X
		SEC
		SBC		_ppu_room_line_pos
		STA		_tobjA.field_C,X
		BCS		loc_61A74
		LDA		#$00
		STA		_tobjA.field_C,X
loc_61A74:
		LDA		_tobjA._state,X
		ORA		#$80
		STA		_tobjA._state,X
loc_61A7A:
		LDA		_tmp14
		CLC
		ADC		#$08
		STA		_tmp14
		DEC		_tmp15
		BEQ		loc_61A88
		JMP		loc_619CE
loc_61A88:
		LDA		_tmp12
		CLC
		ADC		#$10
		STA		_tmp12
		DEC		_tmp13
		BEQ		loc_61A96
		JMP		loc_61950
loc_61A96:
		JSR		_obj_col_testB_calcA
		LDA		#$C0
		STA		_tmp14
		LDA		#$08
		STA		_tmp15
loc_61AA1:
		LDX		_tmp14
		LDA		_tobjB,X
		BMI		loc_61AF6
		LDA		_objsA._player.field_7
		AND		#$07
		AND		_tobjA._x_pos,X
		BEQ		loc_61AF6
		JSR		_obj_col_testB_calcD
		JSR		_obj_col_testB_calcF
		LDA		_tmp16
		BEQ		loc_61AF6
		LDA		_tobjA._x_pos,X
		ORA		#$08
		STA		_tobjA._x_pos,X
		LDA		_objsA._player.field_7
		AND		#$07
		AND		_tobjA._x_pos,X
		BEQ		loc_61AF6
		LDA		_tobjA._y_pos,X
		STA		_ppu_room_line_pos
		LDA		_objsA._player._state
		ORA		#$80
		STA		_objsA._player._state
		LDA		_game._life
		ORA		_game._life+1
		BEQ		loc_61AF6
		LDA		_game._life
		SEC
		SBC		_ppu_room_line_pos
		STA		_game._life
		BCS		loc_61AF6
		LDA		_game._life+1
		SBC		#$00
		STA		_game._life+1
		BCS		loc_61AF6
		LDA		#$00
		STA		_game._life
		STA		_game._life+1
loc_61AF6:
		LDA		_tmp14
		CLC
		ADC		#$08
		STA		_tmp14
		DEC		_tmp15
		BNE		loc_61AA1
		LDA		_game._scr_idx
		CMP		#$FF
		BNE		locret_61B69
		LDA		#$A0
		STA		_tmp14
		LDA		#$04
		STA		_tmp15
		LDA		#$02
		STA		_tmp08
		STA		_tmp09
		LDA		#$70
		STA		_tmp07
		LDA		#$00
		STA		_tmp05
		LDA		#$80
		SEC
		SBC		_final_boss_scroll_pos
		CLC
		ADC		#$40
		STA		_tmp06
loc_61B29:
		LDX		_tmp14
		LDA		_tobjB,X
		BMI		loc_61B5E
		LDA		_tobjB,X
		AND		#$0F
		CMP		#$05
		BNE		loc_61B5E
		JSR		_obj_col_testB_calcC
		JSR		_obj_col_testB_calcF
		LDA		_tmp16
		BEQ		loc_61B5E
		LDX		_tmp14
		LDA		_tobjB.field_4,X
		ORA		#$08
		STA		_tobjB.field_4,X
		LDA		_final_boss_deploy_delay_timer
		BEQ		locret_61B69
		DEC		_final_boss_deploy_delay_timer
		BNE		loc_61B5E
		JSR		_objs_reset
		LDA		#$40
		STA		_final_boss_delay_and_hp
		RTS
loc_61B5E:
		LDA		_tmp14
		CLC
		ADC		#$08
		STA		_tmp14
		DEC		_tmp15
		BNE		loc_61B29
locret_61B69:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_collision_testB_subA:
		LDA		_tobjA.field_9,X
		AND		#$0F
		TAY
		LDA		_obj_collision_tableA,Y
		AND		#$0F
		STA		_tmp09
		LDA		_obj_collision_tableA,Y
		LSR
		LSR
		LSR
		LSR
		STA		_tmp08
		LDA		_tobjA._dir,X
		ASL
		AND		#$80
		STA		_ppu_room_line_pos
		LDA		_tobjA._room_num,X
		AND		#$03
		ORA		_ppu_room_line_pos
		STA		_tmp05
		LDA		_tobjA._x_pos,X
		STA		_tmp06
		LDA		_tobjA._y_pos,X
		STA		_tmp07
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_collision_testB_subB:
		LDA		_tobjB.field_3,X
		AND		#$03
		STA		_tmp05
		LDA		_tobjB.field_1+8,X
		AND		#$F0
		LSR
		LSR
		LSR
		TAY
		LDA		_tobjB.field_6,X
		AND		#$40
		BNE		loc_61BC3
		LDA		_obj_collision_tableB,Y
		AND		#$F0
		LSR
		CLC
		ADC		_tobjB.field_4,X
		STA		_tmp06
		BCC		loc_61BDB
		INC		_tmp05
		LDA		_tmp05
		CMP		#$04
		BCC		loc_61BDB
		BCS		loc_61C0A
loc_61BC3:
		LDA		_obj_collision_tableB,Y
		AND		#$F0
		LSR
		STA		_tmp06
		LDA		_tobjB.field_4,X
		SEC
		SBC		_tmp06
		STA		_tmp06
		BCS		loc_61BDB
		DEC		_tmp05
		BMI		loc_61C0A
loc_61BDB:
		LDA		_obj_collision_tableB,Y
		AND		#$0F
		ASL
		ASL
		ASL
		STA		_tmp07
		LDA		_tobjB.field_5,X
		SEC
		SBC		_tmp07
		STA		_tmp07
		BCC		loc_61C0A
		LDA		_obj_collision_tableB+1,Y
		LSR
		LSR
		LSR
		LSR
		STA		_tmp08
		LDA		_obj_collision_tableB+1,Y
		AND		#$0F
		STA		_tmp09
		LDA		_tobjB.field_6,X
		ASL
		AND		#$80
		ORA		_tmp05
		STA		_tmp05
		LDA		#$00
		RTS
loc_61C0A:
		LDA		#$FF
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_col_testB_calcA:
		LDA		_objsA._player.field_9
		AND		#$0F
		TAY
		LDA		_obj_collision_tableA,Y
		AND		#$0F
		STA		_tmp04
		LDA		_obj_collision_tableA,Y
		LSR
		LSR
		LSR
		LSR
		STA		_tmp03
		LDA		_objsA._player._dir
		ASL
		AND		#$80
		STA		_ppu_room_line_pos
		LDA		_objsA._player._room_num
		AND		#$03
		ORA		_ppu_room_line_pos
		STA		_tmp00
		LDA		_objsA._player._x_pos
		STA		_tmp01
		LDA		_objsA._player._y_pos
		STA		_tmp02
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_col_testB_calcB:
		LDA		_objsA._player._room_num
		AND		#$03
		STA		_tmp00
		LDA		_objsA._player.field_9
		AND		#$F0
		LSR
		LSR
		LSR
		TAY
		BIT		_objsA._player._dir
		BVS		loc_61C64
		LDA		_obj_collision_tableB,Y
		AND		#$F0
		LSR
		CLC
		ADC		_objsA._player._x_pos
		STA		_tmp01
		BCC		loc_61C7C
		INC		_tmp00
		LDA		_tmp00
		CMP		#$04
		BCC		loc_61C7C
		BCS		loc_61CAB
loc_61C64:
		LDA		_obj_collision_tableB,Y
		AND		#$F0
		LSR
		STA		_tmp01
		LDA		_objsA._player._x_pos
		SEC
		SBC		_tmp01
		STA		_tmp01
		BCS		loc_61C7C
		DEC		_tmp00
		BMI		loc_61CAB
loc_61C7C:
		LDA		_obj_collision_tableB,Y
		AND		#$0F
		ASL
		ASL
		ASL
		STA		_tmp02
		LDA		_objsA._player._y_pos
		SEC
		SBC		_tmp02
		STA		_tmp02
		BCC		loc_61CAB
		LDA		_obj_collision_tableB+1,Y
		LSR
		LSR
		LSR
		LSR
		STA		_tmp03
		LDA		_obj_collision_tableB+1,Y
		AND		#$0F
		STA		_tmp04
		LDA		_objsA._player._dir
		ASL
		AND		#$80
		ORA		_tmp00
		STA		_tmp00
		LDA		#$00
		RTS
loc_61CAB:
		LDA		#$FF
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_col_testB_calcC:
		LDX		_tmp14
		LDA		_tobjB.field_4,X
		AND		#$30
		LSR
		LSR
		LSR
		LSR
		TAY
		LDA		_obj_collision_tableA,Y
		AND		#$0F
		STA		_tmp04
		LDA		_obj_collision_tableA,Y
		LSR
		LSR
		LSR
		LSR
		STA		_tmp03
		LDA		_tobjB.field_4,X
		ASL
		AND		#$80
		STA		_ppu_room_line_pos
		LDA		_tobjB.field_1,X
		AND		#$03
		ORA		_ppu_room_line_pos
		STA		_tmp00
		LDA		_tobjB.field_2,X
		STA		_tmp01
		LDA		_tobjB.field_3,X
		STA		_tmp02
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_col_testB_calcD:
		LDX		_tmp14
		LDA		_tobjB.field_4,X
		AND		#$30
		LSR
		LSR
		LSR
		LSR
		TAY
		LDA		_obj_collision_tableA,Y
		AND		#$0F
		STA		_tmp09
		LDA		_obj_collision_tableA,Y
		LSR
		LSR
		LSR
		LSR
		STA		_tmp08
		LDA		_tobjB.field_4,X
		ASL
		AND		#$80
		STA		_ppu_room_line_pos
		LDA		_tobjB.field_1,X
		AND		#$03
		ORA		_ppu_room_line_pos
		STA		_tmp05
		LDA		_tobjB.field_2,X
		STA		_tmp06
		LDA		_tobjB.field_3,X
		STA		_tmp07
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_col_testB_calcE:
		LDA		_tmp17
		AND		#$20
		BEQ		loc_61D49
		LDA		_tobjA._damage,X
		STA		_ppu_room_line_pos
		LDA		_objsA._player._state
		ORA		#$80
		STA		_objsA._player._state
		LDA		_game._life
		ORA		_game._life+1
		BEQ		loc_61D49
		LDA		_game._life
		SEC
		SBC		_ppu_room_line_pos
		STA		_game._life
		BCS		loc_61D49
		LDA		_game._life+1
		SBC		#$00
		STA		_game._life+1
		BCS		loc_61D49
		LDA		#$00
		STA		_game._life+1
		STA		_game._life
loc_61D49:
		LDA		_tmp17
		AND		#$10
		BEQ		locret_61D77
		LDA		_objsA._player._damage
		STA		_ppu_room_line_pos
		LDA		_tobjA._state,X
		ORA		#$80
		STA		_tobjA._state,X
		LDA		_tobjA.field_C,X
		BEQ		locret_61D77
		LDA		_tobjA._hndl_idx,X
		AND		#$3F
		CMP		#$36
		BCC		loc_61D6A
		DEC		_tobjA.field_C,X
		RTS
loc_61D6A:
		LDA		_tobjA.field_C,X
		SEC
		SBC		_ppu_room_line_pos
		STA		_tobjA.field_C,X
		BCS		locret_61D77
		LDA		#$00
		STA		_tobjA.field_C,X
locret_61D77:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_col_testB_calcF:
		LDA		#$00
		STA		_tmp0A
		ASL		_tmp05
		ROR		_tmp0A
		LSR		_tmp05
		ASL		_tmp00
		ROR		_tmp0A
		LSR		_tmp00
		LDA		_tmp00
		STA		_tmp0B
		LDA		_tmp01
		STA		_tmp0C
		LDA		_tmp05
		STA		_tmp0E
		LDA		_tmp06
		STA		_tmp0F
		LDA		_tmp02
		CMP		#$20
		BCC		loc_61DA4
		LDA		_tmp07
		CMP		#$21
		BCS		loc_61DAB
loc_61DA4:
		LDA		#$00
		STA		_tmp16
		RTS
loc_61DAB:
		LDA		_tmp04
		ASL
		ASL
		ASL
		STA		_tmp11
		LDA		_tmp02
		SEC
		SBC		_tmp11
		STA		_tmp0D
		BCS		loc_61DBF
		LDA		#$20
		STA		_tmp0D
loc_61DBF:
		LDA		_tmp09
		ASL
		ASL
		ASL
		STA		_tmp11
		LDA		_tmp07
		SEC
		SBC		_tmp11
		STA		_tmp10
		BCS		loc_61DD3
		LDA		#$20
		STA		_tmp10
loc_61DD3:
		LDA		_tmp10
		CMP		_tmp02
		BCS		loc_61DA4
		LDA		_tmp07
		CMP		_tmp0D
		BCC		loc_61DA4
		BIT		_tmp0A
		BMI		loc_61DFF
		LDA		_tmp03
		ASL
		ASL
		ASL
		ADC		_tmp01
		STA		_tmp0C
		BCC		loc_61E19
		INC		_tmp0B
		LDA		_tmp0B
		CMP		#$04
		BCC		loc_61E19
		DEC		_tmp0B
		LDA		#$FF
		STA		_tmp0C
		BNE		loc_61E19
loc_61DFF:
		LDA		_tmp03
		ASL
		ASL
		ASL
		STA		_tmp11
		LDA		_tmp0C
		SEC
		SBC		_tmp11
		STA		_tmp01
		BCS		loc_61E19
		DEC		_tmp00
		BPL		loc_61E19
		INC		_tmp00
		LDA		#$00
		STA		_tmp01
loc_61E19:
		BIT		_tmp0A
		BVS		loc_61E39
		LDA		_tmp08
		ASL
		ASL
		ASL
		ADC		_tmp06
		STA		_tmp0F
		BCC		loc_61E53
		INC		_tmp0E
		LDA		_tmp0E
		CMP		#$04
		BCC		loc_61E53
		DEC		_tmp0E
		LDA		#$FF
		STA		_tmp0F
		BNE		loc_61E53
loc_61E39:
		LDA		_tmp08
		ASL
		ASL
		ASL
		STA		_tmp11
		LDA		_tmp0F
		SEC
		SBC		_tmp11
		STA		_tmp06
		BCS		loc_61E53
		DEC		_tmp05
		BPL		loc_61E53
		INC		_tmp05
		LDA		#$00
		STA		_tmp06
loc_61E53:
		LDA		_tmp05
		CMP		_tmp0B
		BEQ		loc_61E5E
		BCS		loc_61E78
		BCC		loc_61E64
loc_61E5E:
		LDA		_tmp06
		CMP		_tmp0C
		BCS		loc_61E78
loc_61E64:
		LDA		_tmp0E
		CMP		_tmp00
		BEQ		loc_61E6F
		BCC		loc_61E78
		BCS		loc_61E7B
loc_61E6F:
		LDA		_tmp0F
		CMP		_tmp01
		BCS		loc_61E7B
loc_61E78:
		JMP		loc_61DA4
loc_61E7B:
		LDA		#$FF
		STA		_tmp16
locret_61E7F:
		RTS

; =============== S U B	R O U T	I N E =======================================
_engine_handlers:
		JSR		_final_boss_animate_handler
		JSR		_objA_manager
		JSR		_objB_manager
		JSR		_obj_collision_testA
		JSR		_obj_collision_testB
		JSR		_player_pos_x_delta_calc
		LDA		_tmp00
		BEQ		loc_61F13
		STA		_cur_player_pos_x_delta
		BMI		loc_61EDA
		LDA		_objsA._player._room_num
		CMP		#$00
		BEQ		loc_61EC3
		CMP		#$03
		BNE		loc_61F10
		LDA		_objsA._player._x_pos
		SEC
		SBC		#$86
		BCS		loc_61F13
		LDA		#$86
		SEC
		SBC		_objsA._player._x_pos
		BEQ		loc_61F10
		CMP		#$03
		BCS		loc_61F10
		STA		_cur_player_pos_x_delta
		JMP		loc_61F10
loc_61EC3:
		LDA		_objsA._player._x_pos
		CMP		#$87
		BCS		loc_61F10
		LDA		#$87
		SEC
		SBC		_objsA._player._x_pos
		BEQ		loc_61F13
		CMP		#$03
		BCS		loc_61F13
		STA		_cur_player_pos_x_delta
		JMP		loc_61F13
loc_61EDA:
		LDA		_objsA._player._room_num
		CMP		#$00
		BEQ		loc_61EFE
		CMP		#$03
		BNE		loc_61F10
		LDA		_objsA._player._x_pos
		SEC
		SBC		#$78
		BCC		loc_61F10
		BEQ		loc_61F13
		CMP		#$03
		BCS		loc_61F13
		EOR		#$03
		ORA		#$80
		STA		_cur_player_pos_x_delta
		JMP		loc_61F10
loc_61EFE:
		LDA		_objsA._player._x_pos
		SEC
		SBC		#$79
		BCC		loc_61F13
		BEQ		loc_61F13
		CMP		#$03
		BCS		loc_61F10
		ORA		#$80
		STA		_cur_player_pos_x_delta
loc_61F10:
		JSR		_room_macro_handler
loc_61F13:
		LDA		_objsA._player._room_num
		STA		_prev_player_pos_x
		LDA		_objsA._player._x_pos
		STA		_prev_player_pos_x+1
		RTS

; =============== S U B	R O U T	I N E =======================================
_player_pos_x_delta_calc:
		SEC
		LDA		_prev_player_pos_x+1
		SBC		_objsA._player._x_pos
		STA		_tmp00
		LDA		_prev_player_pos_x
		SBC		_objsA._player._room_num
		STA		_tmp01
		BPL		loc_61F38
		LDA		_tmp00
		EOR		#$FF
		CLC
		ADC		#$01
		STA		_tmp00
loc_61F38:
		ASL		_tmp00
		ASL		_tmp01
		ROR		_tmp00
		RTS

; =============== S U B	R O U T	I N E =======================================
_final_boss_animate_handler:
		LDA		_game._scr_idx
		CMP		#$FF
		BNE		locret_61F4E
		LDA		_game._redraw_req
		BEQ		loc_61F4F
locret_61F4E:
		RTS
loc_61F4F:
		LDA		_final_boss_deploy_delay_timer
		BEQ		loc_61F93
		LDA		_ppu_status_shadow
		AND		#$80
		BNE		loc_61F7E
		INC		_objsA._o3._x_pos
		INC		_objsA._o3._x_pos
		INC		_objsA._o4._x_pos
		INC		_objsA._o4._x_pos
		INC		_final_boss_scroll_pos
		INC		_final_boss_scroll_pos
		LDA		_final_boss_scroll_pos
		CMP		#$80
		BCS		loc_61F73
		JMP		_final_boss_animate
loc_61F73:
		LDA		_ppu_status_shadow
		EOR		#$80
		STA		_ppu_status_shadow
		JMP		_final_boss_animate
loc_61F7E:
		DEC		_objsA._o3._x_pos
		DEC		_objsA._o3._x_pos
		DEC		_objsA._o4._x_pos
		DEC		_objsA._o4._x_pos
		DEC		_final_boss_scroll_pos
		DEC		_final_boss_scroll_pos
		BEQ		loc_61F73
		BMI		loc_61F73
		JMP		_final_boss_animate
loc_61F93:
		JSR		_rand
		AND		#$08
		BEQ		locret_61F4E
		LDX		#$C0
		LDY		#$08
loc_61F9E:
		LDA		_tobjB,X
		BMI		loc_61FAD
		TXA
		CLC
		ADC		#$08
		TAX
		DEY
		BNE		loc_61F9E
		RTS
loc_61FAD:
		LDA		#SEN06
		STA		_apu_se_noise_idx
		LDA		#$80
		SEC
		SBC		_final_boss_scroll_pos
		STA		_tmp06
		LDA		_tmp13
		AND		#$7F
		CLC
		ADC		_tmp06
		STA		_tobjB.field_2,X
		LDA		_tmp13
		AND		#$3F
		CLC
		ADC		#$40
		STA		_tobjB.field_3,X
		LDA		#$00
		STA		_tobjB.field_1,X
		LDA		#$1E
		STA		_tobjB,X
		LDA		#$00
		STA		_tobjB.field_4,X
		STA		_tobjB.field_5,X
		STA		_tobjB.field_7,X
		LDA		#$F2
		STA		_tobjB.field_6,X
		DEC		_final_boss_delay_and_hp
		BEQ		loc_61FE8
		RTS
loc_61FE8:
		LDA		#$AF
		STA		_game._scr_idx
		LDA		#$FF
		STA		_game._redraw_req
		LDA		#$00
		STA		_room_scroll_pos_x
		LDA		#$03
		STA		_room_scroll_pos_x+1
		LDA		#$E7
		STA		_game._life
		LDA		#$03
		STA		_game._life+1
		RTS
_final_boss_animate:
		DEC		_final_boss_delay_and_hp
		LDA		_final_boss_delay_and_hp
		BEQ		_final_boss_obj_insert
		RTS
_final_boss_obj_insert:
		LDA		#$78
		STA		_final_boss_delay_and_hp
		LDA		#$00
		STA		_tmp0A
		LDY		#$06
loc_6201F:
		LDA		_tmp0A
		TAX
		LDA		_objsA._o1,X
		BPL		loc_62047
		LDA		_final_boss_enemy_dinamic_list,Y
		STA		_tmp00
		LDA		_final_boss_enemy_dinamic_list+1,Y
		STA		_tmp01
		LDA		_final_boss_enemy_dinamic_list+2,Y
		STA		_tmp02
		LDA		_final_boss_enemy_dinamic_list+3,Y
		STA		_tmp03
		LDA		_final_boss_enemy_dinamic_list+4,Y
		STA		_tmp04
		LDA		_final_boss_enemy_dinamic_list+5,Y
		STA		_tmp05
		JSR		_obj_lib_insert
loc_62047:
		INY
		INY
		INY
		INY
		INY
		INY
		LDA		_tmp0A
		CLC
		ADC		#$10
		STA		_tmp0A
		CMP		#$30
		BNE		loc_6201F
		LDX		#$06
		LDA		_objsA._o1,X
		ORA		#$04
		STA		_objsA._o1,X
		LDA		_objsA._o2,X
		ORA		#$04
		STA		_objsA._o2,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_objB_manager:
		LDA		#$00
		STA		_tmp14

; =============== S U B	R O U T	I N E =======================================
_objB_handlers_exec:
		LDA		_tmp14
		ASL
		ASL
		ASL
		TAX
		LDA		_objsB,X
		BMI		_objB_continue
		AND		#$3F
		ASL
		TAY
		LDA		_objB_hndl_lib,Y
		STA		_tmp00
		LDA		_objB_hndl_lib+1,Y
		STA		_tmp01
		JSR		_objB_load
		JMP		(_tmp00)

; =============== S U B	R O U T	I N E =======================================
_objB_flush_and_continue:
		JSR		_objB_flush

; =============== S U B	R O U T	I N E =======================================
_objB_continue:
		INC		_tmp14
		LDA		_tmp14
		CMP		#$0C
		BNE		_objB_handlers_exec
		RTS

; =============== S U B	R O U T	I N E =======================================
_objB_load:
		LDA		_objsB._o0.field_6,X
		LSR
		LSR
		LSR
		LSR
		STA		_tmp0F
		LDA		_objsB._o0.field_6,X
		AND		#$0F
		STA		_tmp10
		LDA		_objsB._o0.field_1,X
		STA		_tmp0C
		LDA		_objsB._o0.field_2,X
		STA		_tmp0D
		LDA		_objsB._o0.field_3,X
		STA		_tmp0E
		LDA		_objsB._o0.field_4,X
		STA		_tmp11
		STA		_tmp12
		RTS

; =============== S U B	R O U T	I N E =======================================
_objB_flush:
		LDA		_tmp11
		EOR		_tmp12
		ASL
		ASL
		BCC		loc_620E3
		LDA		#$40
		BIT		_tmp11
		BNE		loc_620D6
		SEC
		LDA		_tmp0D
		SBC		#$08
		STA		_tmp0D
		LDA		_tmp0C
		SBC		#$00
		STA		_tmp0C
		JMP		loc_620E3
loc_620D6:
		LDA		_tmp0D
		CLC
		ADC		#$08
		STA		_tmp0D
		BCC		loc_620D7
		INC		_tmp0C
loc_620D7:
loc_620E3:
		LDA		_tmp0F
		ASL
		ASL
		ASL
		ASL
		ORA		_tmp10
		STA		_objsB._o0.field_6,X
		LDA		_tmp0C
		STA		_objsB._o0.field_1,X
		LDA		_tmp0D
		STA		_objsB._o0.field_2,X
		LDA		_tmp0E
		STA		_objsB._o0.field_3,X
		LDA		_tmp11
		STA		_objsB._o0.field_4,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_objB_hndl00:
		LDA		_tmp11
		AND		#$08
		BEQ		_objB_hndl00_delay_kill
		JMP		_objB_sub62362

; =============== S U B	R O U T	I N E =======================================
_objB_hndl00_delay_kill:
		DEC		_objsB._o0.field_7,X
		BNE		loc_6210F
		LDA		#$80
		STA		_objsB._o0._hndl_idx,X
loc_6210F:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_hndl01:
		LDA		_tmp11
		AND		#$08
		BEQ		loc_6211B
		JMP		_objB_sub62362
loc_6211B:
		LDA		#$06
		STA		_tmp01
		LDA		#$00
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		STA		_tmp02
		JSR		_obj_move_animate_common
		DEC		_objsB._o0.field_7,X
		BNE		loc_62134
		LDA		#$80
		STA		_objsB._o0._hndl_idx,X
loc_62134:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_hndl02:
		LDA		_tmp11
		AND		#$08
		BEQ		loc_62140
		JMP		_objB_sub62362
loc_62140:
		LDA		#$06
		STA		_tmp01
		LDA		#$00
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		STA		_tmp02
		JSR		_obj_move_animate_common
		DEC		_objsB._o0.field_7,X
		BNE		loc_62159
		LDA		#$80
		STA		_objsB._o0._hndl_idx,X
loc_62159:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_hndl03:
		LDA		_tmp11
		AND		#$08
		BEQ		loc_62165
		JMP		_objB_sub62380
loc_62165:
		LDA		#$06
		STA		_tmp01
		LDA		#$00
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		STA		_tmp02
		JSR		_obj_move_animate_common
		DEC		_objsB._o0.field_7,X
		BNE		loc_6217E
		LDA		#$80
		STA		_objsB._o0._hndl_idx,X
loc_6217E:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_hndl04:
		LDA		_tmp11
		AND		#$08
		BEQ		loc_6218A
		JMP		_objB_sub62362
loc_6218A:
		LDA		#$06
		STA		_tmp01
		LDA		#$06
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		STA		_tmp02
		JSR		_obj_move_animate_common
		DEC		_objsB._o0.field_7,X
		BNE		loc_621A3
		LDA		#$80
		STA		_objsB._o0._hndl_idx,X
loc_621A3:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_hndl05:
		LDA		_tmp11
		AND		#$08
		BEQ		loc_621AF
		JMP		_objB_sub62380
loc_621AF:
		LDA		#$06
		STA		_tmp01
		LDA		#$0F
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		LDA		#$01
		STA		_tmp02
		JSR		_obj_move_animate_common
		DEC		_objsB._o0.field_7,X
		BNE		loc_621CA
		LDA		#$80
		STA		_objsB._o0._hndl_idx,X
loc_621CA:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_hndl06:
		LDA		#$03
		STA		_tmp01
		LDA		#$05
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		LDA		#$01
		STA		_tmp02
		DEC		_objsB._o0.field_7,X
		BNE		loc_621E4
		JMP		_objB_sub62380
loc_621E4:
		LDA		_tmp11
		AND		#$08
		BEQ		loc_621F4
		LDA		_tmp11
		ORA		#$80
		STA		_tmp11
		LDA		#$05
		STA		_tmp10
loc_621F4:
		JSR		_obj_move_animate_common

; =============== S U B	R O U T	I N E =======================================
_objB_hndl07:
		LDA		#$06
		STA		_tmp01
		LDA		#$06
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		STA		_tmp02
		JSR		_obj_move_animate_common
		LDA		_tmp0E
		CMP		#$F0
		BCS		loc_62212
		DEC		_objsB._o0.field_7,X
		BNE		loc_62216
loc_62212:
		LDA		#$80
		STA		_objsB,X
loc_62216:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_hndl08:
		LDA		_tmp11
		AND		#$08
		BEQ		loc_62222
		JMP		_objB_sub62380
loc_62222:
		LDA		#$06
		STA		_tmp01
		LDA		#$00
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		STA		_tmp02
		JSR		_obj_move_animate_common
		DEC		_objsB._o0.field_7,X
		BNE		loc_6223B
		LDA		#$80
		STA		_objsB,X
loc_6223B:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_hndl0A_heart:
		LDA		_objsB._o0.field_7,X
		CMP		#$18
		BNE		_objB_animate_common
		LDA		#SEP04
		STA		_apu_se_pulse_idx
		LDA		_game._life_level
		CMP		#$07
		BEQ		loc_62266
		INC		_game._life_level
loc_62266:
		LDA		_game._life_level
		ASL
		TAY
		LDA		_max_life_list,Y
		STA		_game._life
		INY
		LDA		_max_life_list,Y
		STA		_game._life+1
		JMP		_objB_animate_common

; =============== S U B	R O U T	I N E =======================================
_objB_hndl10_potions:
		LDA		_objsB._o0.field_7,X
		CMP		#$18
		BNE		_objB_animate_common
		LDA		_objsB._o0._hndl_idx,X
		AND		#$3F
		TAY
		CLC
		LDA		_game._ammo_knife-$B,Y
		ADC		#$01
		STA		_game._ammo_knife-$B,Y
		JMP		_objB_animate_common

; =============== S U B	R O U T	I N E =======================================
_objB_hndl0B_0F_ammo:
		LDA		_objsB._o0.field_7,X
		CMP		#$18
		BNE		_objB_animate_common
		LDA		_objsB._o0._hndl_idx,X
		AND		#$3F
		TAY
		CLC
		LDA		_game._ammo_knife-$B,Y
		ADC		#$0A
		STA		_game._ammo_knife-$B,Y
		JMP		_objB_animate_common

; =============== S U B	R O U T	I N E =======================================
_objB_hndl11_hi_speed:
		LDA		_objsA._player._dir
		ORA		#$01
		STA		_objsA._player._dir
		JMP		_objB_animate_common

; =============== S U B	R O U T	I N E =======================================
_objB_hndl12_hi_jump:
		LDA		_objsA._player._dir
		ORA		#$02
		STA		_objsA._player._dir
		JMP		_objB_animate_common

; =============== S U B	R O U T	I N E =======================================
_objB_hndl13_invul_unused:
		LDA		_objsB._o0.field_7,X
		CMP		#$18
		BNE		_objB_animate_common
		LDA		#$FF
		STA		_objsA._player._timer
		LDA		_tmp11
		ORA		#$20
		STA		_objsA._player._timer
		JMP		_objB_animate_common

; =============== S U B	R O U T	I N E =======================================
_objB_animate_common:
		LDA		#$00
		STA		_tmp01
		LDA		#$01
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		LDA		#$00
		STA		_tmp02
		JSR		_obj_move_animate_common
		DEC		_objsB._o0.field_7,X
		BNE		loc_622E9
		LDA		#$80
		STA		_objsB._o0._hndl_idx,X
loc_622E9:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_hndl14_1C_score:
		LDA		_objsB._o0.field_7,X
		CMP		#$18
		BNE		loc_6230E
		LDA		_objsB,X
		AND		#$3F
		SEC
		SBC		#$14
		ASL
		TAY
		CLC
		LDA		_scores_tbl,Y
		ADC		_game._exp
		STA		_game._exp
		LDA		_scores_tbl+1,Y
		ADC		_game._exp+1
		STA		_game._exp+1
loc_6230E:
		LDA		#$00
		STA		_tmp01
		LDA		#$01
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		LDA		#$00
		STA		_tmp02
		JSR		_obj_move_animate_common
		DEC		_objsB._o0.field_7,X
		BNE		loc_62329
		LDA		#$80
		STA		_objsB,X
loc_62329:
		JMP		_objB_flush_and_continue
; ---------------------------------------------------------------------------
_scores_tbl:
		.WORD 1
		.WORD 2
		.WORD 5
		.WORD 10
		.WORD 20
		.WORD 50
		.WORD 100
		.WORD 200
		.WORD 500

; =============== S U B	R O U T	I N E =======================================
_objB_hndl1D:
		LDA		_objsB._o0.field_7,X
		CMP		#$0F
		BNE		loc_62348
		LDA		#$80
		STA		_objsB._o0._hndl_idx,X
loc_62348:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_hndl1E:
		LDA		#$00
		STA		_objsB._o0.field_5
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
		LDA		_objsB._o0.field_7,X
		CMP		#$13
		BNE		loc_6235F
		LDA		#$80
		STA		_objsB._o0._hndl_idx,X
loc_6235F:
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_sub62362:
		LDA		#$1D
		STA		_objsB._o0._hndl_idx,X
		LDA		#$01
		STA		_tmp10
		LDA		#$0F
		STA		_tmp0F
		LDA		#SEN06
		STA		_apu_se_noise_idx
		LDA		#$00
		STA		_objsB._o0.field_5
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
		JMP		_objB_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_objB_sub62380:
		LDA		#$1E
		STA		_objsB._o0._hndl_idx,X
		LDA		#$02
		STA		_tmp10
		LDA		#$0F
		STA		_tmp0F
		LDA		_tmp11
		AND		#$C0
		ORA		#$31
		STA		_tmp11
		LDA		#SEN07
		STA		_apu_se_noise_idx
		JMP		_objB_flush_and_continue

; ---------------------------------------------------------------------------
_objB_hndl_lib:
		.WORD _objB_hndl00
		.WORD _objB_hndl01
		.WORD _objB_hndl02
		.WORD _objB_hndl03
		.WORD _objB_hndl04
		.WORD _objB_hndl05
		.WORD _objB_hndl06
		.WORD _objB_hndl07
		.WORD _objB_hndl08
		.WORD _objB_animate_common
		.WORD _objB_hndl0A_heart
		.WORD _objB_hndl0B_0F_ammo
		.WORD _objB_hndl0B_0F_ammo
		.WORD _objB_hndl0B_0F_ammo
		.WORD _objB_hndl0B_0F_ammo
		.WORD _objB_hndl0B_0F_ammo
		.WORD _objB_hndl10_potions
		.WORD _objB_hndl11_hi_speed
		.WORD _objB_hndl12_hi_jump
		.WORD _objB_hndl13_invul_unused
		.WORD _objB_hndl14_1C_score
		.WORD _objB_hndl14_1C_score
		.WORD _objB_hndl14_1C_score
		.WORD _objB_hndl14_1C_score
		.WORD _objB_hndl14_1C_score
		.WORD _objB_hndl14_1C_score
		.WORD _objB_hndl14_1C_score
		.WORD _objB_hndl14_1C_score
		.WORD _objB_hndl14_1C_score
		.WORD _objB_hndl1D
		.WORD _objB_hndl1E

; =============== S U B	R O U T	I N E =======================================
_spr_objsA_manager:
		LDA		#$00
		STA		_tmp09
loc_623DE:
		LDX		_tmp09
		LDY		#$00
loc_623E2:
		LDA		_objsA,X
		STA		_tmp0E,Y
		INX
		INY
		CPY		#$07
		BNE		loc_623E2
		LDA		_tmp0E
		BMI		loc_6240C
		JSR		_spr_obj_insert
		LDX		_tmp09
		LDY		#$00
		LDA		_tmp0E,Y
		STA		_objsA._player._hndl_idx,X
		LDA		_tmp0F,Y
		STA		_objsA._player._anim_phase_idx,X
		LDA		_tmp10,Y
		STA		_objsA._player.field_2,X
		LDA		_tmp14,Y
		STA		_objsA._player._dir,X
loc_6240C:
		LDA		_tmp09
		CMP		_objA_buf_shuffle_pos
		BEQ		loc_6242A
		LDA		_tmp09
		BNE		loc_6241A
		LDA		_objA_buf_shuffle_pos
loc_6241A:
		CLC
		ADC		#$10
		STA		_tmp09
		CMP		#$80
		BNE		loc_623DE
		LDA		#$10
		STA		_tmp09
		BNE		loc_623DE
loc_6242A:
		LDA		_objA_buf_shuffle_pos
		CLC
		ADC		#$10
		CMP		#$80
		BNE		loc_62436
		LDA		#$10
loc_62436:
		STA		_objA_buf_shuffle_pos
		LDX		_spr_buf_pos
		LDA		#$F8
loc_6243E:
		STA		_spr_buf,X
		INX
		INX
		INX
		INX
		BNE		loc_6243E
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_obj_insert:
		JSR		_spr_data_init
		JSR		_spr_room_to_screen_pos_calc
		LDY		#$00
		LDA		(_tmp0A),Y
		CMP		#$FF
		BEQ		locret_62481
		JSR		_spr_obj_fetch_chunkA
		INY
		JSR		_spr_obj_adjust
		LDA		(_tmp0A),Y
		CMP		#$FF
		BEQ		locret_62481
		JSR		_spr_obj_fetch_chunkB
		JSR		_spr_obj_dir_fix
		JSR		_spr_obj_priority_fix
		LDA		_tmp14
		ORA		#$10
		STA		_tmp14
loc_62472:
		JSR		_spr_data_insert
		LDA		(_tmp0A),Y
		CMP		#$FF
		BEQ		locret_62481
		JSR		_spr_obj_fetch_chunkB
		JMP		loc_62472
locret_62481:
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_room_to_screen_pos_calc:
		SEC
		LDA		_tmp12
		SBC		_room_scroll_pos_x
		STA		_tmp12
		LDA		_tmp11
		SBC		_room_scroll_pos_x+1
		STA		_tmp11
		SEC
		LDA		_tmp13
		SBC		#$08
		STA		_tmp13
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_obj_fetch_chunkA:
		LDA		(_tmp0A),Y
		AND		#$F0
		STA		_tmp00
		LDA		(_tmp0A),Y
		AND		#$0F
		STA		_tmp03
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_obj_adjust:
		LDA		#$20
		BIT		_tmp14
		BEQ		locret_624B7
		LDA		_tmp10
		LSR
		BCC		locret_624B7
		LDA		_tmp03
		ORA		#$03
		STA		_tmp03
locret_624B7:
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_obj_fetch_chunkB:
		LDA		_tmp03
		AND		#$08
		BNE		loc_624D3
		LDA		(_tmp0A),Y
		ROL
		ROL
		ROL
		AND		#$03
		STA		_tmp02
		LDA		(_tmp0A),Y
		AND		#$3F
		CLC
		ADC		_tmp00
		STA		_tmp01
		RTS
loc_624D3:
		LDA		(_tmp0A),Y
		ROL
		ROL
		ROL
		ROL
		AND		#$07
		STA		_tmp02
		LDA		(_tmp0A),Y
		AND		#$1F
		CLC
		ADC		_tmp00
		STA		_tmp01
locret_624E6:
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_obj_dir_fix:
		BIT		_tmp14
		BVC		locret_624FE
		SEC
		LDA		_tmp12
		SBC		#$08
		STA		_tmp12
		LDA		_tmp11
		SBC		#$00
		STA		_tmp11
		LDA		#$40
		ORA		_tmp03
		STA		_tmp03
locret_624FE:
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_obj_priority_fix:
		LDA		_cur_loc_room_settings
		AND		#$01
		BEQ		locret_6250C
		LDA		_tmp03
		ORA		#$20
		STA		_tmp03
locret_6250C:
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_data_insert:
		LDA		_tmp12
		STA		_tmp0C
		LDA		_tmp11
		STA		_tmp0D
		INY
loc_62516:
		LDA		_tmp0D
		BNE		loc_62541
		LDA		_tmp14
		AND		#$EF
		STA		_tmp14
		LDX		_spr_buf_pos
		LDA		_tmp13
		STA		_spr_buf,X
		LDA		_tmp01
		STA		_spr_buf+1,X
		LDA		_tmp03
		STA		_spr_buf+2,X
		LDA		_tmp0C
		STA		_spr_buf+3,X
		TXA
		CLC
		ADC		#$04
		TAX
		BEQ		loc_62568
		STX		_spr_buf_pos
loc_62541:
		INC		_tmp01
		BIT		_tmp14
		BVS		loc_62557
		LDA		_tmp0C
		CLC
		ADC		#$08
		STA		_tmp0C
		BCC		loc_62564
		INC		_tmp0D
		JMP		loc_62564
loc_62557:
		SEC
		LDA		_tmp0C
		SBC		#$08
		STA		_tmp0C
		LDA		_tmp0D
		SBC		#$00
		STA		_tmp0D
loc_62564:
		DEC		_tmp02
		BPL		loc_62516
loc_62568:
		SEC
		LDA		_tmp13
		SBC		#$08
		STA		_tmp13
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_data_init:
		LDA		_tmp0E
		AND		#$3F
		ASL
		TAY
		LDA		_obj_anim_lib,Y
		STA		_tmp00
		LDA		_obj_anim_lib+1,Y
		STA		_tmp01
		LDA		_tmp0F
		AND		#$F0
		STA		_tmp04
		LDA		_tmp0F
		AND		#$0F
		STA		_tmp0F
		LDA		_tmp04
		LSR
		LSR
		LSR
		LSR
		CMP		_tmp0F
		BEQ		loc_625A2
		LDA		#$04
		STA		_tmp10
		LDA		_tmp0F
		LDA		_tmp0E
		AND		#$3F
		STA		_tmp0E
loc_625A2:
		LDA		_tmp0F
		ASL
		TAY
		LDA		(_tmp00),Y
		STA		_tmp02
		INY
		LDA		(_tmp00),Y
		STA		_tmp03
		LDY		#$00
		LDA		(_tmp02),Y
		CMP		_tmp10
		BCS		loc_625C6
		LDA		_tmp0E
		ORA		#$40
		STA		_tmp0E
		LDA		_tmp10
		LSR
		LSR
		TAY
		LDA		(_tmp02),Y
		STA		_tmp10
loc_625C6:
		LDA		_tmp10
		LSR
		LSR
		TAY
		LDA		(_tmp02),Y
		BMI		loc_625DE
		ASL
		TAY
		LDA		_spr_libA,Y
		STA		_tmp0A
		LDA		_spr_libA+1,Y
		STA		_tmp0B
		JMP		loc_625EA
loc_625DE:
		ASL
		TAY
		LDA		_spr_libB,Y
		STA		_tmp0A
		LDA		_spr_libB+1,Y
		STA		_tmp0B
loc_625EA:
		INC		_tmp10
		LDA		_tmp0F
		ASL
		ASL
		ASL
		ASL
		ORA		_tmp0F
		STA		_tmp0F
		RTS

; =============== S U B	R O U T	I N E =======================================
_spr_objsB_manager:
		LDA		_objB_buf_shuffle_pos
		STA		_tmp09
loc_625FC:
		LDX		_tmp09
		LDA		_objsB,X
		STA		_tmp0E
		LDA		_objsB._o0.field_1,X
		STA		_tmp11
		LDA		_objsB._o0.field_2,X
		STA		_tmp12
		LDA		_objsB._o0.field_3,X
		STA		_tmp13
		LDA		_objsB._o0.field_4,X
		STA		_tmp14
		LDA		_objsB._o0.field_7,X
		STA		_tmp10
		LDA		_tmp0E
		BMI		loc_62627
		JSR		_obj_insert_prize_sprite
		LDX		_tmp09
		LDA		_tmp10
		STA		_objsB._o0.field_7,X
		LDA		_tmp0E
		STA		_objsB,X
loc_62627:
		LDA		_tmp09
		CLC
		ADC		#$08
		STA		_tmp09
		CMP		#$60
		BNE		loc_62636
		LDA		#$00
		STA		_tmp09
loc_62636:
		CMP		_objB_buf_shuffle_pos
		BNE		loc_625FC
		LDA		_objB_buf_shuffle_pos
		CLC
		ADC		#$08
		CMP		#$60
		BNE		loc_6264A
		LDA		#$00
loc_6264A:
		STA		_objB_buf_shuffle_pos
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_insert_prize_sprite:
		LDA		_tmp0E
		CMP		#$09
		BCS		loc_62658
		ORA		#$80
		STA		_tmp0E
loc_62658:
		AND		#$3F
		CMP		#$1D
		BCS		loc_62676
		JSR		_obj_get_prize_spr_tile_ofs
		JSR		_obj_get_prize_spr_ofs_fix
		LDY		#$00
		LDA		(_tmp0A),Y
		CMP		#$FF
		BEQ		locret_62675
		JSR		_obj_get_prize_spr_tile_fetch
		JSR		_obj_get_prize_spr_tile_calc
		JSR		_obj_get_prize_spr_insert
locret_62675:
		RTS
loc_62676:
		LDA		_objsB._o0.field_6,X
		STA		_tmp0F
		LDA		_tmp0E
		PHA
		LDA		#$3F
		STA		_tmp0E
		JSR		_spr_obj_insert
		PLA
		STA		_tmp0E
		LDX		_tmp09
		LDA		_tmp0F
		STA		_objsB._o0.field_6,X
		LDA		_tmp0E
		AND		#$7F
		STA		_tmp0E
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_get_prize_spr_ofs_fix:
		SEC
		LDA		_tmp12
		SBC		_room_scroll_pos_x
		STA		_tmp12
		LDA		_tmp11
		SBC		_room_scroll_pos_x+1
		STA		_tmp11
		SEC
		LDA		_tmp13
		SBC		#$08
		STA		_tmp13
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_get_prize_spr_tile_fetch:
		LDA		#$00
		STA		_tmp01
		LDA		(_tmp0A),Y
		STA		_tmp00
		BMI		loc_626BE
		ORA		#$80
		STA		_tmp00
		INY
		LDA		(_tmp0A),Y
		STA		_tmp01
loc_626BE:
		LDA		#$03
		STA		_tmp02
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_get_prize_spr_tile_calc:
		BIT		_tmp14
		BVC		locret_626DA
		SEC
		LDA		_tmp12
		SBC		#$08
		STA		_tmp12
		LDA		_tmp11
		SBC		#$00
		STA		_tmp11
		LDA		#$40
		ORA		_tmp02
		STA		_tmp02
locret_626DA:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_get_prize_spr_insert:
		LDA		_tmp11
		BNE		loc_62706
		LDA		_tmp0E
		AND		#$7F
		STA		_tmp0E
		LDX		_spr_buf_pos
		LDA		_tmp13
		STA		_spr_buf,X
		LDA		_tmp00
		STA		_spr_buf+1,X
		LDA		_tmp02
		STA		_spr_buf+2,X
		LDA		_tmp12
		STA		_spr_buf+3,X
		TXA
		CLC
		ADC		#$04
		TAX
		BEQ		locret_62734
		STX		_spr_buf_pos
loc_62706:
		BIT		_tmp14
		BVS		loc_6271A
		LDA		_tmp12
		CLC
		ADC		#$08
		STA		_tmp12
		BCC		loc_62727
		INC		_tmp11
		JMP		loc_62727
loc_6271A:
		SEC
		LDA		_tmp12
		SBC		#$08
		STA		_tmp12
		LDA		_tmp11
		SBC		#$00
		STA		_tmp11
loc_62727:
		LDA		_tmp01
		BEQ		locret_62734
		STA		_tmp00
		LDA		#$00
		STA		_tmp01
		JMP		_obj_get_prize_spr_insert
locret_62734:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_get_prize_spr_tile_ofs:
		LDA		_tmp0E
		AND		#$3F
		ASL
		TAY
		LDA		_spr_prize_tile_lib,Y
		STA		_tmp0A
		LDA		_spr_prize_tile_lib+1,Y
		STA		_tmp0B
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_move_animate_common:
		LDA		_tmp11
		EOR		_tmp02
		AND		#$80
		BNE		loc_6275A
		LDA		_tmp02
		AND		#$0F
		CLC
		ADC		_tmp10
		STA		_tmp10
		JMP		loc_62775
loc_6275A:
		LDA		_tmp02
		AND		#$0F
		STA		_tmp04
		SEC
		LDA		_tmp10
		SBC		_tmp04
		STA		_tmp10
		BPL		loc_62775
		LDA		#$FF
		EOR		_tmp10
		STA		_tmp10
		LDA		_tmp11
		EOR		#$80
		STA		_tmp11
loc_62775:
		LDA		_tmp03
		CMP		_tmp10
		BCS		loc_6277D
		STA		_tmp10
loc_6277D:
		BIT		_tmp11
		BMI		loc_6278B
		LDA		_tmp0E
		CLC
		ADC		_tmp10
		STA		_tmp0E
		JMP		loc_62792
loc_6278B:
		SEC
		LDA		_tmp0E
		SBC		_tmp10
		STA		_tmp0E
loc_62792:
		LDA		_tmp11
		EOR		_tmp00
		AND		#$40
		BNE		loc_627A6
		LDA		_tmp00
		AND		#$0F
		CLC
		ADC		_tmp0F
		STA		_tmp0F
		JMP		loc_627C3
loc_627A6:
		LDA		_tmp00
		AND		#$0F
		STA		_tmp04
		SEC
		LDA		_tmp0F
		SBC		_tmp04
		STA		_tmp0F
		BPL		loc_627C3
		LDA		#$FF
		EOR		_tmp0F
		INC		_tmp0F
		STA		_tmp0F
		LDA		_tmp11
		EOR		#$40
		STA		_tmp11
loc_627C3:
		LDA		_tmp01
		CMP		_tmp0F
		BCS		loc_627CB
		STA		_tmp0F
loc_627CB:
		BIT		_tmp11
		BVS		loc_627E1
		LDA		_tmp0D
		CLC
		ADC		_tmp0F
		STA		_tmp0D
		LDA		_tmp0C
		ADC		#$00
		AND		#$3F
		STA		_tmp0C
		RTS
loc_627E1:
		SEC
		LDA		_tmp0D
		SBC		_tmp0F
		STA		_tmp0D
		LDA		_tmp0C
		SBC		#$00
		AND		#$3F
		STA		_tmp0C
locret_627F0:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_hndl00_rambo:
		LDA		_game._flags+1
		AND		#$10
		BEQ		loc_62812
		INC		_objsA._player._hndl_idx
		LDA		_game._flags
		AND		#$80
		BEQ		loc_62803
		INC		_objsA._player._hndl_idx
loc_62803:
		LDA		#$90
		STA		_objsA._player.field_7
		LDA		#$00
		STA		_objsA._player.field_8
		LDA		#$06
		STA		_objsA._player.field_9
		JMP		_obj_flush_and_continue
loc_62812:
		LDA		_tmp11
		AND		#$08
		BEQ		loc_62856
		LDA		#$04
		STA		_tmp0B
		LDA		_apu_cur_mus_idx
		CMP		#$09
		BNE		loc_62841
		INC		_objsA._player._timer
		LDA		_objsA._player._timer
		AND		#$01
		BEQ		loc_62836
		LDA		_ppu_mask_shadow
		AND		#$FE
		STA		_ppu_mask_shadow
		JMP		_obj_flush_and_continue
loc_62836:
		LDA		_ppu_mask_shadow
		ORA		#$01
		STA		_ppu_mask_shadow
		JMP		_obj_flush_and_continue
loc_62841:
		LDA		_ppu_mask_shadow
		AND		#$FE
		STA		_ppu_mask_shadow
		LDA		#$84
		STA		_game._scr_idx
		LDA		#$01
		STA		_game._redraw_req
		JMP		_obj_flush_and_continue
loc_62856:
		LDA		_tmp11
		AND		#$01
		BNE		loc_62863
		LDA		#$03
		BNE		loc_62867
loc_62863:
		LDA		#$04
loc_62867:
		STA		_tmp01
		LDA		#$0F
		STA		_tmp03
		LDA		#$01
		STA		_tmp02
		LDA		#$00
		STA		_tmp00
		LDA		_tmp11
		AND		#$20
		BEQ		loc_628D5
		LDA		_tmp0B
		CMP		#$04
		BNE		loc_6289E
		DEC		_objsA._player._timer
		LDA		_objsA._player._timer
		CMP		#$18
		BEQ		loc_62891
		LDA		#$40
		AND		_pad
		BNE		loc_62891
		JMP		loc_62AA3
loc_62891:
		LDA		_tmp11
		EOR		#$40
		STA		_tmp11
		LDA		#$00
		STA		_tmp0B
		BEQ		loc_628D5
loc_6289E:
		DEC		_objsA._player._timer
		BNE		loc_628D5
		LDA		_tmp11
		AND		#$DF
		STA		_tmp11
		LDA		_game._life
		BNE		loc_628D5
		LDA		_game._life+1
		BNE		loc_628D5
		LDA		_game._flags+2
		AND		#$80
		BNE		loc_628D5
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
		LDA		_ppu_ctrl_shadow
		AND		#$7F
		STA		_PPU_CTRL
		LDA		#$09
		JSR		_apu_cur_mus_load
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
loc_628D5:
		LDA		_objsA._player._state
		BPL		loc_62900
		LDA		#$04
		STA		_tmp0B
		LDA		#$80
		STA		_objsA._player.field_7
		LDA		#$00
		STA		_objsA._player.field_8
		LDA		#$05
		STA		_objsA._player.field_9
		LDA		_tmp11
		EOR		#$C0
		ORA		#$20
		STA		_tmp11
		LDA		#$03
		STA		_tmp0F
		LDA		#$01
		STA		_tmp10
		LDA		#$20
		STA		_objsA._player._timer
		JMP		loc_62AA3
loc_62900:
		LDA		#$04
		AND		_objsA._player._state
		BEQ		loc_62909
		JMP		loc_6298C
loc_62909:
		LDA		#$08
		AND		_objsA._player._state
		BEQ		loc_6291F
		LDA		_tmp0E
		CMP		#$48
		BCC		loc_6291F
		LDA		#$01
		STA		_tmp10
		LDA		_tmp11
		AND		#$7F
		STA		_tmp11
loc_6291F:
		LDA		_tmp0B
		CMP		#$06
		BCC		loc_6293A
		LDA		_objsA._player._hndl_idx
		AND		#$40
		BNE		loc_6293A
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
		JSR		_rambo_weapon_manager
		JSR		_rambo_crouch_test
		JMP		loc_62AAC
loc_6293A:
		LDX		_cur_weapon_selected
		LDA		_game._exp_level,X
		BNE		loc_62947
		LDA		#$00
		STA		_cur_weapon_selected
loc_62947:
		LDX		#$00
		LDA		#$05
		STA		_tmp0B
		LDA		#$FE
		STA		_objsA._player.field_7
		LDA		#$00
		STA		_objsA._player.field_8
		LDA		#$06
		STA		_objsA._player.field_9
		LDA		#$01
		AND		_pad
		BEQ		loc_62964
		LDA		#$01
		STA		_tmp00
loc_62964:
		LDA		#$02
		AND		_pad
		BEQ		loc_6296F
		LDA		#$41
		STA		_tmp00
loc_6296F:
		LDA		#$40
		AND		_pad
		BEQ		loc_62989
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
		LDA		#$00
		STA		_tmp00
		JSR		_player_weapon_projectile_deploy
		JSR		_rambo_crouch_test
		JMP		loc_62AAC
loc_62989:
		JMP		loc_62AA3
loc_6298C:
		LDA		#$00
		STA		_tmp10
		LDA		#$80
		AND		_pad
		BEQ		loc_629D5
		LDA		#$05
		STA		_tmp0B
		LDA		#$FE
		STA		_objsA._player.field_7
		LDA		#$00
		STA		_objsA._player.field_8
		LDA		#$06
		STA		_objsA._player.field_9
		LDA		_tmp11
		ORA		#$80
		STA		_tmp11
		LDA		#$04
		AND		_pad
		BNE		loc_629C8
		LDA		_tmp11
		AND		#$02
		BNE		loc_629C1
		LDA		#$09
		BNE		loc_629CC
loc_629C1:
		LDA		#$0C
		BNE		loc_629CC
loc_629C8:
		LDA		#$06
loc_629CC:
		STA		_tmp10
		LDA		_tmp0F
		BEQ		loc_629D2
		INC		_tmp10
loc_629D2:
		JMP		loc_62AA3
loc_629D5:
		LDA		_tmp0B
		CMP		#$06
		BCC		loc_629F6
		LDA		_objsA._player._hndl_idx
		AND		#$40
		BNE		loc_629F6
		LDA		_tmp0F
		BEQ		loc_629E7
		DEC		_tmp0F
loc_629E7:
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
		JSR		_rambo_weapon_manager
		JSR		_rambo_crouch_test
		JMP		loc_62AAC
loc_629F6:
		LDX		_cur_weapon_selected
		LDA		_game._exp_level,X
		BNE		loc_62A03
		LDA		#$00
		STA		_cur_weapon_selected
loc_62A03:
		LDX		#$00
		LDA		#$04
		AND		_pad
		BEQ		loc_62A3F
		LDA		#$03
		STA		_tmp0B
		LDA		#$FE
		STA		_objsA._player.field_7
		LDA		#$00
		STA		_objsA._player.field_8
		LDA		#$04
		STA		_objsA._player.field_9
		LDA		#$40
		AND		_pad
		BEQ		loc_62A3C
		LDA		_tmp0F
		BEQ		loc_62A29
		DEC		_tmp0F
loc_62A29:
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
		LDA		#$08
		STA		_tmp00
		JSR		_player_weapon_projectile_deploy
		JSR		_rambo_crouch_test
		JMP		loc_62AAC
loc_62A3C:
		JMP		loc_62A9D
loc_62A3F:
		LDA		#$40
		AND		_pad
		BEQ		loc_62A5F
		LDA		_tmp0F
		BEQ		loc_62A4C
		DEC		_tmp0F
loc_62A4C:
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
		LDA		#$00
		STA		_tmp00
		JSR		_player_weapon_projectile_deploy
		JSR		_rambo_crouch_test
		JMP		loc_62AAC
loc_62A5F:
		LDA		#$01
		AND		_pad
		BEQ		loc_62A70
		LDA		#$01
		STA		_tmp00
		JSR		_rambo_state_adjust
		JMP		loc_62AA3
loc_62A70:
		LDA		#$02
		AND		_pad
		BEQ		loc_62A81
		LDA		#$41
		STA		_tmp00
		JSR		_rambo_state_adjust
		JMP		loc_62AA3
loc_62A81:
		LDA		_tmp0B
		CMP		#$05
		BNE		loc_62A9A
		LDA		#$06
		STA		_tmp0B
		LDA		#$FE
		STA		_objsA._player.field_7
		LDA		#$00
		STA		_objsA._player.field_8
		LDA		#$04
		STA		_objsA._player.field_9
		JMP		loc_62A9D
loc_62A9A:
		JSR		_rambo_state_adjust
loc_62A9D:
		LDA		_tmp0F
		BEQ		loc_62AA3
		DEC		_tmp0F
loc_62AA3:
		JSR		_obj_move_animate_common
		JSR		_rambo_crouch_test
		JSR		_obj_get_hor_delta16
loc_62AAC:
		LDA		_tmp11
		AND		#$20
		BEQ		loc_62ABA
		LDA		_objsA._player.field_7
		AND		#$C0
		ORA		#$10
		STA		_objsA._player.field_7
loc_62ABA:
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_rambo_state_adjust:
		LDA		_objsA._player._state
		AND		#$20
		BNE		loc_62AD3
		LDA		_objsA._player._state
		AND		#$10
		BEQ		loc_62AD3
		LDA		_tmp11
		AND		#$01
		BNE		loc_62AD3
		LDA		#$01
		STA		_tmp01
loc_62AD3:
		LDA		_tmp0F
		CMP		#$03
		BCS		loc_62AE4
		CMP		#$00
		BEQ		loc_62AEB
		LDA		#$01
		BNE		loc_62AEF
loc_62AE4:
		LDA		#$02
		BNE		loc_62AEF
loc_62AEB:
		LDA		#$00
loc_62AEF:
		STA		_tmp0B
		LDA		#$FE
		STA		_objsA._player.field_7
		LDA		#$00
		STA		_objsA._player.field_8
		LDA		#$06
		STA		_objsA._player.field_9
		RTS

; =============== S U B	R O U T	I N E =======================================
_player_weapon_projectile_deploy:
		LDA		_cur_weapon_selected
		ASL
		ASL
		ASL
		ASL
		CLC
		ADC		_tmp00
		TAY
		LDA		_weapons_data_tbl,Y
		STA		_tmp0B
		LDA		#$FE
		STA		_objsA._player.field_7
		LDA		#$00
		STA		_objsA._player.field_8
		LDA		_weapons_data_tbl+1,Y
		STA		_objsA._player.field_9
		LDA		_cur_weapon_selected
		CMP		#$06
		BNE		locret_62B45
		TAY
		LDA		_game._exp_level,Y
		BEQ		loc_62B40
		LDA		_cur_weapon_selected
		TAX
		DEC		_game._exp_level,X
		LDX		#$00
		LDA		_game._life
		CLC
		ADC		#$64
		STA		_game._life
		BCC		loc_62B40
		INC		_game._life+1
loc_62B40:
		LDA		#$00
		STA		_cur_weapon_selected
locret_62B45:
		RTS

; =============== S U B	R O U T	I N E =======================================
_objB_insert:
		TXA
		PHA
		LDA		#$00
		STA		_tmp08
loc_62B4C:
		LDA		_tmp08
		ASL
		ASL
		ASL
		TAX
		LDA		_objsB._o0._hndl_idx,X
		BPL		loc_62B7E
		LDA		_tmp00
		STA		_objsB._o0._hndl_idx,X
		LDA		_tmp01
		STA		_objsB._o0.field_1,X
		LDA		_tmp02
		STA		_objsB._o0.field_2,X
		LDA		_tmp03
		STA		_objsB._o0.field_3,X
		LDA		_tmp04
		STA		_objsB._o0.field_4,X
		LDA		_tmp05
		STA		_objsB._o0.field_5,X
		LDA		_tmp06
		STA		_objsB._o0.field_6,X
		LDA		_tmp07
		STA		_objsB._o0.field_7,X
		LDA		_tmp13
		STA		_apu_se_noise_idx
		JMP		loc_62B86
loc_62B7E:
		INC		_tmp08
		LDA		_tmp08
		CMP		#$04
		BNE		loc_62B4C
loc_62B86:
		PLA
		TAX
		RTS
; ---------------------------------------------------------------------------
_weapons_data_tbl:
		.BYTE $07,$36,$00,$10,$19,$24,$00,$04,$08,$54,$00,$10,$08,$24,$00,$04
		.BYTE $07,$36,$01,$10,$19,$04,$60,$0C,$08,$54,$01,$10,$08,$04,$60,$0C
		.BYTE $09,$06,$02,$08,$19,$24,$60,$10,$0A,$04,$02,$08,$08,$24,$60,$10
		.BYTE $09,$06,$03,$08,$19,$24,$60,$10,$0A,$04,$03,$08,$08,$24,$60,$10
		.BYTE $0B,$06,$04,$08,$19,$02,$60,$FF,$0C,$04,$04,$08,$08,$02,$60,$FF
		.BYTE $0D,$06,$05,$00,$20,$81,$57,$20,$0E,$04,$05,$00,$10,$81,$57,$20
		.BYTE $00,$06,$80,$00,$00,$00,$00,$00,$03,$04,$80,$00,$00,$00,$00,$00
_weapon_se_tbl:
		.BYTE SEN01
		.BYTE SEN02
		.BYTE SEN05
		.BYTE SEN05
		.BYTE SEN04|$80
		.BYTE SEN01|$80
		.BYTE SEN01
_wapon_damage_tbl:
		.BYTE $01,$02,$03,$06,$0C,$18,$30,$60,$C0

; =============== S U B	R O U T	I N E =======================================
_rambo_weapon_manager:
		LDA		_tmp0B
		CMP		#$06
		BEQ		locret_62C44
		CMP		#$07
		BEQ		loc_62C1A
		CMP		#$08
		BEQ		loc_62C2F
		BNE		loc_62C45
loc_62C1A:
		LDA		_objsA._player.field_2
		CMP		#$09
		BNE		locret_62C44
		LDA		#$FE
		STA		_objsA._player.field_7
		LDA		#$90
		STA		_objsA._player.field_8
		LDA		#$16
		STA		_objsA._player.field_9
		BNE		loc_62C6B
loc_62C2F:
		LDA		_objsA._player.field_2
		CMP		#$09
		BNE		locret_62C44
		LDA		#$FE
		STA		_objsA._player.field_7
		LDA		#$90
		STA		_objsA._player.field_8
		LDA		#$06
		STA		_objsA._player.field_9
		BNE		loc_62C6B
locret_62C44:
		RTS
loc_62C45:
		CMP		#$0B
		BEQ		loc_62C50
		CMP		#$0C
		BNE		loc_62C62
loc_62C50:
		LDA		#$40
		AND		_pad
		BEQ		loc_62C62
		LDA		#$FE
		STA		_objsA._player.field_7
		LDA		#$08
		STA		_objsA._player.field_2
		BNE		loc_62C6B
loc_62C62:
		LDA		_objsA._player.field_2
		CMP		#$05
		BEQ		loc_62C6B
		RTS
loc_62C6B:
		LDA		_game._exp_level
		TAY
		LDA		_wapon_damage_tbl,Y
		STA		_objsA._player._damage
		LDA		_cur_weapon_selected
		BNE		loc_62C7D
		LDA		#$FF
		STA		_objsA._player._damage
loc_62C7D:
		LDA		_cur_weapon_selected
		CMP		#$05
		BNE		loc_62C88
		LDA		#$80
		STA		_objsA._player._damage
loc_62C88:
		LDA		_cur_weapon_selected
		TAY
		BEQ		loc_62C9F
		LDA		_game._exp_level,Y
		BNE		loc_62C96
		RTS
loc_62C96:
		LDA		_cur_weapon_selected
		TAX
		DEC		_game._exp_level,X
		LDX		#$00
loc_62C9F:
		LDA		_weapon_se_tbl,Y
		BMI		loc_62CA9
		STA		_tmp13
		JMP		loc_62CB3
loc_62CA9:
		AND		#$7F
		STA		_tmp13
		LDA		_tmp11
		ORA		#$04
		STA		_tmp11
loc_62CB3:
		LDA		_cur_weapon_selected
		ASL
		ASL
		ASL
		ASL
		TAY
		LDA		_tmp0B
		LSR
		BCS		loc_62CC5
		TYA
		CLC
		ADC		#$08
		TAY
loc_62CC5:
		LDA		_weapons_data_tbl+2,Y
		STA		_tmp00
		BIT		_tmp11
		BVS		loc_62CDF
		LDA		_tmp0D
		CLC
		ADC		_weapons_data_tbl+3,Y
		STA		_tmp02
		LDA		_tmp0C
		ADC		#$00
		STA		_tmp01
		JMP		loc_62CED
loc_62CDF:
		SEC
		LDA		_tmp0D
		SBC		_weapons_data_tbl+3,Y
		STA		_tmp02
		LDA		_tmp0C
		SBC		#$00
		STA		_tmp01
loc_62CED:
		SEC
		LDA		_tmp0E
		SBC		_weapons_data_tbl+4,Y
		STA		_tmp03
		LDA		_tmp11
		AND		#$40
		ORA		_weapons_data_tbl+5,Y
		STA		_tmp04
		LDA		_objsA._player._damage
		STA		_tmp05
		LDA		_weapons_data_tbl+6,Y
		STA		_tmp06
		LDA		_cur_weapon_selected
		CMP		#$05
		BNE		loc_62D18
		LDA		_tmp11
		AND		#$80
		BEQ		loc_62D18
		LDA		#$49
		STA		_tmp06
loc_62D18:
		LDA		_weapons_data_tbl+7,Y
		STA		_tmp07
		JSR		_objB_insert
locret_62D20:
		RTS

; =============== S U B	R O U T	I N E =======================================
_rambo_crouch_test:
		LDA		_tmp0B
		CMP		#$05
		BNE		locret_62D3D
		LDA		#$04
		AND		_pad
		BEQ		loc_62D37
		LDA		_objsA._player.field_7
		AND		#$BF
		STA		_objsA._player.field_7
		RTS
loc_62D37:
		LDA		_objsA._player.field_7
		ORA		#$40
		STA		_objsA._player.field_7
locret_62D3D:
		RTS

; =============== S U B	R O U T	I N E =======================================
_player_control_co:
		LDA		_tmp11
		AND		#$DF
		STA		_tmp11
		LDA		#$02
		STA		_tmp01
		LDA		#$09
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_62D6D
		LDA		#$80
		AND		_pad
		BEQ		loc_62D99
		LDA		#$00
		STA		_tmp0B
		LDA		_tmp11
		ORA		#$80
		STA		_tmp11
		LDA		#$09
		STA		_tmp10
		BNE		loc_62D99
loc_62D6D:
		LDA		#$08
		AND		_objsA._player._state,X
		BEQ		loc_62D83
		LDA		_tmp0E
		CMP		#$48
		BCC		loc_62D83
		LDA		#$01
		STA		_tmp10
		LDA		_tmp11
		AND		#$7F
		STA		_tmp11
loc_62D83:
		LDA		#$04
		AND		_pad
		BEQ		loc_62D93
		LDA		_objsA._player.field_7,X
		AND		#$BF
		STA		_objsA._player.field_7,X
		JMP		loc_62D99
loc_62D93:
		LDA		_objsA._player.field_7,X
		ORA		#$40
		STA		_objsA._player.field_7,X
loc_62D99:
		LDA		#$01
		AND		_pad
		BEQ		loc_62DB1
		LDA		#$01
		STA		_tmp0B
		LDA		_tmp11
		AND		#$BF
		STA		_tmp11
		LDA		#$02
		BNE		loc_62DD1
loc_62DB1:
		LDA		#$02
		AND		_pad
		BEQ		loc_62DC9
		LDA		#$01
		STA		_tmp0B
		LDA		_tmp11
		ORA		#$40
		STA		_tmp11
		LDA		#$02
		BNE		loc_62DD1
loc_62DC9:
		LDA		#$00
		STA		_tmp0B
		LDA		#$00
loc_62DD1:
		STA		_tmp0F
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_hud_num_idx_adjust_hi:
		LSR
		LSR
		LSR
		LSR

; =============== S U B	R O U T	I N E =======================================
_hud_num_idx_adjust_ex:
		CMP		#$0A
		BCS		loc_62DE3
		RTS
loc_62DE3:
		CLC
		ADC		#$1E
		RTS

; =============== S U B	R O U T	I N E =======================================
_hud_num_idx_adjust_lo:
		AND		#$0F
		JMP		_hud_num_idx_adjust_ex

; =============== S U B	R O U T	I N E =======================================
_hex_to_dec:
		LDA		#$00
		STA		_tmp02
		STA		_tmp03
		STA		_tmp04
		STA		_tmp05
loc_62DF6:
		JSR		_cmp1000
		BCC		loc_62E03
		JSR		_sub1000
		INC		_tmp05
		JMP		loc_62DF6
loc_62E03:
		JSR		_cmp100
		BCC		loc_62E10
		JSR		_sub100
		INC		_tmp04
		JMP		loc_62E03
loc_62E10:
		LDA		_tmp00
loc_62E12:
		CMP		#$0A
		BCS		loc_62E19
		STA		_tmp02
		RTS
loc_62E19:
		SEC
		SBC		#$0A
		INC		_tmp03
		JMP		loc_62E12

; =============== S U B	R O U T	I N E =======================================
_cmp1000:
		LDA		_tmp01
		CMP		#$03
		BEQ		loc_62E28
		RTS
loc_62E28:
		LDA		_tmp00
		CMP		#$E8
		RTS

; =============== S U B	R O U T	I N E =======================================
_cmp100:
		LDA		_tmp01
		CMP		#$00
		BEQ		loc_62E34
		RTS
loc_62E34:
		LDA		_tmp00
		CMP		#$64
		RTS

; =============== S U B	R O U T	I N E =======================================
_sub1000:
		LDA		_tmp00
		SEC
		SBC		#$E8
		STA		_tmp00
		LDA		_tmp01
		SBC		#$03
		STA		_tmp01
		RTS

; =============== S U B	R O U T	I N E =======================================
_sub100:
		LDA		_tmp00
		SEC
		SBC		#$64
		STA		_tmp00
		LDA		_tmp01
		SBC		#$00
		STA		_tmp01
		RTS

; =============== S U B	R O U T	I N E =======================================
NMI:
		PHA
		TYA
		PHA
		TXA
		PHA
		LDA		_tmp00
		PHA
		LDA		_tmp01
		PHA
		LDA		_tmp02
		PHA
		LDA		_tmp03
		PHA
		LDA		_tmp04
		PHA
		LDA		_tmp05
		PHA
		LDA		_tmp06
		PHA
		LDA		_tmp07
		PHA
		LDA		_tmp08
		PHA
		LDA		_tmp09
		PHA
		LDA		_tmp0A
		PHA
		LDA		_tmp0B
		PHA
		JSR		_nmi_sub
		PLA
		STA		_tmp0B
		PLA
		STA		_tmp0A
		PLA
		STA		_tmp09
		PLA
		STA		_tmp08
		PLA
		STA		_tmp07
		PLA
		STA		_tmp06
		PLA
		STA		_tmp05
		PLA
		STA		_tmp04
		PLA
		STA		_tmp03
		PLA
		STA		_tmp02
		PLA
		STA		_tmp01
		PLA
		STA		_tmp00
		PLA
		TAX
		PLA
		TAY
		PLA
		RTI

; =============== S U B	R O U T	I N E =======================================
_nmi_sub:
		LDA		#$02
		STA		_PPU_OAM_DMA
		INC		_nmi_flag
		LDA		_nmi_disable
		BEQ		loc_62EBA
		JMP		_nmi_finish
loc_62EBA:
		LDA		_nmi_disble_ppu_reset_req
		BPL		loc_62EC5
		LDA		_PPU_STATUS
		JMP		_nmi_finish
loc_62EC5:
		LDA		#$00
		STA		_PPU_MASK
		JSR		_game_time_do_count
		LDA		_game._scr_idx
		CMP		#$FF
		BNE		loc_62F3D
		LDA		_game._redraw_req
		BEQ		loc_62EDC
		JMP		loc_62F3D
loc_62EDC:
		INC		_ppu_status_shadow
		LDA		_ppu_status_shadow
		AND		#$7F
		CMP		#$04
		BCC		loc_62EF0
		LDA		_ppu_status_shadow
		AND		#$80
		STA		_ppu_status_shadow
loc_62EF0:
		LDA		_PPU_STATUS
		LDA		#$21
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDX		#$20
		LDA		#$30
loc_62F01:
		STA		_PPU_DATA
		DEX
		BNE		loc_62F01
		LDA		_PPU_STATUS
		LDA		#$21
		STA		_PPU_ADDR
		LDA		#$11
		STA		_PPU_ADDR
		LDX		#$0E
		LDY		#$30
		LDA		_ppu_status_shadow
		AND		#$01
		BEQ		loc_62F34
		LDA		_ppu_status_shadow
		AND		#$7F
		CMP		#$03
		BNE		loc_62F2A
		LDY		#$40
loc_62F2A:
		STY		_PPU_DATA
		INY
		DEX
		BNE		loc_62F2A
		JMP		loc_63096
loc_62F34:
		STY		_PPU_DATA
loc_62F37:
		DEX
		BNE		loc_62F37
		JMP		loc_63096
loc_62F3D:
		LDA		_cur_pal_bg_idx
		ORA		_cur_pal_spr_lib
		BMI		loc_62F48
		JMP		loc_63096
loc_62F48:
		LDA		_pal_fade_delay
		BEQ		loc_62F53
		DEC		_pal_fade_delay
		JMP		loc_63096
loc_62F53:
		LDA		#$06
		STA		_pal_fade_delay
		LDA		_cur_pal_bg_idx
		AND		#$30
		BEQ		loc_62FA2
		LDA		_cur_pal_bg_idx
		AND		#$40
		BEQ		loc_62F6C
		JSR		_nmi_pal_fade_out
		JMP		loc_62F6F
loc_62F6C:
		JSR		_nmi_pal_fade_in
loc_62F6F:
		LDA		_cur_pal_bg_idx
		SEC
		SBC		#$10
		STA		_cur_pal_bg_idx
		LDA		_cur_pal_spr_lib
		SEC
		SBC		#$10
		STA		_cur_pal_spr_lib
		LDA		_cur_pal_bg_idx
		AND		#$40
		BEQ		loc_62FFA
		LDA		_cur_pal_bg_idx
		AND		#$30
		BNE		loc_62FFA
		LDA		_cur_pal_bg_idx
		AND		#$0F
		STA		_cur_pal_bg_idx
		LDA		_cur_pal_spr_lib
		AND		#$0F
		STA		_cur_pal_spr_lib
		JMP		loc_62FFA
loc_62FA2:
		LDA		_cur_pal_bg_idx
		AND		#$0F
		STA		_cur_pal_bg_idx
		ASL
		ASL
		ASL
		ASL
		TAX
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		_pal_bg_lib,X
		STA		_tmp00
		LDY		#$10
loc_62FC3:
		LDA		_pal_bg_lib,X
		STA		_PPU_DATA
		INX
		DEY
		BNE		loc_62FC3
		LDA		_cur_pal_spr_lib
		AND		#$0F
		STA		_cur_pal_spr_lib
		ASL
		ASL
		ASL
		ASL
		TAX
		LDY		#$04
loc_62FDC:
		LDA		_tmp00
		STA		_PPU_DATA
		LDA		_pal_spr_lib+1,X
		STA		_PPU_DATA
		LDA		_pal_spr_lib+2,X
		STA		_PPU_DATA
		LDA		_pal_spr_lib+3,X
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_62FDC
loc_62FFA:
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		JMP		loc_630FA
loc_63010:
		LDA		_ppu_dequeue_idx
		BNE		loc_63018
		JMP		loc_630E8
loc_63018:
		DEC		_ppu_dequeue_idx
		BEQ		loc_63046
		DEC		_ppu_dequeue_idx
		LDX		#$00
loc_63022:
		LDA		_PPU_STATUS
		LDA		_ppu_queue_buf,X
		BEQ		loc_6303F
		STA		_PPU_ADDR
		INX
		LDY		_ppu_queue_buf,X
		STY		_PPU_ADDR
		INX
		LDY		_ppu_queue_buf,X
		STY		_PPU_DATA
		INX
		JMP		loc_63022
loc_6303F:
		LDA		#<[_ppu_queue_buf]
		STA		_ppu_queue_buf_ofs
		JMP		loc_6308C
loc_63046:
		CLC
		LDA		#$94
		STA		_PPU_CTRL
		LDY		#$00
		LDA		_PPU_STATUS
		LDA		_ppu_room_line_pos
		STA		_PPU_ADDR
		LDA		_ppu_room_line_pos+1
		STA		_PPU_ADDR
loc_6305B:
		LDA		(_ppu_room_line_ptr),Y
		TAX
		STX		_PPU_DATA
		INX
		INX
		STX		_PPU_DATA
		INY
		CPY		#$0D
		BNE		loc_6305B
		LDA		_PPU_STATUS
		LDA		_ppu_room_line_pos
		STA		_PPU_ADDR
		LDY		_ppu_room_line_pos+1
		INY
		STY		_PPU_ADDR
		LDY		#$00
loc_6307B:
		LDA		(_ppu_room_line_ptr),Y
		TAX
		INX
		STX		_PPU_DATA
		INX
		INX
		STX		_PPU_DATA
		INY
		CPY		#$0D
		BNE		loc_6307B
loc_6308C:
		LDA		_ppu_mask_shadow
		AND		#$DF
		BNE		loc_630FA
		JMP		_nmi_finish
loc_63096:
		LDA		_chr_tiles_send_dst+1
		BNE		loc_6309E
		JMP		loc_63010
loc_6309E:
		LDA		_chr_tiles_send_src
		STA		_tmp00
		LDA		_chr_tiles_send_src+1
		STA		_tmp01
		LDA		_PPU_STATUS
		LDA		_chr_tiles_send_dst+1
		STA		_PPU_ADDR
		LDA		_chr_tiles_send_dst
		STA		_PPU_ADDR
		LDA		#$03
		JSR		_mmc_prg_set
		LDY		_chr_tiles_send_dst
loc_630C2:
		LDA		(_tmp00),Y
		STA		_PPU_DATA
		INY
		TYA
		AND		#$0F
		BNE		loc_630C2
		LDA		#$06
		JSR		_mmc_prg_set
		LDA		_chr_tiles_send_dst
		CLC
		ADC		#$10
		STA		_chr_tiles_send_dst
		BNE		loc_6308C
		LDA		#$00
		STA		_chr_tiles_send_dst+1
		BEQ		loc_6308C
loc_630E8:
		LDA		_ppu_mask_shadow
		AND		#$DF
		BNE		loc_630F2
		JMP		_nmi_finish
loc_630F2:
		LDA		#$90
		STA		_PPU_CTRL
		JSR		_hud_decimals_draw_update
loc_630FA:
		LDA		_PPU_STATUS
		AND		#$40
		BNE		loc_630FA
		LDA		_room_scroll_pos_x+1
		AND		#$01
		BEQ		loc_6310B
		LDA		#$24
; ---------------------------------------------------------------------------
		.BYTE $2C
; ---------------------------------------------------------------------------
loc_6310B:
		LDA		#$20
		STA		_tmp01
		LDA		_room_scroll_pos_x
		LSR
		LSR
		LSR
		STA		_tmp00
		LDA		_PPU_STATUS
		LDA		_tmp01
		STA		_PPU_ADDR
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_SCROLL
		STA		_PPU_SCROLL
		LDA		#$90
		STA		_PPU_CTRL
		LDA		_ppu_mask_shadow
		STA		_PPU_MASK
loc_63137:
		LDA		_PPU_STATUS
		AND		#$40
		BEQ		loc_63137
		LDA		_game._scr_idx
		CMP		#$FF
		BNE		loc_63159
		LDA		_final_boss_scroll_pos
		STA		_PPU_SCROLL
		LDA		#$00
		STA		_PPU_SCROLL
		LDA		_ppu_ctrl_shadow
		STA		_PPU_CTRL
		JMP		_nmi_finish
loc_63159:
		LDA		_room_scroll_pos_x
		STA		_PPU_SCROLL
		LDA		#$00
		STA		_PPU_SCROLL
		LDA		_room_scroll_pos_x+1
		AND		#$01
		ORA		#$90
		STA		_PPU_CTRL
		STA		_ppu_ctrl_shadow
_nmi_finish:
		LDA		_ingame_pause_flag
		BEQ		loc_6318A
		LDX		#$02
		LDA		_apu_se_pulse_cnt
		BNE		loc_63184
		LDA		_apu_se_pulse_idx
		BNE		loc_63184
		LDX		#$00
loc_63184:
		STX		_APU_STATUS
		JMP		loc_6318F
loc_6318A:
		LDA		#$0F
		STA		_APU_STATUS
loc_6318F:
		JMP		_apu_play

; =============== S U B	R O U T	I N E =======================================
_nmi_pal_fade_out:
		LDA		_cur_pal_bg_idx
		ASL
		ASL
		ASL
		ASL
		TAX
		LDA		_pal_bg_lib,X
		STA		_tmp00
		LDA		_cur_pal_bg_idx
		AND		#$30
		CMP		#$30
		BNE		loc_6321A
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDY		#$03
loc_631B8:
		LDA		_pal_bg_lib,X
		STA		_PPU_DATA
		LDA		_pal_bg_lib+1,X
		STA		_PPU_DATA
		LDA		_pal_bg_lib+2,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_631B8
		LDA		#$0F
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		LDA		_cur_pal_spr_lib
		ASL
		ASL
		ASL
		ASL
		TAX
		LDY		#$03
loc_631EE:
		LDA		_tmp00
		STA		_PPU_DATA
		LDA		_pal_spr_lib+1,X
		STA		_PPU_DATA
		LDA		_pal_spr_lib+2,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_631EE
		LDA		#$0F
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
locret_63219:
		RTS
loc_6321A:
		CMP		#$20
		BNE		loc_6328F
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDY		#$03
loc_6322D:
		LDA		_pal_bg_lib,X
		STA		_PPU_DATA
		LDA		_pal_bg_lib+1,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_6322D
		LDA		#$0F
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		LDA		_cur_pal_spr_lib
		ASL
		ASL
		ASL
		ASL
		TAX
		LDY		#$03
loc_63262:
		LDA		_tmp00
		STA		_PPU_DATA
		LDA		_pal_spr_lib+1,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_63262
		LDA		#$0F
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		RTS
loc_6328F:
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDY		#$03
loc_6329E:
		LDA		_pal_bg_lib,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_6329E
		LDA		#$0F
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		LDA		_cur_pal_spr_lib
		ASL
		ASL
		ASL
		ASL
		TAX
		LDY		#$03
loc_632D2:
		LDA		_tmp00
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_632D2
		LDA		#$0F
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		STA		_PPU_DATA
		RTS

; =============== S U B	R O U T	I N E =======================================
_nmi_pal_fade_in:
		LDA		_cur_pal_bg_idx
		ASL
		ASL
		ASL
		ASL
		TAX
		LDA		_pal_bg_lib,X
		STA		_tmp00
		LDA		_cur_pal_bg_idx
		AND		#$30
		CMP		#$30
		BNE		loc_63366
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDY		#$04
loc_63323:
		LDA		_pal_bg_lib,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_63323
		LDA		_cur_pal_spr_lib
		ASL
		ASL
		ASL
		ASL
		TAX
		LDY		#$04
loc_63349:
		LDA		_pal_spr_lib,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_63349
locret_63365:
		RTS
loc_63366:
		CMP		#$20
		BNE		loc_633C0
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDY		#$04
loc_63379:
		LDA		_pal_bg_lib,X
		STA		_PPU_DATA
		LDA		_pal_bg_lib+1,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_63379
		LDA		_cur_pal_spr_lib
		ASL
		ASL
		ASL
		ASL
		TAX
		LDY		#$04
loc_633A0:
		LDA		_pal_spr_lib,X
		STA		_PPU_DATA
		LDA		_pal_spr_lib+1,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_633A0
		RTS
loc_633C0:
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDY		#$04
loc_633CF:
		LDA		_pal_bg_lib,X
		STA		_PPU_DATA
		LDA		_pal_bg_lib+1,X
		STA		_PPU_DATA
		LDA		_pal_bg_lib+2,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_633CF
		LDA		_cur_pal_spr_lib
		ASL
		ASL
		ASL
		ASL
		TAX
		LDY		#$04
loc_633F7:
		LDA		_pal_spr_lib,X
		STA		_PPU_DATA
		LDA		_pal_spr_lib+1,X
		STA		_PPU_DATA
		LDA		_pal_spr_lib+2,X
		STA		_PPU_DATA
		LDA		#$0F
		STA		_PPU_DATA
		INX
		INX
		INX
		INX
		DEY
		BNE		loc_633F7
		RTS

; =============== S U B	R O U T	I N E =======================================
_hud_decimals_draw_update:
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$61
		STA		_PPU_ADDR
		LDY		#$00
		LDX		#$00
loc_63429:
		LDA		_hud_decimals_list,X
		CMP		#$FF
		BEQ		locret_6345C
		CMP		#$05
		BCC		loc_6343A
		STA		_PPU_DATA
		BCS		loc_63458
loc_6343A:
		CMP		#$01
		BEQ		loc_63455
		CMP		#$02
		BEQ		loc_6344F
		CMP		#$03
		BNE		loc_6344C
		JSR		_hud_decimal_putB
		JMP		loc_6344F
loc_6344C:
		JSR		_hud_decimal_putA
loc_6344F:
		JSR		_hud_decimal_putA
		JMP		loc_63458
loc_63455:
		JSR		_hud_decimal_putB
loc_63458:
		INX
		JMP		loc_63429
locret_6345C:
		RTS

; =============== S U B	R O U T	I N E =======================================
_hud_decimal_putA:
		LDA		_hud_decimals_buf,Y
		JSR		_hud_num_idx_adjust_hi
		STA		_PPU_DATA

; =============== S U B	R O U T	I N E =======================================
_hud_decimal_putB:
		LDA		_hud_decimals_buf,Y
		JSR		_hud_num_idx_adjust_lo
		STA		_PPU_DATA
		INY
		RTS
; ---------------------------------------------------------------------------
_hud_decimals_list:
		.BYTE $15,$03,$15,$04,$15,$0B,$01,$15,$02,$15,$02,$15,$02,$15,$02,$15
		.BYTE $0A,$01,$15,$0A,$01,$FF

; =============== S U B	R O U T	I N E =======================================
_game_time_do_count:
		INC		_pre_timer
		LDA		_pre_timer
		CMP		#$0A
		BCC		locret_634C6
		LDA		#$00
		STA		_pre_timer
		INC		_play_seconds
		LDA		_play_seconds
		CMP		#$3C
		BCC		locret_634C6
		LDA		#$00
		STA		_play_seconds
		INC		_game._play_minutes
		LDA		_game._play_minutes
		CMP		#$3C
		BCC		locret_634C6
		LDA		#$00
		STA		_game._play_minutes
		INC		_game._play_hours
		LDA		_game._play_hours
		CMP		#$18
		BCC		locret_634C6
		LDA		#$00
		STA		_game._play_hours
		INC		_game._play_days
locret_634C6:
		RTS

		SECTION_END "MAIN PROGRAM"

		SECTION_START
		INCLUDE	"..\apu_player.inc"
		SECTION_END "APU PLAYER"

		SECTION_START
		INCLUDE	"..\scroller.inc"
		SECTION_END "INTRO\ENDING SCROLLER"

		LAST_BANK_END 7,$10000

total_banks	= 8
total_size	= 8*16384
