
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
		msg_printf			$2087	; [ _ 1985 BY CAROLCO\ INTERNATIONAL N.V.\ALL RIGHTS RESERVED.]
		ptr_load			_script80_msg01
		msg_printf			$2163	; [    _           TM]
		ptr_load			_script80_msg02
		msg_printf			$2183	; [RAMBO_FIRST BLOOD PART II]
		ptr_load			_script80_msg03
		msg_printf			$21e4	; [_ A REGISTERED TRADEMARK,\TM A TRADEMARK,ARE OWNED\ BY CAROLCO INTERNATIONAL\     N.V.AND USED BY\  PACK-IN-VIDEO CO.,LTD.\   UNDER AUTHORIZATION.]
		sprite_draw_up		_SPR_PACK_IN_TIME
		stop
_script81:
		ptr_load			_script81_msg00
		msg_printf			$21c3	; [REND THE FEELINGS OF HEART\  WITH PAINFUL FEELINGS]
		ptr_load			_script81_msg01
		msg_printf			$22ac	; [START\CONTINUE]
		ptr_load			_script81_msg02
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
		msg_printf			$2068	; [ミッションコ-ドを いれてください]
_script82_loc00:
		frame_draw_custom	$2125, $17, $12
		ptr_load			_script82_msg01
		msg_printf			$2167	; [A B C D E F G H I J\K L M N O P Q R S T\U V W X Y Z\あ い う え お か き く け こ\さ し す せ そ た ち つ て と\な に ぬ ね の は ひ ふ へ ほ\ま み む め も や ゆ よ\モドル ススム オワリ]
		pass_input
		jmpne_option		$01, _script82_loc01
		checkpoint_set
		checkpoint_restore
		stop
		------------------
_script82_loc01:
		frame_draw_custom	$2269, $0d, $06
		ptr_load			_script82_msg02
		msg_printf			$226b	; [コ-ドがちがいます]
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
		msg_printf			$2465	; [LIFE        (MAX      )\ANGER       (NEXT     )\TIME]
		game_stats_draw
		frame_draw_custom	$2525, $17, $0a
		ptr_load			_script83_msg01
		msg_printf			$252b	; [INVENTORY]
		jmp_flags_not_set	FLAG09_CO_TAKEN, _script83_loc00
		ptr_load			_script83_msg02
		msg_printf			$2567	; [コ-]
		------------------
_script83_loc00:
		jmp_flags_not_set	FLAG0E_BOAT,	_script83_loc01
		ptr_load			_script83_msg03
		msg_printf			$25a7	; [ふね]
		------------------
_script83_loc01:
		jmp_flags_not_set	FLAG03_LAMP_ITEM, _script83_loc02
		ptr_load			_script83_msg04
		msg_printf			$25e7	; [ランプ]
		------------------
_script83_loc02:
		jmp_flags_not_set	FLAG04_KID_TAKEN, _script83_loc03
		ptr_load			_script83_msg05
		msg_printf			$2627	; [こども]
		------------------
_script83_loc03:
		jmp_flags_not_set	FLAG05_PHOTO_ITEM, _script83_loc04
		ptr_load			_script83_msg06
		msg_printf			$256c	; [しゃしん]
		------------------
_script83_loc04:
		jmp_flags_not_set	FLAG06_POW_TAKEN, _script83_loc05
		ptr_load			_script83_msg07
		msg_printf			$25ac	; [ホリョ]
		------------------
_script83_loc05:
		jmp_flags_not_set	FLAG07_DRESS_ITEM, _script83_loc06
		ptr_load			_script83_msg08
		msg_printf			$25ec	; [チャイナドレス]
		------------------
_script83_loc06:
		jmp_flags_not_set	FLAG10_HELI_KEY, _script83_loc07
		ptr_load			_script83_msg09
		msg_printf			$262c	; [ヘリのかぎ]
		------------------
_script83_loc07:
		jmp_flags_not_set	FLAG11_PEDANT, _script83_loc08
		ptr_load			_script83_msg0a
		msg_printf			$2575	; [ペンダント]
		------------------
_script83_loc08:
		jmp_flags_not_set	FLAG12_BANDANA, _script83_loc09
		ptr_load			_script83_msg0b
		msg_printf			$25b5	; [はちまき]
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
		msg_printf			$20e7	; [あるひ ケイムショでフクエキチュウの\ランボ-に トラウトマンたいさが\たずねてきて。]
		msg_input_handler
		frame_draw_up		PORTRAIT08_TRAUMAN1
		ptr_load			_script85_msg01
		msg_draw_up			; [ランボ-。ひさしぶりだな。\じつは、ぜひキミに やってもらいたい\しごとがあるんだ。\キケンなニンムだが せいこうすれば\キミは はれてジユウになれる。]
		ptr_load			_script85_msg02
		msg_draw_up			; [ベトナムの ジャングルで\ショウソクフメイとなった\われわれの なかまが、\どうも テキのホリョとなっている\カノウセイがある。]
		ptr_load			_script85_msg03
		msg_draw_up			; [ゲンチへ センニュウし、\チョウサするのが しごとだ。\どうかね。このミッションを\ひきうける じしんはあるか？]
_script85_loc00:
		frame_draw_down		PORTRAIT00_RAMBO
		input_2_options
		ptr_load			_script85_msg04
		msg_draw_down		; [どうせいちどはジゴクをみたオレだ。\しぬことなど こわくはない。\ \ケイムショぐらしのほうが\きがらくだ。ここはキグロウがない。]
		jmpne_option		$01, _script85_loc01
		ptr_load			_script85_msg05
		msg_draw_up			; [けっこう。さっそくテハイしよう。\キミを ここからだしたいのだ。]
		set_room_idx		$01
		stop
		------------------
_script85_loc01:
		ptr_load			_script85_msg06
		msg_draw_up			; [キミがそういうとは おもわなかった。\キミがYESといってくれないと\ゲ-ムが はじまらんのだよ。]
		jump				_script85_loc00
_script86:
		game_flags_set		FLAG00_SYS
		frame_draw_up		PORTRAIT09_MURDOCK
		ptr_load			_script86_msg00
		msg_draw_up			; [ランボ-、よくきてくれた。\サクセンシキカンのマ-ドックだ。]
		ptr_load			_script86_msg01
		msg_draw_up			; [ゲンチへ センニュウし、もしも \ホリョが シュウヨウされていたならば、\そのショウコシャシンを もちかえるのが\しごとだ。\けっしてテキと コウセンしてはならん。]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script86_msg02
		msg_draw_down		; [シャシンを？ きゅうしゅつせずに？]
		ptr_load			_script86_msg03
		msg_draw_up			; [くりかえす、コウセンはゆるさん。\では ブキコにいって\みじたくをしてくれ。\コウウンを いのっている。]
		set_room_idx		$00
		stop
_script87:
		frame_draw_up		PORTRAIT0D_ERICSON
		jmp_flags_not_set	FLAG00_SYS, _script87_loc00
		jmp_branch			_script87_loc01
_script87_loc00:
		ptr_load			_script87_msg00
		msg_draw_up			; [マ-ドックしれいかんのキョカを\もらっていないと\ブキを わたすわけにはいかないんだ。]
		set_room_idx		$00
		stop
		------------------
_script87_loc01:
		jmp_flags_not_set	FLAG08_SYS, _script87_loc02
		jmp_branch			_script87_loc03
_script87_loc02:
		ptr_load			_script87_msg01
		msg_draw_up			; [ゲリラせんで ゆうこうな\ブキをよういしておいた。\このナイフは、きみにとって\ライフルいじょうに りようかちのある\ブキだろう。]
		game_flags_set		FLAG08_SYS
		add_10_knifes
		add_10_knifes
		add_5_potions
		------------------
_script87_loc03:
		game_hours_set		$17
		ptr_load			_script87_msg02
		msg_draw_up			; [しゅっぱつまで ジカンがない。\はやく トラウトマンたいさのところへ\いけ！]
		set_room_idx		$00
		stop
_script88:
		frame_draw_up		PORTRAIT08_TRAUMAN1
		jmp_flags_not_set	FLAG08_SYS, _script88_loc00
		jump				_script88_loc01
		------------------
_script88_loc00:
		ptr_load			_script88_msg00
		msg_draw_up			; [ランボ-。よくきてくれた。\むちゃな にくだんせんはわすれて\どうぐを かつようしろ。\せんそうは わすれろ。\あのころのベトナムは しんだ。]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script88_msg01
		msg_draw_down		; [おれもベトナムも いきています。]
		ptr_load			_script88_msg02
		msg_draw_up			; [カクノウコへ いってくれ。\マ-ドックしれいかんが まっている。]
		set_room_idx		$01
		stop
_script88_loc01:
		ptr_load			_script88_msg03
		msg_draw_up			; [ゲンチには\われわれのレンラクインがいる。\ゲンチジンのコ-だ。\まず、カレがジャングルを\あんないしてくれるだろう。]
		checkpoint_set
		ptr_load			_script88_msg04
		msg_draw_up			; [せんにゅうから だっしゅつまで\36ジカンだ。みちくさを くうなよ。\テキに はっけんされたら\さんちょうの ピックアップちてんへ\ヘリコプタ-が むかえにいく。]
		ptr_load			_script88_msg05
		msg_draw_up			; [ランボ-・・・・\こううんを いのっている。]
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
		msg_draw_up			; [まっていたのよ、ランボ-。\わたしは レンラクインのコ-。\おんなで びっくりした？\なにか きいておくことはない？]
		frame_draw_down		PORTRAIT00_RAMBO
		input_2_options
		ptr_load			_script89_msg01
		msg_draw_down		; [シュウヨウジョ のことを\なにか しらないか？\ \オレのこと どうおもう？]
		jmpne_option		$02, _script89_loc00
		sprite_draw_down	PORTRAIT02_RAMBO_HAPPY
		sprite_draw_up		PORTRAIT04_CO_HAPPY
		ptr_load			_script89_msg02
		msg_draw_up			; [・・・えっ？\たくましくて、ス・テ・キ。]
		------------------
_script89_loc00:
		ptr_load			_script89_msg03
		msg_draw_up			; [シュウヨウジョは カワのひがしの\ジャングルに あるわ。\ミツユギョウシャと\はなしをつけてあるから、はやく\ふなつきばへ いきましょう。]
		set_room_idx		$0a
		stop
_script8A:
		checkpoint_set
		jmp_flags_not_set	FLAG09_CO_TAKEN, _script8A_loc00
		jmp_branch			_script8A_loc01
_script8A_loc00:
		frame_draw_up		PORTRAIT14_PIRATE
		ptr_load			_script8A_msg00
		msg_draw_up			; [なんだ、アンタ。みかけないヤツだな。\あいにく オレたちは\ゼンリョウな アキンドでね。\ヘンなヤツを フネにのせるわけには\いかないんだよ。]
		set_room_idx		$06
		stop
		------------------
_script8A_loc01:
		jmp_flags_not_set	FLAG0E_BOAT,	_script8A_loc02
		frame_draw_up		PORTRAIT14_PIRATE
		jump				_script8A_loc03
		------------------
_script8A_loc02:
		frame_draw_down		PORTRAIT03_CO
		ptr_load			_script8A_msg01
		msg_draw_down		; [ハナシは つけてあるはずよ。\フネにのりたいの。\はい、おカネをわたすわ。]
		frame_draw_up		PORTRAIT14_PIRATE
		ptr_load			_script8A_msg02
		msg_draw_up			; [ああ、フネにのりたいってのは\アンタたちか。\ジゴクのサタも カネしだいってな。]
_script8A_loc03:
		ptr_load			_script8A_msg03
		msg_draw_up			; [カネさえもらえば、フネだろうと\なんだろうと のせてやるぜ。\・・・・はやくのりな。]
		game_flags_set		FLAG0E_BOAT
		set_room_idx		$06
		stop
_script8B:
		checkpoint_set
		frame_draw_up		PORTRAIT03_CO
		jmp_flags_not_set	FLAG01_SYS, _script8B_loc00
		ptr_load			_script8B_msg00
		msg_draw_up			; [ランボ-！\なんだか ようすがへんよ。]
		jmp_branch			_script8B_loc01
_script8B_loc00:
		jump				_script8B_loc02
		------------------
_script8B_loc01:
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script8B_msg01
		msg_draw_down		; [テキのフネだ。\おれたちを うらぎったな。]
		sprite_draw_up		PORTRAIT14_PIRATE
		ptr_load			_script8B_msg02
		msg_draw_up			; [そうだ。\カネになれば なんでもするのさ。\おとなしく してもらおうか。]
		game_flags_clear	FLAG0E_BOAT
		set_room_idx		$60
		stop
_script8B_loc02:
		jmp_flags_not_set	FLAG11_PEDANT, _script8B_loc03
		jump				_script8B_loc04
		------------------
_script8B_loc03:
		ptr_load			_script8B_msg03
		msg_draw_up			; [ランボ-。\なぜこんな キケンなニンムを\ひきうけたの？\アメリカは、あなたなら\セイコウするって、しんじてるのね。]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script8B_msg04
		msg_draw_down		; [オレを ジャングルにほうりこむことで\コクミンにたいする セキニンを\はたしたことに したいだけさ。\きみはなぜ レンラクイン\などしているんだ。]
		ptr_load			_script8B_msg05
		msg_draw_up			; [ちちが このシゴトをしていたの。\ちちがころされ わたしがあとを\ひきついだのよ。でも・・・\あたしは こんなジゴクはもうイヤ！\アメリカで しずかにくらしたいわ。]
		ptr_load			_script8B_msg06
		msg_draw_down		; [このペンダントは？]
		sprite_draw_up		PORTRAIT04_CO_HAPPY
		ptr_load			_script8B_msg07
		msg_draw_up			; [おまもりよ。\あなたの おまもりは？]
		ptr_load			_script8B_msg08
		msg_draw_down		; [この ナイフかな。]
		ptr_load			_script8B_msg09
		msg_draw_up			; [ランボ-、このペンダントをあげるわ。\たいせつにしてね。]
		life_restore
		game_flags_set		FLAG11_PEDANT
_script8B_loc04:
		ptr_load			_script8B_msg0a
		msg_draw_up			; [やっと ついたみたい。\ここから シュウヨウジョまでは\あるかないといけないわ。]
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
		msg_draw_up			; [むらへ ようすをさぐりに\いきましょう。\ヒガシへ いけばいきつくわ。]
		stop
		------------------
_script8C_loc01:
		jmp_flags_not_set	FLAG01_SYS, _script8C_loc02
		jmp_branch			_script8C_loc03
_script8C_loc02:
		ptr_load			_script8C_msg01
		msg_draw_up			; [シュウヨウジョは ここから\ミナミへ いったところよ。]
		stop
		------------------
_script8C_loc03:
		ptr_load			_script8C_msg02
		msg_draw_up			; [ニシのかわを わたって\やまを のぼったところが\ヘリコプタ-のピックアップポイントよ。]
		jmp_flags_not_set	FLAG0A_MISSION_TIME_OVER, _script8C_loc04
		jmp_branch			_script8C_loc05
_script8C_loc04:
		stop
		------------------
_script8C_loc05:
		ptr_load			_script8C_msg03
		msg_draw_up			; [でも、やくそくのじかんは もう\とっくに すぎてしまったわ。\ヘリコプタ-は むかえにこないわ。\むらへ いってかくれましょう。]
		stop
_script8D:
		checkpoint_set
		frame_draw_up		PORTRAIT15_KID
		ptr_load			_script8D_msg00
		msg_draw_up			; [エ-ン エ-ン\ヒック ヒック]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script8D_msg01
		msg_draw_down		; [あんしんしろ。たすけてやるぞ。]
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
		msg_draw_up			; [よかったわ ぶじで。\てきが きづいたみたいよ。]
		jmp_flags_not_set	FLAG06_POW_TAKEN, _script8F_loc00
		ptr_load			_script8F_msg01
		msg_draw_up			; [え！\ホリョを つれてきたの。\シャシンを とるだけのはずでは\なかったの。]
		------------------
_script8F_loc00:
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script8F_msg02
		msg_draw_down		; [いそいでもどろう。ここで やられたら\もともこもない。]
		set_room_idx		$6c
		stop
_script90:
		checkpoint_set
		game_flags_set		FLAG01_SYS
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script90_msg00
		msg_draw_down		; [ここからさきは オレひとりでいく。\キケンだから ついてくるな。]
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_script90_msg01
		msg_draw_up			; [そう・・・。しかたないわね。\オトにきをつけて。\オトのでるブキは テキを\あつめてしまうから。]
		set_room_idx		$25
		stop
_script91:
		frame_draw_down		PORTRAIT03_CO
		ptr_load			_script91_msg00
		msg_draw_down		; [こんばんは。\わたしをよびだしたのは あなた？]
		frame_draw_up		PORTRAIT11_SOLDIER2
		jmp_flags_not_set	FLAG07_DRESS_ITEM, _script91_loc00
		jmp_branch			_script91_loc01
_script91_loc00:
		ptr_load			_script91_msg01
		msg_draw_up			; [ここは むらのやつらがくるところじゃ\ないんだ。\ケガしないうちに かえりな。]
		set_room_idx		$6f
		stop
		------------------
_script91_loc01:
		ptr_load			_script91_msg02
		msg_draw_up			; [いや、おれじゃねえよ。\たぶん タイチョウだろう。\タイチョウのオンナずきにも\こまったものだ。\もたもたしねえで さっさとはいりな。]
		set_room_idx		$6e
		stop
_script92:
		frame_draw_down		PORTRAIT03_CO
		jmp_flags_not_set	FLAG00_SYS, _script92_loc00
		jump				_script92_loc02
		------------------
_script92_loc00:
		ptr_load			_script92_msg00
		msg_draw_down		; [こんばんは。]
		frame_draw_up		PORTRAIT11_SOLDIER2
		ptr_load			_script92_msg01
		msg_draw_up			; [おっ、なかなかいいオンナじゃないか。\こっちこいよ。ヘヘヘ。]
		input_2_options
		ptr_load			_script92_msg02
		msg_draw_down		; [いや-ね、エッチ！\バシ！\ \ふふふ。コヤのなかにはいって、\イイコト しましょうよん。]
		jmpne_option		$01, _script92_loc01
		ptr_load			_script92_msg03
		msg_draw_up			; [なにすんだよ、こいつ！\とっとと かえれ！]
		set_room_idx		$6e
		stop
		------------------
