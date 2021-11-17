
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
		LDX		#$17
		LDA		#$00
loc_60184:
		STA		_apu,X
		DEX
		BPL		loc_60184
		LDX		_apu_cur_mus_idx
		LDA		_apu_mus_prg_list,X
		STA		_apu_cur_mus_prg
		TXA
		ASL
		ASL
		ASL
		CLC
		ADC		#<[_apu_mus_lib]
		STA		_tmp00
		LDA		#$00
		ADC		#>[_apu_mus_lib]
		STA		_tmp01
		LDY		#$07
loc_601A8:
		LDA		(_tmp00),Y
		STA		_apu_mus_ptrs,Y
		DEY
		BPL		loc_601A8
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
.apu_chnl_loop:
		LDX		_tmp00
		LDA		_apu_mul6_tbl,X
		TAX
		LDA		_apu._ch0._duty,X
		BEQ		loc_63516
		DEC		_apu._ch0._duty,X
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
		BEQ		.apu_next_chnl
		LDA		_apu._ch0.field_3,X
		CMP		#$00
		BNE		loc_63552
		LDY		_apu._ch0.field_4,X
		LDA		_apu_tbl3,Y
		STA		_tmp04
		BEQ		.apu_len_and_continue
		CMP		#$FF
		BNE		loc_63549
		INC		_apu._ch0.field_4,X
		INY
		LDA		_apu_tbl3,Y
		STA		_tmp04
		BEQ		.apu_len_and_continue
		BNE		loc_63549
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
		JMP		.apu_len_and_continue
loc_6356D:
		LDA		_tmp04
		BEQ		.apu_len_and_continue
loc_63549:
		INC		_apu._ch0.field_4,X
.apu_len_and_continue:
		JSR		_apu_len_calc
.apu_next_chnl:
		INC		_tmp00
		LDA		_tmp00
		CMP		#$04
		BNE		.apu_chnl_loop

; !FALLTHROUGH!

; =============== S U B	R O U T	I N E =======================================
_apu_se_play:
		LDA		_apu_se_pulse_cnt
		BEQ		loc_6378B
		DEC		_apu_se_pulse_cnt
		BNE		loc_6378B
		LDA		#$00
		STA		_APU_PULSE2_ENV
		STA		_APU_PULSE2_SWEEP
		STA		_APU_PULSE2_TIME
		STA		_APU_PULSE2_LEN
loc_6378B:
		LDY		_apu_se_pulse_idx
		BEQ		loc_637B7
		LDA		_apu_se_pulse_tbl-4,Y
		STA		_APU_PULSE2_ENV
		LDA		_apu_se_pulse_tbl-3,Y
		STA		_APU_PULSE2_SWEEP
		LDA		_apu_se_pulse_tbl-2,Y
		STA		_APU_PULSE2_TIME
		LDA		_apu_se_pulse_tbl-1,Y
		STA		_APU_PULSE2_LEN
		LSR
		STA		_apu_se_pulse_cnt
		LDA		#$00
		STA		_apu_se_pulse_idx
loc_637B7:
		LDY		_apu_se_noise_idx
		BEQ		loc_637E7
		LDA		_apu_se_noise_tbl-4,Y
		STA		_APU_NOISE_ENV
		LDA		_apu_se_noise_tbl-2,Y
		STA		_APU_NOISE_LOOP
		LDA		_apu_se_noise_tbl-1,Y
		STA		_APU_NOISE_LEN
		LDA		_apu_se_noise_tbl-3,Y
		STA		_apu_se_noise_cnt
		LDA		#$00
		STA		_apu_se_noise_idx
loc_637E7:
		LDA		_apu_se_noise_cnt
		BEQ		locret_637EF
		DEC		_apu_se_noise_cnt
locret_637EF:
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_mus_play:
		LDA		_cur_prg_bank
		STA		_tmp0B
		LDA		_apu_cur_mus_prg
		JSR		_mmc_prg_set
.apu_mus_play_loop:
		LDA		_apu._ch0._pos,X
		ASL
		STA		_tmp02
		LDA		_apu._ch0._pos+1,X
		ROL
		STA		_tmp05
		LDA		_tmp00
		CMP		#$03
		BEQ		loc_635BF
		LDA		_tmp02
		CLC
		ADC		_apu._ch0._pos,X
		STA		_tmp02
		LDA		_apu._ch0._pos+1,X
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
		INC		_apu._ch0._pos,X
		BNE		loc_635DB
		INC		_apu._ch0._pos+1,X
