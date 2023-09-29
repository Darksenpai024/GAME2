#include <iostream>
#include <random>
using namespace std;

// Name Randomizer
string name(int randomizer){
    string a[] = {"Orc", "Wolf", "Skeleton", "Goblin", "Guard", "Bear", "Slime", "Spider", "Giant Rat", "Bandit", "Balloon"};
    string name_ = a[randomizer];
    return name_;
}

// Stat Randomizer
int stat(int h){
    int randomstat1 = rand() % 6; int modifierone = rand() % 2 + 1;
    int enemystat = h;
    if (modifierone == 1) enemystat = enemystat-randomstat1;
    else enemystat = enemystat+randomstat1;
    return enemystat;
}

// Enemy Maker
int enemy(int h, int f, int dmgaddstat, int enemyquantifier){
    string name_ = name((rand() % 11));
    for (int i = 0; i < enemyquantifier; i++){
        int enemyhealth = stat(h); int enemyform = stat(f);
        int xp; bool boss = false;
        if (enemyhealth % 10 < 5) xp = enemyhealth - (enemyhealth % 10);
        else xp = enemyhealth - (enemyhealth % 10) + 5;
        int move = (rand() % 3) + 1;
        // Random Boss Encounter (5% chance):
        int percentage = rand() % 100 + 1;
        if (percentage <= 5){
            enemyhealth += 8;
            enemyform += 8;
            dmgaddstat += 3;
            xp += 15;
            name_ = "Boss: " + name_;
            boss = true;}
        // --------------------------------
        cout << name_ << " | HP: " << enemyhealth << " | Form: " << enemyform << " | Dmg: " << (rand() % 4) + 1 + dmgaddstat <<  " | T/R: " << move << "\n" << xp << " xp for kill" << "\n";
        if (boss) cout << "If killed +1 in one chosen stat";
        cout << "\n";
    }
    return 0;
}

// Dungeon Boss Function
int dungeonboss(int h, int f, int dmgaddstat){
    string name_ = "Boss: " + name((rand() % 11));
    int enemyhealth = stat(h) + 8; int enemyform = stat(f) + 8;
    int xp;
    if (enemyhealth % 10 < 5) xp = enemyhealth - (enemyhealth % 10);
    else xp = enemyhealth - (enemyhealth % 10) + 5;
    int move = (rand() % 2) + 1;
    cout << name_ << " | HP: " << enemyhealth << " | Form: " << enemyform << " | Dmg: " << (rand() % 4) + 1 + dmgaddstat + 3 <<  " | T/R: " << move << "\n" << xp + 15 << " xp for kill" << "\n";
    cout << "If killed +1 in one chosen stat" << "\n";
    return 0;
}

// Fight Function
int fight(){
    int h, f, lvl;
    //for (int i = 0; i < 50; i++){
        cout << "----------------------------------------------------" << "\n";
        cout << "» Write your HP and Form:" << "\n";
        cin >> h >> f;
        cout << "\n" << "» What level of Fight are you looking for? ";
        cin >> lvl;
        switch (lvl)
        {
        case 0: case 1: case 2: case 3: case 4: case 5:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(15,15, 0, 1);
            break;
        case 6: case 7: case 8: case 9: case 10:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(20,20, 0, 1);
            break;
        case 11: case 12: case 13: case 14: case 15:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(25,25, 1, 1);
            break;
        case 16: case 17: case 18: case 19: case 20:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(30,30, 1, 1);
            break;
        case 21: case 22: case 23: case 24: case 25:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(35,35, 2, 1);
            break;
        case 26: case 27: case 28: case 29: case 30:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(40,40, 2, 1);
            break;
        case 31: case 32: case 33: case 34: case 35:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(45,45, 3, 1);
            break;
        case 36: case 37: case 38: case 39: case 40:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(50,50, 3, 1);
            break;
        case 41: case 42: case 43: case 44: case 45:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(55,55, 4, 1);
            break;
        case 46: case 47: case 48: case 49: case 50:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(60,60, 4, 1);
            break;
        case 51: case 52: case 53: case 54: case 55:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(65,65, 5, 1);
            break;
        case 56: case 57: case 58: case 59: case 60:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(70,70, 5, 1);
            break;
        case 61: case 62: case 63: case 64: case 65: 
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(75,75, 6, 1);
            break;
        case 66: case 67: case 68: case 69: case 70:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(80,80, 6, 1);
            break;
        case 71: case 72: case 73: case 74: case 75: 
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(85,85, 7, 1);
            break;
        case 76: case 77: case 78: case 79: case 80:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(90,90, 7, 1);
            break;
        case 81: case 82: case 83: case 84: case 85:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(95,95, 8, 1);
            break;
        case 86: case 87: case 88: case 89: case 90:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(100,100, 8, 1);
            break;
        case 91: case 92: case 93: case 94: case 95:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(105,105, 9, 1);
            break; 
        case 96: case 97: case 98: case 99: case 100:
            cout << "\n" << "Your HP: " << h << " | Your Form: " << f << "\n";
            enemy(110,110, 9, 1);
            break; 
        default:
            cout << "\n" << "!! Write a proper Level from 0-100 !!" << "\n" << "\n";
            break;
        }
        cout << "----------------------------------------------------" << "\n";
    //}
    return 0;
}

