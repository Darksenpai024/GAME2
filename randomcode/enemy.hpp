#include <iostream>
#include "random.hpp"
using namespace std;

// boss? quantity? mixed?
// stats | loot | xp

// Upon entering location level is asked and that value will be used for the rest of the location rooms

// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
// Damage Modifier according to Hero Level -------------------------------------------------------------------------
int dmgmodifiercheck(int level){
    if (0 <= level && level <= 15) return 0;
    else if (16 <= level && level <= 30) return 1;
    else if (31 <= level && level <= 45) return 2;
    else if (46 <= level && level <= 60) return 3;
    else if (61 <= level && level <= 75) return 4;
    else if (76 <= level && level <= 90) return 5;
    //else if (61 <= level && level <= 70) return 6;
    //else if (71 <= level && level <= 80) return 7;
    //else if (81 <= level && level <= 90) return 8;
    //else if (91 <= level && level <= 100) return 9;
    return 0;
}
// Enemy HP and Form based on Highest Hero Level -------------------------------------------------------------------
int hp_form_by_hero_level(int level){
    if (0 <= level && level <= 5) return 15;
    else if (6 <= level && level <= 10) return 20;
    else if (11 <= level && level <= 15) return 25;
    else if (16 <= level && level <= 20) return 30;
    else if (21 <= level && level <= 25) return 35;
    else if (26 <= level && level <= 30) return 40;
    else if (31 <= level && level <= 35) return 45;
    else if (36 <= level && level <= 40) return 50;
    else if (41 <= level && level <= 45) return 55;
    else if (46 <= level && level <= 50) return 60;
    else if (51 <= level && level <= 55) return 65;
    else if (56 <= level && level <= 60) return 70;
    else if (61 <= level && level <= 65) return 75;
    else if (66 <= level && level <= 70) return 80;
    else if (71 <= level && level <= 75) return 85;
    else if (76 <= level && level <= 80) return 90;
    else if (81 <= level && level <= 85) return 95;
    else if (86 <= level && level <= 90) return 100;
    else if (91 <= level && level <= 95) return 105;
    else if (96 <= level && level <= 100) return 110;
    return 0;
}
// Rewards upon clearing a Location fully --------------------------------------------------------------------------
string locationclearrewardsmall(int level){
    string reward;
    if (0 <= level && level <= 10) reward = "";
    else if (11 <= level && level <= 20) reward = "\nBattle Reward: " + to_string(rand()%11+20) + " xp and " + to_string(rand()%6+3) + " coins";
    else if (21 <= level && level <= 30) reward = "\nBattle Reward: " + to_string(rand()%11+30) + " xp and " + to_string(rand()%6+3) + " coins";
    else if (31 <= level && level <= 40) reward = "\nBattle Reward: " + to_string(rand()%11+40) + " xp and " + to_string(rand()%6+10) + " coins";
    else if (41 <= level && level <= 50) reward = "\nBattle Reward: " + to_string(rand()%11+50) + " xp and " + to_string(rand()%6+10) + " coins";
    else if (51 <= level && level <= 60) reward = "\nBattle Reward: " + to_string(rand()%11+60) + " xp and " + to_string(rand()%8+18) + " coins";
    else if (61 <= level && level <= 70) reward = "\nBattle Reward: " + to_string(rand()%11+70) + " xp and " + to_string(rand()%8+18) + " coins";
    else if (71 <= level && level <= 80) reward = "\nBattle Reward: " + to_string(rand()%11+80) + " xp and " + to_string(rand()%8+28) + " coins";
    else if (81 <= level && level <= 90) reward = "\nBattle Reward: " + to_string(rand()%11+90) + " xp and " + to_string(rand()%8+28) + " coins";
    else if (91 <= level && level <= 100) reward = "\nBattle Reward: " + to_string(rand()%11+100) + " xp and " + to_string(rand()%11+35) + " coins";
    return reward;
}
string locationclearrewardbig(int level){
    string reward;
    if (0 <= level && level <= 10) reward = "";
    else if (11 <= level && level <= 20) reward = "\nBattle Reward: " + to_string(rand()%11+20 +10) + " xp and " + to_string(rand()%6+3 +3) + " coins";
    else if (21 <= level && level <= 30) reward = "\nBattle Reward: " + to_string(rand()%11+30 +10) + " xp and " + to_string(rand()%6+3 +3) + " coins";
    else if (31 <= level && level <= 40) reward = "\nBattle Reward: " + to_string(rand()%11+40 +10) + " xp and " + to_string(rand()%6+10 +3) + " coins";
    else if (41 <= level && level <= 50) reward = "\nBattle Reward: " + to_string(rand()%11+50 +10) + " xp and " + to_string(rand()%6+10 +3) + " coins";
    else if (51 <= level && level <= 60) reward = "\nBattle Reward: " + to_string(rand()%11+60 +10) + " xp and " + to_string(rand()%8+18 +3) + " coins";
    else if (61 <= level && level <= 70) reward = "\nBattle Reward: " + to_string(rand()%11+70 +10) + " xp and " + to_string(rand()%8+18 +3) + " coins";
    else if (71 <= level && level <= 80) reward = "\nBattle Reward: " + to_string(rand()%11+80 +10) + " xp and " + to_string(rand()%8+28 +3) + " coins";
    else if (81 <= level && level <= 90) reward = "\nBattle Reward: " + to_string(rand()%11+90 +10) + " xp and " + to_string(rand()%8+28 +3) + " coins";
    else if (91 <= level && level <= 100) reward = "\nBattle Reward: " + to_string(rand()%11+100 +10) + " xp and " + to_string(rand()%11+35 +3) + " coins";
    return reward;
}
//------------------------------------------------------------------------------------------------------------------
// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

