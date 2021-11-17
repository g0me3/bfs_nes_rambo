
		ORG $8000

		BANK_START $06

		SECTION_START

_location_room_settings:
		.BYTE $20,$20,$40,$40,$40,$40,$20,$40,$40,$40,$20,$40,$20,$21,$20,$40
		.BYTE $41,$41,$41,$41,$40,$40,$40,$40,$40,$40,$40,$41,$41,$41,$41,$41
		.BYTE $41,$40,$41,$41,$40,$40,$40,$40,$40,$40,$40,$40,$40,$40,$41,$40
		.BYTE $20,$40,$30,$40,$40,$40,$40,$40,$42,$40,$20,$42,$32,$42,$42,$41
		.BYTE $40,$40,$40,$32,$42,$42,$42,$40,$40,$40,$40,$30,$40,$40,$40,$40
		.BYTE $40,$40,$40,$40,$20,$30,$40,$40,$40,$40,$40,$40,$40,$40,$40,$40
		.BYTE $31,$20,$20,$41,$41,$41,$41,$41,$41,$40,$41,$41,$40,$20,$20,$20
		.BYTE $40,$40,$40,$40,$40,$41,$40,$20,$40,$30,$40,$40,$40,$40,$40,$40
_location_chr_list:
		.BYTE $00,$01,$32,$32,$32,$32,$42,$32,$32,$32,$42,$02,$22,$43,$42,$80
		.BYTE $33,$33,$33,$43,$12,$32,$35,$35,$35,$35,$35,$33,$33,$33,$33,$43
		.BYTE $43,$42,$43,$43,$42,$52,$52,$52,$A2,$52,$52,$52,$52,$52,$53,$52
		.BYTE $02,$76,$76,$72,$42,$32,$35,$12,$12,$15,$22,$12,$12,$12,$12,$33
		.BYTE $35,$45,$45,$12,$12,$12,$12,$45,$75,$66,$60,$90,$67,$67,$67,$67
		.BYTE $67,$67,$67,$80,$00,$27,$87,$87,$87,$87,$87,$87,$87,$A2,$A2,$92
		.BYTE $43,$40,$01,$43,$53,$53,$43,$53,$53,$52,$53,$53,$52,$72,$72,$72
		.BYTE $A2,$A2,$A2,$92,$92,$93,$92,$02,$92,$A6,$92,$62,$14,$04,$04,$04
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
_location_room_idx_and_stop_flags:
		.BYTE $00,$01,$44,$85,$48,$04,$07,$49,$33,$85,$C4,$02,$06,$0E,$04,$27
		.BYTE $0F,$0B,$0F,$0C,$49,$88,$5E,$9F,$20,$21,$9E,$4F,$0B,$0C,$8A,$4C
		.BYTE $0D,$85,$4A,$13,$11,$09,$11,$10,$91,$52,$15,$12,$94,$54,$13,$15
		.BYTE $32,$34,$34,$05,$04,$05,$20,$B3,$1D,$1F,$06,$1B,$18,$19,$1A,$0F
		.BYTE $A4,$25,$A2,$1D,$1C,$1B,$19,$A4,$22,$34,$26,$27,$69,$A8,$6B,$29
		.BYTE $AA,$6A,$28,$36,$37,$6D,$2E,$30,$AE,$6C,$2F,$31,$B1,$94,$50,$11
		.BYTE $0E,$00,$01,$4F,$0B,$0C,$8A,$4C,$0D,$85,$4A,$13,$11,$52,$94,$50
		.BYTE $52,$94,$51,$12,$54,$13,$15,$32,$51,$34,$11,$95,$3C,$3C,$3C,$3C
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
		.BYTE $00,$00,$0B,$0B,$0B,$0B,$00,$0B,$0C,$0C,$00,$00,$00,$00,$00,$0B
		.BYTE $0B,$11,$0F,$0B,$0B,$0B,$10,$0E,$0C,$12,$0B,$0B,$0C,$11,$10,$0C
		.BYTE $0B,$0F,$0B,$12,$0B,$0B,$0B,$0B,$0E,$0C,$0C,$0C,$10,$0B,$0B,$0D
		.BYTE $00,$0D,$0A,$0B,$0B,$0F,$0B,$0D,$0B,$0C,$00,$0C,$0A,$0B,$0B,$0B
		.BYTE $0B,$00,$0D,$0A,$0B,$0B,$0C,$0B,$0E,$0B,$0F,$0A,$0B,$0F,$0D,$0B
		.BYTE $10,$0E,$0B,$0D,$00,$0A,$0B,$0F,$10,$0E,$0B,$0C,$0B,$10,$0B,$0C
		.BYTE $0A,$00,$00,$11,$0B,$0B,$0C,$10,$12,$0D,$0E,$0B,$0C,$00,$00,$00
		.BYTE $0B,$0E,$0B,$0C,$0F,$12,$0E,$00,$0B,$0A,$0B,$0D,$00,$00,$00,$00
_chr_bg_table_lib:
		.BYTE $00,$01,$02,$03,$04,$05,$08,$10,$11,$17,$18,$19,$1A,$1B,$2C,$2D
		.BYTE $00,$01,$02,$03,$04,$05,$0A,$10,$11,$12,$13,$14,$15,$16,$2C,$2D
		.BYTE $00,$01,$02,$03,$04,$05,$09,$0C,$0D,$1C,$1D,$1E,$1F,$20,$2E,$2F
		.BYTE $00,$01,$02,$03,$06,$07,$00,$0E,$0F,$1C,$1D,$1E,$1F,$20,$2E,$2F
		.BYTE $00,$01,$02,$03,$04,$05,$00,$00,$00,$26,$27,$28,$29,$2A,$00,$00
		.BYTE $00,$01,$02,$03,$04,$05,$00,$0E,$0F,$1C,$1D,$1E,$1F,$20,$2E,$2F
		.BYTE $00,$01,$02,$03,$04,$05,$0A,$10,$11,$1C,$1D,$1E,$1F,$20,$2E,$2F
		.BYTE $00,$01,$02,$03,$04,$05,$08,$10,$11,$21,$22,$23,$24,$25,$2C,$2D
		.BYTE $30,$31,$32,$33,$34,$35,$36,$37,$38,$39,$3A,$3B,$3C,$3D,$3E,$3F
		.BYTE $00,$01,$02,$30,$31,$32,$33,$34,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
