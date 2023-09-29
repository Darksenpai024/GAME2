#include <iostream>
#include <unistd.h>
#include "enemy.hpp"
#include "adventure.hpp"
using namespace std;
/*
int main(){
    srand(time(NULL));
    for (int i = 0; i < 15; i++){
    hire(15);
    usleep(15000);
    }
    return 0;
}*/

int main(){
    srand(time(NULL));
    adventure();
    //for (int i = 0; i < 3; i++)
    //skeleton(0, rand()%2+1);
    //craftables();
    //vector<int> a;
    //for ( int i = 0; i < 5; i++) a.push_back(rand() % 21 + 15);
    //for ( int i = 0; i < 25; i++){
    //    cout << a[i] << "\n";
    //    hire(a[i]);
    //hire(15);
        //cout << floor_item("forest") << "\n";
        //cout << namegen() << "\n";
        //cout << floor_item("lake") << "\n";
        //cout << floor_item("dungeon") << "\n";
        //cout << floor_item("camp") << "\n";
        //cout << "\n" << "--------------------------------------------------------------------------------" << "\n";
    //}
    return 0;
}

/*
for ( int i = 0; i < 5; i++){
        hire(10);
    }
    return 0;
    */
    