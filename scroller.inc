
; =============== S U B	R O U T	I N E =======================================
_scroller_screen:
		TYA
		PHA
		TXA
		PHA
		JSR		_render_off_ex
		PPU_FILL_RECT	$2000, $FE, $1E, $20
#if LANGUAGE == LANG_US
; since in us version they changed the small font color, default
; palette does not fit here, so they put another one with one color
; and has to refill attrs with another palette
		PPU_FILL_LINEY	$23C0, $FF, $10
		PPU_FILL_LINEY	    0, $00, $30
#endif
#if LANGUAGE == LANG_JP
		PPU_FILL_LINEY	$23C0, $FF, $40
#endif
		LDA		_game._scr_idx
		CMP		#$80
		BNE		_the_bio_scroller
		JMP		_the_end_scroller

; =============== S U B	R O U T	I N E =======================================
_the_bio_scroller:
		LDY		#$20
		JSR		_scroll_palette_load
		LDA		#$20
		STA		_tmp00
#if LANGUAGE == LANG_US
		LDA		#$03
#endif
#if LANGUAGE == LANG_JP
		LDA		#$06
#endif
		STA		_tmp01
		LDY		#$00
		LDX		#$00
		LDA		#>[_tlm_scroller_heli_with_bio-1]
		STA		_tmp05
		LDA		#<[_tlm_scroller_heli_with_bio-1]
		STA		_tmp04
		LDA		#$C8
		STA		_tmp0A
.scroller_anim_loop:
		TYA
		PHA
		TXA
		PHA
		AND		#$03
		BNE		loc_63A26
		JSR		_scroller_spr_title_insert
loc_63A26:
		PLA
		TAX
		PLA
		TAY
		JSR		_render_off
		LDY		#[_tlm_scroller_heli_with_bio-_tlm_scroller_heli_blades]
		JSR		_scroller_heli_blades_draw
		JSR		_render_off
		INX
		TXA
		CMP		#$E0
		BEQ		loc_63A49
		AND		#$07
		BEQ		loc_63A43
		LDY		#$00
		JSR		_scroller_heli_blades_draw
		JMP		.scroller_anim_loop
loc_63A43:
		JSR		_scroller_draw_line
		JMP		.scroller_anim_loop
loc_63A49:
		JSR		_scroll_reload_render_on
		STX		_tmp14
		JMP		loc_63A5D
.scroller_static_loop:
		JSR		_render_off
		LDY		#[_tlm_scroller_heli_with_bio-_tlm_scroller_heli_blades]
		JSR		_scroller_heli_blades_draw
		JSR		_render_off
		LDY		#$00
		JSR		_scroller_heli_blades_draw
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
		BEQ		.scroller_static_loop
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_scroller_heli_blades_draw:
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
#if LANGUAGE == LANG_US
		LDA		#$03
#endif
#if LANGUAGE == LANG_JP
		LDA		#$06
#endif
		STA		_PPU_ADDR
loc_63AAF:
		LDA		_tlm_scroller_heli_blades,Y
		INY
		CMP		#$FF
		BEQ		loc_63ABD
		STA		_PPU_DATA
		BNE		loc_63AAF
loc_63ABD:
		LDY		#$00
		JMP		_scroll_reload_render_on

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
		JSR		_scroll_reload_render_on
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
		LDY		#$10
		JSR		_scroll_palette_load
		LDA		#$20
		STA		_tmp00
		LDA		#$02
		STA		_tmp01
		LDA		#$00
		TAX
		TAY
		STA		_tmp02
		LDA		#>[_res_the_end-1]
		STA		_tmp05
		LDA		#<[_res_the_end-1]
		STA		_tmp04
.end_scroll_loop:
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
		JSR		_scroll_reload_render_on
		JMP		.end_scroll_loop
loc_B7B67:
		JSR		_scroller_draw_line
		JMP		.end_scroll_loop
loc_B7B6D:
		JSR		_scroller_draw_empty_line
		JMP		.end_scroll_loop
loc_B7B73:
		JSR		_scroll_reload_render_on
