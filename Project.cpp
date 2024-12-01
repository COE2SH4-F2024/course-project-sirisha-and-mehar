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
    myPlayer = new Player(myGM); // my player keeps track of the pointer myGM
    myFood = new Food(); // new
    myFood->generateFood(myPlayer->getPlayerPos()); // start by generating food in a random positon on the baord 
}

void GetInput(void)
{
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
    if (myPlayer->getPlayerPos().pos->x == myFood->getFoodPos().pos->x && myPlayer->getPlayerPos().pos->y == myFood->getFoodPos().pos->y) {
        myFood->generateFood(myPlayer->getPlayerPos()); // Generate new food, blockOff is the playerpositon 
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
    int playerSize = playerPos->getSize();//tells us how many elements are in the list and we need to 
    //iterate through all the elements in the list
    objPos foodPos = myFood->getFoodPos(); // just added 
    // playerPos.pos->x gets the x value
    // playerPos.pos->y gets the y value
    // playerPos.symbl-> gets the symnol
    //put ppa3 board drawing function in here  
    MacUILib_printf("Player[x,y]=[%d,%d], %c\n",playerPos.pos->x, playerPos.pos->y, playerPos.symbol);
    MacUILib_printf("Generated food at [%d, %d]\n", foodPos.pos->x, foodPos.pos->y);
    // using macuilib stll because here its asynhronous input system so not using cout yet

    //MacUILib_clearScreen();   
    // draw the board here  
    // adding for iteration 0 
    
    for (int i=0; i<15; i++)
    {
        for (int j=0; j<30; j++) 
        { 
            //remove else if statement
            //we need to iterat through playerpos array list to print
            //all of the segments out
            
            //to iterate thru every player segment 
            for (int k=0; k<playerSize; k++)
            {
                objPos thisSeg = playerPos->getElement(k);
                //we do this so we can get the element we want to look at and save it to the local objPos instance

                //iteration3
                //check fi te current segment x y position matches the (j,i) cooridnate
                //if yes print the symbol to add the the snake


                //the else statement for the space character is tricky because of the new forloop
                //here that we jsut added it will mess up the gameboard print and print the character symbol and a space ebcause
                //the forloop and if else are not connected basically

                //wathc out!!!
                //we need to skip the if else block below if we have printed soemthing in the forloop
                //use keyword continue and boolean flag
            }

            //at the end of the forloop do smth to determine whetehr to continue with the if else or move on to the next iteration
            //of i,j *key for it3 part1
            //draw border
            if (j==0 || i== 15-1 || i==0 ||j==30-1) // this is where the border should be
            {
                MacUILib_printf("#");
                
            }
            else if (i==playerPos.pos->y && j==playerPos.pos->x)
            {
                MacUILib_printf("%c", playerPos.symbol);
            }
            else if (i==foodPos.pos->y && j==foodPos.pos->x)
            {
                MacUILib_printf("%c", foodPos.symbol);
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
    //delete myPlayer; // if i comment this out the malloc error goes away?
    //delete myGM;
    //delete pointers!!  

    MacUILib_uninit();
    // delete pointers initalized in the beggining
    delete myPlayer;
    delete myGM;
    delete myFood; // just added 
}