// FOR THESE CHECK QUANTITY!! VERY IMPORTANT TO DETERMINE ENEMIES!! 
// stats | xp upon kill | chance for drop

int statcalculator(int h){ // stat - 3 <= stat <= stat + 3
    int randomstat1 = rand() % 4; int modifierone = rand() % 2 + 1;
    int enemystat = h;
    if (modifierone == 1) enemystat = enemystat-randomstat1;
    else enemystat = enemystat+randomstat1;
    return enemystat;
}

// ━╌1╌━
// ━╌2╌━
// ━╌3╌━

// ━-1-━
// ━-2-━
// ━-3-━

// ENEMIES ---------------------------------------------------------------------------------------------------------

int skeleton(int level, int amount, int enemycounter = 1){
    // enemycounter is used to keep track of enemy 'id', so to speak while in fight (default start value set to 1)
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns
        checkleader = true;
        amount--;
    }
    if (checkleader){ // has different stats and different drops
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM); // using avg HP/FORM value, calculate random stat
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Creature) Skeleton Leader: "                                             << "\n";
        cout << "» HP: " << enemyhp - 1 << " | F: " << statcalculator(HP_FORM) - 1 
             << " | Dmg: " << 2 + dmgmodifier << " | T/R: 2 | Range: 2t"                     << "\n";
        cout << "» Drops ";
        if (lootcheck <= 5) cout << "a Human Skull: Worth 3 coins | 1w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Creature) Skeleton: "                                                    << "\n";
        cout << "» HP: " << enemyhp - 3 << " | F: " << statcalculator(HP_FORM) - 3
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 2 | Range: 2t"                     << "\n";
        cout << "» Drops ";
        if (lootcheck <= 3) cout << "a Human Bone: 1 Dmg | 0.5w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true; // this is here because in line 125 i was too lazy and stupid to do 'else if (enemycounter > 1)' :)
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int guard(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Human) Guard Leader: "                                                   << "\n";
        cout << "» HP: " << enemyhp + 2 << " | F: " << statcalculator(HP_FORM) - 2 
             << " | Dmg: " << 2 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 5) cout << "a Bag of Coins: Contains 10 coins \n» and ";
        cout << enemyhp - (enemyhp % 10) + 10 << " xp. "                                     << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Human) Guard: "                                                          << "\n";
        cout << "» HP: " << enemyhp + 1 << " | F: " << statcalculator(HP_FORM) - 1
             << " | Dmg: " << 2 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 3) cout << "a Small Bag of Coins: Contains 5 coins \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int mutant(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Human/Creature) Mutant Leader: "                                         << "\n";
        cout << "» HP: " << enemyhp << " | F: " << statcalculator(HP_FORM) - 5
             << " | Dmg: " << 2 + dmgmodifier << " | T/R: 2"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 5) cout << "a Mutated Limb: 2 Dmg | +1 F | 1w \n» and ";
        else if (lootcheck == 10) cout << "a Human Bone: 1 Dmg | 0.5w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 10 << " xp. "                                     << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Human/Creature) Mutant: "                                                << "\n";
        cout << "» HP: " << enemyhp - 2 << " | F: " << statcalculator(HP_FORM) - 2
             << " | Dmg: " << 2 + dmgmodifier << " | T/R: 2"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 3) cout << "Ragged Cloths: -1 HP, +3 F | 1w \n» and ";
        else if (lootcheck == 10) cout << "a Human Bone: 1 Dmg | 0.5w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int wolf(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Animal) Alpha Wolf: +1 Dmg * Wolf Count "                                << "\n";
        cout << "» HP: " << enemyhp - 1 << " | F: " << statcalculator(HP_FORM) + 5 
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 4) cout << "Wolf Fur: Worth 10 coins | 1.5w \n» and ";
        else if (lootcheck == 10) cout << "Big Animal Bone: Worth 6 coins | 2w | Stacks to 2 \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Animal) Wolf: "                                                          << "\n";
        cout << "» HP: " << enemyhp - 1 << " | F: " << statcalculator(HP_FORM) + 3
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 3"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 3) cout << "Wolf Claw: Worth 3 coins | 0.5w | Stacks to 4 \n» and ";
        else if (lootcheck >= 9) cout << "Animal Bone: Worth 3 coins | 1.5w | Stack to 3 \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int slime(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Animal/Creature) Big Slime: "                                            << "\n";
        cout << "» HP: " << enemyhp - 1 << " | F: " << statcalculator(HP_FORM) + 5
             << " | Dmg: " << 2 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 4) cout << "Slime Liver: Worth 12 coins | 0.5w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Animal/Creature) Slime: "                                                << "\n";
        cout << "» HP: " << enemyhp - 3 << " | F: " << statcalculator(HP_FORM) + 1
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 2) cout << "Solidified Ooze: Worth 8 coins | 1w | Stacks to 3 \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int bucket_slime(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (~Any~) Big Bucket Slime: 1.d6 » even +1 Dmg"                             << "\n";
        cout << "» HP: " << enemyhp + 2 << " | F: " << statcalculator(HP_FORM) + 3
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 2) cout << "Bucket Hat: +1 HP | +1 Dmg to Slimes | 2w \n» and ";
        else if (lootcheck >= 9) cout << "Slime Liver: Worth 12 coins | 0.5w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 10 << " xp. "                                     << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Creature) Bucket Slime: 1.d6 » even +1 Dmg"                              << "\n";
        cout << "» HP: " << enemyhp << " | F: " << statcalculator(HP_FORM) + 1
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 4) cout << "Solidified Ooze: Worth 8 coins | 1w | Stacks to 3 \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int mimic(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Creature) Big Mimic: "                                                   << "\n";
        cout << "» HP: " << enemyhp + 3 << " | F: " << statcalculator(HP_FORM) - 3
             << " | Dmg: " << 4 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops ";
        vector<string> name_and_rarity = located_loot_lists("ruin");
        string iteminfo;
        if (name_and_rarity[1] == "common") iteminfo = item_common(name_and_rarity[0]);
        else if (name_and_rarity[1] == "uncommon") iteminfo = item_uncommon(name_and_rarity[0]);
        else if (name_and_rarity[1] == "rare") iteminfo = item_rare(name_and_rarity[0]);
        else if (name_and_rarity[1] == "ancient") iteminfo = item_ancient(name_and_rarity[0]);
        if (lootcheck <= 8) cout << iteminfo << " \n» and ";
        else if (lootcheck >= 9) cout << "a Mimic Tongue: Worth 15 coins | 0.5w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 10 << " xp. "                                     << "\n"; 
        enemycounter++;
        amount = 0; // one mimic is max
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Creature) Mimic: "                                                       << "\n";
        cout << "» HP: " << enemyhp + 1 << " | F: " << statcalculator(HP_FORM) - 5
             << " | Dmg: " << 3 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops ";
        vector<string> name_and_rarity = located_loot_lists("dungeon");
        string iteminfo;
        if (name_and_rarity[1] == "common") iteminfo = item_common(name_and_rarity[0]);
        else if (name_and_rarity[1] == "uncommon") iteminfo = item_uncommon(name_and_rarity[0]);
        else if (name_and_rarity[1] == "rare") iteminfo = item_rare(name_and_rarity[0]);
        else if (name_and_rarity[1] == "ancient") iteminfo = item_ancient(name_and_rarity[0]);
        if (lootcheck >= 3) cout << iteminfo << " \n» and ";
        else if (lootcheck <= 2) cout << "a Mimic Tongue: Worth 15 coins | 0.5w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int necromancer(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Human) Necromancer Cult Leader: "                                        << "\n";
        cout << "» HP: " << enemyhp + 1 << " | F: " << statcalculator(HP_FORM) - 5 
             << " | Dmg: " << 2 + dmgmodifier << " | T/R: 2 | Range: 3t"                     << "\n";
        cout << "» Drops ";
        if (lootcheck >= 9) cout << "a Cult Staff: 2 Dmg | +1 HP | 3t | 2w \n» and ";
        else if (lootcheck == 5) cout << "a Healing Potion: Heals 5 HP | 1w \n» and ";
        else if (lootcheck <= 3) cout << "a Human Skull: Worth 3 coins | 1w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Human) Necromancer Cult Member: "                                        << "\n";
        cout << "» HP: " << enemyhp + 2 << " | F: " << statcalculator(HP_FORM) - 3
             << " | Dmg: " << 2 + dmgmodifier << " | T/R: 2 | Range: 2t"                     << "\n";
        cout << "» Drops ";
        if (lootcheck <= 3) cout << "a Healing Potion: Heals 5 HP | 1w \n» and ";
        else if (lootcheck >= 9) cout << "a Blood Vial: Heals 10 HP | 0.5w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int bandit(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Human) Bandit Leader: "                                                  << "\n";
        cout << "» HP: " << enemyhp + 2 << " | F: " << statcalculator(HP_FORM) + 6  
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 3"                                 << "\n";
        cout << "» Drops a ";
        if (lootcheck <= 3) cout << "Stack of Arrows: 5 Arrows | Stack up to 15 \n» and ";
        else if (lootcheck == 4) cout << "Bag of Coins: Contains 10 coins \n» and ";
        else if (lootcheck >= 9) cout << "Ration: Heals party by 1 HP | 1w | Stacks to 2 \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Human) Bandit: "                                                         << "\n";
        cout << "» HP: " << enemyhp << " | F: " << statcalculator(HP_FORM) + 4
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 3"                                 << "\n";
        cout << "» Drops a ";
        if (lootcheck <= 2) cout << "Bandit Knife: 1 Dmg | +3 coins per kill | 1.5w \n» and ";
        else if (lootcheck == 3 || lootcheck == 10) cout << "Small Bag of Coins: Contains 5 coins \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int gnome(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Creature) Elder Gnome: "                                                 << "\n";
        cout << "» HP: " << enemyhp + 6 << " | F: " << statcalculator(HP_FORM) - 2 
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops a ";
        if (lootcheck <= 3) cout << "a Green Gnome Hat: Slingshots do +1 Dmg | 1w \n» and ";
        else if (lootcheck == 7) cout << "a Bag of Coins: Contains 10 coins \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Creature) Gnome: "                                                       << "\n";
        cout << "» HP: " << enemyhp + 4 << " | F: " << statcalculator(HP_FORM) - 3
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 1"                                 << "\n";
        cout << "» Drops ";
        if (lootcheck <= 5) cout << "a Bag of Pellets: 6 Pellets | Stack up to 30 \n» and ";
        else if (lootcheck == 8) cout << "Gnome Overalls: +2 HP, -2 F | 1.5w \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int fish_crawler(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int king_queen = rand() % 2 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Animal) Fish Crawler "; 
        if (king_queen == 2) cout << "King: "; 
        else if (king_queen == 1) cout << "Queen: ";
        cout << "\n" << "» HP: " << enemyhp - 2 << " | F: " << statcalculator(HP_FORM) + 5 
             << " | Dmg: " << 2 + dmgmodifier << " | T/R: 2"                                 << "\n";
        cout << "» Drops a ";
        if (lootcheck <= 3 && king_queen == 2) cout << "Crawler K Head: +3 HP, +1 F | 1.5w \n» and ";
        if (lootcheck <= 3 && king_queen == 1) cout << "Crawler Q Head: +1 HP, +3 F | 1.5w \n» and ";
        else if (lootcheck == 5) cout << "Crawler Spine: Worth 8 coins | 2w \n» and ";
        else if (lootcheck >= 9) cout << "Crawler Tooth: Worth 5 coins | Stacks to 2 \n» and ";
        cout << enemyhp - (enemyhp % 10) + 10 << " xp. "                                     << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Animal) Fish Crawler: "                                                  << "\n";
        cout << "» HP: " << enemyhp - 4 << " | F: " << statcalculator(HP_FORM) + 2
             << " | Dmg: " << 2 + dmgmodifier << " | T/R: 3"                                 << "\n";
        cout << "» Drops a ";
        if (lootcheck <= 3) cout << "Crawler Spine: Worth 8 coins | 2w \n» and ";
        else if (lootcheck == 8) cout << "Crawler Tooth: Worth 5 coins | Stacks to 2 \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
        enemycounter++;
        checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}

