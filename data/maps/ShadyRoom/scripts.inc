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
	call ShadyRoom_EventScript_Gentleman_HiddenPower
	return

ShadyRoom_EventScript_Gentleman_Menu_7:
# 47 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_Menu_8:
	return


ShadyRoom_EventScript_Gentleman_CheckTokens::
# 55 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_TOKEN_BALANCE, 0
	goto_if_eq ShadyRoom_EventScript_Gentleman_CheckTokens_2
# 61 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_TOKEN_BALANCE, VAR_SERVICE_COST
	goto_if_lt ShadyRoom_EventScript_Gentleman_CheckTokens_5
# 67 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, TRUE
	return

ShadyRoom_EventScript_Gentleman_CheckTokens_2:
# 56 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NoTokens
# 57 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_CheckTokens_5:
# 62 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_InsufficientTokens
# 63 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, FALSE
	return


ShadyRoom_EventScript_Gentleman_ChangeNature::
# 72 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 2
# 73 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 74 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_2
# 74 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_2
# 78 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NatureCost, MSGBOX_YESNO
# 79 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_7
# 83 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 84 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_10
# 87 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_11
# 92 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 93 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_NATURE_PICKER
# 94 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 96 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_15
# 100 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8006
# 101 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 103 "data/maps/ShadyRoom/scripts.pory"
	special IsNatureSameAsCurrent
# 104 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_18
# 109 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_0x8005
# 110 "data/maps/ShadyRoom/scripts.pory"
	special SetHiddenNature
# 111 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 112 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NatureChanged
# 113 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_2:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_7:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_10:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_11:
# 88 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_15:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_18:
# 105 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_SameNature
	return


ShadyRoom_EventScript_Gentleman_HiddenAbility::
# 117 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 4
# 118 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 119 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_2
# 119 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_2
# 123 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HiddenAbilityCost, MSGBOX_YESNO
# 124 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_7
# 128 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 129 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_10
# 132 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_11
# 137 "data/maps/ShadyRoom/scripts.pory"
	special MonHasHiddenAbility
# 138 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_15
# 143 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HiddenAbilityConfirm, MSGBOX_YESNO
# 144 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_18
# 148 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8005, 2
# 149 "data/maps/ShadyRoom/scripts.pory"
	special SetAbilitySlot
# 151 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 152 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HAApplied
# 153 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_2:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_7:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_10:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_11:
# 133 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_15:
# 139 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AlreadyHiddenAbility
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_18:
	return


ShadyRoom_EventScript_Gentleman_RegularAbility::
# 157 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_RestoreAbilityOffer, MSGBOX_YESNO
# 158 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_2
# 162 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 163 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_5
# 166 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_6
# 171 "data/maps/ShadyRoom/scripts.pory"
	special MonHasHiddenAbility
# 172 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_10
# 177 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_RestoreAbilityConfirm, MSGBOX_YESNO
# 178 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_13
# 182 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 183 "data/maps/ShadyRoom/scripts.pory"
	special SetAbilitySlot
# 185 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AbilityRestored
# 186 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_2:
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_5:
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_6:
# 167 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_10:
# 173 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AlreadyRegularAbility
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_13:
	return


ShadyRoom_EventScript_Gentleman_MaxIV::
# 190 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 2
# 191 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 192 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_2
# 192 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_2
# 196 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVCost, MSGBOX_YESNO
# 197 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_7
# 201 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 202 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_10
# 205 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_11
# 210 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Gentleman_MaxIV_Text_0
# 211 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 213 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_IV_PICKER
# 214 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 215 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_15
# 219 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 221 "data/maps/ShadyRoom/scripts.pory"
	special BufferAndCheckIV
# 223 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_18
# 228 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVConfirm, MSGBOX_YESNO
# 229 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_21
# 233 "data/maps/ShadyRoom/scripts.pory"
	special ApplyIVMax
# 235 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 236 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVMaxed
# 237 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_MaxIV_2:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_7:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_10:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_11:
# 206 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_MaxIV_15:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_18:
# 224 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVAlreadyMax
	return

