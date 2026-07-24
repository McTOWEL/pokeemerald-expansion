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
	setvar VAR_SERVICE_COST, 2
# 193 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_CheckTokens
# 194 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_2
# 194 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_2
# 198 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVCost, MSGBOX_YESNO
# 199 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_7
# 203 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_SelectPokemon
# 204 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_10
# 208 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Gentleman_MaxIV_Text_0
# 209 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 211 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_IV_PICKER
# 212 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 213 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_13
# 217 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 219 "data/maps/ShadyRoom/scripts.pory"
	special BufferAndCheckIV
# 221 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_16
# 226 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVConfirm, MSGBOX_YESNO
# 227 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Gentleman_MaxIV_19
# 231 "data/maps/ShadyRoom/scripts.pory"
	special ApplyIVMax
# 233 "data/maps/ShadyRoom/scripts.pory"
	subvar VAR_TOKEN_BALANCE, VAR_SERVICE_COST
# 234 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVMaxed
# 235 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Gentleman_MaxIV_2:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_7:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_10:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_13:
	return

ShadyRoom_EventScript_Gentleman_MaxIV_16:
# 222 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Gentleman_IVAlreadyMax
	return

ShadyRoom_EventScript_Gentleman_MaxIV_19:
	return


ShadyRoom_EventScript_Assistant::
# 239 "data/maps/ShadyRoom/scripts.pory"
	lock
# 240 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 242 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 243 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_Greeting
ShadyRoom_EventScript_Assistant_2:
# 245 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_ne ShadyRoom_EventScript_Assistant_3
# 249 "data/maps/ShadyRoom/scripts.pory"
	closemessage
# 250 "data/maps/ShadyRoom/scripts.pory"
	release
	return

ShadyRoom_EventScript_Assistant_3:
# 246 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_Menu
	goto ShadyRoom_EventScript_Assistant_2


ShadyRoom_EventScript_Assistant_Menu::
# 254 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_ASSISTANT_SERVICES
# 256 "data/maps/ShadyRoom/scripts.pory"
	message ShadyRoom_Text_Assistant_Menu
# 257 "data/maps/ShadyRoom/scripts.pory"
	waitmessage
# 259 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 261 "data/maps/ShadyRoom/scripts.pory"
	switch VAR_RESULT
# 262 "data/maps/ShadyRoom/scripts.pory"
	case 0, ShadyRoom_EventScript_Assistant_Menu_2
# 265 "data/maps/ShadyRoom/scripts.pory"
	case 1, ShadyRoom_EventScript_Assistant_Menu_3
# 268 "data/maps/ShadyRoom/scripts.pory"
	case 2, ShadyRoom_EventScript_Assistant_Menu_4
# 271 "data/maps/ShadyRoom/scripts.pory"
	case MULTI_B_PRESSED, ShadyRoom_EventScript_Assistant_Menu_5
	return

ShadyRoom_EventScript_Assistant_Menu_2:
# 263 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_SetStatus
	return

ShadyRoom_EventScript_Assistant_Menu_3:
# 266 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Assistant_SetDamage
	return

ShadyRoom_EventScript_Assistant_Menu_4:
# 269 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_Menu_5:
	return


ShadyRoom_EventScript_Assistant_SetStatus::
# 277 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusFlavor, MSGBOX_YESNO
# 278 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_2
# 282 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_SelectPokemon
# 283 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_5
# 287 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Assistant_SetStatus_Text_0
# 288 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 290 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_STATUS_PICKER
# 291 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 293 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_8
# 297 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 299 "data/maps/ShadyRoom/scripts.pory"
	special ApplyStatus
# 301 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 6
	goto_if_eq ShadyRoom_EventScript_Assistant_SetStatus_11
# 305 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusInflicted
ShadyRoom_EventScript_Assistant_SetStatus_10:
# 307 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_SetStatus_2:
	return

ShadyRoom_EventScript_Assistant_SetStatus_5:
	return

ShadyRoom_EventScript_Assistant_SetStatus_8:
	return

ShadyRoom_EventScript_Assistant_SetStatus_11:
# 302 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_StatusCured
	goto ShadyRoom_EventScript_Assistant_SetStatus_10


