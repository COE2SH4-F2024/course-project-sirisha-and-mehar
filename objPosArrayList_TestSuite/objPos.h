#ifndef OBJPOS_H
#define OBJPOS_H


// Not really a C++ thing
typedef struct
{
    int x;
    int y;
    char symbol;
} Pos;

class objPos
{
    public:
        Pos* pos; //pointer to store x and y coordinates
        char symbol; //ASCII character representing the player 

        objPos();
        objPos(int xPos, int yPos, char sym);
        
        // Respect the rule of six / minimum four
        // [TODO] Implement the missing special member functions to meet the minimum four rule
        objPos(const objPos &m);
        // need copy assignment constructor 
        objPos& operator=(const objPos &m);
        // need destructor 
        ~objPos();
        

        void setObjPos(objPos o);        
        void setObjPos(int xPos, int yPos, char sym);  

        objPos getObjPos() const;
        char getSymbol() const;
        char getSymbolIfPosEqual(const objPos* refPos) const;
        
        bool isPosEqual(const objPos* refPos) const;
};

#endif