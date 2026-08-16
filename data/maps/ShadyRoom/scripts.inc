ShadyRoom_MapScripts::
	.byte 0


ShadyRoom_EventScript_Gentleman::
# 6 "data/maps/ShadyRoom/scripts.pory"
	lock
# 7 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 9 "data/maps/ShadyRoom/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TOKEN_BALANCE
# 10 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 11 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_Greeting
ShadyRoom_EventScript_Gentleman_2:
# 13 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_ne ShadyRoom_EventScript_Gentleman_3
# 17 "data/maps/ShadyRoom/scripts.pory"
	closemessage
# 18 "data/maps/ShadyRoom/scripts.pory"
	release
	return

ShadyRoom_EventScript_Gentleman_3:
# 14 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_Menu
	goto ShadyRoom_EventScript_Gentleman_2


ShadyRoom_EventScript_Gentleman_Menu::
# 22 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_GENTLEMAN_SERVICES
# 24 "data/maps/ShadyRoom/scripts.pory"
	buffernumberstring STR_VAR_1, VAR_TOKEN_BALANCE
# 25 "data/maps/ShadyRoom/scripts.pory"
	message ShadyRoom_Text_Gentleman_Menu
# 26 "data/maps/ShadyRoom/scripts.pory"
	waitmessage
# 28 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 30 "data/maps/ShadyRoom/scripts.pory"
	switch VAR_RESULT
# 31 "data/maps/ShadyRoom/scripts.pory"
	case 0, ShadyRoom_EventScript_Gentleman_Menu_2
# 34 "data/maps/ShadyRoom/scripts.pory"
	case 1, ShadyRoom_EventScript_Gentleman_Menu_3
# 37 "data/maps/ShadyRoom/scripts.pory"
	case 2, ShadyRoom_EventScript_Gentleman_Menu_4
# 40 "data/maps/ShadyRoom/scripts.pory"
	case 3, ShadyRoom_EventScript_Gentleman_Menu_5
# 43 "data/maps/ShadyRoom/scripts.pory"
	case 4, ShadyRoom_EventScript_Gentleman_Menu_6
# 46 "data/maps/ShadyRoom/scripts.pory"
	case 5, ShadyRoom_EventScript_Gentleman_Menu_7
# 49 "data/maps/ShadyRoom/scripts.pory"
	case MULTI_B_PRESSED, ShadyRoom_EventScript_Gentleman_Menu_8
	return

ShadyRoom_EventScript_Gentleman_Menu_2:
# 32 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_ChangeNature
	return

ShadyRoom_EventScript_Gentleman_Menu_3:
# 35 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_HiddenAbility
	return

ShadyRoom_EventScript_Gentleman_Menu_4:
# 38 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_RegularAbility
	return

ShadyRoom_EventScript_Gentleman_Menu_5:
# 41 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_MaxIV
	return

ShadyRoom_EventScript_Gentleman_Menu_6:
# 44 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Change_HiddenPower
	return

ShadyRoom_EventScript_Gentleman_Menu_7:
# 47 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_Menu_8:
	return


ShadyRoom_EventScript_SelectPokemon::
# 55 "data/maps/ShadyRoom/scripts.pory"
	special ChoosePartyMon
# 57 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq ShadyRoom_EventScript_SelectPokemon_2
# 62 "data/maps/ShadyRoom/scripts.pory"
	special IsSelectedMonEgg
# 64 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_SelectPokemon_5
# 69 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, TRUE
	return

ShadyRoom_EventScript_SelectPokemon_2:
# 58 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, FALSE
	return

ShadyRoom_EventScript_SelectPokemon_5:
# 65 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, 2
	return


ShadyRoom_EventScript_Gentleman_CheckTokens::
# 74 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_TOKEN_BALANCE, 0
	goto_if_eq ShadyRoom_EventScript_Gentleman_CheckTokens_2
# 80 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_TOKEN_BALANCE, VAR_SERVICE_COST
	goto_if_lt ShadyRoom_EventScript_Gentleman_CheckTokens_5
# 86 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, TRUE
	return

ShadyRoom_EventScript_Gentleman_CheckTokens_2:
# 75 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NoTokens
# 76 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_CheckTokens_5:
# 81 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_InsufficientTokens
# 82 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, FALSE
	return


