
		ORG $8000

		BANK_START $06

		SECTION_START

; =============== S U B	R O U T	I N E =======================================
; here starts main object MAGIC!
;
_objA_manager:
		JSR		_obj_special_bonus_test_handler	; always check for rambo bonus
		JSR		_obj_rambo_shout_deploy_test	; as well as special projectile
		LDA		#$00
		STA		_tmp14					; init object counter here

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_objA_manager_loop:
		LDA		_tmp14					; fetch object one by one
		ASL
		ASL
		ASL
		ASL
		TAX
		LDA		_objsA._player._hndl_idx,X
		BMI		_objA_manager_next
		AND		#$3F
		ASL
		TAY
		LDA		_obj_hndl_lib,Y
		STA		_tmp00
		LDA		_obj_hndl_lib+1,Y
		STA		_tmp01
		JSR		_objA_fetch
		CPX		#$00
		BEQ		loc_51FE7				; explosion handlers are for enemies only
		LDA		_objsA._player._prize_idx,X
		BMI		loc_51FE7				; also check if explosion alredy started
		JSR		_enemy_explosion_handler; when replaced with explosion,
		BCS		_objA_flush_and_continue; run only explosion handler here
loc_51FE7:
		JMP		(_tmp00)				; or else run regular game object handler

; =============== S U B	R O U T	I N E =======================================
_objA_flush_and_continue:
		JSR		_objA_flush				; all obj handlers must return here manually

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_objA_manager_next:
		INC		_tmp14					; iterate up to 8 main objects
		LDA		_tmp14
		CMP		#$08
		BNE		_objA_manager_loop
		RTS

; =============== S U B	R O U T	I N E =======================================
_objA_fetch:
		LDA		_objsA._player._anim_phase_cnt,X
		LSR								; pre-load current object parameters
		LSR								; for faster calcs
		LSR
		LSR
		STA		_tmp0F
		LDA		_objsA._player._anim_phase_cnt,X
		AND		#$0F
		STA		_tmp10
		LDA		_objsA._player._room_num,X
		STA		_tmp0C
		LDA		_objsA._player._x_pos,X
		STA		_tmp0D
		LDA		_objsA._player._y_pos,X
		STA		_tmp0E
		LDA		_objsA._player._dir,X
		STA		_tmp11
		STA		_tmp12
		LDA		_objsA._player._anim_phase_idx,X
		AND		#$0F
		STA		_tmp0B
		RTS

; =============== S U B	R O U T	I N E =======================================
_objA_flush:
		LDA		_tmp0F					; flush object parameters back to
		ASL								; data slot
		ASL
		ASL
		ASL
		ORA		_tmp10
		STA		_objsA._player._anim_phase_cnt,X
		CPX		#$00
		BEQ		loc_52031				; all objects can't run out of location
		LDA		_tmp0C					; will always wrap around rooms 0-3
		AND		#$03					; but not for the player itself
		STA		_tmp0C
loc_52031:
		LDA		_tmp0C
		STA		_objsA._player._room_num,X
		LDA		_tmp0D
		STA		_objsA._player._x_pos,X
		LDA		_tmp0E
		STA		_objsA._player._y_pos,X
		LDA		_tmp11
		STA		_objsA._player._dir,X
		LDA		_objsA._player._anim_phase_idx,X
		AND		#$F0
		ORA		_tmp0B
		STA		_objsA._player._anim_phase_idx,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_objA_frontal_collision_line_calc:
		LDA		_tmp11					; recalc only if direction is changed
		EOR		_tmp12
		ASL
		ASL
		BCC		locret_52075			; calc the line 16 pixels forward in
		LDA		#$40					; moving direction of the object
		BIT		_tmp11
		BNE		loc_52068
		LDA		_tmp0D
		SEC
		SBC		#$0F
		STA		_tmp0D
		BCS		locret_52067
		DEC		_tmp0C
locret_52067:
		RTS
loc_52068:
		LDA		_tmp0D
		CLC
		ADC		#$0F
		STA		_tmp0D
		BCC		locret_52075
		INC		_tmp0C
locret_52075:
		RTS

; =============== S U B	R O U T	I N E =======================================
_enemy_explosion_handler:
		JSR		_explosion_start_and_prize_deploy
		LDA		_objsA._player.field_C,X
		BEQ		loc_52097
		JSR		_explosion_animate		; do explosion anim
		LDA		_tmp11
		AND		#$20
		BNE		loc_52097				; test if main handler need blocking
		CLC
		RTS
loc_52097:
		SEC								; return C=1 to block main handler
		RTS

; =============== S U B	R O U T	I N E =======================================
; when main object is killed, it turns into explosion object
; and deploy simple moving projectile with prize icon
;
_explosion_start_and_prize_deploy:
		LDA		_objsA._player.field_C,X
		BNE		locret_52107
		LDA		#_obj_hndl3F_multipurpose_idx
		STA		_objsA._player._hndl_idx,X
		LDA		#$F0
		STA		_objsA._player._anim_phase_idx,X
		LDA		#$01
		STA		_tmp0B					; select explosion area size
		LDA		_objsA._player._collision_box_idx,X
		AND		#$0F					; depending of the size of collision box
		CMP		#$08
		BCS		loc_520CE
		CMP		#$05
		BCS		loc_520C7
		CMP		#$03
		BCS		loc_520C0
		LDA		#$01
		BNE		loc_520D2
loc_520C0:
		LDA		#$02
		BNE		loc_520D2
loc_520C7:
		LDA		#$03
		BNE		loc_520D2
loc_520CE:
		LDA		#$04
loc_520D2:
		STA		_tmp0B
		LDA		#$00
		STA		_objsA._player.field_7,X
		STA		_objsA._player.field_8,X
		LDA		#$06
		STA		_tmp13
		LDA		_objsA._player._prize_idx,X
		AND		#$1F
		STA		_tmp00
		LDA		_tmp0C
		STA		_tmp01
		LDA		_tmp0D
		STA		_tmp02
		LDA		_tmp0E
		STA		_tmp03
		LDA		#$80
		STA		_tmp04
		LDA		#$00
		STA		_tmp05
		LDA		#$01
		STA		_tmp06
		LDA		#$20
		STA		_tmp07
		JSR		_enemy_projectile_insert
		LDA		#$80
		STA		_objsA._player._prize_idx,X
locret_52107:
		RTS

; =============== S U B	R O U T	I N E =======================================
_explosion_animate:
		LDA		_tmp11
		AND		#$20
		BNE		loc_52177
		LDA		_objsA._player._state,X
		BPL		locret_52198
		LDA		_tmp11
		ORA		#$20
		STA		_tmp11
		LDA		#$0B
		STA		_objsA._player._timer,X
		LDA		_objsA._player._hndl_idx,X
		AND		#$3F
		CMP		#_obj_hndl3A_boss_yusin_idx
		BEQ		loc_52173
		CMP		#_obj_hndl3B_boss_padovski_idx
		BEQ		loc_52173
		CMP		#_obj_hndl1C_soldierA_idx
		BCC		loc_52177
		CMP		#_obj_hndl2A_pirate_idx
		BCS		loc_52177
loc_52173:
		LDA		#$02
		STA		_tmp0B
loc_52177:
		DEC		_objsA._player._timer,X
		BEQ		loc_5217E
		RTS
loc_5217E:
		LDA		#$01
		STA		_objsA._player._timer,X
		LDA		_tmp11
		AND		#$DF
		STA		_tmp11
		LDA		_objsA._player._hndl_idx,X
		AND		#$3F
		CMP		#_obj_hndl1C_soldierA_idx
		BCC		locret_52198
		CMP		#_obj_hndl2A_pirate_idx
		BCS		locret_52198
		LDA		#$00
		STA		_tmp0B
locret_52198:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_enemy_projectile_deploy:
		LDA		_tmp11
		AND		#$C0
		ORA		#$07
		STA		_tmp04
		LDA		_tmp11
		AND		#$40
		BNE		loc_521B7
		LDA		_tmp0D
		CLC
		ADC		_tmp02
		STA		_tmp02
		LDA		_tmp0C
		ADC		#$00
		STA		_tmp01
		JMP		loc_521C4
loc_521B7:
		LDA		_tmp0D
		SEC
		SBC		_tmp02
		STA		_tmp02
		LDA		_tmp0C
		SBC		#$00
		STA		_tmp01
loc_521C4:
		LDA		_tmp0E
		SEC
		SBC		_tmp03
		STA		_tmp03
		LDA		_objsA._player._damage,X
		STA		_tmp05
		LDA		#$30
		STA		_tmp07
		JSR		_objB_projectile_apu_select
		JMP		_enemy_projectile_insert

; =============== S U B	R O U T	I N E =======================================
_objB_projectile_apu_select:
		LDA		_tmp00
		CMP		#$09
		BCC		loc_521E5
		LDA		#$00
		STA		_tmp13
		RTS
loc_521E5:
		TAY
		LDA		_projectile_apu_list,Y
		STA		_tmp13
		RTS
; ---------------------------------------------------------------------------
_projectile_apu_list:
		.BYTE SEN02,SEN02,SEN05,SEN05,SEN03,SEN01,SEN01,$00,SEN06

; =============== S U B	R O U T	I N E =======================================
_obj_hor_targeting_to_player_common:
		LDA		_objsA._player._room_num
		CMP		_tmp0C
		BCC		loc_52207
		BEQ		loc_521FF
		BCS		loc_5220D
loc_521FF:
		LDA		_objsA._player._x_pos
		CMP		_tmp0D
		BCC		loc_52207
loc_5220D:
		JMP		_cur_obj_direction_right_set
loc_52207:
		JMP		_cur_obj_direction_left_set

; =============== S U B	R O U T	I N E =======================================
_obj_vert_targeting_to_player_common:
		SEC
		LDA		_objsA._player._y_pos
		SBC		#$10
		CMP		_tmp0E
		BCC		loc_52220
		JMP		_cur_obj_direction_down_set
loc_52220:
		JMP		_cur_obj_direction_up_set

; =============== S U B	R O U T	I N E =======================================
_obj_multi_deploy_pos_calc:
		JSR		_rand
		LDA		_tmp13
		CLC
		ADC		_objsA._player._x_pos
		STA		_tmp0D
		LDA		_objsA._player._room_num
		ADC		#$00
		STA		_tmp0C
		LDA		_tmp0D
		SEC
		SBC		#$80
		STA		_tmp0D
		BCS		loc_52221
		DEC		_tmp0C
loc_52221:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_sub52242:
		LDA		_objsA._player._state,X
		AND		#$03
		BEQ		locret_5224E
		LDA		_tmp11
		EOR		#$40
		STA		_tmp11
locret_5224E:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_sub5224F:
		LDA		#$00
		STA		_tmp00
		LDA		#$01
		STA		_tmp02
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		locret_52261
		LDA		#$00
		STA		_tmp10
locret_52261:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_tmp00_2_clear:
		LDA		#$00
		STA		_tmp00
		STA		_tmp02
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_jump_animate_test_right:
		JSR		_cur_obj_direction_right_set
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_jump_animate_test_left:
		JSR		_cur_obj_direction_left_set
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_jump_animate_test:
		LDA		#$00
		STA		_tmp0F

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_obj_jump_animate_test_ex:
		JSR		_obj_move_animate_common
		JSR		_objA_frontal_collision_line_calc
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_player_rand_timer_set:
		JSR		_rand
		AND		#$1F
		ORA		#$20
		STA		_objsA._player._timer,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_bomb_redeploy_and_explode:
		TXA
		PHA
		TYA
		PHA
		TXA
		TAY
		CLC
		ADC		#$10
		STA		_tmp05
		LDX		#$10
loc_52299:
		LDA		_objsA._player._hndl_idx,X
		BMI		loc_522A9
		TXA
		CLC
		ADC		#$10
		TAX
		CPX		#$80
		BNE		loc_52299
		BEQ		loc_522C5
loc_522A9:
		LDA		_objsA._player._hndl_idx,Y
		STA		_objsA._player._hndl_idx,X
		INY
		INX
		CPY		_tmp05
		BNE		loc_522A9
		SEC
		TXA
		SBC		#$10
		TAX
		LDA		#_obj_hndl3F_multipurpose_idx
		STA		_objsA._player._hndl_idx,X
		LDA		#$F2
		STA		_objsA._player._anim_phase_idx,X
		LDA		#$20
		STA		_objsA._player.field_7,X
loc_522C5:
		PLA
		TAY
		PLA
		TAX
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_to_player_lock:
		LDA		_tmp11
		AND		#$08
		BNE		loc_522E4
		LDA		#$10
		BIT		_tmp11
		BEQ		loc_522E4
		LDA		_tmp0C
		CMP		_objsA._player._room_num
		BNE		loc_522E2
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
loc_522E2:
		CLC
		RTS
loc_522E4:
		SEC
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_kill_and_continue:
		LDA		#$80
		STA		_objsA._player._hndl_idx,X
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_special_bonus_test_handler:
		LDA		_game._scr_idx			; only for locations
		BMI		locret_52332
		LDA		_objsA._o1._prize_idx	; chek if bonus already deployed
		CMP		#$9F					; (special garbage value left in RAM)
		BEQ		locret_52332
		LDA		_game._play_minutes		; only when minutes counter is divisible
		AND		#$0F					; by 16 (i.e. 00 16 32 48)
		BNE		locret_52332
		LDA		_cur_level_chr_idx		; specific stage CHR library index
		AND		#$F0					; fit with most Russian War Base locations
		CMP		#$20					; and second to last room before the BOSS
		BEQ		loc_52313
		CMP		#$60
		BEQ		loc_52313
		CMP		#$80
		BEQ		loc_52313
		RTS
loc_52313:
		INC		_game._play_minutes		; make sure inutes is different now to
		LDA		_objsA._o1._hndl_idx	; prevent multiple deployment
		BPL		locret_52332			; enemy object 1 must be dead (player is 0)
		LDX		#$0F					; now copy obj data above dead enemy slot
loc_5231E:
		LDA		_obj_data_special_bonus,X
		STA		_objsA._o1,X
		DEX
		BPL		loc_5231E
		LDA		_objsA._player._room_num; update object location info
		STA		_objsA._o1._room_num
		LDA		_objsA._player._x_pos	; position just above Rambo
		STA		_objsA._o1._x_pos
locret_52332:
		RTS
; ---------------------------------------------------------------------------
_obj_data_special_bonus:
		.BYTE _obj_hndl3F_multipurpose_idx
		.BYTE $F5,$00,$00,$80,$20,$00,$18,$00,$03,$00,$00,$00,$03,$9F,$00

; =============== S U B	R O U T	I N E =======================================
_obj_rambo_shout_deploy_test:
		LDA		_objsA._player._hndl_idx; only if player i alive obviously
		BMI		locret_52361
		LDA		_game._scr_idx			; only in two particular locations:
		CMP		#$62					; final war base before game ending
		BEQ		loc_52357
		CMP		#$0B					; and first pick-up-point with heli
		BNE		locret_52361
		LDA		_helicopter_warp_idx	; additionally when helicopter warp
		BEQ		locret_52361			; is set
