#include <iostream>
#include <unistd.h>
#include "dieandcoins.hpp"
#include <random>
#include <map>
#include <string>
using namespace std;


// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
// CALCULATORS

struct Item { string type; double chance; }; // for {name, probability} objects

// CUMULATIVE PROBABILITY CALCULATOR (used for specific location item list)-----------------------------------------
vector<double> cumulativecalculator(vector<Item> itemList){
    vector<double> cumulativechances;
    double cumulativeProbability = 0.0;
    for (const auto& item : itemList) {
        cumulativeProbability += item.chance;
        cumulativechances.push_back(cumulativeProbability);
    }
    return cumulativechances;
}
//------------------------------------------------------------------------------------------------------------------


// Rarity Generator for Item ---------------------------------------------------------------------------------------
string raritygenerator(){
    random_device rd;
    mt19937 gen(rd());
    uniform_real_distribution<> dis(0.0, 100.0);
    double randomNumber = dis(gen);
    vector<Item> Rarities = {    
        {"ancient", 10.0},
        {"rare", 16.0},
        {"uncommon", 26.0},
        {"common", 48.0}
        };
    vector<double> cumulative = cumulativecalculator(Rarities);
    for (std::size_t i = 0; i < Rarities.size(); ++i) 
        if (randomNumber <= cumulative[i]) return Rarities[i].type;
    return "error";
}
//------------------------------------------------------------------------------------------------------------------


// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
// ITEM GENERATORS ACCORDING TO TYPE AND GENERATED RARITY