ShadyRoom_EventScript_Assistant_SetDamage::
# 311 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_DamageFlavor, MSGBOX_YESNO
# 312 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_2
# 316 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Gentleman_SelectPokemon
# 317 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_SERVICE_SELECTION_OK, FALSE
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_5
# 321 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8006, VAR_0x8004
# 323 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_DAMAGE_PICKER
# 324 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 326 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_8
# 330 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8005, VAR_RESULT
# 333 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_0x8005, 7
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_11
ShadyRoom_EventScript_Assistant_SetDamage_10:
# 357 "data/maps/ShadyRoom/scripts.pory"
	special SetPokemonToPercentHP
# 358 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Assistant_DamageApplied
# 359 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, MULTI_B_PRESSED
	return

ShadyRoom_EventScript_Assistant_SetDamage_2:
	return

ShadyRoom_EventScript_Assistant_SetDamage_5:
	return

ShadyRoom_EventScript_Assistant_SetDamage_8:
	return

ShadyRoom_EventScript_Assistant_SetDamage_11:
# 334 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Assistant_SetDamage_Text_0
# 336 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_NUMBER_PICKER
# 337 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 339 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_14
# 343 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8007, VAR_RESULT
# 345 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_EventScript_Assistant_SetDamage_Text_1
# 347 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_0x8004, SCROLL_MULTI_NUMBER_PICKER
# 348 "data/maps/ShadyRoom/scripts.pory"
	special ShowScrollableMultichoice
# 350 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Assistant_SetDamage_17
# 354 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8008, VAR_RESULT
	goto ShadyRoom_EventScript_Assistant_SetDamage_10

ShadyRoom_EventScript_Assistant_SetDamage_14:
	return

ShadyRoom_EventScript_Assistant_SetDamage_17:
	return


ShadyRoom_EventScript_Merchant::
# 363 "data/maps/ShadyRoom/scripts.pory"
	lock
# 364 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 366 "data/maps/ShadyRoom/scripts.pory"
	setvar VAR_RESULT, FALSE
# 367 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_Greeting
ShadyRoom_EventScript_Merchant_2:
# 369 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_ne ShadyRoom_EventScript_Merchant_3
# 373 "data/maps/ShadyRoom/scripts.pory"
	closemessage
# 374 "data/maps/ShadyRoom/scripts.pory"
	release
	return

ShadyRoom_EventScript_Merchant_3:
# 370 "data/maps/ShadyRoom/scripts.pory"
	call ShadyRoom_EventScript_Merchant_Menu
	goto ShadyRoom_EventScript_Merchant_2


ShadyRoom_EventScript_Merchant_Menu::
# 378 "data/maps/ShadyRoom/scripts.pory"
	buffernumberstring STR_VAR_3, VAR_TOKEN_BALANCE
# 379 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_Menu
# 380 "data/maps/ShadyRoom/scripts.pory"
	waitmessage
# 382 "data/maps/ShadyRoom/scripts.pory"
	special MerchantMenu
# 383 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, MULTI_B_PRESSED
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_2
# 387 "data/maps/ShadyRoom/scripts.pory"
	copyvar VAR_0x8004, VAR_RESULT
# 388 "data/maps/ShadyRoom/scripts.pory"
	special GetMerchantItemInfo
# 390 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_PurchaseConfirm, MSGBOX_YESNO
# 391 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, NO
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_5
# 395 "data/maps/ShadyRoom/scripts.pory"
	special TryPurchaseMerchantItem
# 396 "data/maps/ShadyRoom/scripts.pory"
	compare VAR_RESULT, FALSE
	goto_if_eq ShadyRoom_EventScript_Merchant_Menu_8
# 401 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_PurchaseCommit
	return

ShadyRoom_EventScript_Merchant_Menu_2:
	return

ShadyRoom_EventScript_Merchant_Menu_5:
	return

ShadyRoom_EventScript_Merchant_Menu_8:
# 397 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Merchant_InsufficientFunds
	return


ShadyRoom_EventScript_Abra::
# 405 "data/maps/ShadyRoom/scripts.pory"
	lock
# 406 "data/maps/ShadyRoom/scripts.pory"
	faceplayer
# 407 "data/maps/ShadyRoom/scripts.pory"
	addvar VAR_TOKEN_BALANCE, 1
# 408 "data/maps/ShadyRoom/scripts.pory"
	msgbox ShadyRoom_Text_Placeholder