ShadyRoom_EventScript_Gentleman_MaxIV_21:
	return


ShadyRoom_EventScript_Gentleman_HiddenPower::
# 241 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 1
# 242 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 243 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenPower_2
# 243 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenPower_2
# 247 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HPCost, MSGBOX_YESNO
# 248 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenPower_7
# 252 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 253 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenPower_10
# 256 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenPower_11
# 261 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Gentleman_HiddenPower_Text_0
# 262 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 264 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_HIDDEN_POWER_PICKER
# 265 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 266 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenPower_15
# 270 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 272 "data/maps/ShadyRoom/scripts.pory"
	special BufferAndCheckHiddenPower
# 274 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenPower_18
# 279 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HPConfirm, MSGBOX_YESNO
# 280 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenPower_21
# 284 "data/maps/ShadyRoom/scripts.pory"
	special ApplyHiddenPower
# 286 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 287 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HPApplied
# 288 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_HiddenPower_2:
	return

ShadyRoom_EventScript_Gentleman_HiddenPower_7:
	return

ShadyRoom_EventScript_Gentleman_HiddenPower_10:
	return

ShadyRoom_EventScript_Gentleman_HiddenPower_11:
# 257 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_HiddenPower_15:
	return

ShadyRoom_EventScript_Gentleman_HiddenPower_18:
# 275 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HPSame
	return

ShadyRoom_EventScript_Gentleman_HiddenPower_21:
	return


ShadyRoom_EventScript_Assistant::
# 292 "data/maps/ShadyRoom/scripts.pory"
	lock
# 293 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 295 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 296 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_Greeting
ShadyRoom_EventScript_Assistant_2:
# 298 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_ne ShadyRoom_EventScript_Assistant_3
# 302 "data/maps/ShadyRoom/scripts.pory"
	closemessage
# 303 "data/maps/ShadyRoom/scripts.pory"
	release
	return

ShadyRoom_EventScript_Assistant_3:
# 299 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_Menu
	goto ShadyRoom_EventScript_Assistant_2


ShadyRoom_EventScript_Assistant_Menu::
# 307 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_ASSISTANT_SERVICES
# 309 "data/maps/ShadyRoom/scripts.pory"
	message ShadyRoom_Text_Assistant_Menu
# 310 "data/maps/ShadyRoom/scripts.pory"
	waitmessage
# 312 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 314 "data/maps/ShadyRoom/scripts.pory"
	switch VAR_RESULT
# 315 "data/maps/ShadyRoom/scripts.pory"
	case 0, ShadyRoom_EventScript_Assistant_Menu_2
# 318 "data/maps/ShadyRoom/scripts.pory"
	case 1, ShadyRoom_EventScript_Assistant_Menu_3
# 321 "data/maps/ShadyRoom/scripts.pory"
	case 2, ShadyRoom_EventScript_Assistant_Menu_4
# 324 "data/maps/ShadyRoom/scripts.pory"
	case 3, ShadyRoom_EventScript_Assistant_Menu_5
# 327 "data/maps/ShadyRoom/scripts.pory"
	case 4, ShadyRoom_EventScript_Assistant_Menu_6
# 330 "data/maps/ShadyRoom/scripts.pory"
	case 5, ShadyRoom_EventScript_Assistant_Menu_7
# 333 "data/maps/ShadyRoom/scripts.pory"
	case MULTI_B_PRESSED, ShadyRoom_EventScript_Assistant_Menu_8
	return

ShadyRoom_EventScript_Assistant_Menu_2:
# 316 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_SetStatus
	return

ShadyRoom_EventScript_Assistant_Menu_3:
# 319 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_SetDamage
	return

ShadyRoom_EventScript_Assistant_Menu_4:
# 322 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_EdgePartyXP
	return

ShadyRoom_EventScript_Assistant_Menu_5:
# 325 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_EdgePokemonXP
	return

ShadyRoom_EventScript_Assistant_Menu_6:
# 328 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_ToggleShiny
	return