_script92_loc01:
		ptr_load			_script92_msg04
		msg_draw_down		; [きょうなにか あったみたいね。]
		ptr_load			_script92_msg05
		msg_draw_up			; [ああ。スパイをつかまえたんだ。\さっきまで ごうもんしてたんだが\のびちまったんだ。]
		ptr_load			_script92_msg06
		msg_draw_down		; [ゴウモンゴヤのカギは\あなたが もっているというわけね！]
		sprite_draw_up		PORTRAIT_CLEAR
		ptr_load			_script92_msg07
		msg_draw_up			; [そんなことより ヘヘヘ。\ゴキ！ バタン！\・・・]
_script92_loc02:
		ptr_load			_script92_msg08
		msg_draw_down		; [やっと カギをてにいれたわ。\これで ランボ-をたすけだせるわ。]
		game_flags_set		FLAG00_SYS
		set_room_idx		$6e
		stop
_script93:
		frame_draw_up		PORTRAIT10_SOLDIER1
		ptr_load			_script93_msg00
		msg_draw_up			; [おい、こんなところでなにをしている。\なにものだ おまえ！\さっさとかえらないと\ろうやに とじこめるぞ。]
		frame_draw_down		PORTRAIT03_CO
		ptr_load			_script93_msg01
		msg_draw_down		; [・・・ごめんなさい。]
		ptr_load			_script93_msg02
		msg_draw_up			; [おい、どこにいくんだ。\でぐちは ミギだ。\ヒダリは、ゴウモンゴヤがあるんだぞ。\それとも、ゴウモンしてほしいのか？]
		set_room_idx		$6e
		stop
_script94:
		checkpoint_set
		frame_draw_up		PORTRAIT03_CO
		jmp_flags_not_set	FLAG00_SYS, _script94_loc00
		ptr_load			_script94_msg00
		msg_draw_up			; [ランボ-、だいじょうぶ。\すぐにカギを あけるから。]
		jmp_branch			_script94_loc01
_script94_loc00:
		jump				_script94_loc02
		------------------
_script94_loc01:
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script94_msg01
		msg_draw_down		; [ありがとう。ぶきをくれ！]
		ptr_load			_script94_msg02
		msg_draw_up			; [てきが きづいたみたい。\いそいで にげましょう。]
		game_flags_clear	FLAG0C_SYS
		set_room_idx		$70
		stop
_script94_loc02:
		ptr_load			_script94_msg03
		msg_draw_up			; [ランボ-、わたしよ。\カギを さがしてくるから\すこしまっていて。]
		frame_draw_down		PORTRAIT_CLEAR
		ptr_load			_script94_msg04
		msg_draw_down		; [・・・・。]
		set_room_idx		$6d
		stop
_script95:
		checkpoint_set
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_script95_msg00
		msg_draw_up			; [ランボ-。\このさきが ヘリコプタ-の\ピックアップポイントよ。]
		jmp_flags_not_set	FLAG0A_MISSION_TIME_OVER, _script95_loc00
		jmp_branch			_script95_loc01
_script95_loc00:
		jump				_script95_loc02
		------------------
_script95_loc01:
		ptr_load			_script95_msg01
		msg_draw_up			; [でも、もうやくそくのじかんは\とっくにすぎて しまったから\ヘリコプタ-は こないわ。]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script95_msg02
		msg_draw_down		; [しょうがない。\ジャングルに もどろう。]
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
		msg_draw_up			; [このままかえってしまうの？\なにも できなかったわね。]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script95_msg04
		msg_draw_down		; [そうだな。まだじかんがあるし\シュウヨウジョに いってみよう。]
		ptr_load			_script95_msg05
		msg_draw_up			; [シュウヨウジョは ここから\ずっと ミナミよ。]
		set_room_idx		$18
		player_pos_set		$00, $c0
		stop
_script95_loc05:
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script95_msg06
		msg_draw_down		; [コ-。いろいろせわになった。\キミが いなかったら、\ニンムは せいこうしなかっただろう。]
		ptr_load			_script95_msg07
		msg_draw_up			; [ランボ-。\わたしを つれてかえってくれない？\わたしも アメリカにいきたいわ。]
		jmp_flags_not_set	FLAG06_POW_TAKEN, _script95_loc06
		ptr_load			_script95_msg08
		msg_draw_down		; [キミを アメリカにつれてかえるわけには\いかない。]
		jump				_script95_loc07
		------------------
_script95_loc06:
		input_2_options
		ptr_load			_script95_msg09
		msg_draw_down		; [キミを アメリカにつれてかえるわけには\いかない。\ \キミも ここにいてはあぶない。\いっしょに かえろう。]
		jmpne_option		$02, _script95_loc07
		sprite_draw_up		PORTRAIT04_CO_HAPPY
		ptr_load			_script95_msg0a
		msg_draw_up			; [ありがとう・・・とてもうれしいの・・・\はやく いきましょう。\おってが すぐそこまできているわ。]
		game_flags_set		FLAG09_CO_TAKEN
		set_room_idx		$0b
		player_pos_set		$00, $a0
		stop
		------------------
_script95_loc07:
		sprite_draw_up		PORTRAIT05_CO_SAD
		ptr_load			_script95_msg0b
		msg_draw_up			; [ざんねんだわ。\もうこれで あえないのね。\さようなら。きをつけて。]
		game_flags_clear	FLAG09_CO_TAKEN
		set_room_idx		$0b
		player_pos_set		$00, $a0
		stop
_script96:
		frame_draw_up		PORTRAIT0D_ERICSON
		jmp_flags_not_set	FLAG06_POW_TAKEN, _script96_loc00
		ptr_load			_script96_msg00
		msg_draw_up			; [ほんぶ、ランボ-をみつけた。\ホリョをつれている。\これから きゅうしゅつにむかう。\てきに おわれている。]
		jmp_branch			_script96_loc01
_script96_loc00:
		jump				_script96_loc02
		------------------
_script96_loc01:
		frame_draw_down		PORTRAIT_CLEAR
		ptr_load			_script96_msg01
		msg_draw_down		; [(ホンブからのムセン)\・・ きんきゅう じたい ・・\・・ さくせんを ちゅうしせよ ・・]
		sprite_draw_down	PORTRAIT08_TRAUMAN1
		ptr_load			_script96_msg02
		msg_draw_down		; [なんだと このまま かえれるか。\つれてかえるぞ。\みごろしに するつもりか。]
		ptr_load			_script96_msg03
		msg_draw_up			; [わたしは めいれいにしたがいます。]
		sprite_draw_down	PORTRAIT0C_TRAUMAN2
		ptr_load			_script96_msg04
		msg_draw_down		; [やとわれヘイめが。\みかたを みすてるのか！]
		set_room_idx		$0b
		anim_scene_set		$a9
		stop
_script96_loc02:
		ptr_load			_script96_msg05
		msg_draw_up			; [ほんぶ、ランボ-をみつけた。\これから きゅうしゅつにむかう。\てきに おわれている。]
		frame_draw_down		PORTRAIT_CLEAR
		ptr_load			_script96_msg06
		msg_draw_down		; [(ホンブからのムセン)\・・ いそいで きゅうしつしろ！ ・・]
		sprite_draw_up		PORTRAIT08_TRAUMAN1
		ptr_load			_script96_msg07
		msg_draw_up			; [ランボ-。はやくのれ。\よしっ、これでこんなぶっそうな\ジャングルとも おさらばだ。\ジョウショウしろ！]
		set_room_idx		$0b
		anim_scene_set		$7d
		stop
_script97:
		ptr_load			_script97_msg00
		msg_printf			$20e7	; [そのころ てきにつかまったランボ-は\ベトコンのごうもんをうけていた。\そこへ ヒガシがわゲリラブタイが\とうちゃくして。]
		msg_input_handler
		frame_draw_up		PORTRAIT0E_PADOVSKY
		ptr_load			_script97_msg01
		msg_draw_up			; [わたしは パドフスキ-ちゅうさだ。\きみが だれかはしらんが\じきわかるだろう。]
		ptr_load			_script97_msg02
		msg_draw_up			; [きみは このくににいるホリョを\きゅうしゅつにきた。\そのきもちは よくわかる。\しかし、とらえられたことは マズい。\べんめいを きこう。]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script97_msg03
		msg_draw_down		; [・・・・・。]
		ptr_load			_script97_msg04
		msg_draw_up			; [まず、たいほされたことを\キチにれんらくするのだ。\スパイかつどうの つみでこくはつ\されたと。]
		ptr_load			_script97_msg05
		msg_draw_down		; [・・・・・。]
		sprite_draw_down	PORTRAIT00_RAMBO
		ptr_load			_script97_msg06
		msg_draw_up			; [まだげんきがのこってるようだな。\ユ-シン！\ユ-シンぐんそうにとっては\きみは ただのじっけんどうぶつだ。]
		sprite_draw_up		PORTRAIT0F_YUSIN
		ptr_load			_script97_msg07
		msg_draw_up			; [「バキ ボク バシバシ」]
		sprite_draw_down	PORTRAIT01_RAMBO_ANGRY
		ptr_load			_script97_msg08
		msg_draw_down		; [「ギャ-------」]
		sprite_draw_up		PORTRAIT0E_PADOVSKY
		sprite_draw_down	PORTRAIT00_RAMBO
		ptr_load			_script97_msg09
		msg_draw_up			; [おまえのしきかんは キミをみすて\たんだぞ。\キミは そんなやつらをかばうのかね？\れんらくしないと ホリョの\いのちはないぞ。]
_script97_loc00:
		ptr_load			_script97_msg0a
		msg_draw_up			; [ムセンキを つかって、\キチに れんらくしろ。]
		input_2_options
		ptr_load			_script97_msg0b
		msg_draw_down		; [・・・・。\ \ \220・・・56・・どうぞ。]
		jmpne_option		$01, _script97_loc01
		jump				_script97_loc00
		------------------
_script97_loc01:
		sprite_draw_up		PORTRAIT_CLEAR
		ptr_load			_script97_msg0c
		msg_draw_up			; [(ホンブからのムセン)\・・ ゲンザイチと、じょうきょうを\   ほうこくせよ。 ・・]
		sprite_draw_up		PORTRAIT0E_PADOVSKY
		ptr_load			_script97_msg0d
		msg_draw_up			; [こたえろ。\こたえないと ともだちがしぬぞ。]
		sprite_draw_up		PORTRAIT_CLEAR
		ptr_load			_script97_msg0e
		msg_draw_up			; [・・ ジョン わたしだ。\   へんじしろ。 ・・]
		ptr_load			_script97_msg0f
		msg_draw_down		; [マ-ドックは？]
		ptr_load			_script97_msg10
		msg_draw_up			; [・・ ここにいる。 ・・\・・ どこだ。ばしょを\   きゅうしゅつにいく。 ・・]
		sprite_draw_down	PORTRAIT01_RAMBO_ANGRY
		ptr_load			_script97_msg11
		msg_draw_down		; [・・・・。\マ-ドック、いのちをもらいにいくぜ！！]
		set_room_idx		$9f
		stop
_script98:
		checkpoint_set
		frame_draw_up		PORTRAIT12_VILLAGER1
		jmp_flags_not_set	FLAG0C_SYS, _script98_loc00
		jmp_branch			_script98_loc01
_script98_loc00:
		ptr_load			_script98_msg00
		msg_draw_up			; [むらで めんどうを\おこしてもらっては こまる。\はやく でていってくれ。]
		set_room_idx		$0c
		stop
		------------------
_script98_loc01:
		jmp_flags_not_set	FLAG07_DRESS_ITEM, _script98_loc02
		jump				_script98_loc03
		------------------
_script98_loc02:
		ptr_load			_script98_msg01
		msg_draw_up			; [おや、オンナにしてはいいライフルを\もっているな。\そのライフルと、このチャイナドレスと\こうかんしてくれないか。]
		frame_draw_down		PORTRAIT03_CO
		input_2_options
		ptr_load			_script98_msg02
		msg_draw_down		; [ざんねんだわ、このライフルは\てばなせないのよ。\ \あら、きれいなチャイナドレス\まえからほしかったのよ。]
		jmpne_option		$01, _script98_loc03
		ptr_load			_script98_msg03
		msg_draw_up			; [そうか、ざんねんだ。\きが かわったらまたきてくれ。]
		set_room_idx		$0c
		stop
		------------------
_script98_loc03:
		ptr_load			_script98_msg04
		msg_draw_up			; [チャイナドレスが よくにあっているよ。]
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
		msg_draw_up			; [こどもが きたのほうのどうくつで\ゆくえふめいになったんだ。\さがしてくれないだろうか。]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script99_msg01
		msg_draw_down		; [・・・・・。]
		sprite_draw_up		PORTRAIT03_CO
		ptr_load			_script99_msg02
		msg_draw_up			; [ランボ-。たすけだしてあげて。]
		game_flags_set		FLAG00_SYS
		set_room_idx		$3a
		stop
_script99_loc02:
		ptr_load			_script99_msg03
		msg_draw_up			; [こどもをたすけてくれて ありがとう。\なにもできないが、ゆっくり\やすんでいってくれ。]
		life_restore
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script99_msg04
		msg_draw_down		; [あまり、ゆっくりしてられないんだ。\よし、がんばるぞ。]
		game_flags_clear	FLAG04_KID_TAKEN
		game_flags_set		FLAG02_KID_SAVED
		set_room_idx		$3a
		stop
_script9A:
		checkpoint_set
		frame_draw_up		PORTRAIT12_VILLAGER1
		jmp_flags_not_set	FLAG0A_MISSION_TIME_OVER, _script9A_loc00
		ptr_load			_script9A_msg00
		msg_draw_up			; [おや おまえはアメリカじんだな。\こんなやまおくに なにしにきた。]
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
		msg_draw_up			; [おや おまえはアメリカじんだな。\こんなやまおくに なにしにきた。]
		jmp_flags_not_set	FLAG00_SYS, _script9A_loc02
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script9A_msg02
		msg_draw_down		; [どうくつにいって\こどもを たすけだしたいんだ。]
		jmp_branch			_script9A_loc03
_script9A_loc02:
		set_room_idx		$3a
		stop
		------------------
_script9A_loc03:
		game_flags_set		FLAG03_LAMP_ITEM
		ptr_load			_script9A_msg03
		msg_draw_up			; [ランプを かしてあげよう。\ランプがなければ どうくつは\とてもきけんだからな。]
		set_room_idx		$3a
		stop
_script9B:
		checkpoint_set
		frame_draw_up		PORTRAIT13_VILLAGER2
		jmp_flags_not_set	FLAG0C_SYS, _script9B_loc00
		ptr_load			_script9B_msg00
		msg_draw_up			; [アメリカのスパイがつかまったらしい。\いまごろ ごうもんを\うけているだろう。]
		jmp_branch			_script9B_loc01
_script9B_loc00:
		jump				_script9B_loc04
		------------------
_script9B_loc01:
		frame_draw_down		PORTRAIT03_CO
		ptr_load			_script9B_msg01
		msg_draw_down		; [たすけだして あげたいわ。]
		jmp_flags_not_set	FLAG0D_SYS, _script9B_loc02
		jmp_branch			_script9B_loc03
_script9B_loc02:
		add_5_potions
		------------------
_script9B_loc03:
		game_flags_set		FLAG0D_SYS
		ptr_load			_script9B_msg02
		msg_draw_up			; [クスリを わけてあげよう。\これを カレにのませてあげなさい。]
		set_room_idx		$0c
		stop
_script9B_loc04:
		ptr_load			_script9B_msg03
		msg_draw_up			; [つかれてるみたいだな。\すこしやすんで いきなさい。]
		frame_draw_down		PORTRAIT00_RAMBO
		life_restore
		ptr_load			_script9B_msg04
		msg_draw_down		; [ありがとう。\これで、もうひとあばれ できそうだ。]
		set_room_idx		$0c
		stop
_script9C:
		checkpoint_set
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_script9C_msg00
		msg_draw_up			; [もう あんしんよ。\ひどいめに あったわね。\これからどうするの？ タイへ？\それから アメリカね。\わたしを つれてかえってくれない？]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script9C_msg01
		msg_draw_down		; [キミも ここにいてはあぶない。\いっしょに かえろう。]
		sprite_draw_up		PORTRAIT04_CO_HAPPY
		ptr_load			_script9C_msg02
		msg_draw_up			; [ありがとう・・・とてもうれしいの・・・\はやく いきましょう。\おってが すぐそこまできているわ。]
		sprite_draw_up		PORTRAIT_CLEAR
		ptr_load			_script9C_msg03
		msg_draw_up			; [ズドドドドドドドドド\ぎゃ-----]
		sprite_draw_up		PORTRAIT05_CO_SAD
		ptr_load			_script9C_msg04
		msg_draw_down		; [コ-！ しっかりするんだ！]
		ptr_load			_script9C_msg05
		msg_draw_up			; [ランボ-・・・。\わたし、もうアメリカへ\いけないのね・・・。]
		ptr_load			_script9C_msg06
		msg_draw_down		; [なにいっているんだ！\オレは おまえとアメリカに・・・。]
		game_flags_set		FLAG12_BANDANA
		sprite_draw_up		PORTRAIT06_CO_DEAD
		ptr_load			_script9C_msg07
		msg_draw_up			; [ランボ-・・・ ありがとう。\わたしを・ わたしをわすれないで・・。]
		ptr_load			_script9C_msg08
		msg_draw_down		; [コ-！]
		game_flags_clear	FLAG09_CO_TAKEN
		set_room_idx		$48
		stop
_script9D:
		checkpoint_set
		ptr_load			_script9D_msg00
		msg_printf			$20e7	; [ランボ-は、ヘリコプタ-のカギをみつけた。]
		jmp_flags_not_set	FLAG10_HELI_KEY, _script9D_loc00
		msg_input_handler
		set_room_idx		$55
		stop
		------------------
_script9D_loc00:
		ptr_load			_script9D_msg01
		msg_printf			$2127	; [そこへ ユ-シンぐんそうが あらわれて、\・・・・]
		msg_input_handler
		frame_draw_up		PORTRAIT0F_YUSIN
		ptr_load			_script9D_msg02
		msg_draw_up			; [じっくり りょうりしてやろう！\せいぜい あばれるがいい。]
		game_flags_set		FLAG10_HELI_KEY
		set_room_idx		$55
		stop
_script9E:
		checkpoint_set
		jmp_flags_not_set	FLAG10_HELI_KEY, _script9E_loc00
		jmp_branch			_script9E_loc01
_script9E_loc00:
		ptr_load			_script9E_msg00
		msg_printf			$20e7	; [カギをもっていないと\ヘリコプタ-には のれないぞ。]
		msg_input_handler
		set_room_idx		$54
		stop
		------------------
