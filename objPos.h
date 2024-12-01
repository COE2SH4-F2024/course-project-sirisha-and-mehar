#ifndef OBJPOS_H
#define OBJPOS_H

// Not really a C++ thing
typedef struct 
{
    int x;
    int y;
} Pos;

class objPos
{
    public:
        Pos* pos;        
        char symbol;
        int x;
        int y;

        objPos(); // constuctor
        objPos(int xPos, int yPos, char sym); // special constructor 
        
        // Respect the rule of six / minimum four
       
        // added for iteration 0
         
        // need copy constructor
        objPos(const objPos &m);
        // need copy assignment constructor 
        objPos& operator=(const objPos &m);
        // need destructor 
        ~objPos();


        // [TODO] Implement the missing special member functions to meet the minimum four rule
       
        

        // special member functions - these need to be implemented to complete certain tasks
        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif