#include "Player.h"


Player::Player(GameMechs* thisGMRef)//*we asume gamechanics is the border for now
{
    mainGameMechsRef = thisGMRef;//getting pointer 
    myDir = STOP; //defaulted direction to stop

    // more actions to be included
    //initialzing the first location of your player
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
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    //return array list later
    return playerPos;
}

void Player::updatePlayerDir()
{
    //copy ppa2 move direction player thing  
    char input = mainGameMechsRef->getInput();
    // PPA3 input processing logic  
    switch (input) {
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
    // PPA3 Finite State Machine logic
    switch (myDir) {
        case UP:
            playerPos.pos->y--;
            if (playerPos.pos->y<=0)//Wraparound Logic
                playerPos.pos-> y = mainGameMechsRef->getBoardSizeY()-2;
            //player.y = (player.y - 1 + BOARD_HEIGHT) % BOARD_HEIGHT;
            //if (player.y == 0) player.y = BOARD_HEIGHT - 2;
            break;
        case DOWN:
            playerPos.pos->y++;
            if (playerPos.pos->y>= mainGameMechsRef->getBoardSizeY())//Wraparound Logic
                playerPos.pos->y =1;
            //player.y = (player.y + 1) % BOARD_HEIGHT;
            //if (player.y == BOARD_HEIGHT - 1) player.y = 1;
            break;
        case LEFT:
            playerPos.pos->x--;
            if (playerPos.pos->x<=0)//Wraparound Logic
                playerPos.pos-> x = mainGameMechsRef->getBoardSizeX()-2;
            //player.x = (player.x - 1 + BOARD_WIDTH) % BOARD_WIDTH;
            //if (player.x == 0) player.x = BOARD_WIDTH - 2;
            break;
        case RIGHT:
            playerPos.pos->x++;
            if (playerPos.pos->x>=mainGameMechsRef->getBoardSizeX())//Wraparound Logic
                playerPos.pos-> x = 1;
            //player.x = (player.x + 1) % BOARD_WIDTH;
            //if (player.x == BOARD_WIDTH - 1) player.x = 1;
            break;
        default:
            break;
    }
}

// More methods to be added