loc_635DB:
		LDY		#$00
		LDA		(_tmp08),Y
		CMP		#$FD
		BNE		loc_635EB
		LDA		#$0A
		JSR		_apu_cur_mus_load
		JMP		.apu_mus_play_exit
loc_635EB:
		CMP		#$FF					; only two tracks 0D and 0F are using
		BNE		loc_635F8				; this cmd and not so far from beginning
		LDA		_apu._ch0._pos,X		; so they don't need to store high nibble
		STA		_apu._ch0._loop,X		; of offset, but BEWARE if you need it!
		JMP		.apu_mus_play_loop
loc_635F8:
		CMP		#$FE
		BNE		loc_6360A
		LDA		_apu._ch0._loop,X
		STA		_apu._ch0._pos,X
		LDA		#$00
		STA		_apu._ch0._pos+1,X
		BEQ		.apu_mus_play_loop
loc_6360A:
		ASL
		STA		_tmp01
		LDY		_tmp00
		CPY		#$02
		BCS		loc_63622
		STA		_apu_tmp187,Y
loc_63622:
		LDY		#$01
		LDA		(_tmp08),Y
		STA		_apu._ch0._duty,X
		LDA		_tmp00
		CMP		#$03
		BEQ		loc_63671
		INY
		LDA		_apu._ch0.field_3,X
		PHA
		LDA		(_tmp08),Y
		STA		_apu._ch0.field_3,X
		PLA
		BNE		.apu_mus_play_exit
		LDA		#$00
		STA		_apu._ch0.field_4,X
		STA		_tmp06
		STA		_tmp07
		LDY		_tmp01
		BEQ		loc_63671
		LDA		_apu_len_tbl-$20,Y
		STA		_tmp06
		LDA		_apu_len_tbl-$1F,Y
		STA		_tmp07
loc_63671:
		JSR		_apu_chnl_play
.apu_mus_play_exit:
		LDA		_tmp0B
		JMP		_mmc_prg_set

; =============== S U B	R O U T	I N E =======================================
_apu_chnl_play:
		LDA		_tmp00
		ASL
		ASL
		TAY
		CPY		#$00
		BNE		loc_63698
loc_63697:
		LDA		#$F0
		STA		_APU_PULSE1_ENV,Y
		LDA		#$00
		STA		_APU_PULSE1_SWEEP,Y
loc_636970:
		LDA		_tmp06
		STA		_APU_PULSE1_TIME,Y
		LDA		_tmp07
		STA		_APU_PULSE1_LEN,Y
		RTS
loc_63698:
		CPY		#$04
		BNE		loc_636B8
		LDA		_apu_se_pulse_cnt
		BEQ		loc_63697
		RTS
loc_636B8:
		CPY		#$08
		BNE		loc_636DA
		LDA		_apu._ch0.field_3,X
		ASL
		ASL
		CLC
		ADC		_apu._ch0.field_3,X
		STA		_APU_TRI_COUNT
		JMP		loc_636970
loc_636DA:
		LDA		_apu_se_noise_cnt
		BNE		locret_63700
		LDA		_tmp01
		ASL
		TAY
		LDA		_apu_mus_noise_tbl,Y
		STA		_APU_NOISE_ENV
		LDA		_apu_mus_noise_tbl+2,Y
		STA		_APU_NOISE_LOOP
		LDA		_apu_mus_noise_tbl+3,Y
		STA		_APU_NOISE_LEN
locret_63700:
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_len_calc:
		LDA		#$F0
		ORA		_tmp04
		STA		_tmp04
		LDA		_tmp00
		CMP		#$02
		BCS		locret_6375D
		CMP		#$00
		BEQ		loc_63731
		LDY		_apu_se_pulse_cnt
		BNE		locret_6375D
loc_63731:
		TAY
		LDA		_apu_tmp187,Y			; two pulse channels len backup
		BEQ		locret_6375D			; if stop command, no load
		TAY
		LDA		_apu_len_tbl-$20,Y
		STA		_tmp06
		JSR		_apu_decay_calc
		LDA		_tmp00
		ASL
		ASL
		TAY
		LDA		_tmp06
		STA		_APU_PULSE1_TIME,Y
		LDA		_tmp04
		STA		_APU_PULSE1_ENV,Y
locret_6375D:
		RTS

