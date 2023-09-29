#include<stdio.h>
#include<ctype.h>
using namespace std;
#include <iostream>
#include <unistd.h>
#include <chrono>
#include <thread>

int main() {
    std::cout << "Progress: ";

    for (int i = 0; i <= 100; i += 10) {
        std::cout << i << "%\r";
        std::cout.flush();

        // Simulating some work
        std::this_thread::sleep_for(std::chrono::milliseconds(500));
    }

    std::cout << "Completed!" << std::endl;
    return 0;
}