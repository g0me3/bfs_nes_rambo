
; =============== S U B	R O U T	I N E =======================================
_apu_cur_mus_load:
		STA		_apu_cur_mus_idx
		TXA
		PHA
		TYA
		PHA
		LDA		_tmp00
		PHA
		LDA		_tmp01
		PHA
		LDX		#$00
		LDA		#$00
loc_60184:
		STA		_apu,X
		INX
		CPX		#$18
		BNE		loc_60184
		LDX		_apu_cur_mus_idx
		LDA		_apu_mus_prg_list,X
		STA		_apu_cur_mus_prg
		LDA		_apu_cur_mus_idx
		ASL
		ASL
		ASL
		CLC
		ADC		#<[_apu_mus_lib]
		STA		_tmp00
		LDA		#$00
		ADC		#>[_apu_mus_lib]
		STA		_tmp01
		LDY		#$00
loc_601A8:
		LDA		(_tmp00),Y
		STA		_apu_mus_ptrs,Y
		INY
		CPY		#$08
		BNE		loc_601A8
		LDA		#$0F
		STA		_APU_STATUS
		PLA
		STA		_tmp01
		PLA
		STA		_tmp00
		PLA
		TAY
		PLA
		TAX
		RTS

; ---------------------------------------------------------------------------
_apu_mus_prg_list:
		.BYTE $01,$00,$01,$00,$01,$00,$00,$00,$00,$01,$00,$00,$00,$00,$01,$00
_apu_mus_lib:
		.WORD _apu_mus00A,_apu_mus00B,_apu_mus00C,_apu_mus00D
		.WORD _apu_mus01A,_apu_mus01B,_apu_mus01C,_apu_mus01D
		.WORD _apu_mus02A,_apu_mus02B,_apu_mus02C,_apu_mus02D
		.WORD _apu_mus03A,_apu_mus03B,_apu_mus03C,_apu_mus03D
		.WORD _apu_mus04A,_apu_mus04B,_apu_mus04C,_apu_mus04D
		.WORD _apu_mus01A,_apu_mus01B,_apu_mus01C,_apu_mus01D
		.WORD _apu_mus01A,_apu_mus01B,_apu_mus01C,_apu_mus01D
		.WORD _apu_mus01A,_apu_mus01B,_apu_mus01C,_apu_mus01D
		.WORD _apu_mus01A,_apu_mus01B,_apu_mus01C,_apu_mus01D
		.WORD _apu_mus09A,_apu_mus09B,_apu_mus09C,_apu_mus09D
		.WORD _apu_mus01A,_apu_mus01B,_apu_mus01C,_apu_mus01D
		.WORD _apu_mus0BA,_apu_mus0BB,_apu_mus0BC,_apu_mus0BD
		.WORD _apu_mus01A,_apu_mus01B,_apu_mus01C,_apu_mus01D
		.WORD _apu_mus0DA,_apu_mus0DB,_apu_mus0DC,_apu_mus0DD
		.WORD _apu_mus00A,_apu_mus00B,_apu_mus00C,_apu_mus00D
		.WORD _apu_mus0FA,_apu_mus0FB,_apu_mus0FC,_apu_mus0FD

; ---------------------------------------------------------------------------
_apu_tbl3:
		.BYTE $09,$0A,$0B,$FF,$01,$01,$01,$04,$04,$04,$04,$04,$04,$04,$04,$03
		.BYTE $03,$03,$03,$03,$03,$03,$03,$02,$02,$02,$02,$02,$02,$02,$02,$01
		.BYTE $01,$01,$01,$01,$01,$01,$01,$00
; =============== S U B	R O U T	I N E =======================================
_apu_play:
		INC		_apu_counter
		LDA		_apu_counter
		CMP		#$0A
		BCC		loc_634FE
		LDA		#$00
		STA		_apu_counter
loc_634FE:
		LDA		#$00
		STA		_tmp00
loc_63502:
		LDA		_tmp00
		ASL
		STA		_tmp02
		ASL
		CLC
		ADC		_tmp02
		TAX
		LDA		_apu._ch0.field_2,X
		BEQ		loc_63516
		DEC		_apu._ch0.field_2,X
		BNE		loc_63523
loc_63516:
		LDA		_nmi_disble_ppu_reset_req
		BPL		loc_63520
		LDA		#$00
		STA		_nmi_flag
loc_63520:
		JSR		_apu_mus_play
