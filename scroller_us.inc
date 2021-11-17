
; =============== S U B	R O U T	I N E =======================================
_scroller_screen:
		TYA
		PHA
		TXA
		PHA
		LDA		#$10
		STA		_PPU_CTRL
		LDA		#$00
		STA		_PPU_MASK
		LDA		_PPU_STATUS
		LDA		#$20					; manually clear screen here
		STA		_PPU_ADDR				; it seems this routines are added
		LDA		#$00					; at the very later stage of develop
		STA		_PPU_ADDR				; so they are copy some other code
		LDA		#$FE					; and sored at the fixed position
		LDY		#$1E					; at the nd of the ROM
loc_6399F:
		LDX		#$20
loc_639A1:
		STA		_PPU_DATA
		DEX
		BNE		loc_639A1
		DEY
		BNE		loc_6399F
		LDA		_PPU_STATUS
		LDA		#$23					; refill attrs for drawing
		STA		_PPU_ADDR				; helicopter as well as bio
		LDA		#$C0
		STA		_PPU_ADDR
		LDA		#$FF
		LDY		#$10
loc_639BB:
		STA		_PPU_DATA
		DEY
		BNE		loc_639BB
		LDA		#$00					; since in us version they changed
		LDY		#$30					; the small font color, default
loc_639C5:								; palette doe not fit here, so they
		STA		_PPU_DATA				; put another one with one color
		DEY								; and has to refill attrs with another
		BNE		loc_639C5				; palette
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		_game._scr_idx
		CMP		#$80
		BNE		loc_639E2
		JMP		_the_end_scroller
loc_639E2:
		LDY		#$00
loc_639E4:
		LDA		_pal_title_scroll,Y
		STA		_PPU_DATA
		INY
		CPY		#$20
		BNE		loc_639E4
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		JSR		_render_on
		LDA		#$20
		STA		_tmp00
		LDA		#$03
		STA		_tmp01
		LDY		#$00
		LDX		#$00
		LDA		#>[_tlm_scroller_heli_with_bio-1]
		STA		_tmp05
		LDA		#<[_tlm_scroller_heli_with_bio-1]
		STA		_tmp04
		LDA		#$C8
		STA		_tmp0A
loc_63A1A:
		TXA
		PHA
		TYA
		PHA
		TXA
		AND		#$03
		BNE		loc_63A26
		JSR		_scroller_spr_title_insert
loc_63A26:
		PLA
		TAY
		PLA
		TAX
		JSR		_render_off
		JSR		_scroller_heli_bladeB_draw
		JSR		_render_off
		INX
		TXA
		CMP		#$E0
		BEQ		loc_63A49
		AND		#$07
		BEQ		loc_63A43
		JSR		_scroller_heli_bladeA_draw
		JMP		loc_63A1A
loc_63A43:
		JSR		_scroller_draw_line
		JMP		loc_63A1A
loc_63A49:
		JSR		_render_on
		STX		_tmp14
		JMP		loc_63A5D
loc_63A51:
		JSR		_render_off
		JSR		_scroller_heli_bladeB_draw
		JSR		_render_off
		JSR		_scroller_heli_bladeA_draw
loc_63A5D:
		TXA
		PHA
		TYA
		PHA
		INC		_tmp14
		LDA		_tmp14
		AND		#$03
		BNE		loc_63A6C
		JSR		_scroller_spr_title_insert
loc_63A6C:
		JSR		_read_pad_safeB
		PLA
		TAY
		PLA
		TAX
		LDA		_pad
		BEQ		loc_63A51
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_scroller_heli_bladeB_draw:
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$03
		STA		_PPU_ADDR
		LDY		#$00
loc_63A8C:
		LDA		_tlm_scroller_heli_with_bio,Y
		INY
		CMP		#$FF
		BEQ		loc_63A9A
		STA		_PPU_DATA
		BNE		loc_63A8C
loc_63A9A:
		LDY		#$00
		JSR		_render_on
		RTS

