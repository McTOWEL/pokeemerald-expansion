ShadyRoom_MapScripts::
	.byte 0


ShadyRoom_EventScript_Gentleman::
# 4 "data/maps/ShadyRoom/scripts.pory"
	lock
# 5 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 7 "data/maps/ShadyRoom/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TOKEN_BALANCE
# 8 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 9 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_Greeting
ShadyRoom_EventScript_Gentleman_2:
# 11 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_ne ShadyRoom_EventScript_Gentleman_3
# 15 "data/maps/ShadyRoom/scripts.pory"
	closemessage
# 16 "data/maps/ShadyRoom/scripts.pory"
	release
	return

ShadyRoom_EventScript_Gentleman_3:
# 12 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_Menu
	goto ShadyRoom_EventScript_Gentleman_2


ShadyRoom_EventScript_Gentleman_Menu::
# 20 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_GENTLEMAN_SERVICES
# 22 "data/maps/ShadyRoom/scripts.pory"
	message ShadyRoom_Text_Gentleman_Menu
# 23 "data/maps/ShadyRoom/scripts.pory"
	waitmessage
# 25 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 27 "data/maps/ShadyRoom/scripts.pory"
	switch VAR_RESULT
# 28 "data/maps/ShadyRoom/scripts.pory"
	case 0, ShadyRoom_EventScript_Gentleman_Menu_2
# 31 "data/maps/ShadyRoom/scripts.pory"
	case 1, ShadyRoom_EventScript_Gentleman_Menu_3
# 34 "data/maps/ShadyRoom/scripts.pory"
	case 2, ShadyRoom_EventScript_Gentleman_Menu_4
# 37 "data/maps/ShadyRoom/scripts.pory"
	case 3, ShadyRoom_EventScript_Gentleman_Menu_5
# 40 "data/maps/ShadyRoom/scripts.pory"
	case 4, ShadyRoom_EventScript_Gentleman_Menu_6
# 43 "data/maps/ShadyRoom/scripts.pory"
	case MULTI_B_PRESSED, ShadyRoom_EventScript_Gentleman_Menu_7
	return

ShadyRoom_EventScript_Gentleman_Menu_2:
# 29 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_ChangeNature
	return

ShadyRoom_EventScript_Gentleman_Menu_3:
# 32 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_ChangeAbility
	return

ShadyRoom_EventScript_Gentleman_Menu_4:
# 35 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_ChangeHiddenAbility
	return

ShadyRoom_EventScript_Gentleman_Menu_5:
# 38 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_MaxIV
	return

ShadyRoom_EventScript_Gentleman_Menu_6:
# 41 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_Menu_7:
	return


ShadyRoom_EventScript_Gentleman_SelectPokemon::
# 49 "data/maps/ShadyRoom/scripts.pory"
	special ChoosePartyMon
# 51 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq ShadyRoom_EventScript_Gentleman_SelectPokemon_2
# 56 "data/maps/ShadyRoom/scripts.pory"
	special IsSelectedMonEgg
# 58 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_Gentleman_SelectPokemon_5
# 64 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, TRUE
	return

ShadyRoom_EventScript_Gentleman_SelectPokemon_2:
# 52 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, FALSE
	return

ShadyRoom_EventScript_Gentleman_SelectPokemon_5:
# 59 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
# 60 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, FALSE
	return


ShadyRoom_EventScript_Gentleman_CheckTokens::
# 69 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_TOKEN_BALANCE, 0
	goto_if_eq ShadyRoom_EventScript_Gentleman_CheckTokens_2
# 75 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_TOKEN_BALANCE, VAR_SERVICE_COST
	goto_if_lt ShadyRoom_EventScript_Gentleman_CheckTokens_5
# 81 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, TRUE
	return

ShadyRoom_EventScript_Gentleman_CheckTokens_2:
# 70 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NoTokens
# 71 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_CheckTokens_5:
# 76 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_InsufficientTokens
# 77 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, FALSE
	return