ShadyRoom_EventScript_Assistant_Menu_7:
# 331 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_Menu_8:
	return


ShadyRoom_EventScript_Assistant_SetStatus::
# 339 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusFlavor, MSGBOX_YESNO
# 340 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_2
# 344 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 345 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_5
# 348 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_6
# 353 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Assistant_SetStatus_Text_0
# 354 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 356 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_STATUS_PICKER
# 357 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 359 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_10
# 363 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 365 "data/maps/ShadyRoom/scripts.pory"
	special ApplyStatus
# 367 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 6
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_13
# 371 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusInflicted
ShadyRoom_EventScript_Assistant_SetStatus_12:
# 373 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_SetStatus_2:
	return

ShadyRoom_EventScript_Assistant_SetStatus_5:
	return

ShadyRoom_EventScript_Assistant_SetStatus_6:
# 349 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_CantSelectEgg
	return

ShadyRoom_EventScript_Assistant_SetStatus_10:
	return

ShadyRoom_EventScript_Assistant_SetStatus_13:
# 368 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusCured
	goto ShadyRoom_EventScript_Assistant_SetStatus_12


ShadyRoom_EventScript_Assistant_SetDamage::
# 377 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_DamageFlavor, MSGBOX_YESNO
# 378 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_2
# 382 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 383 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_5
# 386 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_6
# 391 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 393 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_DAMAGE_PICKER
# 394 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 396 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_10
# 400 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 402 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 7
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_13
ShadyRoom_EventScript_Assistant_SetDamage_12:
# 413 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 8
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_16
ShadyRoom_EventScript_Assistant_SetDamage_15:
# 421 "data/maps/ShadyRoom/scripts.pory"
	special SetPokemonToPercentHP
# 422 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_DamageApplied
# 423 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_SetDamage_2:
	return

ShadyRoom_EventScript_Assistant_SetDamage_5:
	return

ShadyRoom_EventScript_Assistant_SetDamage_6:
# 387 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_CantSelectEgg
	return

ShadyRoom_EventScript_Assistant_SetDamage_10:
	return

ShadyRoom_EventScript_Assistant_SetDamage_13:
# 403 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8009, 1
# 404 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x800A, 100
# 405 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x800B, 50
# 406 "data/maps/ShadyRoom/scripts.pory"
	special ShowNumberPicker
# 407 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_19
# 410 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
	goto ShadyRoom_EventScript_Assistant_SetDamage_12

ShadyRoom_EventScript_Assistant_SetDamage_16:
# 414 "data/maps/ShadyRoom/scripts.pory"
	special ShowCustomHPPicker
# 415 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_22
# 418 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
	goto ShadyRoom_EventScript_Assistant_SetDamage_15

ShadyRoom_EventScript_Assistant_SetDamage_19:
	return

ShadyRoom_EventScript_Assistant_SetDamage_22:
	return


ShadyRoom_EventScript_Assistant_EdgePartyXP::
# 427 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_EdgePartyXPFlavorConfirm, MSGBOX_YESNO
# 428 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_EdgePartyXP_2
# 432 "data/maps/ShadyRoom/scripts.pory"
	special SetPartytoEdgeXP
# 433 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_EdgePartyXPApplied
# 434 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_EdgePartyXP_2:
	return


ShadyRoom_EventScript_Assistant_EdgePokemonXP::
# 438 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_EdgeXPFlavor, MSGBOX_YESNO
# 439 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_EdgePokemonXP_2
# 443 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 444 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_EdgePokemonXP_5
# 447 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Assistant_EdgePokemonXP_6
# 452 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 454 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_EdgeXPConfirm, MSGBOX_YESNO
# 455 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_EdgePokemonXP_10
# 459 "data/maps/ShadyRoom/scripts.pory"
	special SetPokemontoEdgeXP
# 460 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_EdgeXPApplied
# 461 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_EdgePokemonXP_2:
	return

ShadyRoom_EventScript_Assistant_EdgePokemonXP_5:
	return