_chr_spr_table_lib:
		.BYTE $18,$19,$1C,$00,$04,$05,$06,$0B,$4A,$4B,$4C,$4D,$4E,$4F,$55,$56
		.BYTE $18,$19,$1C,$00,$09,$29,$1E,$1F,$0E,$11,$3E,$3F,$40,$41,$55,$56
		.BYTE $18,$19,$1C,$00,$09,$0A,$07,$08,$12,$13,$46,$47,$48,$49,$55,$56
		.BYTE $18,$19,$1C,$00,$14,$15,$16,$17,$0C,$0D,$00,$01,$02,$03,$55,$56
		.BYTE $18,$19,$1C,$00,$09,$0A,$04,$2A,$0F,$10,$28,$29,$2A,$2B,$55,$56
		.BYTE $18,$19,$1C,$00,$2C,$2D,$14,$15,$34,$35,$00,$01,$02,$03,$55,$56
		.BYTE $18,$19,$1C,$00,$38,$39,$36,$37,$12,$13,$20,$21,$23,$24,$55,$56
		.BYTE $18,$19,$1C,$00,$09,$0A,$3C,$3D,$42,$43,$20,$21,$26,$24,$55,$56
		.BYTE $18,$19,$1C,$00,$3A,$3B,$2E,$2F,$12,$13,$20,$21,$22,$27,$55,$56
		.BYTE $18,$19,$1C,$00,$30,$31,$32,$33,$44,$45,$20,$21,$23,$24,$55,$56
		.BYTE $18,$19,$1C,$00,$7C,$7D,$7E,$7F,$34,$35,$00,$01,$25,$03,$55,$56
		.BYTE $50,$51,$52,$53,$54,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$78
		.BYTE $57,$58,$59,$5A,$5B,$5C,$66,$67,$68,$69,$6A,$6B,$63,$64,$65,$78
		.BYTE $57,$58,$59,$5A,$5B,$5C,$5D,$5E,$5F,$60,$61,$62,$75,$76,$77,$79
		.BYTE $57,$58,$59,$5A,$5B,$5C,$5D,$5E,$5F,$6F,$70,$71,$72,$73,$74,$7A
		.BYTE $57,$58,$59,$5A,$5B,$5C,$6C,$6D,$6E,$60,$61,$62,$63,$64,$65,$7B
		.BYTE $18,$19,$1C,$00,$00,$00,$00,$00,$0F,$00,$20,$21,$26,$24,$55,$56
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
_game_warp_map:
		.BYTE $00,$00,$01,$87
		.BYTE $01,$01,$00,$00
		.BYTE $02,$03,$00,$00
		.BYTE $02,$03,$04,$00
		.BYTE $04,$05,$07,$03
		.BYTE $04,$06,$00,$00
		.BYTE $05,$AA,$00,$00
		.BYTE $07,$08,$04,$00
		.BYTE $07,$09,$00,$00
		.BYTE $08,$09,$06,$0A
		.BYTE $0A,$0A,$09,$00
		.BYTE $18,$18,$00,$00
		.BYTE $AE,$8E,$00,$00
		.BYTE $10,$0E,$00,$00
		.BYTE $A8,$35,$1B,$00
		.BYTE $4A,$53,$52,$00
		.BYTE $AB,$11,$00,$00
		.BYTE $10,$12,$00,$00
		.BYTE $11,$13,$15,$00
		.BYTE $12,$0E,$00,$00
		.BYTE $14,$15,$16,$00
		.BYTE $14,$15,$12,$00
		.BYTE $16,$17,$14,$00
		.BYTE $16,$17,$1A,$00
		.BYTE $95,$19,$17,$00
		.BYTE $18,$1A,$00,$16
		.BYTE $19,$1A,$17,$00
		.BYTE $1B,$1C,$0E,$00
		.BYTE $1B,$1D,$00,$00
		.BYTE $1C,$1E,$20,$00
		.BYTE $1D,$1E,$21,$00
		.BYTE $1F,$20,$22,$00
		.BYTE $1F,$21,$23,$00
		.BYTE $20,$21,$1E,$00
		.BYTE $22,$23,$1F,$00
		.BYTE $22,$24,$20,$00
		.BYTE $23,$90,$00,$00
		.BYTE $8F,$26,$00,$00
		.BYTE $25,$27,$2A,$00
		.BYTE $26,$28,$00,$00
		.BYTE $27,$28,$00,$00
		.BYTE $29,$2A,$2D,$00
		.BYTE $29,$2B,$2E,$26
		.BYTE $2A,$2C,$00,$00
		.BYTE $2B,$2C,$00,$00
		.BYTE $2D,$2E,$29,$00
		.BYTE $2D,$2F,$2A,$00
		.BYTE $2E,$30,$2B,$00
		.BYTE $2F,$30,$00,$00
		.BYTE $72,$32,$00,$00
		.BYTE $31,$33,$00,$00
		.BYTE $32,$34,$00,$00
		.BYTE $33,$0C,$00,$00
		.BYTE $0E,$36,$00,$00
		.BYTE $35,$37,$38,$00
		.BYTE $36,$37,$00,$00
		.BYTE $38,$38,$39,$36
		.BYTE $39,$3A,$38,$3B
		.BYTE $39,$39,$99,$00
		.BYTE $3B,$3B,$3D,$39
		.BYTE $3D,$3C,$00,$00
		.BYTE $3D,$3E,$3B,$3B
		.BYTE $3D,$3D,$00,$3C
		.BYTE $0C,$40,$00,$00
		.BYTE $3F,$40,$00,$41
		.BYTE $41,$41,$43,$42
		.BYTE $3F,$42,$00,$00
		.BYTE $43,$44,$41,$00
		.BYTE $43,$45,$00,$42
		.BYTE $44,$46,$00,$00
		.BYTE $45,$47,$00,$00
		.BYTE $46,$47,$00,$48
		.BYTE $46,$49,$00,$00
		.BYTE $48,$4A,$00,$00
		.BYTE $49,$4B,$00,$00
		.BYTE $4A,$53,$4D,$00
		.BYTE $4C,$4D,$00,$4E
		.BYTE $4C,$4D,$4B,$00
		.BYTE $4E,$4F,$00,$00
		.BYTE $4E,$50,$00,$52
		.BYTE $4F,$50,$00,$00
		.BYTE $51,$52,$00,$00
		.BYTE $51,$52,$0F,$00
		.BYTE $0F,$54,$57,$00
		.BYTE $53,$54,$00,$00
		.BYTE $55,$56,$9D,$59
		.BYTE $55,$57,$5A,$00
		.BYTE $56,$58,$53,$00
		.BYTE $57,$58,$5C,$00
		.BYTE $59,$5A,$00,$00
		.BYTE $59,$5B,$56,$56
		.BYTE $5A,$5C,$00,$00
		.BYTE $5B,$5C,$58,$58
		.BYTE $73,$5D,$00,$00
		.BYTE $5E,$5F,$74,$00
		.BYTE $5E,$73,$00,$00
		.BYTE $13,$13,$00,$00
		.BYTE $61,$61,$62,$00
		.BYTE $62,$62,$61,$00
		.BYTE $63,$64,$0E,$00
		.BYTE $63,$65,$00,$00
		.BYTE $64,$66,$68,$00
		.BYTE $65,$66,$69,$00
		.BYTE $67,$68,$6A,$00
		.BYTE $67,$69,$6B,$00
		.BYTE $68,$69,$66,$00
		.BYTE $6A,$6B,$67,$00
		.BYTE $6A,$6C,$68,$00
		.BYTE $6B,$25,$00,$00
		.BYTE $6D,$6E,$94,$00
		.BYTE $6D,$6E,$6F,$92
		.BYTE $6F,$0C,$00,$00
		.BYTE $70,$71,$00,$00
		.BYTE $70,$71,$72,$00
		.BYTE $72,$31,$71,$00
		.BYTE $5F,$5D,$00,$00
		.BYTE $74,$75,$78,$00
		.BYTE $74,$76,$00,$00
		.BYTE $75,$77,$73,$00
		.BYTE $76,$5D,$5D,$00
		.BYTE $78,$79,$74,$00
		.BYTE $78,$7A,$00,$00
		.BYTE $79,$7B,$00,$00
		.BYTE $7A,$7B,$B0,$00
		.BYTE $7C,$7D,$00,$00
		.BYTE $A6,$7E,$00,$00
		.BYTE $A6,$7F,$00,$00
		.BYTE $A7,$7F,$00,$00
_cutscene_chr_tbl:
		.BYTE $B8,$B8,$B8,$C8,$C8,$C8,$C8,$C8,$C8,$D8,$D8,$D8,$D8,$D8,$C8,$D8
		.BYTE $D8,$E8,$E8,$E8,$E8,$E8,$C8,$F8,$E8,$E8,$E8,$E8,$D8,$F8,$D8,$D8
		.BYTE $D8,$D8,$D8,$C8,$C8,$D8,$C8,$C8,$C8,$C8,$C8,$C8,$C8,$D8,$C8,$D8
		.BYTE $C8,$C8,$D8,$E8,$F8,$C8
