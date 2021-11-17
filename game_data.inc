
; bits4-7 - room music idx
; bit1 - special lamp lightning (==1)
; bit0 - sprite behind background (==1)
_location_room_settings:
		.BYTE $20,$20,$40,$40,$40,$40,$20,$40,$40,$40,$20,$40,$20,$21,$20,$40
		.BYTE $41,$41,$41,$41,$40,$40,$40,$40,$40,$40,$40,$41,$41,$41,$41,$41
		.BYTE $41,$40,$41,$41,$40,$40,$40,$40,$40,$40,$40,$40,$40,$40,$41,$40
		.BYTE $20,$40,$30,$40,$40,$40,$40,$40,$42,$40,$20,$42,$32,$42,$42,$41
		.BYTE $40,$40,$40,$32,$42,$42,$42,$40,$40,$40,$40,$30,$40,$40,$40,$40
		.BYTE $40,$40,$40,$40,$20,$30,$40,$40,$40,$40,$40,$40,$40,$40,$40,$40
		.BYTE $31,$20,$20,$41,$41,$41,$41,$41,$41,$40,$41,$41,$40,$20,$20,$20
		.BYTE $40,$40,$40,$40,$40,$41,$40,$20,$40,$30,$40,$40,$40,$40,$40,$40
; stage CHR tiles library offsets
; low 4-bit nibble is background CHR tiles list idx
; high 4-bit nibble is for sprites CHR tiles list idx
_location_chr_list:
		.BYTE $00,$01,$32,$32,$32,$32,$42,$32,$32,$32,$42,$02,$22,$43,$42,$80
		.BYTE $33,$33,$33,$43,$12,$32,$35,$35,$35,$35,$35,$33,$33,$33,$33,$43
		.BYTE $43,$42,$43,$43,$42,$52,$52,$52,$A2,$52,$52,$52,$52,$52,$53,$52
		.BYTE $02,$76,$76,$72,$42,$32,$35,$12,$12,$15,$22,$12,$12,$12,$12,$33
		.BYTE $35,$45,$45,$12,$12,$12,$12,$45,$75,$66,$60,$90,$67,$67,$67,$67
		.BYTE $67,$67,$67,$80,$00,$27,$87,$87,$87,$87,$87,$87,$87,$A2,$A2,$92
		.BYTE $43,$40,$01,$43,$53,$53,$43,$53,$53,$52,$53,$53,$52,$72,$72,$72
		.BYTE $A2,$A2,$A2,$92,$92,$93,$92,$02,$92,$A6,$92,$62,$14,$04,$04,$04
; dialog cutscene CHR tiles library offsets (4-bit nibbles)
; note, bg tiles idx is always $08 (fonts)
_cutscene_chr_list:
		.BYTE $BB,$CB,$CC,$CC,$DC,$DD,$DD,$DC,$ED,$EE,$EE,$FC,$EE,$EE,$FD,$DD
		.BYTE $DD,$CD,$DC,$CC,$CC,$CC,$DC,$DC,$CC,$ED,$CF
; high 4-bit nibble is night palette idx
; low 4-bit nibble is day palette idx
_location_bg_pal_settings:
		.BYTE $A0,$AD,$A2,$A2,$A2,$A2,$A2,$A2,$A2,$A2,$A2,$A2,$A2,$A4,$A2,$A8
		.BYTE $A4,$A4,$A4,$A4,$A2,$A2,$A5,$A5,$A5,$A5,$A5,$A4,$A4,$A4,$A4,$A4
		.BYTE $A4,$A2,$A4,$A4,$A2,$A2,$A2,$A2,$A2,$A2,$A2,$A2,$A2,$A2,$A4,$A2
		.BYTE $A2,$AC,$AC,$A2,$A2,$A2,$A5,$A2,$E3,$A5,$A2,$E3,$E3,$E3,$E3,$A4
		.BYTE $A6,$A6,$A6,$E3,$E3,$E3,$E3,$A6,$A6,$AC,$A8,$A8,$99,$99,$99,$99
		.BYTE $99,$99,$99,$A1,$A1,$BB,$BB,$BB,$BB,$BB,$BB,$BB,$BB,$A2,$A2,$A2
		.BYTE $A4,$A0,$AD,$A4,$A4,$A4,$A4,$A4,$A4,$A2,$A4,$A4,$A2,$A2,$A2,$A2
		.BYTE $A2,$A2,$A2,$A2,$A2,$A4,$A2,$A2,$A2,$AC,$A2,$A2,$77,$77,$77,$77
_location_spr_pal_settings:
		.BYTE $00,$00,$33,$33,$33,$33,$44,$33,$33,$33,$44,$00,$22,$44,$44,$88
		.BYTE $33,$33,$33,$44,$11,$33,$33,$33,$33,$33,$33,$33,$33,$33,$33,$44
		.BYTE $44,$44,$44,$44,$44,$55,$55,$55,$AA,$55,$55,$55,$33,$55,$33,$33
		.BYTE $00,$77,$77,$77,$44,$33,$33,$11,$B1,$11,$22,$B1,$B1,$B1,$B1,$33
		.BYTE $33,$44,$44,$B1,$B1,$B1,$B1,$44,$77,$77,$66,$66,$66,$66,$66,$66
		.BYTE $66,$66,$66,$88,$00,$22,$88,$88,$88,$88,$88,$88,$88,$AA,$AA,$99
		.BYTE $44,$44,$00,$44,$55,$55,$44,$55,$55,$33,$55,$55,$55,$77,$77,$77
		.BYTE $AA,$AA,$AA,$99,$99,$99,$99,$00,$99,$AA,$99,$99,$11,$00,$00,$00
; bit7 - E exit blocked
; bit6 - W exit blocked
; bits0-3 - room data idx
; 			<$20 - bank 0
; 			>$20 - bank 1
_location_room_idx_and_stop_flags:
		.BYTE $00,$01,$44,$85,$48,$04,$07,$49,$33,$85,$C4,$02,$06,$0E,$04,$27
		.BYTE $0F,$0B,$0F,$0C,$49,$88,$5E,$9F,$20,$21,$9E,$4F,$0B,$0C,$8A,$4C
		.BYTE $0D,$85,$4A,$13,$11,$09,$11,$10,$91,$52,$15,$12,$94,$54,$13,$15
		.BYTE $32,$34,$34,$05,$04,$05,$20,$B3,$1D,$1F,$06,$1B,$18,$19,$1A,$0F
		.BYTE $A4,$25,$A2,$1D,$1C,$1B,$19,$A4,$22,$34,$26,$27,$69,$A8,$6B,$29
		.BYTE $AA,$6A,$28,$36,$37,$6D,$2E,$30,$AE,$6C,$2F,$31,$B1,$94,$50,$11
		.BYTE $0E,$00,$01,$4F,$0B,$0C,$8A,$4C,$0D,$85,$4A,$13,$11,$52,$94,$50
		.BYTE $52,$94,$51,$12,$54,$13,$15,$32,$51,$34,$11,$95,$3C,$3C,$3C,$3C
; bit7 - location have a warp (==1)
; bit6 - this warp is S (==0) or N (==1)
; bits4-5 - warp room idx (0-3)
; bits0-3 - warp X macro idx in room
_location_warpsA_list:
		.BYTE $8D,$CD,$00,$AD,$8D,$00,$00,$CD,$00,$CD,$FD,$00,$00,$00,$DD,$3D
		.BYTE $00,$00,$AD,$00,$9D,$ED,$DD,$BD,$00,$00,$FD,$9D,$00,$DD,$ED,$CD
		.BYTE $ED,$9D,$8D,$9D,$00,$00,$BD,$00,$00,$8D,$9D,$00,$00,$CD,$DD,$CD
		.BYTE $00,$00,$00,$00,$00,$00,$BD,$00,$9D,$DD,$1D,$9D,$00,$DD,$00,$00
		.BYTE $00,$AD,$00,$ED,$00,$00,$00,$00,$00,$00,$00,$3D,$00,$3D,$00,$00
		.BYTE $00,$00,$3D,$2D,$00,$1D,$D7,$2D,$C7,$00,$8D,$00,$A7,$00,$8D,$00
		.BYTE $00,$8D,$CD,$9D,$00,$DD,$ED,$CD,$ED,$9D,$8D,$9D,$00,$1B,$FD,$00
		.BYTE $00,$FD,$9D,$00,$9D,$00,$DD,$FD,$DD,$00,$00,$CD,$00,$00,$00,$00
_location_warpsB_list:
		.BYTE $2D,$00,$00,$00,$ED,$00,$00,$00,$00,$BD,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$FD,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$FD,$AD,$00,$ED,$00,$FD,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$B7,$00,$9D,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$19,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_location_prizes_list:
		.BYTE $00
		.BYTE $00
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE $00
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE $00
		.BYTE $00
		.BYTE $00
		.BYTE $00
		.BYTE $00
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl11_hi_speed_idx
		.BYTE _objB_hndl0F_grenades_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl10_potions_idx
		.BYTE _objB_hndl0E_machinegun_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl12_hi_jump_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl11_hi_speed_idx
		.BYTE _objB_hndl10_potions_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0F_grenades_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl12_hi_jump_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0E_machinegun_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl10_potions_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0D_explo_arrow_ammo_idx
		.BYTE $00
		.BYTE _objB_hndl0D_explo_arrow_ammo_idx
		.BYTE _objB_hndl0A_heart_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0F_grenades_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0D_explo_arrow_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE $00
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl0A_heart_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE $00
		.BYTE _objB_hndl0D_explo_arrow_ammo_idx
		.BYTE _objB_hndl0A_heart_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0E_machinegun_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0F_grenades_ammo_idx
		.BYTE _objB_hndl0A_heart_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0F_grenades_ammo_idx
		.BYTE _objB_hndl0D_explo_arrow_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl10_potions_idx
		.BYTE _objB_hndl0E_machinegun_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0D_explo_arrow_ammo_idx
		.BYTE $00
		.BYTE _objB_hndl0A_heart_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0F_grenades_ammo_idx
		.BYTE _objB_hndl10_potions_idx
		.BYTE _objB_hndl0E_machinegun_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl10_potions_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl0A_heart_idx
		.BYTE $00
		.BYTE $00
		.BYTE _objB_hndl11_hi_speed_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl10_potions_idx
		.BYTE _objB_hndl12_hi_jump_idx
		.BYTE _objB_hndl0D_explo_arrow_ammo_idx
		.BYTE _objB_hndl0E_machinegun_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE $00
		.BYTE $00
		.BYTE $00
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0E_machinegun_ammo_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0C_arrow_ammo_idx
		.BYTE _objB_hndl0F_grenades_ammo_idx
		.BYTE _objB_hndl12_hi_jump_idx
		.BYTE _objB_hndl0E_machinegun_ammo_idx
		.BYTE $00
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0A_heart_idx
		.BYTE _objB_hndl0B_knife_ammo_idx
		.BYTE _objB_hndl0D_explo_arrow_ammo_idx
		.BYTE $00
		.BYTE $00
		.BYTE $00
		.BYTE $00
_chr_bg_table_lib:
		.BYTE $00,$01,$02,$03,$04,$05,$08,$10,$11,$17,$18,$19,$1A,$1B,$2C,$2D	; $00	; regular stage bg tiles
		.BYTE $00,$01,$02,$03,$04,$05,$0A,$10,$11,$12,$13,$14,$15,$16,$2C,$2D	; $01
		.BYTE $00,$01,$02,$03,$04,$05,$09,$0C,$0D,$1C,$1D,$1E,$1F,$20,$2E,$2F	; $02
		.BYTE $00,$01,$02,$03,$06,$07,$00,$0E,$0F,$1C,$1D,$1E,$1F,$20,$2E,$2F	; $03
		.BYTE $00,$01,$02,$03,$04,$05,$00,$00,$00,$26,$27,$28,$29,$2A,$00,$00	; $04
		.BYTE $00,$01,$02,$03,$04,$05,$00,$0E,$0F,$1C,$1D,$1E,$1F,$20,$2E,$2F	; $05
		.BYTE $00,$01,$02,$03,$04,$05,$0A,$10,$11,$1C,$1D,$1E,$1F,$20,$2E,$2F	; $06
		.BYTE $00,$01,$02,$03,$04,$05,$08,$10,$11,$21,$22,$23,$24,$25,$2C,$2D	; $07
		.BYTE $30,$31,$32,$33,$34,$35,$36,$37,$38,$39,$3A,$3B,$3C,$3D,$3E,$3F	; $08	all dialogs fonts bg chr
		.BYTE $00,$01,$02,$30,$31,$32,$33,$34,$00,$00,$00,$00,$00,$00,$00,$00	; $09	final boss bg chr
; <$40 in bank 3
; >=$40 in bank 4
_chr_spr_table_lib:
		.BYTE $18,$19,$1C,$00,$04,$05,$06,$0B,$4A,$4B,$4C,$4D,$4E,$4F,$55,$56	; $00	; regular stages spr tiles sets
		.BYTE $18,$19,$1C,$00,$09,$29,$1E,$1F,$0E,$11,$3E,$3F,$40,$41,$55,$56	; $01
		.BYTE $18,$19,$1C,$00,$09,$0A,$07,$08,$12,$13,$46,$47,$48,$49,$55,$56	; $02
		.BYTE $18,$19,$1C,$00,$14,$15,$16,$17,$0C,$0D,$00,$01,$02,$03,$55,$56	; $03
		.BYTE $18,$19,$1C,$00,$09,$0A,$04,$2A,$0F,$10,$28,$29,$2A,$2B,$55,$56	; $04
		.BYTE $18,$19,$1C,$00,$2C,$2D,$14,$15,$34,$35,$00,$01,$02,$03,$55,$56	; $05
		.BYTE $18,$19,$1C,$00,$38,$39,$36,$37,$12,$13,$20,$21,$23,$24,$55,$56	; $06
		.BYTE $18,$19,$1C,$00,$09,$0A,$3C,$3D,$42,$43,$20,$21,$26,$24,$55,$56	; $07
		.BYTE $18,$19,$1C,$00,$3A,$3B,$2E,$2F,$12,$13,$20,$21,$22,$27,$55,$56	; $08
		.BYTE $18,$19,$1C,$00,$30,$31,$32,$33,$44,$45,$20,$21,$23,$24,$55,$56	; $09
		.BYTE $18,$19,$1C,$00,$7C,$7D,$7E,$7F,$34,$35,$00,$01,$25,$03,$55,$56	; $0A
		.BYTE $50,$51,$52,$53,$54,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$78	; $0B	; dialog spr tiles sets
		.BYTE $57,$58,$59,$5A,$5B,$5C,$66,$67,$68,$69,$6A,$6B,$63,$64,$65,$78	; $0C
		.BYTE $57,$58,$59,$5A,$5B,$5C,$5D,$5E,$5F,$60,$61,$62,$75,$76,$77,$79	; $0D
		.BYTE $57,$58,$59,$5A,$5B,$5C,$5D,$5E,$5F,$6F,$70,$71,$72,$73,$74,$7A	; $0E
		.BYTE $57,$58,$59,$5A,$5B,$5C,$6C,$6D,$6E,$60,$61,$62,$63,$64,$65,$7B	; $0F
		.BYTE $18,$19,$1C,$00,$00,$00,$00,$00,$0F,$00,$20,$21,$26,$24,$55,$56	; $10	; final boss spr tile set
_pal_bg_lib:
		.BYTE $0F,$0C,$10,$2C,$0F,$07,$1B,$10,$0F,$10,$17,$07,$0F,$16,$12,$30
		.BYTE $0F,$06,$10,$2C,$0F,$11,$1B,$10,$0F,$10,$17,$07,$0F,$16,$12,$30
		.BYTE $0F,$00,$10,$19,$0F,$10,$17,$07,$0F,$2A,$2C,$1A,$0F,$16,$12,$30
		.BYTE $0F,$0C,$19,$30,$0F,$06,$17,$08,$0F,$30,$2C,$30,$0F,$16,$12,$30
		.BYTE $0C,$1A,$36,$0F,$0C,$10,$0F,$17,$0C,$07,$17,$27,$0C,$16,$12,$30
		.BYTE $0F,$06,$00,$0F,$0F,$1A,$10,$0F,$0F,$1B,$2C,$0A,$0F,$16,$12,$30
		.BYTE $0F,$1A,$10,$0F,$0F,$17,$10,$07,$0F,$0F,$2C,$1A,$0F,$16,$12,$30
		.BYTE $22,$2C,$1C,$0C,$22,$12,$1A,$0F,$22,$1C,$0F,$1A,$22,$16,$12,$30
		.BYTE $0F,$0A,$10,$2C,$0F,$07,$00,$10,$0F,$10,$17,$07,$0F,$16,$12,$30
		.BYTE $0F,$18,$00,$0B,$0F,$30,$10,$1C,$0F,$10,$17,$07,$0F,$16,$12,$30
		.BYTE $0F,$03,$00,$0C,$0F,$00,$0B,$07,$0F,$00,$0F,$0B,$0F,$16,$12,$30
		.BYTE $0F,$18,$00,$0C,$0F,$10,$00,$0B,$0F,$10,$17,$07,$0F,$16,$12,$30
		.BYTE $0F,$18,$10,$1B,$0F,$30,$27,$17,$0F,$2A,$2C,$1A,$0F,$16,$12,$30
		.BYTE $0F,$03,$10,$2C,$0F,$18,$1B,$10,$0F,$10,$17,$07,$0F,$16,$12,$30
		.BYTE $0F,$0F,$0F,$0F,$0F,$0C,$1C,$0F,$0F,$0F,$0F,$0F,$0F,$16,$12,$30
		.BYTE $0C,$0F,$0F,$0F,$0C,$0C,$1C,$0F,$0C,$0F,$10,$19,$0C,$16,$12,$30
_pal_spr_lib:
		.BYTE $0F,$0F,$16,$27,$0F,$0F,$1A,$27,$0F,$0F,$16,$10,$0F,$16,$12,$30
		.BYTE $0F,$06,$16,$27,$0F,$12,$10,$30,$0F,$14,$15,$36,$0F,$16,$12,$30
		.BYTE $0F,$06,$16,$27,$0F,$0F,$1B,$27,$0F,$0F,$2A,$27,$0F,$16,$12,$30
		.BYTE $0F,$0F,$16,$27,$0F,$0F,$12,$27,$0F,$0F,$16,$27,$0F,$16,$12,$30
		.BYTE $0F,$06,$16,$27,$0F,$0F,$1B,$27,$0F,$25,$05,$30,$0F,$16,$12,$30
		.BYTE $0F,$0F,$16,$27,$0F,$0F,$2B,$27,$0F,$01,$1C,$30,$0F,$16,$12,$30
		.BYTE $0F,$0F,$16,$27,$0F,$0F,$14,$36,$0F,$0F,$16,$30,$0F,$16,$12,$30
		.BYTE $0F,$06,$16,$27,$0F,$0F,$2A,$27,$0F,$0F,$16,$36,$0F,$16,$12,$30
		.BYTE $0F,$0F,$16,$27,$0F,$0F,$1A,$36,$0F,$0B,$0C,$0B,$0F,$16,$12,$30
		.BYTE $0F,$0F,$16,$27,$0F,$0F,$1C,$31,$0F,$0F,$12,$36,$0F,$16,$12,$30
		.BYTE $0F,$0F,$16,$27,$0F,$0F,$16,$27,$0F,$0F,$1A,$36,$0F,$16,$12,$30
		.BYTE $0F,$0C,$1C,$2C,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$0F,$16,$12,$30
; 0 byte - left (west) side exit warp idx
; 1 byte - right (east) side exit warp idx
; 2 byte - 1st (south/north/door leftmost) warp location idx
; 3 byte - 2nd (south/north/door rightmost) warp location idx
; note, $00 means no warp location, except for location $00
; in location $00 warp  idx also $00.
; also note, west/east exits may be blocked via location_room_idx_and_stop_flags
; so if you see for example location 07 west exit is also 07 this does not mean
; it warped, it actually blocked
_game_warp_map:
		.BYTE $00,$00,$01,$87	; 00
		.BYTE $01,$01,$00,$00	; 01
		.BYTE $02,$03,$00,$00	; 02
		.BYTE $02,$03,$04,$00	; 03
		.BYTE $04,$05,$07,$03	; 04
		.BYTE $04,$06,$00,$00	; 05
		.BYTE $05,$AA,$00,$00	; 06
		.BYTE $07,$08,$04,$00	; 07
		.BYTE $07,$09,$00,$00	; 08
		.BYTE $08,$09,$06,$0A	; 09
		.BYTE $0A,$0A,$09,$00	; 0A
		.BYTE $18,$18,$00,$00	; 0B
		.BYTE $AE,$8E,$00,$00	; 0C
		.BYTE $10,$0E,$00,$00	; 0D
		.BYTE $A8,$35,$1B,$00	; 0E
		.BYTE $4A,$53,$52,$00	; 1F
		.BYTE $AB,$11,$00,$00	; 10
		.BYTE $10,$12,$00,$00	; 11
		.BYTE $11,$13,$15,$00	; 12
		.BYTE $12,$0E,$00,$00	; 13
		.BYTE $14,$15,$16,$00	; 14
		.BYTE $14,$15,$12,$00	; 15
		.BYTE $16,$17,$14,$00	; 16
		.BYTE $16,$17,$1A,$00	; 17
		.BYTE $95,$19,$17,$00	; 18
		.BYTE $18,$1A,$00,$16	; 19
		.BYTE $19,$1A,$17,$00	; 1A
		.BYTE $1B,$1C,$0E,$00	; 1B
		.BYTE $1B,$1D,$00,$00	; 1C
		.BYTE $1C,$1E,$20,$00	; 1D
		.BYTE $1D,$1E,$21,$00	; 1E
		.BYTE $1F,$20,$22,$00	; 1F
		.BYTE $1F,$21,$23,$00	; 20
		.BYTE $20,$21,$1E,$00	; 21
		.BYTE $22,$23,$1F,$00	; 22
		.BYTE $22,$24,$20,$00	; 23
		.BYTE $23,$90,$00,$00	; 24
		.BYTE $8F,$26,$00,$00	; 25
		.BYTE $25,$27,$2A,$00	; 26
		.BYTE $26,$28,$00,$00	; 27
		.BYTE $27,$28,$00,$00	; 28
		.BYTE $29,$2A,$2D,$00	; 29
		.BYTE $29,$2B,$2E,$26	; 2A
		.BYTE $2A,$2C,$00,$00	; 2B
		.BYTE $2B,$2C,$00,$00	; 2C
		.BYTE $2D,$2E,$29,$00	; 2D
		.BYTE $2D,$2F,$2A,$00	; 2E
		.BYTE $2E,$30,$2B,$00	; 2F
		.BYTE $2F,$30,$00,$00	; 30
		.BYTE $72,$32,$00,$00	; 31
		.BYTE $31,$33,$00,$00	; 32
		.BYTE $32,$34,$00,$00	; 33
		.BYTE $33,$0C,$00,$00	; 34
		.BYTE $0E,$36,$00,$00	; 35
		.BYTE $35,$37,$38,$00	; 36
		.BYTE $36,$37,$00,$00	; 37
		.BYTE $38,$38,$39,$36	; 38
		.BYTE $39,$3A,$38,$3B	; 39
		.BYTE $39,$39,$99,$00	; 3A
		.BYTE $3B,$3B,$3D,$39	; 3B
		.BYTE $3D,$3C,$00,$00	; 3C
		.BYTE $3D,$3E,$3B,$3B	; 3D
		.BYTE $3D,$3D,$00,$3C	; 3E
		.BYTE $0C,$40,$00,$00	; 3F
		.BYTE $3F,$40,$00,$41	; 40
		.BYTE $41,$41,$43,$42	; 41
		.BYTE $3F,$42,$00,$00	; 42
		.BYTE $43,$44,$41,$00	; 43
		.BYTE $43,$45,$00,$42	; 44
		.BYTE $44,$46,$00,$00	; 45
		.BYTE $45,$47,$00,$00	; 46
		.BYTE $46,$47,$00,$48	; 47
		.BYTE $46,$49,$00,$00	; 48
		.BYTE $48,$4A,$00,$00	; 49
		.BYTE $49,$4B,$00,$00	; 4A
		.BYTE $4A,$53,$4D,$00	; 4B
		.BYTE $4C,$4D,$00,$4E	; 4C
		.BYTE $4C,$4D,$4B,$00	; 4D
		.BYTE $4E,$4F,$00,$00	; 4E
		.BYTE $4E,$50,$00,$52	; 4F
		.BYTE $4F,$50,$00,$00	; 50
		.BYTE $51,$52,$00,$00	; 51
		.BYTE $51,$52,$0F,$00	; 52
		.BYTE $0F,$54,$57,$00	; 53
		.BYTE $53,$54,$00,$00	; 54
		.BYTE $55,$56,$9D,$59	; 55
		.BYTE $55,$57,$5A,$00	; 56
		.BYTE $56,$58,$53,$00	; 57
		.BYTE $57,$58,$5C,$00	; 58
		.BYTE $59,$5A,$00,$00	; 59
		.BYTE $59,$5B,$56,$56	; 5A
		.BYTE $5A,$5C,$00,$00	; 5B
		.BYTE $5B,$5C,$58,$58	; 5C
		.BYTE $73,$5D,$00,$00	; 5D
		.BYTE $5E,$5F,$74,$00	; 5E
		.BYTE $5E,$73,$00,$00	; 5F
		.BYTE $13,$13,$00,$00	; 60
		.BYTE $61,$61,$62,$00	; 61
		.BYTE $62,$62,$61,$00	; 62
		.BYTE $63,$64,$0E,$00	; 63
		.BYTE $63,$65,$00,$00	; 64
		.BYTE $64,$66,$68,$00	; 65
		.BYTE $65,$66,$69,$00	; 66
		.BYTE $67,$68,$6A,$00	; 67
		.BYTE $67,$69,$6B,$00	; 68
		.BYTE $68,$69,$66,$00	; 69
		.BYTE $6A,$6B,$67,$00	; 6A
		.BYTE $6A,$6C,$68,$00	; 6B
		.BYTE $6B,$25,$00,$00	; 6C
		.BYTE $6D,$6E,$94,$00	; 6D
		.BYTE $6D,$6E,$6F,$92	; 6E
		.BYTE $6F,$0C,$00,$00	; 6F
		.BYTE $70,$71,$00,$00	; 70
		.BYTE $70,$71,$72,$00	; 71
		.BYTE $72,$31,$71,$00	; 72
		.BYTE $5F,$5D,$00,$00	; 73
		.BYTE $74,$75,$78,$00	; 74
		.BYTE $74,$76,$00,$00	; 75
		.BYTE $75,$77,$73,$00	; 76
		.BYTE $76,$5D,$5D,$00	; 77
		.BYTE $78,$79,$74,$00	; 78
		.BYTE $78,$7A,$00,$00	; 79
		.BYTE $79,$7B,$00,$00	; 7A
		.BYTE $7A,$7B,$B0,$00	; 7B
		.BYTE $7C,$7D,$00,$00	; 7C
		.BYTE $A6,$7E,$00,$00	; 7D
		.BYTE $A6,$7F,$00,$00	; 7E
		.BYTE $A7,$7F,$00,$00	; 7F
; two-byte for each object slot, 8 slots total, 16 bytes per location
; 0 byte - two 4-bit nibbles for X and Y pos of macro tile in level buffer
; 1 byte - 2-bit nibble for screen index out of max 4 (0-3)
;          6-bit object handler index
_stage_obj_list:
; $00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$A,$1,_obj_hndl03_npcC
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $01
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$3,$3,_obj_hndl01_npcA
		OBJ_MAP $D,$2,$2,_obj_hndl02_npcB
		OBJ_MAP $2,$8,$0,_obj_hndl3E_helicopterB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $02
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $5,$8,$2,_obj_hndl05_bee
		OBJ_MAP $6,$A,$1,_obj_hndl05_bee
		OBJ_MAP $D,$B,$2,_obj_hndl06_snake
		OBJ_MAP $4,$3,$3,_obj_hndl05_bee
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $03
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $4,$8,$3,_obj_hndl05_bee
		OBJ_MAP $D,$7,$3,_obj_hndl06_snake
		OBJ_MAP $6,$B,$0,_obj_hndl05_bee
		OBJ_MAP $D,$5,$1,_obj_hndl06_snake
		OBJ_MAP $7,$8,$1,_obj_hndl05_bee
		OBJ_MAP $5,$4,$2,_obj_hndl05_bee
		OBJ_MAP $0,$0,$0,$00
; $04
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $7,$4,$1,_obj_hndl05_bee
		OBJ_MAP $8,$8,$2,_obj_hndl05_bee
		OBJ_MAP $D,$8,$1,_obj_hndl06_snake
		OBJ_MAP $5,$3,$0,_obj_hndl05_bee
		OBJ_MAP $4,$2,$3,_obj_hndl05_bee
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $05
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $7,$4,$2,_obj_hndl05_bee
		OBJ_MAP $7,$4,$1,_obj_hndl05_bee
		OBJ_MAP $D,$5,$1,_obj_hndl06_snake
		OBJ_MAP $5,$A,$0,_obj_hndl05_bee
		OBJ_MAP $6,$8,$3,_obj_hndl05_bee
		OBJ_MAP $D,$5,$2,_obj_hndl06_snake
		OBJ_MAP $0,$0,$0,$00
; $06
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$5,$2,_obj_hndl04_npcD
		OBJ_MAP $D,$8,$0,_obj_hndl01_npcA
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $07
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$7,$2,_obj_hndl06_snake
		OBJ_MAP $D,$5,$1,_obj_hndl06_snake
		OBJ_MAP $D,$E,$1,_obj_hndl06_snake
		OBJ_MAP $4,$5,$0,_obj_hndl05_bee
		OBJ_MAP $5,$6,$3,_obj_hndl05_bee
		OBJ_MAP $D,$2,$3,_obj_hndl06_snake
		OBJ_MAP $0,$0,$0,$00
; $08
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $9,$B,$1,_obj_hndl19_tiger
		OBJ_MAP $D,$9,$2,_obj_hndl19_tiger
		OBJ_MAP $3,$E,$0,_obj_hndl05_bee
		OBJ_MAP $5,$8,$2,_obj_hndl05_bee
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $09
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$9,$1,_obj_hndl19_tiger
		OBJ_MAP $5,$C,$2,_obj_hndl06_snake
		OBJ_MAP $4,$8,$1,_obj_hndl06_snake
		OBJ_MAP $D,$B,$0,_obj_hndl06_snake
		OBJ_MAP $5,$4,$3,_obj_hndl06_snake
		OBJ_MAP $D,$A,$2,_obj_hndl06_snake
		OBJ_MAP $0,$0,$0,$00
; $0A
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$A,$1,_obj_hndl01_npcA
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $0B
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $F,$F,$1,_obj_hndl15_grenades
		OBJ_MAP $F,$F,$2,_obj_hndl15_grenades
		OBJ_MAP $B,$9,$0,_obj_hndl04_npcD
		OBJ_MAP $F,$F,$2,_obj_hndl15_grenades
		OBJ_MAP $8,$E,$2,_obj_hndl3E_helicopterB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $0C
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$7,$1,_obj_hndl03_npcC
		OBJ_MAP $D,$A,$2,_obj_hndl04_npcD
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $0D
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $B,$3,$2,_obj_hndl01_npcA
		OBJ_MAP $B,$B,$2,_obj_hndl04_npcD
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $0E
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$8,$2,_obj_hndl01_npcA
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $0F
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$8,$2,_obj_hndl23_soldierC
		OBJ_MAP $D,$B,$1,_obj_hndl11_landmine
		OBJ_MAP $D,$1,$3,_obj_hndl27_soldierB
		OBJ_MAP $D,$B,$2,_obj_hndl11_landmine
		OBJ_MAP $D,$C,$0,_obj_hndl11_landmine
		OBJ_MAP $D,$7,$1,_obj_hndl23_soldierC
		OBJ_MAP $0,$0,$0,$00
; $10
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $4,$5,$2,_obj_hndl05_bee
		OBJ_MAP $D,$C,$0,_obj_hndl07_fish
		OBJ_MAP $D,$2,$1,_obj_hndl07_fish
		OBJ_MAP $D,$4,$2,_obj_hndl07_fish
		OBJ_MAP $D,$3,$3,_obj_hndl07_fish
		OBJ_MAP $6,$8,$1,_obj_hndl05_bee
		OBJ_MAP $0,$0,$0,$00
; $11
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $B,$A,$2,_obj_hndl07_fish
		OBJ_MAP $C,$6,$1,_obj_hndl07_fish
		OBJ_MAP $B,$C,$0,_obj_hndl07_fish
		OBJ_MAP $A,$2,$2,_obj_hndl07_fish
		OBJ_MAP $A,$2,$3,_obj_hndl07_fish
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $12
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $4,$8,$1,_obj_hndl05_bee
		OBJ_MAP $D,$C,$0,_obj_hndl07_fish
		OBJ_MAP $D,$9,$1,_obj_hndl07_fish
		OBJ_MAP $6,$B,$2,_obj_hndl05_bee
		OBJ_MAP $D,$1,$2,_obj_hndl07_fish
		OBJ_MAP $D,$4,$3,_obj_hndl07_fish
		OBJ_MAP $0,$0,$0,$00
; $13
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$A,$2,_obj_hndl17_pelikan
		OBJ_MAP $F,$8,$2,_obj_hndl0C_bird
		OBJ_MAP $D,$5,$3,_obj_hndl17_pelikan
		OBJ_MAP $D,$A,$0,_obj_hndl17_pelikan
		OBJ_MAP $F,$8,$1,_obj_hndl0C_bird
		OBJ_MAP $D,$A,$1,_obj_hndl17_pelikan
		OBJ_MAP $0,$0,$0,$00
; $14
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $B,$3,$1,_obj_hndl0F_spider
		OBJ_MAP $B,$4,$2,_obj_hndl0F_spider
		OBJ_MAP $D,$5,$1,_obj_hndl0F_spider
		OBJ_MAP $D,$6,$2,_obj_hndl0F_spider
		OBJ_MAP $B,$4,$3,_obj_hndl0F_spider
		OBJ_MAP $B,$B,$1,_obj_hndl0F_spider
		OBJ_MAP $0,$0,$0,$00
; $15
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $B,$1,$1,_obj_hndl19_tiger
		OBJ_MAP $B,$3,$3,_obj_hndl19_tiger
		OBJ_MAP $B,$C,$1,_obj_hndl19_tiger
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $16
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $8,$5,$2,_obj_hndl18_gorilla
		OBJ_MAP $F,$F,$2,_obj_hndl14_rocks
		OBJ_MAP $9,$E,$0,_obj_hndl18_gorilla
		OBJ_MAP $F,$F,$1,_obj_hndl14_rocks
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $17
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $9,$6,$1,_obj_hndl19_tiger
		OBJ_MAP $9,$B,$1,_obj_hndl06_snake
		OBJ_MAP $B,$5,$2,_obj_hndl19_tiger
		OBJ_MAP $9,$B,$2,_obj_hndl06_snake
		OBJ_MAP $B,$E,$0,_obj_hndl06_snake
		OBJ_MAP $D,$1,$3,_obj_hndl06_snake
		OBJ_MAP $0,$0,$0,$00
; $18
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $5,$C,$2,_obj_hndl21_soldierA
		OBJ_MAP $5,$2,$2,_obj_hndl21_soldierA
		OBJ_MAP $D,$8,$2,_obj_hndl1D_soldierB
		OBJ_MAP $5,$2,$1,_obj_hndl21_soldierA
		OBJ_MAP $5,$D,$1,_obj_hndl21_soldierA
		OBJ_MAP $D,$7,$1,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
; $19
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $C,$E,$2,_obj_hndl3F_multipurpose
		OBJ_MAP $F,$F,$3,_obj_hndl14_rocks
		OBJ_MAP $F,$F,$2,_obj_hndl14_rocks
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $1A
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $8,$6,$2,_obj_hndl18_gorilla
		OBJ_MAP $4,$A,$2,_obj_hndl05_bee
		OBJ_MAP $8,$A,$1,_obj_hndl18_gorilla
		OBJ_MAP $5,$3,$1,_obj_hndl05_bee
		OBJ_MAP $4,$9,$0,_obj_hndl05_bee
		OBJ_MAP $4,$6,$3,_obj_hndl05_bee
		OBJ_MAP $0,$0,$0,$00
; $1B
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $4,$D,$2,_obj_hndl05_bee
		OBJ_MAP $D,$1,$2,_obj_hndl07_fish
		OBJ_MAP $D,$B,$2,_obj_hndl07_fish
		OBJ_MAP $D,$5,$3,_obj_hndl07_fish
		OBJ_MAP $5,$5,$1,_obj_hndl05_bee
		OBJ_MAP $D,$A,$0,_obj_hndl07_fish
		OBJ_MAP $0,$0,$0,$00
; $1C
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $B,$A,$2,_obj_hndl07_fish
		OBJ_MAP $A,$1,$1,_obj_hndl07_fish
		OBJ_MAP $B,$B,$1,_obj_hndl07_fish
		OBJ_MAP $A,$2,$3,_obj_hndl07_fish
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $1D
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$7,$0,_obj_hndl07_fish
		OBJ_MAP $4,$6,$2,_obj_hndl05_bee
		OBJ_MAP $D,$6,$3,_obj_hndl07_fish
		OBJ_MAP $D,$6,$2,_obj_hndl07_fish
		OBJ_MAP $4,$6,$1,_obj_hndl05_bee
		OBJ_MAP $D,$6,$1,_obj_hndl07_fish
		OBJ_MAP $0,$0,$0,$00
; $1E
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$6,$3,_obj_hndl07_fish
		OBJ_MAP $D,$A,$0,_obj_hndl07_fish
		OBJ_MAP $D,$6,$1,_obj_hndl07_fish
		OBJ_MAP $3,$E,$1,_obj_hndl05_bee
		OBJ_MAP $4,$3,$2,_obj_hndl05_bee
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $1F
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$7,$1,_obj_hndl17_pelikan
		OBJ_MAP $F,$8,$0,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$1,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$2,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$3,_obj_hndl0C_bird
		OBJ_MAP $D,$B,$2,_obj_hndl17_pelikan
		OBJ_MAP $0,$0,$0,$00
; $20
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$4,$0,_obj_hndl17_pelikan
		OBJ_MAP $F,$F,$1,_obj_hndl08_bubbles
		OBJ_MAP $F,$F,$1,_obj_hndl08_bubbles
		OBJ_MAP $D,$D,$2,_obj_hndl17_pelikan
		OBJ_MAP $D,$2,$3,_obj_hndl17_pelikan
		OBJ_MAP $F,$F,$1,_obj_hndl08_bubbles
		OBJ_MAP $0,$0,$0,$00
; $21
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$6,$3,_obj_hndl17_pelikan
		OBJ_MAP $F,$8,$1,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$0,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$3,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$2,_obj_hndl0C_bird
		OBJ_MAP $D,$4,$1,_obj_hndl17_pelikan
		OBJ_MAP $0,$0,$0,$00
; $22
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$7,$1,_obj_hndl17_pelikan
		OBJ_MAP $B,$E,$0,_obj_hndl17_pelikan
		OBJ_MAP $D,$5,$3,_obj_hndl17_pelikan
		OBJ_MAP $D,$3,$2,_obj_hndl17_pelikan
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $23
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$B,$0,_obj_hndl3F_multipurpose
		OBJ_MAP $F,$F,$1,_obj_hndl08_bubbles
		OBJ_MAP $F,$F,$1,_obj_hndl08_bubbles
		OBJ_MAP $F,$F,$1,_obj_hndl08_bubbles
		OBJ_MAP $D,$D,$1,_obj_hndl17_pelikan
		OBJ_MAP $D,$E,$2,_obj_hndl17_pelikan
		OBJ_MAP $0,$0,$0,$00
; $24
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$9,$2,_obj_hndl17_pelikan
		OBJ_MAP $B,$D,$0,_obj_hndl17_pelikan
		OBJ_MAP $D,$7,$1,_obj_hndl17_pelikan
		OBJ_MAP $F,$8,$2,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$3,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$0,_obj_hndl0C_bird
		OBJ_MAP $0,$0,$0,$00
; $25
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $C,$B,$1,_obj_hndl1D_soldierB
		OBJ_MAP $B,$2,$1,_obj_hndl1C_soldierA
		OBJ_MAP $D,$7,$2,_obj_hndl1C_soldierA
		OBJ_MAP $A,$2,$3,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $26
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $C,$3,$2,_obj_hndl1C_soldierA
		OBJ_MAP $A,$1,$1,_obj_hndl1C_soldierA
		OBJ_MAP $D,$A,$1,_obj_hndl1D_soldierB
		OBJ_MAP $B,$C,$2,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $27
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$1,$2,_obj_hndl1C_soldierA
		OBJ_MAP $D,$8,$2,_obj_hndl1C_soldierA
		OBJ_MAP $A,$E,$0,_obj_hndl1C_soldierA
		OBJ_MAP $D,$A,$1,_obj_hndl1C_soldierA
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $28
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$A,$1,_obj_hndl1E_soldierB
		OBJ_MAP $A,$1,$1,_obj_hndl1D_soldierB
		OBJ_MAP $B,$C,$2,_obj_hndl1E_soldierB
		OBJ_MAP $A,$E,$1,_obj_hndl1D_soldierB
		OBJ_MAP $A,$2,$3,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $29
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$4,$1,_obj_hndl2C_dubina_man
		OBJ_MAP $B,$6,$2,_obj_hndl2C_dubina_man
		OBJ_MAP $D,$1,$3,_obj_hndl1D_soldierB
		OBJ_MAP $D,$1,$1,_obj_hndl1D_soldierB
		OBJ_MAP $D,$8,$1,_obj_hndl1D_soldierB
		OBJ_MAP $D,$3,$1,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
; $2A
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$C,$1,_obj_hndl3F_multipurpose
		OBJ_MAP $B,$1,$1,_obj_hndl1D_soldierB
		OBJ_MAP $8,$B,$2,_obj_hndl1C_soldierA
		OBJ_MAP $8,$B,$1,_obj_hndl1C_soldierA
		OBJ_MAP $D,$D,$2,_obj_hndl1D_soldierB
		OBJ_MAP $8,$4,$3,_obj_hndl1C_soldierA
		OBJ_MAP $0,$0,$0,$00
; $2B
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$3,$2,_obj_hndl1A_tiger
		OBJ_MAP $D,$6,$1,_obj_hndl1A_tiger
		OBJ_MAP $D,$E,$0,_obj_hndl1D_soldierB
		OBJ_MAP $D,$2,$3,_obj_hndl1D_soldierB
		OBJ_MAP $B,$7,$2,_obj_hndl1C_soldierA
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $2C
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$1,$2,_obj_hndl3F_multipurpose
		OBJ_MAP $8,$2,$2,_obj_hndl21_soldierA
		OBJ_MAP $D,$E,$0,_obj_hndl1D_soldierB
		OBJ_MAP $9,$3,$1,_obj_hndl21_soldierA
		OBJ_MAP $A,$1,$3,_obj_hndl1D_soldierB
		OBJ_MAP $8,$8,$2,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
; $2D
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$1,$2,_obj_hndl3F_multipurpose
		OBJ_MAP $D,$B,$1,_obj_hndl1A_tiger
		OBJ_MAP $D,$4,$2,_obj_hndl1D_soldierB
		OBJ_MAP $9,$C,$2,_obj_hndl1A_tiger
		OBJ_MAP $9,$1,$1,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $2E
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $9,$C,$1,_obj_hndl2C_dubina_man
		OBJ_MAP $9,$1,$1,_obj_hndl1C_soldierA
		OBJ_MAP $9,$8,$1,_obj_hndl1C_soldierA
		OBJ_MAP $9,$4,$2,_obj_hndl1C_soldierA
		OBJ_MAP $9,$A,$2,_obj_hndl1C_soldierA
		OBJ_MAP $9,$1,$3,_obj_hndl21_soldierA
		OBJ_MAP $0,$0,$0,$00
; $2F
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $7,$A,$1,_obj_hndl21_soldierA
		OBJ_MAP $7,$2,$1,_obj_hndl1D_soldierB
		OBJ_MAP $7,$C,$0,_obj_hndl21_soldierA
		OBJ_MAP $8,$B,$2,_obj_hndl1D_soldierB
		OBJ_MAP $8,$1,$3,_obj_hndl21_soldierA
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $30
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $8,$7,$1,_obj_hndl04_npcD
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $31
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$B,$1,_obj_hndl34_crouching_bomb_man
		OBJ_MAP $9,$9,$1,_obj_hndl26_grenade_soldier
		OBJ_MAP $D,$E,$0,_obj_hndl26_grenade_soldier
		OBJ_MAP $9,$6,$2,_obj_hndl26_grenade_soldier
		OBJ_MAP $D,$1,$3,_obj_hndl26_grenade_soldier
		OBJ_MAP $D,$C,$2,_obj_hndl34_crouching_bomb_man
		OBJ_MAP $0,$0,$0,$00
; $32
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$6,$2,_obj_hndl38_boss_motorcycle
		OBJ_MAP $D,$B,$1,_obj_hndl26_grenade_soldier
		OBJ_MAP $9,$1,$1,_obj_hndl26_grenade_soldier
		OBJ_MAP $9,$E,$2,_obj_hndl26_grenade_soldier
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $33
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$4,$1,_obj_hndl34_crouching_bomb_man
		OBJ_MAP $D,$D,$0,_obj_hndl26_grenade_soldier
		OBJ_MAP $D,$B,$1,_obj_hndl26_grenade_soldier
		OBJ_MAP $D,$C,$2,_obj_hndl26_grenade_soldier
		OBJ_MAP $D,$2,$3,_obj_hndl26_grenade_soldier
		OBJ_MAP $D,$8,$2,_obj_hndl34_crouching_bomb_man
		OBJ_MAP $0,$0,$0,$00
; $34
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$8,$1,_obj_hndl17_pelikan
		OBJ_MAP $D,$8,$2,_obj_hndl17_pelikan
		OBJ_MAP $F,$8,$0,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$1,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$2,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$3,_obj_hndl0C_bird
		OBJ_MAP $0,$0,$0,$00
; $35
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $6,$B,$1,_obj_hndl05_bee
		OBJ_MAP $D,$B,$1,_obj_hndl06_snake
		OBJ_MAP $4,$2,$3,_obj_hndl06_snake
		OBJ_MAP $5,$A,$2,_obj_hndl05_bee
		OBJ_MAP $D,$6,$2,_obj_hndl06_snake
		OBJ_MAP $6,$A,$0,_obj_hndl05_bee
		OBJ_MAP $0,$0,$0,$00
; $36
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$6,$2,_obj_hndl19_tiger
		OBJ_MAP $5,$4,$2,_obj_hndl06_snake
		OBJ_MAP $D,$7,$1,_obj_hndl19_tiger
		OBJ_MAP $7,$8,$1,_obj_hndl06_snake
		OBJ_MAP $8,$8,$0,_obj_hndl06_snake
		OBJ_MAP $5,$4,$3,_obj_hndl06_snake
		OBJ_MAP $0,$0,$0,$00
; $37
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $3,$8,$2,_obj_hndl0E_small_bat
		OBJ_MAP $9,$8,$0,_obj_hndl0F_spider
		OBJ_MAP $9,$4,$3,_obj_hndl0F_spider
		OBJ_MAP $3,$8,$1,_obj_hndl0E_small_bat
		OBJ_MAP $9,$B,$1,_obj_hndl0F_spider
		OBJ_MAP $8,$D,$2,_obj_hndl0F_spider
		OBJ_MAP $0,$0,$0,$00
; $38
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $8,$8,$2,_obj_hndl0E_small_bat
		OBJ_MAP $D,$D,$1,_obj_hndl0F_spider
		OBJ_MAP $8,$4,$0,_obj_hndl0E_small_bat
		OBJ_MAP $D,$E,$0,_obj_hndl0F_spider
		OBJ_MAP $D,$7,$2,_obj_hndl0F_spider
		OBJ_MAP $D,$2,$3,_obj_hndl0F_spider
		OBJ_MAP $0,$0,$0,$00
; $39
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $F,$F,$1,_obj_hndl0B_skull
		OBJ_MAP $F,$F,$1,_obj_hndl0B_skull
		OBJ_MAP $D,$1,$1,_obj_hndl0F_spider
		OBJ_MAP $D,$D,$1,_obj_hndl0F_spider
		OBJ_MAP $D,$F,$2,_obj_hndl0F_spider
		OBJ_MAP $D,$5,$3,_obj_hndl0F_spider
		OBJ_MAP $0,$0,$0,$00
; $3A
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$3,$2,_obj_hndl04_npcD
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $3B
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $5,$6,$3,_obj_hndl09_ceiling_bat
		OBJ_MAP $5,$4,$2,_obj_hndl09_ceiling_bat
		OBJ_MAP $5,$4,$1,_obj_hndl09_ceiling_bat
		OBJ_MAP $5,$9,$0,_obj_hndl09_ceiling_bat
		OBJ_MAP $F,$F,$1,_obj_hndl0B_skull
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $3C
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$C,$0,_obj_hndl37_boss_spider
		OBJ_MAP $B,$A,$1,_obj_hndl0F_spider
		OBJ_MAP $9,$1,$2,_obj_hndl0F_spider
		OBJ_MAP $D,$4,$3,_obj_hndl1B_kid
		OBJ_MAP $9,$2,$1,_obj_hndl0F_spider
		OBJ_MAP $D,$7,$1,_obj_hndl0F_spider
		OBJ_MAP $0,$0,$0,$00
; $3D
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $F,$A,$0,_obj_hndl16_cobra
		OBJ_MAP $F,$E,$1,_obj_hndl16_cobra
		OBJ_MAP $F,$6,$2,_obj_hndl16_cobra
		OBJ_MAP $F,$2,$3,_obj_hndl16_cobra
		OBJ_MAP $5,$8,$0,_obj_hndl09_ceiling_bat
		OBJ_MAP $5,$8,$2,_obj_hndl09_ceiling_bat
		OBJ_MAP $0,$0,$0,$00
; $3E
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $C,$7,$1,_obj_hndl0E_small_bat
		OBJ_MAP $7,$9,$0,_obj_hndl0A_stalaktit
		OBJ_MAP $5,$C,$0,_obj_hndl0A_stalaktit
		OBJ_MAP $6,$C,$1,_obj_hndl0A_stalaktit
		OBJ_MAP $6,$C,$0,_obj_hndl0E_small_bat
		OBJ_MAP $4,$1,$2,_obj_hndl0A_stalaktit
		OBJ_MAP $0,$0,$0,$00
; $3F
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$8,$1,_obj_hndl07_fish
		OBJ_MAP $D,$5,$1,_obj_hndl07_fish
		OBJ_MAP $D,$B,$0,_obj_hndl07_fish
		OBJ_MAP $D,$7,$2,_obj_hndl07_fish
		OBJ_MAP $D,$B,$2,_obj_hndl07_fish
		OBJ_MAP $D,$6,$3,_obj_hndl07_fish
		OBJ_MAP $0,$0,$0,$00
; $40
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $5,$3,$2,_obj_hndl05_bee
		OBJ_MAP $7,$C,$1,_obj_hndl05_bee
		OBJ_MAP $3,$C,$2,_obj_hndl05_bee
		OBJ_MAP $C,$8,$2,_obj_hndl05_bee
		OBJ_MAP $4,$F,$0,_obj_hndl05_bee
		OBJ_MAP $8,$1,$1,_obj_hndl05_bee
		OBJ_MAP $0,$0,$0,$00
; $41
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $F,$F,$3,_obj_hndl0D_waterfall_logs
		OBJ_MAP $F,$F,$3,_obj_hndl0D_waterfall_logs
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $42
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $C,$8,$2,_obj_hndl17_pelikan
		OBJ_MAP $9,$5,$1,_obj_hndl17_pelikan
		OBJ_MAP $F,$8,$2,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$0,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$1,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$3,_obj_hndl0C_bird
		OBJ_MAP $0,$0,$0,$00
; $43
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$7,$1,_obj_hndl36_boss_fire_tiger
		OBJ_MAP $9,$B,$1,_obj_hndl0A_stalaktit
		OBJ_MAP $8,$3,$2,_obj_hndl0A_stalaktit
		OBJ_MAP $A,$C,$2,_obj_hndl0A_stalaktit
		OBJ_MAP $A,$D,$2,_obj_hndl0A_stalaktit
		OBJ_MAP $8,$5,$3,_obj_hndl0A_stalaktit
		OBJ_MAP $0,$0,$0,$00
