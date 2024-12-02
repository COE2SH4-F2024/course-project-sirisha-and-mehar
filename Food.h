#ifndef FOOD_H
#define FOOD_H

# include "objPos.h"
# include "Player.h"

class Food
{
    private:
        objPos foodPos;
         
    public:
    
        Food();//constructor
        ~Food();//deconstructor
        void generateFood(objPos blockOff);
        objPos getFoodPos() const; 

};

#endif // FOOD_H
