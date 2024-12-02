#ifndef PLAYER_H
#define PLAYER_H
class GameMechs;
//#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"
//#include "Food.h"


class Player
{
    // Construct the remaining declaration from the project manual.
    

    // Only some sample members are included here

    // You will include more data members and member functions to complete your design.

    
    public:
        enum Dir {UP, DOWN, LEFT, RIGHT, STOP};  // This is the direction state
        //struct objPosition //objPosition before
        //{
            //int x; //x cooridnate of the object
            //int y; // y coordinate of the object 
            //char symbol; // The ASCII symbol of the object about to be drawn on the screen 
        //};

        //Player(GameMechs* thisGMRef, Food* thisFoodRef); // added food bc we need to see if the food pos and head pos is the same
        Player(GameMechs* thisGMRef);
        ~Player();

        bool checkSelfCollision();
    
       

        // changed for iteration 3
        //objPos getPlayerPos() const; // Upgrade this in iteration 3.     
        // now we have a list of positions   
        objPosArrayList* getPlayerPos() const; //upgraded for iteration 3

        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here

    private:
        

        //objPos playerPos; // Upgrade this in iteration 3.       
        //upgrating for iteration 3
        objPosArrayList* playerPosList;

        enum Dir myDir;
        
         // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
        //Food* foodRef;


};

#endif