_script9E_loc01:
		game_flags_set		FLAG08_SYS
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_script9E_msg01
		msg_draw_down		; [くるしい たたかいだったが、\これで ようやくおわりがみえてきた。\これから シュウヨウジョにいって\ホリョを きゅうしゅつしよう。]
		jmp_flags_not_set	FLAG09_CO_TAKEN, _script9E_loc02
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_script9E_msg02
		msg_draw_up			; [ランボ- はやくじょうしょうして！\てきが おってきたわ！]
		------------------
_script9E_loc02:
		game_flags_clear	FLAG06_POW_TAKEN
		player_pos_set		$03, $80
		set_room_idx		$54
		anim_scene_set		$7f
		stop
_script9F:
		ptr_load			_script9F_msg00
		msg_printf			$20e7	; [そのころコ-は、ランボ-を\たすけるために・・・・。]
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
		msg_draw_down		; [だいじょうぶか？ たすけにきたぞ。]
		frame_draw_up		PORTRAIT07_BANKS_POW
		ptr_load			_scriptA0_msg01
		msg_draw_up			; [からだが、よわりきってしにそうだ。\あしでまといに なるかもしれないが、\つれていってくれ。]
		ptr_load			_scriptA0_msg02
		msg_draw_down		; [あたりまえじゃないか。げんきだせ。\もうすこしの しんぼうだ。\いそいでにげよう。]
		game_flags_set		FLAG06_POW_TAKEN
		set_room_idx		$77
		stop
_scriptA1:
		checkpoint_set
		frame_draw_up		PORTRAIT07_BANKS_POW
		ptr_load			_scriptA1_msg00
		msg_draw_up			; [おねがいだ ころさないでくれ。]
		frame_draw_down		PORTRAIT00_RAMBO
		input_2_options
		ptr_load			_scriptA1_msg01
		msg_draw_down		; [だいじょうぶだ。おれはみかただ。\いまなわを ほどくから。\ \すまない。\シャシンをとるのが ニンムなんだ。]
		jmpne_option		$02, _scriptA1_loc00
		ptr_load			_scriptA1_msg02
		msg_draw_up			; [たすけに きてくれたのではないのか。\おねがいだ たすけてくれ！]
		game_flags_set		FLAG05_PHOTO_ITEM
		set_room_idx		$30
		stop
		------------------
_scriptA1_loc00:
		ptr_load			_scriptA1_msg03
		msg_draw_up			; [・・・たすかった。\ほかにも・・・・。]
		game_flags_set		FLAG06_POW_TAKEN
		------------------
		ptr_load			_scriptA1_msg04
		msg_draw_down		; [またもどる。\いそいで にげよう。]
		set_room_idx		$30
		stop
_scriptA2:
		checkpoint_set
		game_flags_clear	FLAG00_SYS
		frame_draw_down		PORTRAIT00_RAMBO
		jmp_flags_not_set	FLAG06_POW_TAKEN, _scriptA2_loc00
		ptr_load			_scriptA2_msg00
		msg_draw_down		; [はやく ヘリにのれ！]
		jmp_branch			_scriptA2_loc01
_scriptA2_loc00:
		jump				_scriptA2_loc02
		------------------
_scriptA2_loc01:
		frame_draw_up		PORTRAIT07_BANKS_POW
		ptr_load			_scriptA2_msg01
		msg_draw_up			; [やったぜ。ベトナムとも\これで おさらばだ。]
		anim_scene_set		$7e
		set_room_idx		$77
		stop
_scriptA2_loc02:
		ptr_load			_scriptA2_msg02
		msg_draw_down		; [ホリョが まだいるはずだ。\きゅうしゅつして\シュウヨウジョを だっしゅつしょう。]
		jmp_flags_not_set	FLAG09_CO_TAKEN, _scriptA2_loc03
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_scriptA2_msg03
		msg_draw_up			; [わたしも てつだうわ。]
		jmp_branch			_scriptA2_loc04
_scriptA2_loc03:
		set_room_idx		$77
		stop
		------------------
_scriptA2_loc04:
		ptr_load			_scriptA2_msg04
		msg_draw_down		; [きみは、ヘリでまっていたほうが\いいだろう。]
		set_room_idx		$77
		stop
_scriptA3:
		frame_draw_up		PORTRAIT09_MURDOCK
		jmp_flags_not_set	FLAG06_POW_TAKEN, _scriptA3_loc00
		ptr_load			_scriptA3_msg00
		msg_draw_up			; [めいれいを くだすのはわたしではない。\わたしは うけるがわだ。\・・・・・・・・・]
		jmp_branch			_scriptA3_loc01
_scriptA3_loc00:
		jump				_scriptA3_loc02
		------------------
_scriptA3_loc01:
		sprite_draw_up		PORTRAIT0B_MURDOCK_SAD
		ptr_load			_scriptA3_msg01
		msg_draw_up			; [こんなことに なるとは\おもわなかった。\・・・・・・・・・]
		ptr_load			_scriptA3_msg02
		msg_draw_up			; [わたしには めいれいのひとつだった。\・・・・・・・・・]
		frame_draw_down		PORTRAIT01_RAMBO_ANGRY
		ptr_load			_scriptA3_msg03
		msg_draw_down		; [にんむ。かんりょうしました。]
		sprite_draw_down	PORTRAIT00_RAMBO
		ptr_load			_scriptA3_msg04
		msg_draw_down		; [まだ、おうぜいのっこっているはずだ。\ころされたくないなら、\ぜいいん きゅうしゅつしろ！]
		game_flags_set		FLAG00_SYS
		set_room_idx		$62
		stop
_scriptA3_loc02:
		jmp_flags_not_set	FLAG05_PHOTO_ITEM, _scriptA3_loc03
		ptr_load			_scriptA3_msg05
		msg_draw_up			; [ごくろうだった。ランボ-。\きみならやると わたしはしんじていた。\きみは もうジユウだ。\どこへでも すきなところへいきたまえ。]
		jmp_branch			_scriptA3_loc04
_scriptA3_loc03:
		jump				_scriptA3_loc05
		------------------
_scriptA3_loc04:
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_scriptA3_msg06
		msg_draw_down		; [ホリョきゅうしゅつに いかないのか？]
		ptr_load			_scriptA3_msg07
		msg_draw_up			; [だめだ。\あのシャシンが、ショウコに\ならなかったんだ。]
		set_room_idx		$62
		stop
_scriptA3_loc05:
		sprite_draw_up		PORTRAIT0A_MURDOCK_ANGRY
		ptr_load			_scriptA3_msg08
		msg_draw_up			; [サクセンは しっぱいだ。\わたしは さいしょから\キミには むりなことだと\おもっていた。]
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
		msg_draw_up			; [ごくろうだった。\ランボ-]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_scriptA4_msg01
		msg_draw_down		; [・・・・・・・]
		set_room_idx		$61
		stop
_scriptA4_loc03:
		ptr_load			_scriptA4_msg02
		msg_draw_up			; [きみは、ほんとうにたいしたやつだ。\じぶんじしんで ジユウをつかみとった\んだ。]
		ptr_load			_scriptA4_msg03
		msg_draw_up			; [ジョン どこへいく。]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_scriptA4_msg04
		msg_draw_down		; [さあ。]
		ptr_load			_scriptA4_msg05
		msg_draw_up			; [にこめの めいよしょうだな。]
		ptr_load			_scriptA4_msg06
		msg_draw_down		; [くんしょうは かれらのものです。]
		ptr_load			_scriptA4_msg07
		msg_draw_up			; [きみはもう ジユウだ。\われわれのところへ もどってこい。]
		ptr_load			_scriptA4_msg08
		msg_draw_down		; [なにがある。\ともだちは ここでしに\おれのこころも しんだ。]
		ptr_load			_scriptA4_msg09
		msg_draw_up			; [まちがったせんそうだったが、\クニをにくむな。]
		ptr_load			_scriptA4_msg0a
		msg_draw_down		; [にくむ？\いのちを ささげます。]
		ptr_load			_scriptA4_msg0b
		msg_draw_up			; [では、なにがのぞみだ。]
		ptr_load			_scriptA4_msg0c
		msg_draw_down		; [かれらがのぞんだことです。\かれらは このとちにきて、\たたかいに みをとうじながら\ひとつのことを ねがった。]
		ptr_load			_scriptA4_msg0d
		msg_draw_down		; [クニへの おもいが\むくわれることです。\おれも おなじだ。]
		ptr_load			_scriptA4_msg0e
		msg_draw_up			; [このさきは？]
		ptr_load			_scriptA4_msg0f
		msg_draw_down		; [ひびを いきます。]
		set_room_idx		$b1
		sprite_draw_up		PORTRAIT_CLEAR
		sprite_draw_down	PORTRAIT02_RAMBO_HAPPY
		stop
_scriptA4_loc04:
		ptr_load			_scriptA4_msg10
		msg_draw_up			; [よくかえってきた。だが、きみはゲ-ムを\しゅうりょうしていない。\ジョン、これでまんぞくか？]
		frame_draw_down		PORTRAIT00_RAMBO
		input_2_options
		ptr_load			_scriptA4_msg11
		msg_draw_down		; [へりに のるところから\もういちど やらせてくれ。\ \もうあんな あぶないめに\あいたくない。]
		jmpne_option		$02, _scriptA4_loc05
		set_room_idx		$61
		stop
		------------------
_scriptA4_loc05:
		ptr_load			_scriptA4_msg12
		msg_draw_up			; [ほんとうの ゲ-ムのもくてきは\ホリョきゅうしゅつ なんだよ。]
		jmp_flags_not_set	FLAG08_SYS, _scriptA4_loc06
		set_room_idx		$9e
		player_pos_set		$03, $d0
		stop
		------------------
_scriptA4_loc06:
		game_flags_clear	FLAG13_SYS
		game_flags_set		FLAG09_CO_TAKEN
		set_room_idx		$95
		stop
_scriptA5:
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_scriptA5_msg00
		msg_draw_up			; [これからどうするの？ アメリカへ？\あたたかな ひと。\あたたかな まち。\あたたかな まいにち。]
		ptr_load			_scriptA5_msg01
		msg_draw_up			; [わたし、アメリカへいって\そんなくらしをするのが\ゆめだったわ。\もし、あなたさえよければ・・・。]
		frame_draw_down		PORTRAIT00_RAMBO
		ptr_load			_scriptA5_msg02
		msg_draw_down		; [コ-・・・キミには、たいせつなものを\まなんだような きがする。\それは いきる ということ\だったかもしれない、\あい だったかもしれない・・・。]
		sprite_draw_up		PORTRAIT04_CO_HAPPY
		sprite_draw_down	PORTRAIT02_RAMBO_HAPPY
		ptr_load			_scriptA5_msg03
		msg_draw_up			; [ほんとう？！\ランボ-、だいすきよっ。CHU！]
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
		ptr_load			_scriptA9_msg00
		msg_printf			$20e7	; [タイのサクセンホンブにもどった\トラウトマンは マ-ドックと\・・・・・・・・]
		msg_input_handler
		frame_draw_down		PORTRAIT08_TRAUMAN1
		ptr_load			_scriptA9_msg01
		msg_draw_down		; [いったいなんの まねだ。\さいしょから ウソをついたな。\シュウヨウジョは むじんのはずだった。]
		frame_draw_up		PORTRAIT09_MURDOCK
		ptr_load			_scriptA9_msg02
		msg_draw_up			; [わたしを だれだとおもっている。]
		ptr_load			_scriptA9_msg03
		msg_draw_down		; [わがみをかばう くさったぐんじんだ。]
		ptr_load			_scriptA9_msg04
		msg_draw_up			; [わがみではない。コッカのもんだいだ。\かってなこうどうをしたのは\きみの「エイユウ」だぞ。\シャシンだけ とってれば\もんだいなかったのだ。]
		ptr_load			_scriptA9_msg05
		msg_draw_up			; [きみっておとこは なにも\わかっておらん。\ホリョの みのしろきんを\はらえと いうのかね？\てきのふところを こやすことになるぞ。]
		sprite_draw_down	PORTRAIT0C_TRAUMAN2
		ptr_load			_scriptA9_msg06
		msg_draw_down		; [そこくのために たたかった\おとこたちだぞ！\ゲスやろう。\いまにこうかいするぞ。]
		sprite_draw_down	PORTRAIT08_TRAUMAN1
		ptr_load			_scriptA9_msg07
		msg_draw_up			; [なぜかね？]
		ptr_load			_scriptA9_msg08
		msg_draw_down		; [・・・・・・・・\ランボ-だよ。]
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
		msg_printf			$20e7	; [ミツユギョウシャのふねを\やとった ランボ-とコ-は・・・・]
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
		msg_draw_up			; [ごくろう。わたしはエリクソンだ。\きみが うわさのおとこか。\ベトナムでは でんせつだぜ。\キミとはたらけて こうえいだ。\キョウセイロウドウより マシだろ？]
		set_room_idx		$01
		stop
		------------------
_scriptAC_loc01:
		ptr_load			_scriptAC_msg01
		msg_draw_up			; [しゅっぱつまで ジカンがない。\はやく トラウトマンたいさのところへ\いけ！]
		set_room_idx		$01
		stop
_scriptAD:
		frame_draw_up		PORTRAIT07_BANKS_POW
		ptr_load			_scriptAD_msg00
		msg_draw_up			; [ありがとう。ランボ-。\きみなら かならず\きゅうしゅつ してくれると\おもっていた。]
		set_room_idx		$62
		stop
_scriptAE:
		jmp_flags_not_set	FLAG0C_SYS, _scriptAE_loc00
		ptr_load			_scriptAE_msg00
		msg_printf			$20e7	; [コ-は、ランボ-をたすけるために\シュウヨウジョに むかった。]
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
		msg_printf			$20aa	; [ジョン・ランボ-\ \ たたかいは、おわった。だが・・・]
		ending_anim
		frame_draw_down		PORTRAIT08_TRAUMAN1
		ptr_load			_scriptB1_msg01
		msg_printf			$2224	; [トラウトマンたいさ\ \ よくやった。]
		ending_anim
		frame_draw_up		PORTRAIT09_MURDOCK
		ptr_load			_scriptB1_msg02
		msg_printf			$20aa	; [マ-ドックしれいかん\ \ おれがわるいんじゃないよ！]
		ending_anim
		frame_draw_down		PORTRAIT0D_ERICSON
		ptr_load			_scriptB1_msg03
		msg_printf			$2224	; [エリクソン\ \ よっ！ えいゆう。]
		ending_anim
		set_room_idx		$b2
		stop
_scriptB2:
		frame_draw_up		PORTRAIT03_CO
		ptr_load			_scriptB2_msg00
		msg_printf			$20aa	; [コ-・バオ\ \ わたしは、あなたを・・・]
		ending_anim
		frame_draw_down		PORTRAIT07_BANKS_POW
		ptr_load			_scriptB2_msg01
		msg_printf			$2224	; [バンクス\ \ また、たすけてね！]
		ending_anim
		frame_draw_up		PORTRAIT14_PIRATE
		ptr_load			_scriptB2_msg02
		msg_printf			$20aa	; [かいぞく\ \ うらぎりものに ごちゅうい！]
		ending_anim
		frame_draw_down		PORTRAIT15_KID
		ptr_load			_scriptB2_msg03
		msg_printf			$2224	; [こども\ \ ランボ-のおじちゃん\ ありがとう。]
		ending_anim
		set_room_idx		$b3
		stop
_scriptB3:
		frame_draw_up		PORTRAIT10_SOLDIER1
		ptr_load			_scriptB3_msg00
		msg_printf			$20aa	; [へいたい1\ \ こぶんにしてください！]
		ending_anim
		frame_draw_down		PORTRAIT11_SOLDIER2
		ptr_load			_scriptB3_msg01
		msg_printf			$2224	; [へいたい2\ \ Hなことしましょうよん！]
		ending_anim
		frame_draw_up		PORTRAIT12_VILLAGER1
		ptr_load			_scriptB3_msg02
		msg_printf			$20aa	; [むらびと1\ \ ランプはいかが？]
		ending_anim
		frame_draw_down		PORTRAIT13_VILLAGER2
		ptr_load			_scriptB3_msg03
		msg_printf			$2224	; [むらびと2\ \ ちょっとやすんでいかない？]
		ending_anim
		set_room_idx		$b4
		stop
_scriptB4:
		frame_draw_up		PORTRAIT0E_PADOVSKY
		ptr_load			_scriptB4_msg00
		msg_printf			$20aa	; [パドフスキ-ちゅうさ\ \ ヘリのかぎ かえして！]
		ending_anim
		frame_draw_down		PORTRAIT0F_YUSIN
		ptr_load			_scriptB4_msg01
		msg_printf			$2224	; [ユ-シンぐんそう\ \ へへへ・・・。]
		ending_anim
		set_room_idx		$b5
		stop
_scriptB5:
		ptr_load			_scriptB5_msg00
		msg_printf			$2312	; [おつかれさまでした。]
		ending_anim
		sprite_draw_down	PORTRAIT02_RAMBO_HAPPY
		set_room_idx		$80
		scroller
		stop
_script80_msg00:
		.BYTE __,_cop,__,_1,_9,_8,_5,__,_B,_Y,__,_C,_A,_R,_O,_L,_C,_O,_eol
		.BYTE __,_I,_N,_T,_E,_R,_N,_A,_T,_I,_O,_N,_A,_L,__,_N,_dot,_V,_dot,_eol
		.BYTE _A,_L,_L,__,_R,_I,_G,_H,_T,_S,__,_R,_E,_S,_E,_R,_V,_E,_D,_dot,_eol,_eol
_script80_msg01:
		.BYTE __,__,__,__,_rig,__,__,__,__,__,__,__,__,__,__,__,__,_T,_M,_eol,_eol
_script80_msg02:
		.BYTE _R,_A,_M,_B,_O,_ddt,_F,_I,_R,_S,_T,__,_B,_L,_O,_O,_D,__,_P,_A,_R,_T,__,_I,_I,_eol,_eol
_script80_msg03:
		.BYTE _rig,__,_A,__,_R,_E,_G,_I,_S,_T,_E,_R,_E,_D,__,_T,_R,_A,_D,_E,_M,_A,_R,_K,_col,_eol
		.BYTE _T,_M,__,_A,__,_T,_R,_A,_D,_E,_M,_A,_R,_K,_col,_A,_R,_E,__,_O,_W,_N,_E,_D,_eol
		.BYTE __,_B,_Y,__,_C,_A,_R,_O,_L,_C,_O,__,_I,_N,_T,_E,_R,_N,_A,_T,_I,_O,_N,_A,_L,_eol
		.BYTE __,__,__,__,__,_N,_dot,_V,_dot,_A,_N,_D,__,_U,_S,_E,_D,__,_B,_Y,_eol
		.BYTE __,__,_P,_A,_C,_K,$E7,_I,_N,$E7,_V,_I,_D,_E,_O,__,_C,_O,_dot,_col,_L,_T,_D,_dot,_eol
		.BYTE __,__,__,_U,_N,_D,_E,_R,__,_A,_U,_T,_H,_O,_R,_I,_Z,_A,_T,_I,_O,_N,_dot,_eol,_eol
