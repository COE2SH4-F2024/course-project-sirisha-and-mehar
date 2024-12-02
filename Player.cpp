#include "Player.h"
#include "GameMechs.h"

// removed the food part for now
Player::Player(GameMechs* thisGMRef)//*we asume gamechanics is the border for now
{
    mainGameMechsRef = thisGMRef;//getting pointer 
    // adding pointer for food collion check
    //foodRef = thisFoodRef; 
    myDir = STOP; //defaulted direction to stop

    // just added for iteration 3
    playerPosList = new objPosArrayList();

    objPos headPos(thisGMRef->getBoardSizeX()/2, thisGMRef->getBoardSizeY()/2, '@');
    playerPosList->insertHead(headPos); // add head to the headposition

    // more actions to be included
    //initialzing the first location of your player
    //dynamically allocating the position
    
    // commenting out for iteration 3 bc now we are using the array list

    //playerPos.pos = new Pos;

    //objPos headPos(thisGMRef->getBoardSizeX()/2, thisGMRef->getBoardSizeY()/2, '@');//headposition

    //playerPosList->insertHead(headPos); //now we have a list containing one head position
    //setting the intial player position to the center of the board
    //playerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    //playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    //playerPos.symbol='@';



}


Player::~Player()
{
    // delete any heap members here
    //no keyword new in the conrtuctor so there is no heap member
    //can leave destructor empty for now
    // commenting out for iteration 3
    //delete playerPos.pos; // Free dynamically allocated memory
    delete playerPosList; 
}


// canged from objPos Player to this for iteration 3

objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    //return array list later
    // now returning the reference to the player obj list
    return playerPosList;
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
    // iteration 3
    // ceate a temp objPos to calcualte the new head positon
    // should get the head element of the playerposlist as the starting psootion 
    // objPos initalHead = playerPosList->getHeadElement();

    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY(); 
    if (boardSizeX > 0 && boardSizeY > 0) { // Ensure valid board dimensions
        
        objPos initalHead = playerPosList->getHeadElement();
        objPos newHead = initalHead; 

        switch (myDir) {

            // calculate the new psotion of the head using the temp objpos
            

            case UP:
            if (initalHead.pos->y >1)
            {
                //newHead.pos->y = initalHead.pos->y - 1;
                newHead.pos->y --;
            }
            else
            {
                newHead.pos->y = boardSizeY-2;
            }
            break;
            case DOWN:
                 if (initalHead.pos->y < boardSizeY-2)
            {
                //newHead.pos->y =initalHead.pos->y + 1;
                newHead.pos->y++;
            }
            else
            {
                newHead.pos->y =1;
            }
            break; 
            case LEFT:
                if (initalHead.pos->x >1)
            {
                //newHead.pos->x =initalHead.pos->x-1;
                newHead.pos->x --;
            }
            else
            {
                newHead.pos->x = boardSizeX-2;
            }
            break; 
            case RIGHT:
                if (initalHead.pos->x <boardSizeX-2)
            {
               //newHead.pos->x =initalHead.pos->x + 1;
               newHead.pos->x ++;
            }
            else
            {
                newHead.pos->x = 1;
            }
            break; 
            case STOP:
            default:
                break;
            }
            playerPosList->insertHead(newHead); // add a new head at the new furute position 

            /*
            for(int i = 1;i<playerPosList->getSize(); i++)
            {
            objPos bodyList = playerPosList->getElement(i);
            
            if(newHead.pos->x==bodyList.pos->x && newHead.pos->y==bodyList.pos->y)
            {
                checkSelfCollision() == true;  // if there is a collision set it as true
                // we can to amke the loseflag true and the exitflag true
                mainGameMechsRef->setLoseFlag(); // true means that they lost the gaem
                mainGameMechsRef->setExitTrue(); // we have to exit the whle loop 
                break; 
            }
            } 
            */
        }
 
}

// More methods to be added
bool Player::checkSelfCollision(){ 
    objPos initalHead = playerPosList->getHeadElement();
    objPos newHead = initalHead; 

    for(int i = 1;i<playerPosList->getSize(); i++)
    {
        objPos bodyList = playerPosList->getElement(i);
        // self collision
        if(newHead.pos->x==bodyList.pos->x && newHead.pos->y==bodyList.pos->y)
        {
            //checkSelfCollision() == true;  // if there is a collision set it as true
            // we can to amke the loseflag true and the exitflag true
            mainGameMechsRef->setLoseFlag(); // true means that they lost the gaem
            mainGameMechsRef->setExitTrue(); // we have to exit the whle loop 
            return true; 
        }
    } 
}
