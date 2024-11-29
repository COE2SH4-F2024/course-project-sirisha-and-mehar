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
        score = 0;;

        boardSizeX = 30;
        boardSizeY = 15;
}

GameMechs::GameMechs(int boardX, int boardY)
{
        input=0;
        exitFlag= false;
        loseFlag = false;
        score = 0;;

        boardSizeX = boardX;
        boardSizeY = boardY;
}

// do you need a destructor?
GameMechs::~GameMechs()
{
    // dont need the destructor yet becuase we dont have any memebers allocated on heap (new) but 
    // might need this later 
    
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
    

char GameMechs::getInput() //remove const here to avoid errors 
{
    if (MacUILib_hasChar())
    {
        input = MacUILib_getChar();
    } return input; 
}


int GameMechs::getScore() const
{
    return score;

}

// need to update this function 
void GameMechs::incrementScore()
{
    // if food eaten increase the score by the numbe of foods eaten
    score += 1; // to have it increased more then one we can take in a
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
    if (input == 27) //esc key is exit 
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

// generate random food positions
void GameMechs::generateFood(objPos blockOff)
{

    // Use random number generator function, rand(), to generate a random x-y coordinate and a random choice of character from the Goal String as the ASCII character symbol.
    //      The x and y coordinate range should fall within the xRange and yRange limits, which should be the x- and y-dimension of the board size.
    // This will then be a candidate of the randomly generated Item to be placed on the game board.
    /*
    srand(time(NULL)); 

    int oldCords[yRange][xRange];
    int oldSymbols[128] = {0}; 
    char rand_symbol; 
    
  

    for ( int i = 0; i<yRange;i++){
        for( int j=0;j<xRange; j++){
            oldCords[i][j] = 0; // 0 means not used cord. Set all cords at 0 
        }
    }
   




    // go through the list and check if the cord has been used before if yes then generate a new x and y cord
    for ( int i = 0; i< listSize; i++){
        int flag = 0; // if it equasl 0 then it was never used before 
        while(!flag){ // if it does not equal 0 then it was used before and we need to regenerate the c and y cords
            int x_cord = rand()%(xRange -2)+1; // we dont want it to go on the border
            int y_cord = rand()%(yRange-2)+1;

            // if the generates cords fall on the postions cods then regeerate
            if (x_cord == PlayerPos.pos->x && y_cord == player_obj.y)
            {
                continue; 
            }
          


            
            // if the egenrated cords give you a 0 then you can add a random symbol there. recall 0 means unused cord 
            if (oldCords[y_cord][x_cord] == 0){

                if(i<2){
                    int rand_index_symbol = rand()%my_strlen(str); // using the length of the string (goal string) give any index
                    rand_symbol = str[rand_index_symbol]; // use that index to find the symbol in the goal string
                }
                else{
                    do
                    {
                        rand_symbol = (char)(rand()%(126-33+1)+33); // fins a random ASCII charecter in range 33 to 126
                    }
                    while(rand_symbol == ' '|| rand_symbol == '*' || rand_symbol == '.'); // generate a random chaecter until the random charecter is one we do not want to use
                }
                
                //int rand_index_symbol = rand()%my_strlen(str); // using the length of the string (goal string) give any index
                //rand_symbol = str[rand_index_symbol]; // use that index to find the symbol in the goal string

            }

            if( oldSymbols[rand_symbol] == 0){  // if the random symbol is 0 that means that it has never been chosen
            // when this is selected we want to make the old cords set to 1, this means they are now used
            oldCords[y_cord][x_cord] = 1;
            oldSymbols[rand_symbol] = 1; 
           

            list[i].x = x_cord;
            list[i].y = y_cord;
            list[i].symbol = rand_symbol; 
            flag = 1; // exit loop 


            }
        }
    }
    */
}

// getter method to get food position
objPos GameMechs::getFoodPos() const
{
    return food;  // bc it is a objPos and we have a copy assignment operator we can just return food

}