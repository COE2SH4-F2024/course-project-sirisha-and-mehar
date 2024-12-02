#include "Food.h"
#include <cstdlib> // for rand()
#include <ctime> 
#include "Player.h"

Player *myplayer; 

// constructor 
Food::Food()
{

    srand(time(NULL)); // Seed the random number generator

    // Initialize food position directly
    // foodPos.pos = new Pos; // Allocate memory for position
    // //foodPos.pos->x = 1;         // Default x
    // //foodPos.pos->y = 1;         // Default y
    // foodPos.symbol = 'o';       // Default food symbol

    foodPos.pos->x = 1;
    foodPos.pos->y = 1; 
    foodPos.symbol = 'o';

}

Food::~Food()
{
    // delete foodPos.pos; 
    //delete foodPos;
    //delete myplayer;
}

void Food::generateFood(objPos blockOff)
{
    
    
    /*
    objPos playerPos = myplayer->getPlayerPos(); 
 
    int oldCords[30][15];
     for ( int i = 0; i<30;i++){
        for( int j=0;j<15; j++){
            oldCords[i][j] = 0; // 0 means not used cord. Set all cords at 0 
        }
    }

    // go through the list and check if the cord has been used before if yes then generate a new x and y cord
    for (int i = 0; i< 5; i++){ // 5 new foods getting generated each time 
        int flag = 0; // if it equasl 0 then it was never used before 
        while(!flag){ // if it does not equal 0 then it was used before and we need to regenerate the c and y cords
            int x_cord = rand()%(30 -2)+1; // we dont want it to go on the border
            int y_cord = rand()%(15-2)+1;

            // if the generates cords fall on the postions cods then regeerate
            //if (x_cord == playerPos.pos->x  && y_cord == playerPos.pos->y)
            //{
            //    continue; 
            //}
       
            // if the egenrated cords give you a 0 then you can add a symbol there. recall 0 means unused cord 
            if (oldCords[y_cord][x_cord] == 0){
                oldCords[y_cord][x_cord] = 1;
                foodPos.pos->x = x_cord;
                foodPos.pos->y = y_cord;
                char rand_symbol = 'o'; 
                flag = 1;
            
            }
            //oldCords[y_cord][x_cord] = 1;
            // need the y_cord and x_cord for food pos
            //foodPos.pos->x = x_cord;
            //foodPos.pos->y = y_cord;
            //foodPos.symbol = 'o'; 


            //flag = 1; // exit loop 


            
        }
    }
    */

  
   while (true) {
    // randomly generate food 
        int x_cord = rand() % (30 - 2) + 1; 
        int y_cord = rand() % (15 - 2) + 1; 

        if (x_cord != blockOff.pos->x || y_cord != blockOff.pos->y) { // if the cords dont equal then add symbol there 
            foodPos.pos->x = x_cord;
            foodPos.pos->y = y_cord;
            foodPos.symbol = 'o'; // Assign symbol
            break; // Exit loop
        }
    }
    

}
//added
//void Food::setObjPos(int x, int y, char sym) {
    //foodPos.pos->x = x;
    //foodPos.pos->y = y;
    //foodPos.symbol = sym;
//}

objPos Food::getFoodPos() const
{
    return foodPos; 
}