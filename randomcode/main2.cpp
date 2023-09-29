#include <iostream>
#include <vector>
#include <random>

struct Item {
    std::string name;
    double chance;
};
int main() {
    std::vector<Item> itemList = {
        {"Item A", 5.0},   // 5% chance
        {"Item B", 30.0},  // 30% chance
        {"Item C", 65.0}   // 65% chance
    };
    // Generate a random number between 0 and 100
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(0.0, 100.0);
    double randomNumber = dis(gen);

    // Calculate cumulative probabilities
    std::vector<double> cumulativeProbabilities;
    double cumulativeProbability = 0.0;
    for (const auto& item : itemList) {
        cumulativeProbability += item.chance;
        std::cout << cumulativeProbability << " ";
        cumulativeProbabilities.push_back(cumulativeProbability);
    }
    
    // Select an item based on random number and cumulative probabilities
    for (std::size_t i = 0; i < itemList.size(); ++i) {
        if (randomNumber <= cumulativeProbabilities[i]) {
            std::cout << " | " << randomNumber << "\n";
            std::cout << "You obtained: " << itemList[i].name << std::endl;
            break;
        }
    }
    return 0;
}