ShadyRoom_EventScript_Gentleman_ChangeNature::
# 91 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 2
# 92 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 93 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_2
# 93 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_2
# 97 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NatureCost, MSGBOX_YESNO
# 98 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_7
# 102 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 103 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_10
# 106 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_11
# 111 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 112 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_NATURE_PICKER
# 113 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 115 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_15
# 119 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8006
# 120 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 122 "data/maps/ShadyRoom/scripts.pory"
	special IsNatureSameAsCurrent
# 123 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_18
# 128 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_0x8005
# 129 "data/maps/ShadyRoom/scripts.pory"
	special SetHiddenNature
# 130 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 131 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NatureChanged
# 132 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_2:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_7:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_10:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_11:
# 107 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_15:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_18:
# 124 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_SameNature
	return


ShadyRoom_EventScript_Gentleman_HiddenAbility::
# 136 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 4
# 137 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 138 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_2
# 138 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_2
# 142 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HiddenAbilityCost, MSGBOX_YESNO
# 143 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_7
# 147 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 148 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_10
# 151 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_11
# 156 "data/maps/ShadyRoom/scripts.pory"
	special MonHasHiddenAbility
# 157 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_15
# 162 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HiddenAbilityConfirm, MSGBOX_YESNO
# 163 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_18
# 167 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8005, 2
# 168 "data/maps/ShadyRoom/scripts.pory"
	special SetAbilitySlot
# 170 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 171 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HAApplied
# 172 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_2:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_7:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_10:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_11:
# 152 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_15:
# 158 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AlreadyHiddenAbility
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_18:
	return


ShadyRoom_EventScript_Gentleman_RegularAbility::
# 176 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_RestoreAbilityOffer, MSGBOX_YESNO
# 177 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_2
# 181 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 182 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_5
# 185 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_6
# 190 "data/maps/ShadyRoom/scripts.pory"
	special MonHasHiddenAbility
# 191 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_10
# 196 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_RestoreAbilityConfirm, MSGBOX_YESNO
# 197 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_13
# 201 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 202 "data/maps/ShadyRoom/scripts.pory"
	special SetAbilitySlot
# 204 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AbilityRestored
# 205 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_2:
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_5:
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_6:
# 186 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_10:
# 192 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AlreadyRegularAbility
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_13:
	return


ShadyRoom_EventScript_Gentleman_MaxIV::
# 209 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 2
# 210 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 211 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_2
# 211 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_2
# 215 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVCost, MSGBOX_YESNO
# 216 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_7
# 220 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 221 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_10
# 224 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_11
# 229 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Gentleman_MaxIV_Text_0
# 230 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 232 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_IV_PICKER
# 233 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 234 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_15
# 238 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 240 "data/maps/ShadyRoom/scripts.pory"
	special BufferAndCheckIV
# 242 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_18
# 247 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVConfirm, MSGBOX_YESNO
# 248 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_21
# 252 "data/maps/ShadyRoom/scripts.pory"
	special ApplyIVMax
# 254 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 255 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVMaxed
# 256 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_MaxIV_2:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_7:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_10:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_11:
# 225 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_MaxIV_15:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_18:
# 243 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVAlreadyMax
	return

ShadyRoom_EventScript_Gentleman_MaxIV_21:
	return


ShadyRoom_EventScript_Change_HiddenPower::
# 260 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 1
# 261 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 262 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Change_HiddenPower_2
# 262 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Change_HiddenPower_2
# 266 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HPCost, MSGBOX_YESNO
# 267 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Change_HiddenPower_7
# 271 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 272 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Change_HiddenPower_10
# 275 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Change_HiddenPower_11
# 280 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Change_HiddenPower_Text_0
# 281 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 283 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_HIDDEN_POWER_PICKER
# 284 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 285 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Change_HiddenPower_15
# 289 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 291 "data/maps/ShadyRoom/scripts.pory"
	special BufferAndCheckHiddenPower
# 293 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Change_HiddenPower_18
# 298 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HPConfirm, MSGBOX_YESNO
# 299 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Change_HiddenPower_21
# 303 "data/maps/ShadyRoom/scripts.pory"
	special ApplyHiddenPower
