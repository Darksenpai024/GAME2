#include <iostream>
using namespace std;

// Rules -----------------------------------------------------------------------------------------------------------------------------------
int rules(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================================================⌦" << "\n";
    cout << "The game revolves around exploring and fighting. To prepare a campaign, grab a hero sheet and choose a class and name." << "\n"
         << "For each stat: Mind, Body, Health and Form, you will need to roll stats. To do so, Throw 4 d6 four times and write "    << "\n"
         << "down the value by summing the 3 highest numbers you get in each four die throw. Then, choose the stats to which you "   << "\n"
         << "would like to assign each of the four values you got."                                                          << "\n" << "\n"
         << "Each stat as a specific use:"                                                                                           << "\n"
         << "» Mind: Used for learning spells and for interactions between characters and npcs."                                     << "\n"
         << "- For example, higher mind level leads to store discounts."                                                             << "\n"
         << "» Body: It represents your max carrying capacity for items."                                                            << "\n"
         << "» Health: Like every other RPG, it represents your hero's health points."                                               << "\n"
         << "» Form: This stat is used to determine attack priority (higher value attacks first) and is used to learn skills."       << "\n"
         << "- Round order of play goes from highest to lowest level of form of all battle participants."                    << "\n" << "\n"
         << "Each class has a stat of tiles per round (t/r), advantages/disadvantages and even starter skills and spells, so choose" << "\n"
         << "according to your preference."                                                                                  << "\n" << "\n"
         << "Equipment cannot be changed until all enemies are cleared if you are in a fighting scenario!"                           << "\n"
         << "'Active' Equipment comprises of 1 Head Slot, 1 Body Slot, 1 Main Weapon Slot, 3 Pendant Slots and 4 Skill/Spell slots." << "\n"
         << "Other items have no restrictions other than the ones each one specifies in its info.                          " << "\n" << "\n"
         << "In a round, you may only do one action, such as moving tiles, attacking, consuming items or using skills or spells.   " << "\n"
         << "Keep in mind some skills and spells do allow for more than one action (Check Before/For the Turn info in Class board)." << "\n"
         << "Upon leaving a location, any shields that remained after clearing such location are lost!"                      << "\n" << "\n"
         << "Leveling up is pretty straight forward: you start at Fool Level 0. To level up each time, you require x10 the next "    << "\n"
         << "level number. For example, a hero at fool level needs 10 xp to reach level 1. As you level up, you will unlock rewards "<< "\n"
         << "(list can be consulted in Info Menu), and will be able to spend two +1 in any stat and you heal your HP fully." << "\n" << "\n"
         << "Most of the game can be easily learned just by playing :) so have fun and have memorable adventures!  "                 << "\n";
    cout << "⌫====================================================================================================================⌦" << "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";;
    return 0;
}
//------------------------------------------------------------------------------------------------------------------