; =============== S U B	R O U T	I N E =======================================
_scroller_heli_bladeA_draw:
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$03
		STA		_PPU_ADDR
		LDY		#$00
loc_63AAF:
		LDA		_tlm_scroller_heli_bladeA,Y
		INY
		CMP		#$FF
		BEQ		loc_63ABD
		STA		_PPU_DATA
		BNE		loc_63AAF
loc_63ABD:
		LDY		#$00
		JSR		_render_on
		RTS

; =============== S U B	R O U T	I N E =======================================
_scroller_draw_line:
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
loc_63AD0:
		INC		_tmp04
		BNE		loc_63AD6
		INC		_tmp05
loc_63AD6:
		LDA		(_tmp04),Y
		CMP		#$FF
		BEQ		loc_63AE2
		STA		_PPU_DATA
		BNE		loc_63AD0
loc_63AE2:
		JSR		_render_on
		LDA		_tmp01
		CLC
		ADC		#$20
		STA		_tmp01
		BCC		loc_63AE3
		INC		_tmp00
loc_63AE3:
		RTS

; =============== S U B	R O U T	I N E =======================================
_the_end_scroller:
		LDY		#$00
loc_63AF5:
		LDA		_pal_title_scroll,Y
		STA		_PPU_DATA
		INY
		CPY		#$10
		BNE		loc_63AF5
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		JSR		_render_on
		LDA		#$20
		STA		_tmp00
		LDA		#$02
		STA		_tmp01
		LDY		#$00
		LDX		#$00
		LDA		#$00
		STA		_tmp02
		LDA		#>[_res_the_end-1]
		STA		_tmp05
		LDA		#<[_res_the_end-1]
		STA		_tmp04
loc_63B2B:
		LDA		_tmp00
		CMP		#$23
		BNE		loc_63B3F
		LDA		_tmp01
		CMP		#$C0
		BCC		loc_63B3F
		LDA		#$20
		STA		_tmp00
		LDA		#$02
		STA		_tmp01
loc_63B3F:
		JSR		_render_toggle
		JSR		_render_toggle
		JSR		_render_off
		INX
		TXA
		CMP		#$F0
		BNE		loc_B7B4F
		INC		_tmp02
		LDX		#$00
		TXA
loc_B7B4F:
		CMP		#$60
		BNE		loc_B7B59
		LDA		_tmp02
		CMP		#$02
		BEQ		loc_B7B73
loc_B7B59:
		AND		#$07
		BEQ		loc_B7B67
		AND		#$03
		BEQ		loc_B7B6D
		JSR		_render_on
		JMP		loc_63B2B
loc_B7B67:
		JSR		_scroller_draw_line
		JMP		loc_63B2B
loc_B7B6D:
		JSR		_scroller_draw_empty_line
		JMP		loc_63B2B
loc_B7B73:
		JSR		_render_on
loc_B7B76:
		JSR		_render_toggle
		TXA
		PHA
		JSR		_read_pad_safeB
		PLA
		TAX
		LDA		_pad
		BEQ		loc_B7B76
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_render_toggle:
		JSR		_render_off
		JMP		_render_on

; =============== S U B	R O U T	I N E =======================================
_scroller_draw_empty_line:
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
		LDY		#$1D
		LDA		#$F1
loc_B7B9E:
		STA		_PPU_DATA
		DEY
		BNE		loc_B7B9E
		LDY		#$00
		JSR		_render_on
		RTS

; =============== S U B	R O U T	I N E =======================================
_scroller_spr_title_insert:
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
		LDA		_tmp0A
		TAY
		LDA		_portraits_lib,Y
		INY
		STA		_tmp04
		JSR		_spr_sheet_title_insert
		CPY		#$DD
		BNE		loc_63BA2
		LDY		#$C8
loc_63BA2:
		TYA
		STA		_tmp0A
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
		RTS

; =============== S U B	R O U T	I N E =======================================
_render_off:
		LDA		#$00
		STA		_nmi_flag