_stage_obj_list:
		.BYTE $00,$00,$AD,$43,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00
		.BYTE $00,$00,$3D,$C1,$2D,$82,$82,$3E,$00,$00,$00,$00,$00,$00,$00,$00; $10
		.BYTE $00,$00,$85,$85,$A6,$45,$BD,$86,$34,$C5,$00,$00,$00,$00,$00,$00; $20
		.BYTE $00,$00,$84,$C5,$7D,$C6,$B6,$05,$5D,$46,$87,$45,$45,$85,$00,$00; $30
		.BYTE $00,$00,$47,$45,$88,$85,$8D,$46,$35,$05,$24,$C5,$00,$00,$00,$00; $40
		.BYTE $00,$00,$47,$85,$47,$45,$5D,$46,$A5,$05,$86,$C5,$5D,$86,$00,$00; $50
		.BYTE $00,$00,$5D,$84,$8D,$01,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $60
		.BYTE $00,$00,$7D,$86,$5D,$46,$ED,$46,$54,$05,$65,$C5,$2D,$C6,$00,$00; $70
		.BYTE $00,$00,$B9,$59,$9D,$99,$E3,$05,$85,$85,$00,$00,$00,$00,$00,$00; $80
		.BYTE $00,$00,$9D,$59,$C5,$86,$84,$46,$BD,$06,$45,$C6,$AD,$86,$00,$00; $90
		.BYTE $00,$00,$AD,$41,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $A0
		.BYTE $00,$00,$FF,$55,$FF,$95,$9B,$04,$FF,$95,$E8,$BE,$00,$00,$00,$00; $B0
		.BYTE $00,$00,$7D,$43,$AD,$84,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $C0
		.BYTE $00,$00,$3B,$81,$BB,$84,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $D0
		.BYTE $00,$00,$8D,$81,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $E0
		.BYTE $00,$00,$8D,$A3,$BD,$51,$1D,$E7,$BD,$91,$CD,$11,$7D,$63,$00,$00; $F0
		.BYTE $00,$00,$54,$85,$CD,$07,$2D,$47,$4D,$87,$3D,$C7,$86,$45,$00,$00; $100
		.BYTE $00,$00,$AB,$87,$6C,$47,$CB,$07,$2A,$87,$2A,$C7,$00,$00,$00,$00; $110
		.BYTE $00,$00,$84,$45,$CD,$07,$9D,$47,$B6,$85,$1D,$87,$4D,$C7,$00,$00; $120
		.BYTE $00,$00,$AD,$97,$8F,$8C,$5D,$D7,$AD,$17,$8F,$4C,$AD,$57,$00,$00; $130
		.BYTE $00,$00,$3B,$4F,$4B,$8F,$5D,$4F,$6D,$8F,$4B,$CF,$BB,$4F,$00,$00; $140
		.BYTE $00,$00,$1B,$59,$3B,$D9,$CB,$59,$00,$00,$00,$00,$00,$00,$00,$00; $150
		.BYTE $00,$00,$58,$98,$FF,$94,$E9,$18,$FF,$54,$00,$00,$00,$00,$00,$00; $160
		.BYTE $00,$00,$69,$59,$B9,$46,$5B,$99,$B9,$86,$EB,$06,$1D,$C6,$00,$00; $170
		.BYTE $00,$00,$C5,$A1,$25,$A1,$8D,$9D,$25,$61,$D5,$61,$7D,$5D,$00,$00; $180
		.BYTE $00,$00,$EC,$BF,$FF,$D4,$FF,$94,$00,$00,$00,$00,$00,$00,$00,$00; $190
		.BYTE $00,$00,$68,$98,$A4,$85,$A8,$58,$35,$45,$94,$05,$64,$C5,$00,$00; $1A0
		.BYTE $00,$00,$D4,$85,$1D,$87,$BD,$87,$5D,$C7,$55,$45,$AD,$07,$00,$00; $1B0
		.BYTE $00,$00,$AB,$87,$1A,$47,$BB,$47,$2A,$C7,$00,$00,$00,$00,$00,$00; $1C0
		.BYTE $00,$00,$7D,$07,$64,$85,$6D,$C7,$6D,$87,$64,$45,$6D,$47,$00,$00; $1D0
		.BYTE $00,$00,$6D,$C7,$AD,$07,$6D,$47,$E3,$45,$34,$85,$00,$00,$00,$00; $1E0
		.BYTE $00,$00,$7D,$57,$8F,$0C,$8F,$4C,$8F,$8C,$8F,$CC,$BD,$97,$00,$00; $1F0
		.BYTE $00,$00,$4D,$17,$FF,$48,$FF,$48,$DD,$97,$2D,$D7,$FF,$48,$00,$00; $200
		.BYTE $00,$00,$6D,$D7,$8F,$4C,$8F,$0C,$8F,$CC,$8F,$8C,$4D,$57,$00,$00; $210
		.BYTE $00,$00,$7D,$57,$EB,$17,$5D,$D7,$3D,$97,$00,$00,$00,$00,$00,$00; $220
		.BYTE $00,$00,$BD,$3F,$FF,$48,$FF,$48,$FF,$48,$DD,$57,$ED,$97,$00,$00; $230
		.BYTE $00,$00,$9D,$97,$DB,$17,$7D,$57,$8F,$8C,$8F,$CC,$8F,$0C,$00,$00; $240
		.BYTE $00,$00,$BC,$5D,$2B,$5C,$7D,$9C,$2A,$DD,$00,$00,$00,$00,$00,$00; $250
		.BYTE $00,$00,$3C,$9C,$1A,$5C,$AD,$5D,$CB,$9D,$00,$00,$00,$00,$00,$00; $260
		.BYTE $00,$00,$1D,$9C,$8D,$9C,$EA,$1C,$AD,$5C,$00,$00,$00,$00,$00,$00; $270
		.BYTE $00,$00,$AD,$5E,$1A,$5D,$CB,$9E,$EA,$5D,$2A,$DD,$00,$00,$00,$00; $280
		.BYTE $00,$00,$4D,$6C,$6B,$AC,$1D,$DD,$1D,$5D,$8D,$5D,$3D,$5D,$00,$00; $290
		.BYTE $00,$00,$CD,$7F,$1B,$5D,$B8,$9C,$B8,$5C,$DD,$9D,$48,$DC,$00,$00; $2A0
		.BYTE $00,$00,$3D,$9A,$6D,$5A,$ED,$1D,$2D,$DD,$7B,$9C,$00,$00,$00,$00; $2B0
		.BYTE $00,$00,$1D,$BF,$28,$A1,$ED,$1D,$39,$61,$1A,$DD,$88,$9D,$00,$00; $2C0
		.BYTE $00,$00,$1D,$BF,$BD,$5A,$4D,$9D,$C9,$9A,$19,$5D,$00,$00,$00,$00; $2D0
		.BYTE $00,$00,$C9,$6C,$19,$5C,$89,$5C,$49,$9C,$A9,$9C,$19,$E1,$00,$00; $2E0
		.BYTE $00,$00,$A7,$61,$27,$5D,$C7,$21,$B8,$9D,$18,$E1,$00,$00,$00,$00; $2F0
		.BYTE $00,$00,$78,$44,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $300
		.BYTE $00,$00,$BD,$74,$99,$66,$ED,$26,$69,$A6,$1D,$E6,$CD,$B4,$00,$00; $310
		.BYTE $00,$00,$6D,$B8,$BD,$66,$19,$66,$E9,$A6,$00,$00,$00,$00,$00,$00; $320
		.BYTE $00,$00,$4D,$74,$DD,$26,$BD,$66,$CD,$A6,$2D,$E6,$8D,$B4,$00,$00; $330
		.BYTE $00,$00,$8D,$57,$8D,$97,$8F,$0C,$8F,$4C,$8F,$8C,$8F,$CC,$00,$00; $340
		.BYTE $00,$00,$B6,$45,$BD,$46,$24,$C6,$A5,$85,$6D,$86,$A6,$05,$00,$00; $350
		.BYTE $00,$00,$6D,$99,$45,$86,$7D,$59,$87,$46,$88,$06,$45,$C6,$00,$00; $360
		.BYTE $00,$00,$83,$8E,$89,$0F,$49,$CF,$83,$4E,$B9,$4F,$D8,$8F,$00,$00; $370
		.BYTE $00,$00,$88,$8E,$DD,$4F,$48,$0E,$ED,$0F,$7D,$8F,$2D,$CF,$00,$00; $380
		.BYTE $00,$00,$FF,$4B,$FF,$4B,$1D,$4F,$DD,$4F,$FD,$8F,$5D,$CF,$00,$00; $390
		.BYTE $00,$00,$3D,$84,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $3A0
		.BYTE $00,$00,$65,$C9,$45,$89,$45,$49,$95,$09,$FF,$4B,$00,$00,$00,$00; $3B0
		.BYTE $00,$00,$CD,$37,$AB,$4F,$19,$8F,$4D,$DB,$29,$4F,$7D,$4F,$00,$00; $3C0
		.BYTE $00,$00,$AF,$16,$EF,$56,$6F,$96,$2F,$D6,$85,$09,$85,$89,$00,$00; $3D0
		.BYTE $00,$00,$7C,$4E,$97,$0A,$C5,$0A,$C6,$4A,$C6,$0E,$14,$8A,$00,$00; $3E0
		.BYTE $00,$00,$8D,$47,$5D,$47,$BD,$07,$7D,$87,$BD,$87,$6D,$C7,$00,$00; $3F0
		.BYTE $00,$00,$35,$85,$C7,$45,$C3,$85,$8C,$85,$F4,$05,$18,$45,$00,$00; $400
		.BYTE $00,$00,$FF,$CD,$FF,$CD,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $410
		.BYTE $00,$00,$8C,$97,$59,$57,$8F,$8C,$8F,$0C,$8F,$4C,$8F,$CC,$00,$00; $420
		.BYTE $00,$00,$7D,$76,$B9,$4A,$38,$8A,$CA,$8A,$DA,$8A,$58,$CA,$00,$00; $430
		.BYTE $00,$00,$77,$8E,$B8,$0E,$85,$4E,$E6,$8E,$65,$CE,$00,$00,$00,$00; $440
		.BYTE $00,$00,$65,$89,$95,$09,$75,$49,$7D,$4F,$8D,$4F,$75,$C9,$00,$00; $450
		.BYTE $00,$00,$6F,$96,$EF,$56,$AF,$16,$2F,$D6,$A9,$4A,$C5,$8A,$00,$00; $460
		.BYTE $00,$00,$8F,$8C,$8F,$4C,$FA,$17,$69,$57,$8F,$CC,$1A,$D7,$00,$00; $470
		.BYTE $00,$00,$AD,$64,$CD,$82,$AD,$24,$3D,$E4,$00,$00,$00,$00,$00,$00; $480
		.BYTE $00,$00,$9D,$A4,$A9,$50,$1D,$50,$9D,$90,$00,$00,$00,$00,$00,$00; $490
		.BYTE $00,$00,$29,$A4,$9D,$65,$FD,$25,$39,$E4,$29,$64,$CD,$A5,$00,$00; $4A0
		.BYTE $00,$00,$1D,$B9,$3D,$64,$4D,$E5,$CD,$A5,$00,$00,$00,$00,$00,$00; $4B0
		.BYTE $00,$00,$35,$64,$A9,$64,$A9,$A4,$1D,$A4,$F5,$A4,$7D,$24,$00,$00; $4C0
		.BYTE $00,$00,$9D,$7F,$B6,$24,$1D,$72,$76,$64,$9D,$B2,$46,$E4,$00,$00; $4D0
		.BYTE $00,$00,$2D,$BF,$1D,$64,$7D,$64,$95,$65,$5D,$A5,$1D,$E5,$00,$00; $4E0
		.BYTE $00,$00,$B9,$64,$D5,$24,$1D,$64,$19,$E4,$2D,$A4,$85,$A4,$00,$00; $4F0
		.BYTE $00,$00,$AD,$B2,$66,$65,$B6,$25,$36,$E5,$5D,$72,$96,$A5,$00,$00; $500
		.BYTE $00,$00,$B6,$A4,$5D,$65,$9D,$A5,$1D,$E5,$46,$64,$8D,$25,$00,$00; $510
		.BYTE $00,$00,$1D,$B1,$A6,$24,$76,$64,$3D,$71,$86,$A4,$56,$E4,$00,$00; $520
		.BYTE $00,$00,$BD,$53,$9D,$11,$FD,$93,$4D,$91,$2D,$51,$2D,$D1,$00,$00; $530
		.BYTE $00,$00,$22,$FE,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $540
		.BYTE $00,$00,$DD,$BA,$8D,$53,$88,$53,$88,$93,$39,$D3,$00,$00,$00,$00; $550
		.BYTE $00,$00,$1D,$E3,$A7,$63,$E7,$27,$87,$A7,$ED,$27,$00,$00,$00,$00; $560
		.BYTE $00,$00,$1D,$BF,$ED,$AD,$DD,$2D,$2D,$67,$AD,$67,$00,$00,$00,$00; $570
		.BYTE $00,$00,$57,$FF,$FD,$A7,$87,$27,$27,$E7,$9D,$23,$87,$63,$00,$00; $580
		.BYTE $00,$00,$38,$7F,$7D,$73,$88,$67,$8D,$A7,$28,$F3,$BD,$27,$00,$00; $590
		.BYTE $00,$00,$77,$B3,$6D,$A3,$1D,$E3,$F7,$23,$ED,$23,$9D,$73,$00,$00; $5A0
		.BYTE $00,$00,$8D,$A3,$14,$52,$14,$D2,$5D,$63,$14,$92,$00,$00,$00,$00; $5B0
		.BYTE $00,$00,$57,$E7,$87,$A7,$37,$67,$8D,$6D,$7D,$AD,$00,$00,$00,$00; $5C0
		.BYTE $00,$00,$1D,$BF,$DA,$22,$49,$62,$8D,$62,$38,$A2,$C8,$A2,$00,$00; $5D0
		.BYTE $00,$00,$5D,$A2,$1B,$62,$BB,$22,$1D,$E2,$BD,$62,$00,$00,$00,$00; $5E0
		.BYTE $00,$00,$4C,$69,$DB,$28,$2A,$E9,$CC,$69,$7D,$A8,$FB,$A9,$00,$00; $5F0
		.BYTE $00,$00,$4D,$6B,$BD,$6A,$1B,$81,$EB,$AA,$4D,$EA,$AD,$2A,$00,$00; $600
		.BYTE $00,$00,$CD,$43,$9D,$C2,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $610
		.BYTE $00,$00,$3D,$C3,$BD,$44,$82,$3E,$00,$00,$00,$00,$00,$00,$00,$00; $620
		.BYTE $00,$00,$EE,$97,$EE,$17,$FF,$95,$FF,$95,$1D,$97,$00,$00,$00,$00; $630
		.BYTE $00,$00,$6C,$5C,$DB,$1D,$CB,$5D,$8B,$9C,$1A,$9C,$DB,$9D,$00,$00; $640
		.BYTE $00,$00,$6D,$9C,$CD,$1C,$7D,$5C,$BD,$5C,$6D,$9C,$6D,$DC,$00,$00; $650
		.BYTE $00,$00,$6D,$D7,$CD,$17,$FF,$55,$FF,$55,$7D,$97,$00,$00,$00,$00; $660
		.BYTE $00,$00,$6D,$9D,$BD,$9D,$1D,$5D,$CD,$5D,$6D,$DD,$00,$00,$00,$00; $670
		.BYTE $00,$00,$19,$9C,$D8,$9C,$1D,$DD,$28,$5C,$ED,$1D,$00,$00,$00,$00; $680
		.BYTE $00,$00,$7D,$E1,$ED,$9D,$4D,$61,$ED,$5D,$DD,$1D,$00,$00,$00,$00; $690
		.BYTE $00,$00,$8D,$9C,$1B,$9C,$5D,$5C,$5D,$DC,$00,$00,$00,$00,$00,$00; $6A0
		.BYTE $00,$00,$CD,$5D,$3D,$5D,$29,$5C,$39,$9C,$C9,$9C,$1D,$DD,$00,$00; $6B0
		.BYTE $00,$00,$BB,$9C,$9D,$5C,$1A,$DD,$EA,$5D,$3C,$9C,$EB,$1C,$00,$00; $6C0
		.BYTE $00,$00,$4D,$60,$5B,$A0,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $6D0
		.BYTE $00,$00,$5D,$F5,$88,$A0,$39,$60,$00,$00,$00,$00,$00,$00,$00,$00; $6E0
		.BYTE $00,$00,$9D,$A0,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $6F0
		.BYTE $00,$00,$6B,$1F,$8B,$9F,$1D,$70,$4B,$DF,$BB,$1F,$2B,$B0,$00,$00; $700
		.BYTE $00,$00,$48,$9F,$E8,$9F,$D8,$70,$19,$5F,$3D,$F0,$00,$00,$00,$00; $710
		.BYTE $00,$00,$CB,$9E,$1A,$DF,$EA,$5F,$3B,$5F,$AD,$5E,$6D,$1E,$00,$00; $720
		.BYTE $00,$00,$5D,$AE,$2B,$A9,$1D,$E9,$6B,$29,$FD,$2E,$00,$00,$00,$00; $730
		.BYTE $00,$00,$1D,$BF,$19,$69,$28,$A8,$9D,$A8,$DA,$29,$1A,$E8,$00,$00; $740
		.BYTE $00,$00,$3D,$68,$E9,$A9,$79,$6E,$49,$AE,$19,$69,$7D,$A8,$00,$00; $750
		.BYTE $00,$00,$E7,$2F,$1A,$A9,$DD,$A9,$78,$EF,$FB,$29,$00,$00,$00,$00; $760
		.BYTE $00,$00,$78,$44,$32,$FE,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $770
		.BYTE $00,$00,$4C,$A9,$EA,$68,$1A,$E9,$BB,$A8,$5D,$28,$FB,$29,$00,$00; $780
		.BYTE $00,$00,$8D,$BB,$2D,$E2,$FD,$22,$00,$00,$00,$00,$00,$00,$00,$00; $790
		.BYTE $00,$00,$8D,$A9,$6D,$A9,$7D,$E9,$DB,$29,$6D,$69,$9D,$69,$00,$00; $7A0
		.BYTE $00,$00,$F8,$A9,$77,$29,$1A,$91,$49,$91,$87,$69,$CD,$E8,$00,$00; $7B0
		.BYTE $00,$3C,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $7C0
		.BYTE $8D,$FD,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $7D0
		.BYTE $8D,$FD,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $7E0
		.BYTE $8D,$FD,$CD,$FE,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00,$00; $7F0
