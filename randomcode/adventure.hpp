#include <iostream>
#include "crafting.hpp"
#include "enemy.hpp"
#include <vector>
using namespace std;

// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
// POSSIBLE ENEMY SPAWNS FOR EACH LOCATION

string forestenemies(){
    vector<string> enemies = {
        "guard",
        "guard",
        "mutant",
        "wolf",
        "wolf",
        "wolf",
        "slime",
        "slime",
        "bandit",
        "bandit",
        "bandit",
        "gnome"
    };
    return enemies[(rand()%12+0)];
}
string mountainenemies(){
    vector<string> enemies = {
        "skeleton",
        "skeleton",
        "guard",
        "guard",
        "wolf",
        "wolf",
        "bandit",
        "bandit",
        "gnome"
    };
    return enemies[(rand()%9+0)];
}
string lakeenemies(){
    vector<string> enemies = {
        "mutant",
        "wolf",
        "bandit",
        "fish_crawler",
        "siren"
    };
    return enemies[(rand()%5+0)];
}
string campenemies(){
    vector<string> enemies = {
        "guard",
        "wolf",
        "bandit"
    };
    return enemies[(rand()%3+0)];
}
string dungeonenemies(){
    vector<string> enemies = {
        "skeleton",
        "skeleton",
        "guard",
        "mutant",
        "mutant",
        "slime",
        "slime",
        "bucket_slime",
        "bucket_slime",
        "mimic",
        "necromancer",
        "necromancer",
        "bandit",
        "fish_crawler"
    };
    return enemies[(rand()%14+0)];
}
string ruinenemies(){
    vector<string> enemies = {
        "skeleton",
        "skeleton",
        "skeleton",
        "guard",
        "guard",
        "slime",
        "slime",
        "bucket_slime",
        "bucket_slime",
        "mimic",
        "mimic",
        "necromancer",
        "necromancer",
        "necromancer"
    };
    return enemies[(rand()%14+0)];
}


// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
// LOCATION FUNCTIONS

int emptyroom(){ // there's a 35% chance the room/zone is empty
    int percentage = rand() % 100 + 1;
    return (percentage <= 20);
}


int forest(){
    cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
    cout << "▹≻ You approach the Forest.\n";
    int roomquantity, level; bool firstroom = true; string enter, choice;
    int roomsize = rand() % 10 + 1;
    if (roomsize < 8)          roomquantity = rand() % 6 + 1; // room quantity common  1-5 rooms  (70% chance)
    else if (roomsize > 7) roomquantity = rand() % 6 + 5; // room quantity rare    5-10 rooms (30% chance)
    // LOCATION OF 1 ROOM -------------------------------------------------------------------------------------
    if (roomquantity == 1){ // 100% with enemies
        cout << "You have found a forest of 1 area. Do you venture inside?" << "\n"; // 1 room location
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the forest and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
            int enemyquantity; // enemy amount
            if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
            else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
            else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
            else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
            else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
            //-----------------------------------------------------------
            if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                << " enemy.    (3x3)\n";
            if (enemyquantity > 1){
                cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                if (enemyquantity == 2) cout << "(4x4)\n";
                else if (enemyquantity == 3) cout << "(5x5)\n";
                else if (enemyquantity == 4) cout << "(7x7)\n";
                else if (enemyquantity >= 5) cout << "(9x9)\n";
                }
            string enemytype = forestenemies();
            if (enemytype == "guard") guard(level, enemyquantity);
            else if (enemytype == "mutant") mutant(level, enemyquantity);
            else if (enemytype == "wolf") wolf(level, enemyquantity);
            else if (enemytype == "slime") slime(level, enemyquantity);
            else if (enemytype == "bandit") bandit(level, enemyquantity);
            else if (enemytype == "gnome") gnome(level, enemyquantity);
            if ((rand()%100+1) <= 25) cout << "\n" << floor_item("forest"); // locations with 1 zones have a 25% chance for floor loot
            cout << "Having cleared the area, you are ready to leave the forest.\n"; 
            string leave; cin >> leave; cout << "\n";
            return 0;
        }
    }
    // LOCATION WITH MORE THAN 1 ROOM -------------------------------------------------------------------------
    else{
        cout << "You have found a forest of " << roomquantity << " areas." << "\n" << "Do you venture inside? " << "\n";
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the forest and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            for (int i = 1; i <= roomquantity; i++){
                // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
                int enemyquantity; // enemy amount
                if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
                else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
                else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
                else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
                else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
                //-----------------------------------------------------------
                // FIRST ROOM GENERATOR
                if (firstroom){
                    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                         << "You enter the first area.                                    ┃";

                        if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                            << " enemy.    (3x3)                           ┃\n";
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        string enemytype = forestenemies();
                        if (enemytype == "guard") guard(level, enemyquantity, 1);
                        else if (enemytype == "mutant") mutant(level, enemyquantity, 1);
                        else if (enemytype == "wolf") wolf(level, enemyquantity, 1);
                        else if (enemytype == "slime") slime(level, enemyquantity, 1);
                        else if (enemytype == "bandit") bandit(level, enemyquantity, 1);
                        else if (enemytype == "gnome") gnome(level, enemyquantity, 1);
                        if ((rand()%100+1) <= 55) cout << "\n" << floor_item("forest");
                        cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                        cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the forest? »» ";
                        cin >> choice;
                        if (choice == "leave" || choice == "l" || choice == "s"){
                            cout << "\n▹≻ You leave the forest and continue walking...\n\n";
                            usleep(610000);
                            return 0;
                        }
                        else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                        << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                        << "You walk into the next area";    
                    firstroom = false;
                }
                //---------------------------------------------------------------------------------------------------------------
                // OTHER ROOMS GENERATOR
                else if (firstroom == false){
                    // LAST ROOM
                    if (i == roomquantity){ // Last Room Generator | 100% with enemies
                        cout << ".                                 ┃\nYou have reached the end of the forest.                      ┃";
                        if (enemyquantity == 1) enemyquantity++;
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        // BOSS SPAWN
                        int chance = rand() % 100 + 1; bool noboss = true;

                        if (roomquantity >= 5 && level > 10 && chance <= 65){ // boss requirements + 70% chance
                            int randomboss = rand() % 4 + 1;
                            if (randomboss == 1) high_guard(level);
                            else if (randomboss == 2) king_orc(level);
                            else if (randomboss == 3) moss_golem(level);
                            else if (randomboss == 4) arachnia(level);
                            string enemytype = forestenemies();
                            enemyquantity--;
                            if (enemyquantity >= 1){ // if there is still quantity left, use it on troops
                                if (enemytype == "guard") guard(level, enemyquantity, 2); // start at 2, since boss is number one
                                else if (enemytype == "mutant") mutant(level, enemyquantity, 2);
                                else if (enemytype == "wolf") wolf(level, enemyquantity, 2);
                                else if (enemytype == "slime") slime(level, enemyquantity, 2);
                                else if (enemytype == "bandit") bandit(level, enemyquantity, 2);
                                else if (enemytype == "gnome") gnome(level, enemyquantity, 2);
                            }
                            noboss = false;
                        }
                        if (noboss){ // if a boss didn't spawn, do normal room
                            string enemytype = forestenemies();
                            if (enemytype == "guard") guard(level, enemyquantity, 1);
                            else if (enemytype == "mutant") mutant(level, enemyquantity, 1);
                            else if (enemytype == "wolf") wolf(level, enemyquantity, 1);
                            else if (enemytype == "slime") slime(level, enemyquantity, 1);
                            else if (enemytype == "bandit") bandit(level, enemyquantity, 1);
                            else if (enemytype == "gnome") gnome(level, enemyquantity, 1);
                        }
                        // instead of floor loot, have 100% xp and coins as reward
                        if (roomquantity <= 5) cout << locationclearrewardsmall(level); // 1-5 room sized location -> small reward
                        else if (roomquantity > 5) cout << locationclearrewardbig(level); // 5-10 room sized location -> slightly better reward
                        cout << "\n▹≻ Having cleared the forest, you are ready to leave.\n";
                        string leave; cin >> leave; cout << "\n";
                        return 0;
                    } 
                    // OTHER ROOMS
                    else{ // Generate other rooms that aren't the first nor last
                        bool empty = emptyroom(); // 35% chance to generate empty room -> 100% chance for floor item

                        if (empty){ // if empty
                            cout << ", but it seems to be empty. \n"<<
                            floor_item("forest") << "\nDo you wish to proceed/p or leave/l the forest? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the forest and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }                                  
                        else{ // if not empty
                            if (enemyquantity == 1) 
                                cout << ".                                 ┃\nAhead of you, is " << enemyquantity 
                                << " enemy.    (3x3)                           ┃\n";
                            if (enemyquantity > 1){
                                cout << ".                                 ┃\nAhead of you, are " 
                                << enemyquantity << " enemies. ";
                                if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                                else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                                else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                                else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                                }
                            string enemytype = forestenemies();
                            if (enemytype == "guard") guard(level, enemyquantity, 1);
                            else if (enemytype == "mutant") mutant(level, enemyquantity, 1);
                            else if (enemytype == "wolf") wolf(level, enemyquantity, 1);
                            else if (enemytype == "slime") slime(level, enemyquantity, 1);
                            else if (enemytype == "bandit") bandit(level, enemyquantity, 1);
                            else if (enemytype == "gnome") gnome(level, enemyquantity, 1);
                            if ((rand()%100+1) <= 55) cout << "\n" << floor_item("forest");
                            cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                            cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the forest? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the forest and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }
                    }
                }
            }
        }
    }
    cout << "▹≻ You leave the forest and continue walking...\n\n";
    return 0;
}