ShadyRoom_EventScript_Assistant_EdgePokemonXP_6:
# 448 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_CantSelectEgg
	return

ShadyRoom_EventScript_Assistant_EdgePokemonXP_10:
	return


ShadyRoom_EventScript_Assistant_ToggleShiny::
# 465 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_ToggleShinyFlavor, MSGBOX_YESNO
# 466 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_ToggleShiny_2
# 470 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 471 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_ToggleShiny_5
# 474 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Assistant_ToggleShiny_6
# 479 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 481 "data/maps/ShadyRoom/scripts.pory"
	special CheckPokemonShiny
# 483 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_ToggleShiny_10
# 492 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_UnshinyConfirm, MSGBOX_YESNO
# 493 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_ToggleShiny_17
# 496 "data/maps/ShadyRoom/scripts.pory"
	special TogglePokemonShiny
# 497 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_UnshinyApplied
ShadyRoom_EventScript_Assistant_ToggleShiny_9:
# 500 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_ToggleShiny_2:
	return

ShadyRoom_EventScript_Assistant_ToggleShiny_5:
	return

ShadyRoom_EventScript_Assistant_ToggleShiny_6:
# 475 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_CantSelectEgg
	return

ShadyRoom_EventScript_Assistant_ToggleShiny_10:
# 484 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_ShinyConfirm, MSGBOX_YESNO
# 485 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_ToggleShiny_14
# 488 "data/maps/ShadyRoom/scripts.pory"
	special TogglePokemonShiny
# 489 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_ShinyApplied
	goto ShadyRoom_EventScript_Assistant_ToggleShiny_9

ShadyRoom_EventScript_Assistant_ToggleShiny_14:
	return

ShadyRoom_EventScript_Assistant_ToggleShiny_17:
	return


ShadyRoom_EventScript_Merchant::
# 504 "data/maps/ShadyRoom/scripts.pory"
	lock
# 505 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 507 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 508 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_Greeting
ShadyRoom_EventScript_Merchant_2:
# 510 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_ne ShadyRoom_EventScript_Merchant_3
# 514 "data/maps/ShadyRoom/scripts.pory"
	closemessage
# 515 "data/maps/ShadyRoom/scripts.pory"
	release
	return

ShadyRoom_EventScript_Merchant_3:
# 511 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Merchant_Menu
	goto ShadyRoom_EventScript_Merchant_2


ShadyRoom_EventScript_Merchant_Menu::
# 519 "data/maps/ShadyRoom/scripts.pory"
	buffernumberstring STR_VAR_3, VAR_TOKEN_BALANCE
# 520 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_Menu
# 521 "data/maps/ShadyRoom/scripts.pory"
	waitmessage
# 523 "data/maps/ShadyRoom/scripts.pory"
	special MerchantMenu
# 524 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_2
# 528 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 529 "data/maps/ShadyRoom/scripts.pory"
	special GetMerchantItemInfo
# 531 "data/maps/ShadyRoom/scripts.pory"
	special CanAffordMerchantItem
# 532 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_5
# 537 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_PurchaseConfirm, MSGBOX_YESNO
# 538 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_8
# 542 "data/maps/ShadyRoom/scripts.pory"
	special PurchaseMerchantItem
# 543 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_PurchaseCommit
	return

ShadyRoom_EventScript_Merchant_Menu_2:
	return

ShadyRoom_EventScript_Merchant_Menu_5:
# 533 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_InsufficientFunds
	return

ShadyRoom_EventScript_Merchant_Menu_8:
	return


ShadyRoom_EventScript_Abra::
# 547 "data/maps/ShadyRoom/scripts.pory"
	lock
# 548 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 549 "data/maps/ShadyRoom/scripts.pory"
	addvar VAR_TOKEN_BALANCE, 1
# 550 "data/maps/ShadyRoom/scripts.pory"
	call GlobalScript_AbraReturn
	return


ShadyRoom_EventScript_SelectPokemon::
# 554 "data/maps/ShadyRoom/scripts.pory"
	special ChoosePartyMon