loc_52357:
		FLAG_TEST	FLAG06_POW_TAKEN	; and the final condition is have
		BNE		loc_52362				; POW saved
locret_52361:
		RTS
loc_52362:
		LDA		_objsA._o6._hndl_idx	; test if object already deployed
		BPL		.shout_collision_test	; jump to animate
		LDA		_pad
		AND		#$40
		BNE		loc_52370				; or wait for B button press
		RTS
loc_52370:
		LDX		#$17					; copy shout projectile data
loc_52374:
		LDA		_obj_data_rambo_shout,X
		STA		_objsA._o6,X
		DEX
		BPL		loc_52374
		LDA		_objsA._player._dir		; set current X position according
		AND		#$40					; to Rambo's face direction
		BEQ		loc_52396
		LDA		_objsA._player._x_pos
		SEC
		SBC		#$20
		STA		_objsA._o6._x_pos
		LDA		_objsA._player._room_num
		SBC		#$00
		STA		_objsA._o6._room_num
		JMP		loc_5239E
loc_52396:
		LDA		_objsA._player._room_num
		STA		_objsA._o6._room_num
		LDA		_objsA._player._x_pos
		STA		_objsA._o6._x_pos
loc_5239E:
		SEC								; set current Y position
		LDA		_objsA._player._y_pos
		SBC		#$10
		STA		_objsA._o6._y_pos
		LDA		_objsA._player._dir		; and same direction
		AND		#$40
		LSR
		LSR
		LSR
		ORA		#$80
		STA		_objsA._o6._dir
.shout_collision_test:
		LDA		_game._scr_idx			; special case at war base
		CMP		#$62					; projectile is turn murdock
		BNE		locret_523F6			; into frog
		LDA		#$40
		STA		_objsA._o6._anim_phase_cnt
		LDA		_objsA._o6._dir			; get shout obj cur position
		AND		#$40
		ASL
		ORA		_objsA._o6._room_num
		STA		_tmp00
		LDA		_objsA._o6._x_pos
		STA		_tmp01
		LDA		_objsA._o6._y_pos
		STA		_tmp02
		LDA		#$04
		STA		_tmp03
		STA		_tmp04
		LDA		_objsA._o1._dir			; get murdock obj cur position
		AND		#$40
		ASL
		ORA		_objsA._o1._room_num
		STA		_tmp05
		LDA		_objsA._o1._x_pos
		STA		_tmp06
		LDA		_objsA._o1._y_pos
		STA		_tmp07
		LDA		#$02
		STA		_tmp08
		LDA		#$05
		STA		_tmp09
		JSR		_obj_to_obj_collision_test	; collision test
		LDA		_tmp16
		BEQ		locret_523F6
		LDA		#$F2					; turn murdock to frog
		STA		_objsA._o1._anim_phase_idx
locret_523F6:
		RTS
; ---------------------------------------------------------------------------
_obj_data_rambo_shout:
		.BYTE _obj_hndl3F_multipurpose_idx
		.BYTE $F6,$00,$00,$00,$00,$80,$00,$00,$00,$00,$00,$00,$04,$9F,$00

; =============== S U B	R O U T	I N E =======================================
_cur_obj_direction_left_set:
		LDA		_tmp11
		ORA		#$40
		STA		_tmp11
		RTS

; =============== S U B	R O U T	I N E =======================================
_cur_obj_direction_right_set:
		LDA		_tmp11
		AND		#$BF
		STA		_tmp11
		RTS

; =============== S U B	R O U T	I N E =======================================
_cur_obj_direction_down_set:
		LDA		_tmp11
		AND		#$7F
		STA		_tmp11
		RTS

; =============== S U B	R O U T	I N E =======================================
_cur_obj_direction_up_set:
		LDA		_tmp11
		ORA		#$80
		STA		_tmp11
		RTS
; ---------------------------------------------------------------------------
		IDX_START	_obj_hndl_lib
		IDX _obj_hndl00_rambo
		IDX _obj_hndl01_npcA
		IDX _obj_hndl02_npcB
		IDX _obj_hndl03_npcC
		IDX _obj_hndl04_npcD
		IDX _obj_hndl05_bee
		IDX _obj_hndl06_snake
		IDX _obj_hndl07_fish
		IDX _obj_hndl08_bubbles
		IDX _obj_hndl09_ceiling_bat
		IDX _obj_hndl0A_stalaktit
		IDX _obj_hndl0B_skull
		IDX _obj_hndl0C_bird
		IDX _obj_hndl0D_waterfall_logs
		IDX _obj_hndl0E_small_bat
		IDX _obj_hndl0F_spider
		IDX _obj_hndl10_floor_turret
		IDX _obj_hndl11_landmine
		IDX _obj_hndl12_ceiling_turret
		IDX _obj_hndl13_jumping_ball
		IDX _obj_hndl14_rocks
		IDX _obj_hndl15_grenades
		IDX _obj_hndl16_cobra
		IDX _obj_hndl17_pelikan
		IDX _obj_hndl18_gorilla
		IDX _obj_hndl19_tiger
		IDX _obj_hndl1A_tiger
		IDX _obj_hndl1B_kid
		IDX _obj_hndl1C_soldierA
		IDX _obj_hndl1D_soldierB
		IDX _obj_hndl1E_soldierB
		IDX _obj_hndl1F_soldierB
		IDX _obj_hndl20_torture_room_soldier
		IDX _obj_hndl21_soldierA
		IDX _obj_hndl22_soldierB
		IDX _obj_hndl23_soldierC
		IDX _obj_hndl24_soldierB
		IDX _obj_hndl25_soldierB
		IDX _obj_hndl26_grenade_soldier
		IDX _obj_hndl27_soldierB
		IDX _obj_hndl28_soldierB
		IDX _obj_hndl29_soldierB
		IDX _obj_hndl2A_pirate
		IDX _obj_hndl2B_boss_pirate
		IDX _obj_hndl2C_dubina_man
		IDX _obj_hndl2D_spectre
		IDX _obj_hndl2E_armored_man
		IDX _obj_hndl2F_strong_man
		IDX _obj_hndl30_burning_man
		IDX _obj_hndl31_machete_man
		IDX _obj_hndl32_skull_monkey
		IDX _obj_hndl33_shield_man
		IDX _obj_hndl34_crouching_bomb_man
		IDX _obj_hndl35_guard_of_torture_room
		IDX _obj_hndl36_boss_fire_tiger
		IDX _obj_hndl37_boss_spider
		IDX _obj_hndl38_boss_motorcycle
		IDX _obj_hndl39_boss_drone
		IDX _obj_hndl3A_boss_yusin
		IDX _obj_hndl3B_boss_padovski
		IDX _obj_hndl3C_plane
		IDX _obj_hndl3D_helicopterA
		IDX _obj_hndl3E_helicopterB
		IDX _obj_hndl3F_multipurpose

; =============== S U B	R O U T	I N E =======================================
_obj_hndl01_talk_idx_select:
		LDA		_pad
		AND		#$08
		BEQ		locret_524C9
		LDA		_objsA._player._state,X
		BPL		locret_524C9
		LDA		_game._scr_idx			; dialog select for NPCA
		CMP		#$01
		BNE		loc_524B7
		LDA		#$88
loc_524B7:
		CMP		#$0A
		BNE		loc_524BD
		LDA		#$89
loc_524BD:
		CMP		#$0D
		BNE		loc_524C3
		LDA		#$8B
loc_524C3:
		CMP		#$0E
		BNE		locret_524C9
		LDA		#$8C
locret_524C9:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_hndl02_talk_idx_select:
		LDA		_pad
		AND		#$08
		BEQ		locret_524EA
		LDA		_objsA._player._state,X
		BPL		locret_524EA
		LDA		_game._scr_idx			; dialog select for NPCB
		CMP		#$01
		BNE		loc_524DE
		LDA		#$AC
loc_524DE:
		CMP		#$48
		BNE		loc_524E4
		LDA		#$9C
loc_524E4:
		CMP		#$61
		BNE		locret_524EA
		LDA		#$A5
locret_524EA:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_hndl03_talk_idx_select:
		LDA		_pad
		AND		#$08
		BEQ		locret_52511
		LDA		_objsA._player._state,X
		BPL		locret_52511
		LDA		_game._scr_idx			; dialog select for NPCC
		CMP		#$00
		BNE		loc_524FF
		LDA		#$86
loc_524FF:
		CMP		#$0C
		BNE		loc_52505
		LDA		#$9B
loc_52505:
		CMP		#$62
		BNE		loc_5250B
		LDA		#$A3
loc_5250B:
		CMP		#$61
		BNE		locret_52511
		LDA		#$A4
locret_52511:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_hndl04_talk_idx_select:
		LDA		_pad
		AND		#$08
		BEQ		locret_52544
		LDA		_objsA._player._state,X
		BPL		locret_52544
		LDA		_game._scr_idx			; dialog select for NPCD
		CMP		#$06
		BNE		loc_52526
		LDA		#$8A
loc_52526:
		CMP		#$0C
		BNE		loc_5252C
		LDA		#$98
loc_5252C:
		CMP		#$30
		BNE		loc_52532
		LDA		#$A1
loc_52532:
		CMP		#$3A
		BNE		loc_52538
		LDA		#$9A
loc_52538:
		CMP		#$62
		BNE		loc_5253E
		LDA		#$AD
loc_5253E:
		CMP		#$77
		BNE		locret_52544
		LDA		#$A0
locret_52544:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_hndl20_talk_idx_select:
		LDA		_pad
		AND		#$08
		BEQ		locret_52559
		LDA		_objsA._player._state,X
		BPL		locret_52559
		LDA		_game._scr_idx			; dialog select for NPCE
		CMP		#$6F
		BNE		locret_52559
		LDA		#$91
locret_52559:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_hndl01_npcA:
		CPX		#$00					; if obj index0 this is RAMBO
		BNE		loc_52561				; so we must control it manually
		JMP		_obj_player_control_input
loc_52561:
		LDA		_game._scr_idx			; this allows the NPC character
		CMP		#$0A					; dub the movement of the main char
		BNE		loc_52572				; in a particular areas 06 and 0A
		FLAG_TEST	FLAG09_CO_TAKEN
		BEQ		loc_52572
		JMP		_obj_player_control_input
loc_52572:
		LDA		_game._scr_idx
		CMP		#$06
		BNE		loc_52586
		FLAG_TEST	FLAG09_CO_TAKEN
		BEQ		loc_52583
		JMP		_obj_player_control_input
loc_52583:
		JMP		_obj_kill_and_continue
loc_52586:
		JSR		_obj_hndl01_talk_idx_select
		JMP		_obj_npc_dialog_start

; =============== S U B	R O U T	I N E =======================================
_obj_hndl02_npcB:
		CPX		#$00
		BNE		loc_52593
		JMP		_obj_player_control_input
loc_52593:
		FLAG_TEST	FLAG09_CO_TAKEN
		BNE		loc_525A4
		LDA		_game._scr_idx
		CMP		#$01
		BEQ		loc_525A4
		JMP		_obj_kill_and_continue
loc_525A4:
		JSR		_obj_hndl02_talk_idx_select
		JMP		_obj_npc_dialog_start

; =============== S U B	R O U T	I N E =======================================
_obj_hndl03_npcC:
		JSR		_obj_hndl03_talk_idx_select
		JMP		_obj_npc_dialog_start

; =============== S U B	R O U T	I N E =======================================
_obj_hndl04_npcD:
		LDA		_game._scr_idx
		CMP		#$30
		BEQ		loc_525BB
		CMP		#$77
		BNE		loc_525C5
loc_525BB:
		FLAG_TEST	FLAG06_POW_TAKEN
		BEQ		loc_525C5
		JMP		_obj_player_control_input
loc_525C5:
		FLAG_TEST	FLAG06_POW_TAKEN
		BNE		loc_525D6
		LDA		_game._scr_idx
		CMP		#$62
		BNE		loc_525D6
		JMP		_obj_kill_and_continue
loc_525D6:
		LDA		_game._scr_idx
		CMP		#$0B
		BNE		loc_525EA
		FLAG_TEST	FLAG06_POW_TAKEN
		BEQ		loc_525E7
		JMP		_obj_player_control_input
loc_525E7:
		JMP		_obj_kill_and_continue
loc_525EA:
		JSR		_obj_hndl04_talk_idx_select
		JMP		_obj_npc_dialog_start

; =============== S U B	R O U T	I N E =======================================
_obj_hndl20_torture_room_soldier:
		JSR		_obj_hndl20_talk_idx_select

; !FALLTHROUGHR!

; =============== S U B	R O U T	I N E =======================================
_obj_npc_dialog_start:
		CMP		#$80
		BCC		loc_525FF
		STA		_game._scr_idx
		LDA		#$01
		STA		_game._redraw_req
loc_525FF:
		LDA		_tmp0B
		CMP		#$02
		BCS		loc_5267A
		LDA		#$04
		STA		_tmp01
		LDA		#$06
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		_tmp0B
		BEQ		loc_5261B
		LDA		#$01
		STA		_tmp0F
loc_5261B:
		LDA		_game._scr_idx
		CMP		#$62
		BNE		loc_5263F
		LDA		_objsA._player._hndl_idx,X
		AND		#$3F
		CMP		#_obj_hndl03_npcC_idx
		BNE		loc_5263F
		FLAG_TEST	FLAG06_POW_TAKEN
		BEQ		loc_5263F
		LDA		#$04
		STA		_tmp0F
		LDA		#$00
		CMP		_tmp0B
		BNE		loc_5263F
		LDA		#$01
		STA		_objsA._player._timer,X
loc_5263F:
		LDA		_tmp0D
		CMP		#$E8
		BCC		loc_5264B
		JSR		_cur_obj_direction_left_set
		JMP		loc_52652
loc_5264B:
		CMP		#$18
		BCS		loc_52652
		JSR		_cur_obj_direction_right_set
loc_52652:
		JSR		_obj_sub52242
		DEC		_objsA._player._timer,X
		BNE		loc_52677
		JSR		_obj_player_rand_timer_set
		LDA		#$01
		STA		_tmp0B
		LDA		_tmp13
		CMP		#$40
		BCC		loc_52670
		CMP		#$A0
		BCC		loc_5266D
		JMP		_obj_jump_animate_test_right
loc_5266D:
		JMP		_obj_jump_animate_test_left
loc_52670:
		LDA		#$00
		STA		_tmp0B
		JMP		_obj_jump_animate_test
loc_52677:
		JMP		_obj_jump_animate_test_ex
loc_5267A:
		LDA		#$03
		STA		_tmp01
		LDA		#$08
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_52697
		LDA		#$00
		STA		_tmp0F
		LDA		#$02
		BNE		loc_52699
loc_52697:
		LDA		#$03
