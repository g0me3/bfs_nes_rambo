
		INCLUDE		"..\macroses.inc"

;--------------------R-A-M----------------------

		ORG $0000

_tmp00:
		.BYTE 0
_tmp01:
		.BYTE 0
_tmp02:
		.BYTE 0
_tmp03:
		.BYTE 0
_tmp04:
		.BYTE 0
_tmp05:
		.BYTE 0
_tmp06:
		.BYTE 0
_tmp07:
		.BYTE 0
_tmp08:
		.BYTE 0
_tmp09:
		.BYTE 0
_tmp0A:
		.BYTE 0
_tmp0B:
		.BYTE 0
_tmp0C:
		.BYTE 0
_tmp0D:
		.BYTE 0
_tmp0E:
		.BYTE 0
_tmp0F:
		.BYTE 0
_tmp10:
		.BYTE 0
_tmp11:
		.BYTE 0
_tmp12:
		.BYTE 0
_tmp13:
		.BYTE 0
_tmp14:
		.BYTE 0
_tmp15:
		.BYTE 0
_tmp16:
		.BYTE 0
_tmp17:
		.BYTE 0
_tmp18:
		.BYTE 0
_tmp19:
		.BYTE 0,0
_ppu_room_line_ptr:
		.BYTE 0,0
_ppu_queue_buf_ofs:
		.BYTE 0,0
_nmi_disable:
		.BYTE 0

		_tobjsA	_objsA
		_tobjsB	_objsB

		ECHO "-------------"
		ECHO "zero ram free:",[$100-.]
		ECHO "-------------"


		ORG $0100

_game:
_game._scr_idx:
		.BYTE 0
_game._flags:
		.BYTE 0,0,0
_game._bosses:
		.BYTE 0
_game._start_room:
		.BYTE 0
_game._start_y:
		.BYTE 0
_game._play_days:
		.BYTE 0
_game._play_hours:
		.BYTE 0
_game._play_minutes:
		.BYTE 0
_game._crc:
		.BYTE 0
_game._life_level:
		.BYTE 0
_game._life:
		.WORD 0
_game._exp:
		.WORD 0
_game._exp_level:
		.BYTE 0
_game._ammo_knife:
		.BYTE 0
_game._ammo_spear:
		.BYTE 0
_game._ammo_spear_bomb:
		.BYTE 0
_game._ammo_gun:
		.BYTE 0
_game._ammo_grenades:
		.BYTE 0
_game._potions:
		.BYTE 0
_game._redraw_req:
		.BYTE 0
_hud_decimals_buf:
		.BYTE 0,0,0,0,0,0,0,0,0,0,0
_ppu_dequeue_idx:
		.BYTE 0
_nmi_flag:
		.BYTE 0
_nmi_disble_ppu_reset_req:
		.BYTE 0
_pal_fade_delay:
		.BYTE 0
_cur_loc_room_settings:
		.BYTE 0  	; &F0>>4 - room music idx
					; 8
					; 4
					; 2 - special lamp lightning (==1)
					; 1 - sprite behind background	(==1)
_cur_level_chr_idx:
		.BYTE 0 	; &0F>>0 - bg chr block	idx
					; &F0>>4 - spr chr block idx
_cur_loc_bg_pal_settings:
		.BYTE 0  	; &F0>>4 - night palette (21 PM -	03 AM)
					; &0F>>0 - day palette (04 AM -	20 PM)
_cur_loc_spr_pal_settings:
		.BYTE 0
_cur_loc_room_idx_and_stop_flags:
		.BYTE 0  	; 80 - E exit blocked
					; 40 - W exit blocked
					; &3F
					; <20 -	room data idx bank 0
					; >20 -	room data idx bank 1
_cur_loc_warpA_pos:
		.BYTE 0 	; 80 - warp active
					; 40 - S/N warp	select
					; &30>>4 - room	idx (0-3)
					; &0F>>0 - room	macro pos
_cur_loc_warpB_pos:
		.BYTE 0
_cur_loc_prize_idx:
		.BYTE 0
_cur_pal_bg_idx:
		.BYTE 0
_cur_pal_spr_lib:
		.BYTE 0
_pad:
		.BYTE 0,0
_ingame_dpad_cheat_counter:
		.BYTE 0
_ingame_down_cheat_counter:
		.BYTE 0
_ppu_ctrl_shadow:
		.BYTE 0
_ppu_mask_shadow:
		.BYTE 0