; $44
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $7,$7,$2,_obj_hndl0E_small_bat
		OBJ_MAP $8,$B,$0,_obj_hndl0E_small_bat
		OBJ_MAP $5,$8,$1,_obj_hndl0E_small_bat
		OBJ_MAP $6,$E,$2,_obj_hndl0E_small_bat
		OBJ_MAP $5,$6,$3,_obj_hndl0E_small_bat
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $45
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $5,$6,$2,_obj_hndl09_ceiling_bat
		OBJ_MAP $5,$9,$0,_obj_hndl09_ceiling_bat
		OBJ_MAP $5,$7,$1,_obj_hndl09_ceiling_bat
		OBJ_MAP $D,$7,$1,_obj_hndl0F_spider
		OBJ_MAP $D,$8,$1,_obj_hndl0F_spider
		OBJ_MAP $5,$7,$3,_obj_hndl09_ceiling_bat
		OBJ_MAP $0,$0,$0,$00
; $46
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $F,$6,$2,_obj_hndl16_cobra
		OBJ_MAP $F,$E,$1,_obj_hndl16_cobra
		OBJ_MAP $F,$A,$0,_obj_hndl16_cobra
		OBJ_MAP $F,$2,$3,_obj_hndl16_cobra
		OBJ_MAP $9,$A,$1,_obj_hndl0A_stalaktit
		OBJ_MAP $5,$C,$2,_obj_hndl0A_stalaktit
		OBJ_MAP $0,$0,$0,$00
; $47
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $F,$8,$2,_obj_hndl0C_bird
		OBJ_MAP $F,$8,$1,_obj_hndl0C_bird
		OBJ_MAP $A,$F,$0,_obj_hndl17_pelikan
		OBJ_MAP $9,$6,$1,_obj_hndl17_pelikan
		OBJ_MAP $F,$8,$3,_obj_hndl0C_bird
		OBJ_MAP $A,$1,$3,_obj_hndl17_pelikan
		OBJ_MAP $0,$0,$0,$00
; $48
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$A,$1,_obj_hndl24_soldierB
		OBJ_MAP $D,$C,$2,_obj_hndl02_npcB
		OBJ_MAP $D,$A,$0,_obj_hndl24_soldierB
		OBJ_MAP $D,$3,$3,_obj_hndl24_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $49
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$9,$2,_obj_hndl24_soldierB
		OBJ_MAP $9,$A,$1,_obj_hndl10_floor_turret
		OBJ_MAP $D,$1,$1,_obj_hndl10_floor_turret
		OBJ_MAP $D,$9,$2,_obj_hndl10_floor_turret
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $4A
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $9,$2,$2,_obj_hndl24_soldierB
		OBJ_MAP $D,$9,$1,_obj_hndl25_soldierB
		OBJ_MAP $D,$F,$0,_obj_hndl25_soldierB
		OBJ_MAP $9,$3,$3,_obj_hndl24_soldierB
		OBJ_MAP $9,$2,$1,_obj_hndl24_soldierB
		OBJ_MAP $D,$C,$2,_obj_hndl25_soldierB
		OBJ_MAP $0,$0,$0,$00
; $4B
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$1,$2,_obj_hndl39_boss_drone
		OBJ_MAP $D,$3,$1,_obj_hndl24_soldierB
		OBJ_MAP $D,$4,$3,_obj_hndl25_soldierB
		OBJ_MAP $D,$C,$2,_obj_hndl25_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $4C
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $5,$3,$1,_obj_hndl24_soldierB
		OBJ_MAP $9,$A,$1,_obj_hndl24_soldierB
		OBJ_MAP $9,$A,$2,_obj_hndl24_soldierB
		OBJ_MAP $D,$1,$2,_obj_hndl24_soldierB
		OBJ_MAP $5,$F,$2,_obj_hndl24_soldierB
		OBJ_MAP $D,$7,$0,_obj_hndl24_soldierB
		OBJ_MAP $0,$0,$0,$00
; $4D
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$9,$1,_obj_hndl3F_multipurpose
		OBJ_MAP $6,$B,$0,_obj_hndl24_soldierB
		OBJ_MAP $D,$1,$1,_obj_hndl32_skull_monkey
		OBJ_MAP $6,$7,$1,_obj_hndl24_soldierB
		OBJ_MAP $D,$9,$2,_obj_hndl32_skull_monkey
		OBJ_MAP $6,$4,$3,_obj_hndl24_soldierB
		OBJ_MAP $0,$0,$0,$00
; $4E
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$2,$2,_obj_hndl3F_multipurpose
		OBJ_MAP $D,$1,$1,_obj_hndl24_soldierB
		OBJ_MAP $D,$7,$1,_obj_hndl24_soldierB
		OBJ_MAP $5,$9,$1,_obj_hndl25_soldierB
		OBJ_MAP $D,$5,$2,_obj_hndl25_soldierB
		OBJ_MAP $D,$1,$3,_obj_hndl25_soldierB
		OBJ_MAP $0,$0,$0,$00
; $4F
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $9,$B,$1,_obj_hndl24_soldierB
		OBJ_MAP $5,$D,$0,_obj_hndl24_soldierB
		OBJ_MAP $D,$1,$1,_obj_hndl24_soldierB
		OBJ_MAP $9,$1,$3,_obj_hndl24_soldierB
		OBJ_MAP $D,$2,$2,_obj_hndl24_soldierB
		OBJ_MAP $5,$8,$2,_obj_hndl24_soldierB
		OBJ_MAP $0,$0,$0,$00
; $50
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$A,$2,_obj_hndl32_skull_monkey
		OBJ_MAP $6,$6,$1,_obj_hndl25_soldierB
		OBJ_MAP $6,$B,$0,_obj_hndl25_soldierB
		OBJ_MAP $6,$3,$3,_obj_hndl25_soldierB
		OBJ_MAP $D,$5,$1,_obj_hndl32_skull_monkey
		OBJ_MAP $6,$9,$2,_obj_hndl25_soldierB
		OBJ_MAP $0,$0,$0,$00
; $51
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $6,$B,$2,_obj_hndl24_soldierB
		OBJ_MAP $D,$5,$1,_obj_hndl25_soldierB
		OBJ_MAP $D,$9,$2,_obj_hndl25_soldierB
		OBJ_MAP $D,$1,$3,_obj_hndl25_soldierB
		OBJ_MAP $6,$4,$1,_obj_hndl24_soldierB
		OBJ_MAP $D,$8,$0,_obj_hndl25_soldierB
		OBJ_MAP $0,$0,$0,$00
; $52
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$1,$2,_obj_hndl31_machete_man
		OBJ_MAP $6,$A,$0,_obj_hndl24_soldierB
		OBJ_MAP $6,$7,$1,_obj_hndl24_soldierB
		OBJ_MAP $D,$3,$1,_obj_hndl31_machete_man
		OBJ_MAP $6,$8,$2,_obj_hndl24_soldierB
		OBJ_MAP $6,$5,$3,_obj_hndl24_soldierB
		OBJ_MAP $0,$0,$0,$00
; $53
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$B,$1,_obj_hndl13_jumping_ball
		OBJ_MAP $D,$9,$0,_obj_hndl11_landmine
		OBJ_MAP $D,$F,$2,_obj_hndl13_jumping_ball
		OBJ_MAP $D,$4,$2,_obj_hndl11_landmine
		OBJ_MAP $D,$2,$1,_obj_hndl11_landmine
		OBJ_MAP $D,$2,$3,_obj_hndl11_landmine
		OBJ_MAP $0,$0,$0,$00
; $54
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $2,$2,$3,_obj_hndl3E_helicopterB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $55
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$D,$2,_obj_hndl3A_boss_yusin
		OBJ_MAP $D,$8,$1,_obj_hndl13_jumping_ball
		OBJ_MAP $8,$8,$1,_obj_hndl13_jumping_ball
		OBJ_MAP $8,$8,$2,_obj_hndl13_jumping_ball
		OBJ_MAP $9,$3,$3,_obj_hndl13_jumping_ball
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $56
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$1,$3,_obj_hndl23_soldierC
		OBJ_MAP $7,$A,$1,_obj_hndl23_soldierC
		OBJ_MAP $7,$E,$0,_obj_hndl27_soldierB
		OBJ_MAP $7,$8,$2,_obj_hndl27_soldierB
		OBJ_MAP $D,$E,$0,_obj_hndl27_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $57
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$1,$2,_obj_hndl3F_multipurpose
		OBJ_MAP $D,$E,$2,_obj_hndl2D_spectre
		OBJ_MAP $D,$D,$0,_obj_hndl2D_spectre
		OBJ_MAP $D,$2,$1,_obj_hndl27_soldierB
		OBJ_MAP $D,$A,$1,_obj_hndl27_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $58
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $7,$5,$3,_obj_hndl3F_multipurpose
		OBJ_MAP $D,$F,$2,_obj_hndl27_soldierB
		OBJ_MAP $7,$8,$0,_obj_hndl27_soldierB
		OBJ_MAP $7,$2,$3,_obj_hndl27_soldierB
		OBJ_MAP $D,$9,$0,_obj_hndl23_soldierC
		OBJ_MAP $7,$8,$1,_obj_hndl23_soldierC
		OBJ_MAP $0,$0,$0,$00
; $59
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $8,$3,$1,_obj_hndl3F_multipurpose
		OBJ_MAP $D,$7,$1,_obj_hndl33_shield_man
		OBJ_MAP $8,$8,$1,_obj_hndl27_soldierB
		OBJ_MAP $D,$8,$2,_obj_hndl27_soldierB
		OBJ_MAP $8,$2,$3,_obj_hndl33_shield_man
		OBJ_MAP $D,$B,$0,_obj_hndl27_soldierB
		OBJ_MAP $0,$0,$0,$00
; $5A
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $7,$7,$2,_obj_hndl33_shield_man
		OBJ_MAP $D,$6,$2,_obj_hndl23_soldierC
		OBJ_MAP $D,$1,$3,_obj_hndl23_soldierC
		OBJ_MAP $7,$F,$0,_obj_hndl23_soldierC
		OBJ_MAP $D,$E,$0,_obj_hndl23_soldierC
		OBJ_MAP $D,$9,$1,_obj_hndl33_shield_man
		OBJ_MAP $0,$0,$0,$00
