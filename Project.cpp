#include <iostream>
#include "MacUILib.h"
#include "objPos.h"

#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

bool exitFlag;

Player *myPlayer; //instantiating player as pointer
//on the heap 

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(exitFlag == false)  
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

    myPlayer = new Player(nullptr); 
    //keepign it nullptr to test features
    exitFlag = false;
    //put pointers under inirialize function
    //myGM
}

void GetInput(void)
{
   
}

void RunLogic(void)
{
    //myPlayer->movePlayer();
    
}

void DrawScreen(void)
{
    MacUILib_clearScreen();  
    //you will need to implement a copy assignment operator
    //to make this lien work
    objectPos playerPos = myPlayer->getPLayerPos();

    //put ppa3 board drawing function in here  
    MacUILib_printf("Player[x,y]=[%d,%d], %c",playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
    // using macuilib stll because here its asynhronous input system so not using cout yet

}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();  
    delete myPlayer;
    delete myGM;
    //delete pointers!!  

    MacUILib_uninit();
}