# 305 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 306 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HPApplied
# 307 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Change_HiddenPower_2:
	return

ShadyRoom_EventScript_Change_HiddenPower_7:
	return

ShadyRoom_EventScript_Change_HiddenPower_10:
	return

ShadyRoom_EventScript_Change_HiddenPower_11:
# 276 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Change_HiddenPower_15:
	return

ShadyRoom_EventScript_Change_HiddenPower_18:
# 294 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HPSame
	return

ShadyRoom_EventScript_Change_HiddenPower_21:
	return


ShadyRoom_EventScript_Assistant::
# 311 "data/maps/ShadyRoom/scripts.pory"
	lock
# 312 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 314 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 315 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_Greeting
ShadyRoom_EventScript_Assistant_2:
# 317 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_ne ShadyRoom_EventScript_Assistant_3
# 321 "data/maps/ShadyRoom/scripts.pory"
	closemessage
# 322 "data/maps/ShadyRoom/scripts.pory"
	release
	return

ShadyRoom_EventScript_Assistant_3:
# 318 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_Menu
	goto ShadyRoom_EventScript_Assistant_2


ShadyRoom_EventScript_Assistant_Menu::
# 326 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_ASSISTANT_SERVICES
# 328 "data/maps/ShadyRoom/scripts.pory"
	message ShadyRoom_Text_Assistant_Menu
# 329 "data/maps/ShadyRoom/scripts.pory"
	waitmessage
# 331 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 333 "data/maps/ShadyRoom/scripts.pory"
	switch VAR_RESULT
# 334 "data/maps/ShadyRoom/scripts.pory"
	case 0, ShadyRoom_EventScript_Assistant_Menu_2
# 337 "data/maps/ShadyRoom/scripts.pory"
	case 1, ShadyRoom_EventScript_Assistant_Menu_3
# 340 "data/maps/ShadyRoom/scripts.pory"
	case 2, ShadyRoom_EventScript_Assistant_Menu_4
# 343 "data/maps/ShadyRoom/scripts.pory"
	case MULTI_B_PRESSED, ShadyRoom_EventScript_Assistant_Menu_5
	return

ShadyRoom_EventScript_Assistant_Menu_2:
# 335 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_SetStatus
	return

ShadyRoom_EventScript_Assistant_Menu_3:
# 338 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_SetDamage
	return

ShadyRoom_EventScript_Assistant_Menu_4:
# 341 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_Menu_5:
	return


ShadyRoom_EventScript_Assistant_SetStatus::
# 349 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusFlavor, MSGBOX_YESNO
# 350 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_2
# 354 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 355 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_5
# 358 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_6
# 363 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Assistant_SetStatus_Text_0
# 364 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 366 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_STATUS_PICKER
# 367 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 369 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_10
# 373 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 375 "data/maps/ShadyRoom/scripts.pory"
	special ApplyStatus
# 377 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 6
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_13
# 381 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusInflicted
ShadyRoom_EventScript_Assistant_SetStatus_12:
# 383 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_SetStatus_2:
	return

ShadyRoom_EventScript_Assistant_SetStatus_5:
	return

ShadyRoom_EventScript_Assistant_SetStatus_6:
# 359 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_CantSelectEgg
	return

ShadyRoom_EventScript_Assistant_SetStatus_10:
	return

ShadyRoom_EventScript_Assistant_SetStatus_13:
# 378 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusCured
	goto ShadyRoom_EventScript_Assistant_SetStatus_12


ShadyRoom_EventScript_Assistant_SetDamage::
# 387 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_DamageFlavor, MSGBOX_YESNO
# 388 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_2
# 392 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 393 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_5
# 396 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_6
# 401 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 403 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_DAMAGE_PICKER
# 404 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 406 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_10
# 410 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 412 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 7
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_13
ShadyRoom_EventScript_Assistant_SetDamage_12:
# 423 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 8
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_16
ShadyRoom_EventScript_Assistant_SetDamage_15:
# 431 "data/maps/ShadyRoom/scripts.pory"
	special SetPokemonToPercentHP
# 432 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_DamageApplied
# 433 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_SetDamage_2:
	return

ShadyRoom_EventScript_Assistant_SetDamage_5:
	return