_script81_msg00:
		.BYTE _R,_E,_N,_D,__,_T,_H,_E,__,_F,_E,_E,_L,_I,_N,_G,_S,__,_O,_F,__,_H,_E,_A,_R,_T,_eol
		.BYTE __,__,_W,_I,_T,_H,__,_P,_A,_I,_N,_F,_U,_L,__,_F,_E,_E,_L,_I,_N,_G,_S,_eol,_eol
_script81_msg01:
		.BYTE _S,_T,_A,_R,_T,_eol
		.BYTE _C,_O,_N,_T,_I,_N,_U,_E,_eol,_eol
_script81_msg02:
		.BYTE _cop,_2,_0,_2,_1,__,_C,_A,_H,_4,_E,_3,__,_B,_F,_S,__,_G,_M,_B,_H,_eol,_eol
_script82_msg00:
		.BYTE $C0,$D7,$AC,$D6,$CD,$AA,$E7,$B4,$F5,$97,__,$6B,$93,$7C,$71,$79,$F5,$74,$6B,_eol,_eol
_script82_msg01:
		.BYTE _A,__,_B,__,_C,__,_D,__,_E,__,_F,__,_G,__,_H,__,_I,__,_J,_eol
		.BYTE _K,__,_L,__,_M,__,_N,__,_O,__,_P,__,_Q,__,_R,__,_S,__,_T,_eol
		.BYTE _U,__,_V,__,_W,__,_X,__,_Y,__,_Z,_eol
		.BYTE $6A,__,$6B,__,$6C,__,$6D,__,$6E,__,$6F,__,$70,__,$71,__,$72,__,$73,_eol
		.BYTE $74,__,$75,__,$76,__,$77,__,$78,__,$79,__,$7A,__,$7B,__,$7C,__,$7D,_eol
		.BYTE $7E,__,$7F,__,$80,__,$81,__,$82,__,$83,__,$84,__,$85,__,$86,__,$87,_eol
		.BYTE $88,__,$89,__,$8A,__,$8B,__,$8C,__,$8D,__,$8E,__,$8F,_eol
		.BYTE $C3,$B4,$F5,$C9,__,$AD,$AD,$C1,__,$A5,$CC,$C8,_eol,_eol
_script82_msg02:
		.BYTE $AA,$E7,$B4,$F5,$6F,$F5,$7A,$6F,$F5,$6B,$88,$76,_eol,_eol
_script82_msg03:
		.BYTE _S,_T,_A,_R,_T,_eol
		.BYTE _C,_O,_N,_T,_I,_N,_U,_E,_eol,_eol
_script83_msg00:
		.BYTE _L,_I,_F,_E,__,__,__,__,__,__,__,__,$EF,_M,_A,_X,__,__,__,__,__,__,$F0,_eol
		.BYTE _A,_N,_G,_E,_R,__,__,__,__,__,__,__,$EF,_N,_E,_X,_T,__,__,__,__,__,$F0,_eol
		.BYTE _T,_I,_M,_E,_eol,_eol
_script83_msg01:
		.BYTE _I,_N,_V,_E,_N,_T,_R,_Y,_eol,_eol
_script83_msg02:
		.BYTE $AA,$E7,_eol,_eol
_script83_msg03:
		.BYTE $85,$81,_eol,_eol
_script83_msg04:
		.BYTE $C7,$CD,$BC,$F6,_eol,_eol
_script83_msg05:
		.BYTE $73,$7D,$F5,$8C,_eol,_eol
_script83_msg06:
		.BYTE $75,$9D,$75,$96,_eol,_eol
_script83_msg07:
		.BYTE $BE,$C8,$D6,_eol,_eol
_script83_msg08:
		.BYTE $B1,$D4,$A2,$B5,$B4,$F5,$CA,$AD,_eol,_eol
_script83_msg09:
		.BYTE $BD,$C8,$82,$6F,$70,$F5,_eol,_eol
_script83_msg0a:
		.BYTE $BD,$F6,$CD,$B0,$F5,$CD,$B4,_eol,_eol
_script83_msg0b:
		.BYTE $83,$7A,$88,$70,_eol,_eol
_script83_msg0c:
		.BYTE _M,_I,_S,_S,_I,_O,_N,__,_C,_O,_D,_E,_eol,_eol
_script84_msg00:
		.BYTE _G,_A,_M,_E,__,_O,_V,_E,_R,_eol,_eol
_script84_msg01:
		.BYTE _C,_O,_N,_T,_I,_N,_U,_E,_eol
		.BYTE _S,_T,_A,_R,_T,_eol,_eol
_script85_msg00:
		.BYTE $6A,$92,$84,__,$A9,$A2,$C1,$AC,$D6,$7C,$F5,$BC,$A8,$A4,$A7,$B1,$D5,$A3,$82,_eol
		.BYTE $C7,$CD,$BE,$F5,$E7,$7F,__,$B4,$C7,$A3,$B4,$BF,$CD,$79,$6B,$74,$6F,$F5,_eol
		.BYTE $79,$76,$F5,$81,$7C,$70,$7C,$EA,_eol,_eol
_script85_msg01:
		.BYTE $C7,$CD,$BE,$F5,$E7,$EA,$84,$74,$75,$85,$F5,$91,$79,$F5,$7E,$EA,_eol
		.BYTE $75,$F5,$7B,$83,$ED,$77,$F5,$84,$A7,$C0,$7F,__,$8D,$A0,$7C,$8C,$90,$6B,$79,$6B,_eol
		.BYTE $75,$73,$F5,$7D,$6F,$F5,$6A,$92,$96,$79,$F5,$EA,_eol
		.BYTE $A7,$A9,$CD,$7E,$B6,$CD,$C1,$79,$F5,$6F,$F5,__,$77,$6B,$73,$6C,$76,$93,$83,$F5,_eol
		.BYTE $A7,$C0,$83,__,$83,$93,$7C,$AC,$F5,$C5,$A3,$7F,$7E,$93,$92,$EA,_eol,_eol
_script85_msg02:
		.BYTE $BD,$F5,$B4,$B5,$C1,$82,__,$AC,$F5,$D4,$CD,$A8,$F5,$C9,$7C,$F5,_eol
		.BYTE $AC,$D6,$A3,$AF,$A8,$BC,$C2,$A2,$7D,$7E,$A0,$79,_eol
		.BYTE $95,$93,$95,$93,$82,__,$7E,$6F,$88,$6F,$F5,$ED,_eol
		.BYTE $7D,$F5,$6C,$8C,__,$B3,$A7,$82,$BE,$C8,$D6,$7D,$7E,$A0,$7C,$6B,$92,_eol
		.BYTE $A6,$B9,$A3,$AE,$A2,$6F,$F5,$6A,$92,$EA,_eol,_eol
_script85_msg03:
		.BYTE $A9,$F5,$CD,$B1,$86,__,$AE,$CD,$B6,$D5,$A3,$75,$ED,_eol
		.BYTE $B1,$D6,$A3,$AB,$76,$92,$82,$6F,$F5,__,$75,$73,$F5,$7D,$79,$F5,$EA,_eol
		.BYTE $7D,$F5,$6C,$6F,$81,$EA,$73,$82,$C0,$D7,$AC,$D6,$CD,$97,_eol
		.BYTE $84,$70,$6C,$72,$92,__,$75,$F5,$75,$96,$83,$6A,$92,$6F,$E8,_eol,_eol
_script85_msg04:
		.BYTE $7D,$F5,$6C,$77,$6B,$7A,$7D,$F5,$83,$AC,$F5,$AA,$F5,$A8,$97,$89,$79,$A5,$CA,$79,$F5,$EA,_eol
		.BYTE $75,$80,$73,$7D,$7E,$7D,$F5,__,$73,$95,$71,$83,$7E,$6B,$EA,_eol
		.BYTE __,_eol
		.BYTE $A9,$A2,$C1,$AC,$D6,$71,$F5,$90,$75,$82,$87,$6C,$6F,$F5,_eol
		.BYTE $70,$6F,$F5,$90,$71,$79,$F5,$EA,$73,$73,$83,$A7,$A8,$F5,$CB,$A3,$6F,$F5,$7E,$6B,$EA,_eol,_eol
_script85_msg05:
		.BYTE $72,$A0,$73,$6C,$EA,$74,$A0,$78,$71,$B3,$BA,$A2,$75,$8F,$6C,$EA,_eol
		.BYTE $A7,$C0,$97,__,$73,$73,$6F,$90,$79,$F5,$75,$79,$6B,$82,$79,$F5,$EA,_eol,_eol
_script85_msg06:
		.BYTE $A7,$C0,$6F,$F5,$78,$6C,$6B,$6C,$7D,$83,__,$6E,$8C,$95,$7E,$6F,$A0,$79,$EA,_eol
		.BYTE $A7,$C0,$6F,$F5,_Y,_E,_S,$7D,$6B,$A0,$7C,$71,$93,$7E,$6B,$7D,_eol
		.BYTE $A9,$F5,$E7,$C1,$6F,$F5,__,$83,$75,$F5,$88,$90,$96,$82,$79,$F5,$8F,$EA,_eol,_eol
_script86_msg00:
		.BYTE $C7,$CD,$BE,$F5,$E7,$ED,$8F,$71,$70,$7C,$71,$93,$79,$EA,_eol
		.BYTE $AB,$A8,$AE,$CD,$AC,$A7,$A6,$CD,$82,$BF,$E7,$B4,$F5,$D7,$A8,$79,$F5,$EA,_eol,_eol
_script86_msg01:
		.BYTE $A9,$F5,$CD,$B1,$86,__,$AE,$CD,$B6,$D5,$A3,$75,$ED,$8C,$75,$8C,__,_eol
		.BYTE $BE,$C8,$D6,$6F,$F5,__,$AC,$D5,$A3,$C6,$A3,$74,$93,$7C,$6B,$79,$7E,$90,$83,$F5,$ED,_eol
		.BYTE $78,$82,$AC,$D6,$A3,$AA,$AC,$D4,$AC,$CD,$97,__,$8C,$7A,$6F,$6D,$92,$82,$6F,$F5,_eol
		.BYTE $75,$73,$F5,$7D,$79,$F5,$EA,_eol
		.BYTE $72,$A0,$75,$7C,$B3,$A7,$7D,__,$AA,$A3,$AE,$CD,$75,$7C,$83,$7E,$90,$96,$EA,_eol,_eol
_script86_msg02:
		.BYTE $AC,$D4,$AC,$CD,$97,$E8,__,$70,$9E,$6C,$75,$9E,$7B,$77,$76,$F5,$7F,$E8,_eol,_eol
_script86_msg03:
		.BYTE $71,$91,$6F,$6D,$76,$ED,$AA,$A3,$AE,$CD,$83,$8E,$92,$74,$96,$EA,_eol
		.BYTE $7C,$F5,$83,__,$BC,$F5,$A7,$AA,$7F,$6B,$A0,$7C,_eol
		.BYTE $89,$75,$F5,$79,$71,$97,$75,$7C,$71,$93,$EA,_eol
		.BYTE $AA,$A3,$A3,$CD,$97,__,$6B,$82,$A0,$7C,$6B,$92,$EA,_eol,_eol
_script87_msg00:
		.BYTE $BF,$E7,$B4,$F5,$D7,$A8,$75,$93,$6B,$6F,$96,$82,$A7,$D6,$A6,$97,_eol
		.BYTE $8C,$90,$A0,$7C,$6B,$7E,$6B,$7D,_eol
		.BYTE $BC,$F5,$A7,$97,__,$95,$79,$76,$95,$72,$7F,$83,$6B,$6F,$7E,$6B,$96,$79,$F5,$EA,_eol,_eol
_script87_msg01:
		.BYTE $A9,$F5,$C8,$C7,$77,$96,$7C,$F5,__,$8E,$6C,$73,$6C,$7E,_eol
		.BYTE $BC,$F5,$A7,$97,$8F,$6C,$6B,$75,$7C,$6E,$6B,$79,$EA,_eol
		.BYTE $73,$82,$B5,$A2,$BC,$83,$ED,$70,$89,$7F,$7D,$A0,$7C,_eol
		.BYTE $C7,$A2,$BC,$C9,$6B,$75,$F5,$9F,$6C,$7F,__,$91,$8F,$6C,$6F,$7A,$82,$6A,$92,_eol
		.BYTE $BC,$F5,$A7,$79,$F5,$94,$6C,$EA,_eol,_eol
_script87_msg02:
		.BYTE $75,$9E,$A0,$83,$F6,$7B,$88,$7C,$F5,__,$AC,$F5,$A6,$CD,$6F,$F5,$7E,$6B,$EA,_eol
		.BYTE $83,$8D,$71,__,$B4,$C7,$A3,$B4,$BF,$CD,$79,$6B,$74,$82,$7D,$73,$94,$86,_eol
		.BYTE $6B,$72,$E9,_eol,_eol
_script88_msg00:
		.BYTE $C7,$CD,$BE,$F5,$E7,$EA,$8F,$71,$70,$7C,$71,$93,$79,$EA,_eol
		.BYTE $8A,$7A,$9D,$7E,__,$7F,$71,$79,$F5,$96,$77,$96,$83,$95,$76,$93,$7C,_eol
		.BYTE $7D,$F5,$6C,$71,$F5,$97,__,$6F,$7B,$8F,$6C,$75,$94,$EA,_eol
		.BYTE $77,$96,$78,$6C,$83,__,$95,$76,$93,$94,$EA,_eol
		.BYTE $6A,$82,$73,$94,$82,$BD,$F5,$B4,$B5,$C1,$83,__,$75,$96,$79,$F5,$EA,_eol,_eol
_script88_msg01:
		.BYTE $6E,$93,$8C,$BD,$F5,$B4,$B5,$C1,$8C,__,$6B,$70,$7C,$6B,$88,$76,$EA,_eol,_eol
_script88_msg02:
		.BYTE $A6,$A8,$B9,$A3,$AA,$86,__,$6B,$A0,$7C,$71,$93,$EA,_eol
		.BYTE $BF,$E7,$B4,$F5,$D7,$A8,$75,$93,$6B,$6F,$96,$6F,$F5,__,$88,$A0,$7C,$6B,$92,$EA,_eol,_eol
_script88_msg03:
		.BYTE $A9,$F5,$CD,$B1,$7F,$83,_eol
		.BYTE $95,$93,$95,$93,$82,$CA,$CD,$C7,$A8,$A2,$CD,$6F,$F5,$6B,$92,$EA,_eol
		.BYTE $A9,$F5,$CD,$B1,$AC,$F5,$CD,$82,$AA,$E7,$79,$F5,$EA,_eol
		.BYTE $88,$76,$F5,$ED,$A6,$CA,$6F,$F5,$AC,$F5,$D4,$CD,$A8,$F5,$C9,$97,_eol
		.BYTE $6A,$96,$7E,$6B,$75,$7C,$71,$93,$92,$79,$F5,$94,$6C,$EA,_eol,_eol
_script88_msg04:
		.BYTE $77,$96,$7F,$9E,$6C,$6F,$90,__,$79,$F5,$A0,$75,$9E,$7B,$88,$7C,$F5,_eol
		.BYTE _3,_6,$AC,$F5,$A6,$CD,$79,$F5,$EA,$89,$7A,$71,$74,$97,__,$71,$6C,$7E,$8F,$EA,_eol
		.BYTE $B3,$A7,$7F,__,$83,$A0,$72,$96,$74,$93,$79,$90,_eol
		.BYTE $74,$96,$7A,$9F,$6C,$82,__,$BB,$F6,$D7,$A8,$A1,$D7,$BC,$F6,$7A,$7C,$96,$86,_eol
		.BYTE $BD,$C8,$AA,$BC,$F6,$B0,$E7,$6F,$F5,__,$8A,$6F,$6D,$7F,$6B,$71,$EA,_eol,_eol
_script88_msg05:
		.BYTE $C7,$CD,$BE,$F5,$E7,$EE,$EE,$EE,$EE,_eol
		.BYTE $73,$6C,$6C,$96,$97,__,$6B,$82,$A0,$7C,$6B,$92,$EA,_eol,_eol
_script89_msg00:
		.BYTE $88,$A0,$7C,$6B,$79,$82,$8F,$ED,$C7,$CD,$BE,$F5,$E7,$EA,_eol
		.BYTE $95,$79,$75,$83,__,$CA,$CD,$C7,$A8,$A2,$CD,$82,$AA,$E7,$EA,_eol
		.BYTE $6E,$96,$7E,$7C,$F5,__,$84,$F5,$A0,$71,$91,$75,$79,$E8,_eol
		.BYTE $7E,$7F,$6F,__,$70,$6B,$7C,$6E,$71,$73,$7D,$83,$7E,$6B,$E8,_eol,_eol
_script89_msg01:
		.BYTE $AC,$D5,$A3,$C6,$A3,$AC,$F5,$D6,__,$82,$73,$7D,$97,_eol
		.BYTE $7E,$7F,$6F,__,$75,$90,$7E,$6B,$6F,$E8,_eol
		.BYTE __,_eol
		.BYTE $A5,$CA,$82,$73,$7D,__,$7D,$F5,$6C,$6E,$8C,$6C,$E8,_eol,_eol
_script89_msg02:
		.BYTE $EE,$EE,$EE,$6D,$A0,$E8,_eol
		.BYTE $79,$71,$88,$75,$71,$7C,$ED,$AD,$EE,$B3,$EE,$A7,$EA,_eol,_eol
_script89_msg03:
		.BYTE $AC,$D5,$A3,$C6,$A3,$AC,$F5,$D6,$83,__,$A6,$CC,$82,$84,$6F,$F5,$75,$82,_eol
		.BYTE $AC,$F5,$D4,$CD,$A8,$F5,$C9,$7F,__,$6A,$92,$95,$EA,_eol
		.BYTE $C0,$B2,$C5,$A7,$F5,$D6,$A3,$AC,$D4,$7D,_eol
		.BYTE $83,$7E,$75,$97,$7B,$72,$7C,$6A,$92,$6F,$90,$ED,$83,$8D,$71,_eol
		.BYTE $85,$7E,$7B,$70,$83,$F5,$86,__,$6B,$70,$88,$75,$9F,$6C,$EA,_eol,_eol