int siren(int level, int amount, int enemycounter = 1){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    bool checkleader = false;
    if (amount >= 3){ // every time there are more than 2 enemies, a leader spawns, having slightly more health and form and different drops
        checkleader = true;
        amount--;
    }
    if (checkleader){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Creature) Siren Leader: "                                                << "\n";
        cout << "» HP: " << enemyhp + 6 << " | F: " << statcalculator(HP_FORM) - 2 
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 2"                                 << "\n";
        cout << "» Drops a ";
        if (lootcheck <= 4) cout << "Siren Fin: Worth 6 coins | Stacks to 2 \n» and ";
        else if (lootcheck >= 9) cout << "Siren Scale: Worth 3 coins | Stacks to 3 \n» and ";
        cout << enemyhp - (enemyhp % 10) + 10 << " xp. "                                     << "\n"; 
        enemycounter++;
    }
    for (int i = 0; i < amount; i++){
        int lootcheck = rand() % 10 + 1;
        int enemyhp = statcalculator(HP_FORM);
        if (checkleader) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        else if (checkleader==false) cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌" << enemycounter << "╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
        cout << "» (Creature) Siren: "                                                       << "\n";
        cout << "» HP: " << enemyhp + 4 << " | F: " << statcalculator(HP_FORM) - 3
             << " | Dmg: " << 1 + dmgmodifier << " | T/R: 2"                                 << "\n";
        cout << "» Drops a ";
        if (lootcheck <= 3) cout << "Siren Scale: Worth 3 coins | Stacks to 3 \n» and ";
        else if (lootcheck >= 9) cout << "Siren Tooth: Worth 2 coins | Stacks to 3 \n» and ";
        cout << enemyhp - (enemyhp % 10) + 5 << " xp. "                                      << "\n"; 
       enemycounter++;
       checkleader = true;
    }
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶\n";
    return 0;
}