loc_52699:
		STA		_tmp0B
		DEC		_objsA._player._timer,X
		BNE		loc_526B9
		JSR		_obj_player_rand_timer_set
		LDA		_tmp13
		CMP		#$80
		BCC		loc_526B9
		LDA		#$08
		STA		_tmp10
		LDA		#$03
		STA		_tmp0F
		JSR		_cur_obj_direction_up_set
		JSR		_obj_hor_targeting_to_player_common
loc_526B9:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl05_bee:
		JSR		_obj_to_player_lock
		BCS		loc_526C4
		JMP		_objA_flush_and_continue
loc_526C4:
		LDA		#$03
		STA		_tmp01
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		#$10
		BIT		_tmp11
		BEQ		loc_526D9
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
loc_526D9:
		LDA		_tmp0E
		CMP		#$C0
		BCC		loc_526E6
		LDA		#$BF
		STA		_tmp0E
		BNE		loc_52700
loc_526E6:
		CMP		#$30
		BCS		loc_526ED
		JSR		_cur_obj_direction_down_set
loc_526ED:
		DEC		_objsA._player._timer,X
		BNE		loc_52719
		JSR		_rand
		AND		#$1F
		ORA		#$10
		STA		_objsA._player._timer,X
		LDA		_tmp13
		CMP		#$80
		BCC		loc_5270E
loc_52700:
		LDA		#$02
		STA		_tmp0F
		LDA		#$00
		STA		_tmp10
		JSR		_obj_hor_targeting_to_player_common
		JMP		_obj_jump_animate_test_ex
loc_5270E:
		LDA		#$00
		STA		_tmp0F
		LDA		#$03
		STA		_tmp10
		JSR		_obj_vert_targeting_to_player_common
loc_52719:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl06_snake:
		LDA		#$03
		STA		_tmp01
		LDA		#$08
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		_tmp11
		AND		#$08
		BNE		loc_52754
		LDA		_tmp0E
		BMI		loc_5274E
		LDA		_tmp0C
		CMP		_objsA._player._room_num
		BEQ		loc_5273D
		JMP		_objA_flush_and_continue
loc_5273D:
		LDA		_objsA._player._x_pos
		AND		#$E0
		CMP		_tmp0D
		BEQ		loc_5274E
		LDA		_objsA._player._y_pos
		CMP		_tmp0E
		BCC		loc_5274E
		JMP		_objA_flush_and_continue
loc_5274E:
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
loc_52754:
		LDA		_tmp11
		AND		#$04
		BNE		loc_52771
		LDA		_objsA._player._state,X
		AND		#$04
		BNE		loc_52763
		JMP		_obj_jump_animate_test_ex
loc_52763:
		LDA		#$01
		STA		_tmp0F
		STA		_tmp0B
		LDA		_tmp11
		ORA		#$04
		STA		_tmp11
loc_52771:
		JSR		_obj_sub52242
		DEC		_objsA._player._timer,X
		BNE		loc_52792
		LDA		#$20
		STA		_objsA._player._timer,X
		LDA		_objsA._player._y_pos
		AND		#$F0
		CMP		_tmp0E
		BEQ		loc_5278B
		LDA		#$01
		STA		_tmp0F
		BNE		loc_52792
loc_5278B:
		LDA		#$03
		STA		_tmp0F
		JSR		_obj_hor_targeting_to_player_common
loc_52792:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl07_fish:
		JSR		_obj_to_player_lock
		BCS		loc_5279D
		JMP		_objA_flush_and_continue
loc_5279D:
		LDA		#$03
		STA		_tmp01
		LDA		#$08
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		LDA		#$04
		AND		_objsA._player._state,X
		BNE		loc_527B8
		LDA		_tmp03
		STA		_tmp0F
		JMP		loc_527D4
loc_527B8:
		LDA		#$01
		STA		_tmp0F
		JSR		_rand
		AND		#$3F
		BNE		loc_527D4
loc_527C6:
		JSR		_obj_hor_targeting_to_player_common
		LDA		#$08
		STA		_tmp10
		LDA		_tmp03
		STA		_tmp0F
		JSR		_cur_obj_direction_up_set
loc_527D4:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl08_bubbles:
		LDA		#$00
		STA		_tmp00
		STA		_tmp01
		STA		_tmp02
		STA		_tmp0F
		LDA		#$03
		STA		_tmp03
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
		LDA		_tmp11
		AND		#$10
		BNE		loc_527FC
		LDA		_tmp0E
		CMP		#$F0
		BCC		loc_52803
loc_527FC:
		JSR		_obj_multi_deploy_pos_calc
		LDA		#$F0
		STA		_tmp0E
loc_52803:
		JSR		_obj_move_animate_common
		JSR		_rand
		LDA		_tmp13
		AND		#$03
		STA		_tmp13
		LDA		_tmp0D
		AND		#$FC
		ORA		_tmp13
		STA		_tmp0D
		JSR		_objA_frontal_collision_line_calc
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl09_ceiling_bat:
		LDA		#$01
		STA		_tmp01
		LDA		#$0F
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		#$00
		STA		_tmp0B
		LDA		_tmp0E
		CMP		#$4F
		BCS		loc_52843
		DEC		_objsA._player._timer,X
		BNE		loc_52864
		JSR		_obj_player_rand_timer_set
		LDA		#$0F
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
loc_52843:
		LDA		#$FF
		EOR		_tmp0E
		STA		_tmp0E
		INC		_tmp0E
		LDA		#$01
		STA		_tmp0B
		LDA		#$01
		STA		_tmp0F
		JSR		_obj_hor_targeting_to_player_common
		JSR		_obj_move_animate_common
		LDA		#$FF
		EOR		_tmp0E
		STA		_tmp0E
		INC		_tmp0E
		JSR		_objA_frontal_collision_line_calc
loc_52864:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl0A_stalaktit:
		LDA		#$00
		STA		_tmp01
		LDA		#$0F
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		_tmp11
		AND		#$08
		BNE		loc_52892
		LDA		_tmp0C
		CMP		_objsA._player._room_num
		BEQ		loc_52881
		JMP		_objA_flush_and_continue
loc_52881:
		LDA		_objsA._player._x_pos
		AND		#$F0
		CMP		_tmp0D
		BEQ		loc_5288C
		JMP		_objA_flush_and_continue
loc_5288C:
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
loc_52892:
		LDA		_objsA._player._state,X
		AND		#$04
		BNE		loc_5289F
		LDA		#$01
		STA		_tmp02
		JMP		_obj_jump_animate_test_ex
loc_5289F:
		LDA		#$00
		STA		_objsA._player.field_C,X
		STA		_objsA._player._prize_idx,X
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl0B_skull:
		LDA		#$03
		STA		_tmp01
		LDA		#$0A
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		#$03
		STA		_tmp0F
		LDA		_tmp11
		AND		#$10
		BEQ		loc_52900
		DEC		_objsA._player._timer,X
		BEQ		loc_528C7
		JMP		loc_5294A
loc_528C7:
		JSR		_obj_player_rand_timer_set
		LDA		#$30
		STA		_tmp0E
		LDA		_tmp11
		AND		#$F7
		STA		_tmp11
		JSR		_cur_obj_direction_down_set
		LDA		_objsA._player._dir
		AND		#$40
		BNE		loc_528F0
		LDA		_objsA._player._x_pos
		CLC
		ADC		#$80
		STA		_tmp0D
		LDA		_objsA._player._room_num
		ADC		#$00
		STA		_tmp0C
		JSR		_cur_obj_direction_left_set
		JMP		loc_52900
loc_528F0:
		SEC
		LDA		_objsA._player._x_pos
		SBC		#$80
		STA		_tmp0D
		LDA		_objsA._player._room_num
		SBC		#$00
		STA		_tmp0C
		JSR		_cur_obj_direction_right_set
loc_52900:
		LDA		_tmp0C
		AND		#$03
		STA		_tmp0C
		LDA		_tmp11
		AND		#$08
		BEQ		loc_52915
		LDA		_tmp0E
		CMP		#$80
		BCS		loc_52928
		BCC		loc_5291B
loc_52915:
		LDA		_tmp0E
		CMP		#$80
		BCC		loc_52928
loc_5291B:
		LDA		_tmp11
		EOR		#$08
		STA		_tmp11
		LDA		#$0A
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
loc_52928:
		LDA		_tmp11
		AND		#$08
		BEQ		loc_52936
		LDA		#$FF
		EOR		_tmp0E
		STA		_tmp0E
		INC		_tmp0E
loc_52936:
		JSR		_obj_move_animate_common
		LDA		_tmp11
		AND		#$08
		BEQ		loc_52947
		LDA		#$FF
		EOR		_tmp0E
		STA		_tmp0E
		INC		_tmp0E
loc_52947:
		JSR		_objA_frontal_collision_line_calc
loc_5294A:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl0C_bird:
		JSR		_obj_to_player_lock
		BCS		loc_52955
		JMP		_objA_flush_and_continue
loc_52955:
		LDA		#$03
		STA		_tmp01
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		_tmp11
		AND		#$10
		BNE		loc_5296F
		LDA		_tmp11
		AND		#$01
		BNE		loc_529CA
		JMP		loc_529B2
loc_5296F:
		JSR		_rand
		AND		#$0F
		BEQ		loc_52979
		JMP		_objA_flush_and_continue
loc_52979:
		JSR		_obj_player_rand_timer_set
		LDA		_tmp11
		AND		#$F8
		STA		_tmp11
		LDA		#$30
		STA		_tmp0E
		JSR		_cur_obj_direction_down_set
		LDA		_objsA._player._dir
		AND		#$40
		BNE		loc_529A2
		LDA		_objsA._player._x_pos
		CLC
		ADC		#$60
		STA		_tmp0D
		LDA		_objsA._player._room_num
		ADC		#$00
		STA		_tmp0C
		JSR		_cur_obj_direction_left_set
		JMP		loc_529B2
loc_529A2:
		SEC
		LDA		_objsA._player._x_pos
		SBC		#$60
		STA		_tmp0D
		LDA		_objsA._player._room_num
		SBC		#$00
		STA		_tmp0C
		JSR		_cur_obj_direction_right_set
loc_529B2:
		LDA		#$03
		STA		_tmp10
		LDA		#$00
		STA		_tmp0F
		LDA		_tmp0E
		CLC
		ADC		#$18
		CMP		_objsA._player._y_pos
		BCS		loc_529CA
		LDA		#$00
		STA		_tmp0B
		JMP		_obj_jump_animate_test_ex
loc_529CA:
		LDA		_tmp11
		ORA		#$01
		STA		_tmp11
		LDA		#$00
		STA		_tmp10
		LDA		#$03
		STA		_tmp0F
		LDA		#$01
		STA		_tmp0B
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl0D_waterfall_logs:
		LDA		#$00
		STA		_tmp00
		STA		_tmp01
		STA		_tmp02
		STA		_tmp0F
		LDA		#$03
		STA		_tmp03
		STA		_tmp10
		JSR		_rand
		LDA		_tmp0E
		CMP		#$F8
		BCC		loc_52A07
loc_529FE:
		LDA		_tmp13
		AND		#$07
		BNE		loc_52A1C
		JSR		_obj_multi_deploy_pos_calc
loc_52A07:
		JSR		_cur_obj_direction_down_set
		JSR		_obj_move_animate_common
		LDA		_tmp13
		AND		#$07
		BNE		loc_52A19
		LDA		_tmp11
		EOR		#$40
		STA		_tmp11
loc_52A19:
		JSR		_objA_frontal_collision_line_calc
loc_52A1C:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl0E_small_bat:
		JSR		_obj_to_player_lock
		BCS		loc_52A27
		JMP		_objA_flush_and_continue
loc_52A27:
		LDA		#$02
		STA		_tmp01
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		_tmp11
		AND		#$10
		BEQ		loc_52A3B
		JMP		_objA_flush_and_continue
loc_52A3B:
		DEC		_objsA._player._timer,X
		BNE		loc_52A5A
		JSR		_obj_player_rand_timer_set
		JSR		_rand
		LDA		_tmp13
		AND		#$0F
		STA		_tmp0F
		JSR		_rand
		LDA		_tmp13
		AND		#$0F
		STA		_tmp10
		JSR		_obj_hor_targeting_to_player_common
		JSR		_obj_vert_targeting_to_player_common
loc_52A5A:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl0F_spider:
		LDA		#$01
		STA		_tmp01
		LDA		#$08
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		DEC		_objsA._player._timer,X
		BNE		loc_52AA8
loc_52A72:
		JSR		_obj_player_rand_timer_set
		LDA		#$01
		STA		_tmp0F
		LDA		_tmp13
		CMP		#$40
		BCC		loc_52AA4
		CMP		#$80
		BCC		loc_52A9E
		CMP		#$C0
		BCC		loc_52A98
		LDA		#$08
		STA		_tmp10
		LDA		#$01
		STA		_tmp0F
		JSR		_cur_obj_direction_up_set
		JSR		_obj_hor_targeting_to_player_common
		JMP		loc_52AA8
loc_52A98:
		JSR		_cur_obj_direction_right_set
		JMP		loc_52AA8
loc_52A9E:
		JSR		_cur_obj_direction_left_set
		JMP		loc_52AA8
loc_52AA4:
		LDA		#$00
		STA		_tmp0F
loc_52AA8:
		JSR		_obj_move_animate_common
		LDA		#$08
		STA		_tmp0A
		JSR		_obj_sub53EBA
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl10_floor_turret:
		DEC		_objsA._player._timer,X
		BNE		loc_52AFB
		LDA		#$20
		STA		_objsA._player._timer,X
		JSR		_obj_hor_targeting_to_player_common
		LDA		_objsA._player._y_pos
		CLC
		ADC		#$20
		CMP		_tmp0E
		BCC		loc_52ACF
		JSR		_cur_obj_direction_down_set
		JMP		loc_52AD2
loc_52ACF:
		JSR		_cur_obj_direction_up_set
loc_52AD2:
		JSR		_objA_frontal_collision_line_calc
		LDA		_tmp11
		AND		#$80
		BNE		loc_52AE6
		LDA		#$40
		STA		_tmp06
		LDA		#$00
		BEQ		loc_52AEE
loc_52AE6:
		LDA		#$33
		STA		_tmp06
		LDA		#$01
loc_52AEE:
		STA		_tmp0B
		LDA		#$04
		STA		_tmp02
		STA		_tmp03
		LDA		#_objB_hndl07_idx
		STA		_tmp00
		JSR		_obj_enemy_projectile_deploy
loc_52AFB:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl11_landmine:
		JSR		_enemy_explosion_handler
		BCC		loc_52B08
		LDA		#SEN07
		STA		_apu_se_noise_idx
loc_52B08:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl12_ceiling_turret:
		INC		_objsA._player._timer,X
		LDA		_objsA._player._timer,X
		AND		#$20
		BEQ		loc_52B23
		LDA		#$00
		STA		_objsA._player._timer,X
		JSR		_obj_hor_targeting_to_player_common
		JSR		_cur_obj_direction_down_set
		LDA		_tmp11
		EOR		#$04
		STA		_tmp11
