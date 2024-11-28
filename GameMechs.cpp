#include "GameMechs.h"
#include "MacUILib.h"

GameMechs::GameMechs()
{
    
}

GameMechs::GameMechs(int boardX, int boardY)
{
    
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    
}

bool GameMechs::getExitFlagStatus() const
{

}

bool GameMechs::getLoseFlagStatus() const
{

}
    

char GameMechs::getInput() //remove const here to avoid errors 
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    }

    if (input == ' ')exitFlag=true;

    return input;
    //ppa3/ppa2 code above 
}

int GameMechs::getScore() const
{

}

void GameMechs::incrementScore()
{
    
}

int GameMechs::getBoardSizeX() const
{

}

int GameMechs::getBoardSizeY() const
{

}


void GameMechs::setExitTrue()
{

}

void GameMechs::setLoseFlag()
{
    
}

void GameMechs::setInput(char this_input)
{

}

void GameMechs::clearInput()
{

}

// More methods should be added here