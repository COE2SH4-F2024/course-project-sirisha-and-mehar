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
    char input = mainGameMechsRef->getInput();

    // PPA3 input processing logic  
    switch (input) {
        case 27:
        myDir = STOP;
        break;

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


 
}

// More methods to be added