int mountain(){
    cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
    cout << "▹≻ You approach the Mountain.\n";
    int roomquantity, level; bool firstroom = true; string enter, choice;
    int roomsize = rand() % 10 + 1;
    if (roomsize < 8)          roomquantity = rand() % 6 + 1; // room quantity common  1-5 rooms  (70% chance)
    else if (roomsize > 7) roomquantity = rand() % 6 + 5; // room quantity rare    5-10 rooms (30% chance)
    // LOCATION OF 1 ROOM -------------------------------------------------------------------------------------
    if (roomquantity == 1){ // 100% with enemies
        cout << "You have found a mountain of 1 area. Do you venture inside?" << "\n"; // 1 room location
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the mountain and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
            int enemyquantity; // enemy amount
            if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
            else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
            else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
            else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
            else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
            //-----------------------------------------------------------
            if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                << " enemy.    (3x3)\n";
            if (enemyquantity > 1){
                cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                if (enemyquantity == 2) cout << "(4x4)\n";
                else if (enemyquantity == 3) cout << "(5x5)\n";
                else if (enemyquantity == 4) cout << "(7x7)\n";
                else if (enemyquantity >= 5) cout << "(9x9)\n";
                }
            string enemytype = mountainenemies();
            if (enemytype == "skeleton") skeleton(level, enemyquantity);
            else if (enemytype == "guard") guard(level, enemyquantity);
            else if (enemytype == "wolf") wolf(level, enemyquantity);
            else if (enemytype == "bandit") bandit(level, enemyquantity);
            else if (enemytype == "gnome") gnome(level, enemyquantity);
            if ((rand()%100+1) <= 25) cout << "\n" << floor_item("mountain"); // locations with 1 zones have a 25% chance for floor loot
            cout << "Having cleared the area, you are ready to leave the mountain.\n"; 
            string leave; cin >> leave; cout << "\n";
            return 0;
        }
    }
    // LOCATION WITH MORE THAN 1 ROOM -------------------------------------------------------------------------
    else{
        cout << "You have found a mountain of " << roomquantity << " areas." << "\n" << "Do you venture inside? " << "\n";
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the mountain and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            for (int i = 1; i <= roomquantity; i++){
                // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
                int enemyquantity; // enemy amount
                if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
                else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
                else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
                else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
                else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
                //-----------------------------------------------------------
                // FIRST ROOM GENERATOR
                if (firstroom){
                    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                         << "You enter the first area.                                    ┃";

                        if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                            << " enemy.    (3x3)                           ┃\n";
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        string enemytype = mountainenemies();
                        if (enemytype == "skeleton") skeleton(level, enemyquantity);
                        else if (enemytype == "guard") guard(level, enemyquantity);
                        else if (enemytype == "wolf") wolf(level, enemyquantity);
                        else if (enemytype == "bandit") bandit(level, enemyquantity);
                        else if (enemytype == "gnome") gnome(level, enemyquantity);
                        if ((rand()%100+1) <= 55) cout << "\n" << floor_item("mountain");
                        cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                        cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the mountain? »» ";
                        cin >> choice;
                        if (choice == "leave" || choice == "l" || choice == "s"){
                            cout << "\n▹≻ You leave the mountain and continue walking...\n\n";
                            usleep(610000);
                            return 0;
                        }
                        else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                        << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                        << "You walk into the next area";    
                    firstroom = false;
                }
                //---------------------------------------------------------------------------------------------------------------
                // OTHER ROOMS GENERATOR
                else if (firstroom == false){
                    // LAST ROOM
                    if (i == roomquantity){ // Last Room Generator | 100% with enemies
                        cout << ".                                 ┃\nYou have reached the end of the mountain.                    ┃";
                        if (enemyquantity == 1) enemyquantity++;
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        // BOSS SPAWN
                        int chance = rand() % 100 + 1; bool noboss = true;

                        if (roomquantity >= 5 && level > 10 && chance <= 65){ // boss requirements + 70% chance
                            int randomboss = rand() % 2 + 1;
                            if (randomboss == 1) snow_golem(level);
                            else if (randomboss == 2) wind_wyvern(level);
                            string enemytype = mountainenemies();
                            enemyquantity--;
                            if (enemyquantity >= 1){ // if there is still quantity left, use it on troops
                                if (enemytype == "skeleton") skeleton(level, enemyquantity, 2);
                                else if (enemytype == "guard") guard(level, enemyquantity, 2);
                                else if (enemytype == "wolf") wolf(level, enemyquantity, 2);
                                else if (enemytype == "bandit") bandit(level, enemyquantity, 2);
                                else if (enemytype == "gnome") gnome(level, enemyquantity, 2);
                            }
                            noboss = false;
                        }
                        if (noboss){ // if a boss didn't spawn, do normal room
                            string enemytype = mountainenemies();
                            if (enemytype == "skeleton") skeleton(level, enemyquantity);
                            else if (enemytype == "guard") guard(level, enemyquantity);
                            else if (enemytype == "wolf") wolf(level, enemyquantity);
                            else if (enemytype == "bandit") bandit(level, enemyquantity);
                            else if (enemytype == "gnome") gnome(level, enemyquantity);
                        }
                        // instead of floor loot, have 100% xp and coins as reward
                        if (roomquantity <= 5) cout << locationclearrewardsmall(level); // 1-5 room sized location -> small reward
                        else if (roomquantity > 5) cout << locationclearrewardbig(level); // 5-10 room sized location -> slightly better reward
                        cout << "\n▹≻ Having cleared the mountain, you are ready to leave.\n";
                        string leave; cin >> leave; cout << "\n";
                        return 0;
                    } 
                    // OTHER ROOMS
                    else{ // Generate other rooms that aren't the first nor last
                        bool empty = emptyroom(); // 35% chance to generate empty room -> 100% chance for floor item

                        if (empty){ // if empty
                            cout << ", but it seems to be empty. \n"<<
                            floor_item("mountain") << "\nDo you wish to proceed/p or leave/l the mountain? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the mountain and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }                                  
                        else{ // if not empty
                            if (enemyquantity == 1) 
                                cout << ".                                 ┃\nAhead of you, is " << enemyquantity 
                                << " enemy.    (3x3)                           ┃\n";
                            if (enemyquantity > 1){
                                cout << ".                                 ┃\nAhead of you, are " 
                                << enemyquantity << " enemies. ";
                                if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                                else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                                else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                                else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                                }
                            string enemytype = mountainenemies();
                            if (enemytype == "skeleton") skeleton(level, enemyquantity);
                            else if (enemytype == "guard") guard(level, enemyquantity);
                            else if (enemytype == "wolf") wolf(level, enemyquantity);
                            else if (enemytype == "bandit") bandit(level, enemyquantity);
                            else if (enemytype == "gnome") gnome(level, enemyquantity);
                            if ((rand()%100+1) <= 55) cout << "\n" << floor_item("mountain");
                            cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                            cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the mountain? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the mountain and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }
                    }
                }
            }
        }
    }
    cout << "▹≻ You leave the mountain and continue walking...\n\n";
    return 0;
}

