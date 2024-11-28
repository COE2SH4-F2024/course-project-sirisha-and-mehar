#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

// include gamemechs.h and player.h
#include "GameMechs.h"
#include "Player.h"
using namespace std;

#define DELAY_CONST 100000
// added for iteration 0 (same size as ppas)
//# define HEIGHT 10
//# define WIDTH 20


Player *myPlayer; // points to player 
GameMechs *myGM; // pointers to gamemechs 


// bool exitFlag; // dont need to expose here bc it is already in game mechanics but we can access game mechanices
// using myGM and get the exitflag

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

    //exitFlag = false;
    myGM = new GameMechs(); // default game mechs so we alwasy have the same dimentions 30x15
    myPlayer = new Player(myGM); // my player keeps track of the pointer myGM
}

void GetInput(void)
{
   // get the input from the myGm object 
   // .input = myGM->getInput(); 
}

void RunLogic(void)
{
// have to come back with 1A content and use getter methid for input char, 
// choosing corr action , then clearing using the myGM pointer pointng to gamemechs
// add ppa2 switch case and add use the pointer for reference on input and then clearing it
 
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();   
    // draw the board here  
    // adding for iteration 0 
    for (int i=0; i<15; i++)
    {
        for (int j=0; j<30; j++) 
        { 
            
            if (j==0 || i==15-1 || i==0 ||j==30-1) // this is where the border should be
            {
                MacUILib_printf("#");
                
             
            }
            else if (j==5&&i==6 || j==9&&i==9 ||j==6&&i==4 ||j==2&&i==1)
            {
                MacUILib_printf("*");
            }
            else 
            {
                MacUILib_printf(" "); // empty space for the rest 
                
            }
        
        }
        MacUILib_printf("\n"); // new line before next row starts 
    }
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();   
    delete myPlayer;
    delete myGM; // alwasy delete everytime new is mentioned 

    MacUILib_uninit();
    // delete pointers initalized in the beggining
}
