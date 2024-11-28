#include "Player.h"


Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included

    
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
}

objPos Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
}

void Player::updatePlayerDir()
{
    // where do you get input? you get this from the gamemechs file
    // use the pointer and use the getInput() method in gamemechs

    // to do so use char input = mainGameMechsRef -> getInput();
    // now you have the input wasd or anything else to see how the player should move and be updated 

    // char input = mainGameMechsRef -> // getting input
        // PPA3 input processing logic          
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
}

// More methods to be added