_script8A_msg00:
		.BYTE $7E,$96,$79,$F5,$ED,$A1,$CD,$B0,$EA,$89,$6F,$72,$7E,$6B,$C4,$B2,$79,$F5,$7E,$EA,_eol
		.BYTE $6A,$6B,$7F,$71,__,$A5,$CA,$79,$7A,$83,_eol
		.BYTE $AE,$F5,$CD,$C8,$D6,$A3,$7E,__,$A1,$A7,$CD,$B4,$F5,$7C,$F5,$81,$EA,_eol
		.BYTE $BD,$CD,$7E,$C4,$B2,$97,__,$BC,$B8,$7F,$82,$77,$92,$95,$72,$7F,$83,_eol
		.BYTE $6B,$6F,$7E,$6B,$96,$79,$F5,$8F,$EA,_eol,_eol
_script8A_msg01:
		.BYTE $BA,$B5,$AC,$83,__,$7B,$72,$7C,$6A,$92,$83,$76,$F5,$8F,$EA,_eol
		.BYTE $BC,$B8,$7F,$82,$91,$79,$6B,$82,$EA,_eol
		.BYTE $83,$6B,$ED,$6E,$A6,$B8,$97,$95,$79,$76,$95,$EA,_eol,_eol
_script8A_msg02:
		.BYTE $6A,$6A,$ED,$BC,$B8,$7F,$82,$91,$79,$6B,$A0,$7C,$82,$83,_eol
		.BYTE $A1,$CD,$B0,$79,$7A,$6F,$EA,_eol
		.BYTE $AC,$F5,$AA,$F5,$A8,$82,$AB,$B0,$8C,__,$A6,$B8,$75,$79,$F5,$6B,$A0,$7C,$7E,$EA,_eol,_eol
_script8A_msg03:
		.BYTE $A6,$B8,$74,$6D,$8C,$90,$6D,$83,$F5,$ED,$BC,$B8,$79,$F5,$94,$6C,$7D,_eol
		.BYTE $7E,$96,$79,$F5,$94,$6C,$7D,__,$82,$77,$7C,$8D,$92,$77,$F5,$EA,_eol
		.BYTE $EE,$EE,$EE,$EE,$83,$8D,$71,$82,$91,$7E,$EA,_eol,_eol
_script8B_msg00:
		.BYTE $C7,$CD,$BE,$F5,$E7,$E9,_eol
		.BYTE $7E,$96,$79,$F5,$6F,__,$8F,$6C,$76,$6F,$F5,$86,$96,$8F,$EA,_eol,_eol
_script8B_msg01:
		.BYTE $B3,$A7,$82,$BC,$B8,$79,$F5,$EA,_eol
		.BYTE $6E,$93,$79,$7A,$97,__,$6C,$90,$70,$F5,$A0,$79,$7E,$EA,_eol,_eol
_script8B_msg02:
		.BYTE $78,$6C,$79,$F5,$EA,_eol
		.BYTE $A6,$B8,$7F,$7E,$93,$83,$F5,__,$7E,$96,$7C,$F5,$8C,$76,$92,$82,$74,$EA,_eol
		.BYTE $6E,$7D,$7E,$75,$71,__,$75,$7C,$8C,$90,$6E,$6C,$6F,$EA,_eol,_eol
_script8B_msg03:
		.BYTE $C7,$CD,$BE,$F5,$E7,$EA,_eol
		.BYTE $7E,$77,$F5,$73,$96,$7E,__,$A7,$A9,$CD,$7E,$B6,$CD,$C1,$97,_eol
		.BYTE $84,$70,$6C,$72,$79,$82,$E8,_eol
		.BYTE $A1,$C2,$C8,$A6,$83,$ED,$6A,$7E,$79,$7E,$90,_eol
		.BYTE $AE,$A2,$AA,$A3,$76,$92,$A0,$7C,$ED,$75,$96,$75,$F5,$7C,$92,$82,$81,$EA,_eol,_eol
_script8B_msg04:
		.BYTE $A5,$CA,$97,__,$AC,$F5,$D4,$CD,$A8,$F5,$C9,$7F,$87,$6C,$91,$73,$8A,$73,$7D,$7C,$F5,_eol
		.BYTE $AA,$A8,$C0,$CD,$7F,$79,$6B,$76,$92,__,$AE,$A7,$B6,$CD,$97,_eol
		.BYTE $83,$79,$75,$79,$73,$7D,$7F,__,$75,$79,$6B,$79,$F5,$72,$74,$EA,_eol
		.BYTE $70,$89,$83,$7E,$77,$F5,__,$CA,$CD,$C7,$A8,$A2,$CD,_eol
		.BYTE $7E,$7D,$F5,$75,$7C,$6B,$92,$96,$79,$F5,$EA,_eol,_eol
_script8B_msg05:
		.BYTE $7A,$7A,$6F,$F5,__,$73,$82,$AC,$AA,$F5,$B4,$97,$75,$7C,$6B,$79,$82,$EA,_eol
		.BYTE $7A,$7A,$6F,$F5,$73,$94,$74,$93,__,$95,$79,$75,$6F,$F5,$6A,$7D,$97,_eol
		.BYTE $84,$70,$7B,$6B,$79,$F5,$82,$8F,$EA,$7C,$F5,$8C,$EE,$EE,$EE,_eol
		.BYTE $6A,$79,$75,$83,__,$73,$96,$7E,$AC,$F5,$AA,$F5,$A8,$83,$8C,$6C,$A2,$C4,$E9,_eol
		.BYTE $A1,$C2,$C8,$A6,$7C,$F5,__,$75,$76,$F5,$6F,$7F,$71,$90,$75,$79,$6B,$95,$EA,_eol,_eol
_script8B_msg06:
		.BYTE $73,$82,$BD,$F6,$CD,$B0,$F5,$CD,$B4,$83,$E8,_eol,_eol
_script8B_msg07:
		.BYTE $6E,$88,$8C,$91,$8F,$EA,_eol
		.BYTE $6A,$7E,$79,$82,__,$6E,$88,$8C,$91,$83,$E8,_eol,_eol
_script8B_msg08:
		.BYTE $73,$82,__,$B5,$A2,$BC,$6F,$7E,$EA,_eol,_eol
_script8B_msg09:
		.BYTE $C7,$CD,$BE,$F5,$E7,$ED,$73,$82,$BD,$F6,$CD,$B0,$F5,$CD,$B4,$97,$6A,$72,$F5,$92,$95,$EA,_eol
		.BYTE $79,$6B,$77,$7B,$7F,$75,$7C,$81,$EA,_eol,_eol
_script8B_msg0a:
		.BYTE $8D,$A0,$7D,__,$7B,$6B,$79,$89,$79,$6B,$EA,_eol
		.BYTE $73,$73,$6F,$90,__,$AC,$D5,$A3,$C6,$A3,$AC,$F5,$D6,$88,$7C,$F5,$83,_eol
		.BYTE $6A,$92,$6F,$7E,$6B,$7D,$6B,$72,$7E,$6B,$95,$EA,_eol,_eol
_script8C_msg00:
		.BYTE $8A,$90,$86,__,$8F,$6C,$76,$97,$74,$71,$F5,$91,$7F,_eol
		.BYTE $6B,$70,$88,$75,$9F,$6C,$EA,_eol
		.BYTE $BB,$A6,$F5,$AC,$86,__,$6B,$72,$83,$F5,$6B,$70,$7B,$71,$95,$EA,_eol,_eol
_script8C_msg01:
		.BYTE $AC,$D5,$A3,$C6,$A3,$AC,$F5,$D6,$83,__,$73,$73,$6F,$90,_eol
		.BYTE $C0,$B5,$C0,$86,__,$6B,$A0,$79,$7D,$73,$94,$8F,$EA,_eol,_eol
_script8C_msg02:
		.BYTE $B6,$AC,$82,$6F,$95,$97,__,$95,$79,$A0,$7C,_eol
		.BYTE $8D,$88,$97,__,$82,$87,$F5,$A0,$79,$7D,$73,$94,$6F,$F5,_eol
		.BYTE $BD,$C8,$AA,$BC,$F6,$B0,$E7,$82,$BB,$F6,$D7,$A8,$A1,$D7,$BC,$F6,$BE,$F6,$A2,$CD,$B4,$8F,$EA,_eol,_eol
_script8C_msg03:
		.BYTE $7C,$F5,$8C,$ED,$8D,$71,$78,$71,$82,$75,$F5,$6F,$96,$83,__,$8C,$6C,_eol
		.BYTE $7D,$A0,$71,$7F,__,$76,$70,$F5,$7C,$75,$88,$A0,$79,$95,$EA,_eol
		.BYTE $BD,$C8,$AA,$BC,$F6,$B0,$E7,$83,__,$8A,$6F,$6D,$7F,$73,$7E,$6B,$95,$EA,_eol
		.BYTE $8A,$90,$86,__,$6B,$A0,$7C,$6F,$71,$93,$88,$75,$9F,$6C,$EA,_eol,_eol
_script8D_msg00:
		.BYTE $A4,$E7,$CD,__,$A4,$E7,$CD,_eol
		.BYTE $BB,$D7,$A8,__,$BB,$D7,$A8,_eol,_eol
_script8D_msg01:
		.BYTE $6A,$96,$75,$96,$75,$94,$EA,$79,$76,$72,$7C,$8D,$92,$78,$F5,$EA,_eol,_eol
		.BYTE _eol		; *--
_script8F_msg00:
		.BYTE $8F,$6F,$A0,$79,$95,__,$85,$F5,$75,$F5,$7C,$F5,$EA,_eol
		.BYTE $7C,$70,$6F,$F5,__,$70,$7B,$F5,$6B,$79,$89,$79,$6B,$8F,$EA,_eol,_eol
_script8F_msg01:
		.BYTE $6D,$E9,_eol
		.BYTE $BE,$C8,$D6,$97,__,$7B,$93,$7C,$70,$79,$82,$EA,_eol
		.BYTE $AC,$D4,$AC,$CD,$97,__,$7D,$92,$79,$F5,$72,$82,$83,$76,$F5,$7C,$F5,$83,_eol
		.BYTE $7E,$6F,$A0,$79,$82,$EA,_eol,_eol
_script8F_msg02:
		.BYTE $6B,$78,$6B,$7C,$F5,$8C,$7D,$F5,$94,$6C,$EA,$73,$73,$7C,$F5,__,$8D,$90,$93,$79,$90,_eol
		.BYTE $8C,$7D,$8C,$73,$8C,$7E,$6B,$EA,_eol,_eol
_script90_msg00:
		.BYTE $73,$73,$6F,$90,$74,$70,$83,__,$A5,$CA,$84,$7D,$91,$7C,$F5,$6B,$71,$EA,_eol
		.BYTE $A7,$A9,$CD,$79,$F5,$6F,$90,__,$7B,$6B,$7C,$71,$92,$7E,$EA,_eol,_eol
_script90_msg01:
		.BYTE $78,$6C,$EE,$EE,$EE,$EA,$75,$6F,$79,$7E,$6B,$95,$81,$EA,_eol
		.BYTE $A5,$B4,$7F,$70,$97,$7B,$72,$7C,$EA,_eol
		.BYTE $A5,$B4,$82,$7C,$F5,$92,$BC,$F5,$A7,$83,__,$B3,$A7,$97,_eol
		.BYTE $6A,$7B,$8B,$7C,$75,$88,$6C,$6F,$90,$EA,_eol,_eol
_script91_msg00:
		.BYTE $73,$96,$83,$F5,$96,$83,$EA,_eol
		.BYTE $95,$79,$75,$97,$8F,$84,$F5,$79,$F5,$75,$79,$82,$83,__,$6A,$7E,$79,$E8,_eol,_eol
_script91_msg01:
		.BYTE $73,$73,$83,__,$8A,$90,$82,$8D,$7B,$90,$6F,$F5,$71,$92,$7D,$73,$94,$75,$F5,$9D,_eol
		.BYTE $7E,$6B,$96,$79,$F5,$EA,_eol
		.BYTE $A9,$A6,$F5,$75,$7E,$6B,$6C,$7A,$7F,__,$6F,$6D,$91,$7E,$EA,_eol,_eol
_script91_msg02:
		.BYTE $6B,$8D,$ED,$6E,$93,$75,$F5,$9D,$81,$6D,$8F,$EA,_eol
		.BYTE $79,$85,$F5,$96,__,$B0,$A2,$B1,$D6,$A3,$79,$F5,$94,$6C,$EA,_eol
		.BYTE $B0,$A2,$B1,$D6,$A3,$82,$A5,$CD,$B5,$76,$F5,$70,$7F,$8C,_eol
		.BYTE $73,$88,$A0,$79,$8C,$82,$79,$F5,$EA,_eol
		.BYTE $8C,$79,$8C,$79,$75,$81,$6D,$7C,$F5,__,$74,$A0,$74,$7D,$83,$6B,$91,$7E,$EA,_eol,_eol
_script92_msg00:
		.BYTE $73,$96,$83,$F5,$96,$83,$EA,_eol,_eol
_script92_msg01:
		.BYTE $6E,$A0,$ED,$7E,$6F,$7E,$6F,$6B,$6B,$A5,$CD,$B5,$75,$F5,$9D,$7E,$6B,$6F,$EA,_eol
		.BYTE $73,$A0,$7A,$73,$6B,$8F,$EA,$BD,$BD,$BD,$EA,_eol,_eol
_script92_msg02:
		.BYTE $6B,$8D,$E7,$81,$ED,$A4,$D7,$B1,$E9,_eol
		.BYTE $BA,$F5,$AC,$E9,_eol
		.BYTE __,_eol
		.BYTE $85,$85,$85,$EA,$AA,$C4,$82,$7E,$6F,$7F,$83,$6B,$A0,$7C,$ED,_eol
		.BYTE $A2,$A2,$AA,$B4,__,$75,$88,$75,$9F,$6C,$8F,$96,$EA,_eol,_eol
_script92_msg03:
		.BYTE $7E,$7F,$76,$96,$79,$F5,$8F,$ED,$73,$6B,$7B,$E9,_eol
		.BYTE $7D,$A0,$7D,$7D,__,$6F,$6D,$93,$E9,_eol,_eol
_script92_msg04:
		.BYTE $70,$9F,$6C,$7E,$7F,$6F,__,$6A,$A0,$79,$89,$79,$6B,$81,$EA,_eol,_eol
_script92_msg05:
		.BYTE $6A,$6A,$EA,$AD,$BA,$F6,$A2,$97,$7B,$6F,$88,$6D,$79,$96,$79,$F5,$EA,_eol
		.BYTE $74,$A0,$70,$88,$7C,$F5,__,$73,$F5,$6C,$8C,$96,$75,$7C,$79,$96,$79,$F5,$6F,$F5,_eol
		.BYTE $82,$84,$F5,$7A,$88,$A0,$79,$96,$79,$F5,$EA,_eol,_eol
_script92_msg06:
		.BYTE $AA,$F5,$A3,$C3,$CD,$AA,$F5,$C4,$82,$A6,$A7,$F5,$83,_eol
		.BYTE $6A,$7E,$79,$6F,$F5,__,$8C,$A0,$7C,$6B,$92,$7D,$6B,$6C,$95,$72,$81,$E9,_eol,_eol
_script92_msg07:
		.BYTE $78,$96,$7E,$73,$7D,$8F,$91,__,$BD,$BD,$BD,$EA,_eol
		.BYTE $AA,$F5,$A7,$E9,__,$BA,$F5,$B0,$CD,$E9,_eol
		.BYTE $EE,$EE,$EE,_eol,_eol
_script92_msg08:
		.BYTE $8D,$A0,$7D,__,$A6,$A7,$F5,$97,$7C,$7F,$6B,$93,$79,$95,$EA,_eol
		.BYTE $73,$93,$7C,$F5,__,$C7,$CD,$BE,$F5,$E7,$97,$79,$76,$72,$79,$F5,$77,$92,$95,$EA,_eol,_eol
_script93_msg00:
		.BYTE $6E,$6B,$ED,$73,$96,$7E,$7D,$73,$94,$7C,$F5,$7E,$7F,$97,$75,$7C,$6B,$92,$EA,_eol
		.BYTE $7E,$7F,$8C,$82,$79,$F5,__,$6E,$88,$6D,$E9,_eol
		.BYTE $74,$A0,$74,$7D,$6F,$6D,$90,$7E,$6B,$7D,_eol
		.BYTE $94,$6C,$8D,$7F,__,$7D,$75,$F5,$73,$8B,$92,$78,$F5,$EA,_eol,_eol
_script93_msg01:
		.BYTE $EE,$EE,$EE,$73,$F5,$8B,$96,$7E,$74,$6B,$EA,_eol,_eol
_script93_msg02:
		.BYTE $6E,$6B,$ED,$7D,$F5,$73,$7F,$6B,$71,$96,$79,$F5,$EA,_eol
		.BYTE $7C,$F5,$71,$F5,$7A,$83,__,$C0,$A7,$F5,$79,$F5,$EA,_eol
		.BYTE $BB,$B0,$F5,$C8,$83,$ED,$AA,$F5,$A3,$C3,$CD,$AA,$F5,$C4,$6F,$F5,$6A,$92,$96,$79,$F5,$78,$F5,$EA,_eol
		.BYTE $78,$93,$7D,$8C,$ED,$AA,$F5,$A3,$C3,$CD,$75,$7C,$87,$75,$6B,$82,$6F,$E8,_eol,_eol
_script94_msg00:
		.BYTE $C7,$CD,$BE,$F5,$E7,$ED,$79,$F5,$6B,$75,$F5,$9F,$6C,$85,$F5,$EA,_eol
		.BYTE $76,$71,$F5,$7F,$A6,$A7,$F5,$97,__,$6A,$72,$92,$6F,$90,$EA,_eol,_eol
_script94_msg01:
		.BYTE $6A,$91,$6F,$F5,$7D,$6C,$EA,$85,$F5,$70,$97,$71,$93,$E9,_eol,_eol
_script94_msg02:
		.BYTE $7C,$70,$6F,$F5,__,$70,$7B,$F5,$6B,$79,$89,$79,$6B,$EA,_eol
		.BYTE $6B,$78,$6B,$7C,$F5,__,$7F,$72,$F5,$88,$75,$9F,$6C,$EA,_eol,_eol
_script94_msg03:
		.BYTE $C7,$CD,$BE,$F5,$E7,$ED,$95,$79,$75,$8F,$EA,_eol
		.BYTE $A6,$A7,$F5,$97,__,$74,$6F,$F5,$75,$7C,$71,$92,$6F,$90,_eol
		.BYTE $76,$73,$75,$88,$A0,$7C,$6B,$7C,$EA,_eol,_eol
_script94_msg04:
		.BYTE $EE,$EE,$EE,$EE,$EA,_eol,_eol