.end_static_loop:
		JSR		_render_toggle
		TXA
		PHA
		JSR		_read_pad_safeB
		PLA
		TAX
		LDA		_pad
		BEQ		.end_static_loop
		PLA
		TAX
		PLA
		TAY
		RTS

; =============== S U B	R O U T	I N E =======================================
_render_toggle:
		JSR		_render_off
		JMP		_scroll_reload_render_on

; =============== S U B	R O U T	I N E =======================================
_scroller_draw_empty_line:
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
#if LANGUAGE == LANG_US
		LDY		#$1D
#endif
#if LANGUAGE == LANG_JP
		LDY		#$1B
#endif
		LDA		#$F1
loc_B7B9E:
		STA		_PPU_DATA
		DEY
		BNE		loc_B7B9E
		LDY		#$00
		JMP		_scroll_reload_render_on

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
_scroll_palette_load:
		LDA		_tmp00
		PHA
		STY		_tmp00
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		TAY
loc_63AF5:
		LDA		_pal_title_scroll,Y
		STA		_PPU_DATA
		INY
		DEC		_tmp00
		BNE		loc_63AF5
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		PLA
		STA		_tmp00
		JMP		_scroll_reload_render_on

; =============== S U B	R O U T	I N E =======================================
_scroll_reload_render_on:
		JSR		_render_on_ex
		LDA		_PPU_STATUS
		LDA		#$00
		STA		_PPU_SCROLL
		STX		_PPU_SCROLL
		RTS
#if LANGUAGE == LANG_US
; ---------------------------------------------------------------------------
_tlm_scroller_heli_blades:
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
; ---------------------------------------------------------------------------
_pal_title_scroll:
		.BYTE $0F,$0F,$19,$19,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$06,$10,$19
		.BYTE $0F,$06,$16,$27,$0F,$16,$27,$37,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
#endif
#if LANGUAGE == LANG_JP
; ---------------------------------------------------------------------------
_tlm_scroller_heli_blades:
		.BYTE $00,$00,$00,$00,$01,$02,$03,$04,$05,$06,$07,$08,$09,$0A,$0B,$0C,$0D,$FF
_tlm_scroller_heli_with_bio:
		.BYTE $00,$00,$00,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19,$1A,$1B,$1C,$1D,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$20,$21,$22,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$23,$24,$25,$26,$27,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$28,$29,$2A,$2B,$FF
		.BYTE $00,$00,$00,$00,$00,$2C,$2D,$2E,$2F,$30,$31,$32,$33,$34,$35,$FF
		.BYTE $00,$00,$00,$00,$36,$37,$38,$39,$3A,$3B,$3C,$3D,$3E,$3F,$40,$41,$42,$FF
		.BYTE $00,$00,$00,$43,$44,$45,$46,$47,$48,$49,$4A,$4B,$4C,$4D,$4E,$1E,$1F,$FF
		.BYTE $FF
		.BYTE $FF
		.BYTE $FF
		.BYTE $FF
		.BYTE $FF
		.BYTE $A9,$A2,$CA,$A7,$AC,$D6,_eol
		.BYTE $F5,__,__,__,__,__,$F5,_eol
		.BYTE $AC,$D6,$CD,$EE,$C7,$CD,$BE,$E7,__,$D9,$E1,$DC,$DF,$B8,$CD,$6C,$88,$93,_eol
		.BYTE __,__,$F5,__,__,__,__,$F5,_eol
		.BYTE $A2,$CD,$B3,$D0,$A1,$CD,$7D,$B4,$A2,$B2,$82,__,$73,$96,$72,$7B,_eol
		.BYTE __,__,__,__,__,__,__,__,__,__,__,$F5,_eol
		.BYTE $D9,$E1,$DE,$DC,$B8,$CD,__,$B4,$A8,$AC,$D5,$BC,$B0,$A2,$7F,$B6,$D5,$A3,$B0,$A2,_eol
		.BYTE __,__,$F5,__,__,__,$F5,_eol
		.BYTE $A9,$A2,$BC,$A7,$82,__,$AC,$D5,$A8,$CA,$CD,$BD,$A2,_eol
		.BYTE __,__,__,__,__,__,$F5,__,__,__,__,__,__,$F5,_eol
		.BYTE $A2,$C8,$D6,$A3,$6E,$8F,$84,__,$BD,$C8,$82,$78,$6C,$75,$9E,$6C,$AC,$A6,$A8,$6A,$91,_eol
		.BYTE __,__,__,__,__,__,__,__,__,__,__,__,__,__,$F5,_eol
		.BYTE $DD,$E1,$C2,$A2,$82,$B3,$A7,$BD,$A2,$97,$79,$6E,$75,__,$AC,$D6,$A8,$CD,$79,$76,$6C,_eol
		.BYTE _eol
		.BYTE _eol
