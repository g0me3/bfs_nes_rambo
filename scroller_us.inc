
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
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		#$FE
		LDY		#$1E
loc_6399F:
		LDX		#$20
loc_639A1:
		STA		_PPU_DATA
		DEX
		BNE		loc_639A1
		DEY
		BNE		loc_6399F
		LDA		_PPU_STATUS
		LDA		#$23
		STA		_PPU_ADDR
		LDA		#$C0
		STA		_PPU_ADDR
		LDA		#$FF
		LDY		#$10
loc_639BB:
		STA		_PPU_DATA
		DEY
		BNE		loc_639BB
		LDA		#$00
		LDY		#$30
loc_639C5:
		STA		_PPU_DATA
		DEY
		BNE		loc_639C5
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		_game._scr_idx
		CMP		#$80
		BNE		loc_639E2
		JMP		_the_end_scroller
; ---------------------------------------------------------------------------
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
		LDA		#$00
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
; ---------------------------------------------------------------------------
loc_63A43:
		JSR		_scroller_draw_line
		JMP		loc_63A1A
; ---------------------------------------------------------------------------
loc_63A49:
		JSR		_render_on
		STX		_tmp14
		JMP		loc_63A5D
; ---------------------------------------------------------------------------
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
		JMP		loc_63A8C
; ---------------------------------------------------------------------------
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
		JMP		loc_63AAF
; ---------------------------------------------------------------------------
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
		JMP		loc_63AD0
; ---------------------------------------------------------------------------
loc_63AE2:
		JSR		_render_on
		LDA		_tmp01
		CLC
		ADC		#$20
		STA		_tmp01
		LDA		_tmp00
		ADC		#$00
		STA		_tmp00
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
		JSR		_render_off
		JSR		_render_on
		JSR		_render_off
		JSR		_render_on
		JSR		_render_off
		INX
		TXA
		CMP		#$60
		BEQ		loc_63B64
		CMP		#$01
		BEQ		loc_63B5E
		JSR		_render_on
		JMP		loc_63B2B
; ---------------------------------------------------------------------------
loc_63B5E:
		JSR		_scroller_draw_line
		JMP		loc_63B2B
; ---------------------------------------------------------------------------
loc_63B64:
		JSR		_render_on
loc_63B67:
		JSR		_render_off
		JSR		_render_on
		TXA
		PHA
		JSR		_read_pad_safeB
		PLA
		TAX
		LDA		_pad
		BEQ		loc_63B67
		PLA
		TAX
		PLA
		TAY
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
		LDA		_spr_title_anim_0,Y
		INY
		STA		_tmp04
		JSR		_scroller_spr_insert
		CPY		#$15
		BNE		loc_63BA2
		LDY		#$00
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
_scroller_spr_insert:
		LDX		#$00
		LDA		#$08
		STA		_tmp02
		LDA		#$03
		STA		_tmp03
		LDA		#$50
		STA		_tmp00
		LDA		#$60
		STA		_tmp01
		JSR		_scroller_sp_sheet_insert
		RTS

; =============== S U B	R O U T	I N E =======================================
_scroller_sp_sheet_insert:
		LDA		#$04
		STA		_tmp08
loc_63BD2:
		LDA		_tmp02
		STA		_tmp06
		LDA		_tmp01
		STA		_tmp07
loc_63BDA:
		LDA		_tmp00
		STA		_spr_buf,X
		LDA		_tmp04
		INC		_tmp04
		STA		_spr_buf+1,X
		INC		_tmp08
		LDA		_tmp08
		CMP		#$05
		BNE		loc_63BF8
		LDA		_spr_title_anim_0,Y
		INY
		STA		_tmp05
		LDA		#$01
		STA		_tmp08
loc_63BF8:
		ASL
		STA		_tmp09
		LDA		_tmp05
		DEC		_tmp09
loc_63BFF:
		DEC		_tmp09
		BEQ		loc_63C07
		LSR
		JMP		loc_63BFF
; ---------------------------------------------------------------------------
loc_63C07:
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
		BNE		loc_63BDA
		LDA		_tmp00
		CLC
		ADC		#$08
		STA		_tmp00
		DEC		_tmp03
		BNE		loc_63BD2
		RTS

; ---------------------------------------------------------------------------
_spr_title_anim_0:
		.BYTE $00,$40,$00,$50,$00,$51,$41
		.BYTE $18,$10,$00,$54,$01,$54,$05
		.BYTE $30,$50,$05,$50,$45,$50,$45
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
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$20,$21,$22,$00,$00,$00,$00,$00,$00,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$23,$24,$25,$26,$27,$00,$00,$00,$00,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$28,$29,$2A,$2B,$00,$00,$00,$00,$00,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$2C,$2D,$2E,$2F,$30,$31,$32,$33,$34,$35,$00,$00,$FF
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
		.BYTE __,_eol
		.BYTE __,_eol
;		.BYTE __,_eol
;		.BYTE __,_eol
_res_the_end:
		.BYTE __,__,__,__,__,_T,_H,_E,__,_E,_N,_D,_eol
_pal_title_scroll:
		.BYTE $0F,$0F,$19,$19,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$06,$10,$19
		.BYTE $0F,$06,$16,$27,$0F,$16,$27,$37,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