int lake(){
    cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
    cout << "▹≻ You approach the Lake.\n";
    int roomquantity, level; bool firstroom = true; string enter, choice;
    int roomsize = rand() % 10 + 1;
    if (roomsize < 8)          roomquantity = rand() % 6 + 1; // room quantity common  1-5 rooms  (70% chance)
    else if (roomsize > 7) roomquantity = rand() % 6 + 5; // room quantity rare    5-10 rooms (30% chance)
    // LOCATION OF 1 ROOM -------------------------------------------------------------------------------------
    if (roomquantity == 1){ // 100% with enemies
        cout << "You have found a lake of 1 area. Do you venture inside?" << "\n"; // 1 room location
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the lake and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
            int enemyquantity; // enemy amount
            if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
            else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
            else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
            else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
            else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
            //-----------------------------------------------------------
            if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                << " enemy.    (3x3)\n";
            if (enemyquantity > 1){
                cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                if (enemyquantity == 2) cout << "(4x4)\n";
                else if (enemyquantity == 3) cout << "(5x5)\n";
                else if (enemyquantity == 4) cout << "(7x7)\n";
                else if (enemyquantity >= 5) cout << "(9x9)\n";
                }
            string enemytype = lakeenemies();
            if (enemytype == "mutant") mutant(level, enemyquantity);
            else if (enemytype == "wolf") wolf(level, enemyquantity);
            else if (enemytype == "bandit") bandit(level, enemyquantity);
            else if (enemytype == "fish_crawler") fish_crawler(level, enemyquantity);
            else if (enemytype == "siren") siren(level, enemyquantity);
            if ((rand()%100+1) <= 25) cout << "\n" << floor_item("lake"); // locations with 1 zones have a 25% chance for floor loot
            cout << "Having cleared the area, you are ready to leave the lake.\n"; 
            string leave; cin >> leave; cout << "\n";
            return 0;
        }
    }
    // LOCATION WITH MORE THAN 1 ROOM -------------------------------------------------------------------------
    else{
        cout << "You have found a lake of " << roomquantity << " areas." << "\n" << "Do you venture inside? " << "\n";
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the lake and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            for (int i = 1; i <= roomquantity; i++){
                // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
                int enemyquantity; // enemy amount
                if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
                else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
                else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
                else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
                else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
                //-----------------------------------------------------------
                // FIRST ROOM GENERATOR
                if (firstroom){
                    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                         << "You enter the first area.                                    ┃";

                        if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                            << " enemy.    (3x3)                           ┃\n";
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        string enemytype = lakeenemies();
                        if (enemytype == "mutant") mutant(level, enemyquantity);
                        else if (enemytype == "wolf") wolf(level, enemyquantity);
                        else if (enemytype == "bandit") bandit(level, enemyquantity);
                        else if (enemytype == "fish_crawler") fish_crawler(level, enemyquantity);
                        else if (enemytype == "siren") siren(level, enemyquantity);
                        if ((rand()%100+1) <= 55) cout << "\n" << floor_item("lake");
                        cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                        cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the lake? »» ";
                        cin >> choice;
                        if (choice == "leave" || choice == "l" || choice == "s"){
                            cout << "\n▹≻ You leave the lake and continue walking...\n\n";
                            usleep(610000);
                            return 0;
                        }
                        else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                        << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                        << "You walk into the next area";    
                    firstroom = false;
                }
                //---------------------------------------------------------------------------------------------------------------
                // OTHER ROOMS GENERATOR
                else if (firstroom == false){
                    // LAST ROOM
                    if (i == roomquantity){ // Last Room Generator | 100% with enemies
                        cout << ".                                 ┃\nYou have reached the end of the lake.                        ┃";
                        if (enemyquantity == 1) enemyquantity++;
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        // BOSS SPAWN
                        int chance = rand() % 100 + 1; bool noboss = true;

                        if (roomquantity >= 5 && level > 10 && chance <= 65){ // boss requirements + 70% chance
                            int randomboss = rand() % 2 + 1;
                            if (randomboss == 1) tomb_serpent(level);
                            else if (randomboss == 2) sand_worm(level);
                            string enemytype = lakeenemies();
                            enemyquantity--;
                            if (enemyquantity >= 1){ // if there is still quantity left, use it on troops
                                if (enemytype == "mutant") mutant(level, enemyquantity, 2);
                                else if (enemytype == "wolf") wolf(level, enemyquantity, 2);
                                else if (enemytype == "bandit") bandit(level, enemyquantity, 2);
                                else if (enemytype == "fish_crawler") fish_crawler(level, enemyquantity, 2);
                                else if (enemytype == "siren") siren(level, enemyquantity, 2);
                            }
                            noboss = false;
                        }
                        if (noboss){ // if a boss didn't spawn, do normal room
                            string enemytype = lakeenemies();
                            if (enemytype == "mutant") mutant(level, enemyquantity);
                            else if (enemytype == "wolf") wolf(level, enemyquantity);
                            else if (enemytype == "bandit") bandit(level, enemyquantity);
                            else if (enemytype == "fish_crawler") fish_crawler(level, enemyquantity);
                            else if (enemytype == "siren") siren(level, enemyquantity);
                        }
                        // instead of floor loot, have 100% xp and coins as reward
                        if (roomquantity <= 5) cout << locationclearrewardsmall(level); // 1-5 room sized location -> small reward
                        else if (roomquantity > 5) cout << locationclearrewardbig(level); // 5-10 room sized location -> slightly better reward
                        cout << "\n▹≻ Having cleared the lake, you are ready to leave.\n";
                        string leave; cin >> leave; cout << "\n";
                        return 0;
                    } 
                    // OTHER ROOMS
                    else{ // Generate other rooms that aren't the first nor last
                        bool empty = emptyroom(); // 35% chance to generate empty room -> 100% chance for floor item

                        if (empty){ // if empty
                            cout << ", but it seems to be empty. \n"<<
                            floor_item("lake") << "\nDo you wish to proceed/p or leave/l the lake? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the lake and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }                                  
                        else{ // if not empty
                            if (enemyquantity == 1) 
                                cout << ".                                 ┃\nAhead of you, is " << enemyquantity 
                                << " enemy.    (3x3)                           ┃\n";
                            if (enemyquantity > 1){
                                cout << ".                                 ┃\nAhead of you, are " 
                                << enemyquantity << " enemies. ";
                                if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                                else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                                else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                                else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                                }
                            string enemytype = lakeenemies();
                            if (enemytype == "mutant") mutant(level, enemyquantity);
                            else if (enemytype == "wolf") wolf(level, enemyquantity);
                            else if (enemytype == "bandit") bandit(level, enemyquantity);
                            else if (enemytype == "fish_crawler") fish_crawler(level, enemyquantity);
                            else if (enemytype == "siren") siren(level, enemyquantity);
                            if ((rand()%100+1) <= 55) cout << "\n" << floor_item("lake");
                            cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                            cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the lake? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the lake and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }
                    }
                }
            }
        }
    }
    cout << "▹≻ You leave the lake and continue walking...\n\n";
    return 0;
}

