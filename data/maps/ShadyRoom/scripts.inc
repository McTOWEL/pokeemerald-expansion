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
	case MULTI_B_PRESSED, ShadyRoom_EventScript_Gentleman_Menu_7
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
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_Menu_7:
	return


ShadyRoom_EventScript_SelectPokemon::
# 52 "data/maps/ShadyRoom/scripts.pory"
	special ChoosePartyMon
# 54 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8004, PARTY_NOTHING_CHOSEN
	goto_if_eq ShadyRoom_EventScript_SelectPokemon_2
# 59 "data/maps/ShadyRoom/scripts.pory"
	special IsSelectedMonEgg
# 61 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_SelectPokemon_5
# 66 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, TRUE
	return

ShadyRoom_EventScript_SelectPokemon_2:
# 55 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, FALSE
	return

ShadyRoom_EventScript_SelectPokemon_5:
# 62 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, 2
	return


ShadyRoom_EventScript_Gentleman_CheckTokens::
# 71 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_TOKEN_BALANCE, 0
	goto_if_eq ShadyRoom_EventScript_Gentleman_CheckTokens_2
# 77 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_TOKEN_BALANCE, VAR_SERVICE_COST
	goto_if_lt ShadyRoom_EventScript_Gentleman_CheckTokens_5
# 83 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, TRUE
	return

ShadyRoom_EventScript_Gentleman_CheckTokens_2:
# 72 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NoTokens
# 73 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_CheckTokens_5:
# 78 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_InsufficientTokens
# 79 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_SELECTION_OK, FALSE
	return


ShadyRoom_EventScript_Gentleman_ChangeNature::
# 88 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 2
# 89 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 90 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_2
# 90 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_2
# 94 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NatureCost, MSGBOX_YESNO
# 95 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_7
# 99 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 100 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_10
# 103 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_11
# 108 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 109 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_NATURE_PICKER
# 110 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 112 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_15
# 116 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_0x8006
# 117 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 119 "data/maps/ShadyRoom/scripts.pory"
	special IsNatureSameAsCurrent
# 120 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_Gentleman_ChangeNature_18
# 125 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_RESULT, VAR_0x8005
# 126 "data/maps/ShadyRoom/scripts.pory"
	special SetHiddenNature
# 127 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 128 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_NatureChanged
# 129 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_2:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_7:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_10:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_11:
# 104 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_15:
	return

ShadyRoom_EventScript_Gentleman_ChangeNature_18:
# 121 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_SameNature
	return


ShadyRoom_EventScript_Gentleman_HiddenAbility::
# 133 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 4
# 134 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 135 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_2
# 135 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_2
# 139 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HiddenAbilityCost, MSGBOX_YESNO
# 140 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_7
# 144 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 145 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_10
# 148 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_11
# 153 "data/maps/ShadyRoom/scripts.pory"
	special MonHasHiddenAbility
# 154 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, TRUE
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_15
# 159 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HiddenAbilityConfirm, MSGBOX_YESNO
# 160 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_HiddenAbility_18
# 164 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8005, 2
# 165 "data/maps/ShadyRoom/scripts.pory"
	special SetAbilitySlot
# 167 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 168 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_HAApplied
# 169 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_2:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_7:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_10:
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_11:
# 149 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_15:
# 155 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AlreadyHiddenAbility
	return

ShadyRoom_EventScript_Gentleman_HiddenAbility_18:
	return


ShadyRoom_EventScript_Gentleman_RegularAbility::
# 173 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_RestoreAbilityOffer, MSGBOX_YESNO
# 174 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_2
# 178 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 179 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_5
# 182 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_6
# 187 "data/maps/ShadyRoom/scripts.pory"
	special MonHasHiddenAbility
# 188 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_10
# 193 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_RestoreAbilityConfirm, MSGBOX_YESNO
# 194 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_RegularAbility_13
# 198 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8005, 0
# 199 "data/maps/ShadyRoom/scripts.pory"
	special SetAbilitySlot
# 201 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AbilityRestored
# 202 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_2:
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_5:
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_6:
# 183 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_10:
# 189 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_AlreadyRegularAbility
	return

