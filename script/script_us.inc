
		.WORD _script80
		.WORD _script81
		.WORD _script82
		.WORD _script83
		.WORD _script84
		.WORD _script85
		.WORD _script86
		.WORD _script87
		.WORD _script88
		.WORD _script89
		.WORD _script8A
		.WORD _script8B
		.WORD _script8C
		.WORD _script8D
		.WORD _script8E
		.WORD _script8F
		.WORD _script90
		.WORD _script91
		.WORD _script92
		.WORD _script93
		.WORD _script94
		.WORD _script95
		.WORD _script96
		.WORD _script97
		.WORD _script98
		.WORD _script99
		.WORD _script9A
		.WORD _script9B
		.WORD _script9C
		.WORD _script9D
		.WORD _script9E
		.WORD _script9F
		.WORD _scriptA0
		.WORD _scriptA1
		.WORD _scriptA2
		.WORD _scriptA3
		.WORD _scriptA4
		.WORD _scriptA5
		.WORD _scriptA6
		.WORD _scriptA7
		.WORD _scriptA8
		.WORD _scriptA9
		.WORD _scriptAA
		.WORD _scriptAB
		.WORD _scriptAC
		.WORD _scriptAD
		.WORD _scriptAE
		.WORD _scriptAF
		.WORD _scriptB0
		.WORD _scriptB1
		.WORD _scriptB2
		.WORD _scriptB3
		.WORD _scriptB4
		.WORD _scriptB5
_script80:
		set_room_idx		$81
		ptr_load			_script80_msg00
		msg_printf			$2063	; [RAMBO_ IS A REGISTERED\TRADEMARK OF CAROLCO\PICTURES INC._ 1985,1988\CAROLCO.ALL RIGHTS RESERVED.]
		ptr_load			_script80_msg01
		msg_printf			$2163	; [UNAUTHORIZED DUPLICATION\IS STRICTLY PROHIBITED.]
		ptr_load			_script80_msg02
		msg_printf			$21e3	; [NINTENDO VERSION _ 1988\PACK-IN-VIDEO CO.,LTD.]
		ptr_load			_script80_msg03
		msg_printf			$2263	; [LICENCED AND CONTROLLED FOR\THE UNITED STATES AND CANADA\BY ACCLAIM ENTERTAINMENT,INC.]
		ptr_load			_script80_msg03A
		msg_printf			$2323	; [LICENSED BY NINTENDO OF\AMERICA,INC.]
		sprite_draw_up		_SPR_PACK_IN_TIME
		stop