ShadyRoom_EventScript_Assistant_SetDamage_6:
# 397 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_CantSelectEgg
	return

ShadyRoom_EventScript_Assistant_SetDamage_10:
	return

ShadyRoom_EventScript_Assistant_SetDamage_13:
# 413 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8009, 1
# 414 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x800A, 100
# 415 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x800B, 50
# 416 "data/maps/ShadyRoom/scripts.pory"
	special ShowNumberPicker
# 417 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_19
# 420 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
	goto ShadyRoom_EventScript_Assistant_SetDamage_12

ShadyRoom_EventScript_Assistant_SetDamage_16:
# 424 "data/maps/ShadyRoom/scripts.pory"
	special ShowCustomHPPicker
# 425 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_22
# 428 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
	goto ShadyRoom_EventScript_Assistant_SetDamage_15

ShadyRoom_EventScript_Assistant_SetDamage_19:
	return

ShadyRoom_EventScript_Assistant_SetDamage_22:
	return


ShadyRoom_EventScript_Merchant::
# 437 "data/maps/ShadyRoom/scripts.pory"
	lock
# 438 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 440 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 441 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_Greeting
ShadyRoom_EventScript_Merchant_2:
# 443 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_ne ShadyRoom_EventScript_Merchant_3
# 447 "data/maps/ShadyRoom/scripts.pory"
	closemessage
# 448 "data/maps/ShadyRoom/scripts.pory"
	release
	return

ShadyRoom_EventScript_Merchant_3:
# 444 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Merchant_Menu
	goto ShadyRoom_EventScript_Merchant_2


ShadyRoom_EventScript_Merchant_Menu::
# 452 "data/maps/ShadyRoom/scripts.pory"
	buffernumberstring STR_VAR_3, VAR_TOKEN_BALANCE
# 453 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_Menu
# 454 "data/maps/ShadyRoom/scripts.pory"
	waitmessage
# 456 "data/maps/ShadyRoom/scripts.pory"
	special MerchantMenu
# 457 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_2
# 461 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 462 "data/maps/ShadyRoom/scripts.pory"
	special GetMerchantItemInfo
# 464 "data/maps/ShadyRoom/scripts.pory"
	special CanAffordMerchantItem
# 465 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_5
# 470 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_PurchaseConfirm, MSGBOX_YESNO
# 471 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_8
# 475 "data/maps/ShadyRoom/scripts.pory"
	special PurchaseMerchantItem
# 476 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_PurchaseCommit
	return

ShadyRoom_EventScript_Merchant_Menu_2:
	return

ShadyRoom_EventScript_Merchant_Menu_5:
# 466 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_InsufficientFunds
	return

ShadyRoom_EventScript_Merchant_Menu_8:
	return


ShadyRoom_EventScript_Abra::
# 480 "data/maps/ShadyRoom/scripts.pory"
	lock
# 481 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 482 "data/maps/ShadyRoom/scripts.pory"
	addvar VAR_TOKEN_BALANCE, 1
# 483 "data/maps/ShadyRoom/scripts.pory"
	giveegg SPECIES_RAYQUAZA
# 484 "data/maps/ShadyRoom/scripts.pory"
	warp MAP_LITTLEROOT_TOWN, 0, 5, 5
# 485 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
# 486 "data/maps/ShadyRoom/scripts.pory"
	release
	return


ShadyRoom_EventScript_Gentleman_MaxIV_Text_0:
# 229 "data/maps/ShadyRoom/scripts.pory"
	.string "Which stat would you like to train?$"

ShadyRoom_EventScript_Change_HiddenPower_Text_0:
# 280 "data/maps/ShadyRoom/scripts.pory"
	.string "Which type would you like your\nHidden Power to be?$"

ShadyRoom_EventScript_Assistant_SetStatus_Text_0:
# 363 "data/maps/ShadyRoom/scripts.pory"
	.string "Which status would you like to inflict?$"

ShadyRoom_Text_Placeholder::
# 489 "data/maps/ShadyRoom/scripts.pory"
	.string "This feature hasn't been implemented yet.$"

ShadyRoom_Text_Gentleman_Greeting::
# 493 "data/maps/ShadyRoom/scripts.pory"
	.string "GENTLEMAN: Keep your voice down...\n"
	.string "Let's see. You have {STR_VAR_1} unit(s) of credit.\p"
	.string "I specialize in... off-the-record\n"
	.string "modifications. What do you need?$"