int camp(){
    cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
    cout << "▹≻ You approach the Camp.\n";
    int roomquantity, level; bool firstroom = true; string enter, choice;
    int roomsize = rand() % 10 + 1;
    if (roomsize < 8)          roomquantity = rand() % 6 + 1; // room quantity common  1-5 rooms  (70% chance)
    else if (roomsize > 7) roomquantity = rand() % 6 + 5; // room quantity rare    5-10 rooms (30% chance)
    // LOCATION OF 1 ROOM -------------------------------------------------------------------------------------
    if (roomquantity == 1){ // 100% with enemies
        cout << "You have found a camp of 1 area. Do you venture inside?" << "\n"; // 1 room location
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the camp and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
            int enemyquantity; // enemy amount
            if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
            else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
            else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
            else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
            else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
            //-----------------------------------------------------------
            if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                << " enemy.    (3x3)\n";
            if (enemyquantity > 1){
                cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                if (enemyquantity == 2) cout << "(4x4)\n";
                else if (enemyquantity == 3) cout << "(5x5)\n";
                else if (enemyquantity == 4) cout << "(7x7)\n";
                else if (enemyquantity >= 5) cout << "(9x9)\n";
                }
            string enemytype = campenemies();
            if (enemytype == "guard") guard(level, enemyquantity);
            else if (enemytype == "wolf") wolf(level, enemyquantity);
            else if (enemytype == "bandit") bandit(level, enemyquantity);
            if ((rand()%100+1) <= 25) cout << "\n" << floor_item("camp"); // locations with 1 zones have a 25% chance for floor loot
            cout << "Having cleared the area, you are ready to leave the camp.\n"; 
            string leave; cin >> leave; cout << "\n";
            return 0;
        }
    }
    // LOCATION WITH MORE THAN 1 ROOM -------------------------------------------------------------------------
    else{
        cout << "You have found a camp of " << roomquantity << " areas." << "\n" << "Do you venture inside? " << "\n";
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the camp and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            for (int i = 1; i <= roomquantity; i++){
                // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
                int enemyquantity; // enemy amount
                if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
                else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
                else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
                else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
                else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
                //-----------------------------------------------------------
                // FIRST ROOM GENERATOR
                if (firstroom){
                    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                         << "You enter the first area.                                    ┃";

                        if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                            << " enemy.    (3x3)                           ┃\n";
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        string enemytype = campenemies();
                        if (enemytype == "guard") guard(level, enemyquantity);
                        else if (enemytype == "wolf") wolf(level, enemyquantity);
                        else if (enemytype == "bandit") bandit(level, enemyquantity);
                        if ((rand()%100+1) <= 55) cout << "\n" << floor_item("camp");
                        cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                        cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the camp? »» ";
                        cin >> choice;
                        if (choice == "leave" || choice == "l" || choice == "s"){
                            cout << "\n▹≻ You leave the camp and continue walking...\n\n";
                            usleep(610000);
                            return 0;
                        }
                        else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                        << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                        << "You walk into the next area";    
                    firstroom = false;
                }
                //---------------------------------------------------------------------------------------------------------------
                // OTHER ROOMS GENERATOR
                else if (firstroom == false){
                    // LAST ROOM
                    if (i == roomquantity){ // Last Room Generator | 100% with enemies
                        cout << ".                                 ┃\nYou have reached the end of the camp.                        ┃";
                        if (enemyquantity == 1) enemyquantity++;
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        // BOSS SPAWN
                        int chance = rand() % 100 + 1; bool noboss = true;

                        if (roomquantity >= 5 && level > 10 && chance <= 65){ // boss requirements + 70% chance
                            int randomboss = rand() % 3 + 1;
                            if (randomboss == 1) high_guard(level);
                            else if (randomboss == 2) hammer_guard(level);
                            else if (randomboss == 3) king_orc(level);
                            string enemytype = campenemies();
                            enemyquantity--;
                            if (enemyquantity >= 1){ // if there is still quantity left, use it on troops
                                if (enemytype == "guard") guard(level, enemyquantity, 2);
                                else if (enemytype == "wolf") wolf(level, enemyquantity, 2);
                                else if (enemytype == "bandit") bandit(level, enemyquantity, 2);
                            }
                            noboss = false;
                        }
                        if (noboss){ // if a boss didn't spawn, do normal room
                            string enemytype = campenemies();
                            if (enemytype == "guard") guard(level, enemyquantity);
                            else if (enemytype == "wolf") wolf(level, enemyquantity);
                            else if (enemytype == "bandit") bandit(level, enemyquantity);
                        }
                        // instead of floor loot, have 100% xp and coins as reward
                        if (roomquantity <= 5) cout << locationclearrewardsmall(level); // 1-5 room sized location -> small reward
                        else if (roomquantity > 5) cout << locationclearrewardbig(level); // 5-10 room sized location -> slightly better reward
                        cout << "\n▹≻ Having cleared the camp, you are ready to leave.\n";
                        string leave; cin >> leave; cout << "\n";
                        return 0;
                    } 
                    // OTHER ROOMS
                    else{ // Generate other rooms that aren't the first nor last
                        bool empty = emptyroom(); // 35% chance to generate empty room -> 100% chance for floor item

                        if (empty){ // if empty
                            cout << ", but it seems to be empty. \n"<<
                            floor_item("camp") << "\nDo you wish to proceed/p or leave/l the camp? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the camp and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }                                  
                        else{ // if not empty
                            if (enemyquantity == 1) 
                                cout << ".                                 ┃\nAhead of you, is " << enemyquantity 
                                << " enemy.    (3x3)                           ┃\n";
                            if (enemyquantity > 1){
                                cout << ".                                 ┃\nAhead of you, are " 
                                << enemyquantity << " enemies. ";
                                if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                                else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                                else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                                else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                                }
                            string enemytype = campenemies();
                            if (enemytype == "guard") guard(level, enemyquantity);
                            else if (enemytype == "wolf") wolf(level, enemyquantity);
                            else if (enemytype == "bandit") bandit(level, enemyquantity);
                            if ((rand()%100+1) <= 55) cout << "\n" << floor_item("camp");
                            cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                            cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the camp? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the camp and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }
                    }
                }
            }
        }
    }
    cout << "▹≻ You leave the camp and continue walking...\n\n";
    return 0;
}