_obj_params_lib:
		.BYTE $F0,$EF,$00,$06,$00,$00,$80,$00	; $00
		.BYTE $F0,$D8,$00,$06,$00,$FF,$94,$00	; $01
		.BYTE $F0,$D8,$00,$06,$00,$FF,$94,$00	; $02
		.BYTE $F0,$D8,$00,$06,$00,$FF,$94,$00	; $03
		.BYTE $F0,$D8,$00,$06,$00,$FF,$94,$00	; $04
		.BYTE $F0,$2F,$00,$03,$04,$01,$14,$00	; $05
		.BYTE $F0,$FF,$00,$03,$04,$02,$14,$00	; $06
		.BYTE $F0,$AF,$00,$03,$04,$04,$15,$00	; $07
		.BYTE $F0,$28,$00,$00,$04,$FF,$94,$00	; $08
		.BYTE $F0,$2F,$00,$03,$08,$04,$15,$00	; $09
		.BYTE $F0,$EF,$00,$03,$14,$FF,$19,$00	; $0A
		.BYTE $F0,$2F,$00,$03,$08,$0C,$17,$00	; $0B
		.BYTE $F0,$2F,$00,$03,$04,$02,$14,$00	; $0C
		.BYTE $F0,$28,$00,$0C,$14,$FF,$9A,$00	; $0D
		.BYTE $F0,$AF,$00,$02,$08,$04,$15,$00	; $0E
		.BYTE $F0,$FF,$00,$00,$04,$02,$14,$00	; $0F
		.BYTE $F0,$3F,$00,$03,$18,$FF,$14,$00	; $10
		.BYTE $F0,$3F,$00,$02,$24,$02,$89,$00	; $11
		.BYTE $F0,$3F,$00,$03,$1C,$02,$14,$00	; $12
		.BYTE $F0,$E8,$00,$03,$1C,$60,$1A,$00	; $13
		.BYTE $F0,$28,$00,$03,$08,$FF,$98,$00	; $14
		.BYTE $F0,$EF,$00,$01,$0C,$FF,$97,$00	; $15
		.BYTE $F0,$28,$00,$00,$08,$06,$16,$00	; $16
		.BYTE $F0,$EF,$00,$05,$08,$06,$16,$00	; $17
		.BYTE $F0,$EF,$00,$09,$10,$18,$18,$00	; $18
		.BYTE $F0,$EF,$00,$0C,$04,$04,$15,$00	; $19
		.BYTE $F0,$EF,$00,$0C,$0C,$06,$16,$00	; $1A
		.BYTE $F0,$D8,$00,$01,$00,$FF,$94,$00	; $1B
		.BYTE $F0,$EF,$00,$06,$0C,$06,$16,$00	; $1C
		.BYTE $F0,$EF,$00,$06,$0C,$06,$16,$00	; $1D
		.BYTE $F0,$EF,$00,$06,$0C,$0C,$17,$00	; $1E
		.BYTE $F0,$EF,$00,$06,$10,$0C,$17,$00	; $1F
		.BYTE $F0,$D8,$00,$06,$00,$FF,$94,$00	; $20
		.BYTE $F0,$EF,$00,$06,$0C,$0C,$17,$00	; $21
		.BYTE $F0,$EF,$00,$06,$20,$C0,$1B,$00	; $22
		.BYTE $F0,$EF,$00,$06,$1C,$60,$1A,$00	; $23
		.BYTE $F0,$EF,$00,$06,$18,$30,$0C,$00	; $24
		.BYTE $F0,$EF,$00,$06,$18,$30,$19,$00	; $25
		.BYTE $F0,$EF,$00,$06,$10,$0C,$17,$00	; $26
		.BYTE $F0,$EF,$00,$06,$1C,$60,$1A,$00	; $27
		.BYTE $F0,$EF,$00,$06,$20,$C0,$1B,$00	; $28
		.BYTE $F0,$EF,$00,$06,$20,$C0,$1B,$00	; $29
		.BYTE $F0,$EF,$00,$06,$0C,$0C,$17,$00	; $2A
		.BYTE $F0,$EF,$00,$06,$0C,$18,$98,$00	; $2B
		.BYTE $F0,$EF,$00,$7A,$0C,$18,$18,$00	; $2C
		.BYTE $F0,$EF,$00,$09,$1C,$C0,$1B,$00	; $2D
		.BYTE $F0,$EF,$00,$06,$20,$FF,$1C,$00	; $2E
		.BYTE $F0,$EF,$00,$07,$20,$FF,$1C,$00	; $2F
		.BYTE $F0,$EF,$00,$06,$10,$18,$98,$00	; $30
		.BYTE $F0,$EF,$00,$0B,$18,$60,$0D,$00	; $31
		.BYTE $F0,$EF,$00,$09,$18,$60,$0E,$00	; $32
		.BYTE $F0,$EF,$00,$05,$1C,$C0,$1B,$00	; $33
		.BYTE $F0,$EF,$00,$06,$10,$18,$18,$00	; $34
		.BYTE $F0,$D8,$00,$06,$00,$FF,$80,$00	; $35
		.BYTE $F0,$EF,$00,$0C,$14,$10,$9B,$00	; $36
		.BYTE $F0,$EF,$0B,$CF,$08,$10,$9A,$00	; $37
		.BYTE $F0,$EF,$0B,$0E,$10,$10,$9B,$00	; $38
		.BYTE $F0,$2F,$00,$DA,$18,$10,$9C,$00	; $39
		.BYTE $F0,$EF,$00,$46,$1C,$10,$9C,$00	; $3A
		.BYTE $F0,$EF,$00,$06,$20,$10,$9C,$00	; $3B
		.BYTE $F0,$00,$00,$00,$00,$FF,$14,$00	; $3C
		.BYTE $F0,$00,$00,$0C,$00,$10,$14,$00	; $3D
		.BYTE $F0,$3F,$00,$0E,$00,$10,$94,$00	; $3E
		.BYTE $F0,$0C,$00,$03,$00,$01,$94,$00	; $3F

		SECTION_END "GAME DATA"

		SECTION_START
		INCLUDE "..\sprites.inc"
		SECTION_END "SPRITES DATA"

		SECTION_START