ShadyRoom_EventScript_Gentleman_RegularAbility_13:
	return


ShadyRoom_EventScript_Gentleman_MaxIV::
# 206 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_SERVICE_COST, 2
# 207 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 208 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_2
# 208 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_2
# 212 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVCost, MSGBOX_YESNO
# 213 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_7
# 217 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 218 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_10
# 221 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_11
# 226 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Gentleman_MaxIV_Text_0
# 227 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 229 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_IV_PICKER
# 230 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 231 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_15
# 235 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 237 "data/maps/ShadyRoom/scripts.pory"
	special BufferAndCheckIV
# 239 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_18
# 244 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVConfirm, MSGBOX_YESNO
# 245 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_21
# 249 "data/maps/ShadyRoom/scripts.pory"
	special ApplyIVMax
# 251 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 252 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVMaxed
# 253 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_MaxIV_2:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_7:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_10:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_11:
# 222 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_CantSelectEgg
	return

ShadyRoom_EventScript_Gentleman_MaxIV_15:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_18:
# 240 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVAlreadyMax
	return

ShadyRoom_EventScript_Gentleman_MaxIV_21:
	return


ShadyRoom_EventScript_Assistant::
# 257 "data/maps/ShadyRoom/scripts.pory"
	lock
# 258 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 260 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 261 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_Greeting
ShadyRoom_EventScript_Assistant_2:
# 263 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_ne ShadyRoom_EventScript_Assistant_3
# 267 "data/maps/ShadyRoom/scripts.pory"
	closemessage
# 268 "data/maps/ShadyRoom/scripts.pory"
	release
	return

ShadyRoom_EventScript_Assistant_3:
# 264 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_Menu
	goto ShadyRoom_EventScript_Assistant_2


ShadyRoom_EventScript_Assistant_Menu::
# 272 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_ASSISTANT_SERVICES
# 274 "data/maps/ShadyRoom/scripts.pory"
	message ShadyRoom_Text_Assistant_Menu
# 275 "data/maps/ShadyRoom/scripts.pory"
	waitmessage
# 277 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 279 "data/maps/ShadyRoom/scripts.pory"
	switch VAR_RESULT
# 280 "data/maps/ShadyRoom/scripts.pory"
	case 0, ShadyRoom_EventScript_Assistant_Menu_2
# 283 "data/maps/ShadyRoom/scripts.pory"
	case 1, ShadyRoom_EventScript_Assistant_Menu_3
# 286 "data/maps/ShadyRoom/scripts.pory"
	case 2, ShadyRoom_EventScript_Assistant_Menu_4
# 289 "data/maps/ShadyRoom/scripts.pory"
	case MULTI_B_PRESSED, ShadyRoom_EventScript_Assistant_Menu_5
	return

ShadyRoom_EventScript_Assistant_Menu_2:
# 281 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_SetStatus
	return

ShadyRoom_EventScript_Assistant_Menu_3:
# 284 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_SetDamage
	return

ShadyRoom_EventScript_Assistant_Menu_4:
# 287 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_Menu_5:
	return


ShadyRoom_EventScript_Assistant_SetStatus::
# 295 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusFlavor, MSGBOX_YESNO
# 296 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_2
# 300 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 301 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_5
# 304 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_6
# 309 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Assistant_SetStatus_Text_0
# 310 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 312 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_STATUS_PICKER
# 313 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 315 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_10
# 319 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 321 "data/maps/ShadyRoom/scripts.pory"
	special ApplyStatus
# 323 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 6
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_13
# 327 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusInflicted
ShadyRoom_EventScript_Assistant_SetStatus_12:
# 329 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_SetStatus_2:
	return

ShadyRoom_EventScript_Assistant_SetStatus_5:
	return

ShadyRoom_EventScript_Assistant_SetStatus_6:
# 305 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_CantSelectEgg
	return

ShadyRoom_EventScript_Assistant_SetStatus_10:
	return

ShadyRoom_EventScript_Assistant_SetStatus_13:
# 324 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusCured
	goto ShadyRoom_EventScript_Assistant_SetStatus_12