loc_63C46:
		LDA		_nmi_flag
		BEQ		loc_63C46
		LDA		#$10
		STA		_PPU_CTRL
		LDA		#$00
		STA		_PPU_MASK
		RTS

; =============== S U B	R O U T	I N E =======================================
_render_on:
		LDA		_PPU_STATUS
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_SCROLL
		STX		_PPU_SCROLL
		LDA		#$1E
		STA		_PPU_MASK
		LDA		#$90
		STA		_PPU_CTRL
		RTS
; ---------------------------------------------------------------------------
_tlm_scroller_heli_bladeA:
		.BYTE $00,$00,$00,$00,$00,$00,$00,$01,$02,$03,$04,$05,$06,$07,$08,$09,$0A,$0B,$0C,$0D,$FF
_tlm_scroller_heli_with_bio:
		.BYTE $00,$00,$00,$00,$00,$00,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19,$1A,$1B,$1C,$1D,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$20,$21,$22,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$23,$24,$25,$26,$27,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$28,$29,$2A,$2B,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$2C,$2D,$2E,$2F,$30,$31,$32,$33,$34,$35,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$36,$37,$38,$39,$3A,$3B,$3C,$3D,$3E,$3F,$40,$41,$42,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$43,$44,$45,$46,$47,$48,$49,$4A,$4B,$4C,$4D,$4E,$1E,$1F,$FF
		.BYTE $FF
		.BYTE $FF
		.BYTE $FF
		.BYTE $FF
		.BYTE $FF
		.BYTE _N,_A,_M,_E,_ddt,__,__,__,__,_J,_o,_h,_n,__,_R,_a,_m,_b,_o,_eol
		.BYTE _A,_G,_E,_ddt,__,__,__,__,__,_B,_o,_r,_n,__,_1,_9,_4,_7,_eol
		.BYTE _R,_A,_C,_E,_ddt,__,__,__,__,_I,_n,_d,_i,_a,_n,__,_a,_n,_d,__,_G,_e,_r,_m,_a,_n,_eol
		.BYTE _C,_I,_T,_I,_Z,_E,_N,_ddt,__,_U,_dot,_S,_dot,_eol
		.BYTE _S,_T,_A,_T,_U,_S,_ddt,__,__,_S,_i,_n,_g,_l,_e,_eol
		.BYTE _M,_I,_L,_I,_T,_A,_R,_Y,__,_S,_E,_R,_V,_I,_C,_E,_ddt,_eol
		.BYTE __,_J,_o,_i,_n,_e,_d,__,_s,_p,_e,_c,_i,_a,_l,__,_f,_o,_r,_c,_e,_s,__,_1,_9,_6,_4,_dot,_eol
		.BYTE __,_E,_x,_p,_e,_r,_t,__,_i,_n,__,_l,_i,_g,_h,_t,__,_w,_e,_a,_p,_o,_n,_s,_eol
		.BYTE __,_a,_n,_d,__,_h,_a,_n,_d,_dsh,_t,_o,_dsh,_h,_a,_n,_d,__,_c,_o,_m,_b,_a,_t,_dot,_eol
		.BYTE __,_Q,_u,_a,_l,_i,_f,_i,_e,_d,__,_m,_e,_d,_i,_c,_dot,__,_P,_O,_W,__,_f,_o,_r,_eol
		.BYTE __,_3,__,_m,_o,_n,_t,_h,_s,_col,__,_e,_s,_c,_a,_p,_e,_d,_dot,__,_L,_i,_c,_e,_n,_s,_e,_d,_eol
		.BYTE __,_p,_i,_l,_o,_t,_dot,__,_5,_9,__,_c,_o,_m,_b,_a,_t,__,_m,_i,_s,_s,_i,_o,_n,_s,_dot,_eol
		.BYTE __,_N,_u,_m,_e,_r,_o,_u,_s,__,_s,_e,_r,_v,_i,_c,_e,__,_a,_w,_a,_r,_d,_s,_dot,_eol
		.BYTE _eol
		.BYTE _eol
