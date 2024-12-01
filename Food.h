#ifndef FOOD_H
#define FOOD_H

#include "objPos.h" // Assuming objPos is a struct or class with x, y, and symbol.

class Food {
private:
    objPos foodPos; // Holds the food's position and symbol.

public:
    // Constructor
    Food();

    // Destructor
    ~Food();

    // Generates food at a random position, avoiding the blockOff position
    void generateFood(const objPos& blockOff, int boardX, int boardY);

    // Getter for food position
    objPos getFoodPos() const;
};

#endif // FOOD_H