; =============== S U B	R O U T	I N E =======================================
_objA_manager:
		JSR		_obj_special_bonus_test_handler
		JSR		_obj_rambo_shout_deploy_test
		LDA		#$00
		STA		_tmp14

; =============== S U B	R O U T	I N E =======================================
_objects_manager_loop:
		LDA		_tmp14
		ASL
		ASL
		ASL
		ASL
		TAX
		LDA		_objsA._player._hndl_idx,X
		BMI		_obj_handler_continue
		AND		#$3F
		ASL
		TAY
		LDA		_obj_hndl_lib,Y
		STA		_tmp00
		LDA		_obj_hndl_lib+1,Y
		STA		_tmp01
		JSR		_cur_obj_load
		CPX		#$00
		BEQ		loc_51FE7
		LDA		_objsA._player._prize_idx,X
		BMI		loc_51FE7
		JSR		_obj_sub52085
		BCS		_obj_flush_and_continue
loc_51FE7:
		JMP		(_tmp00)

; =============== S U B	R O U T	I N E =======================================
_obj_flush_and_continue:
		JSR		_cur_obj_flush

; =============== S U B	R O U T	I N E =======================================
_obj_handler_continue:
		INC		_tmp14
		LDA		_tmp14
		CMP		#$08
		BNE		_objects_manager_loop
		RTS

; =============== S U B	R O U T	I N E =======================================
_cur_obj_load:
		LDA		_objsA._player._anim_phase_cnt,X
		LSR
		LSR
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
_cur_obj_flush:
		LDA		_tmp0F
		ASL
		ASL
		ASL
		ASL
		ORA		_tmp10
		STA		_objsA._player._anim_phase_cnt,X
		CPX		#$00
		BEQ		loc_52031
		LDA		_tmp0C
		AND		#$03
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
_obj_get_hor_delta16:
		LDA		_tmp11
		EOR		_tmp12
		ASL
		ASL
		BCC		locret_52075
		LDA		#$40
		BIT		_tmp11
		BNE		loc_52068
		SEC
		LDA		_tmp0D
		SBC		#$0F
		STA		_tmp0D
		LDA		_tmp0C
		SBC		#$00
		STA		_tmp0C
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
_rand:
		LDY		_rand_seed
		LDA		_objA_manager,Y
		ADC		_rand_seed
		STA		_tmp13
		INC		_rand_seed
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_sub52085:
		JSR		_obj_sub52099
		LDA		_objsA._player.field_C,X
		BEQ		loc_52097
		JSR		_obj_sub5214B
		LDA		_tmp11
		AND		#$20
		BNE		loc_52097
		CLC
		RTS
loc_52097:
		SEC
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_sub52099:
		LDA		_objsA._player.field_C,X
		BNE		locret_52107
		LDA		#$3F
		STA		_objsA._player._hndl_idx,X
		LDA		#$F0
		STA		_objsA._player._anim_phase_idx,X
		LDA		#$01
		STA		_tmp0B
		LDA		_objsA._player.field_9,X
		AND		#$0F
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
		LDA		#$00
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
		JSR		_objB_prize_insert
		LDA		#$80
		STA		_objsA._player._prize_idx,X
locret_52107:
		RTS

; =============== S U B	R O U T	I N E =======================================
_objB_prize_insert:
		TXA
		PHA
		LDA		#$04
		STA		_tmp08
loc_5210E:
		LDA		_tmp08
		ASL
		ASL
		ASL
		TAX
		LDA		_objsB,X
		BPL		loc_52140
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
		JMP		loc_52148
loc_52140:
		INC		_tmp08
		LDA		_tmp08
		CMP		#$0C
		BNE		loc_5210E
loc_52148:
		PLA
		TAX
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_sub5214B:
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
		LDA		_objsA,X
		AND		#$3F
		CMP		#$3A
		BEQ		loc_52173
		CMP		#$3B
		BEQ		loc_52173
		CMP		#$1C
		BCC		loc_52177
		CMP		#$2A
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
		LDA		_objsA,X
		AND		#$3F
		CMP		#$1C
		BCC		locret_52198
		CMP		#$2A
		BCS		locret_52198
		LDA		#$00
		STA		_tmp0B
locret_52198:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_prize_deploy_ex:
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
		SEC
		LDA		_tmp0D
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
		JSR		_objB_prize_apu_select
		JMP		_objB_prize_insert

; =============== S U B	R O U T	I N E =======================================
_objB_prize_apu_select:
		LDA		_tmp00
		CMP		#$09
		BCC		loc_521E5
		LDA		#$00
		STA		_tmp13
		RTS
loc_521E5:
		TAY
		LDA		_prize_apu_list,Y
		STA		_tmp13
		RTS
; ---------------------------------------------------------------------------
_prize_apu_list:
		.BYTE $02,$02,$05,$05,$03,$01,$01,$00,$06

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
		SEC
		LDA		_tmp0D
		SBC		#$80
		STA		_tmp0D
		LDA		_tmp0C
		SBC		#$00
		STA		_tmp0C
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

; =============== S U B	R O U T	I N E =======================================
_obj_jump_animate_test_ex:
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
		JMP		_obj_flush_and_continue

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
		LDA		#$3F
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
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_special_bonus_test_handler:
		LDA		_game._scr_idx
		BMI		locret_52332
		LDA		_objsA._o1._prize_idx
		CMP		#$9F
		BEQ		locret_52332
		LDA		_game._play_minutes
		AND		#$0F
		BNE		locret_52332
		LDA		_cur_level_chr_idx
		AND		#$F0
		CMP		#$20
		BEQ		loc_52313
		CMP		#$60
		BEQ		loc_52313
		CMP		#$80
		BEQ		loc_52313
		RTS
loc_52313:
		INC		_game._play_minutes
		LDA		_objsA._o1._hndl_idx
		BPL		locret_52332
		LDX		#$00
		LDY		#$10
loc_5231E:
		LDA		_obj_data_special,X
		STA		_objsA._player._hndl_idx,Y
		INX
		INY
		CPY		#$20
		BNE		loc_5231E
		LDA		_objsA._player._room_num
		STA		_objsA._o1._room_num
		LDA		_objsA._player._x_pos
		STA		_objsA._o1._x_pos
locret_52332:
		RTS
; ---------------------------------------------------------------------------
_obj_data_special:
		.BYTE $3F,$F5,$00,$00,$80,$20,$00,$18,$00,$03,$00,$00,$00,$03,$9F,$00

; =============== S U B	R O U T	I N E =======================================
_obj_rambo_shout_deploy_test:
		LDA		_objsA._player._hndl_idx
		BMI		locret_52361
		LDA		_game._scr_idx
		CMP		#$62
		BEQ		loc_52357
		CMP		#$0B
		BNE		locret_52361
		LDA		_obj_heli_tmp_flag
		BEQ		locret_52361
loc_52357:
		LDA		_game._flags
		AND		#$40
		BNE		loc_52362
locret_52361:
		RTS
loc_52362:
		LDA		_objsA._o6._hndl_idx
		BPL		loc_523B0
		LDA		_pad
		AND		#$40
		BNE		loc_52370
		RTS
loc_52370:
		LDX		#$00
		LDY		#$60
loc_52374:
		LDA		_obj_data_rambo_shout,X
		STA		_objsA,Y
		INX
		INY
		CPY		#$70
		BNE		loc_52374
		LDA		_objsA._player._dir
		AND		#$40
		BEQ		loc_52396
		SEC
		LDA		_objsA._player._x_pos
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
		SEC
		LDA		_objsA._player._y_pos
		SBC		#$10
		STA		_objsA._o6._y_pos
		LDA		_objsA._player._dir
		AND		#$40
		LSR
		LSR
		LSR
		ORA		#$80
		STA		_objsA._o6._dir
loc_523B0:
		LDA		_game._scr_idx
		CMP		#$62
		BNE		locret_523F6
		LDA		#$40
		STA		_objsA._o6._anim_phase_cnt
		LDA		_objsA._o6._dir
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
		LDA		_objsA._o1._dir
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
		JSR		_obj_col_testB_calcF
		LDA		_tmp16
		BEQ		locret_523F6
		LDA		#$F2
		STA		_objsA._o1._anim_phase_idx
locret_523F6:
		RTS
