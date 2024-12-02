#include "GameMechs.h"
#include "MacUILib.h"
// added macuilib
# include "MacUILib.h"


GameMechs::GameMechs()
{
    //set board size
    // randomly generate food here, using an item bin and geneate function 

    // initalize the game mechanics 
        input=0;
        exitFlag= false;
        loseFlag = false;
        score = 0;

        boardSizeX = 30;
        boardSizeY = 15;
        food = new Food(); // Allocate food object on the heap.
        //food = '*';
}

GameMechs::GameMechs(int boardX, int boardY)
{
        input=0;
        exitFlag= false;
        loseFlag = false;
        score = 0;;

        boardSizeX = boardX;
        boardSizeY = boardY;
        food= new Food(); //Allocating memory on the heap for food object
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // dont need the destructor yet becuase we dont have any memebers allocated on heap (new) but 
    // might need this later 
    delete food;//to prevent memory leak DMA 
    
}

bool GameMechs::getExitFlagStatus() const
{
    // return an exit flag return exitFlag; 
    return exitFlag;

}

bool GameMechs::getLoseFlagStatus() const
{
    return loseFlag;  // do i just get the loseFlag like i did for exitFlag?
}
    
void GameMechs::collectAsyncInput()
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    } //return input; 
    if (input == 27) exitFlag = true; 

}

char GameMechs::getInput() //remove const here to avoid errors 
{
    
    return input;

}


int GameMechs::getScore() const
{
    return score;

}

// need to update this function 
void GameMechs::incrementScore()
{
    // if food eaten increase the score by the numbe of foods eaten
    score += 1; //or could make it score ++; 
    // to have it increased more then one we can take in a
    // parameter and have that be the number of food so that we can increment more than 1
    

}

int GameMechs::getBoardSizeX() const
{
    return boardSizeX;
}

int GameMechs::getBoardSizeY() const
{
    return boardSizeY;
}


void GameMechs::setExitTrue()
{
    if (input == 32) //space bar is exit 
    {
        exitFlag = 1; 
    }
    

}

void GameMechs::setLoseFlag()
{
    // if the snake eats itself, setLoseFlag to 1 
    // when this happens the loseflag is 1
    loseFlag = true; 
    
}

void GameMechs::setInput(char this_input)
{
    input = this_input; 
}

void GameMechs::clearInput()
{
    input = 0; // back to nothing
}

// More methods should be added here
//objPos GameMechs::getFoodPos() const 
//{
    //return *food; // Assuming `food` is a pointer to an objPos object
//}
void GameMechs::consumeFood() {
    // Example: Generate a new random position for the food
    int newX = rand() % boardSizeX;
    int newY = rand() % boardSizeY;
    food->setObjPos(newX, newY, '*'); // Update food's position and symbol
}

objPos GameMechs::getFoodPos() const {
    return food->getFoodPos(); // Assuming `Food` has a method `getObjPos` that returns an `objPos`
}