_play_seconds:
		.BYTE 0
_pre_timer:
		.BYTE 0
_room_scroll_pos_x:
		.BYTE 0,0
_prev_player_pos_x:
		.BYTE 0,0
_cur_player_pos_x_delta:
		.BYTE 0
_objB_buf_shuffle_pos:
		.BYTE 0
_objA_buf_shuffle_pos:
		.BYTE 0
_spr_buf_pos:
		.BYTE 0
_cur_prg_bank:
		.BYTE 0
_cur_weapon_selected:
		.BYTE 0
_ingame_pause_flag:
		.BYTE 0
_pad_tmp:
		.BYTE 0
_rand_seed:
		.BYTE 0
_helicopter_warp_idx:
		.BYTE 0
_prev_weapon_selected:
		.BYTE 0
_game_scr_idx_backup:
		.BYTE 0
_game_flags_backup:
		.BYTE 0,0,0
_game_bosses_backup:
		.BYTE 0
_game_life_level_backup:
		.BYTE 0
_game_life_backup:
		.BYTE 0,0
_ppu_status_shadow:
		.BYTE 0
_final_boss_scroll_pos:
		.BYTE 0
_final_boss_delay_and_hp:
		.BYTE 0
_final_boss_deploy_delay_timer:
		.BYTE 0
_apu_cur_mus_idx:
		.BYTE 0

		_tapu_chnls _apu

_apu_mus_ptrs:
		.BYTE 0,0,0,0,0,0,0,0
_apu_se_pulse_idx:
		.BYTE 0
_apu_se_pulse_cnt:
		.BYTE 0
_apu_se_noise_idx:
		.BYTE 0
_apu_se_noise_cnt:
		.BYTE 0
_apu_prev_mus_idx:
		.BYTE 0
_apu_cur_mus_prg:
		.BYTE 0
_apu_counter:
		.BYTE 0
_apu_tmp187:
		.BYTE 0
_apu_tmp188:
		.BYTE 0
_chr_tiles_send_src:
		.BYTE 0,0
_chr_tiles_send_dst:
		.BYTE 0,0

		ECHO "-------------"
		ECHO "stack ram free:",[$190-.]
		ECHO "-------------"

		ORG $0190

		_tarray _ppu_queue_buf, 16*7

		ORG $0200

		_tarray _spr_buf, 256

		ORG $0300

		_tarray _room_map_buf, 256*4

		ORG $0700

		_tarray _room_attr_buf, 256

;--------------------P-P-U----------------------

		ORG $2000

_PPU_CTRL:
		.BYTE 0
_PPU_MASK:
		.BYTE 0
_PPU_STATUS:
		.BYTE 0
_PPU_OAM_ADDR:
		.BYTE 0
_PPU_OAM_DATA:
		.BYTE 0
_PPU_SCROLL:
		.BYTE 0
_PPU_ADDR:
		.BYTE 0
_PPU_DATA:
		.BYTE 0

;--------------------A-P-U----------------------

		ORG $4000

_APU_PULSE1_ENV:
		.BYTE 0
_APU_PULSE1_SWEEP:
		.BYTE	0
_APU_PULSE1_TIME:
		.BYTE 0
_APU_PULSE1_LEN:
		.BYTE 0

_APU_PULSE2_ENV:
		.BYTE 0
_APU_PULSE2_SWEEP:
		.BYTE 0
_APU_PULSE2_TIME:
		.BYTE 0
_APU_PULSE2_LEN:
		.BYTE 0

_APU_TRI_COUNT:
		.BYTE 0
_APU_TRI_UNUSED:
		.BYTE 0
_APU_TRI_TIME:
		.BYTE 0
_APU_TRI_LEN:
		.BYTE 0

_APU_NOISE_ENV:
		.BYTE 0
_APU_NOISE_UNUSED:
		.BYTE 0
_APU_NOISE_LOOP:
		.BYTE 0
_APU_NOISE_LEN:
		.BYTE 0

_APU_DMC_FREQ:
		.BYTE 0
_APU_DMC_LOAD:
		.BYTE 0
_APU_DMC_ADDR:
		.BYTE 0
_APU_DMC_LEN:
		.BYTE 0
_PPU_OAM_DMA:
		.BYTE 0
_APU_STATUS:
		.BYTE 0
_PAD0_REG:
		.BYTE 0
_PAD1_REG:
		.BYTE 0