# 556 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq ShadyRoom_EventScript_SelectPokemon_2
# 561 "data/maps/ShadyRoom/scripts.pory"
	special IsSelectedMonEgg
# 563 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_SelectPokemon_5
# 568 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, TRUE
	return

ShadyRoom_EventScript_SelectPokemon_2:
# 557 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, FALSE
	return

ShadyRoom_EventScript_SelectPokemon_5:
# 564 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, 2
	return


ShadyRoom_EventScript_Gentleman_MaxIV_Text_0:
# 210 "data/maps/ShadyRoom/scripts.pory"
	.string "Which stat would you like to train?$"

ShadyRoom_EventScript_Gentleman_HiddenPower_Text_0:
# 261 "data/maps/ShadyRoom/scripts.pory"
	.string "Which type would you like your\nHidden Power to be?$"

ShadyRoom_EventScript_Assistant_SetStatus_Text_0:
# 353 "data/maps/ShadyRoom/scripts.pory"
	.string "Which status would you like to inflict?$"

ShadyRoom_Text_Placeholder::
# 572 "data/maps/ShadyRoom/scripts.pory"
	.string "This feature hasn't been implemented yet.$"

ShadyRoom_Text_Gentleman_Greeting::
# 576 "data/maps/ShadyRoom/scripts.pory"
	.string "GENTLEMAN: Keep your voice down...\n"
	.string "Let's see. You have {STR_VAR_1} unit(s) of credit.\p"
	.string "I specialize in... off-the-record\n"
	.string "modifications. What do you need?$"

ShadyRoom_Text_Gentleman_Menu::
# 583 "data/maps/ShadyRoom/scripts.pory"
	.string "What can I do for you?\n"
	.string "You have {STR_VAR_1} unit(s) of credit.$"

ShadyRoom_Text_Gentleman_CantSelectEgg::
# 588 "data/maps/ShadyRoom/scripts.pory"
	.string "An Egg? Too early. Come back when\n"
	.string "there's something to work with.$"

ShadyRoom_Text_Gentleman_InsufficientTokens::
# 593 "data/maps/ShadyRoom/scripts.pory"
	.string "Look, I like you, but I don't work\n"
	.string "pro bono. You're short on credit.\p"
	.string "Come back when you can afford my rates.$"

ShadyRoom_Text_Gentleman_NoTokens::
# 599 "data/maps/ShadyRoom/scripts.pory"
	.string "Come now, let's not waste time.\n"
	.string "Your line of credit is tapped out.$"

ShadyRoom_Text_Gentleman_NatureCost::
# 604 "data/maps/ShadyRoom/scripts.pory"
	.string "A complete shift in Nature, is it?\n"
	.string "That will run you two units of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_SameNature::
# 610 "data/maps/ShadyRoom/scripts.pory"
	.string "My friend, it already behaves like that.\n"
	.string "No need to pay me for something that's\p"
	.string "already been done.$"

ShadyRoom_Text_Gentleman_NatureChanged::
# 616 "data/maps/ShadyRoom/scripts.pory"
	.string "Pleasure doing business with you.\n"
	.string "Its mindset has been... optimized.$"

ShadyRoom_Text_Gentleman_HiddenAbilityCost::
# 621 "data/maps/ShadyRoom/scripts.pory"
	.string "Ah, looking for the premium stock?\n"
	.string "Unlocking a Hidden Ability isn't cheap.\p"
	.string "That will run you four units of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_AlreadyHiddenAbility::
# 628 "data/maps/ShadyRoom/scripts.pory"
	.string "This one's already received the upgrade\n"
	.string "No sense charging you twice.$"

ShadyRoom_Text_Gentleman_HiddenAbilityConfirm::
# 633 "data/maps/ShadyRoom/scripts.pory"
	.string "I can unlock {STR_VAR_1} for this one.\n"
	.string "Shall I proceed?$"

ShadyRoom_Text_Gentleman_HAApplied::
# 638 "data/maps/ShadyRoom/scripts.pory"
	.string "There. The latent potential has been\n"
	.string "unlocked. Keep this between us, eh?$"

