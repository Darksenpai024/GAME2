#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <unistd.h>
#include <random>
#include "item.hpp"
using namespace std;
// generate messages for finding items - Done
// generate locations                  -
// generate enemies                    -
// generate loot                       -
// generate store                      -

// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

// TRAVELER AND STAT FUNCTIONS;
//-----------------------------

// STAT MAKER IN INTERVAL: STAT-5 <= STAT <= STAT+5 ----------------------------------------------------------------
int stat(int current){
    int randomstat1 = rand() % 6; int modifierone = rand() % 2 + 1;
    int newstat = current;
    if (modifierone == 1) newstat = newstat-randomstat1;
    else newstat = newstat+randomstat1;
    usleep(100000);
    return newstat;
}
//------------------------------------------------------------------------------------------------------------------


// NAME GENERATOR FUNCTION (either preset or randomly generated)----------------------------------------------------
string namegen(){
    int randomlygeneratedorlisted = d100();
    if (randomlygeneratedorlisted > 5){
        string prefix_[26] = {"As","Nor","Je","Al","By","Be","Cae","Bel","Ta","Et","Wil","Bran",
                      "Adri","Cy","Ar","Az","Lor","Bri","Ra","Fai","Gol","Ru","No","Lam","Yul","Mar"};
        string sufix_[26] = {"cot","vin","gar","frid","orhk","lan","wyn","dic","bert","inn","na","da","illa",
                      "van","anna","rha","enne","wen","mis","phor","elle","riel","dhar","vir","thus","lka"};
        return prefix_[syllables()] + sufix_[syllables()];
    }
    string listednames_[19] = {"Thom","Tavon","Yosef","Eyleef","Fenton","Tegan","Ballard","Mival","Ingo","Helmut",
                            "Astra","Kira","Tanika","Brunhild","Hiriko","Yuldra","Estrid","Alaine","Margry"};
    return listednames_[listedname()]; // die function 
}
//------------------------------------------------------------------------------------------------------------------


// RANDOM CLASS GENERATOR (used to generate traveler for hire)------------------------------------------------------
string heroclass(){
    string listedclasses[] = {"Healer","Bard","Monk","Mage","Trickster",
    "Alchemist","Scavenger","Cleric","Knight","Barbarian"};
    return listedclasses[d10()];
}
//------------------------------------------------------------------------------------------------------------------


// YOU MUST BE LEVEL 15 OR HIGHER FOR THEM TO APPEAR so before entering village level is asked
// while in village message may show saying "You see a traveler, will you talk to him?" 
// if yes this shows, else nothing because other actions will rewrite this so whatevs.
// TRAVELER GENERATOR ----------------------------------------------------------------------------------------------
// class | Name | M | B | HP | F | lvl
// * grab pc lvl. make: lvl-5 <= lvl <= lvl+5
// then, roll stats like a player would do in fool level.
// finally by using lvl collected in * , add to each stat
void hire(int lvl){
    string travelername = namegen(), travelerclass = heroclass(); int travelerlevel = stat((rand() % 21 + (lvl-10)));
    int form, mind; vector<int> stats; int statmodifier = 0;
    for (int i = 0; i < 4; i++){ // get initial stats by rolling d6 4 times and removing lowest number »» sum total
        int temp = 0; 
        vector<int> numbers;
        for (int i = 0; i < 4; ++i){
            int random_number = d6(); 
            numbers.push_back(random_number);
        }
        sort(numbers.begin(), numbers.end());
        numbers.erase(numbers.begin());
        for (const auto& number : numbers) temp += number;
        stats.push_back(temp);
    }
    sort(stats.begin(), stats.end());
    statmodifier = floor((travelerlevel*2)/4);
    // lowest will go to B, highest to HP, other two are randomly assorted in the "if" and "else if"
    int form_mind_random = d2();
    if (form_mind_random == 1) { form = stats[1]; mind = stats[2]; }
    else if (form_mind_random == 2) { form = stats[2]; mind = stats[1]; }
    usleep(15000);
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n";
    cout << "» " + travelerclass + ": " + travelername + " | Level " + to_string(travelerlevel) << "\n";
    cout << "» M: " + to_string(mind+statmodifier) + " | B: " + to_string(stats[0]+statmodifier) + 
         " | HP: " + to_string(stats[3]+statmodifier) + " | F: " + to_string(form+statmodifier) << "\n";
    cout << "» Looking for a traveling party..." << "\n";
    cout << "» I offer my work for " + to_string(travelerlevel*8-((travelerlevel*8)%10)) + " coins." << "\n";
    cout << "◀━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━▶" << "\n" << "\n";
}
//------------------------------------------------------------------------------------------------------------------

/* ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀

 » LOCATION and PROBABILITY FUNCTIONS
   ----------------------------------

    » Locations:
    ------------
    ~ Forest    F
    ~ Mountain  M
    ~ Dungeon   D
    ~ Ruin      R
    ~ Camp      C
    ~ Lake      L

*/


// LOOT IN SPECIFIC LOCATION (finding items in locations will have a 30% every time)--------------------------------
vector<string> located_loot_lists(string location){
    // srand(time(NULL));
    vector<string> loot = {"error","error"}; // no location found
    // randomizer for double value from 0.0 to 100.0
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 100.0);
    //------------------------------------------
    double randomNumber = dis(gen);
    if (location == "forest"){
        vector<Item> itemList = {    
        {"blades", 5.0},
        {"forestloot", 35.0},
        {"vegetable", 20.0},
        {"fruit", 40.0}
        };
        vector<double> cumulative = cumulativecalculator(itemList);
        for (std::size_t i = 0; i < itemList.size(); ++i) 
            if (randomNumber <= cumulative[i]) return itemcorefunction(itemList[i].type);
    }
    else if (location == "mountain"){
        vector<Item> itemList = {  
        {"artifact", 3.0},  
        {"armour", 15.0},
        {"mountainloot", 82.0}
        };
        vector<double> cumulative = cumulativecalculator(itemList);
        for (std::size_t i = 0; i < itemList.size(); ++i) 
            if (randomNumber <= cumulative[i]) return itemcorefunction(itemList[i].type);
    }
    else if (location == "dungeon"){
        vector<Item> itemList = {
        {"relic", 5.0},   
        {"potion", 35.0},   
        {"dungeonloot", 60.0}
        };
        vector<double> cumulative = cumulativecalculator(itemList);
        for (std::size_t i = 0; i < itemList.size(); ++i) 
            if (randomNumber <= cumulative[i]) return itemcorefunction(itemList[i].type);
    }
    else if (location == "ruin"){
        vector<Item> itemList = {
        {"artifact", 5.0},
        {"potion", 35.0},   
        {"armour", 60.0}
        };
        vector<double> cumulative = cumulativecalculator(itemList);
        for (std::size_t i = 0; i < itemList.size(); ++i) 
            if (randomNumber <= cumulative[i]) return itemcorefunction(itemList[i].type);
    }
    else if (location == "camp"){
        vector<Item> itemList = {   
        {"camploot", 10.0}, 
        {"fruit", 15.0},   
        {"armour", 22.0},
        {"ranged", 25.0},
        {"blades", 28.0}
        };
        vector<double> cumulative = cumulativecalculator(itemList);
        for (std::size_t i = 0; i < itemList.size(); ++i) 
            if (randomNumber <= cumulative[i]) return itemcorefunction(itemList[i].type);
    }
    else if (location == "lake"){ // keeping in mind that there's fishing » more rewards
        vector<Item> itemList = {
        {"relic", 3.0},
        {"forestloot", 10.0},
        {"lakeloot", 87.0}
        };
        vector<double> cumulative = cumulativecalculator(itemList);
        for (std::size_t i = 0; i < itemList.size(); ++i) 
            if (randomNumber <= cumulative[i]) return itemcorefunction(itemList[i].type);
    }
    return loot;
}
//------------------------------------------------------------------------------------------------------------------

/*

*Fishing*
*Fruit*
*Vegetables*
*Flowers*
*Weapons*
*Ammo*
*Armour*
*Artifacts*
*Potions*
*Relics*
*Forest Animal Drops* + specific items
*Mountain Animal Drops*
*Lake Animal Drops*

» if you get *----* then it calls for another function with those items
» that function will have a dictionary » key = name of item (used in printed message) with value = name and use (printed after)

-------------------
Forest:     medium dificulty enemies
Red Mushroom
Brown Mushroom
Small Cutting Knife
Arrow
Coins
Red Gnome Hat +1 HP
Gnome Slingshot 1 dmg | 1 w | uses coin as bullet
Red Berry
*Specific* Animal drops (bones/pelts/teeth/claws/tails whatevs)
Forgotten hero items
*Fruit*
*Vegetables*

-------------------
Mountain:   strong enemies
Ember Lily » 3 arrows to fire arrows +1 dmg
Whispering Petal » heal 1 HP for all party members
Breeze Blossom » 1 first hit if in forest(f) or mountain(m)
Arrow
Coins
*Specific* Animal drops (bones/pelts/teeth/claws/tails whatevs)

-------------------
Lake:       somewhat weak enemies
Crystal Tulip » heal 5 HP and 2 first hits
Dream Blossom » target sleeps next round
*Specific* Animal drops (bones/pelts/teeth/claws/tails whatevs)

-------------------
Ruin:
Shadow Lotus » heal 3 HP in dungeons(d) or ruins(r) / else heal 1 HP
*Potions*
*Armour*
*Artifacts*

-------------------
Dungeon:
*Specific* Animal drops (bones/pelts/teeth/claws/tails whatevs)
*Potions*
*Relics*

-------------------
Camp:
*Weapons*
*Ammo*
*Armour*
*Fruit*
Journal / Letter
Arrows
Bullets

Get location and go to location specific function. get item type according to type rarity
for that location and go to an item function  (string itemname ="default", dictionaryfind=false)
that then chooses randomly a rare specific item. that object will be used for the printed message.
THEN, that item will be sent back to the item function with string itemname = item dictionaryfind = true,
so it can look through a dictionary that lists every item of that type so it finds, as a key,
a value with its name and uses and etc 
*/