loc_52B23:
		JSR		_objA_frontal_collision_line_calc
		LDA		_objsA._player._timer,X
		AND		#$13
		BNE		loc_52B52
		LDA		_tmp11
		AND		#$04
		BNE		loc_52B3D
		LDA		#$04
		STA		_tmp06
		LDA		#$00
		BEQ		loc_52B45
loc_52B3D:
		LDA		#$33
		STA		_tmp06
		LDA		#$01
loc_52B45:
		STA		_tmp0B
		LDA		#$04
		STA		_tmp02
		STA		_tmp03
		LDA		#_objB_hndl07_idx
		STA		_tmp00
		JSR		_obj_enemy_projectile_deploy
loc_52B52:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl13_jumping_ball:
		JSR		_obj_extra_enemy_deploy_test
		LDA		#$01
		STA		_tmp01
		LDA		#$0C
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		_tmp0B
		BNE		loc_52BB7
		LDA		#$04
		AND		_objsA._player._state,X
		BNE		loc_52B7D
		LDA		#$08
		AND		_objsA._player._state,X
		BEQ		loc_52B7A
		LDA		#$01
		STA		_tmp10
		JSR		_cur_obj_direction_down_set
loc_52B7A:
		JMP		loc_52BD2
loc_52B7D:
		DEC		_objsA._player._timer,X
		BNE		loc_52B8B
		JSR		_obj_player_rand_timer_set
		LDA		#$01
		STA		_tmp0B
		BNE		loc_52BB7
loc_52B8B:
		JSR		_rand
		LDA		_tmp13
		CMP		#$80
		BCC		loc_52B9D
		LDA		_tmp11
		AND		#$F7
		STA		_tmp11
		JMP		loc_52BA3
loc_52B9D:
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
loc_52BA3:
		LDA		#$0C
		STA		_tmp10
		LDA		#$01
		STA		_tmp0F
		JSR		_cur_obj_direction_up_set
		LDA		_objsA._player.field_7,X
		AND		#$E8
		STA		_objsA._player.field_7,X
		JMP		loc_52BD2
loc_52BB7:
		DEC		_objsA._player._timer,X
		BNE		loc_52BC6
		LDA		#$08
		STA		_objsA._player._timer,X
		LDA		#$00
		STA		_tmp0B
		BEQ		loc_52B7D
loc_52BC6:
		LDA		#$00
		STA		_tmp10
		STA		_tmp0F
		LDA		_objsA._player.field_7,X
		ORA		#$0F
		STA		_objsA._player.field_7,X
loc_52BD2:
		LDA		_tmp11
		PHA
		AND		#$08
		BNE		loc_52BDF
		JSR		_cur_obj_direction_right_set
		JMP		loc_52BE2
loc_52BDF:
		JSR		_cur_obj_direction_left_set
loc_52BE2:
		JSR		_obj_move_animate_common
		LDA		_tmp11
		AND		#$80
		STA		_tmp11
		PLA
		AND		#$7F
		EOR		#$40
		ORA		_tmp11
		STA		_tmp11
		JSR		_objA_frontal_collision_line_calc
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl14_rocks:
		LDA		#$03
		STA		_tmp01
		LDA		#$03
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		#$03
		STA		_tmp0F
		LDA		_tmp0E
		CMP		#$F8
		BCC		loc_52C18
		JSR		_obj_multi_deploy_pos_calc
		JSR		_cur_obj_direction_down_set
loc_52C18:
		JSR		_obj_move_animate_common
		JSR		_rand
		LDA		_tmp13
		AND		#$07
		BNE		loc_52C2E
		LDA		#$00
		STA		_tmp10
		LDA		_tmp11
		EOR		#$40
		STA		_tmp11
loc_52C2E:
		JSR		_objA_frontal_collision_line_calc
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl15_grenades:
		LDA		#$01
		STA		_tmp01
		LDA		#$05
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		_objsA._player._state,X
		BMI		loc_52C4A
		AND		#$04
		BEQ		loc_52C55
loc_52C4A:
		LDA		#SEN07
		STA		_apu_se_noise_idx
		JSR		_obj_bomb_redeploy_and_explode
		JMP		loc_52C64
loc_52C55:
		LDA		_tmp11
		AND		#$10
		BNE		loc_52C64
		LDA		_tmp0E
		CMP		#$F0
		BCC		loc_52C79
loc_52C64:
		LDA		#$00
		STA		_tmp10
		LDA		#$01
		STA		_tmp0F
		JSR		_cur_obj_direction_down_set
		LDA		#$10
		STA		_tmp0E
		JSR		_obj_multi_deploy_pos_calc
		JSR		_obj_hor_targeting_to_player_common
loc_52C79:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl16_cobra:
		LDA		_tmp11
		AND		#$08
		BEQ		loc_52C97
		DEC		_objsA._player._timer,X
		LDA		_objsA._player._timer,X
		CMP		#$10
		BNE		loc_52C93
		LDA		_tmp11
		AND		#$02
		BNE		loc_52D0A
		JMP		loc_52D40
loc_52C93:
		LDA		_objsA._player._timer,X
		BNE		loc_52C9D
loc_52C97:
		LDA		_objsA._player._hndl_idx,X
		AND		#$40
		BNE		loc_52CA0
loc_52C9D:
		JMP		loc_52D60
loc_52CA0:
		LDA		_tmp11
		AND		#$F7
		STA		_tmp11
		LDA		#$00
		STA		_objsA._player.field_8,X
		JSR		_obj_hor_targeting_to_player_common
		LDA		_tmp0B
		CMP		#$03
		BCC		loc_52CC2
		LDA		_tmp11
		AND		#$02
		BNE		loc_52CF9
		LDA		_tmp11
		AND		#$04
		BNE		loc_52D2F
		JMP		loc_52CD1
loc_52CC2:
		LDA		_tmp11
		AND		#$02
		BNE		loc_52D1C
		LDA		_tmp11
		AND		#$04
		BEQ		loc_52CE6
		JMP		loc_52D52
loc_52CD1:
		LDA		#$00
		STA		_tmp0B
		LDA		_objsA._player._timer,X
		CMP		#$0C
		BCC		loc_52CE3
		LDA		#$2F
		STA		_objsA._player.field_8,X
		LDA		#$90
		STA		_objsA._player._collision_box_idx,X
loc_52CE3:
		JMP		loc_52D60
loc_52CE6:
		LDA		#$00
		STA		_objsA._player.field_8,X
		LDA		#$03
		STA		_tmp0B
		LDA		_tmp11
		AND		#$F0
		ORA		#$02
		STA		_tmp11
		JMP		loc_52D60
loc_52CF9:
		LDA		#$01
		STA		_tmp0B
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
		LDA		#$24
		STA		_objsA._player._timer,X
		JMP		loc_52D60
loc_52D0A:
		LDA		#$2F
		STA		_objsA._player.field_8,X
		LDA		#$A0
		STA		_objsA._player._collision_box_idx,X
		LDA		#$54
		STA		_tmp03
		JSR		_obj_prize_deployA
		JMP		loc_52D60
loc_52D1C:
		LDA		#$00
		STA		_objsA._player.field_8,X
		LDA		#$04
		STA		_tmp0B
		LDA		_tmp11
		AND		#$F0
		ORA		#$04
		STA		_tmp11
		JMP		loc_52D60
loc_52D2F:
		LDA		#$02
		STA		_tmp0B
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
		LDA		#$28
		STA		_objsA._player._timer,X
		JMP		loc_52D60
loc_52D40:
		LDA		#$2F
		STA		_objsA._player.field_8,X
		LDA		#$B0
		STA		_objsA._player._collision_box_idx,X
		LDA		#$64
		STA		_tmp03
		JSR		_obj_prize_deployA
		JMP		loc_52D60
loc_52D52:
		LDA		#$00
		STA		_objsA._player.field_8,X
		LDA		#$05
		STA		_tmp0B
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
loc_52D60:
		JSR		_objA_frontal_collision_line_calc
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_prize_deployA:
		LDA		#$08
		STA		_tmp02
		LDA		#$40
		STA		_tmp06
		LDA		#_objB_hndl07_idx
		STA		_tmp00
		JMP		_obj_enemy_projectile_deploy

; =============== S U B	R O U T	I N E =======================================
_obj_hndl17_pelikan:
		LDA		#$02
		STA		_tmp01
		LDA		#$08
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		DEC		_objsA._player._timer,X
		BNE		loc_52DCB
		JSR		_obj_player_rand_timer_set
		LDA		#$02
		STA		_tmp0F
		LDA		#$01
		STA		_tmp0B
		LDA		#$05
		STA		_objsA._player._collision_box_idx,X
		LDA		_tmp13
		CMP		#$40
		BCC		loc_52DC4
		CMP		#$80
		BCC		loc_52DC1
		CMP		#$C0
		BCC		loc_52DBE
		LDA		#$08
		STA		_tmp10
		LDA		#$02
		STA		_tmp0F
		JSR		_cur_obj_direction_up_set
		JSR		_obj_hor_targeting_to_player_common
		LDA		#$02
		STA		_tmp0B
		LDA		#$0C
		STA		_objsA._player._collision_box_idx,X
		BNE		loc_52DCB
loc_52DBE:
		JMP		_obj_jump_animate_test_right
loc_52DC1:
		JMP		_obj_jump_animate_test_left
loc_52DC4:
		LDA		#$00
		STA		_tmp0B
		JMP		_obj_jump_animate_test
loc_52DCB:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl18_gorilla:
		LDA		#$02
		STA		_tmp01
		LDA		#$09
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_52E00
		LDA		_tmp0B
		CMP		#$00
		BNE		loc_52DF4
		LDA		_objsA._player._timer,X
		AND		#$07
		BNE		loc_52DFC
		LDA		_tmp11
		EOR		#$40
		STA		_tmp11
		JMP		loc_52DFC
loc_52DF4:
		LDA		#$01
		STA		_tmp0F
		LDA		#$01
		STA		_tmp0B
loc_52DFC:
		LDA		#$09
		STA		_objsA._player._collision_box_idx,X
loc_52E00:
		JSR		_obj_sub52242
		DEC		_objsA._player._timer,X
		BNE		loc_52E63
		JSR		_obj_player_rand_timer_set
		LDA		#$01
		STA		_tmp0F
		LDA		#$01
		STA		_tmp0B
		LDA		#$09
		STA		_objsA._player._collision_box_idx,X
		LDA		_tmp13
		CMP		#$20
		BCC		loc_52E58
		CMP		#$60
		BCC		loc_52E55
		CMP		#$A0
		BCC		loc_52E52
		LDA		#$09
		STA		_tmp10
		LDA		#$02
		STA		_tmp0F
		JSR		_cur_obj_direction_up_set
		LDA		_tmp0E
		CMP		_objsA._player._y_pos
		BCS		loc_52E3E
		LDA		_objsA._player.field_7,X
		AND		#$BF
		STA		_objsA._player.field_7,X
		JMP		loc_52E44
loc_52E3E:
		LDA		_objsA._player.field_7,X
		ORA		#$40
		STA		_objsA._player.field_7,X
loc_52E44:
		JSR		_obj_hor_targeting_to_player_common
		LDA		#$02
		STA		_tmp0B
		LDA		#$0D
		STA		_objsA._player._collision_box_idx,X
		BNE		loc_52E63
loc_52E52:
		JMP		_obj_jump_animate_test_right
loc_52E55:
		JMP		_obj_jump_animate_test_left
loc_52E58:
		LDA		#$00
		STA		_tmp0B
		LDA		#$09
		STA		_objsA._player._collision_box_idx,X
		JMP		_obj_jump_animate_test
loc_52E63:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl19_tiger:
_obj_hndl1A_tiger:
		LDA		#$04
		STA		_tmp01
		LDA		#$05
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		LDA		_tmp11
		AND		#$10
		BNE		loc_52EC8
		LDA		_tmp11
		AND		#$01
		BEQ		loc_52E95
		INC		_objsA._player._timer,X
		LDA		_objsA._player._timer,X
		AND		#$01
		BEQ		loc_52E8C
		LDA		#$00
		STA		_tmp02
loc_52E8C:
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_52ED5
		BNE		loc_52EAC
loc_52E95:
		JSR		_obj_hor_targeting_to_player_common
		LDA		_tmp11
		AND		#$10
		BNE		loc_52EC8
		SEC
		LDA		_tmp0D
		SBC		_room_scroll_pos_x
		CMP		#$10
		BCC		loc_52EC8
		CMP		#$F0
		BCS		loc_52EC8
loc_52EAC:
		LDA		_tmp11
		ORA		#$01
		STA		_tmp11
		LDA		#$04
		STA		_tmp0F
		LDA		#$05
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
		LDA		#$01
		STA		_tmp0B
		LDA		#$F0
		STA		_objsA._player._anim_phase_idx,X
		BNE		loc_52ED5
loc_52EC8:
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
		LDA		#$00
		STA		_tmp0B
		JMP		_obj_jump_animate_test
loc_52ED5:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl1B_kid:
		FLAGS_TEST	FLAG02_KID_SAVED,FLAG04_KID_TAKEN
		BEQ		loc_52EE2
		JMP		_obj_kill_and_continue
loc_52EE2:
		LDA		_pad
		AND		#$08
		BEQ		loc_52EF7
		LDA		_objsA._player._state,X
		BPL		loc_52EF7
		LDA		#$8D
		STA		_game._scr_idx
		LDA		#$01
		STA		_game._redraw_req
loc_52EF7:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl1C_soldierA:
_obj_hndl21_soldierA:
		LDA		_tmp11
		ORA		#$01
		STA		_tmp11
		JSR		_obj_soldierB_common_subA
		LDA		_tmp11
		AND		#$08
		BNE		loc_52F43
		LDA		_tmp0B
		CMP		#$02
		BCS		loc_52F40
		LDA		_tmp11
		AND		#$10
		BNE		loc_52F40
		SEC
		LDA		_tmp0D
		SBC		_room_scroll_pos_x
		CMP		#$50
		BCC		loc_52F40
		CMP		#$B0
		BCS		loc_52F40
		LDA		#$30
		STA		_objsA._player._timer,X
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
		LDA		#$09
		STA		_tmp10
		LDA		#$04
		STA		_tmp0B
		JSR		_cur_obj_direction_up_set
		LDA		#$2F
		STA		_objsA._player.field_8,X
		LDA		#$65
		STA		_objsA._player._collision_box_idx,X
loc_52F40:
		JMP		_obj_jump_animate_test_ex
loc_52F43:
		LDA		#$04
		AND		_objsA._player._state,X
		BNE		loc_52F50
		LDA		#$04
		STA		_tmp0B
		BNE		loc_52F40
loc_52F50:
		DEC		_objsA._player._timer,X
		BEQ		loc_52F70
		LDA		#$00
		STA		_objsA._player.field_8,X
		LDA		#$06
		STA		_objsA._player._collision_box_idx,X
		LDA		#$01
		STA		_tmp0F
		LDA		#$00
		STA		_tmp0B
		LDA		_objsA._player._dir
		AND		#$40
		BNE		loc_52F6D
		JMP		_obj_jump_animate_test_left
