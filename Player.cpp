#include "Player.h"
#include "GameMechs.h"

Player::Player(GameMechs* thisGMRef)
{
    mainGameMechsRef = thisGMRef;
    myDir = STOP;

    // more actions to be included
    playerPos.setObjPos(mainGameMechsRef->getBoardSizeX()/2,
                        mainGameMechsRef->getBoardSizeY()/2,
                        '@');
}


Player::~Player()
{
    // delete any heap members here
}

void Player::getPlayerPos(objPos &returnPos)
{
    // return the reference to the playerPos arrray list
    returnPos.setObjPos(playerPos.x,playerPos.y, playerPos.symbol);
}

void Player::updatePlayerDir()
{
    // PPA3 input processing logic   

    // get input using MacUILib_getChar()
    // in game mechanism input will be checked and got 

    char input = mainGameMechsRef->getInput();
    //int score = mainGameMechsRef->getScore();

    switch(input)
    {
        case '1':
            mainGameMechsRef->incrementScore();
            break;

        case ' ':
            mainGameMechsRef->setExitTrue();
            break;

        case 'w':
                if (myDir != DOWN) myDir = UP;
                break;
            
        case 'a':
            if (myDir != RIGHT) myDir = LEFT;
            break;

        case 's':
            if (myDir != UP) myDir = DOWN;
            break;

        case 'd':
            if (myDir != LEFT) myDir = RIGHT;
            break;

        default:
            break;


    }    
    mainGameMechsRef-> clearInput(); //clear input to ensure non repeating input
}

void Player::movePlayer()
{
    // PPA3 Finite State Machine logic
    switch(myDir){

        case UP:
            if(playerPos.y > 1 ){
                playerPos.y--;
            }
            else{
                playerPos.y = (mainGameMechsRef->getBoardSizeY()-2);
            }
            break;

        case DOWN:
            if(playerPos.y < mainGameMechsRef->getBoardSizeY()-2){
                playerPos.y++;
            }
            else{
                playerPos.y = 1;
            }
            break;
        
        case LEFT:
            if(playerPos.x > 1){
                playerPos.x--;
            }
            else{
                playerPos.x = (mainGameMechsRef->getBoardSizeX()-2);
            }
            break;

        case RIGHT:
            if(playerPos.x < mainGameMechsRef->getBoardSizeX()-2){
                playerPos.x++;
            }
            else{
                playerPos.x = 1;
            }
            break;

        default:
            break;
    }
}

