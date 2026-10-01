GlobalScript_AbraTeleport::
# 2 "data/scripts/custom_scripts.pory"
	lock
# 3 "data/scripts/custom_scripts.pory"
	faceplayer
# 5 "data/scripts/custom_scripts.pory"
	call Script_RandomMessage
# 6 "data/scripts/custom_scripts.pory"
	closemessage
# 8 "data/scripts/custom_scripts.pory"
	special SaveCurrentMapToAbraVariables
# 10 "data/scripts/custom_scripts.pory"
	warp MAP_SHADYROOM, 1, 6
	return


GlobalScript_AbraReturn::
# 14 "data/scripts/custom_scripts.pory"
	lock
# 15 "data/scripts/custom_scripts.pory"
	faceplayer
# 17 "data/scripts/custom_scripts.pory"
	call Script_RandomMessage
# 18 "data/scripts/custom_scripts.pory"
	closemessage
# 20 "data/scripts/custom_scripts.pory"
	special WarpToAbraSavedVariables
	return


Script_RandomMessage::
# 24 "data/scripts/custom_scripts.pory"
	random 3
# 26 "data/scripts/custom_scripts.pory"
	switch VAR_RESULT
# 27 "data/scripts/custom_scripts.pory"
	case 0, Script_RandomMessage_2
# 28 "data/scripts/custom_scripts.pory"
	case 1, Script_RandomMessage_3
# 29 "data/scripts/custom_scripts.pory"
	msgbox Script_RandomMessage_Text_2
	return

Script_RandomMessage_2:
# 27 "data/scripts/custom_scripts.pory"
	msgbox Script_RandomMessage_Text_0
	return

Script_RandomMessage_3:
# 28 "data/scripts/custom_scripts.pory"
	msgbox Script_RandomMessage_Text_1
	return


Script_RandomMessage_Text_0:
# 27 "data/scripts/custom_scripts.pory"
	.string "Abra...$"

Script_RandomMessage_Text_1:
# 28 "data/scripts/custom_scripts.pory"
	.string "..bra..$"

Script_RandomMessage_Text_2:
# 29 "data/scripts/custom_scripts.pory"
	.string "Abra stares at you intently$"