ShadyRoom_Text_Gentleman_Menu::
# 500 "data/maps/ShadyRoom/scripts.pory"
	.string "What can I do for you?\n"
	.string "You have {STR_VAR_1} unit(s) of credit.$"

ShadyRoom_Text_Gentleman_CantSelectEgg::
# 505 "data/maps/ShadyRoom/scripts.pory"
	.string "An Egg? Too early. Come back when\n"
	.string "there's something to work with.$"

ShadyRoom_Text_Gentleman_InsufficientTokens::
# 510 "data/maps/ShadyRoom/scripts.pory"
	.string "Look, I like you, but I don't work\n"
	.string "pro bono. You're short on credit.\p"
	.string "Come back when you can afford my rates.$"

ShadyRoom_Text_Gentleman_NoTokens::
# 516 "data/maps/ShadyRoom/scripts.pory"
	.string "Come now, let's not waste time.\n"
	.string "Your line of credit is tapped out.$"

ShadyRoom_Text_Gentleman_NatureCost::
# 521 "data/maps/ShadyRoom/scripts.pory"
	.string "A complete shift in Nature, is it?\n"
	.string "That will run you two units of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_SameNature::
# 527 "data/maps/ShadyRoom/scripts.pory"
	.string "My friend, it already behaves like that.\n"
	.string "No need to pay me for something that's\p"
	.string "already been done.$"

ShadyRoom_Text_Gentleman_NatureChanged::
# 533 "data/maps/ShadyRoom/scripts.pory"
	.string "Pleasure doing business with you.\n"
	.string "Its mindset has been... optimized.$"

ShadyRoom_Text_Gentleman_HiddenAbilityCost::
# 538 "data/maps/ShadyRoom/scripts.pory"
	.string "Ah, looking for the premium stock?\n"
	.string "Unlocking a Hidden Ability isn't cheap.\p"
	.string "That will run you four units of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_AlreadyHiddenAbility::
# 545 "data/maps/ShadyRoom/scripts.pory"
	.string "This one's already received the upgrade\n"
	.string "No sense charging you twice.$"

ShadyRoom_Text_Gentleman_HiddenAbilityConfirm::
# 550 "data/maps/ShadyRoom/scripts.pory"
	.string "I can unlock {STR_VAR_1} for this one.\n"
	.string "Shall I proceed?$"

ShadyRoom_Text_Gentleman_HAApplied::
# 555 "data/maps/ShadyRoom/scripts.pory"
	.string "There. The latent potential has been\n"
	.string "unlocked. Keep this between us, eh?$"

ShadyRoom_Text_Gentleman_RestoreAbilityOffer::
# 560 "data/maps/ShadyRoom/scripts.pory"
	.string "Want to put things back the way\n"
	.string "nature intended?\p"
	.string "I can restore its standard Ability.\n"
	.string "No charge. Do we have a deal?$"

ShadyRoom_Text_Gentleman_AlreadyRegularAbility::
# 567 "data/maps/ShadyRoom/scripts.pory"
	.string "Looks to me like this one's already\n"
	.string "running the factory settings.\p"
	.string "Nothing for me to do.$"

ShadyRoom_Text_Gentleman_RestoreAbilityConfirm::
# 573 "data/maps/ShadyRoom/scripts.pory"
	.string "I can restore {STR_VAR_1} for this one.\n"
	.string "Shall I proceed?$"

ShadyRoom_Text_Gentleman_AbilityRestored::
# 578 "data/maps/ShadyRoom/scripts.pory"
	.string "There. Back to the standard model.\n"
	.string "Sometimes less attention is the best disguise.$"

ShadyRoom_Text_Gentleman_IVCost::
# 583 "data/maps/ShadyRoom/scripts.pory"
	.string "Ah, maxing out potential? Radical changes\n"
	.string "carry a steeper premium.\p"
	.string "That will cost two units of credit.\n"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_IVAlreadyMax::
# 590 "data/maps/ShadyRoom/scripts.pory"
	.string "That stat is already at its peak.\n"
	.string "No point wasting credit on it.$"