loc_63523:
		LDA		_tmp00
		CMP		#$03
		BEQ		loc_63581
		LDA		_apu._ch0.field_3,X
		CMP		#$00
		BNE		loc_63552
		LDY		_apu._ch0.field_4,X
		LDA		_apu_tbl3,Y
		STA		_tmp04
		BEQ		loc_6357A
		CMP		#$FF
		BNE		loc_63549
		INC		_apu._ch0.field_4,X
		INY
		LDA		_apu_tbl3,Y
		STA		_tmp04
		BEQ		loc_6357A
loc_63549:
		JSR		_apu_len_calc
		INC		_apu._ch0.field_4,X
		JMP		loc_63581
; ---------------------------------------------------------------------------
loc_63552:
		DEC		_apu._ch0.field_3,X
		LDY		_apu._ch0.field_4,X
		LDA		_apu_tbl3,Y
		STA		_tmp04
		CMP		#$FF
		BNE		loc_6356D
		DEY
		LDA		_apu_tbl3,Y
		STA		_tmp04
		JSR		_apu_len_calc
		JMP		loc_63581
; ---------------------------------------------------------------------------
loc_6356D:
		LDA		_tmp04
		BEQ		loc_6357A
		JSR		_apu_len_calc
		INC		_apu._ch0.field_4,X
		JMP		loc_63581
; ---------------------------------------------------------------------------
loc_6357A:
		LDA		#$00
		STA		_tmp04
		JSR		_apu_len_calc
loc_63581:
		INC		_tmp00
		LDA		_tmp00
		CMP		#$04
		BEQ		loc_6358C
		JMP		loc_63502
; ---------------------------------------------------------------------------
loc_6358C:
		JSR		_apu_se_play
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_mus_play:
		LDA		_cur_prg_bank
		STA		_tmp0B
		LDA		_apu_cur_mus_prg
		STA		_cur_prg_bank
		JSR		_mmc_prg
loc_6359E:
		LDA		_apu,X
		ASL
		STA		_tmp02
		LDA		_apu._ch0.field_1,X
		ROL
		STA		_tmp05
		LDA		_tmp00
		CMP		#$03
		BEQ		loc_635BF
		LDA		_tmp02
		CLC
		ADC		_apu,X
		STA		_tmp02
		LDA		_apu._ch0.field_1,X
		ADC		_tmp05
		STA		_tmp05
loc_635BF:
		LDA		_tmp00
		ASL
		TAY
		LDA		_apu_mus_ptrs,Y
		INY
		CLC
		ADC		_tmp02
		STA		_tmp08
		LDA		_apu_mus_ptrs,Y
		ADC		_tmp05
		STA		_tmp09
		INC		_apu,X
		BNE		loc_635DB
		INC		_apu._ch0.field_1,X
loc_635DB:
		LDY		#$00
		LDA		(_tmp08),Y
		CMP		#$FD
		BNE		loc_635EB
		LDA		#$0A
		JSR		_apu_cur_mus_load
		JMP		loc_63674
; ---------------------------------------------------------------------------
loc_635EB:
		CMP		#$FF
		BNE		loc_635F8
		LDA		_apu,X
		STA		_apu._ch0.field_5,X
		JMP		loc_6359E
; ---------------------------------------------------------------------------
loc_635F8:
		CMP		#$FE
		BNE		loc_6360A
		LDA		_apu._ch0.field_5,X
		STA		_apu,X
		LDA		#$00
		STA		_apu._ch0.field_1,X
		JMP		loc_6359E
; ---------------------------------------------------------------------------
loc_6360A:
		STA		_tmp01
		LDA		_tmp00
		BNE		loc_63618
		LDA		_tmp01
		STA		_apu_tmp187
		JMP		loc_63621
; ---------------------------------------------------------------------------
loc_63618:
		CMP		#$01
		BNE		loc_63621
		LDA		_tmp01
		STA		_apu_tmp188
loc_63621:
		INY
		LDA		(_tmp08),Y
		STA		_apu._ch0.field_2,X
		LDA		_tmp00
		CMP		#$03
		BEQ		loc_63671
		INY
		LDA		_apu._ch0.field_3,X
		PHA
		LDA		(_tmp08),Y
		STA		_apu._ch0.field_3,X
		PLA
		BNE		loc_63674
		LDA		#$00
		STA		_apu._ch0.field_4,X
		LDA		_tmp01
		BNE		loc_6364E
		LDA		#$00
		STA		_tmp06
		LDA		#$00
		STA		_tmp07
		JMP		loc_63671