; ---------------------------------------------------------------------------
_obj_data_rambo_shout:
		.BYTE $3F,$F6,$00,$00,$00,$00,$80,$00,$00,$00,$00,$00,$00,$04,$9F,$00

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
_obj_hndl_lib:
		.WORD _obj_hndl00_rambo
		.WORD _obj_hndl01_npcA
		.WORD _obj_hndl02_npcB
		.WORD _obj_hndl03_npcC
		.WORD _obj_hndl04_npcD
		.WORD _obj_hndl05_bee
		.WORD _obj_hndl06_snake
		.WORD _obj_hndl07_fish
		.WORD _obj_hndl08_bubbles
		.WORD _obj_hndl09_ceiling_bat
		.WORD _obj_hndl0A_stalaktit
		.WORD _obj_hndl0B_skull
		.WORD _obj_hndl0C_bird
		.WORD _obj_hndl0D_waterfall_logs
		.WORD _obj_hndl0E_small_bat
		.WORD _obj_hndl0F_spider
		.WORD _obj_hndl10_floor_turret
		.WORD _obj_hndl11_landmine
		.WORD _obj_hndl12_ceiling_turret
		.WORD _obj_hndl13_jumping_ball
		.WORD _obj_hndl14_rocks
		.WORD _obj_hndl15_grenades
		.WORD _obj_hndl16_cobra
		.WORD _obj_hndl17_pelikan
		.WORD _obj_hndl18_gorilla
		.WORD _obj_hndl19_tiger
		.WORD _obj_hndl19_tiger
		.WORD _obj_hndl1B_kid
		.WORD _obj_hndl1C_soldierA
		.WORD _obj_hndl1D_soldierB
		.WORD _obj_hndl1D_soldierB
		.WORD _obj_hndl1D_soldierB
		.WORD _obj_hndl20_torture_room_soldier
		.WORD _obj_hndl1C_soldierA
		.WORD _obj_hndl1D_soldierB
		.WORD _obj_hndl23_soldierC
		.WORD _obj_hndl1D_soldierB
		.WORD _obj_hndl1D_soldierB
		.WORD _obj_hndl26_grenade_soldier
		.WORD _obj_hndl1D_soldierB
		.WORD _obj_hndl1D_soldierB
		.WORD _obj_hndl1D_soldierB
		.WORD _obj_hndl2A_pirate
		.WORD _obj_hndl2B_boss_pirate
		.WORD _obj_hndl2C_dubina_man
		.WORD _obj_hndl2D_spectre
		.WORD _obj_hndl2E_armored_man
		.WORD _obj_hndl2F_strong_man
		.WORD _obj_hndl30_burning_man
		.WORD _obj_hndl31_machete_man
		.WORD _obj_hndl32_skull_monkey
		.WORD _obj_hndl33_shield_man
		.WORD _obj_hndl34_crouching_bomb_man
		.WORD _obj_hndl35_guard_of_torture_room
		.WORD _obj_hndl36_boss_fire_tiger
		.WORD _obj_hndl37_boss_spider
		.WORD _obj_hndl38_boss_motorcycle
		.WORD _obj_hndl39_boss_drone
		.WORD _obj_hndl3A_boss_yusin
		.WORD _obj_hndl3B_boss_padovski
		.WORD _obj_hndl3C_plane
		.WORD _obj_hndl3D_helicopterA
		.WORD _obj_hndl3E_helicopterB
		.WORD _obj_hndl3F_multipurpose

; =============== S U B	R O U T	I N E =======================================
_obj_hndl01_talk_idx_select:
		LDA		_pad
		AND		#$08
		BEQ		locret_524C9
		LDA		_objsA._player._state,X
		BPL		locret_524C9
		LDA		_game._scr_idx
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
		LDA		_game._scr_idx
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
		LDA		_game._scr_idx
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
		LDA		_game._scr_idx
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
		LDA		_game._scr_idx
		CMP		#$6F
		BNE		locret_52559
		LDA		#$91
locret_52559:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_hndl01_npcA:
		CPX		#$00
		BNE		loc_52561
		JMP		_player_control_co
loc_52561:
		LDA		_game._scr_idx
		CMP		#$0A
		BNE		loc_52572
		LDA		_game._flags+1
		AND		#$02
		BEQ		loc_52572
		JMP		_player_control_co
loc_52572:
		LDA		_game._scr_idx
		CMP		#$06
		BNE		loc_52586
		LDA		_game._flags+1
		AND		#$02
		BEQ		loc_52583
		JMP		_player_control_co
loc_52583:
		JMP		_obj_kill_and_continue
loc_52586:
		JSR		_obj_hndl01_talk_idx_select
		JMP		_obj_npc_dialog_start

; =============== S U B	R O U T	I N E =======================================
_obj_hndl02_npcB:
		CPX		#$00
		BNE		loc_52593
		JMP		_player_control_co
loc_52593:
		LDA		_game._flags+1
		AND		#$02
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
		LDA		_game._flags
		AND		#$40
		BEQ		loc_525C5
		JMP		_player_control_co
loc_525C5:
		LDA		_game._flags
		AND		#$40
		BNE		loc_525D6
		LDA		_game._scr_idx
		CMP		#$62
		BNE		loc_525D6
		JMP		_obj_kill_and_continue
loc_525D6:
		LDA		_game._scr_idx
		CMP		#$0B
		BNE		loc_525EA
		LDA		_game._flags
		AND		#$40
		BEQ		loc_525E7
		JMP		_player_control_co
loc_525E7:
		JMP		_obj_kill_and_continue
loc_525EA:
		JSR		_obj_hndl04_talk_idx_select
		JMP		_obj_npc_dialog_start

; =============== S U B	R O U T	I N E =======================================
_obj_hndl20_torture_room_soldier:
		JSR		_obj_hndl20_talk_idx_select

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
		LDA		_objsA,X
		AND		#$3F
		CMP		#$03
		BNE		loc_5263F
		LDA		_game._flags
		AND		#$40
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
		JMP		loc_526B9
loc_526B9:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl05_bee:
		JSR		_obj_to_player_lock
		BCS		loc_526C4
		JMP		_obj_flush_and_continue
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
		JMP		_obj_flush_and_continue
loc_5273D:
		LDA		_objsA._player._x_pos
		AND		#$E0
		CMP		_tmp0D
		BEQ		loc_5274E
		LDA		_objsA._player._y_pos
		CMP		_tmp0E
		BCC		loc_5274E
		JMP		_obj_flush_and_continue
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
		LDA		_tmp11
		ORA		#$04
		STA		_tmp11
		LDA		#$01
		STA		_tmp0B
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
		JMP		_obj_flush_and_continue
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
		STA		_tmp01
		LDA		#$03
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		#$03
		STA		_tmp10
		LDA		#$00
		STA		_tmp0F
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
		JSR		_obj_get_hor_delta16
		JMP		_obj_flush_and_continue

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
		JSR		_obj_get_hor_delta16
loc_52864:
		JMP		_obj_flush_and_continue

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
		JMP		_obj_flush_and_continue
loc_52881:
		LDA		_objsA._player._x_pos
		AND		#$F0
		CMP		_tmp0D
		BEQ		loc_5288C
		JMP		_obj_flush_and_continue
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
		JSR		_obj_get_hor_delta16
loc_5294A:
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl0C_bird:
		JSR		_obj_to_player_lock
		BCS		loc_52955
		JMP		_obj_flush_and_continue
loc_52955:
		LDA		#$03
		STA		_tmp01
		LDA		#$03
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
		JMP		_obj_flush_and_continue
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
		STA		_tmp01
		LDA		#$03
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		#$03
		STA		_tmp10
		LDA		#$00
		STA		_tmp0F
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
		JSR		_obj_get_hor_delta16
loc_52A1C:
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl0E_small_bat:
		JSR		_obj_to_player_lock
		BCS		loc_52A27
		JMP		_obj_flush_and_continue
loc_52A27:
		LDA		#$02
		STA		_tmp01
		LDA		#$02
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		_tmp11
		AND		#$10
		BEQ		loc_52A3B
		JMP		_obj_flush_and_continue
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
		JMP		_obj_flush_and_continue

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
		JSR		_obj_get_hor_delta16
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
		LDA		#$07
		STA		_tmp00
		JSR		_obj_prize_deploy_ex
loc_52AFB:
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl11_landmine:
		JSR		_obj_sub52085
		BCC		loc_52B08
		LDA		#$07
		STA		_apu_se_noise_idx
loc_52B08:
		JMP		_obj_flush_and_continue

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
		JSR		_obj_get_hor_delta16
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
		LDA		#$07
		STA		_tmp00
		JSR		_obj_prize_deploy_ex
loc_52B52:
		JMP		_obj_flush_and_continue

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
		JSR		_obj_get_hor_delta16
		JMP		_obj_flush_and_continue

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
		JSR		_obj_get_hor_delta16
		JMP		_obj_flush_and_continue

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
		LDA		#$07
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
		LDA		_objsA,X
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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
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
		JSR		_obj_get_hor_delta16
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_prize_deployA:
		LDA		#$08
		STA		_tmp02
		LDA		#$40
		STA		_tmp06
		LDA		#$07
		STA		_tmp00
		JMP		_obj_prize_deploy_ex

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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
		BNE		loc_52E63
loc_52E52:
		JMP		_obj_jump_animate_test_right
loc_52E55:
		JMP		_obj_jump_animate_test_left
loc_52E58:
		LDA		#$00
		STA		_tmp0B
		LDA		#$09
		STA		_objsA._player.field_9,X
		JMP		_obj_jump_animate_test
loc_52E63:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl19_tiger:
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
		LDA		_game._flags
		AND		#$14
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
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl1C_soldierA:
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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
loc_52FB1:
		DEC		_objsA._player._timer,X
		BEQ		loc_52FBC
		LDA		#$04
		STA		_tmp0B
		JMP		_obj_flush_and_continue
loc_52FBC:
		LDA		_tmp11
		AND		#$F0
		STA		_tmp11
		JMP		_obj_flush_and_continue
loc_52FC5:
		JMP		_obj_jump_animate_test_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl26_grenade_soldier:
		LDA		_game._flags+1
		AND		#$10
		BEQ		_obj_hndl1D_soldierB
		LDA		#$20
		STA		_objsA._player._hndl_idx,X
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl1D_soldierB:
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
		LDA		_objsA._player._dir
		AND		#$04
		BNE		loc_530F2
		LDA		_game._play_hours
		CMP		#$04
		BCC		locret_530F5
		CMP		#$15
		BCS		locret_530F5
loc_530F2:
		JSR		_obj_extra_enemy_insert
locret_530F5:
		RTS

