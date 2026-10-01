#include "global.h"
#include "battle.h"
#include "battle_util.h"
#include "event_data.h"
#include "field_control_avatar.h"
#include "field_screen_effect.h"
#include "field_specials.h"
#include "item.h"
#include "item_use.h"
#include "main.h"
#include "menu.h"
#include "overworld.h"
#include "pokemon.h"
#include "script.h"
#include "script_menu.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "text.h"
#include "window.h"

#include "number_picker.h"
#include "custom_logic.h"

bool8 CanSpeciesLearnMove(enum Species species, enum Move move)
{
    const struct LevelUpMove *levelUpLearnset = GetSpeciesLevelUpLearnset(species);
    const u16 *teachableLearnset = GetSpeciesTeachableLearnset(species);
    const u16 *eggMoves = GetSpeciesEggMoves(species);

    for (u32 i = 0; levelUpLearnset[i].move != MOVE_UNAVAILABLE; i++)
    {
        if (levelUpLearnset[i].move == move)
            return TRUE;
    }

    for (u32 i = 0; teachableLearnset[i] != MOVE_UNAVAILABLE; i++)
    {
        if (teachableLearnset[i] == move)
            return TRUE;
    }

    for (u32 i = 0; eggMoves[i] != MOVE_UNAVAILABLE; i++)
    {
        if (eggMoves[i] == move)
            return TRUE;
    }

    return FALSE;
}

bool32 CanCatchInBattle(void)
{
    return CanThrowBall() && FlagGet(FLAG_CAN_THROW_BALL);
}

void SaveCurrentMapToAbraVariables(void)
{
    VarSet(VAR_ABRA_MAP_GROUP, gSaveBlock1Ptr->location.mapGroup);
    VarSet(VAR_ABRA_MAP_NUM, gSaveBlock1Ptr->location.mapNum);
}

void WarpToAbraSavedVariables(void)
{
    u8 mapGroup = VarGet(VAR_ABRA_MAP_GROUP);
    u8 mapNum = VarGet(VAR_ABRA_MAP_NUM);
    s8 x = 12;
    s8 y = 3;

    SetWarpDestination(mapGroup, mapNum, WARP_ID_NONE, x, y);
    DoWarp();
    ResetInitialPlayerAvatarState();
}

void IsNatureSameAsCurrent(void)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004];
    u8 currentNature = GetMonData(mon, MON_DATA_HIDDEN_NATURE);

    gSpecialVar_Result = (currentNature == gSpecialVar_0x8005);
}

void MonHasHiddenAbility(void)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004];
    u8 abilityNum = GetMonData(mon, MON_DATA_ABILITY_NUM);
    u16 species = GetMonData(mon, MON_DATA_SPECIES);

    if (abilityNum == 2)
    {
        gSpecialVar_Result = TRUE;
        StringCopy(gStringVar1, gAbilitiesInfo[GetAbilityBySpecies(species, 0)].name);
    }
    else
    {
        gSpecialVar_Result = FALSE;
        StringCopy(gStringVar1, gAbilitiesInfo[GetAbilityBySpecies(species, 2)].name);
    }
}

void SetAbilitySlot(void)
{
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][gSpecialVar_0x8004];

    SetMonData(mon, MON_DATA_ABILITY_NUM, &gSpecialVar_0x8005);

    CalculateMonStats(mon);
}

