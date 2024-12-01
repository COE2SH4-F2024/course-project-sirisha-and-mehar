#ifndef PLAYER_H
#define PLAYER_H

#include "GameMechs.h"
#include "objPos.h"
#include "objPosArrayList.h"

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

        Player(GameMechs* thisGMRef);
        ~Player();
        
       


        //objPos getPlayerPos() const; // Upgrade this in iteration 3.  
        objPosArrayList* getPlayerPos() const;
        //objectPosArrayList* PlayerPosList;
        //made objectposition array list a pointer for iteration 3 so that we only use it when needed     
        void updatePlayerDir();
        void movePlayer();

        // More methods to be added here

    private:
        //objPos playerPos; // Upgrade this in iteration 3.    
        objPosArrayList* PlayerPosList;   //make list based data types s pointers ebecause they take up alot of memory
        enum Dir myDir;

        // Need a reference to the Main Game Mechanisms
        GameMechs* mainGameMechsRef;
};

#endif