int dungeon(){
    cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
    cout << "▹≻ You approach the Dungeon.\n";
    int roomquantity, level; bool firstroom = true; string enter, choice;
    int roomsize = rand() % 10 + 1;
    if (roomsize < 8)          roomquantity = rand() % 6 + 1; // room quantity common  1-5 rooms  (70% chance)
    else if (roomsize > 7) roomquantity = rand() % 6 + 5; // room quantity rare    5-10 rooms (30% chance)
    // LOCATION OF 1 ROOM -------------------------------------------------------------------------------------
    if (roomquantity == 1){ // 100% with enemies
        cout << "You have found a dungeon of 1 area. Do you venture inside?" << "\n"; // 1 room location
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the dungeon and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
            int enemyquantity; // enemy amount
            if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
            else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
            else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
            else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
            else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
            //-----------------------------------------------------------
            if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                << " enemy.    (3x3)\n";
            if (enemyquantity > 1){
                cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                if (enemyquantity == 2) cout << "(4x4)\n";
                else if (enemyquantity == 3) cout << "(5x5)\n";
                else if (enemyquantity == 4) cout << "(7x7)\n";
                else if (enemyquantity >= 5) cout << "(9x9)\n";
                }
            string enemytype = dungeonenemies();
            if (enemytype == "skeleton") skeleton(level, enemyquantity);
            else if (enemytype == "guard") guard(level, enemyquantity);
            else if (enemytype == "mutant") mutant(level, enemyquantity);
            else if (enemytype == "slime") slime(level, enemyquantity);
            else if (enemytype == "bucket_slime") bucket_slime(level, enemyquantity);
            else if (enemytype == "mimic") mimic(level, enemyquantity);
            else if (enemytype == "necromancer") necromancer(level, enemyquantity);
            else if (enemytype == "fish_crawler") fish_crawler(level, enemyquantity);
            if ((rand()%100+1) <= 25) cout << "\n" << floor_item("dungeon"); // locations with 1 zones have a 25% chance for floor loot
            cout << "Having cleared the area, you are ready to leave the dungeon.\n"; 
            string leave; cin >> leave; cout << "\n";
            return 0;
        }
    }
    // LOCATION WITH MORE THAN 1 ROOM -------------------------------------------------------------------------
    else{
        cout << "You have found a dungeon of " << roomquantity << " areas." << "\n" << "Do you venture inside? " << "\n";
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the dungeon and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            for (int i = 1; i <= roomquantity; i++){
                // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
                int enemyquantity; // enemy amount
                if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
                else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
                else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
                else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
                else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
                //-----------------------------------------------------------
                // FIRST ROOM GENERATOR
                if (firstroom){
                    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                         << "You enter the first area.                                    ┃";

                        if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                            << " enemy.    (3x3)                           ┃\n";
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        string enemytype = dungeonenemies();
                        if (enemytype == "skeleton") skeleton(level, enemyquantity);
                        else if (enemytype == "guard") guard(level, enemyquantity);
                        else if (enemytype == "mutant") mutant(level, enemyquantity);
                        else if (enemytype == "slime") slime(level, enemyquantity);
                        else if (enemytype == "bucket_slime") bucket_slime(level, enemyquantity);
                        else if (enemytype == "mimic") mimic(level, enemyquantity);
                        else if (enemytype == "necromancer") necromancer(level, enemyquantity);
                        else if (enemytype == "fish_crawler") fish_crawler(level, enemyquantity);
                        if ((rand()%100+1) <= 55) cout << "\n" << floor_item("dungeon");
                        cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                        cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the dungeon? »» ";
                        cin >> choice;
                        if (choice == "leave" || choice == "l" || choice == "s"){
                            cout << "\n▹≻ You leave the dungeon and continue walking...\n\n";
                            usleep(610000);
                            return 0;
                        }
                        else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                        << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                        << "You walk into the next area";    
                    firstroom = false;
                }
                //---------------------------------------------------------------------------------------------------------------
                // OTHER ROOMS GENERATOR
                else if (firstroom == false){
                    // LAST ROOM
                    if (i == roomquantity){ // Last Room Generator | 100% with enemies
                        cout << ".                                 ┃\nYou have reached the end of the dungeon.                     ┃";
                        if (enemyquantity == 1) enemyquantity++;
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        // BOSS SPAWN
                        int chance = rand() % 100 + 1; bool noboss = true;

                        if (roomquantity >= 5 && level > 10 && chance <= 65){ // boss requirements + 70% chance
                            int randomboss = rand() % 4 + 1;
                            if (randomboss == 1) tomb_serpent(level);
                            else if (randomboss == 2) hammer_guard(level);
                            else if (randomboss == 3) stone_golem(level);
                            else if (randomboss == 4) moss_golem(level);
                            string enemytype = dungeonenemies();
                            enemyquantity--;
                            if (enemyquantity >= 1){ // if there is still quantity left, use it on troops
                                if (enemytype == "skeleton") skeleton(level, enemyquantity, 2);
                                else if (enemytype == "guard") guard(level, enemyquantity, 2);
                                else if (enemytype == "mutant") mutant(level, enemyquantity, 2);
                                else if (enemytype == "slime") slime(level, enemyquantity, 2);
                                else if (enemytype == "bucket_slime") bucket_slime(level, enemyquantity, 2);
                                else if (enemytype == "mimic") mimic(level, enemyquantity, 2);
                                else if (enemytype == "necromancer") necromancer(level, enemyquantity, 2);
                                else if (enemytype == "fish_crawler") fish_crawler(level, enemyquantity, 2);
                            }
                            noboss = false;
                        }
                        if (noboss){ // if a boss didn't spawn, do normal room
                            string enemytype = dungeonenemies();
                            if (enemytype == "skeleton") skeleton(level, enemyquantity);
                            else if (enemytype == "guard") guard(level, enemyquantity);
                            else if (enemytype == "mutant") mutant(level, enemyquantity);
                            else if (enemytype == "slime") slime(level, enemyquantity);
                            else if (enemytype == "bucket_slime") bucket_slime(level, enemyquantity);
                            else if (enemytype == "mimic") mimic(level, enemyquantity);
                            else if (enemytype == "necromancer") necromancer(level, enemyquantity);
                            else if (enemytype == "fish_crawler") fish_crawler(level, enemyquantity);
                        }
                        // instead of floor loot, have 100% xp and coins as reward
                        if (roomquantity <= 5) cout << locationclearrewardsmall(level); // 1-5 room sized location -> small reward
                        else if (roomquantity > 5) cout << locationclearrewardbig(level); // 5-10 room sized location -> slightly better reward
                        cout << "\n▹≻ Having cleared the dungeon, you are ready to leave.\n";
                        string leave; cin >> leave; cout << "\n";
                        return 0;
                    } 
                    // OTHER ROOMS
                    else{ // Generate other rooms that aren't the first nor last
                        bool empty = emptyroom(); // 35% chance to generate empty room -> 100% chance for floor item

                        if (empty){ // if empty
                            cout << ", but it seems to be empty. \n"<<
                            floor_item("dungeon") << "\nDo you wish to proceed/p or leave/l the dungeon? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the dungeon and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }                                  
                        else{ // if not empty
                            if (enemyquantity == 1) 
                                cout << ".                                 ┃\nAhead of you, is " << enemyquantity 
                                << " enemy.    (3x3)                           ┃\n";
                            if (enemyquantity > 1){
                                cout << ".                                 ┃\nAhead of you, are " 
                                << enemyquantity << " enemies. ";
                                if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                                else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                                else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                                else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                                }
                            string enemytype = dungeonenemies();
                            if (enemytype == "skeleton") skeleton(level, enemyquantity);
                            else if (enemytype == "guard") guard(level, enemyquantity);
                            else if (enemytype == "mutant") mutant(level, enemyquantity);
                            else if (enemytype == "slime") slime(level, enemyquantity);
                            else if (enemytype == "bucket_slime") bucket_slime(level, enemyquantity);
                            else if (enemytype == "mimic") mimic(level, enemyquantity);
                            else if (enemytype == "necromancer") necromancer(level, enemyquantity);
                            else if (enemytype == "fish_crawler") fish_crawler(level, enemyquantity);
                            if ((rand()%100+1) <= 55) cout << "\n" << floor_item("dungeon");
                            cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                            cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the dungeon? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the dungeon and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }
                    }
                }
            }
        }
    }
    cout << "▹≻ You leave the dungeon and continue walking...\n\n";
    return 0;
}

