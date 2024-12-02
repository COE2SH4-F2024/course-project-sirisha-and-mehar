#include "Player.h"


Player::Player(GameMechs* thisGMRef)//*we asume gamechanics is the border for now
{
    mainGameMechsRef = thisGMRef;//getting pointer 
    PlayerPosList = new objPosArrayList();
    myDir = STOP; //defaulted direction to stop
    foodEaten = false;  // Initialize foodEaten flag
    
    // more actions to be included
    //initialzing the first location of your player
    //dynamically allocating the position
    //playerPos.pos = new Pos; i think we comment it out because this only generates one position instead of a list of posiitons

    objPos headPos(thisGMRef->getBoardSizeX()/2, thisGMRef->getBoardSizeY()/2, '@');//headposition

    PlayerPosList->insertHead(headPos); //now we have a list containing one head position
    objPos currentHead = PlayerPosList->getHeadElement(); // Assuming `getHead()` is defined
    //setting the intial player position to the center of the board
    //PlayerPos.pos->x = mainGameMechsRef->getBoardSizeX()/2;
    //playerPos.pos->y = mainGameMechsRef->getBoardSizeY()/2;
    //playerPos.symbol='@';



}


Player::~Player()
{
    // delete any heap members here
    //no keyword new in the conrtuctor so there is no heap member
    //can leave destructor empty for now
    //delete playerPos.pos; // Free dynamically allocated memory
    delete PlayerPosList; //bc this list sits on the heap we delete it
    delete getPlayerPos();
    //playerPos.pos = nullptr; // Avoid dangling pointer
}




objPosArrayList* Player::getPlayerPos() const
{
    // return the reference to the playerPos arrray list
    //return array list later
    return PlayerPosList;
    //returning the reference to the objpos player array list 
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
    //change this for iteration 3
    //calculate the next position for the head then instert a new object position into the head of the list
    //then deetermine if u need to delete the tail element
    //if the snake collides wiht the food then it grows by 1 so dont delete the tail element 
    //if it doesnt collide with food the delete tail element for snake moving motion 

    //Psuedo code iteration 3: create a temporary objPos to calculate the new head position
    //hint: roobabaly should get the head element of the playerpos list as a good starting point
    int boardSizeX = mainGameMechsRef->getBoardSizeX();
    int boardSizeY = mainGameMechsRef->getBoardSizeY(); 

        // Get the current head position of the player
    objPos currentHead = PlayerPosList->getHeadElement();

    // Calculate the new head position
    objPos newHead = currentHead;
    switch (myDir) {
        case UP:
            newHead.pos->y = (currentHead.pos->y > 1) ? currentHead.pos->y - 1 : boardSizeY - 2;
            break;
        case DOWN:
            newHead.pos->y = (currentHead.pos->y < boardSizeY - 2) ? currentHead.pos->y + 1 : 1;
            break;
        case LEFT:
            newHead.pos->x = (currentHead.pos->x > 1) ? currentHead.pos->x - 1 : boardSizeX - 2;
            break;
        case RIGHT:
            newHead.pos->x = (currentHead.pos->x < boardSizeX - 2) ? currentHead.pos->x + 1 : 1;
            break;
        case STOP:
        default:
            return; // No movement if STOP
    }

    // Insert the new head position into the list
    PlayerPosList->insertHead(newHead);

    // Check if the new head overlaps with the food
    objPos foodPos = mainGameMechsRef->getFoodPos();
    if (newHead.isPosEqual(&foodPos)) {
        // Food consumed: Do not remove the tail, increase the score
        mainGameMechsRef->consumeFood();
    } else {
        // No food consumed: Remove the tail to simulate movement
        PlayerPosList->removeTail();
    }
    if (!foodEaten) {
        PlayerPosList->removeTail(); // Remove the last position
    }

/* before iteration 3
    if (boardSizeX > 0 && boardSizeY > 0) { // Ensure valid board dimensions
        switch (myDir) {
            //iteration 3: calculate the new position of the head using the temporary object position
            //update the cases replace temporary objpos with the new position of the head.
            case UP:
            if (PlayerPos.pos->y >1)
            {
                PlayerPos.pos->y -=1;
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
*/
        //iteration 3: insert temp objpos to the head of the list 
        //after inserting the head make important decsions it3 feature 2 
        //check if the new temp objpos overlaps with the food position (get it from the GamMechs class or the foodclass for us)
        //use isPosEqual() method from objPos class

        // then if overlapped food consumed and DO NOT REMOVE SNAKE TAIL
        // then take respective actions to increase the score

        //Iter3 if no overlap remove the tail and complete movement 
 
}

// More methods to be added