// BOSSES ----------------------------------------------------------------------------------------------------------
/*
10 10
4
15
*/
// messages per boss

int tomb_serpent(int level){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    int lootcheck = rand() % 10 + 1;
    if (lootcheck <= 5) cout << "From the water and eerie mist, an ominous creature appears!  ┃\n";
    else if (lootcheck >= 6) cout << "A scent of decay fills the air as a dark body rises ahead... ┃\n";
    int enemyhp = statcalculator(HP_FORM);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌1╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
    cout << "» (Boss) Tomb Serpent: "                                         << "\n";
    cout << "» HP: " << enemyhp + 6 << " | F: " << statcalculator(HP_FORM) + 12
            << " | Dmg: " << 4 + dmgmodifier << " | T/R: 3 | Range: 2t"       << "\n";
    cout << "» Drops ";
    if (lootcheck <= 3) cout << "a Serpent Spine: Worth 20 coins | 3.5w \n» and ";
    if (lootcheck == 5) cout << "a Serpent Tongue: Worth 40 coins | 1w \n» and ";
    if (lootcheck >= 8) cout << "a Hard Membrane: Worth 15 coins | 1.5w \n» and ";
    cout << enemyhp - (enemyhp % 10) + 15 << " xp. "                          << "\n"; 
    //cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶      \n";
    return 0;
}