int ruin(){
    cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
    cout << "▹≻ You approach the Ruin.\n";
    int roomquantity, level; bool firstroom = true; string enter, choice;
    int roomsize = rand() % 10 + 1;
    if (roomsize < 8)          roomquantity = rand() % 6 + 1; // room quantity common  1-5 rooms  (70% chance)
    else if (roomsize > 7) roomquantity = rand() % 6 + 5; // room quantity rare    5-10 rooms (30% chance)
    // LOCATION OF 1 ROOM -------------------------------------------------------------------------------------
    if (roomquantity == 1){ // 100% with enemies
        cout << "You have found a ruin of 1 area. Do you venture inside?" << "\n"; // 1 room location
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the ruin and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
            int enemyquantity; // enemy amount
            if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
            else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
            else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
            else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
            else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
            //-----------------------------------------------------------
            if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                << " enemy.    (3x3)\n";
            if (enemyquantity > 1){
                cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                if (enemyquantity == 2) cout << "(4x4)\n";
                else if (enemyquantity == 3) cout << "(5x5)\n";
                else if (enemyquantity == 4) cout << "(7x7)\n";
                else if (enemyquantity >= 5) cout << "(9x9)\n";
                }
            string enemytype = ruinenemies();
            if (enemytype == "skeleton") skeleton(level, enemyquantity);
            else if (enemytype == "guard") guard(level, enemyquantity);
            else if (enemytype == "slime") slime(level, enemyquantity);
            else if (enemytype == "bucket_slime") bucket_slime(level, enemyquantity);
            else if (enemytype == "mimic") mimic(level, enemyquantity);
            else if (enemytype == "necromancer") necromancer(level, enemyquantity);
            if ((rand()%100+1) <= 25) cout << "\n" << floor_item("ruin"); // locations with 1 zones have a 25% chance for floor loot
            cout << "Having cleared the area, you are ready to leave the ruin.\n"; 
            string leave; cin >> leave; cout << "\n";
            return 0;
        }
    }
    // LOCATION WITH MORE THAN 1 ROOM -------------------------------------------------------------------------
    else{
        cout << "You have found a ruin of " << roomquantity << " areas." << "\n" << "Do you venture inside? " << "\n";
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the ruin and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫─────────────────────────────────────────────────────────────⌦\n\n";
            for (int i = 1; i <= roomquantity; i++){
                // according to level, generate quantity of enemies: (enemy leaders start spawning after level 10 -> 3 or more enemies)
                int enemyquantity; // enemy amount
                if (level <= 10) enemyquantity = rand() % 2 + 1;            // 1-2 enemies if level <= 10
                else if (11 <= level && level <= 20) enemyquantity = rand() % 3 + 1; // 1-3 enemies if level in [11,20]
                else if (21 <= level && level <= 50) enemyquantity = rand() % 3 + 2; // 2-4 enemies if level in [21,50]
                else if (51 <= level && level <= 90) enemyquantity = rand() % 3 + 3; // 3-5 enemies if level in [51,90]
                else if (level >= 91) enemyquantity = rand() % 6 + 4;       // 4-6 enemies if level >= 91
                //-----------------------------------------------------------
                // FIRST ROOM GENERATOR
                if (firstroom){
                    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                         << "You enter the first area.                                    ┃";

                        if (enemyquantity == 1) cout << "\nAhead of you, is " << enemyquantity 
                            << " enemy.    (3x3)                           ┃\n";
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        string enemytype = ruinenemies();
                        if (enemytype == "skeleton") skeleton(level, enemyquantity);
                        else if (enemytype == "guard") guard(level, enemyquantity);
                        else if (enemytype == "slime") slime(level, enemyquantity);
                        else if (enemytype == "bucket_slime") bucket_slime(level, enemyquantity);
                        else if (enemytype == "mimic") mimic(level, enemyquantity);
                        else if (enemytype == "necromancer") necromancer(level, enemyquantity);
                        if ((rand()%100+1) <= 55) cout << "\n" << floor_item("ruin");
                        cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                        cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the ruin? »» ";
                        cin >> choice;
                        if (choice == "leave" || choice == "l" || choice == "s"){
                            cout << "\n▹≻ You leave the ruin and continue walking...\n\n";
                            usleep(610000);
                            return 0;
                        }
                        else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                        << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                        << "You walk into the next area";    
                    firstroom = false;
                }
                //---------------------------------------------------------------------------------------------------------------
                // OTHER ROOMS GENERATOR
                else if (firstroom == false){
                    // LAST ROOM
                    if (i == roomquantity){ // Last Room Generator | 100% with enemies
                        cout << ".                                 ┃\nYou have reached the end of the ruin.                        ┃";
                        if (enemyquantity == 1) enemyquantity++;
                        if (enemyquantity > 1){
                            cout << "\nAhead of you, are " << enemyquantity << " enemies. ";
                            if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                            else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                            else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                            else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                            }
                        // BOSS SPAWN
                        int chance = rand() % 100 + 1; bool noboss = true;

                        if (roomquantity >= 5 && level > 10 && chance <= 65){ // boss requirements + 70% chance
                            int randomboss = rand() % 4 + 1;
                            if (randomboss == 1) sand_worm(level);
                            else if (randomboss == 2) stone_golem(level);
                            else if (randomboss == 3) arachnia(level);
                            else if (randomboss == 4) wind_wyvern(level);
                            string enemytype = ruinenemies();
                            enemyquantity--;
                            if (enemyquantity >= 1){ // if there is still quantity left, use it on troops
                                if (enemytype == "skeleton") skeleton(level, enemyquantity, 2);
                                else if (enemytype == "guard") guard(level, enemyquantity, 2);
                                else if (enemytype == "slime") slime(level, enemyquantity, 2);
                                else if (enemytype == "bucket_slime") bucket_slime(level, enemyquantity, 2);
                                else if (enemytype == "mimic") mimic(level, enemyquantity, 2);
                                else if (enemytype == "necromancer") necromancer(level, enemyquantity, 2);
                            }
                            noboss = false;
                        }
                        if (noboss){ // if a boss didn't spawn, do normal room
                            string enemytype = ruinenemies();
                            if (enemytype == "skeleton") skeleton(level, enemyquantity);
                            else if (enemytype == "guard") guard(level, enemyquantity);
                            else if (enemytype == "slime") slime(level, enemyquantity);
                            else if (enemytype == "bucket_slime") bucket_slime(level, enemyquantity);
                            else if (enemytype == "mimic") mimic(level, enemyquantity);
                            else if (enemytype == "necromancer") necromancer(level, enemyquantity);
                        }
                        // instead of floor loot, have 100% xp and coins as reward
                        if (roomquantity <= 5) cout << locationclearrewardsmall(level); // 1-5 room sized location -> small reward
                        else if (roomquantity > 5) cout << locationclearrewardbig(level); // 5-10 room sized location -> slightly better reward
                        cout << "\n▹≻ Having cleared the ruin, you are ready to leave.\n";
                        string leave; cin >> leave; cout << "\n";
                        return 0;
                    } 
                    // OTHER ROOMS
                    else{ // Generate other rooms that aren't the first nor last
                        bool empty = emptyroom(); // 35% chance to generate empty room -> 100% chance for floor item

                        if (empty){ // if empty
                            cout << ", but it seems to be empty. \n"<<
                            floor_item("ruin") << "\nDo you wish to proceed/p or leave/l the ruin? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the ruin and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }                                  
                        else{ // if not empty
                            if (enemyquantity == 1) 
                                cout << ".                                 ┃\nAhead of you, is " << enemyquantity 
                                << " enemy.    (3x3)                           ┃\n";
                            if (enemyquantity > 1){
                                cout << ".                                 ┃\nAhead of you, are " 
                                << enemyquantity << " enemies. ";
                                if (enemyquantity == 2) cout << "(4x4)                           ┃\n";
                                else if (enemyquantity == 3) cout << "(5x5)                           ┃\n";
                                else if (enemyquantity == 4) cout << "(7x7)                           ┃\n";
                                else if (enemyquantity >= 5) cout << "(9x9)                           ┃\n";
                                }
                            string enemytype = ruinenemies();
                            if (enemytype == "skeleton") skeleton(level, enemyquantity);
                            else if (enemytype == "guard") guard(level, enemyquantity);
                            else if (enemytype == "slime") slime(level, enemyquantity);
                            else if (enemytype == "bucket_slime") bucket_slime(level, enemyquantity);
                            else if (enemytype == "mimic") mimic(level, enemyquantity);
                            else if (enemytype == "necromancer") necromancer(level, enemyquantity);
                            if ((rand()%100+1) <= 55) cout << "\n" << floor_item("ruin");
                            cout << "\n⌫─────────────────────────────────────────────────────────────⌦" << "\n";
                            cout << "After the area is cleared,\ndo you wish to proceed/p or leave/l the ruin? »» ";
                            cin >> choice;
                            if (choice == "leave" || choice == "l" || choice == "s"){
                                cout << "\n▹≻ You leave the ruin and continue walking...\n\n";
                                usleep(610000);
                                return 0;
                            }
                            else if (choice == "proceed" || choice == "p" || choice == "w") cout << "\n" 
                            << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┳▶" << "\n" 
                            << "You walk into the next area";
                        }
                    }
                }
            }
        }
    }
    cout << "▹≻ You leave the ruin and continue walking...\n\n";
    return 0;
}

