#include "Player.h"


Player::Player(GameMechs* thisGMRef)//*we asume gamechanics is the border for now
{
    mainGameMechsRef = thisGMRef;//getting pointer 
    myDir = STOP; //defaulted direction to stop

    // more actions to be included
    //initialzing the first location of your player
    //dynamically allocating the position
    playerPos.pos = new Pos;

    //setting the intial player position to the center of the board
    playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    playerPos.symbol='@';


    

    
    // get player position playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2; //pos was a ptr to stuct 
    // playerPos.pos->y = mainGameMechsRef->getBoardSizeX()/2;
    // playerPos.symbol = "@"
    

    // now that we have impleemnted gamemechs we can get the boardsize of x and y and the symbol
    // this can be used to find the position of the player and the symbol of the player

    //playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    //playerPos.pos->y = mainGameMechsRef->getBoardSizeX()/2;
    //playerPos.symbol = '*';

}


Player::~Player()
{
    // delete any heap members here
    //no keyword new in the conrtuctor so there is no heap member
    //can leave destructor empty for now
    delete playerPos.pos; // Free dynamically allocated memory
    //playerPos.pos = nullptr; // Avoid dangling pointer
}




objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    //return array list later
    return playerPos;
}

void Player::updatePlayerDir()
{
        // PPA3 input processing logic  
        //copy ppa2 move direction player thing  
    //switch (myGm->getInput()) {
    //    case 27:  // exit, if esc pressed 
    //copy ppa2 move direction player thing  
    char input = mainGameMechsRef->getInput(); //allows us to peak into what input gammechanics has currently
    //as the most recent async input
    // we use the async input to determine whether we move our player with the ASWD switch case
    // PPA3 input processing logic  
    switch (input) {
        case 32:
        //myDir = STOP;
        
         // esitflag = 1 here
        mainGameMechsRef->setExitTrue();
        mainGameMechsRef->getExitFlagStatus();
        
        myDir = STOP;
        break;
        //case 27:  // exit, if esc pressed 
                
            //MacUILib_printf("You have left the game!\n"); //display if we esp out of the game
            //MacUILib_Delay(1000000);
            //exitFlag = 1; 
            //myDir = STOP; // current state
            //break;

        case 'W': case 'w':
            if (myDir != UP&& myDir !=DOWN)
                myDir=UP;
            break;
        case 'A': case 'a':
            if (myDir != RIGHT&& myDir !=LEFT)
                myDir=LEFT;
            break;
        case 'S': case 's':
            if (myDir != UP&& myDir !=DOWN)
                myDir = DOWN;
            break;
        case 'D': case 'd':
            if (myDir != RIGHT&& myDir !=LEFT)
                myDir=RIGHT;
            break;

    }
}

void Player::movePlayer()
{
    /*
    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY(); 
    if (boardSizeX > 0 && boardSizeY > 0) { // Ensure valid board dimensions
        switch (myDir) {
            case UP:
                playerPos.pos->y = (playerPos.pos->y - 1 + boardSizeY) % boardSizeY;
                break;
            case DOWN:
                playerPos.pos->y = (playerPos.pos->y + 1) % boardSizeY;
                break;
            case LEFT:
                playerPos.pos->x = (playerPos.pos->x - 1 + boardSizeX) % boardSizeX;
                break;
            case RIGHT:
                playerPos.pos->x = (playerPos.pos->x + 1) % boardSizeX;
                break;
            case STOP:
            default:
                break;
            }
        }
    */

    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY(); 
    if (boardSizeX > 0 && boardSizeY > 0) { // Ensure valid board dimensions
        switch (myDir) {
            case UP:
            if (playerPos.pos->y >1)
            {
                playerPos.pos->y -=1;
            }
            else
            {
                playerPos.pos->y = boardSizeY-2;
            }
            break;
            case DOWN:
                 if (playerPos.pos->y < boardSizeY-2)
            {
                playerPos.pos->y +=1;
            }
            else
            {
                playerPos.pos->y =1;
            }
            break; 
            case LEFT:
                if (playerPos.pos->x >1)
            {
                playerPos.pos->x -=1;
            }
            else
            {
                playerPos.pos->x = boardSizeX-2;
            }
            break; 
            case RIGHT:
                if (playerPos.pos->x <boardSizeX-2)
            {
                playerPos.pos->x +=1;
            }
            else
            {
                playerPos.pos->x = 1;
            }
            break; 
            case STOP:
            default:
                break;
            }
        }


    // PPA3 Finite State Machine logic
    //switch (myDir) {
        //case UP:
            //playerPos.pos->y--;
            //if (playerPos.pos->y<=0)//Wraparound Logic
                //playerPos.pos-> y = mainGameMechsRef->getBoardSizeY()-2;
            //player.y = (player.y - 1 + BOARD_HEIGHT) % BOARD_HEIGHT;
            //if (player.y == 0) player.y = BOARD_HEIGHT - 2;
            //break;
        //case DOWN:
            //playerPos.pos->y++;
            //if (playerPos.pos->y>= mainGameMechsRef->getBoardSizeY())//Wraparound Logic
                //playerPos.pos->y =1;
            //player.y = (player.y + 1) % BOARD_HEIGHT;
            //if (player.y == BOARD_HEIGHT - 1) player.y = 1;
            //break;
        //case LEFT:
            //playerPos.pos->x--;
            //if (playerPos.pos->x<=0)//Wraparound Logic
                //playerPos.pos-> x = mainGameMechsRef->getBoardSizeX()-2;
            //player.x = (player.x - 1 + BOARD_WIDTH) % BOARD_WIDTH;
            //if (player.x == 0) player.x = BOARD_WIDTH - 2;
            //break;
        //case RIGHT:
            //playerPos.pos->x++;
            //if (playerPos.pos->x>=mainGameMechsRef->getBoardSizeX())//Wraparound Logic
                //playerPos.pos-> x = 1;
            //player.x = (player.x + 1) % BOARD_WIDTH;
            //if (player.x == BOARD_WIDTH - 1) player.x = 1;
            //break;
        //default:
            //break;
    //}
}

// More methods to be added