; ---------------------------------------------------------------------------
loc_6364E:
		LDA		_tmp01
		SEC
		SBC		#$24
		STA		_tmp02
		LDA		_tmp00
		CMP		#$02
		BNE		loc_63662
		LDA		_tmp02
		CLC
		ADC		#$0C
		STA		_tmp02
loc_63662:
		LDA		_tmp02
		ASL
		TAY
		LDA		_apu_len_tbl,Y
		STA		_tmp06
		INY
		LDA		_apu_len_tbl,Y
		STA		_tmp07
loc_63671:
		JSR		_apu_chnl_play
loc_63674:
		LDA		_tmp0B
		STA		_cur_prg_bank
		JSR		_mmc_prg
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_chnl_play:
		LDA		_tmp00
		BNE		loc_63698
		LDA		#$F0
		STA		_APU_PULSE1_ENV
		LDA		#$00
		STA		_APU_PULSE1_SWEEP
		LDA		_tmp06
		STA		_APU_PULSE1_TIME
		LDA		_tmp07
		STA		_APU_PULSE1_LEN
		JMP		locret_63700
; ---------------------------------------------------------------------------
loc_63698:
		CMP		#$01
		BNE		loc_636B8
		LDA		_apu_se_cnt0
		BNE		locret_63700
		LDA		#$F0
		STA		_APU_PULSE2_ENV
		LDA		#$00
		STA		_APU_PULSE2_SWEEP
		LDA		_tmp06
		STA		_APU_PULSE2_TIME
		LDA		_tmp07
		STA		_APU_PULSE2_LEN
		JMP		locret_63700
; ---------------------------------------------------------------------------
loc_636B8:
		CMP		#$02
		BNE		loc_636DA
		LDA		_apu._ch0.field_3,X
		ASL
		ASL
		CLC
		ADC		_apu._ch0.field_3,X
		STA		_APU_TRI_COUNT
		LDA		#$00
		STA		_APU_TRI_UNUSED
		LDA		_tmp06
		STA		_APU_TRI_TIME
		LDA		_tmp07
		STA		_APU_TRI_LEN
		JMP		locret_63700
; ---------------------------------------------------------------------------
loc_636DA:
		CMP		#$03
		BNE		locret_63700
		LDA		_apu_se_cnt2
		BNE		locret_63700
		LDA		_tmp01
		ASL
		ASL
		TAY
		LDA		_apu_tbl0,Y
		STA		_APU_NOISE_ENV
		LDA		_apu_tbl0+1,Y
		STA		_APU_NOISE_UNUSED
		LDA		_apu_tbl0+2,Y
		STA		_APU_NOISE_LOOP
		LDA		_apu_tbl0+3,Y
		STA		_APU_NOISE_LEN
locret_63700:
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_len_calc:
		LDA		#$F0
		AND		#$F0
		ORA		_tmp04
		STA		_tmp04
		LDA		_tmp00
		BNE		loc_63732
		LDA		_apu_tmp187
		BEQ		locret_6375D
		SEC
		SBC		#$24
		ASL
		TAY
		LDA		_apu_len_tbl,Y
		STA		_tmp06
		INY
		LDA		_apu_len_tbl,Y
		STA		_tmp07
		JSR		_apu_decay_calc
		LDA		_tmp06
		STA		_APU_PULSE1_TIME
		LDA		_tmp04
		STA		_APU_PULSE1_ENV
		JMP		locret_6375D
; ---------------------------------------------------------------------------
loc_63732:
		CMP		#$01
		BNE		locret_6375D
		LDA		_apu_se_cnt0
		BNE		locret_6375D
		LDA		_apu_tmp188
		BEQ		locret_6375D
		SEC
		SBC		#$24
		ASL
		TAY
		LDA		_apu_len_tbl,Y
		STA		_tmp06
		INY
		LDA		_apu_len_tbl,Y
		STA		_tmp07
		JSR		_apu_decay_calc
		LDA		_tmp06
		STA		_APU_PULSE2_TIME
		LDA		_tmp04
		STA		_APU_PULSE2_ENV
locret_6375D:
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_decay_calc:
		LDA		_apu_counter
		BEQ		locret_63772
		CMP		#$04
		BCS		loc_6376C
		DEC		_tmp06
		JMP		locret_63772
; ---------------------------------------------------------------------------
loc_6376C:
		CMP		#$04
		BEQ		locret_63772
		INC		_tmp06