_script95_msg00:
		.BYTE $C7,$CD,$BE,$F5,$E7,$EA,_eol
		.BYTE $73,$82,$74,$70,$6F,$F5,__,$BD,$C8,$AA,$BC,$F6,$B0,$E7,$82,_eol
		.BYTE $BB,$F6,$D7,$A8,$A1,$D7,$BC,$F6,$BE,$F6,$A2,$CD,$B4,$8F,$EA,_eol,_eol
_script95_msg01:
		.BYTE $7C,$F5,$8C,$ED,$8C,$6C,$8D,$71,$78,$71,$82,$75,$F5,$6F,$96,$83,_eol
		.BYTE $7D,$A0,$71,$7F,$76,$70,$F5,$7C,__,$75,$88,$A0,$79,$6F,$90,_eol
		.BYTE $BD,$C8,$AA,$BC,$F6,$B0,$E7,$83,__,$73,$7E,$6B,$95,$EA,_eol,_eol
_script95_msg02:
		.BYTE $75,$9F,$6C,$6F,$F5,$7E,$6B,$EA,_eol
		.BYTE $AC,$F5,$D4,$CD,$A8,$F5,$C9,$7F,__,$8C,$7D,$F5,$94,$6C,$EA,_eol,_eol
_script95_msg03:
		.BYTE $73,$82,$88,$88,$6F,$6D,$A0,$7C,$75,$88,$6C,$82,$E8,_eol
		.BYTE $7E,$7F,$8C,__,$7C,$F5,$70,$7E,$6F,$A0,$79,$95,$81,$EA,_eol,_eol
_script95_msg04:
		.BYTE $78,$6C,$79,$F5,$7E,$EA,$88,$79,$F5,$75,$F5,$6F,$96,$6F,$F5,$6A,$92,$75,_eol
		.BYTE $AC,$D5,$A3,$C6,$A3,$AC,$F5,$D6,$7F,__,$6B,$A0,$7C,$89,$8F,$6C,$EA,_eol,_eol
_script95_msg05:
		.BYTE $AC,$D5,$A3,$C6,$A3,$AC,$F5,$D6,$83,__,$73,$73,$6F,$90,_eol
		.BYTE $76,$F5,$A0,$7D,__,$C0,$B5,$C0,$8F,$EA,_eol,_eol
_script95_msg06:
		.BYTE $AA,$E7,$EA,$6B,$94,$6B,$94,$77,$95,$7F,$7E,$A0,$79,$EA,_eol
		.BYTE $A7,$C0,$6F,$F5,__,$6B,$7E,$6F,$A0,$79,$90,$ED,_eol
		.BYTE $B6,$CD,$C1,$83,__,$77,$6B,$73,$6C,$75,$7E,$6F,$A0,$79,$79,$F5,$94,$6C,$EA,_eol,_eol
_script95_msg07:
		.BYTE $C7,$CD,$BE,$F5,$E7,$EA,_eol
		.BYTE $95,$79,$75,$97,__,$7B,$93,$7C,$6F,$6D,$A0,$7C,$71,$93,$7E,$6B,$E8,_eol
		.BYTE $95,$79,$75,$8C,__,$A1,$C2,$C8,$A6,$7F,$6B,$70,$79,$6B,$95,$EA,_eol,_eol
_script95_msg08:
		.BYTE $A7,$C0,$97,__,$A1,$C2,$C8,$A6,$7F,$7B,$93,$7C,$6F,$6D,$92,$95,$72,$7F,$83,_eol
		.BYTE $6B,$6F,$7E,$6B,$EA,_eol,_eol
_script95_msg09:
		.BYTE $A7,$C0,$97,__,$A1,$C2,$C8,$A6,$7F,$7B,$93,$7C,$6F,$6D,$92,$95,$72,$7F,$83,_eol
		.BYTE $6B,$6F,$7E,$6B,$EA,_eol
		.BYTE __,_eol
		.BYTE $A7,$C0,$8C,__,$73,$73,$7F,$6B,$7C,$83,$6A,$85,$F5,$7E,$6B,$EA,_eol
		.BYTE $6B,$A0,$75,$9F,$7F,__,$6F,$6D,$94,$6C,$EA,_eol,_eol
_script95_msg0a:
		.BYTE $6A,$91,$6F,$F5,$7D,$6C,$EE,$EE,$EE,$7D,$7C,$8C,$6C,$93,$75,$6B,$82,$EE,$EE,$EE,_eol
		.BYTE $83,$8D,$71,__,$6B,$70,$88,$75,$9F,$6C,$EA,_eol
		.BYTE $6E,$A0,$7C,$6F,$F5,__,$76,$71,$F5,$78,$73,$88,$7C,$F5,$70,$7C,$6B,$92,$95,$EA,_eol,_eol
_script95_msg0b:
		.BYTE $74,$F5,$96,$81,$96,$79,$F5,$95,$EA,_eol
		.BYTE $8C,$6C,$73,$93,$7C,$F5,__,$6A,$6D,$7E,$6B,$82,$81,$EA,_eol
		.BYTE $74,$8F,$6C,$7E,$90,$EA,$70,$97,$7B,$72,$7C,$EA,_eol,_eol
_script96_msg00:
		.BYTE $87,$96,$85,$F5,$ED,$C7,$CD,$BE,$F5,$E7,$97,$89,$7B,$72,$79,$EA,_eol
		.BYTE $BE,$C8,$D6,$97,$7B,$93,$7C,$6B,$92,$EA,_eol
		.BYTE $73,$93,$6F,$90,__,$70,$9E,$6C,$75,$9E,$7B,$7F,$8A,$6F,$6C,$EA,_eol
		.BYTE $7C,$70,$7F,__,$6E,$95,$93,$7C,$6B,$92,$EA,_eol,_eol
_script96_msg01:
		.BYTE $EF,$BE,$CD,$BC,$F5,$6F,$90,$82,$C1,$AE,$CD,$F0,_eol
		.BYTE $EE,$EE,__,$70,$96,$70,$9E,$6C,__,$75,$F5,$79,$6B,__,$EE,$EE,_eol
		.BYTE $EE,$EE,__,$74,$71,$77,$96,$97,__,$7A,$9E,$6C,$75,$77,$8F,__,$EE,$EE,_eol,_eol
_script96_msg02:
		.BYTE $7E,$96,$79,$F5,$7D,__,$73,$82,$88,$88,__,$6F,$6D,$93,$92,$6F,$EA,_eol
		.BYTE $7B,$93,$7C,$6F,$6D,$92,$78,$F5,$EA,_eol
		.BYTE $89,$73,$F5,$94,$75,$7F,__,$76,$92,$7B,$8C,$91,$6F,$EA,_eol,_eol
_script96_msg03:
		.BYTE $95,$79,$75,$83,__,$8B,$6B,$93,$6B,$7F,$75,$79,$6F,$F5,$6B,$88,$76,$EA,_eol,_eol
_script96_msg04:
		.BYTE $8D,$7D,$95,$93,$BD,$A2,$8B,$6F,$F5,$EA,_eol
		.BYTE $89,$6F,$79,$97,__,$89,$76,$7C,$92,$82,$6F,$E9,_eol,_eol
_script96_msg05:
		.BYTE $87,$96,$85,$F5,$ED,$C7,$CD,$BE,$F5,$E7,$97,$89,$7B,$72,$79,$EA,_eol
		.BYTE $73,$93,$6F,$90,__,$70,$9E,$6C,$75,$9E,$7B,$7F,$8A,$6F,$6C,$EA,_eol
		.BYTE $7C,$70,$7F,__,$6E,$95,$93,$7C,$6B,$92,$EA,_eol,_eol
_script96_msg06:
		.BYTE $EF,$BE,$CD,$BC,$F5,$6F,$90,$82,$C1,$AE,$CD,$F0,_eol
		.BYTE $EE,$EE,__,$6B,$78,$6B,$7C,$F5,__,$70,$9E,$6C,$75,$7B,$75,$94,$E9,__,$EE,$EE,_eol,_eol
_script96_msg07:
		.BYTE $C7,$CD,$BE,$F5,$E7,$EA,$83,$8D,$71,$82,$93,$EA,_eol
		.BYTE $8F,$75,$A0,$ED,$73,$93,$7C,$F5,$73,$96,$7E,$85,$F5,$A0,$78,$6C,$7E,_eol
		.BYTE $AC,$F5,$D4,$CD,$A8,$F5,$C9,$7D,$8C,__,$6E,$74,$90,$83,$F5,$79,$F5,$EA,_eol
		.BYTE $AC,$F5,$D6,$A3,$AC,$D6,$A3,$75,$94,$E9,_eol,_eol
_script97_msg00:
		.BYTE $78,$82,$73,$94,__,$7C,$70,$7F,$7B,$6F,$88,$A0,$79,$C7,$CD,$BE,$F5,$E7,$83,_eol
		.BYTE $BD,$F5,$B4,$AA,$CD,$82,$73,$F5,$6C,$8C,$96,$97,$6C,$72,$7C,$6B,$79,$EA,_eol
		.BYTE $78,$73,$86,__,$BB,$A6,$F5,$AC,$6F,$F5,$95,$A9,$F5,$C8,$C7,$BC,$F5,$B0,$A2,$6F,$F5,_eol
		.BYTE $7D,$6C,$7A,$9D,$71,$75,$7C,$EA,_eol,_eol
_script97_msg01:
		.BYTE $95,$79,$75,$83,__,$BA,$F6,$B4,$F5,$BC,$AD,$A7,$E7,$7A,$9E,$6C,$74,$79,$F5,$EA,_eol
		.BYTE $70,$89,$6F,$F5,__,$79,$F5,$93,$6F,$83,$75,$90,$96,$6F,$F5,_eol
		.BYTE $75,$F5,$70,$95,$6F,$92,$79,$F5,$94,$6C,$EA,_eol,_eol
_script97_msg02:
		.BYTE $70,$89,$83,__,$73,$82,$71,$7F,$7F,$6B,$92,$BE,$C8,$D6,$97,_eol
		.BYTE $70,$9E,$6C,$75,$9E,$7B,$7F,$70,$79,$EA,_eol
		.BYTE $78,$82,$70,$8C,$7A,$83,__,$8F,$71,$95,$6F,$92,$EA,_eol
		.BYTE $75,$6F,$75,$ED,$7D,$90,$6D,$90,$93,$79,$73,$7D,$83,__,$BF,$AD,$F5,$6B,$EA,_eol
		.BYTE $86,$F5,$96,$8B,$6B,$97,__,$70,$73,$6C,$EA,_eol,_eol
_script97_msg03:
		.BYTE $EE,$EE,$EE,$EE,$EE,$EA,_eol,_eol
_script97_msg04:
		.BYTE $88,$76,$F5,$ED,$79,$6B,$87,$74,$93,$79,$73,$7D,$97,_eol
		.BYTE $A7,$B1,$7F,$93,$96,$90,$71,$76,$92,$82,$79,$F5,$EA,_eol
		.BYTE $AD,$BA,$F6,$A2,$6F,$7B,$7D,$F5,$6C,$82,__,$7B,$89,$7C,$F5,$73,$71,$83,$7B,_eol
		.BYTE $74,$93,$79,$7D,$EA,_eol,_eol
_script97_msg05:
		.BYTE $EE,$EE,$EE,$EE,$EE,$EA,_eol,_eol
_script97_msg06:
		.BYTE $88,$79,$F5,$72,$F5,$96,$70,$6F,$F5,$82,$73,$A0,$7C,$92,$8F,$6C,$79,$F5,$7E,$EA,_eol
		.BYTE $C5,$E7,$AC,$CD,$E9,_eol
		.BYTE $C5,$E7,$AC,$CD,$71,$F5,$96,$78,$6C,$7F,$7D,$A0,$7C,$83,_eol
		.BYTE $70,$89,$83,__,$79,$79,$F5,$82,$75,$F5,$A0,$72,$96,$7D,$F5,$6C,$85,$F5,$7B,$79,$F5,$EA,_eol,_eol
_script97_msg07:
		.BYTE $EB,$BA,$F5,$A7,__,$BE,$F5,$A8,__,$BA,$F5,$AC,$BA,$F5,$AC,$EC,_eol,_eol
_script97_msg08:
		.BYTE $EB,$A7,$F5,$D4,$E7,$E7,$E7,$E7,$E7,$E7,$E7,$EC,_eol,_eol
_script97_msg09:
		.BYTE $6E,$88,$6D,$82,$75,$70,$6F,$96,$83,__,$A7,$C0,$97,$89,$76,$7C,_eol
		.BYTE $79,$96,$79,$F5,$78,$F5,$EA,_eol
		.BYTE $A7,$C0,$83,__,$78,$96,$7E,$8D,$7B,$90,$97,$6F,$83,$F5,$6C,$82,$6F,$81,$E8,_eol
		.BYTE $93,$96,$90,$71,$75,$7E,$6B,$7D,__,$BE,$C8,$D6,$82,_eol
		.BYTE $6B,$82,$7A,$83,$7E,$6B,$78,$F5,$EA,_eol,_eol
_script97_msg0a:
		.BYTE $C1,$AE,$CD,$A7,$97,__,$7B,$6F,$A0,$7C,$ED,_eol
		.BYTE $A7,$B1,$7F,__,$93,$96,$90,$71,$75,$94,$EA,_eol,_eol
_script97_msg0b:
		.BYTE $EE,$EE,$EE,$EE,$EA,_eol
		.BYTE __,_eol
		.BYTE __,_eol
		.BYTE _2,_2,_0,$EE,$EE,$EE,_5,_6,$EE,$EE,$7D,$F5,$6C,$78,$F5,$EA,_eol,_eol
_script97_msg0c:
		.BYTE $EF,$BE,$CD,$BC,$F5,$6F,$90,$82,$C1,$AE,$CD,$F0,_eol
		.BYTE $EE,$EE,__,$A9,$F5,$CD,$AB,$F5,$A2,$B1,$7D,$ED,$75,$F5,$9F,$6C,$70,$9F,$6C,$97,_eol
		.BYTE __,__,__,$87,$6C,$73,$71,$77,$8F,$EA,__,$EE,$EE,_eol,_eol
_script97_msg0d:
		.BYTE $73,$79,$6D,$94,$EA,_eol
		.BYTE $73,$79,$6D,$7E,$6B,$7D,__,$7D,$8C,$79,$F5,$7A,$6F,$F5,$75,$80,$78,$F5,$EA,_eol,_eol
_script97_msg0e:
		.BYTE $EE,$EE,__,$AC,$F5,$D6,$CD,__,$95,$79,$75,$79,$F5,$EA,_eol
		.BYTE __,__,__,$86,$96,$75,$F5,$75,$94,$EA,__,$EE,$EE,_eol,_eol
_script97_msg0f:
		.BYTE $BF,$E7,$B4,$F5,$D7,$A8,$83,$E8,_eol,_eol
_script97_msg10:
		.BYTE $EE,$EE,__,$73,$73,$7F,$6B,$92,$EA,__,$EE,$EE,_eol
		.BYTE $EE,$EE,__,$7D,$F5,$73,$79,$F5,$EA,$83,$F5,$75,$9F,$97,_eol
		.BYTE __,__,__,$70,$9E,$6C,$75,$9E,$7B,$7F,$6B,$71,$EA,__,$EE,$EE,_eol,_eol
_script97_msg11:
		.BYTE $EE,$EE,$EE,$EE,$EA,_eol
		.BYTE $BF,$E7,$B4,$F5,$D7,$A8,$ED,$6B,$82,$7A,$97,$8C,$90,$6B,$7F,$6B,$71,$77,$F5,$E9,$E9,_eol,_eol
_script98_msg00:
		.BYTE $8A,$90,$7C,$F5,__,$8B,$96,$7D,$F5,$6C,$97,_eol
		.BYTE $6E,$73,$75,$7C,$8C,$90,$A0,$7C,$83,__,$73,$88,$92,$EA,_eol
		.BYTE $83,$8D,$71,__,$7C,$F5,$7C,$6B,$A0,$7C,$71,$93,$EA,_eol,_eol
_script98_msg01:
		.BYTE $6E,$8D,$ED,$A5,$CD,$B5,$7F,$75,$7C,$83,$6B,$6B,$C7,$A2,$BC,$C9,$97,_eol
		.BYTE $8C,$A0,$7C,$6B,$92,$7E,$EA,_eol
		.BYTE $78,$82,$C7,$A2,$BC,$C9,$7D,$ED,$73,$82,$B1,$D4,$A2,$B5,$B4,$F5,$CA,$AD,$7D,_eol
		.BYTE $73,$6C,$6F,$96,$75,$7C,$71,$93,$7E,$6B,$6F,$EA,_eol,_eol
_script98_msg02:
		.BYTE $74,$F5,$96,$81,$96,$79,$F5,$95,$ED,$73,$82,$C7,$A2,$BC,$C9,$83,_eol
		.BYTE $7C,$83,$F5,$7E,$77,$7E,$6B,$82,$8F,$EA,_eol
		.BYTE __,_eol
		.BYTE $6A,$90,$ED,$70,$93,$6B,$7E,$B1,$D4,$A2,$B5,$B4,$F5,$CA,$AD,_eol
		.BYTE $88,$6D,$6F,$90,$87,$75,$6F,$A0,$79,$82,$8F,$EA,_eol,_eol
_script98_msg03:
		.BYTE $78,$6C,$6F,$ED,$74,$F5,$96,$81,$96,$79,$F5,$EA,_eol
		.BYTE $70,$6F,$F5,__,$6F,$95,$A0,$79,$90,$88,$79,$70,$7C,$71,$93,$EA,_eol,_eol
_script98_msg04:
		.BYTE $B1,$D4,$A2,$B5,$B4,$F5,$CA,$AD,$6F,$F5,__,$8F,$71,$7F,$6A,$A0,$7C,$6B,$92,$8F,$EA,_eol,_eol
_script99_msg00:
		.BYTE $73,$7D,$F5,$8C,$6F,$F5,__,$70,$79,$82,$87,$6C,$82,$7D,$F5,$6C,$71,$7B,$7C,$F5,_eol
		.BYTE $8E,$71,$6D,$85,$8B,$6B,$7F,$7E,$A0,$79,$96,$79,$F5,$EA,_eol
		.BYTE $74,$6F,$F5,$75,$7C,$71,$93,$7E,$6B,$79,$F5,$94,$6C,$6F,$EA,_eol,_eol
_script99_msg01:
		.BYTE $EE,$EE,$EE,$EE,$EE,$EA,_eol,_eol
_script99_msg02:
		.BYTE $C7,$CD,$BE,$F5,$E7,$EA,$79,$76,$72,$79,$F5,$75,$7C,$6A,$72,$F5,$7C,$EA,_eol,_eol