int high_guard(int level){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    int lootcheck = rand() % 10 + 1;
    if (lootcheck <= 5) cout << "Adorned in resplendent armour, the High Guard awaits you.    ┃\n";
    else if (lootcheck >= 6) cout << "Standing tall and heavily armoured, the High Guard appears!  ┃\n";
    int enemyhp = statcalculator(HP_FORM);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌1╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
    cout << "» (Boss) High Guard: "                                           << "\n";
    cout << "» HP: " << enemyhp + 12 << " | F: " << statcalculator(HP_FORM) - 6
            << " | Dmg: " << 4 + dmgmodifier << " | T/R: 1"                   << "\n";
    cout << "» Drops ";
    if (lootcheck <= 4) cout << "Great Guard Helm: +1 HP, +1 F | Guards do -1 Dmg | 2w \n» and ";
    if (lootcheck >= 7) cout << "Great Guard Plate: +2 HP | +1 Dmg to Guards | 3.5w \n» and ";
    cout << enemyhp - (enemyhp % 10) + 17 << " xp. "                          << "\n"; 
    //cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶      \n";
    return 0;
}

int hammer_guard(int level){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    int lootcheck = rand() % 10 + 1;
    if (lootcheck <= 5) cout << "There, waits a Guard with a hammer adorned in sacred runes.  ┃\n";
    else if (lootcheck >= 6) cout << "Carrying a heavy glowing hammer, a strong opponent appears!  ┃\n";
    int enemyhp = statcalculator(HP_FORM);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌1╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
    cout << "» (Boss) Hammer Guard: "                                         << "\n";
    cout << "» HP: " << enemyhp + 8 << " | F: " << statcalculator(HP_FORM) - 10
            << " | Dmg: " << 5 + dmgmodifier << " | T/R: 1 | Range: 2t"       << "\n";
    cout << "» Drops ";
    if (lootcheck <= 4) cout << "Heavy Hammer: 5 Dmg | +1 Dmg to Bosses | -2 F | 5w \n» and ";
    if (lootcheck >= 7) cout << "Long Blade Axe: 5 Dmg | +1 Dmg to Humans | 4.5w \n» and ";
    cout << enemyhp - (enemyhp % 10) + 15 << " xp. "                          << "\n"; 
    //cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶      \n";
    return 0;
}

