#ifndef GUARD_CONFIG_SUMMARY_SCREEN_H
#define GUARD_CONFIG_SUMMARY_SCREEN_H

// Settings
#define P_SUMMARY_SCREEN_NATURE_COLORS   TRUE   // If TRUE, nature-based stat boosts and reductions will be red and blue in the summary screen.
#define P_SUMMARY_SCREEN_RENAME          TRUE   // If TRUE, an option to change Pokémon nicknames replaces the cancel prompt on the summary screen info page.

// IV/EV settings
#define P_SUMMARY_SCREEN_IV_EV_INFO      FALSE  // If TRUE, will allow player to cycle through the Stats, IVs, and EVs in the summary screen skills page.
#define P_SUMMARY_SCREEN_IV_EV_BOX_ONLY  FALSE  // If TRUE, will allow player to cycle through the Stats, IVs, and EVs in the summary screen skills page, but only in the PC storage box.
#define P_SUMMARY_SCREEN_IV_HYPERTRAIN   TRUE   // If TRUE, stats that have been hyper trained will show as 31/S when viewing them in the summary screen
#define P_SUMMARY_SCREEN_IV_EV_TILESET   FALSE  // If TRUE, loads an alternate tileset to allow changing the "STATS" label in the summary screen skills page. Note: if it's still loading the alternate tileset after changing this and recompiling, you may need a `make clean` before compilation.
#define P_SUMMARY_SCREEN_IV_EV_VALUES    FALSE  // If TRUE, will show the actual IV value instead of the letter grade.
/*
LETTER GRADE GUIDE:

    F = 0
    D = 1 - 15
    C = 16 - 25
    B = 26 - 29
    A = 30
    S = 31

Info taken from https://bulbapedia.bulbagarden.net/wiki/Stats_judge.
*/
#define P_SUMMARY_SCREEN_IV_ONLY         FALSE  // If TRUE, will only show IV info in the summary screen.
#define P_SUMMARY_SCREEN_EV_ONLY         FALSE  // If TRUE, will only show EV info in the summary screen.

// IV/EV flags
#define P_FLAG_SUMMARY_SCREEN_IV_EV_INFO 0      // If this flag is set, will allow player to cycle through the Stats, IVs, and EVs in the summary screen skills page. Note: if P_SUMMARY_SCREEN_IV_EV_INFO is TRUE, this flag does nothing.

// Move Relearner settings
#define P_ENABLE_MOVE_RELEARNERS         FALSE   // If TRUE, it enables move relearners for egg, TM and tutor. (see below for specific configs /flags)
#define P_SORT_MOVES                     FALSE   // If TRUE, sorts all moves alphabetically in the relearner's list.

// Level up Relearner
#define P_PRE_EVO_MOVES                  FALSE   // If TRUE, it enables the Pokémon to learn moves from it's pre evolution.
#define P_ENABLE_ALL_LEVEL_UP_MOVES      FALSE   // If TRUE, it enables the Pokémon to learn all level up moves, regardless of its level.

// TM Relearner
#define P_TM_MOVES_RELEARNER             TRUE    // If TRUE, enables machine move relearner.
#define P_ENABLE_ALL_TM_MOVES            FALSE   // If TRUE, it enables the Pokémon to learn all TMs its compatible with, regardless of it being in the bag.

// Relearner flags - Redundant if P_ENABLE_MOVE_RELEARNERS is TRUE, but still added here incase you don't want all relearners unlocked at the same time.
// To use the following features in scripting, replace the 0s with the flag ID you're assigning it to.
// Eg: Replace with FLAG_UNUSED_0x264 so you can use that flag to toggle the feature.
#define P_FLAG_EGG_MOVES                 0       // If this flag is set, enables egg move relearner.
#define P_FLAG_TUTOR_MOVES               0       // If this flag is set, enables tutor move relearner.