ShadyRoom_EventScript_Assistant_SetDamage::
# 333 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_DamageFlavor, MSGBOX_YESNO
# 334 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_2
# 338 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_SelectPokemon
# 339 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_5
# 342 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, 2
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_6
# 347 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 349 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_DAMAGE_PICKER
# 350 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 352 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_10
# 356 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 358 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 7
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_13
ShadyRoom_EventScript_Assistant_SetDamage_12:
# 369 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 8
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_16
ShadyRoom_EventScript_Assistant_SetDamage_15:
# 377 "data/maps/ShadyRoom/scripts.pory"
	special SetPokemonToPercentHP
# 378 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_DamageApplied
# 379 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_SetDamage_2:
	return

ShadyRoom_EventScript_Assistant_SetDamage_5:
	return

ShadyRoom_EventScript_Assistant_SetDamage_6:
# 343 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_CantSelectEgg
	return

ShadyRoom_EventScript_Assistant_SetDamage_10:
	return

ShadyRoom_EventScript_Assistant_SetDamage_13:
# 359 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8009, 1
# 360 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x800A, 100
# 361 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x800B, 50
# 362 "data/maps/ShadyRoom/scripts.pory"
	special ShowNumberPicker
# 363 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_19
# 366 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
	goto ShadyRoom_EventScript_Assistant_SetDamage_12

ShadyRoom_EventScript_Assistant_SetDamage_16:
# 370 "data/maps/ShadyRoom/scripts.pory"
	special ShowCustomHPPicker
# 371 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_22
# 374 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
	goto ShadyRoom_EventScript_Assistant_SetDamage_15

ShadyRoom_EventScript_Assistant_SetDamage_19:
	return

ShadyRoom_EventScript_Assistant_SetDamage_22:
	return


ShadyRoom_EventScript_Merchant::
# 383 "data/maps/ShadyRoom/scripts.pory"
	lock
# 384 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 386 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 387 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_Greeting
ShadyRoom_EventScript_Merchant_2:
# 389 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_ne ShadyRoom_EventScript_Merchant_3
# 393 "data/maps/ShadyRoom/scripts.pory"
	closemessage
# 394 "data/maps/ShadyRoom/scripts.pory"
	release
	return

ShadyRoom_EventScript_Merchant_3:
# 390 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Merchant_Menu
	goto ShadyRoom_EventScript_Merchant_2


ShadyRoom_EventScript_Merchant_Menu::
# 398 "data/maps/ShadyRoom/scripts.pory"
	buffernumberstring STR_VAR_3, VAR_TOKEN_BALANCE
# 399 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_Menu
# 400 "data/maps/ShadyRoom/scripts.pory"
	waitmessage
# 402 "data/maps/ShadyRoom/scripts.pory"
	special MerchantMenu
# 403 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_2
# 407 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 408 "data/maps/ShadyRoom/scripts.pory"
	special GetMerchantItemInfo
# 410 "data/maps/ShadyRoom/scripts.pory"
	special CanAffordMerchantItem
# 411 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_5
# 416 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_PurchaseConfirm, MSGBOX_YESNO
# 417 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_8
# 421 "data/maps/ShadyRoom/scripts.pory"
	special PurchaseMerchantItem
# 422 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_PurchaseCommit
	return

ShadyRoom_EventScript_Merchant_Menu_2:
	return

ShadyRoom_EventScript_Merchant_Menu_5:
# 412 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_InsufficientFunds
	return

ShadyRoom_EventScript_Merchant_Menu_8:
	return


ShadyRoom_EventScript_Abra::
# 426 "data/maps/ShadyRoom/scripts.pory"
	lock
# 427 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 428 "data/maps/ShadyRoom/scripts.pory"
	addvar VAR_TOKEN_BALANCE, 1
# 429 "data/maps/ShadyRoom/scripts.pory"
	giveegg SPECIES_RAYQUAZA
# 430 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
# 431 "data/maps/ShadyRoom/scripts.pory"
	release
	return