void BufferAndCheckIV(void)
{
    u16 menuChoice = VarGet(VAR_0x8005);
    u16 partyIndex = VarGet(VAR_0x8006);
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];

    u8 ivField = 0;
    u8 hyperTrainField = 0;

    switch (menuChoice)
    {
    case 0: // Menu Item 1: HP
        ivField = MON_DATA_HP_IV;
        hyperTrainField = MON_DATA_HYPER_TRAINED_HP;
        StringCopy(gStringVar1, gText_HP4);
        break;
    case 1: // Menu Item 2: Attack
        ivField = MON_DATA_ATK_IV;
        hyperTrainField = MON_DATA_HYPER_TRAINED_ATK;
        StringCopy(gStringVar1, gText_Attack);
        break;
    case 2: // Menu Item 3: Defense
        ivField = MON_DATA_DEF_IV;
        hyperTrainField = MON_DATA_HYPER_TRAINED_DEF;
        StringCopy(gStringVar1, gText_Defense);
        break;
    case 3: // Menu Item 4: Sp. Attack
        ivField = MON_DATA_SPATK_IV;
        hyperTrainField = MON_DATA_HYPER_TRAINED_SPATK;
        StringCopy(gStringVar1, gText_SpAtk);
        break;
    case 4: // Menu Item 5: Sp. Defense
        ivField = MON_DATA_SPDEF_IV;
        hyperTrainField = MON_DATA_HYPER_TRAINED_SPDEF;
        StringCopy(gStringVar1, gText_SpDef);
        break;
    case 5: // Menu Item 6: Speed
        ivField = MON_DATA_SPEED_IV;
        hyperTrainField = MON_DATA_HYPER_TRAINED_SPEED;
        StringCopy(gStringVar1, gText_Speed);
        break;
    default:
        gSpecialVar_Result = FALSE;
        return;
    }

    // Fail if already Trained or if the natural IV is already 31
    if (GetMonData(mon, hyperTrainField) || GetMonData(mon, ivField) >= MAX_PER_STAT_IVS)
    {
        gSpecialVar_Result = FALSE;
    }
    else
    {
        gSpecialVar_Result = TRUE;
    }
}

void ApplyIVMax(void)
{
    u16 menuChoice = VarGet(VAR_0x8005);
    u16 partyIndex = VarGet(VAR_0x8006);
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];

    u8 hyperTrainField = 0;

    switch (menuChoice)
    {
    case 0: // Menu Item 1: HP
        hyperTrainField = MON_DATA_HYPER_TRAINED_HP;
        break;
    case 1: // Menu Item 2: Attack
        hyperTrainField = MON_DATA_HYPER_TRAINED_ATK;
        break;
    case 2: // Menu Item 3: Defense
        hyperTrainField = MON_DATA_HYPER_TRAINED_DEF;
        break;
    case 3: // Menu Item 4: Sp. Attack
        hyperTrainField = MON_DATA_HYPER_TRAINED_SPATK;
        break;
    case 4: // Menu Item 5: Sp. Defense
        hyperTrainField = MON_DATA_HYPER_TRAINED_SPDEF;
        break;
    case 5: // Menu Item 6: Speed
        hyperTrainField = MON_DATA_HYPER_TRAINED_SPEED;
        break;
    }

    bool32 data = TRUE;
    SetMonData(mon, hyperTrainField, &data);
    CalculateMonStats(mon);
}

// this list matches the items and order of my SCROLL_MULTI
static const enum Type sCorrectedTypeOrder[] = {
    TYPE_FIRE,
    TYPE_WATER,
    TYPE_ELECTRIC,
    TYPE_GRASS,
    TYPE_ICE,
    TYPE_FIGHTING,
    TYPE_POISON,
    TYPE_GROUND,
    TYPE_FLYING,
    TYPE_PSYCHIC,
    TYPE_BUG,
    TYPE_ROCK,
    TYPE_GHOST,
    TYPE_DRAGON,
    TYPE_DARK,
    TYPE_STEEL,
    TYPE_FAIRY,
};

void BufferAndCheckHiddenPower(void)
{
    u16 menuChoice = VarGet(VAR_0x8005);
    u16 partyIndex = VarGet(VAR_0x8006);
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];

    enum Type currentHpType = CheckDynamicMoveType(mon, MOVE_HIDDEN_POWER, B_BATTLER_0, MON_OUTSIDE_BATTLE);
    enum Type selectedHpType = sCorrectedTypeOrder[menuChoice];

    if (currentHpType == selectedHpType)
    {
        gSpecialVar_Result = FALSE;
        StringCopy(gStringVar1, gTypesInfo[currentHpType].name);
    }
    else
    {
        gSpecialVar_Result = TRUE;
        StringCopy(gStringVar1, gTypesInfo[selectedHpType].name);
    }
}

void ApplyHiddenPower(void)
{
    u16 menuChoice = VarGet(VAR_0x8005);
    u16 partyIndex = VarGet(VAR_0x8006);
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];

    enum Type selectedHpType = sCorrectedTypeOrder[menuChoice];

    SetMonData(mon, MON_DATA_HIDDEN_POWER_MODIFIER, &selectedHpType);
}