# 409 "data/maps/ShadyRoom/scripts.pory"
	release
	return


ShadyRoom_EventScript_Gentleman_MaxIV_Text_0:
# 208 "data/maps/ShadyRoom/scripts.pory"
	.string "Which stat would you like to train?$"

ShadyRoom_EventScript_Assistant_SetStatus_Text_0:
# 287 "data/maps/ShadyRoom/scripts.pory"
	.string "Which status would you like to inflict?$"

ShadyRoom_EventScript_Assistant_SetDamage_Text_0:
# 334 "data/maps/ShadyRoom/scripts.pory"
	.string "Custom HP %\nTens digit (0-9):$"

ShadyRoom_EventScript_Assistant_SetDamage_Text_1:
# 345 "data/maps/ShadyRoom/scripts.pory"
	.string "Custom HP %\nOnes digit (0-9):$"

ShadyRoom_Text_Placeholder::
# 412 "data/maps/ShadyRoom/scripts.pory"
	.string "This feature hasn't been implemented yet.$"

ShadyRoom_Text_Gentleman_Greeting::
# 416 "data/maps/ShadyRoom/scripts.pory"
	.string "GENTLEMAN: Keep your voice down...\n"
	.string "Let's see. You have {STR_VAR_1} unit(s) of credit.\p"
	.string "I specialize in... off-the-record\n"
	.string "modifications. What do you need?$"

ShadyRoom_Text_Gentleman_Menu::
# 423 "data/maps/ShadyRoom/scripts.pory"
	.string "What can I do for you?\n"
	.string "You have {STR_VAR_1} unit(s) of credit.$"

ShadyRoom_Text_Gentleman_CantSelectEgg::
# 428 "data/maps/ShadyRoom/scripts.pory"
	.string "An Egg? Let's wait until it hatches\n"
	.string "before we start rewriting its DNA.$"

ShadyRoom_Text_Gentleman_InsufficientTokens::
# 433 "data/maps/ShadyRoom/scripts.pory"
	.string "Look, I like you, but I don't work\n"
	.string "pro bono. You're short on credit.\p"
	.string "Come back when you can afford my rates.$"

ShadyRoom_Text_Gentleman_NoTokens::
# 439 "data/maps/ShadyRoom/scripts.pory"
	.string "Come now, let's not waste time.\n"
	.string "Your line of credit is tapped out.$"

ShadyRoom_Text_Gentleman_NatureCost::
# 444 "data/maps/ShadyRoom/scripts.pory"
	.string "A complete shift in Nature, is it?\n"
	.string "That will run you two units of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_SameNature::
# 450 "data/maps/ShadyRoom/scripts.pory"
	.string "My friend, it already behaves like that.\n"
	.string "Don't play games with me. What do you really need?$"

ShadyRoom_Text_Gentleman_NatureChanged::
# 455 "data/maps/ShadyRoom/scripts.pory"
	.string "Pleasure doing business with you.\n"
	.string "Its mindset has been... optimized.$"

ShadyRoom_Text_Gentleman_HiddenAbilityCost::
# 460 "data/maps/ShadyRoom/scripts.pory"
	.string "Ah, looking for the premium stock?\n"
	.string "Unlocking a Hidden Ability isn't cheap.\p"
	.string "That will run you four units of credit.\p"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_AlreadyHiddenAbility::
# 467 "data/maps/ShadyRoom/scripts.pory"
	.string "My work is already done.\n"
	.string "This one's carrying the premium package.\p"
	.string "No sense charging you twice.$"

ShadyRoom_Text_Gentleman_HiddenAbilityConfirm::
# 473 "data/maps/ShadyRoom/scripts.pory"
	.string "I can unlock {STR_VAR_1} for this one.\n"
	.string "Shall I proceed?$"

ShadyRoom_Text_Gentleman_HAApplied::
# 478 "data/maps/ShadyRoom/scripts.pory"
	.string "There. The latent potential has been\n"
	.string "unlocked. Keep this between us, eh?$"

ShadyRoom_Text_Gentleman_RestoreAbilityOffer::
# 483 "data/maps/ShadyRoom/scripts.pory"
	.string "Want to put things back the way\n"
	.string "nature intended?\p"
	.string "I can restore its standard Ability.\n"
	.string "No charge. Do we have a deal?$"