ShadyRoom_EventScript_Gentleman_ChangeNature::
# 86 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 2
# 87 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 88 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_2
# 88 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_2
# 92 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NatureCost, MSGBOX_YESNO
# 93 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_7
# 97 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_SelectPokemon
# 98 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_10
# 102 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 103 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_NATURE_PICKER
# 104 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 106 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_13
# 110 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8006
# 111 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 113 "data/maps/ShadyRoom/scripts.pory"
	special IsNatureSameAsCurrent
# 114 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_16
# 119 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_0x8005
# 120 "data/maps/ShadyRoom/scripts.pory"
	special SetHiddenNature
# 121 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 122 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NatureChanged
# 123 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_2:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_7:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_10:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_13:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_16:
# 115 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_SameNature
	return


ShadyRoom_EventScript_Gentleman_ChangeAbility::
# 127 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
	return


ShadyRoom_EventScript_Gentleman_ChangeHiddenAbility::
# 132 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
	return


ShadyRoom_EventScript_Gentleman_MaxIV::
# 137 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
	return


ShadyRoom_EventScript_Assistant::
# 142 "data/maps/ShadyRoom/scripts.pory"
	lock
# 143 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 144 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
# 145 "data/maps/ShadyRoom/scripts.pory"
	release
	return


ShadyRoom_EventScript_Merchant::
# 149 "data/maps/ShadyRoom/scripts.pory"
	lock
# 150 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 151 "data/maps/ShadyRoom/scripts.pory"
	addvar VAR_TOKEN_BALANCE, 1
# 152 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
# 153 "data/maps/ShadyRoom/scripts.pory"
	release
	return


ShadyRoom_EventScript_Abra::
# 157 "data/maps/ShadyRoom/scripts.pory"
	lock
# 158 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 159 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
# 160 "data/maps/ShadyRoom/scripts.pory"
	release
	return


ShadyRoom_Text_Placeholder::
# 163 "data/maps/ShadyRoom/scripts.pory"
	.string "This feature hasn't been implemented yet.$"

ShadyRoom_Text_Gentleman_Greeting::
# 167 "data/maps/ShadyRoom/scripts.pory"
	.string "GENTLEMAN: Keep your voice down...\n"
	.string "Let's see. You have {STR_VAR_1} unit(s) of credit.\p"
	.string "I specialize in... off-the-record\n"
	.string "modifications. What do you need?$"

ShadyRoom_Text_Gentleman_Menu::
# 174 "data/maps/ShadyRoom/scripts.pory"
	.string "What can I do for you?$"

ShadyRoom_Text_Gentleman_CantSelectEgg::
# 178 "data/maps/ShadyRoom/scripts.pory"
	.string "An Egg? Let's wait until it hatches\n"
	.string "before we start rewriting its DNA.$"

ShadyRoom_Text_Gentleman_InsufficientTokens::
# 183 "data/maps/ShadyRoom/scripts.pory"
	.string "Look, I like you, but I don't work\n"
	.string "pro bono. You're short on credit.\p"
	.string "Come back when you can afford my rates.$"

ShadyRoom_Text_Gentleman_NoTokens::
# 189 "data/maps/ShadyRoom/scripts.pory"
	.string "Come now, let's not waste time.\n"
	.string "Your line of credit is tapped out.$"

ShadyRoom_Text_Gentleman_NatureCost::
# 194 "data/maps/ShadyRoom/scripts.pory"
	.string "A complete shift in Nature, is it?\n"
	.string "That will run you one unit of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_SameNature::
# 200 "data/maps/ShadyRoom/scripts.pory"
	.string "My friend, it already behaves like that.\n"
	.string "Don't play games with me. What do you really need?$"

ShadyRoom_Text_Gentleman_NatureChanged::
# 205 "data/maps/ShadyRoom/scripts.pory"
	.string "Pleasure doing business with you.\n"
	.string "Its mindset has been... optimized.$"
