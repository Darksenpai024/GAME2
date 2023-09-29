#include <iostream>
#include <unistd.h>
#include <random>
#include <map>
#include <string>
using namespace std;

// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
// Crafting Books for:
// - Armour
// - Weapons
// - Food
//------------------------------------------------------------------------------------------------------------------


// Armour Crafting Book --------------------------------------------------------------------------------------------
int armour(){
    string choice; int page = 0; // 0 to 7: 8 pages total
    for (int i = 0; i < 10000; i++){
        if (choice == "craftables" || choice == "c"){
            usleep(610000);
            cout << "\n" << "» Returning to Craftables Menu..." << "\n";
            usleep(610000);
            break;
        }
        // Page Navigation -----------------------------------------------------
        else if ((choice == "previous" || choice == "z") && page >= 1) page--;
        else if ((choice == "previous" || choice == "z") && page == 0) page = 7;
        else if ((choice == "next" || choice == "x") && page <= 6) page++;
        else if ((choice == "next" || choice == "x") && page == 7) page = 0;
        // ---------------------------------------------------------------------
        if (page == 0){
            cout << "⌫========================= PAGE 1 =========================⌦" << "\n";
            cout << "» Deer Hood: -1 HP, +3 F | 1w                               " << "\n";
            cout << "↠ 2 - Deer Antler                                           " << "\n";
            cout << "↠ 1 - Deer Pelt                                             " << "\n";
            cout << "↠ 1 - Animal Bone                                           " << "\n";
            cout << "↠ Price: 15 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Deer Coat: -2 HP, +4 F | 2.5w                             " << "\n";
            cout << "↠ 3 - Deer Pelt                                             " << "\n";
            cout << "↠ 1 - Big Animal Bone                                       " << "\n";
            cout << "                                                            " << "\n";
            cout << "↠ Price: 25 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Wolf Mask: +2 HP | Daggers and Knives do +1 Dmg | 1.5w    " << "\n";
            cout << "↠ 2 - Wolf Claw                                             " << "\n";
            cout << "↠ 1 - Wolf Fur                                              " << "\n";
            cout << "↠ 1 - Animal Bone                                           " << "\n";
            cout << "↠ Price: 20 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Wolf Cloak: +1 HP, -1 F | +1 Dmg if party size >1 | 3w    " << "\n";
            cout << "↠ 2 - Wolf Claw                                             " << "\n";
            cout << "↠ 2 - Wolf Fur                                              " << "\n";
            cout << "↠ 2 - Animal Bone                                           " << "\n";
            cout << "↠ Price: 35 Coins                                           " << "\n";
        }
        else if (page == 1){
            cout << "⌫========================= PAGE 2 =========================⌦" << "\n";
            cout << "» Lion Mask: +1 HP | Always attack first in mountains | 2w  " << "\n";
            cout << "↠ 2 - Wolf Claw                                             " << "\n";
            cout << "↠ 1 - Animal Bone                                           " << "\n";
            cout << "                                                            " << "\n";
            cout << "↠ Price: 50 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Lion Cloak: +2 HP | +1 Dmg in Mountains | 3.5w            " << "\n";
            cout << "↠ 2 - Wolf Claw                                             " << "\n";
            cout << "↠ 2 - Mountain Lion Pelt                                    " << "\n";
            cout << "↠ 1 - Big Animal Bone                                       " << "\n";
            cout << "↠ Price: 65 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Great Goat Mask: +2 HP, +4 F | -5 HP to run 5 tiles | 2w  " << "\n";
            cout << "↠ 2 - Goat Horn                                             " << "\n";
            cout << "↠ 2 - Animal Bone                                           " << "\n";
            cout << "                                                            " << "\n";
            cout << "↠ Price: 60 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Goat Cloak: +2 HP | 1.d6 » 1 ram close target 1t back | 3w" << "\n";
            cout << "↠ 2 - Mountain Goat Hide                                    " << "\n";
            cout << "↠ 1 - Animal Bone                                           " << "\n";
            cout << "↠ 1 - Breeze Blossom                                        " << "\n";
            cout << "↠ Price: 60 Coins                                           " << "\n";
        }
        else if (page == 2){
            cout << "⌫========================= PAGE 3 =========================⌦" << "\n";
            cout << "» Siren Head Mask: +1 F | 1.d6 » 2/4 heal 1 HP to ALL | 1.5w" << "\n";
            cout << "↠ 2 - Siren Tooth                                           " << "\n";
            cout << "↠ 1 - Siren Scale                                           " << "\n";
            cout << "↠ 1 - Silver Crawler                                        " << "\n";
            cout << "↠ Price: 35 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Siren Coat: +1 F | Enemies do -1 Dmg in lakes | 2w        " << "\n";
            cout << "↠ 2 - Siren Fin                                             " << "\n";
            cout << "↠ 2 - Siren Scale                                           " << "\n";
            cout << "↠ 1 - Siren Tooth                                           " << "\n";
            cout << "↠ Price: 35 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Blue Emperor Crown: +15 xp, +3 coins per lake kill | 2w   " << "\n";
            cout << "↠ 2 - Lake Serpent Scale                                    " << "\n";
            cout << "↠ 1 - Crawler Tooth                                         " << "\n";
            cout << "↠ 1 - Nightfish                                             " << "\n";
            cout << "↠ Price: 90 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Blue Emperor Armour: +3 HP | Heal action does +2 HP | 3.5w" << "\n";
            cout << "↠ 2 - Siren Scale                                           " << "\n";
            cout << "↠ 1 - Silverfin Fish Scale                                  " << "\n";
            cout << "↠ 1 - Crawler Spine                                         " << "\n";
            cout << "↠ Price: 50 Coins                                           " << "\n";
        }
        else if (page == 3){
            cout << "⌫========================= PAGE 4 =========================⌦" << "\n";
            cout << "» Bone Helm: +1 HP, +1 F | +10 xp per animal kill | 1.5w    " << "\n";
            cout << "↠ 2 - Animal Bone                                           " << "\n";
            cout << "↠ 1 - Human Skull                                           " << "\n";
            cout << "↠ 1 - Human Bone                                            " << "\n";
            cout << "↠ Price: 20 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Bone Plate: +1 HP, +1 F | +1 Dmg to animals | 2.5w        " << "\n";
            cout << "↠ 2 - Big Animal Bone                                       " << "\n";
            cout << "↠ 1 - Rusted Plate                                          " << "\n";
            cout << "↠ 1 - Human Bone                                            " << "\n";
            cout << "↠ Price: 20 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Mimic Mask: +2 HP, -1 F | Bags contain +10 coins | 2.5w   " << "\n";
            cout << "↠ 3 - Stick                                                 " << "\n";
            cout << "↠ 1 - Mimic Tongue                                          " << "\n";
            cout << "                                                            " << "\n";
            cout << "↠ Price: 70 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Pale One Hood: 1.d6 per stat, 2 hgst vls -> +3_, +3_ perm." << "\n";
            cout << "↠ 1 - Skeleton Key                                          " << "\n";
            cout << "↠ 1 - Mimic Tongue                                          " << "\n";
            cout << "↠ 1 - Ragged Cloths                                         " << "\n";
            cout << "↠ Price: 80 Coins                                           " << "\n";
        }
        else if (page == 4){
            cout << "⌫========================= PAGE 5 =========================⌦" << "\n";
            cout << "» Crawler Plate: -3 HP, +2 F | +1 T/R in lakes | 2w         " << "\n";
            cout << "↠ 2 - Crawler Spine                                         " << "\n";
            cout << "↠ 1 - Crawler Scale                                         " << "\n";
            cout << "↠ 1 - Silver Crawler                                        " << "\n";
            cout << "↠ Price: 55 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Ooze Chestplate: +2 HP, +1 F | Guards do -1 Dmg | 2.5w    " << "\n";
            cout << "↠ 3 - Solidified Ooze                                       " << "\n";
            cout << "↠ 2 - Mutated Limb                                          " << "\n";
            cout << "↠ 1 - Slime Liver                                           " << "\n";
            cout << "↠ Price: 60 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Dragonfish Armour: +3 HP, +1 F | Blades do +1 Dmg | 3.5w  " << "\n";
            cout << "↠ 1 - Bull Dragonfish                                       " << "\n";
            cout << "↠ 1 - Ripped Scaled Tail                                    " << "\n";
            cout << "↠ 1 - Petrified Skull Shell                                 " << "\n";
            cout << "↠ 1 - Pale Skin                                             " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Cursed Hennin: +2 HP | Body armour stats double | 1.5w    " << "\n";
            cout << "↠ 2 - Orc Forged Gold                                       " << "\n";
            cout << "↠ 2 - Spider Hair                                           " << "\n";
            cout << "↠ 1 - Golden Witchbass                                      " << "\n";
            cout << "↠ 1 - Deer Pelt                                             " << "\n";
        }
        else if (page == 5){
            cout << "⌫========================= PAGE 6 =========================⌦" << "\n";
            cout << "» Worm Mask: +2 HP | When HP < 10 do +1 Dmg | 2w            " << "\n";
            cout << "↠ 1 - Worm Tooth                                            " << "\n";
            cout << "↠ 1 - Sand Graygill                                         " << "\n";
            cout << "↠ 1 - Hard Membrane                                         " << "\n";
            cout << "↠ Price: 80 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Worm Spike Coat: +3 HP | BT, 1.d6 » 3 deal 1 Dmg | 4w     " << "\n";
            cout << "↠ 2 - Worm Spike                                            " << "\n";
            cout << "↠ 2 - Pale Skin                                             " << "\n";
            cout << "                                                            " << "\n";
            cout << "↠ Price: 110 Coins                                          " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Red Worm Mask: +2 HP When HP < 10 do +2 Dmg | 2w          " << "\n";
            cout << "↠ 1 - Red Worm Tooth                                        " << "\n";
            cout << "↠ 1 - Sand Graygill                                         " << "\n";
            cout << "↠ 1 - Hard Membrane                                         " << "\n";
            cout << "↠ Price: 95 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Red Worm Coat: +3 HP | BT, 1.d6 » 3 deal 2 Dmg | 4w       " << "\n";
            cout << "↠ 2 - Red Spike                                             " << "\n";
            cout << "↠ 2 - Red Skin                                              " << "\n";
            cout << "                                                            " << "\n";
            cout << "↠ Price: 125 Coins                                          " << "\n";
        }
        else if (page == 6){
            cout << "⌫========================= PAGE 7 =========================⌦" << "\n";
            cout << "» Arachnia Head: +1 HP, +3 F | +1 Dmg to Bosses | 2.5w      " << "\n";
            cout << "↠ 2 - Arachnia Eye                                          " << "\n";
            cout << "↠ 1 - Arachnia Membrane                                     " << "\n";
            cout << "↠ 1 - Big Animal Bone                                       " << "\n";
            cout << "↠ Price: 90 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Arachnia Jacket: +3 HP, +1 F | +1 T/R in ruins | 3.5w     " << "\n";
            cout << "↠ 2 - Spider Hair                                           " << "\n";
            cout << "↠ 1 - Arachnia Membrane                                     " << "\n";
            cout << "↠ 1 - Arachnia Leg                                          " << "\n";
            cout << "↠ Price: 100 Coins                                          " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» King Orc Crown: +2 HP, -3 F | Axes do +1 Dmg | 2w         " << "\n";
            cout << "↠ 2 - Orc Forged Gold                                       " << "\n";
            cout << "↠ 1 - Orc Gem                                               " << "\n";
            cout << "↠ 1 - Human Bone                                            " << "\n";
            cout << "↠ Price: 90 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Death Cloak: +3 HP, -3 F | +2 Dmg if party size > 1 | 4w  " << "\n";
            cout << "↠ 2 - Large Thorn                                           " << "\n";
            cout << "↠ 2 - Wolf Fur                                              " << "\n";
            cout << "↠ 1 - Human Bone                                            " << "\n";
            cout << "↠ 1 - Petrified Bone                                        " << "\n";
        }
        else if (page == 7){
            cout << "⌫========================= PAGE 8 =========================⌦" << "\n";
            cout << "» Wyvern Plate: +3 HP, +2 F | +1 T/R in mountains | 3.5w    " << "\n";
            cout << "↠ 2 - Wyvern Scale                                          " << "\n";
            cout << "↠ 1 - Wyvern Spine                                          " << "\n";
            cout << "↠ 1 - Wyvern Apple                                          " << "\n";
            cout << "↠ 1 - Ripped Scaled Tail                                    " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Boar Mask: +2 HP, +2 F | -3 HP to charge to an enemy | 2w " << "\n";
            cout << "↠ 2 - Boar Tusk                                             " << "\n";
            cout << "↠ 1 - Heavy Boar Fur                                        " << "\n";
            cout << "↠ 1 - Big Animal Bone                                       " << "\n";
            cout << "↠ Price: 75 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Boar Coat: +2 HP, +1 F | Food heals +1 HP | 3w            " << "\n";
            cout << "↠ 2 - Heavy Boar Fur                                        " << "\n";
            cout << "↠ 1 - Big Animal Bone                                       " << "\n";
            cout << "                                                            " << "\n";
            cout << "↠ Price: 95 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
        }
        cout << "⌫──────────────────────────────────────────────────────────⌦" << "\n";
        cout << "⍆ Previous Page                                          (z)" << "\n";
        cout << "⍆ Next Page                                              (x)" << "\n";
        cout << "⍆ Return to Craftables                                   (c)" << "\n";
        cout << "⌫==========================================================⌦" << "\n" << "◼▶ ";
        cin >> choice; cout << "\n";
    }
    return 0;
}
//------------------------------------------------------------------------------------------------------------------