string forestloot(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Small Bag of Coins", "Red Mushroom", "Brown Mushroom", "Red Berry", "Stick"};
        return list[rand() % 5];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Broken Lost Dagger", "Deer Pelt", "Animal Bone", "Stack of Arrows", "Deer Meat"};
        return list[rand() % 5];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Deer Antler", "Wolf Claw", "Solidified Ooze", "Big Animal Bone", "Broken Lost Helm"};
        return list[rand() % 5];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Red Gnome Hat", "Gnome Slingshot", "Bunny Ears", "Ripped Scaled Tail", "Mossy Blade"};
        return list[rand() % 5];
    }
    return "error";
}
string mountainloot(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Bag of Coins", "Bag of Pellets", "Red Berry"};
        return list[rand() % 3];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Stack of Arrows", "Animal Bone", "Goblin Bag of Coins"};
        return list[rand() % 3];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Goat Horn", "Breeze Blossom", "Ember Lily", "Wolf Claw", "Big Animal Bone"};
        return list[rand() % 5];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Mountain Goat Hide", "Whispering Petal", "Crystalized Stone", "Mountain Lion Pelt"};
        return list[rand() % 4];
    }
    return "error";
}
string lakeloot(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Algae", "Stick", "Bag of Pellets"};
        return list[rand() % 3];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Carp", "Bass"};
        return list[rand() % 2];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Dream Blossom", "Fishing Rod", "Siren Scale", "Crawler Tooth"};
        return list[rand() % 4];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Crystal Tulip", "Lake Serpent Scale", "Silverfin Fish Scale", "Coral Blade", "Songbird Feather"};
        return list[rand() % 5];
    }
    return "error";
}
string camploot(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Care Bottle", "Ration", "Bag of Pellets", "Bag of Coins"};
        return list[rand() % 4];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Healing Potion", "Stack of Arrows", "Goblin Bag of Coins", "Throwing Knife"}; 
        return list[rand() % 4];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Poison Dagger", "Wolf Claw"};
        return list[rand() % 2];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Weapon Upgrade Blueprint", "Bandit Knife"};
        return list[rand() % 2];
    }
    return "error";
}
string dungeonloot(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Bag of Pellets", "Small Bag of Coins", "XP Bottle"};
        return list[rand() % 3];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Stack of Arrows", "Healing Potion", "Broken Lost Dagger"};
        return list[rand() % 3];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Human Bone", "Broken Lost Helm", "Solidified Ooze"};
        return list[rand() % 3];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Skeleton Key", "Magic Guide", "Golem Shard", "Heart Elixir", "Shadow Lotus"};
        return list[rand() % 5];
    }
    return "error";
}
string vegetable(){ // all vegetable items are common
    string itemfound;
    vector<string> list ={"Carrot", "Potato", "Cabbage", "Lettuce", "Radish", "Pumpkin", "Corn", "Dragon Leek"};
    return list[rand() % 8];
}
string fruit(){ // all fruit items are common
    string itemfound;
    vector<string> list ={"Wyvern Apple", "Apple", "Slimegum Fruit", "Starfruit", "Firefruit", "Orange"};
    return list[rand() % 6];
}
string blades(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Rusty Knife", "Rusty Sword", "Rusty Axe"};
        return list[rand() % 3];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Axe", "Sword", "Dagger", "Pike", "Short Blade"};
        return list[rand() % 5];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Long Blade", "Dual Axe", "Greatsword", "Claymore", "Halberd"};
        return list[rand() % 5];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Great Heavysword", "Long Blade Axe", "Twisted Dagger", "Heavy Pike", "Hero's Sword Replica"};
        return list[rand() % 5];
    }
    return "error";
}
string ranged(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Composite Bow", "Broken Sling", "Short Bow"};
        return list[rand() % 3];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Bow", "Hand Crossbow", "Slingshot", "Throwing Knife"}; 
        return list[rand() % 4];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Long Bow", "Crossbow", "Javelin", "Hand Axe"};
        return list[rand() % 4];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Hunting Crossbow", "Great Bow", "Hunting Sling", "Hero's Bow Replica"};
        return list[rand() % 4];
    }
    return "error";
}
string armour(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Rusted Helm", "Rusted Visor", "Rusted Plate", "Old Cloths", "Peasant Hat", "Peasant Shirt"};
        return list[rand() % 6];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Leather Hood", "Leather Coat", "Chain Mail Chest", "Chain Mail Hood"};
        return list[rand() % 4];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Iron Helmet", "Iron Bascinet", "Iron Plate"};
        return list[rand() % 3];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Heavy Plate", "Heavy Sallet", "Beast Hood Replica", "Beast Cloak Replica", "Hero's Shield Replica"};
        return list[rand() % 5];
    }
    return "error";
}
string artifact(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Tomb Cannon", "Dragon Slayer Blade", "Golden Rune Axe", "Crawling Saw"};
        return list[rand() % 4];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Hood of the Beast", "Cloak of the Beast", "Blood Orb", "Judge's Scythe"};
        return list[rand() % 4];
    }
    else if (rarity == "rare"){
        vector<string> list ={"True Hero's Sword", "True Hero's Bow", "True Hero's Shield"};
        return list[rand() % 3];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"True Day Armet", "True Day Armour", "True Night Armet", "True Night Armour"};
        return list[rand() % 4];
    }
    return "error";
}
string relic(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Hermit Talisman", "Compass of Talent", "Royal Ring", "Beast Bone"};
        return list[rand() % 4];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Orb of Distance", "Orb of Proximity", "Chalice of Life"};
        return list[rand() % 3];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Pendant of Wisdom", "Pendant of Strength", "Pendant of Healing", "Pendant of Agility"};
        return list[rand() % 4];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Void Arrow Quiver", "Hero's Pendant"};
        return list[rand() % 2];
    }
    return "error";
}
string potion(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Care Bottle", "Agility Potion"};
        return list[rand() % 2];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Healing Potion", "Hunt Vial"};
        return list[rand() % 2];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Blood Vial", "Toxine Vial", "Teleportation Vial"};
        return list[rand() % 3];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Heart Elixir", "Rejuvenating Perfume"};
        return list[rand() % 2];
    }
    return "error";
}
string fishing(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Smallfish", "Smallcarp", "Stick", "Algae"};
        return list[rand() % 4];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Carp", "Bass", "Salmon"};
        return list[rand() % 3];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Silver Crawler", "Nightfish"};
        return list[rand() % 2];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Bull Dragonfish", "Golden Witchbass", "Sand Graygill"};
        return list[rand() % 3];
    }
    return "error";
}
string ammo(string rarity){
    if (rarity == "common"){
        vector<string> list ={"Bag of Pellets", "Bag of Coins"};
        return list[rand() % 2];
    }
    else if (rarity == "uncommon"){
        vector<string> list ={"Stack of Arrows", "Goblin Bag of Coins"};
        return list[rand() % 2];
    }
    else if (rarity == "rare"){
        vector<string> list ={"Stack of Fire Arrows", "Box of Cannon Balls"};
        return list[rand() % 1];
    }
    else if (rarity == "ancient"){
        vector<string> list ={"Bag of Explosive Pellets", "Stack of Teleportation Arrows"};
        return list[rand() % 2];
    }
    return "error";
}


// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
// the following functions have maps with every game item from that rarity, so that the item info can be returned
// Item Info Finder using Rarity -----------------------------------------------------------------------------------
// w -> weight
// Stacks means max amount in inventory

string item_common(string itemname){
    map<string,string> iteminfofinder { 
        {"Small Bag of Coins", "Small Bag of Coins: Contains 5 coins"},
        {"XP Bottle", "XP Bottle: Contains 10 xp"},
        {"Bag of Coins", "Bag of Coins: Contains 10 coins"},
        {"Bag of Pellets", "Bag of Pellets: Contains 6 Pellets | Pellets stack to 30"},
        {"Red Mushroom", "Red Mushroom: 0.5w | Stacks to 3"},
        {"Brown Mushroom", "Brown Mushroom: 0.5w | Stacks to 3"},
        {"Red Berry", "Red Berry: 0.5w | Stacks to 4"},
        {"Stick", "Stick: 1 Dmg | 1w"}, 
        {"Algae", "Algae: 1w | Stacks to 3"},
        {"Smallfish", "Smallfish: 0.5w | Stacks to 3"},
        {"Smallcarp", "Smallcarp: 1w | Stacks to 3"},
        {"Care Bottle", "Care Bottle: Heals 2 HP | 0.5w"}, 
        {"Agility Potion", "Agility Potion: Heal 2 HP and attack first next round | 1w"},
        {"Ration", "Ration: Heals party by 1 HP | 1w | Stacks to 2"},
        {"Carrot", "Carrot: 0.5w | Stacks to 3"}, 
        {"Potato", "Potato: 0.5w | Stacks to 3"}, 
        {"Cabbage", "Cabbage: 0.5w | Stacks to 2"},
        {"Lettuce", "Lettuce: 0.5w | Stacks to 2"}, 
        {"Radish", "Radish: 0.5w | Stacks to 3"}, 
        {"Pumpkin", "Pumpkin: 1w | Doesn't Stack"},
        {"Corn", "Corn: 0.5w | Stacks to 4"}, 
        {"Dragon Leek", "Dragon Leek: Heals 1 HP | 0.5w | Stacks to 2"},
        {"Apple", "Apple: Heals 1 HP | 0.5w | Stacks to 2"}, 
        {"Orange", "Orange: Heals 1 HP | 0.5w | Stack to 2"},
        {"Firefruit", "Firefruit: 1w | Stacks to 2"}, 
        {"Starfruit", "Starfruit: Heals 2 HP in dungeon | 0.5w | Stacks to 2"},
        {"Wyvern Apple", "Wyvern Apple: Heals 1 HP, next attack +1 dmg | 1w | Doesn't Stack"},
        {"Slimegum Fruit", "Slimegum Fruit: Revives Slime | 1w | Stacks to 5"}, 
        {"Rusty Knife", "Rusty Knife: 1 Dmg | +2 F | 1w"},
        {"Rusty Sword", "Rusty Sword: 2 Dmg | 1.5 w"},
        {"Rusty Axe", "Rusty Axe: 2 Dmg | 2w"},
        {"Composite Bow", "Composite Bow: 1 Dmg | Arrows | 3t | 1.5w"}, 
        {"Broken Sling", "Broken Sling 1 Dmg | Pellets | 2t | 1w"}, 
        {"Short Bow", "Short Bow: 1 Dmg | Arrows | 4t | 1.5w"},
        {"Rusted Helm", "Rusted Helm: +1 HP | 2.5w"}, 
        {"Rusted Visor", "Rusted Visor: +1 HP | 2w"}, 
        {"Rusted Plate", "Rusted Plate: +1 HP | 3w"},
        {"Old Cloths", "Old Cloths: +2 F | 1.5w"}, 
        {"Peasant Hat", "Peasant Hat: +1 F | 1w"}, 
        {"Peasant Shirt", "Peasant Shirt: +1 HP | 1.5w"},
        {"Tomb Cannon", "Tomb Cannon: 10 Dmg | Cannon Balls | 4t | 6w"}, 
        {"Dragon Slayer Blade", "Dragon Slayer Blade: 5 Dmg | 6 Dmg in mountains | 3.5w"},
        {"Golden Rune Axe", "Golden Rune Axe: 6 Dmg | +2 Coins per kill | 4w"}, 
        {"Crawling Saw", "Crawling Saw: 3 Dmg | 7 Dmg to Crawlers | 4w"},
        {"Hermit Talisman", "Hermit Talisman: +2 M, +1 F | 0.5w | Doesn't Stack"},
        {"Compass of Talent", "Compass of Talent: Always attack first | 1w"}, 
        {"Royal Ring", "Royal Ring: +1 Dmg to Guards | 0.5w"}, 
        {"Beast Bone", "Beast Bone: +1 Dmg to Wolfs | 2w"}
    };
    return iteminfofinder[itemname];
}
string item_uncommon(string itemname){
    map<string,string> iteminfofinder {
        {"Broken Lost Dagger", "Broken Lost Dagger: 2 Dmg | 1w"}, 
        {"Deer Pelt", "Deer Pelt: Worth 8 coins | 2w | Stacks to 4"},
        {"Deer Meat", "Deer Meat: Worth 8 coins | 1w | Stacks to 4"},
        {"Animal Bone", "Animal Bone: Worth 3 coins | 1.5w | Stack to 3"}, 
        {"Stack of Arrows", "Stack of Arrows: Contains 5 Arrows | Arrows Stack to 15"},
        {"Goblin Bag of Coins", "Goblin Bag of Coins: Contains 15 Coins"}, 
        {"Healing Potion", "Healing Potion: Heals 5 HP | 1w"},
        {"Hunt Vial", "Hunt Vial: lose 1 HP, deal +2 Dmg on next attack | 0.5w"},
        {"Throwing Knife", "Throwing Knife: 1 Dmg | 4t | Consumable | Stacks to 5"}, 
        {"Carp", "Carp: Worth 8 coins | 1.5w | Stacks to 2"},
        {"Bass", "Bass: Worth 4 coins | 1.5w | Stacks to 3"},
        {"Salmon", "Salmon: Worth 6 coins | 2w | Stacks to 2"},
        {"Bow", "Bow: 2 Dmg | Arrows | 4t | 2w"},
        {"Hand Crossbow", "Hand Crossbow: 2 Dmg | Arrows | 5t | 2.5w"}, 
        {"Slingshot", "Slingshot: 1 Dmg | Pellets | 3t | 1w"},
        {"Axe", "Axe: 3 Dmg | 2.5w"}, 
        {"Sword", "Sword: 3 Dmg | 2w"}, 
        {"Dagger", "Dagger: 2 Dmg | 1.5w"},
        {"Pike", "Pike: 2 Dmg | 2t | 2.5w"}, 
        {"Short Blade", "Short Blade: 2 Dmg | 2w"},
        {"Leather Hood", "Leather Hood: +2 F | 1.5w"}, 
        {"Leather Coat", "Leather Coat: +1 HP, +1 F | 1.5w"},
        {"Chain Mail Hood", "Chain Mail Hood: +2 HP | 2w"}, 
        {"Chain Mail Chest", "Chest Mail Chest: +2 HP | 2.5w"},
        {"Hood of the Beast", "Hood of the Beast: +2 HP, +1 F | +1 Dmg to Animals | 2.5w"},
        {"Cloak of the Beast", "Cloak of the Beast: +3 HP, +2 F | +1 Dmg to Animals | 3w"},
        {"Blood Orb", "Blood Orb: 3 Dmg | Do 5 Dmg, lose 2 HP | 4t | 3.5w"},
        {"Judge's Scythe", "Judge's Scythe: 4 Dmg | 2t | 4w"},
        {"Orb of Distance", "Orb of Distance: Ranged weapons do +1 Dmg | 3.5w | Stacks to 2"},
        {"Orb of Proximity", "Orb of Proximity: Melee weapons do +1 Dmg | 3.5w | Stacks to 2"},
        {"Chalice of Life", "Chalice of Life: +2 HP | 3w | Stacks to 2"}
    };
    return iteminfofinder[itemname];
}
string item_rare(string itemname){
    map<string,string> iteminfofinder {
        {"Deer Antler", "Deer Antler: Worth 12 coins | 1.5w | Stacks to 2"},
        {"Wolf Claw", "Wolf Claw: Worth 3 coins | 0.5w | Stacks to 4"},
        {"Solidified Ooze", "Solidified Ooze: Worth 8 coins | 1w | Stacks to 3"},
        {"Big Animal Bone", "Big Animal Bone: Worth 6 coins | 2w | Stacks to 2"},
        {"Broken Lost Helm", "Broken Lost Helm: +1 HP | +1 Dmg in Dungeons | 2w"},
        {"Goat Horn", "Goat Horn: Worth 9 coins | 1w | Stacks to 3"},
        {"Breeze Blossom", "Breeze Blossom: 1 first hit if in forest or mountain | Stacks to 3"},
        {"Ember Lily", "Ember Lily: Turn 3 Arrows to Fire Arrows (+1 Dmg on attack) | Stacks to 3"},
        {"Dream Blossom", "Dream Blossom: Close target sleeps next round | Stacks to 3"},
        {"Fishing Rod", "Fishing Rod: unlocks fishing | Slimegum Fruit or Algae as bait | 2.5w"},
        {"Siren Scale", "Siren Scale: Worth 3 coins | Stacks to 3"},
        {"Crawler Tooth", "Crawler Tooth: Worth 5 coins | Stacks to 2"},
        {"Poison Dagger","Poison Dagger: Roll d6 for Dmg | 2w"},
        {"Human Bone", "Human Bone: Worth 1 coin | 0.5w | Stacks to 3"},
        {"Long Blade", "Long Blade: 4 Dmg | 3w"},
        {"Dual Axe", "Dual Axe: 3 Dmg | +1 Dmg to Guards | 3.5w"},
        {"Greatsword", "Greatsword: 5 Dmg | 3.5w"},
        {"Claymore", "Claymore: 3 Dmg | +1 Dmg in forests | 2.5w"},
        {"Halberd", "Halberd: 3 Dmg | +1 F while using | 3w"},
        {"Long Bow", "Long Bow: 3 Dmg | Arrows | 4t | 2.5w"},
        {"Crossbow", "Crossbow: 4 Dmg | Arrows | 3t | 2.5w"},
        {"Javelin", "Javelin: 1 Dmg | 3t | 1.5w"},
        {"Hand Axe", "Hand Axe: 3 Dmg | 4t | Consumable | Stacks to 3"},
        {"Iron Helmet", "Iron Helmet: +1 HP | +1 Dmg in Ruins | 3w"},
        {"Iron Bascinet", "Iron Bascinet: +1 HP | +1 Dmg in Dungeons | 3w"},
        {"Iron Plate", "Iron Plate: +1 HP | +1 Dmg in Ruins and Dungeons | 3.5w"},
        {"True Hero's Sword", "True Hero's Sword: 7 Dmg | 8 Dmg to Bosses | 4.5w"},
        {"True Hero's Bow", "True Hero's Bow: 6 Dmg | Arrows | 8t | 4w"},
        {"True Hero's Shield", "True Hero's Shield: +6 HP, -2 F | 4.5w"},
        {"Pendant of Wisdom", "Pendant of Wisdom: +3 M | 0.5w | Stacks to 2"},
        {"Pendant of Strength", "Pendant of Strength: +3 B | Stacks to 2"},
        {"Pendant of Healing", "Pendant of Healing: +3 HP | 0.5w | Stacks to 2"},
        {"Pendant of Agility", "Pendant of Agility: +3 F | 0.5w | Stacks to 2"},
        {"Blood Vial", "Blood Vial: Heals 10 HP | 0.5w"},
        {"Toxine Vial", "Toxine Vial: Deal 3 Dmg to ALL | 0.5w"},
        {"Teleportation Vial", "Teleportation Vial: Change location to any tile | 0.5w"},
        {"Silver Crawler", "Silver Crawler: Worth 30 coins | 1.5w | Stacks to 2"},
        {"Nightfish", "Nightfish: Worth 35 coins | 1.5w | Stacks to 2"},
        {"Stack of Fire Arrows", "Stack of Fire Arrows: Contains 3 Fire Arrows | +1 Dmg | Fire Arrows Stack to 9"},
        {"Box of Cannon Balls", "Box of Cannon Balls: Contains 3 Cannon Balls | Cannon Balls Stack to 6"}
    };
    return iteminfofinder[itemname];
}
string item_ancient(string itemname){
    map<string,string> iteminfofinder {
        {"Red Gnome Hat", "Red Gnome Hat: Slingshots do +2 Dmg | 1w"},
        {"Gnome Slingshot", "Gnome Slingshot: 3 Dmg | Pellets or Coins | 3t | 1.5w"},
        {"Bunny Ears", "Bunny Ears: -3 HP, -3 F | +20 xp per kill | 0.5w"},
        {"Ripped Scaled Tail", "Ripped Scaled Tail: Worth 30 coins | 2.5w | Doesn't Stack"},
        {"Mossy Blade", "Mossy Blade: Roll d6 for Dmg | +2 Dmg in forests | 3w"},
        {"Mountain Goat Hide", "Mountain Goat Hide: Worth 25 coins | 2w | Stacks to 2"},
        {"Whispering Petal", "Whispering Petal: Heal party for 10 HP | Stacks to 3"},
        {"Crystalized Stone", "Crystalized Stone: Worth 20 coins | Stacks to 2"},
        {"Mountain Lion Pelt", "Mountain Lion Pelt: Worth 25 coins | 3w | Stacks to 2"},
        {"Crystal Tulip", "Crystal Tulip: Heal 5 HP and stun close target for 1 round | Stacks to 3"},
        {"Lake Serpent Scale", "Lake Serpent Scale: Worth 35 coins | 3w | Stack to 2"},
        {"Coral Blade", "Coral Blade: Roll d6 for Dmg | +2 Dmg in lakes | 3w "},
        {"Songbird Feather", "Songbird Feather: Worth 45 coins | 0.5w | Stacks to 3"},
        {"Weapon Upgrade Blueprint", "Weapon Upgrade Blueprint: '+' any weapon for +1 Dmg | Can only upgrade twice"},
        {"Bandit Knife", "Bandit Knife: 4 Dmg | +8 F, +5 Coins per kill | 2w"},
        {"Skeleton Key", "Skeleton Key: Worth 35 coins | 0.5w | Stacks to 5"},
        {"Magic Guide", "Magic Guide: +3 M and +1 Dmg in ruins | 1w | Doesn't Stack"},
        {"Golem Shard", "Golem Shard: Invokes Clay Statue ally: 1 T/R ┄ 10 HP ┄ 10 B | Breaks upon use (ally not stackable)"},
        {"Heart Elixir", "Heart Elixir: Heals 20 HP | 1.5w"},
        {"Shadow Lotus", "Shadow Lotus: +15 Dmg on next attack | Stacks to 3"},
        {"Great Heavysword", "Great Heavysword: 6 Dmg | T/R reduced to 1 | 5w"},
        {"Long Blade Axe", "Long Blade Axe: 5 Dmg | +1 Dmg to Humans | 4.5w"},
        {"Twisted Dagger", "Twisted Dagger: 4 Dmg | +15 xp per kill | 2.5w"},
        {"Heavy Pike", "Heavy Pike: 4 Dmg | +1 F in dungeons | 3w"},
        {"Hero's Sword Replica", "Hero's Sword Replica: 6 Dmg | 7 Dmg to Bosses | 3.5w"},
        {"Hunting Crossbow", "Hunting Crossbow: 5 Dmg | Arrows | 5t | 3.5w"},
        {"Great Bow", "Great Bow: 4 Dmg | Arrows | 6t | 3w"},
        {"Hunting Sling", "Hunting Sling: 3 Dmg | Pellets | 5t | 2.5w"},
        {"Hero's Bow Replica", "Hero's Bow Replica: 5 Dmg | Arrows | 7t | 3w"},
        {"Heavy Plate", "Heavy Plate: +3 HP, -2 F | +1 Dmg to Bosses | 4.5w"},
        {"Heavy Sallet", "Heavy Sallet: +3 HP, -2 F | +1 Dmg to Bosses | 3.5w"},
        {"Beast Hood Replica", "Beast Hood Replica: +2 HP, +1 F | Bags contain +5 coins | 2.5w"},
        {"Beast Cloak Replica", "Beast Cloak Replica: +2 HP | Daggers and Knives do +1 Dmg | 3w"},
        {"Hero's Shield Replica", "Hero's Shield Replica: +4 HP, -3 F | 4w"},
        {"True Day Armet", "True Day Armet: +4 HP | +15 xp per kill | 4.5w"},
        {"True Day Armour", "True Day Armour: +4 HP | Care and Healing Potion heal twice more | 5w"},
        {"True Night Armet", "True Night Armet: +3 HP | +1 Dmg if under Half HP | 4.5w"},
        {"True Night Armour", "True Night Armour: +3 HP | +2 Dmg if under Half HP | 5w"},
        {"Void Arrow Quiver", "Void Arrow Quiver: Increase Normal Arrow carry to 36 | 3w"},
        {"Hero's Pendant", "Hero's Pendant: After kill, 2.d6 » if 2/6/12 double the drops | 1.5w"},
        {"Rejuvenating Perfume", "Rejuvenating Perfume: Heal full HP | 0.5w | Stacks to 2"},
        {"Bull Dragonfish", "Bull Dragonfish: Worth 50 coins | 6w | Doesn't Stack"},
        {"Golden Witchbass", "Golden Witchbass: Worth 45 coins | 4w | Doesn't Stack"},
        {"Sand Graygill", "Sand Graygill: Worth 40 coins | 5w | Stacks to 2"},
        {"Bag of Explosive Pellets", "Bag of Explosive Pellets: Contains 10 Explo. Pellets | +3 Dmg | Explo. Pellets stack to 20"},
        {"Stack of Teleportation Arrows", "Stack of Teleportation Arrows: Contains 3 Tlp. Arrows | Change to location within range | Tlp. Arrows Stack to 6"}
    };
    return iteminfofinder[itemname];
}
//------------------------------------------------------------------------------------------------------------------
/*
"Bag of Explosive Pellets", "Stack of Teleportation Arrows"

*/

// ▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀▀
// Item Functions Core (colect item name and rarity) ---------------------------------------------------------------
vector<string> itemcorefunction(string itemtype){
    srand(time(NULL)); // used to randomize chances even more in terms of real life time
    string rarity = raritygenerator(), itemfound = "default";
    // get item from specified type:
    if (itemtype == "forestloot")        itemfound = forestloot(rarity);
    else if (itemtype == "mountainloot") itemfound = mountainloot(rarity);
    else if (itemtype == "lakeloot")     itemfound = lakeloot(rarity);
    else if (itemtype == "camploot")     itemfound = camploot(rarity);
    else if (itemtype == "dungeonloot")  itemfound = dungeonloot(rarity);
    else if (itemtype == "vegetable"){   itemfound = vegetable(); rarity = "common";}
    else if (itemtype == "fruit"){       itemfound = fruit();     rarity = "common";}
    else if (itemtype == "blades")       itemfound = blades(rarity);
    else if (itemtype == "ranged")       itemfound = ranged(rarity);
    else if (itemtype == "armour")       itemfound = armour(rarity);
    else if (itemtype == "artifact")     itemfound = artifact(rarity);
    else if (itemtype == "relic")        itemfound = relic(rarity);
    else if (itemtype == "potion")       itemfound = potion(rarity);
    else if (itemtype == "fishing")      itemfound = fishing(rarity);
    else if (itemtype == "ammo")         itemfound = ammo(rarity);
    // once item and rarity objects are colected, return them in vector for easy access
    return {itemfound, rarity};
}
//------------------------------------------------------------------------------------------------------------------
