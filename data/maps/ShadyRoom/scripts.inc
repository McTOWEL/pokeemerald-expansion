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
	call ShadyRoom_EventScript_Gentleman_HiddenAbility
	return

ShadyRoom_EventScript_Gentleman_Menu_4:
# 35 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_RegularAbility
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


ShadyRoom_EventScript_Gentleman_HiddenAbility::
# 127 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 4
# 128 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 129 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_2
# 129 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_2
# 133 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HiddenAbilityCost, MSGBOX_YESNO
# 134 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_7
# 138 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_SelectPokemon
# 139 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_10
# 143 "data/maps/ShadyRoom/scripts.pory"
	special MonHasHiddenAbility
# 144 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_13
# 149 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HiddenAbilityConfirm, MSGBOX_YESNO
# 150 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_16
# 154 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8005, 2
# 155 "data/maps/ShadyRoom/scripts.pory"
	special SetAbilitySlot
# 157 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 158 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HAApplied
# 159 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_2:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_7:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_10:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_13:
# 145 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AlreadyHiddenAbility
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_16:
	return


ShadyRoom_EventScript_Gentleman_RegularAbility::
# 163 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_RestoreAbilityOffer, MSGBOX_YESNO
# 164 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_2
# 168 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_SelectPokemon
# 169 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_5
# 173 "data/maps/ShadyRoom/scripts.pory"
	special MonHasHiddenAbility
# 174 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_8
# 179 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_RestoreAbilityConfirm, MSGBOX_YESNO
# 180 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_11
# 184 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 185 "data/maps/ShadyRoom/scripts.pory"
	special SetAbilitySlot
# 187 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AbilityRestored
# 188 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_2:
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_5:
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_8:
# 175 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AlreadyRegularAbility
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_11:
	return


ShadyRoom_EventScript_Gentleman_MaxIV::
# 192 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
	return


ShadyRoom_EventScript_Assistant::
# 197 "data/maps/ShadyRoom/scripts.pory"
	lock
# 198 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 199 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
# 200 "data/maps/ShadyRoom/scripts.pory"
	release
	return


ShadyRoom_EventScript_Merchant::
# 204 "data/maps/ShadyRoom/scripts.pory"
	lock
# 205 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 206 "data/maps/ShadyRoom/scripts.pory"
	addvar VAR_TOKEN_BALANCE, 1
# 207 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
# 208 "data/maps/ShadyRoom/scripts.pory"
	release
	return


ShadyRoom_EventScript_Abra::
# 212 "data/maps/ShadyRoom/scripts.pory"
	lock
# 213 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 214 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
# 215 "data/maps/ShadyRoom/scripts.pory"
	release
	return


ShadyRoom_Text_Placeholder::
# 218 "data/maps/ShadyRoom/scripts.pory"
	.string "This feature hasn't been implemented yet.$"

ShadyRoom_Text_Gentleman_Greeting::
# 222 "data/maps/ShadyRoom/scripts.pory"
	.string "GENTLEMAN: Keep your voice down...\n"
	.string "Let's see. You have {STR_VAR_1} unit(s) of credit.\p"
	.string "I specialize in... off-the-record\n"
	.string "modifications. What do you need?$"

ShadyRoom_Text_Gentleman_Menu::
# 229 "data/maps/ShadyRoom/scripts.pory"
	.string "What can I do for you?$"

ShadyRoom_Text_Gentleman_CantSelectEgg::
# 233 "data/maps/ShadyRoom/scripts.pory"
	.string "An Egg? Let's wait until it hatches\n"
	.string "before we start rewriting its DNA.$"

ShadyRoom_Text_Gentleman_InsufficientTokens::
# 238 "data/maps/ShadyRoom/scripts.pory"
	.string "Look, I like you, but I don't work\n"
	.string "pro bono. You're short on credit.\p"
	.string "Come back when you can afford my rates.$"

ShadyRoom_Text_Gentleman_NoTokens::
# 244 "data/maps/ShadyRoom/scripts.pory"
	.string "Come now, let's not waste time.\n"
	.string "Your line of credit is tapped out.$"

ShadyRoom_Text_Gentleman_NatureCost::
# 249 "data/maps/ShadyRoom/scripts.pory"
	.string "A complete shift in Nature, is it?\n"
	.string "That will run you one unit of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_SameNature::
# 255 "data/maps/ShadyRoom/scripts.pory"
	.string "My friend, it already behaves like that.\n"
	.string "Don't play games with me. What do you really need?$"

ShadyRoom_Text_Gentleman_NatureChanged::
# 260 "data/maps/ShadyRoom/scripts.pory"
	.string "Pleasure doing business with you.\n"
	.string "Its mindset has been... optimized.$"

ShadyRoom_Text_Gentleman_HiddenAbilityCost::
# 265 "data/maps/ShadyRoom/scripts.pory"
	.string "Ah, looking for the premium stock?\n"
	.string "Unlocking a Hidden Ability isn't cheap.\p"
	.string "That will run you four units of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_AlreadyHiddenAbility::
# 272 "data/maps/ShadyRoom/scripts.pory"
	.string "My work is already done.\n"
	.string "This one's carrying the premium package.\p"
	.string "No sense charging you twice.$"

ShadyRoom_Text_Gentleman_HiddenAbilityConfirm::
# 278 "data/maps/ShadyRoom/scripts.pory"
	.string "I can unlock {STR_VAR_1} for this one.\n"
	.string "Shall I proceed?$"

ShadyRoom_Text_Gentleman_HAApplied::
# 283 "data/maps/ShadyRoom/scripts.pory"
	.string "There. The latent potential has been\n"
	.string "unlocked. Keep this between us, eh?$"

ShadyRoom_Text_Gentleman_RestoreAbilityOffer::
# 288 "data/maps/ShadyRoom/scripts.pory"
	.string "Want to put things back the way\n"
	.string "nature intended?\p"
	.string "I can restore its standard Ability.\n"
	.string "No charge. Do we have a deal?$"

ShadyRoom_Text_Gentleman_AlreadyRegularAbility::
# 295 "data/maps/ShadyRoom/scripts.pory"
	.string "Looks to me like this one's already\n"
	.string "running the factory settings.\p"
	.string "Nothing for me to do.$"

ShadyRoom_Text_Gentleman_RestoreAbilityConfirm::
# 301 "data/maps/ShadyRoom/scripts.pory"
	.string "I can restore {STR_VAR_1} for this one.\n"
	.string "Shall I proceed?$"

ShadyRoom_Text_Gentleman_AbilityRestored::
# 306 "data/maps/ShadyRoom/scripts.pory"
	.string "There. Back to the standard model.\n"
	.string "Sometimes less attention is the best disguise.$"