int king_orc(int level){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    int lootcheck = rand() % 10 + 1;
    cout << "Adorned in regal armor and crowned with a mighty headdress,  ┃\n"
         << "an immense growling figure ahead calls you for a battle!     ┃\n";
    int enemyhp = statcalculator(HP_FORM);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌1╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
    cout << "» (Boss) King Orc: "                                             << "\n";
    cout << "» HP: " << enemyhp + 10 << " | F: " << statcalculator(HP_FORM) + 7
            << " | Dmg: " << 4 + dmgmodifier << " | T/R: 2"                   << "\n";
    cout << "» Drops ";
    if (lootcheck <= 3) cout << "Orc Gem: Worth 30 coins | 1w \n» and ";
    if (lootcheck >= 7) cout << "Orc Forged Gold: Worth 25 coins | 1w \n» and ";
    cout << enemyhp - (enemyhp % 10) + 20 << " xp. "                          << "\n"; 
    //cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶      \n";
    return 0;
}

int sand_worm(int level){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    int lootcheck = rand() % 10 + 1;
    if (lootcheck <= 5) cout << "The shifting sands betray the presence of a massive being!   ┃\n";
    else if (lootcheck >= 6) cout << "As you step in, you feel the presence of something beneath.  ┃\n";
    int enemyhp = statcalculator(HP_FORM);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌1╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
    cout << "» (Boss) Sand Worm: "                                            << "\n";
    cout << "» HP: " << enemyhp + 9 << " | F: " << statcalculator(HP_FORM) + 9
            << " | Dmg: " << 3 + dmgmodifier << " | T/R: 4"                   << "\n";
    cout << "» Drops ";
    if (lootcheck <= 3) cout << "Pale Skin: +1 HP | Worth 10 coins | 2w \n» and ";
    if (lootcheck == 4) cout << "a Worm Tooth: Worth 15 coins | 0.5w \n» and ";
    if (lootcheck == 7) cout << "a Worm Spike: 1 Dmg | Worth 15 coins | 1w \n» and ";
    if (lootcheck >= 8) cout << "a Hard Membrane: Worth 15 coins | 1.5w \n» and ";
    cout << enemyhp - (enemyhp % 10) + 15 << " xp. "                          << "\n"; 
    //cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶      \n";
    return 0;
}