// Weapons Crafting Book -------------------------------------------------------------------------------------------
int weapons(){
    string choice; int page = 0; // 0 to 2: 3 pages total
    for (int i = 0; i < 10000; i++){
        if (choice == "craftables" || choice == "c"){
            usleep(610000);
            cout << "\n" << "» Returning to Craftables Menu..." << "\n";
            usleep(610000);
            break;
        }
        // Page Navigation -----------------------------------------------------
        else if ((choice == "previous" || choice == "z") && page >= 1) page--;
        else if ((choice == "previous" || choice == "z") && page == 0) page = 2;
        else if ((choice == "next" || choice == "x") && page <= 1) page++;
        else if ((choice == "next" || choice == "x") && page == 2) page = 0;
        // --------------------------------------------------------------------- // 3, 4, 5 Dmg
        if (page == 0){
            cout << "⌫========================= PAGE 1 =========================⌦" << "\n"; // 2-12
            cout << "» Crystal Dagger: 3 Dmg | 2.d6 » 7/10 stun for 1 round | 2w " << "\n";
            cout << "↠ 1 - Snow Gem Piece                                        " << "\n";
            cout << "↠ 1 - Animal Bone                                           " << "\n";
            cout << "↠ 1 - Crystalized Stone                                     " << "\n";
            cout << "↠ Price: 75 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Tomb Scythe: 3 Dmg | +2 Dmg to Skeletons | 2t | 4.5w      " << "\n";
            cout << "↠ 1 - Human Skull                                           " << "\n";
            cout << "↠ 1 - Heavy Spine                                           " << "\n";
            cout << "↠ 1 - Shadow Crawler Tooth                                  " << "\n";
            cout << "↠ Price: 80 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Bloodmoon Blade: 4 Dmg | Do 6 Dmg, lose 3 HP | 4w         " << "\n";
            cout << "↠ 1 - Shadow Membrane                                       " << "\n";
            cout << "↠ 1 - Blood Orb                                             " << "\n";
            cout << "↠ 1 - Red Spike                                             " << "\n";
            cout << "↠ Price: 95 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Moonlight Axe: 4 Dmg | Heal 2 HP per kill | 4w            " << "\n";
            cout << "↠ 2 - Nightfish                                             " << "\n";
            cout << "↠ 2 - Starfruit                                             " << "\n";
            cout << "↠ 1 - Dual Axe                                              " << "\n";
            cout << "↠ Price: 80 Coins                                           " << "\n";
        }
        else if (page == 1){
            cout << "⌫========================= PAGE 2 =========================⌦" << "\n";
            cout << "» Crystal Orb: 3 Dmg | Heal 3 HP per kill | 3t | 3.5w       " << "\n";
            cout << "↠ 2 - Crystal Tulip                                         " << "\n";
            cout << "↠ 1 - Orc Forged Gold                                       " << "\n";
            cout << "↠ 1 - Crystalized Stone                                     " << "\n";
            cout << "↠ Price: 65 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Rune Boomerang: 3 Dmg | 1.d6 » 3 double dmg | 4t | 2.5w   " << "\n";
            cout << "↠ 2 - Elemental Essence                                     " << "\n";
            cout << "↠ 1 - Orc Forged Gold                                       " << "\n";
            cout << "↠ 1 - Dark Bone                                             " << "\n";
            cout << "↠ Price: 100 Coins                                          " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Shadow Sling: 2 Dmg | +1 Dmg in ruins | Pellets | 7t | 3w " << "\n";
            cout << "↠ 1 - Shadow Membrane                                       " << "\n";
            cout << "↠ 1 - Petrified Bone                                        " << "\n";
            cout << "↠ 1 - Red Skin                                              " << "\n";
            cout << "↠ Price: 85 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Spirit Bow: 3 Dmg | Arrows | 7t | 3w                      " << "\n";
            cout << "↠ 2 - Spirit Essence                                        " << "\n";
            cout << "↠ 1 - Spirit Treasure                                       " << "\n";
            cout << "↠ 1 - Wyvern Bone                                           " << "\n";
            cout << "↠ Price: 70 Coins                                           " << "\n";
        }
        else if (page == 2){
            cout << "⌫========================= PAGE 3 =========================⌦" << "\n";
            cout << "» Serpent's Tongue Whip: 6 Dmg | +5 F | 2t | 3w             " << "\n";
            cout << "↠ 2 - Serpent Spike                                         " << "\n";
            cout << "↠ 1 - Serpent Tongue                                        " << "\n";
            cout << "↠ 1 - Hard Membrane                                         " << "\n";
            cout << "↠ Price: 130 Coins                                          " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Shifting Sands Pike: 4 Dmg | +1 T/R and -5 F | 2t | 3.5w  " << "\n";
            cout << "↠ 2 - Big Animal Bone                                       " << "\n";
            cout << "↠ 1 - Worm Tooth                                            " << "\n";
            cout << "↠ 1 - Sand Graygill                                         " << "\n";
            cout << "↠ Price: 120 Coins                                          " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Nature's Ocarina: d6»3/5, 3 Dmg + Self-heal 2 HP | 4t | 2w" << "\n";
            cout << "↠ 2 - Snow Gem Piece                                        " << "\n";
            cout << "↠ 2 - Stone Gem Piece                                       " << "\n";
            cout << "↠ 2 - Moss Gem Piece                                        " << "\n";
            cout << "↠ Price: 120 Coins                                          " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Songbird Flute: d6»2/4, any target: 4 HP or Dmg | 6t | 2w " << "\n";
            cout << "↠ 1 - Songbird Feather                                      " << "\n";
            cout << "↠ 1 - Animal Bone                                           " << "\n";
            cout << "↠ 1 - Whispering Petal                                      " << "\n";
            cout << "↠ Price: 135 Coins                                          " << "\n";
        }
        cout << "⌫──────────────────────────────────────────────────────────⌦" << "\n";
        cout << "⍆ Previous Page                                          (z)" << "\n";
        cout << "⍆ Next Page                                              (x)" << "\n";
        cout << "⍆ Return to Craftables                                   (c)" << "\n";
        cout << "⌫==========================================================⌦" << "\n" << "◼▶ ";
        cin >> choice; cout << "\n";
    }
    return 0;
}
//------------------------------------------------------------------------------------------------------------------