void ApplyStatus(void)
{
    u16 menuChoice = VarGet(VAR_0x8005);
    u16 partyIndex = VarGet(VAR_0x8006);

    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];
    u32 status = STATUS1_NONE;

    switch (menuChoice)
    {
    case 0:
        status = STATUS1_BURN;
        break;
    case 1:
        status = STATUS1_POISON;
        break;
    case 2:
        status = STATUS1_TOXIC_POISON;
        break;
    case 3:
        status = STATUS1_PARALYSIS;
        break;
    case 4:
        status = STATUS1_FROSTBITE;
        break;
    case 5:
        status = STATUS1_SLEEP_TURN(3);
        break; // Sets sleep for 3 turns
    case 6:
        status = STATUS1_NONE;
        break; // Cures the status
    default:
        return; // Invalid choice, exit safely
    }

    // Apply the status to the chosen Pokémon
    SetMonData(mon, MON_DATA_STATUS, &status);
}

void SetPokemonToPercentHP(void)
{
    u16 menuChoice = VarGet(VAR_0x8005);
    u16 partyIndex = VarGet(VAR_0x8006);

    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];
    u32 percent = 0;
    u32 hp = 0;

    switch (menuChoice)
    {
    case 0: // FULL
        percent = 100;
        break;
    case 1: // 75%
        percent = 75;
        break;
    case 2: // 66%
        percent = 66;
        break;
    case 3: // 50%
        percent = 50;
        break;
    case 4: // 33%
        percent = 33;
        break;
    case 5: // 25%
        percent = 25;
        break;
    case 6: // 1 HP
        hp = 1;
        break;
    case 7: // CUSTOM %
        percent = VarGet(VAR_0x8008);
        break;
    case 8: // CUSTOM HP
        hp = VarGet(VAR_0x8008);
        break;
    }

    if (hp != 0)
    {
        u16 targetHp = hp;
        SetMonData(mon, MON_DATA_HP, &targetHp);
    }
    else
    {
        u16 maxHp = GetMonData(mon, MON_DATA_MAX_HP);

        u16 targetHp = (maxHp * percent) / 100;

        if (targetHp == 0)
        {
            targetHp = 1;
        }

        SetMonData(mon, MON_DATA_HP, &targetHp);
    }
}

void SetPartytoEdgeXP(void)
{
    u32 i;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][i];
        u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);

        if (species != SPECIES_NONE && !GetMonData(mon, MON_DATA_IS_EGG, NULL))
        {
            u8 currentLevel = GetMonData(mon, MON_DATA_LEVEL, NULL);

            if (currentLevel < 100)
            {
                u32 targetExp = gExperienceTables[gSpeciesInfo[species].growthRate][currentLevel + 1] - 1;
                SetMonData(mon, MON_DATA_EXP, &targetExp);
                CalculateMonStats(mon);
            }
        }
    }
}

void SetPokemontoEdgeXP(void)
{
    u16 partyIndex = VarGet(VAR_0x8006);

    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];

    u16 species = GetMonData(mon, MON_DATA_SPECIES, NULL);
    u8 currentLevel = GetMonData(mon, MON_DATA_LEVEL, NULL);

    if (currentLevel < 100)
    {
        u32 targetExp = gExperienceTables[gSpeciesInfo[species].growthRate][currentLevel + 1] - 1;
        SetMonData(mon, MON_DATA_EXP, &targetExp);
        CalculateMonStats(mon);
    }
}

void CheckPokemonShiny(void)
{
    u16 partyIndex = VarGet(VAR_0x8006);
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];

    gSpecialVar_Result = IsMonShiny(mon);
}

void TogglePokemonShiny(void)
{
    u16 partyIndex = VarGet(VAR_0x8006);
    struct Pokemon *mon = &gParties[B_TRAINER_PLAYER][partyIndex];

    bool8 newShinyState = !GetMonData(mon, MON_DATA_IS_SHINY, NULL);
    SetMonData(mon, MON_DATA_IS_SHINY, &newShinyState);
}

struct MerchantItem
{
    u16 itemId;
    u16 price;
    u16 flagId;
};

