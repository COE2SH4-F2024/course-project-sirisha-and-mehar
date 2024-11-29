#include "objPosArrayList.h"

// Check lecture contents on general purpose array list construction, 
// and modify it to support objPos array list construction.
#include "objPosArrayList.h"

// Paste your Tested implementation here.
// Paste your Tested implementation here.
// Paste your Tested implementation here.

objPosArrayList::objPosArrayList()
{
    // constructor
    aList = new objPos[ARRAY_MAX_CAP]; // create a 200 size array on heap
    listSize = 0;
    arrayCapacity = ARRAY_MAX_CAP; // 200
    
}

// destructor 
objPosArrayList::~objPosArrayList()
{
    // destructor 
    delete[] aList;
}


// copy  consutrctor
objPosArrayList::objPosArrayList(const objPosArrayList &l)
{
    // deep copy
    listSize = l.listSize;
    arrayCapacity = l.arrayCapacity;

    aList = new objPos[ARRAY_MAX_CAP];
    for(int i = 0; i<listSize; i++)
        aList[i] = l.aList[i]; 
}

// copy assigment not needed according to lectue?

int objPosArrayList::getSize() const
{
    return listSize; 
}

void objPosArrayList::insertHead(objPos thisPos)
{
    if (listSize >= ARRAY_MAX_CAP) return;
    for(int i = listSize; i>0; i--)
    {
        aList[i] = aList[i-1];
    }
    aList[0] = thisPos; // gets added to the first index
    listSize++; 
}

void objPosArrayList::insertTail(objPos thisPos)
{
    if (listSize >= arrayCapacity) return; // dont increment, error checking 
    aList[listSize++] = thisPos; 
    //listSize ++; 
}

void objPosArrayList::removeHead()
{
    if(listSize == 0) return;
    for(int i=0;i<listSize-1;i++)
    {
        aList[i] = aList[i+1];
    }
    listSize--; 
}

void objPosArrayList::removeTail()
{
    if(listSize>0)
        listSize--; 
}

objPos objPosArrayList::getHeadElement() const
{
    return aList[0]; 
}

objPos objPosArrayList::getTailElement() const
{
    return aList[listSize-1]; 
}

objPos objPosArrayList::getElement(int index) const
{
    if(index<0) 
        index = 0;
    else if(index>=listSize) 
        index = listSize - 1; 
    return aList[index];
    
}
 