; $5B
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$8,$2,_obj_hndl23_soldierC
		OBJ_MAP $4,$1,$1,_obj_hndl12_ceiling_turret
		OBJ_MAP $4,$1,$3,_obj_hndl12_ceiling_turret
		OBJ_MAP $D,$5,$1,_obj_hndl23_soldierC
		OBJ_MAP $4,$1,$2,_obj_hndl12_ceiling_turret
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $5C
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $7,$5,$3,_obj_hndl27_soldierB
		OBJ_MAP $7,$8,$2,_obj_hndl27_soldierB
		OBJ_MAP $7,$3,$1,_obj_hndl27_soldierB
		OBJ_MAP $D,$8,$1,_obj_hndl2D_spectre
		OBJ_MAP $D,$7,$2,_obj_hndl2D_spectre
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $5D
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$1,$2,_obj_hndl3F_multipurpose
		OBJ_MAP $A,$D,$0,_obj_hndl22_soldierB
		OBJ_MAP $9,$4,$1,_obj_hndl22_soldierB
		OBJ_MAP $D,$8,$1,_obj_hndl22_soldierB
		OBJ_MAP $8,$3,$2,_obj_hndl22_soldierB
		OBJ_MAP $8,$C,$2,_obj_hndl22_soldierB
		OBJ_MAP $0,$0,$0,$00
; $5E
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$5,$2,_obj_hndl22_soldierB
		OBJ_MAP $B,$1,$1,_obj_hndl22_soldierB
		OBJ_MAP $B,$B,$0,_obj_hndl22_soldierB
		OBJ_MAP $D,$1,$3,_obj_hndl22_soldierB
		OBJ_MAP $D,$B,$1,_obj_hndl22_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $5F
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $C,$4,$1,_obj_hndl29_soldierB
		OBJ_MAP $B,$D,$0,_obj_hndl28_soldierB
		OBJ_MAP $A,$2,$3,_obj_hndl29_soldierB
		OBJ_MAP $C,$C,$1,_obj_hndl29_soldierB
		OBJ_MAP $D,$7,$2,_obj_hndl28_soldierB
		OBJ_MAP $B,$F,$2,_obj_hndl29_soldierB
		OBJ_MAP $0,$0,$0,$00
; $60
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$4,$1,_obj_hndl2B_boss_pirate
		OBJ_MAP $D,$B,$1,_obj_hndl2A_pirate
		OBJ_MAP $B,$1,$2,_obj_hndl01_npcA
		OBJ_MAP $B,$E,$2,_obj_hndl2A_pirate
		OBJ_MAP $D,$4,$3,_obj_hndl2A_pirate
		OBJ_MAP $D,$A,$0,_obj_hndl2A_pirate
		OBJ_MAP $0,$0,$0,$00
; $61
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$C,$1,_obj_hndl03_npcC
		OBJ_MAP $D,$9,$3,_obj_hndl02_npcB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $62
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$3,$3,_obj_hndl03_npcC
		OBJ_MAP $D,$B,$1,_obj_hndl04_npcD
		OBJ_MAP $2,$8,$0,_obj_hndl3E_helicopterB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $63
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $E,$E,$2,_obj_hndl17_pelikan
		OBJ_MAP $E,$E,$0,_obj_hndl17_pelikan
		OBJ_MAP $F,$F,$2,_obj_hndl15_grenades
		OBJ_MAP $F,$F,$2,_obj_hndl15_grenades
		OBJ_MAP $D,$1,$2,_obj_hndl17_pelikan
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $64
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $C,$6,$1,_obj_hndl1C_soldierA
		OBJ_MAP $B,$D,$0,_obj_hndl1D_soldierB
		OBJ_MAP $B,$C,$1,_obj_hndl1D_soldierB
		OBJ_MAP $B,$8,$2,_obj_hndl1C_soldierA
		OBJ_MAP $A,$1,$2,_obj_hndl1C_soldierA
		OBJ_MAP $B,$D,$2,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
; $65
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$6,$2,_obj_hndl1C_soldierA
		OBJ_MAP $D,$C,$0,_obj_hndl1C_soldierA
		OBJ_MAP $D,$7,$1,_obj_hndl1C_soldierA
		OBJ_MAP $D,$B,$1,_obj_hndl1C_soldierA
		OBJ_MAP $D,$6,$2,_obj_hndl1C_soldierA
		OBJ_MAP $D,$6,$3,_obj_hndl1C_soldierA
		OBJ_MAP $0,$0,$0,$00
; $66
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$6,$3,_obj_hndl17_pelikan
		OBJ_MAP $D,$C,$0,_obj_hndl17_pelikan
		OBJ_MAP $F,$F,$1,_obj_hndl15_grenades
		OBJ_MAP $F,$F,$1,_obj_hndl15_grenades
		OBJ_MAP $D,$7,$2,_obj_hndl17_pelikan
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $67
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$6,$2,_obj_hndl1D_soldierB
		OBJ_MAP $D,$B,$2,_obj_hndl1D_soldierB
		OBJ_MAP $D,$1,$1,_obj_hndl1D_soldierB
		OBJ_MAP $D,$C,$1,_obj_hndl1D_soldierB
		OBJ_MAP $D,$6,$3,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $68
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $9,$1,$2,_obj_hndl1C_soldierA
		OBJ_MAP $8,$D,$2,_obj_hndl1C_soldierA
		OBJ_MAP $D,$1,$3,_obj_hndl1D_soldierB
		OBJ_MAP $8,$2,$1,_obj_hndl1C_soldierA
		OBJ_MAP $D,$E,$0,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $69
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$7,$3,_obj_hndl21_soldierA
		OBJ_MAP $D,$E,$2,_obj_hndl1D_soldierB
		OBJ_MAP $D,$4,$1,_obj_hndl21_soldierA
		OBJ_MAP $D,$E,$1,_obj_hndl1D_soldierB
		OBJ_MAP $D,$D,$0,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $6A
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$8,$2,_obj_hndl1C_soldierA
		OBJ_MAP $B,$1,$2,_obj_hndl1C_soldierA
		OBJ_MAP $D,$5,$1,_obj_hndl1C_soldierA
		OBJ_MAP $D,$5,$3,_obj_hndl1C_soldierA
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $6B
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$C,$1,_obj_hndl1D_soldierB
		OBJ_MAP $D,$3,$1,_obj_hndl1D_soldierB
		OBJ_MAP $9,$2,$1,_obj_hndl1C_soldierA
		OBJ_MAP $9,$3,$2,_obj_hndl1C_soldierA
		OBJ_MAP $9,$C,$2,_obj_hndl1C_soldierA
		OBJ_MAP $D,$1,$3,_obj_hndl1D_soldierB
		OBJ_MAP $0,$0,$0,$00
; $6C
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $B,$B,$2,_obj_hndl1C_soldierA
		OBJ_MAP $D,$9,$1,_obj_hndl1C_soldierA
		OBJ_MAP $A,$1,$3,_obj_hndl1D_soldierB
		OBJ_MAP $A,$E,$1,_obj_hndl1D_soldierB
		OBJ_MAP $C,$3,$2,_obj_hndl1C_soldierA
		OBJ_MAP $B,$E,$0,_obj_hndl1C_soldierA
		OBJ_MAP $0,$0,$0,$00
; $6D
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$4,$1,_obj_hndl20_torture_room_soldier
		OBJ_MAP $B,$5,$2,_obj_hndl20_torture_room_soldier
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $6E
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$5,$3,_obj_hndl35_guard_of_torture_room
		OBJ_MAP $8,$8,$2,_obj_hndl20_torture_room_soldier
		OBJ_MAP $9,$3,$1,_obj_hndl20_torture_room_soldier
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $6F
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$9,$2,_obj_hndl20_torture_room_soldier
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $70
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $B,$6,$0,_obj_hndl1F_soldierB
		OBJ_MAP $B,$8,$2,_obj_hndl1F_soldierB
		OBJ_MAP $D,$1,$1,_obj_hndl30_burning_man
		OBJ_MAP $B,$4,$3,_obj_hndl1F_soldierB
		OBJ_MAP $B,$B,$0,_obj_hndl1F_soldierB
		OBJ_MAP $B,$2,$2,_obj_hndl30_burning_man
		OBJ_MAP $0,$0,$0,$00
; $71
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $8,$4,$2,_obj_hndl1F_soldierB
		OBJ_MAP $8,$E,$2,_obj_hndl1F_soldierB
		OBJ_MAP $8,$D,$1,_obj_hndl30_burning_man
		OBJ_MAP $9,$1,$1,_obj_hndl1F_soldierB
		OBJ_MAP $D,$3,$3,_obj_hndl30_burning_man
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $72
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $B,$C,$2,_obj_hndl1E_soldierB
		OBJ_MAP $A,$1,$3,_obj_hndl1F_soldierB
		OBJ_MAP $A,$E,$1,_obj_hndl1F_soldierB
		OBJ_MAP $B,$3,$1,_obj_hndl1F_soldierB
		OBJ_MAP $D,$A,$1,_obj_hndl1E_soldierB
		OBJ_MAP $D,$6,$0,_obj_hndl1E_soldierB
		OBJ_MAP $0,$0,$0,$00
; $73
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$5,$2,_obj_hndl2E_armored_man
		OBJ_MAP $B,$2,$2,_obj_hndl29_soldierB
		OBJ_MAP $D,$1,$3,_obj_hndl29_soldierB
		OBJ_MAP $B,$6,$0,_obj_hndl29_soldierB
		OBJ_MAP $D,$F,$0,_obj_hndl2E_armored_man
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $74
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$1,$2,_obj_hndl3F_multipurpose
		OBJ_MAP $9,$1,$1,_obj_hndl29_soldierB
		OBJ_MAP $8,$2,$2,_obj_hndl28_soldierB
		OBJ_MAP $D,$9,$2,_obj_hndl28_soldierB
		OBJ_MAP $A,$D,$0,_obj_hndl29_soldierB
		OBJ_MAP $A,$1,$3,_obj_hndl28_soldierB
		OBJ_MAP $0,$0,$0,$00
; $75
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$3,$1,_obj_hndl28_soldierB
		OBJ_MAP $9,$E,$2,_obj_hndl29_soldierB
		OBJ_MAP $9,$7,$1,_obj_hndl2E_armored_man
		OBJ_MAP $9,$4,$2,_obj_hndl2E_armored_man
		OBJ_MAP $9,$1,$1,_obj_hndl29_soldierB
		OBJ_MAP $D,$7,$2,_obj_hndl28_soldierB
		OBJ_MAP $0,$0,$0,$00