; =============== S U B	R O U T	I N E =======================================
_obj_extra_enemy_insert:
		TXA
		PHA
		TYA
		PHA
		LDA		_objsA._o4._hndl_idx
		BPL		loc_5310E
		LDY		#$40
loc_53100:
		LDA		_objsA._player._hndl_idx,X
		STA		_objsA._player._hndl_idx,Y
		INX
		INY
		CPY		#$50
		BNE		loc_53100
		BEQ		loc_53122
loc_5310E:
		LDA		_objsA._o6._hndl_idx
		BPL		loc_53156
		LDY		#$60
loc_53114:
		LDA		_objsA._player._hndl_idx,X
		STA		_objsA._player._hndl_idx,Y
		INX
		INY
		CPY		#$70
		BNE		loc_53114
		JMP		loc_53122
loc_53122:
		LDA		_objsA._player._room_num
		CMP		#$02
		BCS		loc_5313A
		LDA		#$03
		STA		_tobjA._room_num+$10,Y
		LDA		#$C0
		STA		_tobjA._x_pos+$10,Y
		LDA		#$D0
		STA		_tobjA._y_pos+$10,Y
		BNE		loc_53149
loc_5313A:
		LDA		#$00
		STA		_tobjA._room_num+$10,Y
		LDA		#$40
		STA		_tobjA._x_pos+$10,Y
		LDA		#$D0
		STA		_tobjA._y_pos+$10,Y
loc_53149:
		LDA		#$15
		STA		_tobjA._prize_idx+$10,Y
		LDA		#$04
		STA		_tobjA._damage+$10,Y
		STA		_tobjA.field_C+$10,Y
loc_53156:
		PLA
		TAY
		PLA
		TAX
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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
		JSR		_obj_player_rand_timer_set
		JMP		_obj_flush_and_continue
loc_53197:
		LDA		#$04
		STA		_tmp0B
		LDA		_tmp09
		STA		_objsA._player.field_9,X
		LDA		_objsA._player._hndl_idx,X
		AND		#$3F
		CMP		#$28
		BCC		loc_531BA
		LDA		_pad
		AND		#$04
		BEQ		loc_531BA
		LDA		#$05
		STA		_tmp0B
		LDA		#$04
		STA		_objsA._player.field_9,X
		LDA		#$08
		STA		_tmp0A
loc_531BA:
		LDA		_objsA._player._timer,X
		CMP		#$08
		BNE		loc_531C3
		JSR		_obj_prize_deployB
loc_531C3:
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_prize_deployB:
		LDA		#$10
		STA		_tmp02
		LDA		_tmp0A
		STA		_tmp03
		LDA		_objsA._player._hndl_idx,X
		AND		#$3F
		CMP		#$26
		BEQ		loc_531E5
		CMP		#$27
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
		LDA		#$05
		BNE		loc_53202
loc_531FA:
		LDA		#$40
		STA		_tmp06
		LDA		#$08
loc_53202:
		STA		_tmp00
		JMP		_obj_prize_deploy_ex

; =============== S U B	R O U T	I N E =======================================
_obj_hndl2B_boss_pirate:
		LDA		_game._bosses
		AND		#$40
		BEQ		loc_53210
		JMP		_obj_kill_and_continue
loc_53210:
		JSR		_obj_sub52085
		BCC		_obj_hndl2A_pirate
		LDA		_objsA._player.field_C,X
		BNE		loc_53221
		LDA		_game._bosses
		ORA		#$40
		STA		_game._bosses
loc_53221:
		JMP		_obj_flush_and_continue

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
		LDA		#$01
		STA		_tmp0F
		LDA		#$02
		BNE		loc_53273
loc_53267:
		LDA		#$01
		STA		_tmp0F
		LDA		#$01
		BNE		loc_53273
loc_53272:
		LDA		#$00
		STA		_tmp0B
		JMP		_obj_jump_animate_test
loc_53273:
		STA		_tmp0B
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
		JSR		_obj_get_hor_delta16
		LDA		#$18
		STA		_tmp0A
		JSR		_obj_prize_deployB
		JMP		_obj_flush_and_continue

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
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl2D_spectre:
		LDA		#$01
		STA		_tmp01
		LDA		#$0B
		STA		_tmp03
		LDA		#$00
		STA		_tmp00
		LDA		#$01
		STA		_tmp02
		LDA		_tmp10
		BNE		loc_53339
		LDA		#$00
		STA		_tmp0B
		LDA		#$09
		STA		_objsA._player.field_9,X
		DEC		_objsA._player._timer,X
		BNE		loc_53350
		LDA		#$01
		STA		_tmp0B
		LDA		#$0A
		STA		_objsA._player.field_9,X
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
		JMP		_obj_flush_and_continue

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
		JMP		_obj_flush_and_continue
loc_53381:
		LDA		#$00
		STA		_tmp0B
		JMP		_obj_flush_and_continue
loc_53388:
		LDA		#$01
		STA		_tmp0B
		LDA		#$01
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
		JMP		_obj_flush_and_continue
loc_533A5:
		LDA		#$03
		STA		_tmp0B
		LDA		#$00
		STA		_tmp0F
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
		LDA		#$10
		STA		_tmp02
		STA		_tmp03
		LDA		#$30
		STA		_tmp06
		LDA		#$07
		STA		_tmp00
		JSR		_obj_prize_deploy_ex
		JMP		_obj_flush_and_continue

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
		LDA		#$00
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
		STA		_objsA._player.field_9,X
		BNE		loc_53445
loc_53418:
		LDA		#$02
		STA		_tmp0F
		LDA		#$02
		STA		_tmp0B
		LDA		#$28
		STA		_objsA._player.field_8,X
		LDA		#$27
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
loc_53445:
		JMP		_obj_jump_animate_test_ex
loc_53448:
		JMP		_obj_flush_and_continue

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
		JSR		_obj_sub52099
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
		JSR		_obj_get_hor_delta16
loc_53485:
		JMP		_obj_flush_and_continue
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
		JSR		_obj_get_hor_delta16

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
		LDA		#$07
		STA		_tmp00
		JSR		_obj_prize_deploy_ex
		PLA
		STA		_tmp11
		JMP		_obj_flush_and_continue

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
		JSR		_obj_get_hor_delta16
		LDA		#$00
		STA		_tmp0B
		JMP		_obj_flush_and_continue

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
		JMP		loc_53553
loc_53553:
		LDA		#$09
		STA		_tmp10
		LDA		#$02
		STA		_tmp0F
		JSR		_cur_obj_direction_up_set
		LDA		#$02
		STA		_tmp0B
		LDA		#$0A
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
		LDA		#$01
		STA		_tmp0F
		LDA		#$01
		STA		_tmp0B
		JMP		_obj_jump_animate_test_ex
loc_5359B:
		LDA		#$09
		STA		_objsA._player.field_9,X
		LDA		#$00
		STA		_tmp0F
		LDA		#$00
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
		STA		_objsA._player.field_9,X
		LDA		#$00
		BEQ		loc_5360B
loc_535E9:
		LDA		#$05
		STA		_objsA._player.field_9,X
		LDA		#$02
		BNE		loc_5360B
loc_535F4:
		LDA		#$02
		STA		_tmp0B
		LDA		#$04
		STA		_objsA._player.field_9,X
		LDA		#$00
		BEQ		loc_5360B
loc_53603:
		LDA		#$05
		STA		_objsA._player.field_9,X
		LDA		#$00
loc_5360B:
		STA		_tmp0F
		LDA		#$10
		STA		_objsA._player._timer,X
loc_5360F:
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
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
		LDA		#$08
		STA		_tmp00
		JSR		_obj_prize_deploy_ex
loc_53632:
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl34_crouching_bomb_man:
		LDA		_game._flags+1
		AND		#$10
		BEQ		loc_53643
		LDA		#$35
		STA		_objsA._player._hndl_idx,X
		JMP		_obj_flush_and_continue
loc_53643:
		JSR		_obj_sub52085
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
		STA		_objsA._player.field_9,X
		BNE		loc_53675
loc_53671:
		LDA		#$04
		STA		_objsA._player.field_9,X
loc_53675:
		LDA		#$10
		STA		_objsA._player._timer,X
loc_53679:
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
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
		LDA		#$06
		STA		_tmp00
		JSR		_obj_prize_deploy_ex
loc_5369C:
		JMP		_obj_flush_and_continue

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
		JSR		_obj_get_hor_delta16
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl36_boss_fire_tiger:
		LDA		_game._bosses
		AND		#$01
		BEQ		loc_536E3
		JMP		_obj_kill_and_continue
loc_536E3:
		JSR		_obj_sub52085
		BCC		loc_536F7
		LDA		_objsA._player.field_C,X
		BNE		loc_536F4
		LDA		_game._bosses
		ORA		#$01
		STA		_game._bosses
loc_536F4:
		JMP		_obj_flush_and_continue
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
		LDA		#$00
		STA		_tmp0B
loc_53767:
		JSR		_obj_move_animate_common
		JSR		_obj_get_hor_delta16
		LDA		_objsA._player._timer,X
		AND		#$07
		BNE		loc_53776
		JMP		_obj_prize_deployC
loc_53776:
		JMP		_obj_flush_and_continue

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
		JSR		_obj_sub52085
		BCC		loc_537A3
		LDA		_objsA._player.field_C,X
		BNE		loc_5379D
		LDA		_game._bosses
		ORA		#$02
		STA		_game._bosses
loc_5379D:
		JSR		_obj_adjust_field_7
		JMP		_obj_flush_and_continue
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
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_hndl38_boss_motorcycle:
		LDA		_game._bosses
		AND		#$04
		BEQ		loc_53827
		JMP		_obj_kill_and_continue
loc_53827:
		JSR		_obj_sub52085
		BCC		loc_5383E
		LDA		_objsA._player.field_C,X
		BNE		loc_53838
		LDA		_game._bosses
		ORA		#$04
		STA		_game._bosses
