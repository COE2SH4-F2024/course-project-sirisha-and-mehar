#ifndef GAMEMECHS_H
#define GAMEMECHS_H

#include <cstdlib>
#include <time.h>

#include "objPos.h"
#include "objPosArrayList.h"

#include "Food.h"
#include "Player.h" // just added 

using namespace std;

class GameMechs
{
    private:
        char input;//holds most recent input
        bool exitFlag;//exit status
        bool loseFlag;//lose status
        int score;//players score

        int boardSizeX;//width of the board
        int boardSizeY;//height of the board

        //objPos food;//directly stores the position of the food remove for 1B implementation for 2B
        Food* food;        // Pointer to the Food object.

    public:
    //constructors and destructors
        GameMechs();
        GameMechs(int boardX, int boardY);
        ~GameMechs(); // is this one needed at all? Why or why not? //destructor
        
        bool getExitFlagStatus() const; 
        void setExitTrue();
        bool getLoseFlagStatus() const;
        void setLoseFlag();

        char getInput();
        void setInput(char this_input);
        void clearInput();

        int getBoardSizeX() const;
        int getBoardSizeY() const;
        
        int getScore() const;
        void incrementScore();
        
        // More methods should be added here
        void collectAsyncInput(); 
        objPos getFoodPos() const;
        void consumeFood();
};

#endif