_res_the_end:
		.BYTE __,_W,_H,_A,_T,__,_I,_S,__,_R,_E,_A,_L,__,_L,_I,_B,_E,_R,_T,_Y,__,_ex,_eol
		.BYTE __,_P,_L,_E,_A,_S,_E,__,_T,_H,_I,_N,_K,__,_A,_B,_O,_U,_T,__,_I,_T,_dot,_eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE __,__,__,__,__,__,__,_S,__,_T,__,_A,__,_F,__,_F
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE __,__,__,_P,_R,_O,_D,_U,_C,_E,_R,__,$A5,$A8,$7A,$9D,$96,_eol
		.BYTE _eol
		.BYTE __,__,__,_D,_I,_R,_E,_C,_T,_E,_R,__,$6B,$E7,$7D,$9C,$88,$70,$88,$70,__,$8D,$88,$7A,$9D,$96,_eol
		.BYTE _eol
		.BYTE __,__,__,_S,_C,_E,_N,_A,_R,_I,_O,__,$89,$74,__,$7E,$91,$79,_eol
		.BYTE _eol
		.BYTE __,__,__,_D,_E,_S,_I,_G,_N,_E,_R,__,$BC,$A8,$7A,$9D,$96,__,$7D,$70,$79,_eol
		.BYTE _eol
		.BYTE __,__,__,__,__,__,_M,_U,_S,_I,_C,__,$7D,$6E,$92,__,$83,$77,$86,_eol
		.BYTE _eol
		.BYTE __,_P,_R,_O,_G,_R,_A,_M,_M,_E,_R,__,_A,_A,_Z,_eol
		.BYTE _eol
		.BYTE __,_P,_R,_O,_G,_R,_A,_M,_M,_E,_R,__,$BC,$D0,$C8,$D7,$BC,__,$89,$8D,$74,$95,_eol
		.BYTE _eol
		.BYTE __,_P,_R,_O,_G,_R,_A,_M,_M,_E,_R,__,_N,_T,_T,__,$75,$94,$79,_eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE __,__,__,__,_S,_P,_E,_C,_I,_A,_L,__,_T,_H,_A,_N,_K,_S,_eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _eol
		.BYTE _S,_O,_U,_N,_D,_E,_F,_F,_E,_C,_T,__,$92,$75,$92,$75,__,$75,$88,$74,$70,_eol
		.BYTE _eol
		.BYTE __,__,__,_D,_E,_S,_I,_G,_N,_E,_R,__,$8F,$75,__,$7D,$8F,$6F,$95,_eol
		.BYTE _eol
		.BYTE __,__,__,__,__,__,_M,_U,_S,_I,_C,__,$89,$96,$70,__,$8C,$7D,$8D,$88,_eol
		.BYTE _eol
		.BYTE __,__,__,__,_A,_D,_V,_I,_S,_E,_R,__,_O,_Z,_eol
		.BYTE _eol
		.BYTE __,__,__,_P,_R,_O,_M,_O,_T,_E,_R,__,$7E,$7F,$95,$82,__,$74,$74,$70,_eol
		.BYTE _eol
		.BYTE __,__,__,_P,_R,_O,_M,_O,_T,_E,_R,__,$7B,$6C,_eol
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
		.BYTE __,__,__,__,__,__,__,__,__,_E,_N,_D,_eol
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
; ---------------------------------------------------------------------------
_pal_title_scroll:
		.BYTE $0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$06,$10,$19
		.BYTE $0F,$06,$16,$27,$0F,$16,$27,$37,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
#endif
