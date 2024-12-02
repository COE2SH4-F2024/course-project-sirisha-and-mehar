#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"
#include "Player.h"
#include "Food.h" 
using namespace std;

#define DELAY_CONST 100000

// initalize the pointers 
Player *myPlayer; 
GameMechs *myGM; 
Food *myFood; 


void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



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
    
    srand(time(NULL));
    myGM = new GameMechs(); // default game mechs so we alwasy have the same dimentions 30x15

    myPlayer = new Player(myGM);
    myFood = new Food(); 

    objPosArrayList* playerPositions = myPlayer->getPlayerPos();
    objPos headPos = playerPositions->getHeadElement();
   
    myFood->generateFood(headPos); // start by generating food in a random positon on the baord 
}

void GetInput(void)
{
   
   char input = myGM->getInput();
   
   if(input ==27)
   {
    myGM->setExitTrue();
   }

   myGM->collectAsyncInput(); 

  
}

void RunLogic(void)
{

    myPlayer->movePlayer();
    myPlayer->updatePlayerDir();


    objPosArrayList* playerPositions = myPlayer->getPlayerPos();
    objPos headPos = playerPositions->getHeadElement();


    // Check if player eats food
    if (headPos.pos->x == myFood->getFoodPos().pos->x && headPos.pos->y == myFood->getFoodPos().pos->y) {
        // Generate new food that does not overlap with player positions
        myFood->generateFood(headPos);
        myGM->incrementScore(); 
    }
    else
    {
        playerPositions->removeTail();

    }
   
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  
    //you will need to implement a copy assignment operator
    //to make this line work
    objPosArrayList* playerPos = myPlayer->getPlayerPos();
    int playerSize = playerPos->getSize(); 
    objPos headPos = playerPos->getHeadElement();



    objPos foodPos = myFood->getFoodPos(); 
    // playerPos.pos->x gets the x value
    // playerPos.pos->y gets the y value
    // playerPos.symbl-> gets the symnol
     
   

    // add back
    MacUILib_printf("Player[x,y]=[%d,%d], %c\n",headPos.pos->x, headPos.pos->y, headPos.symbol);
    MacUILib_printf("Generated food at [%d, %d]\n", foodPos.pos->x, foodPos.pos->y);
    MacUILib_printf("Score: %d\n", myGM->getScore());
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
    
    if (myGM->getExitFlagStatus()==1)
    {
        
        MacUILib_printf("You have left the game!\n");
        MacUILib_Delay(1000000);
    }
    
    /*if(myGM->getLoseFlagStatus()==1)
    {
        MacUILib_printf("You have lost the game!\n");
        //MacUILib_Delay(1000000);
        
    }
    */
    
    
    if(myPlayer->checkSelfCollision()==true)
    {
        MacUILib_printf("You have lost the game!\n");
        MacUILib_Delay(1000000);
        
    }
    
    
    

    
    
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
