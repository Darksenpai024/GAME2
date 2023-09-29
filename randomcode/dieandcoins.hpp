#include <iostream>
#include <unistd.h>
using namespace std;

// Functions for random names
int syllables(){ return rand() % 26; }
int listedname(){ return rand() % 19;}

// Die // ----------------------------
int d2(){    return rand() % 2 + 1;  }
int d3(){    return rand() % 3 + 1;  }
int d4(){    return rand() % 4 + 1;  }
int d6(){    return rand() % 6 + 1;  }
int d10(){   return rand() % 10 + 1; }
int d20(){   return rand() % 20 + 1; }
int d100(){  return rand() % 100 + 1;}
int randomstat(){ return rand() % 6; }
//------------------------------------

// Dice Roll Function
int diceroll(){
    char choice;
    cout << "\n" << "» Please write 1 for d4, 2 for d6, 3 for d20 or 4 to go back:" << "\n";
    for (int i = 0; i < 10000; i++){
        cout << "◼▶ ";
        cin >> choice;
        if (choice == '1') cout << "» d④ : " << d4() << "\n" << "---------" << "\n";
        else if (choice == '2') cout << "» d⑥ : " << d6() << "\n" << "---------" << "\n";
        else if (choice == '3') cout << "» d⑳ : " << d20() << "\n" << "---------" << "\n";
        else if (choice == '4'){
            usleep(610000);
            cout << "\n" << "» Returning to Menu..." << "\n";
            usleep(610000);
            break;
        }
        else cout << "» Please write a valid input!" << "\n" << "-------" << "\n";
    }
    return 0;
}

// Coin Flip Function
int coinflip(){
    char choice;
    cout << "\n" << "» Please write 1 for flip or 2 to go back:" << "\n";
    for (int i = 0; i < 10000; i++){
        cout << "-> ";
        cin >> choice;
        if (choice == '1'){
            int flip = d2();
            if (flip == 1) cout << "flip:" << "heads" << "\n" << "----------" << "\n";
            else cout << "flip:" << "tails" << "\n" << "----------" << "\n";
            }
        else if (choice == '2'){
            usleep(610000);
            cout << "\n" << "» Returning to Menu..." << "\n";
            usleep(610000);
            break;
        }
        else cout << "» Please write a valid input!" << "\n" << "----------" << "\n";
    }
    return 0;
}

