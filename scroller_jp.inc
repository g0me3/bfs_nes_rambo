
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
loc_B799F:
		LDX		#$20
loc_B79A1:
		STA		_PPU_DATA
		DEX
		BNE		loc_B79A1
		DEY
		BNE		loc_B799F
		LDA		_PPU_STATUS
		LDA		#$23
		STA		_PPU_ADDR
		LDA		#$C0
		STA		_PPU_ADDR
		LDA		#$FF
		LDY		#$40
loc_B79BB:
		STA		_PPU_DATA
		DEY
		BNE		loc_B79BB
		LDA		_PPU_STATUS
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		LDA		_game._scr_idx
		CMP		#$80
		BNE		loc_B79D8
		JMP		_the_end_scroller
; ---------------------------------------------------------------------------
loc_B79D8:
		LDY		#$00
loc_B79DA:
		LDA		_pal_title_scroll,Y
		STA		_PPU_DATA
		INY
		CPY		#$20
		BNE		loc_B79DA
		LDA		#$3F
		STA		_PPU_ADDR
		LDA		#$00
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		STA		_PPU_ADDR
		JSR		_render_on
		LDA		#$20
		STA		_tmp00
		LDA		#$06
		STA		_tmp01
		LDY		#$00
		LDX		#$00
		LDA		#>[_tlm_scroller_heli_with_bio-1]
		STA		_tmp05
		LDA		#<[_tlm_scroller_heli_with_bio-1]
		STA		_tmp04
		LDA		#$00
		STA		_tmp0A
loc_B7A10:
		TXA
		PHA
		TYA
		PHA
		TXA
		AND		#$03
		BNE		loc_B7A1C
		JSR		_scroller_spr_title_insert
loc_B7A1C:
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
		BEQ		loc_B7A3F
		AND		#$07
		BEQ		loc_B7A39
		JSR		_scroller_heli_bladeA_draw
		JMP		loc_B7A10
; ---------------------------------------------------------------------------
loc_B7A39:
		JSR		_scroller_draw_line
		JMP		loc_B7A10
; ---------------------------------------------------------------------------
loc_B7A3F:
		JSR		_render_on
		STX		_tmp14
		JMP		loc_B7A53
; ---------------------------------------------------------------------------
loc_B7A47:
		JSR		_render_off
		JSR		_scroller_heli_bladeB_draw
		JSR		_render_off
		JSR		_scroller_heli_bladeA_draw
loc_B7A53:
		TXA
		PHA
		TYA
		PHA
		INC		_tmp14
		LDA		_tmp14
		AND		#$03
		BNE		loc_B7A62
		JSR		_scroller_spr_title_insert
loc_B7A62:
		JSR		_read_pad_safeB
		PLA
		TAY
		PLA
		TAX
		LDA		_pad
		BEQ		loc_B7A47
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
		LDA		#$06
		STA		_PPU_ADDR
		LDY		#$00
loc_B7A82:
		LDA		_tlm_scroller_heli_with_bio,Y
		INY
		CMP		#$FF
		BEQ		loc_B7A90
		STA		_PPU_DATA
		JMP		loc_B7A82
; ---------------------------------------------------------------------------
loc_B7A90:
		LDY		#$00
		JSR		_render_on
		RTS

; =============== S U B	R O U T	I N E =======================================
_scroller_heli_bladeA_draw:
		LDA		_PPU_STATUS
		LDA		#$20
		STA		_PPU_ADDR
		LDA		#$06
		STA		_PPU_ADDR
		LDY		#$00
loc_B7AA5:
		LDA		_tlm_scroller_heli_bladeA,Y
		INY
		CMP		#$FF
		BEQ		loc_B7AB3
		STA		_PPU_DATA
		JMP		loc_B7AA5
; ---------------------------------------------------------------------------
loc_B7AB3:
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
loc_B7AC6:
		INC		_tmp04
		BNE		loc_B7ACC
		INC		_tmp05
loc_B7ACC:
		LDA		(_tmp04),Y
		CMP		#$FF
		BEQ		loc_B7AD8
		STA		_PPU_DATA
		JMP		loc_B7AC6