// Food Crafting Book ----------------------------------------------------------------------------------------------
int food(){
    string choice; int page = 0; // 0 to 3: 4 pages total
    for (int i = 0; i < 10000; i++){
        if (choice == "craftables" || choice == "c"){
            usleep(610000);
            cout << "\n" << "» Returning to Craftables Menu..." << "\n";
            usleep(610000);
            break;
        }
        // Page Navigation -----------------------------------------------------
        else if ((choice == "previous" || choice == "z") && page >= 1) page--;
        else if ((choice == "previous" || choice == "z") && page == 0) page = 3;
        else if ((choice == "next" || choice == "x") && page <= 2) page++;
        else if ((choice == "next" || choice == "x") && page == 3) page = 0;
        // --------------------------------------------------------------------- // 3, 4, 5 Dmg
        if (page == 0){
            cout << "⌫========================= PAGE 1 =========================⌦" << "\n"; // 2-12
            cout << "» Dragon Scale Tea: Heal 2 HP, 5 in mountains | Stacks to 2 " << "\n";
            cout << "↠ 2 - Algae                                                 " << "\n";
            cout << "↠ 1 - Dragon Leek                                           " << "\n";
            cout << "↠ 1 - Spiritfruit                                           " << "\n";
            cout << "↠ Price: 15 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Druid's Blossom Drink: Heal party 12 HP | Stacks to 3     " << "\n";
            cout << "↠ 2 - Algae                                                 " << "\n";
            cout << "↠ 1 - Breeze Blossom                                        " << "\n";
            cout << "↠ 1 - Dream Blossom                                         " << "\n";
            cout << "↠ Price: 80 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Barbarian's Stew: +1 Dmg for 1 dungeon room | Stacks to 2 " << "\n";
            cout << "↠ 2 - Red Mushroom                                          " << "\n";
            cout << "↠ 2 - Brown Mushroom                                        " << "\n";
            cout << "↠ 2 - Potato                                                " << "\n";
            cout << "↠ Price: 50 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Veggie Medley: Heal 2 HP, +5 F next round | Stacks to 2   " << "\n";
            cout << "↠ 2 - Carrot                                                " << "\n";
            cout << "↠ 2 - Corn                                                  " << "\n";
            cout << "↠ 1 - Lettuce                                               " << "\n";
            cout << "↠ Price: 15 Coins                                           " << "\n";
        }
        else if (page == 1){
            cout << "⌫========================= PAGE 2 =========================⌦" << "\n";
            cout << "» Hot Berry Jam: Heal 3 HP | 0.5w | Stacks to 2             " << "\n";
            cout << "↠ 2 - Red Berry                                             " << "\n";
            cout << "↠ 1 - Slimegum Fruit                                        " << "\n";
            cout << "↠ 1 - Firefruit                                             " << "\n";
            cout << "↠ Price: 0 Coins                                            " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Forest Skewers: Heal 3 HP, 5 in forests | Stacks to 2     " << "\n";
            cout << "↠ 2 - Deer Meat                                             " << "\n";
            cout << "↠ 1 - Pumpkin                                               " << "\n";
            cout << "↠ 1 - Radish                                                " << "\n";
            cout << "↠ Price: 10 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Artisan's Fruit Platter: Heal party 4 HP | Doesn't Stack  " << "\n";
            cout << "↠ 2 - Wyvern Apple                                          " << "\n";
            cout << "↠ 2 - Orange                                                " << "\n";
            cout << "↠ 2 - Starfruit                                             " << "\n";
            cout << "↠ Price: 30 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Spicy Infusion: -1 HP, +1 T/R next round | Doesn't Stack  " << "\n";
            cout << "↠ 1 - Dragon Leek                                           " << "\n";
            cout << "↠ 1 - Firefruit                                             " << "\n";
            cout << "↠ 1 - Ember Lily                                            " << "\n";
            cout << "↠ Price: 15 Coins                                           " << "\n";
        }
        else if (page == 2){
            cout << "⌫========================= PAGE 3 =========================⌦" << "\n";
            cout << "» Farmer's Pie: Heal 5 HP, +3 F next round | Stacks to 2    " << "\n";
            cout << "↠ 2 - Red Berry                                             " << "\n";
            cout << "↠ 1 - Pumpkin                                               " << "\n";
            cout << "↠ 1 - Radish                                                " << "\n";
            cout << "↠ Price: 30 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Scavenger Soup: Heal 3 HP | 0.5w | Stacks to 4            " << "\n";
            cout << "↠ 1 - Brown Mushroom                                        " << "\n";
            cout << "↠ 1 - Smallfish                                             " << "\n";
            cout << "↠ 1 - Potato                                                " << "\n";
            cout << "↠ Price: 5 Coins                                            " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Sushi Delight: Heal 1 HP, next kill +5 coins | Stacks to 2" << "\n";
            cout << "↠ 1 - Salmon                                                " << "\n";
            cout << "↠ 1 - Cabbage                                               " << "\n";
            cout << "↠ 1 - Algae                                                 " << "\n";
            cout << "↠ Price: 0 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Pirate's Feast: Heal 3 HP, 6 in lakes | Stacks to 2       " << "\n";
            cout << "↠ 2 - Bass                                                  " << "\n";
            cout << "↠ 2 - Potato                                                " << "\n";
            cout << "↠ 1 - Siren Fin                                             " << "\n";
            cout << "↠ Price: 25 Coins                                           " << "\n";
        }
        else if (page == 3){
            cout << "⌫========================= PAGE 4 =========================⌦" << "\n";
            cout << "» Herbalist's Fillet Meal: Heal party 16 HP | Stacks to 2   " << "\n";
            cout << "↠ 1 - Whispering Petal                                      " << "\n";
            cout << "↠ 1 - Smallcarp                                             " << "\n";
            cout << "↠ 1 - Carp                                                  " << "\n";
            cout << "↠ Price: 100 Coins                                          " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "» Hunter's Meal: Heal 6 HP, 8 in W. Encounter | Stacks to 2 " << "\n";
            cout << "↠ 2 - Deer Meat                                             " << "\n";
            cout << "↠ 1 - Cabbage                                               " << "\n";
            cout << "↠ 1 - Red Berry                                             " << "\n";
            cout << "↠ Price: 65 Coins                                           " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
            cout << "⌫╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴╴⌦" << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
            cout << "                                                            " << "\n";
        }
        cout << "⌫──────────────────────────────────────────────────────────⌦" << "\n";
        cout << "⍆ Previous Page                                          (z)" << "\n";
        cout << "⍆ Next Page                                              (x)" << "\n";
        cout << "⍆ Return to Craftables                                   (c)" << "\n";
        cout << "⌫==========================================================⌦" << "\n" << "◼▶ ";
        cin >> choice; cout << "\n";
    }
    return 0;
}
//------------------------------------------------------------------------------------------------------------------




// General Crafting Menu -------------------------------------------------------------------------------------------
int craftables(){
    string choice;
    for (int i = 0; i < 10000; i++){
        cout << "⌫==========================================================⌦" << "\n";
        cout << "Craftables:                                                 " << "\n";
        cout << "⍆ Armour                                                 (a)" << "\n";
        cout << "⍆ Weapons                                                (w)" << "\n";
        cout << "⍆ Food                                                   (f)" << "\n";
        cout << "⍆ Return to Adventure                                    (m)" << "\n";
        cout << "⌫==========================================================⌦" << "\n" << "◼▶ ";
        cin >> choice; cout << "\n";
        if (choice == "adventure" || choice == "m"){
            usleep(610000);
            cout << "\n" << "» Returning to Adventure Menu..." << "\n";
            usleep(610000);
            break;
        }
        else if (choice == "armour" || choice == "a") armour();
        else if (choice == "weapons" || choice == "w") weapons();
        else if (choice == "food" || choice == "f") food();
        else cout << "» Please write a valid input!" << "\n";
    }
    return 0;
}
//------------------------------------------------------------------------------------------------------------------