locret_63772:
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_se_play:
		LDA		_apu_se_cnt0
		BEQ		loc_6378B
		DEC		_apu_se_cnt0
		BNE		loc_6378B
		LDA		#$00
		STA		_APU_PULSE2_ENV
		STA		_APU_PULSE2_SWEEP
		STA		_APU_PULSE2_TIME
		STA		_APU_PULSE2_LEN
loc_6378B:
		LDA		_apu_se_idx
		BEQ		loc_637B7
		TAY
		DEY
		TYA
		ASL
		ASL
		TAY
		LDA		_apu_tbl1,Y
		STA		_APU_PULSE2_ENV
		LDA		_apu_tbl1+1,Y
		STA		_APU_PULSE2_SWEEP
		LDA		_apu_tbl1+2,Y
		STA		_APU_PULSE2_TIME
		LDA		_apu_tbl1+3,Y
		STA		_APU_PULSE2_LEN
		LSR
		STA		_apu_se_cnt0
		LDA		#$00
		STA		_apu_se_idx
loc_637B7:
		LDA		_apu_se_cnt1
		BEQ		loc_637E7
		LDA		_apu_se_cnt1
		TAY
		DEY
		TYA
		ASL
		ASL
		TAY
		LDA		_apu_tbl2,Y
		STA		_APU_NOISE_ENV
		LDA		#$00
		STA		_APU_NOISE_UNUSED
		LDA		_apu_tbl2+2,Y
		STA		_APU_NOISE_LOOP
		LDA		_apu_tbl2+3,Y
		STA		_APU_NOISE_LEN
		LDA		_apu_tbl2+1,Y
		STA		_apu_se_cnt2
		LDA		#$00
		STA		_apu_se_cnt1
loc_637E7:
		LDA		_apu_se_cnt2
		BEQ		locret_637EF
		DEC		_apu_se_cnt2
locret_637EF:
		RTS

; ---------------------------------------------------------------------------
_apu_len_tbl:
		.BYTE $AF,$06,$4E,$06,$F4,$05,$9E,$05,$4E,$05,$01,$05,$BA,$04,$76,$04
		.BYTE $36,$04,$F9,$03,$C0,$03,$8A,$03,$57,$03,$27,$03,$FA,$02,$CF,$02
		.BYTE $A7,$02,$81,$02,$5D,$02,$3B,$02,$1B,$02,$FD,$01,$E0,$01,$C5,$01
		.BYTE $AC,$01,$94,$01,$7D,$01,$68,$01,$53,$01,$40,$01,$2E,$01,$1D,$01
		.BYTE $0D,$01,$FE,$00,$F0,$00,$E3,$00,$D6,$00,$CA,$00,$BE,$00,$B4,$00
		.BYTE $AA,$00,$A0,$00,$97,$00,$8F,$00,$87,$00,$7F,$00,$78,$00,$71,$00
		.BYTE $6B,$00,$65,$00,$5F,$00,$5A,$00,$55,$00,$50,$00,$4C,$00,$47,$00
		.BYTE $43,$00,$40,$00,$3C,$00,$39,$00,$35,$00,$32,$00,$30,$00,$2D,$00
		.BYTE $2A,$00,$28,$00,$26,$00,$24,$00,$22,$00,$20,$00,$1E,$00,$1C,$00
_apu_tbl0:
		.BYTE $00,$00,$00,$00
		.BYTE $01,$00,$03,$01
		.BYTE $01,$00,$03,$01
		.BYTE $02,$00,$08,$08
		.BYTE $03,$00,$03,$01
		.BYTE $01,$00,$03,$01
		.BYTE $01,$00,$03,$01
		.BYTE $01,$00,$03,$01
		.BYTE $01,$00,$03,$01
_apu_tbl1:
		.BYTE $7F,$AA,$FF,$98
		.BYTE $86,$00,$B0,$F8
		.BYTE $BF,$BB,$F6,$A0
		.BYTE $BF,$9B,$F6,$60
		.BYTE $7F,$83,$32,$00
		.BYTE $00,$00,$00,$00
		.BYTE $00,$00,$00,$00
		.BYTE $00,$00,$00,$00
_apu_tbl2:
		.BYTE $0D,$1E,$0C,$00
		.BYTE $0F,$1E,$07,$00
		.BYTE $03,$1E,$6B,$F0
		.BYTE $20,$1E,$0B,$F8
		.BYTE $23,$18,$07,$F8
		.BYTE $22,$12,$0C,$F8
		.BYTE $2F,$3C,$0C,$F8
		.BYTE $00,$00,$00,$00