; =============== S U B	R O U T	I N E =======================================
_apu_decay_calc:
		LDA		_apu_counter
		BEQ		locret_63772
		CMP		#$04
		BCS		loc_6376C
		DEC		_tmp06
		RTS
loc_6376C:
		CMP		#$04
		BEQ		locret_63772
		INC		_tmp06
locret_63772:
		RTS
; ---------------------------------------------------------------------------
_apu_mul6_tbl:
		.BYTE 0*6,1*6,2*6,3*6
_apu_mus_prg_list:
		.BYTE $01,$00,$01,$00,$01,$00,$00,$00,$00,$01,$00,$00,$00,$00,$01,$00
_apu_mus_lib:
		APU_IDX _apu_mus0E	; 00	unused
		APU_IDX _apu_mus0A	; 01	unused
		APU_IDX _apu_mus02	; 02
		APU_IDX _apu_mus03	; 03
		APU_IDX _apu_mus04	; 04
		APU_IDX _apu_mus0A	; 05	unused
		APU_IDX _apu_mus0A	; 06	unused
		APU_IDX _apu_mus0A	; 07	unused
		APU_IDX _apu_mus0A	; 08	unused
		APU_IDX _apu_mus09	; 09
		APU_IDX _apu_mus0A	; 0A	dummy
		APU_IDX _apu_mus0B	; 0B
		APU_IDX _apu_mus0A	; 0C	dummy
		APU_IDX _apu_mus0D	; 0D
		APU_IDX _apu_mus0E	; 0E
		APU_IDX _apu_mus0F	; 0F
_apu_tbl3:
		.BYTE $09,$0A,$0B,$FF,$01,$01,$01,$04,$04,$04,$04,$04,$04,$04,$04,$03
		.BYTE $03,$03,$03,$03,$03,$03,$03,$02,$02,$02,$02,$02,$02,$02,$02,$01
		.BYTE $01,$01,$01,$01,$01,$01,$01,$00
_apu_len_tbl:
;		.WORD $06AF,$064E,$05F4,$059E,$054E,$0501,$04BA,$0476 ; *00-07	unused
;		.WORD $0436,$03F9,$03C0,$038A,$0357,$0327,$02FA,$02CF ; *08-0F	unused
		.WORD $02A7,$0281,$025D,$023B,$021B,$01FD,$01E0,$01C5 ; *10-17
		.WORD $01AC,$0194,$017D,$0168,$0153,$0140,$012E,$011D ; *18-1F
		.WORD $010D,$00FE,$00F0,$00E3,$00D6,$00CA,$00BE,$00B4 ; *20-27
		.WORD $00AA,$00A0,$0097,$008F,$0087,$007F,$0078,$0071 ; *28-2F
		.WORD $006B,$0065,$005F,$005A,$0055,$0050,$004C,$0047 ; *30-37
;		.WORD $0043,$0040,$003C,$0039,$0035,$0032,$0030,$002D ; *38-3F	unused
;		.WORD $002A,$0028,$0026,$0024,$0022,$0020,$001E,$001C ; *40-47	unused
_apu_mus_noise_tbl:
		.BYTE $00,$00,$00,$00
		.BYTE $01,$00,$03,$01
		.BYTE $01,$00,$03,$01
		.BYTE $02,$00,$08,$08
		.BYTE $03,$00,$03,$01
		.BYTE $01,$00,$03,$01
		.BYTE $01,$00,$03,$01
		.BYTE $01,$00,$03,$01
		.BYTE $01,$00,$03,$01
_apu_se_pulse_tbl:
		.BYTE $7F,$AA,$FF,$98	; SEP01
		.BYTE $86,$00,$B0,$F8	; SEP02
		.BYTE $BF,$BB,$F6,$A0	; SEP03
		.BYTE $BF,$9B,$F6,$60	; SEP04
		.BYTE $7F,$83,$32,$00	; SEP05 unused
_apu_se_noise_tbl:
		.BYTE $0D,$1E,$0C,$00	; SEN01
		.BYTE $0F,$1E,$07,$00	; SEN02
		.BYTE $03,$1E,$6B,$F0	; SEN03
		.BYTE $20,$1E,$0B,$F8	; SEN04
		.BYTE $23,$18,$07,$F8	; SEN05
		.BYTE $22,$12,$0C,$F8	; SEN06
		.BYTE $2F,$3C,$0C,$F8	; SEN07