loc_52F6D:
		JMP		_obj_jump_animate_test_right
loc_52F70:
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
		JMP		loc_52F40

; =============== S U B	R O U T	I N E =======================================
_obj_hndl23_soldierC:
		LDA		_tmp11
		ORA		#$01
		STA		_tmp11
		JSR		_obj_soldierB_common_subA
		LDA		#$00
		STA		_objsA._player.field_8,X
		LDA		#$06
		STA		_objsA._player._collision_box_idx,X
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_52FC5
		LDA		_tmp11
		AND		#$08
		BNE		loc_52FB1
		JSR		_rand
		LDA		_tmp13
		CMP		#$10
		BCS		loc_52FC5
		LDA		#$18
		STA		_objsA._player._timer,X
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
		LDA		#$2F
		STA		_objsA._player.field_8,X
		LDA		#$86
		STA		_objsA._player._collision_box_idx,X
loc_52FB1:
		DEC		_objsA._player._timer,X
		BEQ		loc_52FBC
		LDA		#$04
		STA		_tmp0B
		JMP		_objA_flush_and_continue
loc_52FBC:
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
		JMP		_objA_flush_and_continue
loc_52FC5:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl26_grenade_soldier:
		FLAG_TEST	FLAG0C_SYS
		BEQ		_obj_hndl1D_soldierB
		LDA		#_obj_hndl20_torture_room_soldier_idx
		STA		_objsA._player._hndl_idx,X
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl1D_soldierB:
_obj_hndl1E_soldierB:
_obj_hndl1F_soldierB:
_obj_hndl22_soldierB:
_obj_hndl24_soldierB:
_obj_hndl25_soldierB:
_obj_hndl27_soldierB:
_obj_hndl28_soldierB:
_obj_hndl29_soldierB:
		SEC
		LDA		_objsA._player._hndl_idx,X
		AND		#$3F
		SBC		#$1D
		ASL
		TAY
		LDA		_tmp11
		ORA		_obj_soldiersB_params_list,Y
		STA		_tmp11
		LDA		_obj_soldiersB_params_list+1,Y
		STA		_tmp09
		CMP		#$06
		BNE		loc_52FF6
		LDA		#$19
		BNE		loc_52FF7
loc_52FF6:
		LDA		#$11
loc_52FF7:
		STA		_tmp0A
		JMP		_obj_soldierB_common_hndl
; ---------------------------------------------------------------------------
_obj_soldiersB_params_list:
		.BYTE $06,$06
		.BYTE $02,$05
		.BYTE $04,$05
		.BYTE $00,$00
		.BYTE $00,$00
		.BYTE $06,$06
		.BYTE $00,$00
		.BYTE $03,$06
		.BYTE $07,$06
		.BYTE $01,$06
		.BYTE $03,$05
		.BYTE $05,$06
		.BYTE $03,$06

; =============== S U B	R O U T	I N E =======================================
_obj_soldierB_common_subA:
		JSR		_obj_extra_enemy_deploy_test
		LDA		#$02
		STA		_tmp01
		LDA		#$09
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		#$04
		AND		_objsA._player._state,X
		BNE		loc_5303F
		LDA		#$03
		STA		_tmp0B
		LDA		#$08
		AND		_objsA._player._state,X
		BEQ		loc_5303C
		LDA		#$01
		STA		_tmp10
		JSR		_cur_obj_direction_down_set
loc_5303C:
		RTS
loc_5303F:
		LDA		_tmp11
		AND		#$10
		BNE		loc_53056
		SEC
		LDA		_tmp0D
		SBC		_room_scroll_pos_x
		CMP		#$50
		BCC		loc_53056
		CMP		#$B0
		BCC		loc_53059
loc_53056:
		JSR		_obj_hor_targeting_to_player_common
loc_53059:
		LDA		_tmp11
		AND		#$10
		BNE		loc_53099
		LDA		_tmp11
		AND		#$02
		BEQ		loc_5307D
		JSR		_rand
		AND		#$0F
		BEQ		loc_5307D
		SEC
		LDA		_tmp0D
		SBC		_room_scroll_pos_x
		CMP		#$28
		BCC		loc_5307D
		CMP		#$D8
		BCC		loc_5309F
loc_5307D:
		LDA		_tmp11
		AND		#$01
		BNE		loc_5308E
		LDA		#$01
		STA		_tmp0F
		LDA		#$00
		BEQ		loc_53096
loc_5308E:
		LDA		#$02
		STA		_tmp0F
		LDA		#$01
loc_53096:
		STA		_tmp0B
		JMP		loc_530A7
loc_53099:
		LDA		_objsA._player._dir
		AND		#$04
		BNE		loc_5307D
loc_5309F:
		LDA		#$00
		STA		_tmp0F
		LDA		#$00
		STA		_tmp0B
loc_530A7:
		LDA		_objsA._player._state,X
		AND		#$03
		BNE		loc_530BC
		LDA		_tmp11
		AND		#$04
		BEQ		locret_530E0
		JSR		_rand
		LDA		_tmp13
		CMP		#$04
		BCS		locret_530E0
loc_530BC:
		LDA		#$09
		STA		_tmp10
		LDA		#$03
		STA		_tmp0B
		JSR		_cur_obj_direction_up_set
		LDA		_tmp0E
		CMP		_objsA._player._y_pos
		BCS		loc_530DA
		LDA		_objsA._player.field_7,X
		AND		#$BF
		STA		_objsA._player.field_7,X
		LDA		#$06
		STA		_tmp10
		RTS
loc_530DA:
		LDA		_objsA._player.field_7,X
		ORA		#$40
		STA		_objsA._player.field_7,X
locret_530E0:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_extra_enemy_deploy_test:
		LDA		_objsA._player._dir		; test if fire weapon were used in this
		AND		#$04					; location. so force enemy duplication
		BNE		.extra_enemy_insert		; because of SOUND!
		LDA		_game._play_hours		; in other case, do this only at daytime
		CMP		#$04
		BCC		locret_530F5
		CMP		#$15
		BCS		locret_530F5
.extra_enemy_insert:
		TXA								; X = current object OFS ($10-$90)
		PHA
		TYA
		PHA
		LDY		#$40
		LDA		_objsA._player._hndl_idx,Y	; check if o4 slot is empty
		BMI		loc_53122
		LDY		#$60
		LDA		_objsA._player._hndl_idx,Y
		BPL		loc_53156
loc_53122:
		JSR		_obj_to_obj_copy		; copy cur object to empty slot
		LDA		_objsA._player._room_num; set position opposing to the player
		CMP		#$02
		BCS		loc_5313A
		LDA		#$03					; if player in rooms 0 or 1 set
		STA		_tobjA._room_num+$10,Y	; position to room 3, x == 256-64
		LDA		#$C0
		STA		_tobjA._x_pos+$10,Y
		BNE		loc_53149
loc_5313A:
		LDA		#$00					; or if player in rooms 2 or 3 set
		STA		_tobjA._room_num+$10,Y	; position to room 0, x == 64
		LDA		#$40
		STA		_tobjA._x_pos+$10,Y
loc_53149:
		LDA		#$D0
		STA		_tobjA._y_pos+$10,Y		; y pos is fixed
		LDA		#_obj_hndl15_grenades_idx	; prize is always grenades
		STA		_tobjA._prize_idx+$10,Y
		LDA		#$04
		STA		_tobjA._damage+$10,Y
		STA		_tobjA.field_C+$10,Y
loc_53156:
		PLA
		TAY
		PLA
		TAX
locret_530F5:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_to_obj_copy:
		LDA		#$10
		STA		_tmp01
loc_53100:
		LDA		_objsA._player._hndl_idx,X
		STA		_objsA._player._hndl_idx,Y
		INX
		INY
		DEC		_tmp01
		BNE		loc_53100
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_soldierB_common_hndl:
		JSR		_obj_soldierB_common_subA
		LDA		_tmp11
		AND		#$08
		BNE		loc_53183
		LDA		_tmp0B
		CMP		#$02
		BCS		loc_53180
		DEC		_objsA._player._timer,X
		BNE		loc_53180
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
		LDA		#$04
		STA		_tmp0B
		LDA		_tmp09
		STA		_objsA._player._collision_box_idx,X
		LDA		#$10
		STA		_objsA._player._timer,X
loc_53180:
		JMP		_obj_jump_animate_test_ex
loc_53183:
		DEC		_objsA._player._timer,X
		BNE		loc_53197
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
		LDA		#$06
		STA		_objsA._player._collision_box_idx,X
		JSR		_obj_player_rand_timer_set
		JMP		_objA_flush_and_continue
loc_53197:
		LDA		#$04
		STA		_tmp0B
		LDA		_tmp09
		STA		_objsA._player._collision_box_idx,X
		LDA		_objsA._player._hndl_idx,X
		AND		#$3F
		CMP		#_obj_hndl28_soldierB_idx
		BCC		loc_531BA
		LDA		_pad
		AND		#$04
		BEQ		loc_531BA
		LDA		#$05
		STA		_tmp0B
		LDA		#$04
		STA		_objsA._player._collision_box_idx,X
		LDA		#$08
		STA		_tmp0A
loc_531BA:
		LDA		_objsA._player._timer,X
		CMP		#$08
		BNE		loc_531C3
		JSR		_obj_prize_deployB
loc_531C3:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_prize_deployB:
		LDA		#$10
		STA		_tmp02
		LDA		_tmp0A
		STA		_tmp03
		LDA		_objsA._player._hndl_idx,X
		AND		#$3F
		CMP		#_obj_hndl26_grenade_soldier_idx
		BEQ		loc_531E5
		CMP		#_obj_hndl27_soldierB_idx
		BEQ		loc_531FA
		LDA		#$40
		STA		_tmp06
		LDA		#$04
		BNE		loc_53202
loc_531E5:
		LDA		_tmp11
		ORA		#$80
		STA		_tmp11
		LDA		#$00
		STA		_tmp10
		LDA		#$55
		STA		_tmp06
		LDA		#_objB_hndl05_idx
		BNE		loc_53202
loc_531FA:
		LDA		#$40
		STA		_tmp06
		LDA		#_objB_hndl08_idx
loc_53202:
		STA		_tmp00
		JMP		_obj_enemy_projectile_deploy

; =============== S U B	R O U T	I N E =======================================
_obj_hndl2B_boss_pirate:
		LDA		_game._bosses
		AND		#$40
		BEQ		loc_53210
		JMP		_obj_kill_and_continue
loc_53210:
		JSR		_enemy_explosion_handler
		BCC		_obj_hndl2A_pirate
		LDA		_objsA._player.field_C,X
		BNE		loc_53221
		LDA		_game._bosses
		ORA		#$40
		STA		_game._bosses
loc_53221:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl2A_pirate:
		LDA		#$01
		STA		_tmp01
		LDA		#$06
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		LDA		_tmp11
		AND		#$10
		BNE		loc_53272
		LDA		_tmp11
		AND		#$08
		BNE		loc_5327C
		DEC		_objsA._player._timer,X
		BNE		_j_obj_jump_animate_test_ex0
		JSR		_obj_hor_targeting_to_player_common
		JSR		_obj_player_rand_timer_set
		LDA		_tmp13
		CMP		#$30
		BCC		loc_53272
		CMP		#$60
		BCC		loc_53267
		LDA		_tmp11
		ORA		#$08
		STA		_tmp11
		LDA		#$08
		STA		_objsA._player._timer,X
		LDA		#$02
		BNE		loc_53273
loc_53267:
		LDA		#$01
		BNE		loc_53273
loc_53272:
		LDA		#$00
		STA		_tmp0B
		JMP		_obj_jump_animate_test
loc_53273:
		STA		_tmp0B
		LDA		#$01
		STA		_tmp0F
_j_obj_jump_animate_test_ex0:
		JMP		_obj_jump_animate_test_ex
loc_5327C:
		DEC		_objsA._player._timer,X
		BNE		loc_5328D
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
		LDA		#$08
		STA		_objsA._player._timer,X
		JMP		_obj_jump_animate_test_ex
loc_5328D:
		LDA		_objsA._player._timer,X
		CMP		#$04
		BNE		_j_obj_jump_animate_test_ex0
		JSR		_obj_move_animate_common
		JSR		_objA_frontal_collision_line_calc
		LDA		#$18
		STA		_tmp0A
		JSR		_obj_prize_deployB
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl2C_dubina_man:
		LDA		#$03
		STA		_tmp01
		LDA		#$06
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		_tmp0B
		CMP		#$02
		BNE		loc_532C9
		LDA		_objsA._player._hndl_idx,X
		AND		#$40
		BEQ		loc_5330A
		LDA		#$10
		STA		_objsA._player._timer,X
		LDA		#$01
		STA		_tmp0B
		LDA		#$00
		STA		_objsA._player.field_8,X
loc_532C9:
		DEC		_objsA._player._timer,X
		BEQ		loc_532F9
		JSR		_obj_hor_targeting_to_player_common
		LDA		_tmp11
		AND		#$10
		BNE		loc_532EB
		LDA		_tmp11
		AND		#$40
		BNE		loc_532E5
		LDA		_objsA._player._dir
		AND		#$40
		BNE		loc_532F2
		BEQ		loc_532EB
loc_532E5:
		LDA		_objsA._player._dir
		AND		#$40
		BEQ		loc_532F2
loc_532EB:
		LDA		#$03
		STA		_tmp0F
		BNE		loc_53307
loc_532F2:
		LDA		#$01
		STA		_tmp0F
		BNE		loc_53307
loc_532F9:
		LDA		#$02
		STA		_tmp0B
		LDA		#$28
		STA		_objsA._player.field_8,X
		LDA		#$00
		STA		_tmp0F
		STA		_tmp10
loc_53307:
		JMP		_obj_jump_animate_test_ex
loc_5330A:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl2D_spectre:
		LDA		#$01
		STA		_tmp01
		STA		_tmp02
		LDA		#$0B
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		LDA		_tmp10
		BNE		loc_53339
		LDA		#$00
		STA		_tmp0B
		LDA		#$09
		STA		_objsA._player._collision_box_idx,X
		DEC		_objsA._player._timer,X
		BNE		loc_53350
		LDA		#$01
		STA		_tmp0B
		LDA		#$0A
		STA		_objsA._player._collision_box_idx,X
		LDA		#$18
		STA		_objsA._player._timer,X
loc_53339:
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_5334D
		JSR		_obj_hor_targeting_to_player_common
		LDA		#$01
		STA		_tmp0F
		LDA		#$0B
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
loc_5334D:
		JMP		_obj_jump_animate_test_ex
loc_53350:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl2E_armored_man:
		LDA		#$01
		STA		_tmp01
		LDA		#$06
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_hor_targeting_to_player_common
		DEC		_objsA._player._timer,X
		BEQ		loc_5337A
		LDA		_objsA._player._timer,X
		CMP		#$0C
		BCC		loc_5339E
		LDA		_objsA._player._timer,X
		CMP		#$18
		BCC		loc_53393
		LDA		_objsA._player._timer,X
		CMP		#$30
		BCC		loc_53388
		BCS		loc_53381