ShadyRoom_Text_Gentleman_AlreadyRegularAbility::
# 490 "data/maps/ShadyRoom/scripts.pory"
	.string "Looks to me like this one's already\n"
	.string "running the factory settings.\p"
	.string "Nothing for me to do.$"

ShadyRoom_Text_Gentleman_RestoreAbilityConfirm::
# 496 "data/maps/ShadyRoom/scripts.pory"
	.string "I can restore {STR_VAR_1} for this one.\n"
	.string "Shall I proceed?$"

ShadyRoom_Text_Gentleman_AbilityRestored::
# 501 "data/maps/ShadyRoom/scripts.pory"
	.string "There. Back to the standard model.\n"
	.string "Sometimes less attention is the best disguise.$"

ShadyRoom_Text_Gentleman_IVCost::
# 506 "data/maps/ShadyRoom/scripts.pory"
	.string "Ah, maxing out potential? Radical changes\n"
	.string "carry a steeper premium.\p"
	.string "That will cost two units of credit.\n"
	.string "Do we have a deal?$"

ShadyRoom_Text_Gentleman_IVAlreadyMax::
# 513 "data/maps/ShadyRoom/scripts.pory"
	.string "That stat is already at its peak.\n"
	.string "No point wasting credit on it.$"

ShadyRoom_Text_Gentleman_IVConfirm::
# 518 "data/maps/ShadyRoom/scripts.pory"
	.string "I can push its {STR_VAR_1} to the\n"
	.string "absolute limit. Shall I proceed?$"

ShadyRoom_Text_Gentleman_IVMaxed::
# 523 "data/maps/ShadyRoom/scripts.pory"
	.string "Perfect. You won't find a cleaner\n"
	.string "modification job anywhere else.$"

ShadyRoom_Text_Assistant_Greeting::
# 528 "data/maps/ShadyRoom/scripts.pory"
	.string "ASSISTANT: Please state your request.\n"
	.string "The Gentleman has approved my services.\p"
	.string "I will handle any procedures you require.$"

ShadyRoom_Text_Assistant_Menu::
# 534 "data/maps/ShadyRoom/scripts.pory"
	.string "Available procedures?$"

ShadyRoom_Text_Assistant_StatusFlavor::
# 538 "data/maps/ShadyRoom/scripts.pory"
	.string "Status manipulation is a simple\n"
	.string "procedure when properly monitored.\p"
	.string "Shall we begin?$"

ShadyRoom_Text_Assistant_StatusCured::
# 544 "data/maps/ShadyRoom/scripts.pory"
	.string "Status condition removed.\n"
	.string "The subject has returned to normal.$"

ShadyRoom_Text_Assistant_StatusInflicted::
# 549 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "The requested condition has been applied.$"

ShadyRoom_Text_Assistant_DamageFlavor::
# 554 "data/maps/ShadyRoom/scripts.pory"
	.string "I will apply controlled damage.\n"
	.string "Minor discomfort is to be expected.\p"
	.string "Try not to move.$"

ShadyRoom_Text_Assistant_DamageApplied::
# 560 "data/maps/ShadyRoom/scripts.pory"
	.string "Procedure complete.\n"
	.string "The subject is within acceptable limits.$"

ShadyRoom_Text_Merchant_Greeting::
# 565 "data/maps/ShadyRoom/scripts.pory"
	.string "Hey dude$"

ShadyRoom_Text_Merchant_Menu::
# 569 "data/maps/ShadyRoom/scripts.pory"
	.string "What would you like to purchase?\n"
	.string "You have {STR_VAR_3} credit(s)$"

ShadyRoom_Text_Merchant_PurchaseConfirm::
# 574 "data/maps/ShadyRoom/scripts.pory"
	.string "Would you like to buy\n"
	.string "{STR_VAR_2} for {STR_VAR_1} credit(s)?$"

ShadyRoom_Text_Merchant_PurchaseCommit::
# 579 "data/maps/ShadyRoom/scripts.pory"
	.string "Purchase confirmed!$"

ShadyRoom_Text_Merchant_InsufficientFunds::
# 583 "data/maps/ShadyRoom/scripts.pory"
	.string "You ain't got enough money, homeboy$"
