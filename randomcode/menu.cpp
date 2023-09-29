#include <iostream>
#include <unistd.h>
#include "adventure.hpp"
#include "info.hpp"
using namespace std;
int main(){
    srand(time(NULL)); // GAME CORE (used to create the least predictable ./menu) -> without this the game isn't actually random
    cout << "\n" << "» Greetings! Welcome to the crpg. What is your name? ";
    string name, choice;
    cin >> name;
    usleep(610000);
    cout << "\n"<< "» Hello " + name + "!" << "\n" << "\n";
    usleep(610000);
    for (int limitofuse = 0; limitofuse < 10000; limitofuse++){
    cout << "⌫==========================================================⌦" << "\n";
    cout << "-« MENU »-"                                                   << "\n";
    cout << "⍆ General Info                                           (i)" << "\n";
    cout << "⍆ Adventure                                              (a)" << "\n";
    cout << "⍆ Dice Throw                                             (d)" << "\n";
    cout << "⍆ Coin Flip                                              (c)" << "\n";
    cout << "⍆ Exit Game                                              (e)" << "\n";
    cout << "⌫==========================================================⌦" << "\n" << "◼▶ ";
    cin >> choice; cout << "\n";
    // -------------------------------------------------------------------------------------
    // Choice reader:
    if (choice == "exit" || choice == "e") break;
    //else if (choice == "break" || choice == "b") exit(0);
    else if (choice == "info" || choice == "i") { usleep(610000); info();              }
    else if (choice == "adventure" || choice == "a") { usleep(610000); adventuremenu();}
    else if (choice == "dice" || choice == "d") { usleep(610000); diceroll();          }
    else if (choice == "coin" || choice == "c") { usleep(610000); coinflip();          }

    }
    cout << "Goodbye " + name + ", hope to see you soon!" << "\n" << "\n";
    usleep(610000);
    return 0;
}