int snow_golem(int level){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    int lootcheck = rand() % 10 + 1;
    if (lootcheck <= 5) cout << "In the depths of the elemental plane, a snow golem emerges!  ┃\n";
    else if (lootcheck >= 6) cout << "A once silent snow statue lining the path now awakens...     ┃\n";
    int enemyhp = statcalculator(HP_FORM);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌1╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
    cout << "» (Boss) Snow Golem: "                                           << "\n";
    cout << "» HP: " << enemyhp + 15 << " | F: " << statcalculator(HP_FORM) - 5
            << " | Dmg: " << 4 + dmgmodifier << " | T/R: 2"                   << "\n";
    cout << "» Drops ";
    if (lootcheck <= 5) cout << "Elemental Essence: Worth 15 coins | 0.5w \n» and ";
    if (lootcheck >= 7) cout << "Snow Gem Piece: Worth 20 coins | 4.5w \n» and ";
    cout << enemyhp - (enemyhp % 10) + 12 << " xp. "                          << "\n"; 
    //cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶      \n";
    return 0;
}

int stone_golem(int level){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    int lootcheck = rand() % 10 + 1;
    if (lootcheck <= 5) cout << "In the depths of the elemental plane, a stone golem emerges! ┃\n";
    else if (lootcheck >= 6) cout << "A once silent stone statue lining the path now awakens...    ┃\n";
    int enemyhp = statcalculator(HP_FORM);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌1╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
    cout << "» (Boss) Stone Golem: "                                          << "\n";
    cout << "» HP: " << enemyhp + 10 << " | F: " << statcalculator(HP_FORM) - 5
            << " | Dmg: " << 5 + dmgmodifier << " | T/R: 2"                   << "\n";
    cout << "» Drops ";
    if (lootcheck <= 5) cout << "Elemental Essence: Worth 15 coins | 0.5w \n» and ";
    if (lootcheck >= 7) cout << "Stone Gem Piece: Worth 20 coins | 4.5w \n» and ";
    cout << enemyhp - (enemyhp % 10) + 12 << " xp. "                          << "\n"; 
    //cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶      \n";
    return 0;
}