ShadyRoom_EventScript_Gentleman_MaxIV_Text_0:
# 226 "data/maps/ShadyRoom/scripts.pory"
	.string "Which stat would you like to train?$"

ShadyRoom_EventScript_Assistant_SetStatus_Text_0:
# 309 "data/maps/ShadyRoom/scripts.pory"
	.string "Which status would you like to inflict?$"

ShadyRoom_Text_Placeholder::
# 434 "data/maps/ShadyRoom/scripts.pory"
	.string "This feature hasn't been implemented yet.$"

ShadyRoom_Text_Gentleman_Greeting::
# 438 "data/maps/ShadyRoom/scripts.pory"
	.string "GENTLEMAN: Keep your voice down...\n"
	.string "Let's see. You have {STR_VAR_1} unit(s) of credit.\p"
	.string "I specialize in... off-the-record\n"
	.string "modifications. What do you need?$"

ShadyRoom_Text_Gentleman_Menu::
# 445 "data/maps/ShadyRoom/scripts.pory"
	.string "What can I do for you?\n"
	.string "You have {STR_VAR_1} unit(s) of credit.$"

ShadyRoom_Text_Gentleman_CantSelectEgg::
# 450 "data/maps/ShadyRoom/scripts.pory"
	.string "An Egg? Too early. Come back when\n"
	.string "there's something to work with.$"

ShadyRoom_Text_Gentleman_InsufficientTokens::
# 455 "data/maps/ShadyRoom/scripts.pory"
	.string "Look, I like you, but I don't work\n"
	.string "pro bono. You're short on credit.\p"
	.string "Come back when you can afford my rates.$"

ShadyRoom_Text_Gentleman_NoTokens::
# 461 "data/maps/ShadyRoom/scripts.pory"
	.string "Come now, let's not waste time.\n"
	.string "Your line of credit is tapped out.$"

ShadyRoom_Text_Gentleman_NatureCost::
# 466 "data/maps/ShadyRoom/scripts.pory"
	.string "A complete shift in Nature, is it?\n"
	.string "That will run you two units of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_SameNature::
# 472 "data/maps/ShadyRoom/scripts.pory"
	.string "My friend, it already behaves like that.\n"
	.string "No need to pay me for something that's\p"
	.string "already been done.$"

ShadyRoom_Text_Gentleman_NatureChanged::
# 478 "data/maps/ShadyRoom/scripts.pory"
	.string "Pleasure doing business with you.\n"
	.string "Its mindset has been... optimized.$"

ShadyRoom_Text_Gentleman_HiddenAbilityCost::
# 483 "data/maps/ShadyRoom/scripts.pory"
	.string "Ah, looking for the premium stock?\n"
	.string "Unlocking a Hidden Ability isn't cheap.\p"
	.string "That will run you four units of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_AlreadyHiddenAbility::
# 490 "data/maps/ShadyRoom/scripts.pory"
	.string "This one's already received the upgrade\n"
	.string "No sense charging you twice.$"

ShadyRoom_Text_Gentleman_HiddenAbilityConfirm::
# 495 "data/maps/ShadyRoom/scripts.pory"
	.string "I can unlock {STR_VAR_1} for this one.\n"
	.string "Shall I proceed?$"

ShadyRoom_Text_Gentleman_HAApplied::
# 500 "data/maps/ShadyRoom/scripts.pory"
	.string "There. The latent potential has been\n"
	.string "unlocked. Keep this between us, eh?$"

ShadyRoom_Text_Gentleman_RestoreAbilityOffer::
# 505 "data/maps/ShadyRoom/scripts.pory"
	.string "Want to put things back the way\n"
	.string "nature intended?\p"
	.string "I can restore its standard Ability.\n"
	.string "No charge. Do we have a deal?$"

ShadyRoom_Text_Gentleman_AlreadyRegularAbility::
# 512 "data/maps/ShadyRoom/scripts.pory"
	.string "Looks to me like this one's already\n"
	.string "running the factory settings.\p"
	.string "Nothing for me to do.$"