ShadyRoom_Text_Gentleman_RestoreAbilityOffer::
# 643 "data/maps/ShadyRoom/scripts.pory"
	.string "Want to put things back the way\n"
	.string "nature intended?\p"
	.string "I can restore its standard Ability.\n"
	.string "No charge. Do we have a deal?$"

ShadyRoom_Text_Gentleman_AlreadyRegularAbility::
# 650 "data/maps/ShadyRoom/scripts.pory"
	.string "Looks to me like this one's already\n"
	.string "running the factory settings.\p"
	.string "Nothing for me to do.$"

ShadyRoom_Text_Gentleman_RestoreAbilityConfirm::
# 656 "data/maps/ShadyRoom/scripts.pory"
	.string "I can restore {STR_VAR_1} for this one.\n"
	.string "Shall I proceed?$"

ShadyRoom_Text_Gentleman_AbilityRestored::
# 661 "data/maps/ShadyRoom/scripts.pory"
	.string "There. Back to the standard model.\n"
	.string "Sometimes less attention is the best disguise.$"

ShadyRoom_Text_Gentleman_IVCost::
# 666 "data/maps/ShadyRoom/scripts.pory"
	.string "Ah, maxing out potential? Radical changes\n"
	.string "carry a steeper premium.\p"
	.string "That will cost two units of credit.\n"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_IVAlreadyMax::
# 673 "data/maps/ShadyRoom/scripts.pory"
	.string "That stat is already at its peak.\n"
	.string "No point wasting credit on it.$"

ShadyRoom_Text_Gentleman_IVConfirm::
# 678 "data/maps/ShadyRoom/scripts.pory"
	.string "I can push its {STR_VAR_1} to the\n"
	.string "absolute limit. Shall I proceed?$"

ShadyRoom_Text_Gentleman_IVMaxed::
# 683 "data/maps/ShadyRoom/scripts.pory"
	.string "Perfect. You won't find a cleaner\n"
	.string "modification job anywhere else.$"

ShadyRoom_Text_Gentleman_HPCost::
# 688 "data/maps/ShadyRoom/scripts.pory"
	.string "Hidden Power, hm? A delicate \n"
	.string "adjustment.\p"
	.string "That will run you one unit of credit.\n"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_HPSame::
# 695 "data/maps/ShadyRoom/scripts.pory"
	.string "My friend, its Hidden Power is already\n"
	.string "{STR_VAR_1}-type.\p"
	.string "No sense paying me to change nothing.$"

ShadyRoom_Text_Gentleman_HPConfirm::
# 701 "data/maps/ShadyRoom/scripts.pory"
	.string "I can recalibrate its Hidden Power to\n"
	.string "{STR_VAR_1}-type. Shall I proceed?$"

ShadyRoom_Text_Gentleman_HPApplied::
# 706 "data/maps/ShadyRoom/scripts.pory"
	.string "There. Its Hidden Power has been\n"
	.string "recalibrated. Clean and discreet.$"

ShadyRoom_Text_Assistant_Greeting::
# 711 "data/maps/ShadyRoom/scripts.pory"
	.string "ASSISTANT: Please state your request.\n"
	.string "The Gentleman has approved my services.\p"
	.string "I will handle any procedures you require.$"

ShadyRoom_Text_Assistant_Menu::
# 717 "data/maps/ShadyRoom/scripts.pory"
	.string "Please specify your request.$"

ShadyRoom_Text_Assistant_CantSelectEgg::
# 721 "data/maps/ShadyRoom/scripts.pory"
	.string "The subject has not yet developed.\n"
	.string "Procedure cannot be performed.$"

ShadyRoom_Text_Assistant_StatusFlavor::
# 726 "data/maps/ShadyRoom/scripts.pory"
	.string "Status manipulation is a simple\n"
	.string "procedure when properly monitored.\p"
	.string "Shall we begin?$"

