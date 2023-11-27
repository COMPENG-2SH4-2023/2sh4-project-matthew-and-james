#include <iostream>
#include "MacUILib.h"
#include "objPos.h"
#include "GameMechs.h"
#include "Player.h"

using namespace std;

#define DELAY_CONST 100000

GameMechs* myGM;
Player* myPlayer;

bool exitFlag;

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);



int main(void)
{

    Initialize();

    while(myGM->getExitFlagStatus() == false)  
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

    myGM = new GameMechs(30, 15); //board size
    myPlayer = new Player(myGM);
}

void GetInput(void)
{

}

void RunLogic(void)
{
    myPlayer -> updatePlayerDir();
    myPlayer -> movePlayer();
}

void DrawScreen(void)
{
    MacUILib_clearScreen();

    objPos tempPos;
    myPlayer->getPlayerPos(tempPos);

    for(int row = 0; row < myGM->getBoardSizeY(); row++){
        for (int col = 0; col < myGM->getBoardSizeX(); col++){
            if (row == 0 || row == myGM->getBoardSizeY() - 1 || col == 0 || col == myGM->getBoardSizeX() - 1) {
                MacUILib_printf("#");
            }
            else if (row == tempPos.y && col == tempPos.x) {
                MacUILib_printf("%c", tempPos.symbol);
            }
            else{
                MacUILib_printf(" ");
            }
        }
        MacUILib_printf("\n");
    }   

    MacUILib_printf("Press Spacebar to quit\n");
    MacUILib_printf("your score is %d\n", myGM->getScore());
}

void LoopDelay(void)
{
    MacUILib_Delay(DELAY_CONST); // 0.1s delay
}


void CleanUp(void)
{
    MacUILib_clearScreen();    
  
    MacUILib_uninit();

    delete myPlayer;
    delete myGM;
}