_res_the_end:
		.BYTE _W,_H,_A,_T,__,_I,_S,__,_R,_E,_A,_L,__,_L,_I,_B,_E,_R,_T,_Y,_ex,_eol
		.BYTE _P,_L,_E,_A,_S,_E,__,_T,_H,_I,_N,_K,__,_A,_B,_O,_U,_T,__,_I,_T,_dot,_eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE __,__,__,__,__,__,__,_S,__,_T,__,_A,__,_F,__,_F
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE __,__,__,_P,_R,_O,_D,_U,_C,_E,_R,__,_O,_K,_U,_C,_H,_A,_N,_eol
		.BYTE _eol
		.BYTE __,__,__,_D,_I,_R,_E,_C,_T,_O,_R,__,_I,_T,_O,_M,_A,_K,_I,_M,_A,_K,_I,_eol
		.BYTE __,__,__,__,__,__,__,__,__,__,__,__,_Y,_A,_M,_A,_C,_H,_A,_N,_eol
		.BYTE __,__,__,_S,_C,_E,_N,_A,_R,_I,_O,__,_M,_I,_S,_A,__,_N,_A,_R,_I,_T,_A,_eol
		.BYTE _eol
		.BYTE __,__,__,_D,_E,_S,_I,_G,_N,_E,_R,__,_F,_U,_K,_U,_C,_H,_A,_N,__,_T,_O,_K,_I,_T,_A,_eol
		.BYTE _eol
		.BYTE __,__,__,__,__,__,_M,_U,_S,_I,_C,__,_T,_O,_H,_R,_U,__,_H,_A,_S,_E,_B,_E,_eol
		.BYTE _eol
		.BYTE __,_P,_R,_O,_G,_R,_A,_M,_M,_E,_R,__,_A,_A,_Z,_eol
		.BYTE _eol
		.BYTE __,_P,_R,_O,_G,_R,_A,_M,_M,_E,_R,__,_P,_H,_I,_L,_I,_P,__,_M,_I,_Y,_A,_Z,_A,_W,_A,_eol
		.BYTE _eol
		.BYTE __,_P,_R,_O,_G,_R,_A,_M,_M,_E,_R,__,_N,_T,_T,__,_S,_H,_I,_R,_O,_T,_A,_eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE __,__,__,__,_S,_P,_E,_C,_I,_A,_L,__,_T,_H,_A,_N,_K,_S,_eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _S,_O,_U,_N,_D,_E,_F,_F,_E,_C,_T,__,_R,_U,_S,_H,_I,_R,_U,_S,_H,_I,_eol
		.BYTE __,__,__,__,__,__,__,__,__,__,__,__,_S,_H,_I,_M,_A,_Z,_A,_K,_I,_eol
		.BYTE __,__,__,_D,_E,_S,_I,_G,_N,_E,_R,__,_Y,_O,_S,_H,_I,__,_T,_O,_Y,_O,_K,_A,_W,_A,_eol
		.BYTE _eol
		.BYTE __,__,__,__,__,__,_M,_U,_S,_I,_C,__,_M,_I,_N,_K,_Y,__,_M,_O,_T,_O,_Y,_A,_M,_A,_eol
		.BYTE _eol
		.BYTE __,__,__,__,_A,_D,_V,_I,_S,_E,_R,__,_O,_Z,_eol
		.BYTE _eol
		.BYTE __,__,__,_P,_R,_O,_M,_O,_T,_E,_R,__,_N,_A,_N,_I,_W,_A,_N,_O,__,_S,_A,_S,_A,_K,_I,_eol
		.BYTE _eol
		.BYTE __,__,__,_P,_R,_O,_M,_O,_T,_E,_R,__,_T,_S,_U,_U,_eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE __,__,__,__,__,__,__,__,_T,_H,_E,__,_E,_N,_D,_eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
_pal_title_scroll:
		.BYTE $0F,$0F,$19,$19,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$06,$10,$19
		.BYTE $0F,$06,$16,$27,$0F,$16,$27,$37,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