ShadyRoom_Text_Gentleman_RestoreAbilityConfirm::
# 518 "data/maps/ShadyRoom/scripts.pory"
	.string "I can restore {STR_VAR_1} for this one.\n"
	.string "Shall I proceed?$"

ShadyRoom_Text_Gentleman_AbilityRestored::
# 523 "data/maps/ShadyRoom/scripts.pory"
	.string "There. Back to the standard model.\n"
	.string "Sometimes less attention is the best disguise.$"

ShadyRoom_Text_Gentleman_IVCost::
# 528 "data/maps/ShadyRoom/scripts.pory"
	.string "Ah, maxing out potential? Radical changes\n"
	.string "carry a steeper premium.\p"
	.string "That will cost two units of credit.\n"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_IVAlreadyMax::
# 535 "data/maps/ShadyRoom/scripts.pory"
	.string "That stat is already at its peak.\n"
	.string "No point wasting credit on it.$"

ShadyRoom_Text_Gentleman_IVConfirm::
# 540 "data/maps/ShadyRoom/scripts.pory"
	.string "I can push its {STR_VAR_1} to the\n"
	.string "absolute limit. Shall I proceed?$"

ShadyRoom_Text_Gentleman_IVMaxed::
# 545 "data/maps/ShadyRoom/scripts.pory"
	.string "Perfect. You won't find a cleaner\n"
	.string "modification job anywhere else.$"

ShadyRoom_Text_Assistant_Greeting::
# 550 "data/maps/ShadyRoom/scripts.pory"
	.string "ASSISTANT: Please state your request.\n"
	.string "The Gentleman has approved my services.\p"
	.string "I will handle any procedures you require.$"

ShadyRoom_Text_Assistant_Menu::
# 556 "data/maps/ShadyRoom/scripts.pory"
	.string "Please specify your request.$"

ShadyRoom_Text_Assistant_CantSelectEgg::
# 560 "data/maps/ShadyRoom/scripts.pory"
	.string "The subject has not yet developed.\n"
	.string "Procedure cannot be performed.$"

ShadyRoom_Text_Assistant_StatusFlavor::
# 565 "data/maps/ShadyRoom/scripts.pory"
	.string "Status manipulation is a simple\n"
	.string "procedure when properly monitored.\p"
	.string "Shall we begin?$"

ShadyRoom_Text_Assistant_StatusCured::
# 571 "data/maps/ShadyRoom/scripts.pory"
	.string "Status condition removed.\n"
	.string "The subject has returned to normal.$"

ShadyRoom_Text_Assistant_StatusInflicted::
# 576 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "The requested condition has been applied.$"

ShadyRoom_Text_Assistant_DamageFlavor::
# 581 "data/maps/ShadyRoom/scripts.pory"
	.string "I will apply controlled damage.\n"
	.string "Minor discomfort is to be expected.\p"
	.string "Try not to move.$"

ShadyRoom_Text_Assistant_DamageApplied::
# 587 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "The subject is within acceptable limits.$"

ShadyRoom_Text_Merchant_Greeting::
# 592 "data/maps/ShadyRoom/scripts.pory"
	.string "Welcome. Please ignore the\n"
	.string "suspicious atmosphere.\p"
	.string "Everything here is completely\n"
	.string "legitimate.$"

ShadyRoom_Text_Merchant_Menu::
# 599 "data/maps/ShadyRoom/scripts.pory"
	.string "Take a look.\n"
	.string "If you don't see what you need,\p"
	.string "I probably don't have it.\p"
	.string "You have {STR_VAR_3} credit(s)$"

ShadyRoom_Text_Merchant_PurchaseConfirm::
# 606 "data/maps/ShadyRoom/scripts.pory"
	.string "{STR_VAR_2} for {STR_VAR_1} credit\n"
	.string "Is that all you need?$"

ShadyRoom_Text_Merchant_PurchaseCommit::
# 611 "data/maps/ShadyRoom/scripts.pory"
	.string "Purchase confirmed!$"

ShadyRoom_Text_Merchant_InsufficientFunds::
# 615 "data/maps/ShadyRoom/scripts.pory"
	.string "Come back when your credit catches\n"
	.string "up with your ambition.$"