// Class List ------------------------------------------------------------------------------------------------------------------------------
int classes(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫========================================╦===========================================================================⌦" << "\n";
    cout << "Class List: (modifiers, ad. and disad.)  ╎ (Starter Abilities)                                                        " << "\n";
    cout << "» Healer    ▹≻   2 T/R ┄ +2 M ┄ -1 HP    ╎                                                                            " << "\n";
    cout << " +1 damage against all creatures         ╎ Fast Heal I ▹ For the turn, 3.d6 » if 8/14/18 heal 3 HP to anyone          " << "\n";
    cout << " -1 damage against all non-creatures     ╎ Moral Support ▹ FT, 1.d6 » if 1/6 close party members do +1 dmg next round " << "\n";
    cout << "» Bard      ▹≻   2 T/R ┄ +3 M ┄ -1 B     ╎                                                                            " << "\n";
    cout << " +1 damage while in forest               ╎ Medicinal Rhythm ▹ For the turn, 2.d6 » 9/10 heal 2 HP to any close target " << "\n";
    cout << " -2 HP when entering dungeons rooms      ╎ Bard's Note I ▹ For the turn, 2.d6 » 7 do 2 Dmg to one target in 3t range  " << "\n";
    cout << "» Monk      ▹≻   1 T/R ┄ +2 M ┄ +2 B     ╎                                                                            " << "\n";
    cout << " entering ruin room gives 2 shields      ╎ Shining Aura ▹ Before turn, 2.d6 » 2/8/12 to stop close enemy attack       " << "\n";
    cout << " -1 damage against all animals           ╎ Rune Ram ▹ For the turn, 4.d6 » <10 or >20 push close target 2 tiles back  " << "\n";
    cout << "» Mage      ▹≻   2 T/R ┄ +3 M ┄ -3 B     ╎                                                                            " << "\n";
    cout << " +1 damage against all creatures         ╎ Flame Cast ▹ For the turn, 1.d6 » 2, 1 enemy loses 1 HP for 1.d6 rounds    " << "\n";
    cout << " humans do +1 damage in close combat     ╎ Freeze ▹ For the turn, 1.d6 » 4 freeze enemy in tile next round            " << "\n";
    cout << "» Trickster ▹≻   3 T/R ┄ +2 F ┄ -4 HP    ╎                                                                            " << "\n";
    cout << " gain 1 shield entering forest rooms     ╎ Quick Dart ▹ For the turn, 2.d6 » if 2/5/10 hit any target for 1 damage    " << "\n";
    cout << " enemies do +1 damage in close combat    ╎ Thorn Trap ▹ -4 HP to plant trap anywhere (-1 HP to close enemies) (1 max) " << "\n";
    cout << "» Alchemist ▹≻   1 T/R ┄ +3 M ┄ +2 HP    ╎                                                                            " << "\n";
    cout << " ranged weapons and throwables do +1 dmg ╎ Transmutation I ▹ Before the turn, lose 4 HP to do 2 damage anywhere       " << "\n";
    cout << " -1 damage against all creatures         ╎ Transmutation II ▹ Before the turn, lose 3 HP » 4 T/R (for that round)     " << "\n";
    cout << "» Scavenger ▹≻   2 T/R ┄ +3 F ┄ -3 HP    ╎                                                                            " << "\n";
    cout << " while in ruin » 3 tiles per round       ╎ Salvage ▹ Upon kill, instead of gaining XP and loot, heal HP fully         " << "\n";
    cout << " -1 damage against all non-animals       ╎ Cheat ▹ For the turn, 2.d6 » 4/7/12 stop 1 enemy's attack next round       " << "\n";
    cout << "» Cleric    ▹≻   1 T/R ┄ +4 M ┄ -2 HP    ╎                                                                            " << "\n";
    cout << " gain 5 more XP per kill                 ╎ Restore ▹ For the turn, 1.d6 » 1/2/6 heal your HP by 1                     " << "\n";
    cout << " creatures do +1 damage in close combat  ╎ Holy Gift ▹ Before the turn, 2.d6 » if 4/9/12 do +1 Dmg                    " << "\n";
    cout << "» Knight    ▹≻   2 T/R ┄ +2 HP ┄ +2 F    ╎                                                                            " << "\n";
    cout << " humans deal -1 damage in close combat   ╎ Armoured ▹ For the turn, 3.d6 » if 5/10/15 gain 2 shield (not stackable)   " << "\n";
    cout << " while in ruin » 1 tile per round        ╎ Stationary ▹ F and T/R » 0 and you do +1 damage until the room is cleared  " << "\n";
    cout << "» Barbarian ▹≻   2 T/R ┄ +2 B ┄ +1 F     ╎                                                                            " << "\n";
    cout << " +1 damage against all animals           ╎ Impulse ▹ For the turn, 1.d6 » if 3/5 push close target 1t back, do 1 dmg  " << "\n";
    cout << " every purchase/craft costs +10 coins    ╎ Frenzy ▹ Before the turn, 1.d6 » 3, lose 3 HP and for +2 damage            " << "\n";
    cout << "⌫────────────────────────────────────────┴───────────────────────────────────────────────────────────────────────────⌦" << "\n";
    cout << "There are 3 types of enemy: human, animal and creature.                                                               " << "\n";
    cout << "Being 'close' means being in any 8's direction tile of entity.                                                        " << "\n";
    cout << "'For the Turn' (FT) means it uses the action for that round and you may not do anything else.                         " << "\n";
    cout << "'Before the Turn' (BT) will let you use the ability and then do an action (adds one action to your turn).             " << "\n";
    cout << "Keep in mind you can't use more than one BT in one turn.                                                              " << "\n";
    cout << "⌫====================================================================================================================⌦" << "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}
//------------------------------------------------------------------------------------------------------------------


// Level-up Rewards Explanation ------------------------------------------------------------------------------------------------------------
int rewards(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫==================================================================================⌦"<< "\n";
    cout << "Level-up Rewards Table:"                                                             << "\n";
    cout << "» Lvl 10: Explorer I    » Explorer Hat: +1 HP | +5 xp per kill | 0.5w"               << "\n";
    cout << "» Lvl 20: Explorer II   » Explorer Shirt: +1 HP | +5 xp per kill | 1w"               << "\n";
    cout << "» Lvl 30: Adventurer I  » Success Pendant: After each kill, heal 3 HP | 0.5w"        << "\n";
    cout << "» Lvl 40: Adventurer II » Adventurer Pendant: +2 coins and +5 xp per kill | 0.5w"    << "\n";
    cout << "» Lvl 50: Hunter I      » Hunter's Goggles: -2 HP, +1 F | 1.d6 » if 1/6 +1 Dmg | 1w" << "\n";
    cout << "» Lvl 60: Hunter II     » Hunter's Jacket: -1 HP, +3 F | Crossbows do +1 Dmg | 3w"   << "\n";
    cout << "» Lvl 70: Hero I        » True Hero's Helmet: +2 HP | +1 HP * nr of allies | 3.5w"   << "\n";
    cout << "» Lvl 80: Hero II       » True Hero's Armour: +3 HP | True weapons do +1 Dmg | 4w"   << "\n";
    cout << "» Lvl 90: Legend I      » Dragonraven FULL Armour: +10 HP | +1 Dmg to Bosses | 10w"  << "\n";
    cout << "» Lvl 100: Legend II    » Chimera's Whip: 4 Dmg + 1.d6 | 2t | 3w"                    << "\n";
    cout << "⌫==================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}
//------------------------------------------------------------------------------------------------------------------


// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
int healer(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "Healer Skills and Spells:"                                                             << "\n";
    cout << " Form 25 ╎ Fast Heal II ▹ For the turn, 3.d6 » if 12/14/16 heal 5 HP to anyone"        << "\n";
    cout << " Mind 25 ╎ Mind Aura I ▹ For the turn, 2.d6 » 9/11 gain 2 Shield (spell doesn't stack)"<< "\n" << "\n";
    
    cout << " Form 35 ╎ Flavour Renewal ▹ Before the turn, 1.d6 » 1/3/6 eating food restores +2 HP" << "\n";
    cout << " Mind 35 ╎ Pure Touch ▹ For the turn, 1.d6 » 2, heal 3 HP and +2 Shield a close ally"  << "\n" << "\n";

    cout << " Form 50 ╎ Intervention ▹ Lose 12 HP and in return heal 8 HP to someone else"          << "\n";
    cout << " Mind 50 ╎ Mind Aura II ▹ For the turn, 2.d6 » 8/12 gain 4 Shield (spell doesn't stack)"<< "\n" << "\n";

    cout << " Form 70 ╎ Fast Heal III ▹ For the turn, 2.d6 » if 8/9/12 heal 6 HP to anyone"         << "\n";
    cout << " Mind 70 ╎ Pain Link ▹ For the round, lose your turn to suffer ALL Dmg one ally takes" << "\n" << "\n";
                                   
    cout << " Form 95 ╎ Guardian ▹ For the turn, 3.d6 » 12/14 +4 Shield and 1-turn +1 Dmg to anyone"<< "\n";
    cout << " Mind 95 ╎ Resurrection ▹ If an ally dies, 1.d6 » 3 resurrects them (one chance only)" << "\n" << "\n";
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}

int bard(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "Bard Skills and Spells:"                                                               << "\n";
    cout << " Form 25 ╎ Inspiring Melody ▹ For the turn, 1.d6 » 1 for the next round T/R = 4"       << "\n";
    cout << " Mind 25 ╎ Bad Perfomance ▹ Before the turn, 2.d6 » 7 lose 3 HP and do +1 Dmg"         << "\n" << "\n";
    
    cout << " Form 35 ╎ Dissonant Strings ▹ For the turn, 1.d6 » 4 do 2 Dmg in a 2t area to all"    << "\n";
    cout << " Mind 35 ╎ Songs of Restoration ▹ For the turn, 2.d6 » 6/10 heal 2 HP to anyone"       << "\n" << "\n";

    cout << " Form 50 ╎ Bard's Note II ▹ For the turn, 2.d6 » 8 do 4 Dmg to one target in 3t radius"<< "\n";
    cout << " Mind 50 ╎ Charming Verse ▹ For the turn, 2.d6 » 7 stun one enemy for that round"      << "\n" << "\n";

    cout << " Form 70 ╎ Melodic Echo ▹ For the turn, 2.d6 » 6/11, do weapon Dmg*2 - 3"              << "\n";
    cout << " Mind 70 ╎ Serenade ▹ For the round, Heal 6 HP to anyone, but lose next 2 rounds"      << "\n" << "\n";

    cout << " Form 95 ╎ Cacophony ▹ For the turn 1.d6 » 1, allies lose 1 HP, enemies lose 3 HP"     << "\n";
    cout << " Mind 95 ╎ Tales of Valor ▹ 1.d6 » 1/6 next round all party does +1 Dmg"               << "\n" << "\n";
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}

int monk(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "Monk Skills and Spells:"                                                               << "\n";
    cout << " Form 25 ╎ Way of the Wind ▹ Before the turn, 2.d6 » 7 T/R = 3 and +5 F next round"    << "\n";
    cout << " Mind 25 ╎ Inner Peace ▹ For the turn, 1.d6 » 3 heal 3 HP and move 2t away from enemy" << "\n" << "\n";
    
    cout << " Form 35 ╎ Meditation I ▹ For the turn, lose the next 2 rounds and heal 3 HP in each"  << "\n";
    cout << " Mind 35 ╎ Energy Burst ▹ For the turn, 1.d6 » 2, do 3 Dmg to all in a 3t line ahead"  << "\n" << "\n";

    cout << " Form 50 ╎ Iron Body ▹ For the turn, 2.d6 » 8/9 heal 2 HP and gain 1 Shield"           << "\n";
    cout << " Mind 50 ╎ True Focus ▹ Until room is cleared, F » 0 and heal 1 HP after every round"  << "\n" << "\n";

    cout << " Form 70 ╎ Meditation II ▹ For the turn, lose the next 2 rounds and heal 5 HP in each" << "\n";
    cout << " Mind 70 ╎ Eat or Run ▹ Before the turn, food heals +1 HP or T/R = 2 for that round"   << "\n" << "\n";

    cout << " Form 95 ╎ True Focus ▹ Until room is cleared, F » 0 and heal 1 HP after every round"  << "\n";
    cout << " Mind 95 ╎ Rising Dragon Aura ▹ Before the turn, 1.d6 » 5, do +2 Dmg and heal 2 HP"    << "\n" << "\n";
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}

int mage(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "Mage Skills and Spells:"                                                               << "\n";
    cout << " Form 25 ╎ Fireball ▹ For the turn, 2.d6 » 7, do 3 Dmg to target in 3t radius"         << "\n";
    cout << " Mind 25 ╎ Mana Shield I ▹ For the turn, 1.d6 » 1, gain 1 Shield (doesn't stack)"      << "\n" << "\n";
    
    cout << " Form 35 ╎ Chain Lightning ▹ For the turn, 3.d6 » 10/13/16 do 2 Dmg to any 2 enemies"  << "\n";
    cout << " Mind 35 ╎ Mana Shield II ▹ For the turn, 1.d6 » 1, gain 3 Shield (doesn't stack)"     << "\n" << "\n";

    cout << " Form 50 ╎ Health Warp, Before the turn, 2.d6 » 5/6, any Dmg done will heal you equal" << "\n";
    cout << " Mind 50 ╎ Tile Trade ▹ For the turn, 2.d6 » 11/12, change position with any ally"     << "\n" << "\n";

    cout << " Form 70 ╎ Summon Familiar ▹ For the turn, 2.d6 » 3/11, 1 T/R ┄ 12 HP ┄ 1 Dmg (1 max)" << "\n";
    cout << " Mind 70 ╎ Hit Mirror ▹ For the turn, 1.d6 » 6, copy a close target Dmg and deal it"   << "\n" << "\n";

    cout << " Form 95 ╎ Teleport ▹ For the turn, 3.d6 » 12/15, lose 2 HP and move to any tile"      << "\n";
    cout << " Mind 95 ╎ Arcane Blast ▹ For the turn, 3.d6 » 11/17, do 8 Dmg to target in 4t radius" << "\n" << "\n";
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}

int trickster(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "Trickster Skills and Spells:"                                                          << "\n";
    cout << " Form 25 ╎ Sneak Hit ▹ For the turn, if 1.d6 » 3 do 5 Dmg to close target, else -2 HP" << "\n";
    cout << " Mind 25 ╎ Disguise ▹ Copy stats from anyone and play with them until room is cleared" << "\n" << "\n";
    
    cout << " Form 35 ╎ Smoke Bomb ▹ For the turn, 1.d6 » 6, T/R = 1 and +8 F until room is cleared"<< "\n";
    cout << " Mind 35 ╎ Fear Illusion ▹ For the turn, 1.d6 » 2 make one enemy step back 2 tiles"    << "\n" << "\n";

    cout << " Form 50 ╎ Trickster's Gambit ▹ In a 2t range, 2.d6 value is your Dmg done and HP lost"<< "\n";
    cout << " Mind 50 ╎ Deceive ▹ For the turn, 3.d6 » 13/15/17, decide 1 enemy's action this round"<< "\n" << "\n";

    cout << " Form 70 ╎ Fake Terrain ▹ For the turn, 2.d6 » 5/11 change location for next 2 rounds" << "\n";
    cout << " Mind 70 ╎ Trickster's Cheat ▹ 1.d6 » 3 and you kill an enemy next round, heal 10 HP"  << "\n" << "\n";

    cout << " Form 95 ╎ Sleight of Hand ▹ For the turn, 2.d6 » 2/12 turn 1 enemy's Dmg to 3 (perm.)"<< "\n";
    cout << " Mind 95 ╎ Slow Sands ▹ For the turn, 1.d6 » 1, to ALL, but you, T/R = 1 until cleared"<< "\n" << "\n";
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}

int alchemist(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "Alchemist Skills and Spells:"                                                          << "\n";
    cout << " Form 25 ╎ Potion Toss ▹ For the turn, 1.d6 » 2/4: heal 2 HP, 3/5: 3 Dmg close target" << "\n";
    cout << " Mind 25 ╎ Transmutation III ▹ Before the turn, lose 6 HP for +1 Dmg and T/R = 2"      << "\n" << "\n";
    
    cout << " Form 35 ╎ Mutated Barrier ▹ For the turn, 1.d6 » 1, place barrier anywhere (2 max)"   << "\n";
    cout << " Mind 35 ╎ Alchemist's Grace ▹ For the turn, 2.d6 » 7, heal all close targets by 3 HP" << "\n" << "\n";

    cout << " Form 50 ╎ Brewing I ▹ For the turn, 2.d6 » 8/9 creates Care Bottle: Heals 2 HP | 0.5w"<< "\n";
    cout << " Mind 50 ╎ Explosive Rune ▹ For the turn, 3.d6 » 6/10/15, do 2 Dmg in 2t radius"       << "\n" << "\n";

    cout << " Form 70 ╎ Brewing II ▹ For the turn, 2.d6 » 9 creates Healing Potion: Heals 5 HP | 1w"<< "\n";
    cout << " Mind 70 ╎ Summon Homunculus ▹ For the turn, lose 10 HP, 2 T/R ┄ 8 HP ┄ 2 Dmg (1 max)" << "\n" << "\n";

    cout << " Form 95 ╎ Equivalent Exchange ▹ For the turn, 2.d6 » odd, you and 1 target lose 10 HP"<< "\n";
    cout << " Mind 95 ╎ Philosopher's Stone ▹ Before the turn, if 1.d6 » 1/3/6, +3 Dmg and T/R = 3" << "\n" << "\n";
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}

int scavenger(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "Scavenger Skills and Spells:"                                                          << "\n";
    cout << " Form 25 ╎ Resourceful Repair ▹ 1.d6 » 2, consume floor item to gain 1 Shield if found"<< "\n";
    cout << " Mind 25 ╎ Rummage ▹ Upon entering room, 2.d6 » 5/11, doubles floor item if one found" << "\n" << "\n";
    
    cout << " Form 35 ╎ Resourceful Scrounge ▹ Upon kill, 1.d6 » 1/6, instead of xp, get xp/2 coins"<< "\n";
    cout << " Mind 35 ╎ Camouflage ▹ For the turn, 2.d6 » 8, +8 F and T/R = 2 for next 2 rounds"    << "\n" << "\n";

    cout << " Form 50 ╎ Survival Instinct ▹ For the turn, 2.d6 » 7, T/R = 1 and +1 Dmg next round"  << "\n";
    cout << " Mind 50 ╎ Weakness Detection ▹ Before the turn, 2.d6 » 2/6/12 do +2 Dmg"              << "\n" << "\n";

    cout << " Form 70 ╎ Quick Escape ▹ For the turn, 1.d6 » 3/4, lose 1 HP and move 3 tiles"        << "\n";
    cout << " Mind 70 ╎ Hidden Cache ▹ Upon clearing room, 2.d6 » 8, heal full HP and gain 5 coins" << "\n" << "\n";

    cout << " Form 95 ╎ Desperate Gambit ▹ When Scavenger's HP is below 10, do +2 Dmg and T/R = 2"  << "\n";
    cout << " Mind 95 ╎ Pack Rat ▹ Upon kill, 1.d6 » 2/5, If enemy dropped item w > 2 lower it by 1"<< "\n" << "\n";
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}

int cleric(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "Cleric Skills and Spells:"                                                             << "\n";
    cout << " Form 25 ╎ Holy One's Choice ▹ For the turn, 1.d6 » even heal 2 HP, if odd lose 1 HP"  << "\n";
    cout << " Mind 25 ╎ Divine Smite ▹ Before the turn, 1.d6 » 2, for that round, weapon range +2"  << "\n" << "\n";
    
    cout << " Form 35 ╎ Past Recall ▹ For the turn, 1.d6 » 2/5, go back 3 tiles"                    << "\n";
    cout << " Mind 35 ╎ Benediction ▹ For the turn, 1.d6 » 3, heal all close targets by 2 HP"       << "\n" << "\n";

    cout << " Form 50 ╎ Holy Nova ▹ For the turn, 2.d6 » 9, do 1 Dmg to all enemies and heal 2 HP"  << "\n";
    cout << " Mind 50 ╎ Blessing of Protection ▹ For the turn, 2.d6 » 5/9/11, gain 3 Shield (1 use)"<< "\n" << "\n";

    cout << " Form 70 ╎ Banishment ▹ For the turn, 3.d6 < 8, push close target back 2t and do 2 Dmg"<< "\n";
    cout << " Mind 70 ╎ Judgement ▹ For the turn, 3.d6 > 12, deal 5 Dmg to the enemy with lowest HP"<< "\n" << "\n";

    cout << " Form 95 ╎ Resilience ▹ Before the turn, 2.d6 » 6/11, gain 2 Shield and +2 Dmg"        << "\n";
    cout << " Mind 95 ╎ Resurrection ▹ If an ally dies, 1.d6 » 1 resurrects them (one chance only)" << "\n" << "\n";
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}

int knight(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "Knight Skills and Spells:"                                                             << "\n";
    cout << " Form 25 ╎ Shield Bash ▹ For the turn, 1.d6 » 1 push enemy back 1t, if 6 stun for 1 r" << "\n";
    cout << " Mind 25 ╎ Valor Call ▹ For the turn, 1.d6 » 3, party attacks first next round"        << "\n" << "\n";
    
    cout << " Form 35 ╎ Brave Charge ▹ For the turn, 2.d6 » 10/12, charge an enemy and do 3 Dmg"    << "\n";
    cout << " Mind 35 ╎ Shield of Justice ▹ For the turn, 1.d6 » 1/6, all party gets 1 Shield"      << "\n" << "\n";

    cout << " Form 50 ╎ Sword Mastery ▹ Before the turn, 2.d6 » 7, melee weapons do +1 Dmg"         << "\n";
    cout << " Mind 50 ╎ Bow Mastery ▹ Before the turn, 2.d6 » 7, ranged weapons do +1 Dmg"          << "\n" << "\n";

    cout << " Form 70 ╎ Battle Charge ▹ For the turn, 2.d6 » 9, charge enemy, do 3 Dmg and heal 1 HP"<< "\n";
    cout << " Mind 70 ╎ Battle Cry ▹ For the turn, 2.d6 » 10, +6 F and +1 Dmg next round (1 max)"   << "\n" << "\n";

    cout << " Form 95 ╎ Last Stand ▹ When HP < 15, T/R = 1 and enemies do -1 Dmg in close range"    << "\n";
    cout << " Mind 95 ╎ Divine Protection ▹ For the turn, 1.d6 » 4, heal 2 HP and gain 2 Shield"    << "\n" << "\n";
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}

int barbarian(){
    string goback;
    for (int i = 0; i < 1000; i++){
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "Barbarian Skills and Spells:"                                                          << "\n";
    cout << " Form 25 ╎ Battle Roar ▹ For the turn, 1.d6 » 5, enemies have -5 F for the next round" << "\n";
    cout << " Mind 25 ╎ Enrage ▹ For the turn, remain still and get +1 Dmg (3 max, resets if hit)"  << "\n" << "\n";
    
    cout << " Form 35 ╎ All's Blood ▹ Before the turn, +2 Dmg and T/R = 3, but lose 5 HP next round"<< "\n";
    cout << " Mind 35 ╎ Intimidation ▹ Before the turn, 2.d6 » 6/9, stun 1 enemy for the next round"<< "\n" << "\n";

    cout << " Form 50 ╎ Enrage ▹ For the turn, remain still and get +1 Dmg (3 max, resets if hit)"  << "\n";
    cout << " Mind 50 ╎ Call Wolf ▹ For the turn, 2d.6 » 6/13, 3 T/R ┄ 4 HP ┄ 2 Dmg (2 max)"        << "\n" << "\n";

    cout << " Form 70 ╎ Battle Charge ▹ For the turn, 2.d6 » 9, charge enemy, do 3 Dmg and heal 1 HP"<< "\n";
    cout << " Mind 70 ╎ Battle Renewal ▹ For the turn, 1.d6 » 4/5, heal 8 HP but lose next round"   << "\n" << "\n";

    cout << " Form 95 ╎ Bloodlust ▹ For the turn, 1.d6 » 2, for next 2 rounds: +1 Dmg, dmg heals HP"<< "\n";
    cout << " Mind 95 ╎ Beast Presence ▹ For the turn, 2.d6 » 7, do 4 Dmg to all close targets"     << "\n" << "\n";
    cout << "⌫====================================================================================⌦"<< "\n";
    cout << "» Write 'info'/'i' to go back ◼▶ ";
    cin >> goback;
    if (goback == "info" || goback == "i") break;
    else cout << "» Please write a valid input!" << "\n";
    }
    cout << "\n" << "\n";
    return 0;
}



// Skills and Spells Class Board -----------------------------------------------------------------------------------
int skillsandspells(){
    string choice;
    for (int i = 0; i < 10000; i++){
        cout << "⌫================================================⌦" << "\n";
        cout << "Choose a Class to view its Skills and Spells:"      << "\n";
        cout << "⍆ Healer                                       (0)" << "\n";
        cout << "⍆ Bard                                         (1)" << "\n";
        cout << "⍆ Monk                                         (2)" << "\n";
        cout << "⍆ Mage                                         (3)" << "\n";
        cout << "⍆ Trickster                                    (4)" << "\n";
        cout << "⍆ Alchemist                                    (5)" << "\n";
        cout << "⍆ Scavenger                                    (6)" << "\n";
        cout << "⍆ Cleric                                       (7)" << "\n";
        cout << "⍆ Knight                                       (8)" << "\n";
        cout << "⍆ Barbarian                                    (9)" << "\n";
        cout << "⍆ Return to Info Menu                          (m)" << "\n";
        cout << "⌫================================================⌦" << "\n" << "◼▶ ";
        cin >> choice; cout << "\n";
        if (choice == "menu" || choice == "m"){
            usleep(610000);
            cout << "\n" << "» Returning to Menu..." << "\n";
            usleep(610000);
            break;
        }
        else if (choice == "healer" || choice == "0") healer();
        else if (choice == "bard" || choice == "1") bard();
        else if (choice == "monk" || choice == "2") monk();
        else if (choice == "mage" || choice == "3") mage();
        else if (choice == "trickster" || choice == "4") trickster();
        else if (choice == "alchemist" || choice == "5") alchemist();
        else if (choice == "scavenger" || choice == "6") scavenger();
        else if (choice == "cleric" || choice == "7") cleric();
        else if (choice == "knight" || choice == "8") knight();
        else if (choice == "barbarian" || choice == "9") barbarian();
        else cout << "» Please write a valid input!" << "\n";
    }
    return 0;
}
//------------------------------------------------------------------------------------------------------------------


// General Info Menu -----------------------------------------------------------------------------------------------
int info(){
    string choice;
    for (int i = 0; i < 10000; i++){
        cout << "⌫==========================================================⌦" << "\n";
        cout << "What are you looking for?"                                    << "\n";
        cout << "⍆ Rules                                                  (r)" << "\n";
        cout << "⍆ Class                                                  (c)" << "\n";
        cout << "⍆ Level-up Rewards                                       (l)" << "\n";
        cout << "⍆ Skills and Spells                                      (s)" << "\n";
        cout << "⍆ Return to Menu                                         (m)" << "\n";
        cout << "⌫==========================================================⌦" << "\n" << "◼▶ ";
        cin >> choice; cout << "\n";
        if (choice == "menu" || choice == "m"){
            usleep(610000);
            cout << "\n" << "» Returning to Menu..." << "\n";
            usleep(610000);
            break;
        }
        else if (choice == "rules" || choice == "r") { usleep(610000); rules(); }
        else if (choice == "class" || choice == "c") { usleep(610000); classes(); }
        else if (choice == "level" || choice == "l") { usleep(610000); rewards(); }
        else if (choice == "skills" || choice == "spells" || choice == "s") { usleep(610000); skillsandspells(); }
        else cout << "» Please write a valid input!" << "\n";
    }
    return 0;
}
//------------------------------------------------------------------------------------------------------------------