loc_53838:
		JSR		_obj_adjust_field_7
		JMP		_obj_flush_and_continue
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
		STA		_objsA._player.field_9,X
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
		STA		_objsA._player.field_9,X
		BNE		loc_53887
loc_53884:
		JSR		_obj_hor_targeting_to_player_common
loc_53887:
		JSR		_obj_move_animate_common
		LDA		#$20
		STA		_tmp0A
		JSR		_obj_sub53EBA
		JMP		_obj_flush_and_continue

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
		JSR		_obj_sub52085
		BCC		loc_538C9
		LDA		_objsA._player.field_C,X
		BNE		loc_538C3
		LDA		_game._bosses
		ORA		#$08
		STA		_game._bosses
loc_538C3:
		JSR		_obj_drone_proj_adjust_vert
		JMP		_obj_flush_and_continue
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
		LDA		_objsA,X
		AND		#$40
		BNE		loc_538F2
		LDA		_objsA._player.field_2,X
		CMP		#$0F
		BEQ		loc_5393D
		BNE		loc_538FA
loc_538F2:
		LDA		#$00
		STA		_tmp0B
		LDA		#$00
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
		JMP		_obj_flush_and_continue
loc_5393D:
		LDA		#$10
		STA		_tmp02
		LDA		#$08
		STA		_tmp03
		LDA		_objsA,X
		STA		_tmp00
		LDA		#$04
		STA		_tmp05
		LDA		#$01
		STA		_tmp07
		LDA		#$03
		STA		_tmp04
		JSR		_obj_boss_projectile_insert
		JMP		_obj_flush_and_continue

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
		LDA		_game._flags+2
		AND		#$01
		BNE		loc_5397F
		JMP		_obj_kill_and_continue
loc_5397F:
		JSR		_obj_sub52085
		BCC		loc_53999
		JSR		_obj_hor_targeting_to_player_common
		LDA		_objsA._player.field_C,X
		BNE		loc_53993
		LDA		_game._bosses
		ORA		#$10
		STA		_game._bosses
loc_53993:
		JSR		_obj_adjust_field_7
		JMP		_obj_flush_and_continue
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
		JSR		_obj_sub52085
		BCC		loc_53A14
		JSR		_obj_hor_targeting_to_player_common
		LDA		_objsA._player.field_C,X
		BNE		loc_53A0E
		LDA		_game._bosses
		ORA		#$20
		STA		_game._bosses
loc_53A0E:
		JSR		_obj_adjust_field_7
		JMP		_obj_flush_and_continue
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
		LDA		#$04
		STA		_tmp00
		JSR		_obj_prize_deploy_ex
loc_53A69:
		JMP		_obj_flush_and_continue
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
		JMP		_obj_flush_and_continue
loc_53AC7:
		LDA		#$02
		STA		_game._scr_idx
		LDA		#$01
		STA		_game._redraw_req
		LDA		#$00
		STA		_room_scroll_pos_x+1
		STA		_tmp0C
		INY
		LDA		#$00
		STA		_room_scroll_pos_x
		LDA		#$78
		STA		_tmp0D
		LDA		#$40
		STA		_tmp0E
		LDA		#$00
		STA		_ppu_mask_shadow
		JMP		_obj_flush_and_continue
loc_53AEE:
		LDA		#$3C
		STA		_objsA._o1,X
		LDA		#$01
		ORA		#$F0
		STA		_objsA._o1._anim_phase_idx,X
		LDA		#$00
		STA		_objsA._o1.field_7,X
		LDA		#$00
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
		JMP		_obj_flush_and_continue

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
		JMP		_obj_flush_and_continue
loc_53B30:
		LDA		#$00
		STA		_tmp01
		LDA		#$02
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		#$00
		STA		_tmp0F
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
		JMP		_obj_flush_and_continue
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
		JSR		_obj_get_hor_delta16
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
		JMP		_obj_flush_and_continue

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
		JMP		_obj_flush_and_continue
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
		JMP		_obj_flush_and_continue
loc_53C4A:
		LDA		_objA_buf_shuffle_pos
		CMP		#$10
		BNE		loc_53C56
		LDA		#$60
		STA		_objA_buf_shuffle_pos
loc_53C56:
		LDA		_obj_heli_tmp_flag
		BNE		_heli_flight_up
		LDA		_game._flags+2
		AND		#$08
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
		LDA		#$07
		STA		_apu_se_noise_idx
		INC		_tmp0E
		INC		_objsA._o7._y_pos
		LDA		_tmp0E
		CMP		#$D0
		BNE		loc_53CB3
		LDA		_game._flags+2
		ORA		#$08
		STA		_game._flags+2
		LDA		#$00
		STA		_objsA._player._hndl_idx
		LDA		_game._scr_idx
		CMP		#$01
		BNE		loc_53C9A
		LDA		#$01
		STA		_obj_heli_tmp_flag
loc_53C9A:
		LDA		_game._scr_idx
		CMP		#$62
		BNE		loc_53CB3
		LDA		#$09
		STA		_objsA._player._prize_idx,X
		STA		_objsA._o7._prize_idx
		LDA		#$09
		STA		_objsA._player.field_9,X
		STA		_objsA._o7.field_9
		LDA		#$00
		STA		_objsA._player.field_C,X
		STA		_objsA._o7.field_C
loc_53CB3:
		JMP		_obj_flush_and_continue
_heli_flight_up:
		LDA		_game._scr_idx
		CMP		#$0B
		BNE		loc_53CC4
		LDA		_game._flags
		AND		#$40
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
		LDA		#$07
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
		STA		_obj_heli_tmp_flag
		LDA		#$80
		STA		_objsA._o7._hndl_idx
		JMP		_obj_kill_and_continue
loc_53CF5:
		LDA		_obj_heli_tmp_flag
		STA		_game._scr_idx
		LDA		#$00
		STA		_obj_heli_tmp_flag
		LDA		#$01
		STA		_game._redraw_req
		LDA		#$03
		STA		_objsA._player._room_num
		STA		_room_scroll_pos_x+1
		LDA		#$78
		STA		_objsA._player._x_pos
		LDA		#$00
		STA		_room_scroll_pos_x
		LDA		_objsA._player._dir
		AND		#$BF
		STA		_objsA._player._dir
		LDA		_game._flags+2
		AND		#$F7
		STA		_game._flags+2
loc_53D23:
		JMP		_obj_flush_and_continue
_heli_already_landed:
		LDA		_game._scr_idx
		CMP		#$01
		BEQ		loc_53D31
		CMP		#$62
		BNE		loc_53D3D
loc_53D31:
		LDA		#$00
		STA		_obj_heli_tmp_flag
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
		JMP		_obj_flush_and_continue
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
		JMP		_obj_flush_and_continue

; =============== S U B	R O U T	I N E =======================================
_obj_heli_active_zone_obj_insert:
		LDA		_tmp11
		ORA		#$02
		STA		_tmp11
		LDA		#$02
		STA		_objsA._o7._dir
		LDA		#$3E
		STA		_objsA._o7._hndl_idx
		LDA		#$F0
		STA		_objsA._player._anim_phase_idx,X
		LDA		#$00
		STA		_tmp0B
		LDA		#$01
		ORA		#$F0
		STA		_objsA._o7._anim_phase_idx
		LDA		#$18
		STA		_objsA._player.field_7,X
		LDA		#$00
		STA		_objsA._player.field_8,X
		LDA		#$0F
		STA		_objsA._player.field_9,X
		LDA		#$00
		STA		_objsA._o7.field_7
		LDA		#$00
		STA		_objsA._o7.field_8
		LDA		_game._flags+2
		AND		#$08
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
		BEQ		loc_53E1A
		CMP		#$05
		BEQ		_special_head_prize
		CMP		#$06
		BEQ		loc_53E20
		LDA		_objsA._player._hndl_idx,X
		AND		#$40
		BEQ		loc_53E17
		LDA		_tmp0B
		BEQ		loc_53E17
		LDA		#$80
		STA		_objsA._player._hndl_idx,X
loc_53E17:
		JMP		_obj_flush_and_continue
loc_53E1A:
		JSR		_obj_sub52085
		JMP		_obj_flush_and_continue
loc_53E20:
		LDA		#$04
		STA		_tmp01
		LDA		#$04
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
		SEC
		LDA		_tmp0D
		SBC		_tmp0F
		STA		_tmp0D
		LDA		_tmp0C
		SBC		#$00
		STA		_tmp0C
		LDA		#$00
		STA		_tmp0F
loc_53E51:
		JMP		_obj_jump_animate_test_ex
loc_53E54:
		JMP		_obj_kill_and_continue
_special_head_prize:
		LDA		#$00
		STA		_tmp01
		LDA		#$03
		STA		_tmp03
		JSR		_obj_tmp00_2_clear
		LDA		_tmp0E
		CMP		#$D0
		BCS		loc_53EB4
		LDA		_objsA._player._state,X
		BPL		loc_53EB7
		LDA		#$04
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
		ADC		#$64
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
		LDA		_objsA,X
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
		STA		_objsA._player.field_9,X
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
		.BYTE $37,$F2,$00,$00,$00,$00,$C0,$2F,$00,$02,$00,$0A,$FF,$00,$15,$F0

; =============== S U B	R O U T	I N E =======================================
_obj_boss_spider_drone_proj_anim:
		LDA		#$04
		STA		_tmp01
		LDA		#$04
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
		JSR		_obj_get_hor_delta16
		JMP		_obj_flush_and_continue
; ---------------------------------------------------------------------------
_boss_spider_drone_proj_anim_tbl:
		.BYTE $30,$31,$31,$32,$32,$22,$22,$22,$22,$22,$22,$23,$23,$13,$13,$03
		.BYTE $03,$13,$13,$23,$23,$22,$22,$22,$22,$22,$22,$32,$32,$31,$31,$30

		SECTION_END "OBJECTS PROGRAM"

		BANK_END 6,$C000