// BIG RULE: fights are accepted against enemies 10 lvls lower or any lvls higher

// Dice Roll Function
int diceroll(){
    char choice;
    cout << "\n" << "Please write 1 for d4, 2 for d6, 3 for d20 or 4 to go back:" << "\n";
    for (int i = 0; i < 1000; i++){
        cout << "-> ";
        cin >> choice;
        if (choice == '1') cout << "r.d4: " << rand() % 4 +1 << "\n" << "---------" << "\n";
        else if (choice == '2') cout << "r.d6: " << rand() % 6 +1 << "\n" << "---------" << "\n";
        else if (choice == '3') cout << "r.d20: " << rand() % 20 +1 << "\n" << "---------" << "\n";
        else if (choice == '4') break;
        else cout << "Please write a valid input!" << "\n" << "-------" << "\n";
    }
    return 0;
}

// Coin Flip Function
int coinflip(){
    char choice;
    cout << "\n" << "Please write 1 for flip or 2 to go back:" << "\n";
    for (int i = 0; i < 1000; i++){
        cout << "-> ";
        cin >> choice;
        if (choice == '1'){
            int flip = rand() % 2 + 1;
            if (flip == 1) cout << "flip:" << "heads" << "\n" << "----------" << "\n";
            else cout << "flip:" << "tails" << "\n" << "----------" << "\n";
            }
        else if (choice == '2') break;
        else cout << "Please write a valid input!" << "\n" << "----------" << "\n";
    }
    return 0;
}

//---------------------------------------------------------------------------------------------------------------------------------------

int enemyquantity(){
    return rand() % 4 + 1;
}

int emptyorfullroom(){
    return rand() % 2;
}

int dmgmodifiercheck(int level){
    if (0 <= level && level <= 10) return 0;
    else if (11 <= level && level <= 20) return 1;
    else if (21 <= level && level <= 30) return 2;
    else if (31 <= level && level <= 40) return 3;
    else if (41 <= level && level <= 50) return 4;
    else if (51 <= level && level <= 60) return 5;
    else if (61 <= level && level <= 70) return 6;
    else if (71 <= level && level <= 80) return 7;
    else if (81 <= level && level <= 90) return 8;
    else if (91 <= level && level <= 100) return 9;
    return 0;
}