loc_5337A:
		LDA		#$40
		STA		_objsA._player._timer,X
		JMP		_objA_flush_and_continue
loc_53381:
		LDA		#$00
		STA		_tmp0B
		JMP		_objA_flush_and_continue
loc_53388:
		LDA		#$01
		STA		_tmp0B
		STA		_tmp0F
		JMP		_obj_jump_animate_test_ex
loc_53393:
		LDA		#$02
		STA		_tmp0B
		LDA		#$01
		STA		_tmp0F
		JMP		_obj_jump_animate_test_ex
loc_5339E:
		AND		#$03
		BEQ		loc_533A5
		JMP		_objA_flush_and_continue
loc_533A5:
		LDA		#$03
		STA		_tmp0B
		LDA		#$00
		STA		_tmp0F
		JSR		_obj_move_animate_common
		JSR		_objA_frontal_collision_line_calc
		LDA		#$10
		STA		_tmp02
		STA		_tmp03
		LDA		#$30
		STA		_tmp06
		LDA		#_objB_hndl07_idx
		STA		_tmp00
		JSR		_obj_enemy_projectile_deploy
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl2F_strong_man:
		LDA		#$02
		STA		_tmp01
		LDA		#$09
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_53445
		JSR		_obj_sub52242
		LDA		_objsA._player._hndl_idx,X
		AND		#$40
		BEQ		loc_53448
		JSR		_rand
		LDA		_tmp13
		AND		#$03
		STA		_tmp0B
		CMP		#$00
		BEQ		loc_533FA
		CMP		#$01
		BEQ		loc_53405
		CMP		#$02
		BEQ		loc_53418
		CMP		#$03
		BEQ		loc_5342B
loc_533FA:
		LDA		#$00
		STA		_tmp0B
		STA		_objsA._player.field_8,X
		BEQ		loc_53448
loc_53405:
		LDA		#$02
		STA		_tmp0F
		LDA		#$01
		STA		_tmp0B
		LDA		#$28
		STA		_objsA._player.field_8,X
		LDA		#$17
		STA		_objsA._player._collision_box_idx,X
		BNE		loc_53445
loc_53418:
		LDA		#$02
		STA		_tmp0F
		STA		_tmp0B
		LDA		#$28
		STA		_objsA._player.field_8,X
		LDA		#$27
		STA		_objsA._player._collision_box_idx,X
		BNE		loc_53445
loc_5342B:
		JSR		_obj_hor_targeting_to_player_common
		LDA		#$02
		STA		_tmp0F
		LDA		#$09
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
		LDA		#$03
		STA		_tmp0B
		LDA		#$28
		STA		_objsA._player.field_8,X
		LDA		#$27
		STA		_objsA._player._collision_box_idx,X
loc_53445:
		JMP		_obj_jump_animate_test_ex
loc_53448:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl30_burning_man:
		LDA		_tmp11
		AND		#$01
		BNE		loc_53467
		LDA		_objsA._player._state,X
		BPL		loc_53485
		LDA		_tmp11
		ORA		#$01
		STA		_tmp11
		LDA		#$01
		STA		_tmp0B
		LDA		#$E8
		STA		_objsA._player.field_7,X
		LDA		#$08
		STA		_objsA._player._timer,X
loc_53467:
		JSR		_explosion_start_and_prize_deploy
		LDA		_objsA._player.field_C,X
		BEQ		loc_53485
		LDA		#$02
		STA		_tmp01
		LDA		#$09
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		#$04
		AND		_objsA._player._state,X
		BNE		loc_53488
		JSR		_obj_move_animate_common
		JSR		_objA_frontal_collision_line_calc
loc_53485:
		JMP		_objA_flush_and_continue
loc_53488:
		DEC		_objsA._player._timer,X
		BNE		loc_53490
		LDA		#$00
		STA		_objsA._player.field_C,X
loc_53490:
		JSR		_obj_hor_targeting_to_player_common
		LDA		#$02
		STA		_tmp0F
		LDA		#$09
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
		LDA		#$F0
		STA		_objsA._player._anim_phase_idx,X
		LDA		#$01
		STA		_tmp0B
		JSR		_obj_move_animate_common
		JSR		_objA_frontal_collision_line_calc

; =============== S U B	R O U T	I N E =======================================
_obj_prize_deployC:
		LDA		_tmp11
		PHA
		JSR		_rand
		STA		_tmp11
		LDA		#$10
		STA		_tmp02
		STA		_tmp03
		LDA		_tmp13
		AND		#$33
		STA		_tmp06
		LDA		#_objB_hndl07_idx
		STA		_tmp00
		JSR		_obj_enemy_projectile_deploy
		PLA
		STA		_tmp11
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl31_machete_man:
		LDA		#$02
		STA		_tmp01
		LDA		#$06
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_53506
		LDA		_objsA._player._y_pos
		AND		#$F0
		CMP		_tmp0E
		BEQ		loc_534F7
		SEC
		LDA		_tmp0D
		SBC		_room_scroll_pos_x
		CMP		#$40
		BCC		loc_53509
		CMP		#$C0
		BCS		loc_53509
loc_534F7:
		LDA		#$01
		STA		_tmp0B
		LDA		#$02
		STA		_tmp0F
		LDA		#$06
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
loc_53506:
		JMP		_obj_jump_animate_test_ex
loc_53509:
		JSR		_obj_hor_targeting_to_player_common
		JSR		_objA_frontal_collision_line_calc
		LDA		#$00
		STA		_tmp0B
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl32_skull_monkey:
		LDA		#$02
		STA		_tmp01
		LDA		#$09
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		_tmp0B
		CMP		#$02
		BNE		loc_53534
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_53566
		LDA		#$05
		STA		_objsA._player._timer,X
		BNE		loc_5353B
loc_53534:
		JSR		_obj_sub52242
		DEC		_objsA._player._timer,X
		BNE		_j_obj_jump_animate_test_ex
loc_5353B:
		JSR		_rand
		LDA		_tmp13
		AND		#$1F
		ORA		#$20
		STA		_objsA._player._timer,X
		LDA		_tmp13
		CMP		#$40
		BCC		loc_5359B
		CMP		#$80
		BCC		loc_53589
loc_53553:
		LDA		#$09
		STA		_tmp10
		LDA		#$02
		STA		_tmp0F
		JSR		_cur_obj_direction_up_set
		LDA		#$02
		STA		_tmp0B
		LDA		#$0A
		STA		_objsA._player._collision_box_idx,X
loc_53566:
		JSR		_obj_hor_targeting_to_player_common
		LDA		_tmp0E
		CMP		_objsA._player._y_pos
		BCS		loc_53578
		LDA		_objsA._player.field_7,X
		AND		#$BF
		STA		_objsA._player.field_7,X
		JMP		_obj_jump_animate_test_ex
loc_53578:
		INC		_objsA._player._timer,X
		LDA		_objsA._player._timer,X
		AND		#$01
		STA		_tmp02
		LDA		_objsA._player.field_7,X
		ORA		#$40
		STA		_objsA._player.field_7,X
		JMP		_obj_jump_animate_test_ex
loc_53589:
		JSR		_obj_hor_targeting_to_player_common
		LDA		#$09
		STA		_objsA._player._collision_box_idx,X
		LDA		#$01
		STA		_tmp0F
		STA		_tmp0B
		JMP		_obj_jump_animate_test_ex
loc_5359B:
		LDA		#$09
		STA		_objsA._player._collision_box_idx,X
		LDA		#$00
		STA		_tmp0F
		STA		_tmp0B
_j_obj_jump_animate_test_ex:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl33_shield_man:
		LDA		#$02
		STA		_tmp01
		LDA		#$09
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		LDA		_pad
		AND		#$40
		BNE		loc_535F4
		DEC		_objsA._player._timer,X
		BNE		loc_5360F
		JSR		_obj_hor_targeting_to_player_common
		JSR		_rand
		LDA		_tmp13
		AND		#$03
		STA		_tmp0B
		CMP		#$00
		BEQ		loc_535DE
		CMP		#$01
		BEQ		loc_535E9
		CMP		#$02
		BEQ		loc_535F4
		BNE		loc_53603
loc_535DE:
		LDA		#$05
		STA		_objsA._player._collision_box_idx,X
		LDA		#$00
		BEQ		loc_5360B
loc_535E9:
		LDA		#$05
		STA		_objsA._player._collision_box_idx,X
		LDA		#$02
		BNE		loc_5360B
loc_535F4:
		LDA		#$02
		STA		_tmp0B
		LDA		#$04
		STA		_objsA._player._collision_box_idx,X
		LDA		#$00
		BEQ		loc_5360B
loc_53603:
		LDA		#$05
		STA		_objsA._player._collision_box_idx,X
		LDA		#$00
loc_5360B:
		STA		_tmp0F
		LDA		#$10
		STA		_objsA._player._timer,X
loc_5360F:
		JSR		_obj_move_animate_common
		JSR		_objA_frontal_collision_line_calc
		LDA		_tmp0B
		CMP		#$03
		BNE		loc_53632
		LDA		_objsA._player._timer,X
		CMP		#$08
		BNE		loc_53632
		LDA		#$10
		STA		_tmp02
		STA		_tmp03
		LDA		#$30
		STA		_tmp06
		LDA		#_objB_hndl08_idx
		STA		_tmp00
		JSR		_obj_enemy_projectile_deploy
loc_53632:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl34_crouching_bomb_man:
		FLAG_TEST	FLAG0C_SYS
		BEQ		loc_53643
		LDA		#_obj_hndl35_guard_of_torture_room_idx
		STA		_objsA._player._hndl_idx,X
		JMP		_objA_flush_and_continue
loc_53643:
		JSR		_enemy_explosion_handler
		BCS		loc_5367F
		LDA		#$02
		STA		_tmp01
		LDA		#$09
		STA		_tmp03
		JSR		_obj_sub5224F
		DEC		_objsA._player._timer,X
		BNE		loc_53679
		JSR		_obj_hor_targeting_to_player_common
		JSR		_rand
		LDA		_tmp13
		AND		#$03
		STA		_tmp0B
		CMP		#$02
		BCS		loc_53671
		LDA		#$06
		STA		_objsA._player._collision_box_idx,X
		BNE		loc_53675
loc_53671:
		LDA		#$04
		STA		_objsA._player._collision_box_idx,X
loc_53675:
		LDA		#$10
		STA		_objsA._player._timer,X
loc_53679:
		JSR		_obj_move_animate_common
		JSR		_objA_frontal_collision_line_calc
loc_5367F:
		LDA		_tmp0B
		AND		#$01
		BEQ		loc_5369C
		LDA		_objsA._player._timer,X
		CMP		#$08
		BNE		loc_5369C
		LDA		#$10
		STA		_tmp02
		STA		_tmp03
		LDA		#$30
		STA		_tmp06
		LDA		#_objB_hndl06_idx
		STA		_tmp00
		JSR		_obj_enemy_projectile_deploy
loc_5369C:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl35_guard_of_torture_room:
		LDA		_pad
		AND		#$08
		BEQ		loc_536BB
		LDA		_objsA._player._state,X
		BPL		loc_536BB
		LDA		_game._scr_idx
		CMP		#$6E
		BNE		loc_536BB
		LDA		#$93
		STA		_game._scr_idx
		LDA		#$01
		STA		_game._redraw_req
loc_536BB:
		DEC		_objsA._player._timer,X
		BNE		loc_536D3
		LDA		#$20
		STA		_objsA._player._timer,X
		JSR		_obj_hor_targeting_to_player_common
		JSR		_rand
		LDA		_tmp13
		AND		#$01
		STA		_tmp0B
		LDA		#$20
		STA		_objsA._player._timer,X
loc_536D3:
		JSR		_objA_frontal_collision_line_calc
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl36_boss_fire_tiger:
		LDA		_game._bosses
		AND		#$01
		BEQ		loc_536E3
		JMP		_obj_kill_and_continue
loc_536E3:
		JSR		_enemy_explosion_handler
		BCC		loc_536F7
		LDA		_objsA._player.field_C,X
		BNE		loc_536F4
		LDA		_game._bosses
		ORA		#$01
		STA		_game._bosses
loc_536F4:
		JMP		_objA_flush_and_continue
loc_536F7:
		LDA		#$04
		STA		_tmp01
		LDA		#$05
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		INC		_objsA._player._timer,X
		LDA		_tmp11
		AND		#$10
		BNE		loc_53759
		LDA		_tmp11
		AND		#$01
		BEQ		loc_53726
		LDA		_objsA._player._timer,X
		AND		#$01
		BEQ		loc_5371D
		LDA		#$00
		STA		_tmp02
loc_5371D:
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_53767
		JMP		loc_5373D
loc_53726:
		JSR		_obj_hor_targeting_to_player_common
		LDA		_tmp11
		AND		#$10
		BNE		loc_53759
		SEC
		LDA		_tmp0D
		SBC		_room_scroll_pos_x
		CMP		#$10
		BCC		loc_53759
		CMP		#$F0
		BCS		loc_53759
loc_5373D:
		LDA		_tmp11
		ORA		#$01
		STA		_tmp11
		LDA		#$04
		STA		_tmp0F
		LDA		#$05
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
		LDA		#$01
		STA		_tmp0B
		LDA		#$F0
		STA		_objsA._player._anim_phase_idx,X
		BNE		loc_53767
loc_53759:
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
		LDA		#$00
		STA		_tmp0F
		STA		_tmp0B
loc_53767:
		JSR		_obj_move_animate_common
		JSR		_objA_frontal_collision_line_calc
		LDA		_objsA._player._timer,X
		AND		#$07
		BNE		loc_53776
		JMP		_obj_prize_deployC
loc_53776:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl37_boss_spider:
		LDA		_tmp0B
		CMP		#$02
		BNE		loc_53782
		JMP		_obj_boss_spider_drone_proj_anim
loc_53782:
		LDA		_game._bosses
		AND		#$02
		BEQ		loc_5378C
		JMP		_obj_kill_and_continue
loc_5378C:
		JSR		_enemy_explosion_handler
		BCC		loc_537A3
		LDA		_objsA._player.field_C,X
		BNE		loc_5379D
		LDA		_game._bosses
		ORA		#$02
		STA		_game._bosses
loc_5379D:
		JSR		_obj_adjust_field_7
		JMP		_objA_flush_and_continue
loc_537A3:
		JSR		_obj_adjust_field_7
		LDA		#$01
		STA		_tmp01
		LDA		#$0F
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_537EF
		DEC		_objsA._player._timer,X
		BNE		loc_537EF
		JSR		_obj_player_rand_timer_set
		JSR		_obj_hor_targeting_to_player_common
		LDA		_tmp0C
		BNE		loc_537CB
		JSR		_cur_obj_direction_right_set
loc_537CB:
		LDA		#$01
		STA		_tmp0F
		LDA		_tmp13
		CMP		#$80
		BCC		loc_537E7
		CMP		#$C0
		BCC		loc_537EB
		LDA		#$01
		STA		_tmp0B
		LDA		#$0F
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
		JMP		loc_537EF