; $76
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $7,$E,$0,_obj_hndl2F_strong_man
		OBJ_MAP $A,$1,$2,_obj_hndl29_soldierB
		OBJ_MAP $D,$D,$2,_obj_hndl29_soldierB
		OBJ_MAP $8,$7,$3,_obj_hndl2F_strong_man
		OBJ_MAP $B,$F,$0,_obj_hndl29_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $77
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $8,$7,$1,_obj_hndl04_npcD
		OBJ_MAP $2,$3,$3,_obj_hndl3E_helicopterB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $78
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $C,$4,$2,_obj_hndl29_soldierB
		OBJ_MAP $A,$E,$1,_obj_hndl28_soldierB
		OBJ_MAP $A,$1,$3,_obj_hndl29_soldierB
		OBJ_MAP $B,$B,$2,_obj_hndl28_soldierB
		OBJ_MAP $D,$5,$0,_obj_hndl28_soldierB
		OBJ_MAP $B,$F,$0,_obj_hndl29_soldierB
		OBJ_MAP $0,$0,$0,$00
; $79
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$8,$2,_obj_hndl3B_boss_padovski
		OBJ_MAP $D,$2,$3,_obj_hndl22_soldierB
		OBJ_MAP $D,$F,$0,_obj_hndl22_soldierB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $7A
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $D,$8,$2,_obj_hndl29_soldierB
		OBJ_MAP $D,$6,$2,_obj_hndl29_soldierB
		OBJ_MAP $D,$7,$3,_obj_hndl29_soldierB
		OBJ_MAP $B,$D,$0,_obj_hndl29_soldierB
		OBJ_MAP $D,$6,$1,_obj_hndl29_soldierB
		OBJ_MAP $D,$9,$1,_obj_hndl29_soldierB
		OBJ_MAP $0,$0,$0,$00
; $7B
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $8,$F,$2,_obj_hndl29_soldierB
		OBJ_MAP $7,$7,$0,_obj_hndl29_soldierB
		OBJ_MAP $A,$1,$2,_obj_hndl11_landmine
		OBJ_MAP $9,$4,$2,_obj_hndl11_landmine
		OBJ_MAP $7,$8,$1,_obj_hndl29_soldierB
		OBJ_MAP $D,$C,$3,_obj_hndl28_soldierB
		OBJ_MAP $0,$0,$0,$00
; $7C
		OBJ_MAP $0,$0,$0,_obj_hndl3C_plane
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $7D
		OBJ_MAP $D,$8,$3,_obj_hndl3D_helicopterA
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $7E
		OBJ_MAP $D,$8,$3,_obj_hndl3D_helicopterA
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
; $7F
		OBJ_MAP $D,$8,$3,_obj_hndl3D_helicopterA
		OBJ_MAP $D,$C,$3,_obj_hndl3E_helicopterB
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
		OBJ_MAP $0,$0,$0,$00
_obj_params_lib:
		.BYTE $F0,$EF,$00,$06,$00,$00,$80|$00						,$00	; $00
		.BYTE $F0,$D8,$00,$06,$00,$FF,$80|_objB_hndl14_score_1_idx	,$00	; $01
		.BYTE $F0,$D8,$00,$06,$00,$FF,$80|_objB_hndl14_score_1_idx	,$00	; $02
		.BYTE $F0,$D8,$00,$06,$00,$FF,$80|_objB_hndl14_score_1_idx	,$00	; $03
		.BYTE $F0,$D8,$00,$06,$00,$FF,$80|_objB_hndl14_score_1_idx	,$00	; $04
		.BYTE $F0,$2F,$00,$03,$04,$01,    _objB_hndl14_score_1_idx	,$00	; $05
		.BYTE $F0,$FF,$00,$03,$04,$02,    _objB_hndl14_score_1_idx	,$00	; $06
		.BYTE $F0,$AF,$00,$03,$04,$04,    _objB_hndl15_score_2_idx	,$00	; $07
		.BYTE $F0,$28,$00,$00,$04,$FF,$80|_objB_hndl14_score_1_idx	,$00	; $08
		.BYTE $F0,$2F,$00,$03,$08,$04,    _objB_hndl15_score_2_idx	,$00	; $09
		.BYTE $F0,$EF,$00,$03,$14,$FF,    _objB_hndl19_score_50_idx	,$00	; $0A
		.BYTE $F0,$2F,$00,$03,$08,$0C,    _objB_hndl17_score_10_idx	,$00	; $0B
		.BYTE $F0,$2F,$00,$03,$04,$02,    _objB_hndl14_score_1_idx	,$00	; $0C
		.BYTE $F0,$28,$00,$0C,$14,$FF,$80|_objB_hndl1A_score_100_idx,$00	; $0D
		.BYTE $F0,$AF,$00,$02,$08,$04,    _objB_hndl15_score_2_idx	,$00	; $0E
		.BYTE $F0,$FF,$00,$00,$04,$02,    _objB_hndl14_score_1_idx	,$00	; $0F
		.BYTE $F0,$3F,$00,$03,$18,$FF,    _objB_hndl14_score_1_idx	,$00	; $10
		.BYTE $F0,$3F,$00,$02,$24,$02,$80|_objB_hndl09_animate_idx	,$00	; $11
		.BYTE $F0,$3F,$00,$03,$1C,$02,    _objB_hndl14_score_1_idx	,$00	; $12
		.BYTE $F0,$E8,$00,$03,$1C,$60,    _objB_hndl1A_score_100_idx,$00	; $13
		.BYTE $F0,$28,$00,$03,$08,$FF,$80|_objB_hndl18_score_20_idx	,$00	; $14
		.BYTE $F0,$EF,$00,$01,$0C,$FF,$80|_objB_hndl17_score_10_idx	,$00	; $15
		.BYTE $F0,$28,$00,$00,$08,$06,    _objB_hndl16_score_5_idx	,$00	; $16
		.BYTE $F0,$EF,$00,$05,$08,$06,    _objB_hndl16_score_5_idx	,$00	; $17
		.BYTE $F0,$EF,$00,$09,$10,$18,    _objB_hndl18_score_20_idx	,$00	; $18
		.BYTE $F0,$EF,$00,$0C,$04,$04,    _objB_hndl15_score_2_idx	,$00	; $19
		.BYTE $F0,$EF,$00,$0C,$0C,$06,    _objB_hndl16_score_5_idx	,$00	; $1A
		.BYTE $F0,$D8,$00,$01,$00,$FF,$80|_objB_hndl14_score_1_idx	,$00	; $1B
		.BYTE $F0,$EF,$00,$06,$0C,$06,    _objB_hndl16_score_5_idx	,$00	; $1C
		.BYTE $F0,$EF,$00,$06,$0C,$06,    _objB_hndl16_score_5_idx	,$00	; $1D
		.BYTE $F0,$EF,$00,$06,$0C,$0C,    _objB_hndl17_score_10_idx	,$00	; $1E
		.BYTE $F0,$EF,$00,$06,$10,$0C,    _objB_hndl17_score_10_idx	,$00	; $1F
		.BYTE $F0,$D8,$00,$06,$00,$FF,$80|_objB_hndl14_score_1_idx	,$00	; $20
		.BYTE $F0,$EF,$00,$06,$0C,$0C,    _objB_hndl17_score_10_idx	,$00	; $21
		.BYTE $F0,$EF,$00,$06,$20,$C0,    _objB_hndl1B_score_200_idx,$00	; $22
		.BYTE $F0,$EF,$00,$06,$1C,$60,    _objB_hndl1A_score_100_idx,$00	; $23
		.BYTE $F0,$EF,$00,$06,$18,$30,    _objB_hndl0C_arrow_ammo_idx,$00	; $24
		.BYTE $F0,$EF,$00,$06,$18,$30,    _objB_hndl19_score_50_idx	,$00	; $25
		.BYTE $F0,$EF,$00,$06,$10,$0C,    _objB_hndl17_score_10_idx	,$00	; $26
		.BYTE $F0,$EF,$00,$06,$1C,$60,    _objB_hndl1A_score_100_idx,$00	; $27
		.BYTE $F0,$EF,$00,$06,$20,$C0,    _objB_hndl1B_score_200_idx,$00	; $28
		.BYTE $F0,$EF,$00,$06,$20,$C0,    _objB_hndl1B_score_200_idx,$00	; $29
		.BYTE $F0,$EF,$00,$06,$0C,$0C,    _objB_hndl17_score_10_idx	,$00	; $2A
		.BYTE $F0,$EF,$00,$06,$0C,$18,$80|_objB_hndl18_score_20_idx	,$00	; $2B
		.BYTE $F0,$EF,$00,$7A,$0C,$18,    _objB_hndl18_score_20_idx	,$00	; $2C
		.BYTE $F0,$EF,$00,$09,$1C,$C0,    _objB_hndl1B_score_200_idx,$00	; $2D
		.BYTE $F0,$EF,$00,$06,$20,$FF,    _objB_hndl1C_score_500_idx,$00	; $2E
		.BYTE $F0,$EF,$00,$07,$20,$FF,    _objB_hndl1C_score_500_idx,$00	; $2F
		.BYTE $F0,$EF,$00,$06,$10,$18,$80|_objB_hndl18_score_20_idx	,$00	; $30
		.BYTE $F0,$EF,$00,$0B,$18,$60,    _objB_hndl0D_explo_arrow_ammo_idx,$00	; $31
		.BYTE $F0,$EF,$00,$09,$18,$60,    _objB_hndl0E_machinegun_ammo_idx,$00	; $32
		.BYTE $F0,$EF,$00,$05,$1C,$C0,    _objB_hndl1B_score_200_idx,$00	; $33
		.BYTE $F0,$EF,$00,$06,$10,$18,    _objB_hndl18_score_20_idx	,$00	; $34
		.BYTE $F0,$D8,$00,$06,$00,$FF,$80|$00						,$00	; $35
		.BYTE $F0,$EF,$00,$0C,$14,$10,$80|_objB_hndl1B_score_200_idx,$00	; $36
		.BYTE $F0,$EF,$0B,$CF,$08,$10,$80|_objB_hndl1A_score_100_idx,$00	; $37
		.BYTE $F0,$EF,$0B,$0E,$10,$10,$80|_objB_hndl1B_score_200_idx,$00	; $38
		.BYTE $F0,$2F,$00,$DA,$18,$10,$80|_objB_hndl1C_score_500_idx,$00	; $39
		.BYTE $F0,$EF,$00,$46,$1C,$10,$80|_objB_hndl1C_score_500_idx,$00	; $3A
		.BYTE $F0,$EF,$00,$06,$20,$10,$80|_objB_hndl1C_score_500_idx,$00	; $3B
		.BYTE $F0,$00,$00,$00,$00,$FF,    _objB_hndl14_score_1_idx	,$00	; $3C
		.BYTE $F0,$00,$00,$0C,$00,$10,    _objB_hndl14_score_1_idx	,$00	; $3D
		.BYTE $F0,$3F,$00,$0E,$00,$10,$80|_objB_hndl14_score_1_idx	,$00	; $3E
		.BYTE $F0,$0C,$00,$03,$00,$01,$80|_objB_hndl14_score_1_idx	,$00	; $3F