ShadyRoom_Text_Gentleman_IVConfirm::
# 595 "data/maps/ShadyRoom/scripts.pory"
	.string "I can push its {STR_VAR_1} to the\n"
	.string "absolute limit. Shall I proceed?$"

ShadyRoom_Text_Gentleman_IVMaxed::
# 600 "data/maps/ShadyRoom/scripts.pory"
	.string "Perfect. You won't find a cleaner\n"
	.string "modification job anywhere else.$"

ShadyRoom_Text_Gentleman_HPCost::
# 605 "data/maps/ShadyRoom/scripts.pory"
	.string "Hidden Power, hm? A delicate \n"
	.string "adjustment.\p"
	.string "That will run you one unit of credit.\n"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_HPSame::
# 612 "data/maps/ShadyRoom/scripts.pory"
	.string "My friend, its Hidden Power is already\n"
	.string "{STR_VAR_1}-type.\p"
	.string "No sense paying me to change nothing.$"

ShadyRoom_Text_Gentleman_HPConfirm::
# 618 "data/maps/ShadyRoom/scripts.pory"
	.string "I can recalibrate its Hidden Power to\n"
	.string "{STR_VAR_1}-type. Shall I proceed?$"

ShadyRoom_Text_Gentleman_HPApplied::
# 623 "data/maps/ShadyRoom/scripts.pory"
	.string "There. Its Hidden Power has been\n"
	.string "recalibrated. Clean and discreet.$"

ShadyRoom_Text_Assistant_Greeting::
# 628 "data/maps/ShadyRoom/scripts.pory"
	.string "ASSISTANT: Please state your request.\n"
	.string "The Gentleman has approved my services.\p"
	.string "I will handle any procedures you require.$"

ShadyRoom_Text_Assistant_Menu::
# 634 "data/maps/ShadyRoom/scripts.pory"
	.string "Please specify your request.$"

ShadyRoom_Text_Assistant_CantSelectEgg::
# 638 "data/maps/ShadyRoom/scripts.pory"
	.string "The subject has not yet developed.\n"
	.string "Procedure cannot be performed.$"

ShadyRoom_Text_Assistant_StatusFlavor::
# 643 "data/maps/ShadyRoom/scripts.pory"
	.string "Status manipulation is a simple\n"
	.string "procedure when properly monitored.\p"
	.string "Shall we begin?$"

ShadyRoom_Text_Assistant_StatusCured::
# 649 "data/maps/ShadyRoom/scripts.pory"
	.string "Status condition removed.\n"
	.string "The subject has returned to normal.$"

ShadyRoom_Text_Assistant_StatusInflicted::
# 654 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "The requested condition has been applied.$"

ShadyRoom_Text_Assistant_DamageFlavor::
# 659 "data/maps/ShadyRoom/scripts.pory"
	.string "I will apply controlled damage.\n"
	.string "Minor discomfort is to be expected.\p"
	.string "Try not to move.$"

ShadyRoom_Text_Assistant_DamageApplied::
# 665 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "The subject is within acceptable limits.$"

ShadyRoom_Text_Merchant_Greeting::
# 670 "data/maps/ShadyRoom/scripts.pory"
	.string "Welcome. Please ignore the\n"
	.string "suspicious atmosphere.\p"
	.string "Everything here is completely\n"
	.string "legitimate.$"

ShadyRoom_Text_Merchant_Menu::
# 677 "data/maps/ShadyRoom/scripts.pory"
	.string "Take a look.\n"
	.string "If you don't see what you need,\p"
	.string "I probably don't have it.\p"
	.string "You have {STR_VAR_3} credit(s)$"

ShadyRoom_Text_Merchant_PurchaseConfirm::
# 684 "data/maps/ShadyRoom/scripts.pory"
	.string "{STR_VAR_2} for {STR_VAR_1} credit\n"
	.string "Is that all you need?$"

ShadyRoom_Text_Merchant_PurchaseCommit::
# 689 "data/maps/ShadyRoom/scripts.pory"
	.string "Purchase confirmed!$"

ShadyRoom_Text_Merchant_InsufficientFunds::
# 693 "data/maps/ShadyRoom/scripts.pory"
	.string "Come back when your credit catches\n"
	.string "up with your ambition.$"