int village(){
    int level; string enter;
    cout << "▹≻ You approach the Village.\n";
    cout << "Do you venture inside?" << "\n"; // 1 room location
        cout << "[y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO"){
            cout << "⌫────────────────────────────────────────────⌦" << "\n";
            cout << "\n▹≻ You leave the village and continue walking...\n\n";
            usleep(610000);
            return 0;
            }
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "What is your party's level? "; // highest member level is used to generate zone/room and rest of location
            cin >> level;
            cout << "⌫────────────────────────────────────────────⌦" << "\n";
            if (level >= 10 && (rand() % 100 + 1) < 40)
            cout << "Walking around the area, you meet a traveler:\n";
            hire(level);

        }
    string leave; cin >> leave; cout << "\n";
    cout << "▹≻ You continue walking...\n\n";
    return 0;
}


// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
// ADVENTURE FUNCTIONS

// Adventure Messages ----------------------------------------------------------------------------------------------
string beginadventuremessage(){ // for adventure() function loading
    vector<string> messages = {
        "And so, you begin your exploration throughout the lands. \n",
        "With that, your expedition across the land commences. \n",
        "You step into the unknown, commencing your exploration of the \nlands. ",
        "The moment to explore the lands has arrived, and you embrace \nit. ",
        "And with that, your journey of discovery throughout the lands \nbegins. "
    };
    return messages[(rand()%5)];
}
string continueadventuremessage(){ // for adventure() function 'for' loop loading
    vector<string> messages = {
        "Ahead of you, you see: \n",
        "What lies ahead is: \n",
        "Directly ahead, there appears: \n",
        "Before you, unfolds the sight of: \n",
        "Stretching before you, there is: \n",
        "Right before your eyes, you observe: \n",
        "In the distance, you discern: \n"
    };
    return messages[(rand()%7)];
}
//------------------------------------------------------------------------------------------------------------------

