#include <iostream>
#include <vector>
#include <chrono>
#include <random>

const int NUM_ROLLS = 1000;  // Number of times to roll the dice

// Function to roll the dice
int rollDice() {
    // Use a random number generator to simulate dice roll
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(1, 6); // Distribution for numbers between 1 and 6

    return dis(gen);
}

int main() {
    auto startTime = std::chrono::high_resolution_clock::now();

    std::vector<int> rolls;

    for (int i = 0; i < NUM_ROLLS; ++i) {
        int roll = rollDice();
        rolls.push_back(roll);
    }

    auto endTime = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(endTime - startTime);

    // Calculate and display average roll
    int total = 0;
    for (int roll : rolls) {
        total += roll;
    }

    double average = static_cast<double>(total) / NUM_ROLLS;

    std::cout << "Average dice roll after " << NUM_ROLLS << " rolls: " << average << "\n";
    std::cout << "Execution Time: " << duration.count() << " microseconds\n";

    return 0;
}