ShadyRoom_Text_Assistant_StatusCured::
# 732 "data/maps/ShadyRoom/scripts.pory"
	.string "Status condition removed.\n"
	.string "The subject has returned to normal.$"

ShadyRoom_Text_Assistant_StatusInflicted::
# 737 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "The requested condition has been applied.$"

ShadyRoom_Text_Assistant_DamageFlavor::
# 742 "data/maps/ShadyRoom/scripts.pory"
	.string "I will apply controlled damage.\n"
	.string "Minor discomfort is to be expected.\p"
	.string "Try not to move.$"

ShadyRoom_Text_Assistant_DamageApplied::
# 748 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "The subject is within acceptable limits.$"

ShadyRoom_Text_Assistant_EdgePartyXPFlavorConfirm::
# 753 "data/maps/ShadyRoom/scripts.pory"
	.string "Optimizing experience thresholds.\n"
	.string "All viable subjects will be adjusted to\l"
	.string "one unit below growth transition.\p"
	.string "Shall I execute the full party calibration?$"

ShadyRoom_Text_Assistant_EdgePartyXPApplied::
# 760 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "Entire party calibrated to maximum\l"
	.string "sub-level threshold.$"

ShadyRoom_Text_Assistant_EdgeXPFlavor::
# 766 "data/maps/ShadyRoom/scripts.pory"
	.string "Targeted experience optimization.\n"
	.string "Please select the single subject\l"
	.string "requiring threshold adjustment.$"

ShadyRoom_Text_Assistant_EdgeXPConfirm::
# 772 "data/maps/ShadyRoom/scripts.pory"
	.string "Selected subject will be advanced to\n"
	.string "one unit below growth transition.\p"
	.string "Confirm targeted calibration?$"

ShadyRoom_Text_Assistant_EdgeXPApplied::
# 778 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "Subject threshold locked at terminal value.$"

ShadyRoom_Text_Assistant_ToggleShinyFlavor::
# 784 "data/maps/ShadyRoom/scripts.pory"
	.string "Pigmentation manipulation protocol.\n"
	.string "Please select the subject for\l"
	.string "coloration inversion.$"

ShadyRoom_Text_Assistant_ShinyConfirm::
# 790 "data/maps/ShadyRoom/scripts.pory"
	.string "The subject exhibits baseline coloration.\n"
	.string "Proceed with rare pigmentation activation?$"

ShadyRoom_Text_Assistant_ShinyApplied::
# 795 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "Dermal refraction markers adjusted.$"

ShadyRoom_Text_Assistant_UnshinyConfirm::
# 800 "data/maps/ShadyRoom/scripts.pory"
	.string "The subject exhibits anomalous coloration.\n"
	.string "Revert to standard baseline aesthetics?$"

ShadyRoom_Text_Assistant_UnshinyApplied::
# 805 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "Pigmentation reverted to default specs.$"

ShadyRoom_Text_Merchant_Greeting::
# 811 "data/maps/ShadyRoom/scripts.pory"
	.string "Welcome. Please ignore the\n"
	.string "suspicious atmosphere.\p"
	.string "Everything here is completely\n"
	.string "legitimate.$"

ShadyRoom_Text_Merchant_Menu::
# 818 "data/maps/ShadyRoom/scripts.pory"
	.string "Take a look.\n"
	.string "If you don't see what you need,\p"
	.string "I probably don't have it.\p"
	.string "You have {STR_VAR_3} credit(s)$"

ShadyRoom_Text_Merchant_PurchaseConfirm::
# 825 "data/maps/ShadyRoom/scripts.pory"
	.string "{STR_VAR_2} for {STR_VAR_1} credit\n"
	.string "Is that all you need?$"

ShadyRoom_Text_Merchant_PurchaseCommit::
# 830 "data/maps/ShadyRoom/scripts.pory"
	.string "Purchase confirmed!$"

ShadyRoom_Text_Merchant_InsufficientFunds::
# 834 "data/maps/ShadyRoom/scripts.pory"
	.string "Come back when your credit catches\n"
	.string "up with your ambition.$"
