#include "Food.h"
#include <cstdlib> // For rand()
#include <ctime>   // For seeding random number generator

// Constructor
Food::Food() {
    // random number generator (only once, when the program starts).
    //Food=='*';
    //before was std::srand(std::time(nullptr));

    // Initialize the food position (default values)
    foodPos = {0, 0, '*'}; // '@' represents the food symbol.
}

// Destructor
Food::~Food() {
    // No dynamic memory, so nothing special to clean up.
}

// Generates a random position for the food, avoiding blockOff position.
void Food::generateFood(const objPos& blockOff, int boardX, int boardY) {
    int newX, newY;

    do {
        // Generate random x and y coordinates within the board boundaries.
        newX = std::rand() % boardX;
        newY = std::rand() % boardY;
    } while (newX == blockOff.xPos && newY == blockOff.yPos); // Avoid player position.

    // Set the food's position and ASCII symbol.
    foodPos = {newX, newY, '*'};
}

// Returns the current food position.
objPos Food::getFoodPos() const {
    return foodPos;
}