loc_537E7:
		LDA		#$00
		STA		_tmp0F
loc_537EB:
		LDA		#$00
		STA		_tmp0B
loc_537EF:
		JSR		_obj_move_animate_common
		LDA		#$30
		STA		_tmp0A
		JSR		_obj_sub53EBA
		LDA		_objsA._player.field_2,X
		CMP		#$0C
		BNE		loc_5381A
		LDA		#$20
		STA		_tmp02
		LDA		#$10
		STA		_tmp03
		LDA		_objsA._player._hndl_idx,X
		STA		_tmp00
		LDA		#$04
		STA		_tmp05
		LDA		#$01
		STA		_tmp07
		LDA		#$02
		STA		_tmp04
		JSR		_obj_boss_projectile_insert
loc_5381A:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl38_boss_motorcycle:
		LDA		_game._bosses
		AND		#$04
		BEQ		loc_53827
		JMP		_obj_kill_and_continue
loc_53827:
		JSR		_enemy_explosion_handler
		BCC		loc_5383E
		LDA		_objsA._player.field_C,X
		BNE		loc_53838
		LDA		_game._bosses
		ORA		#$04
		STA		_game._bosses
loc_53838:
		JSR		_obj_adjust_field_7
		JMP		_objA_flush_and_continue
loc_5383E:
		JSR		_obj_adjust_field_7
		LDA		#$03
		STA		_tmp01
		LDA		#$05
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		LDA		_tmp11
		AND		#$10
		BNE		loc_53884
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_53887
		LDA		#$03
		STA		_tmp0F
		LDA		#$00
		STA		_tmp0B
		LDA		#$EE
		STA		_objsA._player._collision_box_idx,X
		DEC		_objsA._player._timer,X
		BNE		loc_53887
		JSR		_obj_player_rand_timer_set
		LDA		#$03
		STA		_tmp0F
		LDA		#$05
		STA		_tmp10
		JSR		_cur_obj_direction_up_set
		LDA		#$01
		STA		_tmp0B
		LDA		#$F6
		STA		_objsA._player._collision_box_idx,X
		BNE		loc_53887
loc_53884:
		JSR		_obj_hor_targeting_to_player_common
loc_53887:
		JSR		_obj_move_animate_common
		LDA		#$20
		STA		_tmp0A
		JSR		_obj_sub53EBA
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl39_boss_drone:
		LDA		#$02
		STA		_tmp01
		LDA		#$03
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		_tmp0B
		CMP		#$02
		BNE		loc_538A8
		JMP		_obj_boss_spider_drone_proj_anim
loc_538A8:
		LDA		_game._bosses
		AND		#$08
		BEQ		loc_538B2
		JMP		_obj_kill_and_continue
loc_538B2:
		JSR		_enemy_explosion_handler
		BCC		loc_538C9
		LDA		_objsA._player.field_C,X
		BNE		loc_538C3
		LDA		_game._bosses
		ORA		#$08
		STA		_game._bosses
loc_538C3:
		JSR		_obj_drone_proj_adjust_vert
		JMP		_objA_flush_and_continue
loc_538C9:
		JSR		_obj_drone_proj_adjust_vert
		INC		_objsA._player._timer,X
		LDA		_objsA._player._timer,X
		AND		#$3F
		BNE		loc_538DF
		LDA		#$01
		STA		_tmp0B
		LDA		#$0E
		STA		_objsA._player.field_8,X
		BNE		loc_538FA
loc_538DF:
		LDA		_tmp0B
		BEQ		loc_538FA
		LDA		_objsA._player._hndl_idx,X
		AND		#$40
		BNE		loc_538F2
		LDA		_objsA._player.field_2,X
		CMP		#$0F
		BEQ		loc_5393D
		BNE		loc_538FA
loc_538F2:
		LDA		#$00
		STA		_tmp0B
		STA		_objsA._player.field_8,X
loc_538FA:
		LDA		_tmp0C
		BNE		loc_53901
		JSR		_cur_obj_direction_right_set
loc_53901:
		LDA		_tmp0C
		CMP		#$03
		BNE		loc_5390A
		JSR		_cur_obj_direction_left_set
loc_5390A:
		LDA		#$10
		BIT		_tmp11
		BNE		loc_5391D
		LDA		_tmp0E
		CMP		#$40
		BCC		loc_5391D
		CMP		#$D0
		BCC		loc_53930
loc_5391D:
		JSR		_obj_hor_targeting_to_player_common
		JSR		_obj_vert_targeting_to_player_common
		LDA		#$02
		STA		_tmp0F
		JSR		_rand
		LDA		_tmp13
		AND		#$03
		STA		_tmp10
loc_53930:
		JSR		_obj_move_animate_common
		LDA		#$20
		STA		_tmp0A
		JSR		_obj_sub53EBA
		JMP		_objA_flush_and_continue
loc_5393D:
		LDA		#$10
		STA		_tmp02
		LDA		#$08
		STA		_tmp03
		LDA		_objsA._player._hndl_idx,X
		STA		_tmp00
		LDA		#$04
		STA		_tmp05
		LDA		#$01
		STA		_tmp07
		LDA		#$03
		STA		_tmp04
		JSR		_obj_boss_projectile_insert
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_drone_proj_adjust_vert:
		LDA		_tmp11
		AND		#$20
		BEQ		loc_53966
		LDA		#$00
		BEQ		loc_53967
loc_53966:
		LDA		#$2F
loc_53967:
		STA		_objsA._player.field_7,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_hndl3A_boss_yusin:
		LDA		_game._bosses
		AND		#$10
		BEQ		loc_53975
		JMP		_obj_kill_and_continue
loc_53975:
		FLAG_TEST	FLAG10_HELI_KEY
		BNE		loc_5397F
		JMP		_obj_kill_and_continue
loc_5397F:
		JSR		_enemy_explosion_handler
		BCC		loc_53999
		JSR		_obj_hor_targeting_to_player_common
		LDA		_objsA._player.field_C,X
		BNE		loc_53993
		LDA		_game._bosses
		ORA		#$10
		STA		_game._bosses
loc_53993:
		JSR		_obj_adjust_field_7
		JMP		_objA_flush_and_continue
loc_53999:
		JSR		_obj_adjust_field_7
		LDA		#$04
		STA		_tmp01
		LDA		#$07
		STA		_tmp03
		JSR		_obj_sub5224F
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_539ED
		LDA		#$00
		STA		_objsA._player.field_8,X
		LDA		#$03
		STA		_tmp0F
		LDA		#$00
		STA		_tmp0B
		JSR		_obj_sub52242
		LDA		_tmp11
		AND		#$10
		BEQ		loc_539C5
		JSR		_obj_hor_targeting_to_player_common
loc_539C5:
		LDA		#$80
		AND		_pad
		BNE		loc_539DA
		SEC
		LDA		_tmp0D
		SBC		_room_scroll_pos_x
		CMP		#$40
		BCC		loc_539ED
		CMP		#$C0
		BCS		loc_539ED
loc_539DA:
		LDA		#$07
		STA		_tmp10
		LDA		#$04
		STA		_tmp0F
		LDA		#$01
		STA		_tmp0B
		JSR		_cur_obj_direction_up_set
		LDA		#$2E
		STA		_objsA._player.field_8,X
loc_539ED:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl3B_boss_padovski:
		LDA		_game._bosses
		AND		#$20
		BEQ		loc_539FA
		JMP		_obj_kill_and_continue
loc_539FA:
		JSR		_enemy_explosion_handler
		BCC		loc_53A14
		JSR		_obj_hor_targeting_to_player_common
		LDA		_objsA._player.field_C,X
		BNE		loc_53A0E
		LDA		_game._bosses
		ORA		#$20
		STA		_game._bosses
loc_53A0E:
		JSR		_obj_adjust_field_7
		JMP		_objA_flush_and_continue
loc_53A14:
		JSR		_obj_adjust_field_7
		LDA		#$02
		STA		_tmp01
		LDA		#$06
		STA		_tmp03
		JSR		_obj_sub5224F
		JSR		_obj_sub52242
		LDA		#$04
		AND		_objsA._player._state,X
		BEQ		loc_53A8A
		LDA		_tmp11
		AND		#$10
		BEQ		loc_53A34
		JSR		_obj_hor_targeting_to_player_common
loc_53A34:
		LDA		#$40
		AND		_pad
		BEQ		loc_53A46
		LDA		#$08
		STA		_objsA._player._timer,X
		LDA		#$01
		STA		_tmp0B
		BNE		loc_53A56
loc_53A46:
		LDA		_tmp0B
		CMP		#$01
		BNE		loc_53A6C
		DEC		_objsA._player._timer,X
		BEQ		loc_53A6C
		LDA		_objsA._player._timer,X
		CMP		#$08
		BNE		loc_53A69
loc_53A56:
		LDA		#$10
		STA		_tmp02
		LDA		#$18
		STA		_tmp03
		LDA		#$30
		STA		_tmp06
		LDA		#_objB_hndl04_idx
		STA		_tmp00
		JSR		_obj_enemy_projectile_deploy
loc_53A69:
		JMP		_objA_flush_and_continue
loc_53A6C:
		LDA		#$00
		STA		_tmp0B
		LDA		#$02
		STA		_tmp0F
		LDA		#$80
		AND		_pad
		BNE		loc_53A82
		JSR		_rand
		AND		#$1F
		BNE		loc_53A8A
loc_53A82:
		LDA		#$01
		STA		_tmp0B
		LDA		#$10
		STA		_objsA._player._timer,X
loc_53A8A:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_adjust_field_7:
		LDA		_tmp11
		AND		#$20
		BEQ		loc_53A98
		LDA		#$C0
		BNE		loc_53A99
loc_53A98:
		LDA		#$EF
loc_53A99:
		STA		_objsA._player.field_7,X
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_hndl3C_plane:
		LDA		_tmp0B
		BNE		loc_53B0F
		LDA		_tmp0D
		CLC
		ADC		#$02
		STA		_tmp0D
		BCC		loc_53AB7
		INC		_tmp0C
loc_53AB7:
		LDA		_tmp0C
		CMP		#$03
		BNE		loc_53AB8
		LDA		_tmp0D
		BEQ		loc_53AEE
loc_53AB8:
		LDA		_tmp0C
		CMP		#$03
		BNE		loc_53AC4
		LDA		_tmp0D
		CMP		#$F0
		BEQ		loc_53AC7
loc_53AC4:
		JMP		_objA_flush_and_continue
loc_53AC7:
		INY
		LDA		#$00
		STA		_room_scroll_pos_x+1
		STA		_tmp0C
		STA		_room_scroll_pos_x
		STA		_ppu_mask_shadow
		LDA		#$01
		STA		_game._redraw_req
		LDA		#$02
		STA		_game._scr_idx
		LDA		#$78
		STA		_tmp0D
		LDA		#$40
		STA		_tmp0E
		JMP		_objA_flush_and_continue
loc_53AEE:
		LDA		#$3C
		STA		_objsA._o1,X
		LDA		#$01
		ORA		#$F0
		STA		_objsA._o1._anim_phase_idx,X
		LDA		#$00
		STA		_objsA._o1.field_7,X
		STA		_objsA._o1.field_8,X
		LDA		_tmp0D
		STA		_objsA._o1._x_pos,X
		LDA		_tmp0C
		STA		_objsA._o1._room_num,X
		LDA		_tmp0E
		STA		_objsA._o1._y_pos,X
		JMP		loc_53AB8
loc_53B0F:
		LDA		_tmp0E
		CMP		#$D0
		BEQ		loc_53B19
		INC		_tmp0E
		INC		_tmp0D
loc_53B19:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl3D_helicopterA:
		LDA		_tmp11
		AND		#$02
		BNE		loc_53B27
		JSR		_obj_heli_active_zone_obj_insert
		DEC		_objsA._o7._hndl_idx
loc_53B27:
		LDA		_tmp0B
		CMP		#$01
		BNE		loc_53B30
		JMP		_objA_flush_and_continue
loc_53B30:
		LDA		#$00
		STA		_tmp00
		STA		_tmp01
		STA		_tmp02
		STA		_tmp0F
		LDA		#$02
		STA		_tmp03
		LDA		_tmp0E
		CMP		#$50
		BEQ		loc_53B90
		CMP		#$D0
		BEQ		loc_53B6E
		LDA		_tmp11
		AND		#$01
		BNE		loc_53B86
		BEQ		loc_53B7C
loc_53B52:
		LDA		_game._scr_idx
		CMP		#$7F
		BEQ		loc_53B61
		LDA		#$A6
		STA		_game._scr_idx
		BNE		loc_53B66
loc_53B61:
		LDA		#$A7
		STA		_game._scr_idx
loc_53B66:
		LDA		#$01
		STA		_game._redraw_req
		JMP		_objA_flush_and_continue
loc_53B6E:
		LDA		_tmp11
		AND		#$01
		BNE		loc_53B52
		LDA		#$00
		DEC		_objsA._player._timer,X
		BNE		loc_53B9E
loc_53B7C:
		JSR		_cur_obj_direction_up_set
		LDA		#$02
		BNE		loc_53B9E
loc_53B86:
		JSR		_cur_obj_direction_down_set
		LDA		#$02
		BNE		loc_53B9E
loc_53B90:
		LDA		_tmp0C
		BEQ		loc_53B86
		LDA		_tmp11
		ORA		#$01
		STA		_tmp11
		LDA		#$00
loc_53B9E:
		STA		_tmp10
		JSR		_obj_move_animate_common
		JSR		_objA_frontal_collision_line_calc
		SEC
		LDA		_tmp0D
		SBC		#$01
		STA		_tmp0D
		LDA		_tmp0C
		SBC		#$00
		STA		_tmp0C
		LDA		_tmp0D
		CLC
		ADC		#$20
		STA		_objsA._o7._x_pos
		LDA		_tmp0C
		ADC		#$00
		STA		_objsA._o7._room_num
		LDA		_tmp0E
		STA		_objsA._o7._y_pos
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl3E_helicopterB:
		LDA		_game._scr_idx
		CMP		#$7C
		BCS		_obj_helicopter_for_cutsenes
		JMP		_obj_helicopter_for_locations

; =============== S U B	R O U T	I N E =======================================
_obj_helicopter_for_cutsenes:
		LDA		#$02
		STA		_tmp0B
		JSR		_cur_obj_direction_left_set
		LDA		#$01
		STA		_tmp01
		LDA		#$02
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		_tmp0E
		CMP		#$70
		BEQ		loc_53C23
		CMP		#$D0
		BEQ		loc_53BF7
		LDA		_tmp11
		AND		#$01
		BNE		loc_53C15
		BEQ		loc_53C07
loc_53BF4:
		JMP		_objA_flush_and_continue
loc_53BF7:
		LDA		_tmp11
		AND		#$01
		BNE		loc_53BF4
		LDA		#$00
		STA		_tmp0F
		DEC		_objsA._player._timer,X
		BNE		loc_53C35