int moss_golem(int level){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    int lootcheck = rand() % 10 + 1;
    if (lootcheck <= 5) cout << "In the depths of the elemental plane, a moss golem emerges!  ┃\n";
    else if (lootcheck >= 6) cout << "A once silent moss statue lining the path now awakens...     ┃\n";
    int enemyhp = statcalculator(HP_FORM);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌1╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
    cout << "» (Boss) Moss Golem: "                                           << "\n";
    cout << "» HP: " << enemyhp + 10 << " | F: " << statcalculator(HP_FORM)
            << " | Dmg: " << 4 + dmgmodifier << " | T/R: 2"                   << "\n";
    cout << "» Drops ";
    if (lootcheck <= 5) cout << "Elemental Essence: Worth 15 coins | 0.5w \n» and ";
    if (lootcheck >= 7) cout << "Moss Gem Piece: Worth 20 coins | 4.5w \n» and ";
    cout << enemyhp - (enemyhp % 10) + 12 << " xp. "                          << "\n"; 
    //cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶      \n";
    return 0;
}

int arachnia(int level){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    int lootcheck = rand() % 10 + 1;
    if (lootcheck <= 5) cout << "Suddenly, sets of hairy legs and gleaming eyes charge you!   ┃\n";
    else if (lootcheck >= 6) cout << "The sound of scuttling feet fills the air... A Giant Spider! ┃\n";
    int enemyhp = statcalculator(HP_FORM);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌1╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
    cout << "» (Boss) Arachnia: "                                             << "\n";
    cout << "» HP: " << enemyhp + 5 << " | F: " << statcalculator(HP_FORM) + 8
            << " | Dmg: " << 3 + dmgmodifier << " | T/R: 3 | Range: 2t"       << "\n";
    cout << "» Drops ";
    if (lootcheck <= 3) cout << "Arachnia Eye: Worth 10 coins | 0.5w \n» and ";
    if (lootcheck == 4) cout << "Arachnia Leg: Worth 25 coins | 2w \n» and ";
    if (lootcheck == 7 || lootcheck == 6) cout << "Spider Hair: Worth 15 coins | 1w \n» and ";
    if (lootcheck >= 8) cout << "Arachnia Membrane: Worth 15 coins | 2.5w \n» and ";
    cout << enemyhp - (enemyhp % 10) + 15 << " xp. "                          << "\n"; 
    //cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶      \n";
    return 0;
}

int wind_wyvern(int level){
    int dmgmodifier = dmgmodifiercheck(level);
    int HP_FORM = hp_form_by_hero_level(level);
    int lootcheck = rand() % 10 + 1;
    if (lootcheck <= 5) cout << "High above, you catch a glimpse of a majestic silhouette.    ┃\n";
    else if (lootcheck >= 6) cout << "Above the mountain peaks, an ethereal presence approaches.   ┃\n";
    int enemyhp = statcalculator(HP_FORM);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━╌1╌━━━━━━━━━━━━━━━━━━━━━━━━━━━━┻▶" << "\n";
    cout << "» (Boss) Wind Wyvern: "                                          << "\n";
    cout << "» HP: " << enemyhp + 9 << " | F: " << statcalculator(HP_FORM) + 15
            << " | Dmg: " << 3 + dmgmodifier << " | T/R: 2 | Range: 3t"       << "\n";
    cout << "» Drops ";
    if (lootcheck <= 3) cout << "a Wyvern Scale: Worth 20 coins | 1.5w \n» and ";
    if (lootcheck == 5) cout << "a Wyvern Bone: 4 Dmg | Worth 15 coins | 2.5w \n» and ";
    if (lootcheck >= 8) cout << "a Wyvern Spine: Worth 25 coins | 3w \n» and ";
    cout << enemyhp - (enemyhp % 10) + 25 << " xp. "                          << "\n"; 
    //cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶      \n";
    return 0;
}