_script99_msg03:
		.BYTE $73,$7D,$F5,$8C,$97,$79,$76,$72,$7C,$71,$93,$7C,__,$6A,$91,$6F,$F5,$7D,$6C,$EA,_eol
		.BYTE $7E,$7F,$8C,$7C,$F5,$70,$7E,$6B,$6F,$F5,$ED,$8E,$A0,$71,$91,_eol
		.BYTE $8D,$76,$96,$7C,$F5,$6B,$A0,$7C,$71,$93,$EA,_eol,_eol
_script99_msg04:
		.BYTE $6A,$88,$91,$ED,$8E,$A0,$71,$91,$75,$7C,$90,$93,$7E,$6B,$96,$79,$F5,$EA,_eol
		.BYTE $8F,$75,$ED,$6F,$F5,$96,$83,$F5,$92,$78,$F5,$EA,_eol,_eol
_script9A_msg00:
		.BYTE $6E,$8D,__,$6E,$88,$6D,$83,$A1,$C2,$C8,$A6,$75,$F5,$96,$79,$F5,$7E,$EA,_eol
		.BYTE $73,$96,$7E,$8D,$88,$6E,$71,$7F,__,$7E,$7F,$75,$7F,$70,$79,$EA,_eol,_eol
_script9A_msg02:
		.BYTE $7D,$F5,$6C,$71,$7B,$7F,$6B,$A0,$7C,_eol
		.BYTE $73,$7D,$F5,$8C,$97,__,$79,$76,$72,$79,$F5,$75,$79,$6B,$96,$79,$F5,$EA,_eol,_eol
_script9A_msg03:
		.BYTE $C7,$CD,$BC,$F6,$97,__,$6F,$75,$7C,$6A,$72,$F5,$8F,$6C,$EA,_eol
		.BYTE $C7,$CD,$BC,$F6,$6F,$F5,$7E,$72,$93,$83,$F5,__,$7D,$F5,$6C,$71,$7B,$83,_eol
		.BYTE $7D,$7C,$8C,$70,$72,$96,$79,$F5,$6F,$90,$7E,$EA,_eol,_eol
_script9B_msg00:
		.BYTE $A1,$C2,$C8,$A6,$82,$AD,$BA,$F6,$A2,$6F,$F5,$7B,$6F,$88,$A0,$79,$90,$75,$6B,$EA,_eol
		.BYTE $6B,$88,$73,$F5,$94,__,$73,$F5,$6C,$8C,$96,$97,_eol
		.BYTE $6C,$72,$7C,$6B,$92,$79,$F5,$94,$6C,$EA,_eol,_eol
_script9B_msg01:
		.BYTE $79,$76,$72,$79,$F5,$75,$7C,__,$6A,$72,$F5,$79,$6B,$95,$EA,_eol,_eol
_script9B_msg02:
		.BYTE $A8,$AD,$C8,$97,__,$95,$72,$7C,$6A,$72,$F5,$8F,$6C,$EA,_eol
		.BYTE $73,$93,$97,__,$A6,$CA,$7F,$82,$88,$77,$7C,$6A,$72,$F5,$7E,$74,$6B,$EA,_eol,_eol
_script9B_msg03:
		.BYTE $7B,$6F,$93,$7C,$92,$89,$79,$6B,$79,$F5,$7E,$EA,_eol
		.BYTE $76,$73,$75,$8D,$76,$96,$7C,$F5,__,$6B,$70,$7E,$74,$6B,$EA,_eol,_eol
_script9B_msg04:
		.BYTE $6A,$91,$6F,$F5,$7D,$6C,$EA,_eol
		.BYTE $73,$93,$7C,$F5,$ED,$8C,$6C,$84,$7D,$6A,$83,$F5,$93,__,$7C,$F5,$70,$78,$6C,$79,$F5,$EA,_eol,_eol
_script9C_msg00:
		.BYTE $8C,$6C,__,$6A,$96,$75,$96,$8F,$EA,_eol
		.BYTE $84,$7D,$F5,$6B,$8B,$7F,__,$6A,$A0,$79,$95,$81,$EA,_eol
		.BYTE $73,$93,$6F,$90,$7D,$F5,$6C,$76,$92,$82,$E8,__,$B0,$A2,$86,$E8,_eol
		.BYTE $78,$93,$6F,$90,__,$A1,$C2,$C8,$A6,$81,$EA,_eol
		.BYTE $95,$79,$75,$97,__,$7B,$93,$7C,$6F,$6D,$A0,$7C,$71,$93,$7E,$6B,$E8,_eol,_eol
_script9C_msg01:
		.BYTE $A7,$C0,$8C,__,$73,$73,$7F,$6B,$7C,$83,$6A,$85,$F5,$7E,$6B,$EA,_eol
		.BYTE $6B,$A0,$75,$9F,$7F,__,$6F,$6D,$94,$6C,$EA,_eol,_eol
_script9C_msg02:
		.BYTE $6A,$91,$6F,$F5,$7D,$6C,$EE,$EE,$EE,$7D,$7C,$8C,$6C,$93,$75,$6B,$82,$EE,$EE,$EE,_eol
		.BYTE $83,$8D,$71,__,$6B,$70,$88,$75,$9F,$6C,$EA,_eol
		.BYTE $6E,$A0,$7C,$6F,$F5,__,$76,$71,$F5,$78,$73,$88,$7C,$F5,$70,$7C,$6B,$92,$95,$EA,_eol,_eol
_script9C_msg03:
		.BYTE $AD,$F5,$B4,$F5,$B4,$F5,$B4,$F5,$B4,$F5,$B4,$F5,$B4,$F5,$B4,$F5,$B4,$F5,$B4,$F5,_eol
		.BYTE $70,$F5,$9D,$E7,$E7,$E7,$E7,$E7,_eol,_eol
_script9C_msg04:
		.BYTE $AA,$E7,$E9,__,$75,$A0,$6F,$91,$76,$92,$96,$79,$F5,$E9,_eol,_eol
_script9C_msg05:
		.BYTE $C7,$CD,$BE,$F5,$E7,$EE,$EE,$EE,$EA,_eol
		.BYTE $95,$79,$75,$ED,$8C,$6C,$A1,$C2,$C8,$A6,$86,_eol
		.BYTE $6B,$72,$7E,$6B,$82,$81,$EE,$EE,$EE,$EA,_eol,_eol
_script9C_msg06:
		.BYTE $7E,$7F,$6B,$A0,$7C,$6B,$92,$96,$79,$F5,$E9,_eol
		.BYTE $A5,$CA,$83,__,$6E,$88,$6D,$7D,$A1,$C2,$C8,$A6,$7F,$EE,$EE,$EE,$EA,_eol,_eol
_script9C_msg07:
		.BYTE $C7,$CD,$BE,$F5,$E7,$EE,$EE,$EE,__,$6A,$91,$6F,$F5,$7D,$6C,$EA,_eol
		.BYTE $95,$79,$75,$97,$EE,__,$95,$79,$75,$97,$95,$76,$93,$7E,$6B,$7C,$F5,$EE,$EE,$EA,_eol,_eol
_script9C_msg08:
		.BYTE $AA,$E7,$E9,_eol,_eol
_script9D_msg00:
		.BYTE $C7,$CD,$BE,$F5,$E7,$83,$ED,$BD,$C8,$AA,$BC,$F6,$B0,$E7,$82,$A6,$A7,$F5,$97,$89,$7B,$72,$79,$EA,_eol,_eol
_script9D_msg01:
		.BYTE $78,$73,$86,__,$C5,$E7,$AC,$CD,$71,$F5,$96,$78,$6C,$6F,$F5,__,$6A,$90,$95,$93,$7C,$ED,_eol
		.BYTE $EE,$EE,$EE,$EE,_eol,_eol
_script9D_msg02:
		.BYTE $75,$F5,$A0,$71,$91,__,$91,$9F,$6C,$91,$75,$7C,$8D,$94,$6C,$E9,_eol
		.BYTE $77,$6B,$77,$F5,$6B,__,$6A,$83,$F5,$93,$92,$6F,$F5,$6B,$6B,$EA,_eol,_eol
_script9E_msg00:
		.BYTE $A6,$A7,$F5,$97,$8C,$A0,$7C,$6B,$7E,$6B,$7D,_eol
		.BYTE $BD,$C8,$AA,$BC,$F6,$B0,$E7,$7F,$83,__,$82,$93,$7E,$6B,$78,$F5,$EA,_eol,_eol
_script9E_msg01:
		.BYTE $71,$92,$75,$6B,__,$79,$79,$6F,$6B,$79,$F5,$A0,$79,$6F,$F5,$ED,_eol
		.BYTE $73,$93,$7C,$F5,__,$8F,$6C,$8D,$71,$6E,$95,$91,$6F,$F5,$89,$6D,$7C,$70,$79,$EA,_eol
		.BYTE $73,$93,$6F,$90,__,$AC,$D5,$A3,$C6,$A3,$AC,$F5,$D6,$7F,$6B,$A0,$7C,_eol
		.BYTE $BE,$C8,$D6,$97,__,$70,$9E,$6C,$75,$9E,$7B,$75,$8F,$6C,$EA,_eol,_eol
_script9E_msg02:
		.BYTE $C7,$CD,$BE,$F5,$E7,__,$83,$8D,$71,$75,$F5,$9F,$6C,$75,$9F,$6C,$75,$7C,$E9,_eol
		.BYTE $7C,$70,$6F,$F5,__,$6E,$A0,$7C,$70,$79,$95,$E9,_eol,_eol
_script9F_msg00:
		.BYTE $78,$82,$73,$94,$AA,$E7,$83,$ED,$C7,$CD,$BE,$F5,$E7,$97,_eol
		.BYTE $79,$76,$72,$92,$79,$8B,$7F,$EE,$EE,$EE,$EE,$EA,_eol,_eol
_scriptA0_msg00:
		.BYTE $79,$F5,$6B,$75,$F5,$9F,$6C,$85,$F5,$6F,$E8,__,$79,$76,$72,$7F,$70,$79,$78,$F5,$EA,_eol,_eol
_scriptA0_msg01:
		.BYTE $6F,$90,$79,$F5,$6F,$F5,$ED,$8F,$95,$91,$70,$A0,$7C,$75,$7F,$78,$6C,$79,$F5,$EA,_eol
		.BYTE $6A,$75,$7C,$F5,$88,$7D,$6B,$7F,__,$7E,$92,$6F,$8C,$75,$93,$7E,$6B,$6F,$F5,$ED,_eol
		.BYTE $7B,$93,$7C,$6B,$A0,$7C,$71,$93,$EA,_eol,_eol
_scriptA0_msg02:
		.BYTE $6A,$79,$91,$88,$6D,$75,$F5,$9D,$7E,$6B,$6F,$EA,$72,$F5,$96,$70,$79,$F5,$77,$EA,_eol
		.BYTE $8C,$6C,$76,$73,$75,$82,__,$75,$96,$87,$F5,$6C,$79,$F5,$EA,_eol
		.BYTE $6B,$78,$6B,$7C,$F5,$7F,$72,$F5,$8F,$6C,$EA,_eol,_eol
_scriptA1_msg00:
		.BYTE $6E,$81,$6F,$F5,$6B,$79,$F5,__,$73,$94,$74,$7E,$6B,$7C,$F5,$71,$93,$EA,_eol,_eol
_scriptA1_msg01:
		.BYTE $79,$F5,$6B,$75,$F5,$9F,$6C,$85,$F5,$79,$F5,$EA,$6E,$93,$83,$89,$6F,$79,$79,$F5,$EA,_eol
		.BYTE $6B,$88,$7E,$95,$97,__,$87,$7D,$F5,$71,$6F,$90,$EA,_eol
		.BYTE __,_eol
		.BYTE $76,$88,$7E,$6B,$EA,_eol
		.BYTE $AC,$D4,$AC,$CD,$97,$7D,$92,$82,$6F,$F5,__,$B6,$CD,$C1,$7E,$96,$79,$F5,$EA,_eol,_eol
_scriptA1_msg02:
		.BYTE $79,$76,$72,$7F,__,$70,$7C,$71,$93,$79,$82,$7C,$F5,$83,$7E,$6B,$82,$6F,$EA,_eol
		.BYTE $6E,$81,$6F,$F5,$6B,$79,$F5,__,$79,$76,$72,$7C,$71,$93,$E9,_eol,_eol
_scriptA1_msg03:
		.BYTE $EE,$EE,$EE,$79,$76,$6F,$A0,$79,$EA,_eol
		.BYTE $87,$6F,$7F,$8C,$EE,$EE,$EE,$EE,$EA,_eol,_eol
_scriptA1_msg04:
		.BYTE $88,$79,$8C,$7D,$F5,$92,$EA,_eol
		.BYTE $6B,$78,$6B,$7C,$F5,__,$7F,$72,$F5,$8F,$6C,$EA,_eol,_eol
_scriptA2_msg00:
		.BYTE $83,$8D,$71,__,$BD,$C8,$7F,$82,$93,$E9,_eol,_eol
_scriptA2_msg01:
		.BYTE $8D,$A0,$79,$77,$F5,$EA,$BD,$F5,$B4,$B5,$C1,$7D,$8C,_eol
		.BYTE $73,$93,$7C,$F5,__,$6E,$74,$90,$83,$F5,$79,$F5,$EA,_eol,_eol
_scriptA2_msg02:
		.BYTE $BE,$C8,$D6,$6F,$F5,__,$88,$79,$F5,$6B,$92,$83,$76,$F5,$79,$F5,$EA,_eol
		.BYTE $70,$9E,$6C,$75,$9E,$7B,$75,$7C,_eol
		.BYTE $AC,$D5,$A3,$C6,$A3,$AC,$F5,$D6,$97,__,$79,$F5,$A0,$75,$9E,$7B,$75,$9F,$6C,$EA,_eol,_eol
_scriptA2_msg03:
		.BYTE $95,$79,$75,$8C,__,$7C,$7B,$79,$F5,$6C,$95,$EA,_eol,_eol
_scriptA2_msg04:
		.BYTE $70,$89,$83,$ED,$BD,$C8,$7C,$F5,$88,$A0,$7C,$6B,$79,$87,$6C,$6F,$F5,_eol
		.BYTE $6B,$6B,$79,$F5,$94,$6C,$EA,_eol,_eol
_scriptA3_msg00:
		.BYTE $8B,$6B,$93,$6B,$97,__,$71,$79,$F5,$76,$82,$83,$95,$79,$75,$7C,$F5,$83,$7E,$6B,$EA,_eol
		.BYTE $95,$79,$75,$83,__,$6C,$72,$92,$6F,$F5,$95,$79,$F5,$EA,_eol
		.BYTE $EE,$EE,$EE,$EE,$EE,$EE,$EE,$EE,$EE,_eol,_eol
_scriptA3_msg01:
		.BYTE $73,$96,$7E,$73,$7D,$7F,__,$7E,$92,$7D,$83,_eol
		.BYTE $6E,$8C,$95,$7E,$6F,$A0,$79,$EA,_eol
		.BYTE $EE,$EE,$EE,$EE,$EE,$EE,$EE,$EE,$EE,_eol,_eol
_scriptA3_msg02:
		.BYTE $95,$79,$75,$7F,$83,__,$8B,$6B,$93,$6B,$82,$84,$7D,$7B,$79,$F5,$A0,$79,$EA,_eol
		.BYTE $EE,$EE,$EE,$EE,$EE,$EE,$EE,$EE,$EE,_eol,_eol
_scriptA3_msg03:
		.BYTE $7F,$96,$8A,$EA,$6F,$96,$91,$9F,$6C,$75,$88,$75,$79,$EA,_eol,_eol
_scriptA3_msg04:
		.BYTE $88,$79,$F5,$ED,$6E,$6C,$77,$F5,$6B,$82,$A0,$73,$A0,$7C,$6B,$92,$83,$76,$F5,$79,$F5,$EA,_eol
		.BYTE $73,$94,$74,$93,$79,$71,$7E,$6B,$7E,$90,$ED,_eol
		.BYTE $77,$F5,$6B,$6B,$96,__,$70,$9E,$6C,$75,$9E,$7B,$75,$94,$E9,_eol,_eol
_scriptA3_msg05:
		.BYTE $73,$F5,$71,$94,$6C,$79,$F5,$A0,$79,$EA,$C7,$CD,$BE,$F5,$E7,$EA,_eol
		.BYTE $70,$89,$7E,$90,$8D,$92,$7D,__,$95,$79,$75,$83,$75,$96,$75,$F5,$7C,$6B,$79,$EA,_eol
		.BYTE $70,$89,$83,__,$8C,$6C,$AC,$F5,$C5,$A3,$79,$F5,$EA,_eol
		.BYTE $7D,$F5,$73,$86,$7C,$F5,$8C,__,$76,$70,$7E,$7D,$73,$94,$86,$6B,$70,$79,$88,$6D,$EA,_eol,_eol
_scriptA3_msg06:
		.BYTE $BE,$C8,$D6,$70,$9E,$6C,$75,$9E,$7B,$7F,__,$6B,$6F,$7E,$6B,$82,$6F,$E8,_eol,_eol
_scriptA3_msg07:
		.BYTE $79,$F5,$8B,$79,$F5,$EA,_eol
		.BYTE $6A,$82,$AC,$D4,$AC,$CD,$6F,$F5,$ED,$AC,$D6,$A3,$AA,$7F,_eol
		.BYTE $7E,$90,$7E,$6F,$A0,$79,$96,$79,$F5,$EA,_eol,_eol
_scriptA3_msg08:
		.BYTE $AB,$A8,$AE,$CD,$83,__,$75,$A0,$83,$F6,$6B,$79,$F5,$EA,_eol
		.BYTE $95,$79,$75,$83,__,$74,$6B,$75,$9F,$6F,$90,_eol
		.BYTE $A7,$C0,$7F,$83,__,$8A,$91,$7E,$73,$7D,$79,$F5,$7D,_eol
		.BYTE $6E,$8C,$A0,$7C,$6B,$79,$EA,_eol,_eol
		.BYTE _eol		; *--
_scriptA4_msg00:
		.BYTE $73,$F5,$71,$94,$6C,$79,$F5,$A0,$79,$EA,_eol
		.BYTE $C7,$CD,$BE,$F5,$E7,_eol,_eol
_scriptA4_msg01:
		.BYTE $EE,$EE,$EE,$EE,$EE,$EE,$EE,_eol,_eol