// Adventure Function (aka Path Generator) -------------------------------------------------------------------------
int adventure(){
    srand(time(NULL));
    bool adventurestart = true;
    vector<string> locations = { // some locations have higher probability to be found (reason for repetition)
        "⍆ A Forest  ",
        "⍆ A Forest  ",
        "⍆ A Mountain",
        "⍆ A Mountain",
        "⍆ A Lake    ",
        "⍆ A Camp    ",
        "⍆ A Dungeon ",
        "⍆ A Dungeon ",
        "⍆ A Ruin    ",
        "⍆ A Village "};
    for (int walklength = 0; walklength < 1000; walklength++){
        string option_1 = locations[(rand() % 10)], option_2 = locations[(rand() % 10)], choice;
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━⚔━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
        if (adventurestart){ // only used when loading function, else flag is false
            cout << beginadventuremessage(); 
            adventurestart = false;
        }
        cout << continueadventuremessage(); 
        cout << option_1 << "                                                (a)" << "\n";
        cout << option_2 << "                                                (d)" << "\n";
        cout << "⌫─────────────────────────────────────────────────────────────⌦" << "\n";
        cout << "⍆ Continue walking                                          (w)" << "\n";
        cout << "⍆ Return to Adventure Menu                                  (m)" << "\n";
        cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━⚔━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n" << "◼▶ ";
        cin >> choice; cout << "\n";
        if (choice == "a"){ // go left -> look for asserted location
            if (option_1[6] == 'F') forest();
            else if (option_1[6] == 'M') mountain();
            else if (option_1[6] == 'L') lake();
            else if (option_1[6] == 'C') camp();
            else if (option_1[6] == 'D') dungeon();
            else if (option_1[6] == 'R') ruin();
            else if (option_1[6] == 'V') village();
        }
        else if (choice == "d"){ // go right -> look for asserted location
            if (option_2[6] == 'F') forest();
            else if (option_2[6] == 'M') mountain();
            else if (option_2[6] == 'L') lake();
            else if (option_2[6] == 'C') camp();
            else if (option_2[6] == 'D') dungeon();
            else if (option_2[6] == 'R') ruin();
            else if (option_2[6] == 'V') village();
        }
        else if (choice == "continue" || choice == "w"){ // loads new locations
            usleep(750000);
            cout << "You continue walking...\n\n";
            usleep(750000);
        }
        else if (choice == "menu" || choice == "m") break; // end adventure
    }
    usleep(610000);
    return 0;
}
//------------------------------------------------------------------------------------------------------------------


// Chest Function --------------------------------------------------------------------------------------------------
int chests(){
    string choice;
    for (int limitofuse = 0; limitofuse < 10000; limitofuse++){
    cout << "\n⌫==================================================================⌦" << "\n";
    cout << "» Open a Location Chest for 20 coins each by choosing from the list:\n" <<
            "⌫──────────────────────────────────────────────────────────────────⌦\n" <<
            "⍆ Forest                                                        (f) \n" <<
            "⍆ Mountain                                                      (m) \n" <<
            "⍆ Lake                                                          (l) \n" <<
            "⍆ Camp                                                          (c) \n" <<
            "⍆ Dungeon                                                       (d) \n" <<
            "⍆ Ruin                                                          (r) \n" <<
            "⌫──────────────────────────────────────────────────────────────────⌦\n" <<
            "» Write 'exit'/'e' to return to Adventure Menu                      \n" <<
            "⌫==================================================================⌦\n";
            cin >> choice; cout << "\n";
            if (choice == "forest" || choice == "f") cout << floor_item("forest");
            else if (choice == "mountain" || choice == "m") cout << floor_item("mountain");
            else if (choice == "lake" || choice == "l") cout << floor_item("lake");
            else if (choice == "camp" || choice == "c") cout << floor_item("camp");
            else if (choice == "dungeon" || choice == "d") cout << floor_item("dungeon");
            else if (choice == "ruin" || choice == "r") cout << floor_item("ruin");
            else if (choice == "exit" || choice == "e") break;
        }
    usleep(610000);
    return 0;
}



// Adventure Menu --------------------------------------------------------------------------------------------------
int adventuremenu(){
    usleep(610000);
    string choice;
    for (int limitofuse = 0; limitofuse < 10000; limitofuse++){
    cout << "⌫==========================================================⌦" << "\n";
    cout << "-« Adventure Menu »-"                                         << "\n";
    cout << "⍆ Start Adventure                                        (s)" << "\n";
    cout << "⍆ Open Chests                                            (o)" << "\n";
//  cout << "⍆ Wild Encounter                                         (w)" << "\n";  !! TO BE ADDED !!
    cout << "⍆ Craftables Menu                                        (c)" << "\n";
    cout << "⍆ Return to Main Menu                                    (m)" << "\n";
    cout << "⌫==========================================================⌦" << "\n" << "◼▶ ";
    cin >> choice; cout << "\n";
    // -------------------------------------------------------------------------------------
    // Choice reader:
    if (choice == "start" || choice == "s") { usleep(610000); adventure(); }
    else if (choice == "open" || choice == "chest" || choice == "o") { usleep(610000); chests(); }
    //else if (choice == "wild" || choice == "w") { usleep(610000); wildencounter(); }
    else if (choice == "craftables" || choice == "c") { usleep(610000); craftables(); }
    else if (choice == "menu" || choice == "m") break;
    }
    usleep(610000);
    return 0;
}
//------------------------------------------------------------------------------------------------------------------