// FLOOR ITEM FINDER MESSAGE (either full sentence or two-parted)---------------------------------------------------
string floor_item(string location){
    // srand(time(NULL));
    string message; int typeofmessage = d2() - 1;
    // Arrays for messages:
    string message_space[] = {
        "On the floor, you stumbled upon a ",
        "The floor yielded a surprising find: a ",
        "There, amidst the floor's surface, you came across a ",
        "The floor gifted you with the presence of a ",
        "The floor bestowed upon you the discovery of a ",
        "As you scanned the floor, your attention was captured by a ",
        "The floor relinquished its treasure: an unexpected ",
        "Lying before you is a ",
        "While carefully exploring around, you find a ",
        "Upon inspection of the surroundings, you come across a ",
        "With careful observation, you uncover before you a ",
        "Within the area, your gaze lands upon a ",
        "In your path you detect a ",
        "As you venture forth, you unearth a ",
        "Scattered in your wake, you discern a ",
        "While traversing, you happen upon a ",
        "Within your path lies a ",
        "As you investigate further, you find a ",
        "In your search, you happen upon a ",
        "On the surface beneath you, you spot a "
    };
    string prefixmessage[] = {
        "You discovered a ",
        "Your eyes caught sight of a ",
        "A chance encounter led you to discover a ",
        "You noticed a ",
        "As you gazed downward, a ", 
        "Serendipitously, you unearthed a ",
        "Resting on the floor, you stumbled upon a ",
        "Amidst the floor's expanse, you uncovered a ",
        "Your eyes were drawn to a ",
        "The floor revealed its secret: a hidden ",
        "A stroke of luck led you to find a ",
        "In an unexpected twist, you see a ",
        "Hidden from common eye, a ",
        "There before you, a ",
        "Upon investigation, you find a ",
        "While exploring, you come across a ",
        "Among the surroundings, you spy a ",
        "As your eyes scan the vicinity, you notice a ",
        "Within the area, you uncover a ",
        "Through careful observation, you locate a ",
        "Within your sight, you spot a ",
        "Nearby, you find a "
    };
    string suffixmessage[] = {
        " lying on the floor.",
        " resting on the floor.",
        " on the ground.",
        " abandoned on the floor.",
        ", materialized on the floor.",
        " from the floor.",
        " by chance.",
        " waiting to be found.",
        " waiting to be picked up.",
        " lying abandoned on the floor.",
        " in plain sight.",
        " on the floor's surface.",
        " manifesting itself on the floor before you.",
        ", revealed from a pile of stones.",
        " waiting patiently on the floor for your discovery.",
        " lying nearby.",
        " within reach.",
        " nestled in a corner.",
        " amidst the scattered remnants.",
        " burried partially in dirt and rocks.",
        " presenting itsef, in all its beauty and mystery.",
        " catching your attention",
        " lying waiting to be picked up."
    }; 
    vector<string> name_and_rarity = located_loot_lists(location); // object with item name and its rarity
    string iteminfo;
    // according to rarity stored in name_and_rarity find the items info -----------------
    if (name_and_rarity[1] == "common") iteminfo = item_common(name_and_rarity[0]);
    else if (name_and_rarity[1] == "uncommon") iteminfo = item_uncommon(name_and_rarity[0]);
    else if (name_and_rarity[1] == "rare") iteminfo = item_rare(name_and_rarity[0]);
    else if (name_and_rarity[1] == "ancient") iteminfo = item_ancient(name_and_rarity[0]);
    // - - -
    // Note that name_and_rarity[0] is the item name and iteminfo was previously found
    if (typeofmessage == 1){
        int randommessage = rand() % 19;
        message = message_space[randommessage] + name_and_rarity[0] + ". " + "\n" + "» Item Info: " + iteminfo + "\n";
    }
    else if (typeofmessage == 0){
        int prefixmessage_ = rand() % 22;
        int sufixmessage_ = rand() % 23; 
        message = prefixmessage[prefixmessage_] + name_and_rarity[0] + suffixmessage[sufixmessage_] + "\n" + "» Item Info: " + iteminfo + "\n";
    }
    return message;
}
//------------------------------------------------------------------------------------------------------------------