loc_53C07:
		JSR		_cur_obj_direction_up_set
		LDA		#$01
		STA		_tmp0F
		LDA		#$02
		BNE		loc_53C35
loc_53C15:
		JSR		_cur_obj_direction_down_set
		LDA		#$01
		STA		_tmp0F
		LDA		#$02
		BNE		loc_53C35
loc_53C23:
		LDA		_tmp0C
		BEQ		loc_53C15
		LDA		_tmp11
		ORA		#$01
		STA		_tmp11
		LDA		#$01
		STA		_tmp0F
		LDA		#$00
loc_53C35:
		STA		_tmp10
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_helicopter_for_locations:
		LDA		_tmp11
		AND		#$02
		BNE		loc_53C41
		JSR		_obj_heli_active_zone_obj_insert
loc_53C41:
		LDA		_tmp0B
		CMP		#$01
		BNE		loc_53C4A
		JMP		_objA_flush_and_continue
loc_53C4A:
		LDA		_objA_buf_shuffle_pos
		CMP		#$10
		BNE		loc_53C56
		LDA		#$60
		STA		_objA_buf_shuffle_pos
loc_53C56:
		LDA		_helicopter_warp_idx
		BNE		_heli_flight_up
		FLAG_TEST	FLAG13_SYS
		BEQ		_heli_not_landed
		JMP		_heli_already_landed
_heli_not_landed:
		LDA		_game._scr_idx
		CMP		#$0B
		BNE		_heli_land_anim
		JMP		loc_53D66
_heli_land_anim:
		LDA		#$80
		STA		_objsA._player._hndl_idx
		LDA		#SEN07
		STA		_apu_se_noise_idx
		INC		_tmp0E
		INC		_objsA._o7._y_pos
		LDA		_tmp0E
		CMP		#$D0
		BNE		loc_53CB3
		FLAG_SET	FLAG13_SYS
		LDA		#_obj_hndl00_rambo_idx
		STA		_objsA._player._hndl_idx
		LDA		_game._scr_idx
		CMP		#$01
		BNE		loc_53C9A
		STA		_helicopter_warp_idx
loc_53C9A:
		LDA		_game._scr_idx
		CMP		#$62
		BNE		loc_53CB3
		LDA		#$09
		STA		_objsA._player._prize_idx,X
		STA		_objsA._o7._prize_idx
		LDA		#$09
		STA		_objsA._player._collision_box_idx,X
		STA		_objsA._o7._collision_box_idx
		LDA		#$00
		STA		_objsA._player.field_C,X
		STA		_objsA._o7.field_C
loc_53CB3:
		JMP		_objA_flush_and_continue
_heli_flight_up:
		LDA		_game._scr_idx
		CMP		#$0B
		BNE		loc_53CC4
		FLAG_TEST	FLAG06_POW_TAKEN
		BNE		loc_53CD3
loc_53CC4:
		LDA		_game._scr_idx
		CMP		#$01
		BEQ		loc_53CD3
		LDA		#$80
		STA		_objsA._player._hndl_idx
		LDA		#$00
		STA		_objsA._player.field_7
loc_53CD3:
		LDA		#SEN07
		STA		_apu_se_noise_idx
		DEC		_tmp0E
		DEC		_objsA._o7._y_pos
		LDA		_tmp0E
		CMP		#$20
		BCS		loc_53D23
		LDA		_game._scr_idx
		CMP		#$01
		BNE		loc_53CF5
		LDA		#$00
		STA		_helicopter_warp_idx
		LDA		#$80
		STA		_objsA._o7._hndl_idx
		JMP		_obj_kill_and_continue
loc_53CF5:
		LDA		_helicopter_warp_idx
		STA		_game._scr_idx
		LDA		#$01
		STA		_game._redraw_req
		LDA		#$03
		STA		_objsA._player._room_num
		STA		_room_scroll_pos_x+1
		LDA		#$78
		STA		_objsA._player._x_pos
		LDA		#$00
		STA		_helicopter_warp_idx
		STA		_room_scroll_pos_x
		LDA		_objsA._player._dir
		AND		#$BF
		STA		_objsA._player._dir
		FLAG_CLEAR	FLAG13_SYS
loc_53D23:
		JMP		_objA_flush_and_continue
_heli_already_landed:
		LDA		_game._scr_idx
		CMP		#$01
		BEQ		loc_53D31
		CMP		#$62
		BNE		loc_53D3D
loc_53D31:
		LDA		#$00
		STA		_helicopter_warp_idx
		LDA		#$80
		STA		_objsA._o7._hndl_idx
		JMP		_obj_kill_and_continue
loc_53D3D:
		LDA		_pad
		AND		#$08
		BEQ		loc_53D63
		LDA		_objsA._player._state,X
		BPL		loc_53D63
		LDA		_game._scr_idx
		CMP		#$54
		BNE		loc_53D51
		LDA		#$9E
loc_53D51:
		CMP		#$77
		BNE		loc_53D57
		LDA		#$A2
loc_53D57:
		CMP		#$80
		BCC		loc_53D63
		STA		_game._scr_idx
		LDA		#$01
		STA		_game._redraw_req
loc_53D63:
		JMP		_objA_flush_and_continue
loc_53D66:
		LDA		_tmp0E
		CMP		#$70
		BCS		loc_53D73
		CMP		#$30
		BCC		loc_53D79
		BCS		loc_53D7C
loc_53D73:
		JSR		_cur_obj_direction_up_set
		JMP		loc_53D7C
loc_53D79:
		JSR		_cur_obj_direction_down_set
loc_53D7C:
		LDA		_tmp11
		AND		#$80
		BNE		loc_53D89
		INC		_tmp0E
		INC		_objsA._o7._y_pos
		JMP		loc_53D8D
loc_53D89:
		DEC		_tmp0E
		DEC		_objsA._o7._y_pos
loc_53D8D:
		LDA		_pad
		AND		#$08
		BEQ		loc_53DA9
		LDA		_objsA._player._state,X
		BPL		loc_53DA9
		LDA		_game._scr_idx
		CMP		#$0B
		BNE		loc_53DA9
		LDA		#$96
		STA		_game._scr_idx
		LDA		#$01
		STA		_game._redraw_req
loc_53DA9:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_heli_active_zone_obj_insert:
		LDA		#$02
		STA		_objsA._o7._dir
		ORA		_tmp11
		STA		_tmp11
		LDA		#_obj_hndl3E_helicopterB_idx
		STA		_objsA._o7._hndl_idx
		LDA		#$F0
		STA		_objsA._player._anim_phase_idx,X
		LDA		#$F1
		STA		_objsA._o7._anim_phase_idx
		LDA		#$18
		STA		_objsA._player.field_7,X
		LDA		#$0F
		STA		_objsA._player._collision_box_idx,X
		LDA		#$00
		STA		_tmp0B
		STA		_objsA._player.field_8,X
		STA		_objsA._o7.field_7
		STA		_objsA._o7.field_8
		FLAG_TEST	FLAG13_SYS
		BEQ		loc_53DE7
		LDA		#$D0
		STA		_tmp0E
loc_53DE7:
		LDA		_tmp0D
		CLC
		ADC		#$20
		STA		_objsA._o7._x_pos
		LDA		_tmp0C
		ADC		#$00
		STA		_objsA._o7._room_num
		LDA		_tmp0E
		STA		_objsA._o7._y_pos
		LDA		#$80
		STA		_objsA._o7._prize_idx
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_hndl3F_multipurpose:
		LDA		_tmp0B
		BEQ		_hidden_static_prize_object
		CMP		#$05
		BEQ		_special_head_prize
		CMP		#$06
		BEQ		_rambo_shout_animate

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_regular_enemy_explosion:
		LDA		_objsA._player._hndl_idx,X
		AND		#$40
		BEQ		loc_53E17
		LDA		_tmp0B
		BEQ		loc_53E17
		LDA		#$80
		STA		_objsA._player._hndl_idx,X
loc_53E17:
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_hidden_static_prize_object:
		JSR		_enemy_explosion_handler
		JMP		_objA_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_rambo_shout_animate:
		LDA		#$04
		STA		_tmp01
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		#$10
		BIT		_tmp11
		BEQ		loc_53E34
		JMP		_obj_kill_and_continue
loc_53E34:
		LDA		_tmp0E
		CMP		#$40
		BCC		loc_53E54
		LDA		_tmp11
		AND		#$08
		BEQ		loc_53E51
		LDA		_tmp0D
		SEC
		SBC		_tmp0F
		STA		_tmp0D
		BCS		loc_53E35
		DEC		_tmp0C
loc_53E35:
		LDA		#$00
		STA		_tmp0F
loc_53E51:
		JMP		_obj_jump_animate_test_ex
loc_53E54:
		JMP		_obj_kill_and_continue

; =============== S U B	R O U T	I N E =======================================
_special_head_prize:
		LDA		#$00
		STA		_tmp00
		STA		_tmp01
		STA		_tmp02
		LDA		#$03
		STA		_tmp03
		LDA		_tmp0E
		CMP		#$D0
		BCS		loc_53EB4
		LDA		_objsA._player._state,X
		BPL		loc_53EB7
		LDA		#SEP04
		STA		_apu_se_pulse_idx
		JSR		_rand
		CMP		#$50
		BCC		loc_53E95
		CMP		#$A0
		BCC		loc_53EA9
		LDA		_objsA._player._anim_phase_idx
		AND		#$0F
		CMP		#$04
		BNE		loc_53E88
		LDA		#$F0
		STA		_objsA._player._anim_phase_idx
loc_53E88:
		LDA		_objsA._player._dir
		ORA		#$20
		STA		_objsA._player._dir
		LDA		#$FF
		STA		_objsA._player._timer
		JMP		_obj_kill_and_continue
loc_53E95:
		CLC
		LDA		_game._life
		ADC		#100
		STA		_game._life
		BCC		loc_53E96
		INC		_game._life+1
loc_53E96:
		JMP		_obj_kill_and_continue
loc_53EA9:
		JSR		_rand
		AND		#$03
		TAY
		LDA		#$64
		STA		_game._ammo_knife,Y
loc_53EB4:
		JMP		_obj_kill_and_continue
loc_53EB7:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_sub53EBA:
		LDA		_tmp11
		EOR		_tmp12
		ASL
		ASL
		BCC		locret_53EE5
		LDA		#$40
		BIT		_tmp11
		BNE		loc_53ED8
		SEC
		LDA		_tmp0D
		SBC		_tmp0A
		STA		_tmp0D
		LDA		_tmp0C
		SBC		#$00
		STA		_tmp0C
		RTS
loc_53ED8:
		LDA		_tmp0D
		CLC
		ADC		_tmp0A
		STA		_tmp0D
		BCC		locret_53EE5
		INC		_tmp0C
locret_53EE5:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_boss_projectile_insert:
		TXA
		PHA
		TYA
		PHA
		LDX		#$00
loc_53EEC:
		LDA		_objsA._player._hndl_idx,X
		BPL		loc_53F47
		LDY		#$00
loc_53EF2:
		LDA		_obj_data_boss_projectile,Y
		STA		_objsA,X
		INY
		INX
		CPY		#$10
		BNE		loc_53EF2
		SEC
		TXA
		SBC		#$10
		TAX
		LDA		_tmp11
		AND		#$40
		BNE		loc_53F20
		LDA		_tmp0D
		CLC
		ADC		_tmp02
		STA		_objsA._player._x_pos,X
		LDA		_tmp0C
		ADC		#$00
		STA		_objsA._player._room_num,X
		LDA		#$1F
		STA		_objsA._player._timer,X
		LDA		#$00
		STA		_objsA._player._dir,X
		BEQ		loc_53F2D
loc_53F20:
		SEC
		LDA		_tmp0D
		SBC		_tmp02
		STA		_objsA._player._x_pos,X
		LDA		_tmp0C
		SBC		#$00
		STA		_objsA._player._room_num,X
loc_53F2D:
		LDA		_tmp0E
		SEC
		SBC		_tmp03
		STA		_objsA._player._y_pos,X
		LDA		_tmp00
		STA		_objsA._player._hndl_idx,X
		LDA		_tmp05
		STA		_objsA._player._damage,X
		LDA		_tmp04
		STA		_objsA._player._collision_box_idx,X
		LDA		_tmp07
		STA		_objsA._player.field_C,X
		JMP		loc_53F50
loc_53F47:
		CLC
		TXA
		ADC		#$10
		TAX
		CPX		#$80
		BNE		loc_53EEC
loc_53F50:
		PLA
		TAY
		PLA
		TAX
		RTS
; ---------------------------------------------------------------------------
_obj_data_boss_projectile:
		.BYTE _obj_hndl37_boss_spider_idx
		.BYTE $F2,$00,$00,$00,$00,$C0,$2F,$00,$02,$00,$0A,$FF,$00,$15,$F0

; =============== S U B	R O U T	I N E =======================================
_obj_boss_spider_drone_proj_anim:
		LDA		#$04
		STA		_tmp01
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		INC		_objsA._player._timer,X
		LDA		_objsA._player._timer,X
		AND		#$1F
		TAY
		LDA		_boss_spider_drone_proj_anim_tbl,Y
		AND		#$F0
		LSR
		LSR
		LSR
		LSR
		STA		_tmp0F
		LDA		_boss_spider_drone_proj_anim_tbl,Y
		AND		#$0F
		STA		_tmp10
		TYA
		AND		#$0F
		BNE		loc_53FC0
		LDA		#$10
		BIT		_tmp11
		BEQ		loc_53F97
		JMP		_obj_kill_and_continue
loc_53F97:
		LDA		_objsA._player._timer,X
		AND		#$20
		ASL
		ASL
		LSR		_tmp11
		ORA		_tmp11
		AND		#$C0
		STA		_tmp11
		JSR		_obj_move_animate_common
		LDA		_tmp11
		PHA
		LDA		#$02
		STA		_tmp0F
		STA		_tmp10
		JSR		_obj_hor_targeting_to_player_common
		JSR		_obj_vert_targeting_to_player_common
		JSR		_obj_move_animate_common
		PLA
		STA		_tmp11
		JMP		loc_53FC3
loc_53FC0:
		JSR		_obj_move_animate_common
loc_53FC3:
		JSR		_objA_frontal_collision_line_calc
		JMP		_objA_flush_and_continue
; ---------------------------------------------------------------------------
_boss_spider_drone_proj_anim_tbl:
		.BYTE $30,$31,$31,$32,$32,$22,$22,$22,$22,$22,$22,$23,$23,$13,$13,$03
		.BYTE $03,$13,$13,$23,$23,$22,$22,$22,$22,$22,$22,$32,$32,$31,$31,$30

		SECTION_END "OBJECTS PROGRAM"

		SECTION_START
		INCLUDE "../game_data.inc"
		SECTION_END "GAME DATA"

		SECTION_START
		INCLUDE "../sprites.inc"
		SECTION_END "SPRITES DATA"

		BANK_END 6,$C000