int dungeon(){
    int roomquantity = rand() % 10 + 1; bool firstroom = true; string enter; string choice;
    int health, form, level;

    if (roomquantity == 1){
        // have an auxiliar function for rand numbers to have different messages every now and then
        cout << "» You have seem to found a dungeon of 1 room.";
        cout << "\n" << "Will you go in?" << "\n";
        cout << " [Y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO") return 0;
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "\n";
            int enemies = enemyquantity();
            cout << "Ahead of you, are " << enemies << " enemies." << "\n";
            cout << "» Health | Form | Level » ";
            cin >> health >> form >> level;
            cout << "----------------------------------------------------" << "\n";
            enemy(health, form, dmgmodifiercheck(level), enemies);
            cout << "----------------------------------------------------" << "\n" << "Having cleaned the dungeon, you leave." << "\n";
            return 0;
        }
    }
    
    else{
        cout << "» You have seem to found a dungeon of " << roomquantity << " rooms" << "\n" << "Will you go in? " << "\n";
        cout << " [Y/n] »» ";
        cin >> enter;
        if (enter == "n" || enter == "N" || enter == "no" || enter == "No" || enter == "NO") return 0;
        else if (enter == "y" || enter == "Y" || enter == "yes" || enter == "Yes" || enter == "YES"){
            cout << "\n";
            for (int i = 1; i <= roomquantity; i++){
                //---------------------------------------------------------------------------------------------------------------
                // first room checker
                if (firstroom){
                    cout << "You've entered the first room. ";
                    int crowdcheck = emptyorfullroom();
                // if empty
                    if (crowdcheck == 0){
                        cout << "The room seems to be empty. Do you wish to proceed/p or leave/l the dungeon? " << "\n";
                        cin >> choice;
                        if (choice == "leave" || choice == "l") return 0;
                        else if (choice == "proceed" || choice == "p") cout << "\n" << "You walk into the next room. ";
                    }
                // if crowded
                    else if (crowdcheck == 1){
                        int enemies = enemyquantity();
                        cout << "Ahead of you, are " << enemies << " enemies." << "\n";
                        cout << "» Health | Form | Level » ";
                        cin >> health >> form >> level;
                        enemy(health, form, dmgmodifiercheck(level), enemies);
                        cout << "\n" << "After the room is cleaned, do you wish to proceed/p or leave/l the dungeon? " << "\n";
                        cin >> choice;
                        if (choice == "leave" || choice == "l") return 0;
                        else if (choice == "proceed" || choice == "p") cout << "\n" << "You walk into the next room. ";
                    }
                    firstroom = false;
                }
                //---------------------------------------------------------------------------------------------------------------
                // other rooms
                else if (firstroom == false){
                    // check if last room or not
                    if (i == roomquantity){
                        cout << "You have reached the last room of the dungeon. ";
                            cout << "Ahead of you, stands the last enemy." << "\n";
                            cout << "» Health | Form | Level » ";
                            cin >> health >> form >> level;
                            cout << "----------------------------------------------------" << "\n";
                            dungeonboss(health, form, dmgmodifiercheck(level));
                            cout << "----------------------------------------------------" << "\n" << "Having cleaned the dungeon, you leave. " << "\n";
                            return 0;
                    }

                    else{
                        int crowdcheck = emptyorfullroom();
                    // if empty
                        if (crowdcheck == 0){
                            cout << "The room seems to be empty. Do you wish to proceed/p or leave/l the dungeon? " << "\n";
                            cin >> choice;
                            if (choice == "leave" || choice == "l") return 0;
                            else if (choice == "proceed" || choice == "p") cout << "\n" << "You walk into the next room. ";
                        }
                    // if crowded
                        else if (crowdcheck == 1){
                            int enemies = enemyquantity();
                            cout << "Ahead of you, are " << enemies << " enemies." << "\n";
                            cout << "» Health | Form | Level » ";
                            cin >> health >> form >> level;
                            cout << "----------------------------------------------------" << "\n";
                            enemy(health, form, dmgmodifiercheck(level), enemies);
                            cout << "----------------------------------------------------" << "\n" << "After the room is cleaned, do you wish to proceed/p or leave/l the dungeon? " << "\n";
                            cin >> choice;
                            if (choice == "leave" || choice == "l") return 0;
                            else if (choice == "proceed" || choice == "p") cout << "\n" << "You walk into the next room. ";
                        }
                    }
                }
            }
        }
    }
    return 0;
}



int main(){
    cout << "\n" << "» Greetings! Welcome to the crpg. What is your name? ";
    string name;
    cin >> name;
    cout << "\n"<< "» Hello " + name + "!" << "\n";
    for (int i = 0; i < 500; i++){
        string action;
        cout << "\n" << "----------------------------------------------------------------------------------------------------------------------------------------";
        cout << "\n" << "» Please write 'dungeon'/'d' to look for a dungeon, fight'/'f' to battle freely, 'roll'/'r' to throw dice or 'coin'/'c' to flip a coin: " << "\n";
        cin >> action;
        cout << "\n";
        if (action == "dungeon" || action == "d") dungeon();
        else if (action == "fight" || action == "f") fight();
        else if (action == "roll" || action == "r") diceroll();
        else if (action == "coin" || action == "c") coinflip();
    }
    return 0;
}