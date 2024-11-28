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
        // PPA3 input processing logic  
        //copy ppa2 move direction player thing  
    switch (input) {
        case 27:  // exit, if esc pressed 
                
            MacUILib_printf("You have left the game!\n"); //display if we esp out of the game
            MacUILib_Delay(1000000);
            exitFlag = 1; 
            currentdirection = STOP; // current state
            break;

        case 'W': case 'w':
            currentdirection = UP;
            break;
        case 'A': case 'a':
            currentdirection = LEFT;
            break;
        case 'S': case 's':
            currentdirection = DOWN;
            break;
        case 'D': case 'd':
            currentdirection = RIGHT;
            break;

    }
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch (currentdirection) {
        case UP:
            player.y = (player.y - 1 + BOARD_HEIGHT) % BOARD_HEIGHT;
            if (player.y == 0) player.y = BOARD_HEIGHT - 2;
            break;
        case DOWN:
            player.y = (player.y + 1) % BOARD_HEIGHT;
            if (player.y == BOARD_HEIGHT - 1) player.y = 1;
            break;
        case LEFT:
            player.x = (player.x - 1 + BOARD_WIDTH) % BOARD_WIDTH;
            if (player.x == 0) player.x = BOARD_WIDTH - 2;
            break;
        case RIGHT:
            player.x = (player.x + 1) % BOARD_WIDTH;
            if (player.x == BOARD_WIDTH - 1) player.x = 1;
            break;
        default:
            break;
    }
}

// More methods to be added