_scriptA4_msg02:
		.BYTE $70,$89,$83,$ED,$87,$96,$7D,$6C,$7F,$79,$6B,$75,$79,$8D,$7B,$79,$F5,$EA,_eol
		.BYTE $75,$F5,$85,$F5,$96,$75,$F5,$75,$96,$7C,$F5,__,$AC,$F5,$C5,$A3,$97,$7B,$6F,$89,$7D,$A0,$79,_eol
		.BYTE $96,$79,$F5,$EA,_eol,_eol
_scriptA4_msg03:
		.BYTE $AC,$F5,$D6,$CD,__,$7D,$F5,$73,$86,$6B,$71,$EA,_eol,_eol
_scriptA4_msg04:
		.BYTE $74,$6A,$EA,_eol,_eol
_scriptA4_msg05:
		.BYTE $7F,$73,$8B,$82,__,$8B,$6B,$8F,$75,$9F,$6C,$79,$F5,$7E,$EA,_eol,_eol
_scriptA4_msg06:
		.BYTE $71,$96,$75,$9F,$6C,$83,__,$6F,$93,$90,$82,$8C,$82,$7C,$F5,$76,$EA,_eol,_eol
_scriptA4_msg07:
		.BYTE $70,$89,$83,$8C,$6C,__,$AC,$F5,$C5,$A3,$79,$F5,$EA,_eol
		.BYTE $95,$93,$95,$93,$82,$7D,$73,$94,$86,__,$8C,$7D,$F5,$A0,$7C,$73,$6B,$EA,_eol,_eol
_scriptA4_msg08:
		.BYTE $7E,$7F,$6F,$F5,$6A,$92,$EA,_eol
		.BYTE $7D,$8C,$79,$F5,$7A,$83,__,$73,$73,$7C,$F5,$75,$7F,_eol
		.BYTE $6E,$93,$82,$73,$73,$94,$8C,__,$75,$96,$79,$F5,$EA,_eol,_eol
_scriptA4_msg09:
		.BYTE $88,$7A,$6F,$F5,$A0,$79,$77,$96,$78,$6C,$79,$F5,$A0,$79,$6F,$F5,$ED,_eol
		.BYTE $A8,$B6,$97,$7F,$71,$8A,$7E,$EA,_eol,_eol
_scriptA4_msg0a:
		.BYTE $7F,$71,$8A,$E8,_eol
		.BYTE $6B,$82,$7A,$97,__,$74,$74,$72,$F5,$88,$76,$EA,_eol,_eol
_scriptA4_msg0b:
		.BYTE $7C,$F5,$83,$ED,$7E,$7F,$6F,$F5,$82,$78,$F5,$89,$79,$F5,$EA,_eol,_eol
_scriptA4_msg0c:
		.BYTE $6F,$93,$90,$6F,$F5,$82,$78,$F5,$96,$79,$F5,$73,$7D,$7C,$F5,$76,$EA,_eol
		.BYTE $6F,$93,$90,$83,__,$73,$82,$7D,$7A,$7F,$70,$7C,$ED,_eol
		.BYTE $79,$79,$6F,$6B,$7F,__,$89,$97,$7D,$6C,$75,$F5,$7E,$6F,$F5,$90,_eol
		.BYTE $84,$7D,$7B,$82,$73,$7D,$97,__,$81,$6F,$F5,$A0,$79,$EA,_eol,_eol
_scriptA4_msg0d:
		.BYTE $A8,$B6,$86,$82,__,$6E,$8C,$6B,$6F,$F5,_eol
		.BYTE $8A,$71,$95,$93,$92,$73,$7D,$7C,$F5,$76,$EA,_eol
		.BYTE $6E,$93,$8C,__,$6E,$7E,$75,$F5,$79,$F5,$EA,_eol,_eol
_scriptA4_msg0e:
		.BYTE $73,$82,$74,$70,$83,$E8,_eol,_eol
_scriptA4_msg0f:
		.BYTE $84,$84,$F5,$97,__,$6B,$70,$88,$76,$EA,_eol,_eol
_scriptA4_msg10:
		.BYTE $8F,$71,$6F,$6D,$A0,$7C,$70,$79,$EA,$79,$F5,$6F,$F5,$ED,$70,$89,$83,$A9,$F5,$E7,$C1,$97,_eol
		.BYTE $75,$9E,$6C,$91,$9F,$6C,$75,$7C,$6B,$7E,$6B,$EA,_eol
		.BYTE $AC,$F5,$D6,$CD,$ED,$73,$93,$7C,$F5,$88,$96,$78,$F5,$71,$6F,$E8,_eol,_eol
_scriptA4_msg11:
		.BYTE $86,$91,$7F,__,$82,$92,$7D,$73,$94,$6F,$90,_eol
		.BYTE $8C,$6C,$6B,$7A,$7D,$F5,__,$8D,$90,$77,$7C,$71,$93,$EA,_eol
		.BYTE __,_eol
		.BYTE $8C,$6C,$6A,$96,$7E,__,$6A,$85,$F5,$7E,$6B,$8B,$7F,_eol
		.BYTE $6A,$6B,$79,$71,$7E,$6B,$EA,_eol,_eol
		.BYTE _eol		; *--
_scriptA4_msg12:
		.BYTE $87,$96,$7D,$6C,$82,__,$A9,$F5,$E7,$C1,$82,$8C,$71,$7C,$70,$83,_eol
		.BYTE $BE,$C8,$D6,$70,$9E,$6C,$75,$9E,$7B,__,$7E,$96,$79,$F5,$8F,$EA,_eol,_eol
_scriptA5_msg00:
		.BYTE $73,$93,$6F,$90,$7D,$F5,$6C,$76,$92,$82,$E8,__,$A1,$C2,$C8,$A6,$86,$E8,_eol
		.BYTE $6A,$79,$79,$6F,$7E,__,$84,$7D,$EA,_eol
		.BYTE $6A,$79,$79,$6F,$7E,__,$88,$7A,$EA,_eol
		.BYTE $6A,$79,$79,$6F,$7E,__,$88,$6B,$7F,$7A,$EA,_eol,_eol
_scriptA5_msg01:
		.BYTE $95,$79,$75,$ED,$A1,$C2,$C8,$A6,$86,$6B,$A0,$7C,_eol
		.BYTE $78,$96,$7E,$71,$90,$75,$97,$76,$92,$82,$6F,$F5,_eol
		.BYTE $8E,$8B,$79,$F5,$A0,$79,$95,$EA,_eol
		.BYTE $8C,$75,$ED,$6A,$7E,$79,$74,$6D,$8F,$72,$93,$83,$F5,$EE,$EE,$EE,$EA,_eol,_eol
_scriptA5_msg02:
		.BYTE $AA,$E7,$EE,$EE,$EE,$A7,$C0,$7F,$83,$ED,$79,$6B,$77,$7B,$7E,$8C,$82,$97,_eol
		.BYTE $88,$7E,$96,$79,$F5,$8F,$6C,$7E,__,$70,$6F,$F5,$76,$92,$EA,_eol
		.BYTE $78,$93,$83,__,$6B,$70,$92,__,$7D,$6B,$6C,$73,$7D,_eol
		.BYTE $79,$F5,$A0,$79,$6F,$8C,$75,$93,$7E,$6B,$ED,_eol
		.BYTE $6A,$6B,__,$79,$F5,$A0,$79,$6F,$8C,$75,$93,$7E,$6B,$EE,$EE,$EE,$EA,_eol,_eol
_scriptA5_msg03:
		.BYTE $87,$96,$7D,$6C,$E8,$E9,_eol
		.BYTE $C7,$CD,$BE,$F5,$E7,$ED,$79,$F5,$6B,$76,$70,$8F,$A0,$EA,_C,_H,_U,$E9,_eol,_eol
		.BYTE _eol		; *--
		.BYTE _eol		; *--
		.BYTE _eol		; *--
_scriptA9_msg00:
		.BYTE $B0,$A2,$82,$AB,$A8,$AE,$CD,$BE,$CD,$BC,$F5,$7F,$8C,$7D,$F5,$A0,$79,_eol
		.BYTE $B4,$C7,$A3,$B4,$BF,$CD,$83,__,$BF,$E7,$B4,$F5,$D7,$A8,$7D,_eol
		.BYTE $EE,$EE,$EE,$EE,$EE,$EE,$EE,$EE,_eol,_eol
_scriptA9_msg01:
		.BYTE $6B,$A0,$79,$6B,$7E,$96,$82,__,$88,$81,$79,$F5,$EA,_eol
		.BYTE $74,$6B,$75,$9F,$6F,$90,__,$A3,$AF,$97,$7B,$6B,$79,$7E,$EA,_eol
		.BYTE $AC,$D5,$A3,$C6,$A3,$AC,$F5,$D6,$83,__,$8A,$75,$F5,$96,$82,$83,$76,$F5,$79,$F5,$A0,$79,$EA,_eol,_eol
_scriptA9_msg02:
		.BYTE $95,$79,$75,$97,__,$79,$F5,$93,$79,$F5,$7D,$6E,$8C,$A0,$7C,$6B,$92,$EA,_eol,_eol
_scriptA9_msg03:
		.BYTE $95,$6F,$F5,$89,$97,$6F,$83,$F5,$6C,__,$71,$74,$A0,$79,$71,$F5,$96,$75,$F5,$96,$79,$F5,$EA,_eol,_eol
_scriptA9_msg04:
		.BYTE $95,$6F,$F5,$89,$7C,$F5,$83,$7E,$6B,$EA,$AA,$D7,$A6,$82,$8C,$96,$79,$F5,$6B,$79,$F5,$EA,_eol
		.BYTE $6F,$A0,$7C,$7E,$73,$6C,$7D,$F5,$6C,$97,$75,$79,$82,$83,_eol
		.BYTE $70,$89,$82,$EB,$A4,$A2,$C5,$A3,$EC,$79,$F5,$78,$F5,$EA,_eol
		.BYTE $AC,$D4,$AC,$CD,$79,$F5,$72,__,$7D,$A0,$7C,$93,$83,$F5,_eol
		.BYTE $8C,$96,$79,$F5,$6B,$7E,$6F,$A0,$79,$82,$79,$F5,$EA,_eol,_eol
_scriptA9_msg05:
		.BYTE $70,$89,$A0,$7C,$6E,$7D,$73,$83,__,$7E,$7F,$8C,_eol
		.BYTE $95,$6F,$A0,$7C,$6E,$90,$96,$EA,_eol
		.BYTE $BE,$C8,$D6,$82,__,$89,$82,$75,$94,$70,$96,$97,_eol
		.BYTE $83,$90,$6D,$7D,__,$6B,$6C,$82,$6F,$81,$E8,_eol
		.BYTE $7C,$70,$82,$85,$7D,$73,$94,$97,__,$73,$8D,$76,$73,$7D,$7F,$7E,$92,$78,$F5,$EA,_eol,_eol
_scriptA9_msg06:
		.BYTE $78,$73,$71,$82,$79,$8B,$7F,__,$79,$79,$6F,$A0,$79,_eol
		.BYTE $6E,$7D,$73,$79,$7A,$79,$F5,$78,$F5,$E9,_eol
		.BYTE $A9,$F5,$AD,$8D,$94,$6C,$EA,_eol
		.BYTE $6B,$88,$7F,$73,$6C,$6F,$6B,$76,$92,$78,$F5,$EA,_eol,_eol
_scriptA9_msg07:
		.BYTE $7E,$77,$F5,$6F,$81,$E8,_eol,_eol
_scriptA9_msg08:
		.BYTE $EE,$EE,$EE,$EE,$EE,$EE,$EE,$EE,_eol
		.BYTE $C7,$CD,$BE,$F5,$E7,$79,$F5,$8F,$EA,_eol,_eol
		.BYTE _eol		; *--
_scriptAA_msg00:
		.BYTE $C0,$B2,$C5,$A7,$F5,$D6,$A3,$AC,$D4,$82,$85,$81,$97,_eol
		.BYTE $8D,$7D,$A0,$79,__,$C7,$CD,$BE,$F5,$E7,$7D,$AA,$E7,$83,$EE,$EE,$EE,$EE,_eol,_eol
		.BYTE _eol		; *--
		.BYTE _eol		; *--
_scriptAC_msg00:
		.BYTE $73,$F5,$71,$94,$6C,$EA,$95,$79,$75,$83,$A4,$C8,$A8,$AF,$CD,$79,$F5,$EA,_eol
		.BYTE $70,$89,$6F,$F5,__,$6C,$95,$74,$82,$6E,$7D,$73,$6F,$EA,_eol
		.BYTE $BD,$F5,$B4,$B5,$C1,$7C,$F5,$83,__,$7C,$F5,$96,$77,$7B,$79,$F5,$77,$F5,$EA,_eol
		.BYTE $A7,$C0,$7D,$83,$79,$90,$72,$7C,__,$73,$6C,$6D,$6B,$79,$F5,$EA,_eol
		.BYTE $A7,$D6,$A3,$AE,$A2,$CB,$A3,$B4,$F5,$A3,$8F,$91,__,$BF,$AC,$79,$F5,$94,$E8,_eol,_eol
_scriptAC_msg01:
		.BYTE $75,$9E,$A0,$83,$F6,$7B,$88,$7C,$F5,__,$AC,$F5,$A6,$CD,$6F,$F5,$7E,$6B,$EA,_eol
		.BYTE $83,$8D,$71,__,$B4,$C7,$A3,$B4,$BF,$CD,$79,$6B,$74,$82,$7D,$73,$94,$86,_eol
		.BYTE $6B,$72,$E9,_eol,_eol
_scriptAD_msg00:
		.BYTE $6A,$91,$6F,$F5,$7D,$6C,$EA,$C7,$CD,$BE,$F5,$E7,$EA,_eol
		.BYTE $70,$89,$7E,$90,__,$6F,$7E,$90,$76,$F5,_eol
		.BYTE $70,$9E,$6C,$75,$9E,$7B,__,$75,$7C,$71,$93,$92,$7D,_eol
		.BYTE $6E,$8C,$A0,$7C,$6B,$79,$EA,_eol,_eol
_scriptAE_msg00:
		.BYTE $AA,$E7,$83,$ED,$C7,$CD,$BE,$F5,$E7,$97,$79,$76,$72,$92,$79,$8B,$7F,_eol
		.BYTE $AC,$D5,$A3,$C6,$A3,$AC,$F5,$D6,$7F,__,$8A,$6F,$A0,$79,$EA,_eol,_eol
		.BYTE _eol		; *--
		.BYTE _eol		; *--
		.BYTE _eol		; *--
_scriptB1_msg00:
		.BYTE $AC,$F5,$D6,$CD,$EE,$C7,$CD,$BE,$F5,$E7,_eol
		.BYTE __,_eol
		.BYTE __,$79,$79,$6F,$6B,$83,$ED,$6E,$95,$A0,$79,$EA,$79,$F5,$6F,$F5,$EE,$EE,$EE,_eol,_eol
_scriptB1_msg01:
		.BYTE $B4,$C7,$A3,$B4,$BF,$CD,$79,$6B,$74,_eol
		.BYTE __,_eol
		.BYTE __,$8F,$71,$8D,$A0,$79,$EA,_eol,_eol
_scriptB1_msg02:
		.BYTE $BF,$E7,$B4,$F5,$D7,$A8,$75,$93,$6B,$6F,$96,_eol
		.BYTE __,_eol
		.BYTE __,$6E,$93,$6F,$F5,$95,$92,$6B,$96,$75,$F5,$9D,$7E,$6B,$8F,$E9,_eol,_eol
_scriptB1_msg03:
		.BYTE $A4,$C8,$A8,$AF,$CD,_eol
		.BYTE __,_eol
		.BYTE __,$8F,$A0,$E9,__,$6D,$6B,$8E,$6C,$EA,_eol,_eol
_scriptB2_msg00:
		.BYTE $AA,$E7,$EE,$BA,$F5,$A5,_eol
		.BYTE __,_eol
		.BYTE __,$95,$79,$75,$83,$ED,$6A,$7E,$79,$97,$EE,$EE,$EE,_eol,_eol
_scriptB2_msg01:
		.BYTE $BA,$F5,$CD,$A8,$AD,_eol
		.BYTE __,_eol
		.BYTE __,$88,$79,$ED,$79,$76,$72,$7C,$81,$E9,_eol,_eol
_scriptB2_msg02:
		.BYTE $6F,$6B,$78,$F5,$71,_eol
		.BYTE __,_eol
		.BYTE __,$6C,$90,$70,$F5,$91,$8C,$82,$7F,__,$73,$F5,$7A,$9E,$6C,$6B,$E9,_eol,_eol
_scriptB2_msg03:
		.BYTE $73,$7D,$F5,$8C,_eol
		.BYTE __,_eol
		.BYTE __,$C7,$CD,$BE,$F5,$E7,$82,$6E,$75,$F5,$7A,$9D,$96,_eol
		.BYTE __,$6A,$91,$6F,$F5,$7D,$6C,$EA,_eol,_eol
_scriptB3_msg00:
		.BYTE $86,$6B,$79,$6B,_1,_eol
		.BYTE __,_eol
		.BYTE __,$73,$85,$F5,$96,$7F,$75,$7C,$71,$79,$F5,$74,$6B,$E9,_eol,_eol
_scriptB3_msg01:
		.BYTE $86,$6B,$79,$6B,_2,_eol
		.BYTE __,_eol
		.BYTE __,_H,$7E,$73,$7D,$75,$88,$75,$9F,$6C,$8F,$96,$E9,_eol,_eol
_scriptB3_msg02:
		.BYTE $8A,$90,$84,$F5,$7D,_1,_eol
		.BYTE __,_eol
		.BYTE __,$C7,$CD,$BC,$F6,$83,$6B,$6F,$6F,$F5,$E8,_eol,_eol
_scriptB3_msg03:
		.BYTE $8A,$90,$84,$F5,$7D,_2,_eol
		.BYTE __,_eol
		.BYTE __,$7A,$9F,$A0,$7D,$8D,$76,$96,$7C,$F5,$6B,$6F,$7E,$6B,$E8,_eol,_eol
_scriptB4_msg00:
		.BYTE $BA,$F6,$B4,$F5,$BC,$AD,$A7,$E7,$7A,$9E,$6C,$74,_eol
		.BYTE __,_eol
		.BYTE __,$BD,$C8,$82,$6F,$70,$F5,__,$6F,$6D,$75,$7C,$E9,_eol,_eol
_scriptB4_msg01:
		.BYTE $C5,$E7,$AC,$CD,$71,$F5,$96,$78,$6C,_eol
		.BYTE __,_eol
		.BYTE __,$86,$86,$86,$EE,$EE,$EE,$EA,_eol,_eol
_scriptB5_msg00:
		.BYTE $6E,$7B,$6F,$93,$74,$88,$7C,$F5,$75,$79,$EA,_eol,_eol