// Move Relearner summary screen
#define P_SUMMARY_SCREEN_MOVE_RELEARNER  TRUE   // If TRUE, shows an option for Pokémon to relearn moves on the summary screen moves page.
#define P_SUMMARY_MOVE_RELEARNER_FULL_PP TRUE   // If TRUE, the move relearner in the summary screen restores relearned moves' PP to full.

// Move Relearner party menu
#define P_PARTY_MOVE_RELEARNER           FALSE  // If TRUE, it enables the move relearner in the party menu.

// BW-style summary UI

// constants
#define BW_MAX_MOVE_DESCRIPTION_LENGTH 100   // this only needs to be updated if you use auto-formatting
#define BW_SUMMARY_MON_IDLE_ANIMS_FRAMES 300 // number of frames between each idle anim IF BW_SUMMARY_MON_IDLE_ANIMS is true.
                                             // for reference, Emerald runs at 60FPS by default

// configs
#define BW_SUMMARY_AUTO_FORMAT_MOVE_DESCRIPTIONS TRUE  // automatically formats move descriptions to fit the new box size. disable if you want to format them manually
#define BW_SUMMARY_NATURE_COLORS                 TRUE  // color stats increased or reduced by nature, red = boosted, blue = reduced
#define BW_SUMMARY_NATURE_ARROWS                 FALSE // arrows to show stats increased or reduced by nature
#define BW_SUMMARY_CATEGORY_ICONS                TRUE  // determines whether category (split) icons are shown or not
#define BW_SUMMARY_DECAP                         FALSE // indicates if summary screen-specific strings should be decapitalized
#define BW_SUMMARY_SHOW_FRIENDSHIP               FALSE // show a heart that fills up to indicate friendship value
#define BW_SUMMARY_BW_STATUS_ICONS               TRUE  // use Gen 5 style status icons instead of the default ones.
#define BW_SUMMARY_BW_TYPE_ICONS                 TRUE  // use Gen 5 style type icons instead of the default ones.
                                                       // out of the box the vanilla icons don't fit well, this is mostly a compatibility
                                                       // option for people who already use custom icons everywhere else
#define BW_SUMMARY_SCROLLING_BG                  TRUE  // enables scrolling animated background
#define BW_SUMMARY_BG_BLEND                      TRUE  // enables alpha blending for the main UI (semi-transparency)
#define BW_SUMMARY_MON_IDLE_ANIMS                TRUE  // loops the mon animations regularly as an "idle" anim
#define BW_SUMMARY_MON_SHADOWS                   TRUE  // displays a shadow for the mon sprite
#define BW_SUMMARY_SHOW_TERA_TYPE                FALSE // show tera type icons
#define BW_SUMMARY_SHOW_CONTEST_MOVES            TRUE  // show the contest moves page


// Renaming and move relearner behavior use the standard Expansion configs above:
// P_SUMMARY_SCREEN_RENAME
// P_SUMMARY_SCREEN_MOVE_RELEARNER
// Dynamic move types use P_SHOW_DYNAMIC_TYPES.

/* Info for users

General tilemap setup
BG3 - scrolling grid background (or not scrolling if you turned the config off)
BG2 - main UI overlayed on scrolling BG
BG1 - pop in move effect windows
BG0 - text windows

Mosaic effect used when transitioning between screens and actvating
effect windows is controlled by tMosaicStrength in the relevant
task functions.

BG scrolling speed can be modified by altering the value parameter
of the ChangeBgX and ChangeBgY functions in VBlank()

Main UI and shadow transparency levels can be adjusted by changing the
value written to the alpha blend register in this line in bw_summary_screen.c:

static void InitBGs(void)
...
SetGpuReg(REG_OFFSET_BLDALPHA, BLDALPHA_BLEND(14, 6));
...
}

*/

/* ravetodo in future updates
- extended move desc window
- ribbons
*/

#endif // GUARD_CONFIG_SUMMARY_SCREEN_H
