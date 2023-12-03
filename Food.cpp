#include "Food.h"
#include "MacUILib.h"
#include "objPosArrayList.h"
#include "objPos.h"

#include <cstdlib>
#include <time.h>

Food::Food(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    foodPos.setObjPos(-1,-1,'o');
}

Food::~Food()
{

}

void Food::generateFood(objPosArrayList* blockOff)
{
    int Count = 0;
    objPos currElement;

    int sizex = mainGameMechsRef->getBoardSizeX();
    int sizey = mainGameMechsRef->getBoardSizeY();

    srand(time(NULL));

    while(Count == 0){
        foodPos.x = rand() % (sizex - 2 ) + 1;
        foodPos.y = rand() % (sizey - 2 ) + 1;

        bool Pos = true;

        for (int i = 0; i < blockOff->getSize(); i++){
            blockOff->getElement(currElement, i);
            if (foodPos.x == currElement.x && foodPos.y == currElement.y){
                Pos = false;
                break;
            }
        }
        if(Pos){
            Count++;
        }
    }
    

}

void Food::getFoodPos(objPos &returnPos)
{
    returnPos = foodPos;
}