_script81:
		ptr_load			_script81_msg00
		msg_printf			$21c3	; [REND THE FEELINGS OF HEART\  WITH PAINFUL FEELINGS]
		ptr_load			_script81_msg01
		msg_printf			$22ac	; [START\CONTINUE]
		ptr_load			_script81_msg02
		msg_printf			$20E9	; [DIRECTOR'S CUT]
		ptr_load			_script81_msg03
		msg_printf			$2B65	; [_2021 CAH4E3 BFS GMBH]
		sprite_draw_up		_SPR_TITLE_SCREEN
		jmpne_option		$01, _script81_loc00
		checkpoint_reset
		set_room_idx		$85
		checkpoint_set
		scroller
		stop
		------------------
_script81_loc00:
		set_room_idx		$82
		stop
_script82:
		frame_draw_custom	$2065, $17, $06
		ptr_load			_script82_msg00
		msg_printf			$2068	; [Input Mission Code]
_script82_loc00:
		frame_draw_custom	$2125, $17, $12
		ptr_load			_script82_msg01
		msg_printf			$2167	; [0 1 2 3 4 5 6 7 8 9\A B C D E F G H I J\K L M N O P Q R S T\U V W X Y Z\a b c d e f g h i j\k l m n o p q r s t\u v w x y z ? !\BS  SP  END]
		pass_input
		jmpne_option		$01, _script82_loc01
		checkpoint_set
		checkpoint_restore
		stop
		------------------
_script82_loc01:
		frame_draw_custom	$2269, $0d, $06
		ptr_load			_script82_msg02
		msg_printf			$226b	; [Code Error]
		set_room_idx		$82
		ptr_load			_script82_msg03
		msg_printf			$22ac	; [START\CONTINUE]
		continue_cur_draw
		jmpne_option		$01, _script82_loc02
		checkpoint_reset
		set_room_idx		$85
		checkpoint_set
		stop
		------------------
_script82_loc02:
		jump				_script82_loc00
_script83:
		ptr_load			_script83_msg00
		msg_printf			$2465	; [LIFE        (MAX      )\EXP         (NEXT     )\TIME]
		game_stats_draw
		frame_draw_custom	$2525, $17, $0a
		ptr_load			_script83_msg01
		msg_printf			$252b	; [INVENTORY]
		jmp_flags_not_set	FLAG09_CO_TAKEN, _script83_loc00
		ptr_load			_script83_msg02
		msg_printf			$2567	; [CO]
		------------------
_script83_loc00:
		jmp_flags_not_set	FLAG0E_BOAT,	_script83_loc01
		ptr_load			_script83_msg03
		msg_printf			$25a7	; [BOAT]
		------------------
_script83_loc01:
		jmp_flags_not_set	FLAG03_LAMP_ITEM, _script83_loc02
		ptr_load			_script83_msg04
		msg_printf			$25e7	; [LAMP]
		------------------
_script83_loc02:
		jmp_flags_not_set	FLAG04_KID_TAKEN, _script83_loc03
		ptr_load			_script83_msg05
		msg_printf			$2627	; [KID]
		------------------
_script83_loc03:
		jmp_flags_not_set	FLAG05_PHOTO_ITEM, _script83_loc04
		ptr_load			_script83_msg06
		msg_printf			$256c	; [PHOTO]
		------------------
_script83_loc04:
		jmp_flags_not_set	FLAG06_POW_TAKEN, _script83_loc05
		ptr_load			_script83_msg07
		msg_printf			$25ac	; [POW]
		------------------
_script83_loc05:
		jmp_flags_not_set	FLAG07_DRESS_ITEM, _script83_loc06
		ptr_load			_script83_msg08
		msg_printf			$25ec	; [DRESS]
		------------------
_script83_loc06:
		jmp_flags_not_set	FLAG10_HELI_KEY, _script83_loc07
		ptr_load			_script83_msg09
		msg_printf			$262c	; [KEY]
		------------------
_script83_loc07:
		jmp_flags_not_set	FLAG11_PEDANT, _script83_loc08
		ptr_load			_script83_msg0a
		msg_printf			$2573	; [PENDANT]
		------------------
_script83_loc08:
		jmp_flags_not_set	FLAG12_BANDANA, _script83_loc09
		ptr_load			_script83_msg0b
		msg_printf			$25b3	; [BANDANA]
		------------------
_script83_loc09:
		frame_draw_custom	$2685, $17, $06
		ptr_load			_script83_msg0c
		msg_printf			$268a	; [MISSION CODE]
		stop
_script84:
		ptr_load			_script84_msg00
		msg_printf			$210b	; [GAME OVER]
		sprite_draw_down	PORTRAIT01_RAMBO_ANGRY
		ptr_load			_script84_msg01
		msg_printf			$22ac	; [CONTINUE\START]
		continue_cur_draw
		jmpne_option		$02, _script84_loc00
		checkpoint_reset
		set_room_idx		$85
		checkpoint_set
		stop
		------------------
_script84_loc00:
		checkpoint_restore
		stop
_script85:
		player_pos_set		$00, $d0
		game_hours_set		$0c
		ptr_load			_script85_msg00
		msg_printf			$20e7	; [Colonel Trautman\visits Rambo in the\military prison.]
		msg_input_handler
		frame_draw_up		PORTRAIT08_TRAUMAN1
		ptr_load			_script85_msg01
		msg_draw_up			; [Rambo,I want to\send you on\a Mission.]
		ptr_load			_script85_msg01A
		msg_draw_up			; [It's dangerous,but\you'll be free\if you succeed.]
		ptr_load			_script85_msg02
		msg_draw_up			; [Our men are still\missing]
		ptr_load			_script85_msg02A
		msg_draw_up			; [in a jungle\in Vietnam.We\believe they are\alive,prisoners of\the enemy.]
		ptr_load			_script85_msg03
		msg_draw_up			; [Your mission is to\sneak into the\enemy camp and find\them.\Are you up to it?]
_script85_loc00:
		frame_draw_down		PORTRAIT00_RAMBO
		input_2_options
		ptr_load			_script85_msg04
		msg_draw_down		; [ I'm not afraid of\death.\ \ I feel better in\prison.]
		jmpne_option		$01, _script85_loc01
		ptr_load			_script85_msg05
		msg_draw_up			; [Good,I'll make the\arrangements.]
		set_room_idx		$01
		stop
		------------------
_script85_loc01:
		ptr_load			_script85_msg06
		msg_draw_up			; [But it's up to you.\The game doesn't\start until you\say YES.]
		jump				_script85_loc00
_script86:
		game_flags_set		FLAG00_SYS
		frame_draw_up		PORTRAIT09_MURDOCK
		ptr_load			_script86_msg00
		msg_draw_up			; [I'm\Commander Murdock.]
		ptr_load			_script86_msg01
		msg_draw_up			; [We want you to get\into enemy\territory and take\photographs of the\POW camp.]
		ptr_load			_script86_msg01A
		msg_draw_up			; [You're not to\engage the enemy.]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script86_msg02
		msg_draw_down		; [Photos? Not rescue\them?]
		ptr_load			_script86_msg03
		msg_draw_up			; [I repeat.You're not\to engage the\enemy.]
		ptr_load			_script86_msg03A
		msg_draw_up			; [Go to the weapons\center and\get ready.]
		set_room_idx		$00
		stop
_script87:
		frame_draw_up		PORTRAIT0D_ERICSON
		jmp_flags_not_set	FLAG00_SYS, _script87_loc00
		jmp_branch			_script87_loc01
_script87_loc00:
		ptr_load			_script87_msg00
		msg_draw_up			; [We can't give you\weapons without\Murdock's\permission.]
		set_room_idx		$00
		stop
		------------------
_script87_loc01:
		jmp_flags_not_set	FLAG08_SYS, _script87_loc02
		jmp_branch			_script87_loc03
_script87_loc02:
		ptr_load			_script87_msg01
		msg_draw_up			; [I picked some\weapons for\your mission.]
		game_flags_set		FLAG08_SYS
		add_10_knifes
		add_10_knifes
		add_5_potions
		------------------
_script87_loc03:
		game_hours_set		$17
		ptr_load			_script87_msg02
		msg_draw_up			; [Go to Trautman.]
		set_room_idx		$00
		stop
_script88:
		frame_draw_up		PORTRAIT08_TRAUMAN1
		jmp_flags_not_set	FLAG08_SYS, _script88_loc00
		jump				_script88_loc01
		------------------
_script88_loc00:
		ptr_load			_script88_msg00
		msg_draw_up			; [Rambo,forget about\your absurd hand-to\-hand fighting.\Military technology\will work best.]
		frame_draw_down		PORTRAIT00_RAMBO
;		ptr_load			_script88_msg01
;		msg_draw_down		; [-MISSING-]
		ptr_load			_script88_msg02
		msg_draw_up			; [Go to the hangar.]
		set_room_idx		$01
		stop
_script88_loc01:
		ptr_load			_script88_msg03
		msg_draw_up			; [There's a contact\man Co,over\there.He'll guide\you in the jungle.]
		checkpoint_set
		ptr_load			_script88_msg04
		msg_draw_up			; [You've got 36 hours\to get in,complete\your assignment,\and get the hell\out.]
		ptr_load			_script88_msg04A
		msg_draw_up			; [If you get in\trouble,try to\reach the\extraction site\marked on the map.]
		ptr_load			_script88_msg05
		msg_draw_up			; [Rambo...\Good luck.]
		game_hours_set		$03
		game_flags_clear	FLAG00_SYS
		game_flags_clear	FLAG08_SYS
		game_flags_clear	FLAG13_SYS
		anim_scene_set		$00
		set_room_idx		$7c
		player_pos_set		$01, $50
		stop
_script89:
		checkpoint_set
		game_flags_set		FLAG09_CO_TAKEN
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_script89_msg00
		msg_draw_up			; [I'm Co.\You did not expect\a woman?]
		ptr_load			_script89_msg00A
		msg_draw_up			; [Would you like to\know something?]
		frame_draw_down		PORTRAIT00_RAMBO
		input_2_options
		ptr_load			_script89_msg01
		msg_draw_down		; [ Where is the camp?\ \ \ What do you think\ about me?]
		jmpne_option		$02, _script89_loc00
		sprite_draw_down	PORTRAIT02_RAMBO_HAPPY
		sprite_draw_up		PORTRAIT04_CO_HAPPY
		ptr_load			_script89_msg02
		msg_draw_up			; [What?\You look good.]
		------------------
_script89_loc00:
		ptr_load			_script89_msg03
		msg_draw_up			; [The camp is located\in the jungle to\the East of the\river.]
		ptr_load			_script89_msg03A
		msg_draw_up			; [I've arranged\a boat.Let's go to\the dock.]
		set_room_idx		$0a
		stop
_script8A:
		checkpoint_set
		jmp_flags_not_set	FLAG09_CO_TAKEN, _script8A_loc00
		jmp_branch			_script8A_loc01
_script8A_loc00:
		frame_draw_up		PORTRAIT14_PIRATE
		ptr_load			_script8A_msg00
		msg_draw_up			; [You're outsiders,\aren't you.] [-MORE TEXT-]
		ptr_load			_script8A_msg00A
		msg_draw_up			; [Sorry,we can't\allow strangers\to get on our boat.]
		set_room_idx		$06
		stop
_script8A_loc01:
		jmp_flags_not_set	FLAG0E_BOAT,	_script8A_loc02
		frame_draw_up		PORTRAIT14_PIRATE
		jump				_script8A_loc03
		------------------
_script8A_loc02:
		frame_draw_down		PORTRAIT03_CO
		ptr_load			_script8A_msg01
		msg_draw_down		; [What? You should\know us.We wanna\get on the boat.\Here's money.]
		frame_draw_up		PORTRAIT14_PIRATE
		ptr_load			_script8A_msg02
		msg_draw_up			; [OK] [-MORE TEXT-]
_script8A_loc03:
		ptr_load			_script8A_msg03
		msg_draw_up			; [Get on,hurry.] [-MORE TEXT-]
		game_flags_set		FLAG0E_BOAT
		set_room_idx		$06
		stop
_script8B:
		checkpoint_set
		frame_draw_up		PORTRAIT03_CO
		jmp_flags_not_set	FLAG01_SYS, _script8B_loc00
		ptr_load			_script8B_msg00
		msg_draw_up			; [Rambo,something's\strange.]
		jmp_branch			_script8B_loc01
_script8B_loc00:
		jump				_script8B_loc02
		------------------
_script8B_loc01:
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script8B_msg01
		msg_draw_down		; [Look! That's an\enemy boat.\You sold us!]
		sprite_draw_up		PORTRAIT14_PIRATE
		ptr_load			_script8B_msg02
		msg_draw_up			; [Right,We do\everything for\money.Don't move.]
		game_flags_clear	FLAG0E_BOAT
		set_room_idx		$60
		stop
_script8B_loc02:
		jmp_flags_not_set	FLAG11_PEDANT, _script8B_loc03
		jump				_script8B_loc04
		------------------
_script8B_loc03:
;		ptr_load			_script8B_msg03
;		msg_draw_up			; [-MISSING-]
		frame_draw_down		PORTRAIT00_RAMBO
;		ptr_load			_script8B_msg04
;		msg_draw_down		; [-MISSING-]
;		ptr_load			_script8B_msg05
;		msg_draw_up			; [-MISSING-]
		ptr_load			_script8B_msg06
		msg_draw_down		; [What does this\pendant mean?]
		sprite_draw_up		PORTRAIT04_CO_HAPPY
		ptr_load			_script8B_msg07
		msg_draw_up			; [It brings me good\luck.]
;		ptr_load			_script8B_msg08
;		msg_draw_down		; [-MISSING-]
		ptr_load			_script8B_msg09
		msg_draw_up			; [Rambo,keep this\pendant.\Please take care\of it.]
		life_restore
		game_flags_set		FLAG11_PEDANT
_script8B_loc04:
		ptr_load			_script8B_msg0a
		msg_draw_up			; [Now,here we are.\We'll have to walk\from here\to the camp.]
		set_room_idx		$0d
		stop
_script8C:
		checkpoint_set
		game_flags_set		FLAG09_CO_TAKEN
		set_room_idx		$0e
		frame_draw_up		PORTRAIT03_CO
		jmp_flags_not_set	FLAG02_KID_SAVED, _script8C_loc00
		jmp_branch			_script8C_loc01
_script8C_loc00:
		ptr_load			_script8C_msg00
		msg_draw_up			; [Let's go\search the village.\You'll find it\in the East.]
		stop
		------------------
_script8C_loc01:
		jmp_flags_not_set	FLAG01_SYS, _script8C_loc02
		jmp_branch			_script8C_loc03
_script8C_loc02:
		ptr_load			_script8C_msg01
		msg_draw_up			; [The camp is located\South from here.]
		stop
		------------------
_script8C_loc03:
		ptr_load			_script8C_msg02
		msg_draw_up			; [Cross the river\to the West,and\climb the hill,\then you'll find\the pick-up point.]
		jmp_flags_not_set	FLAG0A_MISSION_TIME_OVER, _script8C_loc04
		jmp_branch			_script8C_loc05
_script8C_loc04:
		stop
		------------------
_script8C_loc05:
		ptr_load			_script8C_msg03
		msg_draw_up			; [But,we're late\for the contact\time.]
		ptr_load			_script8C_msg03A
		msg_draw_up			; [The helicopter\won't come any\more.\We'd better hide\in the village.]
		stop
_script8D:
		checkpoint_set
		frame_draw_up		PORTRAIT15_KID
		ptr_load			_script8D_msg00
		msg_draw_up			; [AHHH...!\AHH...!]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script8D_msg01
		msg_draw_down		; [I'll help you.]
		game_flags_set		FLAG04_KID_TAKEN
		set_room_idx		$3c
		stop
_script8E:
		jmp_flags_not_set	FLAG0C_SYS, _script8E_loc00
		set_room_idx		$0c
		stop
		------------------
_script8E_loc00:
		set_room_idx		$3f
		stop
_script8F:
		checkpoint_set
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_script8F_msg00
		msg_draw_up			; [I'm so happy to\see you're safe.]
		jmp_flags_not_set	FLAG06_POW_TAKEN, _script8F_loc00
		ptr_load			_script8F_msg01
		msg_draw_up			; [What?\Did you take the\POW out?]
		ptr_load			_script8F_msg01A
		msg_draw_up			; [You were supposed\to take photos\only!]
		------------------
_script8F_loc00:
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script8F_msg02
		msg_draw_down		; [Let's get out of\here,now!]
		set_room_idx		$6c
		stop
_script90:
		checkpoint_set
		game_flags_set		FLAG01_SYS
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script90_msg00
		msg_draw_down		; [I'll go ahead by\myself.]
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_script90_msg01
		msg_draw_up			; [I see...] [-MORE TEXT-]
		set_room_idx		$25
		stop
_script91:
		frame_draw_down		PORTRAIT03_CO
		ptr_load			_script91_msg00
		msg_draw_down		; [Did you call me?]
		frame_draw_up		PORTRAIT11_SOLDIER2
		jmp_flags_not_set	FLAG07_DRESS_ITEM, _script91_loc00
		jmp_branch			_script91_loc01
_script91_loc00:
		ptr_load			_script91_msg01
		msg_draw_up			; [This is no place\for villagers.]
		set_room_idx		$6f
		stop
		------------------
_script91_loc01:
		ptr_load			_script91_msg02
		msg_draw_up			; [Aha.\This way to the\captain's quarters.] [-DIFFERENT MEANING-]
		set_room_idx		$6e
		stop
_script92:
		frame_draw_down		PORTRAIT03_CO
		jmp_flags_not_set	FLAG00_SYS, _script92_loc00
		jump				_script92_loc02
		------------------
_script92_loc00:
		ptr_load			_script92_msg00
		msg_draw_down		; [Good evening.]
		frame_draw_up		PORTRAIT11_SOLDIER2
		ptr_load			_script92_msg01
		msg_draw_up			; [You must be the\general's wife.] [-DIFFERENT MEANING-]
		input_2_options
		ptr_load			_script92_msg02
		msg_draw_down		; [ No.I'm looking\ for some.\ \ Yes.] [-DIFFERENT MEANING-]
		jmpne_option		$01, _script92_loc01
		ptr_load			_script92_msg03
		msg_draw_up			; [Get out of here.] [-DIFFERENT MEANING-]
		set_room_idx		$6e
		stop
		------------------
_script92_loc01:
		ptr_load			_script92_msg04
		msg_draw_down		; [What happened\today?] [-DIFFERENT MEANING-]
		ptr_load			_script92_msg05
		msg_draw_up			; [I caught a spy.] [-DIFFERENT MEANING-]
		ptr_load			_script92_msg06
		msg_draw_down		; [So,you have the key\to the room.] [-DIFFERENT MEANING-]
		sprite_draw_up		PORTRAIT_CLEAR
		ptr_load			_script92_msg07
		msg_draw_up			; [Anything for the\general's wife.] [-DIFFERENT MEANING-]
_script92_loc02:
		ptr_load			_script92_msg08
		msg_draw_down		; [I got the key.] [-DIFFERENT MEANING-]
		game_flags_set		FLAG00_SYS
		set_room_idx		$6e
		stop
_script93:
		frame_draw_up		PORTRAIT10_SOLDIER1
		ptr_load			_script93_msg00
		msg_draw_up			; [What are you doing\here?]  [-DIFFERENT MEANING-]
		frame_draw_down		PORTRAIT03_CO
		ptr_load			_script93_msg01
		msg_draw_down		; [Sorry.]
		ptr_load			_script93_msg02
		msg_draw_up			; [Hey!Where are you\going?\The exit is on the\right.]
		ptr_load			_script93_msg03
		msg_draw_up			; [To the left is the\torture room.]
		set_room_idx		$6e
		stop
_script94:
		checkpoint_set
		frame_draw_up		PORTRAIT03_CO
		jmp_flags_not_set	FLAG00_SYS, _script94_loc00
		ptr_load			_script94_msg00
		msg_draw_up			; [I'm opening\the door now.]
		jmp_branch			_script94_loc01
_script94_loc00:
		jump				_script94_loc02
		------------------
_script94_loc01:
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script94_msg01
		msg_draw_down		; [Thanks.] [-MORE TEXT-]
		ptr_load			_script94_msg02
		msg_draw_up			; [They've seen us.\Let's get out\of here now.]
		game_flags_clear	FLAG0C_SYS
		set_room_idx		$70
		stop
_script94_loc02:
		ptr_load			_script94_msg03
		msg_draw_up			; [Rambo,it's me.\Wait a minute.\I'm going to look\for the key.]
		frame_draw_down		PORTRAIT_CLEAR
		ptr_load			_script94_msg04
		msg_draw_down		; [...]
		set_room_idx		$6d
		stop
_script95:
		checkpoint_set
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_script95_msg00
		msg_draw_up			; [Rambo,the pick-up\point is ahead.]
		jmp_flags_not_set	FLAG0A_MISSION_TIME_OVER, _script95_loc00
		jmp_branch			_script95_loc01
_script95_loc00:
		jump				_script95_loc02
		------------------
_script95_loc01:
		ptr_load			_script95_msg01
		msg_draw_up			; [But the contact\time has already\passed.]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script95_msg02
		msg_draw_down		; [Let's return to\the jungle.]
		set_room_idx		$18
		player_pos_set		$00, $c0
		stop
_script95_loc02:
		jmp_flags_not_set	FLAG06_POW_TAKEN, _script95_loc03
		jump				_script95_loc05
		------------------
_script95_loc03:
		jmp_flags_not_set	FLAG05_PHOTO_ITEM, _script95_loc04
		jump				_script95_loc05
		------------------
_script95_loc04:
		ptr_load			_script95_msg03
		msg_draw_up			; [Are you going back\without doing\anything?]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script95_msg04
		msg_draw_down		; [We still have\time to get to\the camp.]
		ptr_load			_script95_msg05
		msg_draw_up			; [The camp is located\far South from\here.]
		set_room_idx		$18
		player_pos_set		$00, $c0
		stop
_script95_loc05:
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script95_msg06
		msg_draw_down		; [Co,thanks for\helping me.] [-MORE TEXT-]
		ptr_load			_script95_msg07
		msg_draw_up			; [Rambo,I want to go\to America with\you.]
		jmp_flags_not_set	FLAG06_POW_TAKEN, _script95_loc06
		ptr_load			_script95_msg08
		msg_draw_down		; [I'm sorry.I can't\take you.]
		jump				_script95_loc07
		------------------
_script95_loc06:
		input_2_options
		ptr_load			_script95_msg09
		msg_draw_down		; [ I'm sorry.I can't\ take you.\ \ Then come back with\ me.]
		jmpne_option		$02, _script95_loc07
		sprite_draw_up		PORTRAIT04_CO_HAPPY
		ptr_load			_script95_msg0a
		msg_draw_up			; [Thanks.\I'm so glad.\Let's go,they're\coming.Hurry up.]
		game_flags_set		FLAG09_CO_TAKEN
		set_room_idx		$0b
		player_pos_set		$00, $a0
		stop
		------------------
_script95_loc07:
		sprite_draw_up		PORTRAIT05_CO_SAD
		ptr_load			_script95_msg0b
		msg_draw_up			; [I won't see you\any more.\Good-bye.]
		game_flags_clear	FLAG09_CO_TAKEN
		set_room_idx		$0b
		player_pos_set		$00, $a0
		stop
_script96:
		frame_draw_up		PORTRAIT0D_ERICSON
		jmp_flags_not_set	FLAG06_POW_TAKEN, _script96_loc00
		ptr_load			_script96_msg00
		msg_draw_up			; [Headquarters,\we found Rambo.\He's taking POW's\with him.]
		jmp_branch			_script96_loc01
_script96_loc00:
		jump				_script96_loc02
		------------------
_script96_loc01:
		frame_draw_down		PORTRAIT_CLEAR
		ptr_load			_script96_msg01
		msg_draw_down		; [..Emergency\Stop the mission..]
		sprite_draw_down	PORTRAIT08_TRAUMAN1
		ptr_load			_script96_msg02
		msg_draw_down		; [What?\I can't leave them\stranded.]
		ptr_load			_script96_msg03
		msg_draw_up			; [I have to follow\orders.]
		sprite_draw_down	PORTRAIT0C_TRAUMAN2
		ptr_load			_script96_msg04
		msg_draw_down		; [Mercenaries!] [-MORE TEXT-]
		set_room_idx		$0b
		anim_scene_set		$a9
		stop
_script96_loc02:
		ptr_load			_script96_msg05
		msg_draw_up			; [Headquarters,we've\found Rambo.We're\going in to rescue\him.]
		ptr_load			_script96_msg05A
		msg_draw_up			; [He's being chased\by the enemy.]
		frame_draw_down		PORTRAIT_CLEAR
		ptr_load			_script96_msg06
		msg_draw_down		; [.. Rescue him ..]
		sprite_draw_up		PORTRAIT08_TRAUMAN1
		ptr_load			_script96_msg07
		msg_draw_up			; [Rambo,get on,hurry\up.So long,jungle.]
		set_room_idx		$0b
		anim_scene_set		$7d
		stop
_script97:
		ptr_load			_script97_msg00
		msg_printf			$20e7	; [At that time Rambo,\who was caught by\the enemy,was being\interrogated.]
		msg_input_handler
		frame_draw_up		PORTRAIT0E_PADOVSKY
		ptr_load			_script97_msg01
		msg_draw_up			; [I'm\Commander Padovsky.]
		ptr_load			_script97_msg02
		msg_draw_up			; [You were sent here\in an effort to\free war criminals.]
		ptr_load			_script97_msg02A
		msg_draw_up			; [I want all the\details of your\Mission.]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script97_msg03
		msg_draw_down		; [...]
		ptr_load			_script97_msg04
		msg_draw_up			; [I want you to radio\your headquarters\and say that you\have been captured.]
		ptr_load			_script97_msg05
		msg_draw_down		; [...]
		sprite_draw_down	PORTRAIT00_RAMBO
		ptr_load			_script97_msg06
		msg_draw_up			; [You will not talk?\O.K.\Yashin!]
		ptr_load			_script97_msg06A
		msg_draw_up			; [You're only an\experimental\animal for sergeant\Yashin.]
;		sprite_draw_up		PORTRAIT0F_YUSIN
;		ptr_load			_script97_msg07
;		msg_draw_up			; [-MISSING-]
;		sprite_draw_down	PORTRAIT01_RAMBO_ANGRY
;		ptr_load			_script97_msg08
;		msg_draw_down		; [-MISSING-]
		sprite_draw_up		PORTRAIT0E_PADOVSKY
		sprite_draw_down	PORTRAIT00_RAMBO
		ptr_load			_script97_msg09
		msg_draw_up			; [Your Command has\abandoned you.\Do you still\protect them?]
		ptr_load			_script97_msg09A
		msg_draw_up			; [You must make\contact,otherwise\your friend will be\killed.]
_script97_loc00:
		ptr_load			_script97_msg0a
		msg_draw_up			; [Make a radio call.]
		input_2_options
		ptr_load			_script97_msg0b
		msg_draw_down		; [ ...\ \ \ 220...56..please]
		jmpne_option		$01, _script97_loc01
		jump				_script97_loc00
		------------------
_script97_loc01:
		sprite_draw_up		PORTRAIT_CLEAR
		ptr_load			_script97_msg0c
		msg_draw_up			; [..Report your\position and\status..]
		sprite_draw_up		PORTRAIT0E_PADOVSKY
		ptr_load			_script97_msg0d
		msg_draw_up			; [Answer it,if you\don't wanna see\your friend die.]
		sprite_draw_up		PORTRAIT_CLEAR
		ptr_load			_script97_msg0e
		msg_draw_up			; [John,it's me.\Answer.]
		ptr_load			_script97_msg0f
		msg_draw_down		; [Where is Murdock?]
		ptr_load			_script97_msg10
		msg_draw_up			; [He is here.\Give us the\position.We'll\come to pick\you up.]
		sprite_draw_down	PORTRAIT01_RAMBO_ANGRY
		ptr_load			_script97_msg11
		msg_draw_down		; [I'm coming to\terminate you.]
		set_room_idx		$9f
		stop
_script98:
		checkpoint_set
		frame_draw_up		PORTRAIT12_VILLAGER1
		jmp_flags_not_set	FLAG0C_SYS, _script98_loc00
		jmp_branch			_script98_loc01
_script98_loc00:
		ptr_load			_script98_msg00
		msg_draw_up			; [Hello!] [-MORE TEXT-]
		set_room_idx		$0c
		stop
		------------------
_script98_loc01:
		jmp_flags_not_set	FLAG07_DRESS_ITEM, _script98_loc02
		jump				_script98_loc03
		------------------
_script98_loc02:
		ptr_load			_script98_msg01
		msg_draw_up			; [Oh,what's on your\mind,just let me\know.Would you like\to buy this dress?]
		frame_draw_down		PORTRAIT03_CO
		input_2_options
		ptr_load			_script98_msg02
		msg_draw_down		; [ I can't go without\ this rifle.\ \ Oh,this is a\ beautiful dress.]
		jmpne_option		$01, _script98_loc03
		ptr_load			_script98_msg03
		msg_draw_up			; [Hmm,I'm sorry.] [-MORE TEXT-]
		set_room_idx		$0c
		stop
		------------------
_script98_loc03:
		ptr_load			_script98_msg04
		msg_draw_up			; [You look good in\the dress.]
		game_flags_set		FLAG07_DRESS_ITEM
		set_room_idx		$0c
		stop
_script99:
		checkpoint_set
		frame_draw_up		PORTRAIT13_VILLAGER2
		jmp_flags_not_set	FLAG02_KID_SAVED, _script99_loc00
		jump				_script99_loc02
		------------------
_script99_loc00:
		jmp_flags_not_set	FLAG04_KID_TAKEN, _script99_loc01
		jump				_script99_loc02
		------------------
_script99_loc01:
		ptr_load			_script99_msg00
		msg_draw_up			; [A kid is missing\in a cave to the\north.\Please find him.]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script99_msg01
		msg_draw_down		; [...]
		sprite_draw_up		PORTRAIT03_CO
		ptr_load			_script99_msg02
		msg_draw_up			; [Rambo,please save\the kid.]
		game_flags_set		FLAG00_SYS
		set_room_idx		$3a
		stop
_script99_loc02:
		ptr_load			_script99_msg03
		msg_draw_up			; [Thank you for\saving the kid.\Please rest.]
		life_restore
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script99_msg04
		msg_draw_down		; [I can't stay here\for a long time.\I must go.]
		game_flags_clear	FLAG04_KID_TAKEN
		game_flags_set		FLAG02_KID_SAVED
		set_room_idx		$3a
		stop
_script9A:
		checkpoint_set
		frame_draw_up		PORTRAIT12_VILLAGER1
		jmp_flags_not_set	FLAG0A_MISSION_TIME_OVER, _script9A_loc00
		ptr_load			_script9A_msg00
		msg_draw_up			; [Why did you come\here?] [-MORE TEXT-]
		game_flags_set		FLAG13_SYS
		set_room_idx		$0c
		stop
		------------------
_script9A_loc00:
		jmp_flags_not_set	FLAG03_LAMP_ITEM, _script9A_loc01
		jump				_script9A_loc03
		------------------
_script9A_loc01:
		ptr_load			_script9A_msg00
		msg_draw_up			; [Why did you come\here?]
		jmp_flags_not_set	FLAG00_SYS, _script9A_loc02
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script9A_msg02
		msg_draw_down		; [I want to save the\kid in the cave.]
		jmp_branch			_script9A_loc03
_script9A_loc02:
		set_room_idx		$3a
		stop
		------------------
_script9A_loc03:
		game_flags_set		FLAG03_LAMP_ITEM
		ptr_load			_script9A_msg03
		msg_draw_up			; [Take this lamp.] [-MORE TEXT-]
		set_room_idx		$3a
		stop
_script9B:
		checkpoint_set
		frame_draw_up		PORTRAIT13_VILLAGER2
		jmp_flags_not_set	FLAG0C_SYS, _script9B_loc00
		ptr_load			_script9B_msg00
		msg_draw_up			; [An American spy was\caught.] [-MORE TEXT-]
		jmp_branch			_script9B_loc01
_script9B_loc00:
		jump				_script9B_loc04
		------------------
_script9B_loc01:
		frame_draw_down		PORTRAIT03_CO
		ptr_load			_script9B_msg01
		msg_draw_down		; [I wanna take him\out.]
		jmp_flags_not_set	FLAG0D_SYS, _script9B_loc02
		jmp_branch			_script9B_loc03
_script9B_loc02:
		add_5_potions
		------------------
_script9B_loc03:
		game_flags_set		FLAG0D_SYS
		ptr_load			_script9B_msg02
		msg_draw_up			; [Take this medicine\and give it to him.]
		set_room_idx		$0c
		stop
_script9B_loc04:
		ptr_load			_script9B_msg03
		msg_draw_up			; [You look tired.\Rest here for a\while.]
		frame_draw_down		PORTRAIT00_RAMBO
		life_restore
		ptr_load			_script9B_msg04
		msg_draw_down		; [Thanks.\I'm able to fight\again.]
		set_room_idx		$0c
		stop
_script9C:
		checkpoint_set
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_script9C_msg00
		msg_draw_up			; [We're safe for now.\What are you going\to do?\Going to Thailand?]
		ptr_load			_script9C_msg00A
		msg_draw_up			; [Then America?\Would you please\take me with you?]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script9C_msg01
		msg_draw_down		; [You're in danger\here.Let's go back\together.]
		sprite_draw_up		PORTRAIT04_CO_HAPPY
		ptr_load			_script9C_msg02
		msg_draw_up			; [Thank you...\I'm so happy...\Let's go.They're\coming up behind\us.]
		sprite_draw_up		PORTRAIT_CLEAR
		ptr_load			_script9C_msg03
		msg_draw_up			; [Ugh!]
		sprite_draw_up		PORTRAIT05_CO_SAD
		ptr_load			_script9C_msg04
		msg_draw_down		; [Co.Are you all\right?]
		ptr_load			_script9C_msg05
		msg_draw_up			; [Rambo,I can't go\with you.]
		ptr_load			_script9C_msg06
		msg_draw_down		; [You're going with\me to the States.]
		game_flags_set		FLAG12_BANDANA
		sprite_draw_up		PORTRAIT06_CO_DEAD
		ptr_load			_script9C_msg07
		msg_draw_up			; [Rambo,thank you.\Please don't forget\me.]
		ptr_load			_script9C_msg08
		msg_draw_down		; [Co!]
		game_flags_clear	FLAG09_CO_TAKEN
		set_room_idx		$48
		stop
_script9D:
		checkpoint_set
		ptr_load			_script9D_msg00
		msg_printf			$20e7	; [Rambo found the key\to the helicopter.]
		jmp_flags_not_set	FLAG10_HELI_KEY, _script9D_loc00
		msg_input_handler
		set_room_idx		$55
		stop
		------------------
_script9D_loc00:
		ptr_load			_script9D_msg01
;		msg_printf			$2127	; [Sergeant Yashin\came up there.]
; BUG. in the US version this message overwrites the second line
; of upper message because offsets are from japanese version, but
; there the message above is single lined. althoug they knew this issue!
; bug "fixed" somehow with adding an extra spaces to the following message
; to effectively erase the previous one! instead of just moving the
; message one line down!
; FIX
		msg_printf			$2167	; [Sergeant Yashin\came up there.]
		msg_input_handler
		frame_draw_up		PORTRAIT0F_YUSIN
		ptr_load			_script9D_msg02
		msg_draw_up			; [It's time for\you to die.]
		game_flags_set		FLAG10_HELI_KEY
		set_room_idx		$55
		stop
_script9E:
		checkpoint_set
		jmp_flags_not_set	FLAG10_HELI_KEY, _script9E_loc00
		jmp_branch			_script9E_loc01
_script9E_loc00:
		ptr_load			_script9E_msg00
		msg_printf			$20e7	; [You can't fly\without the key to\the helicopter.]
		msg_input_handler
		set_room_idx		$54
		stop
		------------------
_script9E_loc01:
		game_flags_set		FLAG08_SYS
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script9E_msg01
		msg_draw_down		; [Let's go to the\camp and rescue\them.]
		jmp_flags_not_set	FLAG09_CO_TAKEN, _script9E_loc02
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_script9E_msg02
		msg_draw_up			; [Rambo,jump on\quickly.]
		------------------
_script9E_loc02:
		game_flags_clear	FLAG06_POW_TAKEN
		player_pos_set		$03, $80
		set_room_idx		$54
		anim_scene_set		$7f
		stop
_script9F:
		ptr_load			_script9F_msg00
		msg_printf			$20e7	; [Meanwhile,Co,\to save Rambo...]
		msg_input_handler
		game_flags_clear	FLAG06_POW_TAKEN
		game_flags_clear	FLAG00_SYS
		game_flags_set		FLAG0C_SYS
		game_flags_set		FLAG09_CO_TAKEN
		game_flags_set		FLAG13_SYS
		set_room_idx		$0c
		player_pos_set		$00, $d0
		stop
_scriptA0:
		checkpoint_set
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_scriptA0_msg00
		msg_draw_down		; [Are you alright?\I came here to get\you home.]
		frame_draw_up		PORTRAIT07_BANKS_POW
		ptr_load			_scriptA0_msg01
		msg_draw_up			; [I'm weak.\I think I'm dying.]
		ptr_load			_scriptA0_msg02
		msg_draw_down		; [Be strong!\We can make it!\Hurry,let's get out\of here.]
		game_flags_set		FLAG06_POW_TAKEN
		set_room_idx		$77
		stop
_scriptA1:
		checkpoint_set
		frame_draw_up		PORTRAIT07_BANKS_POW
		ptr_load			_scriptA1_msg00
		msg_draw_up			; [Please rescue me.]
		frame_draw_down		PORTRAIT00_RAMBO
		input_2_options
		ptr_load			_scriptA1_msg01
		msg_draw_down		; [ All right.\ \ \ Sorry,my duty is\ just to take photos.]
		jmpne_option		$02, _scriptA1_loc00
		ptr_load			_scriptA1_msg02
		msg_draw_up			; [Didn't you come\here to save us.\Please take us out.]
		game_flags_set		FLAG05_PHOTO_ITEM
		set_room_idx		$30
		stop
		------------------
_scriptA1_loc00:
		ptr_load			_scriptA1_msg03
		msg_draw_up			; [I'm free.\There are some\more.]
		game_flags_set		FLAG06_POW_TAKEN
		------------------
		ptr_load			_scriptA1_msg04
		msg_draw_down		; [I'll be back.\Let's get out of\here.]
		set_room_idx		$30
		stop
_scriptA2:
		checkpoint_set
		game_flags_clear	FLAG00_SYS
		frame_draw_down		PORTRAIT00_RAMBO
		jmp_flags_not_set	FLAG06_POW_TAKEN, _scriptA2_loc00
		ptr_load			_scriptA2_msg00
		msg_draw_down		; [Get on the chopper!\Quick!]
		jmp_branch			_scriptA2_loc01
_scriptA2_loc00:
		jump				_scriptA2_loc02
		------------------
_scriptA2_loc01:
		frame_draw_up		PORTRAIT07_BANKS_POW
		ptr_load			_scriptA2_msg01
		msg_draw_up			; [Good-bye 'Nam.]
		anim_scene_set		$7e
		set_room_idx		$77
		stop
_scriptA2_loc02:
		ptr_load			_scriptA2_msg02
		msg_draw_down		; [There must be some\more.\Let's take them\out.]
		jmp_flags_not_set	FLAG09_CO_TAKEN, _scriptA2_loc03
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_scriptA2_msg03
		msg_draw_up			; [I'll help you.]
		jmp_branch			_scriptA2_loc04
_scriptA2_loc03:
		set_room_idx		$77
		stop
		------------------
_scriptA2_loc04:
		ptr_load			_scriptA2_msg04
		msg_draw_down		; [You'd better stay\here in the\chopper.]
		set_room_idx		$77
		stop
_scriptA3:
		frame_draw_up		PORTRAIT09_MURDOCK
		jmp_flags_not_set	FLAG06_POW_TAKEN, _scriptA3_loc00
		ptr_load			_scriptA3_msg00
		msg_draw_up			; [I don't make\orders.I take them\just like you.]
		jmp_branch			_scriptA3_loc01
_scriptA3_loc00:
		jump				_scriptA3_loc02
		------------------
_scriptA3_loc01:
		sprite_draw_up		PORTRAIT0B_MURDOCK_SAD
		ptr_load			_scriptA3_msg01
		msg_draw_up			; [I swear to God,\this wasn't\supposed to happen.]
		ptr_load			_scriptA3_msg02
		msg_draw_up			; [It was just\supposed to be\another\assignment.]
		frame_draw_down		PORTRAIT01_RAMBO_ANGRY
		ptr_load			_scriptA3_msg03
		msg_draw_down		; [Mission\accomplished.]
		sprite_draw_down	PORTRAIT00_RAMBO
		ptr_load			_scriptA3_msg04
		msg_draw_down		; [There are more men\out there.\Find them,or I'll\find you.]
		game_flags_set		FLAG00_SYS
		set_room_idx		$62
		stop
_scriptA3_loc02:
		jmp_flags_not_set	FLAG05_PHOTO_ITEM, _scriptA3_loc03
		ptr_load			_scriptA3_msg05
		msg_draw_up			; [Good job,Rambo.\I'm keeping our\deal,you can go\wherever you want.]
		jmp_branch			_scriptA3_loc04
_scriptA3_loc03:
		jump				_scriptA3_loc05
		------------------
_scriptA3_loc04:
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_scriptA3_msg06
		msg_draw_down		; [Aren't you going to\rescue the POW's?]
		ptr_load			_scriptA3_msg07
		msg_draw_up			; [No,those photos\were useless as\evidence.]
		set_room_idx		$62
		stop
_scriptA3_loc05:
		sprite_draw_up		PORTRAIT0A_MURDOCK_ANGRY
		ptr_load			_scriptA3_msg08
		msg_draw_up			; [The mission was\a failure.I knew\you couldn't do it.]
		set_room_idx		$62
		stop
_scriptA4:
		frame_draw_up		PORTRAIT08_TRAUMAN1
		jmp_flags_not_set	FLAG06_POW_TAKEN, _scriptA4_loc00
		jmp_branch			_scriptA4_loc01
_scriptA4_loc00:
		jump				_scriptA4_loc04
		------------------
_scriptA4_loc01:
		jmp_flags_not_set	FLAG00_SYS, _scriptA4_loc02
		jump				_scriptA4_loc03
		------------------
_scriptA4_loc02:
		ptr_load			_scriptA4_msg00
		msg_draw_up			; [Good job,Rambo.]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_scriptA4_msg01
		msg_draw_down		; [...]
		set_room_idx		$61
		stop
_scriptA4_loc03:
		ptr_load			_scriptA4_msg02
		msg_draw_up			; [You're tougher\then I thought.Now,\you're free.]
		ptr_load			_scriptA4_msg03
		msg_draw_up			; [John,where are you\going?]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_scriptA4_msg04
		msg_draw_down		; [I don't know.]
		ptr_load			_scriptA4_msg05
		msg_draw_up			; [This is a second\Medal of Honor for\you.]
		ptr_load			_scriptA4_msg06
		msg_draw_down		; [You should give it\to them.]
		ptr_load			_scriptA4_msg07
		msg_draw_up			; [You're free now.\Come back with us.]
		ptr_load			_scriptA4_msg08
		msg_draw_down		; [What's there for\me?\My friends died\here,and a piece of\me did to.]
		ptr_load			_scriptA4_msg09
		msg_draw_up			; [The war,everything\that happened maybe\it's wrong.]
		ptr_load			_scriptA4_msg09A
		msg_draw_up			; [Don't hate\your country for\what you've been\through.]
		ptr_load			_scriptA4_msg0a
		msg_draw_down		; [Hate?\I'd die for it.]
		ptr_load			_scriptA4_msg0b
		msg_draw_up			; [So,what do you\want.]
		ptr_load			_scriptA4_msg0c
		msg_draw_down		; [I want what they\want...\every other guy\who came over here,]
		ptr_load			_scriptA4_msg0cA
		msg_draw_down		; [I want for\my country to love\me as much as\I love it.]
		ptr_load			_scriptA4_msg0d
		msg_draw_down		; [That's what I want.]
		ptr_load			_scriptA4_msg0e
		msg_draw_up			; [What are you going\to do?]
		ptr_load			_scriptA4_msg0f
		msg_draw_down		; [Day by day.]
		set_room_idx		$b1
		sprite_draw_up		PORTRAIT_CLEAR
		sprite_draw_down	PORTRAIT02_RAMBO_HAPPY
		stop
_scriptA4_loc04:
		ptr_load			_scriptA4_msg10
		msg_draw_up			; [Welcome back.\But the game is not\over.John,are you\satisfied?]
		frame_draw_down		PORTRAIT00_RAMBO
		input_2_options
		ptr_load			_scriptA4_msg11
		msg_draw_down		; [ Let me try again.\ \ \ I don't want to do\ that again.]
		jmpne_option		$02, _scriptA4_loc05
		set_room_idx		$61
		stop
		------------------
_scriptA4_loc05:
		ptr_load			_scriptA4_msg12
		msg_draw_up			; [The real purpose of\the game is to save\the POW.]
		jmp_flags_not_set	FLAG08_SYS, _scriptA4_loc06
		set_room_idx		$9e
		player_pos_set		$03, $d0
		stop
		------------------
_scriptA4_loc06:
		game_flags_clear	FLAG13_SYS
		game_flags_set		FLAG09_CO_TAKEN
; here is the main difference between US and JP scripts, the US version return you directly
; to the POW cell, while the JP version return you to the evacuation point where you need
; to return all the way back to the POW by yourself
		set_room_idx		$30
		player_pos_set		$01, $80
; JP version
;		set_room_idx		$95
		stop
_scriptA5:
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_scriptA5_msg00
		msg_draw_up			; [What are you doing?\Going to\the States?]
		ptr_load			_scriptA5_msg01
		msg_draw_up			; [Warm people.\Warm city.\Warm days.]
		ptr_load			_scriptA5_msg01A
		msg_draw_up			; [I've been dreaming\of living in the\USA and having a\simple life.If you\don't mind...]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_scriptA5_msg02
		msg_draw_down		; [I think I learned\something important\from you.I may be\able to live,\or love...]
		sprite_draw_up		PORTRAIT04_CO_HAPPY
		sprite_draw_down	PORTRAIT02_RAMBO_HAPPY
		ptr_load			_scriptA5_msg03
		msg_draw_up			; [Really?\I love you.]
		life_restore
		set_room_idx		$61
		stop
_scriptA6:
		set_room_idx		$62
		player_pos_set		$00, $d0
		stop
_scriptA7:
		set_room_idx		$77
		player_pos_set		$03, $d0
		stop
_scriptA8:
		jmp_flags_not_set	FLAG0E_BOAT,	_scriptA8_loc00
		set_room_idx		$0d
		stop
		------------------
_scriptA8_loc00:
		set_room_idx		$13
		stop
_scriptA9:
;		ptr_load			_scriptA9_msg00
;		msg_printf			$20e7	; [-MISSING-]
;		msg_input_handler
;		frame_draw_down		PORTRAIT08_TRAUMAN1
;		ptr_load			_scriptA9_msg01
;		msg_draw_down		; [-MISSING-]
;		frame_draw_up		PORTRAIT09_MURDOCK
;		ptr_load			_scriptA9_msg02
;		msg_draw_up			; [-MISSING-]
;		ptr_load			_scriptA9_msg03
;		msg_draw_down		; [-MISSING-]
;		ptr_load			_scriptA9_msg04
;		msg_draw_up			; [-MISSING-]
;		ptr_load			_scriptA9_msg05
;		msg_draw_up			; [-MISSING-]
;		sprite_draw_down	PORTRAIT0C_TRAUMAN2
;		ptr_load			_scriptA9_msg06
;		msg_draw_down		; [-MISSING-]
;		sprite_draw_down	PORTRAIT08_TRAUMAN1
;		ptr_load			_scriptA9_msg07
;		msg_draw_up			; [-MISSING-]
;		ptr_load			_scriptA9_msg08
;		msg_draw_down		; [-MISSING-]
		set_room_idx		$97
		stop
_scriptAA:
		jmp_flags_not_set	FLAG09_CO_TAKEN, _scriptAA_loc00
		jmp_branch			_scriptAA_loc01
_scriptAA_loc00:
		set_room_idx		$06
		stop
		------------------
_scriptAA_loc01:
		jmp_flags_not_set	FLAG0E_BOAT,	_scriptAA_loc02
		ptr_load			_scriptAA_msg00
		msg_printf			$20e7	; [Rambo and Co on\the boat...]
		msg_input_handler
		set_room_idx		$0d
		player_pos_set		$02, $b1
		stop
		------------------
_scriptAA_loc02:
		set_room_idx		$10
		stop
_scriptAB:
		jmp_flags_not_set	FLAG01_SYS, _scriptAB_loc00
		set_room_idx		$10
		stop
		------------------
_scriptAB_loc00:
		jmp_flags_not_set	FLAG0E_BOAT,	_scriptAB_loc01
		set_room_idx		$10
		stop
		------------------
_scriptAB_loc01:
		set_room_idx		$06
		stop
_scriptAC:
		frame_draw_up		PORTRAIT0D_ERICSON
		jmp_flags_not_set	FLAG08_SYS, _scriptAC_loc00
		jmp_branch			_scriptAC_loc01
_scriptAC_loc00:
		ptr_load			_scriptAC_msg00
		msg_draw_up			; [I'm Ericson.\I'm glad to work\with you.]
		set_room_idx		$01
		stop
		------------------
_scriptAC_loc01:
		ptr_load			_scriptAC_msg01
		msg_draw_up			; [We've no time.\Go to\Trautman soon.]
		set_room_idx		$01
		stop
_scriptAD:
		frame_draw_up		PORTRAIT07_BANKS_POW
		ptr_load			_scriptAD_msg00
		msg_draw_up			; [Thank you Rambo.\We knew that\you would save\them.]
		set_room_idx		$62
		stop
_scriptAE:
		jmp_flags_not_set	FLAG0C_SYS, _scriptAE_loc00
		ptr_load			_scriptAE_msg00
		msg_printf			$20e7	; [Co went to the camp\to help Rambo.]
		msg_input_handler
		set_room_idx		$6f
		stop
		------------------
_scriptAE_loc00:
		set_room_idx		$34
		stop
_scriptAF:
		game_flags_set		FLAG14_FLY_FORTRESS_DEAD
		set_room_idx		$77
		player_pos_set		$03, $d0
		stop
_scriptB0:
		jmp_flags_not_set	FLAG14_FLY_FORTRESS_DEAD, _scriptB0_loc00
		set_room_idx		$77
		player_pos_set		$03, $d0
		stop
		------------------
_scriptB0_loc00:
		jmp_flags_not_set	FLAG06_POW_TAKEN, _scriptB0_loc01
		set_room_idx		$ff
		stop
		------------------
_scriptB0_loc01:
		set_room_idx		$77
		player_pos_set		$03, $d0
		stop
_scriptB1:
		frame_draw_up		PORTRAIT00_RAMBO
		ptr_load			_scriptB1_msg00
		msg_printf			$20aa	; [Rambo\ \ The battle is\ over,but...]
		ending_anim
;		frame_draw_down		PORTRAIT08_TRAUMAN1
;		ptr_load			_scriptB1_msg01
;		msg_printf			$2224	; [-MISSING-]
;		ending_anim
;		frame_draw_up		PORTRAIT09_MURDOCK
;		ptr_load			_scriptB1_msg02
;		msg_printf			$20aa	; [-MISSING-]
;		ending_anim
;		frame_draw_down		PORTRAIT0D_ERICSON
;		ptr_load			_scriptB1_msg03
;		msg_printf			$2224	; [-MISSING-]
;		ending_anim
;		set_room_idx		$b2
;		stop
_scriptB2:
;		frame_draw_up		PORTRAIT03_CO
;		ptr_load			_scriptB2_msg00
;		msg_printf			$20aa	; [-MISSING-]
;		ending_anim
;		frame_draw_down		PORTRAIT07_BANKS_POW
;		ptr_load			_scriptB2_msg01
;		msg_printf			$2224	; [-MISSING-]
;		ending_anim
;		frame_draw_up		PORTRAIT14_PIRATE
;		ptr_load			_scriptB2_msg02
;		msg_printf			$20aa	; [-MISSING-]
;		ending_anim
;		frame_draw_down		PORTRAIT15_KID
;		ptr_load			_scriptB2_msg03
;		msg_printf			$2224	; [-MISSING-]
;		ending_anim
;		set_room_idx		$b3
;		stop
_scriptB3:
;		frame_draw_up		PORTRAIT10_SOLDIER1
;		ptr_load			_scriptB3_msg00
;		msg_printf			$20aa	; [-MISSING-]
;		ending_anim
;		frame_draw_down		PORTRAIT11_SOLDIER2
;		ptr_load			_scriptB3_msg01
;		msg_printf			$2224	; [-MISSING-]
;		ending_anim
;		frame_draw_up		PORTRAIT12_VILLAGER1
;		ptr_load			_scriptB3_msg02
;		msg_printf			$20aa	; [-MISSING-]
;		ending_anim
;		frame_draw_down		PORTRAIT13_VILLAGER2
;		ptr_load			_scriptB3_msg03
;		msg_printf			$2224	; [-MISSING-]
;		ending_anim
;		set_room_idx		$b4
;		stop
_scriptB4:
;		frame_draw_up		PORTRAIT0E_PADOVSKY
;		ptr_load			_scriptB4_msg00
;		msg_printf			$20aa	; [-MISSING-]
;		ending_anim
;		frame_draw_down		PORTRAIT0F_YUSIN
;		ptr_load			_scriptB4_msg01
;		msg_printf			$2224	; [-MISSING-]
;		ending_anim
		set_room_idx		$b5
		stop
_scriptB5:
		ptr_load			_scriptB5_msg00
		msg_printf			$230d	; [Thank you\for trying.]
		ending_anim
		sprite_draw_down	PORTRAIT02_RAMBO_HAPPY
		set_room_idx		$80
		scroller
		stop

_script80_msg00:
		.BYTE _R,_A,_M,_B,_O,_rig,__,_I,_S,__,_A,__,_R,_E,_G,_I,_S,_T,_E,_R,_E,_D,_eol
		.BYTE _T,_R,_A,_D,_E,_M,_A,_R,_K,__,_O,_F,__,_C,_A,_R,_O,_L,_C,_O,_eol
		.BYTE _P,_I,_C,_T,_U,_R,_E,_S,__,_I,_N,_C,_dot,_cop,__,_1,_9,_8,_5,_col,_1,_9,_8,_8,_eol
		.BYTE _C,_A,_R,_O,_L,_C,_O,_dot,_A,_L,_L,__,_R,_I,_G,_H,_T,_S,__,_R,_E,_S,_E,_R,_V,_E,_D,_dot,_eol
		.BYTE _eof
_script80_msg01:
		.BYTE _U,_N,_A,_U,_T,_H,_O,_R,_I,_Z,_E,_D,__,_D,_U,_P,_L,_I,_C,_A,_T,_I,_O,_N,_eol
		.BYTE _I,_S,__,_S,_T,_R,_I,_C,_T,_L,_Y,__,_P,_R,_O,_H,_I,_B,_I,_T,_E,_D,_dot,_eol
		.BYTE _eof
_script80_msg02:
		.BYTE _N,_I,_N,_T,_E,_N,_D,_O,__,_V,_E,_R,_S,_I,_O,_N,__,_cop,__,_1,_9,_8,_8,_eol
		.BYTE _P,_A,_C,_K,_dsh,_I,_N,_dsh,_V,_I,_D,_E,_O,__,_C,_O,_dot,_col,_L,_T,_D,_dot,_eol
		.BYTE _eof
_script80_msg03:
		.BYTE _L,_I,_C,_E,_N,_C,_E,_D,__,_A,_N,_D,__,_C,_O,_N,_T,_R,_O,_L,_L,_E,_D,__,_F,_O,_R,_eol
		.BYTE _T,_H,_E,__,_U,_N,_I,_T,_E,_D,__,_S,_T,_A,_T,_E,_S,__,_A,_N,_D,__,_C,_A,_N,_A,_D,_A,_eol
		.BYTE _B,_Y,__,_A,_C,_C,_L,_A,_I,_M,__,_E,_N,_T,_E,_R,_T,_A,_I,_N,_M,_E,_N,_T,_col,_I,_N,_C,_dot,_eol
		.BYTE _eof
_script80_msg03A:
		.BYTE _L,_I,_C,_E,_N,_S,_E,_D,__,_B,_Y,__,_N,_I,_N,_T,_E,_N,_D,_O,__,_O,_F,_eol
		.BYTE _A,_M,_E,_R,_I,_C,_A,_col,_I,_N,_C,_dot,_eol
		.BYTE _eof
_script81_msg00:
		.BYTE _R,_E,_N,_D,__,_T,_H,_E,__,_F,_E,_E,_L,_I,_N,_G,_S,__,_O,_F,__,_H,_E,_A,_R,_T,_eol
		.BYTE __,__,_W,_I,_T,_H,__,_P,_A,_I,_N,_F,_U,_L,__,_F,_E,_E,_L,_I,_N,_G,_S,_eol
		.BYTE _eof
_script81_msg01:
		.BYTE _S,_T,_A,_R,_T,_eol
		.BYTE _C,_O,_N,_T,_I,_N,_U,_E,_eol
		.BYTE _eof
_script81_msg02:
		.BYTE _D,_I,_R,_E,_C,_T,_O,_R,_ap,_S,__,_C,_U,_T,_eol
		.BYTE _eof
_script81_msg03:
		.BYTE _cop,_2,_0,_2,_1,__,_C,_A,_H,_4,_E,_3,__,_B,_F,_S,__,_G,_M,_B,_H,_eol
		.BYTE _eof
_script82_msg00:
		.BYTE _I,_n,_p,_u,_t,__,_M,_i,_s,_s,_i,_o,_n,__,_C,_o,_d,_e,_eol
		.BYTE _eof
_script82_msg01:
		.BYTE _0,__,_1,__,_2,__,_3,__,_4,__,_5,__,_6,__,_7,__,_8,__,_9,_eol
		.BYTE _A,__,_B,__,_C,__,_D,__,_E,__,_F,__,_G,__,_H,__,_I,__,_J,_eol
		.BYTE _K,__,_L,__,_M,__,_N,__,_O,__,_P,__,_Q,__,_R,__,_S,__,_T,_eol
		.BYTE _U,__,_V,__,_W,__,_X,__,_Y,__,_Z,_eol
		.BYTE _a,__,_b,__,_c,__,_d,__,_e,__,_f,__,_g,__,_h,__,_i,__,_j,_eol
		.BYTE _k,__,_l,__,_m,__,_n,__,_o,__,_p,__,_q,__,_r,__,_s,__,_t,_eol
		.BYTE _u,__,_v,__,_w,__,_x,__,_y,__,_z,__,_qe,__,_ex,_eol
		.BYTE _B,_S,__,__,_S,_P,__,__,_E,_N,_D,_eol
		.BYTE _eof
_script82_msg02:
		.BYTE _C,_o,_d,_e,__,_E,_r,_r,_o,_r,_eol
		.BYTE _eof
_script82_msg03:
		.BYTE _S,_T,_A,_R,_T,_eol
		.BYTE _C,_O,_N,_T,_I,_N,_U,_E,_eol
		.BYTE _eof
_script83_msg00:
		.BYTE _L,_I,_F,_E,__,__,__,__,__,__,__,__,_ls,_M,_A,_X,__,__,__,__,__,__,_rs,_eol
		.BYTE _E,_X,_P,__,__,__,__,__,__,__,__,__,_ls,_N,_E,_X,_T,__,__,__,__,__,_rs,_eol
		.BYTE _T,_I,_M,_E,_eol
		.BYTE _eof
_script83_msg01:
		.BYTE _I,_N,_V,_E,_N,_T,_O,_R,_Y,_eol
		.BYTE _eof
_script83_msg02:
		.BYTE _C,_O,_eol
		.BYTE _eof
_script83_msg03:
		.BYTE _B,_O,_A,_T,_eol
		.BYTE _eof
_script83_msg04:
		.BYTE _L,_A,_M,_P,_eol
		.BYTE _eof
_script83_msg05:
		.BYTE _K,_I,_D,_eol
		.BYTE _eof
_script83_msg06:
		.BYTE _P,_H,_O,_T,_O,_eol
		.BYTE _eof
_script83_msg07:
		.BYTE _P,_O,_W,_eol
		.BYTE _eof
_script83_msg08:
		.BYTE _D,_R,_E,_S,_S,_eol
		.BYTE _eof
_script83_msg09:
		.BYTE _K,_E,_Y,_eol
		.BYTE _eof
_script83_msg0a:
		.BYTE _P,_E,_N,_D,_A,_N,_T,_eol
		.BYTE _eof
_script83_msg0b:
		.BYTE _B,_A,_N,_D,_A,_N,_A,_eol
		.BYTE _eof
_script83_msg0c:
		.BYTE _M,_I,_S,_S,_I,_O,_N,__,_C,_O,_D,_E,_eol
		.BYTE _eof
_script84_msg00:
		.BYTE _G,_A,_M,_E,__,_O,_V,_E,_R,_eol
		.BYTE _eof
_script84_msg01:
		.BYTE _C,_O,_N,_T,_I,_N,_U,_E,_eol
		.BYTE _S,_T,_A,_R,_T,_eol
		.BYTE _eof
_script85_msg00:
		.BYTE _C,_o,_l,_o,_n,_e,_l,__,_T,_r,_a,_u,_t,_m,_a,_n,_eol
		.BYTE _v,_i,_s,_i,_t,_s,__,_R,_a,_m,_b,_o,__,_i,_n,__,_t,_h,_e,_eol
		.BYTE _m,_i,_l,_i,_t,_a,_r,_y,__,_p,_r,_i,_s,_o,_n,_dot,_eol
		.BYTE _eof
_script85_msg01:
		.BYTE _R,_a,_m,_b,_o,_col,_I,__,_w,_a,_n,_t,__,_t,_o,_eol
		.BYTE _s,_e,_n,_d,__,_y,_o,_u,__,_o,_n,_eol
		.BYTE _a,__,_M,_i,_s,_s,_i,_o,_n,_dot,_eol
		.BYTE _eof
_script85_msg01A:
		.BYTE _I,_t,_ap,_s,__,_d,_a,_n,_g,_e,_r,_o,_u,_s,_col,_b,_u,_t,_eol
		.BYTE _y,_o,_u,_ap,_l,_l,__,_b,_e,__,_f,_r,_e,_e,_eol
		.BYTE _i,_f,__,_y,_o,_u,__,_s,_u,_c,_c,_e,_e,_d,_dot,_eol
		.BYTE _eof
_script85_msg02:
		.BYTE _O,_u,_r,__,_m,_e,_n,__,_a,_r,_e,__,_s,_t,_i,_l,_l,_eol
		.BYTE _m,_i,_s,_s,_i,_n,_g,_eol
		.BYTE _eof
_script85_msg02A:
		.BYTE _i,_n,__,_a,__,_j,_u,_n,_g,_l,_e,_eol
		.BYTE _i,_n,__,_V,_i,_e,_t,_n,_a,_m,_dot,_W,_e,_eol
		.BYTE _b,_e,_l,_i,_e,_v,_e,__,_t,_h,_e,_y,__,_a,_r,_e,_eol
		.BYTE _a,_l,_i,_v,_e,_col,_p,_r,_i,_s,_o,_n,_e,_r,_s,__,_o,_f,_eol
		.BYTE _t,_h,_e,__,_e,_n,_e,_m,_y,_dot,_eol
		.BYTE _eof
_script85_msg03:
		.BYTE _Y,_o,_u,_r,__,_m,_i,_s,_s,_i,_o,_n,__,_i,_s,__,_t,_o,_eol
		.BYTE _s,_n,_e,_a,_k,__,_i,_n,_t,_o,__,_t,_h,_e,_eol
		.BYTE _e,_n,_e,_m,_y,__,_c,_a,_m,_p,__,_a,_n,_d,__,_f,_i,_n,_d,_eol
		.BYTE _t,_h,_e,_m,_dot,_eol
		.BYTE _A,_r,_e,__,_y,_o,_u,__,_u,_p,__,_t,_o,__,_i,_t,_qe,_eol
		.BYTE _eof
_script85_msg04:
		.BYTE __,_I,_ap,_m,__,_n,_o,_t,__,_a,_f,_r,_a,_i,_d,__,_o,_f,_eol
		.BYTE __,_d,_e,_a,_t,_h,_dot,_eol
		.BYTE __,_eol
		.BYTE __,_I,__,_f,_e,_e,_l,__,_b,_e,_t,_t,_e,_r,__,_i,_n,_eol
		.BYTE __,_p,_r,_i,_s,_o,_n,_dot,_eol
		.BYTE _eof
_script85_msg05:
		.BYTE _G,_o,_o,_d,_col,_I,_ap,_l,_l,__,_m,_a,_k,_e,__,_t,_h,_e,_eol
		.BYTE _a,_r,_r,_a,_n,_g,_e,_m,_e,_n,_t,_s,_dot,_eol
		.BYTE _eof
_script85_msg06:
		.BYTE _B,_u,_t,__,_i,_t,_ap,_s,__,_u,_p,__,_t,_o,__,_y,_o,_u,_dot,_eol
		.BYTE _T,_h,_e,__,_g,_a,_m,_e,__,_d,_o,_e,_s,_n,_ap,_t,_eol
		.BYTE _s,_t,_a,_r,_t,__,_u,_n,_t,_i,_l,__,_y,_o,_u,_eol
		.BYTE _s,_a,_y,__,_Y,_E,_S,_dot,_eol
		.BYTE _eof
_script86_msg00:
		.BYTE _I,_ap,_m,_eol
		.BYTE _C,_o,_m,_m,_a,_n,_d,_e,_r,__,_M,_u,_r,_d,_o,_c,_k,_dot,_eol
		.BYTE _eof
_script86_msg01:
		.BYTE _W,_e,__,_w,_a,_n,_t,__,_y,_o,_u,__,_t,_o,__,_g,_e,_t,_eol
		.BYTE _i,_n,_t,_o,__,_e,_n,_e,_m,_y,_eol
		.BYTE _t,_e,_r,_r,_i,_t,_o,_r,_y,__,_a,_n,_d,__,_t,_a,_k,_e,_eol
		.BYTE _p,_h,_o,_t,_o,_g,_r,_a,_p,_h,_s,__,_o,_f,__,_t,_h,_e,_eol
		.BYTE _P,_O,_W,__,_c,_a,_m,_p,_dot,_eol
		.BYTE _eof
_script86_msg01A:
		.BYTE _Y,_o,_u,_ap,_r,_e,__,_n,_o,_t,__,_t,_o,_eol
		.BYTE _e,_n,_g,_a,_g,_e,__,_t,_h,_e,__,_e,_n,_e,_m,_y,_dot,_eol
		.BYTE _eof
_script86_msg02:
		.BYTE _P,_h,_o,_t,_o,_s,_qe,__,_N,_o,_t,__,_r,_e,_s,_c,_u,_e,_eol
		.BYTE _t,_h,_e,_m,_qe,_eol
		.BYTE _eof
_script86_msg03:
		.BYTE _I,__,_r,_e,_p,_e,_a,_t,_dot,_Y,_o,_u,_ap,_r,_e,__,_n,_o,_t,_eol
		.BYTE _t,_o,__,_e,_n,_g,_a,_g,_e,__,_t,_h,_e,_eol
		.BYTE _e,_n,_e,_m,_y,_dot,_eol
		.BYTE _eof
_script86_msg03A:
		.BYTE _G,_o,__,_t,_o,__,_t,_h,_e,__,_w,_e,_a,_p,_o,_n,_s,_eol
		.BYTE _c,_e,_n,_t,_e,_r,__,_a,_n,_d,_eol
		.BYTE _g,_e,_t,__,_r,_e,_a,_d,_y,_dot,_eol
		.BYTE _eof
_script87_msg00:
		.BYTE _W,_e,__,_c,_a,_n,_ap,_t,__,_g,_i,_v,_e,__,_y,_o,_u,_eol
		.BYTE _w,_e,_a,_p,_o,_n,_s,__,_w,_i,_t,_h,_o,_u,_t,_eol
		.BYTE _M,_u,_r,_d,_o,_c,_k,_ap,_s,_eol
		.BYTE _p,_e,_r,_m,_i,_s,_s,_i,_o,_n,_dot,_eol
		.BYTE _eof
_script87_msg01:
		.BYTE _I,__,_p,_i,_c,_k,_e,_d,__,_s,_o,_m,_e,_eol
		.BYTE _w,_e,_a,_p,_o,_n,_s,__,_f,_o,_r,_eol
		.BYTE _y,_o,_u,_r,__,_m,_i,_s,_s,_i,_o,_n,_dot,_eol
		.BYTE _eof
_script87_msg02:
		.BYTE _G,_o,__,_t,_o,__,_T,_r,_a,_u,_t,_m,_a,_n,_dot,_eol
		.BYTE _eof
_script88_msg00:
		.BYTE _R,_a,_m,_b,_o,_col,_f,_o,_r,_g,_e,_t,__,_a,_b,_o,_u,_t,_eol
		.BYTE _y,_o,_u,_r,__,_a,_b,_s,_u,_r,_d,__,_h,_a,_n,_d,_dsh,_t,_o,_eol
		.BYTE _dsh,_h,_a,_n,_d,__,_f,_i,_g,_h,_t,_i,_n,_g,_dot,_eol
		.BYTE _M,_i,_l,_i,_t,_a,_r,_y,__,_t,_e,_c,_h,_n,_o,_l,_o,_g,_y,_eol
		.BYTE _w,_i,_l,_l,__,_w,_o,_r,_k,__,_b,_e,_s,_t,_dot,_eol
		.BYTE _eof
_script88_msg02:
		.BYTE _G,_o,__,_t,_o,__,_t,_h,_e,__,_h,_a,_n,_g,_a,_r,_dot,_eol
		.BYTE _eof
_script88_msg03:
		.BYTE _T,_h,_e,_r,_e,_ap,_s,__,_a,__,_c,_o,_n,_t,_a,_c,_t,_eol
		.BYTE _m,_a,_n,__,_C,_o,_col,_o,_v,_e,_r,_eol
		.BYTE _t,_h,_e,_r,_e,_dot,_H,_e,_ap,_l,_l,__,_g,_u,_i,_d,_e,_eol
		.BYTE _y,_o,_u,__,_i,_n,__,_t,_h,_e,__,_j,_u,_n,_g,_l,_e,_dot,_eol
		.BYTE _eof
_script88_msg04:
		.BYTE _Y,_o,_u,_ap,_v,_e,__,_g,_o,_t,__,_3,_6,__,_h,_o,_u,_r,_s,_eol
		.BYTE _t,_o,__,_g,_e,_t,__,_i,_n,_col,_c,_o,_m,_p,_l,_e,_t,_e,_eol
		.BYTE _y,_o,_u,_r,__,_a,_s,_s,_i,_g,_n,_m,_e,_n,_t,_col,_eol
		.BYTE _a,_n,_d,__,_g,_e,_t,__,_t,_h,_e,__,_h,_e,_l,_l,_eol
		.BYTE _o,_u,_t,_dot,_eol
		.BYTE _eof
_script88_msg04A:
		.BYTE _I,_f,__,_y,_o,_u,__,_g,_e,_t,__,_i,_n,_eol
		.BYTE _t,_r,_o,_u,_b,_l,_e,_col,_t,_r,_y,__,_t,_o,_eol
		.BYTE _r,_e,_a,_c,_h,__,_t,_h,_e,_eol
		.BYTE _e,_x,_t,_r,_a,_c,_t,_i,_o,_n,__,_s,_i,_t,_e,_eol
		.BYTE _m,_a,_r,_k,_e,_d,__,_o,_n,__,_t,_h,_e,__,_m,_a,_p,_dot,_eol
		.BYTE _eof
_script88_msg05:
		.BYTE _R,_a,_m,_b,_o,_dtt,_dtt,_dtt,_eol
		.BYTE _G,_o,_o,_d,__,_l,_u,_c,_k,_dot,_eol
		.BYTE _eof
_script89_msg00:
		.BYTE _I,_ap,_m,__,_C,_o,_dot,_eol
		.BYTE _Y,_o,_u,__,_d,_i,_d,__,_n,_o,_t,__,_e,_x,_p,_e,_c,_t,_eol
		.BYTE _a,__,_w,_o,_m,_a,_n,_qe,_eol
		.BYTE _eof
_script89_msg00A:
		.BYTE _W,_o,_u,_l,_d,__,_y,_o,_u,__,_l,_i,_k,_e,__,_t,_o,_eol
		.BYTE _k,_n,_o,_w,__,_s,_o,_m,_e,_t,_h,_i,_n,_g,_qe,_eol
		.BYTE _eof
_script89_msg01:
		.BYTE __,_W,_h,_e,_r,_e,__,_i,_s,__,_t,_h,_e,__,_c,_a,_m,_p,_qe,_eol
		.BYTE __,_eol
		.BYTE __,_eol
		.BYTE __,_W,_h,_a,_t,__,_d,_o,__,_y,_o,_u,__,_t,_h,_i,_n,_k,_eol
		.BYTE __,_a,_b,_o,_u,_t,__,_m,_e,_qe,_eol
		.BYTE _eof
_script89_msg02:
		.BYTE _W,_h,_a,_t,_qe,_eol
		.BYTE _Y,_o,_u,__,_l,_o,_o,_k,__,_g,_o,_o,_d,_dot,_eol
		.BYTE _eof
_script89_msg03:
		.BYTE _T,_h,_e,__,_c,_a,_m,_p,__,_i,_s,__,_l,_o,_c,_a,_t,_e,_d,_eol
		.BYTE _i,_n,__,_t,_h,_e,__,_j,_u,_n,_g,_l,_e,__,_t,_o,_eol
		.BYTE _t,_h,_e,__,_E,_a,_s,_t,__,_o,_f,__,_t,_h,_e,_eol
		.BYTE _r,_i,_v,_e,_r,_dot,_eol
		.BYTE _eof
_script89_msg03A:
		.BYTE _I,_ap,_v,_e,__,_a,_r,_r,_a,_n,_g,_e,_d,_eol
		.BYTE _a,__,_b,_o,_a,_t,_dot,_L,_e,_t,_ap,_s,__,_g,_o,__,_t,_o,_eol
		.BYTE _t,_h,_e,__,_d,_o,_c,_k,_dot,_eol
		.BYTE _eof
_script8A_msg00:
		.BYTE _Y,_o,_u,_ap,_r,_e,__,_o,_u,_t,_s,_i,_d,_e,_r,_s,_col,_eol
		.BYTE _a,_r,_e,_n,_ap,_t,__,_y,_o,_u,_dot,_eol
		.BYTE _eof
_script8A_msg00A:
		.BYTE _S,_o,_r,_r,_y,_col,_w,_e,__,_c,_a,_n,_ap,_t,_eol
		.BYTE _a,_l,_l,_o,_w,__,_s,_t,_r,_a,_n,_g,_e,_r,_s,_eol
		.BYTE _t,_o,__,_g,_e,_t,__,_o,_n,__,_o,_u,_r,__,_b,_o,_a,_t,_dot,_eol
		.BYTE _eof
_script8A_msg01:
		.BYTE _W,_h,_a,_t,_qe,__,_Y,_o,_u,__,_s,_h,_o,_u,_l,_d,_eol
		.BYTE _k,_n,_o,_w,__,_u,_s,_dot,_W,_e,__,_w,_a,_n,_n,_a,_eol
		.BYTE _g,_e,_t,__,_o,_n,__,_t,_h,_e,__,_b,_o,_a,_t,_dot,_eol
		.BYTE _H,_e,_r,_e,_ap,_s,__,_m,_o,_n,_e,_y,_dot,_eol
		.BYTE _eof
_script8A_msg02:
		.BYTE _O,_K,_eol
		.BYTE _eof
_script8A_msg03:
		.BYTE _G,_e,_t,__,_o,_n,_col,_h,_u,_r,_r,_y,_dot,_eol
		.BYTE _eof
_script8B_msg00:
		.BYTE _R,_a,_m,_b,_o,_col,_s,_o,_m,_e,_t,_h,_i,_n,_g,_ap,_s,_eol
		.BYTE _s,_t,_r,_a,_n,_g,_e,_dot,_eol
		.BYTE _eof
_script8B_msg01:
		.BYTE _L,_o,_o,_k,_ex,__,_T,_h,_a,_t,_ap,_s,__,_a,_n,_eol
		.BYTE _e,_n,_e,_m,_y,__,_b,_o,_a,_t,_dot,_eol
		.BYTE _Y,_o,_u,__,_s,_o,_l,_d,__,_u,_s,_ex,_eol
		.BYTE _eof
_script8B_msg02:
		.BYTE _R,_i,_g,_h,_t,_col,_W,_e,__,_d,_o,_eol
		.BYTE _e,_v,_e,_r,_y,_t,_h,_i,_n,_g,__,_f,_o,_r,_eol
		.BYTE _m,_o,_n,_e,_y,_dot,_D,_o,_n,_ap,_t,__,_m,_o,_v,_e,_dot,_eol
		.BYTE _eof
_script8B_msg06:
		.BYTE _W,_h,_a,_t,__,_d,_o,_e,_s,__,_t,_h,_i,_s,_eol
		.BYTE _p,_e,_n,_d,_a,_n,_t,__,_m,_e,_a,_n,_qe,_eol
		.BYTE _eof
_script8B_msg07:
		.BYTE _I,_t,__,_b,_r,_i,_n,_g,_s,__,_m,_e,__,_g,_o,_o,_d,_eol
		.BYTE _l,_u,_c,_k,_dot,_eol
		.BYTE _eof
_script8B_msg09:
		.BYTE _R,_a,_m,_b,_o,_col,_k,_e,_e,_p,__,_t,_h,_i,_s,_eol
		.BYTE _p,_e,_n,_d,_a,_n,_t,_dot,_eol
		.BYTE _P,_l,_e,_a,_s,_e,__,_t,_a,_k,_e,__,_c,_a,_r,_e,_eol
		.BYTE _o,_f,__,_i,_t,_dot,_eol
		.BYTE _eof
_script8B_msg0a:
		.BYTE _N,_o,_w,_col,_h,_e,_r,_e,__,_w,_e,__,_a,_r,_e,_dot,_eol
		.BYTE _W,_e,_ap,_l,_l,__,_h,_a,_v,_e,__,_t,_o,__,_w,_a,_l,_k,_eol
		.BYTE _f,_r,_o,_m,__,_h,_e,_r,_e,_eol
		.BYTE _t,_o,__,_t,_h,_e,__,_c,_a,_m,_p,_dot,_eol
		.BYTE _eof
_script8C_msg00:
		.BYTE _L,_e,_t,_ap,_s,__,_g,_o,_eol
		.BYTE _s,_e,_a,_r,_c,_h,__,_t,_h,_e,__,_v,_i,_l,_l,_a,_g,_e,_dot,_eol
		.BYTE _Y,_o,_u,_ap,_l,_l,__,_f,_i,_n,_d,__,_i,_t,_eol
		.BYTE _i,_n,__,_t,_h,_e,__,_E,_a,_s,_t,_dot,_eol
		.BYTE _eof
_script8C_msg01:
		.BYTE _T,_h,_e,__,_c,_a,_m,_p,__,_i,_s,__,_l,_o,_c,_a,_t,_e,_d,_eol
		.BYTE _S,_o,_u,_t,_h,__,_f,_r,_o,_m,__,_h,_e,_r,_e,_dot,_eol
		.BYTE _eof
_script8C_msg02:
		.BYTE _C,_r,_o,_s,_s,__,_t,_h,_e,__,_r,_i,_v,_e,_r,_eol
		.BYTE _t,_o,__,_t,_h,_e,__,_W,_e,_s,_t,_col,_a,_n,_d,_eol
		.BYTE _c,_l,_i,_m,_b,__,_t,_h,_e,__,_h,_i,_l,_l,_col,_eol
		.BYTE _t,_h,_e,_n,__,_y,_o,_u,_ap,_l,_l,__,_f,_i,_n,_d,_eol
		.BYTE _t,_h,_e,__,_p,_i,_c,_k,_dsh,_u,_p,__,_p,_o,_i,_n,_t,_dot,_eol
		.BYTE _eof
_script8C_msg03:
		.BYTE _B,_u,_t,_col,_w,_e,_ap,_r,_e,__,_l,_a,_t,_e,_eol
		.BYTE _f,_o,_r,__,_t,_h,_e,__,_c,_o,_n,_t,_a,_c,_t,_eol
		.BYTE _t,_i,_m,_e,_dot,_eol
		.BYTE _eof
_script8C_msg03A:
		.BYTE _T,_h,_e,__,_h,_e,_l,_i,_c,_o,_p,_t,_e,_r,_eol
		.BYTE _w,_o,_n,_ap,_t,__,_c,_o,_m,_e,__,_a,_n,_y,_eol
		.BYTE _m,_o,_r,_e,_dot,_eol
		.BYTE _W,_e,_ap,_d,__,_b,_e,_t,_t,_e,_r,__,_h,_i,_d,_e,_eol
		.BYTE _i,_n,__,_t,_h,_e,__,_v,_i,_l,_l,_a,_g,_e,_dot,_eol
		.BYTE _eof
_script8D_msg00:
		.BYTE _A,_H,_H,_H,_dtt,_dtt,_dtt,_ex,_eol
		.BYTE _A,_H,_H,_dtt,_dtt,_dtt,_ex,_eol
		.BYTE _eof
_script8D_msg01:
		.BYTE _I,_ap,_l,_l,__,_h,_e,_l,_p,__,_y,_o,_u,_dot,_eol
		.BYTE _eof
_script8F_msg00:
		.BYTE _I,_ap,_m,__,_s,_o,__,_h,_a,_p,_p,_y,__,_t,_o,_eol
		.BYTE _s,_e,_e,__,_y,_o,_u,_ap,_r,_e,__,_s,_a,_f,_e,_dot,_eol
		.BYTE _eof
_script8F_msg01:
		.BYTE _W,_h,_a,_t,_qe,_eol
		.BYTE _D,_i,_d,__,_y,_o,_u,__,_t,_a,_k,_e,__,_t,_h,_e,_eol
		.BYTE _P,_O,_W,__,_o,_u,_t,_qe,_eol
		.BYTE _eof
_script8F_msg01A:
		.BYTE _Y,_o,_u,__,_w,_e,_r,_e,__,_s,_u,_p,_p,_o,_s,_e,_d,_eol
		.BYTE _t,_o,__,_t,_a,_k,_e,__,_p,_h,_o,_t,_o,_s,_eol
		.BYTE _o,_n,_l,_y,_ex,_eol
		.BYTE _eof
_script8F_msg02:
		.BYTE _L,_e,_t,_ap,_s,__,_g,_e,_t,__,_o,_u,_t,__,_o,_f,_eol
		.BYTE _h,_e,_r,_e,_col,_n,_o,_w,_ex,_eol
		.BYTE _eof
_script90_msg00:
		.BYTE _I,_ap,_l,_l,__,_g,_o,__,_a,_h,_e,_a,_d,__,_b,_y,_eol
		.BYTE _m,_y,_s,_e,_l,_f,_dot,_eol
		.BYTE _eof
_script90_msg01:
		.BYTE _I,__,_s,_e,_e,_dtt,_dtt,_dtt,_eol
		.BYTE _eof
_script91_msg00:
		.BYTE _D,_i,_d,__,_y,_o,_u,__,_c,_a,_l,_l,__,_m,_e,_qe,_eol
		.BYTE _eof
_script91_msg01:
		.BYTE _T,_h,_i,_s,__,_i,_s,__,_n,_o,__,_p,_l,_a,_c,_e,_eol
		.BYTE _f,_o,_r,__,_v,_i,_l,_l,_a,_g,_e,_r,_s,_dot,_eol
		.BYTE _eof
_script91_msg02:
		.BYTE _A,_h,_a,_dot,_eol
		.BYTE _T,_h,_i,_s,__,_w,_a,_y,__,_t,_o,__,_t,_h,_e,_eol
		.BYTE _c,_a,_p,_t,_a,_i,_n,_ap,_s,__,_q,_u,_a,_r,_t,_e,_r,_s,_dot,_eol
		.BYTE _eof
_script92_msg00:
		.BYTE _G,_o,_o,_d,__,_e,_v,_e,_n,_i,_n,_g,_dot,_eol
		.BYTE _eof
_script92_msg01:
		.BYTE _Y,_o,_u,__,_m,_u,_s,_t,__,_b,_e,__,_t,_h,_e,_eol
		.BYTE _g,_e,_n,_e,_r,_a,_l,_ap,_s,__,_w,_i,_f,_e,_dot,_eol
		.BYTE _eof
_script92_msg02:
		.BYTE __,_N,_o,_dot,_I,_ap,_m,__,_l,_o,_o,_k,_i,_n,_g,_eol
		.BYTE __,_f,_o,_r,__,_s,_o,_m,_e,_dot,_eol
		.BYTE __,_eol
		.BYTE __,_Y,_e,_s,_dot,_eol
		.BYTE _eof
_script92_msg03:
		.BYTE _G,_e,_t,__,_o,_u,_t,__,_o,_f,__,_h,_e,_r,_e,_dot,_eol
		.BYTE _eof
_script92_msg04:
		.BYTE _W,_h,_a,_t,__,_h,_a,_p,_p,_e,_n,_e,_d,_eol
		.BYTE _t,_o,_d,_a,_y,_qe,_eol
		.BYTE _eof
_script92_msg05:
		.BYTE _I,__,_c,_a,_u,_g,_h,_t,__,_a,__,_s,_p,_y,_dot,_eol
		.BYTE _eof
_script92_msg06:
		.BYTE _S,_o,_col,_y,_o,_u,__,_h,_a,_v,_e,__,_t,_h,_e,__,_k,_e,_y,_eol
		.BYTE _t,_o,__,_t,_h,_e,__,_r,_o,_o,_m,_dot,_eol
		.BYTE _eof
_script92_msg07:
		.BYTE _A,_n,_y,_t,_h,_i,_n,_g,__,_f,_o,_r,__,_t,_h,_e,_eol
		.BYTE _g,_e,_n,_e,_r,_a,_l,_ap,_s,__,_w,_i,_f,_e,_dot,_eol
		.BYTE _eof
_script92_msg08:
		.BYTE _I,__,_g,_o,_t,__,_t,_h,_e,__,_k,_e,_y,_dot,_eol
		.BYTE _eof
_script93_msg00:
		.BYTE _W,_h,_a,_t,__,_a,_r,_e,__,_y,_o,_u,__,_d,_o,_i,_n,_g,_eol
		.BYTE _h,_e,_r,_e,_qe,_eol
		.BYTE _eof
_script93_msg01:
		.BYTE _S,_o,_r,_r,_y,_dot,_eol
		.BYTE _eof
_script93_msg02:
		.BYTE _H,_e,_y,_ex,_W,_h,_e,_r,_e,__,_a,_r,_e,__,_y,_o,_u,_eol
		.BYTE _g,_o,_i,_n,_g,_qe,_eol
		.BYTE _T,_h,_e,__,_e,_x,_i,_t,__,_i,_s,__,_o,_n,__,_t,_h,_e,_eol
		.BYTE _r,_i,_g,_h,_t,_dot,_eol
		.BYTE _eof
_script93_msg03:
		.BYTE _T,_o,__,_t,_h,_e,__,_l,_e,_f,_t,__,_i,_s,__,_t,_h,_e,_eol
		.BYTE _t,_o,_r,_t,_u,_r,_e,__,_r,_o,_o,_m,_dot,_eol
		.BYTE _eof
_script94_msg00:
		.BYTE _I,_ap,_m,__,_o,_p,_e,_n,_i,_n,_g,_eol
		.BYTE _t,_h,_e,__,_d,_o,_o,_r,__,_n,_o,_w,_dot,_eol
		.BYTE _eof
_script94_msg01:
		.BYTE _T,_h,_a,_n,_k,_s,_dot,_eol
		.BYTE _eof
_script94_msg02:
		.BYTE _T,_h,_e,_y,_ap,_v,_e,__,_s,_e,_e,_n,__,_u,_s,_dot,_eol
		.BYTE _L,_e,_t,_ap,_s,__,_g,_e,_t,__,_o,_u,_t,_eol
		.BYTE _o,_f,__,_h,_e,_r,_e,__,_n,_o,_w,_dot,_eol
		.BYTE _eof
_script94_msg03:
		.BYTE _R,_a,_m,_b,_o,_col,_i,_t,_ap,_s,__,_m,_e,_dot,_eol
		.BYTE _W,_a,_i,_t,__,_a,__,_m,_i,_n,_u,_t,_e,_dot,_eol
		.BYTE _I,_ap,_m,__,_g,_o,_i,_n,_g,__,_t,_o,__,_l,_o,_o,_k,_eol
		.BYTE _f,_o,_r,__,_t,_h,_e,__,_k,_e,_y,_dot,_eol
		.BYTE _eof
_script94_msg04:
		.BYTE _dtt,_dtt,_dtt,_eol
		.BYTE _eof
_script95_msg00:
		.BYTE _R,_a,_m,_b,_o,_col,_t,_h,_e,__,_p,_i,_c,_k,_dsh,_u,_p,_eol
		.BYTE _p,_o,_i,_n,_t,__,_i,_s,__,_a,_h,_e,_a,_d,_dot,_eol
		.BYTE _eof
_script95_msg01:
		.BYTE _B,_u,_t,__,_t,_h,_e,__,_c,_o,_n,_t,_a,_c,_t,_eol
		.BYTE _t,_i,_m,_e,__,_h,_a,_s,__,_a,_l,_r,_e,_a,_d,_y,_eol
		.BYTE _p,_a,_s,_s,_e,_d,_dot,_eol
		.BYTE _eof
_script95_msg02:
		.BYTE _L,_e,_t,_ap,_s,__,_r,_e,_t,_u,_r,_n,__,_t,_o,_eol
		.BYTE _t,_h,_e,__,_j,_u,_n,_g,_l,_e,_dot,_eol
		.BYTE _eof
_script95_msg03:
		.BYTE _A,_r,_e,__,_y,_o,_u,__,_g,_o,_i,_n,_g,__,_b,_a,_c,_k,_eol
		.BYTE _w,_i,_t,_h,_o,_u,_t,__,_d,_o,_i,_n,_g,_eol
		.BYTE _a,_n,_y,_t,_h,_i,_n,_g,_qe,_eol
		.BYTE _eof
_script95_msg04:
		.BYTE _W,_e,__,_s,_t,_i,_l,_l,__,_h,_a,_v,_e,_eol
		.BYTE _t,_i,_m,_e,__,_t,_o,__,_g,_e,_t,__,_t,_o,_eol
		.BYTE _t,_h,_e,__,_c,_a,_m,_p,_dot,_eol
		.BYTE _eof
_script95_msg05:
		.BYTE _T,_h,_e,__,_c,_a,_m,_p,__,_i,_s,__,_l,_o,_c,_a,_t,_e,_d,_eol
		.BYTE _f,_a,_r,__,_S,_o,_u,_t,_h,__,_f,_r,_o,_m,_eol
		.BYTE _h,_e,_r,_e,_dot,_eol
		.BYTE _eof
_script95_msg06:
		.BYTE _C,_o,_col,_t,_h,_a,_n,_k,_s,__,_f,_o,_r,_eol
		.BYTE _h,_e,_l,_p,_i,_n,_g,__,_m,_e,_dot,_eol
		.BYTE _eof
_script95_msg07:
		.BYTE _R,_a,_m,_b,_o,_col,_I,__,_w,_a,_n,_t,__,_t,_o,__,_g,_o,_eol
		.BYTE _t,_o,__,_A,_m,_e,_r,_i,_c,_a,__,_w,_i,_t,_h,_eol
		.BYTE _y,_o,_u,_dot,_eol
		.BYTE _eof
_script95_msg08:
		.BYTE _I,_ap,_m,__,_s,_o,_r,_r,_y,_dot,_I,__,_c,_a,_n,_ap,_t,_eol
		.BYTE _t,_a,_k,_e,__,_y,_o,_u,_dot,_eol
		.BYTE _eof
_script95_msg09:
		.BYTE __,_I,_ap,_m,__,_s,_o,_r,_r,_y,_dot,_I,__,_c,_a,_n,_ap,_t,_eol
		.BYTE __,_t,_a,_k,_e,__,_y,_o,_u,_dot,_eol
		.BYTE __,_eol
		.BYTE __,_T,_h,_e,_n,__,_c,_o,_m,_e,__,_b,_a,_c,_k,__,_w,_i,_t,_h,_eol
		.BYTE __,_m,_e,_dot,_eol
		.BYTE _eof
_script95_msg0a:
		.BYTE _T,_h,_a,_n,_k,_s,_dot,_eol
		.BYTE _I,_ap,_m,__,_s,_o,__,_g,_l,_a,_d,_dot,_eol
		.BYTE _L,_e,_t,_ap,_s,__,_g,_o,_col,_t,_h,_e,_y,_ap,_r,_e,_eol
		.BYTE _c,_o,_m,_i,_n,_g,_dot,_H,_u,_r,_r,_y,__,_u,_p,_dot,_eol
		.BYTE _eof
_script95_msg0b:
		.BYTE _I,__,_w,_o,_n,_ap,_t,__,_s,_e,_e,__,_y,_o,_u,_eol
		.BYTE _a,_n,_y,__,_m,_o,_r,_e,_dot,_eol
		.BYTE _G,_o,_o,_d,_dsh,_b,_y,_e,_dot,_eol
		.BYTE _eof
_script96_msg00:
		.BYTE _H,_e,_a,_d,_q,_u,_a,_r,_t,_e,_r,_s,_col,_eol
		.BYTE _w,_e,__,_f,_o,_u,_n,_d,__,_R,_a,_m,_b,_o,_dot,_eol
		.BYTE _H,_e,_ap,_s,__,_t,_a,_k,_i,_n,_g,__,_P,_O,_W,_ap,_s,_eol
		.BYTE _w,_i,_t,_h,__,_h,_i,_m,_dot,_eol
		.BYTE _eof
_script96_msg01:
		.BYTE _dtt,_dtt,_E,_m,_e,_r,_g,_e,_n,_c,_y,_eol
		.BYTE _S,_t,_o,_p,__,_t,_h,_e,__,_m,_i,_s,_s,_i,_o,_n,_dtt,_dtt,_eol
		.BYTE _eof
_script96_msg02:
		.BYTE _W,_h,_a,_t,_qe,_eol
		.BYTE _I,__,_c,_a,_n,_ap,_t,__,_l,_e,_a,_v,_e,__,_t,_h,_e,_m,_eol
		.BYTE _s,_t,_r,_a,_n,_d,_e,_d,_dot,_eol
		.BYTE _eof
_script96_msg03:
		.BYTE _I,__,_h,_a,_v,_e,__,_t,_o,__,_f,_o,_l,_l,_o,_w,_eol
		.BYTE _o,_r,_d,_e,_r,_s,_dot,_eol
		.BYTE _eof
_script96_msg04:
		.BYTE _M,_e,_r,_c,_e,_n,_a,_r,_i,_e,_s,_ex,_eol
		.BYTE _eof
_script96_msg05:
		.BYTE _H,_e,_a,_d,_q,_u,_a,_r,_t,_e,_r,_s,_col,_w,_e,_ap,_v,_e,_eol
		.BYTE _f,_o,_u,_n,_d,__,_R,_a,_m,_b,_o,_dot,_W,_e,_ap,_r,_e,_eol
		.BYTE _g,_o,_i,_n,_g,__,_i,_n,__,_t,_o,__,_r,_e,_s,_c,_u,_e,_eol
		.BYTE _h,_i,_m,_dot,_eol
		.BYTE _eof
_script96_msg05A:
		.BYTE _H,_e,_ap,_s,__,_b,_e,_i,_n,_g,__,_c,_h,_a,_s,_e,_d,_eol
		.BYTE _b,_y,__,_t,_h,_e,__,_e,_n,_e,_m,_y,_dot,_eol
		.BYTE _eof
_script96_msg06:
		.BYTE _dtt,_dtt,__,_R,_e,_s,_c,_u,_e,__,_h,_i,_m,__,_dtt,_dtt,_eol
		.BYTE _eof
_script96_msg07:
		.BYTE _R,_a,_m,_b,_o,_col,_g,_e,_t,__,_o,_n,_col,_h,_u,_r,_r,_y,_eol
		.BYTE _u,_p,_dot,_S,_o,__,_l,_o,_n,_g,_col,_j,_u,_n,_g,_l,_e,_dot,_eol
		.BYTE _eof
_script97_msg00:
		.BYTE _A,_t,__,_t,_h,_a,_t,__,_t,_i,_m,_e,__,_R,_a,_m,_b,_o,_col,_eol
		.BYTE _w,_h,_o,__,_w,_a,_s,__,_c,_a,_u,_g,_h,_t,__,_b,_y,_eol
		.BYTE _t,_h,_e,__,_e,_n,_e,_m,_y,_col,_w,_a,_s,__,_b,_e,_i,_n,_g,_eol
		.BYTE _i,_n,_t,_e,_r,_r,_o,_g,_a,_t,_e,_d,_dot,_eol
		.BYTE _eof
_script97_msg01:
		.BYTE _I,_ap,_m,_eol
		.BYTE _C,_o,_m,_m,_a,_n,_d,_e,_r,__,_P,_a,_d,_o,_v,_s,_k,_y,_dot,_eol
		.BYTE _eof
_script97_msg02:
		.BYTE _Y,_o,_u,__,_w,_e,_r,_e,__,_s,_e,_n,_t,__,_h,_e,_r,_e,_eol
		.BYTE _i,_n,__,_a,_n,__,_e,_f,_f,_o,_r,_t,__,_t,_o,_eol
		.BYTE _f,_r,_e,_e,__,_w,_a,_r,__,_c,_r,_i,_m,_i,_n,_a,_l,_s,_dot,_eol
		.BYTE _eof
_script97_msg02A:
		.BYTE _I,__,_w,_a,_n,_t,__,_a,_l,_l,__,_t,_h,_e,_eol
		.BYTE _d,_e,_t,_a,_i,_l,_s,__,_o,_f,__,_y,_o,_u,_r,_eol
		.BYTE _M,_i,_s,_s,_i,_o,_n,_dot,_eol
		.BYTE _eof
_script97_msg03:
		.BYTE _dtt,_dtt,_dtt,_eol
		.BYTE _eof
_script97_msg04:
		.BYTE _I,__,_w,_a,_n,_t,__,_y,_o,_u,__,_t,_o,__,_r,_a,_d,_i,_o,_eol
		.BYTE _y,_o,_u,_r,__,_h,_e,_a,_d,_q,_u,_a,_r,_t,_e,_r,_s,_eol
		.BYTE _a,_n,_d,__,_s,_a,_y,__,_t,_h,_a,_t,__,_y,_o,_u,_eol
		.BYTE _h,_a,_v,_e,__,_b,_e,_e,_n,__,_c,_a,_p,_t,_u,_r,_e,_d,_dot,_eol
		.BYTE _eof
_script97_msg05:
		.BYTE _dtt,_dtt,_dtt,_eol
		.BYTE _eof
_script97_msg06:
		.BYTE _Y,_o,_u,__,_w,_i,_l,_l,__,_n,_o,_t,__,_t,_a,_l,_k,_qe,_eol
		.BYTE _O,_dot,_K,_dot,_eol
		.BYTE _Y,_a,_s,_h,_i,_n,_ex,_eol
		.BYTE _eof
_script97_msg06A:
		.BYTE _Y,_o,_u,_ap,_r,_e,__,_o,_n,_l,_y,__,_a,_n,_eol
		.BYTE _e,_x,_p,_e,_r,_i,_m,_e,_n,_t,_a,_l,_eol
		.BYTE _a,_n,_i,_m,_a,_l,__,_f,_o,_r,__,_s,_e,_r,_g,_e,_a,_n,_t,_eol
		.BYTE _Y,_a,_s,_h,_i,_n,_dot,_eol
		.BYTE _eof
_script97_msg09:
		.BYTE _Y,_o,_u,_r,__,_C,_o,_m,_m,_a,_n,_d,__,_h,_a,_s,_eol
		.BYTE _a,_b,_a,_n,_d,_o,_n,_e,_d,__,_y,_o,_u,_dot,_eol
		.BYTE _D,_o,__,_y,_o,_u,__,_s,_t,_i,_l,_l,_eol
		.BYTE _p,_r,_o,_t,_e,_c,_t,__,_t,_h,_e,_m,_qe,_eol
		.BYTE _eof
_script97_msg09A:
		.BYTE _Y,_o,_u,__,_m,_u,_s,_t,__,_m,_a,_k,_e,_eol
		.BYTE _c,_o,_n,_t,_a,_c,_t,_col,_o,_t,_h,_e,_r,_w,_i,_s,_e,_eol
		.BYTE _y,_o,_u,_r,__,_f,_r,_i,_e,_n,_d,__,_w,_i,_l,_l,__,_b,_e,_eol
		.BYTE _k,_i,_l,_l,_e,_d,_dot,_eol
		.BYTE _eof
_script97_msg0a:
		.BYTE _M,_a,_k,_e,__,_a,__,_r,_a,_d,_i,_o,__,_c,_a,_l,_l,_dot,_eol
		.BYTE _eof
_script97_msg0b:
		.BYTE __,_dtt,_dtt,_dtt,_eol
		.BYTE __,_eol
		.BYTE __,_eol
		.BYTE __,_2,_2,_0,_dtt,_dtt,_dtt,_5,_6,_dtt,_dtt,_p,_l,_e,_a,_s,_e,_eol
		.BYTE _eof
_script97_msg0c:
		.BYTE _dtt,_dtt,_R,_e,_p,_o,_r,_t,__,_y,_o,_u,_r,_eol
		.BYTE _p,_o,_s,_i,_t,_i,_o,_n,__,_a,_n,_d,_eol
		.BYTE _s,_t,_a,_t,_u,_s,_dtt,_dtt,_eol
		.BYTE _eof
_script97_msg0d:
		.BYTE _A,_n,_s,_w,_e,_r,__,_i,_t,_col,_i,_f,__,_y,_o,_u,_eol
		.BYTE _d,_o,_n,_ap,_t,__,_w,_a,_n,_n,_a,__,_s,_e,_e,_eol
		.BYTE _y,_o,_u,_r,__,_f,_r,_i,_e,_n,_d,__,_d,_i,_e,_dot,_eol
		.BYTE _eof
_script97_msg0e:
		.BYTE _J,_o,_h,_n,_col,_i,_t,_ap,_s,__,_m,_e,_dot,_eol
		.BYTE _A,_n,_s,_w,_e,_r,_dot,_eol
		.BYTE _eof
_script97_msg0f:
		.BYTE _W,_h,_e,_r,_e,__,_i,_s,__,_M,_u,_r,_d,_o,_c,_k,_qe,_eol
		.BYTE _eof
_script97_msg10:
		.BYTE _H,_e,__,_i,_s,__,_h,_e,_r,_e,_dot,_eol
		.BYTE _G,_i,_v,_e,__,_u,_s,__,_t,_h,_e,_eol
		.BYTE _p,_o,_s,_i,_t,_i,_o,_n,_dot,_W,_e,_ap,_l,_l,_eol
		.BYTE _c,_o,_m,_e,__,_t,_o,__,_p,_i,_c,_k,_eol
		.BYTE _y,_o,_u,__,_u,_p,_dot,_eol
		.BYTE _eof
_script97_msg11:
		.BYTE _I,_ap,_m,__,_c,_o,_m,_i,_n,_g,__,_t,_o,_eol
		.BYTE _t,_e,_r,_m,_i,_n,_a,_t,_e,__,_y,_o,_u,_dot,_eol
		.BYTE _eof
_script98_msg00:
		.BYTE _H,_e,_l,_l,_o,_ex,_eol
		.BYTE _eof
_script98_msg01:
		.BYTE _O,_h,_col,_w,_h,_a,_t,_ap,_s,__,_o,_n,__,_y,_o,_u,_r,_eol
		.BYTE _m,_i,_n,_d,_col,_j,_u,_s,_t,__,_l,_e,_t,__,_m,_e,_eol
		.BYTE _k,_n,_o,_w,_dot,_W,_o,_u,_l,_d,__,_y,_o,_u,__,_l,_i,_k,_e,_eol
		.BYTE _t,_o,__,_b,_u,_y,__,_t,_h,_i,_s,__,_d,_r,_e,_s,_s,_qe,_eol
		.BYTE _eof
_script98_msg02:
		.BYTE __,_I,__,_c,_a,_n,_ap,_t,__,_g,_o,__,_w,_i,_t,_h,_o,_u,_t,_eol
		.BYTE __,_t,_h,_i,_s,__,_r,_i,_f,_l,_e,_dot,_eol
		.BYTE __,_eol
		.BYTE __,_O,_h,_col,_t,_h,_i,_s,__,_i,_s,__,_a,_eol
		.BYTE __,_b,_e,_a,_u,_t,_i,_f,_u,_l,__,_d,_r,_e,_s,_s,_dot,_eol
		.BYTE _eof
_script98_msg03:
		.BYTE _H,_m,_m,_col,_I,_ap,_m,__,_s,_o,_r,_r,_y,_dot,_eol
		.BYTE _eof
_script98_msg04:
		.BYTE _Y,_o,_u,__,_l,_o,_o,_k,__,_g,_o,_o,_d,__,_i,_n,_eol
		.BYTE _t,_h,_e,__,_d,_r,_e,_s,_s,_dot,_eol
		.BYTE _eof
_script99_msg00:
		.BYTE _A,__,_k,_i,_d,__,_i,_s,__,_m,_i,_s,_s,_i,_n,_g,_eol
		.BYTE _i,_n,__,_a,__,_c,_a,_v,_e,__,_t,_o,__,_t,_h,_e,_eol
		.BYTE _n,_o,_r,_t,_h,_dot,_eol
		.BYTE _P,_l,_e,_a,_s,_e,__,_f,_i,_n,_d,__,_h,_i,_m,_dot,_eol
		.BYTE _eof
_script99_msg01:
		.BYTE _dtt,_dtt,_dtt,_eol
		.BYTE _eof
_script99_msg02:
		.BYTE _R,_a,_m,_b,_o,_col,_p,_l,_e,_a,_s,_e,__,_s,_a,_v,_e,_eol
		.BYTE _t,_h,_e,__,_k,_i,_d,_dot,_eol
		.BYTE _eof
_script99_msg03:
		.BYTE _T,_h,_a,_n,_k,__,_y,_o,_u,__,_f,_o,_r,_eol
		.BYTE _s,_a,_v,_i,_n,_g,__,_t,_h,_e,__,_k,_i,_d,_dot,_eol
		.BYTE _P,_l,_e,_a,_s,_e,__,_r,_e,_s,_t,_dot,_eol
		.BYTE _eof
_script99_msg04:
		.BYTE _I,__,_c,_a,_n,_ap,_t,__,_s,_t,_a,_y,__,_h,_e,_r,_e,_eol
		.BYTE _f,_o,_r,__,_a,__,_l,_o,_n,_g,__,_t,_i,_m,_e,_dot,_eol
		.BYTE _I,__,_m,_u,_s,_t,__,_g,_o,_dot,_eol
		.BYTE _eof
_script9A_msg00:
		.BYTE _W,_h,_y,__,_d,_i,_d,__,_y,_o,_u,__,_c,_o,_m,_e,_eol
		.BYTE _h,_e,_r,_e,_qe,_eol
		.BYTE _eof
_script9A_msg02:
		.BYTE _I,__,_w,_a,_n,_t,__,_t,_o,__,_s,_a,_v,_e,__,_t,_h,_e,_eol
		.BYTE _k,_i,_d,__,_i,_n,__,_t,_h,_e,__,_c,_a,_v,_e,_dot,_eol
		.BYTE _eof
_script9A_msg03:
		.BYTE _T,_a,_k,_e,__,_t,_h,_i,_s,__,_l,_a,_m,_p,_dot,_eol
		.BYTE _eof
_script9B_msg00:
		.BYTE _A,_n,__,_A,_m,_e,_r,_i,_c,_a,_n,__,_s,_p,_y,__,_w,_a,_s,_eol
		.BYTE _c,_a,_u,_g,_h,_t,_dot,_eol
		.BYTE _eof
_script9B_msg01:
		.BYTE _I,__,_w,_a,_n,_n,_a,__,_t,_a,_k,_e,__,_h,_i,_m,_eol
		.BYTE _o,_u,_t,_dot,_eol
		.BYTE _eof
_script9B_msg02:
		.BYTE _T,_a,_k,_e,__,_t,_h,_i,_s,__,_m,_e,_d,_i,_c,_i,_n,_e,_eol
		.BYTE _a,_n,_d,__,_g,_i,_v,_e,__,_i,_t,__,_t,_o,__,_h,_i,_m,_dot,_eol
		.BYTE _eof
_script9B_msg03:
		.BYTE _Y,_o,_u,__,_l,_o,_o,_k,__,_t,_i,_r,_e,_d,_dot,_eol
		.BYTE _R,_e,_s,_t,__,_h,_e,_r,_e,__,_f,_o,_r,__,_a,_eol
		.BYTE _w,_h,_i,_l,_e,_dot,_eol
		.BYTE _eof
_script9B_msg04:
		.BYTE _T,_h,_a,_n,_k,_s,_dot,_eol
		.BYTE _I,_ap,_m,__,_a,_b,_l,_e,__,_t,_o,__,_f,_i,_g,_h,_t,_eol
		.BYTE _a,_g,_a,_i,_n,_dot,_eol
		.BYTE _eof
_script9C_msg00:
		.BYTE _W,_e,_ap,_r,_e,__,_s,_a,_f,_e,__,_f,_o,_r,__,_n,_o,_w,_dot,_eol
		.BYTE _W,_h,_a,_t,__,_a,_r,_e,__,_y,_o,_u,__,_g,_o,_i,_n,_g,_eol
		.BYTE _t,_o,__,_d,_o,_qe,_eol
		.BYTE _G,_o,_i,_n,_g,__,_t,_o,__,_T,_h,_a,_i,_l,_a,_n,_d,_qe,_eol
		.BYTE _eof
_script9C_msg00A:
		.BYTE _T,_h,_e,_n,__,_A,_m,_e,_r,_i,_c,_a,_qe,_eol
		.BYTE _W,_o,_u,_l,_d,__,_y,_o,_u,__,_p,_l,_e,_a,_s,_e,_eol
		.BYTE _t,_a,_k,_e,__,_m,_e,__,_w,_i,_t,_h,__,_y,_o,_u,_qe,_eol
		.BYTE _eof
_script9C_msg01:
		.BYTE _Y,_o,_u,_ap,_r,_e,__,_i,_n,__,_d,_a,_n,_g,_e,_r,_eol
		.BYTE _h,_e,_r,_e,_dot,_L,_e,_t,_ap,_s,__,_g,_o,__,_b,_a,_c,_k,_eol
		.BYTE _t,_o,_g,_e,_t,_h,_e,_r,_dot,_eol
		.BYTE _eof
_script9C_msg02:
		.BYTE _T,_h,_a,_n,_k,__,_y,_o,_u,_dtt,_dtt,_dtt,_eol
		.BYTE _I,_ap,_m,__,_s,_o,__,_h,_a,_p,_p,_y,_dtt,_dtt,_dtt,_eol
		.BYTE _L,_e,_t,_ap,_s,__,_g,_o,_dot,_T,_h,_e,_y,_ap,_r,_e,_eol
		.BYTE _c,_o,_m,_i,_n,_g,__,_u,_p,__,_b,_e,_h,_i,_n,_d,_eol
		.BYTE _u,_s,_dot,_eol
		.BYTE _eof
_script9C_msg03:
		.BYTE _U,_g,_h,_ex,_eol
		.BYTE _eof
_script9C_msg04:
		.BYTE _C,_o,_dot,_A,_r,_e,__,_y,_o,_u,__,_a,_l,_l,_eol
		.BYTE _r,_i,_g,_h,_t,_qe,_eol
		.BYTE _eof
_script9C_msg05:
		.BYTE _R,_a,_m,_b,_o,_col,_I,__,_c,_a,_n,_ap,_t,__,_g,_o,_eol
		.BYTE _w,_i,_t,_h,__,_y,_o,_u,_dot,_eol
		.BYTE _eof
_script9C_msg06:
		.BYTE _Y,_o,_u,_ap,_r,_e,__,_g,_o,_i,_n,_g,__,_w,_i,_t,_h,_eol
		.BYTE _m,_e,__,_t,_o,__,_t,_h,_e,__,_S,_t,_a,_t,_e,_s,_dot,_eol
		.BYTE _eof
_script9C_msg07:
		.BYTE _R,_a,_m,_b,_o,_col,_t,_h,_a,_n,_k,__,_y,_o,_u,_dot,_eol
		.BYTE _P,_l,_e,_a,_s,_e,__,_d,_o,_n,_ap,_t,__,_f,_o,_r,_g,_e,_t,_eol
		.BYTE _m,_e,_dot,_eol
		.BYTE _eof
_script9C_msg08:
		.BYTE _C,_o,_ex,_eol
		.BYTE _eof
_script9D_msg00:
		.BYTE _R,_a,_m,_b,_o,__,_f,_o,_u,_n,_d,__,_t,_h,_e,__,_k,_e,_y,_eol
		.BYTE _t,_o,__,_t,_h,_e,__,_h,_e,_l,_i,_c,_o,_p,_t,_e,_r,_dot,_eol
		.BYTE _eof
_script9D_msg01:
		.BYTE _S,_e,_r,_g,_e,_a,_n,_t,__,_Y,_a,_s,_h,_i,_n,_eol
		.BYTE _c,_a,_m,_e,__,_u,_p,__,_t,_h,_e,_r,_e,_dot,_eol
		.BYTE _eof
_script9D_msg02:
		.BYTE _I,_t,_ap,_s,__,_t,_i,_m,_e,__,_f,_o,_r,_eol
		.BYTE _y,_o,_u,__,_t,_o,__,_d,_i,_e,_dot,_eol
		.BYTE _eof
_script9E_msg00:
		.BYTE _Y,_o,_u,__,_c,_a,_n,_ap,_t,__,_f,_l,_y,_eol
		.BYTE _w,_i,_t,_h,_o,_u,_t,__,_t,_h,_e,__,_k,_e,_y,__,_t,_o,_eol
		.BYTE _t,_h,_e,__,_h,_e,_l,_i,_c,_o,_p,_t,_e,_r,_dot,_eol
		.BYTE _eof
_script9E_msg01:
		.BYTE _L,_e,_t,_ap,_s,__,_g,_o,__,_t,_o,__,_t,_h,_e,_eol
		.BYTE _c,_a,_m,_p,__,_a,_n,_d,__,_r,_e,_s,_c,_u,_e,_eol
		.BYTE _t,_h,_e,_m,_dot,_eol
		.BYTE _eof
_script9E_msg02:
		.BYTE _R,_a,_m,_b,_o,_col,_j,_u,_m,_p,__,_o,_n,_eol
		.BYTE _q,_u,_i,_c,_k,_l,_y,_dot,_eol
		.BYTE _eof
_script9F_msg00:
		.BYTE _M,_e,_a,_n,_w,_h,_i,_l,_e,_col,_C,_o,_col,_eol
		.BYTE _t,_o,__,_s,_a,_v,_e,__,_R,_a,_m,_b,_o,_dtt,_dtt,_dtt,_eol
		.BYTE _eof
_scriptA0_msg00:
		.BYTE _A,_r,_e,__,_y,_o,_u,__,_a,_l,_r,_i,_g,_h,_t,_qe,_eol
		.BYTE _I,__,_c,_a,_m,_e,__,_h,_e,_r,_e,__,_t,_o,__,_g,_e,_t,_eol
		.BYTE _y,_o,_u,__,_h,_o,_m,_e,_dot,_eol
		.BYTE _eof
_scriptA0_msg01:
		.BYTE _I,_ap,_m,__,_w,_e,_a,_k,_dot,_eol
		.BYTE _I,__,_t,_h,_i,_n,_k,__,_I,_ap,_m,__,_d,_y,_i,_n,_g,_dot,_eol
		.BYTE _eof
_scriptA0_msg02:
		.BYTE _B,_e,__,_s,_t,_r,_o,_n,_g,_ex,_eol
		.BYTE _W,_e,__,_c,_a,_n,__,_m,_a,_k,_e,__,_i,_t,_ex,_eol
		.BYTE _H,_u,_r,_r,_y,_col,_l,_e,_t,_ap,_s,__,_g,_e,_t,__,_o,_u,_t,_eol
		.BYTE _o,_f,__,_h,_e,_r,_e,_dot,_eol
		.BYTE _eof
_scriptA1_msg00:
		.BYTE _P,_l,_e,_a,_s,_e,__,_r,_e,_s,_c,_u,_e,__,_m,_e,_dot,_eol
		.BYTE _eof
_scriptA1_msg01:
		.BYTE __,_A,_l,_l,__,_r,_i,_g,_h,_t,_dot,_eol
		.BYTE __,_eol
		.BYTE __,_eol
		.BYTE __,_S,_o,_r,_r,_y,_col,_m,_y,__,_d,_u,_t,_y,__,_i,_s,_eol
		.BYTE __,_j,_u,_s,_t,__,_t,_o,__,_t,_a,_k,_e,__,_p,_h,_o,_t,_o,_s,_dot,_eol
		.BYTE _eof
_scriptA1_msg02:
		.BYTE _D,_i,_d,_n,_ap,_t,__,_y,_o,_u,__,_c,_o,_m,_e,_eol
		.BYTE _h,_e,_r,_e,__,_t,_o,__,_s,_a,_v,_e,__,_u,_s,_dot,_eol
		.BYTE _P,_l,_e,_a,_s,_e,__,_t,_a,_k,_e,__,_u,_s,__,_o,_u,_t,_dot,_eol
		.BYTE _eof
_scriptA1_msg03:
		.BYTE _I,_ap,_m,__,_f,_r,_e,_e,_dot,_eol
		.BYTE _T,_h,_e,_r,_e,__,_a,_r,_e,__,_s,_o,_m,_e,_eol
		.BYTE _m,_o,_r,_e,_dot,_eol
		.BYTE _eof
_scriptA1_msg04:
		.BYTE _I,_ap,_l,_l,__,_b,_e,__,_b,_a,_c,_k,_dot,_eol
		.BYTE _L,_e,_t,_ap,_s,__,_g,_e,_t,__,_o,_u,_t,__,_o,_f,_eol
		.BYTE _h,_e,_r,_e,_dot,_eol
		.BYTE _eof
_scriptA2_msg00:
		.BYTE _G,_e,_t,__,_o,_n,__,_t,_h,_e,__,_c,_h,_o,_p,_p,_e,_r,_ex,_eol
		.BYTE _Q,_u,_i,_c,_k,_ex,_eol
		.BYTE _eof
_scriptA2_msg01:
		.BYTE _G,_o,_o,_d,_dsh,_b,_y,_e,__,_ap,_N,_a,_m,_dot,_eol
		.BYTE _eof
_scriptA2_msg02:
		.BYTE _T,_h,_e,_r,_e,__,_m,_u,_s,_t,__,_b,_e,__,_s,_o,_m,_e,_eol
		.BYTE _m,_o,_r,_e,_dot,_eol
		.BYTE _L,_e,_t,_ap,_s,__,_t,_a,_k,_e,__,_t,_h,_e,_m,_eol
		.BYTE _o,_u,_t,_dot,_eol
		.BYTE _eof
_scriptA2_msg03:
		.BYTE _I,_ap,_l,_l,__,_h,_e,_l,_p,__,_y,_o,_u,_dot,_eol
		.BYTE _eof
_scriptA2_msg04:
		.BYTE _Y,_o,_u,_ap,_d,__,_b,_e,_t,_t,_e,_r,__,_s,_t,_a,_y,_eol
		.BYTE _h,_e,_r,_e,__,_i,_n,__,_t,_h,_e,_eol
		.BYTE _c,_h,_o,_p,_p,_e,_r,_dot,_eol
		.BYTE _eof
_scriptA3_msg00:
		.BYTE _I,__,_d,_o,_n,_ap,_t,__,_m,_a,_k,_e,_eol
		.BYTE _o,_r,_d,_e,_r,_s,_dot,_I,__,_t,_a,_k,_e,__,_t,_h,_e,_m,_eol
		.BYTE _j,_u,_s,_t,__,_l,_i,_k,_e,__,_y,_o,_u,_dot,_eol
		.BYTE _eof
_scriptA3_msg01:
		.BYTE _I,__,_s,_w,_e,_a,_r,__,_t,_o,__,_G,_o,_d,_col,_eol
		.BYTE _t,_h,_i,_s,__,_w,_a,_s,_n,_ap,_t,_eol
		.BYTE _s,_u,_p,_p,_o,_s,_e,_d,__,_t,_o,__,_h,_a,_p,_p,_e,_n,_dot,_eol
		.BYTE _eof
_scriptA3_msg02:
		.BYTE _I,_t,__,_w,_a,_s,__,_j,_u,_s,_t,_eol
		.BYTE _s,_u,_p,_p,_o,_s,_e,_d,__,_t,_o,__,_b,_e,_eol
		.BYTE _a,_n,_o,_t,_h,_e,_r,_eol
		.BYTE _a,_s,_s,_i,_g,_n,_m,_e,_n,_t,_dot,_eol
		.BYTE _eof
_scriptA3_msg03:
		.BYTE _M,_i,_s,_s,_i,_o,_n,_eol
		.BYTE _a,_c,_c,_o,_m,_p,_l,_i,_s,_h,_e,_d,_dot,_eol
		.BYTE _eof
_scriptA3_msg04:
		.BYTE _T,_h,_e,_r,_e,__,_a,_r,_e,__,_m,_o,_r,_e,__,_m,_e,_n,_eol
		.BYTE _o,_u,_t,__,_t,_h,_e,_r,_e,_dot,_eol
		.BYTE _F,_i,_n,_d,__,_t,_h,_e,_m,_col,_o,_r,__,_I,_ap,_l,_l,_eol
		.BYTE _f,_i,_n,_d,__,_y,_o,_u,_dot,_eol
		.BYTE _eof
_scriptA3_msg05:
		.BYTE _G,_o,_o,_d,__,_j,_o,_b,_col,_R,_a,_m,_b,_o,_dot,_eol
		.BYTE _I,_ap,_m,__,_k,_e,_e,_p,_i,_n,_g,__,_o,_u,_r,_eol
		.BYTE _d,_e,_a,_l,_col,_y,_o,_u,__,_c,_a,_n,__,_g,_o,_eol
		.BYTE _w,_h,_e,_r,_e,_v,_e,_r,__,_y,_o,_u,__,_w,_a,_n,_t,_dot,_eol
		.BYTE _eof
_scriptA3_msg06:
		.BYTE _A,_r,_e,_n,_ap,_t,__,_y,_o,_u,__,_g,_o,_i,_n,_g,__,_t,_o,_eol
		.BYTE _r,_e,_s,_c,_u,_e,__,_t,_h,_e,__,_P,_O,_W,_ap,_s,_qe,_eol
		.BYTE _eof
_scriptA3_msg07:
		.BYTE _N,_o,_col,_t,_h,_o,_s,_e,__,_p,_h,_o,_t,_o,_s,_eol
		.BYTE _w,_e,_r,_e,__,_u,_s,_e,_l,_e,_s,_s,__,_a,_s,_eol
		.BYTE _e,_v,_i,_d,_e,_n,_c,_e,_dot,_eol
		.BYTE _eof
_scriptA3_msg08:
		.BYTE _T,_h,_e,__,_m,_i,_s,_s,_i,_o,_n,__,_w,_a,_s,_eol
		.BYTE _a,__,_f,_a,_i,_l,_u,_r,_e,_dot,_I,__,_k,_n,_e,_w,_eol
		.BYTE _y,_o,_u,__,_c,_o,_u,_l,_d,_n,_ap,_t,__,_d,_o,__,_i,_t,_dot,_eol
		.BYTE _eof
_scriptA4_msg00:
		.BYTE _G,_o,_o,_d,__,_j,_o,_b,_col,_R,_a,_m,_b,_o,_dot,_eol
		.BYTE _eof
_scriptA4_msg01:
		.BYTE _dtt,_dtt,_dtt,_eol
		.BYTE _eof
_scriptA4_msg02:
		.BYTE _Y,_o,_u,_ap,_r,_e,__,_t,_o,_u,_g,_h,_e,_r,_eol
		.BYTE _t,_h,_e,_n,__,_I,__,_t,_h,_o,_u,_g,_h,_t,_dot,_N,_o,_w,_col,_eol
		.BYTE _y,_o,_u,_ap,_r,_e,__,_f,_r,_e,_e,_dot,_eol
		.BYTE _eof
_scriptA4_msg03:
		.BYTE _J,_o,_h,_n,_col,_w,_h,_e,_r,_e,__,_a,_r,_e,__,_y,_o,_u,_eol
		.BYTE _g,_o,_i,_n,_g,_qe,_eol
		.BYTE _eof
_scriptA4_msg04:
		.BYTE _I,__,_d,_o,_n,_ap,_t,__,_k,_n,_o,_w,_dot,_eol
		.BYTE _eof
_scriptA4_msg05:
		.BYTE _T,_h,_i,_s,__,_i,_s,__,_a,__,_s,_e,_c,_o,_n,_d,_eol
		.BYTE _M,_e,_d,_a,_l,__,_o,_f,__,_H,_o,_n,_o,_r,__,_f,_o,_r,_eol
		.BYTE _y,_o,_u,_dot,_eol
		.BYTE _eof
_scriptA4_msg06:
		.BYTE _Y,_o,_u,__,_s,_h,_o,_u,_l,_d,__,_g,_i,_v,_e,__,_i,_t,_eol
		.BYTE _t,_o,__,_t,_h,_e,_m,_dot,_eol
		.BYTE _eof
_scriptA4_msg07:
		.BYTE _Y,_o,_u,_ap,_r,_e,__,_f,_r,_e,_e,__,_n,_o,_w,_dot,_eol
		.BYTE _C,_o,_m,_e,__,_b,_a,_c,_k,__,_w,_i,_t,_h,__,_u,_s,_dot,_eol
		.BYTE _eof
_scriptA4_msg08:
		.BYTE _W,_h,_a,_t,_ap,_s,__,_t,_h,_e,_r,_e,__,_f,_o,_r,_eol
		.BYTE _m,_e,_qe,_eol
		.BYTE _M,_y,__,_f,_r,_i,_e,_n,_d,_s,__,_d,_i,_e,_d,_eol
		.BYTE _h,_e,_r,_e,_col,_a,_n,_d,__,_a,__,_p,_i,_e,_c,_e,__,_o,_f,_eol
		.BYTE _m,_e,__,_d,_i,_d,__,_t,_o,_dot,_eol
		.BYTE _eof
_scriptA4_msg09:
		.BYTE _T,_h,_e,__,_w,_a,_r,_col,_e,_v,_e,_r,_y,_t,_h,_i,_n,_g,_eol
		.BYTE _t,_h,_a,_t,__,_h,_a,_p,_p,_e,_n,_e,_d,__,_m,_a,_y,_b,_e,_eol
		.BYTE _i,_t,_ap,_s,__,_w,_r,_o,_n,_g,_dot,_eol
		.BYTE _eof
_scriptA4_msg09A:
		.BYTE _D,_o,_n,_ap,_t,__,_h,_a,_t,_e,_eol
		.BYTE _y,_o,_u,_r,__,_c,_o,_u,_n,_t,_r,_y,__,_f,_o,_r,_eol
		.BYTE _w,_h,_a,_t,__,_y,_o,_u,_ap,_v,_e,__,_b,_e,_e,_n,_eol
		.BYTE _t,_h,_r,_o,_u,_g,_h,_dot,_eol
		.BYTE _eof
_scriptA4_msg0a:
		.BYTE _H,_a,_t,_e,_qe,_eol
		.BYTE _I,_ap,_d,__,_d,_i,_e,__,_f,_o,_r,__,_i,_t,_dot,_eol
		.BYTE _eof
_scriptA4_msg0b:
		.BYTE _S,_o,_col,_w,_h,_a,_t,__,_d,_o,__,_y,_o,_u,_eol
		.BYTE _w,_a,_n,_t,_dot,_eol
		.BYTE _eof
_scriptA4_msg0c:
		.BYTE _I,__,_w,_a,_n,_t,__,_w,_h,_a,_t,__,_t,_h,_e,_y,_eol
		.BYTE _w,_a,_n,_t,_dot,_dot,_dot,_eol
		.BYTE _e,_v,_e,_r,_y,__,_o,_t,_h,_e,_r,__,_g,_u,_y,_eol
		.BYTE _w,_h,_o,__,_c,_a,_m,_e,__,_o,_v,_e,_r,__,_h,_e,_r,_e,_col,_eol
		.BYTE _eof
_scriptA4_msg0cA:
		.BYTE _I,__,_w,_a,_n,_t,__,_f,_o,_r,_eol
		.BYTE _m,_y,__,_c,_o,_u,_n,_t,_r,_y,__,_t,_o,__,_l,_o,_v,_e,_eol
		.BYTE _m,_e,__,_a,_s,__,_m,_u,_c,_h,__,_a,_s,_eol
		.BYTE _I,__,_l,_o,_v,_e,__,_i,_t,_dot,_eol
		.BYTE _eof
_scriptA4_msg0d:
		.BYTE _T,_h,_a,_t,_ap,_s,__,_w,_h,_a,_t,__,_I,__,_w,_a,_n,_t,_dot,_eol
		.BYTE _eof
_scriptA4_msg0e:
		.BYTE _W,_h,_a,_t,__,_a,_r,_e,__,_y,_o,_u,__,_g,_o,_i,_n,_g,_eol
		.BYTE _t,_o,__,_d,_o,_qe,_eol
		.BYTE _eof
_scriptA4_msg0f:
		.BYTE _D,_a,_y,__,_b,_y,__,_d,_a,_y,_dot,_eol
		.BYTE _eof
_scriptA4_msg10:
		.BYTE _W,_e,_l,_c,_o,_m,_e,__,_b,_a,_c,_k,_dot,_eol
		.BYTE _B,_u,_t,__,_t,_h,_e,__,_g,_a,_m,_e,__,_i,_s,__,_n,_o,_t,_eol
		.BYTE _o,_v,_e,_r,_dot,_J,_o,_h,_n,_col,_a,_r,_e,__,_y,_o,_u,_eol
		.BYTE _s,_a,_t,_i,_s,_f,_i,_e,_d,_qe,_eol
		.BYTE _eof
_scriptA4_msg11:
		.BYTE __,_L,_e,_t,__,_m,_e,__,_t,_r,_y,__,_a,_g,_a,_i,_n,_dot,_eol
		.BYTE __,_eol
		.BYTE __,_eol
		.BYTE __,_I,__,_d,_o,_n,_ap,_t,__,_w,_a,_n,_t,__,_t,_o,__,_d,_o,_eol
		.BYTE __,_t,_h,_a,_t,__,_a,_g,_a,_i,_n,_dot,_eol
		.BYTE _eof
_scriptA4_msg12:
		.BYTE _T,_h,_e,__,_r,_e,_a,_l,__,_p,_u,_r,_p,_o,_s,_e,__,_o,_f,_eol
		.BYTE _t,_h,_e,__,_g,_a,_m,_e,__,_i,_s,__,_t,_o,__,_s,_a,_v,_e,_eol
		.BYTE _t,_h,_e,__,_P,_O,_W,_dot,_eol
		.BYTE _eof
_scriptA5_msg00:
		.BYTE _W,_h,_a,_t,__,_a,_r,_e,__,_y,_o,_u,__,_d,_o,_i,_n,_g,_qe,_eol
		.BYTE _G,_o,_i,_n,_g,__,_t,_o,_eol
		.BYTE _t,_h,_e,__,_S,_t,_a,_t,_e,_s,_qe,_eol
		.BYTE _eof
_scriptA5_msg01:
		.BYTE _W,_a,_r,_m,__,_p,_e,_o,_p,_l,_e,_dot,_eol
		.BYTE _W,_a,_r,_m,__,_c,_i,_t,_y,_dot,_eol
		.BYTE _W,_a,_r,_m,__,_d,_a,_y,_s,_dot,_eol
		.BYTE _eof
_scriptA5_msg01A:
		.BYTE _I,_ap,_v,_e,__,_b,_e,_e,_n,__,_d,_r,_e,_a,_m,_i,_n,_g,_eol
		.BYTE _o,_f,__,_l,_i,_v,_i,_n,_g,__,_i,_n,__,_t,_h,_e,_eol
		.BYTE _U,_S,_A,__,_a,_n,_d,__,_h,_a,_v,_i,_n,_g,__,_a,_eol
		.BYTE _s,_i,_m,_p,_l,_e,__,_l,_i,_f,_e,_dot,_I,_f,__,_y,_o,_u,_eol
		.BYTE _d,_o,_n,_ap,_t,__,_m,_i,_n,_d,_dtt,_dtt,_dtt,_eol
		.BYTE _eof
_scriptA5_msg02:
		.BYTE _I,__,_t,_h,_i,_n,_k,__,_I,__,_l,_e,_a,_r,_n,_e,_d,_eol
		.BYTE _s,_o,_m,_e,_t,_h,_i,_n,_g,__,_i,_m,_p,_o,_r,_t,_a,_n,_t,_eol
		.BYTE _f,_r,_o,_m,__,_y,_o,_u,_dot,_I,__,_m,_a,_y,__,_b,_e,_eol
		.BYTE _a,_b,_l,_e,__,_t,_o,__,_l,_i,_v,_e,_col,_eol
		.BYTE _o,_r,__,_l,_o,_v,_e,_dtt,_dtt,_dtt,_eol
		.BYTE _eof
_scriptA5_msg03:
		.BYTE _R,_e,_a,_l,_l,_y,_qe,_eol
		.BYTE _I,__,_l,_o,_v,_e,__,_y,_o,_u,_dot,_eol
		.BYTE _eof
_scriptAA_msg00:
		.BYTE _R,_a,_m,_b,_o,__,_a,_n,_d,__,_C,_o,__,_o,_n,_eol
		.BYTE _t,_h,_e,__,_b,_o,_a,_t,_dtt,_dtt,_dtt,_eol
		.BYTE _eof
_scriptAC_msg00:
		.BYTE _I,_ap,_m,__,_E,_r,_i,_c,_s,_o,_n,_dot,_eol
		.BYTE _I,_ap,_m,__,_g,_l,_a,_d,__,_t,_o,__,_w,_o,_r,_k,_eol
		.BYTE _w,_i,_t,_h,__,_y,_o,_u,_dot,_eol
		.BYTE _eof
_scriptAC_msg01:
		.BYTE _W,_e,_ap,_v,_e,__,_n,_o,__,_t,_i,_m,_e,_dot,_eol
		.BYTE _G,_o,__,_t,_o,_eol
		.BYTE _T,_r,_a,_u,_t,_m,_a,_n,__,_s,_o,_o,_n,_dot,_eol
		.BYTE _eof
_scriptAD_msg00:
		.BYTE _T,_h,_a,_n,_k,__,_y,_o,_u,__,_R,_a,_m,_b,_o,_dot,_eol
		.BYTE _W,_e,__,_k,_n,_e,_w,__,_t,_h,_a,_t,_eol
		.BYTE _y,_o,_u,__,_w,_o,_u,_l,_d,__,_s,_a,_v,_e,_eol
		.BYTE _t,_h,_e,_m,_dot,_eol
		.BYTE _eof
_scriptAE_msg00:
		.BYTE _C,_o,__,_w,_e,_n,_t,__,_t,_o,__,_t,_h,_e,__,_c,_a,_m,_p,_eol
		.BYTE _t,_o,__,_h,_e,_l,_p,__,_R,_a,_m,_b,_o,_dot,_eol
		.BYTE _eof
_scriptB1_msg00:
		.BYTE _R,_a,_m,_b,_o,_eol
		.BYTE __,_eol
		.BYTE __,_T,_h,_e,__,_b,_a,_t,_t,_l,_e,__,_i,_s,_eol
		.BYTE __,_o,_v,_e,_r,_col,_b,_u,_t,_dtt,_dtt,_dtt,_eol
		.BYTE _eof
_scriptB5_msg00:
		.BYTE _T,_h,_a,_n,_k,__,_y,_o,_u,_eol
		.BYTE _f,_o,_r,__,_t,_r,_y,_i,_n,_g,_dot,_eol
		.BYTE _eof
