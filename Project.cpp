#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"
#include "Player.h"
#include "Food.h" // added now
using namespace std;

#define DELAY_CONST 100000
// added for iteration 0 (same size as ppas)
//# define HEIGHT 10
//# define WIDTH 20


Player *myPlayer; // points to player 
GameMechs *myGM; // pointers to gamemechs 
Food *myFood; // added now 

// bool exitFlag; // dont need to expose here bc it is already in game mechanics but we can access game mechanices
// using myGM and get the exitflag

//Player *myPlayer; //instantiating player as pointer
//on the heap 

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// initalize the pointers 

int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  // while the exist flag is not initalized you have to keep incrementign
    {
        GetInput();
        RunLogic();
        DrawScreen();
        LoopDelay();
    }

    CleanUp();

}

void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();


    // removed bc it was causing a seg fault
    //myPlayer = new Player(nullptr);  

    //keepign it nullptr to test features
    //exitFlag = false;
    //put pointers under inirialize function
    //myGM
    //exitFlag = false;
    
    srand(time(NULL));
    myGM = new GameMechs(); // default game mechs so we alwasy have the same dimentions 30x15
    // add back
    // myPlayer = new Player(myGM, myFood); // my player keeps track of the pointer myGM, added myFood
    myPlayer = new Player(myGM);
    myFood = new Food(); // new

    objPosArrayList* playerPositions = myPlayer->getPlayerPos();
    objPos headPos = playerPositions->getHeadElement();
   
    // add back
    myFood->generateFood(headPos); // start by generating food in a random positon on the baord 
}

void GetInput(void)
{
    // Assuming you are collecting asynchronous input
    char input = myGM->getInput();  // Get the input character from the game mechanics

    // Check for the ESC key (ASCII 27)
    if (input == 27) {
        myGM->setExitTrue();  // Set the exit flag to true to stop the game loop
    }
    else {
        myGM->collectAsyncInput(); // Handle other inputs normally
    }
   // get the input from the myGm object 
   // .input = myGM->getInput(); 
   //char input = myGM->getInput();
   myGM->collectAsyncInput(); 
  
}

void RunLogic(void)
{

    myPlayer->movePlayer();
    myPlayer->updatePlayerDir();

    // make sure there is no ovelap 
   // add back
    //if (myPlayer->getPlayerPos().pos->x == myFood->getFoodPos().pos->x && myPlayer->getPlayerPos().pos->y == myFood->getFoodPos().pos->y) {
    //    myFood->generateFood(myPlayer->getPlayerPos()); // Generate new food, blockOff is the playerpositon 
    //}
    objPosArrayList* playerPositions = myPlayer->getPlayerPos();
    objPos headPos = playerPositions->getHeadElement();


    // Check if player eats food
    if (headPos.pos->x == myFood->getFoodPos().pos->x && headPos.pos->y == myFood->getFoodPos().pos->y) {
        // Generate new food that does not overlap with player positions
        myFood->generateFood(headPos);
        
    }
    else{
        playerPositions->removeTail();

    }
   

    
    //myGm->getInput(); 
// have to come back with 1A content and use getter methid for input char, 
// choosing corr action , then clearing using the myGM pointer pointng to gamemechs
// add ppa2 switch case and add use the pointer for reference on input and then clearing it
 
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  
    //you will need to implement a copy assignment operator
    //to make this lien work
    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int playerSize = playerPos->getSize(); 
    objPos headPos = playerPos->getHeadElement();



    objPos foodPos = myFood->getFoodPos(); // just added 
    // playerPos.pos->x gets the x value
    // playerPos.pos->y gets the y value
    // playerPos.symbl-> gets the symnol
    //put ppa3 board drawing function in here  

    // add back
    MacUILib_printf("Player[x,y]=[%d,%d], %c\n",headPos.pos->x, headPos.pos->y, headPos.symbol);
    MacUILib_printf("Generated food at [%d, %d]\n", foodPos.pos->x, foodPos.pos->y);
    
    //MacUILib_printf("You have left the game!\n", myGM->setExitTrue());
    // using macuilib stll because here its asynhronous input system so not using cout yet

    //MacUILib_clearScreen();   
    // draw the board here  
    // adding for iteration 0 
    
    for (int i=0; i<15; i++)
    {
        for (int j=0; j<30; j++) 
        { bool isDrawn = false; // added 
            
            for(int k=0;k<playerSize; k++)
            {
                objPos thisSeg = playerPos->getElement(k);
                if (i==thisSeg.pos->y && j==thisSeg.pos->x)
                {
                    MacUILib_printf("%c", thisSeg.symbol);
                    isDrawn = true; // added
                    break;  // added
                }


                // check i fthe current seg x, y pos mathces j and i coord, if yes proint symbol
                // we need to skip if else block if we printied something in the for loop

            }
            if(!isDrawn){ // del if 
            if (j==0 || i== 15-1 || i==0 ||j==30-1) // this is where the border should be
            {
                MacUILib_printf("#");
                
            }


            //else if (i==playerPos.pos->y && j==playerPos.pos->x)
            //{
            //    MacUILib_printf("%c", playerPos.symbol);
            //}
            else if (i==foodPos.pos->y && j==foodPos.pos->x)
            {
                MacUILib_printf("%c", foodPos.symbol);
            }
            else 
            {
                
               MacUILib_printf(" "); // empty space for the rest 
                
            }
            } // del for loop 
        
        }
        MacUILib_printf("\n"); // new line before next row starts 
    }
    if (myGM->getExitFlagStatus()==1){
        MacUILib_printf("You have left the game!\n"); //display if we esp out of the game
        MacUILib_Delay(1000000);

    }
    if (myGM->getLoseFlagStatus()) {
        MacUILib_printf("Game Over! You lost!\n");
    } 
    //else {
        //MacUILib_printf("Game Over! You exited the game!\n");
   // }
    
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  
    //delete myPlayer; // if i comment this out the malloc error goes away?
    //delete myGM;
    //delete pointers!!  

    MacUILib_uninit();
    // delete pointers initalized in the beggining
    delete myPlayer;
    delete myGM;
    delete myFood; // just added 
}