static const struct MerchantItem sMerchantItems[] =
    {
        // Placeholder prices, will change
        {ITEM_CHOICE_BAND, 5, FLAG_BOUGHT_CHOICE_BAND},
        {ITEM_CHOICE_SPECS, 5, FLAG_BOUGHT_CHOICE_SPECS},
        {ITEM_CHOICE_SCARF, 5, FLAG_BOUGHT_CHOICE_SCARF},
        {ITEM_LIFE_ORB, 5, FLAG_BOUGHT_LIFE_ORB},
        {ITEM_EXPERT_BELT, 5, FLAG_BOUGHT_EXPERT_BELT},
        {ITEM_LOADED_DICE, 5, FLAG_BOUGHT_LOADED_DICE},
        {ITEM_PUNCHING_GLOVE, 5, FLAG_BOUGHT_PUNCHING_GLOVE},
        {ITEM_WHITE_HERB, 5, FLAG_BOUGHT_WHITE_HERB},
        {ITEM_POWER_HERB, 5, FLAG_BOUGHT_POWER_HERB},
        {ITEM_EJECT_PACK, 5, FLAG_BOUGHT_EJECT_PACK},
        {ITEM_AIR_BALLOON, 5, FLAG_BOUGHT_AIR_BALLOON},
        {ITEM_LEFTOVERS, 5, FLAG_BOUGHT_LEFTOVERS},
        {ITEM_BLACK_SLUDGE, 5, FLAG_BOUGHT_BLACK_SLUDGE},
        {ITEM_ASSAULT_VEST, 5, FLAG_BOUGHT_ASSAULT_VEST},
        {ITEM_ROCKY_HELMET, 5, FLAG_BOUGHT_ROCKY_HELMET},
};

#define MERCHANT_ITEM_COUNT ARRAY_COUNT(sMerchantItems)
#define MERCHANT_MENU_STRING_LENGTH 48

static u8 sMerchantStringBuffers[MERCHANT_ITEM_COUNT][MERCHANT_MENU_STRING_LENGTH];
static const u8 *sMerchantMenu[MERCHANT_ITEM_COUNT];
static u8 sSelectedMerchantSlot;

static void BuildMerchantMenuEntry(u8 slot, const u8 *itemName, u16 price, bool32 soldOut)
{
    static const u8 sText_SoldOut[] = _("{COLOR RED}SOLD OUT");
    static const u8 sText_MenuSpacing[] = _(" {CLEAR_TO 100}{FONT_SMALL}");
    static const u8 sText_Credit[] = _(" credit");
    static const u8 sText_Blue[] = _("{COLOR BLUE}");

    StringCopy(sMerchantStringBuffers[slot], itemName);
    StringAppend(sMerchantStringBuffers[slot], sText_MenuSpacing);

    if (soldOut)
    {
        StringAppend(sMerchantStringBuffers[slot], sText_SoldOut);
    }
    else
    {
        ConvertIntToDecimalStringN(gStringVar1, price, STR_CONV_MODE_LEFT_ALIGN, 2);
        StringAppend(sMerchantStringBuffers[slot], sText_Blue);
        StringAppend(sMerchantStringBuffers[slot], gStringVar1);
        StringAppend(sMerchantStringBuffers[slot], sText_Credit);
    }

    sMerchantMenu[slot] = sMerchantStringBuffers[slot];
}

void MerchantMenu(void)
{
    u8 i;

    for (i = 0; i < MERCHANT_ITEM_COUNT; i++)
    {
        BuildMerchantMenuEntry(i, GetItemName(sMerchantItems[i].itemId), sMerchantItems[i].price, FlagGet(sMerchantItems[i].flagId));
    }

    ShowDynamicScrollableMultichoice(sMerchantMenu, MERCHANT_ITEM_COUNT);
}

void GetMerchantItemInfo(void)
{
    sSelectedMerchantSlot = gSpecialVar_0x8004; // slot index passed in from script
    StringCopy(gStringVar2, GetItemName(sMerchantItems[sSelectedMerchantSlot].itemId));
    ConvertIntToDecimalStringN(gStringVar1, sMerchantItems[sSelectedMerchantSlot].price, STR_CONV_MODE_LEFT_ALIGN, 2);
}

void CanAffordMerchantItem(void)
{
    const struct MerchantItem *item = &sMerchantItems[sSelectedMerchantSlot];

    if (VarGet(VAR_TOKEN_BALANCE) < item->price)
    {
        gSpecialVar_Result = FALSE;
    }
}

void PurchaseMerchantItem(void)
{
    const struct MerchantItem *item = &sMerchantItems[sSelectedMerchantSlot];

    VarSet(VAR_TOKEN_BALANCE, VarGet(VAR_TOKEN_BALANCE) - item->price);
    AddBagItem(item->itemId, 1);
    FlagSet(item->flagId);
    gSpecialVar_Result = TRUE;
}