; ---------------------------------------------------------------------------
loc_B7AD8:
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
loc_B7AEB:
		LDA		_pal_title_scroll,Y
		STA		_PPU_DATA
		INY
		CPY		#$10
		BNE		loc_B7AEB
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
loc_B7B21:
		LDA		_tmp00
		CMP		#$23
		BNE		loc_B7B35
		LDA		_tmp01
		CMP		#$C0
		BCC		loc_B7B35
		LDA		#$20
		STA		_tmp00
		LDA		#$02
		STA		_tmp01
loc_B7B35:
		JSR		_render_off
		JSR		_render_on
		JSR		_render_off
		JSR		_render_on
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
		JMP		loc_B7B21
; ---------------------------------------------------------------------------
loc_B7B67:
		JSR		_scroller_draw_line
		JMP		loc_B7B21
; ---------------------------------------------------------------------------
loc_B7B6D:
		JSR		_scroller_draw_empty_line
		JMP		loc_B7B21
; ---------------------------------------------------------------------------
loc_B7B73:
		JSR		_render_on
loc_B7B76:
		JSR		_render_off
		JSR		_render_on
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
_scroller_draw_empty_line:
		LDA		_PPU_STATUS
		LDA		_tmp00
		STA		_PPU_ADDR
		LDA		_tmp01
		STA		_PPU_ADDR
		LDY		#$1B
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
		LDA		_spr_title_anim_0,Y
		INY
		STA		_tmp04
		JSR		_scroller_spr_insert
		CPY		#$15
		BNE		loc_B7BCE
		LDY		#$00
loc_B7BCE:
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
		JSR		_scroller_spr_sheet_insert
		RTS

; =============== S U B	R O U T	I N E =======================================
_scroller_spr_sheet_insert:
		LDA		#$04
		STA		_tmp08
loc_B7BFE:
		LDA		_tmp02
		STA		_tmp06
		LDA		_tmp01
		STA		_tmp07
loc_B7C06:
		LDA		_tmp00
		STA		_spr_buf,X
		LDA		_tmp04
		INC		_tmp04
		STA		_spr_buf+1,X
		INC		_tmp08
		LDA		_tmp08
		CMP		#$05
		BNE		loc_B7C24
		LDA		_spr_title_anim_0,Y
		INY
		STA		_tmp05
		LDA		#$01
		STA		_tmp08
loc_B7C24:
		ASL
		STA		_tmp09
		LDA		_tmp05
		DEC		_tmp09
loc_B7C2B:
		DEC		_tmp09
		BEQ		loc_B7C33
		LSR
		JMP		loc_B7C2B
; ---------------------------------------------------------------------------
loc_B7C33:
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
		BNE		loc_B7C06
		LDA		_tmp00
		CLC
		ADC		#$08
		STA		_tmp00
		DEC		_tmp03
		BNE		loc_B7BFE
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
loc_B7C72:
		LDA		_nmi_flag
		BEQ		loc_B7C72
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
		.BYTE $00,$00,$00,$00,$01,$02,$03,$04,$05,$06,$07,$08,$09,$0A,$0B,$0C,$0D,$FF
_tlm_scroller_heli_with_bio:
		.BYTE $00,$00,$00,$10,$11,$12,$13,$14,$15,$16,$17,$18,$19,$1A,$1B,$1C,$1D,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$20,$21,$22,$00,$00,$00,$00,$00,$00,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$23,$24,$25,$26,$27,$00,$00,$00,$00,$FF
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$28,$29,$2A,$2B,$00,$00,$00,$00,$00,$FF
		.BYTE $00,$00,$00,$00,$00,$2C,$2D,$2E,$2F,$30,$31,$32,$33,$34,$35,$00,$00,$FF
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
;		.BYTE _eol
;		.BYTE _eol
;		.BYTE _eol
;		.BYTE _eol
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
;		.BYTE _eol
;		.BYTE _eol
;		.BYTE _eol
;		.BYTE _eol
;		.BYTE _eol
;		.BYTE _eol
;		.BYTE _eol
;		.BYTE _eol
_pal_title_scroll:
		.BYTE $0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$06,$10,$19
		.BYTE $0F,$06,$16,$27,$0F,$16,$27,$37,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F
